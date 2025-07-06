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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT2_FEATURES_EXT_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT2_FEATURES_EXT_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_EXT_shader_atomic_float2)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& a,
                                               const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.shaderBufferFloat16Atomics, b.shaderBufferFloat16Atomics)
        and equal(a.shaderBufferFloat16AtomicAdd, b.shaderBufferFloat16AtomicAdd)
        and equal(a.shaderBufferFloat16AtomicMinMax, b.shaderBufferFloat16AtomicMinMax)
        and equal(a.shaderBufferFloat32AtomicMinMax, b.shaderBufferFloat32AtomicMinMax)
        and equal(a.shaderBufferFloat64AtomicMinMax, b.shaderBufferFloat64AtomicMinMax)
        and equal(a.shaderSharedFloat16Atomics, b.shaderSharedFloat16Atomics)
        and equal(a.shaderSharedFloat16AtomicAdd, b.shaderSharedFloat16AtomicAdd)
        and equal(a.shaderSharedFloat16AtomicMinMax, b.shaderSharedFloat16AtomicMinMax)
        and equal(a.shaderSharedFloat32AtomicMinMax, b.shaderSharedFloat32AtomicMinMax)
        and equal(a.shaderSharedFloat64AtomicMinMax, b.shaderSharedFloat64AtomicMinMax)
        and equal(a.shaderImageFloat32AtomicMinMax, b.shaderImageFloat32AtomicMinMax)
        and equal(a.sparseImageFloat32AtomicMinMax, b.sparseImageFloat32AtomicMinMax);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& a,
                                               const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& a,
                                                const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderBufferFloat16Atomics, b.shaderBufferFloat16Atomics));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderBufferFloat16AtomicAdd, b.shaderBufferFloat16AtomicAdd));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderBufferFloat16AtomicMinMax, b.shaderBufferFloat16AtomicMinMax));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderBufferFloat32AtomicMinMax, b.shaderBufferFloat32AtomicMinMax));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderBufferFloat64AtomicMinMax, b.shaderBufferFloat64AtomicMinMax));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSharedFloat16Atomics, b.shaderSharedFloat16Atomics));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSharedFloat16AtomicAdd, b.shaderSharedFloat16AtomicAdd));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSharedFloat16AtomicMinMax, b.shaderSharedFloat16AtomicMinMax));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSharedFloat32AtomicMinMax, b.shaderSharedFloat32AtomicMinMax));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSharedFloat64AtomicMinMax, b.shaderSharedFloat64AtomicMinMax));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderImageFloat32AtomicMinMax, b.shaderImageFloat32AtomicMinMax));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseImageFloat32AtomicMinMax, b.sparseImageFloat32AtomicMinMax));
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
inline constexpr bool equal(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& a, const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT (&a)[N],
                            const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& x,
                                 const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>
{
    using type = decltype(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT{} <=> VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& a,
                                        const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT (&a)[N],
                                        const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a,
        b,
        [](const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& x, const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& y) constexpr noexcept
        { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_EXT_shader_atomic_float2)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT2_FEATURES_EXT_HPP
