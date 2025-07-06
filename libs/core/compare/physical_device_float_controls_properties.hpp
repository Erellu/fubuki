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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_2)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceFloatControlsProperties& a,
                                               const VkPhysicalDeviceFloatControlsProperties& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.denormBehaviorIndependence, b.denormBehaviorIndependence)
        and equal(a.roundingModeIndependence, b.roundingModeIndependence)
        and equal(a.shaderSignedZeroInfNanPreserveFloat16, b.shaderSignedZeroInfNanPreserveFloat16)
        and equal(a.shaderSignedZeroInfNanPreserveFloat32, b.shaderSignedZeroInfNanPreserveFloat32)
        and equal(a.shaderSignedZeroInfNanPreserveFloat64, b.shaderSignedZeroInfNanPreserveFloat64)
        and equal(a.shaderDenormPreserveFloat16, b.shaderDenormPreserveFloat16)
        and equal(a.shaderDenormPreserveFloat32, b.shaderDenormPreserveFloat32)
        and equal(a.shaderDenormPreserveFloat64, b.shaderDenormPreserveFloat64)
        and equal(a.shaderDenormFlushToZeroFloat16, b.shaderDenormFlushToZeroFloat16)
        and equal(a.shaderDenormFlushToZeroFloat32, b.shaderDenormFlushToZeroFloat32)
        and equal(a.shaderDenormFlushToZeroFloat64, b.shaderDenormFlushToZeroFloat64)
        and equal(a.shaderRoundingModeRTEFloat16, b.shaderRoundingModeRTEFloat16)
        and equal(a.shaderRoundingModeRTEFloat32, b.shaderRoundingModeRTEFloat32)
        and equal(a.shaderRoundingModeRTEFloat64, b.shaderRoundingModeRTEFloat64)
        and equal(a.shaderRoundingModeRTZFloat16, b.shaderRoundingModeRTZFloat16)
        and equal(a.shaderRoundingModeRTZFloat32, b.shaderRoundingModeRTZFloat32)
        and equal(a.shaderRoundingModeRTZFloat64, b.shaderRoundingModeRTZFloat64);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceFloatControlsProperties& a,
                                               const VkPhysicalDeviceFloatControlsProperties& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceFloatControlsProperties& a,
                                                const VkPhysicalDeviceFloatControlsProperties& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.sType)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.sType, b.sType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pNext, b.pNext)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.denormBehaviorIndependence, b.denormBehaviorIndependence));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.roundingModeIndependence, b.roundingModeIndependence)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSignedZeroInfNanPreserveFloat16, b.shaderSignedZeroInfNanPreserveFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSignedZeroInfNanPreserveFloat32, b.shaderSignedZeroInfNanPreserveFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSignedZeroInfNanPreserveFloat64, b.shaderSignedZeroInfNanPreserveFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormPreserveFloat16, b.shaderDenormPreserveFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormPreserveFloat32, b.shaderDenormPreserveFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormPreserveFloat64, b.shaderDenormPreserveFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormFlushToZeroFloat16, b.shaderDenormFlushToZeroFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormFlushToZeroFloat32, b.shaderDenormFlushToZeroFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormFlushToZeroFloat64, b.shaderDenormFlushToZeroFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTEFloat16, b.shaderRoundingModeRTEFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTEFloat32, b.shaderRoundingModeRTEFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTEFloat64, b.shaderRoundingModeRTEFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTZFloat16, b.shaderRoundingModeRTZFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTZFloat32, b.shaderRoundingModeRTZFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTZFloat64, b.shaderRoundingModeRTZFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceFloatControlsProperties& a, const VkPhysicalDeviceFloatControlsProperties& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceFloatControlsProperties (&a)[N], const VkPhysicalDeviceFloatControlsProperties (&b)[N]) noexcept
{
    return std::ranges::equal(
        a,
        b,
        [](const VkPhysicalDeviceFloatControlsProperties& x, const VkPhysicalDeviceFloatControlsProperties& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceFloatControlsProperties>
{
    using type = decltype(VkPhysicalDeviceFloatControlsProperties{} <=> VkPhysicalDeviceFloatControlsProperties{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceFloatControlsProperties& a, const VkPhysicalDeviceFloatControlsProperties& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceFloatControlsProperties (&a)[N],
                                        const VkPhysicalDeviceFloatControlsProperties (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(a,
                                                    b,
                                                    [](const VkPhysicalDeviceFloatControlsProperties& x,
                                                       const VkPhysicalDeviceFloatControlsProperties& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_2)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_HPP
