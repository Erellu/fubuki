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

#ifndef FUBUKI_CORE_COMPARE_TRACE_RAYS_INDIRECT_COMMAND2_KHR_HPP
#define FUBUKI_CORE_COMPARE_TRACE_RAYS_INDIRECT_COMMAND2_KHR_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_ray_tracing_maintenance1)

[[nodiscard]] inline constexpr bool operator==(const VkTraceRaysIndirectCommand2KHR& a, const VkTraceRaysIndirectCommand2KHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.raygenShaderRecordAddress, b.raygenShaderRecordAddress) and equal(a.raygenShaderRecordSize, b.raygenShaderRecordSize)
        and equal(a.missShaderBindingTableAddress, b.missShaderBindingTableAddress)
        and equal(a.missShaderBindingTableSize, b.missShaderBindingTableSize)
        and equal(a.missShaderBindingTableStride, b.missShaderBindingTableStride)
        and equal(a.hitShaderBindingTableAddress, b.hitShaderBindingTableAddress) and equal(a.hitShaderBindingTableSize, b.hitShaderBindingTableSize)
        and equal(a.hitShaderBindingTableStride, b.hitShaderBindingTableStride)
        and equal(a.callableShaderBindingTableAddress, b.callableShaderBindingTableAddress)
        and equal(a.callableShaderBindingTableSize, b.callableShaderBindingTableSize)
        and equal(a.callableShaderBindingTableStride, b.callableShaderBindingTableStride) and equal(a.width, b.width) and equal(a.height, b.height)
        and equal(a.depth, b.depth);
}

[[nodiscard]] inline constexpr bool operator!=(const VkTraceRaysIndirectCommand2KHR& a, const VkTraceRaysIndirectCommand2KHR& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkTraceRaysIndirectCommand2KHR& a, const VkTraceRaysIndirectCommand2KHR& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.raygenShaderRecordAddress)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.raygenShaderRecordAddress, b.raygenShaderRecordAddress)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.raygenShaderRecordSize, b.raygenShaderRecordSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.missShaderBindingTableAddress, b.missShaderBindingTableAddress));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.missShaderBindingTableSize, b.missShaderBindingTableSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.missShaderBindingTableStride, b.missShaderBindingTableStride));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.hitShaderBindingTableAddress, b.hitShaderBindingTableAddress));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.hitShaderBindingTableSize, b.hitShaderBindingTableSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.hitShaderBindingTableStride, b.hitShaderBindingTableStride));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.callableShaderBindingTableAddress, b.callableShaderBindingTableAddress));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.callableShaderBindingTableSize, b.callableShaderBindingTableSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.callableShaderBindingTableStride, b.callableShaderBindingTableStride));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.width, b.width)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.height, b.height)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.depth, b.depth)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkTraceRaysIndirectCommand2KHR& a, const VkTraceRaysIndirectCommand2KHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkTraceRaysIndirectCommand2KHR (&a)[N], const VkTraceRaysIndirectCommand2KHR (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkTraceRaysIndirectCommand2KHR& x, const VkTraceRaysIndirectCommand2KHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkTraceRaysIndirectCommand2KHR>
{
    using type = decltype(VkTraceRaysIndirectCommand2KHR{} <=> VkTraceRaysIndirectCommand2KHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkTraceRaysIndirectCommand2KHR& a, const VkTraceRaysIndirectCommand2KHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkTraceRaysIndirectCommand2KHR (&a)[N], const VkTraceRaysIndirectCommand2KHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkTraceRaysIndirectCommand2KHR& x, const VkTraceRaysIndirectCommand2KHR& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_ray_tracing_maintenance1)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_TRACE_RAYS_INDIRECT_COMMAND2_KHR_HPP
