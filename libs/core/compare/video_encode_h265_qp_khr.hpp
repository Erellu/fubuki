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

#ifndef FUBUKI_CORE_COMPARE_VIDEO_ENCODE_H265_QP_KHR_HPP
#define FUBUKI_CORE_COMPARE_VIDEO_ENCODE_H265_QP_KHR_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_video_encode_h265)

[[nodiscard]] inline constexpr bool operator==(const VkVideoEncodeH265QpKHR& a, const VkVideoEncodeH265QpKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.qpI, b.qpI) and equal(a.qpP, b.qpP) and equal(a.qpB, b.qpB);
}

[[nodiscard]] inline constexpr bool operator!=(const VkVideoEncodeH265QpKHR& a, const VkVideoEncodeH265QpKHR& b) noexcept { return not(a == b); }

[[nodiscard]] inline constexpr auto operator<=>(const VkVideoEncodeH265QpKHR& a, const VkVideoEncodeH265QpKHR& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.qpI)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.qpI, b.qpI)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.qpP, b.qpP)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.qpB, b.qpB)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkVideoEncodeH265QpKHR& a, const VkVideoEncodeH265QpKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkVideoEncodeH265QpKHR (&a)[N], const VkVideoEncodeH265QpKHR (&b)[N]) noexcept
{
    return std::ranges::equal(a, b, [](const VkVideoEncodeH265QpKHR& x, const VkVideoEncodeH265QpKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkVideoEncodeH265QpKHR>
{
    using type = decltype(VkVideoEncodeH265QpKHR{} <=> VkVideoEncodeH265QpKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkVideoEncodeH265QpKHR& a, const VkVideoEncodeH265QpKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkVideoEncodeH265QpKHR (&a)[N], const VkVideoEncodeH265QpKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkVideoEncodeH265QpKHR& x, const VkVideoEncodeH265QpKHR& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_video_encode_h265)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_VIDEO_ENCODE_H265_QP_KHR_HPP
