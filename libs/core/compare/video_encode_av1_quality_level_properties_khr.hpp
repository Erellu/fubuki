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

#ifndef FUBUKI_CORE_COMPARE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR_HPP
#define FUBUKI_CORE_COMPARE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR_HPP

#include "core/compare/video_encode_av1_q_index_khr.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"                       // IWYU pragma: keep
#include "core/vulkan.hpp"                               // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_video_encode_av1)

[[nodiscard]] inline constexpr bool operator==(const VkVideoEncodeAV1QualityLevelPropertiesKHR& a,
                                               const VkVideoEncodeAV1QualityLevelPropertiesKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.preferredRateControlFlags, b.preferredRateControlFlags)
        and equal(a.preferredGopFrameCount, b.preferredGopFrameCount) and equal(a.preferredKeyFramePeriod, b.preferredKeyFramePeriod)
        and equal(a.preferredConsecutiveBipredictiveFrameCount, b.preferredConsecutiveBipredictiveFrameCount)
        and equal(a.preferredTemporalLayerCount, b.preferredTemporalLayerCount) and equal(a.preferredConstantQIndex, b.preferredConstantQIndex)
        and equal(a.preferredMaxSingleReferenceCount, b.preferredMaxSingleReferenceCount)
        and equal(a.preferredSingleReferenceNameMask, b.preferredSingleReferenceNameMask)
        and equal(a.preferredMaxUnidirectionalCompoundReferenceCount, b.preferredMaxUnidirectionalCompoundReferenceCount)
        and equal(a.preferredMaxUnidirectionalCompoundGroup1ReferenceCount, b.preferredMaxUnidirectionalCompoundGroup1ReferenceCount)
        and equal(a.preferredUnidirectionalCompoundReferenceNameMask, b.preferredUnidirectionalCompoundReferenceNameMask)
        and equal(a.preferredMaxBidirectionalCompoundReferenceCount, b.preferredMaxBidirectionalCompoundReferenceCount)
        and equal(a.preferredMaxBidirectionalCompoundGroup1ReferenceCount, b.preferredMaxBidirectionalCompoundGroup1ReferenceCount)
        and equal(a.preferredMaxBidirectionalCompoundGroup2ReferenceCount, b.preferredMaxBidirectionalCompoundGroup2ReferenceCount)
        and equal(a.preferredBidirectionalCompoundReferenceNameMask, b.preferredBidirectionalCompoundReferenceNameMask);
}

[[nodiscard]] inline constexpr bool operator!=(const VkVideoEncodeAV1QualityLevelPropertiesKHR& a,
                                               const VkVideoEncodeAV1QualityLevelPropertiesKHR& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkVideoEncodeAV1QualityLevelPropertiesKHR& a,
                                                const VkVideoEncodeAV1QualityLevelPropertiesKHR& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.preferredRateControlFlags, b.preferredRateControlFlags)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.preferredGopFrameCount, b.preferredGopFrameCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.preferredKeyFramePeriod, b.preferredKeyFramePeriod)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.preferredConsecutiveBipredictiveFrameCount, b.preferredConsecutiveBipredictiveFrameCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.preferredTemporalLayerCount, b.preferredTemporalLayerCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.preferredConstantQIndex, b.preferredConstantQIndex)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.preferredMaxSingleReferenceCount, b.preferredMaxSingleReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.preferredSingleReferenceNameMask, b.preferredSingleReferenceNameMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.preferredMaxUnidirectionalCompoundReferenceCount, b.preferredMaxUnidirectionalCompoundReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.preferredMaxUnidirectionalCompoundGroup1ReferenceCount, b.preferredMaxUnidirectionalCompoundGroup1ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.preferredUnidirectionalCompoundReferenceNameMask, b.preferredUnidirectionalCompoundReferenceNameMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.preferredMaxBidirectionalCompoundReferenceCount, b.preferredMaxBidirectionalCompoundReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.preferredMaxBidirectionalCompoundGroup1ReferenceCount, b.preferredMaxBidirectionalCompoundGroup1ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.preferredMaxBidirectionalCompoundGroup2ReferenceCount, b.preferredMaxBidirectionalCompoundGroup2ReferenceCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.preferredBidirectionalCompoundReferenceNameMask, b.preferredBidirectionalCompoundReferenceNameMask));
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
inline constexpr bool equal(const VkVideoEncodeAV1QualityLevelPropertiesKHR& a, const VkVideoEncodeAV1QualityLevelPropertiesKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkVideoEncodeAV1QualityLevelPropertiesKHR (&a)[N], const VkVideoEncodeAV1QualityLevelPropertiesKHR (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkVideoEncodeAV1QualityLevelPropertiesKHR& x,
                                 const VkVideoEncodeAV1QualityLevelPropertiesKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkVideoEncodeAV1QualityLevelPropertiesKHR>
{
    using type = decltype(VkVideoEncodeAV1QualityLevelPropertiesKHR{} <=> VkVideoEncodeAV1QualityLevelPropertiesKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkVideoEncodeAV1QualityLevelPropertiesKHR& a,
                                        const VkVideoEncodeAV1QualityLevelPropertiesKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkVideoEncodeAV1QualityLevelPropertiesKHR (&a)[N],
                                        const VkVideoEncodeAV1QualityLevelPropertiesKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(a,
                                                    b,
                                                    [](const VkVideoEncodeAV1QualityLevelPropertiesKHR& x,
                                                       const VkVideoEncodeAV1QualityLevelPropertiesKHR& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_video_encode_av1)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR_HPP
