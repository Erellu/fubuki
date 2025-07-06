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

#include "extension/nv_low_latency2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::nv_low_latency2
{

#if defined(VK_NV_low_latency2)

[[nodiscard]]
std::expected<void, api_call_info> set_latency_sleep_mode(const functions&                ext,
                                                          device_handle                   device,
                                                          swapchain_khr_handle            swapchain,
                                                          const VkLatencySleepModeInfoNV& sleep_mode_info) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkSetLatencySleepModeNV">(ext, device.vk, swapchain.vk, std::addressof(sleep_mode_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info>
latency_sleep(const functions& ext, device_handle device, swapchain_khr_handle swapchain, const VkLatencySleepInfoNV& sleep_info) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkLatencySleepNV">(ext, device.vk, swapchain.vk, std::addressof(sleep_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

void set_latency_marker(const functions&                ext,
                        device_handle                   device,
                        swapchain_khr_handle            swapchain,
                        const VkSetLatencyMarkerInfoNV& latency_marker_info) noexcept
{
    return fubuki::invoke<"vkSetLatencyMarkerNV">(ext, device.vk, swapchain.vk, std::addressof(latency_marker_info));
}

void get_latency_timings(const functions&          ext,
                         device_handle             device,
                         swapchain_khr_handle      swapchain,
                         VkGetLatencyMarkerInfoNV& latency_marker_info) noexcept
{
    return fubuki::invoke<"vkGetLatencyTimingsNV">(ext, device.vk, swapchain.vk, std::addressof(latency_marker_info));
}

void queue_notify_out_of_band(const functions& ext, queue_handle queue, const VkOutOfBandQueueTypeInfoNV& queue_type_info) noexcept
{
    return fubuki::invoke<"vkQueueNotifyOutOfBandNV">(ext, queue.vk, &queue_type_info);
}

#endif // defined(VK_NV_low_latency2)

} // namespace fubuki::extension::nv_low_latency2
