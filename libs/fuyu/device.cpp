/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2025, Erwan DUHAMEL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fuyu/device.hpp"

#include <core/assertion.hpp>
#include <core/collect.hpp>
#include <extension/khr_surface.hpp>
#include <extension/khr_swapchain.hpp>

#include "fuyu/allocation.hpp"
#include "fuyu/debug/name.hpp"
#include "fuyu/hardware.hpp"
#include "fuyu/instance.hpp"

namespace fubuki::fuyu
{

/********************************************************************************/
/*                                LOCAL CONSTANTS                               */
/********************************************************************************/

namespace
{

constexpr float default_queue_priority = +0.f;

struct intermediate_representation
{
    struct queue
    {
        using underlying_type = VkDeviceQueueCreateInfo;

        VkQueueFlags             type         = {};
        VkDeviceQueueCreateFlags flags        = {};
        std::uint32_t            family_index = {};
        std::uint32_t            count        = {};
        small_vector<float>      priorities   = {};

        [[nodiscard]] operator underlying_type() const noexcept
        {
            fubuki_assert(vk_size(priorities) == count, "Internal error. Sizes should match. Please open an issue.");

            return {.sType            = structure_type_v<VkDeviceQueueCreateInfo>,
                    .pNext            = nullptr,
                    .flags            = flags,
                    .queueFamilyIndex = family_index,
                    .queueCount       = count,
                    .pQueuePriorities = priorities.data()};
        }
    };

    small_flat_set<std::string> extensions = {};
    small_vector<queue>         queues     = {};
};

/// Generates the structures required to creates queues managed by the device.
/// @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
[[nodiscard]]
std::expected<small_vector<intermediate_representation::queue>, api_call_info>
make_queue_creators(const fuyu::instance& instance, physical_device_handle physical_device, const device::information::complements& complements)
{
    small_vector<intermediate_representation::queue> result;
    result.reserve(complements.queues.size() + complements.surfaces.size());

    const auto queue_properties = hardware::queue_properties(instance, physical_device);

    // Retrieve families for each queue requested by user
    {
        for(const auto& q : complements.queues)
        {
            const auto family = hardware::queue_family_index(queue_properties, q.type);

            if(not family.has_value())
            {
                return std::unexpected{
                    api_call_info{.result       = {VK_ERROR_FEATURE_NOT_PRESENT},
                                  .call_literal = "fuyu::hardware::queue_family_index - No queue available matching the requirements"_literal,
                                  .location     = std::source_location::current()}
                };
            }

            if(auto it
               = std::ranges::find_if(result, [family](const intermediate_representation::queue& i) noexcept { return i.family_index == *family; });
               it != result.end())
            {
                it->count += 1;
                it->priorities.emplace_back(q.priority);
            }
            else
            {
                result.emplace_back(intermediate_representation::queue{
                    .type = queue_properties[*family].queueFlags, .flags = q.flags, .family_index = *family, .count = 1, .priorities = {q.priority}});
            }
        }
    }

    // Retrieve queues supporting present operations for surfaces
    // Vulkan does not provide a separate queue type for 'present' operations,
    // so it HAS to be associated to another supporting that operation.
    for(const auto& surf : complements.surfaces)
    {
        const auto supports_present = [&instance, physical_device, s = surf](std::uint32_t family) noexcept -> std::expected<bool, api_call_info>
        { return extension::khr_surface::support(instance.function().ext, physical_device, s, family); };

        // First try: check if a queue already registered supports 'present' operation.
        bool already_requested = false;
        for(const auto& q : result)
        {
            const auto support = supports_present(q.family_index);

            if(not support.has_value())
            {
                return std::unexpected{support.error()};
            }

            if(*support)
            {
                already_requested = true;
                break; // Proceed to the next surface
            }
        }

        // Second try: find another type of queue supporting 'present' operation
        if(not already_requested)
        {
            bool found = false;

            for(std::size_t family = 0; family < queue_properties.size(); ++family)
            {
                const auto family_u32 = vk_size(family);

                const auto has_support = supports_present(family_u32);

                if(not has_support.has_value())
                {
                    return std::unexpected{has_support.error()};
                }

                if(*has_support)
                {
                    result.emplace_back(
                        intermediate_representation::queue{.type         = queue_properties[family].queueFlags,
                                                           .flags        = {},
                                                           .family_index = family_u32,
                                                           .count        = 1,
                                                           .priorities   = {default_queue_priority}}); // TODO: add support for custom priorities

                    found = true;
                    break; // Proceed to the next surface
                }
            }

            if(not found)
            {
                return std::unexpected{
                    api_call_info{.result       = {VK_ERROR_FEATURE_NOT_PRESENT},
                                  .call_literal = "fuyu::hardware::queue_family_index - No queue can present to one the surface provided"_literal,
                                  .location     = std::source_location::current()}
                };
            }
        }
    }

    return result;
}

[[nodiscard]]
std::expected<small_flat_set<std::string>, api_call_info>
validate_requested_extensions(const fuyu::instance&                                       instance,
                              physical_device_handle                                      physical_device,
                              const device::information::complements&                     complements,
                              std::optional<std::reference_wrapper<unsupported_features>> unsupported_features)
{
    const auto available_extensions = hardware::supported_extensions(instance, physical_device);

    if(not available_extensions.has_value())
    {
        return std::unexpected{available_extensions.error()};
    }

    small_flat_set<std::string> tmp;

    const auto add_if_supported = [&tmp, &available_extensions](std::string_view ext) noexcept -> bool
    {
        for(const auto& properties : available_extensions->properties)
        {
            if(properties.extensionName == ext) // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay
            {
                tmp.insert(ext);
                return true;
            }
        }

        return false;
    };

    add_if_supported(extension::khr_swapchain::name);

    for(const auto& ext : complements.extensions)
    {
        const auto available = add_if_supported(ext);
        if(not available and unsupported_features.has_value())
        {
            unsupported_features->get().extensions.hardware.insert(ext);
        }
    }

    return tmp;
}

[[nodiscard]] std::expected<intermediate_representation, api_call_info>
make_intermediate_representation(const fuyu::instance&                                       instance,
                                 physical_device_handle                                      physical_device,
                                 const device::information::complements&                     complements,
                                 std::optional<std::reference_wrapper<unsupported_features>> unsupported_features)
{
    intermediate_representation result = {};

    // Extensions
    {
        auto validated_extensions = validate_requested_extensions(instance, physical_device, complements, unsupported_features);

        if(not validated_extensions)
        {
            return std::unexpected{validated_extensions.error()};
        }

        result.extensions = *std::move(validated_extensions);
    }

    // Queues
    {
        auto queues = make_queue_creators(instance, physical_device, complements);

        if(not queues)
        {
            return std::unexpected{queues.error()};
        }

        result.queues = *std::move(queues);
    }

    return result;
}

} // anonymous namespace

/********************************************************************************/
/*                            PRIVATE MEMBER FUNCTIONS                          */
/********************************************************************************/

[[nodiscard]]
std::optional<api_call_info> device::create(const VkDeviceCreateInfo&                                   base_info,
                                            const information::complements&                             complements,
                                            std::optional<std::reference_wrapper<unsupported_features>> unsupported)
{
    // Vulkan version
    {
        m_vulkan_version = instance().info().application.vulkan_version;
    }

    const auto tmp_resources = make_intermediate_representation(m_parent, m_physical_device, complements, unsupported);

    if(not tmp_resources)
    {
        return tmp_resources.error();
    }

    // Handle
    if(m_handle == null_handle)
    {
        auto c_extension_names = tmp_resources->extensions | std::views::transform([](const auto& str) noexcept { return str.c_str(); });
        const small_vector<const char*> vk_extension_names = {c_extension_names.begin(), c_extension_names.end()};

        const auto vk_queue_create = collect<VkDeviceQueueCreateInfo>(small_span{tmp_resources->queues}.const_span());

        const VkDeviceCreateInfo device_info{.sType                   = structure_type_v<VkDeviceCreateInfo>,
                                             .pNext                   = base_info.pNext,
                                             .flags                   = base_info.flags,
                                             .queueCreateInfoCount    = vk_size(vk_queue_create),
                                             .pQueueCreateInfos       = vk_queue_create.data(),
                                             .enabledLayerCount       = 0,       // Deprecated and ignored anyway as none existed.
                                             .ppEnabledLayerNames     = nullptr, // Deprecated and ignored anyway as none existed.
                                             .enabledExtensionCount   = vk_size(vk_extension_names),
                                             .ppEnabledExtensionNames = vk_extension_names.data(),
                                             .pEnabledFeatures        = base_info.pEnabledFeatures};

        if(auto check = fuyu::create_handle(instance(), m_physical_device, device_info, m_info.callbacks))
        {
            m_handle = *check;
        }
        else
        {
            return check.error();
        }
    }

    // Functions
    {
        fuyu::load(m_functions, instance(), m_handle);
    }

    // Retrieve queues
    {
        for(const auto& q : tmp_resources->queues)
        {
            for(std::uint32_t const index : std::views::iota(0U, q.count))
            {
                auto& new_queue = m_queues.all.emplace_back(fuyu::queue{
                    .handle = {},
                    .device = *this,
                    .family = q.family_index,
                    .index  = index,
                    .type   = q.type,
                });

                m_functions.core.vk10.get_device_queue(m_handle.vk, new_queue.family, new_queue.index, std::addressof(new_queue.handle.vk));
                fubuki_assert(new_queue.handle != null_handle, "Failed to retrieve queue.");
            }
        }

        // Queues supporting present operations on the surfaces
        for(const auto& surf : complements.surfaces)
        {
            const auto supports_present = [this, s = surf](std::uint32_t family) noexcept -> std::expected<bool, api_call_info>
            { return extension::khr_surface::support(instance().function().ext, m_physical_device, s, family); };

            for(const auto& q : m_queues.all)
            {
                const auto has_support = supports_present(q.family);

                if(not has_support.has_value())
                {
                    return has_support.error();
                }

                if(*has_support)
                {
                    m_queues.presentable.emplace_back(presentable_queue{{q}, surf});
                }
            }
        }
    }

    // Extensions
    for(const auto& extension : tmp_resources->extensions)
    {
        const auto loaded = extension::load(m_functions.ext, instance(), instance().info().application.vulkan_version, m_handle, extension);

        if(not loaded and unsupported.has_value())
        {
            unsupported->get().extensions.loading.insert(extension);
        }
    }

    // Debug markers
    if(const auto check = debug::name_if_loaded(*this, m_handle, m_info.name.value_or("<Unnamed device>")); not check)
    {
        return check.error();
    }

    return {};
}

//------------------------------------------------------------------------------

void device::destroy() noexcept
{
    if(m_handle != null_handle)
    {
        fuyu::destroy_handle(instance(), m_handle, m_info.callbacks);
    }
}

//------------------------------------------------------------------------------

} // namespace fubuki::fuyu
