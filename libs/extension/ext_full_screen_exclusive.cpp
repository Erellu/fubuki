﻿/*
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

#include "extension/ext_full_screen_exclusive.hpp"

#include <core/invoke.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::ext_full_screen_exclusive
{

#if defined(VK_EXT_full_screen_exclusive)

[[nodiscard]]
std::expected<small_vector<VkPresentModeKHR>, api_call_info> get_physical_device_surface_present_modes(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceSurfaceInfo2KHR& surface_info)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfacePresentModes2EXT">(ext, physical_device.vk, &surface_info, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkPresentModeKHR> result(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfacePresentModes2EXT">(ext, physical_device.vk, &surface_info, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<void, api_call_info>
acquire_full_screen_exclusive_mode(const functions& ext, device_handle device, swapchain_khr_handle swapchain) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkAcquireFullScreenExclusiveModeEXT">(ext, device.vk, swapchain.vk));
}

[[nodiscard]]
std::expected<void, api_call_info>
release_full_screen_exclusive_mode(const functions& ext, device_handle device, swapchain_khr_handle swapchain) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkReleaseFullScreenExclusiveModeEXT">(ext, device.vk, swapchain.vk));
}

[[nodiscard]]
std::expected<VkDeviceGroupPresentModeFlagsKHR, api_call_info>
get_device_group_surface_present_modes(const functions& ext, device_handle device, const VkPhysicalDeviceSurfaceInfo2KHR& surface_info) noexcept
{
    VkDeviceGroupPresentModeFlagsKHR result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDeviceGroupSurfacePresentModes2EXT">(ext, device.vk, &surface_info, &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_EXT_full_screen_exclusive)

} // namespace fubuki::extension::ext_full_screen_exclusive
