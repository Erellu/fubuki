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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_DEVICE_CREATE_INFO_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_DEVICE_CREATE_INFO_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_0)

template<typename structure_type>
struct chain_validator<VkDeviceCreateInfo, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_NV_optical_flow)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceOpticalFlowFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_KHR_ray_tracing_maintenance1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_tracing_maintenance1)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceGlobalPriorityQueryFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_texel_buffer_alignment)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_texel_buffer_alignment)

    #if defined(VK_KHR_portability_subset)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePortabilitySubsetFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_portability_subset)

    #if defined(VK_NV_cooperative_matrix2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrix2FeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_matrix2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupRotateFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_NV_shader_sm_builtins)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shader_sm_builtins)

    #if defined(VK_KHR_maintenance8)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance8FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_maintenance8)

    #if defined(VK_KHR_video_encode_quantization_map)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_encode_quantization_map)

    #if defined(VK_NV_cooperative_vector)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeVectorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_vector)

    #if defined(VK_EXT_non_seamless_cube_map)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_non_seamless_cube_map)

    #if defined(VK_EXT_mutable_descriptor_type)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_mutable_descriptor_type)

    #if defined(VK_NV_displacement_micromap)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDisplacementMicromapFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_displacement_micromap)

    #if defined(VK_EXT_device_fault)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFaultFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_fault)

    #if defined(VK_KHR_video_encode_av1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_encode_av1)

    #if defined(VK_QCOM_image_processing2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessing2FeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_image_processing2)

    #if defined(VK_NV_corner_sampled_image)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCornerSampledImageFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_corner_sampled_image)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceInlineUniformBlockFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_4444_formats)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevice4444FormatsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_4444_formats)

    #if defined(VK_EXT_device_generated_commands)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_generated_commands)

    #if defined(VK_EXT_shader_module_identifier)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_subpass_merge_feedback)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_subpass_merge_feedback)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevice16BitStorageFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVulkan12Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance6Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_astc_decode_mode)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceASTCDecodeFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_astc_decode_mode)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceHostImageCopyFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_fragment_density_map2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_density_map2)

    #if defined(VK_NV_external_memory_rdma)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_rdma)

    #if defined(VK_EXT_depth_clip_enable)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipEnableFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_multi_draw)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMultiDrawFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_multi_draw)

    #if defined(VK_EXT_shader_atomic_float)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_atomic_float)

    #if defined(VK_NV_memory_decompression)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMemoryDecompressionFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_memory_decompression)

    #if defined(VK_EXT_color_write_enable)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceColorWriteEnableFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_color_write_enable)

    #if defined(VK_NV_present_metering)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePresentMeteringFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_present_metering)

    #if defined(VK_NV_shader_image_footprint)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageFootprintFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shader_image_footprint)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceUniformBufferStandardLayoutFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_external_sci_sync2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSync2FeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_sci_sync2)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVulkan13Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_external_sci_sync)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExternalSciSyncFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_sci_sync)

    #if defined(VK_AMD_device_coherent_memory)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCoherentMemoryFeaturesAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_device_coherent_memory)

    #if defined(VK_KHR_fragment_shading_rate)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_EXT_conditional_rendering)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceConditionalRenderingFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_conditional_rendering)

    #if defined(VK_EXT_image_compression_control_swapchain)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_compression_control_swapchain)

    #if defined(VK_EXT_device_address_binding_report)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceAddressBindingReportFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_address_binding_report)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderExpectAssumeFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_HUAWEI_subpass_shading)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_KHR_ray_query)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayQueryFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_query)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSamplerYcbcrConversionFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_rasterization_order_attachment_access)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_rasterization_order_attachment_access)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_ray_tracing_validation)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingValidationFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_validation)

    #if defined(VK_ARM_render_pass_striped)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRenderPassStripedFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_render_pass_striped)

    #if defined(VK_KHR_performance_query)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePerformanceQueryFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_performance_query)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelineProtectedAccessFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_depth_bias_control)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDepthBiasControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_bias_control)

    #if defined(VK_NV_linear_color_attachment)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceLinearColorAttachmentFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_linear_color_attachment)

    #if defined(VK_NV_extended_sparse_address_space)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_EXT_custom_border_color)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCustomBorderColorFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_custom_border_color)

    #if defined(VK_QNX_external_memory_screen_buffer)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_SEC_amigo_profiling)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceAmigoProfilingFeaturesSEC>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_SEC_amigo_profiling)

    #if defined(VK_EXT_device_memory_report)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDeviceDeviceMemoryReportCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_EXT_device_memory_report)

    #if defined(VK_NV_cooperative_matrix)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_matrix)

    #if defined(VK_EXT_fragment_shader_interlock)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_shader_interlock)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVulkan11Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_image_view_min_lod)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageViewMinLodFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_view_min_lod)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVariablePointersFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelineRobustnessFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_QCOM_filter_cubic_clamp)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCubicClampFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_filter_cubic_clamp)

    #if defined(VK_EXT_vertex_input_dynamic_state)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_NV_coverage_reduction_mode)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCoverageReductionModeFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_coverage_reduction_mode)

    #if defined(VK_EXT_provoking_vertex)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceProvokingVertexFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_provoking_vertex)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceTextureCompressionASTCHDRFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_map_memory_placed)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_map_memory_placed)

    #if defined(VK_NV_device_diagnostics_config)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDeviceDiagnosticsConfigCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_diagnostics_config)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceTimelineSemaphoreFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_present_barrier)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePresentBarrierFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_present_barrier)

    #if defined(VK_NV_device_diagnostics_config)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDiagnosticsConfigFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_diagnostics_config)

    #if defined(VK_VALVE_descriptor_set_host_mapping)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VALVE_descriptor_set_host_mapping)

    #if defined(VK_ARM_scheduling_controls)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDeviceQueueShaderCoreControlCreateInfoARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_scheduling_controls)

    #if defined(VK_EXT_extended_dynamic_state)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_NV_device_generated_commands_compute)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_generated_commands_compute)

    #if defined(VK_QCOM_image_processing)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageProcessingFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_image_processing)

    #if defined(VK_EXT_pipeline_properties)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelinePropertiesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_pipeline_properties)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVulkanMemoryModelFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_inherited_viewport_scissor)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceInheritedViewportScissorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_EXT_shader_object)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderObjectFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_object)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevice8BitStorageFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_mesh_shader)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_mesh_shader)

    #if defined(VK_KHR_workgroup_memory_explicit_layout)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_workgroup_memory_explicit_layout)

    #if defined(VK_EXT_ycbcr_image_arrays)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_ycbcr_image_arrays)

    #if defined(VK_ARM_shader_core_builtins)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_shader_core_builtins)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelineCreationCacheControlFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_blend_operation_advanced)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_KHR_fragment_shader_barycentric)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_EXT_extended_dynamic_state3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_descriptor_buffer)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorBufferFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_nested_command_buffer)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceNestedCommandBufferFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_nested_command_buffer)

    #if defined(VK_NV_raw_access_chains)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRawAccessChainsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_raw_access_chains)

    #if defined(VK_KHR_ray_tracing_position_fetch)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_tracing_position_fetch)

    #if defined(VK_KHR_shader_quad_control)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderQuadControlFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_quad_control)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceHostQueryResetFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_ANDROID_external_format_resolve)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_KHR_pipeline_binary)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelineBinaryFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_binary)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePrivateDataFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_vertex_attribute_robustness)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_vertex_attribute_robustness)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_image_compression_control)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageCompressionControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_compression_control)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageRobustnessFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_KHR_shader_clock)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderClockFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_clock)

    #if defined(VK_NV_external_memory_sci_buf)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExternalMemorySciBufFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_sci_buf)

    #if defined(VKSC_VERSION_1_0)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDeviceObjectReservationCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVulkan14Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_depth_clamp_control)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_clamp_control)

    #if defined(VK_NV_representative_fragment_test)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_representative_fragment_test)

    #if defined(VK_EXT_shader_tile_image)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderTileImageFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_tile_image)

    #if defined(VK_KHR_depth_clamp_zero_one)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_depth_clamp_zero_one)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDeviceGroupDeviceCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_dynamic_rendering_unused_attachments)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_dynamic_rendering_unused_attachments)

    #if defined(VK_QCOM_tile_properties)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceTilePropertiesFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_tile_properties)

    #if defined(VK_HUAWEI_invocation_mask)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_invocation_mask)

    #if defined(VK_EXT_attachment_feedback_loop_layout)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_attachment_feedback_loop_layout)

    #if defined(VK_KHR_shader_relaxed_extended_instruction)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_relaxed_extended_instruction)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_memory_priority)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMemoryPriorityFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_memory_priority)

    #if defined(VK_NV_device_generated_commands)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_generated_commands)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceProtectedMemoryFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_KHR_present_id)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePresentIdFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_present_id)

    #if defined(VK_NV_scissor_exclusive)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExclusiveScissorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_scissor_exclusive)

    #if defined(VK_NV_partitioned_acceleration_structure)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingLocalReadFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_image_2d_view_of_3d)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_2d_view_of_3d)

    #if defined(VK_NV_command_buffer_inheritance)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_command_buffer_inheritance)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceLineRasterizationFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSynchronization2Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_AMD_shader_early_and_late_fragment_tests)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_shader_early_and_late_fragment_tests)

    #if defined(VK_EXT_fragment_density_map)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_density_map)

    #if defined(VK_NV_descriptor_pool_overallocation)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_descriptor_pool_overallocation)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVertexAttributeDivisorFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_mesh_shader)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMeshShaderFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_mesh_shader)

    #if defined(VK_NV_external_sci_sync2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_NV_external_sci_sync2)

    #if defined(VK_EXT_robustness2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRobustness2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_robustness2)

    #if defined(VK_EXT_opacity_micromap)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceOpacityMicromapFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_QCOM_ycbcr_degamma)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_ycbcr_degamma)

    #if defined(VK_QCOM_filter_cubic_weights)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCubicWeightsFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_filter_cubic_weights)

    #if defined(VK_IMG_relaxed_line_rasterization)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_IMG_relaxed_line_rasterization)

    #if defined(VK_KHR_video_maintenance2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance2FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_maintenance2)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDevicePrivateDataCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_KHR_pipeline_binary)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDevicePipelineBinaryInternalCacheControlKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_binary)

    #if defined(VK_EXT_frame_boundary)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFrameBoundaryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_frame_boundary)

    #if defined(VK_KHR_pipeline_executable_properties)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_executable_properties)

    #if defined(VK_EXT_pipeline_library_group_handles)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_pipeline_library_group_handles)

    #if defined(VK_EXT_transform_feedback)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceTransformFeedbackFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_transform_feedback)

    #if defined(VK_AMD_memory_overallocation_behavior)
template<>
struct chain_validator<VkDeviceCreateInfo, VkDeviceMemoryOverallocationCreateInfoAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_memory_overallocation_behavior)

    #if defined(VK_EXT_pageable_device_local_memory)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_pageable_device_local_memory)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance4Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSubgroupSizeControlFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_ray_tracing_motion_blur)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_motion_blur)

    #if defined(VK_NV_cuda_kernel_launch)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCudaKernelLaunchFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_MESA_image_alignment_control)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageAlignmentControlFeaturesMESA>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_MESA_image_alignment_control)

    #if defined(VK_HUAWEI_hdr_vivid)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceHdrVividFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_hdr_vivid)

    #if defined(VK_KHR_maintenance7)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance7FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_maintenance7)

    #if defined(VK_QCOM_fragment_density_map_offset)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderDrawParametersFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_device_memory_report)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_memory_report)

    #if defined(VK_KHR_shader_subgroup_uniform_control_flow)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_subgroup_uniform_control_flow)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicInt64Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_INTEL_shader_integer_functions2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_INTEL_shader_integer_functions2)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloat16Int8Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_HUAWEI_cluster_culling_shader)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderTerminateInvocationFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_ARM_scheduling_controls)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSchedulingControlsFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_scheduling_controls)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderFloatControls2Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_legacy_vertex_attributes)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_KHR_cooperative_matrix)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCooperativeMatrixFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_cooperative_matrix)

    #if defined(VK_AMDX_shader_enqueue)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderEnqueueFeaturesAMDX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMDX_shader_enqueue)

    #if defined(VKSC_VERSION_1_0)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVulkanSC10Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_EXT_present_mode_fifo_latest_ready)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_present_mode_fifo_latest_ready)

    #if defined(VK_KHR_compute_shader_derivatives)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_EXT_buffer_device_address)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_buffer_device_address)

    #if defined(VK_EXT_swapchain_maintenance1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_shader_image_atomic_int64)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_image_atomic_int64)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImagelessFramebufferFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceIndexTypeUint8Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_ycbcr_2plane_444_formats)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_ycbcr_2plane_444_formats)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDynamicRenderingFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_shading_rate_image)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShadingRateImageFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_dedicated_allocation_image_aliasing)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_dedicated_allocation_image_aliasing)

    #if defined(VK_EXT_shader_atomic_float2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_atomic_float2)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_QCOM_multiview_per_view_render_areas)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_multiview_per_view_render_areas)

    #if defined(VK_KHR_shader_maximal_reconvergence)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_shader_maximal_reconvergence)

    #if defined(VK_EXT_multisampled_render_to_single_sampled)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_multisampled_render_to_single_sampled)

    #if defined(VK_EXT_shader_replicated_composites)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_replicated_composites)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFeatures2>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_NV_fragment_shading_rate_enums)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_EXT_extended_dynamic_state2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_QCOM_multiview_per_view_viewports)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_multiview_per_view_viewports)

    #if defined(VK_NV_shader_atomic_float16_vector)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shader_atomic_float16_vector)

    #if defined(VK_EXT_primitives_generated_query)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_primitives_generated_query)

    #if defined(VK_NV_ray_tracing_linear_swept_spheres)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_linear_swept_spheres)

    #if defined(VK_NV_per_stage_descriptor_set)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePerStageDescriptorSetFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_per_stage_descriptor_set)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDescriptorIndexingFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceMaintenance5Features>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_KHR_present_wait)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePresentWaitFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_present_wait)

    #if defined(VK_NV_copy_memory_indirect)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_copy_memory_indirect)

    #if defined(VKSC_VERSION_1_0)
template<>
struct chain_validator<VkDeviceCreateInfo, VkFaultCallbackInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_EXT_application_parameters)
template<>
struct chain_validator<VkDeviceCreateInfo, VkApplicationParametersEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_EXT_application_parameters)

    #if defined(VK_EXT_graphics_pipeline_library)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_EXT_image_sliced_view_of_3d)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_primitive_topology_list_restart)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_primitive_topology_list_restart)

    #if defined(VK_KHR_acceleration_structure)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceAccelerationStructureFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_EXT_legacy_dithering)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceLegacyDitheringFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_legacy_dithering)

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceShaderIntegerDotProductFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_AMD_anti_lag)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceAntiLagFeaturesAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_anti_lag)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceScalarBlockLayoutFeatures>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_depth_clip_control)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceDepthClipControlFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_clip_control)

    #if defined(VK_EXT_border_color_swizzle)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_border_color_swizzle)

    #if defined(VK_KHR_video_maintenance1)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceVideoMaintenance1FeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_maintenance1)

    #if defined(VK_ARM_pipeline_opacity_micromap)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_pipeline_opacity_micromap)

    #if defined(VK_NV_cluster_acceleration_structure)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_EXT_rgba10x6_formats)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_rgba10x6_formats)

    #if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct chain_validator<VkDeviceCreateInfo, VkPhysicalDeviceRayTracingPipelineFeaturesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_tracing_pipeline)

#endif // #if defined(VK_VERSION_1_0)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_DEVICE_CREATE_INFO_HPP
