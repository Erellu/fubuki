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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_AMD_shader_core_properties)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceShaderCorePropertiesAMD& a,
                                               const VkPhysicalDeviceShaderCorePropertiesAMD& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.shaderEngineCount, b.shaderEngineCount)
        and equal(a.shaderArraysPerEngineCount, b.shaderArraysPerEngineCount) and equal(a.computeUnitsPerShaderArray, b.computeUnitsPerShaderArray)
        and equal(a.simdPerComputeUnit, b.simdPerComputeUnit) and equal(a.wavefrontsPerSimd, b.wavefrontsPerSimd)
        and equal(a.wavefrontSize, b.wavefrontSize) and equal(a.sgprsPerSimd, b.sgprsPerSimd) and equal(a.minSgprAllocation, b.minSgprAllocation)
        and equal(a.maxSgprAllocation, b.maxSgprAllocation) and equal(a.sgprAllocationGranularity, b.sgprAllocationGranularity)
        and equal(a.vgprsPerSimd, b.vgprsPerSimd) and equal(a.minVgprAllocation, b.minVgprAllocation)
        and equal(a.maxVgprAllocation, b.maxVgprAllocation) and equal(a.vgprAllocationGranularity, b.vgprAllocationGranularity);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceShaderCorePropertiesAMD& a,
                                               const VkPhysicalDeviceShaderCorePropertiesAMD& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceShaderCorePropertiesAMD& a,
                                                const VkPhysicalDeviceShaderCorePropertiesAMD& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderEngineCount, b.shaderEngineCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderArraysPerEngineCount, b.shaderArraysPerEngineCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.computeUnitsPerShaderArray, b.computeUnitsPerShaderArray));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.simdPerComputeUnit, b.simdPerComputeUnit)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.wavefrontsPerSimd, b.wavefrontsPerSimd)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.wavefrontSize, b.wavefrontSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sgprsPerSimd, b.sgprsPerSimd)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minSgprAllocation, b.minSgprAllocation)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSgprAllocation, b.maxSgprAllocation)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sgprAllocationGranularity, b.sgprAllocationGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vgprsPerSimd, b.vgprsPerSimd)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minVgprAllocation, b.minVgprAllocation)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxVgprAllocation, b.maxVgprAllocation)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vgprAllocationGranularity, b.vgprAllocationGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceShaderCorePropertiesAMD& a, const VkPhysicalDeviceShaderCorePropertiesAMD& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceShaderCorePropertiesAMD (&a)[N], const VkPhysicalDeviceShaderCorePropertiesAMD (&b)[N]) noexcept
{
    return std::ranges::equal(
        a,
        b,
        [](const VkPhysicalDeviceShaderCorePropertiesAMD& x, const VkPhysicalDeviceShaderCorePropertiesAMD& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceShaderCorePropertiesAMD>
{
    using type = decltype(VkPhysicalDeviceShaderCorePropertiesAMD{} <=> VkPhysicalDeviceShaderCorePropertiesAMD{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceShaderCorePropertiesAMD& a, const VkPhysicalDeviceShaderCorePropertiesAMD& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceShaderCorePropertiesAMD (&a)[N],
                                        const VkPhysicalDeviceShaderCorePropertiesAMD (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(a,
                                                    b,
                                                    [](const VkPhysicalDeviceShaderCorePropertiesAMD& x,
                                                       const VkPhysicalDeviceShaderCorePropertiesAMD& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_AMD_shader_core_properties)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD_HPP
