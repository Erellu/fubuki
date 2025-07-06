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

#ifndef FUBUKI_CORE_COMPARE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR_HPP
#define FUBUKI_CORE_COMPARE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR_HPP

#include "core/compare/extent2d.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"   // IWYU pragma: keep
#include "core/vulkan.hpp"           // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_video_encode_av1)

[[nodiscard]] inline constexpr bool operator==(const VkVideoEncodeAV1CapabilitiesKHR& a, const VkVideoEncodeAV1CapabilitiesKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.flags, b.flags) and equal(a.maxLevel, b.maxLevel)
        and equal(a.codedPictureAlignment, b.codedPictureAlignment) and equal(a.maxTiles, b.maxTiles) and equal(a.minTileSize, b.minTileSize)
        and equal(a.maxTileSize, b.maxTileSize) and equal(a.superblockSizes, b.superblockSizes)
        and equal(a.maxSingleReferenceCount, b.maxSingleReferenceCount) and equal(a.singleReferenceNameMask, b.singleReferenceNameMask)
        and equal(a.maxUnidirectionalCompoundReferenceCount, b.maxUnidirectionalCompoundReferenceCount)
        and equal(a.maxUnidirectionalCompoundGroup1ReferenceCount, b.maxUnidirectionalCompoundGroup1ReferenceCount)
        and equal(a.unidirectionalCompoundReferenceNameMask, b.unidirectionalCompoundReferenceNameMask)
        and equal(a.maxBidirectionalCompoundReferenceCount, b.maxBidirectionalCompoundReferenceCount)
        and equal(a.maxBidirectionalCompoundGroup1ReferenceCount, b.maxBidirectionalCompoundGroup1ReferenceCount)
        and equal(a.maxBidirectionalCompoundGroup2ReferenceCount, b.maxBidirectionalCompoundGroup2ReferenceCount)
        and equal(a.bidirectionalCompoundReferenceNameMask, b.bidirectionalCompoundReferenceNameMask)
        and equal(a.maxTemporalLayerCount, b.maxTemporalLayerCount) and equal(a.maxSpatialLayerCount, b.maxSpatialLayerCount)
        and equal(a.maxOperatingPoints, b.maxOperatingPoints) and equal(a.minQIndex, b.minQIndex) and equal(a.maxQIndex, b.maxQIndex)
        and equal(a.prefersGopRemainingFrames, b.prefersGopRemainingFrames) and equal(a.requiresGopRemainingFrames, b.requiresGopRemainingFrames)
        and equal(a.stdSyntaxFlags, b.stdSyntaxFlags);
}

[[nodiscard]] inline constexpr bool operator!=(const VkVideoEncodeAV1CapabilitiesKHR& a, const VkVideoEncodeAV1CapabilitiesKHR& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkVideoEncodeAV1CapabilitiesKHR& a, const VkVideoEncodeAV1CapabilitiesKHR& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.flags, b.flags)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxLevel, b.maxLevel)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.codedPictureAlignment, b.codedPictureAlignment)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTiles, b.maxTiles)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minTileSize, b.minTileSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTileSize, b.maxTileSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.superblockSizes, b.superblockSizes)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSingleReferenceCount, b.maxSingleReferenceCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.singleReferenceNameMask, b.singleReferenceNameMask)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxUnidirectionalCompoundReferenceCount, b.maxUnidirectionalCompoundReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxUnidirectionalCompoundGroup1ReferenceCount, b.maxUnidirectionalCompoundGroup1ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.unidirectionalCompoundReferenceNameMask, b.unidirectionalCompoundReferenceNameMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxBidirectionalCompoundReferenceCount, b.maxBidirectionalCompoundReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxBidirectionalCompoundGroup1ReferenceCount, b.maxBidirectionalCompoundGroup1ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxBidirectionalCompoundGroup2ReferenceCount, b.maxBidirectionalCompoundGroup2ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bidirectionalCompoundReferenceNameMask, b.bidirectionalCompoundReferenceNameMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTemporalLayerCount, b.maxTemporalLayerCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSpatialLayerCount, b.maxSpatialLayerCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxOperatingPoints, b.maxOperatingPoints)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minQIndex, b.minQIndex)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxQIndex, b.maxQIndex)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.prefersGopRemainingFrames, b.prefersGopRemainingFrames)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.requiresGopRemainingFrames, b.requiresGopRemainingFrames));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.stdSyntaxFlags, b.stdSyntaxFlags)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkVideoEncodeAV1CapabilitiesKHR& a, const VkVideoEncodeAV1CapabilitiesKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkVideoEncodeAV1CapabilitiesKHR (&a)[N], const VkVideoEncodeAV1CapabilitiesKHR (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkVideoEncodeAV1CapabilitiesKHR& x, const VkVideoEncodeAV1CapabilitiesKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkVideoEncodeAV1CapabilitiesKHR>
{
    using type = decltype(VkVideoEncodeAV1CapabilitiesKHR{} <=> VkVideoEncodeAV1CapabilitiesKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkVideoEncodeAV1CapabilitiesKHR& a, const VkVideoEncodeAV1CapabilitiesKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkVideoEncodeAV1CapabilitiesKHR (&a)[N], const VkVideoEncodeAV1CapabilitiesKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkVideoEncodeAV1CapabilitiesKHR& x, const VkVideoEncodeAV1CapabilitiesKHR& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_video_encode_av1)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR_HPP
