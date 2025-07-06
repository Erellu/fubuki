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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_EXT_mesh_shader)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceMeshShaderPropertiesEXT& a,
                                               const VkPhysicalDeviceMeshShaderPropertiesEXT& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.maxTaskWorkGroupTotalCount, b.maxTaskWorkGroupTotalCount)
        and equal(a.maxTaskWorkGroupCount, b.maxTaskWorkGroupCount) and equal(a.maxTaskWorkGroupInvocations, b.maxTaskWorkGroupInvocations)
        and equal(a.maxTaskWorkGroupSize, b.maxTaskWorkGroupSize) and equal(a.maxTaskPayloadSize, b.maxTaskPayloadSize)
        and equal(a.maxTaskSharedMemorySize, b.maxTaskSharedMemorySize)
        and equal(a.maxTaskPayloadAndSharedMemorySize, b.maxTaskPayloadAndSharedMemorySize)
        and equal(a.maxMeshWorkGroupTotalCount, b.maxMeshWorkGroupTotalCount) and equal(a.maxMeshWorkGroupCount, b.maxMeshWorkGroupCount)
        and equal(a.maxMeshWorkGroupInvocations, b.maxMeshWorkGroupInvocations) and equal(a.maxMeshWorkGroupSize, b.maxMeshWorkGroupSize)
        and equal(a.maxMeshSharedMemorySize, b.maxMeshSharedMemorySize)
        and equal(a.maxMeshPayloadAndSharedMemorySize, b.maxMeshPayloadAndSharedMemorySize)
        and equal(a.maxMeshOutputMemorySize, b.maxMeshOutputMemorySize)
        and equal(a.maxMeshPayloadAndOutputMemorySize, b.maxMeshPayloadAndOutputMemorySize)
        and equal(a.maxMeshOutputComponents, b.maxMeshOutputComponents) and equal(a.maxMeshOutputVertices, b.maxMeshOutputVertices)
        and equal(a.maxMeshOutputPrimitives, b.maxMeshOutputPrimitives) and equal(a.maxMeshOutputLayers, b.maxMeshOutputLayers)
        and equal(a.maxMeshMultiviewViewCount, b.maxMeshMultiviewViewCount)
        and equal(a.meshOutputPerVertexGranularity, b.meshOutputPerVertexGranularity)
        and equal(a.meshOutputPerPrimitiveGranularity, b.meshOutputPerPrimitiveGranularity)
        and equal(a.maxPreferredTaskWorkGroupInvocations, b.maxPreferredTaskWorkGroupInvocations)
        and equal(a.maxPreferredMeshWorkGroupInvocations, b.maxPreferredMeshWorkGroupInvocations)
        and equal(a.prefersLocalInvocationVertexOutput, b.prefersLocalInvocationVertexOutput)
        and equal(a.prefersLocalInvocationPrimitiveOutput, b.prefersLocalInvocationPrimitiveOutput)
        and equal(a.prefersCompactVertexOutput, b.prefersCompactVertexOutput)
        and equal(a.prefersCompactPrimitiveOutput, b.prefersCompactPrimitiveOutput);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceMeshShaderPropertiesEXT& a,
                                               const VkPhysicalDeviceMeshShaderPropertiesEXT& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceMeshShaderPropertiesEXT& a,
                                                const VkPhysicalDeviceMeshShaderPropertiesEXT& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTaskWorkGroupTotalCount, b.maxTaskWorkGroupTotalCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTaskWorkGroupCount, b.maxTaskWorkGroupCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTaskWorkGroupInvocations, b.maxTaskWorkGroupInvocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTaskWorkGroupSize, b.maxTaskWorkGroupSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTaskPayloadSize, b.maxTaskPayloadSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTaskSharedMemorySize, b.maxTaskSharedMemorySize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTaskPayloadAndSharedMemorySize, b.maxTaskPayloadAndSharedMemorySize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshWorkGroupTotalCount, b.maxMeshWorkGroupTotalCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshWorkGroupCount, b.maxMeshWorkGroupCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshWorkGroupInvocations, b.maxMeshWorkGroupInvocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshWorkGroupSize, b.maxMeshWorkGroupSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshSharedMemorySize, b.maxMeshSharedMemorySize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshPayloadAndSharedMemorySize, b.maxMeshPayloadAndSharedMemorySize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshOutputMemorySize, b.maxMeshOutputMemorySize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshPayloadAndOutputMemorySize, b.maxMeshPayloadAndOutputMemorySize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshOutputComponents, b.maxMeshOutputComponents)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshOutputVertices, b.maxMeshOutputVertices)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshOutputPrimitives, b.maxMeshOutputPrimitives)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshOutputLayers, b.maxMeshOutputLayers)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMeshMultiviewViewCount, b.maxMeshMultiviewViewCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.meshOutputPerVertexGranularity, b.meshOutputPerVertexGranularity));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.meshOutputPerPrimitiveGranularity, b.meshOutputPerPrimitiveGranularity));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPreferredTaskWorkGroupInvocations, b.maxPreferredTaskWorkGroupInvocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPreferredMeshWorkGroupInvocations, b.maxPreferredMeshWorkGroupInvocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.prefersLocalInvocationVertexOutput, b.prefersLocalInvocationVertexOutput));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.prefersLocalInvocationPrimitiveOutput, b.prefersLocalInvocationPrimitiveOutput));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.prefersCompactVertexOutput, b.prefersCompactVertexOutput));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.prefersCompactPrimitiveOutput, b.prefersCompactPrimitiveOutput));
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
inline constexpr bool equal(const VkPhysicalDeviceMeshShaderPropertiesEXT& a, const VkPhysicalDeviceMeshShaderPropertiesEXT& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceMeshShaderPropertiesEXT (&a)[N], const VkPhysicalDeviceMeshShaderPropertiesEXT (&b)[N]) noexcept
{
    return std::ranges::equal(
        a,
        b,
        [](const VkPhysicalDeviceMeshShaderPropertiesEXT& x, const VkPhysicalDeviceMeshShaderPropertiesEXT& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceMeshShaderPropertiesEXT>
{
    using type = decltype(VkPhysicalDeviceMeshShaderPropertiesEXT{} <=> VkPhysicalDeviceMeshShaderPropertiesEXT{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceMeshShaderPropertiesEXT& a, const VkPhysicalDeviceMeshShaderPropertiesEXT& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceMeshShaderPropertiesEXT (&a)[N],
                                        const VkPhysicalDeviceMeshShaderPropertiesEXT (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(a,
                                                    b,
                                                    [](const VkPhysicalDeviceMeshShaderPropertiesEXT& x,
                                                       const VkPhysicalDeviceMeshShaderPropertiesEXT& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_EXT_mesh_shader)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT_HPP
