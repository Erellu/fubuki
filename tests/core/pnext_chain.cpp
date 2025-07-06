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

#include <core/pnext_chain.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))
#define STATIC_EXPECT_FALSE(x) \
    static_assert(not(x));     \
    EXPECT_FALSE((x))

// clang-format off
namespace
{

using fubuki::detail::pnext_chain::can_extend_v;
using fubuki::detail::pnext_chain::chain_compatible;


TEST(pnext_chain, application_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_application_parameters)
        STATIC_EXPECT_TRUE((can_extend_v<VkApplicationInfo, VkApplicationParametersEXT>));
    #endif // defined(VK_EXT_application_parameters)

    #if defined(VK_EXT_application_parameters)
        STATIC_EXPECT_TRUE((chain_compatible<VkApplicationInfo, VkApplicationParametersEXT>));
    #endif // defined(VK_EXT_application_parameters)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, device_queue_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceQueueCreateInfo, VkDeviceQueueShaderCoreControlCreateInfoARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceQueueCreateInfo, VkDeviceQueueShaderCoreControlCreateInfoARM, VkDeviceQueueShaderCoreControlCreateInfoARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceQueueCreateInfo, VkDeviceQueueShaderCoreControlCreateInfoARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceQueueCreateInfo, VkDeviceQueueGlobalPriorityCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceQueueCreateInfo, VkDeviceQueueGlobalPriorityCreateInfo, VkDeviceQueueGlobalPriorityCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceQueueCreateInfo, VkDeviceQueueGlobalPriorityCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, device_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineProtectedAccessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineProtectedAccessFeatures, VkPhysicalDevicePipelineProtectedAccessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelineProtectedAccessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceProvokingVertexFeaturesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceProvokingVertexFeaturesEXT, VkPhysicalDeviceProvokingVertexFeaturesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceProvokingVertexFeaturesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipEnableFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipEnableFeaturesEXT, VkPhysicalDeviceDepthClipEnableFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipEnableFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_shader_replicated_composites)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>));
    #endif // defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_EXT_shader_replicated_composites)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>));
    #endif // defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_EXT_shader_replicated_composites)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>));
    #endif // defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan13Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan13Features, VkPhysicalDeviceVulkan13Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVulkan13Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>));
    #endif // defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>));
    #endif // defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>));
    #endif // defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeatures, VkPhysicalDeviceBufferDeviceAddressFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDeviceDeviceMemoryReportCreateInfoEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDeviceDeviceMemoryReportCreateInfoEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageAlignmentControlFeaturesMESA, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_KHR_depth_clamp_zero_one)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>));
    #endif // defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_KHR_depth_clamp_zero_one)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>));
    #endif // defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_KHR_depth_clamp_zero_one)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>));
    #endif // defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_KHR_shader_clock)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderClockFeaturesKHR>));
    #endif // defined(VK_KHR_shader_clock)

    #if defined(VK_KHR_shader_clock)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderClockFeaturesKHR, VkPhysicalDeviceShaderClockFeaturesKHR>));
    #endif // defined(VK_KHR_shader_clock)

    #if defined(VK_KHR_shader_clock)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderClockFeaturesKHR>));
    #endif // defined(VK_KHR_shader_clock)

    #if defined(VK_KHR_ray_tracing_position_fetch)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_KHR_ray_tracing_position_fetch)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_KHR_ray_tracing_position_fetch)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceIndexTypeUint8Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceIndexTypeUint8Features, VkPhysicalDeviceIndexTypeUint8Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceIndexTypeUint8Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampControlFeaturesEXT, VkPhysicalDeviceDepthClampControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan12Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan12Features, VkPhysicalDeviceVulkan12Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVulkan12Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloat16Int8Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloat16Int8Features, VkPhysicalDeviceShaderFloat16Int8Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloat16Int8Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_KHR_ray_tracing_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_KHR_ray_tracing_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_KHR_ray_tracing_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTextureCompressionASTCHDRFeatures, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_QCOM_tile_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTilePropertiesFeaturesQCOM>));
    #endif // defined(VK_QCOM_tile_properties)

    #if defined(VK_QCOM_tile_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTilePropertiesFeaturesQCOM, VkPhysicalDeviceTilePropertiesFeaturesQCOM>));
    #endif // defined(VK_QCOM_tile_properties)

    #if defined(VK_QCOM_tile_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceTilePropertiesFeaturesQCOM>));
    #endif // defined(VK_QCOM_tile_properties)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemorySciBufFeaturesNV, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipControlFeaturesEXT, VkPhysicalDeviceDepthClipControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan11Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan11Features, VkPhysicalDeviceVulkan11Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVulkan11Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAmigoProfilingFeaturesSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAmigoProfilingFeaturesSEC, VkPhysicalDeviceAmigoProfilingFeaturesSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceAmigoProfilingFeaturesSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_KHR_ray_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayQueryFeaturesKHR>));
    #endif // defined(VK_KHR_ray_query)

    #if defined(VK_KHR_ray_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayQueryFeaturesKHR, VkPhysicalDeviceRayQueryFeaturesKHR>));
    #endif // defined(VK_KHR_ray_query)

    #if defined(VK_KHR_ray_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayQueryFeaturesKHR>));
    #endif // defined(VK_KHR_ray_query)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerDotProductFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerDotProductFeatures, VkPhysicalDeviceShaderIntegerDotProductFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerDotProductFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_image_2d_view_of_3d)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_EXT_image_2d_view_of_3d)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_EXT_image_2d_view_of_3d)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSamplerYcbcrConversionFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSamplerYcbcrConversionFeatures, VkPhysicalDeviceSamplerYcbcrConversionFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSamplerYcbcrConversionFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_fragment_shader_interlock)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_EXT_fragment_shader_interlock)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_EXT_fragment_shader_interlock)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFeatures2>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFeatures2, VkPhysicalDeviceFeatures2>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFeatures2>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_non_seamless_cube_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>));
    #endif // defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_EXT_non_seamless_cube_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>));
    #endif // defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_EXT_non_seamless_cube_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>));
    #endif // defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_HUAWEI_invocation_mask)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_HUAWEI_invocation_mask)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_HUAWEI_invocation_mask)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_NV_raw_access_chains)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRawAccessChainsFeaturesNV>));
    #endif // defined(VK_NV_raw_access_chains)

    #if defined(VK_NV_raw_access_chains)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRawAccessChainsFeaturesNV, VkPhysicalDeviceRawAccessChainsFeaturesNV>));
    #endif // defined(VK_NV_raw_access_chains)

    #if defined(VK_NV_raw_access_chains)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRawAccessChainsFeaturesNV>));
    #endif // defined(VK_NV_raw_access_chains)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeVectorFeaturesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeVectorFeaturesNV, VkPhysicalDeviceCooperativeVectorFeaturesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeVectorFeaturesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceGlobalPriorityQueryFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceGlobalPriorityQueryFeatures, VkPhysicalDeviceGlobalPriorityQueryFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceGlobalPriorityQueryFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_INTEL_shader_integer_functions2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>));
    #endif // defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_INTEL_shader_integer_functions2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>));
    #endif // defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_INTEL_shader_integer_functions2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>));
    #endif // defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance2FeaturesKHR, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_NV_corner_sampled_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCornerSampledImageFeaturesNV>));
    #endif // defined(VK_NV_corner_sampled_image)

    #if defined(VK_NV_corner_sampled_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCornerSampledImageFeaturesNV, VkPhysicalDeviceCornerSampledImageFeaturesNV>));
    #endif // defined(VK_NV_corner_sampled_image)

    #if defined(VK_NV_corner_sampled_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCornerSampledImageFeaturesNV>));
    #endif // defined(VK_NV_corner_sampled_image)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAccelerationStructureFeaturesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAccelerationStructureFeaturesKHR, VkPhysicalDeviceAccelerationStructureFeaturesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceAccelerationStructureFeaturesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthBiasControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDepthBiasControlFeaturesEXT, VkPhysicalDeviceDepthBiasControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDepthBiasControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkanMemoryModelFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkanMemoryModelFeatures, VkPhysicalDeviceVulkanMemoryModelFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVulkanMemoryModelFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_shader_atomic_float2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_EXT_shader_atomic_float2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_EXT_shader_atomic_float2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSchedulingControlsFeaturesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSchedulingControlsFeaturesARM, VkPhysicalDeviceSchedulingControlsFeaturesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSchedulingControlsFeaturesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>));
    #endif // defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>));
    #endif // defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>));
    #endif // defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_KHR_pipeline_executable_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_pipeline_executable_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_pipeline_executable_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_present_wait)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentWaitFeaturesKHR>));
    #endif // defined(VK_KHR_present_wait)

    #if defined(VK_KHR_present_wait)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentWaitFeaturesKHR, VkPhysicalDevicePresentWaitFeaturesKHR>));
    #endif // defined(VK_KHR_present_wait)

    #if defined(VK_KHR_present_wait)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePresentWaitFeaturesKHR>));
    #endif // defined(VK_KHR_present_wait)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderObjectFeaturesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderObjectFeaturesEXT, VkPhysicalDeviceShaderObjectFeaturesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderObjectFeaturesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance4Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance4Features, VkPhysicalDeviceMaintenance4Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance4Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessingFeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessingFeaturesQCOM, VkPhysicalDeviceImageProcessingFeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessingFeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePerformanceQueryFeaturesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePerformanceQueryFeaturesKHR, VkPhysicalDevicePerformanceQueryFeaturesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePerformanceQueryFeaturesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePortabilitySubsetFeaturesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePortabilitySubsetFeaturesKHR, VkPhysicalDevicePortabilitySubsetFeaturesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePortabilitySubsetFeaturesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_EXT_pageable_device_local_memory)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>));
    #endif // defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_EXT_pageable_device_local_memory)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>));
    #endif // defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_EXT_pageable_device_local_memory)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>));
    #endif // defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDeviceGroupDeviceCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkDeviceGroupDeviceCreateInfo, VkDeviceGroupDeviceCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDeviceGroupDeviceCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceUniformBufferStandardLayoutFeatures, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSynchronization2Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSynchronization2Features, VkPhysicalDeviceSynchronization2Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSynchronization2Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorIndexingFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorIndexingFeatures, VkPhysicalDeviceDescriptorIndexingFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorIndexingFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineRobustnessFeatures, VkPhysicalDevicePipelineRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelineRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_AMD_anti_lag)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAntiLagFeaturesAMD>));
    #endif // defined(VK_AMD_anti_lag)

    #if defined(VK_AMD_anti_lag)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAntiLagFeaturesAMD, VkPhysicalDeviceAntiLagFeaturesAMD>));
    #endif // defined(VK_AMD_anti_lag)

    #if defined(VK_AMD_anti_lag)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceAntiLagFeaturesAMD>));
    #endif // defined(VK_AMD_anti_lag)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeDivisorFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeDivisorFeatures, VkPhysicalDeviceVertexAttributeDivisorFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeDivisorFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_AMD_memory_overallocation_behavior)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDeviceMemoryOverallocationCreateInfoAMD>));
    #endif // defined(VK_AMD_memory_overallocation_behavior)

    #if defined(VK_AMD_memory_overallocation_behavior)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkDeviceMemoryOverallocationCreateInfoAMD, VkDeviceMemoryOverallocationCreateInfoAMD>));
    #endif // defined(VK_AMD_memory_overallocation_behavior)

    #if defined(VK_AMD_memory_overallocation_behavior)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDeviceMemoryOverallocationCreateInfoAMD>));
    #endif // defined(VK_AMD_memory_overallocation_behavior)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDevicePrivateDataCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDevicePrivateDataCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDevicePipelineBinaryInternalCacheControlKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkDevicePipelineBinaryInternalCacheControlKHR, VkDevicePipelineBinaryInternalCacheControlKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDevicePipelineBinaryInternalCacheControlKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance5Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance5Features, VkPhysicalDeviceMaintenance5Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance5Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceOpticalFlowFeaturesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceOpticalFlowFeaturesNV, VkPhysicalDeviceOpticalFlowFeaturesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceOpticalFlowFeaturesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingLocalReadFeatures, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_NV_ray_tracing_validation)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingValidationFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_validation)

    #if defined(VK_NV_ray_tracing_validation)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingValidationFeaturesNV, VkPhysicalDeviceRayTracingValidationFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_validation)

    #if defined(VK_NV_ray_tracing_validation)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingValidationFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_validation)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_NV_per_stage_descriptor_set)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>));
    #endif // defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_NV_per_stage_descriptor_set)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePerStageDescriptorSetFeaturesNV, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>));
    #endif // defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_NV_per_stage_descriptor_set)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>));
    #endif // defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLineRasterizationFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLineRasterizationFeatures, VkPhysicalDeviceLineRasterizationFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceLineRasterizationFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_device_fault)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFaultFeaturesEXT>));
    #endif // defined(VK_EXT_device_fault)

    #if defined(VK_EXT_device_fault)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFaultFeaturesEXT, VkPhysicalDeviceFaultFeaturesEXT>));
    #endif // defined(VK_EXT_device_fault)

    #if defined(VK_EXT_device_fault)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFaultFeaturesEXT>));
    #endif // defined(VK_EXT_device_fault)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMemoryDecompressionFeaturesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMemoryDecompressionFeaturesNV, VkPhysicalDeviceMemoryDecompressionFeaturesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMemoryDecompressionFeaturesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRobustness2FeaturesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRobustness2FeaturesEXT, VkPhysicalDeviceRobustness2FeaturesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRobustness2FeaturesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>));
    #endif // defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>));
    #endif // defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>));
    #endif // defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderEnqueueFeaturesAMDX, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_EXT_extended_dynamic_state)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_extended_dynamic_state)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_extended_dynamic_state)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineCreationCacheControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineCreationCacheControlFeatures, VkPhysicalDevicePipelineCreationCacheControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelineCreationCacheControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderExpectAssumeFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderExpectAssumeFeatures, VkPhysicalDeviceShaderExpectAssumeFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderExpectAssumeFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance8FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance8FeaturesKHR, VkPhysicalDeviceMaintenance8FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance8FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_EXT_application_parameters)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkApplicationParametersEXT>));
    #endif // defined(VK_EXT_application_parameters)

    #if defined(VK_EXT_application_parameters)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkApplicationParametersEXT>));
    #endif // defined(VK_EXT_application_parameters)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>));
    #endif // defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>));
    #endif // defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>));
    #endif // defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_EXT_vertex_input_dynamic_state)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_EXT_vertex_input_dynamic_state)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_EXT_vertex_input_dynamic_state)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPipelineFeaturesKHR, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_pipeline_library_group_handles)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_EXT_pipeline_library_group_handles)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_EXT_pipeline_library_group_handles)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>));
    #endif // defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>));
    #endif // defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>));
    #endif // defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupRotateFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupRotateFeatures, VkPhysicalDeviceShaderSubgroupRotateFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupRotateFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_legacy_dithering)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLegacyDitheringFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_dithering)

    #if defined(VK_EXT_legacy_dithering)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLegacyDitheringFeaturesEXT, VkPhysicalDeviceLegacyDitheringFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_dithering)

    #if defined(VK_EXT_legacy_dithering)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceLegacyDitheringFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_dithering)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePrivateDataFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePrivateDataFeatures, VkPhysicalDevicePrivateDataFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePrivateDataFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderTerminateInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderTerminateInvocationFeatures, VkPhysicalDeviceShaderTerminateInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderTerminateInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAddressBindingReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceAddressBindingReportFeaturesEXT, VkPhysicalDeviceAddressBindingReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceAddressBindingReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_QCOM_multiview_per_view_viewports)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_QCOM_multiview_per_view_viewports)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_QCOM_multiview_per_view_viewports)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageRobustnessFeatures, VkPhysicalDeviceImageRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevice8BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevice8BitStorageFeatures, VkPhysicalDevice8BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevice8BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesKHR, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShadingRateImageFeaturesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShadingRateImageFeaturesNV, VkPhysicalDeviceShadingRateImageFeaturesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShadingRateImageFeaturesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_KHR_shader_maximal_reconvergence)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>));
    #endif // defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_KHR_shader_maximal_reconvergence)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>));
    #endif // defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_KHR_shader_maximal_reconvergence)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>));
    #endif // defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapFeaturesEXT, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance1FeaturesKHR, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentMeteringFeaturesNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentMeteringFeaturesNV, VkPhysicalDevicePresentMeteringFeaturesNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePresentMeteringFeaturesNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCubicWeightsFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCubicWeightsFeaturesQCOM, VkPhysicalDeviceCubicWeightsFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCubicWeightsFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImagelessFramebufferFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImagelessFramebufferFeatures, VkPhysicalDeviceImagelessFramebufferFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImagelessFramebufferFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_linear_color_attachment)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>));
    #endif // defined(VK_NV_linear_color_attachment)

    #if defined(VK_NV_linear_color_attachment)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceLinearColorAttachmentFeaturesNV, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>));
    #endif // defined(VK_NV_linear_color_attachment)

    #if defined(VK_NV_linear_color_attachment)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>));
    #endif // defined(VK_NV_linear_color_attachment)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceNestedCommandBufferFeaturesEXT, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>));
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>));
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>));
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_EXT_pipeline_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelinePropertiesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_properties)

    #if defined(VK_EXT_pipeline_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelinePropertiesFeaturesEXT, VkPhysicalDevicePipelinePropertiesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_properties)

    #if defined(VK_EXT_pipeline_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelinePropertiesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_properties)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>));
    #endif // defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>));
    #endif // defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>));
    #endif // defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlFeaturesEXT, VkPhysicalDeviceImageCompressionControlFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRenderPassStripedFeaturesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRenderPassStripedFeaturesARM, VkPhysicalDeviceRenderPassStripedFeaturesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRenderPassStripedFeaturesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessing2FeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessing2FeaturesQCOM, VkPhysicalDeviceImageProcessing2FeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessing2FeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_EXT_primitive_topology_list_restart)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>));
    #endif // defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_EXT_primitive_topology_list_restart)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>));
    #endif // defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_EXT_primitive_topology_list_restart)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>));
    #endif // defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_NV_descriptor_pool_overallocation)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>));
    #endif // defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_NV_descriptor_pool_overallocation)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>));
    #endif // defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_NV_descriptor_pool_overallocation)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>));
    #endif // defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVariablePointersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVariablePointersFeatures, VkPhysicalDeviceVariablePointersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVariablePointersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentIdFeaturesKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentIdFeaturesKHR, VkPhysicalDevicePresentIdFeaturesKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePresentIdFeaturesKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateFeaturesKHR, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance7FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance7FeaturesKHR, VkPhysicalDeviceMaintenance7FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance7FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMemoryPriorityFeaturesEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMemoryPriorityFeaturesEXT, VkPhysicalDeviceMemoryPriorityFeaturesEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMemoryPriorityFeaturesEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_extended_dynamic_state2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_extended_dynamic_state2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_extended_dynamic_state2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_primitives_generated_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>));
    #endif // defined(VK_EXT_primitives_generated_query)

    #if defined(VK_EXT_primitives_generated_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>));
    #endif // defined(VK_EXT_primitives_generated_query)

    #if defined(VK_EXT_primitives_generated_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>));
    #endif // defined(VK_EXT_primitives_generated_query)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceOpacityMicromapFeaturesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceOpacityMicromapFeaturesEXT, VkPhysicalDeviceOpacityMicromapFeaturesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceOpacityMicromapFeaturesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceHdrVividFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceHdrVividFeaturesHUAWEI, VkPhysicalDeviceHdrVividFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceHdrVividFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_NV_external_memory_rdma)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>));
    #endif // defined(VK_NV_external_memory_rdma)

    #if defined(VK_NV_external_memory_rdma)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>));
    #endif // defined(VK_NV_external_memory_rdma)

    #if defined(VK_NV_external_memory_rdma)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>));
    #endif // defined(VK_NV_external_memory_rdma)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewFeatures, VkPhysicalDeviceMultiviewFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTimelineSemaphoreFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTimelineSemaphoreFeatures, VkPhysicalDeviceTimelineSemaphoreFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceTimelineSemaphoreFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCudaKernelLaunchFeaturesNV, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceScalarBlockLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceScalarBlockLayoutFeatures, VkPhysicalDeviceScalarBlockLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceScalarBlockLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_ARM_pipeline_opacity_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>));
    #endif // defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_ARM_pipeline_opacity_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>));
    #endif // defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_ARM_pipeline_opacity_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>));
    #endif // defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevice16BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevice16BitStorageFeatures, VkPhysicalDevice16BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevice16BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSync2FeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSync2FeaturesNV, VkPhysicalDeviceExternalSciSync2FeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSync2FeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_EXT_rgba10x6_formats)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_EXT_rgba10x6_formats)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_EXT_rgba10x6_formats)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiDrawFeaturesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiDrawFeaturesEXT, VkPhysicalDeviceMultiDrawFeaturesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMultiDrawFeaturesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_shader_atomic_float)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float)

    #if defined(VK_EXT_shader_atomic_float)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float)

    #if defined(VK_EXT_shader_atomic_float)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTransformFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTransformFeedbackFeaturesEXT, VkPhysicalDeviceTransformFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceTransformFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceColorWriteEnableFeaturesEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceColorWriteEnableFeaturesEXT, VkPhysicalDeviceColorWriteEnableFeaturesEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceColorWriteEnableFeaturesEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_image_compression_control_swapchain)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_EXT_image_compression_control_swapchain)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_EXT_image_compression_control_swapchain)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_IMG_relaxed_line_rasterization)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>));
    #endif // defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_IMG_relaxed_line_rasterization)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>));
    #endif // defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_IMG_relaxed_line_rasterization)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>));
    #endif // defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicInt64Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicInt64Features, VkPhysicalDeviceShaderAtomicInt64Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicInt64Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDeviceObjectReservationCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDeviceObjectReservationCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExclusiveScissorFeaturesNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExclusiveScissorFeaturesNV, VkPhysicalDeviceExclusiveScissorFeaturesNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExclusiveScissorFeaturesNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDeviceDiagnosticsConfigCreateInfoNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkDeviceDiagnosticsConfigCreateInfoNV, VkDeviceDiagnosticsConfigCreateInfoNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDeviceDiagnosticsConfigCreateInfoNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_NV_shader_atomic_float16_vector)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>));
    #endif // defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_NV_shader_atomic_float16_vector)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>));
    #endif // defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_NV_shader_atomic_float16_vector)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>));
    #endif // defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesEXT, VkPhysicalDeviceMeshShaderFeaturesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_rasterization_order_attachment_access)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>));
    #endif // defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_EXT_rasterization_order_attachment_access)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>));
    #endif // defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_EXT_rasterization_order_attachment_access)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>));
    #endif // defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_QCOM_filter_cubic_clamp)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCubicClampFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VK_QCOM_filter_cubic_clamp)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCubicClampFeaturesQCOM, VkPhysicalDeviceCubicClampFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VK_QCOM_filter_cubic_clamp)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCubicClampFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkanSC10Features>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkanSC10Features, VkPhysicalDeviceVulkanSC10Features>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVulkanSC10Features>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkDeviceQueueShaderCoreControlCreateInfoARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkDeviceQueueShaderCoreControlCreateInfoARM, VkDeviceQueueShaderCoreControlCreateInfoARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkDeviceQueueShaderCoreControlCreateInfoARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_AMD_device_coherent_memory)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCoherentMemoryFeaturesAMD>));
    #endif // defined(VK_AMD_device_coherent_memory)

    #if defined(VK_AMD_device_coherent_memory)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCoherentMemoryFeaturesAMD, VkPhysicalDeviceCoherentMemoryFeaturesAMD>));
    #endif // defined(VK_AMD_device_coherent_memory)

    #if defined(VK_AMD_device_coherent_memory)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCoherentMemoryFeaturesAMD>));
    #endif // defined(VK_AMD_device_coherent_memory)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloatControls2Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloatControls2Features, VkPhysicalDeviceShaderFloatControls2Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloatControls2Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceHostImageCopyFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceHostImageCopyFeatures, VkPhysicalDeviceHostImageCopyFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceHostImageCopyFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesNV, VkPhysicalDeviceCooperativeMatrixFeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_EXT_shader_image_atomic_int64)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>));
    #endif // defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_EXT_shader_image_atomic_int64)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>));
    #endif // defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_EXT_shader_image_atomic_int64)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>));
    #endif // defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorBufferFeaturesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorBufferFeaturesEXT, VkPhysicalDeviceDescriptorBufferFeaturesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorBufferFeaturesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceConditionalRenderingFeaturesEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceConditionalRenderingFeaturesEXT, VkPhysicalDeviceConditionalRenderingFeaturesEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceConditionalRenderingFeaturesEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingFeatures, VkPhysicalDeviceDynamicRenderingFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_ycbcr_image_arrays)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_EXT_ycbcr_image_arrays)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_EXT_ycbcr_image_arrays)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceInlineUniformBlockFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceInlineUniformBlockFeatures, VkPhysicalDeviceInlineUniformBlockFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceInlineUniformBlockFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSubgroupSizeControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSubgroupSizeControlFeatures, VkPhysicalDeviceSubgroupSizeControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSubgroupSizeControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFrameBoundaryFeaturesEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceFrameBoundaryFeaturesEXT, VkPhysicalDeviceFrameBoundaryFeaturesEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceFrameBoundaryFeaturesEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDiagnosticsConfigFeaturesNV, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_EXT_texel_buffer_alignment)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>));
    #endif // defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_EXT_texel_buffer_alignment)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>));
    #endif // defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_EXT_texel_buffer_alignment)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>));
    #endif // defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_NV_command_buffer_inheritance)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>));
    #endif // defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_NV_command_buffer_inheritance)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>));
    #endif // defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_NV_command_buffer_inheritance)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>));
    #endif // defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesNV, VkPhysicalDeviceMeshShaderFeaturesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentBarrierFeaturesNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePresentBarrierFeaturesNV, VkPhysicalDevicePresentBarrierFeaturesNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePresentBarrierFeaturesNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSyncFeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSyncFeaturesNV, VkPhysicalDeviceExternalSciSyncFeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSyncFeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceProtectedMemoryFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceProtectedMemoryFeatures, VkPhysicalDeviceProtectedMemoryFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceProtectedMemoryFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageViewMinLodFeaturesEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageViewMinLodFeaturesEXT, VkPhysicalDeviceImageViewMinLodFeaturesEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageViewMinLodFeaturesEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceHostQueryResetFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceHostQueryResetFeatures, VkPhysicalDeviceHostQueryResetFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceHostQueryResetFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance6Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance6Features, VkPhysicalDeviceMaintenance6Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance6Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCustomBorderColorFeaturesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCustomBorderColorFeaturesEXT, VkPhysicalDeviceCustomBorderColorFeaturesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCustomBorderColorFeaturesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCoverageReductionModeFeaturesNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCoverageReductionModeFeaturesNV, VkPhysicalDeviceCoverageReductionModeFeaturesNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCoverageReductionModeFeaturesNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineBinaryFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevicePipelineBinaryFeaturesKHR, VkPhysicalDevicePipelineBinaryFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevicePipelineBinaryFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceASTCDecodeFeaturesEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceASTCDecodeFeaturesEXT, VkPhysicalDeviceASTCDecodeFeaturesEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceASTCDecodeFeaturesEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDisplacementMicromapFeaturesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceDisplacementMicromapFeaturesNV, VkPhysicalDeviceDisplacementMicromapFeaturesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceDisplacementMicromapFeaturesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_shader_image_footprint)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageFootprintFeaturesNV>));
    #endif // defined(VK_NV_shader_image_footprint)

    #if defined(VK_NV_shader_image_footprint)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageFootprintFeaturesNV, VkPhysicalDeviceShaderImageFootprintFeaturesNV>));
    #endif // defined(VK_NV_shader_image_footprint)

    #if defined(VK_NV_shader_image_footprint)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageFootprintFeaturesNV>));
    #endif // defined(VK_NV_shader_image_footprint)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderTileImageFeaturesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderTileImageFeaturesEXT, VkPhysicalDeviceShaderTileImageFeaturesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderTileImageFeaturesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderDrawParametersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderDrawParametersFeatures, VkPhysicalDeviceShaderDrawParametersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderDrawParametersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_KHR_shader_quad_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderQuadControlFeaturesKHR>));
    #endif // defined(VK_KHR_shader_quad_control)

    #if defined(VK_KHR_shader_quad_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderQuadControlFeaturesKHR, VkPhysicalDeviceShaderQuadControlFeaturesKHR>));
    #endif // defined(VK_KHR_shader_quad_control)

    #if defined(VK_KHR_shader_quad_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderQuadControlFeaturesKHR>));
    #endif // defined(VK_KHR_shader_quad_control)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceInheritedViewportScissorFeaturesNV, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_EXT_vertex_attribute_robustness)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_EXT_vertex_attribute_robustness)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_EXT_vertex_attribute_robustness)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>));
    #endif // defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>));
    #endif // defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>));
    #endif // defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkFaultCallbackInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkFaultCallbackInfo, VkFaultCallbackInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkFaultCallbackInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrix2FeaturesNV, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan14Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDeviceVulkan14Features, VkPhysicalDeviceVulkan14Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDeviceVulkan14Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_4444_formats)
        STATIC_EXPECT_TRUE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevice4444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_4444_formats)

    #if defined(VK_EXT_4444_formats)
        STATIC_EXPECT_FALSE((can_extend_v<VkDeviceCreateInfo, VkPhysicalDevice4444FormatsFeaturesEXT, VkPhysicalDevice4444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_4444_formats)

    #if defined(VK_EXT_4444_formats)
        STATIC_EXPECT_TRUE((chain_compatible<VkDeviceCreateInfo, VkPhysicalDevice4444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_4444_formats)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, instance_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_debug_report)
        STATIC_EXPECT_TRUE((can_extend_v<VkInstanceCreateInfo, VkDebugReportCallbackCreateInfoEXT>));
    #endif // defined(VK_EXT_debug_report)

    #if defined(VK_EXT_debug_report)
        STATIC_EXPECT_FALSE((can_extend_v<VkInstanceCreateInfo, VkDebugReportCallbackCreateInfoEXT, VkDebugReportCallbackCreateInfoEXT>));
    #endif // defined(VK_EXT_debug_report)

    #if defined(VK_EXT_debug_report)
        STATIC_EXPECT_TRUE((chain_compatible<VkInstanceCreateInfo, VkDebugReportCallbackCreateInfoEXT>));
    #endif // defined(VK_EXT_debug_report)

    #if defined(VK_EXT_layer_settings)
        STATIC_EXPECT_TRUE((can_extend_v<VkInstanceCreateInfo, VkLayerSettingsCreateInfoEXT>));
    #endif // defined(VK_EXT_layer_settings)

    #if defined(VK_EXT_layer_settings)
        STATIC_EXPECT_TRUE((chain_compatible<VkInstanceCreateInfo, VkLayerSettingsCreateInfoEXT>));
    #endif // defined(VK_EXT_layer_settings)

    #if defined(VK_LUNARG_direct_driver_loading)
        STATIC_EXPECT_TRUE((can_extend_v<VkInstanceCreateInfo, VkDirectDriverLoadingListLUNARG>));
    #endif // defined(VK_LUNARG_direct_driver_loading)

    #if defined(VK_LUNARG_direct_driver_loading)
        STATIC_EXPECT_FALSE((can_extend_v<VkInstanceCreateInfo, VkDirectDriverLoadingListLUNARG, VkDirectDriverLoadingListLUNARG>));
    #endif // defined(VK_LUNARG_direct_driver_loading)

    #if defined(VK_LUNARG_direct_driver_loading)
        STATIC_EXPECT_TRUE((chain_compatible<VkInstanceCreateInfo, VkDirectDriverLoadingListLUNARG>));
    #endif // defined(VK_LUNARG_direct_driver_loading)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkInstanceCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkInstanceCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_validation_flags)
        STATIC_EXPECT_TRUE((can_extend_v<VkInstanceCreateInfo, VkValidationFlagsEXT>));
    #endif // defined(VK_EXT_validation_flags)

    #if defined(VK_EXT_validation_flags)
        STATIC_EXPECT_FALSE((can_extend_v<VkInstanceCreateInfo, VkValidationFlagsEXT, VkValidationFlagsEXT>));
    #endif // defined(VK_EXT_validation_flags)

    #if defined(VK_EXT_validation_flags)
        STATIC_EXPECT_TRUE((chain_compatible<VkInstanceCreateInfo, VkValidationFlagsEXT>));
    #endif // defined(VK_EXT_validation_flags)

    #if defined(VK_EXT_debug_utils)
        STATIC_EXPECT_TRUE((can_extend_v<VkInstanceCreateInfo, VkDebugUtilsMessengerCreateInfoEXT>));
    #endif // defined(VK_EXT_debug_utils)

    #if defined(VK_EXT_debug_utils)
        STATIC_EXPECT_TRUE((chain_compatible<VkInstanceCreateInfo, VkDebugUtilsMessengerCreateInfoEXT>));
    #endif // defined(VK_EXT_debug_utils)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_TRUE((can_extend_v<VkInstanceCreateInfo, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_FALSE((can_extend_v<VkInstanceCreateInfo, VkValidationFeaturesEXT, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_TRUE((chain_compatible<VkInstanceCreateInfo, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, memory_allocate_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkDedicatedAllocationMemoryAllocateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkDedicatedAllocationMemoryAllocateInfoNV, VkDedicatedAllocationMemoryAllocateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkDedicatedAllocationMemoryAllocateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_EXT_external_memory_metal)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryMetalHandleInfoEXT>));
    #endif // defined(VK_EXT_external_memory_metal)

    #if defined(VK_EXT_external_memory_metal)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryMetalHandleInfoEXT, VkImportMemoryMetalHandleInfoEXT>));
    #endif // defined(VK_EXT_external_memory_metal)

    #if defined(VK_EXT_external_memory_metal)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemoryMetalHandleInfoEXT>));
    #endif // defined(VK_EXT_external_memory_metal)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryBufferCollectionFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryBufferCollectionFUCHSIA, VkImportMemoryBufferCollectionFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemoryBufferCollectionFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemorySciBufInfoNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemorySciBufInfoNV, VkImportMemorySciBufInfoNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemorySciBufInfoNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_KHR_external_memory_win32)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_memory_win32)

    #if defined(VK_KHR_external_memory_win32)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoKHR, VkExportMemoryWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_memory_win32)

    #if defined(VK_KHR_external_memory_win32)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_memory_win32)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkMemoryAllocateFlagsInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkMemoryAllocateFlagsInfo, VkMemoryAllocateFlagsInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkMemoryAllocateFlagsInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryAllocateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryAllocateInfo, VkExportMemoryAllocateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkExportMemoryAllocateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkMemoryDedicatedAllocateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkMemoryDedicatedAllocateInfo, VkMemoryDedicatedAllocateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkMemoryDedicatedAllocateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportScreenBufferInfoQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportScreenBufferInfoQNX, VkImportScreenBufferInfoQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportScreenBufferInfoQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_KHR_external_memory_fd)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryFdInfoKHR>));
    #endif // defined(VK_KHR_external_memory_fd)

    #if defined(VK_KHR_external_memory_fd)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryFdInfoKHR, VkImportMemoryFdInfoKHR>));
    #endif // defined(VK_KHR_external_memory_fd)

    #if defined(VK_KHR_external_memory_fd)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemoryFdInfoKHR>));
    #endif // defined(VK_KHR_external_memory_fd)

    #if defined(VK_EXT_external_memory_host)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryHostPointerInfoEXT>));
    #endif // defined(VK_EXT_external_memory_host)

    #if defined(VK_EXT_external_memory_host)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryHostPointerInfoEXT, VkImportMemoryHostPointerInfoEXT>));
    #endif // defined(VK_EXT_external_memory_host)

    #if defined(VK_EXT_external_memory_host)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemoryHostPointerInfoEXT>));
    #endif // defined(VK_EXT_external_memory_host)

    #if defined(VK_NV_external_memory_win32)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoNV>));
    #endif // defined(VK_NV_external_memory_win32)

    #if defined(VK_NV_external_memory_win32)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoNV, VkExportMemoryWin32HandleInfoNV>));
    #endif // defined(VK_NV_external_memory_win32)

    #if defined(VK_NV_external_memory_win32)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoNV>));
    #endif // defined(VK_NV_external_memory_win32)

    #if defined(VK_NV_external_memory)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryAllocateInfoNV>));
    #endif // defined(VK_NV_external_memory)

    #if defined(VK_NV_external_memory)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkExportMemoryAllocateInfoNV, VkExportMemoryAllocateInfoNV>));
    #endif // defined(VK_NV_external_memory)

    #if defined(VK_NV_external_memory)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkExportMemoryAllocateInfoNV>));
    #endif // defined(VK_NV_external_memory)

    #if defined(VK_NV_external_memory_win32)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoNV>));
    #endif // defined(VK_NV_external_memory_win32)

    #if defined(VK_NV_external_memory_win32)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoNV, VkImportMemoryWin32HandleInfoNV>));
    #endif // defined(VK_NV_external_memory_win32)

    #if defined(VK_NV_external_memory_win32)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoNV>));
    #endif // defined(VK_NV_external_memory_win32)

    #if defined(VK_KHR_external_memory_win32)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_memory_win32)

    #if defined(VK_KHR_external_memory_win32)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoKHR, VkImportMemoryWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_memory_win32)

    #if defined(VK_KHR_external_memory_win32)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_memory_win32)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportAndroidHardwareBufferInfoANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportAndroidHardwareBufferInfoANDROID, VkImportAndroidHardwareBufferInfoANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportAndroidHardwareBufferInfoANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkExportMemorySciBufInfoNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkExportMemorySciBufInfoNV, VkExportMemorySciBufInfoNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkExportMemorySciBufInfoNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkMemoryPriorityAllocateInfoEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkMemoryPriorityAllocateInfoEXT, VkMemoryPriorityAllocateInfoEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkMemoryPriorityAllocateInfoEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkMemoryOpaqueCaptureAddressAllocateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkMemoryOpaqueCaptureAddressAllocateInfo, VkMemoryOpaqueCaptureAddressAllocateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkMemoryOpaqueCaptureAddressAllocateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_FUCHSIA_external_memory)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryZirconHandleInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_external_memory)

    #if defined(VK_FUCHSIA_external_memory)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMemoryZirconHandleInfoFUCHSIA, VkImportMemoryZirconHandleInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_external_memory)

    #if defined(VK_FUCHSIA_external_memory)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMemoryZirconHandleInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_external_memory)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryAllocateInfo, VkImportMetalBufferInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryAllocateInfo, VkImportMetalBufferInfoEXT, VkImportMetalBufferInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryAllocateInfo, VkImportMetalBufferInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, write_descriptor_set)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_NV_ray_tracing)
        STATIC_EXPECT_TRUE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetAccelerationStructureNV>));
    #endif // defined(VK_NV_ray_tracing)

    #if defined(VK_NV_ray_tracing)
        STATIC_EXPECT_FALSE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetAccelerationStructureNV, VkWriteDescriptorSetAccelerationStructureNV>));
    #endif // defined(VK_NV_ray_tracing)

    #if defined(VK_NV_ray_tracing)
        STATIC_EXPECT_TRUE((chain_compatible<VkWriteDescriptorSet, VkWriteDescriptorSetAccelerationStructureNV>));
    #endif // defined(VK_NV_ray_tracing)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetInlineUniformBlock>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetInlineUniformBlock, VkWriteDescriptorSetInlineUniformBlock>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkWriteDescriptorSet, VkWriteDescriptorSetInlineUniformBlock>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetPartitionedAccelerationStructureNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetPartitionedAccelerationStructureNV, VkWriteDescriptorSetPartitionedAccelerationStructureNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkWriteDescriptorSet, VkWriteDescriptorSetPartitionedAccelerationStructureNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetAccelerationStructureKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkWriteDescriptorSet, VkWriteDescriptorSetAccelerationStructureKHR, VkWriteDescriptorSetAccelerationStructureKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkWriteDescriptorSet, VkWriteDescriptorSetAccelerationStructureKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, buffer_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkBufferUsageFlags2CreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkBufferDeviceAddressCreateInfoEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkBufferDeviceAddressCreateInfoEXT, VkBufferDeviceAddressCreateInfoEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkBufferDeviceAddressCreateInfoEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkBufferCollectionBufferCreateInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkBufferCollectionBufferCreateInfoFUCHSIA, VkBufferCollectionBufferCreateInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkBufferCollectionBufferCreateInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkVideoProfileListInfoKHR, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkBufferOpaqueCaptureAddressCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkBufferOpaqueCaptureAddressCreateInfo, VkBufferOpaqueCaptureAddressCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkBufferOpaqueCaptureAddressCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkExternalMemoryBufferCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkExternalMemoryBufferCreateInfo, VkExternalMemoryBufferCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkExternalMemoryBufferCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferCreateInfo, VkDedicatedAllocationBufferCreateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferCreateInfo, VkDedicatedAllocationBufferCreateInfoNV, VkDedicatedAllocationBufferCreateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferCreateInfo, VkDedicatedAllocationBufferCreateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, buffer_view_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferViewCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferViewCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferViewCreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferViewCreateInfo, VkBufferUsageFlags2CreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferViewCreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, buffer_memory_barrier)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferMemoryBarrier, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferMemoryBarrier, VkExternalMemoryAcquireUnmodifiedEXT, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferMemoryBarrier, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, image_memory_barrier)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageMemoryBarrier, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageMemoryBarrier, VkExternalMemoryAcquireUnmodifiedEXT, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageMemoryBarrier, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageMemoryBarrier, VkSampleLocationsInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageMemoryBarrier, VkSampleLocationsInfoEXT, VkSampleLocationsInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageMemoryBarrier, VkSampleLocationsInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, image_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkExternalFormatQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkExternalFormatQNX, VkExternalFormatQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkExternalFormatQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkOpticalFlowImageFormatInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkOpticalFlowImageFormatInfoNV, VkOpticalFlowImageFormatInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkOpticalFlowImageFormatInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImageCompressionControlEXT, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImageSwapchainCreateInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImageSwapchainCreateInfoKHR, VkImageSwapchainCreateInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImageSwapchainCreateInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkDedicatedAllocationImageCreateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkDedicatedAllocationImageCreateInfoNV, VkDedicatedAllocationImageCreateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_NV_dedicated_allocation)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkDedicatedAllocationImageCreateInfoNV>));
    #endif // defined(VK_NV_dedicated_allocation)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImageDrmFormatModifierListCreateInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImageDrmFormatModifierListCreateInfoEXT, VkImageDrmFormatModifierListCreateInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImageDrmFormatModifierListCreateInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkExternalMemoryImageCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkExternalMemoryImageCreateInfo, VkExternalMemoryImageCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkExternalMemoryImageCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImageAlignmentControlCreateInfoMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImageAlignmentControlCreateInfoMESA, VkImageAlignmentControlCreateInfoMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImageAlignmentControlCreateInfoMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_NV_external_memory)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkExternalMemoryImageCreateInfoNV>));
    #endif // defined(VK_NV_external_memory)

    #if defined(VK_NV_external_memory)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkExternalMemoryImageCreateInfoNV, VkExternalMemoryImageCreateInfoNV>));
    #endif // defined(VK_NV_external_memory)

    #if defined(VK_NV_external_memory)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkExternalMemoryImageCreateInfoNV>));
    #endif // defined(VK_NV_external_memory)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImageDrmFormatModifierExplicitCreateInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImageDrmFormatModifierExplicitCreateInfoEXT, VkImageDrmFormatModifierExplicitCreateInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImageDrmFormatModifierExplicitCreateInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkExternalFormatANDROID, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImportMetalIOSurfaceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImportMetalIOSurfaceInfoEXT, VkImportMetalIOSurfaceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImportMetalIOSurfaceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkBufferCollectionImageCreateInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkBufferCollectionImageCreateInfoFUCHSIA, VkBufferCollectionImageCreateInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_FUCHSIA_buffer_collection)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkBufferCollectionImageCreateInfoFUCHSIA>));
    #endif // defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImageFormatListCreateInfo, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImportMetalTextureInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImportMetalTextureInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkVideoProfileListInfoKHR, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkImageStencilUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageCreateInfo, VkImageStencilUsageCreateInfo, VkImageStencilUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkImageStencilUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, image_view_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkImageViewSlicedCreateInfoEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageViewCreateInfo, VkImageViewSlicedCreateInfoEXT, VkImageViewSlicedCreateInfoEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkImageViewSlicedCreateInfoEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageViewCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkImageViewMinLodCreateInfoEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageViewCreateInfo, VkImageViewMinLodCreateInfoEXT, VkImageViewMinLodCreateInfoEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkImageViewMinLodCreateInfoEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkImageViewASTCDecodeModeEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageViewCreateInfo, VkImageViewASTCDecodeModeEXT, VkImageViewASTCDecodeModeEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkImageViewASTCDecodeModeEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkImageViewSampleWeightCreateInfoQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageViewCreateInfo, VkImageViewSampleWeightCreateInfoQCOM, VkImageViewSampleWeightCreateInfoQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkImageViewSampleWeightCreateInfoQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkSamplerYcbcrConversionInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageViewCreateInfo, VkSamplerYcbcrConversionInfo, VkSamplerYcbcrConversionInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkSamplerYcbcrConversionInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageViewCreateInfo, VkImageViewUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageViewCreateInfo, VkImageViewUsageCreateInfo, VkImageViewUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageViewCreateInfo, VkImageViewUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, bind_sparse_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindSparseInfo, VkDeviceGroupBindSparseInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindSparseInfo, VkDeviceGroupBindSparseInfo, VkDeviceGroupBindSparseInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindSparseInfo, VkDeviceGroupBindSparseInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindSparseInfo, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindSparseInfo, VkFrameBoundaryEXT, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindSparseInfo, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindSparseInfo, VkTimelineSemaphoreSubmitInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindSparseInfo, VkTimelineSemaphoreSubmitInfo, VkTimelineSemaphoreSubmitInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindSparseInfo, VkTimelineSemaphoreSubmitInfo>));
    #endif // defined(VK_VERSION_1_2)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, shader_module_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_validation_cache)
        STATIC_EXPECT_TRUE((can_extend_v<VkShaderModuleCreateInfo, VkShaderModuleValidationCacheCreateInfoEXT>));
    #endif // defined(VK_EXT_validation_cache)

    #if defined(VK_EXT_validation_cache)
        STATIC_EXPECT_FALSE((can_extend_v<VkShaderModuleCreateInfo, VkShaderModuleValidationCacheCreateInfoEXT, VkShaderModuleValidationCacheCreateInfoEXT>));
    #endif // defined(VK_EXT_validation_cache)

    #if defined(VK_EXT_validation_cache)
        STATIC_EXPECT_TRUE((chain_compatible<VkShaderModuleCreateInfo, VkShaderModuleValidationCacheCreateInfoEXT>));
    #endif // defined(VK_EXT_validation_cache)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_TRUE((can_extend_v<VkShaderModuleCreateInfo, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_FALSE((can_extend_v<VkShaderModuleCreateInfo, VkValidationFeaturesEXT, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_TRUE((chain_compatible<VkShaderModuleCreateInfo, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, descriptor_set_layout_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorSetLayoutCreateInfo, VkMutableDescriptorTypeCreateInfoEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorSetLayoutCreateInfo, VkMutableDescriptorTypeCreateInfoEXT, VkMutableDescriptorTypeCreateInfoEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorSetLayoutCreateInfo, VkMutableDescriptorTypeCreateInfoEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorSetLayoutCreateInfo, VkDescriptorSetLayoutBindingFlagsCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorSetLayoutCreateInfo, VkDescriptorSetLayoutBindingFlagsCreateInfo, VkDescriptorSetLayoutBindingFlagsCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorSetLayoutCreateInfo, VkDescriptorSetLayoutBindingFlagsCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, descriptor_pool_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorPoolCreateInfo, VkMutableDescriptorTypeCreateInfoEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorPoolCreateInfo, VkMutableDescriptorTypeCreateInfoEXT, VkMutableDescriptorTypeCreateInfoEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorPoolCreateInfo, VkMutableDescriptorTypeCreateInfoEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorPoolCreateInfo, VkDescriptorPoolInlineUniformBlockCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorPoolCreateInfo, VkDescriptorPoolInlineUniformBlockCreateInfo, VkDescriptorPoolInlineUniformBlockCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorPoolCreateInfo, VkDescriptorPoolInlineUniformBlockCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, descriptor_set_allocate_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorSetAllocateInfo, VkDescriptorSetVariableDescriptorCountAllocateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorSetAllocateInfo, VkDescriptorSetVariableDescriptorCountAllocateInfo, VkDescriptorSetVariableDescriptorCountAllocateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorSetAllocateInfo, VkDescriptorSetVariableDescriptorCountAllocateInfo>));
    #endif // defined(VK_VERSION_1_2)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, pipeline_shader_stage_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineShaderStageCreateInfo, VkShaderModuleCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineShaderStageCreateInfo, VkShaderModuleCreateInfo, VkShaderModuleCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineShaderStageCreateInfo, VkShaderModuleCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageModuleIdentifierCreateInfoEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageModuleIdentifierCreateInfoEXT, VkPipelineShaderStageModuleIdentifierCreateInfoEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageModuleIdentifierCreateInfoEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_debug_utils)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineShaderStageCreateInfo, VkDebugUtilsObjectNameInfoEXT>));
    #endif // defined(VK_EXT_debug_utils)

    #if defined(VK_EXT_debug_utils)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineShaderStageCreateInfo, VkDebugUtilsObjectNameInfoEXT, VkDebugUtilsObjectNameInfoEXT>));
    #endif // defined(VK_EXT_debug_utils)

    #if defined(VK_EXT_debug_utils)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineShaderStageCreateInfo, VkDebugUtilsObjectNameInfoEXT>));
    #endif // defined(VK_EXT_debug_utils)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageNodeCreateInfoAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageNodeCreateInfoAMDX, VkPipelineShaderStageNodeCreateInfoAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineShaderStageCreateInfo, VkPipelineShaderStageNodeCreateInfoAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_EXT_validation_cache)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineShaderStageCreateInfo, VkShaderModuleValidationCacheCreateInfoEXT>));
    #endif // defined(VK_EXT_validation_cache)

    #if defined(VK_EXT_validation_cache)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineShaderStageCreateInfo, VkShaderModuleValidationCacheCreateInfoEXT, VkShaderModuleValidationCacheCreateInfoEXT>));
    #endif // defined(VK_EXT_validation_cache)

    #if defined(VK_EXT_validation_cache)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineShaderStageCreateInfo, VkShaderModuleValidationCacheCreateInfoEXT>));
    #endif // defined(VK_EXT_validation_cache)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineShaderStageCreateInfo, VkPipelineRobustnessCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineShaderStageCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, compute_pipeline_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineBinaryInfoKHR, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineOfflineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineCompilerControlCreateInfoAMD, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineCreateFlags2CreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineCreationFeedbackCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkSubpassShadingPipelineCreateInfoHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkSubpassShadingPipelineCreateInfoHUAWEI, VkSubpassShadingPipelineCreateInfoHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkSubpassShadingPipelineCreateInfoHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkPipelineRobustnessCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_TRUE((can_extend_v<VkComputePipelineCreateInfo, VkComputePipelineIndirectBufferInfoNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_FALSE((can_extend_v<VkComputePipelineCreateInfo, VkComputePipelineIndirectBufferInfoNV, VkComputePipelineIndirectBufferInfoNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_TRUE((chain_compatible<VkComputePipelineCreateInfo, VkComputePipelineIndirectBufferInfoNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, pipeline_vertex_input_state_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineVertexInputStateCreateInfo, VkPipelineVertexInputDivisorStateCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineVertexInputStateCreateInfo, VkPipelineVertexInputDivisorStateCreateInfo, VkPipelineVertexInputDivisorStateCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineVertexInputStateCreateInfo, VkPipelineVertexInputDivisorStateCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, pipeline_tessellation_state_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineTessellationStateCreateInfo, VkPipelineTessellationDomainOriginStateCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineTessellationStateCreateInfo, VkPipelineTessellationDomainOriginStateCreateInfo, VkPipelineTessellationDomainOriginStateCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineTessellationStateCreateInfo, VkPipelineTessellationDomainOriginStateCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, pipeline_viewport_state_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportDepthClampControlCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportDepthClampControlCreateInfoEXT, VkPipelineViewportDepthClampControlCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineViewportStateCreateInfo, VkPipelineViewportDepthClampControlCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportExclusiveScissorStateCreateInfoNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportExclusiveScissorStateCreateInfoNV, VkPipelineViewportExclusiveScissorStateCreateInfoNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineViewportStateCreateInfo, VkPipelineViewportExclusiveScissorStateCreateInfoNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_clip_space_w_scaling)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportWScalingStateCreateInfoNV>));
    #endif // defined(VK_NV_clip_space_w_scaling)

    #if defined(VK_NV_clip_space_w_scaling)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportWScalingStateCreateInfoNV, VkPipelineViewportWScalingStateCreateInfoNV>));
    #endif // defined(VK_NV_clip_space_w_scaling)

    #if defined(VK_NV_clip_space_w_scaling)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineViewportStateCreateInfo, VkPipelineViewportWScalingStateCreateInfoNV>));
    #endif // defined(VK_NV_clip_space_w_scaling)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportDepthClipControlCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportDepthClipControlCreateInfoEXT, VkPipelineViewportDepthClipControlCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineViewportStateCreateInfo, VkPipelineViewportDepthClipControlCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportShadingRateImageStateCreateInfoNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportShadingRateImageStateCreateInfoNV, VkPipelineViewportShadingRateImageStateCreateInfoNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineViewportStateCreateInfo, VkPipelineViewportShadingRateImageStateCreateInfoNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_viewport_swizzle)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportSwizzleStateCreateInfoNV>));
    #endif // defined(VK_NV_viewport_swizzle)

    #if defined(VK_NV_viewport_swizzle)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportSwizzleStateCreateInfoNV, VkPipelineViewportSwizzleStateCreateInfoNV>));
    #endif // defined(VK_NV_viewport_swizzle)

    #if defined(VK_NV_viewport_swizzle)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineViewportStateCreateInfo, VkPipelineViewportSwizzleStateCreateInfoNV>));
    #endif // defined(VK_NV_viewport_swizzle)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineViewportStateCreateInfo, VkPipelineViewportCoarseSampleOrderStateCreateInfoNV, VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineViewportStateCreateInfo, VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>));
    #endif // defined(VK_NV_shading_rate_image)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, pipeline_rasterization_state_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateStreamCreateInfoEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateStreamCreateInfoEXT, VkPipelineRasterizationStateStreamCreateInfoEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateStreamCreateInfoEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkDepthBiasRepresentationInfoEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkDepthBiasRepresentationInfoEXT, VkDepthBiasRepresentationInfoEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineRasterizationStateCreateInfo, VkDepthBiasRepresentationInfoEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationProvokingVertexStateCreateInfoEXT, VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_conservative_rasterization)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationConservativeStateCreateInfoEXT>));
    #endif // defined(VK_EXT_conservative_rasterization)

    #if defined(VK_EXT_conservative_rasterization)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationConservativeStateCreateInfoEXT, VkPipelineRasterizationConservativeStateCreateInfoEXT>));
    #endif // defined(VK_EXT_conservative_rasterization)

    #if defined(VK_EXT_conservative_rasterization)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationConservativeStateCreateInfoEXT>));
    #endif // defined(VK_EXT_conservative_rasterization)

    #if defined(VK_AMD_rasterization_order)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateRasterizationOrderAMD>));
    #endif // defined(VK_AMD_rasterization_order)

    #if defined(VK_AMD_rasterization_order)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateRasterizationOrderAMD, VkPipelineRasterizationStateRasterizationOrderAMD>));
    #endif // defined(VK_AMD_rasterization_order)

    #if defined(VK_AMD_rasterization_order)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateRasterizationOrderAMD>));
    #endif // defined(VK_AMD_rasterization_order)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationDepthClipStateCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationDepthClipStateCreateInfoEXT, VkPipelineRasterizationDepthClipStateCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationDepthClipStateCreateInfoEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationLineStateCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationLineStateCreateInfo, VkPipelineRasterizationLineStateCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationLineStateCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, pipeline_multisample_state_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageReductionStateCreateInfoNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageReductionStateCreateInfoNV, VkPipelineCoverageReductionStateCreateInfoNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageReductionStateCreateInfoNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineSampleLocationsStateCreateInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineSampleLocationsStateCreateInfoEXT, VkPipelineSampleLocationsStateCreateInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineMultisampleStateCreateInfo, VkPipelineSampleLocationsStateCreateInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_NV_framebuffer_mixed_samples)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageModulationStateCreateInfoNV>));
    #endif // defined(VK_NV_framebuffer_mixed_samples)

    #if defined(VK_NV_framebuffer_mixed_samples)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageModulationStateCreateInfoNV, VkPipelineCoverageModulationStateCreateInfoNV>));
    #endif // defined(VK_NV_framebuffer_mixed_samples)

    #if defined(VK_NV_framebuffer_mixed_samples)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageModulationStateCreateInfoNV>));
    #endif // defined(VK_NV_framebuffer_mixed_samples)

    #if defined(VK_NV_fragment_coverage_to_color)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageToColorStateCreateInfoNV>));
    #endif // defined(VK_NV_fragment_coverage_to_color)

    #if defined(VK_NV_fragment_coverage_to_color)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageToColorStateCreateInfoNV, VkPipelineCoverageToColorStateCreateInfoNV>));
    #endif // defined(VK_NV_fragment_coverage_to_color)

    #if defined(VK_NV_fragment_coverage_to_color)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineMultisampleStateCreateInfo, VkPipelineCoverageToColorStateCreateInfoNV>));
    #endif // defined(VK_NV_fragment_coverage_to_color)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, pipeline_color_blend_state_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineColorBlendStateCreateInfo, VkPipelineColorWriteCreateInfoEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineColorBlendStateCreateInfo, VkPipelineColorWriteCreateInfoEXT, VkPipelineColorWriteCreateInfoEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineColorBlendStateCreateInfo, VkPipelineColorWriteCreateInfoEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((can_extend_v<VkPipelineColorBlendStateCreateInfo, VkPipelineColorBlendAdvancedStateCreateInfoEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_FALSE((can_extend_v<VkPipelineColorBlendStateCreateInfo, VkPipelineColorBlendAdvancedStateCreateInfoEXT, VkPipelineColorBlendAdvancedStateCreateInfoEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((chain_compatible<VkPipelineColorBlendStateCreateInfo, VkPipelineColorBlendAdvancedStateCreateInfoEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, graphics_pipeline_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineCompilerControlCreateInfoAMD, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateStateCreateInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateStateCreateInfoKHR, VkPipelineFragmentShadingRateStateCreateInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateStateCreateInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineShaderGroupsCreateInfoNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineShaderGroupsCreateInfoNV, VkGraphicsPipelineShaderGroupsCreateInfoNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineShaderGroupsCreateInfoNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineRenderingCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineRenderingCreateInfo, VkPipelineRenderingCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineRenderingCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineRobustnessCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineOfflineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineCreateFlags2CreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineLibraryCreateInfoEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineLibraryCreateInfoEXT, VkGraphicsPipelineLibraryCreateInfoEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineLibraryCreateInfoEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkMultiviewPerViewAttributesInfoNVX, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkRenderingAttachmentLocationInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkRenderingAttachmentLocationInfo, VkRenderingAttachmentLocationInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkRenderingAttachmentLocationInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_discard_rectangles)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineDiscardRectangleStateCreateInfoEXT>));
    #endif // defined(VK_EXT_discard_rectangles)

    #if defined(VK_EXT_discard_rectangles)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineDiscardRectangleStateCreateInfoEXT, VkPipelineDiscardRectangleStateCreateInfoEXT>));
    #endif // defined(VK_EXT_discard_rectangles)

    #if defined(VK_EXT_discard_rectangles)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineDiscardRectangleStateCreateInfoEXT>));
    #endif // defined(VK_EXT_discard_rectangles)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkExternalFormatANDROID, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_KHR_pipeline_library)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineLibraryCreateInfoKHR>));
    #endif // defined(VK_KHR_pipeline_library)

    #if defined(VK_KHR_pipeline_library)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineLibraryCreateInfoKHR, VkPipelineLibraryCreateInfoKHR>));
    #endif // defined(VK_KHR_pipeline_library)

    #if defined(VK_KHR_pipeline_library)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineLibraryCreateInfoKHR>));
    #endif // defined(VK_KHR_pipeline_library)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineCreationFeedbackCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineBinaryInfoKHR, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_AMD_mixed_attachment_samples)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkAttachmentSampleCountInfoAMD>));
    #endif // defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_AMD_mixed_attachment_samples)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkAttachmentSampleCountInfoAMD, VkAttachmentSampleCountInfoAMD>));
    #endif // defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_AMD_mixed_attachment_samples)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkAttachmentSampleCountInfoAMD>));
    #endif // defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateEnumStateCreateInfoNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateEnumStateCreateInfoNV, VkPipelineFragmentShadingRateEnumStateCreateInfoNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateEnumStateCreateInfoNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkRenderingInputAttachmentIndexInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkRenderingInputAttachmentIndexInfo, VkRenderingInputAttachmentIndexInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkRenderingInputAttachmentIndexInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_TRUE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineRepresentativeFragmentTestStateCreateInfoNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_FALSE((can_extend_v<VkGraphicsPipelineCreateInfo, VkPipelineRepresentativeFragmentTestStateCreateInfoNV, VkPipelineRepresentativeFragmentTestStateCreateInfoNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_TRUE((chain_compatible<VkGraphicsPipelineCreateInfo, VkPipelineRepresentativeFragmentTestStateCreateInfoNV>));
    #endif // defined(VK_NV_representative_fragment_test)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, sampler_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerCreateInfo, VkSamplerBlockMatchWindowCreateInfoQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerCreateInfo, VkSamplerBlockMatchWindowCreateInfoQCOM, VkSamplerBlockMatchWindowCreateInfoQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerCreateInfo, VkSamplerBlockMatchWindowCreateInfoQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerCreateInfo, VkSamplerBorderColorComponentMappingCreateInfoEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerCreateInfo, VkSamplerBorderColorComponentMappingCreateInfoEXT, VkSamplerBorderColorComponentMappingCreateInfoEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerCreateInfo, VkSamplerBorderColorComponentMappingCreateInfoEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerCreateInfo, VkSamplerCubicWeightsCreateInfoQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerCreateInfo, VkSamplerCubicWeightsCreateInfoQCOM, VkSamplerCubicWeightsCreateInfoQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerCreateInfo, VkSamplerCubicWeightsCreateInfoQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerCreateInfo, VkSamplerReductionModeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerCreateInfo, VkSamplerReductionModeCreateInfo, VkSamplerReductionModeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerCreateInfo, VkSamplerReductionModeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerCreateInfo, VkSamplerCustomBorderColorCreateInfoEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerCreateInfo, VkSamplerCustomBorderColorCreateInfoEXT, VkSamplerCustomBorderColorCreateInfoEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerCreateInfo, VkSamplerCustomBorderColorCreateInfoEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerCreateInfo, VkSamplerYcbcrConversionInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerCreateInfo, VkSamplerYcbcrConversionInfo, VkSamplerYcbcrConversionInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerCreateInfo, VkSamplerYcbcrConversionInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, command_pool_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandPoolCreateInfo, VkCommandPoolMemoryReservationCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandPoolCreateInfo, VkCommandPoolMemoryReservationCreateInfo, VkCommandPoolMemoryReservationCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandPoolCreateInfo, VkCommandPoolMemoryReservationCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, command_buffer_inheritance_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_QCOM_render_pass_transform)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderPassTransformInfoQCOM>));
    #endif // defined(VK_QCOM_render_pass_transform)

    #if defined(VK_QCOM_render_pass_transform)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderPassTransformInfoQCOM, VkCommandBufferInheritanceRenderPassTransformInfoQCOM>));
    #endif // defined(VK_QCOM_render_pass_transform)

    #if defined(VK_QCOM_render_pass_transform)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderPassTransformInfoQCOM>));
    #endif // defined(VK_QCOM_render_pass_transform)

    #if defined(VK_AMD_mixed_attachment_samples)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkAttachmentSampleCountInfoAMD>));
    #endif // defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_AMD_mixed_attachment_samples)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkAttachmentSampleCountInfoAMD, VkAttachmentSampleCountInfoAMD>));
    #endif // defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_AMD_mixed_attachment_samples)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkAttachmentSampleCountInfoAMD>));
    #endif // defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkMultiviewPerViewAttributesInfoNVX, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkRenderingAttachmentLocationInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkRenderingAttachmentLocationInfo, VkRenderingAttachmentLocationInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkRenderingAttachmentLocationInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkExternalFormatANDROID, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkRenderingInputAttachmentIndexInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkRenderingInputAttachmentIndexInfo, VkRenderingInputAttachmentIndexInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkRenderingInputAttachmentIndexInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceViewportScissorInfoNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceViewportScissorInfoNV, VkCommandBufferInheritanceViewportScissorInfoNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceViewportScissorInfoNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderingInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderingInfo, VkCommandBufferInheritanceRenderingInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderingInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceConditionalRenderingInfoEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceConditionalRenderingInfoEXT, VkCommandBufferInheritanceConditionalRenderingInfoEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceConditionalRenderingInfoEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, command_buffer_begin_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferBeginInfo, VkDeviceGroupCommandBufferBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferBeginInfo, VkDeviceGroupCommandBufferBeginInfo, VkDeviceGroupCommandBufferBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferBeginInfo, VkDeviceGroupCommandBufferBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, render_pass_begin_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassSampleLocationsBeginInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassSampleLocationsBeginInfoEXT, VkRenderPassSampleLocationsBeginInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassBeginInfo, VkRenderPassSampleLocationsBeginInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassStripeBeginInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassStripeBeginInfoARM, VkRenderPassStripeBeginInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassBeginInfo, VkRenderPassStripeBeginInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassAttachmentBeginInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassAttachmentBeginInfo, VkRenderPassAttachmentBeginInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassBeginInfo, VkRenderPassAttachmentBeginInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_QCOM_render_pass_transform)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassTransformBeginInfoQCOM>));
    #endif // defined(VK_QCOM_render_pass_transform)

    #if defined(VK_QCOM_render_pass_transform)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassBeginInfo, VkRenderPassTransformBeginInfoQCOM, VkRenderPassTransformBeginInfoQCOM>));
    #endif // defined(VK_QCOM_render_pass_transform)

    #if defined(VK_QCOM_render_pass_transform)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassBeginInfo, VkRenderPassTransformBeginInfoQCOM>));
    #endif // defined(VK_QCOM_render_pass_transform)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassBeginInfo, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassBeginInfo, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassBeginInfo, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassBeginInfo, VkDeviceGroupRenderPassBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassBeginInfo, VkDeviceGroupRenderPassBeginInfo, VkDeviceGroupRenderPassBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassBeginInfo, VkDeviceGroupRenderPassBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, render_pass_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassCreateInfo, VkRenderPassMultiviewCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassCreateInfo, VkRenderPassMultiviewCreateInfo, VkRenderPassMultiviewCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassCreateInfo, VkRenderPassMultiviewCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassCreateInfo, VkRenderPassInputAttachmentAspectCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassCreateInfo, VkRenderPassInputAttachmentAspectCreateInfo, VkRenderPassInputAttachmentAspectCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassCreateInfo, VkRenderPassInputAttachmentAspectCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassCreateInfo, VkRenderPassFragmentDensityMapCreateInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassCreateInfo, VkRenderPassFragmentDensityMapCreateInfoEXT, VkRenderPassFragmentDensityMapCreateInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassCreateInfo, VkRenderPassFragmentDensityMapCreateInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, event_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkEventCreateInfo, VkImportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_FALSE((can_extend_v<VkEventCreateInfo, VkImportMetalSharedEventInfoEXT, VkImportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkEventCreateInfo, VkImportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkEventCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkEventCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, fence_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((can_extend_v<VkFenceCreateInfo, VkExportFenceSciSyncInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_FALSE((can_extend_v<VkFenceCreateInfo, VkExportFenceSciSyncInfoNV, VkExportFenceSciSyncInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((chain_compatible<VkFenceCreateInfo, VkExportFenceSciSyncInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkFenceCreateInfo, VkExportFenceCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkFenceCreateInfo, VkExportFenceCreateInfo, VkExportFenceCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkFenceCreateInfo, VkExportFenceCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_KHR_external_fence_win32)
        STATIC_EXPECT_TRUE((can_extend_v<VkFenceCreateInfo, VkExportFenceWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_fence_win32)

    #if defined(VK_KHR_external_fence_win32)
        STATIC_EXPECT_FALSE((can_extend_v<VkFenceCreateInfo, VkExportFenceWin32HandleInfoKHR, VkExportFenceWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_fence_win32)

    #if defined(VK_KHR_external_fence_win32)
        STATIC_EXPECT_TRUE((chain_compatible<VkFenceCreateInfo, VkExportFenceWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_fence_win32)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, semaphore_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkSemaphoreTypeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSemaphoreCreateInfo, VkSemaphoreTypeCreateInfo, VkSemaphoreTypeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkSemaphoreTypeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_low_latency)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkQueryLowLatencySupportNV>));
    #endif // defined(VK_NV_low_latency)

    #if defined(VK_NV_low_latency)
        STATIC_EXPECT_FALSE((can_extend_v<VkSemaphoreCreateInfo, VkQueryLowLatencySupportNV, VkQueryLowLatencySupportNV>));
    #endif // defined(VK_NV_low_latency)

    #if defined(VK_NV_low_latency)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkQueryLowLatencySupportNV>));
    #endif // defined(VK_NV_low_latency)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkExportSemaphoreSciSyncInfoNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_FALSE((can_extend_v<VkSemaphoreCreateInfo, VkExportSemaphoreSciSyncInfoNV, VkExportSemaphoreSciSyncInfoNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkExportSemaphoreSciSyncInfoNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_KHR_external_semaphore_win32)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkExportSemaphoreWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_semaphore_win32)

    #if defined(VK_KHR_external_semaphore_win32)
        STATIC_EXPECT_FALSE((can_extend_v<VkSemaphoreCreateInfo, VkExportSemaphoreWin32HandleInfoKHR, VkExportSemaphoreWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_semaphore_win32)

    #if defined(VK_KHR_external_semaphore_win32)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkExportSemaphoreWin32HandleInfoKHR>));
    #endif // defined(VK_KHR_external_semaphore_win32)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkImportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_FALSE((can_extend_v<VkSemaphoreCreateInfo, VkImportMetalSharedEventInfoEXT, VkImportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkImportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkExportMetalObjectCreateInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkExportSemaphoreCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSemaphoreCreateInfo, VkExportSemaphoreCreateInfo, VkExportSemaphoreCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkExportSemaphoreCreateInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSemaphoreCreateInfo, VkSemaphoreSciSyncCreateInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSemaphoreCreateInfo, VkSemaphoreSciSyncCreateInfoNV, VkSemaphoreSciSyncCreateInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSemaphoreCreateInfo, VkSemaphoreSciSyncCreateInfoNV>));
    #endif // defined(VK_NV_external_sci_sync2)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, query_pool_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeUsageInfoKHR, VkVideoDecodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoDecodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_INTEL_performance_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkQueryPoolPerformanceQueryCreateInfoINTEL>));
    #endif // defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkQueryPoolPerformanceQueryCreateInfoINTEL, VkQueryPoolPerformanceQueryCreateInfoINTEL>));
    #endif // defined(VK_INTEL_performance_query)

    #if defined(VK_INTEL_performance_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkQueryPoolPerformanceQueryCreateInfoINTEL>));
    #endif // defined(VK_INTEL_performance_query)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeH264ProfileInfoKHR, VkVideoDecodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoDecodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeH265ProfileInfoKHR, VkVideoDecodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoDecodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkQueryPoolPerformanceCreateInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkQueryPoolPerformanceCreateInfoKHR, VkQueryPoolPerformanceCreateInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkQueryPoolPerformanceCreateInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeUsageInfoKHR, VkVideoEncodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoEncodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkQueryPoolVideoEncodeFeedbackCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkQueryPoolVideoEncodeFeedbackCreateInfoKHR, VkQueryPoolVideoEncodeFeedbackCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkQueryPoolVideoEncodeFeedbackCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoProfileInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoProfileInfoKHR, VkVideoProfileInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoProfileInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeH265ProfileInfoKHR, VkVideoEncodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoEncodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoDecodeAV1ProfileInfoKHR, VkVideoDecodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoDecodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeAV1ProfileInfoKHR, VkVideoEncodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoEncodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueryPoolCreateInfo, VkVideoEncodeH264ProfileInfoKHR, VkVideoEncodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueryPoolCreateInfo, VkVideoEncodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, framebuffer_create_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkFramebufferCreateInfo, VkFramebufferAttachmentsCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkFramebufferCreateInfo, VkFramebufferAttachmentsCreateInfo, VkFramebufferAttachmentsCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkFramebufferCreateInfo, VkFramebufferAttachmentsCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, submit_info)
{
#if defined(VK_VERSION_1_0) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkDeviceGroupSubmitInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkDeviceGroupSubmitInfo, VkDeviceGroupSubmitInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkDeviceGroupSubmitInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkAmigoProfilingSubmitInfoSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkAmigoProfilingSubmitInfoSEC, VkAmigoProfilingSubmitInfoSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkAmigoProfilingSubmitInfoSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkProtectedSubmitInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkProtectedSubmitInfo, VkProtectedSubmitInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkProtectedSubmitInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkTimelineSemaphoreSubmitInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkTimelineSemaphoreSubmitInfo, VkTimelineSemaphoreSubmitInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkTimelineSemaphoreSubmitInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkLatencySubmissionPresentIdNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkLatencySubmissionPresentIdNV, VkLatencySubmissionPresentIdNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkLatencySubmissionPresentIdNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkFrameBoundaryEXT, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_KHR_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkWin32KeyedMutexAcquireReleaseInfoKHR>));
    #endif // defined(VK_KHR_win32_keyed_mutex)

    #if defined(VK_KHR_win32_keyed_mutex)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkWin32KeyedMutexAcquireReleaseInfoKHR, VkWin32KeyedMutexAcquireReleaseInfoKHR>));
    #endif // defined(VK_KHR_win32_keyed_mutex)

    #if defined(VK_KHR_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkWin32KeyedMutexAcquireReleaseInfoKHR>));
    #endif // defined(VK_KHR_win32_keyed_mutex)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkPerformanceQuerySubmitInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkPerformanceQuerySubmitInfoKHR, VkPerformanceQuerySubmitInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkPerformanceQuerySubmitInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_NV_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkWin32KeyedMutexAcquireReleaseInfoNV>));
    #endif // defined(VK_NV_win32_keyed_mutex)

    #if defined(VK_NV_win32_keyed_mutex)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkWin32KeyedMutexAcquireReleaseInfoNV, VkWin32KeyedMutexAcquireReleaseInfoNV>));
    #endif // defined(VK_NV_win32_keyed_mutex)

    #if defined(VK_NV_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkWin32KeyedMutexAcquireReleaseInfoNV>));
    #endif // defined(VK_NV_win32_keyed_mutex)

    #if defined(VK_KHR_external_semaphore_win32)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo, VkD3D12FenceSubmitInfoKHR>));
    #endif // defined(VK_KHR_external_semaphore_win32)

    #if defined(VK_KHR_external_semaphore_win32)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo, VkD3D12FenceSubmitInfoKHR, VkD3D12FenceSubmitInfoKHR>));
    #endif // defined(VK_KHR_external_semaphore_win32)

    #if defined(VK_KHR_external_semaphore_win32)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo, VkD3D12FenceSubmitInfoKHR>));
    #endif // defined(VK_KHR_external_semaphore_win32)

#endif // VK_VERSION_1_0
}

TEST(pnext_chain, display_surface_create_info_khr)
{
#if defined(VK_KHR_display) 
    
    #if defined(VK_NV_display_stereo)
        STATIC_EXPECT_TRUE((can_extend_v<VkDisplaySurfaceCreateInfoKHR, VkDisplaySurfaceStereoCreateInfoNV>));
    #endif // defined(VK_NV_display_stereo)

    #if defined(VK_NV_display_stereo)
        STATIC_EXPECT_FALSE((can_extend_v<VkDisplaySurfaceCreateInfoKHR, VkDisplaySurfaceStereoCreateInfoNV, VkDisplaySurfaceStereoCreateInfoNV>));
    #endif // defined(VK_NV_display_stereo)

    #if defined(VK_NV_display_stereo)
        STATIC_EXPECT_TRUE((chain_compatible<VkDisplaySurfaceCreateInfoKHR, VkDisplaySurfaceStereoCreateInfoNV>));
    #endif // defined(VK_NV_display_stereo)

#endif // VK_KHR_display
}

TEST(pnext_chain, swapchain_create_info_khr)
{
#if defined(VK_KHR_swapchain) 
    
    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainLatencyCreateInfoNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainLatencyCreateInfoNV, VkSwapchainLatencyCreateInfoNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSwapchainLatencyCreateInfoNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkImageFormatListCreateInfo, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_AMD_display_native_hdr)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainDisplayNativeHdrCreateInfoAMD>));
    #endif // defined(VK_AMD_display_native_hdr)

    #if defined(VK_AMD_display_native_hdr)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainDisplayNativeHdrCreateInfoAMD, VkSwapchainDisplayNativeHdrCreateInfoAMD>));
    #endif // defined(VK_AMD_display_native_hdr)

    #if defined(VK_AMD_display_native_hdr)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSwapchainDisplayNativeHdrCreateInfoAMD>));
    #endif // defined(VK_AMD_display_native_hdr)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkImageCompressionControlEXT, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainPresentModesCreateInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainPresentModesCreateInfoEXT, VkSwapchainPresentModesCreateInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSwapchainPresentModesCreateInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveInfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveInfoEXT, VkSurfaceFullScreenExclusiveInfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveInfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainPresentScalingCreateInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainPresentScalingCreateInfoEXT, VkSwapchainPresentScalingCreateInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSwapchainPresentScalingCreateInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkDeviceGroupSwapchainCreateInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkDeviceGroupSwapchainCreateInfoKHR, VkDeviceGroupSwapchainCreateInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkDeviceGroupSwapchainCreateInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainPresentBarrierCreateInfoNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainPresentBarrierCreateInfoNV, VkSwapchainPresentBarrierCreateInfoNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSwapchainPresentBarrierCreateInfoNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveWin32InfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveWin32InfoEXT, VkSurfaceFullScreenExclusiveWin32InfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveWin32InfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_display_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainCounterCreateInfoEXT>));
    #endif // defined(VK_EXT_display_control)

    #if defined(VK_EXT_display_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkSwapchainCreateInfoKHR, VkSwapchainCounterCreateInfoEXT, VkSwapchainCounterCreateInfoEXT>));
    #endif // defined(VK_EXT_display_control)

    #if defined(VK_EXT_display_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkSwapchainCreateInfoKHR, VkSwapchainCounterCreateInfoEXT>));
    #endif // defined(VK_EXT_display_control)

#endif // VK_KHR_swapchain
}

TEST(pnext_chain, present_info_khr)
{
#if defined(VK_KHR_swapchain) 
    
    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkSwapchainPresentModeInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkSwapchainPresentModeInfoEXT, VkSwapchainPresentModeInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkSwapchainPresentModeInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_GGP_frame_token)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkPresentFrameTokenGGP>));
    #endif // defined(VK_GGP_frame_token)

    #if defined(VK_GGP_frame_token)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkPresentFrameTokenGGP, VkPresentFrameTokenGGP>));
    #endif // defined(VK_GGP_frame_token)

    #if defined(VK_GGP_frame_token)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkPresentFrameTokenGGP>));
    #endif // defined(VK_GGP_frame_token)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkSetPresentConfigNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkSetPresentConfigNV, VkSetPresentConfigNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkSetPresentConfigNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkSwapchainPresentFenceInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkSwapchainPresentFenceInfoEXT, VkSwapchainPresentFenceInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkSwapchainPresentFenceInfoEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkFrameBoundaryEXT, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_GOOGLE_display_timing)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkPresentTimesInfoGOOGLE>));
    #endif // defined(VK_GOOGLE_display_timing)

    #if defined(VK_GOOGLE_display_timing)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkPresentTimesInfoGOOGLE, VkPresentTimesInfoGOOGLE>));
    #endif // defined(VK_GOOGLE_display_timing)

    #if defined(VK_GOOGLE_display_timing)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkPresentTimesInfoGOOGLE>));
    #endif // defined(VK_GOOGLE_display_timing)

    #if defined(VK_KHR_incremental_present)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkPresentRegionsKHR>));
    #endif // defined(VK_KHR_incremental_present)

    #if defined(VK_KHR_incremental_present)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkPresentRegionsKHR, VkPresentRegionsKHR>));
    #endif // defined(VK_KHR_incremental_present)

    #if defined(VK_KHR_incremental_present)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkPresentRegionsKHR>));
    #endif // defined(VK_KHR_incremental_present)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkDeviceGroupPresentInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkDeviceGroupPresentInfoKHR, VkDeviceGroupPresentInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkDeviceGroupPresentInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkPresentIdKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkPresentIdKHR, VkPresentIdKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkPresentIdKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_KHR_display_swapchain)
        STATIC_EXPECT_TRUE((can_extend_v<VkPresentInfoKHR, VkDisplayPresentInfoKHR>));
    #endif // defined(VK_KHR_display_swapchain)

    #if defined(VK_KHR_display_swapchain)
        STATIC_EXPECT_FALSE((can_extend_v<VkPresentInfoKHR, VkDisplayPresentInfoKHR, VkDisplayPresentInfoKHR>));
    #endif // defined(VK_KHR_display_swapchain)

    #if defined(VK_KHR_display_swapchain)
        STATIC_EXPECT_TRUE((chain_compatible<VkPresentInfoKHR, VkDisplayPresentInfoKHR>));
    #endif // defined(VK_KHR_display_swapchain)

#endif // VK_KHR_swapchain
}

TEST(pnext_chain, physical_device_features2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineProtectedAccessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineProtectedAccessFeatures, VkPhysicalDevicePipelineProtectedAccessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineProtectedAccessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProvokingVertexFeaturesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProvokingVertexFeaturesEXT, VkPhysicalDeviceProvokingVertexFeaturesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProvokingVertexFeaturesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipEnableFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipEnableFeaturesEXT, VkPhysicalDeviceDepthClipEnableFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_depth_clip_enable)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipEnableFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_shader_replicated_composites)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>));
    #endif // defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_EXT_shader_replicated_composites)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>));
    #endif // defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_EXT_shader_replicated_composites)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>));
    #endif // defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan13Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan13Features, VkPhysicalDeviceVulkan13Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan13Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>));
    #endif // defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>));
    #endif // defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>));
    #endif // defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeatures, VkPhysicalDeviceBufferDeviceAddressFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageAlignmentControlFeaturesMESA, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_KHR_depth_clamp_zero_one)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>));
    #endif // defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_KHR_depth_clamp_zero_one)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>));
    #endif // defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_KHR_depth_clamp_zero_one)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>));
    #endif // defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_KHR_shader_clock)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderClockFeaturesKHR>));
    #endif // defined(VK_KHR_shader_clock)

    #if defined(VK_KHR_shader_clock)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderClockFeaturesKHR, VkPhysicalDeviceShaderClockFeaturesKHR>));
    #endif // defined(VK_KHR_shader_clock)

    #if defined(VK_KHR_shader_clock)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderClockFeaturesKHR>));
    #endif // defined(VK_KHR_shader_clock)

    #if defined(VK_KHR_ray_tracing_position_fetch)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_KHR_ray_tracing_position_fetch)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_KHR_ray_tracing_position_fetch)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceIndexTypeUint8Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceIndexTypeUint8Features, VkPhysicalDeviceIndexTypeUint8Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceIndexTypeUint8Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_EXT_device_memory_report)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_memory_report)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampControlFeaturesEXT, VkPhysicalDeviceDepthClampControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_EXT_depth_clamp_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clamp_control)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan12Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan12Features, VkPhysicalDeviceVulkan12Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan12Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloat16Int8Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloat16Int8Features, VkPhysicalDeviceShaderFloat16Int8Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloat16Int8Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_KHR_ray_tracing_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_KHR_ray_tracing_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_KHR_ray_tracing_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTextureCompressionASTCHDRFeatures, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_QCOM_tile_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTilePropertiesFeaturesQCOM>));
    #endif // defined(VK_QCOM_tile_properties)

    #if defined(VK_QCOM_tile_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTilePropertiesFeaturesQCOM, VkPhysicalDeviceTilePropertiesFeaturesQCOM>));
    #endif // defined(VK_QCOM_tile_properties)

    #if defined(VK_QCOM_tile_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTilePropertiesFeaturesQCOM>));
    #endif // defined(VK_QCOM_tile_properties)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemorySciBufFeaturesNV, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_NV_external_memory_sci_buf)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>));
    #endif // defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipControlFeaturesEXT, VkPhysicalDeviceDepthClipControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_depth_clip_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_EXT_border_color_swizzle)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>));
    #endif // defined(VK_EXT_border_color_swizzle)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan11Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan11Features, VkPhysicalDeviceVulkan11Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan11Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAmigoProfilingFeaturesSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAmigoProfilingFeaturesSEC, VkPhysicalDeviceAmigoProfilingFeaturesSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_SEC_amigo_profiling)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAmigoProfilingFeaturesSEC>));
    #endif // defined(VK_SEC_amigo_profiling)

    #if defined(VK_KHR_ray_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayQueryFeaturesKHR>));
    #endif // defined(VK_KHR_ray_query)

    #if defined(VK_KHR_ray_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayQueryFeaturesKHR, VkPhysicalDeviceRayQueryFeaturesKHR>));
    #endif // defined(VK_KHR_ray_query)

    #if defined(VK_KHR_ray_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayQueryFeaturesKHR>));
    #endif // defined(VK_KHR_ray_query)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerDotProductFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerDotProductFeatures, VkPhysicalDeviceShaderIntegerDotProductFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerDotProductFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_image_2d_view_of_3d)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_EXT_image_2d_view_of_3d)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_EXT_image_2d_view_of_3d)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSamplerYcbcrConversionFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSamplerYcbcrConversionFeatures, VkPhysicalDeviceSamplerYcbcrConversionFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSamplerYcbcrConversionFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_fragment_shader_interlock)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_EXT_fragment_shader_interlock)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_EXT_fragment_shader_interlock)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_EXT_non_seamless_cube_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>));
    #endif // defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_EXT_non_seamless_cube_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>));
    #endif // defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_EXT_non_seamless_cube_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>));
    #endif // defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_HUAWEI_invocation_mask)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_HUAWEI_invocation_mask)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_HUAWEI_invocation_mask)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_NV_raw_access_chains)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRawAccessChainsFeaturesNV>));
    #endif // defined(VK_NV_raw_access_chains)

    #if defined(VK_NV_raw_access_chains)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRawAccessChainsFeaturesNV, VkPhysicalDeviceRawAccessChainsFeaturesNV>));
    #endif // defined(VK_NV_raw_access_chains)

    #if defined(VK_NV_raw_access_chains)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRawAccessChainsFeaturesNV>));
    #endif // defined(VK_NV_raw_access_chains)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeVectorFeaturesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeVectorFeaturesNV, VkPhysicalDeviceCooperativeVectorFeaturesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeVectorFeaturesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGlobalPriorityQueryFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGlobalPriorityQueryFeatures, VkPhysicalDeviceGlobalPriorityQueryFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGlobalPriorityQueryFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_INTEL_shader_integer_functions2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>));
    #endif // defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_INTEL_shader_integer_functions2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>));
    #endif // defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_INTEL_shader_integer_functions2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>));
    #endif // defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance2FeaturesKHR, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_NV_corner_sampled_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCornerSampledImageFeaturesNV>));
    #endif // defined(VK_NV_corner_sampled_image)

    #if defined(VK_NV_corner_sampled_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCornerSampledImageFeaturesNV, VkPhysicalDeviceCornerSampledImageFeaturesNV>));
    #endif // defined(VK_NV_corner_sampled_image)

    #if defined(VK_NV_corner_sampled_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCornerSampledImageFeaturesNV>));
    #endif // defined(VK_NV_corner_sampled_image)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAccelerationStructureFeaturesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAccelerationStructureFeaturesKHR, VkPhysicalDeviceAccelerationStructureFeaturesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAccelerationStructureFeaturesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthBiasControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthBiasControlFeaturesEXT, VkPhysicalDeviceDepthBiasControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthBiasControlFeaturesEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanMemoryModelFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanMemoryModelFeatures, VkPhysicalDeviceVulkanMemoryModelFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanMemoryModelFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_shader_atomic_float2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_EXT_shader_atomic_float2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_EXT_shader_atomic_float2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSchedulingControlsFeaturesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSchedulingControlsFeaturesARM, VkPhysicalDeviceSchedulingControlsFeaturesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSchedulingControlsFeaturesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>));
    #endif // defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>));
    #endif // defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>));
    #endif // defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_KHR_pipeline_executable_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_pipeline_executable_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_pipeline_executable_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_KHR_present_wait)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentWaitFeaturesKHR>));
    #endif // defined(VK_KHR_present_wait)

    #if defined(VK_KHR_present_wait)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentWaitFeaturesKHR, VkPhysicalDevicePresentWaitFeaturesKHR>));
    #endif // defined(VK_KHR_present_wait)

    #if defined(VK_KHR_present_wait)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentWaitFeaturesKHR>));
    #endif // defined(VK_KHR_present_wait)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderObjectFeaturesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderObjectFeaturesEXT, VkPhysicalDeviceShaderObjectFeaturesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderObjectFeaturesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance4Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance4Features, VkPhysicalDeviceMaintenance4Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance4Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessingFeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessingFeaturesQCOM, VkPhysicalDeviceImageProcessingFeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessingFeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerformanceQueryFeaturesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerformanceQueryFeaturesKHR, VkPhysicalDevicePerformanceQueryFeaturesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerformanceQueryFeaturesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePortabilitySubsetFeaturesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePortabilitySubsetFeaturesKHR, VkPhysicalDevicePortabilitySubsetFeaturesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePortabilitySubsetFeaturesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_EXT_pageable_device_local_memory)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>));
    #endif // defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_EXT_pageable_device_local_memory)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>));
    #endif // defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_EXT_pageable_device_local_memory)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>));
    #endif // defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceUniformBufferStandardLayoutFeatures, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSynchronization2Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSynchronization2Features, VkPhysicalDeviceSynchronization2Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSynchronization2Features>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorIndexingFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorIndexingFeatures, VkPhysicalDeviceDescriptorIndexingFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorIndexingFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineRobustnessFeatures, VkPhysicalDevicePipelineRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_AMD_anti_lag)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAntiLagFeaturesAMD>));
    #endif // defined(VK_AMD_anti_lag)

    #if defined(VK_AMD_anti_lag)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAntiLagFeaturesAMD, VkPhysicalDeviceAntiLagFeaturesAMD>));
    #endif // defined(VK_AMD_anti_lag)

    #if defined(VK_AMD_anti_lag)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAntiLagFeaturesAMD>));
    #endif // defined(VK_AMD_anti_lag)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeDivisorFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeDivisorFeatures, VkPhysicalDeviceVertexAttributeDivisorFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeDivisorFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpticalFlowFeaturesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpticalFlowFeaturesNV, VkPhysicalDeviceOpticalFlowFeaturesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpticalFlowFeaturesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingLocalReadFeatures, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance5Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance5Features, VkPhysicalDeviceMaintenance5Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance5Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_NV_ray_tracing_validation)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingValidationFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_validation)

    #if defined(VK_NV_ray_tracing_validation)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingValidationFeaturesNV, VkPhysicalDeviceRayTracingValidationFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_validation)

    #if defined(VK_NV_ray_tracing_validation)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingValidationFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_validation)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_NV_per_stage_descriptor_set)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>));
    #endif // defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_NV_per_stage_descriptor_set)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerStageDescriptorSetFeaturesNV, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>));
    #endif // defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_NV_per_stage_descriptor_set)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>));
    #endif // defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_EXT_mutable_descriptor_type)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>));
    #endif // defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLineRasterizationFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLineRasterizationFeatures, VkPhysicalDeviceLineRasterizationFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLineRasterizationFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_device_fault)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFaultFeaturesEXT>));
    #endif // defined(VK_EXT_device_fault)

    #if defined(VK_EXT_device_fault)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFaultFeaturesEXT, VkPhysicalDeviceFaultFeaturesEXT>));
    #endif // defined(VK_EXT_device_fault)

    #if defined(VK_EXT_device_fault)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFaultFeaturesEXT>));
    #endif // defined(VK_EXT_device_fault)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryDecompressionFeaturesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryDecompressionFeaturesNV, VkPhysicalDeviceMemoryDecompressionFeaturesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryDecompressionFeaturesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRobustness2FeaturesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRobustness2FeaturesEXT, VkPhysicalDeviceRobustness2FeaturesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRobustness2FeaturesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>));
    #endif // defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>));
    #endif // defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>));
    #endif // defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>));
    #endif // defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEnqueueFeaturesAMDX, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_EXT_extended_dynamic_state)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_extended_dynamic_state)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_extended_dynamic_state)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineCreationCacheControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineCreationCacheControlFeatures, VkPhysicalDevicePipelineCreationCacheControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineCreationCacheControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderExpectAssumeFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderExpectAssumeFeatures, VkPhysicalDeviceShaderExpectAssumeFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderExpectAssumeFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance8FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance8FeaturesKHR, VkPhysicalDeviceMaintenance8FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance8FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>));
    #endif // defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>));
    #endif // defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>));
    #endif // defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_EXT_vertex_input_dynamic_state)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_EXT_vertex_input_dynamic_state)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_EXT_vertex_input_dynamic_state)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPipelineFeaturesKHR, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_pipeline_library_group_handles)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_EXT_pipeline_library_group_handles)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_EXT_pipeline_library_group_handles)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>));
    #endif // defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>));
    #endif // defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>));
    #endif // defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_buffer_device_address)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>));
    #endif // defined(VK_EXT_buffer_device_address)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupRotateFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupRotateFeatures, VkPhysicalDeviceShaderSubgroupRotateFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupRotateFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_legacy_dithering)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyDitheringFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_dithering)

    #if defined(VK_EXT_legacy_dithering)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyDitheringFeaturesEXT, VkPhysicalDeviceLegacyDitheringFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_dithering)

    #if defined(VK_EXT_legacy_dithering)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyDitheringFeaturesEXT>));
    #endif // defined(VK_EXT_legacy_dithering)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrivateDataFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrivateDataFeatures, VkPhysicalDevicePrivateDataFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrivateDataFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTerminateInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTerminateInvocationFeatures, VkPhysicalDeviceShaderTerminateInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTerminateInvocationFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAddressBindingReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAddressBindingReportFeaturesEXT, VkPhysicalDeviceAddressBindingReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAddressBindingReportFeaturesEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_QCOM_multiview_per_view_viewports)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_QCOM_multiview_per_view_viewports)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_QCOM_multiview_per_view_viewports)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageRobustnessFeatures, VkPhysicalDeviceImageRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageRobustnessFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevice8BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevice8BitStorageFeatures, VkPhysicalDevice8BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevice8BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesKHR, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShadingRateImageFeaturesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShadingRateImageFeaturesNV, VkPhysicalDeviceShadingRateImageFeaturesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShadingRateImageFeaturesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_KHR_shader_maximal_reconvergence)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>));
    #endif // defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_KHR_shader_maximal_reconvergence)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>));
    #endif // defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_KHR_shader_maximal_reconvergence)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>));
    #endif // defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapFeaturesEXT, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance1FeaturesKHR, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentMeteringFeaturesNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentMeteringFeaturesNV, VkPhysicalDevicePresentMeteringFeaturesNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_NV_present_metering)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentMeteringFeaturesNV>));
    #endif // defined(VK_NV_present_metering)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicWeightsFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicWeightsFeaturesQCOM, VkPhysicalDeviceCubicWeightsFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicWeightsFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImagelessFramebufferFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImagelessFramebufferFeatures, VkPhysicalDeviceImagelessFramebufferFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImagelessFramebufferFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_linear_color_attachment)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>));
    #endif // defined(VK_NV_linear_color_attachment)

    #if defined(VK_NV_linear_color_attachment)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLinearColorAttachmentFeaturesNV, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>));
    #endif // defined(VK_NV_linear_color_attachment)

    #if defined(VK_NV_linear_color_attachment)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>));
    #endif // defined(VK_NV_linear_color_attachment)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNestedCommandBufferFeaturesEXT, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>));
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>));
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>));
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_EXT_pipeline_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelinePropertiesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_properties)

    #if defined(VK_EXT_pipeline_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelinePropertiesFeaturesEXT, VkPhysicalDevicePipelinePropertiesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_properties)

    #if defined(VK_EXT_pipeline_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelinePropertiesFeaturesEXT>));
    #endif // defined(VK_EXT_pipeline_properties)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>));
    #endif // defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>));
    #endif // defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>));
    #endif // defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlFeaturesEXT, VkPhysicalDeviceImageCompressionControlFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRenderPassStripedFeaturesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRenderPassStripedFeaturesARM, VkPhysicalDeviceRenderPassStripedFeaturesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRenderPassStripedFeaturesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessing2FeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessing2FeaturesQCOM, VkPhysicalDeviceImageProcessing2FeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessing2FeaturesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_EXT_primitive_topology_list_restart)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>));
    #endif // defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_EXT_primitive_topology_list_restart)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>));
    #endif // defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_EXT_primitive_topology_list_restart)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>));
    #endif // defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_NV_descriptor_pool_overallocation)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>));
    #endif // defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_NV_descriptor_pool_overallocation)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>));
    #endif // defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_NV_descriptor_pool_overallocation)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>));
    #endif // defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVariablePointersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVariablePointersFeatures, VkPhysicalDeviceVariablePointersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVariablePointersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentIdFeaturesKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentIdFeaturesKHR, VkPhysicalDevicePresentIdFeaturesKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_KHR_present_id)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentIdFeaturesKHR>));
    #endif // defined(VK_KHR_present_id)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateFeaturesKHR, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance7FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance7FeaturesKHR, VkPhysicalDeviceMaintenance7FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance7FeaturesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryPriorityFeaturesEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryPriorityFeaturesEXT, VkPhysicalDeviceMemoryPriorityFeaturesEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_memory_priority)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryPriorityFeaturesEXT>));
    #endif // defined(VK_EXT_memory_priority)

    #if defined(VK_EXT_extended_dynamic_state2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_extended_dynamic_state2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_extended_dynamic_state2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_primitives_generated_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>));
    #endif // defined(VK_EXT_primitives_generated_query)

    #if defined(VK_EXT_primitives_generated_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>));
    #endif // defined(VK_EXT_primitives_generated_query)

    #if defined(VK_EXT_primitives_generated_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>));
    #endif // defined(VK_EXT_primitives_generated_query)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpacityMicromapFeaturesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpacityMicromapFeaturesEXT, VkPhysicalDeviceOpacityMicromapFeaturesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpacityMicromapFeaturesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHdrVividFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHdrVividFeaturesHUAWEI, VkPhysicalDeviceHdrVividFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHdrVividFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_NV_external_memory_rdma)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>));
    #endif // defined(VK_NV_external_memory_rdma)

    #if defined(VK_NV_external_memory_rdma)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>));
    #endif // defined(VK_NV_external_memory_rdma)

    #if defined(VK_NV_external_memory_rdma)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>));
    #endif // defined(VK_NV_external_memory_rdma)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewFeatures, VkPhysicalDeviceMultiviewFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTimelineSemaphoreFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTimelineSemaphoreFeatures, VkPhysicalDeviceTimelineSemaphoreFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTimelineSemaphoreFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCudaKernelLaunchFeaturesNV, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_representative_fragment_test)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>));
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceScalarBlockLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceScalarBlockLayoutFeatures, VkPhysicalDeviceScalarBlockLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceScalarBlockLayoutFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_ARM_pipeline_opacity_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>));
    #endif // defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_ARM_pipeline_opacity_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>));
    #endif // defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_ARM_pipeline_opacity_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>));
    #endif // defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_NV_device_generated_commands_compute)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevice16BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevice16BitStorageFeatures, VkPhysicalDevice16BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevice16BitStorageFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSync2FeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSync2FeaturesNV, VkPhysicalDeviceExternalSciSync2FeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_NV_external_sci_sync2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSync2FeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync2)

    #if defined(VK_EXT_rgba10x6_formats)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_EXT_rgba10x6_formats)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_EXT_rgba10x6_formats)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiDrawFeaturesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiDrawFeaturesEXT, VkPhysicalDeviceMultiDrawFeaturesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiDrawFeaturesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_shader_atomic_float)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float)

    #if defined(VK_EXT_shader_atomic_float)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float)

    #if defined(VK_EXT_shader_atomic_float)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>));
    #endif // defined(VK_EXT_shader_atomic_float)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTransformFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTransformFeedbackFeaturesEXT, VkPhysicalDeviceTransformFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTransformFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceColorWriteEnableFeaturesEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceColorWriteEnableFeaturesEXT, VkPhysicalDeviceColorWriteEnableFeaturesEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_color_write_enable)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceColorWriteEnableFeaturesEXT>));
    #endif // defined(VK_EXT_color_write_enable)

    #if defined(VK_EXT_image_compression_control_swapchain)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_EXT_image_compression_control_swapchain)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_EXT_image_compression_control_swapchain)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>));
    #endif // defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_IMG_relaxed_line_rasterization)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>));
    #endif // defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_IMG_relaxed_line_rasterization)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>));
    #endif // defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_IMG_relaxed_line_rasterization)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>));
    #endif // defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicInt64Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicInt64Features, VkPhysicalDeviceShaderAtomicInt64Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicInt64Features>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExclusiveScissorFeaturesNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExclusiveScissorFeaturesNV, VkPhysicalDeviceExclusiveScissorFeaturesNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_scissor_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExclusiveScissorFeaturesNV>));
    #endif // defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_shader_atomic_float16_vector)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>));
    #endif // defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_NV_shader_atomic_float16_vector)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>));
    #endif // defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_NV_shader_atomic_float16_vector)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>));
    #endif // defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesEXT, VkPhysicalDeviceMeshShaderFeaturesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_rasterization_order_attachment_access)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>));
    #endif // defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_EXT_rasterization_order_attachment_access)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>));
    #endif // defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_EXT_rasterization_order_attachment_access)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>));
    #endif // defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_QCOM_filter_cubic_clamp)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicClampFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VK_QCOM_filter_cubic_clamp)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicClampFeaturesQCOM, VkPhysicalDeviceCubicClampFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VK_QCOM_filter_cubic_clamp)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicClampFeaturesQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanSC10Features>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanSC10Features, VkPhysicalDeviceVulkanSC10Features>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanSC10Features>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_AMD_device_coherent_memory)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoherentMemoryFeaturesAMD>));
    #endif // defined(VK_AMD_device_coherent_memory)

    #if defined(VK_AMD_device_coherent_memory)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoherentMemoryFeaturesAMD, VkPhysicalDeviceCoherentMemoryFeaturesAMD>));
    #endif // defined(VK_AMD_device_coherent_memory)

    #if defined(VK_AMD_device_coherent_memory)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoherentMemoryFeaturesAMD>));
    #endif // defined(VK_AMD_device_coherent_memory)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloatControls2Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloatControls2Features, VkPhysicalDeviceShaderFloatControls2Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloatControls2Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostImageCopyFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostImageCopyFeatures, VkPhysicalDeviceHostImageCopyFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostImageCopyFeatures>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesNV, VkPhysicalDeviceCooperativeMatrixFeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_EXT_shader_image_atomic_int64)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>));
    #endif // defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_EXT_shader_image_atomic_int64)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>));
    #endif // defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_EXT_shader_image_atomic_int64)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>));
    #endif // defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorBufferFeaturesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorBufferFeaturesEXT, VkPhysicalDeviceDescriptorBufferFeaturesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorBufferFeaturesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceConditionalRenderingFeaturesEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceConditionalRenderingFeaturesEXT, VkPhysicalDeviceConditionalRenderingFeaturesEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_conditional_rendering)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceConditionalRenderingFeaturesEXT>));
    #endif // defined(VK_EXT_conditional_rendering)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingFeatures, VkPhysicalDeviceDynamicRenderingFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_ycbcr_image_arrays)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_EXT_ycbcr_image_arrays)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_EXT_ycbcr_image_arrays)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInlineUniformBlockFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInlineUniformBlockFeatures, VkPhysicalDeviceInlineUniformBlockFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInlineUniformBlockFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubgroupSizeControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubgroupSizeControlFeatures, VkPhysicalDeviceSubgroupSizeControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubgroupSizeControlFeatures>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFrameBoundaryFeaturesEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFrameBoundaryFeaturesEXT, VkPhysicalDeviceFrameBoundaryFeaturesEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFrameBoundaryFeaturesEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDiagnosticsConfigFeaturesNV, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_NV_device_diagnostics_config)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>));
    #endif // defined(VK_NV_device_diagnostics_config)

    #if defined(VK_EXT_texel_buffer_alignment)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>));
    #endif // defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_EXT_texel_buffer_alignment)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>));
    #endif // defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_EXT_texel_buffer_alignment)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>));
    #endif // defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_NV_command_buffer_inheritance)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>));
    #endif // defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_NV_command_buffer_inheritance)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>));
    #endif // defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_NV_command_buffer_inheritance)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>));
    #endif // defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesNV, VkPhysicalDeviceMeshShaderFeaturesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentBarrierFeaturesNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentBarrierFeaturesNV, VkPhysicalDevicePresentBarrierFeaturesNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentBarrierFeaturesNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSyncFeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSyncFeaturesNV, VkPhysicalDeviceExternalSciSyncFeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_NV_external_sci_sync)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSyncFeaturesNV>));
    #endif // defined(VK_NV_external_sci_sync)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProtectedMemoryFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProtectedMemoryFeatures, VkPhysicalDeviceProtectedMemoryFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProtectedMemoryFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageViewMinLodFeaturesEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageViewMinLodFeaturesEXT, VkPhysicalDeviceImageViewMinLodFeaturesEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_EXT_image_view_min_lod)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageViewMinLodFeaturesEXT>));
    #endif // defined(VK_EXT_image_view_min_lod)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostQueryResetFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostQueryResetFeatures, VkPhysicalDeviceHostQueryResetFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostQueryResetFeatures>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance6Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance6Features, VkPhysicalDeviceMaintenance6Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance6Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCustomBorderColorFeaturesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCustomBorderColorFeaturesEXT, VkPhysicalDeviceCustomBorderColorFeaturesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCustomBorderColorFeaturesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoverageReductionModeFeaturesNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoverageReductionModeFeaturesNV, VkPhysicalDeviceCoverageReductionModeFeaturesNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_NV_coverage_reduction_mode)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoverageReductionModeFeaturesNV>));
    #endif // defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineBinaryFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineBinaryFeaturesKHR, VkPhysicalDevicePipelineBinaryFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineBinaryFeaturesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_image_sliced_view_of_3d)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>));
    #endif // defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceASTCDecodeFeaturesEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceASTCDecodeFeaturesEXT, VkPhysicalDeviceASTCDecodeFeaturesEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_astc_decode_mode)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceASTCDecodeFeaturesEXT>));
    #endif // defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_swapchain_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>));
    #endif // defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDisplacementMicromapFeaturesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDisplacementMicromapFeaturesNV, VkPhysicalDeviceDisplacementMicromapFeaturesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDisplacementMicromapFeaturesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_shader_image_footprint)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageFootprintFeaturesNV>));
    #endif // defined(VK_NV_shader_image_footprint)

    #if defined(VK_NV_shader_image_footprint)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageFootprintFeaturesNV, VkPhysicalDeviceShaderImageFootprintFeaturesNV>));
    #endif // defined(VK_NV_shader_image_footprint)

    #if defined(VK_NV_shader_image_footprint)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageFootprintFeaturesNV>));
    #endif // defined(VK_NV_shader_image_footprint)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTileImageFeaturesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTileImageFeaturesEXT, VkPhysicalDeviceShaderTileImageFeaturesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTileImageFeaturesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDrawParametersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDrawParametersFeatures, VkPhysicalDeviceShaderDrawParametersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDrawParametersFeatures>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_KHR_shader_quad_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderQuadControlFeaturesKHR>));
    #endif // defined(VK_KHR_shader_quad_control)

    #if defined(VK_KHR_shader_quad_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderQuadControlFeaturesKHR, VkPhysicalDeviceShaderQuadControlFeaturesKHR>));
    #endif // defined(VK_KHR_shader_quad_control)

    #if defined(VK_KHR_shader_quad_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderQuadControlFeaturesKHR>));
    #endif // defined(VK_KHR_shader_quad_control)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInheritedViewportScissorFeaturesNV, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_NV_inherited_viewport_scissor)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>));
    #endif // defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_EXT_vertex_attribute_robustness)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_EXT_vertex_attribute_robustness)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_EXT_vertex_attribute_robustness)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>));
    #endif // defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>));
    #endif // defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>));
    #endif // defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrix2FeaturesNV, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan14Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan14Features, VkPhysicalDeviceVulkan14Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan14Features>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_4444_formats)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevice4444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_4444_formats)

    #if defined(VK_EXT_4444_formats)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceFeatures2, VkPhysicalDevice4444FormatsFeaturesEXT, VkPhysicalDevice4444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_4444_formats)

    #if defined(VK_EXT_4444_formats)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceFeatures2, VkPhysicalDevice4444FormatsFeaturesEXT>));
    #endif // defined(VK_EXT_4444_formats)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, physical_device_properties2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX, VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesNV, VkPhysicalDeviceCooperativeMatrixPropertiesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_NV_cooperative_matrix)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesNV>));
    #endif // defined(VK_NV_cooperative_matrix)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCopyMemoryIndirectPropertiesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCopyMemoryIndirectPropertiesNV, VkPhysicalDeviceCopyMemoryIndirectPropertiesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VK_NV_copy_memory_indirect)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceCopyMemoryIndirectPropertiesNV>));
    #endif // defined(VK_NV_copy_memory_indirect)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkanSC10Properties>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkanSC10Properties, VkPhysicalDeviceVulkanSC10Properties>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkanSC10Properties>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_NV_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>));
    #endif // defined(VK_NV_device_generated_commands)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePushDescriptorProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePushDescriptorProperties, VkPhysicalDevicePushDescriptorProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePushDescriptorProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan14Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan14Properties, VkPhysicalDeviceVulkan14Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan14Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSampleLocationsPropertiesEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSampleLocationsPropertiesEXT, VkPhysicalDeviceSampleLocationsPropertiesEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceSampleLocationsPropertiesEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_ARM_shader_core_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesARM>));
    #endif // defined(VK_ARM_shader_core_properties)

    #if defined(VK_ARM_shader_core_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesARM, VkPhysicalDeviceShaderCorePropertiesARM>));
    #endif // defined(VK_ARM_shader_core_properties)

    #if defined(VK_ARM_shader_core_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesARM>));
    #endif // defined(VK_ARM_shader_core_properties)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiDrawPropertiesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiDrawPropertiesEXT, VkPhysicalDeviceMultiDrawPropertiesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_multi_draw)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiDrawPropertiesEXT>));
    #endif // defined(VK_EXT_multi_draw)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDepthStencilResolveProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDepthStencilResolveProperties, VkPhysicalDeviceDepthStencilResolveProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDepthStencilResolveProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPipelinePropertiesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPipelinePropertiesKHR, VkPhysicalDeviceRayTracingPipelinePropertiesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_KHR_ray_tracing_pipeline)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPipelinePropertiesKHR>));
    #endif // defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceTimelineSemaphoreProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceTimelineSemaphoreProperties, VkPhysicalDeviceTimelineSemaphoreProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceTimelineSemaphoreProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_external_memory_host)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalMemoryHostPropertiesEXT>));
    #endif // defined(VK_EXT_external_memory_host)

    #if defined(VK_EXT_external_memory_host)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalMemoryHostPropertiesEXT, VkPhysicalDeviceExternalMemoryHostPropertiesEXT>));
    #endif // defined(VK_EXT_external_memory_host)

    #if defined(VK_EXT_external_memory_host)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalMemoryHostPropertiesEXT>));
    #endif // defined(VK_EXT_external_memory_host)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDriverProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDriverProperties, VkPhysicalDeviceDriverProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDriverProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSamplerFilterMinmaxProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSamplerFilterMinmaxProperties, VkPhysicalDeviceSamplerFilterMinmaxProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceSamplerFilterMinmaxProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_discard_rectangles)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDiscardRectanglePropertiesEXT>));
    #endif // defined(VK_EXT_discard_rectangles)

    #if defined(VK_EXT_discard_rectangles)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDiscardRectanglePropertiesEXT, VkPhysicalDeviceDiscardRectanglePropertiesEXT>));
    #endif // defined(VK_EXT_discard_rectangles)

    #if defined(VK_EXT_discard_rectangles)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDiscardRectanglePropertiesEXT>));
    #endif // defined(VK_EXT_discard_rectangles)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceAccelerationStructurePropertiesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceAccelerationStructurePropertiesKHR, VkPhysicalDeviceAccelerationStructurePropertiesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_KHR_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceAccelerationStructurePropertiesKHR>));
    #endif // defined(VK_KHR_acceleration_structure)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceInlineUniformBlockProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceInlineUniformBlockProperties, VkPhysicalDeviceInlineUniformBlockProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceInlineUniformBlockProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorProperties, VkPhysicalDeviceVertexAttributeDivisorProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_AMD_shader_core_properties)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesAMD>));
    #endif // defined(VK_AMD_shader_core_properties)

    #if defined(VK_AMD_shader_core_properties)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesAMD, VkPhysicalDeviceShaderCorePropertiesAMD>));
    #endif // defined(VK_AMD_shader_core_properties)

    #if defined(VK_AMD_shader_core_properties)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesAMD>));
    #endif // defined(VK_AMD_shader_core_properties)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI, VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_MSFT_layered_driver)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredDriverPropertiesMSFT>));
    #endif // defined(VK_MSFT_layered_driver)

    #if defined(VK_MSFT_layered_driver)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredDriverPropertiesMSFT, VkPhysicalDeviceLayeredDriverPropertiesMSFT>));
    #endif // defined(VK_MSFT_layered_driver)

    #if defined(VK_MSFT_layered_driver)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredDriverPropertiesMSFT>));
    #endif // defined(VK_MSFT_layered_driver)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceProtectedMemoryProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceProtectedMemoryProperties, VkPhysicalDeviceProtectedMemoryProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceProtectedMemoryProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRenderPassStripedPropertiesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRenderPassStripedPropertiesARM, VkPhysicalDeviceRenderPassStripedPropertiesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceRenderPassStripedPropertiesARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderIntegerDotProductProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderIntegerDotProductProperties, VkPhysicalDeviceShaderIntegerDotProductProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderIntegerDotProductProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePortabilitySubsetPropertiesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePortabilitySubsetPropertiesKHR, VkPhysicalDevicePortabilitySubsetPropertiesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_KHR_portability_subset)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePortabilitySubsetPropertiesKHR>));
    #endif // defined(VK_KHR_portability_subset)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrix2PropertiesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrix2PropertiesNV, VkPhysicalDeviceCooperativeMatrix2PropertiesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_NV_cooperative_matrix2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrix2PropertiesNV>));
    #endif // defined(VK_NV_cooperative_matrix2)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCudaKernelLaunchPropertiesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCudaKernelLaunchPropertiesNV, VkPhysicalDeviceCudaKernelLaunchPropertiesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_cuda_kernel_launch)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceCudaKernelLaunchPropertiesNV>));
    #endif // defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT, VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_shader_module_identifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT>));
    #endif // defined(VK_EXT_shader_module_identifier)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV, VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_NV_extended_sparse_address_space)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV>));
    #endif // defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT, VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_graphics_pipeline_library)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>));
    #endif // defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRobustness2PropertiesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRobustness2PropertiesEXT, VkPhysicalDeviceRobustness2PropertiesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_EXT_robustness2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceRobustness2PropertiesEXT>));
    #endif // defined(VK_EXT_robustness2)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCustomBorderColorPropertiesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCustomBorderColorPropertiesEXT, VkPhysicalDeviceCustomBorderColorPropertiesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_EXT_custom_border_color)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceCustomBorderColorPropertiesEXT>));
    #endif // defined(VK_EXT_custom_border_color)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan11Properties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan11Properties, VkPhysicalDeviceVulkan11Properties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan11Properties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_NV_ray_tracing)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPropertiesNV>));
    #endif // defined(VK_NV_ray_tracing)

    #if defined(VK_NV_ray_tracing)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPropertiesNV, VkPhysicalDeviceRayTracingPropertiesNV>));
    #endif // defined(VK_NV_ray_tracing)

    #if defined(VK_NV_ray_tracing)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPropertiesNV>));
    #endif // defined(VK_NV_ray_tracing)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLineRasterizationProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLineRasterizationProperties, VkPhysicalDeviceLineRasterizationProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceLineRasterizationProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRatePropertiesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRatePropertiesKHR, VkPhysicalDeviceFragmentShadingRatePropertiesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRatePropertiesKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance7PropertiesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance7PropertiesKHR, VkPhysicalDeviceMaintenance7PropertiesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance7PropertiesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV, VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV>));
    #endif // defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_EXT_conservative_rasterization)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceConservativeRasterizationPropertiesEXT>));
    #endif // defined(VK_EXT_conservative_rasterization)

    #if defined(VK_EXT_conservative_rasterization)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceConservativeRasterizationPropertiesEXT, VkPhysicalDeviceConservativeRasterizationPropertiesEXT>));
    #endif // defined(VK_EXT_conservative_rasterization)

    #if defined(VK_EXT_conservative_rasterization)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceConservativeRasterizationPropertiesEXT>));
    #endif // defined(VK_EXT_conservative_rasterization)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT, VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM, VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesNV, VkPhysicalDeviceMeshShaderPropertiesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_NV_mesh_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesNV>));
    #endif // defined(VK_NV_mesh_shader)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessingPropertiesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessingPropertiesQCOM, VkPhysicalDeviceImageProcessingPropertiesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_QCOM_image_processing)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessingPropertiesQCOM>));
    #endif // defined(VK_QCOM_image_processing)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderObjectPropertiesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderObjectPropertiesEXT, VkPhysicalDeviceShaderObjectPropertiesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_EXT_shader_object)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderObjectPropertiesEXT>));
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeVectorPropertiesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeVectorPropertiesNV, VkPhysicalDeviceCooperativeVectorPropertiesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_NV_cooperative_vector)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeVectorPropertiesNV>));
    #endif // defined(VK_NV_cooperative_vector)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMemoryDecompressionPropertiesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMemoryDecompressionPropertiesNV, VkPhysicalDeviceMemoryDecompressionPropertiesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_NV_memory_decompression)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMemoryDecompressionPropertiesNV>));
    #endif // defined(VK_NV_memory_decompression)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceIDProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceIDProperties, VkPhysicalDeviceIDProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceIDProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorIndexingProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorIndexingProperties, VkPhysicalDeviceDescriptorIndexingProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorIndexingProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_vertex_attribute_divisor)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_divisor)

    #if defined(VK_EXT_vertex_attribute_divisor)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_divisor)

    #if defined(VK_EXT_vertex_attribute_divisor)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>));
    #endif // defined(VK_EXT_vertex_attribute_divisor)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesKHR, VkPhysicalDeviceCooperativeMatrixPropertiesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_KHR_cooperative_matrix)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesKHR>));
    #endif // defined(VK_KHR_cooperative_matrix)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineRobustnessProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineRobustnessProperties, VkPhysicalDevicePipelineRobustnessProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineRobustnessProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceTransformFeedbackPropertiesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceTransformFeedbackPropertiesEXT, VkPhysicalDeviceTransformFeedbackPropertiesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_transform_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceTransformFeedbackPropertiesEXT>));
    #endif // defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMapMemoryPlacedPropertiesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMapMemoryPlacedPropertiesEXT, VkPhysicalDeviceMapMemoryPlacedPropertiesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMapMemoryPlacedPropertiesEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapPropertiesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapPropertiesEXT, VkPhysicalDeviceFragmentDensityMapPropertiesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapPropertiesEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewProperties, VkPhysicalDeviceMultiviewProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSchedulingControlsPropertiesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSchedulingControlsPropertiesARM, VkPhysicalDeviceSchedulingControlsPropertiesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_ARM_scheduling_controls)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceSchedulingControlsPropertiesARM>));
    #endif // defined(VK_ARM_scheduling_controls)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDisplacementMicromapPropertiesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDisplacementMicromapPropertiesNV, VkPhysicalDeviceDisplacementMicromapPropertiesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDisplacementMicromapPropertiesNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubpassShadingPropertiesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubpassShadingPropertiesHUAWEI, VkPhysicalDeviceSubpassShadingPropertiesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_HUAWEI_subpass_shading)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubpassShadingPropertiesHUAWEI>));
    #endif // defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance6Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance6Properties, VkPhysicalDeviceMaintenance6Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance6Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupProperties, VkPhysicalDeviceSubgroupProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR, VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_KHR_compute_shader_derivatives)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR>));
    #endif // defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderEnqueuePropertiesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderEnqueuePropertiesAMDX, VkPhysicalDeviceShaderEnqueuePropertiesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_AMDX_shader_enqueue)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderEnqueuePropertiesAMDX>));
    #endif // defined(VK_AMDX_shader_enqueue)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceProvokingVertexPropertiesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceProvokingVertexPropertiesEXT, VkPhysicalDeviceProvokingVertexPropertiesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_provoking_vertex)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceProvokingVertexPropertiesEXT>));
    #endif // defined(VK_EXT_provoking_vertex)

    #if defined(VK_AMD_shader_core_properties2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreProperties2AMD>));
    #endif // defined(VK_AMD_shader_core_properties2)

    #if defined(VK_AMD_shader_core_properties2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreProperties2AMD, VkPhysicalDeviceShaderCoreProperties2AMD>));
    #endif // defined(VK_AMD_shader_core_properties2)

    #if defined(VK_AMD_shader_core_properties2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreProperties2AMD>));
    #endif // defined(VK_AMD_shader_core_properties2)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesEXT, VkPhysicalDeviceMeshShaderPropertiesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_mesh_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesEXT>));
    #endif // defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpacityMicromapPropertiesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpacityMicromapPropertiesEXT, VkPhysicalDeviceOpacityMicromapPropertiesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpacityMicromapPropertiesEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM, VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_ARM_shader_core_builtins)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM>));
    #endif // defined(VK_ARM_shader_core_builtins)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedDynamicState3PropertiesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedDynamicState3PropertiesEXT, VkPhysicalDeviceExtendedDynamicState3PropertiesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_extended_dynamic_state3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedDynamicState3PropertiesEXT>));
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_EXT_blend_operation_advanced)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>));
    #endif // defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFloatControlsProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFloatControlsProperties, VkPhysicalDeviceFloatControlsProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceFloatControlsProperties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_pci_bus_info)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePCIBusInfoPropertiesEXT>));
    #endif // defined(VK_EXT_pci_bus_info)

    #if defined(VK_EXT_pci_bus_info)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePCIBusInfoPropertiesEXT, VkPhysicalDevicePCIBusInfoPropertiesEXT>));
    #endif // defined(VK_EXT_pci_bus_info)

    #if defined(VK_EXT_pci_bus_info)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePCIBusInfoPropertiesEXT>));
    #endif // defined(VK_EXT_pci_bus_info)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR, VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_KHR_fragment_shader_barycentric)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>));
    #endif // defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance4Properties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance4Properties, VkPhysicalDeviceMaintenance4Properties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance4Properties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredApiPropertiesListKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredApiPropertiesListKHR, VkPhysicalDeviceLayeredApiPropertiesListKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredApiPropertiesListKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan12Properties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan12Properties, VkPhysicalDeviceVulkan12Properties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan12Properties>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceTexelBufferAlignmentProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceTexelBufferAlignmentProperties, VkPhysicalDeviceTexelBufferAlignmentProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceTexelBufferAlignmentProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan13Properties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan13Properties, VkPhysicalDeviceVulkan13Properties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan13Properties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShadingRateImagePropertiesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShadingRateImagePropertiesNV, VkPhysicalDeviceShadingRateImagePropertiesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_shading_rate_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShadingRateImagePropertiesNV>));
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalFormatResolvePropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalFormatResolvePropertiesANDROID, VkPhysicalDeviceExternalFormatResolvePropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalFormatResolvePropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMap2PropertiesEXT, VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_EXT_fragment_density_map2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>));
    #endif // defined(VK_EXT_fragment_density_map2)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupSizeControlProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupSizeControlProperties, VkPhysicalDeviceSubgroupSizeControlProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupSizeControlProperties>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderSMBuiltinsPropertiesNV, VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_NV_shader_sm_builtins)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>));
    #endif // defined(VK_NV_shader_sm_builtins)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance5Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance5Properties, VkPhysicalDeviceMaintenance5Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance5Properties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePerformanceQueryPropertiesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePerformanceQueryPropertiesKHR, VkPhysicalDevicePerformanceQueryPropertiesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePerformanceQueryPropertiesKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance3Properties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance3Properties, VkPhysicalDeviceMaintenance3Properties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance3Properties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterAccelerationStructurePropertiesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterAccelerationStructurePropertiesNV, VkPhysicalDeviceClusterAccelerationStructurePropertiesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterAccelerationStructurePropertiesNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePointClippingProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePointClippingProperties, VkPhysicalDevicePointClippingProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePointClippingProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT, VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_EXT_legacy_vertex_attributes)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT>));
    #endif // defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_EXT_physical_device_drm)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDrmPropertiesEXT>));
    #endif // defined(VK_EXT_physical_device_drm)

    #if defined(VK_EXT_physical_device_drm)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDrmPropertiesEXT, VkPhysicalDeviceDrmPropertiesEXT>));
    #endif // defined(VK_EXT_physical_device_drm)

    #if defined(VK_EXT_physical_device_drm)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDrmPropertiesEXT>));
    #endif // defined(VK_EXT_physical_device_drm)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageAlignmentControlPropertiesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageAlignmentControlPropertiesMESA, VkPhysicalDeviceImageAlignmentControlPropertiesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_MESA_image_alignment_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageAlignmentControlPropertiesMESA>));
    #endif // defined(VK_MESA_image_alignment_control)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderTileImagePropertiesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderTileImagePropertiesEXT, VkPhysicalDeviceShaderTileImagePropertiesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_EXT_shader_tile_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderTileImagePropertiesEXT>));
    #endif // defined(VK_EXT_shader_tile_image)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpticalFlowPropertiesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpticalFlowPropertiesNV, VkPhysicalDeviceOpticalFlowPropertiesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpticalFlowPropertiesNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferPropertiesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferPropertiesEXT, VkPhysicalDeviceDescriptorBufferPropertiesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferPropertiesEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineBinaryPropertiesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineBinaryPropertiesKHR, VkPhysicalDevicePipelineBinaryPropertiesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineBinaryPropertiesKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessing2PropertiesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessing2PropertiesQCOM, VkPhysicalDeviceImageProcessing2PropertiesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_QCOM_image_processing2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessing2PropertiesQCOM>));
    #endif // defined(VK_QCOM_image_processing2)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV, VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceNestedCommandBufferPropertiesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceNestedCommandBufferPropertiesEXT, VkPhysicalDeviceNestedCommandBufferPropertiesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_EXT_nested_command_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceNestedCommandBufferPropertiesEXT>));
    #endif // defined(VK_EXT_nested_command_buffer)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV, VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_NV_fragment_shading_rate_enums)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>));
    #endif // defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceHostImageCopyProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceProperties2, VkPhysicalDeviceHostImageCopyProperties, VkPhysicalDeviceHostImageCopyProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceProperties2, VkPhysicalDeviceHostImageCopyProperties>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, format_properties2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkFormatProperties2, VkDrmFormatModifierPropertiesList2EXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkFormatProperties2, VkDrmFormatModifierPropertiesList2EXT, VkDrmFormatModifierPropertiesList2EXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkFormatProperties2, VkDrmFormatModifierPropertiesList2EXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkFormatProperties2, VkFormatProperties3>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkFormatProperties2, VkFormatProperties3, VkFormatProperties3>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkFormatProperties2, VkFormatProperties3>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkFormatProperties2, VkDrmFormatModifierPropertiesListEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkFormatProperties2, VkDrmFormatModifierPropertiesListEXT, VkDrmFormatModifierPropertiesListEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkFormatProperties2, VkDrmFormatModifierPropertiesListEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((can_extend_v<VkFormatProperties2, VkSubpassResolvePerformanceQueryEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_FALSE((can_extend_v<VkFormatProperties2, VkSubpassResolvePerformanceQueryEXT, VkSubpassResolvePerformanceQueryEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((chain_compatible<VkFormatProperties2, VkSubpassResolvePerformanceQueryEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, image_format_properties2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_EXT_filter_cubic)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageFormatProperties2, VkFilterCubicImageViewImageFormatPropertiesEXT>));
    #endif // defined(VK_EXT_filter_cubic)

    #if defined(VK_EXT_filter_cubic)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageFormatProperties2, VkFilterCubicImageViewImageFormatPropertiesEXT, VkFilterCubicImageViewImageFormatPropertiesEXT>));
    #endif // defined(VK_EXT_filter_cubic)

    #if defined(VK_EXT_filter_cubic)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageFormatProperties2, VkFilterCubicImageViewImageFormatPropertiesEXT>));
    #endif // defined(VK_EXT_filter_cubic)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageFormatProperties2, VkHostImageCopyDevicePerformanceQuery>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageFormatProperties2, VkHostImageCopyDevicePerformanceQuery, VkHostImageCopyDevicePerformanceQuery>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageFormatProperties2, VkHostImageCopyDevicePerformanceQuery>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageFormatProperties2, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageFormatProperties2, VkImageCompressionPropertiesEXT, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageFormatProperties2, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageFormatProperties2, VkSamplerYcbcrConversionImageFormatProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageFormatProperties2, VkSamplerYcbcrConversionImageFormatProperties, VkSamplerYcbcrConversionImageFormatProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageFormatProperties2, VkSamplerYcbcrConversionImageFormatProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageFormatProperties2, VkExternalImageFormatProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageFormatProperties2, VkExternalImageFormatProperties, VkExternalImageFormatProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageFormatProperties2, VkExternalImageFormatProperties>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_AMD_texture_gather_bias_lod)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageFormatProperties2, VkTextureLODGatherFormatPropertiesAMD>));
    #endif // defined(VK_AMD_texture_gather_bias_lod)

    #if defined(VK_AMD_texture_gather_bias_lod)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageFormatProperties2, VkTextureLODGatherFormatPropertiesAMD, VkTextureLODGatherFormatPropertiesAMD>));
    #endif // defined(VK_AMD_texture_gather_bias_lod)

    #if defined(VK_AMD_texture_gather_bias_lod)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageFormatProperties2, VkTextureLODGatherFormatPropertiesAMD>));
    #endif // defined(VK_AMD_texture_gather_bias_lod)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageFormatProperties2, VkAndroidHardwareBufferUsageANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageFormatProperties2, VkAndroidHardwareBufferUsageANDROID, VkAndroidHardwareBufferUsageANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageFormatProperties2, VkAndroidHardwareBufferUsageANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, physical_device_image_format_info2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkImageFormatListCreateInfo, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkImageFormatListCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_EXT_filter_cubic)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceImageViewImageFormatInfoEXT>));
    #endif // defined(VK_EXT_filter_cubic)

    #if defined(VK_EXT_filter_cubic)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceImageViewImageFormatInfoEXT, VkPhysicalDeviceImageViewImageFormatInfoEXT>));
    #endif // defined(VK_EXT_filter_cubic)

    #if defined(VK_EXT_filter_cubic)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceImageViewImageFormatInfoEXT>));
    #endif // defined(VK_EXT_filter_cubic)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkOpticalFlowImageFormatInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkOpticalFlowImageFormatInfoNV, VkOpticalFlowImageFormatInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkOpticalFlowImageFormatInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkImageCompressionControlEXT, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkImageCompressionControlEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkVideoProfileListInfoKHR, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceImageDrmFormatModifierInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceImageDrmFormatModifierInfoEXT, VkPhysicalDeviceImageDrmFormatModifierInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_image_drm_format_modifier)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceImageDrmFormatModifierInfoEXT>));
    #endif // defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkImageStencilUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkImageStencilUsageCreateInfo, VkImageStencilUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkImageStencilUsageCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceExternalImageFormatInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceExternalImageFormatInfo, VkPhysicalDeviceExternalImageFormatInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceImageFormatInfo2, VkPhysicalDeviceExternalImageFormatInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, queue_family_properties2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyQueryResultStatusPropertiesKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyQueryResultStatusPropertiesKHR, VkQueueFamilyQueryResultStatusPropertiesKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueueFamilyProperties2, VkQueueFamilyQueryResultStatusPropertiesKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyVideoPropertiesKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyVideoPropertiesKHR, VkQueueFamilyVideoPropertiesKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueueFamilyProperties2, VkQueueFamilyVideoPropertiesKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_NV_device_diagnostic_checkpoints)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyCheckpointProperties2NV>));
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

    #if defined(VK_NV_device_diagnostic_checkpoints)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyCheckpointProperties2NV, VkQueueFamilyCheckpointProperties2NV>));
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

    #if defined(VK_NV_device_diagnostic_checkpoints)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueueFamilyProperties2, VkQueueFamilyCheckpointProperties2NV>));
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyGlobalPriorityProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyGlobalPriorityProperties, VkQueueFamilyGlobalPriorityProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueueFamilyProperties2, VkQueueFamilyGlobalPriorityProperties>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_device_diagnostic_checkpoints)
        STATIC_EXPECT_TRUE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyCheckpointPropertiesNV>));
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

    #if defined(VK_NV_device_diagnostic_checkpoints)
        STATIC_EXPECT_FALSE((can_extend_v<VkQueueFamilyProperties2, VkQueueFamilyCheckpointPropertiesNV, VkQueueFamilyCheckpointPropertiesNV>));
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

    #if defined(VK_NV_device_diagnostic_checkpoints)
        STATIC_EXPECT_TRUE((chain_compatible<VkQueueFamilyProperties2, VkQueueFamilyCheckpointPropertiesNV>));
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, physical_device_memory_properties2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_EXT_memory_budget)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceMemoryProperties2, VkPhysicalDeviceMemoryBudgetPropertiesEXT>));
    #endif // defined(VK_EXT_memory_budget)

    #if defined(VK_EXT_memory_budget)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceMemoryProperties2, VkPhysicalDeviceMemoryBudgetPropertiesEXT, VkPhysicalDeviceMemoryBudgetPropertiesEXT>));
    #endif // defined(VK_EXT_memory_budget)

    #if defined(VK_EXT_memory_budget)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceMemoryProperties2, VkPhysicalDeviceMemoryBudgetPropertiesEXT>));
    #endif // defined(VK_EXT_memory_budget)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, physical_device_external_buffer_info)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceExternalBufferInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceExternalBufferInfo, VkBufferUsageFlags2CreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceExternalBufferInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, physical_device_external_semaphore_info)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceExternalSemaphoreInfo, VkSemaphoreTypeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceExternalSemaphoreInfo, VkSemaphoreTypeCreateInfo, VkSemaphoreTypeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceExternalSemaphoreInfo, VkSemaphoreTypeCreateInfo>));
    #endif // defined(VK_VERSION_1_2)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, bind_buffer_memory_info)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindBufferMemoryInfo, VkBindBufferMemoryDeviceGroupInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindBufferMemoryInfo, VkBindBufferMemoryDeviceGroupInfo, VkBindBufferMemoryDeviceGroupInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindBufferMemoryInfo, VkBindBufferMemoryDeviceGroupInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindBufferMemoryInfo, VkBindMemoryStatus>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindBufferMemoryInfo, VkBindMemoryStatus, VkBindMemoryStatus>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindBufferMemoryInfo, VkBindMemoryStatus>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, bind_image_memory_info)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindImageMemoryInfo, VkBindImageMemoryDeviceGroupInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindImageMemoryInfo, VkBindImageMemoryDeviceGroupInfo, VkBindImageMemoryDeviceGroupInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindImageMemoryInfo, VkBindImageMemoryDeviceGroupInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindImageMemoryInfo, VkBindImageMemorySwapchainInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindImageMemoryInfo, VkBindImageMemorySwapchainInfoKHR, VkBindImageMemorySwapchainInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_KHR_device_group)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindImageMemoryInfo, VkBindImageMemorySwapchainInfoKHR>));
    #endif // defined(VK_KHR_device_group)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindImageMemoryInfo, VkBindMemoryStatus>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindImageMemoryInfo, VkBindMemoryStatus, VkBindMemoryStatus>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindImageMemoryInfo, VkBindMemoryStatus>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindImageMemoryInfo, VkBindImagePlaneMemoryInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindImageMemoryInfo, VkBindImagePlaneMemoryInfo, VkBindImagePlaneMemoryInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindImageMemoryInfo, VkBindImagePlaneMemoryInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, hdr_metadata_ext)
{
#if defined(VK_EXT_hdr_metadata) 
    
    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_TRUE((can_extend_v<VkHdrMetadataEXT, VkHdrVividDynamicMetadataHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_FALSE((can_extend_v<VkHdrMetadataEXT, VkHdrVividDynamicMetadataHUAWEI, VkHdrVividDynamicMetadataHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_HUAWEI_hdr_vivid)
        STATIC_EXPECT_TRUE((chain_compatible<VkHdrMetadataEXT, VkHdrVividDynamicMetadataHUAWEI>));
    #endif // defined(VK_HUAWEI_hdr_vivid)

#endif // VK_EXT_hdr_metadata
}

TEST(pnext_chain, physical_device_surface_info2_khr)
{
#if defined(VK_KHR_get_surface_capabilities2) 
    
    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfaceFullScreenExclusiveWin32InfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfaceFullScreenExclusiveWin32InfoEXT, VkSurfaceFullScreenExclusiveWin32InfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfaceFullScreenExclusiveWin32InfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfacePresentModeEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfacePresentModeEXT, VkSurfacePresentModeEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfacePresentModeEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfaceFullScreenExclusiveInfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfaceFullScreenExclusiveInfoEXT, VkSurfaceFullScreenExclusiveInfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceSurfaceInfo2KHR, VkSurfaceFullScreenExclusiveInfoEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

#endif // VK_KHR_get_surface_capabilities2
}

TEST(pnext_chain, surface_capabilities2_khr)
{
#if defined(VK_KHR_get_surface_capabilities2) 
    
    #if defined(VK_KHR_shared_presentable_image)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkSharedPresentSurfaceCapabilitiesKHR>));
    #endif // defined(VK_KHR_shared_presentable_image)

    #if defined(VK_KHR_shared_presentable_image)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkSharedPresentSurfaceCapabilitiesKHR, VkSharedPresentSurfaceCapabilitiesKHR>));
    #endif // defined(VK_KHR_shared_presentable_image)

    #if defined(VK_KHR_shared_presentable_image)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkSharedPresentSurfaceCapabilitiesKHR>));
    #endif // defined(VK_KHR_shared_presentable_image)

    #if defined(VK_AMD_display_native_hdr)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkDisplayNativeHdrSurfaceCapabilitiesAMD>));
    #endif // defined(VK_AMD_display_native_hdr)

    #if defined(VK_AMD_display_native_hdr)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkDisplayNativeHdrSurfaceCapabilitiesAMD, VkDisplayNativeHdrSurfaceCapabilitiesAMD>));
    #endif // defined(VK_AMD_display_native_hdr)

    #if defined(VK_AMD_display_native_hdr)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkDisplayNativeHdrSurfaceCapabilitiesAMD>));
    #endif // defined(VK_AMD_display_native_hdr)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfaceCapabilitiesFullScreenExclusiveEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfaceCapabilitiesFullScreenExclusiveEXT, VkSurfaceCapabilitiesFullScreenExclusiveEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_full_screen_exclusive)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkSurfaceCapabilitiesFullScreenExclusiveEXT>));
    #endif // defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfacePresentScalingCapabilitiesEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfacePresentScalingCapabilitiesEXT, VkSurfacePresentScalingCapabilitiesEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkSurfacePresentScalingCapabilitiesEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfaceCapabilitiesPresentBarrierNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfaceCapabilitiesPresentBarrierNV, VkSurfaceCapabilitiesPresentBarrierNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_NV_present_barrier)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkSurfaceCapabilitiesPresentBarrierNV>));
    #endif // defined(VK_NV_present_barrier)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfacePresentModeCompatibilityEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfacePresentModeCompatibilityEXT, VkSurfacePresentModeCompatibilityEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_EXT_surface_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkSurfacePresentModeCompatibilityEXT>));
    #endif // defined(VK_EXT_surface_maintenance1)

    #if defined(VK_KHR_surface_protected_capabilities)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfaceProtectedCapabilitiesKHR>));
    #endif // defined(VK_KHR_surface_protected_capabilities)

    #if defined(VK_KHR_surface_protected_capabilities)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkSurfaceProtectedCapabilitiesKHR, VkSurfaceProtectedCapabilitiesKHR>));
    #endif // defined(VK_KHR_surface_protected_capabilities)

    #if defined(VK_KHR_surface_protected_capabilities)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkSurfaceProtectedCapabilitiesKHR>));
    #endif // defined(VK_KHR_surface_protected_capabilities)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceCapabilities2KHR, VkLatencySurfaceCapabilitiesNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceCapabilities2KHR, VkLatencySurfaceCapabilitiesNV, VkLatencySurfaceCapabilitiesNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceCapabilities2KHR, VkLatencySurfaceCapabilitiesNV>));
    #endif // defined(VK_NV_low_latency2)

#endif // VK_KHR_get_surface_capabilities2
}

TEST(pnext_chain, surface_format2_khr)
{
#if defined(VK_KHR_get_surface_capabilities2) 
    
    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkSurfaceFormat2KHR, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkSurfaceFormat2KHR, VkImageCompressionPropertiesEXT, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkSurfaceFormat2KHR, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

#endif // VK_KHR_get_surface_capabilities2
}

TEST(pnext_chain, display_mode_properties2_khr)
{
#if defined(VK_KHR_get_display_properties2) 
    
    #if defined(VK_NV_display_stereo)
        STATIC_EXPECT_TRUE((can_extend_v<VkDisplayModeProperties2KHR, VkDisplayModeStereoPropertiesNV>));
    #endif // defined(VK_NV_display_stereo)

    #if defined(VK_NV_display_stereo)
        STATIC_EXPECT_FALSE((can_extend_v<VkDisplayModeProperties2KHR, VkDisplayModeStereoPropertiesNV, VkDisplayModeStereoPropertiesNV>));
    #endif // defined(VK_NV_display_stereo)

    #if defined(VK_NV_display_stereo)
        STATIC_EXPECT_TRUE((chain_compatible<VkDisplayModeProperties2KHR, VkDisplayModeStereoPropertiesNV>));
    #endif // defined(VK_NV_display_stereo)

#endif // VK_KHR_get_display_properties2
}

TEST(pnext_chain, image_memory_requirements_info2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageMemoryRequirementsInfo2, VkImagePlaneMemoryRequirementsInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageMemoryRequirementsInfo2, VkImagePlaneMemoryRequirementsInfo, VkImagePlaneMemoryRequirementsInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageMemoryRequirementsInfo2, VkImagePlaneMemoryRequirementsInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, memory_requirements2)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryRequirements2, VkMemoryDedicatedRequirements>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryRequirements2, VkMemoryDedicatedRequirements, VkMemoryDedicatedRequirements>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryRequirements2, VkMemoryDedicatedRequirements>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, sampler_ycbcr_conversion_create_info)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerYcbcrConversionCreateInfo, VkExternalFormatQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerYcbcrConversionCreateInfo, VkExternalFormatQNX, VkExternalFormatQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerYcbcrConversionCreateInfo, VkExternalFormatQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerYcbcrConversionCreateInfo, VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerYcbcrConversionCreateInfo, VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM, VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_ycbcr_degamma)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerYcbcrConversionCreateInfo, VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM>));
    #endif // defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkSamplerYcbcrConversionCreateInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkSamplerYcbcrConversionCreateInfo, VkExternalFormatANDROID, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkSamplerYcbcrConversionCreateInfo, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, physical_device_layered_api_properties_khr)
{
#if defined(VK_KHR_maintenance7) 
    
    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceLayeredApiPropertiesKHR, VkPhysicalDeviceLayeredApiVulkanPropertiesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceLayeredApiPropertiesKHR, VkPhysicalDeviceLayeredApiVulkanPropertiesKHR, VkPhysicalDeviceLayeredApiVulkanPropertiesKHR>));
    #endif // defined(VK_KHR_maintenance7)

    #if defined(VK_KHR_maintenance7)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceLayeredApiPropertiesKHR, VkPhysicalDeviceLayeredApiVulkanPropertiesKHR>));
    #endif // defined(VK_KHR_maintenance7)

#endif // VK_KHR_maintenance7
}

TEST(pnext_chain, descriptor_set_layout_support)
{
#if defined(VK_VERSION_1_1) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorSetLayoutSupport, VkDescriptorSetVariableDescriptorCountLayoutSupport>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorSetLayoutSupport, VkDescriptorSetVariableDescriptorCountLayoutSupport, VkDescriptorSetVariableDescriptorCountLayoutSupport>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorSetLayoutSupport, VkDescriptorSetVariableDescriptorCountLayoutSupport>));
    #endif // defined(VK_VERSION_1_2)

#endif // VK_VERSION_1_1
}

TEST(pnext_chain, debug_utils_messenger_callback_data_ext)
{
#if defined(VK_EXT_debug_utils) 
    
    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_TRUE((can_extend_v<VkDebugUtilsMessengerCallbackDataEXT, VkDeviceAddressBindingCallbackDataEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_FALSE((can_extend_v<VkDebugUtilsMessengerCallbackDataEXT, VkDeviceAddressBindingCallbackDataEXT, VkDeviceAddressBindingCallbackDataEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

    #if defined(VK_EXT_device_address_binding_report)
        STATIC_EXPECT_TRUE((chain_compatible<VkDebugUtilsMessengerCallbackDataEXT, VkDeviceAddressBindingCallbackDataEXT>));
    #endif // defined(VK_EXT_device_address_binding_report)

#endif // VK_EXT_debug_utils
}

TEST(pnext_chain, attachment_description2)
{
#if defined(VK_VERSION_1_2) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkAttachmentDescription2, VkAttachmentDescriptionStencilLayout>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkAttachmentDescription2, VkAttachmentDescriptionStencilLayout, VkAttachmentDescriptionStencilLayout>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkAttachmentDescription2, VkAttachmentDescriptionStencilLayout>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkAttachmentDescription2, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkAttachmentDescription2, VkExternalFormatANDROID, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkAttachmentDescription2, VkExternalFormatANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#endif // VK_VERSION_1_2
}

TEST(pnext_chain, attachment_reference2)
{
#if defined(VK_VERSION_1_2) 
    
    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkAttachmentReference2, VkAttachmentReferenceStencilLayout>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkAttachmentReference2, VkAttachmentReferenceStencilLayout, VkAttachmentReferenceStencilLayout>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkAttachmentReference2, VkAttachmentReferenceStencilLayout>));
    #endif // defined(VK_VERSION_1_2)

#endif // VK_VERSION_1_2
}

TEST(pnext_chain, subpass_description2)
{
#if defined(VK_VERSION_1_2) 
    
    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubpassDescription2, VkMultisampledRenderToSingleSampledInfoEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubpassDescription2, VkMultisampledRenderToSingleSampledInfoEXT, VkMultisampledRenderToSingleSampledInfoEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubpassDescription2, VkMultisampledRenderToSingleSampledInfoEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubpassDescription2, VkRenderPassSubpassFeedbackCreateInfoEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubpassDescription2, VkRenderPassSubpassFeedbackCreateInfoEXT, VkRenderPassSubpassFeedbackCreateInfoEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubpassDescription2, VkRenderPassSubpassFeedbackCreateInfoEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubpassDescription2, VkSubpassDescriptionDepthStencilResolve>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubpassDescription2, VkSubpassDescriptionDepthStencilResolve, VkSubpassDescriptionDepthStencilResolve>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubpassDescription2, VkSubpassDescriptionDepthStencilResolve>));
    #endif // defined(VK_VERSION_1_2)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubpassDescription2, VkFragmentShadingRateAttachmentInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubpassDescription2, VkFragmentShadingRateAttachmentInfoKHR, VkFragmentShadingRateAttachmentInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubpassDescription2, VkFragmentShadingRateAttachmentInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubpassDescription2, VkRenderPassCreationControlEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubpassDescription2, VkRenderPassCreationControlEXT, VkRenderPassCreationControlEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubpassDescription2, VkRenderPassCreationControlEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

#endif // VK_VERSION_1_2
}

TEST(pnext_chain, subpass_dependency2)
{
#if defined(VK_VERSION_1_2) 
    
    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubpassDependency2, VkMemoryBarrier2>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubpassDependency2, VkMemoryBarrier2, VkMemoryBarrier2>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubpassDependency2, VkMemoryBarrier2>));
    #endif // defined(VK_VERSION_1_3)

#endif // VK_VERSION_1_2
}

TEST(pnext_chain, render_pass_create_info2)
{
#if defined(VK_VERSION_1_2) 
    
    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassCreateInfo2, VkRenderPassCreationFeedbackCreateInfoEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassCreateInfo2, VkRenderPassCreationFeedbackCreateInfoEXT, VkRenderPassCreationFeedbackCreateInfoEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassCreateInfo2, VkRenderPassCreationFeedbackCreateInfoEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassCreateInfo2, VkRenderPassCreationControlEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassCreateInfo2, VkRenderPassCreationControlEXT, VkRenderPassCreationControlEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_subpass_merge_feedback)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassCreateInfo2, VkRenderPassCreationControlEXT>));
    #endif // defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderPassCreateInfo2, VkRenderPassFragmentDensityMapCreateInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderPassCreateInfo2, VkRenderPassFragmentDensityMapCreateInfoEXT, VkRenderPassFragmentDensityMapCreateInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderPassCreateInfo2, VkRenderPassFragmentDensityMapCreateInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

#endif // VK_VERSION_1_2
}

TEST(pnext_chain, subpass_end_info)
{
#if defined(VK_VERSION_1_2) 
    
    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubpassEndInfo, VkSubpassFragmentDensityMapOffsetEndInfoQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubpassEndInfo, VkSubpassFragmentDensityMapOffsetEndInfoQCOM, VkSubpassFragmentDensityMapOffsetEndInfoQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_QCOM_fragment_density_map_offset)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubpassEndInfo, VkSubpassFragmentDensityMapOffsetEndInfoQCOM>));
    #endif // defined(VK_QCOM_fragment_density_map_offset)

#endif // VK_VERSION_1_2
}

TEST(pnext_chain, android_hardware_buffer_properties_android)
{
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) 
    
    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatProperties2ANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatProperties2ANDROID, VkAndroidHardwareBufferFormatProperties2ANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatProperties2ANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((can_extend_v<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatResolvePropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_FALSE((can_extend_v<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatResolvePropertiesANDROID, VkAndroidHardwareBufferFormatResolvePropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_format_resolve)
        STATIC_EXPECT_TRUE((chain_compatible<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatResolvePropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatPropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatPropertiesANDROID, VkAndroidHardwareBufferFormatPropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkAndroidHardwareBufferPropertiesANDROID, VkAndroidHardwareBufferFormatPropertiesANDROID>));
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#endif // VK_ANDROID_external_memory_android_hardware_buffer
}

TEST(pnext_chain, ray_tracing_pipeline_create_info_nv)
{
#if defined(VK_NV_ray_tracing) 
    
    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoNV, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoNV, VkPipelineOfflineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoNV, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoNV, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoNV, VkPipelineCreationFeedbackCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoNV, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoNV, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoNV, VkPipelineCreateFlags2CreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoNV, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_NV_ray_tracing
}

TEST(pnext_chain, ray_tracing_pipeline_create_info_khr)
{
#if defined(VK_KHR_ray_tracing_pipeline) 
    
    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineBinaryInfoKHR, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_pipeline_binary)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoKHR, VkPipelineBinaryInfoKHR>));
    #endif // defined(VK_KHR_pipeline_binary)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineOfflineCreateInfo, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VKSC_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoKHR, VkPipelineOfflineCreateInfo>));
    #endif // defined(VKSC_VERSION_1_0)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineCreateFlags2CreateInfo, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoKHR, VkPipelineCreateFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV, VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_NV_cluster_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoKHR, VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV>));
    #endif // defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineCreationFeedbackCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoKHR, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkRayTracingPipelineCreateInfoKHR, VkPipelineRobustnessCreateInfo, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkRayTracingPipelineCreateInfoKHR, VkPipelineRobustnessCreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_KHR_ray_tracing_pipeline
}

TEST(pnext_chain, acceleration_structure_create_info_nv)
{
#if defined(VK_NV_ray_tracing) 
    
    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureCreateInfoNV, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureCreateInfoNV, VkOpaqueCaptureDescriptorDataCreateInfoEXT, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureCreateInfoNV, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

#endif // VK_NV_ray_tracing
}

TEST(pnext_chain, acceleration_structure_geometry_triangles_data_khr)
{
#if defined(VK_KHR_acceleration_structure) 
    
    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureTrianglesDisplacementMicromapNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureTrianglesDisplacementMicromapNV, VkAccelerationStructureTrianglesDisplacementMicromapNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_displacement_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureTrianglesDisplacementMicromapNV>));
    #endif // defined(VK_NV_displacement_micromap)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureGeometryMotionTrianglesDataNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureGeometryMotionTrianglesDataNV, VkAccelerationStructureGeometryMotionTrianglesDataNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureGeometryMotionTrianglesDataNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureTrianglesOpacityMicromapEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureTrianglesOpacityMicromapEXT, VkAccelerationStructureTrianglesOpacityMicromapEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

    #if defined(VK_EXT_opacity_micromap)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureGeometryTrianglesDataKHR, VkAccelerationStructureTrianglesOpacityMicromapEXT>));
    #endif // defined(VK_EXT_opacity_micromap)

#endif // VK_KHR_acceleration_structure
}

TEST(pnext_chain, acceleration_structure_geometry_khr)
{
#if defined(VK_KHR_acceleration_structure) 
    
    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureGeometryKHR, VkAccelerationStructureGeometrySpheresDataNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureGeometryKHR, VkAccelerationStructureGeometrySpheresDataNV, VkAccelerationStructureGeometrySpheresDataNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureGeometryKHR, VkAccelerationStructureGeometrySpheresDataNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureGeometryKHR, VkAccelerationStructureGeometryLinearSweptSpheresDataNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureGeometryKHR, VkAccelerationStructureGeometryLinearSweptSpheresDataNV, VkAccelerationStructureGeometryLinearSweptSpheresDataNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureGeometryKHR, VkAccelerationStructureGeometryLinearSweptSpheresDataNV>));
    #endif // defined(VK_NV_ray_tracing_linear_swept_spheres)

#endif // VK_KHR_acceleration_structure
}

TEST(pnext_chain, acceleration_structure_create_info_khr)
{
#if defined(VK_KHR_acceleration_structure) 
    
    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureCreateInfoKHR, VkAccelerationStructureMotionInfoNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureCreateInfoKHR, VkAccelerationStructureMotionInfoNV, VkAccelerationStructureMotionInfoNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_ray_tracing_motion_blur)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureCreateInfoKHR, VkAccelerationStructureMotionInfoNV>));
    #endif // defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkAccelerationStructureCreateInfoKHR, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkAccelerationStructureCreateInfoKHR, VkOpaqueCaptureDescriptorDataCreateInfoEXT, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkAccelerationStructureCreateInfoKHR, VkOpaqueCaptureDescriptorDataCreateInfoEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

#endif // VK_KHR_acceleration_structure
}

TEST(pnext_chain, partitioned_acceleration_structure_instances_input_nv)
{
#if defined(VK_NV_partitioned_acceleration_structure) 
    
    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((can_extend_v<VkPartitionedAccelerationStructureInstancesInputNV, VkPartitionedAccelerationStructureFlagsNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_FALSE((can_extend_v<VkPartitionedAccelerationStructureInstancesInputNV, VkPartitionedAccelerationStructureFlagsNV, VkPartitionedAccelerationStructureFlagsNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_NV_partitioned_acceleration_structure)
        STATIC_EXPECT_TRUE((chain_compatible<VkPartitionedAccelerationStructureInstancesInputNV, VkPartitionedAccelerationStructureFlagsNV>));
    #endif // defined(VK_NV_partitioned_acceleration_structure)

#endif // VK_NV_partitioned_acceleration_structure
}

TEST(pnext_chain, physical_device_cluster_culling_shader_features_huawei)
{
#if defined(VK_HUAWEI_cluster_culling_shader) 
    
    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI, VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_HUAWEI_cluster_culling_shader)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI>));
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

#endif // VK_HUAWEI_cluster_culling_shader
}

TEST(pnext_chain, image_blit2)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_QCOM_rotated_copy_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageBlit2, VkCopyCommandTransformInfoQCOM>));
    #endif // defined(VK_QCOM_rotated_copy_commands)

    #if defined(VK_QCOM_rotated_copy_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageBlit2, VkCopyCommandTransformInfoQCOM, VkCopyCommandTransformInfoQCOM>));
    #endif // defined(VK_QCOM_rotated_copy_commands)

    #if defined(VK_QCOM_rotated_copy_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageBlit2, VkCopyCommandTransformInfoQCOM>));
    #endif // defined(VK_QCOM_rotated_copy_commands)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, buffer_image_copy2)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_QCOM_rotated_copy_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferImageCopy2, VkCopyCommandTransformInfoQCOM>));
    #endif // defined(VK_QCOM_rotated_copy_commands)

    #if defined(VK_QCOM_rotated_copy_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferImageCopy2, VkCopyCommandTransformInfoQCOM, VkCopyCommandTransformInfoQCOM>));
    #endif // defined(VK_QCOM_rotated_copy_commands)

    #if defined(VK_QCOM_rotated_copy_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferImageCopy2, VkCopyCommandTransformInfoQCOM>));
    #endif // defined(VK_QCOM_rotated_copy_commands)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, blit_image_info2)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((can_extend_v<VkBlitImageInfo2, VkBlitImageCubicWeightsInfoQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_FALSE((can_extend_v<VkBlitImageInfo2, VkBlitImageCubicWeightsInfoQCOM, VkBlitImageCubicWeightsInfoQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_QCOM_filter_cubic_weights)
        STATIC_EXPECT_TRUE((chain_compatible<VkBlitImageInfo2, VkBlitImageCubicWeightsInfoQCOM>));
    #endif // defined(VK_QCOM_filter_cubic_weights)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, generated_commands_memory_requirements_info_ext)
{
#if defined(VK_EXT_device_generated_commands) 
    
    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkGeneratedCommandsMemoryRequirementsInfoEXT, VkGeneratedCommandsPipelineInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkGeneratedCommandsMemoryRequirementsInfoEXT, VkGeneratedCommandsPipelineInfoEXT, VkGeneratedCommandsPipelineInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkGeneratedCommandsMemoryRequirementsInfoEXT, VkGeneratedCommandsPipelineInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkGeneratedCommandsMemoryRequirementsInfoEXT, VkGeneratedCommandsShaderInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkGeneratedCommandsMemoryRequirementsInfoEXT, VkGeneratedCommandsShaderInfoEXT, VkGeneratedCommandsShaderInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkGeneratedCommandsMemoryRequirementsInfoEXT, VkGeneratedCommandsShaderInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

#endif // VK_EXT_device_generated_commands
}

TEST(pnext_chain, generated_commands_info_ext)
{
#if defined(VK_EXT_device_generated_commands) 
    
    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkGeneratedCommandsInfoEXT, VkGeneratedCommandsPipelineInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkGeneratedCommandsInfoEXT, VkGeneratedCommandsPipelineInfoEXT, VkGeneratedCommandsPipelineInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkGeneratedCommandsInfoEXT, VkGeneratedCommandsPipelineInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((can_extend_v<VkGeneratedCommandsInfoEXT, VkGeneratedCommandsShaderInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_FALSE((can_extend_v<VkGeneratedCommandsInfoEXT, VkGeneratedCommandsShaderInfoEXT, VkGeneratedCommandsShaderInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_device_generated_commands)
        STATIC_EXPECT_TRUE((chain_compatible<VkGeneratedCommandsInfoEXT, VkGeneratedCommandsShaderInfoEXT>));
    #endif // defined(VK_EXT_device_generated_commands)

#endif // VK_EXT_device_generated_commands
}

TEST(pnext_chain, indirect_commands_layout_create_info_ext)
{
#if defined(VK_EXT_device_generated_commands) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkIndirectCommandsLayoutCreateInfoEXT, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkIndirectCommandsLayoutCreateInfoEXT, VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkIndirectCommandsLayoutCreateInfoEXT, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

#endif // VK_EXT_device_generated_commands
}

TEST(pnext_chain, memory_barrier2)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, image_memory_barrier2)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageMemoryBarrier2, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageMemoryBarrier2, VkExternalMemoryAcquireUnmodifiedEXT, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageMemoryBarrier2, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((can_extend_v<VkImageMemoryBarrier2, VkSampleLocationsInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_FALSE((can_extend_v<VkImageMemoryBarrier2, VkSampleLocationsInfoEXT, VkSampleLocationsInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_sample_locations)
        STATIC_EXPECT_TRUE((chain_compatible<VkImageMemoryBarrier2, VkSampleLocationsInfoEXT>));
    #endif // defined(VK_EXT_sample_locations)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, buffer_memory_barrier2)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_maintenance8)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferMemoryBarrier2, VkMemoryBarrierAccessFlags3KHR>));
    #endif // defined(VK_KHR_maintenance8)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((can_extend_v<VkBufferMemoryBarrier2, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_FALSE((can_extend_v<VkBufferMemoryBarrier2, VkExternalMemoryAcquireUnmodifiedEXT, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

    #if defined(VK_EXT_external_memory_acquire_unmodified)
        STATIC_EXPECT_TRUE((chain_compatible<VkBufferMemoryBarrier2, VkExternalMemoryAcquireUnmodifiedEXT>));
    #endif // defined(VK_EXT_external_memory_acquire_unmodified)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, command_buffer_submit_info)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((can_extend_v<VkCommandBufferSubmitInfo, VkRenderPassStripeSubmitInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_FALSE((can_extend_v<VkCommandBufferSubmitInfo, VkRenderPassStripeSubmitInfoARM, VkRenderPassStripeSubmitInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((chain_compatible<VkCommandBufferSubmitInfo, VkRenderPassStripeSubmitInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, submit_info2)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo2, VkLatencySubmissionPresentIdNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo2, VkLatencySubmissionPresentIdNV, VkLatencySubmissionPresentIdNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_NV_low_latency2)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo2, VkLatencySubmissionPresentIdNV>));
    #endif // defined(VK_NV_low_latency2)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo2, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo2, VkFrameBoundaryEXT, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_EXT_frame_boundary)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo2, VkFrameBoundaryEXT>));
    #endif // defined(VK_EXT_frame_boundary)

    #if defined(VK_KHR_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo2, VkWin32KeyedMutexAcquireReleaseInfoKHR>));
    #endif // defined(VK_KHR_win32_keyed_mutex)

    #if defined(VK_KHR_win32_keyed_mutex)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo2, VkWin32KeyedMutexAcquireReleaseInfoKHR, VkWin32KeyedMutexAcquireReleaseInfoKHR>));
    #endif // defined(VK_KHR_win32_keyed_mutex)

    #if defined(VK_KHR_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo2, VkWin32KeyedMutexAcquireReleaseInfoKHR>));
    #endif // defined(VK_KHR_win32_keyed_mutex)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo2, VkPerformanceQuerySubmitInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo2, VkPerformanceQuerySubmitInfoKHR, VkPerformanceQuerySubmitInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_KHR_performance_query)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo2, VkPerformanceQuerySubmitInfoKHR>));
    #endif // defined(VK_KHR_performance_query)

    #if defined(VK_NV_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubmitInfo2, VkWin32KeyedMutexAcquireReleaseInfoNV>));
    #endif // defined(VK_NV_win32_keyed_mutex)

    #if defined(VK_NV_win32_keyed_mutex)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubmitInfo2, VkWin32KeyedMutexAcquireReleaseInfoNV, VkWin32KeyedMutexAcquireReleaseInfoNV>));
    #endif // defined(VK_NV_win32_keyed_mutex)

    #if defined(VK_NV_win32_keyed_mutex)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubmitInfo2, VkWin32KeyedMutexAcquireReleaseInfoNV>));
    #endif // defined(VK_NV_win32_keyed_mutex)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, physical_device_video_format_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkPhysicalDeviceVideoFormatInfoKHR, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkPhysicalDeviceVideoFormatInfoKHR, VkVideoProfileListInfoKHR, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

    #if defined(VK_KHR_video_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkPhysicalDeviceVideoFormatInfoKHR, VkVideoProfileListInfoKHR>));
    #endif // defined(VK_KHR_video_queue)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_format_properties_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoFormatPropertiesKHR, VkVideoFormatAV1QuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoFormatPropertiesKHR, VkVideoFormatAV1QuantizationMapPropertiesKHR, VkVideoFormatAV1QuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoFormatPropertiesKHR, VkVideoFormatAV1QuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoFormatPropertiesKHR, VkVideoFormatH265QuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoFormatPropertiesKHR, VkVideoFormatH265QuantizationMapPropertiesKHR, VkVideoFormatH265QuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoFormatPropertiesKHR, VkVideoFormatH265QuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoFormatPropertiesKHR, VkVideoFormatQuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoFormatPropertiesKHR, VkVideoFormatQuantizationMapPropertiesKHR, VkVideoFormatQuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoFormatPropertiesKHR, VkVideoFormatQuantizationMapPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_profile_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeUsageInfoKHR, VkVideoDecodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoDecodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeH264ProfileInfoKHR, VkVideoDecodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoDecodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeH265ProfileInfoKHR, VkVideoDecodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoDecodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeUsageInfoKHR, VkVideoEncodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoEncodeUsageInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeH265ProfileInfoKHR, VkVideoEncodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoEncodeH265ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoDecodeAV1ProfileInfoKHR, VkVideoDecodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoDecodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeAV1ProfileInfoKHR, VkVideoEncodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoEncodeAV1ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoProfileInfoKHR, VkVideoEncodeH264ProfileInfoKHR, VkVideoEncodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoProfileInfoKHR, VkVideoEncodeH264ProfileInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_capabilities_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeH265CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeH265CapabilitiesKHR, VkVideoDecodeH265CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoDecodeH265CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeAV1CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeAV1CapabilitiesKHR, VkVideoEncodeAV1CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeAV1CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeH264CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeH264CapabilitiesKHR, VkVideoDecodeH264CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoDecodeH264CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeCapabilitiesKHR, VkVideoDecodeCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_decode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoDecodeCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_queue)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH264QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH264QuantizationMapCapabilitiesKHR, VkVideoEncodeH264QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeH264QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeQuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeQuantizationMapCapabilitiesKHR, VkVideoEncodeQuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeQuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeCapabilitiesKHR, VkVideoEncodeCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH265CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH265CapabilitiesKHR, VkVideoEncodeH265CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeH265CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeAV1QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeAV1QuantizationMapCapabilitiesKHR, VkVideoEncodeAV1QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeAV1QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH264CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH264CapabilitiesKHR, VkVideoEncodeH264CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeH264CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeAV1CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoDecodeAV1CapabilitiesKHR, VkVideoDecodeAV1CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoDecodeAV1CapabilitiesKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH265QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCapabilitiesKHR, VkVideoEncodeH265QuantizationMapCapabilitiesKHR, VkVideoEncodeH265QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCapabilitiesKHR, VkVideoEncodeH265QuantizationMapCapabilitiesKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_reference_slot_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoEncodeH265DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoEncodeH265DpbSlotInfoKHR, VkVideoEncodeH265DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoReferenceSlotInfoKHR, VkVideoEncodeH265DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoDecodeH264DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoDecodeH264DpbSlotInfoKHR, VkVideoDecodeH264DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoReferenceSlotInfoKHR, VkVideoDecodeH264DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoEncodeH264DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoEncodeH264DpbSlotInfoKHR, VkVideoEncodeH264DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoReferenceSlotInfoKHR, VkVideoEncodeH264DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoEncodeAV1DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoEncodeAV1DpbSlotInfoKHR, VkVideoEncodeAV1DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoReferenceSlotInfoKHR, VkVideoEncodeAV1DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoDecodeH265DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoDecodeH265DpbSlotInfoKHR, VkVideoDecodeH265DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoReferenceSlotInfoKHR, VkVideoDecodeH265DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoDecodeAV1DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoReferenceSlotInfoKHR, VkVideoDecodeAV1DpbSlotInfoKHR, VkVideoDecodeAV1DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoReferenceSlotInfoKHR, VkVideoDecodeAV1DpbSlotInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_decode_info_khr)
{
#if defined(VK_KHR_video_decode_queue) 
    
    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoInlineQueryInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoInlineQueryInfoKHR, VkVideoInlineQueryInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoDecodeInfoKHR, VkVideoInlineQueryInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeAV1PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeAV1PictureInfoKHR, VkVideoDecodeAV1PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoDecodeInfoKHR, VkVideoDecodeAV1PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH265PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH265PictureInfoKHR, VkVideoDecodeH265PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoDecodeInfoKHR, VkVideoDecodeH265PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeAV1InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeAV1InlineSessionParametersInfoKHR, VkVideoDecodeAV1InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoDecodeInfoKHR, VkVideoDecodeAV1InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH264InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH264InlineSessionParametersInfoKHR, VkVideoDecodeH264InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoDecodeInfoKHR, VkVideoDecodeH264InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH264PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH264PictureInfoKHR, VkVideoDecodeH264PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoDecodeInfoKHR, VkVideoDecodeH264PictureInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH265InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoDecodeInfoKHR, VkVideoDecodeH265InlineSessionParametersInfoKHR, VkVideoDecodeH265InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

    #if defined(VK_KHR_video_maintenance2)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoDecodeInfoKHR, VkVideoDecodeH265InlineSessionParametersInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance2)

#endif // VK_KHR_video_decode_queue
}

TEST(pnext_chain, video_session_create_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionCreateInfoKHR, VkVideoEncodeAV1SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionCreateInfoKHR, VkVideoEncodeAV1SessionCreateInfoKHR, VkVideoEncodeAV1SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionCreateInfoKHR, VkVideoEncodeAV1SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionCreateInfoKHR, VkVideoEncodeH264SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionCreateInfoKHR, VkVideoEncodeH264SessionCreateInfoKHR, VkVideoEncodeH264SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionCreateInfoKHR, VkVideoEncodeH264SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionCreateInfoKHR, VkVideoEncodeH265SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionCreateInfoKHR, VkVideoEncodeH265SessionCreateInfoKHR, VkVideoEncodeH265SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionCreateInfoKHR, VkVideoEncodeH265SessionCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_session_parameters_create_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR, VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeQualityLevelInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeQualityLevelInfoKHR, VkVideoEncodeQualityLevelInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeQualityLevelInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeH265SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeH265SessionParametersCreateInfoKHR, VkVideoDecodeH265SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeH265SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeH264SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeH264SessionParametersCreateInfoKHR, VkVideoEncodeH264SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeH264SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeH265SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeH265SessionParametersCreateInfoKHR, VkVideoEncodeH265SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeH265SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeAV1SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeAV1SessionParametersCreateInfoKHR, VkVideoDecodeAV1SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeAV1SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_av1)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeH264SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeH264SessionParametersCreateInfoKHR, VkVideoDecodeH264SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoDecodeH264SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeAV1SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeAV1SessionParametersCreateInfoKHR, VkVideoEncodeAV1SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersCreateInfoKHR, VkVideoEncodeAV1SessionParametersCreateInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_session_parameters_update_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoEncodeH264SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoEncodeH264SessionParametersAddInfoKHR, VkVideoEncodeH264SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersUpdateInfoKHR, VkVideoEncodeH264SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoEncodeH265SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoEncodeH265SessionParametersAddInfoKHR, VkVideoEncodeH265SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersUpdateInfoKHR, VkVideoEncodeH265SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoDecodeH264SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoDecodeH264SessionParametersAddInfoKHR, VkVideoDecodeH264SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersUpdateInfoKHR, VkVideoDecodeH264SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h264)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoDecodeH265SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoSessionParametersUpdateInfoKHR, VkVideoDecodeH265SessionParametersAddInfoKHR, VkVideoDecodeH265SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

    #if defined(VK_KHR_video_decode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoSessionParametersUpdateInfoKHR, VkVideoDecodeH265SessionParametersAddInfoKHR>));
    #endif // defined(VK_KHR_video_decode_h265)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_encode_session_parameters_get_info_khr)
{
#if defined(VK_KHR_video_encode_queue) 
    
    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeSessionParametersGetInfoKHR, VkVideoEncodeH264SessionParametersGetInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeSessionParametersGetInfoKHR, VkVideoEncodeH264SessionParametersGetInfoKHR, VkVideoEncodeH264SessionParametersGetInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeSessionParametersGetInfoKHR, VkVideoEncodeH264SessionParametersGetInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeSessionParametersGetInfoKHR, VkVideoEncodeH265SessionParametersGetInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeSessionParametersGetInfoKHR, VkVideoEncodeH265SessionParametersGetInfoKHR, VkVideoEncodeH265SessionParametersGetInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeSessionParametersGetInfoKHR, VkVideoEncodeH265SessionParametersGetInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

#endif // VK_KHR_video_encode_queue
}

TEST(pnext_chain, video_encode_session_parameters_feedback_info_khr)
{
#if defined(VK_KHR_video_encode_queue) 
    
    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeSessionParametersFeedbackInfoKHR, VkVideoEncodeH265SessionParametersFeedbackInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeSessionParametersFeedbackInfoKHR, VkVideoEncodeH265SessionParametersFeedbackInfoKHR, VkVideoEncodeH265SessionParametersFeedbackInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeSessionParametersFeedbackInfoKHR, VkVideoEncodeH265SessionParametersFeedbackInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeSessionParametersFeedbackInfoKHR, VkVideoEncodeH264SessionParametersFeedbackInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeSessionParametersFeedbackInfoKHR, VkVideoEncodeH264SessionParametersFeedbackInfoKHR, VkVideoEncodeH264SessionParametersFeedbackInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeSessionParametersFeedbackInfoKHR, VkVideoEncodeH264SessionParametersFeedbackInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

#endif // VK_KHR_video_encode_queue
}

TEST(pnext_chain, video_begin_coding_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH265GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH265GopRemainingFrameInfoKHR, VkVideoEncodeH265GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoBeginCodingInfoKHR, VkVideoEncodeH265GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH264RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH264RateControlInfoKHR, VkVideoEncodeH264RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoBeginCodingInfoKHR, VkVideoEncodeH264RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeAV1GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeAV1GopRemainingFrameInfoKHR, VkVideoEncodeAV1GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoBeginCodingInfoKHR, VkVideoEncodeAV1GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH264GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH264GopRemainingFrameInfoKHR, VkVideoEncodeH264GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoBeginCodingInfoKHR, VkVideoEncodeH264GopRemainingFrameInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH265RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeH265RateControlInfoKHR, VkVideoEncodeH265RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoBeginCodingInfoKHR, VkVideoEncodeH265RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeAV1RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeAV1RateControlInfoKHR, VkVideoEncodeAV1RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoBeginCodingInfoKHR, VkVideoEncodeAV1RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeRateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoBeginCodingInfoKHR, VkVideoEncodeRateControlInfoKHR, VkVideoEncodeRateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoBeginCodingInfoKHR, VkVideoEncodeRateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_coding_control_info_khr)
{
#if defined(VK_KHR_video_queue) 
    
    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeQualityLevelInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeQualityLevelInfoKHR, VkVideoEncodeQualityLevelInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCodingControlInfoKHR, VkVideoEncodeQualityLevelInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeH264RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeH264RateControlInfoKHR, VkVideoEncodeH264RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCodingControlInfoKHR, VkVideoEncodeH264RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeH265RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeH265RateControlInfoKHR, VkVideoEncodeH265RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCodingControlInfoKHR, VkVideoEncodeH265RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeAV1RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeAV1RateControlInfoKHR, VkVideoEncodeAV1RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCodingControlInfoKHR, VkVideoEncodeAV1RateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeRateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoCodingControlInfoKHR, VkVideoEncodeRateControlInfoKHR, VkVideoEncodeRateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

    #if defined(VK_KHR_video_encode_queue)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoCodingControlInfoKHR, VkVideoEncodeRateControlInfoKHR>));
    #endif // defined(VK_KHR_video_encode_queue)

#endif // VK_KHR_video_queue
}

TEST(pnext_chain, video_encode_info_khr)
{
#if defined(VK_KHR_video_encode_queue) 
    
    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoInlineQueryInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoInlineQueryInfoKHR, VkVideoInlineQueryInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_maintenance1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeInfoKHR, VkVideoInlineQueryInfoKHR>));
    #endif // defined(VK_KHR_video_maintenance1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeAV1PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeAV1PictureInfoKHR, VkVideoEncodeAV1PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeInfoKHR, VkVideoEncodeAV1PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeQuantizationMapInfoKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeQuantizationMapInfoKHR, VkVideoEncodeQuantizationMapInfoKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_quantization_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeInfoKHR, VkVideoEncodeQuantizationMapInfoKHR>));
    #endif // defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeH264PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeH264PictureInfoKHR, VkVideoEncodeH264PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeInfoKHR, VkVideoEncodeH264PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeH265PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeInfoKHR, VkVideoEncodeH265PictureInfoKHR, VkVideoEncodeH265PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeInfoKHR, VkVideoEncodeH265PictureInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

#endif // VK_KHR_video_encode_queue
}

TEST(pnext_chain, video_encode_quality_level_properties_khr)
{
#if defined(VK_KHR_video_encode_queue) 
    
    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeH265QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeH265QualityLevelPropertiesKHR, VkVideoEncodeH265QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeH265QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeAV1QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeAV1QualityLevelPropertiesKHR, VkVideoEncodeAV1QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeAV1QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeH264QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeH264QualityLevelPropertiesKHR, VkVideoEncodeH264QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeQualityLevelPropertiesKHR, VkVideoEncodeH264QualityLevelPropertiesKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

#endif // VK_KHR_video_encode_queue
}

TEST(pnext_chain, video_encode_rate_control_layer_info_khr)
{
#if defined(VK_KHR_video_encode_queue) 
    
    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeH265RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeH265RateControlLayerInfoKHR, VkVideoEncodeH265RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h265)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeH265RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h265)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeH264RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeH264RateControlLayerInfoKHR, VkVideoEncodeH264RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_h264)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeH264RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_h264)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((can_extend_v<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeAV1RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_FALSE((can_extend_v<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeAV1RateControlLayerInfoKHR, VkVideoEncodeAV1RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

    #if defined(VK_KHR_video_encode_av1)
        STATIC_EXPECT_TRUE((chain_compatible<VkVideoEncodeRateControlLayerInfoKHR, VkVideoEncodeAV1RateControlLayerInfoKHR>));
    #endif // defined(VK_KHR_video_encode_av1)

#endif // VK_KHR_video_encode_queue
}

TEST(pnext_chain, cu_module_create_info_nvx)
{
#if defined(VK_NVX_binary_import) 
    
    #if defined(VK_NVX_binary_import)
        STATIC_EXPECT_TRUE((can_extend_v<VkCuModuleCreateInfoNVX, VkCuModuleTexturingModeCreateInfoNVX>));
    #endif // defined(VK_NVX_binary_import)

    #if defined(VK_NVX_binary_import)
        STATIC_EXPECT_FALSE((can_extend_v<VkCuModuleCreateInfoNVX, VkCuModuleTexturingModeCreateInfoNVX, VkCuModuleTexturingModeCreateInfoNVX>));
    #endif // defined(VK_NVX_binary_import)

    #if defined(VK_NVX_binary_import)
        STATIC_EXPECT_TRUE((chain_compatible<VkCuModuleCreateInfoNVX, VkCuModuleTexturingModeCreateInfoNVX>));
    #endif // defined(VK_NVX_binary_import)

#endif // VK_NVX_binary_import
}

TEST(pnext_chain, descriptor_buffer_binding_info_ext)
{
#if defined(VK_EXT_descriptor_buffer) 
    
    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorBufferBindingInfoEXT, VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorBufferBindingInfoEXT, VkDescriptorBufferBindingPushDescriptorBufferHandleEXT, VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_descriptor_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorBufferBindingInfoEXT, VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>));
    #endif // defined(VK_EXT_descriptor_buffer)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkDescriptorBufferBindingInfoEXT, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkDescriptorBufferBindingInfoEXT, VkBufferUsageFlags2CreateInfo, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkDescriptorBufferBindingInfoEXT, VkBufferUsageFlags2CreateInfo>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_EXT_descriptor_buffer
}

TEST(pnext_chain, rendering_info)
{
#if defined(VK_VERSION_1_3) 
    
    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderingInfo, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderingInfo, VkMultiviewPerViewAttributesInfoNVX, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_NVX_multiview_per_view_attributes)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderingInfo, VkMultiviewPerViewAttributesInfoNVX>));
    #endif // defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderingInfo, VkMultisampledRenderToSingleSampledInfoEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderingInfo, VkMultisampledRenderToSingleSampledInfoEXT, VkMultisampledRenderToSingleSampledInfoEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderingInfo, VkMultisampledRenderToSingleSampledInfoEXT>));
    #endif // defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderingInfo, VkRenderPassStripeBeginInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderingInfo, VkRenderPassStripeBeginInfoARM, VkRenderPassStripeBeginInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_ARM_render_pass_striped)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderingInfo, VkRenderPassStripeBeginInfoARM>));
    #endif // defined(VK_ARM_render_pass_striped)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderingInfo, VkRenderingFragmentShadingRateAttachmentInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderingInfo, VkRenderingFragmentShadingRateAttachmentInfoKHR, VkRenderingFragmentShadingRateAttachmentInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_KHR_fragment_shading_rate)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderingInfo, VkRenderingFragmentShadingRateAttachmentInfoKHR>));
    #endif // defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderingInfo, VkRenderingFragmentDensityMapAttachmentInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderingInfo, VkRenderingFragmentDensityMapAttachmentInfoEXT, VkRenderingFragmentDensityMapAttachmentInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_EXT_fragment_density_map)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderingInfo, VkRenderingFragmentDensityMapAttachmentInfoEXT>));
    #endif // defined(VK_EXT_fragment_density_map)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderingInfo, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderingInfo, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderingInfo, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>));
    #endif // defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((can_extend_v<VkRenderingInfo, VkDeviceGroupRenderPassBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_FALSE((can_extend_v<VkRenderingInfo, VkDeviceGroupRenderPassBeginInfo, VkDeviceGroupRenderPassBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        STATIC_EXPECT_TRUE((chain_compatible<VkRenderingInfo, VkDeviceGroupRenderPassBeginInfo>));
    #endif // defined(VK_VERSION_1_1)

#endif // VK_VERSION_1_3
}

TEST(pnext_chain, subresource_layout2)
{
#if defined(VK_VERSION_1_4) 
    
    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubresourceLayout2, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubresourceLayout2, VkImageCompressionPropertiesEXT, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_image_compression_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubresourceLayout2, VkImageCompressionPropertiesEXT>));
    #endif // defined(VK_EXT_image_compression_control)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((can_extend_v<VkSubresourceLayout2, VkSubresourceHostMemcpySize>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_FALSE((can_extend_v<VkSubresourceLayout2, VkSubresourceHostMemcpySize, VkSubresourceHostMemcpySize>));
    #endif // defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        STATIC_EXPECT_TRUE((chain_compatible<VkSubresourceLayout2, VkSubresourceHostMemcpySize>));
    #endif // defined(VK_VERSION_1_4)

#endif // VK_VERSION_1_4
}

TEST(pnext_chain, export_metal_objects_info_ext)
{
#if defined(VK_EXT_metal_objects) 
    
    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkExportMetalObjectsInfoEXT, VkExportMetalBufferInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkExportMetalObjectsInfoEXT, VkExportMetalBufferInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkExportMetalObjectsInfoEXT, VkExportMetalTextureInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkExportMetalObjectsInfoEXT, VkExportMetalTextureInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkExportMetalObjectsInfoEXT, VkExportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkExportMetalObjectsInfoEXT, VkExportMetalSharedEventInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkExportMetalObjectsInfoEXT, VkExportMetalDeviceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_FALSE((can_extend_v<VkExportMetalObjectsInfoEXT, VkExportMetalDeviceInfoEXT, VkExportMetalDeviceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkExportMetalObjectsInfoEXT, VkExportMetalDeviceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkExportMetalObjectsInfoEXT, VkExportMetalIOSurfaceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkExportMetalObjectsInfoEXT, VkExportMetalIOSurfaceInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((can_extend_v<VkExportMetalObjectsInfoEXT, VkExportMetalCommandQueueInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
        STATIC_EXPECT_TRUE((chain_compatible<VkExportMetalObjectsInfoEXT, VkExportMetalCommandQueueInfoEXT>));
    #endif // defined(VK_EXT_metal_objects)

#endif // VK_EXT_metal_objects
}

TEST(pnext_chain, optical_flow_session_create_info_nv)
{
#if defined(VK_NV_optical_flow) 
    
    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((can_extend_v<VkOpticalFlowSessionCreateInfoNV, VkOpticalFlowSessionCreatePrivateDataInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_FALSE((can_extend_v<VkOpticalFlowSessionCreateInfoNV, VkOpticalFlowSessionCreatePrivateDataInfoNV, VkOpticalFlowSessionCreatePrivateDataInfoNV>));
    #endif // defined(VK_NV_optical_flow)

    #if defined(VK_NV_optical_flow)
        STATIC_EXPECT_TRUE((chain_compatible<VkOpticalFlowSessionCreateInfoNV, VkOpticalFlowSessionCreatePrivateDataInfoNV>));
    #endif // defined(VK_NV_optical_flow)

#endif // VK_NV_optical_flow
}

TEST(pnext_chain, depth_bias_info_ext)
{
#if defined(VK_EXT_depth_bias_control) 
    
    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkDepthBiasInfoEXT, VkDepthBiasRepresentationInfoEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkDepthBiasInfoEXT, VkDepthBiasRepresentationInfoEXT, VkDepthBiasRepresentationInfoEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

    #if defined(VK_EXT_depth_bias_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkDepthBiasInfoEXT, VkDepthBiasRepresentationInfoEXT>));
    #endif // defined(VK_EXT_depth_bias_control)

#endif // VK_EXT_depth_bias_control
}

TEST(pnext_chain, memory_map_info)
{
#if defined(VK_VERSION_1_4) 
    
    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((can_extend_v<VkMemoryMapInfo, VkMemoryMapPlacedInfoEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_FALSE((can_extend_v<VkMemoryMapInfo, VkMemoryMapPlacedInfoEXT, VkMemoryMapPlacedInfoEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

    #if defined(VK_EXT_map_memory_placed)
        STATIC_EXPECT_TRUE((chain_compatible<VkMemoryMapInfo, VkMemoryMapPlacedInfoEXT>));
    #endif // defined(VK_EXT_map_memory_placed)

#endif // VK_VERSION_1_4
}

TEST(pnext_chain, shader_create_info_ext)
{
#if defined(VK_EXT_shader_object) 
    
    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkShaderCreateInfoEXT, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkShaderCreateInfoEXT, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkShaderCreateInfoEXT, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_TRUE((can_extend_v<VkShaderCreateInfoEXT, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_FALSE((can_extend_v<VkShaderCreateInfoEXT, VkValidationFeaturesEXT, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

    #if defined(VK_EXT_validation_features)
        STATIC_EXPECT_TRUE((chain_compatible<VkShaderCreateInfoEXT, VkValidationFeaturesEXT>));
    #endif // defined(VK_EXT_validation_features)

#endif // VK_EXT_shader_object
}

TEST(pnext_chain, screen_buffer_properties_qnx)
{
#if defined(VK_QNX_external_memory_screen_buffer) 
    
    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((can_extend_v<VkScreenBufferPropertiesQNX, VkScreenBufferFormatPropertiesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_FALSE((can_extend_v<VkScreenBufferPropertiesQNX, VkScreenBufferFormatPropertiesQNX, VkScreenBufferFormatPropertiesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
        STATIC_EXPECT_TRUE((chain_compatible<VkScreenBufferPropertiesQNX, VkScreenBufferFormatPropertiesQNX>));
    #endif // defined(VK_QNX_external_memory_screen_buffer)

#endif // VK_QNX_external_memory_screen_buffer
}

TEST(pnext_chain, execution_graph_pipeline_create_info_amdx)
{
#if defined(VK_AMDX_shader_enqueue) 
    
    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((can_extend_v<VkExecutionGraphPipelineCreateInfoAMDX, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_FALSE((can_extend_v<VkExecutionGraphPipelineCreateInfoAMDX, VkPipelineCreationFeedbackCreateInfo, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        STATIC_EXPECT_TRUE((chain_compatible<VkExecutionGraphPipelineCreateInfoAMDX, VkPipelineCreationFeedbackCreateInfo>));
    #endif // defined(VK_VERSION_1_3)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_TRUE((can_extend_v<VkExecutionGraphPipelineCreateInfoAMDX, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_FALSE((can_extend_v<VkExecutionGraphPipelineCreateInfoAMDX, VkPipelineCompilerControlCreateInfoAMD, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_AMD_pipeline_compiler_control)
        STATIC_EXPECT_TRUE((chain_compatible<VkExecutionGraphPipelineCreateInfoAMDX, VkPipelineCompilerControlCreateInfoAMD>));
    #endif // defined(VK_AMD_pipeline_compiler_control)

#endif // VK_AMDX_shader_enqueue
}

TEST(pnext_chain, bind_descriptor_sets_info)
{
#if defined(VK_VERSION_1_4) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindDescriptorSetsInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindDescriptorSetsInfo, VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindDescriptorSetsInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

#endif // VK_VERSION_1_4
}

TEST(pnext_chain, push_constants_info)
{
#if defined(VK_VERSION_1_4) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkPushConstantsInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkPushConstantsInfo, VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkPushConstantsInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

#endif // VK_VERSION_1_4
}

TEST(pnext_chain, push_descriptor_set_info)
{
#if defined(VK_VERSION_1_4) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkPushDescriptorSetInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkPushDescriptorSetInfo, VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkPushDescriptorSetInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

#endif // VK_VERSION_1_4
}

TEST(pnext_chain, push_descriptor_set_with_template_info)
{
#if defined(VK_VERSION_1_4) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkPushDescriptorSetWithTemplateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkPushDescriptorSetWithTemplateInfo, VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkPushDescriptorSetWithTemplateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

#endif // VK_VERSION_1_4
}

TEST(pnext_chain, set_descriptor_buffer_offsets_info_ext)
{
#if defined(VK_KHR_maintenance6) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkSetDescriptorBufferOffsetsInfoEXT, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkSetDescriptorBufferOffsetsInfoEXT, VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkSetDescriptorBufferOffsetsInfoEXT, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

#endif // VK_KHR_maintenance6
}

TEST(pnext_chain, bind_descriptor_buffer_embedded_samplers_info_ext)
{
#if defined(VK_KHR_maintenance6) 
    
    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((can_extend_v<VkBindDescriptorBufferEmbeddedSamplersInfoEXT, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_FALSE((can_extend_v<VkBindDescriptorBufferEmbeddedSamplersInfoEXT, VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        STATIC_EXPECT_TRUE((chain_compatible<VkBindDescriptorBufferEmbeddedSamplersInfoEXT, VkPipelineLayoutCreateInfo>));
    #endif // defined(VK_VERSION_1_0)

#endif // VK_KHR_maintenance6
}

#undef STATIC_EXPECT_TRUE
#undef STATIC_EXPECT_FALSE

} // anonymous namespace
// clang-format on
