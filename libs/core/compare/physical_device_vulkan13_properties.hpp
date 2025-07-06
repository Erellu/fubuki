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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN13_PROPERTIES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN13_PROPERTIES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_3)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceVulkan13Properties& a, const VkPhysicalDeviceVulkan13Properties& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.minSubgroupSize, b.minSubgroupSize)
        and equal(a.maxSubgroupSize, b.maxSubgroupSize) and equal(a.maxComputeWorkgroupSubgroups, b.maxComputeWorkgroupSubgroups)
        and equal(a.requiredSubgroupSizeStages, b.requiredSubgroupSizeStages) and equal(a.maxInlineUniformBlockSize, b.maxInlineUniformBlockSize)
        and equal(a.maxPerStageDescriptorInlineUniformBlocks, b.maxPerStageDescriptorInlineUniformBlocks)
        and equal(a.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, b.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks)
        and equal(a.maxDescriptorSetInlineUniformBlocks, b.maxDescriptorSetInlineUniformBlocks)
        and equal(a.maxDescriptorSetUpdateAfterBindInlineUniformBlocks, b.maxDescriptorSetUpdateAfterBindInlineUniformBlocks)
        and equal(a.maxInlineUniformTotalSize, b.maxInlineUniformTotalSize)
        and equal(a.integerDotProduct8BitUnsignedAccelerated, b.integerDotProduct8BitUnsignedAccelerated)
        and equal(a.integerDotProduct8BitSignedAccelerated, b.integerDotProduct8BitSignedAccelerated)
        and equal(a.integerDotProduct8BitMixedSignednessAccelerated, b.integerDotProduct8BitMixedSignednessAccelerated)
        and equal(a.integerDotProduct4x8BitPackedUnsignedAccelerated, b.integerDotProduct4x8BitPackedUnsignedAccelerated)
        and equal(a.integerDotProduct4x8BitPackedSignedAccelerated, b.integerDotProduct4x8BitPackedSignedAccelerated)
        and equal(a.integerDotProduct4x8BitPackedMixedSignednessAccelerated, b.integerDotProduct4x8BitPackedMixedSignednessAccelerated)
        and equal(a.integerDotProduct16BitUnsignedAccelerated, b.integerDotProduct16BitUnsignedAccelerated)
        and equal(a.integerDotProduct16BitSignedAccelerated, b.integerDotProduct16BitSignedAccelerated)
        and equal(a.integerDotProduct16BitMixedSignednessAccelerated, b.integerDotProduct16BitMixedSignednessAccelerated)
        and equal(a.integerDotProduct32BitUnsignedAccelerated, b.integerDotProduct32BitUnsignedAccelerated)
        and equal(a.integerDotProduct32BitSignedAccelerated, b.integerDotProduct32BitSignedAccelerated)
        and equal(a.integerDotProduct32BitMixedSignednessAccelerated, b.integerDotProduct32BitMixedSignednessAccelerated)
        and equal(a.integerDotProduct64BitUnsignedAccelerated, b.integerDotProduct64BitUnsignedAccelerated)
        and equal(a.integerDotProduct64BitSignedAccelerated, b.integerDotProduct64BitSignedAccelerated)
        and equal(a.integerDotProduct64BitMixedSignednessAccelerated, b.integerDotProduct64BitMixedSignednessAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, b.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating8BitSignedAccelerated, b.integerDotProductAccumulatingSaturating8BitSignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated,
                  b.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated,
                  b.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated,
                  b.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated,
                  b.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated,
                  b.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating16BitSignedAccelerated, b.integerDotProductAccumulatingSaturating16BitSignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated,
                  b.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated,
                  b.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating32BitSignedAccelerated, b.integerDotProductAccumulatingSaturating32BitSignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated,
                  b.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated,
                  b.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating64BitSignedAccelerated, b.integerDotProductAccumulatingSaturating64BitSignedAccelerated)
        and equal(a.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated,
                  b.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated)
        and equal(a.storageTexelBufferOffsetAlignmentBytes, b.storageTexelBufferOffsetAlignmentBytes)
        and equal(a.storageTexelBufferOffsetSingleTexelAlignment, b.storageTexelBufferOffsetSingleTexelAlignment)
        and equal(a.uniformTexelBufferOffsetAlignmentBytes, b.uniformTexelBufferOffsetAlignmentBytes)
        and equal(a.uniformTexelBufferOffsetSingleTexelAlignment, b.uniformTexelBufferOffsetSingleTexelAlignment)
        and equal(a.maxBufferSize, b.maxBufferSize);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceVulkan13Properties& a, const VkPhysicalDeviceVulkan13Properties& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceVulkan13Properties& a, const VkPhysicalDeviceVulkan13Properties& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.minSubgroupSize, b.minSubgroupSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSubgroupSize, b.maxSubgroupSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxComputeWorkgroupSubgroups, b.maxComputeWorkgroupSubgroups));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.requiredSubgroupSizeStages, b.requiredSubgroupSizeStages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxInlineUniformBlockSize, b.maxInlineUniformBlockSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageDescriptorInlineUniformBlocks, b.maxPerStageDescriptorInlineUniformBlocks));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, b.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetInlineUniformBlocks, b.maxDescriptorSetInlineUniformBlocks));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxDescriptorSetUpdateAfterBindInlineUniformBlocks, b.maxDescriptorSetUpdateAfterBindInlineUniformBlocks));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxInlineUniformTotalSize, b.maxInlineUniformTotalSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct8BitUnsignedAccelerated, b.integerDotProduct8BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct8BitSignedAccelerated, b.integerDotProduct8BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.integerDotProduct8BitMixedSignednessAccelerated, b.integerDotProduct8BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.integerDotProduct4x8BitPackedUnsignedAccelerated, b.integerDotProduct4x8BitPackedUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.integerDotProduct4x8BitPackedSignedAccelerated, b.integerDotProduct4x8BitPackedSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.integerDotProduct4x8BitPackedMixedSignednessAccelerated, b.integerDotProduct4x8BitPackedMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct16BitUnsignedAccelerated, b.integerDotProduct16BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct16BitSignedAccelerated, b.integerDotProduct16BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.integerDotProduct16BitMixedSignednessAccelerated, b.integerDotProduct16BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct32BitUnsignedAccelerated, b.integerDotProduct32BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct32BitSignedAccelerated, b.integerDotProduct32BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.integerDotProduct32BitMixedSignednessAccelerated, b.integerDotProduct32BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct64BitUnsignedAccelerated, b.integerDotProduct64BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProduct64BitSignedAccelerated, b.integerDotProduct64BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.integerDotProduct64BitMixedSignednessAccelerated, b.integerDotProduct64BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.integerDotProductAccumulatingSaturating8BitSignedAccelerated, b.integerDotProductAccumulatingSaturating8BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated,
                                                           b.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated,
                                                           b.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating16BitSignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating16BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated,
                                                           b.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating32BitSignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating32BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated,
                                                           b.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating64BitSignedAccelerated,
                                                           b.integerDotProductAccumulatingSaturating64BitSignedAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated,
                                                           b.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.storageTexelBufferOffsetAlignmentBytes, b.storageTexelBufferOffsetAlignmentBytes));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.storageTexelBufferOffsetSingleTexelAlignment, b.storageTexelBufferOffsetSingleTexelAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.uniformTexelBufferOffsetAlignmentBytes, b.uniformTexelBufferOffsetAlignmentBytes));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.uniformTexelBufferOffsetSingleTexelAlignment, b.uniformTexelBufferOffsetSingleTexelAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxBufferSize, b.maxBufferSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan13Properties& a, const VkPhysicalDeviceVulkan13Properties& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan13Properties (&a)[N], const VkPhysicalDeviceVulkan13Properties (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceVulkan13Properties& x, const VkPhysicalDeviceVulkan13Properties& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceVulkan13Properties>
{
    using type = decltype(VkPhysicalDeviceVulkan13Properties{} <=> VkPhysicalDeviceVulkan13Properties{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan13Properties& a, const VkPhysicalDeviceVulkan13Properties& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan13Properties (&a)[N], const VkPhysicalDeviceVulkan13Properties (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceVulkan13Properties& x, const VkPhysicalDeviceVulkan13Properties& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_3)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN13_PROPERTIES_HPP
