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

#ifndef FUBUKI_CORE_COMPARE_LATENCY_TIMINGS_FRAME_REPORT_NV_HPP
#define FUBUKI_CORE_COMPARE_LATENCY_TIMINGS_FRAME_REPORT_NV_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_NV_low_latency2)

[[nodiscard]] inline constexpr bool operator==(const VkLatencyTimingsFrameReportNV& a, const VkLatencyTimingsFrameReportNV& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.presentID, b.presentID) and equal(a.inputSampleTimeUs, b.inputSampleTimeUs)
        and equal(a.simStartTimeUs, b.simStartTimeUs) and equal(a.simEndTimeUs, b.simEndTimeUs)
        and equal(a.renderSubmitStartTimeUs, b.renderSubmitStartTimeUs) and equal(a.renderSubmitEndTimeUs, b.renderSubmitEndTimeUs)
        and equal(a.presentStartTimeUs, b.presentStartTimeUs) and equal(a.presentEndTimeUs, b.presentEndTimeUs)
        and equal(a.driverStartTimeUs, b.driverStartTimeUs) and equal(a.driverEndTimeUs, b.driverEndTimeUs)
        and equal(a.osRenderQueueStartTimeUs, b.osRenderQueueStartTimeUs) and equal(a.osRenderQueueEndTimeUs, b.osRenderQueueEndTimeUs)
        and equal(a.gpuRenderStartTimeUs, b.gpuRenderStartTimeUs) and equal(a.gpuRenderEndTimeUs, b.gpuRenderEndTimeUs);
}

[[nodiscard]] inline constexpr bool operator!=(const VkLatencyTimingsFrameReportNV& a, const VkLatencyTimingsFrameReportNV& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkLatencyTimingsFrameReportNV& a, const VkLatencyTimingsFrameReportNV& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.presentID, b.presentID)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.inputSampleTimeUs, b.inputSampleTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.simStartTimeUs, b.simStartTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.simEndTimeUs, b.simEndTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.renderSubmitStartTimeUs, b.renderSubmitStartTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.renderSubmitEndTimeUs, b.renderSubmitEndTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.presentStartTimeUs, b.presentStartTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.presentEndTimeUs, b.presentEndTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.driverStartTimeUs, b.driverStartTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.driverEndTimeUs, b.driverEndTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.osRenderQueueStartTimeUs, b.osRenderQueueStartTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.osRenderQueueEndTimeUs, b.osRenderQueueEndTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.gpuRenderStartTimeUs, b.gpuRenderStartTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.gpuRenderEndTimeUs, b.gpuRenderEndTimeUs)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkLatencyTimingsFrameReportNV& a, const VkLatencyTimingsFrameReportNV& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkLatencyTimingsFrameReportNV (&a)[N], const VkLatencyTimingsFrameReportNV (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkLatencyTimingsFrameReportNV& x, const VkLatencyTimingsFrameReportNV& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkLatencyTimingsFrameReportNV>
{
    using type = decltype(VkLatencyTimingsFrameReportNV{} <=> VkLatencyTimingsFrameReportNV{});
};

template<>
inline constexpr std::int32_t three_way(const VkLatencyTimingsFrameReportNV& a, const VkLatencyTimingsFrameReportNV& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkLatencyTimingsFrameReportNV (&a)[N], const VkLatencyTimingsFrameReportNV (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkLatencyTimingsFrameReportNV& x, const VkLatencyTimingsFrameReportNV& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_NV_low_latency2)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_LATENCY_TIMINGS_FRAME_REPORT_NV_HPP
