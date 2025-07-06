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

#include "fuyu/instance.hpp"

#include <core/assertion.hpp>
#include <core/collect.hpp>
#include <extension/ext_debug_utils.hpp>
#include <extension/khr_surface.hpp>

#include "fuyu/allocation.hpp"
#include "fuyu/debug/layers.hpp"
#include "fuyu/hardware.hpp"

namespace fubuki::fuyu
{

namespace
{

[[nodiscard]] std::expected<small_flat_set<std::string>, api_call_info>
validate_requested_extensions(const instance::information::complements&                   complements,
                              std::optional<std::reference_wrapper<unsupported_features>> unsupported)
{
    small_flat_set<std::string> result;

    // Validation layers
    if(not complements.layers.empty())
    {
        result.emplace(extension::ext_debug_utils::name);
    }

    // Surface
    {
        result.emplace(extension::khr_surface::name);
        result.insert_range(extension::khr_surface::surface_extensions);
    }

    // User requests
    {
        result.insert_range(complements.extensions);
    }

    const auto available_extensions = hardware::supported_instance_extensions();

    if(not available_extensions)
    {
        return std::unexpected{available_extensions.error()};
    }

    const auto copy = result;

    for(const auto& ext : copy)
    {
        // NOLINTBEGIN(cppcoreguidelines-pro-bounds-array-to-pointer-decay)
        const bool available = std::ranges::find_if(available_extensions->properties,
                                                    [&ext](const VkExtensionProperties& properties) constexpr noexcept
                                                    { return (std::string_view{properties.extensionName} == ext); })
            != available_extensions->properties.end();
        // NOLINTEND(cppcoreguidelines-pro-bounds-array-to-pointer-decay)

        if(not available)
        {
            result.erase(ext);

            if(unsupported.has_value())
            {
                unsupported->get().extensions.hardware.insert(ext);
            }
        }
    }

    return result;
}

struct intermediate_representation
{
    small_flat_set<std::string> extensions = {};
};

[[nodiscard]] std::expected<intermediate_representation, api_call_info>
make_intermediate_representation(const instance::information::complements&                   complements,
                                 std::optional<std::reference_wrapper<unsupported_features>> unsupported)
{
    intermediate_representation result = {};

    // Extensions
    {
        auto ext = validate_requested_extensions(complements, unsupported);

        if(not ext)
        {
            return std::unexpected{ext.error()};
        }

        result.extensions = *std::move(ext);
    }

    return result;
}

} // anonymous namespace

/********************************************************************************/
/*                            PRIVATE MEMBER FUNCTIONS                          */
/********************************************************************************/

[[nodiscard]]
std::optional<api_call_info> instance::create(const VkInstanceCreateInfo&                                 info,
                                              const information::complements&                             complements,
                                              std::optional<std::reference_wrapper<unsupported_features>> unsupported)
{
    const auto tmp = make_intermediate_representation(complements, unsupported);

    if(not tmp)
    {
        return tmp.error();
    }

    // Handle creation
    if(m_handle == null_handle)
    {
        const VkApplicationInfo app_info = {
            .sType              = structure_type_v<VkApplicationInfo>,
            .pNext              = nullptr,
            .pApplicationName   = m_info.application.name.c_str(),
            .applicationVersion = m_info.application.version,
            .pEngineName        = m_info.application.engine.name.c_str(),
            .engineVersion      = m_info.application.engine.version,
            .apiVersion         = m_info.application.vulkan_version,
        };

        const auto vk_layers_name    = debug::validate_layers(complements.layers);
        auto       c_extension_names = tmp->extensions | std::views::transform([](const auto& str) noexcept { return str.c_str(); });
        const small_vector<const char*> vk_extension_names = {c_extension_names.begin(), c_extension_names.end()};

        const VkInstanceCreateInfo instance_info = {
            .sType                   = structure_type_v<VkInstanceCreateInfo>,
            .pNext                   = info.pNext,
            .flags                   = m_info.flags,
            .pApplicationInfo        = std::addressof(app_info),
            .enabledLayerCount       = vk_size(vk_layers_name),
            .ppEnabledLayerNames     = vk_layers_name.data(),
            .enabledExtensionCount   = vk_size(vk_extension_names),
            .ppEnabledExtensionNames = vk_extension_names.empty() ? nullptr : vk_extension_names.data(),
        };

        if(auto success = fuyu::create_handle(instance_info, m_info.callbacks))
        {
            m_handle = *success;
        }
        else
        {
            return success.error();
        }
    }

    // Functions
    {
        // TODO: append to unsupported_features?
        fuyu::load(m_functions, m_handle, m_info.application.vulkan_version);
    }

    // Extensions to load
    for(const auto& extension : tmp->extensions)
    {
        const auto loaded = extension::load(m_functions.ext, m_handle, m_info.application.vulkan_version, extension);

        if(not loaded and unsupported.has_value())
        {
            unsupported->get().extensions.loading.insert(extension);
        }
    }

    return {};
}

//------------------------------------------------------------------------------

void instance::destroy() noexcept
{
    if(m_handle != null_handle)
    {
        fuyu::destroy_handle(m_handle, m_info.callbacks);
    }
}

//------------------------------------------------------------------------------

} // namespace fubuki::fuyu
