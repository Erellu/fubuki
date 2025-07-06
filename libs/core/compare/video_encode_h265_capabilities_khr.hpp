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

#ifndef FUBUKI_CORE_COMPARE_VIDEO_ENCODE_H265_CAPABILITIES_KHR_HPP
#define FUBUKI_CORE_COMPARE_VIDEO_ENCODE_H265_CAPABILITIES_KHR_HPP

#include "core/compare/extent2d.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"   // IWYU pragma: keep
#include "core/vulkan.hpp"           // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_video_encode_h265)

[[nodiscard]] inline constexpr bool operator==(const VkVideoEncodeH265CapabilitiesKHR& a, const VkVideoEncodeH265CapabilitiesKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.flags, b.flags) and equal(a.maxLevelIdc, b.maxLevelIdc)
        and equal(a.maxSliceSegmentCount, b.maxSliceSegmentCount) and equal(a.maxTiles, b.maxTiles) and equal(a.ctbSizes, b.ctbSizes)
        and equal(a.transformBlockSizes, b.transformBlockSizes) and equal(a.maxPPictureL0ReferenceCount, b.maxPPictureL0ReferenceCount)
        and equal(a.maxBPictureL0ReferenceCount, b.maxBPictureL0ReferenceCount) and equal(a.maxL1ReferenceCount, b.maxL1ReferenceCount)
        and equal(a.maxSubLayerCount, b.maxSubLayerCount) and equal(a.expectDyadicTemporalSubLayerPattern, b.expectDyadicTemporalSubLayerPattern)
        and equal(a.minQp, b.minQp) and equal(a.maxQp, b.maxQp) and equal(a.prefersGopRemainingFrames, b.prefersGopRemainingFrames)
        and equal(a.requiresGopRemainingFrames, b.requiresGopRemainingFrames) and equal(a.stdSyntaxFlags, b.stdSyntaxFlags);
}

[[nodiscard]] inline constexpr bool operator!=(const VkVideoEncodeH265CapabilitiesKHR& a, const VkVideoEncodeH265CapabilitiesKHR& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkVideoEncodeH265CapabilitiesKHR& a, const VkVideoEncodeH265CapabilitiesKHR& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxLevelIdc, b.maxLevelIdc)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSliceSegmentCount, b.maxSliceSegmentCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTiles, b.maxTiles)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.ctbSizes, b.ctbSizes)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.transformBlockSizes, b.transformBlockSizes)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPPictureL0ReferenceCount, b.maxPPictureL0ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxBPictureL0ReferenceCount, b.maxBPictureL0ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxL1ReferenceCount, b.maxL1ReferenceCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSubLayerCount, b.maxSubLayerCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.expectDyadicTemporalSubLayerPattern, b.expectDyadicTemporalSubLayerPattern));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minQp, b.minQp)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxQp, b.maxQp)); cmp != result_type::equivalent)
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
inline constexpr bool equal(const VkVideoEncodeH265CapabilitiesKHR& a, const VkVideoEncodeH265CapabilitiesKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkVideoEncodeH265CapabilitiesKHR (&a)[N], const VkVideoEncodeH265CapabilitiesKHR (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkVideoEncodeH265CapabilitiesKHR& x, const VkVideoEncodeH265CapabilitiesKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkVideoEncodeH265CapabilitiesKHR>
{
    using type = decltype(VkVideoEncodeH265CapabilitiesKHR{} <=> VkVideoEncodeH265CapabilitiesKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkVideoEncodeH265CapabilitiesKHR& a, const VkVideoEncodeH265CapabilitiesKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkVideoEncodeH265CapabilitiesKHR (&a)[N], const VkVideoEncodeH265CapabilitiesKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkVideoEncodeH265CapabilitiesKHR& x, const VkVideoEncodeH265CapabilitiesKHR& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_video_encode_h265)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_VIDEO_ENCODE_H265_CAPABILITIES_KHR_HPP
