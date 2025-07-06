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

#include <ranges>

#include "fuyu/hardware.hpp"

#include <core/assertion.hpp>
#include <core/collect.hpp>
#include <core/validate.hpp>
#include <fuyu/instance.hpp>

#include "fuyu/views/instance.hpp"

extern "C"
{

// Extracted from vulkan_core.h (Apache 2.0)
// Allows to compile with VK_NO_PROTOTYPES

// NOLINTBEGIN(readability-identifier-naming)
extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                             uint32_t*              pPropertyCount,
                                                                             VkExtensionProperties* pProperties);
// NOLINTEND(readability-identifier-naming)

} // extern "C"

namespace fubuki::fuyu::hardware
{

[[nodiscard]]
std::expected<std::uint32_t, api_call_info> physical_device_count(instance_view instance) noexcept
{
    fubuki_assert(instance.handle != null_handle, "Instance must not be nullptr.");
    fubuki_assert(instance->vk10.enumerate_physical_devices != nullptr, "Instance functions must be loaded.");

    std::uint32_t count = 0;

    if(auto check = fubuki_validate(validate_by::expected, instance->vk10.enumerate_physical_devices(instance.handle.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    return count;
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<small_vector<physical_device_handle>, api_call_info> physical_devices(instance_view instance) noexcept
{
    std::uint32_t count = 0;

    if(const auto check = physical_device_count(instance))
    {
        count = *check;
    }
    else
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkPhysicalDevice> result(count);

    if(const auto check
       = fubuki_validate(validate_by::expected, instance->vk10.enumerate_physical_devices(instance.handle.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<physical_device_handle>{result.begin(), result.end()};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<extension_support, api_call_info> supported_extensions(instance_view instance, physical_device_handle device) noexcept
{
    fubuki_assert(instance.handle != null_handle, "Instance must not be nullptr.");
    fubuki_assert(instance->vk10.enumerate_device_extension_properties != nullptr, "Instance functions must be loaded.");

    extension_support result;

    std::uint32_t count = 0;
    if(auto check
       = fubuki_validate(validate_by::expected, instance->vk10.enumerate_device_extension_properties(device.vk, nullptr, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    result.properties.resize(count);

    if(auto check = fubuki_validate(validate_by::expected, instance->vk10.enumerate_device_extension_properties(device.vk, nullptr, &count, result.properties.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    const auto names
        = result.properties | std::views::transform([](const auto& prop) -> std::string { return static_cast<const char*>(prop.extensionName); });

    result.names.insert_range(names);

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]] std::expected<extension_support, api_call_info> supported_instance_extensions(const char* layer)
{
    extension_support result;

    std::uint32_t count = 0;

    if(auto check = fubuki_validate(validate_by::expected, vkEnumerateInstanceExtensionProperties(layer, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    result.properties.resize(count);

    if(auto check = fubuki_validate(validate_by::expected, vkEnumerateInstanceExtensionProperties(layer, &count, result.properties.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    auto names
        = result.properties | std::views::transform([](const auto& prop) -> std::string { return static_cast<const char*>(prop.extensionName); });

    result.names.insert_range(names);

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]] FUBUKI_SEMI_PURE std::optional<std::uint32_t> queue_family_index(const std::span<const VkQueueFamilyProperties> properties,
                                                                               const VkQueueFlags                             flags) noexcept
{
    /*
     * Adapted from Sacha Willems VulkanDevice function getQueueFamilyIndex.
     *
     * (https://github.com/SaschaWillems/Vulkan/blob/master/base/VulkanDevice.cpp)
     *
     * Copyright (C) by Sascha Willems - www.saschawillems.de
     *
     * This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
     */

    // Dedicated queue for compute
    // Try to find a queue family index that supports compute but not graphics
    if(flags & VK_QUEUE_COMPUTE_BIT)
    {
        for(std::uint32_t i = 0; i < vk_size(properties); i++)
        {
            if(((properties[i].queueFlags & flags) != 0) && ((properties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0))
            {
                return i;
            }
        }
    }

    // Dedicated queue for transfer
    // Try to find a queue family index that supports transfer but not graphics and compute
    if(flags & VK_QUEUE_TRANSFER_BIT)
    {
        for(std::uint32_t i = 0; i < vk_size(properties); i++)
        {
            if(((properties[i].queueFlags & flags) != 0) && ((properties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0)
               && ((properties[i].queueFlags & VK_QUEUE_COMPUTE_BIT) == 0))
            {
                return i;
            }
        }
    }

    // For other queue types or if no separate compute queue is present, return the first one to support the requested
    // flags
    for(std::uint32_t i = 0; i < vk_size(properties); i++)
    {
        if(properties[i].queueFlags & flags)
        {
            return i;
        }
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
small_vector<VkQueueFamilyProperties> queue_properties(instance_view instance, physical_device_handle device) noexcept
{
    fubuki_assert(instance.handle != null_handle, "Instance must not be nullptr.");
    fubuki_assert(instance->vk10.get_physical_device_queue_family_properties != nullptr, "Instance functions must be loaded.");

    std::uint32_t queue_count = 0;
    {
        instance->vk10.get_physical_device_queue_family_properties(device.vk, &queue_count, nullptr);
    }

    small_vector<VkQueueFamilyProperties> queue_properties(queue_count);
    {
        instance->vk10.get_physical_device_queue_family_properties(device.vk, &queue_count, queue_properties.data());
    }

    return queue_properties;
}

//------------------------------------------------------------------------------

[[nodiscard]] small_vector<VkQueueFamilyProperties> queue_properties(device_view d) noexcept
{
    return queue_properties(d.instance.get(), d.hardware);
}

//------------------------------------------------------------------------------

#if defined(VK_VERSION_1_1)

[[nodiscard]]
VkExternalBufferProperties
external_buffer_properties(instance_view instance, physical_device_handle device, const VkPhysicalDeviceExternalBufferInfo& info) noexcept
{
    fubuki_assert(instance.handle != null_handle, "Instance must not be nullptr.");
    fubuki_assert((instance.version >= version_number{1, 1, 0}), "Attempting to use a Vulkan 1.1 function, but instance is using a lower version.");
    fubuki_assert(instance->vk11.get_physical_device_external_buffer_properties != nullptr, "Instance functions must be loaded.");

    VkExternalBufferProperties result = {};
    instance->vk11.get_physical_device_external_buffer_properties(device.vk, std::addressof(info), std::addressof(result));
    return result;
}

#endif // defined(VK_VERSION_1_1)

//------------------------------------------------------------------------------

[[nodiscard]] FUBUKI_SEMI_PURE std::optional<std::uint32_t>
memory_index(const VkPhysicalDeviceMemoryProperties& properties, std::uint32_t type, const VkMemoryPropertyFlags flags) noexcept
{
    // Original code from Sacha Willems - www.saschawillems.de
    // From https://github.com/SaschaWillems/Vulkan/blob/master/base/VulkanDevice.cpp
    // Available under MIT license (http://opensource.org/licenses/MIT).

    for(std::uint32_t index = 0; index < properties.memoryTypeCount; index++)
    {
        if(((type & 1) == 1))
        {
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
            // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
            if(((properties.memoryTypes[index].propertyFlags & flags) == flags))
            {
                return index;
            }

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
        }

        type >>= 1;
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]] FUBUKI_SEMI_PURE std::optional<std::uint32_t>
                               memory_index(device_view d, const VkMemoryRequirements& requirements, VkMemoryPropertyFlags flags) noexcept
{
    VkPhysicalDeviceMemoryProperties properties = {};
    fuyu::instance_view const        i          = d.instance.get();

    fubuki_assert(i->vk10.get_physical_device_memory_properties != nullptr, "Instance functions must be loaded.");

    i->vk10.get_physical_device_memory_properties(d.hardware.vk, std::addressof(properties));

    return memory_index(properties, requirements, flags);
}

} // namespace fubuki::fuyu::hardware
