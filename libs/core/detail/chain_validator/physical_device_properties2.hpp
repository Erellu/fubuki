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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PHYSICAL_DEVICE_PROPERTIES2_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PHYSICAL_DEVICE_PROPERTIES2_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_1)

template<typename structure_type>
struct chain_validator<VkPhysicalDeviceProperties2, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_conservative_rasterization)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceConservativeRasterizationPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_conservative_rasterization)

    #if defined(VK_KHR_maintenance7)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredApiPropertiesListKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_maintenance7)

    #if defined(VK_QCOM_image_processing2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessing2PropertiesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_image_processing2)

    #if defined(VK_KHR_fragment_shading_rate)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRatePropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_EXT_shader_module_identifier)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_module_identifier)

    #if defined(VK_EXT_nested_command_buffer)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceNestedCommandBufferPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_nested_command_buffer)

    #if defined(VK_KHR_fragment_shader_barycentric)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_fragment_shader_barycentric)

    #if defined(VK_EXT_pci_bus_info)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePCIBusInfoPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_pci_bus_info)

    #if defined(VK_EXT_opacity_micromap)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpacityMicromapPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_opacity_micromap)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorIndexingProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NVX_multiview_per_view_attributes)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDriverProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_cooperative_vector)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeVectorPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_vector)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceIDProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_ARM_render_pass_striped)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceRenderPassStripedPropertiesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_render_pass_striped)

    #if defined(VK_KHR_maintenance7)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance7PropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_maintenance7)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePushDescriptorProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance5Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_AMD_shader_core_properties)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_shader_core_properties)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceTimelineSemaphoreProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_MSFT_layered_driver)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceLayeredDriverPropertiesMSFT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_MSFT_layered_driver)

    #if defined(VK_EXT_shader_object)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderObjectPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_object)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePointClippingProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan13Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_provoking_vertex)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceProvokingVertexPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_provoking_vertex)

    #if defined(VK_EXT_discard_rectangles)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDiscardRectanglePropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_discard_rectangles)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceFloatControlsProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan12Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_KHR_compute_shader_derivatives)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_compute_shader_derivatives)

    #if defined(VK_KHR_performance_query)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePerformanceQueryPropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_performance_query)

    #if defined(VK_EXT_transform_feedback)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceTransformFeedbackPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_transform_feedback)

    #if defined(VK_HUAWEI_cluster_culling_shader)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_cluster_culling_shader)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceHostImageCopyProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_NV_cluster_acceleration_structure)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceClusterAccelerationStructurePropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cluster_acceleration_structure)

    #if defined(VK_EXT_legacy_vertex_attributes)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_legacy_vertex_attributes)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan14Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_AMD_shader_core_properties2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreProperties2AMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_shader_core_properties2)

    #if defined(VK_EXT_custom_border_color)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceCustomBorderColorPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_custom_border_color)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance4Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_KHR_acceleration_structure)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceAccelerationStructurePropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_acceleration_structure)

    #if defined(VK_ARM_scheduling_controls)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceSchedulingControlsPropertiesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_scheduling_controls)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceSamplerFilterMinmaxProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_graphics_pipeline_library)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_graphics_pipeline_library)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceTexelBufferAlignmentProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_HUAWEI_subpass_shading)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubpassShadingPropertiesHUAWEI>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_HUAWEI_subpass_shading)

    #if defined(VK_ARM_shader_core_properties)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCorePropertiesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_shader_core_properties)

    #if defined(VK_NV_mesh_shader)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_mesh_shader)

    #if defined(VK_KHR_portability_subset)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePortabilitySubsetPropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_portability_subset)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance3Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_device_generated_commands)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_device_generated_commands)

    #if defined(VK_NV_extended_sparse_address_space)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_extended_sparse_address_space)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceLineRasterizationProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_NV_optical_flow)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceOpticalFlowPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineRobustnessProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_descriptor_buffer)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_descriptor_buffer)

    #if defined(VK_EXT_blend_operation_advanced)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_blend_operation_advanced)

    #if defined(VK_NV_cooperative_matrix)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_matrix)

    #if defined(VK_EXT_physical_device_drm)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDrmPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_physical_device_drm)

    #if defined(VK_EXT_sample_locations)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceSampleLocationsPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_sample_locations)

    #if defined(VK_EXT_fragment_density_map)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_density_map)

    #if defined(VK_KHR_pipeline_binary)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePipelineBinaryPropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_binary)

    #if defined(VK_KHR_cooperative_matrix)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrixPropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_cooperative_matrix)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkan11Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_ARM_shader_core_builtins)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ARM_shader_core_builtins)

    #if defined(VK_EXT_shader_tile_image)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderTileImagePropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_shader_tile_image)

    #if defined(VK_NV_cooperative_matrix2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceCooperativeMatrix2PropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cooperative_matrix2)

    #if defined(VK_EXT_external_memory_host)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalMemoryHostPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_external_memory_host)

    #if defined(VK_NV_cuda_kernel_launch)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceCudaKernelLaunchPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_cuda_kernel_launch)

    #if defined(VK_NV_memory_decompression)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMemoryDecompressionPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_memory_decompression)

    #if defined(VKSC_VERSION_1_0)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceVulkanSC10Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_NV_copy_memory_indirect)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceCopyMemoryIndirectPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_copy_memory_indirect)

    #if defined(VK_NV_partitioned_acceleration_structure)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_partitioned_acceleration_structure)

    #if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPipelinePropertiesKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_ray_tracing_pipeline)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceProtectedMemoryProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderIntegerDotProductProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_robustness2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceRobustness2PropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_robustness2)

    #if defined(VK_QCOM_image_processing)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageProcessingPropertiesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_image_processing)

    #if defined(VK_EXT_extended_dynamic_state3)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceExtendedDynamicState3PropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_NV_ray_tracing)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceSubgroupSizeControlProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_map_memory_placed)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMapMemoryPlacedPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_map_memory_placed)

    #if defined(VK_NV_device_generated_commands)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_generated_commands)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceInlineUniformBlockProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_EXT_vertex_attribute_divisor)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_vertex_attribute_divisor)

    #if defined(VK_NV_fragment_shading_rate_enums)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_ANDROID_external_format_resolve)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceExternalFormatResolvePropertiesANDROID>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ANDROID_external_format_resolve)

    #if defined(VK_MESA_image_alignment_control)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceImageAlignmentControlPropertiesMESA>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_MESA_image_alignment_control)

    #if defined(VK_QCOM_fragment_density_map_offset)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_fragment_density_map_offset)

    #if defined(VK_EXT_fragment_density_map2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_fragment_density_map2)

    #if defined(VK_EXT_descriptor_buffer)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_descriptor_buffer)

    #if defined(VK_NV_displacement_micromap)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDisplacementMicromapPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_displacement_micromap)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiviewProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_NV_shading_rate_image)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShadingRateImagePropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shading_rate_image)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMaintenance6Properties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceDepthStencilResolveProperties>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_mesh_shader)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMeshShaderPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_mesh_shader)

    #if defined(VK_AMDX_shader_enqueue)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderEnqueuePropertiesAMDX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMDX_shader_enqueue)

    #if defined(VK_NV_ray_tracing_invocation_reorder)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_ray_tracing_invocation_reorder)

    #if defined(VK_NV_shader_sm_builtins)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_shader_sm_builtins)

    #if defined(VK_EXT_multi_draw)
template<>
struct chain_validator<VkPhysicalDeviceProperties2, VkPhysicalDeviceMultiDrawPropertiesEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_multi_draw)

#endif // #if defined(VK_VERSION_1_1)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PHYSICAL_DEVICE_PROPERTIES2_HPP
