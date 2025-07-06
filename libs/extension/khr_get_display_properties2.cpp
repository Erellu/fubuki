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

#include "extension/khr_get_display_properties2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_get_display_properties2
{

#if defined(VK_KHR_get_display_properties2)

namespace detail
{

std::optional<api_call_info> get_display_plane_capabilities(const functions&                ext,
                                                            physical_device_handle          physical_device,
                                                            const VkDisplayPlaneInfo2KHR&   display_plane_info,
                                                            VkDisplayPlaneCapabilities2KHR& result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayPlaneCapabilities2KHR">(ext, physical_device.vk, &display_plane_info, &result)); not check)
    {
        return check.error();
    }

    return {};
}

} // namespace detail

[[nodiscard]]
std::expected<std::vector<VkDisplayProperties2KHR>, api_call_info> get_physical_device_display_properties(const functions&       ext,
                                                                                                          physical_device_handle physical_device)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayProperties2KHR">(ext, physical_device.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkDisplayProperties2KHR> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayProperties2KHR">(ext, physical_device.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<std::vector<VkDisplayPlaneProperties2KHR>, api_call_info>
get_physical_device_display_plane_properties(const functions& ext, physical_device_handle physical_device)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayPlaneProperties2KHR">(ext, physical_device.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkDisplayPlaneProperties2KHR> result;
    result.resize(count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayPlaneProperties2KHR">(ext, physical_device.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<std::vector<VkDisplayModeProperties2KHR>, api_call_info>
get_display_mode_properties(const functions& ext, physical_device_handle physical_device, display_khr_handle display)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayModeProperties2KHR">(ext, physical_device.vk, display.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkDisplayModeProperties2KHR> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayModeProperties2KHR">(ext, physical_device.vk, display.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_KHR_get_display_properties2)

} // namespace fubuki::extension::khr_get_display_properties2
