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

#ifndef FUBUKI_CORE_COMPARE_CU_LAUNCH_INFO_NVX_HPP
#define FUBUKI_CORE_COMPARE_CU_LAUNCH_INFO_NVX_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_NVX_binary_import)

[[nodiscard]] inline constexpr bool operator==(const VkCuLaunchInfoNVX& a, const VkCuLaunchInfoNVX& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.function, b.function) and equal(a.gridDimX, b.gridDimX)
        and equal(a.gridDimY, b.gridDimY) and equal(a.gridDimZ, b.gridDimZ) and equal(a.blockDimX, b.blockDimX) and equal(a.blockDimY, b.blockDimY)
        and equal(a.blockDimZ, b.blockDimZ) and equal(a.sharedMemBytes, b.sharedMemBytes) and equal(a.paramCount, b.paramCount)
        and equal(a.pParams, b.pParams) and equal(a.extraCount, b.extraCount) and equal(a.pExtras, b.pExtras);
}

[[nodiscard]] inline constexpr bool operator!=(const VkCuLaunchInfoNVX& a, const VkCuLaunchInfoNVX& b) noexcept { return not(a == b); }

[[nodiscard]] inline constexpr auto operator<=>(const VkCuLaunchInfoNVX& a, const VkCuLaunchInfoNVX& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.function, b.function)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.gridDimX, b.gridDimX)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.gridDimY, b.gridDimY)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.gridDimZ, b.gridDimZ)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.blockDimX, b.blockDimX)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.blockDimY, b.blockDimY)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.blockDimZ, b.blockDimZ)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sharedMemBytes, b.sharedMemBytes)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.paramCount, b.paramCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pParams, b.pParams)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extraCount, b.extraCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pExtras, b.pExtras)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkCuLaunchInfoNVX& a, const VkCuLaunchInfoNVX& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkCuLaunchInfoNVX (&a)[N], const VkCuLaunchInfoNVX (&b)[N]) noexcept
{
    return std::ranges::equal(a, b, [](const VkCuLaunchInfoNVX& x, const VkCuLaunchInfoNVX& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkCuLaunchInfoNVX>
{
    using type = decltype(VkCuLaunchInfoNVX{} <=> VkCuLaunchInfoNVX{});
};

template<>
inline constexpr std::int32_t three_way(const VkCuLaunchInfoNVX& a, const VkCuLaunchInfoNVX& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkCuLaunchInfoNVX (&a)[N], const VkCuLaunchInfoNVX (&b)[N]) noexcept
{
    return to_int(
        lexicographical_compare_three_way(a, b, [](const VkCuLaunchInfoNVX& x, const VkCuLaunchInfoNVX& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_NVX_binary_import)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_CU_LAUNCH_INFO_NVX_HPP
