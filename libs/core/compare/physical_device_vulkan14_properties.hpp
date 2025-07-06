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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN14_PROPERTIES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN14_PROPERTIES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_4)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceVulkan14Properties& a, const VkPhysicalDeviceVulkan14Properties& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.lineSubPixelPrecisionBits, b.lineSubPixelPrecisionBits)
        and equal(a.maxVertexAttribDivisor, b.maxVertexAttribDivisor) and equal(a.supportsNonZeroFirstInstance, b.supportsNonZeroFirstInstance)
        and equal(a.maxPushDescriptors, b.maxPushDescriptors)
        and equal(a.dynamicRenderingLocalReadDepthStencilAttachments, b.dynamicRenderingLocalReadDepthStencilAttachments)
        and equal(a.dynamicRenderingLocalReadMultisampledAttachments, b.dynamicRenderingLocalReadMultisampledAttachments)
        and equal(a.earlyFragmentMultisampleCoverageAfterSampleCounting, b.earlyFragmentMultisampleCoverageAfterSampleCounting)
        and equal(a.earlyFragmentSampleMaskTestBeforeSampleCounting, b.earlyFragmentSampleMaskTestBeforeSampleCounting)
        and equal(a.depthStencilSwizzleOneSupport, b.depthStencilSwizzleOneSupport) and equal(a.polygonModePointSize, b.polygonModePointSize)
        and equal(a.nonStrictSinglePixelWideLinesUseParallelogram, b.nonStrictSinglePixelWideLinesUseParallelogram)
        and equal(a.nonStrictWideLinesUseParallelogram, b.nonStrictWideLinesUseParallelogram)
        and equal(a.blockTexelViewCompatibleMultipleLayers, b.blockTexelViewCompatibleMultipleLayers)
        and equal(a.maxCombinedImageSamplerDescriptorCount, b.maxCombinedImageSamplerDescriptorCount)
        and equal(a.fragmentShadingRateClampCombinerInputs, b.fragmentShadingRateClampCombinerInputs)
        and equal(a.defaultRobustnessStorageBuffers, b.defaultRobustnessStorageBuffers)
        and equal(a.defaultRobustnessUniformBuffers, b.defaultRobustnessUniformBuffers)
        and equal(a.defaultRobustnessVertexInputs, b.defaultRobustnessVertexInputs) and equal(a.defaultRobustnessImages, b.defaultRobustnessImages)
        and equal(a.copySrcLayoutCount, b.copySrcLayoutCount) and equal(a.pCopySrcLayouts, b.pCopySrcLayouts)
        and equal(a.copyDstLayoutCount, b.copyDstLayoutCount) and equal(a.pCopyDstLayouts, b.pCopyDstLayouts)
        and equal(a.optimalTilingLayoutUUID, b.optimalTilingLayoutUUID)
        and equal(a.identicalMemoryTypeRequirements, b.identicalMemoryTypeRequirements);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceVulkan14Properties& a, const VkPhysicalDeviceVulkan14Properties& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceVulkan14Properties& a, const VkPhysicalDeviceVulkan14Properties& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.lineSubPixelPrecisionBits, b.lineSubPixelPrecisionBits)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxVertexAttribDivisor, b.maxVertexAttribDivisor)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.supportsNonZeroFirstInstance, b.supportsNonZeroFirstInstance));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPushDescriptors, b.maxPushDescriptors)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.dynamicRenderingLocalReadDepthStencilAttachments, b.dynamicRenderingLocalReadDepthStencilAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.dynamicRenderingLocalReadMultisampledAttachments, b.dynamicRenderingLocalReadMultisampledAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.earlyFragmentMultisampleCoverageAfterSampleCounting, b.earlyFragmentMultisampleCoverageAfterSampleCounting));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.earlyFragmentSampleMaskTestBeforeSampleCounting, b.earlyFragmentSampleMaskTestBeforeSampleCounting));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.depthStencilSwizzleOneSupport, b.depthStencilSwizzleOneSupport));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.polygonModePointSize, b.polygonModePointSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.nonStrictSinglePixelWideLinesUseParallelogram, b.nonStrictSinglePixelWideLinesUseParallelogram));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.nonStrictWideLinesUseParallelogram, b.nonStrictWideLinesUseParallelogram));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.blockTexelViewCompatibleMultipleLayers, b.blockTexelViewCompatibleMultipleLayers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxCombinedImageSamplerDescriptorCount, b.maxCombinedImageSamplerDescriptorCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fragmentShadingRateClampCombinerInputs, b.fragmentShadingRateClampCombinerInputs));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.defaultRobustnessStorageBuffers, b.defaultRobustnessStorageBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.defaultRobustnessUniformBuffers, b.defaultRobustnessUniformBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.defaultRobustnessVertexInputs, b.defaultRobustnessVertexInputs));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.defaultRobustnessImages, b.defaultRobustnessImages)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.copySrcLayoutCount, b.copySrcLayoutCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pCopySrcLayouts, b.pCopySrcLayouts)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.copyDstLayoutCount, b.copyDstLayoutCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pCopyDstLayouts, b.pCopyDstLayouts)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.optimalTilingLayoutUUID, b.optimalTilingLayoutUUID)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.identicalMemoryTypeRequirements, b.identicalMemoryTypeRequirements));
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
inline constexpr bool equal(const VkPhysicalDeviceVulkan14Properties& a, const VkPhysicalDeviceVulkan14Properties& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan14Properties (&a)[N], const VkPhysicalDeviceVulkan14Properties (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceVulkan14Properties& x, const VkPhysicalDeviceVulkan14Properties& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceVulkan14Properties>
{
    using type = decltype(VkPhysicalDeviceVulkan14Properties{} <=> VkPhysicalDeviceVulkan14Properties{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan14Properties& a, const VkPhysicalDeviceVulkan14Properties& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan14Properties (&a)[N], const VkPhysicalDeviceVulkan14Properties (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceVulkan14Properties& x, const VkPhysicalDeviceVulkan14Properties& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_4)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN14_PROPERTIES_HPP
