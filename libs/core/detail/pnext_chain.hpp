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

#ifndef FUBUKI_CORE_DETAIL_PNEXT_CHAIN_HPP
#define FUBUKI_CORE_DETAIL_PNEXT_CHAIN_HPP

// IWYU pragma: begin_exports

#include <core/detail/chain_compatibility/acceleration_structure_geometry_linear_swept_spheres_data_nv.hpp>
#include <core/detail/chain_compatibility/acceleration_structure_geometry_motion_triangles_data_nv.hpp>
#include <core/detail/chain_compatibility/acceleration_structure_geometry_spheres_data_nv.hpp>
#include <core/detail/chain_compatibility/acceleration_structure_motion_info_nv.hpp>
#include <core/detail/chain_compatibility/acceleration_structure_triangles_displacement_micromap_nv.hpp>
#include <core/detail/chain_compatibility/acceleration_structure_triangles_opacity_micromap_ext.hpp>
#include <core/detail/chain_compatibility/amigo_profiling_submit_info_sec.hpp>
#include <core/detail/chain_compatibility/android_hardware_buffer_format_properties2_android.hpp>
#include <core/detail/chain_compatibility/android_hardware_buffer_format_properties_android.hpp>
#include <core/detail/chain_compatibility/android_hardware_buffer_format_resolve_properties_android.hpp>
#include <core/detail/chain_compatibility/android_hardware_buffer_usage_android.hpp>
#include <core/detail/chain_compatibility/application_parameters_ext.hpp>
#include <core/detail/chain_compatibility/attachment_description_stencil_layout.hpp>
#include <core/detail/chain_compatibility/attachment_reference_stencil_layout.hpp>
#include <core/detail/chain_compatibility/attachment_sample_count_info_amd.hpp>
#include <core/detail/chain_compatibility/bind_buffer_memory_device_group_info.hpp>
#include <core/detail/chain_compatibility/bind_image_memory_device_group_info.hpp>
#include <core/detail/chain_compatibility/bind_image_memory_swapchain_info_khr.hpp>
#include <core/detail/chain_compatibility/bind_image_plane_memory_info.hpp>
#include <core/detail/chain_compatibility/bind_memory_status.hpp>
#include <core/detail/chain_compatibility/blit_image_cubic_weights_info_qcom.hpp>
#include <core/detail/chain_compatibility/buffer_collection_buffer_create_info_fuchsia.hpp>
#include <core/detail/chain_compatibility/buffer_collection_image_create_info_fuchsia.hpp>
#include <core/detail/chain_compatibility/buffer_device_address_create_info_ext.hpp>
#include <core/detail/chain_compatibility/buffer_opaque_capture_address_create_info.hpp>
#include <core/detail/chain_compatibility/buffer_usage_flags2_create_info.hpp>
#include <core/detail/chain_compatibility/command_buffer_inheritance_conditional_rendering_info_ext.hpp>
#include <core/detail/chain_compatibility/command_buffer_inheritance_render_pass_transform_info_qcom.hpp>
#include <core/detail/chain_compatibility/command_buffer_inheritance_rendering_info.hpp>
#include <core/detail/chain_compatibility/command_buffer_inheritance_viewport_scissor_info_nv.hpp>
#include <core/detail/chain_compatibility/command_pool_memory_reservation_create_info.hpp>
#include <core/detail/chain_compatibility/compute_pipeline_indirect_buffer_info_nv.hpp>
#include <core/detail/chain_compatibility/copy_command_transform_info_qcom.hpp>
#include <core/detail/chain_compatibility/cu_module_texturing_mode_create_info_nvx.hpp>
#include <core/detail/chain_compatibility/d3d12_fence_submit_info_khr.hpp>
#include <core/detail/chain_compatibility/debug_report_callback_create_info_ext.hpp>
#include <core/detail/chain_compatibility/debug_utils_messenger_create_info_ext.hpp>
#include <core/detail/chain_compatibility/debug_utils_object_name_info_ext.hpp>
#include <core/detail/chain_compatibility/dedicated_allocation_buffer_create_info_nv.hpp>
#include <core/detail/chain_compatibility/dedicated_allocation_image_create_info_nv.hpp>
#include <core/detail/chain_compatibility/dedicated_allocation_memory_allocate_info_nv.hpp>
#include <core/detail/chain_compatibility/depth_bias_representation_info_ext.hpp>
#include <core/detail/chain_compatibility/descriptor_buffer_binding_push_descriptor_buffer_handle_ext.hpp>
#include <core/detail/chain_compatibility/descriptor_pool_inline_uniform_block_create_info.hpp>
#include <core/detail/chain_compatibility/descriptor_set_layout_binding_flags_create_info.hpp>
#include <core/detail/chain_compatibility/descriptor_set_variable_descriptor_count_allocate_info.hpp>
#include <core/detail/chain_compatibility/descriptor_set_variable_descriptor_count_layout_support.hpp>
#include <core/detail/chain_compatibility/device_address_binding_callback_data_ext.hpp>
#include <core/detail/chain_compatibility/device_device_memory_report_create_info_ext.hpp>
#include <core/detail/chain_compatibility/device_diagnostics_config_create_info_nv.hpp>
#include <core/detail/chain_compatibility/device_group_bind_sparse_info.hpp>
#include <core/detail/chain_compatibility/device_group_command_buffer_begin_info.hpp>
#include <core/detail/chain_compatibility/device_group_device_create_info.hpp>
#include <core/detail/chain_compatibility/device_group_present_info_khr.hpp>
#include <core/detail/chain_compatibility/device_group_render_pass_begin_info.hpp>
#include <core/detail/chain_compatibility/device_group_submit_info.hpp>
#include <core/detail/chain_compatibility/device_group_swapchain_create_info_khr.hpp>
#include <core/detail/chain_compatibility/device_memory_overallocation_create_info_amd.hpp>
#include <core/detail/chain_compatibility/device_object_reservation_create_info.hpp>
#include <core/detail/chain_compatibility/device_pipeline_binary_internal_cache_control_khr.hpp>
#include <core/detail/chain_compatibility/device_private_data_create_info.hpp>
#include <core/detail/chain_compatibility/device_queue_global_priority_create_info.hpp>
#include <core/detail/chain_compatibility/device_queue_shader_core_control_create_info_arm.hpp>
#include <core/detail/chain_compatibility/device_semaphore_sci_sync_pool_reservation_create_info_nv.hpp>
#include <core/detail/chain_compatibility/direct_driver_loading_list_lunarg.hpp>
#include <core/detail/chain_compatibility/display_mode_stereo_properties_nv.hpp>
#include <core/detail/chain_compatibility/display_native_hdr_surface_capabilities_amd.hpp>
#include <core/detail/chain_compatibility/display_present_info_khr.hpp>
#include <core/detail/chain_compatibility/display_surface_stereo_create_info_nv.hpp>
#include <core/detail/chain_compatibility/drm_format_modifier_properties_list2_ext.hpp>
#include <core/detail/chain_compatibility/drm_format_modifier_properties_list_ext.hpp>
#include <core/detail/chain_compatibility/export_fence_create_info.hpp>
#include <core/detail/chain_compatibility/export_fence_sci_sync_info_nv.hpp>
#include <core/detail/chain_compatibility/export_fence_win32_handle_info_khr.hpp>
#include <core/detail/chain_compatibility/export_memory_allocate_info.hpp>
#include <core/detail/chain_compatibility/export_memory_allocate_info_nv.hpp>
#include <core/detail/chain_compatibility/export_memory_sci_buf_info_nv.hpp>
#include <core/detail/chain_compatibility/export_memory_win32_handle_info_khr.hpp>
#include <core/detail/chain_compatibility/export_memory_win32_handle_info_nv.hpp>
#include <core/detail/chain_compatibility/export_metal_buffer_info_ext.hpp>
#include <core/detail/chain_compatibility/export_metal_command_queue_info_ext.hpp>
#include <core/detail/chain_compatibility/export_metal_device_info_ext.hpp>
#include <core/detail/chain_compatibility/export_metal_io_surface_info_ext.hpp>
#include <core/detail/chain_compatibility/export_metal_object_create_info_ext.hpp>
#include <core/detail/chain_compatibility/export_metal_shared_event_info_ext.hpp>
#include <core/detail/chain_compatibility/export_metal_texture_info_ext.hpp>
#include <core/detail/chain_compatibility/export_semaphore_create_info.hpp>
#include <core/detail/chain_compatibility/export_semaphore_sci_sync_info_nv.hpp>
#include <core/detail/chain_compatibility/export_semaphore_win32_handle_info_khr.hpp>
#include <core/detail/chain_compatibility/external_format_android.hpp>
#include <core/detail/chain_compatibility/external_format_qnx.hpp>
#include <core/detail/chain_compatibility/external_image_format_properties.hpp>
#include <core/detail/chain_compatibility/external_memory_acquire_unmodified_ext.hpp>
#include <core/detail/chain_compatibility/external_memory_buffer_create_info.hpp>
#include <core/detail/chain_compatibility/external_memory_image_create_info.hpp>
#include <core/detail/chain_compatibility/external_memory_image_create_info_nv.hpp>
#include <core/detail/chain_compatibility/fault_callback_info.hpp>
#include <core/detail/chain_compatibility/filter_cubic_image_view_image_format_properties_ext.hpp>
#include <core/detail/chain_compatibility/format_properties3.hpp>
#include <core/detail/chain_compatibility/fragment_shading_rate_attachment_info_khr.hpp>
#include <core/detail/chain_compatibility/frame_boundary_ext.hpp>
#include <core/detail/chain_compatibility/framebuffer_attachments_create_info.hpp>
#include <core/detail/chain_compatibility/generated_commands_pipeline_info_ext.hpp>
#include <core/detail/chain_compatibility/generated_commands_shader_info_ext.hpp>
#include <core/detail/chain_compatibility/graphics_pipeline_library_create_info_ext.hpp>
#include <core/detail/chain_compatibility/graphics_pipeline_shader_groups_create_info_nv.hpp>
#include <core/detail/chain_compatibility/hdr_vivid_dynamic_metadata_huawei.hpp>
#include <core/detail/chain_compatibility/host_image_copy_device_performance_query.hpp>
#include <core/detail/chain_compatibility/image_alignment_control_create_info_mesa.hpp>
#include <core/detail/chain_compatibility/image_compression_control_ext.hpp>
#include <core/detail/chain_compatibility/image_compression_properties_ext.hpp>
#include <core/detail/chain_compatibility/image_drm_format_modifier_explicit_create_info_ext.hpp>
#include <core/detail/chain_compatibility/image_drm_format_modifier_list_create_info_ext.hpp>
#include <core/detail/chain_compatibility/image_format_list_create_info.hpp>
#include <core/detail/chain_compatibility/image_plane_memory_requirements_info.hpp>
#include <core/detail/chain_compatibility/image_stencil_usage_create_info.hpp>
#include <core/detail/chain_compatibility/image_swapchain_create_info_khr.hpp>
#include <core/detail/chain_compatibility/image_view_astc_decode_mode_ext.hpp>
#include <core/detail/chain_compatibility/image_view_min_lod_create_info_ext.hpp>
#include <core/detail/chain_compatibility/image_view_sample_weight_create_info_qcom.hpp>
#include <core/detail/chain_compatibility/image_view_sliced_create_info_ext.hpp>
#include <core/detail/chain_compatibility/image_view_usage_create_info.hpp>
#include <core/detail/chain_compatibility/import_android_hardware_buffer_info_android.hpp>
#include <core/detail/chain_compatibility/import_memory_buffer_collection_fuchsia.hpp>
#include <core/detail/chain_compatibility/import_memory_fd_info_khr.hpp>
#include <core/detail/chain_compatibility/import_memory_host_pointer_info_ext.hpp>
#include <core/detail/chain_compatibility/import_memory_metal_handle_info_ext.hpp>
#include <core/detail/chain_compatibility/import_memory_sci_buf_info_nv.hpp>
#include <core/detail/chain_compatibility/import_memory_win32_handle_info_khr.hpp>
#include <core/detail/chain_compatibility/import_memory_win32_handle_info_nv.hpp>
#include <core/detail/chain_compatibility/import_memory_zircon_handle_info_fuchsia.hpp>
#include <core/detail/chain_compatibility/import_metal_buffer_info_ext.hpp>
#include <core/detail/chain_compatibility/import_metal_io_surface_info_ext.hpp>
#include <core/detail/chain_compatibility/import_metal_shared_event_info_ext.hpp>
#include <core/detail/chain_compatibility/import_metal_texture_info_ext.hpp>
#include <core/detail/chain_compatibility/import_screen_buffer_info_qnx.hpp>
#include <core/detail/chain_compatibility/latency_submission_present_id_nv.hpp>
#include <core/detail/chain_compatibility/latency_surface_capabilities_nv.hpp>
#include <core/detail/chain_compatibility/layer_settings_create_info_ext.hpp>
#include <core/detail/chain_compatibility/memory_allocate_flags_info.hpp>
#include <core/detail/chain_compatibility/memory_barrier2.hpp>
#include <core/detail/chain_compatibility/memory_barrier_access_flags3_khr.hpp>
#include <core/detail/chain_compatibility/memory_dedicated_allocate_info.hpp>
#include <core/detail/chain_compatibility/memory_dedicated_requirements.hpp>
#include <core/detail/chain_compatibility/memory_map_placed_info_ext.hpp>
#include <core/detail/chain_compatibility/memory_opaque_capture_address_allocate_info.hpp>
#include <core/detail/chain_compatibility/memory_priority_allocate_info_ext.hpp>
#include <core/detail/chain_compatibility/multisampled_render_to_single_sampled_info_ext.hpp>
#include <core/detail/chain_compatibility/multiview_per_view_attributes_info_nvx.hpp>
#include <core/detail/chain_compatibility/multiview_per_view_render_areas_render_pass_begin_info_qcom.hpp>
#include <core/detail/chain_compatibility/mutable_descriptor_type_create_info_ext.hpp>
#include <core/detail/chain_compatibility/opaque_capture_descriptor_data_create_info_ext.hpp>
#include <core/detail/chain_compatibility/optical_flow_image_format_info_nv.hpp>
#include <core/detail/chain_compatibility/optical_flow_session_create_private_data_info_nv.hpp>
#include <core/detail/chain_compatibility/partitioned_acceleration_structure_flags_nv.hpp>
#include <core/detail/chain_compatibility/performance_query_submit_info_khr.hpp>
#include <core/detail/chain_compatibility/physical_device16_bit_storage_features.hpp>
#include <core/detail/chain_compatibility/physical_device4444_formats_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device8_bit_storage_features.hpp>
#include <core/detail/chain_compatibility/physical_device_acceleration_structure_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_acceleration_structure_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_address_binding_report_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_amigo_profiling_features_sec.hpp>
#include <core/detail/chain_compatibility/physical_device_anti_lag_features_amd.hpp>
#include <core/detail/chain_compatibility/physical_device_astc_decode_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_attachment_feedback_loop_dynamic_state_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_attachment_feedback_loop_layout_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_blend_operation_advanced_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_blend_operation_advanced_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_border_color_swizzle_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_buffer_device_address_features.hpp>
#include <core/detail/chain_compatibility/physical_device_buffer_device_address_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_cluster_acceleration_structure_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cluster_acceleration_structure_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cluster_culling_shader_features_huawei.hpp>
#include <core/detail/chain_compatibility/physical_device_cluster_culling_shader_properties_huawei.hpp>
#include <core/detail/chain_compatibility/physical_device_cluster_culling_shader_vrs_features_huawei.hpp>
#include <core/detail/chain_compatibility/physical_device_coherent_memory_features_amd.hpp>
#include <core/detail/chain_compatibility/physical_device_color_write_enable_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_command_buffer_inheritance_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_compute_shader_derivatives_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_compute_shader_derivatives_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_conditional_rendering_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_conservative_rasterization_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_matrix2_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_matrix2_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_matrix_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_matrix_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_matrix_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_matrix_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_vector_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cooperative_vector_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_copy_memory_indirect_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_copy_memory_indirect_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_corner_sampled_image_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_coverage_reduction_mode_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cubic_clamp_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_cubic_weights_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_cuda_kernel_launch_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_cuda_kernel_launch_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_custom_border_color_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_custom_border_color_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_dedicated_allocation_image_aliasing_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_depth_bias_control_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_depth_clamp_control_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_depth_clamp_zero_one_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_depth_clip_control_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_depth_clip_enable_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_depth_stencil_resolve_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_descriptor_buffer_density_map_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_descriptor_buffer_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_descriptor_buffer_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_descriptor_indexing_features.hpp>
#include <core/detail/chain_compatibility/physical_device_descriptor_indexing_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_descriptor_pool_overallocation_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_descriptor_set_host_mapping_features_valve.hpp>
#include <core/detail/chain_compatibility/physical_device_device_generated_commands_compute_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_device_generated_commands_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_device_generated_commands_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_device_generated_commands_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_device_generated_commands_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_device_memory_report_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_diagnostics_config_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_discard_rectangle_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_displacement_micromap_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_displacement_micromap_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_driver_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_drm_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_dynamic_rendering_features.hpp>
#include <core/detail/chain_compatibility/physical_device_dynamic_rendering_local_read_features.hpp>
#include <core/detail/chain_compatibility/physical_device_dynamic_rendering_unused_attachments_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_exclusive_scissor_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_extended_dynamic_state2_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_extended_dynamic_state3_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_extended_dynamic_state3_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_extended_dynamic_state_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_extended_sparse_address_space_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_extended_sparse_address_space_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_external_format_resolve_features_android.hpp>
#include <core/detail/chain_compatibility/physical_device_external_format_resolve_properties_android.hpp>
#include <core/detail/chain_compatibility/physical_device_external_image_format_info.hpp>
#include <core/detail/chain_compatibility/physical_device_external_memory_host_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_external_memory_rdma_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_external_memory_sci_buf_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_external_memory_screen_buffer_features_qnx.hpp>
#include <core/detail/chain_compatibility/physical_device_external_sci_sync2_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_external_sci_sync_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_fault_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_features2.hpp>
#include <core/detail/chain_compatibility/physical_device_float_controls_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_density_map2_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_density_map2_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_density_map_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_density_map_offset_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_density_map_offset_properties_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_density_map_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_shader_barycentric_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_shader_barycentric_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_shader_interlock_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_shading_rate_enums_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_shading_rate_enums_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_shading_rate_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_fragment_shading_rate_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_frame_boundary_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_global_priority_query_features.hpp>
#include <core/detail/chain_compatibility/physical_device_graphics_pipeline_library_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_graphics_pipeline_library_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_hdr_vivid_features_huawei.hpp>
#include <core/detail/chain_compatibility/physical_device_host_image_copy_features.hpp>
#include <core/detail/chain_compatibility/physical_device_host_image_copy_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_host_query_reset_features.hpp>
#include <core/detail/chain_compatibility/physical_device_id_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_image2d_view_of3d_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_image_alignment_control_features_mesa.hpp>
#include <core/detail/chain_compatibility/physical_device_image_alignment_control_properties_mesa.hpp>
#include <core/detail/chain_compatibility/physical_device_image_compression_control_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_image_compression_control_swapchain_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_image_drm_format_modifier_info_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_image_processing2_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_image_processing2_properties_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_image_processing_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_image_processing_properties_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_image_robustness_features.hpp>
#include <core/detail/chain_compatibility/physical_device_image_sliced_view_of3d_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_image_view_image_format_info_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_image_view_min_lod_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_imageless_framebuffer_features.hpp>
#include <core/detail/chain_compatibility/physical_device_index_type_uint8_features.hpp>
#include <core/detail/chain_compatibility/physical_device_inherited_viewport_scissor_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_inline_uniform_block_features.hpp>
#include <core/detail/chain_compatibility/physical_device_inline_uniform_block_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_invocation_mask_features_huawei.hpp>
#include <core/detail/chain_compatibility/physical_device_layered_api_properties_list_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_layered_api_vulkan_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_layered_driver_properties_msft.hpp>
#include <core/detail/chain_compatibility/physical_device_legacy_dithering_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_legacy_vertex_attributes_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_legacy_vertex_attributes_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_line_rasterization_features.hpp>
#include <core/detail/chain_compatibility/physical_device_line_rasterization_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_linear_color_attachment_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance3_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance4_features.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance4_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance5_features.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance5_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance6_features.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance6_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance7_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance7_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_maintenance8_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_map_memory_placed_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_map_memory_placed_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_memory_budget_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_memory_decompression_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_memory_decompression_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_memory_priority_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_mesh_shader_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_mesh_shader_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_mesh_shader_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_mesh_shader_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_multi_draw_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_multi_draw_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_multisampled_render_to_single_sampled_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_multiview_features.hpp>
#include <core/detail/chain_compatibility/physical_device_multiview_per_view_attributes_properties_nvx.hpp>
#include <core/detail/chain_compatibility/physical_device_multiview_per_view_render_areas_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_multiview_per_view_viewports_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_multiview_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_mutable_descriptor_type_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_nested_command_buffer_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_nested_command_buffer_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_non_seamless_cube_map_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_opacity_micromap_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_opacity_micromap_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_optical_flow_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_optical_flow_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_pageable_device_local_memory_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_partitioned_acceleration_structure_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_partitioned_acceleration_structure_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_pci_bus_info_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_per_stage_descriptor_set_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_performance_query_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_performance_query_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_binary_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_binary_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_creation_cache_control_features.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_executable_properties_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_library_group_handles_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_opacity_micromap_features_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_properties_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_protected_access_features.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_robustness_features.hpp>
#include <core/detail/chain_compatibility/physical_device_pipeline_robustness_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_point_clipping_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_portability_subset_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_portability_subset_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_present_barrier_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_present_id_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_present_metering_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_present_mode_fifo_latest_ready_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_present_wait_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_primitive_topology_list_restart_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_primitives_generated_query_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_private_data_features.hpp>
#include <core/detail/chain_compatibility/physical_device_protected_memory_features.hpp>
#include <core/detail/chain_compatibility/physical_device_protected_memory_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_provoking_vertex_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_provoking_vertex_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_push_descriptor_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_rasterization_order_attachment_access_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_raw_access_chains_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_query_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_invocation_reorder_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_invocation_reorder_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_linear_swept_spheres_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_maintenance1_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_motion_blur_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_pipeline_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_pipeline_properties_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_position_fetch_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_ray_tracing_validation_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_relaxed_line_rasterization_features_img.hpp>
#include <core/detail/chain_compatibility/physical_device_render_pass_striped_features_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_render_pass_striped_properties_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_representative_fragment_test_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_rgba10_x6_formats_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_robustness2_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_robustness2_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_sample_locations_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_sampler_filter_minmax_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_sampler_ycbcr_conversion_features.hpp>
#include <core/detail/chain_compatibility/physical_device_scalar_block_layout_features.hpp>
#include <core/detail/chain_compatibility/physical_device_scheduling_controls_features_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_scheduling_controls_properties_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_separate_depth_stencil_layouts_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_atomic_float16_vector_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_atomic_float2_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_atomic_float_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_atomic_int64_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_clock_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_core_builtins_features_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_core_builtins_properties_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_core_properties2_amd.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_core_properties_amd.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_core_properties_arm.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_demote_to_helper_invocation_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_draw_parameters_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_early_and_late_fragment_tests_features_amd.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_enqueue_features_amdx.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_enqueue_properties_amdx.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_expect_assume_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_float16_int8_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_float_controls2_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_image_atomic_int64_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_image_footprint_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_integer_dot_product_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_integer_dot_product_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_integer_functions2_features_intel.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_maximal_reconvergence_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_module_identifier_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_module_identifier_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_object_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_object_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_quad_control_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_relaxed_extended_instruction_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_replicated_composites_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_sm_builtins_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_sm_builtins_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_subgroup_extended_types_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_subgroup_rotate_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_subgroup_uniform_control_flow_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_terminate_invocation_features.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_tile_image_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shader_tile_image_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_shading_rate_image_features_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_shading_rate_image_properties_nv.hpp>
#include <core/detail/chain_compatibility/physical_device_subgroup_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_subgroup_size_control_features.hpp>
#include <core/detail/chain_compatibility/physical_device_subgroup_size_control_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_subpass_merge_feedback_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_subpass_shading_features_huawei.hpp>
#include <core/detail/chain_compatibility/physical_device_subpass_shading_properties_huawei.hpp>
#include <core/detail/chain_compatibility/physical_device_swapchain_maintenance1_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_synchronization2_features.hpp>
#include <core/detail/chain_compatibility/physical_device_texel_buffer_alignment_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_texel_buffer_alignment_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_texture_compression_astchdr_features.hpp>
#include <core/detail/chain_compatibility/physical_device_tile_properties_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_timeline_semaphore_features.hpp>
#include <core/detail/chain_compatibility/physical_device_timeline_semaphore_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_transform_feedback_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_transform_feedback_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_uniform_buffer_standard_layout_features.hpp>
#include <core/detail/chain_compatibility/physical_device_variable_pointers_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vertex_attribute_divisor_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vertex_attribute_divisor_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_vertex_attribute_divisor_properties_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_vertex_attribute_robustness_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_vertex_input_dynamic_state_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_video_encode_av1_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_video_encode_quantization_map_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_video_maintenance1_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_video_maintenance2_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan11_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan11_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan12_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan12_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan13_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan13_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan14_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan14_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan_memory_model_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan_sc10_features.hpp>
#include <core/detail/chain_compatibility/physical_device_vulkan_sc10_properties.hpp>
#include <core/detail/chain_compatibility/physical_device_workgroup_memory_explicit_layout_features_khr.hpp>
#include <core/detail/chain_compatibility/physical_device_ycbcr2_plane444_formats_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_ycbcr_degamma_features_qcom.hpp>
#include <core/detail/chain_compatibility/physical_device_ycbcr_image_arrays_features_ext.hpp>
#include <core/detail/chain_compatibility/physical_device_zero_initialize_workgroup_memory_features.hpp>
#include <core/detail/chain_compatibility/pipeline_binary_info_khr.hpp>
#include <core/detail/chain_compatibility/pipeline_color_blend_advanced_state_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_color_write_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_compiler_control_create_info_amd.hpp>
#include <core/detail/chain_compatibility/pipeline_coverage_modulation_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_coverage_reduction_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_coverage_to_color_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_create_flags2_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_creation_feedback_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_discard_rectangle_state_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_fragment_shading_rate_enum_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_fragment_shading_rate_state_create_info_khr.hpp>
#include <core/detail/chain_compatibility/pipeline_layout_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_library_create_info_khr.hpp>
#include <core/detail/chain_compatibility/pipeline_offline_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_rasterization_conservative_state_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_rasterization_depth_clip_state_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_rasterization_line_state_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_rasterization_provoking_vertex_state_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_rasterization_state_rasterization_order_amd.hpp>
#include <core/detail/chain_compatibility/pipeline_rasterization_state_stream_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_rendering_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_representative_fragment_test_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_robustness_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_sample_locations_state_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_shader_stage_module_identifier_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_shader_stage_node_create_info_amdx.hpp>
#include <core/detail/chain_compatibility/pipeline_shader_stage_required_subgroup_size_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_tessellation_domain_origin_state_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_vertex_input_divisor_state_create_info.hpp>
#include <core/detail/chain_compatibility/pipeline_viewport_coarse_sample_order_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_viewport_depth_clamp_control_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_viewport_depth_clip_control_create_info_ext.hpp>
#include <core/detail/chain_compatibility/pipeline_viewport_exclusive_scissor_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_viewport_shading_rate_image_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_viewport_swizzle_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/pipeline_viewport_w_scaling_state_create_info_nv.hpp>
#include <core/detail/chain_compatibility/present_frame_token_ggp.hpp>
#include <core/detail/chain_compatibility/present_id_khr.hpp>
#include <core/detail/chain_compatibility/present_regions_khr.hpp>
#include <core/detail/chain_compatibility/present_times_info_google.hpp>
#include <core/detail/chain_compatibility/protected_submit_info.hpp>
#include <core/detail/chain_compatibility/query_low_latency_support_nv.hpp>
#include <core/detail/chain_compatibility/query_pool_performance_create_info_khr.hpp>
#include <core/detail/chain_compatibility/query_pool_performance_query_create_info_intel.hpp>
#include <core/detail/chain_compatibility/query_pool_video_encode_feedback_create_info_khr.hpp>
#include <core/detail/chain_compatibility/queue_family_checkpoint_properties2_nv.hpp>
#include <core/detail/chain_compatibility/queue_family_checkpoint_properties_nv.hpp>
#include <core/detail/chain_compatibility/queue_family_global_priority_properties.hpp>
#include <core/detail/chain_compatibility/queue_family_query_result_status_properties_khr.hpp>
#include <core/detail/chain_compatibility/queue_family_video_properties_khr.hpp>
#include <core/detail/chain_compatibility/ray_tracing_pipeline_cluster_acceleration_structure_create_info_nv.hpp>
#include <core/detail/chain_compatibility/render_pass_attachment_begin_info.hpp>
#include <core/detail/chain_compatibility/render_pass_creation_control_ext.hpp>
#include <core/detail/chain_compatibility/render_pass_creation_feedback_create_info_ext.hpp>
#include <core/detail/chain_compatibility/render_pass_fragment_density_map_create_info_ext.hpp>
#include <core/detail/chain_compatibility/render_pass_input_attachment_aspect_create_info.hpp>
#include <core/detail/chain_compatibility/render_pass_multiview_create_info.hpp>
#include <core/detail/chain_compatibility/render_pass_sample_locations_begin_info_ext.hpp>
#include <core/detail/chain_compatibility/render_pass_stripe_begin_info_arm.hpp>
#include <core/detail/chain_compatibility/render_pass_stripe_submit_info_arm.hpp>
#include <core/detail/chain_compatibility/render_pass_subpass_feedback_create_info_ext.hpp>
#include <core/detail/chain_compatibility/render_pass_transform_begin_info_qcom.hpp>
#include <core/detail/chain_compatibility/rendering_attachment_location_info.hpp>
#include <core/detail/chain_compatibility/rendering_fragment_density_map_attachment_info_ext.hpp>
#include <core/detail/chain_compatibility/rendering_fragment_shading_rate_attachment_info_khr.hpp>
#include <core/detail/chain_compatibility/rendering_input_attachment_index_info.hpp>
#include <core/detail/chain_compatibility/sample_locations_info_ext.hpp>
#include <core/detail/chain_compatibility/sampler_block_match_window_create_info_qcom.hpp>
#include <core/detail/chain_compatibility/sampler_border_color_component_mapping_create_info_ext.hpp>
#include <core/detail/chain_compatibility/sampler_cubic_weights_create_info_qcom.hpp>
#include <core/detail/chain_compatibility/sampler_custom_border_color_create_info_ext.hpp>
#include <core/detail/chain_compatibility/sampler_reduction_mode_create_info.hpp>
#include <core/detail/chain_compatibility/sampler_ycbcr_conversion_image_format_properties.hpp>
#include <core/detail/chain_compatibility/sampler_ycbcr_conversion_info.hpp>
#include <core/detail/chain_compatibility/sampler_ycbcr_conversion_ycbcr_degamma_create_info_qcom.hpp>
#include <core/detail/chain_compatibility/screen_buffer_format_properties_qnx.hpp>
#include <core/detail/chain_compatibility/semaphore_sci_sync_create_info_nv.hpp>
#include <core/detail/chain_compatibility/semaphore_type_create_info.hpp>
#include <core/detail/chain_compatibility/set_present_config_nv.hpp>
#include <core/detail/chain_compatibility/shader_module_create_info.hpp>
#include <core/detail/chain_compatibility/shader_module_validation_cache_create_info_ext.hpp>
#include <core/detail/chain_compatibility/shared_present_surface_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/subpass_description_depth_stencil_resolve.hpp>
#include <core/detail/chain_compatibility/subpass_fragment_density_map_offset_end_info_qcom.hpp>
#include <core/detail/chain_compatibility/subpass_resolve_performance_query_ext.hpp>
#include <core/detail/chain_compatibility/subpass_shading_pipeline_create_info_huawei.hpp>
#include <core/detail/chain_compatibility/subresource_host_memcpy_size.hpp>
#include <core/detail/chain_compatibility/surface_capabilities_full_screen_exclusive_ext.hpp>
#include <core/detail/chain_compatibility/surface_capabilities_present_barrier_nv.hpp>
#include <core/detail/chain_compatibility/surface_full_screen_exclusive_info_ext.hpp>
#include <core/detail/chain_compatibility/surface_full_screen_exclusive_win32_info_ext.hpp>
#include <core/detail/chain_compatibility/surface_present_mode_compatibility_ext.hpp>
#include <core/detail/chain_compatibility/surface_present_mode_ext.hpp>
#include <core/detail/chain_compatibility/surface_present_scaling_capabilities_ext.hpp>
#include <core/detail/chain_compatibility/surface_protected_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/swapchain_counter_create_info_ext.hpp>
#include <core/detail/chain_compatibility/swapchain_display_native_hdr_create_info_amd.hpp>
#include <core/detail/chain_compatibility/swapchain_latency_create_info_nv.hpp>
#include <core/detail/chain_compatibility/swapchain_present_barrier_create_info_nv.hpp>
#include <core/detail/chain_compatibility/swapchain_present_fence_info_ext.hpp>
#include <core/detail/chain_compatibility/swapchain_present_mode_info_ext.hpp>
#include <core/detail/chain_compatibility/swapchain_present_modes_create_info_ext.hpp>
#include <core/detail/chain_compatibility/swapchain_present_scaling_create_info_ext.hpp>
#include <core/detail/chain_compatibility/texture_lod_gather_format_properties_amd.hpp>
#include <core/detail/chain_compatibility/timeline_semaphore_submit_info.hpp>
#include <core/detail/chain_compatibility/validation_features_ext.hpp>
#include <core/detail/chain_compatibility/validation_flags_ext.hpp>
#include <core/detail/chain_compatibility/video_decode_av1_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_av1_dpb_slot_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_av1_inline_session_parameters_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_av1_picture_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_av1_profile_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_av1_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h264_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h264_dpb_slot_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h264_inline_session_parameters_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h264_picture_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h264_profile_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h264_session_parameters_add_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h264_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h265_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h265_dpb_slot_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h265_inline_session_parameters_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h265_picture_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h265_profile_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h265_session_parameters_add_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_h265_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_decode_usage_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_dpb_slot_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_gop_remaining_frame_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_picture_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_profile_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_quality_level_properties_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_quantization_map_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_rate_control_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_rate_control_layer_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_session_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_av1_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_dpb_slot_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_gop_remaining_frame_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_picture_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_profile_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_quality_level_properties_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_quantization_map_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_rate_control_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_rate_control_layer_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_session_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_session_parameters_add_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_session_parameters_feedback_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h264_session_parameters_get_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_dpb_slot_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_gop_remaining_frame_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_picture_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_profile_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_quality_level_properties_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_quantization_map_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_rate_control_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_rate_control_layer_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_session_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_session_parameters_add_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_session_parameters_feedback_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_h265_session_parameters_get_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_quality_level_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_quantization_map_capabilities_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_quantization_map_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_quantization_map_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_rate_control_info_khr.hpp>
#include <core/detail/chain_compatibility/video_encode_usage_info_khr.hpp>
#include <core/detail/chain_compatibility/video_format_av1_quantization_map_properties_khr.hpp>
#include <core/detail/chain_compatibility/video_format_h265_quantization_map_properties_khr.hpp>
#include <core/detail/chain_compatibility/video_format_quantization_map_properties_khr.hpp>
#include <core/detail/chain_compatibility/video_inline_query_info_khr.hpp>
#include <core/detail/chain_compatibility/video_profile_info_khr.hpp>
#include <core/detail/chain_compatibility/video_profile_list_info_khr.hpp>
#include <core/detail/chain_compatibility/win32_keyed_mutex_acquire_release_info_khr.hpp>
#include <core/detail/chain_compatibility/win32_keyed_mutex_acquire_release_info_nv.hpp>
#include <core/detail/chain_compatibility/write_descriptor_set_acceleration_structure_khr.hpp>
#include <core/detail/chain_compatibility/write_descriptor_set_acceleration_structure_nv.hpp>
#include <core/detail/chain_compatibility/write_descriptor_set_inline_uniform_block.hpp>
#include <core/detail/chain_compatibility/write_descriptor_set_partitioned_acceleration_structure_nv.hpp>
#include <core/detail/chain_validator/acceleration_structure_create_info_khr.hpp>
#include <core/detail/chain_validator/acceleration_structure_create_info_nv.hpp>
#include <core/detail/chain_validator/acceleration_structure_geometry_khr.hpp>
#include <core/detail/chain_validator/acceleration_structure_geometry_triangles_data_khr.hpp>
#include <core/detail/chain_validator/android_hardware_buffer_properties_android.hpp>
#include <core/detail/chain_validator/application_info.hpp>
#include <core/detail/chain_validator/attachment_description2.hpp>
#include <core/detail/chain_validator/attachment_reference2.hpp>
#include <core/detail/chain_validator/bind_buffer_memory_info.hpp>
#include <core/detail/chain_validator/bind_descriptor_buffer_embedded_samplers_info_ext.hpp>
#include <core/detail/chain_validator/bind_descriptor_sets_info.hpp>
#include <core/detail/chain_validator/bind_image_memory_info.hpp>
#include <core/detail/chain_validator/bind_sparse_info.hpp>
#include <core/detail/chain_validator/blit_image_info2.hpp>
#include <core/detail/chain_validator/buffer_create_info.hpp>
#include <core/detail/chain_validator/buffer_image_copy2.hpp>
#include <core/detail/chain_validator/buffer_memory_barrier.hpp>
#include <core/detail/chain_validator/buffer_memory_barrier2.hpp>
#include <core/detail/chain_validator/buffer_view_create_info.hpp>
#include <core/detail/chain_validator/command_buffer_begin_info.hpp>
#include <core/detail/chain_validator/command_buffer_inheritance_info.hpp>
#include <core/detail/chain_validator/command_buffer_submit_info.hpp>
#include <core/detail/chain_validator/command_pool_create_info.hpp>
#include <core/detail/chain_validator/compute_pipeline_create_info.hpp>
#include <core/detail/chain_validator/cu_module_create_info_nvx.hpp>
#include <core/detail/chain_validator/debug_utils_messenger_callback_data_ext.hpp>
#include <core/detail/chain_validator/depth_bias_info_ext.hpp>
#include <core/detail/chain_validator/descriptor_buffer_binding_info_ext.hpp>
#include <core/detail/chain_validator/descriptor_pool_create_info.hpp>
#include <core/detail/chain_validator/descriptor_set_allocate_info.hpp>
#include <core/detail/chain_validator/descriptor_set_layout_create_info.hpp>
#include <core/detail/chain_validator/descriptor_set_layout_support.hpp>
#include <core/detail/chain_validator/device_create_info.hpp>
#include <core/detail/chain_validator/device_queue_create_info.hpp>
#include <core/detail/chain_validator/display_mode_properties2_khr.hpp>
#include <core/detail/chain_validator/display_surface_create_info_khr.hpp>
#include <core/detail/chain_validator/event_create_info.hpp>
#include <core/detail/chain_validator/execution_graph_pipeline_create_info_amdx.hpp>
#include <core/detail/chain_validator/export_metal_objects_info_ext.hpp>
#include <core/detail/chain_validator/fence_create_info.hpp>
#include <core/detail/chain_validator/format_properties2.hpp>
#include <core/detail/chain_validator/framebuffer_create_info.hpp>
#include <core/detail/chain_validator/generated_commands_info_ext.hpp>
#include <core/detail/chain_validator/generated_commands_memory_requirements_info_ext.hpp>
#include <core/detail/chain_validator/graphics_pipeline_create_info.hpp>
#include <core/detail/chain_validator/hdr_metadata_ext.hpp>
#include <core/detail/chain_validator/image_blit2.hpp>
#include <core/detail/chain_validator/image_create_info.hpp>
#include <core/detail/chain_validator/image_format_properties2.hpp>
#include <core/detail/chain_validator/image_memory_barrier.hpp>
#include <core/detail/chain_validator/image_memory_barrier2.hpp>
#include <core/detail/chain_validator/image_memory_requirements_info2.hpp>
#include <core/detail/chain_validator/image_view_create_info.hpp>
#include <core/detail/chain_validator/indirect_commands_layout_create_info_ext.hpp>
#include <core/detail/chain_validator/instance_create_info.hpp>
#include <core/detail/chain_validator/memory_allocate_info.hpp>
#include <core/detail/chain_validator/memory_barrier2.hpp>
#include <core/detail/chain_validator/memory_map_info.hpp>
#include <core/detail/chain_validator/memory_requirements2.hpp>
#include <core/detail/chain_validator/optical_flow_session_create_info_nv.hpp>
#include <core/detail/chain_validator/partitioned_acceleration_structure_instances_input_nv.hpp>
#include <core/detail/chain_validator/physical_device_cluster_culling_shader_features_huawei.hpp>
#include <core/detail/chain_validator/physical_device_external_buffer_info.hpp>
#include <core/detail/chain_validator/physical_device_external_semaphore_info.hpp>
#include <core/detail/chain_validator/physical_device_features2.hpp>
#include <core/detail/chain_validator/physical_device_image_format_info2.hpp>
#include <core/detail/chain_validator/physical_device_layered_api_properties_khr.hpp>
#include <core/detail/chain_validator/physical_device_memory_properties2.hpp>
#include <core/detail/chain_validator/physical_device_properties2.hpp>
#include <core/detail/chain_validator/physical_device_surface_info2_khr.hpp>
#include <core/detail/chain_validator/physical_device_video_format_info_khr.hpp>
#include <core/detail/chain_validator/pipeline_color_blend_state_create_info.hpp>
#include <core/detail/chain_validator/pipeline_multisample_state_create_info.hpp>
#include <core/detail/chain_validator/pipeline_rasterization_state_create_info.hpp>
#include <core/detail/chain_validator/pipeline_shader_stage_create_info.hpp>
#include <core/detail/chain_validator/pipeline_tessellation_state_create_info.hpp>
#include <core/detail/chain_validator/pipeline_vertex_input_state_create_info.hpp>
#include <core/detail/chain_validator/pipeline_viewport_state_create_info.hpp>
#include <core/detail/chain_validator/present_info_khr.hpp>
#include <core/detail/chain_validator/push_constants_info.hpp>
#include <core/detail/chain_validator/push_descriptor_set_info.hpp>
#include <core/detail/chain_validator/push_descriptor_set_with_template_info.hpp>
#include <core/detail/chain_validator/query_pool_create_info.hpp>
#include <core/detail/chain_validator/queue_family_properties2.hpp>
#include <core/detail/chain_validator/ray_tracing_pipeline_create_info_khr.hpp>
#include <core/detail/chain_validator/ray_tracing_pipeline_create_info_nv.hpp>
#include <core/detail/chain_validator/render_pass_begin_info.hpp>
#include <core/detail/chain_validator/render_pass_create_info.hpp>
#include <core/detail/chain_validator/render_pass_create_info2.hpp>
#include <core/detail/chain_validator/rendering_info.hpp>
#include <core/detail/chain_validator/sampler_create_info.hpp>
#include <core/detail/chain_validator/sampler_ycbcr_conversion_create_info.hpp>
#include <core/detail/chain_validator/screen_buffer_properties_qnx.hpp>
#include <core/detail/chain_validator/semaphore_create_info.hpp>
#include <core/detail/chain_validator/set_descriptor_buffer_offsets_info_ext.hpp>
#include <core/detail/chain_validator/shader_create_info_ext.hpp>
#include <core/detail/chain_validator/shader_module_create_info.hpp>
#include <core/detail/chain_validator/submit_info.hpp>
#include <core/detail/chain_validator/submit_info2.hpp>
#include <core/detail/chain_validator/subpass_dependency2.hpp>
#include <core/detail/chain_validator/subpass_description2.hpp>
#include <core/detail/chain_validator/subpass_end_info.hpp>
#include <core/detail/chain_validator/subresource_layout2.hpp>
#include <core/detail/chain_validator/surface_capabilities2_khr.hpp>
#include <core/detail/chain_validator/surface_format2_khr.hpp>
#include <core/detail/chain_validator/swapchain_create_info_khr.hpp>
#include <core/detail/chain_validator/video_begin_coding_info_khr.hpp>
#include <core/detail/chain_validator/video_capabilities_khr.hpp>
#include <core/detail/chain_validator/video_coding_control_info_khr.hpp>
#include <core/detail/chain_validator/video_decode_info_khr.hpp>
#include <core/detail/chain_validator/video_encode_info_khr.hpp>
#include <core/detail/chain_validator/video_encode_quality_level_properties_khr.hpp>
#include <core/detail/chain_validator/video_encode_rate_control_layer_info_khr.hpp>
#include <core/detail/chain_validator/video_encode_session_parameters_feedback_info_khr.hpp>
#include <core/detail/chain_validator/video_encode_session_parameters_get_info_khr.hpp>
#include <core/detail/chain_validator/video_format_properties_khr.hpp>
#include <core/detail/chain_validator/video_profile_info_khr.hpp>
#include <core/detail/chain_validator/video_reference_slot_info_khr.hpp>
#include <core/detail/chain_validator/video_session_create_info_khr.hpp>
#include <core/detail/chain_validator/video_session_parameters_create_info_khr.hpp>
#include <core/detail/chain_validator/video_session_parameters_update_info_khr.hpp>
#include <core/detail/chain_validator/write_descriptor_set.hpp>

// IWYU pragma: end_exports

#include <core/traits/parameter_pack.hpp>
#include <core/traits/tuple.hpp>

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

template<typename base_type, typename structure_type>
struct chain_validator
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

template<typename base_type, typename structure_type>
inline constexpr bool allowed_v = chain_validator<base_type, structure_type>::allowed;

template<typename base_type, typename structure_type>
inline constexpr bool unique_v = chain_validator<base_type, structure_type>::unique;

template<typename structure_type>
struct chain_compatibility;

template<typename structure_type>
struct chain_compatibility
{
    using type    = structure_type;
    using parents = std::tuple<>;
};

/// Indicates that two structures are compatible, that is, they have a possible common parent.
template<typename struct_1, typename struct_2>
concept chain_compatible = allowed_v<struct_1, struct_2>
    or (std::tuple_size_v<
           fubuki::traits::tuple::intersection_t<typename chain_compatibility<struct_1>::parents, typename chain_compatibility<struct_2>::parents>>)
        > 0;

template<typename base, typename element, typename... pnext_members>
concept unique = not unique_v<base, std::decay_t<element>> or fubuki::traits::parameter_pack::count_v<element, pnext_members...> == 1u;

/**
 * Indicates if a pnext chain made of the indicated types can be used to extend a structure.
 * @tparam base Type of the structure to extend
 * @tparam pnext_members Types of the elements in the chain.
 */
template<typename base, typename... pnext_members>
[[nodiscard]] constexpr bool can_extend() noexcept
{
    namespace traits = fubuki::traits;

    // It's always valid to not extend a pNext chain
    if constexpr(sizeof...(pnext_members) == 0)
    {
        return true;
    }
    else
    {
        constexpr bool all_compatible = (chain_compatible<base, std::decay_t<pnext_members>> and ...);

        if constexpr(not all_compatible)
        {
            return false;
        }
        else
        {
            constexpr auto uniqueness = []<typename element>(chain_validator<base, element>) constexpr noexcept -> bool
            {
                // May be false when extending a structure that's not a direct base
                constexpr bool direct = allowed_v<base, element>;

                if constexpr(direct)
                {
                    return unique<base, element, pnext_members...>;
                }
                else
                {
                    using possible_parents = traits::tuple::intersection_t<base, element>;

                    constexpr std::size_t possible_parent_count = std::tuple_size_v<possible_parents>;

                    if constexpr(possible_parent_count == 0u)
                    {
                        return false;
                    }
                    else
                    {
                        constexpr auto most_restrictive = []<std::size_t... indices>(std::index_sequence<indices...>) constexpr noexcept -> bool
                        {
                            constexpr auto impl = []<std::size_t index>(std::integral_constant<std::size_t, index>) constexpr noexcept -> bool
                            {
                                using parent_type = traits::parameter_pack::nth_type<index, pnext_members...>;
                                return unique<parent_type, element, pnext_members...>;
                            };

                            return (impl(std::integral_constant<std::size_t, indices>{}) and ...);
                        };

                        return most_restrictive(std::make_index_sequence<possible_parent_count>{});
                    }
                }
            };

            return (uniqueness(chain_validator<base, pnext_members>{}) and ...);
        }
    }
}

template<typename base, typename... pnext_members>
inline constexpr bool can_extend_v = can_extend<base, pnext_members...>();

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_PNEXT_CHAIN_HPP
