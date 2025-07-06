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

#include "extension/khr_performance_query.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_performance_query
{

#if defined(VK_KHR_performance_query)

[[nodiscard]]
lock_result acquire_profiling_lock(const functions& ext, device_handle device, const VkAcquireProfilingLockInfoKHR& info) noexcept
{
    return {static_cast<lock_result::code>(fubuki::invoke<"vkAcquireProfilingLockKHR">(ext, device.vk, std::addressof(info)))};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<std::uint32_t, api_call_info>
performance_counters_count(const functions& ext, physical_device_handle device, std::uint32_t queue_family) noexcept
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">(ext, device.vk, queue_family, &count, nullptr, nullptr));
                                              not check)
    {
        return std::unexpected{check.error()};
    }

    return count;
}

[[nodiscard]]
std::expected<std::vector<VkPerformanceCounterKHR>, api_call_info>
performance_counters_handle(const functions& ext, physical_device_handle device, std::uint32_t queue_family)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">(ext, device.vk, queue_family, &count, nullptr, nullptr));
                                              not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkPerformanceCounterKHR> counters;
    counters.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">(ext, device.vk, queue_family, &count, counters.data(), nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    return counters;
}

[[nodiscard]]
std::expected<std::vector<counter>, api_call_info>
performance_counters(const functions& ext, physical_device_handle device, std::uint32_t queue_family)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">(ext, device.vk, queue_family, &count, nullptr, nullptr));
                                              not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkPerformanceCounterKHR> counters;
    counters.resize(count);

    std::vector<VkPerformanceCounterDescriptionKHR> descriptions;
    descriptions.resize(count);

    std::vector<counter> result;
    result.reserve(count);

    if(const auto check = fubuki_validate(validate_by::expected,
        fubuki::invoke<"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">(ext, device.vk, queue_family, &count, counters.data(), descriptions.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    for(std::uint32_t i = 0; i < count; ++i)
    {
        result.emplace_back(counters[i], descriptions[i]);
    }

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::uint32_t pass_count_for_query_pool(const functions& ext, physical_device_handle device, const VkQueryPoolPerformanceCreateInfoKHR& info) noexcept
{
    std::uint32_t count = 0;

    fubuki::invoke<"vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR">(ext, device.vk, std::addressof(info), &count);

    return count;
}

//------------------------------------------------------------------------------

void release_profiling_lock(const functions& ext, device_handle device) noexcept
{
    return fubuki::invoke<"vkReleaseProfilingLockKHR">(ext, device.vk);
}

#endif // defined(VK_KHR_performance_query)

} // namespace fubuki::extension::khr_performance_query
