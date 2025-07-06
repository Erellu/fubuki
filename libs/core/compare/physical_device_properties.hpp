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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_PROPERTIES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_PROPERTIES_HPP

#include "core/compare/physical_device_limits.hpp"            // IWYU pragma: keep
#include "core/compare/physical_device_sparse_properties.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"                            // IWYU pragma: keep
#include "core/vulkan.hpp"                                    // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_0)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceProperties& a, const VkPhysicalDeviceProperties& b) noexcept
{
    using detail::compare::equal;
    return equal(a.apiVersion, b.apiVersion) and equal(a.driverVersion, b.driverVersion) and equal(a.vendorID, b.vendorID)
        and equal(a.deviceID, b.deviceID) and equal(a.deviceType, b.deviceType) and equal(a.deviceName, b.deviceName)
        and equal(a.pipelineCacheUUID, b.pipelineCacheUUID) and equal(a.limits, b.limits) and equal(a.sparseProperties, b.sparseProperties);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceProperties& a, const VkPhysicalDeviceProperties& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceProperties& a, const VkPhysicalDeviceProperties& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.apiVersion)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.apiVersion, b.apiVersion)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.driverVersion, b.driverVersion)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vendorID, b.vendorID)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.deviceID, b.deviceID)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.deviceType, b.deviceType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.deviceName, b.deviceName)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineCacheUUID, b.pipelineCacheUUID)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.limits, b.limits)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseProperties, b.sparseProperties)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceProperties& a, const VkPhysicalDeviceProperties& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceProperties (&a)[N], const VkPhysicalDeviceProperties (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceProperties& x, const VkPhysicalDeviceProperties& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceProperties>
{
    using type = decltype(VkPhysicalDeviceProperties{} <=> VkPhysicalDeviceProperties{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceProperties& a, const VkPhysicalDeviceProperties& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceProperties (&a)[N], const VkPhysicalDeviceProperties (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceProperties& x, const VkPhysicalDeviceProperties& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_0)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_PROPERTIES_HPP
