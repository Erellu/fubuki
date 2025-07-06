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

#ifndef FUBUKI_CORE_COMPARE_CLUSTER_ACCELERATION_STRUCTURE_BUILD_TRIANGLE_CLUSTER_TEMPLATE_INFO_NV_HPP
#define FUBUKI_CORE_COMPARE_CLUSTER_ACCELERATION_STRUCTURE_BUILD_TRIANGLE_CLUSTER_TEMPLATE_INFO_NV_HPP

#include "core/compare/cluster_acceleration_structure_geometry_index_and_geometry_flags_nv.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"                                                              // IWYU pragma: keep
#include "core/vulkan.hpp"                                                                      // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_NV_cluster_acceleration_structure)

[[nodiscard]] inline constexpr bool operator==(const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& a,
                                               const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& b) noexcept
{
    using detail::compare::equal;
    return equal(a.clusterID, b.clusterID) and equal(a.clusterFlags, b.clusterFlags) and equal(a.triangleCount, b.triangleCount)
        and equal(a.vertexCount, b.vertexCount) and equal(a.positionTruncateBitCount, b.positionTruncateBitCount) and equal(a.indexType, b.indexType)
        and equal(a.opacityMicromapIndexType, b.opacityMicromapIndexType)
        and equal(a.baseGeometryIndexAndGeometryFlags, b.baseGeometryIndexAndGeometryFlags) and equal(a.indexBufferStride, b.indexBufferStride)
        and equal(a.vertexBufferStride, b.vertexBufferStride) and equal(a.geometryIndexAndFlagsBufferStride, b.geometryIndexAndFlagsBufferStride)
        and equal(a.opacityMicromapIndexBufferStride, b.opacityMicromapIndexBufferStride) and equal(a.indexBuffer, b.indexBuffer)
        and equal(a.vertexBuffer, b.vertexBuffer) and equal(a.geometryIndexAndFlagsBuffer, b.geometryIndexAndFlagsBuffer)
        and equal(a.opacityMicromapArray, b.opacityMicromapArray) and equal(a.opacityMicromapIndexBuffer, b.opacityMicromapIndexBuffer)
        and equal(a.instantiationBoundingBoxLimit, b.instantiationBoundingBoxLimit);
}

[[nodiscard]] inline constexpr bool operator!=(const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& a,
                                               const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& a,
                                                const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.clusterID)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.clusterID, b.clusterID)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.clusterFlags, b.clusterFlags)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.triangleCount, b.triangleCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vertexCount, b.vertexCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.positionTruncateBitCount, b.positionTruncateBitCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.indexType, b.indexType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.opacityMicromapIndexType, b.opacityMicromapIndexType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.baseGeometryIndexAndGeometryFlags, b.baseGeometryIndexAndGeometryFlags));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.indexBufferStride, b.indexBufferStride)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vertexBufferStride, b.vertexBufferStride)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.geometryIndexAndFlagsBufferStride, b.geometryIndexAndFlagsBufferStride));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.opacityMicromapIndexBufferStride, b.opacityMicromapIndexBufferStride));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.indexBuffer, b.indexBuffer)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vertexBuffer, b.vertexBuffer)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.geometryIndexAndFlagsBuffer, b.geometryIndexAndFlagsBuffer));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.opacityMicromapArray, b.opacityMicromapArray)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.opacityMicromapIndexBuffer, b.opacityMicromapIndexBuffer));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.instantiationBoundingBoxLimit, b.instantiationBoundingBoxLimit));
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
inline constexpr bool equal(const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& a,
                            const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV (&a)[N],
                            const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& x,
                                 const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV>
{
    using type = decltype(VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV{}
                          <=> VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV{});
};

template<>
inline constexpr std::int32_t three_way(const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& a,
                                        const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV (&a)[N],
                                        const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(a,
                                                    b,
                                                    [](const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& x,
                                                       const VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV& y) constexpr noexcept
                                                    { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_NV_cluster_acceleration_structure)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_CLUSTER_ACCELERATION_STRUCTURE_BUILD_TRIANGLE_CLUSTER_TEMPLATE_INFO_NV_HPP
