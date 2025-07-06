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

#include "extension/khr_get_physical_device_properties2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_get_physical_device_properties2
{

#if defined(VK_KHR_get_physical_device_properties2)

namespace detail
{

void get_physical_device_memory_properties2(const functions&                   ext,
                                            physical_device_handle             physical_device,
                                            VkPhysicalDeviceMemoryProperties2& result) noexcept
{
    fubuki::invoke<"vkGetPhysicalDeviceMemoryProperties2KHR">(ext, physical_device.vk, std::addressof(result));
}

[[nodiscard]]
std::optional<api_call_info> get_physical_device_image_format_properties2(const functions&                        ext,
                                                                          physical_device_handle                  physical_device,
                                                                          const VkPhysicalDeviceImageFormatInfo2& image_format_info,
                                                                          VkImageFormatProperties2&               result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceImageFormatProperties2KHR">(ext, physical_device.vk, &image_format_info, std::addressof(result))); not check)
    {
        return check.error();
    }

    return {};
}

void get_physical_device_format_properties2(const functions&       ext,
                                            physical_device_handle physical_device,
                                            VkFormat               format,
                                            VkFormatProperties2&   result) noexcept
{
    return fubuki::invoke<"vkGetPhysicalDeviceFormatProperties2KHR">(ext, physical_device.vk, format, std::addressof(result));
}

void get_physical_device_properties2(const functions& ext, physical_device_handle physical_device, VkPhysicalDeviceProperties2& result) noexcept
{
    return fubuki::invoke<"vkGetPhysicalDeviceProperties2KHR">(ext, physical_device.vk, std::addressof(result));
}

void get_physical_device_features2(const functions& ext, physical_device_handle physical_device, VkPhysicalDeviceFeatures2& result) noexcept
{
    return fubuki::invoke<"vkGetPhysicalDeviceFeatures2KHR">(ext, physical_device.vk, std::addressof(result));
}

} // namespace detail

[[nodiscard]] std::vector<VkQueueFamilyProperties2> get_physical_device_queue_family_properties2(const functions&       ext,
                                                                                                 physical_device_handle physical_device)
{
    std::uint32_t count = 0;

    fubuki::invoke<"vkGetPhysicalDeviceQueueFamilyProperties2KHR">(ext, physical_device.vk, &count, nullptr);

    std::vector<VkQueueFamilyProperties2> result;
    result.resize(count);

    fubuki::invoke<"vkGetPhysicalDeviceQueueFamilyProperties2KHR">(ext, physical_device.vk, &count, result.data());

    return result;
}

[[nodiscard]]
std::vector<VkSparseImageFormatProperties2> get_physical_device_sparse_image_format_properties2(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceSparseImageFormatInfo2& format_info)
{
    std::uint32_t count = 0;

    fubuki::invoke<"vkGetPhysicalDeviceSparseImageFormatProperties2KHR">(ext, physical_device.vk, &format_info, &count, nullptr);

    std::vector<VkSparseImageFormatProperties2> result;
    result.resize(count);

    fubuki::invoke<"vkGetPhysicalDeviceSparseImageFormatProperties2KHR">(ext, physical_device.vk, &format_info, &count, result.data());

    return result;
}

#endif // defined(VK_KHR_get_physical_device_properties2)

} // namespace fubuki::extension::khr_get_physical_device_properties2
