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

#ifndef FUBUKI_CORE_COMPARE_SWAPCHAIN_CREATE_INFO_KHR_HPP
#define FUBUKI_CORE_COMPARE_SWAPCHAIN_CREATE_INFO_KHR_HPP

#include "core/compare/extent2d.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"   // IWYU pragma: keep
#include "core/vulkan.hpp"           // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_swapchain)

[[nodiscard]] inline constexpr bool operator==(const VkSwapchainCreateInfoKHR& a, const VkSwapchainCreateInfoKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.flags, b.flags) and equal(a.surface, b.surface)
        and equal(a.minImageCount, b.minImageCount) and equal(a.imageFormat, b.imageFormat) and equal(a.imageColorSpace, b.imageColorSpace)
        and equal(a.imageExtent, b.imageExtent) and equal(a.imageArrayLayers, b.imageArrayLayers) and equal(a.imageUsage, b.imageUsage)
        and equal(a.imageSharingMode, b.imageSharingMode) and equal(a.queueFamilyIndexCount, b.queueFamilyIndexCount)
        and equal(a.pQueueFamilyIndices, b.pQueueFamilyIndices) and equal(a.preTransform, b.preTransform)
        and equal(a.compositeAlpha, b.compositeAlpha) and equal(a.presentMode, b.presentMode) and equal(a.clipped, b.clipped)
        and equal(a.oldSwapchain, b.oldSwapchain);
}

[[nodiscard]] inline constexpr bool operator!=(const VkSwapchainCreateInfoKHR& a, const VkSwapchainCreateInfoKHR& b) noexcept { return not(a == b); }

[[nodiscard]] inline constexpr auto operator<=>(const VkSwapchainCreateInfoKHR& a, const VkSwapchainCreateInfoKHR& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.surface, b.surface)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minImageCount, b.minImageCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageFormat, b.imageFormat)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageColorSpace, b.imageColorSpace)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageExtent, b.imageExtent)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageArrayLayers, b.imageArrayLayers)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageUsage, b.imageUsage)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageSharingMode, b.imageSharingMode)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.queueFamilyIndexCount, b.queueFamilyIndexCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pQueueFamilyIndices, b.pQueueFamilyIndices)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.preTransform, b.preTransform)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.compositeAlpha, b.compositeAlpha)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.presentMode, b.presentMode)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.clipped, b.clipped)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.oldSwapchain, b.oldSwapchain)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkSwapchainCreateInfoKHR& a, const VkSwapchainCreateInfoKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkSwapchainCreateInfoKHR (&a)[N], const VkSwapchainCreateInfoKHR (&b)[N]) noexcept
{
    return std::ranges::equal(a, b, [](const VkSwapchainCreateInfoKHR& x, const VkSwapchainCreateInfoKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkSwapchainCreateInfoKHR>
{
    using type = decltype(VkSwapchainCreateInfoKHR{} <=> VkSwapchainCreateInfoKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkSwapchainCreateInfoKHR& a, const VkSwapchainCreateInfoKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkSwapchainCreateInfoKHR (&a)[N], const VkSwapchainCreateInfoKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkSwapchainCreateInfoKHR& x, const VkSwapchainCreateInfoKHR& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_swapchain)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_SWAPCHAIN_CREATE_INFO_KHR_HPP
