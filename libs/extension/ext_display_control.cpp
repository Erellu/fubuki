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

#include "extension/ext_display_control.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::ext_display_control
{

#if defined(VK_EXT_display_control)

[[nodiscard]]
std::expected<void, api_call_info> display_power_control(const functions&             ext,
                                                         device_handle                device,
                                                         display_khr_handle           display,
                                                         const VkDisplayPowerInfoEXT& display_power_info) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkDisplayPowerControlEXT">(ext, device.vk, display.vk, std::addressof(display_power_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<fence_handle, api_call_info>
register_device_event(const functions& ext, device_handle device, const VkDeviceEventInfoEXT& device_event_info) noexcept
{
    fence_handle fence;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkRegisterDeviceEventEXT">(ext, device.vk, &device_event_info, nullptr, &fence.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return fence;
}

[[nodiscard]]
std::expected<fence_handle, api_call_info> register_device_event(const functions&             ext,
                                                                 device_handle                device,
                                                                 const VkDeviceEventInfoEXT&  device_event_info,
                                                                 const VkAllocationCallbacks& allocator) noexcept
{
    fence_handle fence;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkRegisterDeviceEventEXT">(ext, device.vk, std::addressof(device_event_info), std::addressof(allocator), &fence.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return fence;
}

[[nodiscard]]
std::expected<fence_handle, api_call_info> register_display_event(const functions&             ext,
                                                                  device_handle                device,
                                                                  display_khr_handle           display,
                                                                  const VkDisplayEventInfoEXT& display_event_info) noexcept
{
    fence_handle fence;

    if(const auto check
       = fubuki_validate(validate_by::expected,  fubuki::invoke<"vkRegisterDisplayEventEXT">(ext, device.vk, display.vk, &display_event_info, nullptr, &fence.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return fence;
}

[[nodiscard]]
std::expected<fence_handle, api_call_info> register_display_event(const functions&             ext,
                                                                  device_handle                device,
                                                                  display_khr_handle           display,
                                                                  const VkDisplayEventInfoEXT& display_event_info,
                                                                  const VkAllocationCallbacks& allocator) noexcept
{
    fence_handle fence;

    if(const auto check = fubuki_validate(validate_by::expected,  fubuki::invoke<"vkRegisterDisplayEventEXT">(ext, device.vk, display.vk, &display_event_info, std::addressof(allocator), &fence.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return fence;
}

[[nodiscard]]
std::expected<std::uint64_t, api_call_info>
get_swapchain_counter(const functions& ext, device_handle device, swapchain_khr_handle swapchain, VkSurfaceCounterFlagBitsEXT counter) noexcept
{
    std::uint64_t result = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetSwapchainCounterEXT">(ext, device.vk, swapchain.vk, counter, &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_EXT_display_control)

} // namespace fubuki::extension::ext_display_control
