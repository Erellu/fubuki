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

#ifndef FUBUKI_EXTENSION_FUNCTIONS_DEVICE_HPP
#define FUBUKI_EXTENSION_FUNCTIONS_DEVICE_HPP

#include <memory>
#include <string_view>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/amd_anti_lag.hpp"
#include "extension/functions/amd_buffer_marker.hpp"
#include "extension/functions/amd_device_coherent_memory.hpp"
#include "extension/functions/amd_display_native_hdr.hpp"
#include "extension/functions/amd_draw_indirect_count.hpp"
#include "extension/functions/amd_gcn_shader.hpp"
#include "extension/functions/amd_gpu_shader_half_float.hpp"
#include "extension/functions/amd_gpu_shader_int16.hpp"
#include "extension/functions/amd_memory_overallocation_behavior.hpp"
#include "extension/functions/amd_mixed_attachment_samples.hpp"
#include "extension/functions/amd_negative_viewport_height.hpp"
#include "extension/functions/amd_pipeline_compiler_control.hpp"
#include "extension/functions/amd_rasterization_order.hpp"
#include "extension/functions/amd_shader_ballot.hpp"
#include "extension/functions/amd_shader_core_properties.hpp"
#include "extension/functions/amd_shader_core_properties2.hpp"
#include "extension/functions/amd_shader_early_and_late_fragment_tests.hpp"
#include "extension/functions/amd_shader_explicit_vertex_parameter.hpp"
#include "extension/functions/amd_shader_fragment_mask.hpp"
#include "extension/functions/amd_shader_image_load_store_lod.hpp"
#include "extension/functions/amd_shader_info.hpp"
#include "extension/functions/amd_shader_trinary_minmax.hpp"
#include "extension/functions/amd_texture_gather_bias_lod.hpp"
#include "extension/functions/amdx_shader_enqueue.hpp"
#include "extension/functions/android_external_format_resolve.hpp"
#include "extension/functions/android_external_memory_android_hardware_buffer.hpp"
#include "extension/functions/arm_pipeline_opacity_micromap.hpp"
#include "extension/functions/arm_rasterization_order_attachment_access.hpp"
#include "extension/functions/arm_render_pass_striped.hpp"
#include "extension/functions/arm_scheduling_controls.hpp"
#include "extension/functions/arm_shader_core_builtins.hpp"
#include "extension/functions/arm_shader_core_properties.hpp"
#include "extension/functions/ext_4444_formats.hpp"
#include "extension/functions/ext_astc_decode_mode.hpp"
#include "extension/functions/ext_attachment_feedback_loop_dynamic_state.hpp"
#include "extension/functions/ext_attachment_feedback_loop_layout.hpp"
#include "extension/functions/ext_blend_operation_advanced.hpp"
#include "extension/functions/ext_border_color_swizzle.hpp"
#include "extension/functions/ext_buffer_device_address.hpp"
#include "extension/functions/ext_calibrated_timestamps.hpp"
#include "extension/functions/ext_color_write_enable.hpp"
#include "extension/functions/ext_conditional_rendering.hpp"
#include "extension/functions/ext_conservative_rasterization.hpp"
#include "extension/functions/ext_custom_border_color.hpp"
#include "extension/functions/ext_debug_marker.hpp"
#include "extension/functions/ext_depth_bias_control.hpp"
#include "extension/functions/ext_depth_clamp_control.hpp"
#include "extension/functions/ext_depth_clamp_zero_one.hpp"
#include "extension/functions/ext_depth_clip_control.hpp"
#include "extension/functions/ext_depth_clip_enable.hpp"
#include "extension/functions/ext_depth_range_unrestricted.hpp"
#include "extension/functions/ext_descriptor_buffer.hpp"
#include "extension/functions/ext_descriptor_indexing.hpp"
#include "extension/functions/ext_device_address_binding_report.hpp"
#include "extension/functions/ext_device_fault.hpp"
#include "extension/functions/ext_device_generated_commands.hpp"
#include "extension/functions/ext_device_memory_report.hpp"
#include "extension/functions/ext_discard_rectangles.hpp"
#include "extension/functions/ext_display_control.hpp"
#include "extension/functions/ext_dynamic_rendering_unused_attachments.hpp"
#include "extension/functions/ext_extended_dynamic_state.hpp"
#include "extension/functions/ext_extended_dynamic_state2.hpp"
#include "extension/functions/ext_extended_dynamic_state3.hpp"
#include "extension/functions/ext_external_memory_acquire_unmodified.hpp"
#include "extension/functions/ext_external_memory_dma_buf.hpp"
#include "extension/functions/ext_external_memory_host.hpp"
#include "extension/functions/ext_external_memory_metal.hpp"
#include "extension/functions/ext_filter_cubic.hpp"
#include "extension/functions/ext_fragment_density_map.hpp"
#include "extension/functions/ext_fragment_density_map2.hpp"
#include "extension/functions/ext_fragment_density_map_offset.hpp"
#include "extension/functions/ext_fragment_shader_interlock.hpp"
#include "extension/functions/ext_frame_boundary.hpp"
#include "extension/functions/ext_full_screen_exclusive.hpp"
#include "extension/functions/ext_global_priority.hpp"
#include "extension/functions/ext_global_priority_query.hpp"
#include "extension/functions/ext_graphics_pipeline_library.hpp"
#include "extension/functions/ext_hdr_metadata.hpp"
#include "extension/functions/ext_host_image_copy.hpp"
#include "extension/functions/ext_host_query_reset.hpp"
#include "extension/functions/ext_image_2d_view_of_3d.hpp"
#include "extension/functions/ext_image_compression_control.hpp"
#include "extension/functions/ext_image_compression_control_swapchain.hpp"
#include "extension/functions/ext_image_drm_format_modifier.hpp"
#include "extension/functions/ext_image_robustness.hpp"
#include "extension/functions/ext_image_sliced_view_of_3d.hpp"
#include "extension/functions/ext_image_view_min_lod.hpp"
#include "extension/functions/ext_index_type_uint8.hpp"
#include "extension/functions/ext_inline_uniform_block.hpp"
#include "extension/functions/ext_legacy_dithering.hpp"
#include "extension/functions/ext_legacy_vertex_attributes.hpp"
#include "extension/functions/ext_line_rasterization.hpp"
#include "extension/functions/ext_load_store_op_none.hpp"
#include "extension/functions/ext_map_memory_placed.hpp"
#include "extension/functions/ext_memory_budget.hpp"
#include "extension/functions/ext_memory_priority.hpp"
#include "extension/functions/ext_mesh_shader.hpp"
#include "extension/functions/ext_metal_objects.hpp"
#include "extension/functions/ext_multi_draw.hpp"
#include "extension/functions/ext_multisampled_render_to_single_sampled.hpp"
#include "extension/functions/ext_mutable_descriptor_type.hpp"
#include "extension/functions/ext_nested_command_buffer.hpp"
#include "extension/functions/ext_non_seamless_cube_map.hpp"
#include "extension/functions/ext_opacity_micromap.hpp"
#include "extension/functions/ext_pageable_device_local_memory.hpp"
#include "extension/functions/ext_pci_bus_info.hpp"
#include "extension/functions/ext_physical_device_drm.hpp"
#include "extension/functions/ext_pipeline_creation_cache_control.hpp"
#include "extension/functions/ext_pipeline_creation_feedback.hpp"
#include "extension/functions/ext_pipeline_library_group_handles.hpp"
#include "extension/functions/ext_pipeline_properties.hpp"
#include "extension/functions/ext_pipeline_protected_access.hpp"
#include "extension/functions/ext_pipeline_robustness.hpp"
#include "extension/functions/ext_post_depth_coverage.hpp"
#include "extension/functions/ext_present_mode_fifo_latest_ready.hpp"
#include "extension/functions/ext_primitive_topology_list_restart.hpp"
#include "extension/functions/ext_primitives_generated_query.hpp"
#include "extension/functions/ext_private_data.hpp"
#include "extension/functions/ext_provoking_vertex.hpp"
#include "extension/functions/ext_queue_family_foreign.hpp"
#include "extension/functions/ext_rasterization_order_attachment_access.hpp"
#include "extension/functions/ext_rgba10x6_formats.hpp"
#include "extension/functions/ext_robustness2.hpp"
#include "extension/functions/ext_sample_locations.hpp"
#include "extension/functions/ext_sampler_filter_minmax.hpp"
#include "extension/functions/ext_scalar_block_layout.hpp"
#include "extension/functions/ext_separate_stencil_usage.hpp"
#include "extension/functions/ext_shader_atomic_float.hpp"
#include "extension/functions/ext_shader_atomic_float2.hpp"
#include "extension/functions/ext_shader_demote_to_helper_invocation.hpp"
#include "extension/functions/ext_shader_image_atomic_int64.hpp"
#include "extension/functions/ext_shader_module_identifier.hpp"
#include "extension/functions/ext_shader_object.hpp"
#include "extension/functions/ext_shader_replicated_composites.hpp"
#include "extension/functions/ext_shader_stencil_export.hpp"
#include "extension/functions/ext_shader_subgroup_ballot.hpp"
#include "extension/functions/ext_shader_subgroup_vote.hpp"
#include "extension/functions/ext_shader_tile_image.hpp"
#include "extension/functions/ext_shader_viewport_index_layer.hpp"
#include "extension/functions/ext_subgroup_size_control.hpp"
#include "extension/functions/ext_subpass_merge_feedback.hpp"
#include "extension/functions/ext_swapchain_maintenance1.hpp"
#include "extension/functions/ext_texel_buffer_alignment.hpp"
#include "extension/functions/ext_texture_compression_astc_hdr.hpp"
#include "extension/functions/ext_tooling_info.hpp"
#include "extension/functions/ext_transform_feedback.hpp"
#include "extension/functions/ext_validation_cache.hpp"
#include "extension/functions/ext_vertex_attribute_divisor.hpp"
#include "extension/functions/ext_vertex_attribute_robustness.hpp"
#include "extension/functions/ext_vertex_input_dynamic_state.hpp"
#include "extension/functions/ext_ycbcr_2plane_444_formats.hpp"
#include "extension/functions/ext_ycbcr_image_arrays.hpp"
#include "extension/functions/fuchsia_buffer_collection.hpp"
#include "extension/functions/fuchsia_external_memory.hpp"
#include "extension/functions/fuchsia_external_semaphore.hpp"
#include "extension/functions/ggp_frame_token.hpp"
#include "extension/functions/google_decorate_string.hpp"
#include "extension/functions/google_display_timing.hpp"
#include "extension/functions/google_hlsl_functionality1.hpp"
#include "extension/functions/google_user_type.hpp"
#include "extension/functions/huawei_cluster_culling_shader.hpp"
#include "extension/functions/huawei_hdr_vivid.hpp"
#include "extension/functions/huawei_invocation_mask.hpp"
#include "extension/functions/huawei_subpass_shading.hpp"
#include "extension/functions/img_filter_cubic.hpp"
#include "extension/functions/img_format_pvrtc.hpp"
#include "extension/functions/img_relaxed_line_rasterization.hpp"
#include "extension/functions/intel_performance_query.hpp"
#include "extension/functions/intel_shader_integer_functions2.hpp"
#include "extension/functions/khr_16bit_storage.hpp"
#include "extension/functions/khr_8bit_storage.hpp"
#include "extension/functions/khr_acceleration_structure.hpp"
#include "extension/functions/khr_bind_memory2.hpp"
#include "extension/functions/khr_buffer_device_address.hpp"
#include "extension/functions/khr_calibrated_timestamps.hpp"
#include "extension/functions/khr_compute_shader_derivatives.hpp"
#include "extension/functions/khr_cooperative_matrix.hpp"
#include "extension/functions/khr_copy_commands2.hpp"
#include "extension/functions/khr_create_renderpass2.hpp"
#include "extension/functions/khr_dedicated_allocation.hpp"
#include "extension/functions/khr_deferred_host_operations.hpp"
#include "extension/functions/khr_depth_clamp_zero_one.hpp"
#include "extension/functions/khr_depth_stencil_resolve.hpp"
#include "extension/functions/khr_descriptor_update_template.hpp"
#include "extension/functions/khr_device_group.hpp"
#include "extension/functions/khr_display_swapchain.hpp"
#include "extension/functions/khr_draw_indirect_count.hpp"
#include "extension/functions/khr_driver_properties.hpp"
#include "extension/functions/khr_dynamic_rendering.hpp"
#include "extension/functions/khr_dynamic_rendering_local_read.hpp"
#include "extension/functions/khr_external_fence.hpp"
#include "extension/functions/khr_external_fence_fd.hpp"
#include "extension/functions/khr_external_fence_win32.hpp"
#include "extension/functions/khr_external_memory.hpp"
#include "extension/functions/khr_external_memory_fd.hpp"
#include "extension/functions/khr_external_memory_win32.hpp"
#include "extension/functions/khr_external_semaphore.hpp"
#include "extension/functions/khr_external_semaphore_fd.hpp"
#include "extension/functions/khr_external_semaphore_win32.hpp"
#include "extension/functions/khr_format_feature_flags2.hpp"
#include "extension/functions/khr_fragment_shader_barycentric.hpp"
#include "extension/functions/khr_fragment_shading_rate.hpp"
#include "extension/functions/khr_get_memory_requirements2.hpp"
#include "extension/functions/khr_global_priority.hpp"
#include "extension/functions/khr_image_format_list.hpp"
#include "extension/functions/khr_imageless_framebuffer.hpp"
#include "extension/functions/khr_incremental_present.hpp"
#include "extension/functions/khr_index_type_uint8.hpp"
#include "extension/functions/khr_line_rasterization.hpp"
#include "extension/functions/khr_load_store_op_none.hpp"
#include "extension/functions/khr_maintenance1.hpp"
#include "extension/functions/khr_maintenance2.hpp"
#include "extension/functions/khr_maintenance3.hpp"
#include "extension/functions/khr_maintenance4.hpp"
#include "extension/functions/khr_maintenance5.hpp"
#include "extension/functions/khr_maintenance6.hpp"
#include "extension/functions/khr_maintenance7.hpp"
#include "extension/functions/khr_maintenance8.hpp"
#include "extension/functions/khr_map_memory2.hpp"
#include "extension/functions/khr_multiview.hpp"
#include "extension/functions/khr_performance_query.hpp"
#include "extension/functions/khr_pipeline_binary.hpp"
#include "extension/functions/khr_pipeline_executable_properties.hpp"
#include "extension/functions/khr_pipeline_library.hpp"
#include "extension/functions/khr_portability_subset.hpp"
#include "extension/functions/khr_present_id.hpp"
#include "extension/functions/khr_present_wait.hpp"
#include "extension/functions/khr_push_descriptor.hpp"
#include "extension/functions/khr_ray_query.hpp"
#include "extension/functions/khr_ray_tracing_maintenance1.hpp"
#include "extension/functions/khr_ray_tracing_pipeline.hpp"
#include "extension/functions/khr_ray_tracing_position_fetch.hpp"
#include "extension/functions/khr_relaxed_block_layout.hpp"
#include "extension/functions/khr_sampler_mirror_clamp_to_edge.hpp"
#include "extension/functions/khr_sampler_ycbcr_conversion.hpp"
#include "extension/functions/khr_separate_depth_stencil_layouts.hpp"
#include "extension/functions/khr_shader_atomic_int64.hpp"
#include "extension/functions/khr_shader_bfloat16.hpp"
#include "extension/functions/khr_shader_clock.hpp"
#include "extension/functions/khr_shader_draw_parameters.hpp"
#include "extension/functions/khr_shader_expect_assume.hpp"
#include "extension/functions/khr_shader_float16_int8.hpp"
#include "extension/functions/khr_shader_float_controls.hpp"
#include "extension/functions/khr_shader_float_controls2.hpp"
#include "extension/functions/khr_shader_integer_dot_product.hpp"
#include "extension/functions/khr_shader_maximal_reconvergence.hpp"
#include "extension/functions/khr_shader_non_semantic_info.hpp"
#include "extension/functions/khr_shader_quad_control.hpp"
#include "extension/functions/khr_shader_relaxed_extended_instruction.hpp"
#include "extension/functions/khr_shader_subgroup_extended_types.hpp"
#include "extension/functions/khr_shader_subgroup_rotate.hpp"
#include "extension/functions/khr_shader_subgroup_uniform_control_flow.hpp"
#include "extension/functions/khr_shader_terminate_invocation.hpp"
#include "extension/functions/khr_shared_presentable_image.hpp"
#include "extension/functions/khr_spirv_1_4.hpp"
#include "extension/functions/khr_storage_buffer_storage_class.hpp"
#include "extension/functions/khr_swapchain.hpp"
#include "extension/functions/khr_swapchain_mutable_format.hpp"
#include "extension/functions/khr_synchronization2.hpp"
#include "extension/functions/khr_timeline_semaphore.hpp"
#include "extension/functions/khr_uniform_buffer_standard_layout.hpp"
#include "extension/functions/khr_variable_pointers.hpp"
#include "extension/functions/khr_vertex_attribute_divisor.hpp"
#include "extension/functions/khr_video_decode_av1.hpp"
#include "extension/functions/khr_video_decode_h264.hpp"
#include "extension/functions/khr_video_decode_h265.hpp"
#include "extension/functions/khr_video_decode_queue.hpp"
#include "extension/functions/khr_video_encode_av1.hpp"
#include "extension/functions/khr_video_encode_h264.hpp"
#include "extension/functions/khr_video_encode_h265.hpp"
#include "extension/functions/khr_video_encode_quantization_map.hpp"
#include "extension/functions/khr_video_encode_queue.hpp"
#include "extension/functions/khr_video_maintenance1.hpp"
#include "extension/functions/khr_video_maintenance2.hpp"
#include "extension/functions/khr_video_queue.hpp"
#include "extension/functions/khr_vulkan_memory_model.hpp"
#include "extension/functions/khr_win32_keyed_mutex.hpp"
#include "extension/functions/khr_workgroup_memory_explicit_layout.hpp"
#include "extension/functions/khr_zero_initialize_workgroup_memory.hpp"
#include "extension/functions/mesa_image_alignment_control.hpp"
#include "extension/functions/msft_layered_driver.hpp"
#include "extension/functions/nv_acquire_winrt_display.hpp"
#include "extension/functions/nv_clip_space_w_scaling.hpp"
#include "extension/functions/nv_cluster_acceleration_structure.hpp"
#include "extension/functions/nv_command_buffer_inheritance.hpp"
#include "extension/functions/nv_compute_shader_derivatives.hpp"
#include "extension/functions/nv_cooperative_matrix.hpp"
#include "extension/functions/nv_cooperative_matrix2.hpp"
#include "extension/functions/nv_cooperative_vector.hpp"
#include "extension/functions/nv_copy_memory_indirect.hpp"
#include "extension/functions/nv_corner_sampled_image.hpp"
#include "extension/functions/nv_coverage_reduction_mode.hpp"
#include "extension/functions/nv_cuda_kernel_launch.hpp"
#include "extension/functions/nv_dedicated_allocation.hpp"
#include "extension/functions/nv_dedicated_allocation_image_aliasing.hpp"
#include "extension/functions/nv_descriptor_pool_overallocation.hpp"
#include "extension/functions/nv_device_diagnostic_checkpoints.hpp"
#include "extension/functions/nv_device_diagnostics_config.hpp"
#include "extension/functions/nv_device_generated_commands.hpp"
#include "extension/functions/nv_device_generated_commands_compute.hpp"
#include "extension/functions/nv_displacement_micromap.hpp"
#include "extension/functions/nv_extended_sparse_address_space.hpp"
#include "extension/functions/nv_external_memory.hpp"
#include "extension/functions/nv_external_memory_rdma.hpp"
#include "extension/functions/nv_external_memory_win32.hpp"
#include "extension/functions/nv_fill_rectangle.hpp"
#include "extension/functions/nv_fragment_coverage_to_color.hpp"
#include "extension/functions/nv_fragment_shader_barycentric.hpp"
#include "extension/functions/nv_fragment_shading_rate_enums.hpp"
#include "extension/functions/nv_framebuffer_mixed_samples.hpp"
#include "extension/functions/nv_geometry_shader_passthrough.hpp"
#include "extension/functions/nv_glsl_shader.hpp"
#include "extension/functions/nv_inherited_viewport_scissor.hpp"
#include "extension/functions/nv_linear_color_attachment.hpp"
#include "extension/functions/nv_low_latency.hpp"
#include "extension/functions/nv_low_latency2.hpp"
#include "extension/functions/nv_memory_decompression.hpp"
#include "extension/functions/nv_mesh_shader.hpp"
#include "extension/functions/nv_optical_flow.hpp"
#include "extension/functions/nv_partitioned_acceleration_structure.hpp"
#include "extension/functions/nv_per_stage_descriptor_set.hpp"
#include "extension/functions/nv_present_barrier.hpp"
#include "extension/functions/nv_present_metering.hpp"
#include "extension/functions/nv_raw_access_chains.hpp"
#include "extension/functions/nv_ray_tracing.hpp"
#include "extension/functions/nv_ray_tracing_invocation_reorder.hpp"
#include "extension/functions/nv_ray_tracing_linear_swept_spheres.hpp"
#include "extension/functions/nv_ray_tracing_motion_blur.hpp"
#include "extension/functions/nv_ray_tracing_validation.hpp"
#include "extension/functions/nv_representative_fragment_test.hpp"
#include "extension/functions/nv_sample_mask_override_coverage.hpp"
#include "extension/functions/nv_scissor_exclusive.hpp"
#include "extension/functions/nv_shader_atomic_float16_vector.hpp"
#include "extension/functions/nv_shader_image_footprint.hpp"
#include "extension/functions/nv_shader_sm_builtins.hpp"
#include "extension/functions/nv_shader_subgroup_partitioned.hpp"
#include "extension/functions/nv_shading_rate_image.hpp"
#include "extension/functions/nv_viewport_array2.hpp"
#include "extension/functions/nv_viewport_swizzle.hpp"
#include "extension/functions/nv_win32_keyed_mutex.hpp"
#include "extension/functions/nvx_binary_import.hpp"
#include "extension/functions/nvx_image_view_handle.hpp"
#include "extension/functions/nvx_multiview_per_view_attributes.hpp"
#include "extension/functions/qcom_filter_cubic_clamp.hpp"
#include "extension/functions/qcom_filter_cubic_weights.hpp"
#include "extension/functions/qcom_fragment_density_map_offset.hpp"
#include "extension/functions/qcom_image_processing.hpp"
#include "extension/functions/qcom_image_processing2.hpp"
#include "extension/functions/qcom_multiview_per_view_render_areas.hpp"
#include "extension/functions/qcom_multiview_per_view_viewports.hpp"
#include "extension/functions/qcom_render_pass_shader_resolve.hpp"
#include "extension/functions/qcom_render_pass_store_ops.hpp"
#include "extension/functions/qcom_render_pass_transform.hpp"
#include "extension/functions/qcom_rotated_copy_commands.hpp"
#include "extension/functions/qcom_tile_properties.hpp"
#include "extension/functions/qcom_ycbcr_degamma.hpp"
#include "extension/functions/qnx_external_memory_screen_buffer.hpp"
#include "extension/functions/sec_amigo_profiling.hpp"
#include "extension/functions/valve_descriptor_set_host_mapping.hpp"
#include "extension/functions/valve_mutable_descriptor_type.hpp"

//------------------------------------------------------------------------------
// Macros

//------------------------------------------------------------------------------

namespace fubuki
{

namespace extension
{

#if defined(FUBUKI_DECLARE_EXT)
    #error "FUBUKI_DECLARE_EXT is already defined."
#endif

#define FUBUKI_DECLARE_EXT(name)                                                                                 \
                                                                                                                 \
    std::unique_ptr<extension::functions::name> name;                                                            \
                                                                                                                 \
    [[nodiscard]] constexpr operator const extension::functions::name*() const noexcept { return (name).get(); } \
    [[nodiscard]] constexpr operator const extension::functions::name&() const noexcept                          \
    {                                                                                                            \
        fubuki_assert((name) != nullptr, "Extension not loaded");                                                \
        return *(name);                                                                                          \
    }

struct device_functions
{

    FUBUKI_DECLARE_EXT(khr_swapchain)
    FUBUKI_DECLARE_EXT(khr_display_swapchain)
    FUBUKI_DECLARE_EXT(nv_glsl_shader)
    FUBUKI_DECLARE_EXT(ext_depth_range_unrestricted)
    FUBUKI_DECLARE_EXT(khr_sampler_mirror_clamp_to_edge)
    FUBUKI_DECLARE_EXT(img_filter_cubic)
    FUBUKI_DECLARE_EXT(amd_rasterization_order)
    FUBUKI_DECLARE_EXT(amd_shader_trinary_minmax)
    FUBUKI_DECLARE_EXT(amd_shader_explicit_vertex_parameter)
    FUBUKI_DECLARE_EXT(ext_debug_marker)
    FUBUKI_DECLARE_EXT(khr_video_queue)
    FUBUKI_DECLARE_EXT(khr_video_decode_queue)
    FUBUKI_DECLARE_EXT(amd_gcn_shader)
    FUBUKI_DECLARE_EXT(nv_dedicated_allocation)
    FUBUKI_DECLARE_EXT(ext_transform_feedback)
    FUBUKI_DECLARE_EXT(nvx_binary_import)
    FUBUKI_DECLARE_EXT(nvx_image_view_handle)
    FUBUKI_DECLARE_EXT(amd_draw_indirect_count)
    FUBUKI_DECLARE_EXT(amd_negative_viewport_height)
    FUBUKI_DECLARE_EXT(amd_gpu_shader_half_float)
    FUBUKI_DECLARE_EXT(amd_shader_ballot)
    FUBUKI_DECLARE_EXT(khr_video_encode_h264)
    FUBUKI_DECLARE_EXT(khr_video_encode_h265)
    FUBUKI_DECLARE_EXT(khr_video_decode_h264)
    FUBUKI_DECLARE_EXT(amd_texture_gather_bias_lod)
    FUBUKI_DECLARE_EXT(amd_shader_info)
    FUBUKI_DECLARE_EXT(khr_dynamic_rendering)
    FUBUKI_DECLARE_EXT(amd_shader_image_load_store_lod)
    FUBUKI_DECLARE_EXT(nv_corner_sampled_image)
    FUBUKI_DECLARE_EXT(khr_multiview)
    FUBUKI_DECLARE_EXT(img_format_pvrtc)
    FUBUKI_DECLARE_EXT(nv_external_memory)
    FUBUKI_DECLARE_EXT(nv_external_memory_win32)
    FUBUKI_DECLARE_EXT(nv_win32_keyed_mutex)
    FUBUKI_DECLARE_EXT(khr_device_group)
    FUBUKI_DECLARE_EXT(khr_shader_draw_parameters)
    FUBUKI_DECLARE_EXT(ext_shader_subgroup_ballot)
    FUBUKI_DECLARE_EXT(ext_shader_subgroup_vote)
    FUBUKI_DECLARE_EXT(ext_texture_compression_astc_hdr)
    FUBUKI_DECLARE_EXT(ext_astc_decode_mode)
    FUBUKI_DECLARE_EXT(ext_pipeline_robustness)
    FUBUKI_DECLARE_EXT(khr_maintenance1)
    FUBUKI_DECLARE_EXT(khr_external_memory)
    FUBUKI_DECLARE_EXT(khr_external_memory_win32)
    FUBUKI_DECLARE_EXT(khr_external_memory_fd)
    FUBUKI_DECLARE_EXT(khr_win32_keyed_mutex)
    FUBUKI_DECLARE_EXT(khr_external_semaphore)
    FUBUKI_DECLARE_EXT(khr_external_semaphore_win32)
    FUBUKI_DECLARE_EXT(khr_external_semaphore_fd)
    FUBUKI_DECLARE_EXT(khr_push_descriptor)
    FUBUKI_DECLARE_EXT(ext_conditional_rendering)
    FUBUKI_DECLARE_EXT(khr_shader_float16_int8)
    FUBUKI_DECLARE_EXT(khr_16bit_storage)
    FUBUKI_DECLARE_EXT(khr_incremental_present)
    FUBUKI_DECLARE_EXT(khr_descriptor_update_template)
    FUBUKI_DECLARE_EXT(nv_clip_space_w_scaling)
    FUBUKI_DECLARE_EXT(ext_display_control)
    FUBUKI_DECLARE_EXT(google_display_timing)
    FUBUKI_DECLARE_EXT(nv_sample_mask_override_coverage)
    FUBUKI_DECLARE_EXT(nv_geometry_shader_passthrough)
    FUBUKI_DECLARE_EXT(nv_viewport_array2)
    FUBUKI_DECLARE_EXT(nvx_multiview_per_view_attributes)
    FUBUKI_DECLARE_EXT(nv_viewport_swizzle)
    FUBUKI_DECLARE_EXT(ext_discard_rectangles)
    FUBUKI_DECLARE_EXT(ext_conservative_rasterization)
    FUBUKI_DECLARE_EXT(ext_depth_clip_enable)
    FUBUKI_DECLARE_EXT(ext_hdr_metadata)
    FUBUKI_DECLARE_EXT(khr_imageless_framebuffer)
    FUBUKI_DECLARE_EXT(khr_create_renderpass2)
    FUBUKI_DECLARE_EXT(img_relaxed_line_rasterization)
    FUBUKI_DECLARE_EXT(khr_shared_presentable_image)
    FUBUKI_DECLARE_EXT(khr_external_fence)
    FUBUKI_DECLARE_EXT(khr_external_fence_win32)
    FUBUKI_DECLARE_EXT(khr_external_fence_fd)
    FUBUKI_DECLARE_EXT(khr_performance_query)
    FUBUKI_DECLARE_EXT(khr_maintenance2)
    FUBUKI_DECLARE_EXT(khr_variable_pointers)
    FUBUKI_DECLARE_EXT(ext_external_memory_dma_buf)
    FUBUKI_DECLARE_EXT(ext_queue_family_foreign)
    FUBUKI_DECLARE_EXT(khr_dedicated_allocation)
    FUBUKI_DECLARE_EXT(android_external_memory_android_hardware_buffer)
    FUBUKI_DECLARE_EXT(ext_sampler_filter_minmax)
    FUBUKI_DECLARE_EXT(khr_storage_buffer_storage_class)
    FUBUKI_DECLARE_EXT(amd_gpu_shader_int16)
    FUBUKI_DECLARE_EXT(amdx_shader_enqueue)
    FUBUKI_DECLARE_EXT(amd_mixed_attachment_samples)
    FUBUKI_DECLARE_EXT(amd_shader_fragment_mask)
    FUBUKI_DECLARE_EXT(ext_inline_uniform_block)
    FUBUKI_DECLARE_EXT(ext_shader_stencil_export)
    FUBUKI_DECLARE_EXT(khr_shader_bfloat16)
    FUBUKI_DECLARE_EXT(ext_sample_locations)
    FUBUKI_DECLARE_EXT(khr_relaxed_block_layout)
    FUBUKI_DECLARE_EXT(khr_get_memory_requirements2)
    FUBUKI_DECLARE_EXT(khr_image_format_list)
    FUBUKI_DECLARE_EXT(ext_blend_operation_advanced)
    FUBUKI_DECLARE_EXT(nv_fragment_coverage_to_color)
    FUBUKI_DECLARE_EXT(khr_acceleration_structure)
    FUBUKI_DECLARE_EXT(khr_ray_tracing_pipeline)
    FUBUKI_DECLARE_EXT(khr_ray_query)
    FUBUKI_DECLARE_EXT(nv_framebuffer_mixed_samples)
    FUBUKI_DECLARE_EXT(nv_fill_rectangle)
    FUBUKI_DECLARE_EXT(nv_shader_sm_builtins)
    FUBUKI_DECLARE_EXT(ext_post_depth_coverage)
    FUBUKI_DECLARE_EXT(khr_sampler_ycbcr_conversion)
    FUBUKI_DECLARE_EXT(khr_bind_memory2)
    FUBUKI_DECLARE_EXT(ext_image_drm_format_modifier)
    FUBUKI_DECLARE_EXT(ext_validation_cache)
    FUBUKI_DECLARE_EXT(ext_descriptor_indexing)
    FUBUKI_DECLARE_EXT(ext_shader_viewport_index_layer)
    FUBUKI_DECLARE_EXT(khr_portability_subset)
    FUBUKI_DECLARE_EXT(nv_shading_rate_image)
    FUBUKI_DECLARE_EXT(nv_ray_tracing)
    FUBUKI_DECLARE_EXT(nv_representative_fragment_test)
    FUBUKI_DECLARE_EXT(khr_maintenance3)
    FUBUKI_DECLARE_EXT(khr_draw_indirect_count)
    FUBUKI_DECLARE_EXT(ext_filter_cubic)
    FUBUKI_DECLARE_EXT(qcom_render_pass_shader_resolve)
    FUBUKI_DECLARE_EXT(ext_global_priority)
    FUBUKI_DECLARE_EXT(khr_shader_subgroup_extended_types)
    FUBUKI_DECLARE_EXT(khr_8bit_storage)
    FUBUKI_DECLARE_EXT(ext_external_memory_host)
    FUBUKI_DECLARE_EXT(amd_buffer_marker)
    FUBUKI_DECLARE_EXT(khr_shader_atomic_int64)
    FUBUKI_DECLARE_EXT(khr_shader_clock)
    FUBUKI_DECLARE_EXT(amd_pipeline_compiler_control)
    FUBUKI_DECLARE_EXT(ext_calibrated_timestamps)
    FUBUKI_DECLARE_EXT(amd_shader_core_properties)
    FUBUKI_DECLARE_EXT(khr_video_decode_h265)
    FUBUKI_DECLARE_EXT(khr_global_priority)
    FUBUKI_DECLARE_EXT(amd_memory_overallocation_behavior)
    FUBUKI_DECLARE_EXT(ext_vertex_attribute_divisor)
    FUBUKI_DECLARE_EXT(ggp_frame_token)
    FUBUKI_DECLARE_EXT(ext_pipeline_creation_feedback)
    FUBUKI_DECLARE_EXT(khr_driver_properties)
    FUBUKI_DECLARE_EXT(khr_shader_float_controls)
    FUBUKI_DECLARE_EXT(nv_shader_subgroup_partitioned)
    FUBUKI_DECLARE_EXT(khr_depth_stencil_resolve)
    FUBUKI_DECLARE_EXT(khr_swapchain_mutable_format)
    FUBUKI_DECLARE_EXT(nv_compute_shader_derivatives)
    FUBUKI_DECLARE_EXT(nv_mesh_shader)
    FUBUKI_DECLARE_EXT(nv_fragment_shader_barycentric)
    FUBUKI_DECLARE_EXT(nv_shader_image_footprint)
    FUBUKI_DECLARE_EXT(nv_scissor_exclusive)
    FUBUKI_DECLARE_EXT(nv_device_diagnostic_checkpoints)
    FUBUKI_DECLARE_EXT(khr_timeline_semaphore)
    FUBUKI_DECLARE_EXT(intel_shader_integer_functions2)
    FUBUKI_DECLARE_EXT(intel_performance_query)
    FUBUKI_DECLARE_EXT(khr_vulkan_memory_model)
    FUBUKI_DECLARE_EXT(ext_pci_bus_info)
    FUBUKI_DECLARE_EXT(amd_display_native_hdr)
    FUBUKI_DECLARE_EXT(khr_shader_terminate_invocation)
    FUBUKI_DECLARE_EXT(ext_fragment_density_map)
    FUBUKI_DECLARE_EXT(ext_scalar_block_layout)
    FUBUKI_DECLARE_EXT(google_hlsl_functionality1)
    FUBUKI_DECLARE_EXT(google_decorate_string)
    FUBUKI_DECLARE_EXT(ext_subgroup_size_control)
    FUBUKI_DECLARE_EXT(khr_fragment_shading_rate)
    FUBUKI_DECLARE_EXT(amd_shader_core_properties2)
    FUBUKI_DECLARE_EXT(amd_device_coherent_memory)
    FUBUKI_DECLARE_EXT(khr_dynamic_rendering_local_read)
    FUBUKI_DECLARE_EXT(ext_shader_image_atomic_int64)
    FUBUKI_DECLARE_EXT(khr_shader_quad_control)
    FUBUKI_DECLARE_EXT(khr_spirv_1_4)
    FUBUKI_DECLARE_EXT(ext_memory_budget)
    FUBUKI_DECLARE_EXT(ext_memory_priority)
    FUBUKI_DECLARE_EXT(nv_dedicated_allocation_image_aliasing)
    FUBUKI_DECLARE_EXT(khr_separate_depth_stencil_layouts)
    FUBUKI_DECLARE_EXT(ext_buffer_device_address)
    FUBUKI_DECLARE_EXT(ext_tooling_info)
    FUBUKI_DECLARE_EXT(ext_separate_stencil_usage)
    FUBUKI_DECLARE_EXT(khr_present_wait)
    FUBUKI_DECLARE_EXT(nv_cooperative_matrix)
    FUBUKI_DECLARE_EXT(nv_coverage_reduction_mode)
    FUBUKI_DECLARE_EXT(ext_fragment_shader_interlock)
    FUBUKI_DECLARE_EXT(ext_ycbcr_image_arrays)
    FUBUKI_DECLARE_EXT(khr_uniform_buffer_standard_layout)
    FUBUKI_DECLARE_EXT(ext_provoking_vertex)
    FUBUKI_DECLARE_EXT(ext_full_screen_exclusive)
    FUBUKI_DECLARE_EXT(khr_buffer_device_address)
    FUBUKI_DECLARE_EXT(ext_line_rasterization)
    FUBUKI_DECLARE_EXT(ext_shader_atomic_float)
    FUBUKI_DECLARE_EXT(ext_host_query_reset)
    FUBUKI_DECLARE_EXT(ext_index_type_uint8)
    FUBUKI_DECLARE_EXT(ext_extended_dynamic_state)
    FUBUKI_DECLARE_EXT(khr_deferred_host_operations)
    FUBUKI_DECLARE_EXT(khr_pipeline_executable_properties)
    FUBUKI_DECLARE_EXT(ext_host_image_copy)
    FUBUKI_DECLARE_EXT(khr_map_memory2)
    FUBUKI_DECLARE_EXT(ext_map_memory_placed)
    FUBUKI_DECLARE_EXT(ext_shader_atomic_float2)
    FUBUKI_DECLARE_EXT(ext_swapchain_maintenance1)
    FUBUKI_DECLARE_EXT(ext_shader_demote_to_helper_invocation)
    FUBUKI_DECLARE_EXT(nv_device_generated_commands)
    FUBUKI_DECLARE_EXT(nv_inherited_viewport_scissor)
    FUBUKI_DECLARE_EXT(khr_shader_integer_dot_product)
    FUBUKI_DECLARE_EXT(ext_texel_buffer_alignment)
    FUBUKI_DECLARE_EXT(qcom_render_pass_transform)
    FUBUKI_DECLARE_EXT(ext_depth_bias_control)
    FUBUKI_DECLARE_EXT(ext_device_memory_report)
    FUBUKI_DECLARE_EXT(ext_robustness2)
    FUBUKI_DECLARE_EXT(ext_custom_border_color)
    FUBUKI_DECLARE_EXT(google_user_type)
    FUBUKI_DECLARE_EXT(khr_pipeline_library)
    FUBUKI_DECLARE_EXT(nv_present_barrier)
    FUBUKI_DECLARE_EXT(khr_shader_non_semantic_info)
    FUBUKI_DECLARE_EXT(khr_present_id)
    FUBUKI_DECLARE_EXT(ext_private_data)
    FUBUKI_DECLARE_EXT(ext_pipeline_creation_cache_control)
    FUBUKI_DECLARE_EXT(khr_video_encode_queue)
    FUBUKI_DECLARE_EXT(nv_device_diagnostics_config)
    FUBUKI_DECLARE_EXT(qcom_render_pass_store_ops)
    FUBUKI_DECLARE_EXT(nv_cuda_kernel_launch)
    FUBUKI_DECLARE_EXT(nv_low_latency)
    FUBUKI_DECLARE_EXT(ext_metal_objects)
    FUBUKI_DECLARE_EXT(khr_synchronization2)
    FUBUKI_DECLARE_EXT(ext_descriptor_buffer)
    FUBUKI_DECLARE_EXT(ext_graphics_pipeline_library)
    FUBUKI_DECLARE_EXT(amd_shader_early_and_late_fragment_tests)
    FUBUKI_DECLARE_EXT(khr_fragment_shader_barycentric)
    FUBUKI_DECLARE_EXT(khr_shader_subgroup_uniform_control_flow)
    FUBUKI_DECLARE_EXT(khr_zero_initialize_workgroup_memory)
    FUBUKI_DECLARE_EXT(nv_fragment_shading_rate_enums)
    FUBUKI_DECLARE_EXT(nv_ray_tracing_motion_blur)
    FUBUKI_DECLARE_EXT(ext_mesh_shader)
    FUBUKI_DECLARE_EXT(ext_ycbcr_2plane_444_formats)
    FUBUKI_DECLARE_EXT(ext_fragment_density_map2)
    FUBUKI_DECLARE_EXT(qcom_rotated_copy_commands)
    FUBUKI_DECLARE_EXT(ext_image_robustness)
    FUBUKI_DECLARE_EXT(khr_workgroup_memory_explicit_layout)
    FUBUKI_DECLARE_EXT(khr_copy_commands2)
    FUBUKI_DECLARE_EXT(ext_image_compression_control)
    FUBUKI_DECLARE_EXT(ext_attachment_feedback_loop_layout)
    FUBUKI_DECLARE_EXT(ext_4444_formats)
    FUBUKI_DECLARE_EXT(ext_device_fault)
    FUBUKI_DECLARE_EXT(arm_rasterization_order_attachment_access)
    FUBUKI_DECLARE_EXT(ext_rgba10x6_formats)
    FUBUKI_DECLARE_EXT(nv_acquire_winrt_display)
    FUBUKI_DECLARE_EXT(valve_mutable_descriptor_type)
    FUBUKI_DECLARE_EXT(ext_vertex_input_dynamic_state)
    FUBUKI_DECLARE_EXT(ext_physical_device_drm)
    FUBUKI_DECLARE_EXT(ext_device_address_binding_report)
    FUBUKI_DECLARE_EXT(ext_depth_clip_control)
    FUBUKI_DECLARE_EXT(ext_primitive_topology_list_restart)
    FUBUKI_DECLARE_EXT(khr_format_feature_flags2)
    FUBUKI_DECLARE_EXT(ext_present_mode_fifo_latest_ready)
    FUBUKI_DECLARE_EXT(fuchsia_external_memory)
    FUBUKI_DECLARE_EXT(fuchsia_external_semaphore)
    FUBUKI_DECLARE_EXT(fuchsia_buffer_collection)
    FUBUKI_DECLARE_EXT(huawei_subpass_shading)
    FUBUKI_DECLARE_EXT(huawei_invocation_mask)
    FUBUKI_DECLARE_EXT(nv_external_memory_rdma)
    FUBUKI_DECLARE_EXT(ext_pipeline_properties)
    FUBUKI_DECLARE_EXT(ext_frame_boundary)
    FUBUKI_DECLARE_EXT(ext_multisampled_render_to_single_sampled)
    FUBUKI_DECLARE_EXT(ext_extended_dynamic_state2)
    FUBUKI_DECLARE_EXT(ext_color_write_enable)
    FUBUKI_DECLARE_EXT(ext_primitives_generated_query)
    FUBUKI_DECLARE_EXT(khr_ray_tracing_maintenance1)
    FUBUKI_DECLARE_EXT(ext_global_priority_query)
    FUBUKI_DECLARE_EXT(ext_image_view_min_lod)
    FUBUKI_DECLARE_EXT(ext_multi_draw)
    FUBUKI_DECLARE_EXT(ext_image_2d_view_of_3d)
    FUBUKI_DECLARE_EXT(ext_shader_tile_image)
    FUBUKI_DECLARE_EXT(ext_opacity_micromap)
    FUBUKI_DECLARE_EXT(nv_displacement_micromap)
    FUBUKI_DECLARE_EXT(ext_load_store_op_none)
    FUBUKI_DECLARE_EXT(huawei_cluster_culling_shader)
    FUBUKI_DECLARE_EXT(ext_border_color_swizzle)
    FUBUKI_DECLARE_EXT(ext_pageable_device_local_memory)
    FUBUKI_DECLARE_EXT(khr_maintenance4)
    FUBUKI_DECLARE_EXT(arm_shader_core_properties)
    FUBUKI_DECLARE_EXT(khr_shader_subgroup_rotate)
    FUBUKI_DECLARE_EXT(arm_scheduling_controls)
    FUBUKI_DECLARE_EXT(ext_image_sliced_view_of_3d)
    FUBUKI_DECLARE_EXT(valve_descriptor_set_host_mapping)
    FUBUKI_DECLARE_EXT(ext_depth_clamp_zero_one)
    FUBUKI_DECLARE_EXT(ext_non_seamless_cube_map)
    FUBUKI_DECLARE_EXT(arm_render_pass_striped)
    FUBUKI_DECLARE_EXT(qcom_fragment_density_map_offset)
    FUBUKI_DECLARE_EXT(nv_copy_memory_indirect)
    FUBUKI_DECLARE_EXT(nv_memory_decompression)
    FUBUKI_DECLARE_EXT(nv_device_generated_commands_compute)
    FUBUKI_DECLARE_EXT(nv_ray_tracing_linear_swept_spheres)
    FUBUKI_DECLARE_EXT(nv_linear_color_attachment)
    FUBUKI_DECLARE_EXT(khr_shader_maximal_reconvergence)
    FUBUKI_DECLARE_EXT(ext_image_compression_control_swapchain)
    FUBUKI_DECLARE_EXT(qcom_image_processing)
    FUBUKI_DECLARE_EXT(ext_nested_command_buffer)
    FUBUKI_DECLARE_EXT(ext_external_memory_acquire_unmodified)
    FUBUKI_DECLARE_EXT(ext_extended_dynamic_state3)
    FUBUKI_DECLARE_EXT(ext_subpass_merge_feedback)
    FUBUKI_DECLARE_EXT(ext_shader_module_identifier)
    FUBUKI_DECLARE_EXT(ext_rasterization_order_attachment_access)
    FUBUKI_DECLARE_EXT(nv_optical_flow)
    FUBUKI_DECLARE_EXT(ext_legacy_dithering)
    FUBUKI_DECLARE_EXT(ext_pipeline_protected_access)
    FUBUKI_DECLARE_EXT(android_external_format_resolve)
    FUBUKI_DECLARE_EXT(khr_maintenance5)
    FUBUKI_DECLARE_EXT(amd_anti_lag)
    FUBUKI_DECLARE_EXT(khr_ray_tracing_position_fetch)
    FUBUKI_DECLARE_EXT(ext_shader_object)
    FUBUKI_DECLARE_EXT(khr_pipeline_binary)
    FUBUKI_DECLARE_EXT(qcom_tile_properties)
    FUBUKI_DECLARE_EXT(sec_amigo_profiling)
    FUBUKI_DECLARE_EXT(qcom_multiview_per_view_viewports)
    FUBUKI_DECLARE_EXT(nv_ray_tracing_invocation_reorder)
    FUBUKI_DECLARE_EXT(nv_cooperative_vector)
    FUBUKI_DECLARE_EXT(nv_extended_sparse_address_space)
    FUBUKI_DECLARE_EXT(ext_mutable_descriptor_type)
    FUBUKI_DECLARE_EXT(ext_legacy_vertex_attributes)
    FUBUKI_DECLARE_EXT(arm_shader_core_builtins)
    FUBUKI_DECLARE_EXT(ext_pipeline_library_group_handles)
    FUBUKI_DECLARE_EXT(ext_dynamic_rendering_unused_attachments)
    FUBUKI_DECLARE_EXT(nv_low_latency2)
    FUBUKI_DECLARE_EXT(khr_cooperative_matrix)
    FUBUKI_DECLARE_EXT(qcom_multiview_per_view_render_areas)
    FUBUKI_DECLARE_EXT(khr_compute_shader_derivatives)
    FUBUKI_DECLARE_EXT(khr_video_decode_av1)
    FUBUKI_DECLARE_EXT(khr_video_encode_av1)
    FUBUKI_DECLARE_EXT(khr_video_maintenance1)
    FUBUKI_DECLARE_EXT(nv_per_stage_descriptor_set)
    FUBUKI_DECLARE_EXT(qcom_image_processing2)
    FUBUKI_DECLARE_EXT(qcom_filter_cubic_weights)
    FUBUKI_DECLARE_EXT(qcom_ycbcr_degamma)
    FUBUKI_DECLARE_EXT(qcom_filter_cubic_clamp)
    FUBUKI_DECLARE_EXT(ext_attachment_feedback_loop_dynamic_state)
    FUBUKI_DECLARE_EXT(khr_vertex_attribute_divisor)
    FUBUKI_DECLARE_EXT(khr_load_store_op_none)
    FUBUKI_DECLARE_EXT(khr_shader_float_controls2)
    FUBUKI_DECLARE_EXT(qnx_external_memory_screen_buffer)
    FUBUKI_DECLARE_EXT(msft_layered_driver)
    FUBUKI_DECLARE_EXT(khr_index_type_uint8)
    FUBUKI_DECLARE_EXT(khr_line_rasterization)
    FUBUKI_DECLARE_EXT(khr_calibrated_timestamps)
    FUBUKI_DECLARE_EXT(khr_shader_expect_assume)
    FUBUKI_DECLARE_EXT(khr_maintenance6)
    FUBUKI_DECLARE_EXT(nv_descriptor_pool_overallocation)
    FUBUKI_DECLARE_EXT(khr_video_encode_quantization_map)
    FUBUKI_DECLARE_EXT(nv_raw_access_chains)
    FUBUKI_DECLARE_EXT(khr_shader_relaxed_extended_instruction)
    FUBUKI_DECLARE_EXT(nv_command_buffer_inheritance)
    FUBUKI_DECLARE_EXT(khr_maintenance7)
    FUBUKI_DECLARE_EXT(nv_shader_atomic_float16_vector)
    FUBUKI_DECLARE_EXT(ext_shader_replicated_composites)
    FUBUKI_DECLARE_EXT(nv_ray_tracing_validation)
    FUBUKI_DECLARE_EXT(nv_cluster_acceleration_structure)
    FUBUKI_DECLARE_EXT(nv_partitioned_acceleration_structure)
    FUBUKI_DECLARE_EXT(ext_device_generated_commands)
    FUBUKI_DECLARE_EXT(khr_maintenance8)
    FUBUKI_DECLARE_EXT(mesa_image_alignment_control)
    FUBUKI_DECLARE_EXT(ext_depth_clamp_control)
    FUBUKI_DECLARE_EXT(khr_video_maintenance2)
    FUBUKI_DECLARE_EXT(huawei_hdr_vivid)
    FUBUKI_DECLARE_EXT(nv_cooperative_matrix2)
    FUBUKI_DECLARE_EXT(arm_pipeline_opacity_micromap)
    FUBUKI_DECLARE_EXT(ext_external_memory_metal)
    FUBUKI_DECLARE_EXT(khr_depth_clamp_zero_one)
    FUBUKI_DECLARE_EXT(ext_vertex_attribute_robustness)
    FUBUKI_DECLARE_EXT(nv_present_metering)
    FUBUKI_DECLARE_EXT(ext_fragment_density_map_offset)

    FUBUKI_EXTENSION_API
    device_functions();

    FUBUKI_EXTENSION_API
    device_functions(device_functions&&) noexcept;

    FUBUKI_EXTENSION_API
    device_functions& operator=(device_functions&&) noexcept;

    FUBUKI_EXTENSION_API
    ~device_functions();

    device_functions(const device_functions&)            = delete;
    device_functions& operator=(const device_functions&) = delete;
};

#undef FUBUKI_DECLARE_EXT

//------------------------------------------------------------------------------

/// Loads an extension functions, if Fubuki supports it.
/// @returns A boolean indicating if the operation succeeded.
[[nodiscard]] FUBUKI_EXTENSION_API bool
load(device_functions& functions, instance_handle instance, version_number version, device_handle device, std::string_view extension);

} // namespace extension

using device_ext_functions = extension::device_functions;

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

#if defined(VK_KHR_swapchain)
template<>
struct get_from<extension::device_functions, "vkCreateSwapchainKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateSwapchainKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkCreateSwapchainKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkCreateSwapchainKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct get_from<extension::device_functions, "vkDestroySwapchainKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroySwapchainKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkDestroySwapchainKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkDestroySwapchainKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct get_from<extension::device_functions, "vkGetSwapchainImagesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSwapchainImagesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkGetSwapchainImagesKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkGetSwapchainImagesKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct get_from<extension::device_functions, "vkAcquireNextImageKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquireNextImageKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkAcquireNextImageKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkAcquireNextImageKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct get_from<extension::device_functions, "vkQueuePresentKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkQueuePresentKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkQueuePresentKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkQueuePresentKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_swapchain) or defined(VK_KHR_device_group)
template<>
struct get_from<extension::device_functions, "vkGetDeviceGroupPresentCapabilitiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceGroupPresentCapabilitiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkGetDeviceGroupPresentCapabilitiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkGetDeviceGroupPresentCapabilitiesKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

    #if defined(VK_KHR_device_group)
        if(functions.khr_device_group)
        {
            static_assert(
                requires {
                    { functions.khr_device_group };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group, "vkGetDeviceGroupPresentCapabilitiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group, "vkGetDeviceGroupPresentCapabilitiesKHR">::get(*functions.khr_device_group);
        }
    #endif // defined(VK_KHR_device_group)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)or defined(VK_KHR_device_group)

#if defined(VK_KHR_swapchain) or defined(VK_KHR_device_group)
template<>
struct get_from<extension::device_functions, "vkGetDeviceGroupSurfacePresentModesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceGroupSurfacePresentModesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkGetDeviceGroupSurfacePresentModesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkGetDeviceGroupSurfacePresentModesKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

    #if defined(VK_KHR_device_group)
        if(functions.khr_device_group)
        {
            static_assert(
                requires {
                    { functions.khr_device_group };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group, "vkGetDeviceGroupSurfacePresentModesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group, "vkGetDeviceGroupSurfacePresentModesKHR">::get(*functions.khr_device_group);
        }
    #endif // defined(VK_KHR_device_group)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)or defined(VK_KHR_device_group)

#if defined(VK_KHR_swapchain) or defined(VK_KHR_device_group)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDevicePresentRectanglesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDevicePresentRectanglesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkGetPhysicalDevicePresentRectanglesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkGetPhysicalDevicePresentRectanglesKHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

    #if defined(VK_KHR_device_group)
        if(functions.khr_device_group)
        {
            static_assert(
                requires {
                    { functions.khr_device_group };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group, "vkGetPhysicalDevicePresentRectanglesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group, "vkGetPhysicalDevicePresentRectanglesKHR">::get(*functions.khr_device_group);
        }
    #endif // defined(VK_KHR_device_group)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)or defined(VK_KHR_device_group)

#if defined(VK_KHR_swapchain) or defined(VK_KHR_device_group)
template<>
struct get_from<extension::device_functions, "vkAcquireNextImage2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquireNextImage2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_swapchain)
        if(functions.khr_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_swapchain, "vkAcquireNextImage2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_swapchain, "vkAcquireNextImage2KHR">::get(*functions.khr_swapchain);
        }
    #endif // defined(VK_KHR_swapchain)

    #if defined(VK_KHR_device_group)
        if(functions.khr_device_group)
        {
            static_assert(
                requires {
                    { functions.khr_device_group };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group, "vkAcquireNextImage2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group, "vkAcquireNextImage2KHR">::get(*functions.khr_device_group);
        }
    #endif // defined(VK_KHR_device_group)

        return nullptr;
    }
};
#endif // defined(VK_KHR_swapchain)or defined(VK_KHR_device_group)

#if defined(VK_KHR_display_swapchain)
template<>
struct get_from<extension::device_functions, "vkCreateSharedSwapchainsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateSharedSwapchainsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_display_swapchain)
        if(functions.khr_display_swapchain)
        {
            static_assert(
                requires {
                    { functions.khr_display_swapchain };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display_swapchain, "vkCreateSharedSwapchainsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display_swapchain, "vkCreateSharedSwapchainsKHR">::get(*functions.khr_display_swapchain);
        }
    #endif // defined(VK_KHR_display_swapchain)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display_swapchain)

#if defined(VK_EXT_debug_marker)
template<>
struct get_from<extension::device_functions, "vkDebugMarkerSetObjectTagEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDebugMarkerSetObjectTagEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_marker)
        if(functions.ext_debug_marker)
        {
            static_assert(
                requires {
                    { functions.ext_debug_marker };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_marker, "vkDebugMarkerSetObjectTagEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_marker, "vkDebugMarkerSetObjectTagEXT">::get(*functions.ext_debug_marker);
        }
    #endif // defined(VK_EXT_debug_marker)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct get_from<extension::device_functions, "vkDebugMarkerSetObjectNameEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDebugMarkerSetObjectNameEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_marker)
        if(functions.ext_debug_marker)
        {
            static_assert(
                requires {
                    { functions.ext_debug_marker };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_marker, "vkDebugMarkerSetObjectNameEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_marker, "vkDebugMarkerSetObjectNameEXT">::get(*functions.ext_debug_marker);
        }
    #endif // defined(VK_EXT_debug_marker)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct get_from<extension::device_functions, "vkCmdDebugMarkerBeginEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDebugMarkerBeginEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_marker)
        if(functions.ext_debug_marker)
        {
            static_assert(
                requires {
                    { functions.ext_debug_marker };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_marker, "vkCmdDebugMarkerBeginEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_marker, "vkCmdDebugMarkerBeginEXT">::get(*functions.ext_debug_marker);
        }
    #endif // defined(VK_EXT_debug_marker)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct get_from<extension::device_functions, "vkCmdDebugMarkerEndEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDebugMarkerEndEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_marker)
        if(functions.ext_debug_marker)
        {
            static_assert(
                requires {
                    { functions.ext_debug_marker };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_marker, "vkCmdDebugMarkerEndEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_marker, "vkCmdDebugMarkerEndEXT">::get(*functions.ext_debug_marker);
        }
    #endif // defined(VK_EXT_debug_marker)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct get_from<extension::device_functions, "vkCmdDebugMarkerInsertEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDebugMarkerInsertEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_marker)
        if(functions.ext_debug_marker)
        {
            static_assert(
                requires {
                    { functions.ext_debug_marker };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_marker, "vkCmdDebugMarkerInsertEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_marker, "vkCmdDebugMarkerInsertEXT">::get(*functions.ext_debug_marker);
        }
    #endif // defined(VK_EXT_debug_marker)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_marker)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceVideoCapabilitiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkGetPhysicalDeviceVideoCapabilitiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkGetPhysicalDeviceVideoCapabilitiesKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceVideoFormatPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkGetPhysicalDeviceVideoFormatPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkGetPhysicalDeviceVideoFormatPropertiesKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkCreateVideoSessionKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateVideoSessionKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkCreateVideoSessionKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkCreateVideoSessionKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkDestroyVideoSessionKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyVideoSessionKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkDestroyVideoSessionKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkDestroyVideoSessionKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkGetVideoSessionMemoryRequirementsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetVideoSessionMemoryRequirementsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkGetVideoSessionMemoryRequirementsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkGetVideoSessionMemoryRequirementsKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkBindVideoSessionMemoryKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkBindVideoSessionMemoryKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkBindVideoSessionMemoryKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkBindVideoSessionMemoryKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkCreateVideoSessionParametersKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateVideoSessionParametersKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkCreateVideoSessionParametersKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkCreateVideoSessionParametersKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkUpdateVideoSessionParametersKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkUpdateVideoSessionParametersKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkUpdateVideoSessionParametersKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkUpdateVideoSessionParametersKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkDestroyVideoSessionParametersKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyVideoSessionParametersKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkDestroyVideoSessionParametersKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkDestroyVideoSessionParametersKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkCmdBeginVideoCodingKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBeginVideoCodingKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkCmdBeginVideoCodingKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkCmdBeginVideoCodingKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkCmdEndVideoCodingKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndVideoCodingKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkCmdEndVideoCodingKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkCmdEndVideoCodingKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct get_from<extension::device_functions, "vkCmdControlVideoCodingKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdControlVideoCodingKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_queue)
        if(functions.khr_video_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_queue, "vkCmdControlVideoCodingKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_queue, "vkCmdControlVideoCodingKHR">::get(*functions.khr_video_queue);
        }
    #endif // defined(VK_KHR_video_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_decode_queue)
template<>
struct get_from<extension::device_functions, "vkCmdDecodeVideoKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDecodeVideoKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_decode_queue)
        if(functions.khr_video_decode_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_decode_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_decode_queue, "vkCmdDecodeVideoKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_decode_queue, "vkCmdDecodeVideoKHR">::get(*functions.khr_video_decode_queue);
        }
    #endif // defined(VK_KHR_video_decode_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_decode_queue)

#if defined(VK_EXT_transform_feedback)
template<>
struct get_from<extension::device_functions, "vkCmdBindTransformFeedbackBuffersEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindTransformFeedbackBuffersEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_transform_feedback)
        if(functions.ext_transform_feedback)
        {
            static_assert(
                requires {
                    { functions.ext_transform_feedback };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_transform_feedback, "vkCmdBindTransformFeedbackBuffersEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_transform_feedback, "vkCmdBindTransformFeedbackBuffersEXT">::get(
                *functions.ext_transform_feedback);
        }
    #endif // defined(VK_EXT_transform_feedback)

        return nullptr;
    }
};
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct get_from<extension::device_functions, "vkCmdBeginTransformFeedbackEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBeginTransformFeedbackEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_transform_feedback)
        if(functions.ext_transform_feedback)
        {
            static_assert(
                requires {
                    { functions.ext_transform_feedback };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_transform_feedback, "vkCmdBeginTransformFeedbackEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_transform_feedback, "vkCmdBeginTransformFeedbackEXT">::get(*functions.ext_transform_feedback);
        }
    #endif // defined(VK_EXT_transform_feedback)

        return nullptr;
    }
};
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct get_from<extension::device_functions, "vkCmdEndTransformFeedbackEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndTransformFeedbackEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_transform_feedback)
        if(functions.ext_transform_feedback)
        {
            static_assert(
                requires {
                    { functions.ext_transform_feedback };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_transform_feedback, "vkCmdEndTransformFeedbackEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_transform_feedback, "vkCmdEndTransformFeedbackEXT">::get(*functions.ext_transform_feedback);
        }
    #endif // defined(VK_EXT_transform_feedback)

        return nullptr;
    }
};
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct get_from<extension::device_functions, "vkCmdBeginQueryIndexedEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBeginQueryIndexedEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_transform_feedback)
        if(functions.ext_transform_feedback)
        {
            static_assert(
                requires {
                    { functions.ext_transform_feedback };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_transform_feedback, "vkCmdBeginQueryIndexedEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_transform_feedback, "vkCmdBeginQueryIndexedEXT">::get(*functions.ext_transform_feedback);
        }
    #endif // defined(VK_EXT_transform_feedback)

        return nullptr;
    }
};
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct get_from<extension::device_functions, "vkCmdEndQueryIndexedEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndQueryIndexedEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_transform_feedback)
        if(functions.ext_transform_feedback)
        {
            static_assert(
                requires {
                    { functions.ext_transform_feedback };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_transform_feedback, "vkCmdEndQueryIndexedEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_transform_feedback, "vkCmdEndQueryIndexedEXT">::get(*functions.ext_transform_feedback);
        }
    #endif // defined(VK_EXT_transform_feedback)

        return nullptr;
    }
};
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct get_from<extension::device_functions, "vkCmdDrawIndirectByteCountEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawIndirectByteCountEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_transform_feedback)
        if(functions.ext_transform_feedback)
        {
            static_assert(
                requires {
                    { functions.ext_transform_feedback };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_transform_feedback, "vkCmdDrawIndirectByteCountEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_transform_feedback, "vkCmdDrawIndirectByteCountEXT">::get(*functions.ext_transform_feedback);
        }
    #endif // defined(VK_EXT_transform_feedback)

        return nullptr;
    }
};
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_NVX_binary_import)
template<>
struct get_from<extension::device_functions, "vkCreateCuModuleNVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateCuModuleNVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_binary_import)
        if(functions.nvx_binary_import)
        {
            static_assert(
                requires {
                    { functions.nvx_binary_import };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_binary_import, "vkCreateCuModuleNVX">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_binary_import, "vkCreateCuModuleNVX">::get(*functions.nvx_binary_import);
        }
    #endif // defined(VK_NVX_binary_import)

        return nullptr;
    }
};
#endif // defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct get_from<extension::device_functions, "vkCreateCuFunctionNVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateCuFunctionNVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_binary_import)
        if(functions.nvx_binary_import)
        {
            static_assert(
                requires {
                    { functions.nvx_binary_import };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_binary_import, "vkCreateCuFunctionNVX">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_binary_import, "vkCreateCuFunctionNVX">::get(*functions.nvx_binary_import);
        }
    #endif // defined(VK_NVX_binary_import)

        return nullptr;
    }
};
#endif // defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct get_from<extension::device_functions, "vkDestroyCuModuleNVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyCuModuleNVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_binary_import)
        if(functions.nvx_binary_import)
        {
            static_assert(
                requires {
                    { functions.nvx_binary_import };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_binary_import, "vkDestroyCuModuleNVX">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_binary_import, "vkDestroyCuModuleNVX">::get(*functions.nvx_binary_import);
        }
    #endif // defined(VK_NVX_binary_import)

        return nullptr;
    }
};
#endif // defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct get_from<extension::device_functions, "vkDestroyCuFunctionNVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyCuFunctionNVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_binary_import)
        if(functions.nvx_binary_import)
        {
            static_assert(
                requires {
                    { functions.nvx_binary_import };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_binary_import, "vkDestroyCuFunctionNVX">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_binary_import, "vkDestroyCuFunctionNVX">::get(*functions.nvx_binary_import);
        }
    #endif // defined(VK_NVX_binary_import)

        return nullptr;
    }
};
#endif // defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct get_from<extension::device_functions, "vkCmdCuLaunchKernelNVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCuLaunchKernelNVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_binary_import)
        if(functions.nvx_binary_import)
        {
            static_assert(
                requires {
                    { functions.nvx_binary_import };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_binary_import, "vkCmdCuLaunchKernelNVX">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_binary_import, "vkCmdCuLaunchKernelNVX">::get(*functions.nvx_binary_import);
        }
    #endif // defined(VK_NVX_binary_import)

        return nullptr;
    }
};
#endif // defined(VK_NVX_binary_import)

#if defined(VK_NVX_image_view_handle)
template<>
struct get_from<extension::device_functions, "vkGetImageViewHandleNVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageViewHandleNVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_image_view_handle)
        if(functions.nvx_image_view_handle)
        {
            static_assert(
                requires {
                    { functions.nvx_image_view_handle };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_image_view_handle, "vkGetImageViewHandleNVX">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_image_view_handle, "vkGetImageViewHandleNVX">::get(*functions.nvx_image_view_handle);
        }
    #endif // defined(VK_NVX_image_view_handle)

        return nullptr;
    }
};
#endif // defined(VK_NVX_image_view_handle)

#if defined(VK_NVX_image_view_handle)
template<>
struct get_from<extension::device_functions, "vkGetImageViewHandle64NVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageViewHandle64NVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_image_view_handle)
        if(functions.nvx_image_view_handle)
        {
            static_assert(
                requires {
                    { functions.nvx_image_view_handle };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_image_view_handle, "vkGetImageViewHandle64NVX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_image_view_handle, "vkGetImageViewHandle64NVX">::get(*functions.nvx_image_view_handle);
        }
    #endif // defined(VK_NVX_image_view_handle)

        return nullptr;
    }
};
#endif // defined(VK_NVX_image_view_handle)

#if defined(VK_NVX_image_view_handle)
template<>
struct get_from<extension::device_functions, "vkGetImageViewAddressNVX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageViewAddressNVX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NVX_image_view_handle)
        if(functions.nvx_image_view_handle)
        {
            static_assert(
                requires {
                    { functions.nvx_image_view_handle };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nvx_image_view_handle, "vkGetImageViewAddressNVX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nvx_image_view_handle, "vkGetImageViewAddressNVX">::get(*functions.nvx_image_view_handle);
        }
    #endif // defined(VK_NVX_image_view_handle)

        return nullptr;
    }
};
#endif // defined(VK_NVX_image_view_handle)

#if defined(VK_AMD_draw_indirect_count)
template<>
struct get_from<extension::device_functions, "vkCmdDrawIndirectCountAMD">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawIndirectCountAMD get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMD_draw_indirect_count)
        if(functions.amd_draw_indirect_count)
        {
            static_assert(
                requires {
                    { functions.amd_draw_indirect_count };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amd_draw_indirect_count, "vkCmdDrawIndirectCountAMD">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amd_draw_indirect_count, "vkCmdDrawIndirectCountAMD">::get(*functions.amd_draw_indirect_count);
        }
    #endif // defined(VK_AMD_draw_indirect_count)

        return nullptr;
    }
};
#endif // defined(VK_AMD_draw_indirect_count)

#if defined(VK_AMD_draw_indirect_count)
template<>
struct get_from<extension::device_functions, "vkCmdDrawIndexedIndirectCountAMD">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawIndexedIndirectCountAMD get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMD_draw_indirect_count)
        if(functions.amd_draw_indirect_count)
        {
            static_assert(
                requires {
                    { functions.amd_draw_indirect_count };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amd_draw_indirect_count, "vkCmdDrawIndexedIndirectCountAMD">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amd_draw_indirect_count, "vkCmdDrawIndexedIndirectCountAMD">::get(
                *functions.amd_draw_indirect_count);
        }
    #endif // defined(VK_AMD_draw_indirect_count)

        return nullptr;
    }
};
#endif // defined(VK_AMD_draw_indirect_count)

#if defined(VK_AMD_shader_info)
template<>
struct get_from<extension::device_functions, "vkGetShaderInfoAMD">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetShaderInfoAMD get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMD_shader_info)
        if(functions.amd_shader_info)
        {
            static_assert(
                requires {
                    { functions.amd_shader_info };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amd_shader_info, "vkGetShaderInfoAMD">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::amd_shader_info, "vkGetShaderInfoAMD">::get(*functions.amd_shader_info);
        }
    #endif // defined(VK_AMD_shader_info)

        return nullptr;
    }
};
#endif // defined(VK_AMD_shader_info)

#if defined(VK_KHR_dynamic_rendering)
template<>
struct get_from<extension::device_functions, "vkCmdBeginRenderingKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBeginRenderingKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_dynamic_rendering)
        if(functions.khr_dynamic_rendering)
        {
            static_assert(
                requires {
                    { functions.khr_dynamic_rendering };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_dynamic_rendering, "vkCmdBeginRenderingKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_dynamic_rendering, "vkCmdBeginRenderingKHR">::get(*functions.khr_dynamic_rendering);
        }
    #endif // defined(VK_KHR_dynamic_rendering)

        return nullptr;
    }
};
#endif // defined(VK_KHR_dynamic_rendering)

#if defined(VK_KHR_dynamic_rendering)
template<>
struct get_from<extension::device_functions, "vkCmdEndRenderingKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndRenderingKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_dynamic_rendering)
        if(functions.khr_dynamic_rendering)
        {
            static_assert(
                requires {
                    { functions.khr_dynamic_rendering };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_dynamic_rendering, "vkCmdEndRenderingKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_dynamic_rendering, "vkCmdEndRenderingKHR">::get(*functions.khr_dynamic_rendering);
        }
    #endif // defined(VK_KHR_dynamic_rendering)

        return nullptr;
    }
};
#endif // defined(VK_KHR_dynamic_rendering)

#if defined(VK_NV_external_memory_win32)
template<>
struct get_from<extension::device_functions, "vkGetMemoryWin32HandleNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryWin32HandleNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_external_memory_win32)
        if(functions.nv_external_memory_win32)
        {
            static_assert(
                requires {
                    { functions.nv_external_memory_win32 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_external_memory_win32, "vkGetMemoryWin32HandleNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_external_memory_win32, "vkGetMemoryWin32HandleNV">::get(*functions.nv_external_memory_win32);
        }
    #endif // defined(VK_NV_external_memory_win32)

        return nullptr;
    }
};
#endif // defined(VK_NV_external_memory_win32)

#if defined(VK_KHR_device_group)
template<>
struct get_from<extension::device_functions, "vkGetDeviceGroupPeerMemoryFeaturesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_device_group)
        if(functions.khr_device_group)
        {
            static_assert(
                requires {
                    { functions.khr_device_group };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group, "vkGetDeviceGroupPeerMemoryFeaturesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group, "vkGetDeviceGroupPeerMemoryFeaturesKHR">::get(*functions.khr_device_group);
        }
    #endif // defined(VK_KHR_device_group)

        return nullptr;
    }
};
#endif // defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
template<>
struct get_from<extension::device_functions, "vkCmdSetDeviceMaskKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDeviceMaskKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_device_group)
        if(functions.khr_device_group)
        {
            static_assert(
                requires {
                    { functions.khr_device_group };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group, "vkCmdSetDeviceMaskKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group, "vkCmdSetDeviceMaskKHR">::get(*functions.khr_device_group);
        }
    #endif // defined(VK_KHR_device_group)

        return nullptr;
    }
};
#endif // defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
template<>
struct get_from<extension::device_functions, "vkCmdDispatchBaseKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDispatchBaseKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_device_group)
        if(functions.khr_device_group)
        {
            static_assert(
                requires {
                    { functions.khr_device_group };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group, "vkCmdDispatchBaseKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group, "vkCmdDispatchBaseKHR">::get(*functions.khr_device_group);
        }
    #endif // defined(VK_KHR_device_group)

        return nullptr;
    }
};
#endif // defined(VK_KHR_device_group)

#if defined(VK_KHR_maintenance1)
template<>
struct get_from<extension::device_functions, "vkTrimCommandPoolKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkTrimCommandPoolKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance1)
        if(functions.khr_maintenance1)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance1 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance1, "vkTrimCommandPoolKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance1, "vkTrimCommandPoolKHR">::get(*functions.khr_maintenance1);
        }
    #endif // defined(VK_KHR_maintenance1)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance1)

#if defined(VK_KHR_external_memory_win32)
template<>
struct get_from<extension::device_functions, "vkGetMemoryWin32HandleKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryWin32HandleKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_memory_win32)
        if(functions.khr_external_memory_win32)
        {
            static_assert(
                requires {
                    { functions.khr_external_memory_win32 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_memory_win32, "vkGetMemoryWin32HandleKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_memory_win32, "vkGetMemoryWin32HandleKHR">::get(*functions.khr_external_memory_win32);
        }
    #endif // defined(VK_KHR_external_memory_win32)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
template<>
struct get_from<extension::device_functions, "vkGetMemoryWin32HandlePropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryWin32HandlePropertiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_memory_win32)
        if(functions.khr_external_memory_win32)
        {
            static_assert(
                requires {
                    { functions.khr_external_memory_win32 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_memory_win32, "vkGetMemoryWin32HandlePropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_memory_win32, "vkGetMemoryWin32HandlePropertiesKHR">::get(
                *functions.khr_external_memory_win32);
        }
    #endif // defined(VK_KHR_external_memory_win32)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)
template<>
struct get_from<extension::device_functions, "vkGetMemoryFdKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryFdKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_memory_fd)
        if(functions.khr_external_memory_fd)
        {
            static_assert(
                requires {
                    { functions.khr_external_memory_fd };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_memory_fd, "vkGetMemoryFdKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_memory_fd, "vkGetMemoryFdKHR">::get(*functions.khr_external_memory_fd);
        }
    #endif // defined(VK_KHR_external_memory_fd)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
template<>
struct get_from<extension::device_functions, "vkGetMemoryFdPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryFdPropertiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_memory_fd)
        if(functions.khr_external_memory_fd)
        {
            static_assert(
                requires {
                    { functions.khr_external_memory_fd };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_memory_fd, "vkGetMemoryFdPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_memory_fd, "vkGetMemoryFdPropertiesKHR">::get(*functions.khr_external_memory_fd);
        }
    #endif // defined(VK_KHR_external_memory_fd)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_semaphore_win32)
template<>
struct get_from<extension::device_functions, "vkImportSemaphoreWin32HandleKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkImportSemaphoreWin32HandleKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_semaphore_win32)
        if(functions.khr_external_semaphore_win32)
        {
            static_assert(
                requires {
                    { functions.khr_external_semaphore_win32 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_semaphore_win32, "vkImportSemaphoreWin32HandleKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_semaphore_win32, "vkImportSemaphoreWin32HandleKHR">::get(
                *functions.khr_external_semaphore_win32);
        }
    #endif // defined(VK_KHR_external_semaphore_win32)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
template<>
struct get_from<extension::device_functions, "vkGetSemaphoreWin32HandleKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSemaphoreWin32HandleKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_semaphore_win32)
        if(functions.khr_external_semaphore_win32)
        {
            static_assert(
                requires {
                    { functions.khr_external_semaphore_win32 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_semaphore_win32, "vkGetSemaphoreWin32HandleKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_semaphore_win32, "vkGetSemaphoreWin32HandleKHR">::get(
                *functions.khr_external_semaphore_win32);
        }
    #endif // defined(VK_KHR_external_semaphore_win32)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)
template<>
struct get_from<extension::device_functions, "vkImportSemaphoreFdKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkImportSemaphoreFdKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_semaphore_fd)
        if(functions.khr_external_semaphore_fd)
        {
            static_assert(
                requires {
                    { functions.khr_external_semaphore_fd };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_semaphore_fd, "vkImportSemaphoreFdKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_semaphore_fd, "vkImportSemaphoreFdKHR">::get(*functions.khr_external_semaphore_fd);
        }
    #endif // defined(VK_KHR_external_semaphore_fd)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_external_semaphore_fd)
template<>
struct get_from<extension::device_functions, "vkGetSemaphoreFdKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSemaphoreFdKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_semaphore_fd)
        if(functions.khr_external_semaphore_fd)
        {
            static_assert(
                requires {
                    { functions.khr_external_semaphore_fd };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_semaphore_fd, "vkGetSemaphoreFdKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_semaphore_fd, "vkGetSemaphoreFdKHR">::get(*functions.khr_external_semaphore_fd);
        }
    #endif // defined(VK_KHR_external_semaphore_fd)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_push_descriptor)
template<>
struct get_from<extension::device_functions, "vkCmdPushDescriptorSetKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPushDescriptorSetKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_push_descriptor)
        if(functions.khr_push_descriptor)
        {
            static_assert(
                requires {
                    { functions.khr_push_descriptor };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_push_descriptor, "vkCmdPushDescriptorSetKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_push_descriptor, "vkCmdPushDescriptorSetKHR">::get(*functions.khr_push_descriptor);
        }
    #endif // defined(VK_KHR_push_descriptor)

        return nullptr;
    }
};
#endif // defined(VK_KHR_push_descriptor)

#if defined(VK_KHR_push_descriptor) or defined(VK_KHR_descriptor_update_template)
template<>
struct get_from<extension::device_functions, "vkCmdPushDescriptorSetWithTemplateKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPushDescriptorSetWithTemplateKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_push_descriptor)
        if(functions.khr_push_descriptor)
        {
            static_assert(
                requires {
                    { functions.khr_push_descriptor };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_push_descriptor, "vkCmdPushDescriptorSetWithTemplateKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_push_descriptor, "vkCmdPushDescriptorSetWithTemplateKHR">::get(*functions.khr_push_descriptor);
        }
    #endif // defined(VK_KHR_push_descriptor)

    #if defined(VK_KHR_descriptor_update_template)
        if(functions.khr_descriptor_update_template)
        {
            static_assert(
                requires {
                    { functions.khr_descriptor_update_template };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_descriptor_update_template, "vkCmdPushDescriptorSetWithTemplateKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_descriptor_update_template, "vkCmdPushDescriptorSetWithTemplateKHR">::get(
                *functions.khr_descriptor_update_template);
        }
    #endif // defined(VK_KHR_descriptor_update_template)

        return nullptr;
    }
};
#endif // defined(VK_KHR_push_descriptor)or defined(VK_KHR_descriptor_update_template)

#if defined(VK_EXT_conditional_rendering)
template<>
struct get_from<extension::device_functions, "vkCmdBeginConditionalRenderingEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBeginConditionalRenderingEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_conditional_rendering)
        if(functions.ext_conditional_rendering)
        {
            static_assert(
                requires {
                    { functions.ext_conditional_rendering };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_conditional_rendering, "vkCmdBeginConditionalRenderingEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_conditional_rendering, "vkCmdBeginConditionalRenderingEXT">::get(
                *functions.ext_conditional_rendering);
        }
    #endif // defined(VK_EXT_conditional_rendering)

        return nullptr;
    }
};
#endif // defined(VK_EXT_conditional_rendering)

#if defined(VK_EXT_conditional_rendering)
template<>
struct get_from<extension::device_functions, "vkCmdEndConditionalRenderingEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndConditionalRenderingEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_conditional_rendering)
        if(functions.ext_conditional_rendering)
        {
            static_assert(
                requires {
                    { functions.ext_conditional_rendering };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_conditional_rendering, "vkCmdEndConditionalRenderingEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_conditional_rendering, "vkCmdEndConditionalRenderingEXT">::get(
                *functions.ext_conditional_rendering);
        }
    #endif // defined(VK_EXT_conditional_rendering)

        return nullptr;
    }
};
#endif // defined(VK_EXT_conditional_rendering)

#if defined(VK_KHR_descriptor_update_template)
template<>
struct get_from<extension::device_functions, "vkCreateDescriptorUpdateTemplateKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateDescriptorUpdateTemplateKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_descriptor_update_template)
        if(functions.khr_descriptor_update_template)
        {
            static_assert(
                requires {
                    { functions.khr_descriptor_update_template };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_descriptor_update_template, "vkCreateDescriptorUpdateTemplateKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_descriptor_update_template, "vkCreateDescriptorUpdateTemplateKHR">::get(
                *functions.khr_descriptor_update_template);
        }
    #endif // defined(VK_KHR_descriptor_update_template)

        return nullptr;
    }
};
#endif // defined(VK_KHR_descriptor_update_template)

#if defined(VK_KHR_descriptor_update_template)
template<>
struct get_from<extension::device_functions, "vkDestroyDescriptorUpdateTemplateKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyDescriptorUpdateTemplateKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_descriptor_update_template)
        if(functions.khr_descriptor_update_template)
        {
            static_assert(
                requires {
                    { functions.khr_descriptor_update_template };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_descriptor_update_template, "vkDestroyDescriptorUpdateTemplateKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_descriptor_update_template, "vkDestroyDescriptorUpdateTemplateKHR">::get(
                *functions.khr_descriptor_update_template);
        }
    #endif // defined(VK_KHR_descriptor_update_template)

        return nullptr;
    }
};
#endif // defined(VK_KHR_descriptor_update_template)

#if defined(VK_KHR_descriptor_update_template)
template<>
struct get_from<extension::device_functions, "vkUpdateDescriptorSetWithTemplateKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkUpdateDescriptorSetWithTemplateKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_descriptor_update_template)
        if(functions.khr_descriptor_update_template)
        {
            static_assert(
                requires {
                    { functions.khr_descriptor_update_template };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_descriptor_update_template, "vkUpdateDescriptorSetWithTemplateKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_descriptor_update_template, "vkUpdateDescriptorSetWithTemplateKHR">::get(
                *functions.khr_descriptor_update_template);
        }
    #endif // defined(VK_KHR_descriptor_update_template)

        return nullptr;
    }
};
#endif // defined(VK_KHR_descriptor_update_template)

#if defined(VK_NV_clip_space_w_scaling)
template<>
struct get_from<extension::device_functions, "vkCmdSetViewportWScalingNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetViewportWScalingNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_clip_space_w_scaling)
        if(functions.nv_clip_space_w_scaling)
        {
            static_assert(
                requires {
                    { functions.nv_clip_space_w_scaling };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_clip_space_w_scaling, "vkCmdSetViewportWScalingNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_clip_space_w_scaling, "vkCmdSetViewportWScalingNV">::get(*functions.nv_clip_space_w_scaling);
        }
    #endif // defined(VK_NV_clip_space_w_scaling)

        return nullptr;
    }
};
#endif // defined(VK_NV_clip_space_w_scaling)

#if defined(VK_EXT_display_control)
template<>
struct get_from<extension::device_functions, "vkDisplayPowerControlEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDisplayPowerControlEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_display_control)
        if(functions.ext_display_control)
        {
            static_assert(
                requires {
                    { functions.ext_display_control };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_display_control, "vkDisplayPowerControlEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_display_control, "vkDisplayPowerControlEXT">::get(*functions.ext_display_control);
        }
    #endif // defined(VK_EXT_display_control)

        return nullptr;
    }
};
#endif // defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
template<>
struct get_from<extension::device_functions, "vkRegisterDeviceEventEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkRegisterDeviceEventEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_display_control)
        if(functions.ext_display_control)
        {
            static_assert(
                requires {
                    { functions.ext_display_control };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_display_control, "vkRegisterDeviceEventEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_display_control, "vkRegisterDeviceEventEXT">::get(*functions.ext_display_control);
        }
    #endif // defined(VK_EXT_display_control)

        return nullptr;
    }
};
#endif // defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
template<>
struct get_from<extension::device_functions, "vkRegisterDisplayEventEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkRegisterDisplayEventEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_display_control)
        if(functions.ext_display_control)
        {
            static_assert(
                requires {
                    { functions.ext_display_control };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_display_control, "vkRegisterDisplayEventEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_display_control, "vkRegisterDisplayEventEXT">::get(*functions.ext_display_control);
        }
    #endif // defined(VK_EXT_display_control)

        return nullptr;
    }
};
#endif // defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
template<>
struct get_from<extension::device_functions, "vkGetSwapchainCounterEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSwapchainCounterEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_display_control)
        if(functions.ext_display_control)
        {
            static_assert(
                requires {
                    { functions.ext_display_control };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_display_control, "vkGetSwapchainCounterEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_display_control, "vkGetSwapchainCounterEXT">::get(*functions.ext_display_control);
        }
    #endif // defined(VK_EXT_display_control)

        return nullptr;
    }
};
#endif // defined(VK_EXT_display_control)

#if defined(VK_GOOGLE_display_timing)
template<>
struct get_from<extension::device_functions, "vkGetRefreshCycleDurationGOOGLE">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetRefreshCycleDurationGOOGLE get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_GOOGLE_display_timing)
        if(functions.google_display_timing)
        {
            static_assert(
                requires {
                    { functions.google_display_timing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::google_display_timing, "vkGetRefreshCycleDurationGOOGLE">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::google_display_timing, "vkGetRefreshCycleDurationGOOGLE">::get(*functions.google_display_timing);
        }
    #endif // defined(VK_GOOGLE_display_timing)

        return nullptr;
    }
};
#endif // defined(VK_GOOGLE_display_timing)

#if defined(VK_GOOGLE_display_timing)
template<>
struct get_from<extension::device_functions, "vkGetPastPresentationTimingGOOGLE">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPastPresentationTimingGOOGLE get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_GOOGLE_display_timing)
        if(functions.google_display_timing)
        {
            static_assert(
                requires {
                    { functions.google_display_timing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::google_display_timing, "vkGetPastPresentationTimingGOOGLE">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::google_display_timing, "vkGetPastPresentationTimingGOOGLE">::get(*functions.google_display_timing);
        }
    #endif // defined(VK_GOOGLE_display_timing)

        return nullptr;
    }
};
#endif // defined(VK_GOOGLE_display_timing)

#if defined(VK_EXT_discard_rectangles)
template<>
struct get_from<extension::device_functions, "vkCmdSetDiscardRectangleEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDiscardRectangleEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_discard_rectangles)
        if(functions.ext_discard_rectangles)
        {
            static_assert(
                requires {
                    { functions.ext_discard_rectangles };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_discard_rectangles, "vkCmdSetDiscardRectangleEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_discard_rectangles, "vkCmdSetDiscardRectangleEXT">::get(*functions.ext_discard_rectangles);
        }
    #endif // defined(VK_EXT_discard_rectangles)

        return nullptr;
    }
};
#endif // defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles)
template<>
struct get_from<extension::device_functions, "vkCmdSetDiscardRectangleEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDiscardRectangleEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_discard_rectangles)
        if(functions.ext_discard_rectangles)
        {
            static_assert(
                requires {
                    { functions.ext_discard_rectangles };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_discard_rectangles, "vkCmdSetDiscardRectangleEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_discard_rectangles, "vkCmdSetDiscardRectangleEnableEXT">::get(
                *functions.ext_discard_rectangles);
        }
    #endif // defined(VK_EXT_discard_rectangles)

        return nullptr;
    }
};
#endif // defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles)
template<>
struct get_from<extension::device_functions, "vkCmdSetDiscardRectangleModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDiscardRectangleModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_discard_rectangles)
        if(functions.ext_discard_rectangles)
        {
            static_assert(
                requires {
                    { functions.ext_discard_rectangles };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_discard_rectangles, "vkCmdSetDiscardRectangleModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_discard_rectangles, "vkCmdSetDiscardRectangleModeEXT">::get(*functions.ext_discard_rectangles);
        }
    #endif // defined(VK_EXT_discard_rectangles)

        return nullptr;
    }
};
#endif // defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_hdr_metadata)
template<>
struct get_from<extension::device_functions, "vkSetHdrMetadataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetHdrMetadataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_hdr_metadata)
        if(functions.ext_hdr_metadata)
        {
            static_assert(
                requires {
                    { functions.ext_hdr_metadata };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_hdr_metadata, "vkSetHdrMetadataEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_hdr_metadata, "vkSetHdrMetadataEXT">::get(*functions.ext_hdr_metadata);
        }
    #endif // defined(VK_EXT_hdr_metadata)

        return nullptr;
    }
};
#endif // defined(VK_EXT_hdr_metadata)

#if defined(VK_KHR_create_renderpass2)
template<>
struct get_from<extension::device_functions, "vkCreateRenderPass2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateRenderPass2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_create_renderpass2)
        if(functions.khr_create_renderpass2)
        {
            static_assert(
                requires {
                    { functions.khr_create_renderpass2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_create_renderpass2, "vkCreateRenderPass2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_create_renderpass2, "vkCreateRenderPass2KHR">::get(*functions.khr_create_renderpass2);
        }
    #endif // defined(VK_KHR_create_renderpass2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_create_renderpass2)

#if defined(VK_KHR_create_renderpass2)
template<>
struct get_from<extension::device_functions, "vkCmdBeginRenderPass2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBeginRenderPass2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_create_renderpass2)
        if(functions.khr_create_renderpass2)
        {
            static_assert(
                requires {
                    { functions.khr_create_renderpass2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_create_renderpass2, "vkCmdBeginRenderPass2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_create_renderpass2, "vkCmdBeginRenderPass2KHR">::get(*functions.khr_create_renderpass2);
        }
    #endif // defined(VK_KHR_create_renderpass2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_create_renderpass2)

#if defined(VK_KHR_create_renderpass2)
template<>
struct get_from<extension::device_functions, "vkCmdNextSubpass2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdNextSubpass2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_create_renderpass2)
        if(functions.khr_create_renderpass2)
        {
            static_assert(
                requires {
                    { functions.khr_create_renderpass2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_create_renderpass2, "vkCmdNextSubpass2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_create_renderpass2, "vkCmdNextSubpass2KHR">::get(*functions.khr_create_renderpass2);
        }
    #endif // defined(VK_KHR_create_renderpass2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_create_renderpass2)

#if defined(VK_KHR_create_renderpass2)
template<>
struct get_from<extension::device_functions, "vkCmdEndRenderPass2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndRenderPass2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_create_renderpass2)
        if(functions.khr_create_renderpass2)
        {
            static_assert(
                requires {
                    { functions.khr_create_renderpass2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_create_renderpass2, "vkCmdEndRenderPass2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_create_renderpass2, "vkCmdEndRenderPass2KHR">::get(*functions.khr_create_renderpass2);
        }
    #endif // defined(VK_KHR_create_renderpass2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_create_renderpass2)

#if defined(VK_KHR_shared_presentable_image)
template<>
struct get_from<extension::device_functions, "vkGetSwapchainStatusKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSwapchainStatusKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_shared_presentable_image)
        if(functions.khr_shared_presentable_image)
        {
            static_assert(
                requires {
                    { functions.khr_shared_presentable_image };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_shared_presentable_image, "vkGetSwapchainStatusKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_shared_presentable_image, "vkGetSwapchainStatusKHR">::get(
                *functions.khr_shared_presentable_image);
        }
    #endif // defined(VK_KHR_shared_presentable_image)

        return nullptr;
    }
};
#endif // defined(VK_KHR_shared_presentable_image)

#if defined(VK_KHR_external_fence_win32)
template<>
struct get_from<extension::device_functions, "vkImportFenceWin32HandleKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkImportFenceWin32HandleKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_fence_win32)
        if(functions.khr_external_fence_win32)
        {
            static_assert(
                requires {
                    { functions.khr_external_fence_win32 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_fence_win32, "vkImportFenceWin32HandleKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_fence_win32, "vkImportFenceWin32HandleKHR">::get(*functions.khr_external_fence_win32);
        }
    #endif // defined(VK_KHR_external_fence_win32)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
template<>
struct get_from<extension::device_functions, "vkGetFenceWin32HandleKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetFenceWin32HandleKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_fence_win32)
        if(functions.khr_external_fence_win32)
        {
            static_assert(
                requires {
                    { functions.khr_external_fence_win32 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_fence_win32, "vkGetFenceWin32HandleKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_fence_win32, "vkGetFenceWin32HandleKHR">::get(*functions.khr_external_fence_win32);
        }
    #endif // defined(VK_KHR_external_fence_win32)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)
template<>
struct get_from<extension::device_functions, "vkImportFenceFdKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkImportFenceFdKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_fence_fd)
        if(functions.khr_external_fence_fd)
        {
            static_assert(
                requires {
                    { functions.khr_external_fence_fd };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_fence_fd, "vkImportFenceFdKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_fence_fd, "vkImportFenceFdKHR">::get(*functions.khr_external_fence_fd);
        }
    #endif // defined(VK_KHR_external_fence_fd)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_fence_fd)

#if defined(VK_KHR_external_fence_fd)
template<>
struct get_from<extension::device_functions, "vkGetFenceFdKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetFenceFdKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_fence_fd)
        if(functions.khr_external_fence_fd)
        {
            static_assert(
                requires {
                    { functions.khr_external_fence_fd };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_fence_fd, "vkGetFenceFdKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_fence_fd, "vkGetFenceFdKHR">::get(*functions.khr_external_fence_fd);
        }
    #endif // defined(VK_KHR_external_fence_fd)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_fence_fd)

#if defined(VK_KHR_performance_query)
template<>
struct get_from<extension::device_functions, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
    get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_performance_query)
        if(functions.khr_performance_query)
        {
            static_assert(
                requires {
                    { functions.khr_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::khr_performance_query, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::khr_performance_query, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">::get(
                *functions.khr_performance_query);
        }
    #endif // defined(VK_KHR_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR
    get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_performance_query)
        if(functions.khr_performance_query)
        {
            static_assert(
                requires {
                    { functions.khr_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_performance_query, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_performance_query, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR">::get(
                *functions.khr_performance_query);
        }
    #endif // defined(VK_KHR_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
template<>
struct get_from<extension::device_functions, "vkAcquireProfilingLockKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquireProfilingLockKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_performance_query)
        if(functions.khr_performance_query)
        {
            static_assert(
                requires {
                    { functions.khr_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_performance_query, "vkAcquireProfilingLockKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_performance_query, "vkAcquireProfilingLockKHR">::get(*functions.khr_performance_query);
        }
    #endif // defined(VK_KHR_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
template<>
struct get_from<extension::device_functions, "vkReleaseProfilingLockKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkReleaseProfilingLockKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_performance_query)
        if(functions.khr_performance_query)
        {
            static_assert(
                requires {
                    { functions.khr_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_performance_query, "vkReleaseProfilingLockKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_performance_query, "vkReleaseProfilingLockKHR">::get(*functions.khr_performance_query);
        }
    #endif // defined(VK_KHR_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_KHR_performance_query)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct get_from<extension::device_functions, "vkGetAndroidHardwareBufferPropertiesANDROID">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetAndroidHardwareBufferPropertiesANDROID get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        if(functions.android_external_memory_android_hardware_buffer)
        {
            static_assert(
                requires {
                    { functions.android_external_memory_android_hardware_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::android_external_memory_android_hardware_buffer, "vkGetAndroidHardwareBufferPropertiesANDROID">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::android_external_memory_android_hardware_buffer,
                            "vkGetAndroidHardwareBufferPropertiesANDROID">::get(*functions.android_external_memory_android_hardware_buffer);
        }
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

        return nullptr;
    }
};
#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct get_from<extension::device_functions, "vkGetMemoryAndroidHardwareBufferANDROID">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryAndroidHardwareBufferANDROID get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        if(functions.android_external_memory_android_hardware_buffer)
        {
            static_assert(
                requires {
                    { functions.android_external_memory_android_hardware_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::android_external_memory_android_hardware_buffer, "vkGetMemoryAndroidHardwareBufferANDROID">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::android_external_memory_android_hardware_buffer, "vkGetMemoryAndroidHardwareBufferANDROID">::get(
                *functions.android_external_memory_android_hardware_buffer);
        }
    #endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

        return nullptr;
    }
};
#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct get_from<extension::device_functions, "vkCreateExecutionGraphPipelinesAMDX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateExecutionGraphPipelinesAMDX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMDX_shader_enqueue)
        if(functions.amdx_shader_enqueue)
        {
            static_assert(
                requires {
                    { functions.amdx_shader_enqueue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amdx_shader_enqueue, "vkCreateExecutionGraphPipelinesAMDX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amdx_shader_enqueue, "vkCreateExecutionGraphPipelinesAMDX">::get(*functions.amdx_shader_enqueue);
        }
    #endif // defined(VK_AMDX_shader_enqueue)

        return nullptr;
    }
};
#endif // defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct get_from<extension::device_functions, "vkGetExecutionGraphPipelineScratchSizeAMDX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetExecutionGraphPipelineScratchSizeAMDX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMDX_shader_enqueue)
        if(functions.amdx_shader_enqueue)
        {
            static_assert(
                requires {
                    { functions.amdx_shader_enqueue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amdx_shader_enqueue, "vkGetExecutionGraphPipelineScratchSizeAMDX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amdx_shader_enqueue, "vkGetExecutionGraphPipelineScratchSizeAMDX">::get(
                *functions.amdx_shader_enqueue);
        }
    #endif // defined(VK_AMDX_shader_enqueue)

        return nullptr;
    }
};
#endif // defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct get_from<extension::device_functions, "vkGetExecutionGraphPipelineNodeIndexAMDX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetExecutionGraphPipelineNodeIndexAMDX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMDX_shader_enqueue)
        if(functions.amdx_shader_enqueue)
        {
            static_assert(
                requires {
                    { functions.amdx_shader_enqueue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amdx_shader_enqueue, "vkGetExecutionGraphPipelineNodeIndexAMDX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amdx_shader_enqueue, "vkGetExecutionGraphPipelineNodeIndexAMDX">::get(
                *functions.amdx_shader_enqueue);
        }
    #endif // defined(VK_AMDX_shader_enqueue)

        return nullptr;
    }
};
#endif // defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct get_from<extension::device_functions, "vkCmdInitializeGraphScratchMemoryAMDX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdInitializeGraphScratchMemoryAMDX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMDX_shader_enqueue)
        if(functions.amdx_shader_enqueue)
        {
            static_assert(
                requires {
                    { functions.amdx_shader_enqueue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amdx_shader_enqueue, "vkCmdInitializeGraphScratchMemoryAMDX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amdx_shader_enqueue, "vkCmdInitializeGraphScratchMemoryAMDX">::get(*functions.amdx_shader_enqueue);
        }
    #endif // defined(VK_AMDX_shader_enqueue)

        return nullptr;
    }
};
#endif // defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct get_from<extension::device_functions, "vkCmdDispatchGraphAMDX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDispatchGraphAMDX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMDX_shader_enqueue)
        if(functions.amdx_shader_enqueue)
        {
            static_assert(
                requires {
                    { functions.amdx_shader_enqueue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amdx_shader_enqueue, "vkCmdDispatchGraphAMDX">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::amdx_shader_enqueue, "vkCmdDispatchGraphAMDX">::get(*functions.amdx_shader_enqueue);
        }
    #endif // defined(VK_AMDX_shader_enqueue)

        return nullptr;
    }
};
#endif // defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct get_from<extension::device_functions, "vkCmdDispatchGraphIndirectAMDX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDispatchGraphIndirectAMDX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMDX_shader_enqueue)
        if(functions.amdx_shader_enqueue)
        {
            static_assert(
                requires {
                    { functions.amdx_shader_enqueue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amdx_shader_enqueue, "vkCmdDispatchGraphIndirectAMDX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amdx_shader_enqueue, "vkCmdDispatchGraphIndirectAMDX">::get(*functions.amdx_shader_enqueue);
        }
    #endif // defined(VK_AMDX_shader_enqueue)

        return nullptr;
    }
};
#endif // defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct get_from<extension::device_functions, "vkCmdDispatchGraphIndirectCountAMDX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDispatchGraphIndirectCountAMDX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMDX_shader_enqueue)
        if(functions.amdx_shader_enqueue)
        {
            static_assert(
                requires {
                    { functions.amdx_shader_enqueue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amdx_shader_enqueue, "vkCmdDispatchGraphIndirectCountAMDX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::amdx_shader_enqueue, "vkCmdDispatchGraphIndirectCountAMDX">::get(*functions.amdx_shader_enqueue);
        }
    #endif // defined(VK_AMDX_shader_enqueue)

        return nullptr;
    }
};
#endif // defined(VK_AMDX_shader_enqueue)

#if defined(VK_EXT_sample_locations)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceMultisamplePropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_sample_locations)
        if(functions.ext_sample_locations)
        {
            static_assert(
                requires {
                    { functions.ext_sample_locations };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_sample_locations, "vkGetPhysicalDeviceMultisamplePropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_sample_locations, "vkGetPhysicalDeviceMultisamplePropertiesEXT">::get(
                *functions.ext_sample_locations);
        }
    #endif // defined(VK_EXT_sample_locations)

        return nullptr;
    }
};
#endif // defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
template<>
struct get_from<extension::device_functions, "vkCmdSetSampleLocationsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetSampleLocationsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_sample_locations)
        if(functions.ext_sample_locations)
        {
            static_assert(
                requires {
                    { functions.ext_sample_locations };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_sample_locations, "vkCmdSetSampleLocationsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_sample_locations, "vkCmdSetSampleLocationsEXT">::get(*functions.ext_sample_locations);
        }
    #endif // defined(VK_EXT_sample_locations)

        return nullptr;
    }
};
#endif // defined(VK_EXT_sample_locations)

#if defined(VK_KHR_get_memory_requirements2)
template<>
struct get_from<extension::device_functions, "vkGetImageMemoryRequirements2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageMemoryRequirements2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_memory_requirements2)
        if(functions.khr_get_memory_requirements2)
        {
            static_assert(
                requires {
                    { functions.khr_get_memory_requirements2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_memory_requirements2, "vkGetImageMemoryRequirements2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_memory_requirements2, "vkGetImageMemoryRequirements2KHR">::get(
                *functions.khr_get_memory_requirements2);
        }
    #endif // defined(VK_KHR_get_memory_requirements2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_get_memory_requirements2)
template<>
struct get_from<extension::device_functions, "vkGetBufferMemoryRequirements2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetBufferMemoryRequirements2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_memory_requirements2)
        if(functions.khr_get_memory_requirements2)
        {
            static_assert(
                requires {
                    { functions.khr_get_memory_requirements2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_memory_requirements2, "vkGetBufferMemoryRequirements2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_memory_requirements2, "vkGetBufferMemoryRequirements2KHR">::get(
                *functions.khr_get_memory_requirements2);
        }
    #endif // defined(VK_KHR_get_memory_requirements2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_get_memory_requirements2)
template<>
struct get_from<extension::device_functions, "vkGetImageSparseMemoryRequirements2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageSparseMemoryRequirements2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_memory_requirements2)
        if(functions.khr_get_memory_requirements2)
        {
            static_assert(
                requires {
                    { functions.khr_get_memory_requirements2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_memory_requirements2, "vkGetImageSparseMemoryRequirements2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_memory_requirements2, "vkGetImageSparseMemoryRequirements2KHR">::get(
                *functions.khr_get_memory_requirements2);
        }
    #endif // defined(VK_KHR_get_memory_requirements2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCreateAccelerationStructureKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateAccelerationStructureKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCreateAccelerationStructureKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCreateAccelerationStructureKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkDestroyAccelerationStructureKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyAccelerationStructureKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkDestroyAccelerationStructureKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkDestroyAccelerationStructureKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkBuildAccelerationStructuresKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkBuildAccelerationStructuresKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkBuildAccelerationStructuresKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkBuildAccelerationStructuresKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCopyAccelerationStructureKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyAccelerationStructureKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCopyAccelerationStructureKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCopyAccelerationStructureKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCopyAccelerationStructureToMemoryKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyAccelerationStructureToMemoryKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCopyAccelerationStructureToMemoryKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCopyAccelerationStructureToMemoryKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCopyMemoryToAccelerationStructureKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyMemoryToAccelerationStructureKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCopyMemoryToAccelerationStructureKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCopyMemoryToAccelerationStructureKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkWriteAccelerationStructuresPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkWriteAccelerationStructuresPropertiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkWriteAccelerationStructuresPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkWriteAccelerationStructuresPropertiesKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkGetAccelerationStructureDeviceAddressKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetAccelerationStructureDeviceAddressKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkGetAccelerationStructureDeviceAddressKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkGetAccelerationStructureDeviceAddressKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkGetDeviceAccelerationStructureCompatibilityKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceAccelerationStructureCompatibilityKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkGetDeviceAccelerationStructureCompatibilityKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkGetDeviceAccelerationStructureCompatibilityKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkGetAccelerationStructureBuildSizesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetAccelerationStructureBuildSizesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkGetAccelerationStructureBuildSizesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkGetAccelerationStructureBuildSizesKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdBuildAccelerationStructuresKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBuildAccelerationStructuresKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCmdBuildAccelerationStructuresKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCmdBuildAccelerationStructuresKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdBuildAccelerationStructuresIndirectKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBuildAccelerationStructuresIndirectKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCmdBuildAccelerationStructuresIndirectKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCmdBuildAccelerationStructuresIndirectKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdCopyAccelerationStructureKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyAccelerationStructureKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCmdCopyAccelerationStructureKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCmdCopyAccelerationStructureKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdCopyAccelerationStructureToMemoryKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyAccelerationStructureToMemoryKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCmdCopyAccelerationStructureToMemoryKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCmdCopyAccelerationStructureToMemoryKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdCopyMemoryToAccelerationStructureKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyMemoryToAccelerationStructureKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCmdCopyMemoryToAccelerationStructureKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCmdCopyMemoryToAccelerationStructureKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdWriteAccelerationStructuresPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdWriteAccelerationStructuresPropertiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_acceleration_structure)
        if(functions.khr_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.khr_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_acceleration_structure, "vkCmdWriteAccelerationStructuresPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_acceleration_structure, "vkCmdWriteAccelerationStructuresPropertiesKHR">::get(
                *functions.khr_acceleration_structure);
        }
    #endif // defined(VK_KHR_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct get_from<extension::device_functions, "vkCreateRayTracingPipelinesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateRayTracingPipelinesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_pipeline)
        if(functions.khr_ray_tracing_pipeline)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_pipeline };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_pipeline, "vkCreateRayTracingPipelinesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_pipeline, "vkCreateRayTracingPipelinesKHR">::get(
                *functions.khr_ray_tracing_pipeline);
        }
    #endif // defined(VK_KHR_ray_tracing_pipeline)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct get_from<extension::device_functions, "vkGetRayTracingShaderGroupHandlesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetRayTracingShaderGroupHandlesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_pipeline)
        if(functions.khr_ray_tracing_pipeline)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_pipeline };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_pipeline, "vkGetRayTracingShaderGroupHandlesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_pipeline, "vkGetRayTracingShaderGroupHandlesKHR">::get(
                *functions.khr_ray_tracing_pipeline);
        }
    #endif // defined(VK_KHR_ray_tracing_pipeline)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct get_from<extension::device_functions, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_pipeline)
        if(functions.khr_ray_tracing_pipeline)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_pipeline };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_pipeline, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_pipeline, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR">::get(
                *functions.khr_ray_tracing_pipeline);
        }
    #endif // defined(VK_KHR_ray_tracing_pipeline)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct get_from<extension::device_functions, "vkGetRayTracingShaderGroupStackSizeKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetRayTracingShaderGroupStackSizeKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_pipeline)
        if(functions.khr_ray_tracing_pipeline)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_pipeline };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_pipeline, "vkGetRayTracingShaderGroupStackSizeKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_pipeline, "vkGetRayTracingShaderGroupStackSizeKHR">::get(
                *functions.khr_ray_tracing_pipeline);
        }
    #endif // defined(VK_KHR_ray_tracing_pipeline)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct get_from<extension::device_functions, "vkCmdTraceRaysKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdTraceRaysKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_pipeline)
        if(functions.khr_ray_tracing_pipeline)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_pipeline };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_pipeline, "vkCmdTraceRaysKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_pipeline, "vkCmdTraceRaysKHR">::get(*functions.khr_ray_tracing_pipeline);
        }
    #endif // defined(VK_KHR_ray_tracing_pipeline)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct get_from<extension::device_functions, "vkCmdTraceRaysIndirectKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdTraceRaysIndirectKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_pipeline)
        if(functions.khr_ray_tracing_pipeline)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_pipeline };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_pipeline, "vkCmdTraceRaysIndirectKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_pipeline, "vkCmdTraceRaysIndirectKHR">::get(*functions.khr_ray_tracing_pipeline);
        }
    #endif // defined(VK_KHR_ray_tracing_pipeline)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct get_from<extension::device_functions, "vkCmdSetRayTracingPipelineStackSizeKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetRayTracingPipelineStackSizeKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_pipeline)
        if(functions.khr_ray_tracing_pipeline)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_pipeline };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_pipeline, "vkCmdSetRayTracingPipelineStackSizeKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_pipeline, "vkCmdSetRayTracingPipelineStackSizeKHR">::get(
                *functions.khr_ray_tracing_pipeline);
        }
    #endif // defined(VK_KHR_ray_tracing_pipeline)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_sampler_ycbcr_conversion)
template<>
struct get_from<extension::device_functions, "vkCreateSamplerYcbcrConversionKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateSamplerYcbcrConversionKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_sampler_ycbcr_conversion)
        if(functions.khr_sampler_ycbcr_conversion)
        {
            static_assert(
                requires {
                    { functions.khr_sampler_ycbcr_conversion };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_sampler_ycbcr_conversion, "vkCreateSamplerYcbcrConversionKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_sampler_ycbcr_conversion, "vkCreateSamplerYcbcrConversionKHR">::get(
                *functions.khr_sampler_ycbcr_conversion);
        }
    #endif // defined(VK_KHR_sampler_ycbcr_conversion)

        return nullptr;
    }
};
#endif // defined(VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion)
template<>
struct get_from<extension::device_functions, "vkDestroySamplerYcbcrConversionKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroySamplerYcbcrConversionKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_sampler_ycbcr_conversion)
        if(functions.khr_sampler_ycbcr_conversion)
        {
            static_assert(
                requires {
                    { functions.khr_sampler_ycbcr_conversion };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_sampler_ycbcr_conversion, "vkDestroySamplerYcbcrConversionKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_sampler_ycbcr_conversion, "vkDestroySamplerYcbcrConversionKHR">::get(
                *functions.khr_sampler_ycbcr_conversion);
        }
    #endif // defined(VK_KHR_sampler_ycbcr_conversion)

        return nullptr;
    }
};
#endif // defined(VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_bind_memory2)
template<>
struct get_from<extension::device_functions, "vkBindBufferMemory2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkBindBufferMemory2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_bind_memory2)
        if(functions.khr_bind_memory2)
        {
            static_assert(
                requires {
                    { functions.khr_bind_memory2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_bind_memory2, "vkBindBufferMemory2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_bind_memory2, "vkBindBufferMemory2KHR">::get(*functions.khr_bind_memory2);
        }
    #endif // defined(VK_KHR_bind_memory2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_bind_memory2)

#if defined(VK_KHR_bind_memory2)
template<>
struct get_from<extension::device_functions, "vkBindImageMemory2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkBindImageMemory2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_bind_memory2)
        if(functions.khr_bind_memory2)
        {
            static_assert(
                requires {
                    { functions.khr_bind_memory2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_bind_memory2, "vkBindImageMemory2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_bind_memory2, "vkBindImageMemory2KHR">::get(*functions.khr_bind_memory2);
        }
    #endif // defined(VK_KHR_bind_memory2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_bind_memory2)

#if defined(VK_EXT_image_drm_format_modifier)
template<>
struct get_from<extension::device_functions, "vkGetImageDrmFormatModifierPropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageDrmFormatModifierPropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_image_drm_format_modifier)
        if(functions.ext_image_drm_format_modifier)
        {
            static_assert(
                requires {
                    { functions.ext_image_drm_format_modifier };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_image_drm_format_modifier, "vkGetImageDrmFormatModifierPropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_image_drm_format_modifier, "vkGetImageDrmFormatModifierPropertiesEXT">::get(
                *functions.ext_image_drm_format_modifier);
        }
    #endif // defined(VK_EXT_image_drm_format_modifier)

        return nullptr;
    }
};
#endif // defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_validation_cache)
template<>
struct get_from<extension::device_functions, "vkCreateValidationCacheEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateValidationCacheEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_validation_cache)
        if(functions.ext_validation_cache)
        {
            static_assert(
                requires {
                    { functions.ext_validation_cache };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_validation_cache, "vkCreateValidationCacheEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_validation_cache, "vkCreateValidationCacheEXT">::get(*functions.ext_validation_cache);
        }
    #endif // defined(VK_EXT_validation_cache)

        return nullptr;
    }
};
#endif // defined(VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
template<>
struct get_from<extension::device_functions, "vkDestroyValidationCacheEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyValidationCacheEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_validation_cache)
        if(functions.ext_validation_cache)
        {
            static_assert(
                requires {
                    { functions.ext_validation_cache };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_validation_cache, "vkDestroyValidationCacheEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_validation_cache, "vkDestroyValidationCacheEXT">::get(*functions.ext_validation_cache);
        }
    #endif // defined(VK_EXT_validation_cache)

        return nullptr;
    }
};
#endif // defined(VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
template<>
struct get_from<extension::device_functions, "vkMergeValidationCachesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkMergeValidationCachesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_validation_cache)
        if(functions.ext_validation_cache)
        {
            static_assert(
                requires {
                    { functions.ext_validation_cache };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_validation_cache, "vkMergeValidationCachesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_validation_cache, "vkMergeValidationCachesEXT">::get(*functions.ext_validation_cache);
        }
    #endif // defined(VK_EXT_validation_cache)

        return nullptr;
    }
};
#endif // defined(VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
template<>
struct get_from<extension::device_functions, "vkGetValidationCacheDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetValidationCacheDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_validation_cache)
        if(functions.ext_validation_cache)
        {
            static_assert(
                requires {
                    { functions.ext_validation_cache };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_validation_cache, "vkGetValidationCacheDataEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_validation_cache, "vkGetValidationCacheDataEXT">::get(*functions.ext_validation_cache);
        }
    #endif // defined(VK_EXT_validation_cache)

        return nullptr;
    }
};
#endif // defined(VK_EXT_validation_cache)

#if defined(VK_NV_shading_rate_image)
template<>
struct get_from<extension::device_functions, "vkCmdBindShadingRateImageNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindShadingRateImageNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_shading_rate_image)
        if(functions.nv_shading_rate_image)
        {
            static_assert(
                requires {
                    { functions.nv_shading_rate_image };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_shading_rate_image, "vkCmdBindShadingRateImageNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_shading_rate_image, "vkCmdBindShadingRateImageNV">::get(*functions.nv_shading_rate_image);
        }
    #endif // defined(VK_NV_shading_rate_image)

        return nullptr;
    }
};
#endif // defined(VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
template<>
struct get_from<extension::device_functions, "vkCmdSetViewportShadingRatePaletteNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetViewportShadingRatePaletteNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_shading_rate_image)
        if(functions.nv_shading_rate_image)
        {
            static_assert(
                requires {
                    { functions.nv_shading_rate_image };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_shading_rate_image, "vkCmdSetViewportShadingRatePaletteNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_shading_rate_image, "vkCmdSetViewportShadingRatePaletteNV">::get(
                *functions.nv_shading_rate_image);
        }
    #endif // defined(VK_NV_shading_rate_image)

        return nullptr;
    }
};
#endif // defined(VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
template<>
struct get_from<extension::device_functions, "vkCmdSetCoarseSampleOrderNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCoarseSampleOrderNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_shading_rate_image)
        if(functions.nv_shading_rate_image)
        {
            static_assert(
                requires {
                    { functions.nv_shading_rate_image };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_shading_rate_image, "vkCmdSetCoarseSampleOrderNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_shading_rate_image, "vkCmdSetCoarseSampleOrderNV">::get(*functions.nv_shading_rate_image);
        }
    #endif // defined(VK_NV_shading_rate_image)

        return nullptr;
    }
};
#endif // defined(VK_NV_shading_rate_image)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkCreateAccelerationStructureNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateAccelerationStructureNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkCreateAccelerationStructureNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkCreateAccelerationStructureNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkDestroyAccelerationStructureNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyAccelerationStructureNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkDestroyAccelerationStructureNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkDestroyAccelerationStructureNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkGetAccelerationStructureMemoryRequirementsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetAccelerationStructureMemoryRequirementsNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkGetAccelerationStructureMemoryRequirementsNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkGetAccelerationStructureMemoryRequirementsNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkBindAccelerationStructureMemoryNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkBindAccelerationStructureMemoryNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkBindAccelerationStructureMemoryNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkBindAccelerationStructureMemoryNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkCreateRayTracingPipelinesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateRayTracingPipelinesNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkCreateRayTracingPipelinesNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkCreateRayTracingPipelinesNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkGetRayTracingShaderGroupHandlesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetRayTracingShaderGroupHandlesNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkGetRayTracingShaderGroupHandlesNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkGetRayTracingShaderGroupHandlesNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkGetAccelerationStructureHandleNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetAccelerationStructureHandleNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkGetAccelerationStructureHandleNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkGetAccelerationStructureHandleNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkCompileDeferredNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCompileDeferredNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkCompileDeferredNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkCompileDeferredNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkCmdBuildAccelerationStructureNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBuildAccelerationStructureNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkCmdBuildAccelerationStructureNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkCmdBuildAccelerationStructureNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkCmdCopyAccelerationStructureNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyAccelerationStructureNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkCmdCopyAccelerationStructureNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkCmdCopyAccelerationStructureNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkCmdTraceRaysNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdTraceRaysNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkCmdTraceRaysNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkCmdTraceRaysNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct get_from<extension::device_functions, "vkCmdWriteAccelerationStructuresPropertiesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdWriteAccelerationStructuresPropertiesNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_ray_tracing)
        if(functions.nv_ray_tracing)
        {
            static_assert(
                requires {
                    { functions.nv_ray_tracing };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_ray_tracing, "vkCmdWriteAccelerationStructuresPropertiesNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_ray_tracing, "vkCmdWriteAccelerationStructuresPropertiesNV">::get(*functions.nv_ray_tracing);
        }
    #endif // defined(VK_NV_ray_tracing)

        return nullptr;
    }
};
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_KHR_maintenance3)
template<>
struct get_from<extension::device_functions, "vkGetDescriptorSetLayoutSupportKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDescriptorSetLayoutSupportKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance3)
        if(functions.khr_maintenance3)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance3, "vkGetDescriptorSetLayoutSupportKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance3, "vkGetDescriptorSetLayoutSupportKHR">::get(*functions.khr_maintenance3);
        }
    #endif // defined(VK_KHR_maintenance3)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance3)

#if defined(VK_KHR_draw_indirect_count)
template<>
struct get_from<extension::device_functions, "vkCmdDrawIndirectCountKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawIndirectCountKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_draw_indirect_count)
        if(functions.khr_draw_indirect_count)
        {
            static_assert(
                requires {
                    { functions.khr_draw_indirect_count };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_draw_indirect_count, "vkCmdDrawIndirectCountKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_draw_indirect_count, "vkCmdDrawIndirectCountKHR">::get(*functions.khr_draw_indirect_count);
        }
    #endif // defined(VK_KHR_draw_indirect_count)

        return nullptr;
    }
};
#endif // defined(VK_KHR_draw_indirect_count)

#if defined(VK_KHR_draw_indirect_count)
template<>
struct get_from<extension::device_functions, "vkCmdDrawIndexedIndirectCountKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawIndexedIndirectCountKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_draw_indirect_count)
        if(functions.khr_draw_indirect_count)
        {
            static_assert(
                requires {
                    { functions.khr_draw_indirect_count };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_draw_indirect_count, "vkCmdDrawIndexedIndirectCountKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_draw_indirect_count, "vkCmdDrawIndexedIndirectCountKHR">::get(
                *functions.khr_draw_indirect_count);
        }
    #endif // defined(VK_KHR_draw_indirect_count)

        return nullptr;
    }
};
#endif // defined(VK_KHR_draw_indirect_count)

#if defined(VK_EXT_external_memory_host)
template<>
struct get_from<extension::device_functions, "vkGetMemoryHostPointerPropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryHostPointerPropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_external_memory_host)
        if(functions.ext_external_memory_host)
        {
            static_assert(
                requires {
                    { functions.ext_external_memory_host };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_external_memory_host, "vkGetMemoryHostPointerPropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_external_memory_host, "vkGetMemoryHostPointerPropertiesEXT">::get(
                *functions.ext_external_memory_host);
        }
    #endif // defined(VK_EXT_external_memory_host)

        return nullptr;
    }
};
#endif // defined(VK_EXT_external_memory_host)

#if defined(VK_AMD_buffer_marker)
template<>
struct get_from<extension::device_functions, "vkCmdWriteBufferMarkerAMD">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdWriteBufferMarkerAMD get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMD_buffer_marker)
        if(functions.amd_buffer_marker)
        {
            static_assert(
                requires {
                    { functions.amd_buffer_marker };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amd_buffer_marker, "vkCmdWriteBufferMarkerAMD">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::amd_buffer_marker, "vkCmdWriteBufferMarkerAMD">::get(*functions.amd_buffer_marker);
        }
    #endif // defined(VK_AMD_buffer_marker)

        return nullptr;
    }
};
#endif // defined(VK_AMD_buffer_marker)

#if defined(VK_AMD_buffer_marker)
template<>
struct get_from<extension::device_functions, "vkCmdWriteBufferMarker2AMD">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdWriteBufferMarker2AMD get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMD_buffer_marker)
        if(functions.amd_buffer_marker)
        {
            static_assert(
                requires {
                    { functions.amd_buffer_marker };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amd_buffer_marker, "vkCmdWriteBufferMarker2AMD">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::amd_buffer_marker, "vkCmdWriteBufferMarker2AMD">::get(*functions.amd_buffer_marker);
        }
    #endif // defined(VK_AMD_buffer_marker)

        return nullptr;
    }
};
#endif // defined(VK_AMD_buffer_marker)

#if defined(VK_EXT_calibrated_timestamps)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_calibrated_timestamps)
        if(functions.ext_calibrated_timestamps)
        {
            static_assert(
                requires {
                    { functions.ext_calibrated_timestamps };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_calibrated_timestamps, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_calibrated_timestamps, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT">::get(
                *functions.ext_calibrated_timestamps);
        }
    #endif // defined(VK_EXT_calibrated_timestamps)

        return nullptr;
    }
};
#endif // defined(VK_EXT_calibrated_timestamps)

#if defined(VK_EXT_calibrated_timestamps)
template<>
struct get_from<extension::device_functions, "vkGetCalibratedTimestampsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetCalibratedTimestampsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_calibrated_timestamps)
        if(functions.ext_calibrated_timestamps)
        {
            static_assert(
                requires {
                    { functions.ext_calibrated_timestamps };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_calibrated_timestamps, "vkGetCalibratedTimestampsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_calibrated_timestamps, "vkGetCalibratedTimestampsEXT">::get(
                *functions.ext_calibrated_timestamps);
        }
    #endif // defined(VK_EXT_calibrated_timestamps)

        return nullptr;
    }
};
#endif // defined(VK_EXT_calibrated_timestamps)

#if defined(VK_NV_mesh_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMeshTasksNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMeshTasksNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_mesh_shader)
        if(functions.nv_mesh_shader)
        {
            static_assert(
                requires {
                    { functions.nv_mesh_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_mesh_shader, "vkCmdDrawMeshTasksNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_mesh_shader, "vkCmdDrawMeshTasksNV">::get(*functions.nv_mesh_shader);
        }
    #endif // defined(VK_NV_mesh_shader)

        return nullptr;
    }
};
#endif // defined(VK_NV_mesh_shader)

#if defined(VK_NV_mesh_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMeshTasksIndirectNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMeshTasksIndirectNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_mesh_shader)
        if(functions.nv_mesh_shader)
        {
            static_assert(
                requires {
                    { functions.nv_mesh_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_mesh_shader, "vkCmdDrawMeshTasksIndirectNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_mesh_shader, "vkCmdDrawMeshTasksIndirectNV">::get(*functions.nv_mesh_shader);
        }
    #endif // defined(VK_NV_mesh_shader)

        return nullptr;
    }
};
#endif // defined(VK_NV_mesh_shader)

#if defined(VK_NV_mesh_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMeshTasksIndirectCountNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMeshTasksIndirectCountNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_mesh_shader)
        if(functions.nv_mesh_shader)
        {
            static_assert(
                requires {
                    { functions.nv_mesh_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_mesh_shader, "vkCmdDrawMeshTasksIndirectCountNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_mesh_shader, "vkCmdDrawMeshTasksIndirectCountNV">::get(*functions.nv_mesh_shader);
        }
    #endif // defined(VK_NV_mesh_shader)

        return nullptr;
    }
};
#endif // defined(VK_NV_mesh_shader)

#if defined(VK_NV_scissor_exclusive)
template<>
struct get_from<extension::device_functions, "vkCmdSetExclusiveScissorEnableNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetExclusiveScissorEnableNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_scissor_exclusive)
        if(functions.nv_scissor_exclusive)
        {
            static_assert(
                requires {
                    { functions.nv_scissor_exclusive };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_scissor_exclusive, "vkCmdSetExclusiveScissorEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_scissor_exclusive, "vkCmdSetExclusiveScissorEnableNV">::get(*functions.nv_scissor_exclusive);
        }
    #endif // defined(VK_NV_scissor_exclusive)

        return nullptr;
    }
};
#endif // defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_scissor_exclusive)
template<>
struct get_from<extension::device_functions, "vkCmdSetExclusiveScissorNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetExclusiveScissorNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_scissor_exclusive)
        if(functions.nv_scissor_exclusive)
        {
            static_assert(
                requires {
                    { functions.nv_scissor_exclusive };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_scissor_exclusive, "vkCmdSetExclusiveScissorNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_scissor_exclusive, "vkCmdSetExclusiveScissorNV">::get(*functions.nv_scissor_exclusive);
        }
    #endif // defined(VK_NV_scissor_exclusive)

        return nullptr;
    }
};
#endif // defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_device_diagnostic_checkpoints)
template<>
struct get_from<extension::device_functions, "vkGetQueueCheckpointDataNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetQueueCheckpointDataNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_diagnostic_checkpoints)
        if(functions.nv_device_diagnostic_checkpoints)
        {
            static_assert(
                requires {
                    { functions.nv_device_diagnostic_checkpoints };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_diagnostic_checkpoints, "vkGetQueueCheckpointDataNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_diagnostic_checkpoints, "vkGetQueueCheckpointDataNV">::get(
                *functions.nv_device_diagnostic_checkpoints);
        }
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
template<>
struct get_from<extension::device_functions, "vkGetQueueCheckpointData2NV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetQueueCheckpointData2NV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_diagnostic_checkpoints)
        if(functions.nv_device_diagnostic_checkpoints)
        {
            static_assert(
                requires {
                    { functions.nv_device_diagnostic_checkpoints };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_diagnostic_checkpoints, "vkGetQueueCheckpointData2NV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_diagnostic_checkpoints, "vkGetQueueCheckpointData2NV">::get(
                *functions.nv_device_diagnostic_checkpoints);
        }
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
template<>
struct get_from<extension::device_functions, "vkCmdSetCheckpointNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCheckpointNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_diagnostic_checkpoints)
        if(functions.nv_device_diagnostic_checkpoints)
        {
            static_assert(
                requires {
                    { functions.nv_device_diagnostic_checkpoints };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_diagnostic_checkpoints, "vkCmdSetCheckpointNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_diagnostic_checkpoints, "vkCmdSetCheckpointNV">::get(
                *functions.nv_device_diagnostic_checkpoints);
        }
    #endif // defined(VK_NV_device_diagnostic_checkpoints)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_KHR_timeline_semaphore)
template<>
struct get_from<extension::device_functions, "vkGetSemaphoreCounterValueKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSemaphoreCounterValueKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_timeline_semaphore)
        if(functions.khr_timeline_semaphore)
        {
            static_assert(
                requires {
                    { functions.khr_timeline_semaphore };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_timeline_semaphore, "vkGetSemaphoreCounterValueKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_timeline_semaphore, "vkGetSemaphoreCounterValueKHR">::get(*functions.khr_timeline_semaphore);
        }
    #endif // defined(VK_KHR_timeline_semaphore)

        return nullptr;
    }
};
#endif // defined(VK_KHR_timeline_semaphore)

#if defined(VK_KHR_timeline_semaphore)
template<>
struct get_from<extension::device_functions, "vkWaitSemaphoresKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkWaitSemaphoresKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_timeline_semaphore)
        if(functions.khr_timeline_semaphore)
        {
            static_assert(
                requires {
                    { functions.khr_timeline_semaphore };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_timeline_semaphore, "vkWaitSemaphoresKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_timeline_semaphore, "vkWaitSemaphoresKHR">::get(*functions.khr_timeline_semaphore);
        }
    #endif // defined(VK_KHR_timeline_semaphore)

        return nullptr;
    }
};
#endif // defined(VK_KHR_timeline_semaphore)

#if defined(VK_KHR_timeline_semaphore)
template<>
struct get_from<extension::device_functions, "vkSignalSemaphoreKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSignalSemaphoreKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_timeline_semaphore)
        if(functions.khr_timeline_semaphore)
        {
            static_assert(
                requires {
                    { functions.khr_timeline_semaphore };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_timeline_semaphore, "vkSignalSemaphoreKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_timeline_semaphore, "vkSignalSemaphoreKHR">::get(*functions.khr_timeline_semaphore);
        }
    #endif // defined(VK_KHR_timeline_semaphore)

        return nullptr;
    }
};
#endif // defined(VK_KHR_timeline_semaphore)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkInitializePerformanceApiINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkInitializePerformanceApiINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkInitializePerformanceApiINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkInitializePerformanceApiINTEL">::get(
                *functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkUninitializePerformanceApiINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkUninitializePerformanceApiINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkUninitializePerformanceApiINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkUninitializePerformanceApiINTEL">::get(
                *functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkAcquirePerformanceConfigurationINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquirePerformanceConfigurationINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkAcquirePerformanceConfigurationINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkAcquirePerformanceConfigurationINTEL">::get(
                *functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkReleasePerformanceConfigurationINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkReleasePerformanceConfigurationINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkReleasePerformanceConfigurationINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkReleasePerformanceConfigurationINTEL">::get(
                *functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkQueueSetPerformanceConfigurationINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkQueueSetPerformanceConfigurationINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkQueueSetPerformanceConfigurationINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkQueueSetPerformanceConfigurationINTEL">::get(
                *functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkGetPerformanceParameterINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPerformanceParameterINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkGetPerformanceParameterINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkGetPerformanceParameterINTEL">::get(*functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkCmdSetPerformanceMarkerINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetPerformanceMarkerINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkCmdSetPerformanceMarkerINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkCmdSetPerformanceMarkerINTEL">::get(*functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkCmdSetPerformanceStreamMarkerINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetPerformanceStreamMarkerINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkCmdSetPerformanceStreamMarkerINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkCmdSetPerformanceStreamMarkerINTEL">::get(
                *functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct get_from<extension::device_functions, "vkCmdSetPerformanceOverrideINTEL">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetPerformanceOverrideINTEL get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_INTEL_performance_query)
        if(functions.intel_performance_query)
        {
            static_assert(
                requires {
                    { functions.intel_performance_query };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::intel_performance_query, "vkCmdSetPerformanceOverrideINTEL">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::intel_performance_query, "vkCmdSetPerformanceOverrideINTEL">::get(
                *functions.intel_performance_query);
        }
    #endif // defined(VK_INTEL_performance_query)

        return nullptr;
    }
};
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_AMD_display_native_hdr)
template<>
struct get_from<extension::device_functions, "vkSetLocalDimmingAMD">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetLocalDimmingAMD get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMD_display_native_hdr)
        if(functions.amd_display_native_hdr)
        {
            static_assert(
                requires {
                    { functions.amd_display_native_hdr };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amd_display_native_hdr, "vkSetLocalDimmingAMD">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::amd_display_native_hdr, "vkSetLocalDimmingAMD">::get(*functions.amd_display_native_hdr);
        }
    #endif // defined(VK_AMD_display_native_hdr)

        return nullptr;
    }
};
#endif // defined(VK_AMD_display_native_hdr)

#if defined(VK_KHR_fragment_shading_rate)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceFragmentShadingRatesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_fragment_shading_rate)
        if(functions.khr_fragment_shading_rate)
        {
            static_assert(
                requires {
                    { functions.khr_fragment_shading_rate };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_fragment_shading_rate, "vkGetPhysicalDeviceFragmentShadingRatesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_fragment_shading_rate, "vkGetPhysicalDeviceFragmentShadingRatesKHR">::get(
                *functions.khr_fragment_shading_rate);
        }
    #endif // defined(VK_KHR_fragment_shading_rate)

        return nullptr;
    }
};
#endif // defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
template<>
struct get_from<extension::device_functions, "vkCmdSetFragmentShadingRateKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetFragmentShadingRateKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_fragment_shading_rate)
        if(functions.khr_fragment_shading_rate)
        {
            static_assert(
                requires {
                    { functions.khr_fragment_shading_rate };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_fragment_shading_rate, "vkCmdSetFragmentShadingRateKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_fragment_shading_rate, "vkCmdSetFragmentShadingRateKHR">::get(
                *functions.khr_fragment_shading_rate);
        }
    #endif // defined(VK_KHR_fragment_shading_rate)

        return nullptr;
    }
};
#endif // defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_dynamic_rendering_local_read)
template<>
struct get_from<extension::device_functions, "vkCmdSetRenderingAttachmentLocationsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetRenderingAttachmentLocationsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_dynamic_rendering_local_read)
        if(functions.khr_dynamic_rendering_local_read)
        {
            static_assert(
                requires {
                    { functions.khr_dynamic_rendering_local_read };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_dynamic_rendering_local_read, "vkCmdSetRenderingAttachmentLocationsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_dynamic_rendering_local_read, "vkCmdSetRenderingAttachmentLocationsKHR">::get(
                *functions.khr_dynamic_rendering_local_read);
        }
    #endif // defined(VK_KHR_dynamic_rendering_local_read)

        return nullptr;
    }
};
#endif // defined(VK_KHR_dynamic_rendering_local_read)

#if defined(VK_KHR_dynamic_rendering_local_read)
template<>
struct get_from<extension::device_functions, "vkCmdSetRenderingInputAttachmentIndicesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetRenderingInputAttachmentIndicesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_dynamic_rendering_local_read)
        if(functions.khr_dynamic_rendering_local_read)
        {
            static_assert(
                requires {
                    { functions.khr_dynamic_rendering_local_read };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_dynamic_rendering_local_read, "vkCmdSetRenderingInputAttachmentIndicesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_dynamic_rendering_local_read, "vkCmdSetRenderingInputAttachmentIndicesKHR">::get(
                *functions.khr_dynamic_rendering_local_read);
        }
    #endif // defined(VK_KHR_dynamic_rendering_local_read)

        return nullptr;
    }
};
#endif // defined(VK_KHR_dynamic_rendering_local_read)

#if defined(VK_EXT_buffer_device_address)
template<>
struct get_from<extension::device_functions, "vkGetBufferDeviceAddressEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetBufferDeviceAddressEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_buffer_device_address)
        if(functions.ext_buffer_device_address)
        {
            static_assert(
                requires {
                    { functions.ext_buffer_device_address };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_buffer_device_address, "vkGetBufferDeviceAddressEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_buffer_device_address, "vkGetBufferDeviceAddressEXT">::get(
                *functions.ext_buffer_device_address);
        }
    #endif // defined(VK_EXT_buffer_device_address)

        return nullptr;
    }
};
#endif // defined(VK_EXT_buffer_device_address)

#if defined(VK_EXT_tooling_info)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceToolPropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceToolPropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_tooling_info)
        if(functions.ext_tooling_info)
        {
            static_assert(
                requires {
                    { functions.ext_tooling_info };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_tooling_info, "vkGetPhysicalDeviceToolPropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_tooling_info, "vkGetPhysicalDeviceToolPropertiesEXT">::get(*functions.ext_tooling_info);
        }
    #endif // defined(VK_EXT_tooling_info)

        return nullptr;
    }
};
#endif // defined(VK_EXT_tooling_info)

#if defined(VK_KHR_present_wait)
template<>
struct get_from<extension::device_functions, "vkWaitForPresentKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkWaitForPresentKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_present_wait)
        if(functions.khr_present_wait)
        {
            static_assert(
                requires {
                    { functions.khr_present_wait };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_present_wait, "vkWaitForPresentKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_present_wait, "vkWaitForPresentKHR">::get(*functions.khr_present_wait);
        }
    #endif // defined(VK_KHR_present_wait)

        return nullptr;
    }
};
#endif // defined(VK_KHR_present_wait)

#if defined(VK_NV_cooperative_matrix)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cooperative_matrix)
        if(functions.nv_cooperative_matrix)
        {
            static_assert(
                requires {
                    { functions.nv_cooperative_matrix };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cooperative_matrix, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cooperative_matrix, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV">::get(
                *functions.nv_cooperative_matrix);
        }
    #endif // defined(VK_NV_cooperative_matrix)

        return nullptr;
    }
};
#endif // defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_coverage_reduction_mode)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV
    get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_coverage_reduction_mode)
        if(functions.nv_coverage_reduction_mode)
        {
            static_assert(
                requires {
                    { functions.nv_coverage_reduction_mode };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_coverage_reduction_mode,
                                   "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_coverage_reduction_mode,
                            "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV">::get(*functions.nv_coverage_reduction_mode);
        }
    #endif // defined(VK_NV_coverage_reduction_mode)

        return nullptr;
    }
};
#endif // defined(VK_NV_coverage_reduction_mode)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceSurfacePresentModes2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_full_screen_exclusive)
        if(functions.ext_full_screen_exclusive)
        {
            static_assert(
                requires {
                    { functions.ext_full_screen_exclusive };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_full_screen_exclusive, "vkGetPhysicalDeviceSurfacePresentModes2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_full_screen_exclusive, "vkGetPhysicalDeviceSurfacePresentModes2EXT">::get(
                *functions.ext_full_screen_exclusive);
        }
    #endif // defined(VK_EXT_full_screen_exclusive)

        return nullptr;
    }
};
#endif // defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct get_from<extension::device_functions, "vkAcquireFullScreenExclusiveModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquireFullScreenExclusiveModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_full_screen_exclusive)
        if(functions.ext_full_screen_exclusive)
        {
            static_assert(
                requires {
                    { functions.ext_full_screen_exclusive };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_full_screen_exclusive, "vkAcquireFullScreenExclusiveModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_full_screen_exclusive, "vkAcquireFullScreenExclusiveModeEXT">::get(
                *functions.ext_full_screen_exclusive);
        }
    #endif // defined(VK_EXT_full_screen_exclusive)

        return nullptr;
    }
};
#endif // defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct get_from<extension::device_functions, "vkReleaseFullScreenExclusiveModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkReleaseFullScreenExclusiveModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_full_screen_exclusive)
        if(functions.ext_full_screen_exclusive)
        {
            static_assert(
                requires {
                    { functions.ext_full_screen_exclusive };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_full_screen_exclusive, "vkReleaseFullScreenExclusiveModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_full_screen_exclusive, "vkReleaseFullScreenExclusiveModeEXT">::get(
                *functions.ext_full_screen_exclusive);
        }
    #endif // defined(VK_EXT_full_screen_exclusive)

        return nullptr;
    }
};
#endif // defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct get_from<extension::device_functions, "vkGetDeviceGroupSurfacePresentModes2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceGroupSurfacePresentModes2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_full_screen_exclusive)
        if(functions.ext_full_screen_exclusive)
        {
            static_assert(
                requires {
                    { functions.ext_full_screen_exclusive };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_full_screen_exclusive, "vkGetDeviceGroupSurfacePresentModes2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_full_screen_exclusive, "vkGetDeviceGroupSurfacePresentModes2EXT">::get(
                *functions.ext_full_screen_exclusive);
        }
    #endif // defined(VK_EXT_full_screen_exclusive)

        return nullptr;
    }
};
#endif // defined(VK_EXT_full_screen_exclusive)

#if defined(VK_KHR_buffer_device_address)
template<>
struct get_from<extension::device_functions, "vkGetBufferDeviceAddressKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetBufferDeviceAddressKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_buffer_device_address)
        if(functions.khr_buffer_device_address)
        {
            static_assert(
                requires {
                    { functions.khr_buffer_device_address };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_buffer_device_address, "vkGetBufferDeviceAddressKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_buffer_device_address, "vkGetBufferDeviceAddressKHR">::get(
                *functions.khr_buffer_device_address);
        }
    #endif // defined(VK_KHR_buffer_device_address)

        return nullptr;
    }
};
#endif // defined(VK_KHR_buffer_device_address)

#if defined(VK_KHR_buffer_device_address)
template<>
struct get_from<extension::device_functions, "vkGetBufferOpaqueCaptureAddressKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetBufferOpaqueCaptureAddressKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_buffer_device_address)
        if(functions.khr_buffer_device_address)
        {
            static_assert(
                requires {
                    { functions.khr_buffer_device_address };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_buffer_device_address, "vkGetBufferOpaqueCaptureAddressKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_buffer_device_address, "vkGetBufferOpaqueCaptureAddressKHR">::get(
                *functions.khr_buffer_device_address);
        }
    #endif // defined(VK_KHR_buffer_device_address)

        return nullptr;
    }
};
#endif // defined(VK_KHR_buffer_device_address)

#if defined(VK_KHR_buffer_device_address)
template<>
struct get_from<extension::device_functions, "vkGetDeviceMemoryOpaqueCaptureAddressKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_buffer_device_address)
        if(functions.khr_buffer_device_address)
        {
            static_assert(
                requires {
                    { functions.khr_buffer_device_address };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_buffer_device_address, "vkGetDeviceMemoryOpaqueCaptureAddressKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_buffer_device_address, "vkGetDeviceMemoryOpaqueCaptureAddressKHR">::get(
                *functions.khr_buffer_device_address);
        }
    #endif // defined(VK_KHR_buffer_device_address)

        return nullptr;
    }
};
#endif // defined(VK_KHR_buffer_device_address)

#if defined(VK_EXT_line_rasterization)
template<>
struct get_from<extension::device_functions, "vkCmdSetLineStippleEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetLineStippleEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_line_rasterization)
        if(functions.ext_line_rasterization)
        {
            static_assert(
                requires {
                    { functions.ext_line_rasterization };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_line_rasterization, "vkCmdSetLineStippleEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_line_rasterization, "vkCmdSetLineStippleEXT">::get(*functions.ext_line_rasterization);
        }
    #endif // defined(VK_EXT_line_rasterization)

        return nullptr;
    }
};
#endif // defined(VK_EXT_line_rasterization)

#if defined(VK_EXT_host_query_reset)
template<>
struct get_from<extension::device_functions, "vkResetQueryPoolEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkResetQueryPoolEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_host_query_reset)
        if(functions.ext_host_query_reset)
        {
            static_assert(
                requires {
                    { functions.ext_host_query_reset };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_host_query_reset, "vkResetQueryPoolEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_host_query_reset, "vkResetQueryPoolEXT">::get(*functions.ext_host_query_reset);
        }
    #endif // defined(VK_EXT_host_query_reset)

        return nullptr;
    }
};
#endif // defined(VK_EXT_host_query_reset)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetCullModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCullModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetCullModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetCullModeEXT">::get(*functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetCullModeEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetCullModeEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetFrontFaceEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetFrontFaceEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetFrontFaceEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetFrontFaceEXT">::get(*functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetFrontFaceEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetFrontFaceEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetPrimitiveTopologyEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetPrimitiveTopologyEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetPrimitiveTopologyEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetPrimitiveTopologyEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetPrimitiveTopologyEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetPrimitiveTopologyEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetViewportWithCountEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetViewportWithCountEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetViewportWithCountEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetViewportWithCountEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetViewportWithCountEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetViewportWithCountEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetScissorWithCountEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetScissorWithCountEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetScissorWithCountEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetScissorWithCountEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetScissorWithCountEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetScissorWithCountEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdBindVertexBuffers2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindVertexBuffers2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdBindVertexBuffers2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdBindVertexBuffers2EXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdBindVertexBuffers2EXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdBindVertexBuffers2EXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthTestEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthTestEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthTestEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthTestEnableEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthTestEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthTestEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthWriteEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthWriteEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthWriteEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthWriteEnableEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthWriteEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthWriteEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthCompareOpEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthCompareOpEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthCompareOpEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthCompareOpEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthCompareOpEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthCompareOpEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthBoundsTestEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthBoundsTestEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthBoundsTestEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetDepthBoundsTestEnableEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthBoundsTestEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthBoundsTestEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetStencilTestEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetStencilTestEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetStencilTestEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetStencilTestEnableEXT">::get(
                *functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetStencilTestEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetStencilTestEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetStencilOpEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetStencilOpEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state)
        if(functions.ext_extended_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetStencilOpEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state, "vkCmdSetStencilOpEXT">::get(*functions.ext_extended_dynamic_state);
        }
    #endif // defined(VK_EXT_extended_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetStencilOpEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetStencilOpEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct get_from<extension::device_functions, "vkCreateDeferredOperationKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateDeferredOperationKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_deferred_host_operations)
        if(functions.khr_deferred_host_operations)
        {
            static_assert(
                requires {
                    { functions.khr_deferred_host_operations };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_deferred_host_operations, "vkCreateDeferredOperationKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_deferred_host_operations, "vkCreateDeferredOperationKHR">::get(
                *functions.khr_deferred_host_operations);
        }
    #endif // defined(VK_KHR_deferred_host_operations)

        return nullptr;
    }
};
#endif // defined(VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct get_from<extension::device_functions, "vkDestroyDeferredOperationKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyDeferredOperationKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_deferred_host_operations)
        if(functions.khr_deferred_host_operations)
        {
            static_assert(
                requires {
                    { functions.khr_deferred_host_operations };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_deferred_host_operations, "vkDestroyDeferredOperationKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_deferred_host_operations, "vkDestroyDeferredOperationKHR">::get(
                *functions.khr_deferred_host_operations);
        }
    #endif // defined(VK_KHR_deferred_host_operations)

        return nullptr;
    }
};
#endif // defined(VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct get_from<extension::device_functions, "vkGetDeferredOperationMaxConcurrencyKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeferredOperationMaxConcurrencyKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_deferred_host_operations)
        if(functions.khr_deferred_host_operations)
        {
            static_assert(
                requires {
                    { functions.khr_deferred_host_operations };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_deferred_host_operations, "vkGetDeferredOperationMaxConcurrencyKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_deferred_host_operations, "vkGetDeferredOperationMaxConcurrencyKHR">::get(
                *functions.khr_deferred_host_operations);
        }
    #endif // defined(VK_KHR_deferred_host_operations)

        return nullptr;
    }
};
#endif // defined(VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct get_from<extension::device_functions, "vkGetDeferredOperationResultKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeferredOperationResultKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_deferred_host_operations)
        if(functions.khr_deferred_host_operations)
        {
            static_assert(
                requires {
                    { functions.khr_deferred_host_operations };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_deferred_host_operations, "vkGetDeferredOperationResultKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_deferred_host_operations, "vkGetDeferredOperationResultKHR">::get(
                *functions.khr_deferred_host_operations);
        }
    #endif // defined(VK_KHR_deferred_host_operations)

        return nullptr;
    }
};
#endif // defined(VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct get_from<extension::device_functions, "vkDeferredOperationJoinKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDeferredOperationJoinKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_deferred_host_operations)
        if(functions.khr_deferred_host_operations)
        {
            static_assert(
                requires {
                    { functions.khr_deferred_host_operations };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_deferred_host_operations, "vkDeferredOperationJoinKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_deferred_host_operations, "vkDeferredOperationJoinKHR">::get(
                *functions.khr_deferred_host_operations);
        }
    #endif // defined(VK_KHR_deferred_host_operations)

        return nullptr;
    }
};
#endif // defined(VK_KHR_deferred_host_operations)

#if defined(VK_KHR_pipeline_executable_properties)
template<>
struct get_from<extension::device_functions, "vkGetPipelineExecutablePropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelineExecutablePropertiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_executable_properties)
        if(functions.khr_pipeline_executable_properties)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_executable_properties };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_pipeline_executable_properties, "vkGetPipelineExecutablePropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_executable_properties, "vkGetPipelineExecutablePropertiesKHR">::get(
                *functions.khr_pipeline_executable_properties);
        }
    #endif // defined(VK_KHR_pipeline_executable_properties)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
template<>
struct get_from<extension::device_functions, "vkGetPipelineExecutableStatisticsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelineExecutableStatisticsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_executable_properties)
        if(functions.khr_pipeline_executable_properties)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_executable_properties };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_pipeline_executable_properties, "vkGetPipelineExecutableStatisticsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_executable_properties, "vkGetPipelineExecutableStatisticsKHR">::get(
                *functions.khr_pipeline_executable_properties);
        }
    #endif // defined(VK_KHR_pipeline_executable_properties)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
template<>
struct get_from<extension::device_functions, "vkGetPipelineExecutableInternalRepresentationsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelineExecutableInternalRepresentationsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_executable_properties)
        if(functions.khr_pipeline_executable_properties)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_executable_properties };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::khr_pipeline_executable_properties, "vkGetPipelineExecutableInternalRepresentationsKHR">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_executable_properties, "vkGetPipelineExecutableInternalRepresentationsKHR">::get(
                *functions.khr_pipeline_executable_properties);
        }
    #endif // defined(VK_KHR_pipeline_executable_properties)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_EXT_host_image_copy)
template<>
struct get_from<extension::device_functions, "vkCopyMemoryToImageEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyMemoryToImageEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_host_image_copy)
        if(functions.ext_host_image_copy)
        {
            static_assert(
                requires {
                    { functions.ext_host_image_copy };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_host_image_copy, "vkCopyMemoryToImageEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_host_image_copy, "vkCopyMemoryToImageEXT">::get(*functions.ext_host_image_copy);
        }
    #endif // defined(VK_EXT_host_image_copy)

        return nullptr;
    }
};
#endif // defined(VK_EXT_host_image_copy)

#if defined(VK_EXT_host_image_copy)
template<>
struct get_from<extension::device_functions, "vkCopyImageToMemoryEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyImageToMemoryEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_host_image_copy)
        if(functions.ext_host_image_copy)
        {
            static_assert(
                requires {
                    { functions.ext_host_image_copy };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_host_image_copy, "vkCopyImageToMemoryEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_host_image_copy, "vkCopyImageToMemoryEXT">::get(*functions.ext_host_image_copy);
        }
    #endif // defined(VK_EXT_host_image_copy)

        return nullptr;
    }
};
#endif // defined(VK_EXT_host_image_copy)

#if defined(VK_EXT_host_image_copy)
template<>
struct get_from<extension::device_functions, "vkCopyImageToImageEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyImageToImageEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_host_image_copy)
        if(functions.ext_host_image_copy)
        {
            static_assert(
                requires {
                    { functions.ext_host_image_copy };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_host_image_copy, "vkCopyImageToImageEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_host_image_copy, "vkCopyImageToImageEXT">::get(*functions.ext_host_image_copy);
        }
    #endif // defined(VK_EXT_host_image_copy)

        return nullptr;
    }
};
#endif // defined(VK_EXT_host_image_copy)

#if defined(VK_EXT_host_image_copy)
template<>
struct get_from<extension::device_functions, "vkTransitionImageLayoutEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkTransitionImageLayoutEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_host_image_copy)
        if(functions.ext_host_image_copy)
        {
            static_assert(
                requires {
                    { functions.ext_host_image_copy };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_host_image_copy, "vkTransitionImageLayoutEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_host_image_copy, "vkTransitionImageLayoutEXT">::get(*functions.ext_host_image_copy);
        }
    #endif // defined(VK_EXT_host_image_copy)

        return nullptr;
    }
};
#endif // defined(VK_EXT_host_image_copy)

#if defined(VK_EXT_image_compression_control) or defined(VK_EXT_host_image_copy)
template<>
struct get_from<extension::device_functions, "vkGetImageSubresourceLayout2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageSubresourceLayout2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_host_image_copy)
        if(functions.ext_host_image_copy)
        {
            static_assert(
                requires {
                    { functions.ext_host_image_copy };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_host_image_copy, "vkGetImageSubresourceLayout2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_host_image_copy, "vkGetImageSubresourceLayout2EXT">::get(*functions.ext_host_image_copy);
        }
    #endif // defined(VK_EXT_host_image_copy)

    #if defined(VK_EXT_image_compression_control)
        if(functions.ext_image_compression_control)
        {
            static_assert(
                requires {
                    { functions.ext_image_compression_control };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_image_compression_control, "vkGetImageSubresourceLayout2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_image_compression_control, "vkGetImageSubresourceLayout2EXT">::get(
                *functions.ext_image_compression_control);
        }
    #endif // defined(VK_EXT_image_compression_control)

        return nullptr;
    }
};
#endif // defined(VK_EXT_image_compression_control)or defined(VK_EXT_host_image_copy)

#if defined(VK_KHR_map_memory2)
template<>
struct get_from<extension::device_functions, "vkMapMemory2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkMapMemory2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_map_memory2)
        if(functions.khr_map_memory2)
        {
            static_assert(
                requires {
                    { functions.khr_map_memory2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_map_memory2, "vkMapMemory2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_map_memory2, "vkMapMemory2KHR">::get(*functions.khr_map_memory2);
        }
    #endif // defined(VK_KHR_map_memory2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_map_memory2)

#if defined(VK_KHR_map_memory2)
template<>
struct get_from<extension::device_functions, "vkUnmapMemory2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkUnmapMemory2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_map_memory2)
        if(functions.khr_map_memory2)
        {
            static_assert(
                requires {
                    { functions.khr_map_memory2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_map_memory2, "vkUnmapMemory2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_map_memory2, "vkUnmapMemory2KHR">::get(*functions.khr_map_memory2);
        }
    #endif // defined(VK_KHR_map_memory2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_map_memory2)

#if defined(VK_EXT_swapchain_maintenance1)
template<>
struct get_from<extension::device_functions, "vkReleaseSwapchainImagesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkReleaseSwapchainImagesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_swapchain_maintenance1)
        if(functions.ext_swapchain_maintenance1)
        {
            static_assert(
                requires {
                    { functions.ext_swapchain_maintenance1 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_swapchain_maintenance1, "vkReleaseSwapchainImagesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_swapchain_maintenance1, "vkReleaseSwapchainImagesEXT">::get(
                *functions.ext_swapchain_maintenance1);
        }
    #endif // defined(VK_EXT_swapchain_maintenance1)

        return nullptr;
    }
};
#endif // defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_NV_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkGetGeneratedCommandsMemoryRequirementsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetGeneratedCommandsMemoryRequirementsNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands)
        if(functions.nv_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands, "vkGetGeneratedCommandsMemoryRequirementsNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands, "vkGetGeneratedCommandsMemoryRequirementsNV">::get(
                *functions.nv_device_generated_commands);
        }
    #endif // defined(VK_NV_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCreateIndirectCommandsLayoutNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateIndirectCommandsLayoutNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands)
        if(functions.nv_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands, "vkCreateIndirectCommandsLayoutNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands, "vkCreateIndirectCommandsLayoutNV">::get(
                *functions.nv_device_generated_commands);
        }
    #endif // defined(VK_NV_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkDestroyIndirectCommandsLayoutNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyIndirectCommandsLayoutNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands)
        if(functions.nv_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands, "vkDestroyIndirectCommandsLayoutNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands, "vkDestroyIndirectCommandsLayoutNV">::get(
                *functions.nv_device_generated_commands);
        }
    #endif // defined(VK_NV_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCmdPreprocessGeneratedCommandsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPreprocessGeneratedCommandsNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands)
        if(functions.nv_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands, "vkCmdPreprocessGeneratedCommandsNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands, "vkCmdPreprocessGeneratedCommandsNV">::get(
                *functions.nv_device_generated_commands);
        }
    #endif // defined(VK_NV_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCmdExecuteGeneratedCommandsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdExecuteGeneratedCommandsNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands)
        if(functions.nv_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands, "vkCmdExecuteGeneratedCommandsNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands, "vkCmdExecuteGeneratedCommandsNV">::get(
                *functions.nv_device_generated_commands);
        }
    #endif // defined(VK_NV_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCmdBindPipelineShaderGroupNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindPipelineShaderGroupNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands)
        if(functions.nv_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands, "vkCmdBindPipelineShaderGroupNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands, "vkCmdBindPipelineShaderGroupNV">::get(
                *functions.nv_device_generated_commands);
        }
    #endif // defined(VK_NV_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands)

#if defined(VK_EXT_depth_bias_control)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthBias2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthBias2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_depth_bias_control)
        if(functions.ext_depth_bias_control)
        {
            static_assert(
                requires {
                    { functions.ext_depth_bias_control };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_depth_bias_control, "vkCmdSetDepthBias2EXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_depth_bias_control, "vkCmdSetDepthBias2EXT">::get(*functions.ext_depth_bias_control);
        }
    #endif // defined(VK_EXT_depth_bias_control)

        return nullptr;
    }
};
#endif // defined(VK_EXT_depth_bias_control)

#if defined(VK_EXT_private_data)
template<>
struct get_from<extension::device_functions, "vkCreatePrivateDataSlotEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreatePrivateDataSlotEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_private_data)
        if(functions.ext_private_data)
        {
            static_assert(
                requires {
                    { functions.ext_private_data };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_private_data, "vkCreatePrivateDataSlotEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_private_data, "vkCreatePrivateDataSlotEXT">::get(*functions.ext_private_data);
        }
    #endif // defined(VK_EXT_private_data)

        return nullptr;
    }
};
#endif // defined(VK_EXT_private_data)

#if defined(VK_EXT_private_data)
template<>
struct get_from<extension::device_functions, "vkDestroyPrivateDataSlotEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyPrivateDataSlotEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_private_data)
        if(functions.ext_private_data)
        {
            static_assert(
                requires {
                    { functions.ext_private_data };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_private_data, "vkDestroyPrivateDataSlotEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_private_data, "vkDestroyPrivateDataSlotEXT">::get(*functions.ext_private_data);
        }
    #endif // defined(VK_EXT_private_data)

        return nullptr;
    }
};
#endif // defined(VK_EXT_private_data)

#if defined(VK_EXT_private_data)
template<>
struct get_from<extension::device_functions, "vkSetPrivateDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetPrivateDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_private_data)
        if(functions.ext_private_data)
        {
            static_assert(
                requires {
                    { functions.ext_private_data };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_private_data, "vkSetPrivateDataEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_private_data, "vkSetPrivateDataEXT">::get(*functions.ext_private_data);
        }
    #endif // defined(VK_EXT_private_data)

        return nullptr;
    }
};
#endif // defined(VK_EXT_private_data)

#if defined(VK_EXT_private_data)
template<>
struct get_from<extension::device_functions, "vkGetPrivateDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPrivateDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_private_data)
        if(functions.ext_private_data)
        {
            static_assert(
                requires {
                    { functions.ext_private_data };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_private_data, "vkGetPrivateDataEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_private_data, "vkGetPrivateDataEXT">::get(*functions.ext_private_data);
        }
    #endif // defined(VK_EXT_private_data)

        return nullptr;
    }
};
#endif // defined(VK_EXT_private_data)

#if defined(VK_KHR_video_encode_queue)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR
    get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_encode_queue)
        if(functions.khr_video_encode_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_encode_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_encode_queue, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_encode_queue, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR">::get(
                *functions.khr_video_encode_queue);
        }
    #endif // defined(VK_KHR_video_encode_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
template<>
struct get_from<extension::device_functions, "vkGetEncodedVideoSessionParametersKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetEncodedVideoSessionParametersKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_encode_queue)
        if(functions.khr_video_encode_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_encode_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_encode_queue, "vkGetEncodedVideoSessionParametersKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_encode_queue, "vkGetEncodedVideoSessionParametersKHR">::get(
                *functions.khr_video_encode_queue);
        }
    #endif // defined(VK_KHR_video_encode_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
template<>
struct get_from<extension::device_functions, "vkCmdEncodeVideoKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEncodeVideoKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_video_encode_queue)
        if(functions.khr_video_encode_queue)
        {
            static_assert(
                requires {
                    { functions.khr_video_encode_queue };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_video_encode_queue, "vkCmdEncodeVideoKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_video_encode_queue, "vkCmdEncodeVideoKHR">::get(*functions.khr_video_encode_queue);
        }
    #endif // defined(VK_KHR_video_encode_queue)

        return nullptr;
    }
};
#endif // defined(VK_KHR_video_encode_queue)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct get_from<extension::device_functions, "vkCreateCudaModuleNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateCudaModuleNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cuda_kernel_launch)
        if(functions.nv_cuda_kernel_launch)
        {
            static_assert(
                requires {
                    { functions.nv_cuda_kernel_launch };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cuda_kernel_launch, "vkCreateCudaModuleNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cuda_kernel_launch, "vkCreateCudaModuleNV">::get(*functions.nv_cuda_kernel_launch);
        }
    #endif // defined(VK_NV_cuda_kernel_launch)

        return nullptr;
    }
};
#endif // defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct get_from<extension::device_functions, "vkGetCudaModuleCacheNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetCudaModuleCacheNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cuda_kernel_launch)
        if(functions.nv_cuda_kernel_launch)
        {
            static_assert(
                requires {
                    { functions.nv_cuda_kernel_launch };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cuda_kernel_launch, "vkGetCudaModuleCacheNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cuda_kernel_launch, "vkGetCudaModuleCacheNV">::get(*functions.nv_cuda_kernel_launch);
        }
    #endif // defined(VK_NV_cuda_kernel_launch)

        return nullptr;
    }
};
#endif // defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct get_from<extension::device_functions, "vkCreateCudaFunctionNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateCudaFunctionNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cuda_kernel_launch)
        if(functions.nv_cuda_kernel_launch)
        {
            static_assert(
                requires {
                    { functions.nv_cuda_kernel_launch };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cuda_kernel_launch, "vkCreateCudaFunctionNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cuda_kernel_launch, "vkCreateCudaFunctionNV">::get(*functions.nv_cuda_kernel_launch);
        }
    #endif // defined(VK_NV_cuda_kernel_launch)

        return nullptr;
    }
};
#endif // defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct get_from<extension::device_functions, "vkDestroyCudaModuleNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyCudaModuleNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cuda_kernel_launch)
        if(functions.nv_cuda_kernel_launch)
        {
            static_assert(
                requires {
                    { functions.nv_cuda_kernel_launch };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cuda_kernel_launch, "vkDestroyCudaModuleNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cuda_kernel_launch, "vkDestroyCudaModuleNV">::get(*functions.nv_cuda_kernel_launch);
        }
    #endif // defined(VK_NV_cuda_kernel_launch)

        return nullptr;
    }
};
#endif // defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct get_from<extension::device_functions, "vkDestroyCudaFunctionNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyCudaFunctionNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cuda_kernel_launch)
        if(functions.nv_cuda_kernel_launch)
        {
            static_assert(
                requires {
                    { functions.nv_cuda_kernel_launch };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cuda_kernel_launch, "vkDestroyCudaFunctionNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cuda_kernel_launch, "vkDestroyCudaFunctionNV">::get(*functions.nv_cuda_kernel_launch);
        }
    #endif // defined(VK_NV_cuda_kernel_launch)

        return nullptr;
    }
};
#endif // defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct get_from<extension::device_functions, "vkCmdCudaLaunchKernelNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCudaLaunchKernelNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cuda_kernel_launch)
        if(functions.nv_cuda_kernel_launch)
        {
            static_assert(
                requires {
                    { functions.nv_cuda_kernel_launch };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cuda_kernel_launch, "vkCmdCudaLaunchKernelNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cuda_kernel_launch, "vkCmdCudaLaunchKernelNV">::get(*functions.nv_cuda_kernel_launch);
        }
    #endif // defined(VK_NV_cuda_kernel_launch)

        return nullptr;
    }
};
#endif // defined(VK_NV_cuda_kernel_launch)

#if defined(VK_EXT_metal_objects)
template<>
struct get_from<extension::device_functions, "vkExportMetalObjectsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkExportMetalObjectsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_metal_objects)
        if(functions.ext_metal_objects)
        {
            static_assert(
                requires {
                    { functions.ext_metal_objects };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_metal_objects, "vkExportMetalObjectsEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_metal_objects, "vkExportMetalObjectsEXT">::get(*functions.ext_metal_objects);
        }
    #endif // defined(VK_EXT_metal_objects)

        return nullptr;
    }
};
#endif // defined(VK_EXT_metal_objects)

#if defined(VK_KHR_synchronization2)
template<>
struct get_from<extension::device_functions, "vkQueueSubmit2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkQueueSubmit2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_synchronization2)
        if(functions.khr_synchronization2)
        {
            static_assert(
                requires {
                    { functions.khr_synchronization2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_synchronization2, "vkQueueSubmit2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_synchronization2, "vkQueueSubmit2KHR">::get(*functions.khr_synchronization2);
        }
    #endif // defined(VK_KHR_synchronization2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct get_from<extension::device_functions, "vkCmdSetEvent2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetEvent2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_synchronization2)
        if(functions.khr_synchronization2)
        {
            static_assert(
                requires {
                    { functions.khr_synchronization2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_synchronization2, "vkCmdSetEvent2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_synchronization2, "vkCmdSetEvent2KHR">::get(*functions.khr_synchronization2);
        }
    #endif // defined(VK_KHR_synchronization2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct get_from<extension::device_functions, "vkCmdResetEvent2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdResetEvent2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_synchronization2)
        if(functions.khr_synchronization2)
        {
            static_assert(
                requires {
                    { functions.khr_synchronization2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_synchronization2, "vkCmdResetEvent2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_synchronization2, "vkCmdResetEvent2KHR">::get(*functions.khr_synchronization2);
        }
    #endif // defined(VK_KHR_synchronization2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct get_from<extension::device_functions, "vkCmdWaitEvents2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdWaitEvents2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_synchronization2)
        if(functions.khr_synchronization2)
        {
            static_assert(
                requires {
                    { functions.khr_synchronization2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_synchronization2, "vkCmdWaitEvents2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_synchronization2, "vkCmdWaitEvents2KHR">::get(*functions.khr_synchronization2);
        }
    #endif // defined(VK_KHR_synchronization2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct get_from<extension::device_functions, "vkCmdPipelineBarrier2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPipelineBarrier2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_synchronization2)
        if(functions.khr_synchronization2)
        {
            static_assert(
                requires {
                    { functions.khr_synchronization2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_synchronization2, "vkCmdPipelineBarrier2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_synchronization2, "vkCmdPipelineBarrier2KHR">::get(*functions.khr_synchronization2);
        }
    #endif // defined(VK_KHR_synchronization2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct get_from<extension::device_functions, "vkCmdWriteTimestamp2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdWriteTimestamp2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_synchronization2)
        if(functions.khr_synchronization2)
        {
            static_assert(
                requires {
                    { functions.khr_synchronization2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_synchronization2, "vkCmdWriteTimestamp2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_synchronization2, "vkCmdWriteTimestamp2KHR">::get(*functions.khr_synchronization2);
        }
    #endif // defined(VK_KHR_synchronization2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_synchronization2)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetDescriptorSetLayoutSizeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDescriptorSetLayoutSizeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetDescriptorSetLayoutSizeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetDescriptorSetLayoutSizeEXT">::get(*functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetDescriptorSetLayoutBindingOffsetEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDescriptorSetLayoutBindingOffsetEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetDescriptorSetLayoutBindingOffsetEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetDescriptorSetLayoutBindingOffsetEXT">::get(
                *functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetDescriptorEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDescriptorEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetDescriptorEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetDescriptorEXT">::get(*functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetBufferOpaqueCaptureDescriptorDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetBufferOpaqueCaptureDescriptorDataEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetBufferOpaqueCaptureDescriptorDataEXT">::get(
                *functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetImageOpaqueCaptureDescriptorDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageOpaqueCaptureDescriptorDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetImageOpaqueCaptureDescriptorDataEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetImageOpaqueCaptureDescriptorDataEXT">::get(
                *functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetImageViewOpaqueCaptureDescriptorDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetImageViewOpaqueCaptureDescriptorDataEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetImageViewOpaqueCaptureDescriptorDataEXT">::get(
                *functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetSamplerOpaqueCaptureDescriptorDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetSamplerOpaqueCaptureDescriptorDataEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetSamplerOpaqueCaptureDescriptorDataEXT">::get(
                *functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT
    get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT">::get(
                *functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkCmdBindDescriptorBuffersEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindDescriptorBuffersEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkCmdBindDescriptorBuffersEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkCmdBindDescriptorBuffersEXT">::get(*functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkCmdSetDescriptorBufferOffsetsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDescriptorBufferOffsetsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkCmdSetDescriptorBufferOffsetsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkCmdSetDescriptorBufferOffsetsEXT">::get(*functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct get_from<extension::device_functions, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_descriptor_buffer)
        if(functions.ext_descriptor_buffer)
        {
            static_assert(
                requires {
                    { functions.ext_descriptor_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_descriptor_buffer, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_descriptor_buffer, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT">::get(
                *functions.ext_descriptor_buffer);
        }
    #endif // defined(VK_EXT_descriptor_buffer)

        return nullptr;
    }
};
#endif // defined(VK_EXT_descriptor_buffer)

#if defined(VK_NV_fragment_shading_rate_enums)
template<>
struct get_from<extension::device_functions, "vkCmdSetFragmentShadingRateEnumNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetFragmentShadingRateEnumNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_fragment_shading_rate_enums)
        if(functions.nv_fragment_shading_rate_enums)
        {
            static_assert(
                requires {
                    { functions.nv_fragment_shading_rate_enums };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_fragment_shading_rate_enums, "vkCmdSetFragmentShadingRateEnumNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_fragment_shading_rate_enums, "vkCmdSetFragmentShadingRateEnumNV">::get(
                *functions.nv_fragment_shading_rate_enums);
        }
    #endif // defined(VK_NV_fragment_shading_rate_enums)

        return nullptr;
    }
};
#endif // defined(VK_NV_fragment_shading_rate_enums)

#if defined(VK_EXT_mesh_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMeshTasksEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMeshTasksEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_mesh_shader)
        if(functions.ext_mesh_shader)
        {
            static_assert(
                requires {
                    { functions.ext_mesh_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_mesh_shader, "vkCmdDrawMeshTasksEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_mesh_shader, "vkCmdDrawMeshTasksEXT">::get(*functions.ext_mesh_shader);
        }
    #endif // defined(VK_EXT_mesh_shader)

        return nullptr;
    }
};
#endif // defined(VK_EXT_mesh_shader)

#if defined(VK_EXT_mesh_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMeshTasksIndirectEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMeshTasksIndirectEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_mesh_shader)
        if(functions.ext_mesh_shader)
        {
            static_assert(
                requires {
                    { functions.ext_mesh_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_mesh_shader, "vkCmdDrawMeshTasksIndirectEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_mesh_shader, "vkCmdDrawMeshTasksIndirectEXT">::get(*functions.ext_mesh_shader);
        }
    #endif // defined(VK_EXT_mesh_shader)

        return nullptr;
    }
};
#endif // defined(VK_EXT_mesh_shader)

#if defined(VK_EXT_mesh_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMeshTasksIndirectCountEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMeshTasksIndirectCountEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_mesh_shader)
        if(functions.ext_mesh_shader)
        {
            static_assert(
                requires {
                    { functions.ext_mesh_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_mesh_shader, "vkCmdDrawMeshTasksIndirectCountEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_mesh_shader, "vkCmdDrawMeshTasksIndirectCountEXT">::get(*functions.ext_mesh_shader);
        }
    #endif // defined(VK_EXT_mesh_shader)

        return nullptr;
    }
};
#endif // defined(VK_EXT_mesh_shader)

#if defined(VK_KHR_copy_commands2)
template<>
struct get_from<extension::device_functions, "vkCmdCopyBuffer2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyBuffer2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_copy_commands2)
        if(functions.khr_copy_commands2)
        {
            static_assert(
                requires {
                    { functions.khr_copy_commands2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_copy_commands2, "vkCmdCopyBuffer2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_copy_commands2, "vkCmdCopyBuffer2KHR">::get(*functions.khr_copy_commands2);
        }
    #endif // defined(VK_KHR_copy_commands2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct get_from<extension::device_functions, "vkCmdCopyImage2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyImage2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_copy_commands2)
        if(functions.khr_copy_commands2)
        {
            static_assert(
                requires {
                    { functions.khr_copy_commands2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_copy_commands2, "vkCmdCopyImage2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_copy_commands2, "vkCmdCopyImage2KHR">::get(*functions.khr_copy_commands2);
        }
    #endif // defined(VK_KHR_copy_commands2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct get_from<extension::device_functions, "vkCmdCopyBufferToImage2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyBufferToImage2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_copy_commands2)
        if(functions.khr_copy_commands2)
        {
            static_assert(
                requires {
                    { functions.khr_copy_commands2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_copy_commands2, "vkCmdCopyBufferToImage2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_copy_commands2, "vkCmdCopyBufferToImage2KHR">::get(*functions.khr_copy_commands2);
        }
    #endif // defined(VK_KHR_copy_commands2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct get_from<extension::device_functions, "vkCmdCopyImageToBuffer2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyImageToBuffer2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_copy_commands2)
        if(functions.khr_copy_commands2)
        {
            static_assert(
                requires {
                    { functions.khr_copy_commands2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_copy_commands2, "vkCmdCopyImageToBuffer2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_copy_commands2, "vkCmdCopyImageToBuffer2KHR">::get(*functions.khr_copy_commands2);
        }
    #endif // defined(VK_KHR_copy_commands2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct get_from<extension::device_functions, "vkCmdBlitImage2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBlitImage2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_copy_commands2)
        if(functions.khr_copy_commands2)
        {
            static_assert(
                requires {
                    { functions.khr_copy_commands2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_copy_commands2, "vkCmdBlitImage2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_copy_commands2, "vkCmdBlitImage2KHR">::get(*functions.khr_copy_commands2);
        }
    #endif // defined(VK_KHR_copy_commands2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct get_from<extension::device_functions, "vkCmdResolveImage2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdResolveImage2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_copy_commands2)
        if(functions.khr_copy_commands2)
        {
            static_assert(
                requires {
                    { functions.khr_copy_commands2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_copy_commands2, "vkCmdResolveImage2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_copy_commands2, "vkCmdResolveImage2KHR">::get(*functions.khr_copy_commands2);
        }
    #endif // defined(VK_KHR_copy_commands2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_copy_commands2)

#if defined(VK_EXT_device_fault)
template<>
struct get_from<extension::device_functions, "vkGetDeviceFaultInfoEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceFaultInfoEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_fault)
        if(functions.ext_device_fault)
        {
            static_assert(
                requires {
                    { functions.ext_device_fault };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_fault, "vkGetDeviceFaultInfoEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_fault, "vkGetDeviceFaultInfoEXT">::get(*functions.ext_device_fault);
        }
    #endif // defined(VK_EXT_device_fault)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_fault)

#if defined(VK_NV_acquire_winrt_display)
template<>
struct get_from<extension::device_functions, "vkAcquireWinrtDisplayNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquireWinrtDisplayNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_acquire_winrt_display)
        if(functions.nv_acquire_winrt_display)
        {
            static_assert(
                requires {
                    { functions.nv_acquire_winrt_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_acquire_winrt_display, "vkAcquireWinrtDisplayNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_acquire_winrt_display, "vkAcquireWinrtDisplayNV">::get(*functions.nv_acquire_winrt_display);
        }
    #endif // defined(VK_NV_acquire_winrt_display)

        return nullptr;
    }
};
#endif // defined(VK_NV_acquire_winrt_display)

#if defined(VK_NV_acquire_winrt_display)
template<>
struct get_from<extension::device_functions, "vkGetWinrtDisplayNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetWinrtDisplayNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_acquire_winrt_display)
        if(functions.nv_acquire_winrt_display)
        {
            static_assert(
                requires {
                    { functions.nv_acquire_winrt_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_acquire_winrt_display, "vkGetWinrtDisplayNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_acquire_winrt_display, "vkGetWinrtDisplayNV">::get(*functions.nv_acquire_winrt_display);
        }
    #endif // defined(VK_NV_acquire_winrt_display)

        return nullptr;
    }
};
#endif // defined(VK_NV_acquire_winrt_display)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_vertex_input_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetVertexInputEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetVertexInputEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_vertex_input_dynamic_state)
        if(functions.ext_vertex_input_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_vertex_input_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_vertex_input_dynamic_state, "vkCmdSetVertexInputEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_vertex_input_dynamic_state, "vkCmdSetVertexInputEXT">::get(
                *functions.ext_vertex_input_dynamic_state);
        }
    #endif // defined(VK_EXT_vertex_input_dynamic_state)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetVertexInputEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetVertexInputEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_vertex_input_dynamic_state)

#if defined(VK_FUCHSIA_external_memory)
template<>
struct get_from<extension::device_functions, "vkGetMemoryZirconHandleFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryZirconHandleFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_external_memory)
        if(functions.fuchsia_external_memory)
        {
            static_assert(
                requires {
                    { functions.fuchsia_external_memory };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_external_memory, "vkGetMemoryZirconHandleFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_external_memory, "vkGetMemoryZirconHandleFUCHSIA">::get(*functions.fuchsia_external_memory);
        }
    #endif // defined(VK_FUCHSIA_external_memory)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
template<>
struct get_from<extension::device_functions, "vkGetMemoryZirconHandlePropertiesFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_external_memory)
        if(functions.fuchsia_external_memory)
        {
            static_assert(
                requires {
                    { functions.fuchsia_external_memory };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_external_memory, "vkGetMemoryZirconHandlePropertiesFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_external_memory, "vkGetMemoryZirconHandlePropertiesFUCHSIA">::get(
                *functions.fuchsia_external_memory);
        }
    #endif // defined(VK_FUCHSIA_external_memory)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_semaphore)
template<>
struct get_from<extension::device_functions, "vkImportSemaphoreZirconHandleFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkImportSemaphoreZirconHandleFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_external_semaphore)
        if(functions.fuchsia_external_semaphore)
        {
            static_assert(
                requires {
                    { functions.fuchsia_external_semaphore };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_external_semaphore, "vkImportSemaphoreZirconHandleFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_external_semaphore, "vkImportSemaphoreZirconHandleFUCHSIA">::get(
                *functions.fuchsia_external_semaphore);
        }
    #endif // defined(VK_FUCHSIA_external_semaphore)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_external_semaphore)

#if defined(VK_FUCHSIA_external_semaphore)
template<>
struct get_from<extension::device_functions, "vkGetSemaphoreZirconHandleFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetSemaphoreZirconHandleFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_external_semaphore)
        if(functions.fuchsia_external_semaphore)
        {
            static_assert(
                requires {
                    { functions.fuchsia_external_semaphore };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_external_semaphore, "vkGetSemaphoreZirconHandleFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_external_semaphore, "vkGetSemaphoreZirconHandleFUCHSIA">::get(
                *functions.fuchsia_external_semaphore);
        }
    #endif // defined(VK_FUCHSIA_external_semaphore)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_external_semaphore)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct get_from<extension::device_functions, "vkCreateBufferCollectionFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateBufferCollectionFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_buffer_collection)
        if(functions.fuchsia_buffer_collection)
        {
            static_assert(
                requires {
                    { functions.fuchsia_buffer_collection };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_buffer_collection, "vkCreateBufferCollectionFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_buffer_collection, "vkCreateBufferCollectionFUCHSIA">::get(
                *functions.fuchsia_buffer_collection);
        }
    #endif // defined(VK_FUCHSIA_buffer_collection)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct get_from<extension::device_functions, "vkSetBufferCollectionImageConstraintsFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetBufferCollectionImageConstraintsFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_buffer_collection)
        if(functions.fuchsia_buffer_collection)
        {
            static_assert(
                requires {
                    { functions.fuchsia_buffer_collection };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_buffer_collection, "vkSetBufferCollectionImageConstraintsFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_buffer_collection, "vkSetBufferCollectionImageConstraintsFUCHSIA">::get(
                *functions.fuchsia_buffer_collection);
        }
    #endif // defined(VK_FUCHSIA_buffer_collection)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct get_from<extension::device_functions, "vkSetBufferCollectionBufferConstraintsFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_buffer_collection)
        if(functions.fuchsia_buffer_collection)
        {
            static_assert(
                requires {
                    { functions.fuchsia_buffer_collection };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_buffer_collection, "vkSetBufferCollectionBufferConstraintsFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_buffer_collection, "vkSetBufferCollectionBufferConstraintsFUCHSIA">::get(
                *functions.fuchsia_buffer_collection);
        }
    #endif // defined(VK_FUCHSIA_buffer_collection)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct get_from<extension::device_functions, "vkDestroyBufferCollectionFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyBufferCollectionFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_buffer_collection)
        if(functions.fuchsia_buffer_collection)
        {
            static_assert(
                requires {
                    { functions.fuchsia_buffer_collection };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_buffer_collection, "vkDestroyBufferCollectionFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_buffer_collection, "vkDestroyBufferCollectionFUCHSIA">::get(
                *functions.fuchsia_buffer_collection);
        }
    #endif // defined(VK_FUCHSIA_buffer_collection)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct get_from<extension::device_functions, "vkGetBufferCollectionPropertiesFUCHSIA">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetBufferCollectionPropertiesFUCHSIA get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_FUCHSIA_buffer_collection)
        if(functions.fuchsia_buffer_collection)
        {
            static_assert(
                requires {
                    { functions.fuchsia_buffer_collection };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::fuchsia_buffer_collection, "vkGetBufferCollectionPropertiesFUCHSIA">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::fuchsia_buffer_collection, "vkGetBufferCollectionPropertiesFUCHSIA">::get(
                *functions.fuchsia_buffer_collection);
        }
    #endif // defined(VK_FUCHSIA_buffer_collection)

        return nullptr;
    }
};
#endif // defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_HUAWEI_subpass_shading)
template<>
struct get_from<extension::device_functions, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_HUAWEI_subpass_shading)
        if(functions.huawei_subpass_shading)
        {
            static_assert(
                requires {
                    { functions.huawei_subpass_shading };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::huawei_subpass_shading, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::huawei_subpass_shading, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI">::get(
                *functions.huawei_subpass_shading);
        }
    #endif // defined(VK_HUAWEI_subpass_shading)

        return nullptr;
    }
};
#endif // defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_subpass_shading)
template<>
struct get_from<extension::device_functions, "vkCmdSubpassShadingHUAWEI">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSubpassShadingHUAWEI get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_HUAWEI_subpass_shading)
        if(functions.huawei_subpass_shading)
        {
            static_assert(
                requires {
                    { functions.huawei_subpass_shading };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::huawei_subpass_shading, "vkCmdSubpassShadingHUAWEI">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::huawei_subpass_shading, "vkCmdSubpassShadingHUAWEI">::get(*functions.huawei_subpass_shading);
        }
    #endif // defined(VK_HUAWEI_subpass_shading)

        return nullptr;
    }
};
#endif // defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_invocation_mask)
template<>
struct get_from<extension::device_functions, "vkCmdBindInvocationMaskHUAWEI">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindInvocationMaskHUAWEI get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_HUAWEI_invocation_mask)
        if(functions.huawei_invocation_mask)
        {
            static_assert(
                requires {
                    { functions.huawei_invocation_mask };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::huawei_invocation_mask, "vkCmdBindInvocationMaskHUAWEI">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::huawei_invocation_mask, "vkCmdBindInvocationMaskHUAWEI">::get(*functions.huawei_invocation_mask);
        }
    #endif // defined(VK_HUAWEI_invocation_mask)

        return nullptr;
    }
};
#endif // defined(VK_HUAWEI_invocation_mask)

#if defined(VK_NV_external_memory_rdma)
template<>
struct get_from<extension::device_functions, "vkGetMemoryRemoteAddressNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryRemoteAddressNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_external_memory_rdma)
        if(functions.nv_external_memory_rdma)
        {
            static_assert(
                requires {
                    { functions.nv_external_memory_rdma };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_external_memory_rdma, "vkGetMemoryRemoteAddressNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_external_memory_rdma, "vkGetMemoryRemoteAddressNV">::get(*functions.nv_external_memory_rdma);
        }
    #endif // defined(VK_NV_external_memory_rdma)

        return nullptr;
    }
};
#endif // defined(VK_NV_external_memory_rdma)

#if defined(VK_EXT_pipeline_properties)
template<>
struct get_from<extension::device_functions, "vkGetPipelinePropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelinePropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_pipeline_properties)
        if(functions.ext_pipeline_properties)
        {
            static_assert(
                requires {
                    { functions.ext_pipeline_properties };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_pipeline_properties, "vkGetPipelinePropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_pipeline_properties, "vkGetPipelinePropertiesEXT">::get(*functions.ext_pipeline_properties);
        }
    #endif // defined(VK_EXT_pipeline_properties)

        return nullptr;
    }
};
#endif // defined(VK_EXT_pipeline_properties)

#if defined(VK_EXT_extended_dynamic_state2) or defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkCmdSetPatchControlPointsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetPatchControlPointsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state2)
        if(functions.ext_extended_dynamic_state2)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetPatchControlPointsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetPatchControlPointsEXT">::get(
                *functions.ext_extended_dynamic_state2);
        }
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetPatchControlPointsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetPatchControlPointsEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_extended_dynamic_state2)or defined(VK_EXT_shader_object)

#if defined(VK_EXT_extended_dynamic_state2) or defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkCmdSetRasterizerDiscardEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetRasterizerDiscardEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state2)
        if(functions.ext_extended_dynamic_state2)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetRasterizerDiscardEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetRasterizerDiscardEnableEXT">::get(
                *functions.ext_extended_dynamic_state2);
        }
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetRasterizerDiscardEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetRasterizerDiscardEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_extended_dynamic_state2)or defined(VK_EXT_shader_object)

#if defined(VK_EXT_extended_dynamic_state2) or defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthBiasEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthBiasEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state2)
        if(functions.ext_extended_dynamic_state2)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetDepthBiasEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetDepthBiasEnableEXT">::get(
                *functions.ext_extended_dynamic_state2);
        }
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthBiasEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthBiasEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_extended_dynamic_state2)or defined(VK_EXT_shader_object)

#if defined(VK_EXT_extended_dynamic_state2) or defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkCmdSetLogicOpEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetLogicOpEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state2)
        if(functions.ext_extended_dynamic_state2)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetLogicOpEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetLogicOpEXT">::get(*functions.ext_extended_dynamic_state2);
        }
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetLogicOpEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetLogicOpEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_extended_dynamic_state2)or defined(VK_EXT_shader_object)

#if defined(VK_EXT_extended_dynamic_state2) or defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkCmdSetPrimitiveRestartEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetPrimitiveRestartEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state2)
        if(functions.ext_extended_dynamic_state2)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetPrimitiveRestartEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state2, "vkCmdSetPrimitiveRestartEnableEXT">::get(
                *functions.ext_extended_dynamic_state2);
        }
    #endif // defined(VK_EXT_extended_dynamic_state2)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetPrimitiveRestartEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetPrimitiveRestartEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_extended_dynamic_state2)or defined(VK_EXT_shader_object)

#if defined(VK_EXT_color_write_enable)
template<>
struct get_from<extension::device_functions, "vkCmdSetColorWriteEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetColorWriteEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_color_write_enable)
        if(functions.ext_color_write_enable)
        {
            static_assert(
                requires {
                    { functions.ext_color_write_enable };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_color_write_enable, "vkCmdSetColorWriteEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_color_write_enable, "vkCmdSetColorWriteEnableEXT">::get(*functions.ext_color_write_enable);
        }
    #endif // defined(VK_EXT_color_write_enable)

        return nullptr;
    }
};
#endif // defined(VK_EXT_color_write_enable)

#if defined(VK_KHR_ray_tracing_maintenance1)
template<>
struct get_from<extension::device_functions, "vkCmdTraceRaysIndirect2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdTraceRaysIndirect2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_ray_tracing_maintenance1)
        if(functions.khr_ray_tracing_maintenance1)
        {
            static_assert(
                requires {
                    { functions.khr_ray_tracing_maintenance1 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_ray_tracing_maintenance1, "vkCmdTraceRaysIndirect2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_ray_tracing_maintenance1, "vkCmdTraceRaysIndirect2KHR">::get(
                *functions.khr_ray_tracing_maintenance1);
        }
    #endif // defined(VK_KHR_ray_tracing_maintenance1)

        return nullptr;
    }
};
#endif // defined(VK_KHR_ray_tracing_maintenance1)

#if defined(VK_EXT_multi_draw)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMultiEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMultiEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_multi_draw)
        if(functions.ext_multi_draw)
        {
            static_assert(
                requires {
                    { functions.ext_multi_draw };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_multi_draw, "vkCmdDrawMultiEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_multi_draw, "vkCmdDrawMultiEXT">::get(*functions.ext_multi_draw);
        }
    #endif // defined(VK_EXT_multi_draw)

        return nullptr;
    }
};
#endif // defined(VK_EXT_multi_draw)

#if defined(VK_EXT_multi_draw)
template<>
struct get_from<extension::device_functions, "vkCmdDrawMultiIndexedEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawMultiIndexedEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_multi_draw)
        if(functions.ext_multi_draw)
        {
            static_assert(
                requires {
                    { functions.ext_multi_draw };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_multi_draw, "vkCmdDrawMultiIndexedEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_multi_draw, "vkCmdDrawMultiIndexedEXT">::get(*functions.ext_multi_draw);
        }
    #endif // defined(VK_EXT_multi_draw)

        return nullptr;
    }
};
#endif // defined(VK_EXT_multi_draw)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCreateMicromapEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateMicromapEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCreateMicromapEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCreateMicromapEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkDestroyMicromapEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyMicromapEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkDestroyMicromapEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkDestroyMicromapEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkBuildMicromapsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkBuildMicromapsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkBuildMicromapsEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkBuildMicromapsEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCopyMicromapEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyMicromapEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCopyMicromapEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCopyMicromapEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCopyMicromapToMemoryEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyMicromapToMemoryEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCopyMicromapToMemoryEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCopyMicromapToMemoryEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCopyMemoryToMicromapEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCopyMemoryToMicromapEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCopyMemoryToMicromapEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCopyMemoryToMicromapEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkWriteMicromapsPropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkWriteMicromapsPropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkWriteMicromapsPropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkWriteMicromapsPropertiesEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkGetDeviceMicromapCompatibilityEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceMicromapCompatibilityEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkGetDeviceMicromapCompatibilityEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkGetDeviceMicromapCompatibilityEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkGetMicromapBuildSizesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMicromapBuildSizesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkGetMicromapBuildSizesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkGetMicromapBuildSizesEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCmdBuildMicromapsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBuildMicromapsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCmdBuildMicromapsEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCmdBuildMicromapsEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCmdCopyMicromapEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyMicromapEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCmdCopyMicromapEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCmdCopyMicromapEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCmdCopyMicromapToMemoryEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyMicromapToMemoryEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCmdCopyMicromapToMemoryEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCmdCopyMicromapToMemoryEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCmdCopyMemoryToMicromapEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyMemoryToMicromapEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCmdCopyMemoryToMicromapEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCmdCopyMemoryToMicromapEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct get_from<extension::device_functions, "vkCmdWriteMicromapsPropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdWriteMicromapsPropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_opacity_micromap)
        if(functions.ext_opacity_micromap)
        {
            static_assert(
                requires {
                    { functions.ext_opacity_micromap };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_opacity_micromap, "vkCmdWriteMicromapsPropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_opacity_micromap, "vkCmdWriteMicromapsPropertiesEXT">::get(*functions.ext_opacity_micromap);
        }
    #endif // defined(VK_EXT_opacity_micromap)

        return nullptr;
    }
};
#endif // defined(VK_EXT_opacity_micromap)

#if defined(VK_HUAWEI_cluster_culling_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawClusterHUAWEI">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawClusterHUAWEI get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_HUAWEI_cluster_culling_shader)
        if(functions.huawei_cluster_culling_shader)
        {
            static_assert(
                requires {
                    { functions.huawei_cluster_culling_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::huawei_cluster_culling_shader, "vkCmdDrawClusterHUAWEI">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::huawei_cluster_culling_shader, "vkCmdDrawClusterHUAWEI">::get(
                *functions.huawei_cluster_culling_shader);
        }
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

        return nullptr;
    }
};
#endif // defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_HUAWEI_cluster_culling_shader)
template<>
struct get_from<extension::device_functions, "vkCmdDrawClusterIndirectHUAWEI">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDrawClusterIndirectHUAWEI get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_HUAWEI_cluster_culling_shader)
        if(functions.huawei_cluster_culling_shader)
        {
            static_assert(
                requires {
                    { functions.huawei_cluster_culling_shader };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::huawei_cluster_culling_shader, "vkCmdDrawClusterIndirectHUAWEI">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::huawei_cluster_culling_shader, "vkCmdDrawClusterIndirectHUAWEI">::get(
                *functions.huawei_cluster_culling_shader);
        }
    #endif // defined(VK_HUAWEI_cluster_culling_shader)

        return nullptr;
    }
};
#endif // defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_EXT_pageable_device_local_memory)
template<>
struct get_from<extension::device_functions, "vkSetDeviceMemoryPriorityEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetDeviceMemoryPriorityEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_pageable_device_local_memory)
        if(functions.ext_pageable_device_local_memory)
        {
            static_assert(
                requires {
                    { functions.ext_pageable_device_local_memory };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_pageable_device_local_memory, "vkSetDeviceMemoryPriorityEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_pageable_device_local_memory, "vkSetDeviceMemoryPriorityEXT">::get(
                *functions.ext_pageable_device_local_memory);
        }
    #endif // defined(VK_EXT_pageable_device_local_memory)

        return nullptr;
    }
};
#endif // defined(VK_EXT_pageable_device_local_memory)

#if defined(VK_KHR_maintenance4)
template<>
struct get_from<extension::device_functions, "vkGetDeviceBufferMemoryRequirementsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceBufferMemoryRequirementsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance4)
        if(functions.khr_maintenance4)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance4 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance4, "vkGetDeviceBufferMemoryRequirementsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance4, "vkGetDeviceBufferMemoryRequirementsKHR">::get(*functions.khr_maintenance4);
        }
    #endif // defined(VK_KHR_maintenance4)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance4)

#if defined(VK_KHR_maintenance4)
template<>
struct get_from<extension::device_functions, "vkGetDeviceImageMemoryRequirementsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceImageMemoryRequirementsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance4)
        if(functions.khr_maintenance4)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance4 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance4, "vkGetDeviceImageMemoryRequirementsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance4, "vkGetDeviceImageMemoryRequirementsKHR">::get(*functions.khr_maintenance4);
        }
    #endif // defined(VK_KHR_maintenance4)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance4)

#if defined(VK_KHR_maintenance4)
template<>
struct get_from<extension::device_functions, "vkGetDeviceImageSparseMemoryRequirementsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceImageSparseMemoryRequirementsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance4)
        if(functions.khr_maintenance4)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance4 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance4, "vkGetDeviceImageSparseMemoryRequirementsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance4, "vkGetDeviceImageSparseMemoryRequirementsKHR">::get(*functions.khr_maintenance4);
        }
    #endif // defined(VK_KHR_maintenance4)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance4)

#if defined(VK_VALVE_descriptor_set_host_mapping)
template<>
struct get_from<extension::device_functions, "vkGetDescriptorSetLayoutHostMappingInfoVALVE">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        if(functions.valve_descriptor_set_host_mapping)
        {
            static_assert(
                requires {
                    { functions.valve_descriptor_set_host_mapping };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::valve_descriptor_set_host_mapping, "vkGetDescriptorSetLayoutHostMappingInfoVALVE">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::valve_descriptor_set_host_mapping, "vkGetDescriptorSetLayoutHostMappingInfoVALVE">::get(
                *functions.valve_descriptor_set_host_mapping);
        }
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

        return nullptr;
    }
};
#endif // defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
template<>
struct get_from<extension::device_functions, "vkGetDescriptorSetHostMappingVALVE">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDescriptorSetHostMappingVALVE get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_VALVE_descriptor_set_host_mapping)
        if(functions.valve_descriptor_set_host_mapping)
        {
            static_assert(
                requires {
                    { functions.valve_descriptor_set_host_mapping };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::valve_descriptor_set_host_mapping, "vkGetDescriptorSetHostMappingVALVE">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::valve_descriptor_set_host_mapping, "vkGetDescriptorSetHostMappingVALVE">::get(
                *functions.valve_descriptor_set_host_mapping);
        }
    #endif // defined(VK_VALVE_descriptor_set_host_mapping)

        return nullptr;
    }
};
#endif // defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_NV_copy_memory_indirect)
template<>
struct get_from<extension::device_functions, "vkCmdCopyMemoryIndirectNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyMemoryIndirectNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_copy_memory_indirect)
        if(functions.nv_copy_memory_indirect)
        {
            static_assert(
                requires {
                    { functions.nv_copy_memory_indirect };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_copy_memory_indirect, "vkCmdCopyMemoryIndirectNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_copy_memory_indirect, "vkCmdCopyMemoryIndirectNV">::get(*functions.nv_copy_memory_indirect);
        }
    #endif // defined(VK_NV_copy_memory_indirect)

        return nullptr;
    }
};
#endif // defined(VK_NV_copy_memory_indirect)

#if defined(VK_NV_copy_memory_indirect)
template<>
struct get_from<extension::device_functions, "vkCmdCopyMemoryToImageIndirectNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdCopyMemoryToImageIndirectNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_copy_memory_indirect)
        if(functions.nv_copy_memory_indirect)
        {
            static_assert(
                requires {
                    { functions.nv_copy_memory_indirect };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_copy_memory_indirect, "vkCmdCopyMemoryToImageIndirectNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_copy_memory_indirect, "vkCmdCopyMemoryToImageIndirectNV">::get(
                *functions.nv_copy_memory_indirect);
        }
    #endif // defined(VK_NV_copy_memory_indirect)

        return nullptr;
    }
};
#endif // defined(VK_NV_copy_memory_indirect)

#if defined(VK_NV_memory_decompression)
template<>
struct get_from<extension::device_functions, "vkCmdDecompressMemoryNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDecompressMemoryNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_memory_decompression)
        if(functions.nv_memory_decompression)
        {
            static_assert(
                requires {
                    { functions.nv_memory_decompression };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_memory_decompression, "vkCmdDecompressMemoryNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_memory_decompression, "vkCmdDecompressMemoryNV">::get(*functions.nv_memory_decompression);
        }
    #endif // defined(VK_NV_memory_decompression)

        return nullptr;
    }
};
#endif // defined(VK_NV_memory_decompression)

#if defined(VK_NV_memory_decompression)
template<>
struct get_from<extension::device_functions, "vkCmdDecompressMemoryIndirectCountNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdDecompressMemoryIndirectCountNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_memory_decompression)
        if(functions.nv_memory_decompression)
        {
            static_assert(
                requires {
                    { functions.nv_memory_decompression };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_memory_decompression, "vkCmdDecompressMemoryIndirectCountNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_memory_decompression, "vkCmdDecompressMemoryIndirectCountNV">::get(
                *functions.nv_memory_decompression);
        }
    #endif // defined(VK_NV_memory_decompression)

        return nullptr;
    }
};
#endif // defined(VK_NV_memory_decompression)

#if defined(VK_NV_device_generated_commands_compute)
template<>
struct get_from<extension::device_functions, "vkGetPipelineIndirectMemoryRequirementsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelineIndirectMemoryRequirementsNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands_compute)
        if(functions.nv_device_generated_commands_compute)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands_compute };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands_compute, "vkGetPipelineIndirectMemoryRequirementsNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands_compute, "vkGetPipelineIndirectMemoryRequirementsNV">::get(
                *functions.nv_device_generated_commands_compute);
        }
    #endif // defined(VK_NV_device_generated_commands_compute)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands_compute)

#if defined(VK_NV_device_generated_commands_compute)
template<>
struct get_from<extension::device_functions, "vkGetPipelineIndirectDeviceAddressNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelineIndirectDeviceAddressNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands_compute)
        if(functions.nv_device_generated_commands_compute)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands_compute };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands_compute, "vkGetPipelineIndirectDeviceAddressNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands_compute, "vkGetPipelineIndirectDeviceAddressNV">::get(
                *functions.nv_device_generated_commands_compute);
        }
    #endif // defined(VK_NV_device_generated_commands_compute)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands_compute)

#if defined(VK_NV_device_generated_commands_compute)
template<>
struct get_from<extension::device_functions, "vkCmdUpdatePipelineIndirectBufferNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdUpdatePipelineIndirectBufferNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_device_generated_commands_compute)
        if(functions.nv_device_generated_commands_compute)
        {
            static_assert(
                requires {
                    { functions.nv_device_generated_commands_compute };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_device_generated_commands_compute, "vkCmdUpdatePipelineIndirectBufferNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_device_generated_commands_compute, "vkCmdUpdatePipelineIndirectBufferNV">::get(
                *functions.nv_device_generated_commands_compute);
        }
    #endif // defined(VK_NV_device_generated_commands_compute)

        return nullptr;
    }
};
#endif // defined(VK_NV_device_generated_commands_compute)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthClampEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthClampEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetDepthClampEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetDepthClampEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClampEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClampEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetPolygonModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetPolygonModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetPolygonModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetPolygonModeEXT">::get(*functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetPolygonModeEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetPolygonModeEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetRasterizationSamplesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetRasterizationSamplesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetRasterizationSamplesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetRasterizationSamplesEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetRasterizationSamplesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetRasterizationSamplesEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetSampleMaskEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetSampleMaskEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetSampleMaskEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetSampleMaskEXT">::get(*functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetSampleMaskEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetSampleMaskEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetAlphaToCoverageEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetAlphaToCoverageEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetAlphaToCoverageEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetAlphaToCoverageEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetAlphaToCoverageEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetAlphaToCoverageEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetAlphaToOneEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetAlphaToOneEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetAlphaToOneEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetAlphaToOneEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetAlphaToOneEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetAlphaToOneEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetLogicOpEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetLogicOpEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetLogicOpEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetLogicOpEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetLogicOpEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetLogicOpEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetColorBlendEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetColorBlendEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorBlendEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorBlendEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetColorBlendEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetColorBlendEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetColorBlendEquationEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetColorBlendEquationEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorBlendEquationEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorBlendEquationEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetColorBlendEquationEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetColorBlendEquationEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetColorWriteMaskEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetColorWriteMaskEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorWriteMaskEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorWriteMaskEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetColorWriteMaskEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetColorWriteMaskEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetTessellationDomainOriginEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetTessellationDomainOriginEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetTessellationDomainOriginEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetTessellationDomainOriginEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetTessellationDomainOriginEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetTessellationDomainOriginEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetRasterizationStreamEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetRasterizationStreamEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetRasterizationStreamEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetRasterizationStreamEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetRasterizationStreamEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetRasterizationStreamEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetConservativeRasterizationModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetConservativeRasterizationModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetConservativeRasterizationModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetConservativeRasterizationModeEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetConservativeRasterizationModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetConservativeRasterizationModeEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetExtraPrimitiveOverestimationSizeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetExtraPrimitiveOverestimationSizeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetExtraPrimitiveOverestimationSizeEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetExtraPrimitiveOverestimationSizeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetExtraPrimitiveOverestimationSizeEXT">::get(
                *functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthClipEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthClipEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetDepthClipEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetDepthClipEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClipEnableEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClipEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetSampleLocationsEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetSampleLocationsEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetSampleLocationsEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetSampleLocationsEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetSampleLocationsEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetSampleLocationsEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetColorBlendAdvancedEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetColorBlendAdvancedEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorBlendAdvancedEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetColorBlendAdvancedEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetColorBlendAdvancedEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetColorBlendAdvancedEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetProvokingVertexModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetProvokingVertexModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetProvokingVertexModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetProvokingVertexModeEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetProvokingVertexModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetProvokingVertexModeEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetLineRasterizationModeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetLineRasterizationModeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetLineRasterizationModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetLineRasterizationModeEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetLineRasterizationModeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetLineRasterizationModeEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetLineStippleEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetLineStippleEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetLineStippleEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetLineStippleEnableEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetLineStippleEnableEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetLineStippleEnableEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthClipNegativeOneToOneEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthClipNegativeOneToOneEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetDepthClipNegativeOneToOneEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetDepthClipNegativeOneToOneEXT">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClipNegativeOneToOneEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClipNegativeOneToOneEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetViewportWScalingEnableNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetViewportWScalingEnableNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetViewportWScalingEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetViewportWScalingEnableNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetViewportWScalingEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetViewportWScalingEnableNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetViewportSwizzleNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetViewportSwizzleNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetViewportSwizzleNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetViewportSwizzleNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetViewportSwizzleNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetViewportSwizzleNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetCoverageToColorEnableNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCoverageToColorEnableNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageToColorEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageToColorEnableNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageToColorEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageToColorEnableNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetCoverageToColorLocationNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCoverageToColorLocationNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageToColorLocationNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageToColorLocationNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageToColorLocationNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageToColorLocationNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetCoverageModulationModeNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCoverageModulationModeNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageModulationModeNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageModulationModeNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageModulationModeNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageModulationModeNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetCoverageModulationTableEnableNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCoverageModulationTableEnableNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageModulationTableEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageModulationTableEnableNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageModulationTableEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageModulationTableEnableNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetCoverageModulationTableNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCoverageModulationTableNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageModulationTableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageModulationTableNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageModulationTableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageModulationTableNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetShadingRateImageEnableNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetShadingRateImageEnableNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetShadingRateImageEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetShadingRateImageEnableNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetShadingRateImageEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetShadingRateImageEnableNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetRepresentativeFragmentTestEnableNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetRepresentativeFragmentTestEnableNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetRepresentativeFragmentTestEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetRepresentativeFragmentTestEnableNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetRepresentativeFragmentTestEnableNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetRepresentativeFragmentTestEnableNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_extended_dynamic_state3)
template<>
struct get_from<extension::device_functions, "vkCmdSetCoverageReductionModeNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetCoverageReductionModeNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_extended_dynamic_state3)
        if(functions.ext_extended_dynamic_state3)
        {
            static_assert(
                requires {
                    { functions.ext_extended_dynamic_state3 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageReductionModeNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_extended_dynamic_state3, "vkCmdSetCoverageReductionModeNV">::get(
                *functions.ext_extended_dynamic_state3);
        }
    #endif // defined(VK_EXT_extended_dynamic_state3)

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageReductionModeNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetCoverageReductionModeNV">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_module_identifier)
template<>
struct get_from<extension::device_functions, "vkGetShaderModuleIdentifierEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetShaderModuleIdentifierEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_shader_module_identifier)
        if(functions.ext_shader_module_identifier)
        {
            static_assert(
                requires {
                    { functions.ext_shader_module_identifier };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_module_identifier, "vkGetShaderModuleIdentifierEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_module_identifier, "vkGetShaderModuleIdentifierEXT">::get(
                *functions.ext_shader_module_identifier);
        }
    #endif // defined(VK_EXT_shader_module_identifier)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
template<>
struct get_from<extension::device_functions, "vkGetShaderModuleCreateInfoIdentifierEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetShaderModuleCreateInfoIdentifierEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_shader_module_identifier)
        if(functions.ext_shader_module_identifier)
        {
            static_assert(
                requires {
                    { functions.ext_shader_module_identifier };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_module_identifier, "vkGetShaderModuleCreateInfoIdentifierEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_module_identifier, "vkGetShaderModuleCreateInfoIdentifierEXT">::get(
                *functions.ext_shader_module_identifier);
        }
    #endif // defined(VK_EXT_shader_module_identifier)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_module_identifier)

#if defined(VK_NV_optical_flow)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_optical_flow)
        if(functions.nv_optical_flow)
        {
            static_assert(
                requires {
                    { functions.nv_optical_flow };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_optical_flow, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_optical_flow, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV">::get(*functions.nv_optical_flow);
        }
    #endif // defined(VK_NV_optical_flow)

        return nullptr;
    }
};
#endif // defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct get_from<extension::device_functions, "vkCreateOpticalFlowSessionNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateOpticalFlowSessionNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_optical_flow)
        if(functions.nv_optical_flow)
        {
            static_assert(
                requires {
                    { functions.nv_optical_flow };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_optical_flow, "vkCreateOpticalFlowSessionNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_optical_flow, "vkCreateOpticalFlowSessionNV">::get(*functions.nv_optical_flow);
        }
    #endif // defined(VK_NV_optical_flow)

        return nullptr;
    }
};
#endif // defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct get_from<extension::device_functions, "vkDestroyOpticalFlowSessionNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyOpticalFlowSessionNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_optical_flow)
        if(functions.nv_optical_flow)
        {
            static_assert(
                requires {
                    { functions.nv_optical_flow };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_optical_flow, "vkDestroyOpticalFlowSessionNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_optical_flow, "vkDestroyOpticalFlowSessionNV">::get(*functions.nv_optical_flow);
        }
    #endif // defined(VK_NV_optical_flow)

        return nullptr;
    }
};
#endif // defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct get_from<extension::device_functions, "vkBindOpticalFlowSessionImageNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkBindOpticalFlowSessionImageNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_optical_flow)
        if(functions.nv_optical_flow)
        {
            static_assert(
                requires {
                    { functions.nv_optical_flow };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_optical_flow, "vkBindOpticalFlowSessionImageNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_optical_flow, "vkBindOpticalFlowSessionImageNV">::get(*functions.nv_optical_flow);
        }
    #endif // defined(VK_NV_optical_flow)

        return nullptr;
    }
};
#endif // defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct get_from<extension::device_functions, "vkCmdOpticalFlowExecuteNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdOpticalFlowExecuteNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_optical_flow)
        if(functions.nv_optical_flow)
        {
            static_assert(
                requires {
                    { functions.nv_optical_flow };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_optical_flow, "vkCmdOpticalFlowExecuteNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_optical_flow, "vkCmdOpticalFlowExecuteNV">::get(*functions.nv_optical_flow);
        }
    #endif // defined(VK_NV_optical_flow)

        return nullptr;
    }
};
#endif // defined(VK_NV_optical_flow)

#if defined(VK_KHR_maintenance5)
template<>
struct get_from<extension::device_functions, "vkGetRenderingAreaGranularityKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetRenderingAreaGranularityKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance5)
        if(functions.khr_maintenance5)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance5 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance5, "vkGetRenderingAreaGranularityKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance5, "vkGetRenderingAreaGranularityKHR">::get(*functions.khr_maintenance5);
        }
    #endif // defined(VK_KHR_maintenance5)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance5)

#if defined(VK_KHR_maintenance5)
template<>
struct get_from<extension::device_functions, "vkGetDeviceImageSubresourceLayoutKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDeviceImageSubresourceLayoutKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance5)
        if(functions.khr_maintenance5)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance5 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance5, "vkGetDeviceImageSubresourceLayoutKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance5, "vkGetDeviceImageSubresourceLayoutKHR">::get(*functions.khr_maintenance5);
        }
    #endif // defined(VK_KHR_maintenance5)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance5)

#if defined(VK_KHR_maintenance5)
template<>
struct get_from<extension::device_functions, "vkGetImageSubresourceLayout2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetImageSubresourceLayout2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance5)
        if(functions.khr_maintenance5)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance5 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance5, "vkGetImageSubresourceLayout2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance5, "vkGetImageSubresourceLayout2KHR">::get(*functions.khr_maintenance5);
        }
    #endif // defined(VK_KHR_maintenance5)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance5)

#if defined(VK_KHR_maintenance5)
template<>
struct get_from<extension::device_functions, "vkCmdBindIndexBuffer2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindIndexBuffer2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance5)
        if(functions.khr_maintenance5)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance5 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance5, "vkCmdBindIndexBuffer2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance5, "vkCmdBindIndexBuffer2KHR">::get(*functions.khr_maintenance5);
        }
    #endif // defined(VK_KHR_maintenance5)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance5)

#if defined(VK_AMD_anti_lag)
template<>
struct get_from<extension::device_functions, "vkAntiLagUpdateAMD">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAntiLagUpdateAMD get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_AMD_anti_lag)
        if(functions.amd_anti_lag)
        {
            static_assert(
                requires {
                    { functions.amd_anti_lag };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::amd_anti_lag, "vkAntiLagUpdateAMD">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::amd_anti_lag, "vkAntiLagUpdateAMD">::get(*functions.amd_anti_lag);
        }
    #endif // defined(VK_AMD_anti_lag)

        return nullptr;
    }
};
#endif // defined(VK_AMD_anti_lag)

#if defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkCreateShadersEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateShadersEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCreateShadersEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCreateShadersEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkDestroyShaderEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyShaderEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkDestroyShaderEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkDestroyShaderEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkGetShaderBinaryDataEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetShaderBinaryDataEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkGetShaderBinaryDataEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkGetShaderBinaryDataEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
template<>
struct get_from<extension::device_functions, "vkCmdBindShadersEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindShadersEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdBindShadersEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdBindShadersEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object) or defined(VK_EXT_depth_clamp_control)
template<>
struct get_from<extension::device_functions, "vkCmdSetDepthClampRangeEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDepthClampRangeEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_shader_object)
        if(functions.ext_shader_object)
        {
            static_assert(
                requires {
                    { functions.ext_shader_object };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClampRangeEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_shader_object, "vkCmdSetDepthClampRangeEXT">::get(*functions.ext_shader_object);
        }
    #endif // defined(VK_EXT_shader_object)

    #if defined(VK_EXT_depth_clamp_control)
        if(functions.ext_depth_clamp_control)
        {
            static_assert(
                requires {
                    { functions.ext_depth_clamp_control };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_depth_clamp_control, "vkCmdSetDepthClampRangeEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_depth_clamp_control, "vkCmdSetDepthClampRangeEXT">::get(*functions.ext_depth_clamp_control);
        }
    #endif // defined(VK_EXT_depth_clamp_control)

        return nullptr;
    }
};
#endif // defined(VK_EXT_shader_object)or defined(VK_EXT_depth_clamp_control)

#if defined(VK_KHR_pipeline_binary)
template<>
struct get_from<extension::device_functions, "vkCreatePipelineBinariesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreatePipelineBinariesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_binary)
        if(functions.khr_pipeline_binary)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_binary };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_pipeline_binary, "vkCreatePipelineBinariesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_binary, "vkCreatePipelineBinariesKHR">::get(*functions.khr_pipeline_binary);
        }
    #endif // defined(VK_KHR_pipeline_binary)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct get_from<extension::device_functions, "vkDestroyPipelineBinaryKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyPipelineBinaryKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_binary)
        if(functions.khr_pipeline_binary)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_binary };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_pipeline_binary, "vkDestroyPipelineBinaryKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_binary, "vkDestroyPipelineBinaryKHR">::get(*functions.khr_pipeline_binary);
        }
    #endif // defined(VK_KHR_pipeline_binary)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct get_from<extension::device_functions, "vkGetPipelineKeyKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelineKeyKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_binary)
        if(functions.khr_pipeline_binary)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_binary };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_pipeline_binary, "vkGetPipelineKeyKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_binary, "vkGetPipelineKeyKHR">::get(*functions.khr_pipeline_binary);
        }
    #endif // defined(VK_KHR_pipeline_binary)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct get_from<extension::device_functions, "vkGetPipelineBinaryDataKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPipelineBinaryDataKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_binary)
        if(functions.khr_pipeline_binary)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_binary };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_pipeline_binary, "vkGetPipelineBinaryDataKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_binary, "vkGetPipelineBinaryDataKHR">::get(*functions.khr_pipeline_binary);
        }
    #endif // defined(VK_KHR_pipeline_binary)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct get_from<extension::device_functions, "vkReleaseCapturedPipelineDataKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkReleaseCapturedPipelineDataKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_pipeline_binary)
        if(functions.khr_pipeline_binary)
        {
            static_assert(
                requires {
                    { functions.khr_pipeline_binary };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_pipeline_binary, "vkReleaseCapturedPipelineDataKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_pipeline_binary, "vkReleaseCapturedPipelineDataKHR">::get(*functions.khr_pipeline_binary);
        }
    #endif // defined(VK_KHR_pipeline_binary)

        return nullptr;
    }
};
#endif // defined(VK_KHR_pipeline_binary)

#if defined(VK_QCOM_tile_properties)
template<>
struct get_from<extension::device_functions, "vkGetFramebufferTilePropertiesQCOM">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetFramebufferTilePropertiesQCOM get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_QCOM_tile_properties)
        if(functions.qcom_tile_properties)
        {
            static_assert(
                requires {
                    { functions.qcom_tile_properties };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::qcom_tile_properties, "vkGetFramebufferTilePropertiesQCOM">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::qcom_tile_properties, "vkGetFramebufferTilePropertiesQCOM">::get(*functions.qcom_tile_properties);
        }
    #endif // defined(VK_QCOM_tile_properties)

        return nullptr;
    }
};
#endif // defined(VK_QCOM_tile_properties)

#if defined(VK_QCOM_tile_properties)
template<>
struct get_from<extension::device_functions, "vkGetDynamicRenderingTilePropertiesQCOM">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDynamicRenderingTilePropertiesQCOM get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_QCOM_tile_properties)
        if(functions.qcom_tile_properties)
        {
            static_assert(
                requires {
                    { functions.qcom_tile_properties };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::qcom_tile_properties, "vkGetDynamicRenderingTilePropertiesQCOM">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::qcom_tile_properties, "vkGetDynamicRenderingTilePropertiesQCOM">::get(
                *functions.qcom_tile_properties);
        }
    #endif // defined(VK_QCOM_tile_properties)

        return nullptr;
    }
};
#endif // defined(VK_QCOM_tile_properties)

#if defined(VK_NV_cooperative_vector)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cooperative_vector)
        if(functions.nv_cooperative_vector)
        {
            static_assert(
                requires {
                    { functions.nv_cooperative_vector };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cooperative_vector, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cooperative_vector, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV">::get(
                *functions.nv_cooperative_vector);
        }
    #endif // defined(VK_NV_cooperative_vector)

        return nullptr;
    }
};
#endif // defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
template<>
struct get_from<extension::device_functions, "vkConvertCooperativeVectorMatrixNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkConvertCooperativeVectorMatrixNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cooperative_vector)
        if(functions.nv_cooperative_vector)
        {
            static_assert(
                requires {
                    { functions.nv_cooperative_vector };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cooperative_vector, "vkConvertCooperativeVectorMatrixNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cooperative_vector, "vkConvertCooperativeVectorMatrixNV">::get(*functions.nv_cooperative_vector);
        }
    #endif // defined(VK_NV_cooperative_vector)

        return nullptr;
    }
};
#endif // defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
template<>
struct get_from<extension::device_functions, "vkCmdConvertCooperativeVectorMatrixNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdConvertCooperativeVectorMatrixNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cooperative_vector)
        if(functions.nv_cooperative_vector)
        {
            static_assert(
                requires {
                    { functions.nv_cooperative_vector };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cooperative_vector, "vkCmdConvertCooperativeVectorMatrixNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cooperative_vector, "vkCmdConvertCooperativeVectorMatrixNV">::get(
                *functions.nv_cooperative_vector);
        }
    #endif // defined(VK_NV_cooperative_vector)

        return nullptr;
    }
};
#endif // defined(VK_NV_cooperative_vector)

#if defined(VK_NV_low_latency2)
template<>
struct get_from<extension::device_functions, "vkSetLatencySleepModeNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetLatencySleepModeNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_low_latency2)
        if(functions.nv_low_latency2)
        {
            static_assert(
                requires {
                    { functions.nv_low_latency2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_low_latency2, "vkSetLatencySleepModeNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_low_latency2, "vkSetLatencySleepModeNV">::get(*functions.nv_low_latency2);
        }
    #endif // defined(VK_NV_low_latency2)

        return nullptr;
    }
};
#endif // defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct get_from<extension::device_functions, "vkLatencySleepNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkLatencySleepNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_low_latency2)
        if(functions.nv_low_latency2)
        {
            static_assert(
                requires {
                    { functions.nv_low_latency2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_low_latency2, "vkLatencySleepNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_low_latency2, "vkLatencySleepNV">::get(*functions.nv_low_latency2);
        }
    #endif // defined(VK_NV_low_latency2)

        return nullptr;
    }
};
#endif // defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct get_from<extension::device_functions, "vkSetLatencyMarkerNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetLatencyMarkerNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_low_latency2)
        if(functions.nv_low_latency2)
        {
            static_assert(
                requires {
                    { functions.nv_low_latency2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_low_latency2, "vkSetLatencyMarkerNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_low_latency2, "vkSetLatencyMarkerNV">::get(*functions.nv_low_latency2);
        }
    #endif // defined(VK_NV_low_latency2)

        return nullptr;
    }
};
#endif // defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct get_from<extension::device_functions, "vkGetLatencyTimingsNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetLatencyTimingsNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_low_latency2)
        if(functions.nv_low_latency2)
        {
            static_assert(
                requires {
                    { functions.nv_low_latency2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_low_latency2, "vkGetLatencyTimingsNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_low_latency2, "vkGetLatencyTimingsNV">::get(*functions.nv_low_latency2);
        }
    #endif // defined(VK_NV_low_latency2)

        return nullptr;
    }
};
#endif // defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct get_from<extension::device_functions, "vkQueueNotifyOutOfBandNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkQueueNotifyOutOfBandNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_low_latency2)
        if(functions.nv_low_latency2)
        {
            static_assert(
                requires {
                    { functions.nv_low_latency2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_low_latency2, "vkQueueNotifyOutOfBandNV">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::nv_low_latency2, "vkQueueNotifyOutOfBandNV">::get(*functions.nv_low_latency2);
        }
    #endif // defined(VK_NV_low_latency2)

        return nullptr;
    }
};
#endif // defined(VK_NV_low_latency2)

#if defined(VK_KHR_cooperative_matrix)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_cooperative_matrix)
        if(functions.khr_cooperative_matrix)
        {
            static_assert(
                requires {
                    { functions.khr_cooperative_matrix };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_cooperative_matrix, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_cooperative_matrix, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR">::get(
                *functions.khr_cooperative_matrix);
        }
    #endif // defined(VK_KHR_cooperative_matrix)

        return nullptr;
    }
};
#endif // defined(VK_KHR_cooperative_matrix)

#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
template<>
struct get_from<extension::device_functions, "vkCmdSetAttachmentFeedbackLoopEnableEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        if(functions.ext_attachment_feedback_loop_dynamic_state)
        {
            static_assert(
                requires {
                    { functions.ext_attachment_feedback_loop_dynamic_state };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::ext_attachment_feedback_loop_dynamic_state, "vkCmdSetAttachmentFeedbackLoopEnableEXT">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::ext_attachment_feedback_loop_dynamic_state, "vkCmdSetAttachmentFeedbackLoopEnableEXT">::get(
                *functions.ext_attachment_feedback_loop_dynamic_state);
        }
    #endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

        return nullptr;
    }
};
#endif // defined(VK_EXT_attachment_feedback_loop_dynamic_state)

#if defined(VK_QNX_external_memory_screen_buffer)
template<>
struct get_from<extension::device_functions, "vkGetScreenBufferPropertiesQNX">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetScreenBufferPropertiesQNX get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_QNX_external_memory_screen_buffer)
        if(functions.qnx_external_memory_screen_buffer)
        {
            static_assert(
                requires {
                    { functions.qnx_external_memory_screen_buffer };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::qnx_external_memory_screen_buffer, "vkGetScreenBufferPropertiesQNX">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::qnx_external_memory_screen_buffer, "vkGetScreenBufferPropertiesQNX">::get(
                *functions.qnx_external_memory_screen_buffer);
        }
    #endif // defined(VK_QNX_external_memory_screen_buffer)

        return nullptr;
    }
};
#endif // defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_KHR_line_rasterization)
template<>
struct get_from<extension::device_functions, "vkCmdSetLineStippleKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetLineStippleKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_line_rasterization)
        if(functions.khr_line_rasterization)
        {
            static_assert(
                requires {
                    { functions.khr_line_rasterization };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_line_rasterization, "vkCmdSetLineStippleKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_line_rasterization, "vkCmdSetLineStippleKHR">::get(*functions.khr_line_rasterization);
        }
    #endif // defined(VK_KHR_line_rasterization)

        return nullptr;
    }
};
#endif // defined(VK_KHR_line_rasterization)

#if defined(VK_KHR_calibrated_timestamps)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_calibrated_timestamps)
        if(functions.khr_calibrated_timestamps)
        {
            static_assert(
                requires {
                    { functions.khr_calibrated_timestamps };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_calibrated_timestamps, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_calibrated_timestamps, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR">::get(
                *functions.khr_calibrated_timestamps);
        }
    #endif // defined(VK_KHR_calibrated_timestamps)

        return nullptr;
    }
};
#endif // defined(VK_KHR_calibrated_timestamps)

#if defined(VK_KHR_calibrated_timestamps)
template<>
struct get_from<extension::device_functions, "vkGetCalibratedTimestampsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetCalibratedTimestampsKHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_calibrated_timestamps)
        if(functions.khr_calibrated_timestamps)
        {
            static_assert(
                requires {
                    { functions.khr_calibrated_timestamps };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_calibrated_timestamps, "vkGetCalibratedTimestampsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_calibrated_timestamps, "vkGetCalibratedTimestampsKHR">::get(
                *functions.khr_calibrated_timestamps);
        }
    #endif // defined(VK_KHR_calibrated_timestamps)

        return nullptr;
    }
};
#endif // defined(VK_KHR_calibrated_timestamps)

#if defined(VK_KHR_maintenance6)
template<>
struct get_from<extension::device_functions, "vkCmdBindDescriptorSets2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindDescriptorSets2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance6)
        if(functions.khr_maintenance6)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance6 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance6, "vkCmdBindDescriptorSets2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance6, "vkCmdBindDescriptorSets2KHR">::get(*functions.khr_maintenance6);
        }
    #endif // defined(VK_KHR_maintenance6)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct get_from<extension::device_functions, "vkCmdPushConstants2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPushConstants2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance6)
        if(functions.khr_maintenance6)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance6 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance6, "vkCmdPushConstants2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance6, "vkCmdPushConstants2KHR">::get(*functions.khr_maintenance6);
        }
    #endif // defined(VK_KHR_maintenance6)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct get_from<extension::device_functions, "vkCmdPushDescriptorSet2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPushDescriptorSet2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance6)
        if(functions.khr_maintenance6)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance6 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance6, "vkCmdPushDescriptorSet2KHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance6, "vkCmdPushDescriptorSet2KHR">::get(*functions.khr_maintenance6);
        }
    #endif // defined(VK_KHR_maintenance6)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct get_from<extension::device_functions, "vkCmdPushDescriptorSetWithTemplate2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPushDescriptorSetWithTemplate2KHR get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance6)
        if(functions.khr_maintenance6)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance6 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance6, "vkCmdPushDescriptorSetWithTemplate2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance6, "vkCmdPushDescriptorSetWithTemplate2KHR">::get(*functions.khr_maintenance6);
        }
    #endif // defined(VK_KHR_maintenance6)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct get_from<extension::device_functions, "vkCmdSetDescriptorBufferOffsets2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdSetDescriptorBufferOffsets2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance6)
        if(functions.khr_maintenance6)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance6 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance6, "vkCmdSetDescriptorBufferOffsets2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance6, "vkCmdSetDescriptorBufferOffsets2EXT">::get(*functions.khr_maintenance6);
        }
    #endif // defined(VK_KHR_maintenance6)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct get_from<extension::device_functions, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_KHR_maintenance6)
        if(functions.khr_maintenance6)
        {
            static_assert(
                requires {
                    { functions.khr_maintenance6 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_maintenance6, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_maintenance6, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT">::get(
                *functions.khr_maintenance6);
        }
    #endif // defined(VK_KHR_maintenance6)

        return nullptr;
    }
};
#endif // defined(VK_KHR_maintenance6)

#if defined(VK_NV_cluster_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkGetClusterAccelerationStructureBuildSizesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetClusterAccelerationStructureBuildSizesNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cluster_acceleration_structure)
        if(functions.nv_cluster_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.nv_cluster_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::nv_cluster_acceleration_structure, "vkGetClusterAccelerationStructureBuildSizesNV">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cluster_acceleration_structure, "vkGetClusterAccelerationStructureBuildSizesNV">::get(
                *functions.nv_cluster_acceleration_structure);
        }
    #endif // defined(VK_NV_cluster_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdBuildClusterAccelerationStructureIndirectNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBuildClusterAccelerationStructureIndirectNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cluster_acceleration_structure)
        if(functions.nv_cluster_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.nv_cluster_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::nv_cluster_acceleration_structure, "vkCmdBuildClusterAccelerationStructureIndirectNV">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cluster_acceleration_structure, "vkCmdBuildClusterAccelerationStructureIndirectNV">::get(
                *functions.nv_cluster_acceleration_structure);
        }
    #endif // defined(VK_NV_cluster_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkGetPartitionedAccelerationStructuresBuildSizesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_partitioned_acceleration_structure)
        if(functions.nv_partitioned_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.nv_partitioned_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::nv_partitioned_acceleration_structure, "vkGetPartitionedAccelerationStructuresBuildSizesNV">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::nv_partitioned_acceleration_structure, "vkGetPartitionedAccelerationStructuresBuildSizesNV">::get(
                *functions.nv_partitioned_acceleration_structure);
        }
    #endif // defined(VK_NV_partitioned_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
template<>
struct get_from<extension::device_functions, "vkCmdBuildPartitionedAccelerationStructuresNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBuildPartitionedAccelerationStructuresNV get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_partitioned_acceleration_structure)
        if(functions.nv_partitioned_acceleration_structure)
        {
            static_assert(
                requires {
                    { functions.nv_partitioned_acceleration_structure };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::nv_partitioned_acceleration_structure, "vkCmdBuildPartitionedAccelerationStructuresNV">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::nv_partitioned_acceleration_structure, "vkCmdBuildPartitionedAccelerationStructuresNV">::get(
                *functions.nv_partitioned_acceleration_structure);
        }
    #endif // defined(VK_NV_partitioned_acceleration_structure)

        return nullptr;
    }
};
#endif // defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkGetGeneratedCommandsMemoryRequirementsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetGeneratedCommandsMemoryRequirementsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkGetGeneratedCommandsMemoryRequirementsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkGetGeneratedCommandsMemoryRequirementsEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCreateIndirectCommandsLayoutEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateIndirectCommandsLayoutEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkCreateIndirectCommandsLayoutEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkCreateIndirectCommandsLayoutEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkDestroyIndirectCommandsLayoutEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyIndirectCommandsLayoutEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkDestroyIndirectCommandsLayoutEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkDestroyIndirectCommandsLayoutEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCreateIndirectExecutionSetEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateIndirectExecutionSetEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkCreateIndirectExecutionSetEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkCreateIndirectExecutionSetEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkDestroyIndirectExecutionSetEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyIndirectExecutionSetEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkDestroyIndirectExecutionSetEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkDestroyIndirectExecutionSetEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkUpdateIndirectExecutionSetPipelineEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkUpdateIndirectExecutionSetPipelineEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkUpdateIndirectExecutionSetPipelineEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkUpdateIndirectExecutionSetPipelineEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkUpdateIndirectExecutionSetShaderEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkUpdateIndirectExecutionSetShaderEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkUpdateIndirectExecutionSetShaderEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkUpdateIndirectExecutionSetShaderEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCmdPreprocessGeneratedCommandsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdPreprocessGeneratedCommandsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkCmdPreprocessGeneratedCommandsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkCmdPreprocessGeneratedCommandsEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct get_from<extension::device_functions, "vkCmdExecuteGeneratedCommandsEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdExecuteGeneratedCommandsEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_device_generated_commands)
        if(functions.ext_device_generated_commands)
        {
            static_assert(
                requires {
                    { functions.ext_device_generated_commands };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_device_generated_commands, "vkCmdExecuteGeneratedCommandsEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_device_generated_commands, "vkCmdExecuteGeneratedCommandsEXT">::get(
                *functions.ext_device_generated_commands);
        }
    #endif // defined(VK_EXT_device_generated_commands)

        return nullptr;
    }
};
#endif // defined(VK_EXT_device_generated_commands)

#if defined(VK_NV_cooperative_matrix2)
template<>
struct get_from<extension::device_functions, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV
    get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_NV_cooperative_matrix2)
        if(functions.nv_cooperative_matrix2)
        {
            static_assert(
                requires {
                    { functions.nv_cooperative_matrix2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::nv_cooperative_matrix2, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::nv_cooperative_matrix2, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV">::get(
                *functions.nv_cooperative_matrix2);
        }
    #endif // defined(VK_NV_cooperative_matrix2)

        return nullptr;
    }
};
#endif // defined(VK_NV_cooperative_matrix2)

#if defined(VK_EXT_external_memory_metal)
template<>
struct get_from<extension::device_functions, "vkGetMemoryMetalHandleEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryMetalHandleEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_external_memory_metal)
        if(functions.ext_external_memory_metal)
        {
            static_assert(
                requires {
                    { functions.ext_external_memory_metal };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_external_memory_metal, "vkGetMemoryMetalHandleEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_external_memory_metal, "vkGetMemoryMetalHandleEXT">::get(*functions.ext_external_memory_metal);
        }
    #endif // defined(VK_EXT_external_memory_metal)

        return nullptr;
    }
};
#endif // defined(VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
template<>
struct get_from<extension::device_functions, "vkGetMemoryMetalHandlePropertiesEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetMemoryMetalHandlePropertiesEXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_external_memory_metal)
        if(functions.ext_external_memory_metal)
        {
            static_assert(
                requires {
                    { functions.ext_external_memory_metal };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_external_memory_metal, "vkGetMemoryMetalHandlePropertiesEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_external_memory_metal, "vkGetMemoryMetalHandlePropertiesEXT">::get(
                *functions.ext_external_memory_metal);
        }
    #endif // defined(VK_EXT_external_memory_metal)

        return nullptr;
    }
};
#endif // defined(VK_EXT_external_memory_metal)

#if defined(VK_EXT_fragment_density_map_offset)
template<>
struct get_from<extension::device_functions, "vkCmdEndRendering2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndRendering2EXT get(const extension::device_functions& functions) noexcept
    {

    #if defined(VK_EXT_fragment_density_map_offset)
        if(functions.ext_fragment_density_map_offset)
        {
            static_assert(
                requires {
                    { functions.ext_fragment_density_map_offset };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_fragment_density_map_offset, "vkCmdEndRendering2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_fragment_density_map_offset, "vkCmdEndRendering2EXT">::get(
                *functions.ext_fragment_density_map_offset);
        }
    #endif // defined(VK_EXT_fragment_density_map_offset)

        return nullptr;
    }
};
#endif // defined(VK_EXT_fragment_density_map_offset)

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_CORE_FUNCTIONS_DEVICE_EXTENSIONS_HPP
