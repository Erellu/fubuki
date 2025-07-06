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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN14_FEATURES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN14_FEATURES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_4)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceVulkan14Features& a, const VkPhysicalDeviceVulkan14Features& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.globalPriorityQuery, b.globalPriorityQuery)
        and equal(a.shaderSubgroupRotate, b.shaderSubgroupRotate) and equal(a.shaderSubgroupRotateClustered, b.shaderSubgroupRotateClustered)
        and equal(a.shaderFloatControls2, b.shaderFloatControls2) and equal(a.shaderExpectAssume, b.shaderExpectAssume)
        and equal(a.rectangularLines, b.rectangularLines) and equal(a.bresenhamLines, b.bresenhamLines) and equal(a.smoothLines, b.smoothLines)
        and equal(a.stippledRectangularLines, b.stippledRectangularLines) and equal(a.stippledBresenhamLines, b.stippledBresenhamLines)
        and equal(a.stippledSmoothLines, b.stippledSmoothLines) and equal(a.vertexAttributeInstanceRateDivisor, b.vertexAttributeInstanceRateDivisor)
        and equal(a.vertexAttributeInstanceRateZeroDivisor, b.vertexAttributeInstanceRateZeroDivisor) and equal(a.indexTypeUint8, b.indexTypeUint8)
        and equal(a.dynamicRenderingLocalRead, b.dynamicRenderingLocalRead) and equal(a.maintenance5, b.maintenance5)
        and equal(a.maintenance6, b.maintenance6) and equal(a.pipelineProtectedAccess, b.pipelineProtectedAccess)
        and equal(a.pipelineRobustness, b.pipelineRobustness) and equal(a.hostImageCopy, b.hostImageCopy)
        and equal(a.pushDescriptor, b.pushDescriptor);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceVulkan14Features& a, const VkPhysicalDeviceVulkan14Features& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceVulkan14Features& a, const VkPhysicalDeviceVulkan14Features& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.globalPriorityQuery, b.globalPriorityQuery)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSubgroupRotate, b.shaderSubgroupRotate)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSubgroupRotateClustered, b.shaderSubgroupRotateClustered));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderFloatControls2, b.shaderFloatControls2)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderExpectAssume, b.shaderExpectAssume)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.rectangularLines, b.rectangularLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bresenhamLines, b.bresenhamLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.smoothLines, b.smoothLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.stippledRectangularLines, b.stippledRectangularLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.stippledBresenhamLines, b.stippledBresenhamLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.stippledSmoothLines, b.stippledSmoothLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vertexAttributeInstanceRateDivisor, b.vertexAttributeInstanceRateDivisor));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vertexAttributeInstanceRateZeroDivisor, b.vertexAttributeInstanceRateZeroDivisor));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.indexTypeUint8, b.indexTypeUint8)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.dynamicRenderingLocalRead, b.dynamicRenderingLocalRead)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maintenance5, b.maintenance5)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maintenance6, b.maintenance6)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineProtectedAccess, b.pipelineProtectedAccess)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineRobustness, b.pipelineRobustness)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.hostImageCopy, b.hostImageCopy)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pushDescriptor, b.pushDescriptor)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan14Features& a, const VkPhysicalDeviceVulkan14Features& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan14Features (&a)[N], const VkPhysicalDeviceVulkan14Features (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceVulkan14Features& x, const VkPhysicalDeviceVulkan14Features& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceVulkan14Features>
{
    using type = decltype(VkPhysicalDeviceVulkan14Features{} <=> VkPhysicalDeviceVulkan14Features{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan14Features& a, const VkPhysicalDeviceVulkan14Features& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan14Features (&a)[N], const VkPhysicalDeviceVulkan14Features (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceVulkan14Features& x, const VkPhysicalDeviceVulkan14Features& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_4)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN14_FEATURES_HPP
