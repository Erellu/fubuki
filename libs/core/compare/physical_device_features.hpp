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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FEATURES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FEATURES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_0)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceFeatures& a, const VkPhysicalDeviceFeatures& b) noexcept
{
    using detail::compare::equal;
    return equal(a.robustBufferAccess, b.robustBufferAccess) and equal(a.fullDrawIndexUint32, b.fullDrawIndexUint32)
        and equal(a.imageCubeArray, b.imageCubeArray) and equal(a.independentBlend, b.independentBlend) and equal(a.geometryShader, b.geometryShader)
        and equal(a.tessellationShader, b.tessellationShader) and equal(a.sampleRateShading, b.sampleRateShading)
        and equal(a.dualSrcBlend, b.dualSrcBlend) and equal(a.logicOp, b.logicOp) and equal(a.multiDrawIndirect, b.multiDrawIndirect)
        and equal(a.drawIndirectFirstInstance, b.drawIndirectFirstInstance) and equal(a.depthClamp, b.depthClamp)
        and equal(a.depthBiasClamp, b.depthBiasClamp) and equal(a.fillModeNonSolid, b.fillModeNonSolid) and equal(a.depthBounds, b.depthBounds)
        and equal(a.wideLines, b.wideLines) and equal(a.largePoints, b.largePoints) and equal(a.alphaToOne, b.alphaToOne)
        and equal(a.multiViewport, b.multiViewport) and equal(a.samplerAnisotropy, b.samplerAnisotropy)
        and equal(a.textureCompressionETC2, b.textureCompressionETC2) and equal(a.textureCompressionASTC_LDR, b.textureCompressionASTC_LDR)
        and equal(a.textureCompressionBC, b.textureCompressionBC) and equal(a.occlusionQueryPrecise, b.occlusionQueryPrecise)
        and equal(a.pipelineStatisticsQuery, b.pipelineStatisticsQuery) and equal(a.vertexPipelineStoresAndAtomics, b.vertexPipelineStoresAndAtomics)
        and equal(a.fragmentStoresAndAtomics, b.fragmentStoresAndAtomics)
        and equal(a.shaderTessellationAndGeometryPointSize, b.shaderTessellationAndGeometryPointSize)
        and equal(a.shaderImageGatherExtended, b.shaderImageGatherExtended)
        and equal(a.shaderStorageImageExtendedFormats, b.shaderStorageImageExtendedFormats)
        and equal(a.shaderStorageImageMultisample, b.shaderStorageImageMultisample)
        and equal(a.shaderStorageImageReadWithoutFormat, b.shaderStorageImageReadWithoutFormat)
        and equal(a.shaderStorageImageWriteWithoutFormat, b.shaderStorageImageWriteWithoutFormat)
        and equal(a.shaderUniformBufferArrayDynamicIndexing, b.shaderUniformBufferArrayDynamicIndexing)
        and equal(a.shaderSampledImageArrayDynamicIndexing, b.shaderSampledImageArrayDynamicIndexing)
        and equal(a.shaderStorageBufferArrayDynamicIndexing, b.shaderStorageBufferArrayDynamicIndexing)
        and equal(a.shaderStorageImageArrayDynamicIndexing, b.shaderStorageImageArrayDynamicIndexing)
        and equal(a.shaderClipDistance, b.shaderClipDistance) and equal(a.shaderCullDistance, b.shaderCullDistance)
        and equal(a.shaderFloat64, b.shaderFloat64) and equal(a.shaderInt64, b.shaderInt64) and equal(a.shaderInt16, b.shaderInt16)
        and equal(a.shaderResourceResidency, b.shaderResourceResidency) and equal(a.shaderResourceMinLod, b.shaderResourceMinLod)
        and equal(a.sparseBinding, b.sparseBinding) and equal(a.sparseResidencyBuffer, b.sparseResidencyBuffer)
        and equal(a.sparseResidencyImage2D, b.sparseResidencyImage2D) and equal(a.sparseResidencyImage3D, b.sparseResidencyImage3D)
        and equal(a.sparseResidency2Samples, b.sparseResidency2Samples) and equal(a.sparseResidency4Samples, b.sparseResidency4Samples)
        and equal(a.sparseResidency8Samples, b.sparseResidency8Samples) and equal(a.sparseResidency16Samples, b.sparseResidency16Samples)
        and equal(a.sparseResidencyAliased, b.sparseResidencyAliased) and equal(a.variableMultisampleRate, b.variableMultisampleRate)
        and equal(a.inheritedQueries, b.inheritedQueries);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceFeatures& a, const VkPhysicalDeviceFeatures& b) noexcept { return not(a == b); }

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceFeatures& a, const VkPhysicalDeviceFeatures& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.robustBufferAccess)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.robustBufferAccess, b.robustBufferAccess)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fullDrawIndexUint32, b.fullDrawIndexUint32)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageCubeArray, b.imageCubeArray)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.independentBlend, b.independentBlend)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.geometryShader, b.geometryShader)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.tessellationShader, b.tessellationShader)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sampleRateShading, b.sampleRateShading)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.dualSrcBlend, b.dualSrcBlend)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.logicOp, b.logicOp)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.multiDrawIndirect, b.multiDrawIndirect)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.drawIndirectFirstInstance, b.drawIndirectFirstInstance)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.depthClamp, b.depthClamp)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.depthBiasClamp, b.depthBiasClamp)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fillModeNonSolid, b.fillModeNonSolid)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.depthBounds, b.depthBounds)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.wideLines, b.wideLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.largePoints, b.largePoints)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.alphaToOne, b.alphaToOne)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.multiViewport, b.multiViewport)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerAnisotropy, b.samplerAnisotropy)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.textureCompressionETC2, b.textureCompressionETC2)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.textureCompressionASTC_LDR, b.textureCompressionASTC_LDR));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.textureCompressionBC, b.textureCompressionBC)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.occlusionQueryPrecise, b.occlusionQueryPrecise)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineStatisticsQuery, b.pipelineStatisticsQuery)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vertexPipelineStoresAndAtomics, b.vertexPipelineStoresAndAtomics));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fragmentStoresAndAtomics, b.fragmentStoresAndAtomics)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderTessellationAndGeometryPointSize, b.shaderTessellationAndGeometryPointSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderImageGatherExtended, b.shaderImageGatherExtended)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderStorageImageExtendedFormats, b.shaderStorageImageExtendedFormats));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderStorageImageMultisample, b.shaderStorageImageMultisample));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderStorageImageReadWithoutFormat, b.shaderStorageImageReadWithoutFormat));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderStorageImageWriteWithoutFormat, b.shaderStorageImageWriteWithoutFormat));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderUniformBufferArrayDynamicIndexing, b.shaderUniformBufferArrayDynamicIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSampledImageArrayDynamicIndexing, b.shaderSampledImageArrayDynamicIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderStorageBufferArrayDynamicIndexing, b.shaderStorageBufferArrayDynamicIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderStorageImageArrayDynamicIndexing, b.shaderStorageImageArrayDynamicIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderClipDistance, b.shaderClipDistance)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderCullDistance, b.shaderCullDistance)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderFloat64, b.shaderFloat64)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderInt64, b.shaderInt64)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderInt16, b.shaderInt16)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderResourceResidency, b.shaderResourceResidency)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderResourceMinLod, b.shaderResourceMinLod)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseBinding, b.sparseBinding)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidencyBuffer, b.sparseResidencyBuffer)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidencyImage2D, b.sparseResidencyImage2D)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidencyImage3D, b.sparseResidencyImage3D)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidency2Samples, b.sparseResidency2Samples)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidency4Samples, b.sparseResidency4Samples)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidency8Samples, b.sparseResidency8Samples)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidency16Samples, b.sparseResidency16Samples)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseResidencyAliased, b.sparseResidencyAliased)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.variableMultisampleRate, b.variableMultisampleRate)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.inheritedQueries, b.inheritedQueries)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceFeatures& a, const VkPhysicalDeviceFeatures& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceFeatures (&a)[N], const VkPhysicalDeviceFeatures (&b)[N]) noexcept
{
    return std::ranges::equal(a, b, [](const VkPhysicalDeviceFeatures& x, const VkPhysicalDeviceFeatures& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceFeatures>
{
    using type = decltype(VkPhysicalDeviceFeatures{} <=> VkPhysicalDeviceFeatures{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceFeatures& a, const VkPhysicalDeviceFeatures& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceFeatures (&a)[N], const VkPhysicalDeviceFeatures (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceFeatures& x, const VkPhysicalDeviceFeatures& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_0)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FEATURES_HPP
