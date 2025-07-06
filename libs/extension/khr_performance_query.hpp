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

#ifndef FUBUKI_EXTENSION_KHR_PERFORMANCE_QUERY_HPP
#define FUBUKI_EXTENSION_KHR_PERFORMANCE_QUERY_HPP

#include <vector>

#include <core/compare/performance_counter_description_khr.hpp>
#include <core/compare/performance_counter_khr.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_performance_query.hpp" // IWYU pragma: export

/**
 * The VK_KHR_performance_query extension adds a mechanism to allow querying of performance counters for use in applications and by profiling tools.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_KHR_performance_query.html
 */
namespace fubuki::extension::khr_performance_query
{

/// Performance counter.
struct counter
{
#if defined(VK_KHR_performance_query)
    VkPerformanceCounterKHR            handle;      ///< Underlying handle.
    VkPerformanceCounterDescriptionKHR description; ///< Counter description.

    [[nodiscard]] constexpr operator VkPerformanceCounterKHR&() { return handle; }
    [[nodiscard]] constexpr operator const VkPerformanceCounterKHR&() const { return handle; }
    [[nodiscard]] constexpr operator VkPerformanceCounterDescriptionKHR&() { return description; }
    [[nodiscard]] constexpr operator const VkPerformanceCounterDescriptionKHR&() const { return description; }

    [[nodiscard]] friend constexpr bool operator==(const counter& a, const counter& b) noexcept
    {
        return a.handle == b.handle and a.description == b.description;
    }

    [[nodiscard]] friend constexpr bool operator!=(const counter& a, const counter& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr auto operator<=>(const counter& a, const counter& b) noexcept
    {
        if(const auto cmp = a.handle <=> b.handle; cmp != std::strong_ordering::equivalent)
        {
            return cmp;
        }

        if(const auto cmp = a.description <=> b.description; cmp != std::strong_ordering::equivalent)
        {
            return cmp;
        }

        return std::strong_ordering::equivalent;
    }

#endif // defined(VK_KHR_performance_query)
};

/// Result of acquire_profiling_lock().
struct lock_result
{
    /// Restriction of VkResult codes that can be returned by acquire_profiling_lock().
    enum class code
    {
        success = VK_SUCCESS,

        out_of_memory = VK_ERROR_OUT_OF_HOST_MEMORY,
        timeout       = VK_TIMEOUT,
    };

    code value; ///< Return code.

    [[nodiscard]]
    inline constexpr operator code() const noexcept
    {
        return value;
    }

    [[nodiscard]]
    inline constexpr operator VkResult() const noexcept
    {
        return static_cast<VkResult>(value);
    }
};

#if defined(VK_KHR_performance_query)

/**
 * Acquires the profiling lock.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkAcquireProfilingLockKHR.html
 */
[[nodiscard]] FUBUKI_EXTENSION_API lock_result acquire_profiling_lock(const functions&                     ext,
                                                                      device_handle                        device,
                                                                      const VkAcquireProfilingLockInfoKHR& info) noexcept;

//------------------------------------------------------------------------------

/**
 * Reports the count of query counters available on a queue family of a device.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR.html
 */
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::uint32_t, api_call_info>
performance_counters_count(const functions& ext, physical_device_handle device, std::uint32_t queue_family) noexcept;

/**
 * Reports handles of query counters available on a queue family of a device.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR.html
 */
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkPerformanceCounterKHR>, api_call_info>
                                   performance_counters_handle(const functions& ext, physical_device_handle device, std::uint32_t queue_family);

/**
 * Reports properties of the performance query counters available on a queue family of a device.
 * This overload queries the detailed descriptions.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR.html
 */
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<counter>, api_call_info>
                                   performance_counters(const functions& ext, physical_device_handle device, std::uint32_t queue_family);

//------------------------------------------------------------------------------

/**
 * Reports the number of passes require for a performance query pool type
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR.html
 */
[[nodiscard]] FUBUKI_EXTENSION_API std::uint32_t
pass_count_for_query_pool(const functions& ext, physical_device_handle device, const VkQueryPoolPerformanceCreateInfoKHR& info) noexcept;

//------------------------------------------------------------------------------

/**
 * Releases the profiling lock
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseProfilingLockKHR.html
 */
FUBUKI_EXTENSION_API
void release_profiling_lock(const functions& ext, device_handle device) noexcept;

#endif // defined(VK_KHR_performance_query)

} // namespace fubuki::extension::khr_performance_query

#endif // FUBUKI_EXTENSION_KHR_PERFORMANCE_QUERY_HPP
