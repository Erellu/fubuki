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

#include <gtest/gtest.h>

#include <core/enums.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

// clang-format off
TEST(enums, to_string_view)
{

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageLayout{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAttachmentLoadOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAttachmentStoreOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageTiling{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageViewType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCommandBufferLevel{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkComponentSwizzle{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDescriptorType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueryType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBorderColor{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineBindPoint{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineCacheHeaderVersion{})};});
    #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_EXT_pipeline_creation_cache_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineCacheCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_pipeline_creation_cache_control)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPrimitiveTopology{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSharingMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkIndexType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFilter{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSamplerMipmapMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSamplerAddressMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCompareOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPolygonMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFrontFace{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBlendFactor{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBlendOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkStencilOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkLogicOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkInternalAllocationType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSystemAllocationScope{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPhysicalDeviceType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVertexInputRate{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFormat{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkStructureType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSubpassContents{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkResult{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDynamicState{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDescriptorUpdateTemplateType{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkObjectType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkRayTracingInvocationReorderModeNV{})};});
    #endif // #if defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_LUNARG_direct_driver_loading)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDirectDriverLoadingModeLUNARG{})};});
    #endif // #if defined(VK_LUNARG_direct_driver_loading)

    #if defined(VK_AMD_anti_lag)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAntiLagModeAMD{})};});
    #endif // #if defined(VK_AMD_anti_lag)

    #if defined(VK_AMD_anti_lag)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAntiLagStageAMD{})};});
    #endif // #if defined(VK_AMD_anti_lag)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueueFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCullModeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkRenderPassCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceQueueCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMemoryPropertyFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMemoryHeapFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccessFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBufferUsageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_KHR_maintenance5)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBufferUsageFlagBits2KHR{})};});
    // #endif // #if defined(VK_KHR_maintenance5)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBufferCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderStageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageUsageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageViewCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSamplerCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_KHR_maintenance5)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineCreateFlagBits2KHR{})};});
    // #endif // #if defined(VK_KHR_maintenance5)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineShaderStageCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkColorComponentFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFenceCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSemaphoreCreateFlagBits{})};});
    // #endif // #if defined()

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFormatFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueryControlFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueryResultFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCommandBufferUsageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueryPipelineStatisticFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMemoryMapFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageAspectFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSparseImageFormatFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSparseMemoryBindFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineStageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCommandPoolCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCommandPoolResetFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCommandBufferResetFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSampleCountFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAttachmentDescriptionFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkStencilFaceFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDescriptorPoolCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDependencyFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSemaphoreType{})};});
    #endif // #if defined(VK_VERSION_1_2)

    // #if defined(VK_VERSION_1_2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSemaphoreWaitFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_KHR_surface)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPresentModeKHR{})};});
    #endif // #if defined(VK_KHR_surface)

    #if defined(VK_KHR_surface)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkColorSpaceKHR{})};});
    #endif // #if defined(VK_KHR_surface)

    // #if defined(VK_KHR_display)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDisplayPlaneAlphaFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_display)

    // #if defined(VK_KHR_surface)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCompositeAlphaFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_surface)

    // #if defined(VK_KHR_surface)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSurfaceTransformFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_surface)

    // #if defined(VK_ANDROID_native_buffer)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSwapchainImageUsageFlagBitsANDROID{})};});
    // #endif // #if defined(VK_ANDROID_native_buffer)

    #if defined(VK_KHR_calibrated_timestamps)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkTimeDomainKHR{})};});
    #endif // #if defined(VK_KHR_calibrated_timestamps)

    // #if defined(VK_EXT_debug_report)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDebugReportFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_debug_report)

    #if defined(VK_EXT_debug_marker)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDebugReportObjectTypeEXT{})};});
    #endif // #if defined(VK_EXT_debug_marker)

    #if defined(VK_EXT_device_memory_report)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceMemoryReportEventTypeEXT{})};});
    #endif // #if defined(VK_EXT_device_memory_report)

    #if defined(VK_AMD_rasterization_order)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkRasterizationOrderAMD{})};});
    #endif // #if defined(VK_AMD_rasterization_order)

    // #if defined(VK_NV_external_memory_capabilities)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalMemoryHandleTypeFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_external_memory_capabilities)

    // #if defined(VK_NV_external_memory_capabilities)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalMemoryFeatureFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_external_memory_capabilities)

    #if defined(VK_EXT_validation_flags)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkValidationCheckEXT{})};});
    #endif // #if defined(VK_EXT_validation_flags)

    #if defined(VK_EXT_validation_features)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkValidationFeatureEnableEXT{})};});
    #endif // #if defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkValidationFeatureDisableEXT{})};});
    #endif // #if defined(VK_EXT_validation_features)

    #if defined(VK_EXT_layer_settings)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkLayerSettingTypeEXT{})};});
    #endif // #if defined(VK_EXT_layer_settings)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSubgroupFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_NV_device_generated_commands)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkIndirectCommandsLayoutUsageFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_device_generated_commands)

    // #if defined(VK_NV_device_generated_commands)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkIndirectStateFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkIndirectCommandsTokenTypeNV{})};});
    #endif // #if defined(VK_NV_device_generated_commands)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPrivateDataSlotCreateFlagBits{})};});
    // #endif // #if defined()

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDescriptorSetLayoutCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalMemoryHandleTypeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalMemoryFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalSemaphoreHandleTypeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalSemaphoreFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSemaphoreImportFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalFenceHandleTypeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExternalFenceFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFenceImportFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_EXT_display_surface_counter)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSurfaceCounterFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_display_surface_counter)

    #if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDisplayPowerStateEXT{})};});
    #endif // #if defined(VK_EXT_display_control)

    #if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceEventTypeEXT{})};});
    #endif // #if defined(VK_EXT_display_control)

    #if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDisplayEventTypeEXT{})};});
    #endif // #if defined(VK_EXT_display_control)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPeerMemoryFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMemoryAllocateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_KHR_device_group)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceGroupPresentModeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_device_group)

    // #if defined(VK_KHR_swapchain)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSwapchainCreateFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_swapchain)

    #if defined(VK_NV_viewport_swizzle)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkViewportCoordinateSwizzleNV{})};});
    #endif // #if defined(VK_NV_viewport_swizzle)

    #if defined(VK_EXT_discard_rectangles)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDiscardRectangleModeEXT{})};});
    #endif // #if defined(VK_EXT_discard_rectangles)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSubpassDescriptionFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPointClippingBehavior{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSamplerReductionMode{})};});
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkTessellationDomainOrigin{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSamplerYcbcrModelConversion{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSamplerYcbcrRange{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkChromaLocation{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_blend_operation_advanced)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBlendOverlapEXT{})};});
    #endif // #if defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_NV_framebuffer_mixed_samples)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCoverageModulationModeNV{})};});
    #endif // #if defined(VK_NV_framebuffer_mixed_samples)

    #if defined(VK_NV_coverage_reduction_mode)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCoverageReductionModeNV{})};});
    #endif // #if defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_EXT_validation_cache)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkValidationCacheHeaderVersionEXT{})};});
    #endif // #if defined(VK_EXT_validation_cache)

    #if defined(VK_AMD_shader_info)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderInfoTypeAMD{})};});
    #endif // #if defined(VK_AMD_shader_info)

    #if defined(VK_KHR_global_priority)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueueGlobalPriorityKHR{})};});
    #endif // #if defined(VK_KHR_global_priority)

    // #if defined(VK_EXT_debug_utils)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDebugUtilsMessageSeverityFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_debug_utils)

    // #if defined(VK_EXT_debug_utils)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDebugUtilsMessageTypeFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_debug_utils)

    #if defined(VK_EXT_conservative_rasterization)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkConservativeRasterizationModeEXT{})};});
    #endif // #if defined(VK_EXT_conservative_rasterization)

    // #if defined(VK_VERSION_1_2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDescriptorBindingFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVendorId{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDriverId{})};});
    #endif // #if defined(VK_VERSION_1_2)

    // #if defined(VK_EXT_conditional_rendering)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkConditionalRenderingFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_conditional_rendering)

    // #if defined(VK_VERSION_1_2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkResolveModeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShadingRatePaletteEntryNV{})};});
    #endif // #if defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCoarseSampleOrderTypeNV{})};});
    #endif // #if defined(VK_NV_shading_rate_image)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkGeometryInstanceFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkGeometryFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBuildAccelerationStructureFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccelerationStructureCreateFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCopyAccelerationStructureModeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBuildAccelerationStructureModeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccelerationStructureTypeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkGeometryTypeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccelerationStructureMemoryRequirementsTypeNV{})};});
    #endif // #if defined(VK_NV_ray_tracing)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccelerationStructureBuildTypeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkRayTracingShaderGroupTypeKHR{})};});
    #endif // #if defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccelerationStructureCompatibilityKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderGroupShaderKHR{})};});
    #endif // #if defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_AMD_memory_overallocation_behavior)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMemoryOverallocationBehaviorAMD{})};});
    #endif // #if defined(VK_AMD_memory_overallocation_behavior)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFramebufferCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_NV_device_diagnostics_config)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceDiagnosticsConfigFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_device_diagnostics_config)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineCreationFeedbackFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_full_screen_exclusive)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFullScreenExclusiveEXT{})};});
    #endif // #if defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceCounterScopeKHR{})};});
    #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_NV_memory_decompression)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMemoryDecompressionMethodFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_memory_decompression)

    #if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceCounterUnitKHR{})};});
    #endif // #if defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceCounterStorageKHR{})};});
    #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_KHR_performance_query)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceCounterDescriptionFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_KHR_performance_query)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAcquireProfilingLockFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_AMD_shader_core_properties2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderCorePropertiesFlagBitsAMD{})};});
    // #endif // #if defined(VK_AMD_shader_core_properties2)

    // #if defined(VK_KHR_object_refresh)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkRefreshObjectFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_object_refresh)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceConfigurationTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueryPoolSamplingModeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceOverrideTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceParameterTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPerformanceValueTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderFloatControlsIndependence{})};});
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineExecutableStatisticFormatKHR{})};});
    #endif // #if defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_line_rasterization)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkLineRasterizationModeKHR{})};});
    #endif // #if defined(VK_KHR_line_rasterization)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderModuleCreateFlagBits{})};});
    // #endif // #if defined()

    // #if defined(VK_AMD_pipeline_compiler_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineCompilerControlFlagBitsAMD{})};});
    // #endif // #if defined(VK_AMD_pipeline_compiler_control)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFaultLevel{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFaultType{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFaultQueryBehavior{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkToolPurposeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineMatchControl{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFragmentShadingRateCombinerOpKHR{})};});
    #endif // #if defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_NV_fragment_shading_rate_enums)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFragmentShadingRateNV{})};});
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFragmentShadingRateTypeNV{})};});
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_EXT_subpass_merge_feedback)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSubpassMergeStatusEXT{})};});
    #endif // #if defined(VK_EXT_subpass_merge_feedback)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccessFlagBits2{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineStageFlagBits2{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSubmitFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkEventCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_EXT_graphics_pipeline_library)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineLayoutCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSciSyncClientTypeNV{})};});
    #endif // #if defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkSciSyncPrimitiveTypeNV{})};});
    #endif // #if defined(VK_NV_external_sci_sync2)

    #if defined(VK_EXT_provoking_vertex)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkProvokingVertexModeEXT{})};});
    #endif // #if defined(VK_EXT_provoking_vertex)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineCacheValidationVersion{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_NV_ray_tracing_motion_blur)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkAccelerationStructureMotionInstanceTypeNV{})};});
    #endif // #if defined(VK_NV_ray_tracing_motion_blur)

    // #if defined(VK_EXT_rasterization_order_attachment_access)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineColorBlendStateCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_rasterization_order_attachment_access)

    // #if defined(VK_EXT_rasterization_order_attachment_access)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineDepthStencilStateCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_rasterization_order_attachment_access)

    // #if defined(VK_EXT_graphics_pipeline_library)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkGraphicsPipelineLibraryFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_graphics_pipeline_library)

    // #if defined(VK_EXT_device_address_binding_report)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceAddressBindingFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceAddressBindingTypeEXT{})};});
    #endif // #if defined(VK_EXT_device_address_binding_report)

    // #if defined(VK_EXT_frame_boundary)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFrameBoundaryFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_frame_boundary)

    // #if defined(VK_EXT_surface_maintenance1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPresentScalingFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_surface_maintenance1)

    // #if defined(VK_EXT_surface_maintenance1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPresentGravityFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_surface_maintenance1)

    // #if defined(VK_ARM_scheduling_controls)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPhysicalDeviceSchedulingControlsFlagBitsARM{})};});
    // #endif // #if defined(VK_ARM_scheduling_controls)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoCodecOperationFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoChromaSubsamplingFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoComponentBitDepthFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoCapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoSessionCreateFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_decode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoDecodeH264PictureLayoutFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_decode_h264)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoCodingControlFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkQueryResultStatusKHR{})};});
    #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_decode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoDecodeUsageFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_decode_queue)

    // #if defined(VK_KHR_video_decode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoDecodeCapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_decode_queue)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeFlagBitsKHR{})};});
    // #endif // #if defined()

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeUsageFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeContentFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeTuningModeKHR{})};});
    #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeCapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeFeedbackFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeRateControlModeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH264CapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h264)

    // #if defined(VK_KHR_video_encode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH264StdFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h264)

    // #if defined(VK_KHR_video_encode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH264RateControlFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h264)

    // #if defined(VK_EXT_host_image_copy)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkHostImageCopyFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_host_image_copy)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageFormatConstraintsFlagBitsFUCHSIA{})};});
    // #endif // #if defined()

    // #if defined(VK_FUCHSIA_buffer_collection)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageConstraintsInfoFlagBitsFUCHSIA{})};});
    // #endif // #if defined(VK_FUCHSIA_buffer_collection)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkFormatFeatureFlagBits2{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkRenderingFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH265CapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH265StdFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH265RateControlFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH265CtbSizeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkVideoEncodeH265TransformBlockSizeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_EXT_metal_objects)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkExportMetalObjectTypeFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_metal_objects)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkInstanceCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_EXT_image_compression_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageCompressionFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_image_compression_control)

    // #if defined(VK_EXT_image_compression_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkImageCompressionFixedRateFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_pipeline_robustness)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineRobustnessBufferBehaviorEXT{})};});
    #endif // #if defined(VK_EXT_pipeline_robustness)

    #if defined(VK_EXT_pipeline_robustness)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPipelineRobustnessImageBehaviorEXT{})};});
    #endif // #if defined(VK_EXT_pipeline_robustness)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpticalFlowGridSizeFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpticalFlowUsageFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpticalFlowPerformanceLevelNV{})};});
    #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpticalFlowSessionBindingPointNV{})};});
    #endif // #if defined(VK_NV_optical_flow)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpticalFlowSessionCreateFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpticalFlowExecuteFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMicromapTypeEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    // #if defined(VK_EXT_opacity_micromap)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBuildMicromapFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_opacity_micromap)

    // #if defined(VK_EXT_opacity_micromap)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMicromapCreateFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCopyMicromapModeEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBuildMicromapModeEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpacityMicromapFormatEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOpacityMicromapSpecialIndexEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_depth_bias_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDepthBiasRepresentationEXT{})};});
    #endif // #if defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_device_fault)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceFaultAddressTypeEXT{})};});
    #endif // #if defined(VK_EXT_device_fault)

    #if defined(VK_EXT_device_fault)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDeviceFaultVendorBinaryHeaderVersionEXT{})};});
    #endif // #if defined(VK_EXT_device_fault)

    #if defined(VK_NV_displacement_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkDisplacementMicromapFormatNV{})};});
    #endif // #if defined(VK_NV_displacement_micromap)

    // #if defined(VK_EXT_shader_object)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderCreateFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkShaderCodeTypeEXT{})};});
    #endif // #if defined(VK_EXT_shader_object)

    #if defined(VK_KHR_cooperative_matrix)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkScopeKHR{})};});
    #endif // #if defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkComponentTypeKHR{})};});
    #endif // #if defined(VK_KHR_cooperative_matrix)

    #if defined(VK_QCOM_filter_cubic_weights)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkCubicFilterWeightsQCOM{})};});
    #endif // #if defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_image_processing2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkBlockMatchWindowCompareModeQCOM{})};});
    #endif // #if defined(VK_QCOM_image_processing2)

    #if defined(VK_KHR_maintenance7)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkPhysicalDeviceLayeredApiKHR{})};});
    #endif // #if defined(VK_KHR_maintenance7)

    #if defined(VK_MSFT_layered_driver)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkLayeredDriverUnderlyingApiMSFT{})};});
    #endif // #if defined(VK_MSFT_layered_driver)

    #if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkLatencyMarkerNV{})};});
    #endif // #if defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkOutOfBandQueueTypeNV{})};});
    #endif // #if defined(VK_NV_low_latency2)

    // #if defined(VK_KHR_map_memory2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(VkMemoryUnmapFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_map_memory2)

}

TEST(enums, to_string)
{

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageLayout{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAttachmentLoadOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAttachmentStoreOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageTiling{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageViewType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCommandBufferLevel{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkComponentSwizzle{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDescriptorType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueryType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBorderColor{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineBindPoint{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineCacheHeaderVersion{})};});
    #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_EXT_pipeline_creation_cache_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineCacheCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_pipeline_creation_cache_control)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPrimitiveTopology{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSharingMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkIndexType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFilter{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSamplerMipmapMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSamplerAddressMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCompareOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPolygonMode{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFrontFace{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBlendFactor{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBlendOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkStencilOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkLogicOp{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkInternalAllocationType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSystemAllocationScope{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPhysicalDeviceType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVertexInputRate{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFormat{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkStructureType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSubpassContents{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkResult{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDynamicState{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDescriptorUpdateTemplateType{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkObjectType{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkRayTracingInvocationReorderModeNV{})};});
    #endif // #if defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_LUNARG_direct_driver_loading)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDirectDriverLoadingModeLUNARG{})};});
    #endif // #if defined(VK_LUNARG_direct_driver_loading)

    #if defined(VK_AMD_anti_lag)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAntiLagModeAMD{})};});
    #endif // #if defined(VK_AMD_anti_lag)

    #if defined(VK_AMD_anti_lag)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAntiLagStageAMD{})};});
    #endif // #if defined(VK_AMD_anti_lag)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueueFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCullModeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkRenderPassCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceQueueCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMemoryPropertyFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMemoryHeapFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccessFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBufferUsageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_KHR_maintenance5)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBufferUsageFlagBits2KHR{})};});
    // #endif // #if defined(VK_KHR_maintenance5)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBufferCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderStageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageUsageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageViewCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSamplerCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_KHR_maintenance5)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineCreateFlagBits2KHR{})};});
    // #endif // #if defined(VK_KHR_maintenance5)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineShaderStageCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkColorComponentFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFenceCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSemaphoreCreateFlagBits{})};});
    // #endif // #if defined()

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFormatFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueryControlFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueryResultFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCommandBufferUsageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueryPipelineStatisticFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMemoryMapFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageAspectFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSparseImageFormatFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSparseMemoryBindFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineStageFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCommandPoolCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCommandPoolResetFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCommandBufferResetFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSampleCountFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAttachmentDescriptionFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkStencilFaceFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDescriptorPoolCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDependencyFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSemaphoreType{})};});
    #endif // #if defined(VK_VERSION_1_2)

    // #if defined(VK_VERSION_1_2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSemaphoreWaitFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_KHR_surface)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPresentModeKHR{})};});
    #endif // #if defined(VK_KHR_surface)

    #if defined(VK_KHR_surface)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkColorSpaceKHR{})};});
    #endif // #if defined(VK_KHR_surface)

    // #if defined(VK_KHR_display)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDisplayPlaneAlphaFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_display)

    // #if defined(VK_KHR_surface)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCompositeAlphaFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_surface)

    // #if defined(VK_KHR_surface)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSurfaceTransformFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_surface)

    // #if defined(VK_ANDROID_native_buffer)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSwapchainImageUsageFlagBitsANDROID{})};});
    // #endif // #if defined(VK_ANDROID_native_buffer)

    #if defined(VK_KHR_calibrated_timestamps)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkTimeDomainKHR{})};});
    #endif // #if defined(VK_KHR_calibrated_timestamps)

    // #if defined(VK_EXT_debug_report)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDebugReportFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_debug_report)

    #if defined(VK_EXT_debug_marker)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDebugReportObjectTypeEXT{})};});
    #endif // #if defined(VK_EXT_debug_marker)

    #if defined(VK_EXT_device_memory_report)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceMemoryReportEventTypeEXT{})};});
    #endif // #if defined(VK_EXT_device_memory_report)

    #if defined(VK_AMD_rasterization_order)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkRasterizationOrderAMD{})};});
    #endif // #if defined(VK_AMD_rasterization_order)

    // #if defined(VK_NV_external_memory_capabilities)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalMemoryHandleTypeFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_external_memory_capabilities)

    // #if defined(VK_NV_external_memory_capabilities)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalMemoryFeatureFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_external_memory_capabilities)

    #if defined(VK_EXT_validation_flags)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkValidationCheckEXT{})};});
    #endif // #if defined(VK_EXT_validation_flags)

    #if defined(VK_EXT_validation_features)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkValidationFeatureEnableEXT{})};});
    #endif // #if defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkValidationFeatureDisableEXT{})};});
    #endif // #if defined(VK_EXT_validation_features)

    #if defined(VK_EXT_layer_settings)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkLayerSettingTypeEXT{})};});
    #endif // #if defined(VK_EXT_layer_settings)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSubgroupFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_NV_device_generated_commands)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkIndirectCommandsLayoutUsageFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_device_generated_commands)

    // #if defined(VK_NV_device_generated_commands)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkIndirectStateFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkIndirectCommandsTokenTypeNV{})};});
    #endif // #if defined(VK_NV_device_generated_commands)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPrivateDataSlotCreateFlagBits{})};});
    // #endif // #if defined()

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDescriptorSetLayoutCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalMemoryHandleTypeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalMemoryFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalSemaphoreHandleTypeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalSemaphoreFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSemaphoreImportFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalFenceHandleTypeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExternalFenceFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFenceImportFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_EXT_display_surface_counter)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSurfaceCounterFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_display_surface_counter)

    #if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDisplayPowerStateEXT{})};});
    #endif // #if defined(VK_EXT_display_control)

    #if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceEventTypeEXT{})};});
    #endif // #if defined(VK_EXT_display_control)

    #if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDisplayEventTypeEXT{})};});
    #endif // #if defined(VK_EXT_display_control)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPeerMemoryFeatureFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_VERSION_1_1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMemoryAllocateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_1)

    // #if defined(VK_KHR_device_group)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceGroupPresentModeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_device_group)

    // #if defined(VK_KHR_swapchain)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSwapchainCreateFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_swapchain)

    #if defined(VK_NV_viewport_swizzle)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkViewportCoordinateSwizzleNV{})};});
    #endif // #if defined(VK_NV_viewport_swizzle)

    #if defined(VK_EXT_discard_rectangles)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDiscardRectangleModeEXT{})};});
    #endif // #if defined(VK_EXT_discard_rectangles)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSubpassDescriptionFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPointClippingBehavior{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSamplerReductionMode{})};});
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkTessellationDomainOrigin{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSamplerYcbcrModelConversion{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSamplerYcbcrRange{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkChromaLocation{})};});
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_blend_operation_advanced)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBlendOverlapEXT{})};});
    #endif // #if defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_NV_framebuffer_mixed_samples)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCoverageModulationModeNV{})};});
    #endif // #if defined(VK_NV_framebuffer_mixed_samples)

    #if defined(VK_NV_coverage_reduction_mode)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCoverageReductionModeNV{})};});
    #endif // #if defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_EXT_validation_cache)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkValidationCacheHeaderVersionEXT{})};});
    #endif // #if defined(VK_EXT_validation_cache)

    #if defined(VK_AMD_shader_info)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderInfoTypeAMD{})};});
    #endif // #if defined(VK_AMD_shader_info)

    #if defined(VK_KHR_global_priority)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueueGlobalPriorityKHR{})};});
    #endif // #if defined(VK_KHR_global_priority)

    // #if defined(VK_EXT_debug_utils)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDebugUtilsMessageSeverityFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_debug_utils)

    // #if defined(VK_EXT_debug_utils)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDebugUtilsMessageTypeFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_debug_utils)

    #if defined(VK_EXT_conservative_rasterization)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkConservativeRasterizationModeEXT{})};});
    #endif // #if defined(VK_EXT_conservative_rasterization)

    // #if defined(VK_VERSION_1_2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDescriptorBindingFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVendorId{})};});
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDriverId{})};});
    #endif // #if defined(VK_VERSION_1_2)

    // #if defined(VK_EXT_conditional_rendering)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkConditionalRenderingFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_conditional_rendering)

    // #if defined(VK_VERSION_1_2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkResolveModeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShadingRatePaletteEntryNV{})};});
    #endif // #if defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCoarseSampleOrderTypeNV{})};});
    #endif // #if defined(VK_NV_shading_rate_image)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkGeometryInstanceFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkGeometryFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBuildAccelerationStructureFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    // #if defined(VK_KHR_acceleration_structure)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccelerationStructureCreateFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCopyAccelerationStructureModeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBuildAccelerationStructureModeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccelerationStructureTypeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkGeometryTypeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccelerationStructureMemoryRequirementsTypeNV{})};});
    #endif // #if defined(VK_NV_ray_tracing)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccelerationStructureBuildTypeKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkRayTracingShaderGroupTypeKHR{})};});
    #endif // #if defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccelerationStructureCompatibilityKHR{})};});
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderGroupShaderKHR{})};});
    #endif // #if defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_AMD_memory_overallocation_behavior)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMemoryOverallocationBehaviorAMD{})};});
    #endif // #if defined(VK_AMD_memory_overallocation_behavior)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFramebufferCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_NV_device_diagnostics_config)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceDiagnosticsConfigFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_device_diagnostics_config)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineCreationFeedbackFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_full_screen_exclusive)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFullScreenExclusiveEXT{})};});
    #endif // #if defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceCounterScopeKHR{})};});
    #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_NV_memory_decompression)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMemoryDecompressionMethodFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_memory_decompression)

    #if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceCounterUnitKHR{})};});
    #endif // #if defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceCounterStorageKHR{})};});
    #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_KHR_performance_query)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceCounterDescriptionFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_KHR_performance_query)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAcquireProfilingLockFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_performance_query)

    // #if defined(VK_AMD_shader_core_properties2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderCorePropertiesFlagBitsAMD{})};});
    // #endif // #if defined(VK_AMD_shader_core_properties2)

    // #if defined(VK_KHR_object_refresh)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkRefreshObjectFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_object_refresh)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceConfigurationTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueryPoolSamplingModeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceOverrideTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceParameterTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPerformanceValueTypeINTEL{})};});
    #endif // #if defined(VK_INTEL_performance_query)

    #if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderFloatControlsIndependence{})};});
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineExecutableStatisticFormatKHR{})};});
    #endif // #if defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_line_rasterization)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkLineRasterizationModeKHR{})};});
    #endif // #if defined(VK_KHR_line_rasterization)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderModuleCreateFlagBits{})};});
    // #endif // #if defined()

    // #if defined(VK_AMD_pipeline_compiler_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineCompilerControlFlagBitsAMD{})};});
    // #endif // #if defined(VK_AMD_pipeline_compiler_control)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFaultLevel{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFaultType{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFaultQueryBehavior{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkToolPurposeFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineMatchControl{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFragmentShadingRateCombinerOpKHR{})};});
    #endif // #if defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_NV_fragment_shading_rate_enums)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFragmentShadingRateNV{})};});
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFragmentShadingRateTypeNV{})};});
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_EXT_subpass_merge_feedback)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSubpassMergeStatusEXT{})};});
    #endif // #if defined(VK_EXT_subpass_merge_feedback)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccessFlagBits2{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineStageFlagBits2{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSubmitFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkEventCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_EXT_graphics_pipeline_library)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineLayoutCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSciSyncClientTypeNV{})};});
    #endif // #if defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkSciSyncPrimitiveTypeNV{})};});
    #endif // #if defined(VK_NV_external_sci_sync2)

    #if defined(VK_EXT_provoking_vertex)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkProvokingVertexModeEXT{})};});
    #endif // #if defined(VK_EXT_provoking_vertex)

    #if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineCacheValidationVersion{})};});
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_NV_ray_tracing_motion_blur)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkAccelerationStructureMotionInstanceTypeNV{})};});
    #endif // #if defined(VK_NV_ray_tracing_motion_blur)

    // #if defined(VK_EXT_rasterization_order_attachment_access)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineColorBlendStateCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_rasterization_order_attachment_access)

    // #if defined(VK_EXT_rasterization_order_attachment_access)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineDepthStencilStateCreateFlagBits{})};});
    // #endif // #if defined(VK_EXT_rasterization_order_attachment_access)

    // #if defined(VK_EXT_graphics_pipeline_library)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkGraphicsPipelineLibraryFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_graphics_pipeline_library)

    // #if defined(VK_EXT_device_address_binding_report)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceAddressBindingFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceAddressBindingTypeEXT{})};});
    #endif // #if defined(VK_EXT_device_address_binding_report)

    // #if defined(VK_EXT_frame_boundary)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFrameBoundaryFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_frame_boundary)

    // #if defined(VK_EXT_surface_maintenance1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPresentScalingFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_surface_maintenance1)

    // #if defined(VK_EXT_surface_maintenance1)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPresentGravityFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_surface_maintenance1)

    // #if defined(VK_ARM_scheduling_controls)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPhysicalDeviceSchedulingControlsFlagBitsARM{})};});
    // #endif // #if defined(VK_ARM_scheduling_controls)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoCodecOperationFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoChromaSubsamplingFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoComponentBitDepthFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoCapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoSessionCreateFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_decode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoDecodeH264PictureLayoutFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_decode_h264)

    // #if defined(VK_KHR_video_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoCodingControlFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkQueryResultStatusKHR{})};});
    #endif // #if defined(VK_KHR_video_queue)

    // #if defined(VK_KHR_video_decode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoDecodeUsageFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_decode_queue)

    // #if defined(VK_KHR_video_decode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoDecodeCapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_decode_queue)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeFlagBitsKHR{})};});
    // #endif // #if defined()

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeUsageFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeContentFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeTuningModeKHR{})};});
    #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeCapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeFeedbackFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_queue)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeRateControlModeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_queue)

    // #if defined(VK_KHR_video_encode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH264CapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h264)

    // #if defined(VK_KHR_video_encode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH264StdFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h264)

    // #if defined(VK_KHR_video_encode_h264)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH264RateControlFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h264)

    // #if defined(VK_EXT_host_image_copy)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkHostImageCopyFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_host_image_copy)

    // #if defined()
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageFormatConstraintsFlagBitsFUCHSIA{})};});
    // #endif // #if defined()

    // #if defined(VK_FUCHSIA_buffer_collection)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageConstraintsInfoFlagBitsFUCHSIA{})};});
    // #endif // #if defined(VK_FUCHSIA_buffer_collection)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkFormatFeatureFlagBits2{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_VERSION_1_3)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkRenderingFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_3)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH265CapabilityFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH265StdFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH265RateControlFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH265CtbSizeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_KHR_video_encode_h265)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkVideoEncodeH265TransformBlockSizeFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_video_encode_h265)

    // #if defined(VK_EXT_metal_objects)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkExportMetalObjectTypeFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_metal_objects)

    // #if defined(VK_VERSION_1_0)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkInstanceCreateFlagBits{})};});
    // #endif // #if defined(VK_VERSION_1_0)

    // #if defined(VK_EXT_image_compression_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageCompressionFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_image_compression_control)

    // #if defined(VK_EXT_image_compression_control)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkImageCompressionFixedRateFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_pipeline_robustness)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineRobustnessBufferBehaviorEXT{})};});
    #endif // #if defined(VK_EXT_pipeline_robustness)

    #if defined(VK_EXT_pipeline_robustness)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPipelineRobustnessImageBehaviorEXT{})};});
    #endif // #if defined(VK_EXT_pipeline_robustness)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpticalFlowGridSizeFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpticalFlowUsageFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpticalFlowPerformanceLevelNV{})};});
    #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpticalFlowSessionBindingPointNV{})};});
    #endif // #if defined(VK_NV_optical_flow)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpticalFlowSessionCreateFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    // #if defined(VK_NV_optical_flow)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpticalFlowExecuteFlagBitsNV{})};});
    // #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMicromapTypeEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    // #if defined(VK_EXT_opacity_micromap)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBuildMicromapFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_opacity_micromap)

    // #if defined(VK_EXT_opacity_micromap)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMicromapCreateFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCopyMicromapModeEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBuildMicromapModeEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpacityMicromapFormatEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOpacityMicromapSpecialIndexEXT{})};});
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_depth_bias_control)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDepthBiasRepresentationEXT{})};});
    #endif // #if defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_device_fault)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceFaultAddressTypeEXT{})};});
    #endif // #if defined(VK_EXT_device_fault)

    #if defined(VK_EXT_device_fault)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDeviceFaultVendorBinaryHeaderVersionEXT{})};});
    #endif // #if defined(VK_EXT_device_fault)

    #if defined(VK_NV_displacement_micromap)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkDisplacementMicromapFormatNV{})};});
    #endif // #if defined(VK_NV_displacement_micromap)

    // #if defined(VK_EXT_shader_object)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderCreateFlagBitsEXT{})};});
    // #endif // #if defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkShaderCodeTypeEXT{})};});
    #endif // #if defined(VK_EXT_shader_object)

    #if defined(VK_KHR_cooperative_matrix)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkScopeKHR{})};});
    #endif // #if defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkComponentTypeKHR{})};});
    #endif // #if defined(VK_KHR_cooperative_matrix)

    #if defined(VK_QCOM_filter_cubic_weights)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkCubicFilterWeightsQCOM{})};});
    #endif // #if defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_image_processing2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkBlockMatchWindowCompareModeQCOM{})};});
    #endif // #if defined(VK_QCOM_image_processing2)

    #if defined(VK_KHR_maintenance7)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkPhysicalDeviceLayeredApiKHR{})};});
    #endif // #if defined(VK_KHR_maintenance7)

    #if defined(VK_MSFT_layered_driver)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkLayeredDriverUnderlyingApiMSFT{})};});
    #endif // #if defined(VK_MSFT_layered_driver)

    #if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkLatencyMarkerNV{})};});
    #endif // #if defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkOutOfBandQueueTypeNV{})};});
    #endif // #if defined(VK_NV_low_latency2)

    // #if defined(VK_KHR_map_memory2)
    // STATIC_EXPECT_TRUE(requires{{fubuki::to_string(VkMemoryUnmapFlagBitsKHR{})};});
    // #endif // #if defined(VK_KHR_map_memory2)

}
// clang-format on

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
