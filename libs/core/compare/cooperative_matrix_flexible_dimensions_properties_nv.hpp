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

#ifndef FUBUKI_CORE_COMPARE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV_HPP
#define FUBUKI_CORE_COMPARE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_NV_cooperative_matrix2)

[[nodiscard]] inline constexpr bool operator==(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& a,
                                               const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.MGranularity, b.MGranularity) and equal(a.NGranularity, b.NGranularity)
        and equal(a.KGranularity, b.KGranularity) and equal(a.AType, b.AType) and equal(a.BType, b.BType) and equal(a.CType, b.CType)
        and equal(a.ResultType, b.ResultType) and equal(a.saturatingAccumulation, b.saturatingAccumulation) and equal(a.scope, b.scope)
        and equal(a.workgroupInvocations, b.workgroupInvocations);
}

[[nodiscard]] inline constexpr bool operator!=(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& a,
                                               const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& a,
                                                const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.MGranularity, b.MGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.NGranularity, b.NGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.KGranularity, b.KGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.AType, b.AType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.BType, b.BType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.CType, b.CType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.ResultType, b.ResultType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.saturatingAccumulation, b.saturatingAccumulation)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.scope, b.scope)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.workgroupInvocations, b.workgroupInvocations)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& a,
                            const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV (&a)[N],
                            const VkCooperativeMatrixFlexibleDimensionsPropertiesNV (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& x,
                                 const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkCooperativeMatrixFlexibleDimensionsPropertiesNV>
{
    using type = decltype(VkCooperativeMatrixFlexibleDimensionsPropertiesNV{} <=> VkCooperativeMatrixFlexibleDimensionsPropertiesNV{});
};

template<>
inline constexpr std::int32_t three_way(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& a,
                                        const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV (&a)[N],
                                        const VkCooperativeMatrixFlexibleDimensionsPropertiesNV (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a,
        b,
        [](const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& x, const VkCooperativeMatrixFlexibleDimensionsPropertiesNV& y) constexpr noexcept
        { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_NV_cooperative_matrix2)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV_HPP
