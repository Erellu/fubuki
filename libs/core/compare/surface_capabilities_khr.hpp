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

#ifndef FUBUKI_CORE_COMPARE_SURFACE_CAPABILITIES_KHR_HPP
#define FUBUKI_CORE_COMPARE_SURFACE_CAPABILITIES_KHR_HPP

#include "core/compare/extent2d.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"   // IWYU pragma: keep
#include "core/vulkan.hpp"           // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_surface)

[[nodiscard]] inline constexpr bool operator==(const VkSurfaceCapabilitiesKHR& a, const VkSurfaceCapabilitiesKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.minImageCount, b.minImageCount) and equal(a.maxImageCount, b.maxImageCount) and equal(a.currentExtent, b.currentExtent)
        and equal(a.minImageExtent, b.minImageExtent) and equal(a.maxImageExtent, b.maxImageExtent)
        and equal(a.maxImageArrayLayers, b.maxImageArrayLayers) and equal(a.supportedTransforms, b.supportedTransforms)
        and equal(a.currentTransform, b.currentTransform) and equal(a.supportedCompositeAlpha, b.supportedCompositeAlpha)
        and equal(a.supportedUsageFlags, b.supportedUsageFlags);
}

[[nodiscard]] inline constexpr bool operator!=(const VkSurfaceCapabilitiesKHR& a, const VkSurfaceCapabilitiesKHR& b) noexcept { return not(a == b); }

[[nodiscard]] inline constexpr auto operator<=>(const VkSurfaceCapabilitiesKHR& a, const VkSurfaceCapabilitiesKHR& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.minImageCount)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.minImageCount, b.minImageCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageCount, b.maxImageCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.currentExtent, b.currentExtent)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minImageExtent, b.minImageExtent)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageExtent, b.maxImageExtent)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageArrayLayers, b.maxImageArrayLayers)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.supportedTransforms, b.supportedTransforms)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.currentTransform, b.currentTransform)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.supportedCompositeAlpha, b.supportedCompositeAlpha)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.supportedUsageFlags, b.supportedUsageFlags)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkSurfaceCapabilitiesKHR& a, const VkSurfaceCapabilitiesKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkSurfaceCapabilitiesKHR (&a)[N], const VkSurfaceCapabilitiesKHR (&b)[N]) noexcept
{
    return std::ranges::equal(a, b, [](const VkSurfaceCapabilitiesKHR& x, const VkSurfaceCapabilitiesKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkSurfaceCapabilitiesKHR>
{
    using type = decltype(VkSurfaceCapabilitiesKHR{} <=> VkSurfaceCapabilitiesKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkSurfaceCapabilitiesKHR& a, const VkSurfaceCapabilitiesKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkSurfaceCapabilitiesKHR (&a)[N], const VkSurfaceCapabilitiesKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkSurfaceCapabilitiesKHR& x, const VkSurfaceCapabilitiesKHR& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_surface)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_SURFACE_CAPABILITIES_KHR_HPP
