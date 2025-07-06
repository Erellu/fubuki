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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PHYSICAL_DEVICE_FEATURES2_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PHYSICAL_DEVICE_FEATURES2_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_1)

template<typename structure_type>
struct chain_validator<VkPhysicalDeviceFeatures2, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_NV_optical_flow)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpticalFlowFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_KHR_ray_tracing_maintenance1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGlobalPriorityQueryFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_texel_buffer_alignment)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_KHR_portability_subset)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePortabilitySubsetFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_portability_subset)

    #if defined(VK_NV_cooperative_matrix2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_matrix2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupRotateFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_NV_shader_sm_builtins)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shader_sm_builtins)

    #if defined(VK_KHR_maintenance8)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance8FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_video_encode_quantization_map)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_NV_cooperative_vector)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeVectorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_vector)

    #if defined(VK_EXT_non_seamless_cube_map)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_EXT_mutable_descriptor_type)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_NV_displacement_micromap)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDisplacementMicromapFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_displacement_micromap)

    #if defined(VK_EXT_device_fault)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFaultFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_fault)

    #if defined(VK_KHR_video_encode_av1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_encode_av1)

    #if defined(VK_QCOM_image_processing2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessing2FeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_image_processing2)

    #if defined(VK_NV_corner_sampled_image)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCornerSampledImageFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_corner_sampled_image)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInlineUniformBlockFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_4444_formats)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevice4444FormatsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_4444_formats)

    #if defined(VK_EXT_device_generated_commands)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_shader_module_identifier)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_subpass_merge_feedback)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevice16BitStorageFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan12Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance6Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_astc_decode_mode)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceASTCDecodeFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_astc_decode_mode)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostImageCopyFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_fragment_density_map2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_density_map2)

    #if defined(VK_NV_external_memory_rdma)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_rdma)

    #if defined(VK_EXT_depth_clip_enable)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipEnableFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_multi_draw)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiDrawFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_shader_atomic_float)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_atomic_float)

    #if defined(VK_NV_memory_decompression)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryDecompressionFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_memory_decompression)

    #if defined(VK_EXT_color_write_enable)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceColorWriteEnableFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_color_write_enable)

    #if defined(VK_NV_present_metering)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentMeteringFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_present_metering)

    #if defined(VK_NV_shader_image_footprint)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageFootprintFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shader_image_footprint)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_external_sci_sync2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSync2FeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_sci_sync2)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan13Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_external_sci_sync)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalSciSyncFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_sci_sync)

    #if defined(VK_AMD_device_coherent_memory)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoherentMemoryFeaturesAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_device_coherent_memory)

    #if defined(VK_KHR_fragment_shading_rate)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_EXT_conditional_rendering)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceConditionalRenderingFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_image_compression_control_swapchain)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_EXT_device_address_binding_report)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAddressBindingReportFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_address_binding_report)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderExpectAssumeFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_HUAWEI_subpass_shading)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_KHR_ray_query)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayQueryFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_query)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSamplerYcbcrConversionFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_rasterization_order_attachment_access)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_ray_tracing_validation)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingValidationFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_validation)

    #if defined(VK_ARM_render_pass_striped)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRenderPassStripedFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_render_pass_striped)

    #if defined(VK_KHR_performance_query)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerformanceQueryFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_performance_query)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineProtectedAccessFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_depth_bias_control)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthBiasControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_bias_control)

    #if defined(VK_NV_linear_color_attachment)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_linear_color_attachment)

    #if defined(VK_NV_extended_sparse_address_space)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_EXT_custom_border_color)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCustomBorderColorFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_custom_border_color)

    #if defined(VK_QNX_external_memory_screen_buffer)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_SEC_amigo_profiling)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAmigoProfilingFeaturesSEC>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_SEC_amigo_profiling)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan11Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_cooperative_matrix)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_matrix)

    #if defined(VK_EXT_fragment_shader_interlock)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_EXT_image_view_min_lod)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageViewMinLodFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_view_min_lod)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineRobustnessFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVariablePointersFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_QCOM_filter_cubic_clamp)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicClampFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VK_EXT_vertex_input_dynamic_state)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_NV_coverage_reduction_mode)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCoverageReductionModeFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_EXT_provoking_vertex)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProvokingVertexFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_provoking_vertex)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_map_memory_placed)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_map_memory_placed)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTimelineSemaphoreFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_present_barrier)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentBarrierFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_present_barrier)

    #if defined(VK_NV_device_diagnostics_config)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_diagnostics_config)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_EXT_extended_dynamic_state)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_NV_device_generated_commands_compute)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_QCOM_image_processing)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageProcessingFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_image_processing)

    #if defined(VK_EXT_pipeline_properties)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelinePropertiesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_pipeline_properties)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanMemoryModelFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_inherited_viewport_scissor)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_EXT_shader_object)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderObjectFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_object)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevice8BitStorageFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_mesh_shader)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_mesh_shader)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_EXT_ycbcr_image_arrays)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_ARM_shader_core_builtins)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_shader_core_builtins)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineCreationCacheControlFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_blend_operation_advanced)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_KHR_fragment_shader_barycentric)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_EXT_extended_dynamic_state3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_descriptor_buffer)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorBufferFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_nested_command_buffer)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_nested_command_buffer)

    #if defined(VK_NV_raw_access_chains)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRawAccessChainsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_raw_access_chains)

    #if defined(VK_KHR_ray_tracing_position_fetch)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_KHR_shader_quad_control)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderQuadControlFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_quad_control)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHostQueryResetFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_ANDROID_external_format_resolve)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_KHR_pipeline_binary)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineBinaryFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_binary)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrivateDataFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_vertex_attribute_robustness)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_image_compression_control)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageCompressionControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_compression_control)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageRobustnessFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_KHR_shader_clock)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderClockFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_clock)

    #if defined(VK_NV_external_memory_sci_buf)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkan14Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_depth_clamp_control)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_clamp_control)

    #if defined(VK_NV_representative_fragment_test)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_representative_fragment_test)

    #if defined(VK_EXT_shader_tile_image)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTileImageFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_tile_image)

    #if defined(VK_KHR_depth_clamp_zero_one)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_QCOM_tile_properties)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTilePropertiesFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_tile_properties)

    #if defined(VK_HUAWEI_invocation_mask)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_memory_priority)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMemoryPriorityFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_memory_priority)

    #if defined(VK_NV_device_generated_commands)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_generated_commands)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceProtectedMemoryFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_KHR_present_id)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentIdFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_present_id)

    #if defined(VK_NV_scissor_exclusive)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExclusiveScissorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_partitioned_acceleration_structure)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_image_2d_view_of_3d)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_NV_command_buffer_inheritance)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLineRasterizationFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSynchronization2Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VK_EXT_fragment_density_map)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_density_map)

    #if defined(VK_NV_descriptor_pool_overallocation)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVertexAttributeDivisorFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_mesh_shader)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMeshShaderFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_mesh_shader)

    #if defined(VK_EXT_robustness2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRobustness2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_robustness2)

    #if defined(VK_EXT_opacity_micromap)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceOpacityMicromapFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_QCOM_ycbcr_degamma)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_filter_cubic_weights)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCubicWeightsFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_IMG_relaxed_line_rasterization)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_KHR_video_maintenance2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_maintenance2)

    #if defined(VK_EXT_frame_boundary)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFrameBoundaryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_frame_boundary)

    #if defined(VK_KHR_pipeline_executable_properties)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_EXT_pipeline_library_group_handles)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_EXT_transform_feedback)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceTransformFeedbackFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_transform_feedback)

    #if defined(VK_EXT_pageable_device_local_memory)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance4Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSubgroupSizeControlFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_ray_tracing_motion_blur)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_cuda_kernel_launch)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_MESA_image_alignment_control)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_MESA_image_alignment_control)

    #if defined(VK_HUAWEI_hdr_vivid)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceHdrVividFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_KHR_maintenance7)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance7FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_maintenance7)

    #if defined(VK_QCOM_fragment_density_map_offset)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDrawParametersFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_device_memory_report)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_memory_report)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicInt64Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_INTEL_shader_integer_functions2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloat16Int8Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_HUAWEI_cluster_culling_shader)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderTerminateInvocationFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_ARM_scheduling_controls)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSchedulingControlsFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_scheduling_controls)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderFloatControls2Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_legacy_vertex_attributes)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_KHR_cooperative_matrix)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_cooperative_matrix)

    #if defined(VK_AMDX_shader_enqueue)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMDX_shader_enqueue)

    #if defined(VKSC_VERSION_1_0)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVulkanSC10Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_KHR_compute_shader_derivatives)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_EXT_buffer_device_address)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_swapchain_maintenance1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_shader_image_atomic_int64)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImagelessFramebufferFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceIndexTypeUint8Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDynamicRenderingFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_shading_rate_image)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShadingRateImageFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_EXT_shader_atomic_float2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_KHR_shader_maximal_reconvergence)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_shader_replicated_composites)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_NV_fragment_shading_rate_enums)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_EXT_extended_dynamic_state2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_QCOM_multiview_per_view_viewports)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_NV_shader_atomic_float16_vector)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_EXT_primitives_generated_query)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_primitives_generated_query)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_per_stage_descriptor_set)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDescriptorIndexingFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceMaintenance5Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_KHR_present_wait)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePresentWaitFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_present_wait)

    #if defined(VK_NV_copy_memory_indirect)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_copy_memory_indirect)

    #if defined(VK_EXT_graphics_pipeline_library)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_image_sliced_view_of_3d)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_primitive_topology_list_restart)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_KHR_acceleration_structure)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAccelerationStructureFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_EXT_legacy_dithering)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceLegacyDitheringFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_legacy_dithering)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceShaderIntegerDotProductFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_AMD_anti_lag)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceAntiLagFeaturesAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_anti_lag)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceScalarBlockLayoutFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_depth_clip_control)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceDepthClipControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_border_color_swizzle)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_border_color_swizzle)

    #if defined(VK_KHR_video_maintenance1)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_maintenance1)

    #if defined(VK_ARM_pipeline_opacity_micromap)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_NV_cluster_acceleration_structure)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_EXT_rgba10x6_formats)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct chain_validator<VkPhysicalDeviceFeatures2, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_tracing_pipeline)

#endif // #if defined(VK_VERSION_1_1)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PHYSICAL_DEVICE_FEATURES2_HPP
