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

#ifndef FUBUKI_CORE_COMPARE_IMAGE_MEMORY_BARRIER2_HPP
#define FUBUKI_CORE_COMPARE_IMAGE_MEMORY_BARRIER2_HPP

#include "core/compare/image_subresource_range.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"                  // IWYU pragma: keep
#include "core/vulkan.hpp"                          // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_3)

[[nodiscard]] inline constexpr bool operator==(const VkImageMemoryBarrier2& a, const VkImageMemoryBarrier2& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.srcStageMask, b.srcStageMask) and equal(a.srcAccessMask, b.srcAccessMask)
        and equal(a.dstStageMask, b.dstStageMask) and equal(a.dstAccessMask, b.dstAccessMask) and equal(a.oldLayout, b.oldLayout)
        and equal(a.newLayout, b.newLayout) and equal(a.srcQueueFamilyIndex, b.srcQueueFamilyIndex)
        and equal(a.dstQueueFamilyIndex, b.dstQueueFamilyIndex) and equal(a.image, b.image) and equal(a.subresourceRange, b.subresourceRange);
}

[[nodiscard]] inline constexpr bool operator!=(const VkImageMemoryBarrier2& a, const VkImageMemoryBarrier2& b) noexcept { return not(a == b); }

[[nodiscard]] inline constexpr auto operator<=>(const VkImageMemoryBarrier2& a, const VkImageMemoryBarrier2& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.srcStageMask, b.srcStageMask)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.srcAccessMask, b.srcAccessMask)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.dstStageMask, b.dstStageMask)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.dstAccessMask, b.dstAccessMask)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.oldLayout, b.oldLayout)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.newLayout, b.newLayout)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.srcQueueFamilyIndex, b.srcQueueFamilyIndex)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.dstQueueFamilyIndex, b.dstQueueFamilyIndex)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.image, b.image)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.subresourceRange, b.subresourceRange)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkImageMemoryBarrier2& a, const VkImageMemoryBarrier2& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkImageMemoryBarrier2 (&a)[N], const VkImageMemoryBarrier2 (&b)[N]) noexcept
{
    return std::ranges::equal(a, b, [](const VkImageMemoryBarrier2& x, const VkImageMemoryBarrier2& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkImageMemoryBarrier2>
{
    using type = decltype(VkImageMemoryBarrier2{} <=> VkImageMemoryBarrier2{});
};

template<>
inline constexpr std::int32_t three_way(const VkImageMemoryBarrier2& a, const VkImageMemoryBarrier2& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkImageMemoryBarrier2 (&a)[N], const VkImageMemoryBarrier2 (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkImageMemoryBarrier2& x, const VkImageMemoryBarrier2& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_3)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_IMAGE_MEMORY_BARRIER2_HPP
