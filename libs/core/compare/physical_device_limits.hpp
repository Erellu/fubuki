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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_LIMITS_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_LIMITS_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_0)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceLimits& a, const VkPhysicalDeviceLimits& b) noexcept
{
    using detail::compare::equal;
    return equal(a.maxImageDimension1D, b.maxImageDimension1D) and equal(a.maxImageDimension2D, b.maxImageDimension2D)
        and equal(a.maxImageDimension3D, b.maxImageDimension3D) and equal(a.maxImageDimensionCube, b.maxImageDimensionCube)
        and equal(a.maxImageArrayLayers, b.maxImageArrayLayers) and equal(a.maxTexelBufferElements, b.maxTexelBufferElements)
        and equal(a.maxUniformBufferRange, b.maxUniformBufferRange) and equal(a.maxStorageBufferRange, b.maxStorageBufferRange)
        and equal(a.maxPushConstantsSize, b.maxPushConstantsSize) and equal(a.maxMemoryAllocationCount, b.maxMemoryAllocationCount)
        and equal(a.maxSamplerAllocationCount, b.maxSamplerAllocationCount) and equal(a.bufferImageGranularity, b.bufferImageGranularity)
        and equal(a.sparseAddressSpaceSize, b.sparseAddressSpaceSize) and equal(a.maxBoundDescriptorSets, b.maxBoundDescriptorSets)
        and equal(a.maxPerStageDescriptorSamplers, b.maxPerStageDescriptorSamplers)
        and equal(a.maxPerStageDescriptorUniformBuffers, b.maxPerStageDescriptorUniformBuffers)
        and equal(a.maxPerStageDescriptorStorageBuffers, b.maxPerStageDescriptorStorageBuffers)
        and equal(a.maxPerStageDescriptorSampledImages, b.maxPerStageDescriptorSampledImages)
        and equal(a.maxPerStageDescriptorStorageImages, b.maxPerStageDescriptorStorageImages)
        and equal(a.maxPerStageDescriptorInputAttachments, b.maxPerStageDescriptorInputAttachments)
        and equal(a.maxPerStageResources, b.maxPerStageResources) and equal(a.maxDescriptorSetSamplers, b.maxDescriptorSetSamplers)
        and equal(a.maxDescriptorSetUniformBuffers, b.maxDescriptorSetUniformBuffers)
        and equal(a.maxDescriptorSetUniformBuffersDynamic, b.maxDescriptorSetUniformBuffersDynamic)
        and equal(a.maxDescriptorSetStorageBuffers, b.maxDescriptorSetStorageBuffers)
        and equal(a.maxDescriptorSetStorageBuffersDynamic, b.maxDescriptorSetStorageBuffersDynamic)
        and equal(a.maxDescriptorSetSampledImages, b.maxDescriptorSetSampledImages)
        and equal(a.maxDescriptorSetStorageImages, b.maxDescriptorSetStorageImages)
        and equal(a.maxDescriptorSetInputAttachments, b.maxDescriptorSetInputAttachments)
        and equal(a.maxVertexInputAttributes, b.maxVertexInputAttributes) and equal(a.maxVertexInputBindings, b.maxVertexInputBindings)
        and equal(a.maxVertexInputAttributeOffset, b.maxVertexInputAttributeOffset)
        and equal(a.maxVertexInputBindingStride, b.maxVertexInputBindingStride) and equal(a.maxVertexOutputComponents, b.maxVertexOutputComponents)
        and equal(a.maxTessellationGenerationLevel, b.maxTessellationGenerationLevel)
        and equal(a.maxTessellationPatchSize, b.maxTessellationPatchSize)
        and equal(a.maxTessellationControlPerVertexInputComponents, b.maxTessellationControlPerVertexInputComponents)
        and equal(a.maxTessellationControlPerVertexOutputComponents, b.maxTessellationControlPerVertexOutputComponents)
        and equal(a.maxTessellationControlPerPatchOutputComponents, b.maxTessellationControlPerPatchOutputComponents)
        and equal(a.maxTessellationControlTotalOutputComponents, b.maxTessellationControlTotalOutputComponents)
        and equal(a.maxTessellationEvaluationInputComponents, b.maxTessellationEvaluationInputComponents)
        and equal(a.maxTessellationEvaluationOutputComponents, b.maxTessellationEvaluationOutputComponents)
        and equal(a.maxGeometryShaderInvocations, b.maxGeometryShaderInvocations)
        and equal(a.maxGeometryInputComponents, b.maxGeometryInputComponents) and equal(a.maxGeometryOutputComponents, b.maxGeometryOutputComponents)
        and equal(a.maxGeometryOutputVertices, b.maxGeometryOutputVertices)
        and equal(a.maxGeometryTotalOutputComponents, b.maxGeometryTotalOutputComponents)
        and equal(a.maxFragmentInputComponents, b.maxFragmentInputComponents)
        and equal(a.maxFragmentOutputAttachments, b.maxFragmentOutputAttachments)
        and equal(a.maxFragmentDualSrcAttachments, b.maxFragmentDualSrcAttachments)
        and equal(a.maxFragmentCombinedOutputResources, b.maxFragmentCombinedOutputResources)
        and equal(a.maxComputeSharedMemorySize, b.maxComputeSharedMemorySize) and equal(a.maxComputeWorkGroupCount, b.maxComputeWorkGroupCount)
        and equal(a.maxComputeWorkGroupInvocations, b.maxComputeWorkGroupInvocations) and equal(a.maxComputeWorkGroupSize, b.maxComputeWorkGroupSize)
        and equal(a.subPixelPrecisionBits, b.subPixelPrecisionBits) and equal(a.subTexelPrecisionBits, b.subTexelPrecisionBits)
        and equal(a.mipmapPrecisionBits, b.mipmapPrecisionBits) and equal(a.maxDrawIndexedIndexValue, b.maxDrawIndexedIndexValue)
        and equal(a.maxDrawIndirectCount, b.maxDrawIndirectCount) and equal(a.maxSamplerLodBias, b.maxSamplerLodBias)
        and equal(a.maxSamplerAnisotropy, b.maxSamplerAnisotropy) and equal(a.maxViewports, b.maxViewports)
        and equal(a.maxViewportDimensions, b.maxViewportDimensions) and equal(a.viewportBoundsRange, b.viewportBoundsRange)
        and equal(a.viewportSubPixelBits, b.viewportSubPixelBits) and equal(a.minMemoryMapAlignment, b.minMemoryMapAlignment)
        and equal(a.minTexelBufferOffsetAlignment, b.minTexelBufferOffsetAlignment)
        and equal(a.minUniformBufferOffsetAlignment, b.minUniformBufferOffsetAlignment)
        and equal(a.minStorageBufferOffsetAlignment, b.minStorageBufferOffsetAlignment) and equal(a.minTexelOffset, b.minTexelOffset)
        and equal(a.maxTexelOffset, b.maxTexelOffset) and equal(a.minTexelGatherOffset, b.minTexelGatherOffset)
        and equal(a.maxTexelGatherOffset, b.maxTexelGatherOffset) and equal(a.minInterpolationOffset, b.minInterpolationOffset)
        and equal(a.maxInterpolationOffset, b.maxInterpolationOffset) and equal(a.subPixelInterpolationOffsetBits, b.subPixelInterpolationOffsetBits)
        and equal(a.maxFramebufferWidth, b.maxFramebufferWidth) and equal(a.maxFramebufferHeight, b.maxFramebufferHeight)
        and equal(a.maxFramebufferLayers, b.maxFramebufferLayers) and equal(a.framebufferColorSampleCounts, b.framebufferColorSampleCounts)
        and equal(a.framebufferDepthSampleCounts, b.framebufferDepthSampleCounts)
        and equal(a.framebufferStencilSampleCounts, b.framebufferStencilSampleCounts)
        and equal(a.framebufferNoAttachmentsSampleCounts, b.framebufferNoAttachmentsSampleCounts)
        and equal(a.maxColorAttachments, b.maxColorAttachments) and equal(a.sampledImageColorSampleCounts, b.sampledImageColorSampleCounts)
        and equal(a.sampledImageIntegerSampleCounts, b.sampledImageIntegerSampleCounts)
        and equal(a.sampledImageDepthSampleCounts, b.sampledImageDepthSampleCounts)
        and equal(a.sampledImageStencilSampleCounts, b.sampledImageStencilSampleCounts)
        and equal(a.storageImageSampleCounts, b.storageImageSampleCounts) and equal(a.maxSampleMaskWords, b.maxSampleMaskWords)
        and equal(a.timestampComputeAndGraphics, b.timestampComputeAndGraphics) and equal(a.timestampPeriod, b.timestampPeriod)
        and equal(a.maxClipDistances, b.maxClipDistances) and equal(a.maxCullDistances, b.maxCullDistances)
        and equal(a.maxCombinedClipAndCullDistances, b.maxCombinedClipAndCullDistances)
        and equal(a.discreteQueuePriorities, b.discreteQueuePriorities) and equal(a.pointSizeRange, b.pointSizeRange)
        and equal(a.lineWidthRange, b.lineWidthRange) and equal(a.pointSizeGranularity, b.pointSizeGranularity)
        and equal(a.lineWidthGranularity, b.lineWidthGranularity) and equal(a.strictLines, b.strictLines)
        and equal(a.standardSampleLocations, b.standardSampleLocations)
        and equal(a.optimalBufferCopyOffsetAlignment, b.optimalBufferCopyOffsetAlignment)
        and equal(a.optimalBufferCopyRowPitchAlignment, b.optimalBufferCopyRowPitchAlignment) and equal(a.nonCoherentAtomSize, b.nonCoherentAtomSize);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceLimits& a, const VkPhysicalDeviceLimits& b) noexcept { return not(a == b); }

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceLimits& a, const VkPhysicalDeviceLimits& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.maxImageDimension1D)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageDimension1D, b.maxImageDimension1D)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageDimension2D, b.maxImageDimension2D)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageDimension3D, b.maxImageDimension3D)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageDimensionCube, b.maxImageDimensionCube)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageArrayLayers, b.maxImageArrayLayers)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTexelBufferElements, b.maxTexelBufferElements)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxUniformBufferRange, b.maxUniformBufferRange)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxStorageBufferRange, b.maxStorageBufferRange)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPushConstantsSize, b.maxPushConstantsSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxMemoryAllocationCount, b.maxMemoryAllocationCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSamplerAllocationCount, b.maxSamplerAllocationCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferImageGranularity, b.bufferImageGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sparseAddressSpaceSize, b.sparseAddressSpaceSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxBoundDescriptorSets, b.maxBoundDescriptorSets)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageDescriptorSamplers, b.maxPerStageDescriptorSamplers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageDescriptorUniformBuffers, b.maxPerStageDescriptorUniformBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageDescriptorStorageBuffers, b.maxPerStageDescriptorStorageBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageDescriptorSampledImages, b.maxPerStageDescriptorSampledImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageDescriptorStorageImages, b.maxPerStageDescriptorStorageImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageDescriptorInputAttachments, b.maxPerStageDescriptorInputAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageResources, b.maxPerStageResources)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetSamplers, b.maxDescriptorSetSamplers)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetUniformBuffers, b.maxDescriptorSetUniformBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetUniformBuffersDynamic, b.maxDescriptorSetUniformBuffersDynamic));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetStorageBuffers, b.maxDescriptorSetStorageBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetStorageBuffersDynamic, b.maxDescriptorSetStorageBuffersDynamic));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetSampledImages, b.maxDescriptorSetSampledImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetStorageImages, b.maxDescriptorSetStorageImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetInputAttachments, b.maxDescriptorSetInputAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxVertexInputAttributes, b.maxVertexInputAttributes)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxVertexInputBindings, b.maxVertexInputBindings)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxVertexInputAttributeOffset, b.maxVertexInputAttributeOffset));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxVertexInputBindingStride, b.maxVertexInputBindingStride));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxVertexOutputComponents, b.maxVertexOutputComponents)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTessellationGenerationLevel, b.maxTessellationGenerationLevel));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTessellationPatchSize, b.maxTessellationPatchSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxTessellationControlPerVertexInputComponents, b.maxTessellationControlPerVertexInputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxTessellationControlPerVertexOutputComponents, b.maxTessellationControlPerVertexOutputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxTessellationControlPerPatchOutputComponents, b.maxTessellationControlPerPatchOutputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxTessellationControlTotalOutputComponents, b.maxTessellationControlTotalOutputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTessellationEvaluationInputComponents, b.maxTessellationEvaluationInputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTessellationEvaluationOutputComponents, b.maxTessellationEvaluationOutputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxGeometryShaderInvocations, b.maxGeometryShaderInvocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxGeometryInputComponents, b.maxGeometryInputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxGeometryOutputComponents, b.maxGeometryOutputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxGeometryOutputVertices, b.maxGeometryOutputVertices)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxGeometryTotalOutputComponents, b.maxGeometryTotalOutputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentInputComponents, b.maxFragmentInputComponents));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentOutputAttachments, b.maxFragmentOutputAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentDualSrcAttachments, b.maxFragmentDualSrcAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentCombinedOutputResources, b.maxFragmentCombinedOutputResources));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxComputeSharedMemorySize, b.maxComputeSharedMemorySize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxComputeWorkGroupCount, b.maxComputeWorkGroupCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxComputeWorkGroupInvocations, b.maxComputeWorkGroupInvocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxComputeWorkGroupSize, b.maxComputeWorkGroupSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.subPixelPrecisionBits, b.subPixelPrecisionBits)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.subTexelPrecisionBits, b.subTexelPrecisionBits)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.mipmapPrecisionBits, b.mipmapPrecisionBits)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDrawIndexedIndexValue, b.maxDrawIndexedIndexValue)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDrawIndirectCount, b.maxDrawIndirectCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSamplerLodBias, b.maxSamplerLodBias)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSamplerAnisotropy, b.maxSamplerAnisotropy)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxViewports, b.maxViewports)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxViewportDimensions, b.maxViewportDimensions)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.viewportBoundsRange, b.viewportBoundsRange)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.viewportSubPixelBits, b.viewportSubPixelBits)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minMemoryMapAlignment, b.minMemoryMapAlignment)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minTexelBufferOffsetAlignment, b.minTexelBufferOffsetAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minUniformBufferOffsetAlignment, b.minUniformBufferOffsetAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minStorageBufferOffsetAlignment, b.minStorageBufferOffsetAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minTexelOffset, b.minTexelOffset)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTexelOffset, b.maxTexelOffset)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minTexelGatherOffset, b.minTexelGatherOffset)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTexelGatherOffset, b.maxTexelGatherOffset)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.minInterpolationOffset, b.minInterpolationOffset)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxInterpolationOffset, b.maxInterpolationOffset)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.subPixelInterpolationOffsetBits, b.subPixelInterpolationOffsetBits));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFramebufferWidth, b.maxFramebufferWidth)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFramebufferHeight, b.maxFramebufferHeight)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFramebufferLayers, b.maxFramebufferLayers)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.framebufferColorSampleCounts, b.framebufferColorSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.framebufferDepthSampleCounts, b.framebufferDepthSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.framebufferStencilSampleCounts, b.framebufferStencilSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.framebufferNoAttachmentsSampleCounts, b.framebufferNoAttachmentsSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxColorAttachments, b.maxColorAttachments)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sampledImageColorSampleCounts, b.sampledImageColorSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sampledImageIntegerSampleCounts, b.sampledImageIntegerSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sampledImageDepthSampleCounts, b.sampledImageDepthSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sampledImageStencilSampleCounts, b.sampledImageStencilSampleCounts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.storageImageSampleCounts, b.storageImageSampleCounts)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSampleMaskWords, b.maxSampleMaskWords)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.timestampComputeAndGraphics, b.timestampComputeAndGraphics));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.timestampPeriod, b.timestampPeriod)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxClipDistances, b.maxClipDistances)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxCullDistances, b.maxCullDistances)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxCombinedClipAndCullDistances, b.maxCombinedClipAndCullDistances));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.discreteQueuePriorities, b.discreteQueuePriorities)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pointSizeRange, b.pointSizeRange)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.lineWidthRange, b.lineWidthRange)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pointSizeGranularity, b.pointSizeGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.lineWidthGranularity, b.lineWidthGranularity)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.strictLines, b.strictLines)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.standardSampleLocations, b.standardSampleLocations)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.optimalBufferCopyOffsetAlignment, b.optimalBufferCopyOffsetAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.optimalBufferCopyRowPitchAlignment, b.optimalBufferCopyRowPitchAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.nonCoherentAtomSize, b.nonCoherentAtomSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceLimits& a, const VkPhysicalDeviceLimits& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceLimits (&a)[N], const VkPhysicalDeviceLimits (&b)[N]) noexcept
{
    return std::ranges::equal(a, b, [](const VkPhysicalDeviceLimits& x, const VkPhysicalDeviceLimits& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceLimits>
{
    using type = decltype(VkPhysicalDeviceLimits{} <=> VkPhysicalDeviceLimits{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceLimits& a, const VkPhysicalDeviceLimits& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceLimits (&a)[N], const VkPhysicalDeviceLimits (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceLimits& x, const VkPhysicalDeviceLimits& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_0)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_LIMITS_HPP
