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

#ifndef FUBUKI_FUYU_PHYSICAL_DEVICE_HPP
#define FUBUKI_FUYU_PHYSICAL_DEVICE_HPP

#include <vector>

#include <core/handle.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu
{

/// Representation of a physical device.
struct physical_device
{
    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    /// Features per Vulkan API version.
    struct features_type
    {
        /// Physical device features available in Vulkan 1.0.
        VkPhysicalDeviceFeatures vk10{
            .robustBufferAccess                      = VK_FALSE,
            .fullDrawIndexUint32                     = VK_FALSE,
            .imageCubeArray                          = VK_FALSE,
            .independentBlend                        = VK_FALSE,
            .geometryShader                          = VK_FALSE,
            .tessellationShader                      = VK_FALSE,
            .sampleRateShading                       = VK_FALSE,
            .dualSrcBlend                            = VK_FALSE,
            .logicOp                                 = VK_FALSE,
            .multiDrawIndirect                       = VK_FALSE,
            .drawIndirectFirstInstance               = VK_FALSE,
            .depthClamp                              = VK_FALSE,
            .depthBiasClamp                          = VK_FALSE,
            .fillModeNonSolid                        = VK_FALSE,
            .depthBounds                             = VK_FALSE,
            .wideLines                               = VK_FALSE,
            .largePoints                             = VK_FALSE,
            .alphaToOne                              = VK_FALSE,
            .multiViewport                           = VK_FALSE,
            .samplerAnisotropy                       = VK_FALSE,
            .textureCompressionETC2                  = VK_FALSE,
            .textureCompressionASTC_LDR              = VK_FALSE,
            .textureCompressionBC                    = VK_FALSE,
            .occlusionQueryPrecise                   = VK_FALSE,
            .pipelineStatisticsQuery                 = VK_FALSE,
            .vertexPipelineStoresAndAtomics          = VK_FALSE,
            .fragmentStoresAndAtomics                = VK_FALSE,
            .shaderTessellationAndGeometryPointSize  = VK_FALSE,
            .shaderImageGatherExtended               = VK_FALSE,
            .shaderStorageImageExtendedFormats       = VK_FALSE,
            .shaderStorageImageMultisample           = VK_FALSE,
            .shaderStorageImageReadWithoutFormat     = VK_FALSE,
            .shaderStorageImageWriteWithoutFormat    = VK_FALSE,
            .shaderUniformBufferArrayDynamicIndexing = VK_FALSE,
            .shaderSampledImageArrayDynamicIndexing  = VK_FALSE,
            .shaderStorageBufferArrayDynamicIndexing = VK_FALSE,
            .shaderStorageImageArrayDynamicIndexing  = VK_FALSE,
            .shaderClipDistance                      = VK_FALSE,
            .shaderCullDistance                      = VK_FALSE,
            .shaderFloat64                           = VK_FALSE,
            .shaderInt64                             = VK_FALSE,
            .shaderInt16                             = VK_FALSE,
            .shaderResourceResidency                 = VK_FALSE,
            .shaderResourceMinLod                    = VK_FALSE,
            .sparseBinding                           = VK_FALSE,
            .sparseResidencyBuffer                   = VK_FALSE,
            .sparseResidencyImage2D                  = VK_FALSE,
            .sparseResidencyImage3D                  = VK_FALSE,
            .sparseResidency2Samples                 = VK_FALSE,
            .sparseResidency4Samples                 = VK_FALSE,
            .sparseResidency8Samples                 = VK_FALSE,
            .sparseResidency16Samples                = VK_FALSE,
            .sparseResidencyAliased                  = VK_FALSE,
            .variableMultisampleRate                 = VK_FALSE,
            .inheritedQueries                        = VK_FALSE,
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceFeatures&() const noexcept { return vk10; }

#if defined(VK_VERSION_1_1)
        /// Physical device features (extended parameters added in Vulkan 1.1).
        VkPhysicalDeviceVulkan11Features vk11{
            .sType                              = structure_type_v<VkPhysicalDeviceVulkan11Features>,
            .pNext                              = nullptr,
            .storageBuffer16BitAccess           = VK_FALSE,
            .uniformAndStorageBuffer16BitAccess = VK_FALSE,
            .storagePushConstant16              = VK_FALSE,
            .storageInputOutput16               = VK_FALSE,
            .multiview                          = VK_FALSE,
            .multiviewGeometryShader            = VK_FALSE,
            .multiviewTessellationShader        = VK_FALSE,
            .variablePointersStorageBuffer      = VK_FALSE,
            .variablePointers                   = VK_FALSE,
            .protectedMemory                    = VK_FALSE,
            .samplerYcbcrConversion             = VK_FALSE,
            .shaderDrawParameters               = VK_FALSE,
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan11Features&() const noexcept { return vk11; }
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
        /// Physical device features (extended parameters added in Vulkan 1.2).
        VkPhysicalDeviceVulkan12Features vk12{
            .sType                                              = structure_type_v<VkPhysicalDeviceVulkan12Features>,
            .pNext                                              = nullptr,
            .samplerMirrorClampToEdge                           = VK_FALSE,
            .drawIndirectCount                                  = VK_FALSE,
            .storageBuffer8BitAccess                            = VK_FALSE,
            .uniformAndStorageBuffer8BitAccess                  = VK_FALSE,
            .storagePushConstant8                               = VK_FALSE,
            .shaderBufferInt64Atomics                           = VK_FALSE,
            .shaderSharedInt64Atomics                           = VK_FALSE,
            .shaderFloat16                                      = VK_FALSE,
            .shaderInt8                                         = VK_FALSE,
            .descriptorIndexing                                 = VK_FALSE,
            .shaderInputAttachmentArrayDynamicIndexing          = VK_FALSE,
            .shaderUniformTexelBufferArrayDynamicIndexing       = VK_FALSE,
            .shaderStorageTexelBufferArrayDynamicIndexing       = VK_FALSE,
            .shaderUniformBufferArrayNonUniformIndexing         = VK_FALSE,
            .shaderSampledImageArrayNonUniformIndexing          = VK_FALSE,
            .shaderStorageBufferArrayNonUniformIndexing         = VK_FALSE,
            .shaderStorageImageArrayNonUniformIndexing          = VK_FALSE,
            .shaderInputAttachmentArrayNonUniformIndexing       = VK_FALSE,
            .shaderUniformTexelBufferArrayNonUniformIndexing    = VK_FALSE,
            .shaderStorageTexelBufferArrayNonUniformIndexing    = VK_FALSE,
            .descriptorBindingUniformBufferUpdateAfterBind      = VK_FALSE,
            .descriptorBindingSampledImageUpdateAfterBind       = VK_FALSE,
            .descriptorBindingStorageImageUpdateAfterBind       = VK_FALSE,
            .descriptorBindingStorageBufferUpdateAfterBind      = VK_FALSE,
            .descriptorBindingUniformTexelBufferUpdateAfterBind = VK_FALSE,
            .descriptorBindingStorageTexelBufferUpdateAfterBind = VK_FALSE,
            .descriptorBindingUpdateUnusedWhilePending          = VK_FALSE,
            .descriptorBindingPartiallyBound                    = VK_FALSE,
            .descriptorBindingVariableDescriptorCount           = VK_FALSE,
            .runtimeDescriptorArray                             = VK_FALSE,
            .samplerFilterMinmax                                = VK_FALSE,
            .scalarBlockLayout                                  = VK_FALSE,
            .imagelessFramebuffer                               = VK_FALSE,
            .uniformBufferStandardLayout                        = VK_FALSE,
            .shaderSubgroupExtendedTypes                        = VK_FALSE,
            .separateDepthStencilLayouts                        = VK_FALSE,
            .hostQueryReset                                     = VK_FALSE,
            .timelineSemaphore                                  = VK_FALSE,
            .bufferDeviceAddress                                = VK_FALSE,
            .bufferDeviceAddressCaptureReplay                   = VK_FALSE,
            .bufferDeviceAddressMultiDevice                     = VK_FALSE,
            .vulkanMemoryModel                                  = VK_FALSE,
            .vulkanMemoryModelDeviceScope                       = VK_FALSE,
            .vulkanMemoryModelAvailabilityVisibilityChains      = VK_FALSE,
            .shaderOutputViewportIndex                          = VK_FALSE,
            .shaderOutputLayer                                  = VK_FALSE,
            .subgroupBroadcastDynamicId                         = VK_FALSE,
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan12Features&() const noexcept { return vk12; }
#endif // defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
        /// Physical device features (extended parameters added in Vulkan 1.3).
        VkPhysicalDeviceVulkan13Features vk13{
            .sType                                              = structure_type_v<VkPhysicalDeviceVulkan13Features>,
            .pNext                                              = nullptr,
            .robustImageAccess                                  = VK_FALSE,
            .inlineUniformBlock                                 = VK_FALSE,
            .descriptorBindingInlineUniformBlockUpdateAfterBind = VK_FALSE,
            .pipelineCreationCacheControl                       = VK_FALSE,
            .privateData                                        = VK_FALSE,
            .shaderDemoteToHelperInvocation                     = VK_FALSE,
            .shaderTerminateInvocation                          = VK_FALSE,
            .subgroupSizeControl                                = VK_FALSE,
            .computeFullSubgroups                               = VK_FALSE,
            .synchronization2                                   = VK_FALSE,
            .textureCompressionASTC_HDR                         = VK_FALSE,
            .shaderZeroInitializeWorkgroupMemory                = VK_FALSE,
            .dynamicRendering                                   = VK_FALSE,
            .shaderIntegerDotProduct                            = VK_FALSE,
            .maintenance4                                       = VK_FALSE,
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan13Features&() const noexcept { return vk13; }
#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
        /// Physical device features (extended parameters added in Vulkan 1.4).
        VkPhysicalDeviceVulkan14Features vk14{
            .sType                                  = structure_type_v<VkPhysicalDeviceVulkan14Features>,
            .pNext                                  = {},
            .globalPriorityQuery                    = {},
            .shaderSubgroupRotate                   = {},
            .shaderSubgroupRotateClustered          = {},
            .shaderFloatControls2                   = {},
            .shaderExpectAssume                     = {},
            .rectangularLines                       = {},
            .bresenhamLines                         = {},
            .smoothLines                            = {},
            .stippledRectangularLines               = {},
            .stippledBresenhamLines                 = {},
            .stippledSmoothLines                    = {},
            .vertexAttributeInstanceRateDivisor     = {},
            .vertexAttributeInstanceRateZeroDivisor = {},
            .indexTypeUint8                         = {},
            .dynamicRenderingLocalRead              = {},
            .maintenance5                           = {},
            .maintenance6                           = {},
            .pipelineProtectedAccess                = {},
            .pipelineRobustness                     = {},
            .hostImageCopy                          = {},
            .pushDescriptor                         = {},
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan14Features&() const noexcept { return vk14; }

#endif // defined(VK_VERSION_1_4)
    };

    /// Devices properties per Vulkan version.
    struct properties_type
    {
        /// Physical device properties available in Vulkan 1.0.
        VkPhysicalDeviceProperties vk10
        {
            .apiVersion        = 0,
            .driverVersion     = 0,
            .vendorID          = 0,
            .deviceID          = 0,
            .deviceType        = VK_PHYSICAL_DEVICE_TYPE_OTHER,
            .deviceName        = {},
            .pipelineCacheUUID = {},
            .limits            =
            {
                .maxImageDimension1D                             = 0,
                .maxImageDimension2D                             = 0,
                .maxImageDimension3D                             = 0,
                .maxImageDimensionCube                           = 0,
                .maxImageArrayLayers                             = 0,
                .maxTexelBufferElements                          = 0,
                .maxUniformBufferRange                           = 0,
                .maxStorageBufferRange                           = 0,
                .maxPushConstantsSize                            = 0,
                .maxMemoryAllocationCount                        = 0,
                .maxSamplerAllocationCount                       = 0,
                .bufferImageGranularity                          = 0,
                .sparseAddressSpaceSize                          = 0,
                .maxBoundDescriptorSets                          = 0,
                .maxPerStageDescriptorSamplers                   = 0,
                .maxPerStageDescriptorUniformBuffers             = 0,
                .maxPerStageDescriptorStorageBuffers             = 0,
                .maxPerStageDescriptorSampledImages              = 0,
                .maxPerStageDescriptorStorageImages              = 0,
                .maxPerStageDescriptorInputAttachments           = 0,
                .maxPerStageResources                            = 0,
                .maxDescriptorSetSamplers                        = 0,
                .maxDescriptorSetUniformBuffers                  = 0,
                .maxDescriptorSetUniformBuffersDynamic           = 0,
                .maxDescriptorSetStorageBuffers                  = 0,
                .maxDescriptorSetStorageBuffersDynamic           = 0,
                .maxDescriptorSetSampledImages                   = 0,
                .maxDescriptorSetStorageImages                   = 0,
                .maxDescriptorSetInputAttachments                = 0,
                .maxVertexInputAttributes                        = 0,
                .maxVertexInputBindings                          = 0,
                .maxVertexInputAttributeOffset                   = 0,
                .maxVertexInputBindingStride                     = 0,
                .maxVertexOutputComponents                       = 0,
                .maxTessellationGenerationLevel                  = 0,
                .maxTessellationPatchSize                        = 0,
                .maxTessellationControlPerVertexInputComponents  = 0,
                .maxTessellationControlPerVertexOutputComponents = 0,
                .maxTessellationControlPerPatchOutputComponents  = 0,
                .maxTessellationControlTotalOutputComponents     = 0,
                .maxTessellationEvaluationInputComponents        = 0,
                .maxTessellationEvaluationOutputComponents       = 0,
                .maxGeometryShaderInvocations                    = 0,
                .maxGeometryInputComponents                      = 0,
                .maxGeometryOutputComponents                     = 0,
                .maxGeometryOutputVertices                       = 0,
                .maxGeometryTotalOutputComponents                = 0,
                .maxFragmentInputComponents                      = 0,
                .maxFragmentOutputAttachments                    = 0,
                .maxFragmentDualSrcAttachments                   = 0,
                .maxFragmentCombinedOutputResources              = 0,
                .maxComputeSharedMemorySize                      = 0,
                .maxComputeWorkGroupCount                        = {0U, 0U, 0U},
                .maxComputeWorkGroupInvocations                  = 0,
                .maxComputeWorkGroupSize                         = {0U, 0U, 0U},
                .subPixelPrecisionBits                           = 0,
                .subTexelPrecisionBits                           = 0,
                .mipmapPrecisionBits                             = 0,
                .maxDrawIndexedIndexValue                        = 0,
                .maxDrawIndirectCount                            = 0,
                .maxSamplerLodBias                               = 0.f,
                .maxSamplerAnisotropy                            = 0.f,
                .maxViewports                                    = 0,
                .maxViewportDimensions                           = {0, 0},
                .viewportBoundsRange                             = {0.f, 0.f},
                .viewportSubPixelBits                            = 0,
                .minMemoryMapAlignment                           = 0,
                .minTexelBufferOffsetAlignment                   = 0,
                .minUniformBufferOffsetAlignment                 = 0,
                .minStorageBufferOffsetAlignment                 = 0,
                .minTexelOffset                                  = 0,
                .maxTexelOffset                                  = 0,
                .minTexelGatherOffset                            = 0,
                .maxTexelGatherOffset                            = 0,
                .minInterpolationOffset                          = 0.f,
                .maxInterpolationOffset                          = 0.f,
                .subPixelInterpolationOffsetBits                 = 0,
                .maxFramebufferWidth                             = 0,
                .maxFramebufferHeight                            = 0,
                .maxFramebufferLayers                            = 0,
                .framebufferColorSampleCounts                    = 0,
                .framebufferDepthSampleCounts                    = 0,
                .framebufferStencilSampleCounts                  = 0,
                .framebufferNoAttachmentsSampleCounts            = 0,
                .maxColorAttachments                             = 0,
                .sampledImageColorSampleCounts                   = 0,
                .sampledImageIntegerSampleCounts                 = 0,
                .sampledImageDepthSampleCounts                   = 0,
                .sampledImageStencilSampleCounts                 = 0,
                .storageImageSampleCounts                        = 0,
                .maxSampleMaskWords                              = 0,
                .timestampComputeAndGraphics                     = VK_FALSE,
                .timestampPeriod                                 = 0.f,
                .maxClipDistances                                = 0,
                .maxCullDistances                                = 0,
                .maxCombinedClipAndCullDistances                 = 0,
                .discreteQueuePriorities                         = 0,
                .pointSizeRange                                  = {0.f, 0.f},
                .lineWidthRange                                  = {0.f, 0.f},
                .pointSizeGranularity                            = 0.f,
                .lineWidthGranularity                            = 0.f,
                .strictLines                                     = VK_FALSE,
                .standardSampleLocations                         = VK_FALSE,
                .optimalBufferCopyOffsetAlignment                = 0,
                .optimalBufferCopyRowPitchAlignment              = 0,
                .nonCoherentAtomSize                             = 0,
            },
            .sparseProperties =
            {
                .residencyStandard2DBlockShape            = VK_FALSE,
                .residencyStandard2DMultisampleBlockShape = VK_FALSE,
                .residencyStandard3DBlockShape            = VK_FALSE,
                .residencyAlignedMipSize                  = VK_FALSE,
                .residencyNonResidentStrict               = VK_FALSE,
            },
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceProperties&() const noexcept { return vk10; }

#if defined(VK_VERSION_1_1)
        /// Physical device properties (extended parameters added in Vulkan 1.1).
        VkPhysicalDeviceVulkan11Properties vk11{
            .sType                             = structure_type_v<VkPhysicalDeviceVulkan11Properties>,
            .pNext                             = nullptr,
            .deviceUUID                        = {},
            .driverUUID                        = {},
            .deviceLUID                        = {},
            .deviceNodeMask                    = 0,
            .deviceLUIDValid                   = VK_FALSE,
            .subgroupSize                      = 0,
            .subgroupSupportedStages           = VkShaderStageFlags(),
            .subgroupSupportedOperations       = VkSubgroupFeatureFlags(),
            .subgroupQuadOperationsInAllStages = VK_FALSE,
            .pointClippingBehavior             = VkPointClippingBehavior{},
            .maxMultiviewViewCount             = 0,
            .maxMultiviewInstanceIndex         = 0,
            .protectedNoFault                  = VK_FALSE,
            .maxPerSetDescriptors              = 0,
            .maxMemoryAllocationSize           = 0,
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan11Properties&() const noexcept { return vk11; }
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
        /// Physical device properties (extended parameters added in Vulkan 1.2).
        VkPhysicalDeviceVulkan12Properties vk12{
            .sType                                                = structure_type_v<VkPhysicalDeviceVulkan12Properties>,
            .pNext                                                = nullptr,
            .driverID                                             = VkDriverId{},
            .driverName                                           = {},
            .driverInfo                                           = {},
            .conformanceVersion                                   = VkConformanceVersion{},
            .denormBehaviorIndependence                           = VkShaderFloatControlsIndependence{},
            .roundingModeIndependence                             = VkShaderFloatControlsIndependence{},
            .shaderSignedZeroInfNanPreserveFloat16                = VK_FALSE,
            .shaderSignedZeroInfNanPreserveFloat32                = VK_FALSE,
            .shaderSignedZeroInfNanPreserveFloat64                = VK_FALSE,
            .shaderDenormPreserveFloat16                          = VK_FALSE,
            .shaderDenormPreserveFloat32                          = VK_FALSE,
            .shaderDenormPreserveFloat64                          = VK_FALSE,
            .shaderDenormFlushToZeroFloat16                       = VK_FALSE,
            .shaderDenormFlushToZeroFloat32                       = VK_FALSE,
            .shaderDenormFlushToZeroFloat64                       = VK_FALSE,
            .shaderRoundingModeRTEFloat16                         = VK_FALSE,
            .shaderRoundingModeRTEFloat32                         = VK_FALSE,
            .shaderRoundingModeRTEFloat64                         = VK_FALSE,
            .shaderRoundingModeRTZFloat16                         = VK_FALSE,
            .shaderRoundingModeRTZFloat32                         = VK_FALSE,
            .shaderRoundingModeRTZFloat64                         = VK_FALSE,
            .maxUpdateAfterBindDescriptorsInAllPools              = 0,
            .shaderUniformBufferArrayNonUniformIndexingNative     = VK_FALSE,
            .shaderSampledImageArrayNonUniformIndexingNative      = VK_FALSE,
            .shaderStorageBufferArrayNonUniformIndexingNative     = VK_FALSE,
            .shaderStorageImageArrayNonUniformIndexingNative      = VK_FALSE,
            .shaderInputAttachmentArrayNonUniformIndexingNative   = VK_FALSE,
            .robustBufferAccessUpdateAfterBind                    = VK_FALSE,
            .quadDivergentImplicitLod                             = VK_FALSE,
            .maxPerStageDescriptorUpdateAfterBindSamplers         = 0,
            .maxPerStageDescriptorUpdateAfterBindUniformBuffers   = 0,
            .maxPerStageDescriptorUpdateAfterBindStorageBuffers   = 0,
            .maxPerStageDescriptorUpdateAfterBindSampledImages    = 0,
            .maxPerStageDescriptorUpdateAfterBindStorageImages    = 0,
            .maxPerStageDescriptorUpdateAfterBindInputAttachments = 0,
            .maxPerStageUpdateAfterBindResources                  = 0,
            .maxDescriptorSetUpdateAfterBindSamplers              = 0,
            .maxDescriptorSetUpdateAfterBindUniformBuffers        = 0,
            .maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = 0,
            .maxDescriptorSetUpdateAfterBindStorageBuffers        = 0,
            .maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = 0,
            .maxDescriptorSetUpdateAfterBindSampledImages         = 0,
            .maxDescriptorSetUpdateAfterBindStorageImages         = 0,
            .maxDescriptorSetUpdateAfterBindInputAttachments      = 0,
            .supportedDepthResolveModes                           = VkResolveModeFlags(),
            .supportedStencilResolveModes                         = VkResolveModeFlags(),
            .independentResolveNone                               = VK_FALSE,
            .independentResolve                                   = VK_FALSE,
            .filterMinmaxSingleComponentFormats                   = VK_FALSE,
            .filterMinmaxImageComponentMapping                    = VK_FALSE,
            .maxTimelineSemaphoreValueDifference                  = 0,
            .framebufferIntegerColorSampleCounts                  = VkSampleCountFlags(),
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan12Properties&() const noexcept { return vk12; }
#endif // defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
        /// Physical device properties (extended parameters added in Vulkan 1.3).
        VkPhysicalDeviceVulkan13Properties vk13{
            .sType                                                                         = structure_type_v<VkPhysicalDeviceVulkan13Properties>,
            .pNext                                                                         = nullptr,
            .minSubgroupSize                                                               = 0,
            .maxSubgroupSize                                                               = 0,
            .maxComputeWorkgroupSubgroups                                                  = 0,
            .requiredSubgroupSizeStages                                                    = {},
            .maxInlineUniformBlockSize                                                     = 0,
            .maxPerStageDescriptorInlineUniformBlocks                                      = 0,
            .maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks                       = 0,
            .maxDescriptorSetInlineUniformBlocks                                           = 0,
            .maxDescriptorSetUpdateAfterBindInlineUniformBlocks                            = 0,
            .maxInlineUniformTotalSize                                                     = 0,
            .integerDotProduct8BitUnsignedAccelerated                                      = VK_FALSE,
            .integerDotProduct8BitSignedAccelerated                                        = VK_FALSE,
            .integerDotProduct8BitMixedSignednessAccelerated                               = VK_FALSE,
            .integerDotProduct4x8BitPackedUnsignedAccelerated                              = VK_FALSE,
            .integerDotProduct4x8BitPackedSignedAccelerated                                = VK_FALSE,
            .integerDotProduct4x8BitPackedMixedSignednessAccelerated                       = VK_FALSE,
            .integerDotProduct16BitUnsignedAccelerated                                     = VK_FALSE,
            .integerDotProduct16BitSignedAccelerated                                       = VK_FALSE,
            .integerDotProduct16BitMixedSignednessAccelerated                              = VK_FALSE,
            .integerDotProduct32BitUnsignedAccelerated                                     = VK_FALSE,
            .integerDotProduct32BitSignedAccelerated                                       = VK_FALSE,
            .integerDotProduct32BitMixedSignednessAccelerated                              = VK_FALSE,
            .integerDotProduct64BitUnsignedAccelerated                                     = VK_FALSE,
            .integerDotProduct64BitSignedAccelerated                                       = VK_FALSE,
            .integerDotProduct64BitMixedSignednessAccelerated                              = VK_FALSE,
            .integerDotProductAccumulatingSaturating8BitUnsignedAccelerated                = VK_FALSE,
            .integerDotProductAccumulatingSaturating8BitSignedAccelerated                  = VK_FALSE,
            .integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated         = VK_FALSE,
            .integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated        = VK_FALSE,
            .integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated          = VK_FALSE,
            .integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated = VK_FALSE,
            .integerDotProductAccumulatingSaturating16BitUnsignedAccelerated               = VK_FALSE,
            .integerDotProductAccumulatingSaturating16BitSignedAccelerated                 = VK_FALSE,
            .integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated        = VK_FALSE,
            .integerDotProductAccumulatingSaturating32BitUnsignedAccelerated               = VK_FALSE,
            .integerDotProductAccumulatingSaturating32BitSignedAccelerated                 = VK_FALSE,
            .integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated        = VK_FALSE,
            .integerDotProductAccumulatingSaturating64BitUnsignedAccelerated               = VK_FALSE,
            .integerDotProductAccumulatingSaturating64BitSignedAccelerated                 = VK_FALSE,
            .integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated        = VK_FALSE,
            .storageTexelBufferOffsetAlignmentBytes                                        = 0,
            .storageTexelBufferOffsetSingleTexelAlignment                                  = VK_FALSE,
            .uniformTexelBufferOffsetAlignmentBytes                                        = 0,
            .uniformTexelBufferOffsetSingleTexelAlignment                                  = VK_FALSE,
            .maxBufferSize                                                                 = 0,
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan13Properties&() const noexcept { return vk13; }
#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)

        VkPhysicalDeviceVulkan14Properties vk14{
            .sType                                               = structure_type_v<VkPhysicalDeviceVulkan14Properties>,
            .pNext                                               = {},
            .lineSubPixelPrecisionBits                           = {},
            .maxVertexAttribDivisor                              = {},
            .supportsNonZeroFirstInstance                        = {},
            .maxPushDescriptors                                  = {},
            .dynamicRenderingLocalReadDepthStencilAttachments    = {},
            .dynamicRenderingLocalReadMultisampledAttachments    = {},
            .earlyFragmentMultisampleCoverageAfterSampleCounting = {},
            .earlyFragmentSampleMaskTestBeforeSampleCounting     = {},
            .depthStencilSwizzleOneSupport                       = {},
            .polygonModePointSize                                = {},
            .nonStrictSinglePixelWideLinesUseParallelogram       = {},
            .nonStrictWideLinesUseParallelogram                  = {},
            .blockTexelViewCompatibleMultipleLayers              = {},
            .maxCombinedImageSamplerDescriptorCount              = {},
            .fragmentShadingRateClampCombinerInputs              = {},
            .defaultRobustnessStorageBuffers                     = {},
            .defaultRobustnessUniformBuffers                     = {},
            .defaultRobustnessVertexInputs                       = {},
            .defaultRobustnessImages                             = {},
            .copySrcLayoutCount                                  = {},
            .pCopySrcLayouts                                     = {},
            .copyDstLayoutCount                                  = {},
            .pCopyDstLayouts                                     = {},
            .optimalTilingLayoutUUID                             = {},
            .identicalMemoryTypeRequirements                     = {},
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan14Properties&() const noexcept { return vk14; }

#endif // #defined(VK_VERSION_1_2)
    };

    /// Memory properties.
    struct memory_properties_type
    {
        /// Device memory properties.
        VkPhysicalDeviceMemoryProperties properties{
            .memoryTypeCount = 0,
            .memoryTypes     = {},
            .memoryHeapCount = 0,
            .memoryHeaps     = {},
        };

        [[nodiscard]] constexpr operator const VkPhysicalDeviceMemoryProperties&() const noexcept { return properties; }
    };

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    //-------------------------------------
    // Handle

    [[nodiscard]] constexpr operator physical_device_handle() const noexcept { return handle; }

    //-------------------------------------
    // Features

    [[nodiscard]] constexpr operator const features_type&() const noexcept { return features; }

    [[nodiscard]] constexpr operator const VkPhysicalDeviceFeatures&() const noexcept { return features; }

#if defined(VK_VERSION_1_1)
    [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan11Features&() const noexcept { return features; }
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan12Features&() const noexcept { return features; }
#endif // defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan13Features&() const noexcept { return features; }
#endif // defined(VK_VERSION_1_3)

    //-------------------------------------
    // Properties

    [[nodiscard]] constexpr operator const properties_type&() const noexcept { return properties; }

    [[nodiscard]] constexpr operator const VkPhysicalDeviceProperties&() const noexcept { return properties; }

#if defined(VK_VERSION_1_1)
    [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan11Properties&() const noexcept { return properties; }
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan12Properties&() const noexcept { return properties; }
#endif // defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    [[nodiscard]] constexpr operator const VkPhysicalDeviceVulkan13Properties&() const noexcept { return properties; }
#endif // defined(VK_VERSION_1_3)

    //-------------------------------------
    // Memory properties

    [[nodiscard]] constexpr operator const memory_properties_type&() const noexcept { return memory; }

    [[nodiscard]] constexpr operator const VkPhysicalDeviceMemoryProperties&() const noexcept { return memory; }

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    physical_device_handle             handle     = {}; ///< Device handle.
    std::vector<VkExtensionProperties> extensions = {}; ///< Extensions available to a physical device.
    features_type                      features   = {}; ///< Physical device features.
    properties_type                    properties = {}; ///< Physical device properties.
    memory_properties_type             memory     = {}; ///< Memory properties.
};

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_PHYSICAL_DEVICE_HPP
