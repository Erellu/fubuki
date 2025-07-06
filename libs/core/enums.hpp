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

/*
 * This header is provided to avoid having to regenerate top-level (user-exposed) headers.
 * Its contents may change without notice between versions.
 */

#ifndef FUBUKI_CORE_ENUMS_HPP
#define FUBUKI_CORE_ENUMS_HPP

#include "core/enum/acceleration_structure_build_type_khr.hpp"                          // IWYU pragma: export
#include "core/enum/acceleration_structure_compatibility_khr.hpp"                       // IWYU pragma: export
#include "core/enum/acceleration_structure_create_flag_bits_khr.hpp"                    // IWYU pragma: export
#include "core/enum/acceleration_structure_memory_requirements_type_nv.hpp"             // IWYU pragma: export
#include "core/enum/acceleration_structure_motion_instance_type_nv.hpp"                 // IWYU pragma: export
#include "core/enum/acceleration_structure_type_khr.hpp"                                // IWYU pragma: export
#include "core/enum/access_flag_bits.hpp"                                               // IWYU pragma: export
#include "core/enum/access_flag_bits2.hpp"                                              // IWYU pragma: export
#include "core/enum/access_flag_bits3_khr.hpp"                                          // IWYU pragma: export
#include "core/enum/acquire_profiling_lock_flag_bits_khr.hpp"                           // IWYU pragma: export
#include "core/enum/anti_lag_mode_amd.hpp"                                              // IWYU pragma: export
#include "core/enum/anti_lag_stage_amd.hpp"                                             // IWYU pragma: export
#include "core/enum/attachment_description_flag_bits.hpp"                               // IWYU pragma: export
#include "core/enum/attachment_load_op.hpp"                                             // IWYU pragma: export
#include "core/enum/attachment_store_op.hpp"                                            // IWYU pragma: export
#include "core/enum/blend_factor.hpp"                                                   // IWYU pragma: export
#include "core/enum/blend_op.hpp"                                                       // IWYU pragma: export
#include "core/enum/blend_overlap_ext.hpp"                                              // IWYU pragma: export
#include "core/enum/block_match_window_compare_mode_qcom.hpp"                           // IWYU pragma: export
#include "core/enum/border_color.hpp"                                                   // IWYU pragma: export
#include "core/enum/buffer_create_flag_bits.hpp"                                        // IWYU pragma: export
#include "core/enum/buffer_usage_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/buffer_usage_flag_bits2.hpp"                                        // IWYU pragma: export
#include "core/enum/build_acceleration_structure_flag_bits_khr.hpp"                     // IWYU pragma: export
#include "core/enum/build_acceleration_structure_mode_khr.hpp"                          // IWYU pragma: export
#include "core/enum/build_micromap_flag_bits_ext.hpp"                                   // IWYU pragma: export
#include "core/enum/build_micromap_mode_ext.hpp"                                        // IWYU pragma: export
#include "core/enum/chroma_location.hpp"                                                // IWYU pragma: export
#include "core/enum/cluster_acceleration_structure_address_resolution_flag_bits_nv.hpp" // IWYU pragma: export
#include "core/enum/cluster_acceleration_structure_cluster_flag_bits_nv.hpp"            // IWYU pragma: export
#include "core/enum/cluster_acceleration_structure_geometry_flag_bits_nv.hpp"           // IWYU pragma: export
#include "core/enum/cluster_acceleration_structure_index_format_flag_bits_nv.hpp"       // IWYU pragma: export
#include "core/enum/cluster_acceleration_structure_op_mode_nv.hpp"                      // IWYU pragma: export
#include "core/enum/cluster_acceleration_structure_op_type_nv.hpp"                      // IWYU pragma: export
#include "core/enum/cluster_acceleration_structure_type_nv.hpp"                         // IWYU pragma: export
#include "core/enum/coarse_sample_order_type_nv.hpp"                                    // IWYU pragma: export
#include "core/enum/color_component_flag_bits.hpp"                                      // IWYU pragma: export
#include "core/enum/color_space_khr.hpp"                                                // IWYU pragma: export
#include "core/enum/command_buffer_level.hpp"                                           // IWYU pragma: export
#include "core/enum/command_buffer_reset_flag_bits.hpp"                                 // IWYU pragma: export
#include "core/enum/command_buffer_usage_flag_bits.hpp"                                 // IWYU pragma: export
#include "core/enum/command_pool_create_flag_bits.hpp"                                  // IWYU pragma: export
#include "core/enum/command_pool_reset_flag_bits.hpp"                                   // IWYU pragma: export
#include "core/enum/compare_op.hpp"                                                     // IWYU pragma: export
#include "core/enum/component_swizzle.hpp"                                              // IWYU pragma: export
#include "core/enum/component_type_khr.hpp"                                             // IWYU pragma: export
#include "core/enum/composite_alpha_flag_bits_khr.hpp"                                  // IWYU pragma: export
#include "core/enum/conditional_rendering_flag_bits_ext.hpp"                            // IWYU pragma: export
#include "core/enum/conservative_rasterization_mode_ext.hpp"                            // IWYU pragma: export
#include "core/enum/cooperative_vector_matrix_layout_nv.hpp"                            // IWYU pragma: export
#include "core/enum/copy_acceleration_structure_mode_khr.hpp"                           // IWYU pragma: export
#include "core/enum/copy_micromap_mode_ext.hpp"                                         // IWYU pragma: export
#include "core/enum/coverage_modulation_mode_nv.hpp"                                    // IWYU pragma: export
#include "core/enum/coverage_reduction_mode_nv.hpp"                                     // IWYU pragma: export
#include "core/enum/cubic_filter_weights_qcom.hpp"                                      // IWYU pragma: export
#include "core/enum/cull_mode_flag_bits.hpp"                                            // IWYU pragma: export
#include "core/enum/debug_report_flag_bits_ext.hpp"                                     // IWYU pragma: export
#include "core/enum/debug_report_object_type_ext.hpp"                                   // IWYU pragma: export
#include "core/enum/debug_utils_message_severity_flag_bits_ext.hpp"                     // IWYU pragma: export
#include "core/enum/debug_utils_message_type_flag_bits_ext.hpp"                         // IWYU pragma: export
#include "core/enum/dependency_flag_bits.hpp"                                           // IWYU pragma: export
#include "core/enum/depth_bias_representation_ext.hpp"                                  // IWYU pragma: export
#include "core/enum/depth_clamp_mode_ext.hpp"                                           // IWYU pragma: export
#include "core/enum/descriptor_binding_flag_bits.hpp"                                   // IWYU pragma: export
#include "core/enum/descriptor_pool_create_flag_bits.hpp"                               // IWYU pragma: export
#include "core/enum/descriptor_set_layout_create_flag_bits.hpp"                         // IWYU pragma: export
#include "core/enum/descriptor_type.hpp"                                                // IWYU pragma: export
#include "core/enum/descriptor_update_template_type.hpp"                                // IWYU pragma: export
#include "core/enum/device_address_binding_flag_bits_ext.hpp"                           // IWYU pragma: export
#include "core/enum/device_address_binding_type_ext.hpp"                                // IWYU pragma: export
#include "core/enum/device_diagnostics_config_flag_bits_nv.hpp"                         // IWYU pragma: export
#include "core/enum/device_event_type_ext.hpp"                                          // IWYU pragma: export
#include "core/enum/device_fault_address_type_ext.hpp"                                  // IWYU pragma: export
#include "core/enum/device_fault_vendor_binary_header_version_ext.hpp"                  // IWYU pragma: export
#include "core/enum/device_group_present_mode_flag_bits_khr.hpp"                        // IWYU pragma: export
#include "core/enum/device_memory_report_event_type_ext.hpp"                            // IWYU pragma: export
#include "core/enum/device_queue_create_flag_bits.hpp"                                  // IWYU pragma: export
#include "core/enum/direct_driver_loading_mode_lunarg.hpp"                              // IWYU pragma: export
#include "core/enum/discard_rectangle_mode_ext.hpp"                                     // IWYU pragma: export
#include "core/enum/displacement_micromap_format_nv.hpp"                                // IWYU pragma: export
#include "core/enum/display_event_type_ext.hpp"                                         // IWYU pragma: export
#include "core/enum/display_plane_alpha_flag_bits_khr.hpp"                              // IWYU pragma: export
#include "core/enum/display_power_state_ext.hpp"                                        // IWYU pragma: export
#include "core/enum/display_surface_stereo_type_nv.hpp"                                 // IWYU pragma: export
#include "core/enum/driver_id.hpp"                                                      // IWYU pragma: export
#include "core/enum/dynamic_state.hpp"                                                  // IWYU pragma: export
#include "core/enum/event_create_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/export_metal_object_type_flag_bits_ext.hpp"                         // IWYU pragma: export
#include "core/enum/external_fence_feature_flag_bits.hpp"                               // IWYU pragma: export
#include "core/enum/external_fence_handle_type_flag_bits.hpp"                           // IWYU pragma: export
#include "core/enum/external_memory_feature_flag_bits.hpp"                              // IWYU pragma: export
#include "core/enum/external_memory_feature_flag_bits_nv.hpp"                           // IWYU pragma: export
#include "core/enum/external_memory_handle_type_flag_bits.hpp"                          // IWYU pragma: export
#include "core/enum/external_memory_handle_type_flag_bits_nv.hpp"                       // IWYU pragma: export
#include "core/enum/external_semaphore_feature_flag_bits.hpp"                           // IWYU pragma: export
#include "core/enum/external_semaphore_handle_type_flag_bits.hpp"                       // IWYU pragma: export
#include "core/enum/fault_level.hpp"                                                    // IWYU pragma: export
#include "core/enum/fault_query_behavior.hpp"                                           // IWYU pragma: export
#include "core/enum/fault_type.hpp"                                                     // IWYU pragma: export
#include "core/enum/fence_create_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/fence_import_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/filter.hpp"                                                         // IWYU pragma: export
#include "core/enum/format.hpp"                                                         // IWYU pragma: export
#include "core/enum/format_feature_flag_bits.hpp"                                       // IWYU pragma: export
#include "core/enum/format_feature_flag_bits2.hpp"                                      // IWYU pragma: export
#include "core/enum/fragment_shading_rate_combiner_op_khr.hpp"                          // IWYU pragma: export
#include "core/enum/fragment_shading_rate_nv.hpp"                                       // IWYU pragma: export
#include "core/enum/fragment_shading_rate_type_nv.hpp"                                  // IWYU pragma: export
#include "core/enum/frame_boundary_flag_bits_ext.hpp"                                   // IWYU pragma: export
#include "core/enum/framebuffer_create_flag_bits.hpp"                                   // IWYU pragma: export
#include "core/enum/front_face.hpp"                                                     // IWYU pragma: export
#include "core/enum/full_screen_exclusive_ext.hpp"                                      // IWYU pragma: export
#include "core/enum/geometry_flag_bits_khr.hpp"                                         // IWYU pragma: export
#include "core/enum/geometry_instance_flag_bits_khr.hpp"                                // IWYU pragma: export
#include "core/enum/geometry_type_khr.hpp"                                              // IWYU pragma: export
#include "core/enum/graphics_pipeline_library_flag_bits_ext.hpp"                        // IWYU pragma: export
#include "core/enum/host_image_copy_flag_bits.hpp"                                      // IWYU pragma: export
#include "core/enum/image_aspect_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/image_compression_fixed_rate_flag_bits_ext.hpp"                     // IWYU pragma: export
#include "core/enum/image_compression_flag_bits_ext.hpp"                                // IWYU pragma: export
#include "core/enum/image_constraints_info_flag_bits_fuchsia.hpp"                       // IWYU pragma: export
#include "core/enum/image_create_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/image_format_constraints_flag_bits_fuchsia.hpp"                     // IWYU pragma: export
#include "core/enum/image_layout.hpp"                                                   // IWYU pragma: export
#include "core/enum/image_tiling.hpp"                                                   // IWYU pragma: export
#include "core/enum/image_type.hpp"                                                     // IWYU pragma: export
#include "core/enum/image_usage_flag_bits.hpp"                                          // IWYU pragma: export
#include "core/enum/image_view_create_flag_bits.hpp"                                    // IWYU pragma: export
#include "core/enum/image_view_type.hpp"                                                // IWYU pragma: export
#include "core/enum/index_type.hpp"                                                     // IWYU pragma: export
#include "core/enum/indirect_commands_input_mode_flag_bits_ext.hpp"                     // IWYU pragma: export
#include "core/enum/indirect_commands_layout_usage_flag_bits_ext.hpp"                   // IWYU pragma: export
#include "core/enum/indirect_commands_layout_usage_flag_bits_nv.hpp"                    // IWYU pragma: export
#include "core/enum/indirect_commands_token_type_ext.hpp"                               // IWYU pragma: export
#include "core/enum/indirect_commands_token_type_nv.hpp"                                // IWYU pragma: export
#include "core/enum/indirect_execution_set_info_type_ext.hpp"                           // IWYU pragma: export
#include "core/enum/indirect_state_flag_bits_nv.hpp"                                    // IWYU pragma: export
#include "core/enum/instance_create_flag_bits.hpp"                                      // IWYU pragma: export
#include "core/enum/internal_allocation_type.hpp"                                       // IWYU pragma: export
#include "core/enum/latency_marker_nv.hpp"                                              // IWYU pragma: export
#include "core/enum/layer_setting_type_ext.hpp"                                         // IWYU pragma: export
#include "core/enum/layered_driver_underlying_api_msft.hpp"                             // IWYU pragma: export
#include "core/enum/line_rasterization_mode.hpp"                                        // IWYU pragma: export
#include "core/enum/logic_op.hpp"                                                       // IWYU pragma: export
#include "core/enum/memory_allocate_flag_bits.hpp"                                      // IWYU pragma: export
#include "core/enum/memory_decompression_method_flag_bits_nv.hpp"                       // IWYU pragma: export
#include "core/enum/memory_heap_flag_bits.hpp"                                          // IWYU pragma: export
#include "core/enum/memory_map_flag_bits.hpp"                                           // IWYU pragma: export
#include "core/enum/memory_overallocation_behavior_amd.hpp"                             // IWYU pragma: export
#include "core/enum/memory_property_flag_bits.hpp"                                      // IWYU pragma: export
#include "core/enum/memory_unmap_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/micromap_create_flag_bits_ext.hpp"                                  // IWYU pragma: export
#include "core/enum/micromap_type_ext.hpp"                                              // IWYU pragma: export
#include "core/enum/object_type.hpp"                                                    // IWYU pragma: export
#include "core/enum/opacity_micromap_format_ext.hpp"                                    // IWYU pragma: export
#include "core/enum/opacity_micromap_special_index_ext.hpp"                             // IWYU pragma: export
#include "core/enum/optical_flow_execute_flag_bits_nv.hpp"                              // IWYU pragma: export
#include "core/enum/optical_flow_grid_size_flag_bits_nv.hpp"                            // IWYU pragma: export
#include "core/enum/optical_flow_performance_level_nv.hpp"                              // IWYU pragma: export
#include "core/enum/optical_flow_session_binding_point_nv.hpp"                          // IWYU pragma: export
#include "core/enum/optical_flow_session_create_flag_bits_nv.hpp"                       // IWYU pragma: export
#include "core/enum/optical_flow_usage_flag_bits_nv.hpp"                                // IWYU pragma: export
#include "core/enum/out_of_band_queue_type_nv.hpp"                                      // IWYU pragma: export
#include "core/enum/partitioned_acceleration_structure_instance_flag_bits_nv.hpp"       // IWYU pragma: export
#include "core/enum/partitioned_acceleration_structure_op_type_nv.hpp"                  // IWYU pragma: export
#include "core/enum/peer_memory_feature_flag_bits.hpp"                                  // IWYU pragma: export
#include "core/enum/performance_configuration_type_intel.hpp"                           // IWYU pragma: export
#include "core/enum/performance_counter_description_flag_bits_khr.hpp"                  // IWYU pragma: export
#include "core/enum/performance_counter_scope_khr.hpp"                                  // IWYU pragma: export
#include "core/enum/performance_counter_storage_khr.hpp"                                // IWYU pragma: export
#include "core/enum/performance_counter_unit_khr.hpp"                                   // IWYU pragma: export
#include "core/enum/performance_override_type_intel.hpp"                                // IWYU pragma: export
#include "core/enum/performance_parameter_type_intel.hpp"                               // IWYU pragma: export
#include "core/enum/performance_value_type_intel.hpp"                                   // IWYU pragma: export
#include "core/enum/physical_device_layered_api_khr.hpp"                                // IWYU pragma: export
#include "core/enum/physical_device_scheduling_controls_flag_bits_arm.hpp"              // IWYU pragma: export
#include "core/enum/physical_device_type.hpp"                                           // IWYU pragma: export
#include "core/enum/pipeline_bind_point.hpp"                                            // IWYU pragma: export
#include "core/enum/pipeline_cache_create_flag_bits.hpp"                                // IWYU pragma: export
#include "core/enum/pipeline_cache_header_version.hpp"                                  // IWYU pragma: export
#include "core/enum/pipeline_cache_validation_version.hpp"                              // IWYU pragma: export
#include "core/enum/pipeline_color_blend_state_create_flag_bits.hpp"                    // IWYU pragma: export
#include "core/enum/pipeline_compiler_control_flag_bits_amd.hpp"                        // IWYU pragma: export
#include "core/enum/pipeline_create_flag_bits.hpp"                                      // IWYU pragma: export
#include "core/enum/pipeline_create_flag_bits2.hpp"                                     // IWYU pragma: export
#include "core/enum/pipeline_creation_feedback_flag_bits.hpp"                           // IWYU pragma: export
#include "core/enum/pipeline_depth_stencil_state_create_flag_bits.hpp"                  // IWYU pragma: export
#include "core/enum/pipeline_executable_statistic_format_khr.hpp"                       // IWYU pragma: export
#include "core/enum/pipeline_layout_create_flag_bits.hpp"                               // IWYU pragma: export
#include "core/enum/pipeline_match_control.hpp"                                         // IWYU pragma: export
#include "core/enum/pipeline_robustness_buffer_behavior.hpp"                            // IWYU pragma: export
#include "core/enum/pipeline_robustness_image_behavior.hpp"                             // IWYU pragma: export
#include "core/enum/pipeline_shader_stage_create_flag_bits.hpp"                         // IWYU pragma: export
#include "core/enum/pipeline_stage_flag_bits.hpp"                                       // IWYU pragma: export
#include "core/enum/pipeline_stage_flag_bits2.hpp"                                      // IWYU pragma: export
#include "core/enum/point_clipping_behavior.hpp"                                        // IWYU pragma: export
#include "core/enum/polygon_mode.hpp"                                                   // IWYU pragma: export
#include "core/enum/present_gravity_flag_bits_ext.hpp"                                  // IWYU pragma: export
#include "core/enum/present_mode_khr.hpp"                                               // IWYU pragma: export
#include "core/enum/present_scaling_flag_bits_ext.hpp"                                  // IWYU pragma: export
#include "core/enum/primitive_topology.hpp"                                             // IWYU pragma: export
#include "core/enum/private_data_slot_create_flag_bits.hpp"                             // IWYU pragma: export
#include "core/enum/provoking_vertex_mode_ext.hpp"                                      // IWYU pragma: export
#include "core/enum/query_control_flag_bits.hpp"                                        // IWYU pragma: export
#include "core/enum/query_pipeline_statistic_flag_bits.hpp"                             // IWYU pragma: export
#include "core/enum/query_pool_sampling_mode_intel.hpp"                                 // IWYU pragma: export
#include "core/enum/query_result_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/query_result_status_khr.hpp"                                        // IWYU pragma: export
#include "core/enum/query_type.hpp"                                                     // IWYU pragma: export
#include "core/enum/queue_flag_bits.hpp"                                                // IWYU pragma: export
#include "core/enum/queue_global_priority.hpp"                                          // IWYU pragma: export
#include "core/enum/rasterization_order_amd.hpp"                                        // IWYU pragma: export
#include "core/enum/ray_tracing_invocation_reorder_mode_nv.hpp"                         // IWYU pragma: export
#include "core/enum/ray_tracing_lss_indexing_mode_nv.hpp"                               // IWYU pragma: export
#include "core/enum/ray_tracing_lss_primitive_end_caps_mode_nv.hpp"                     // IWYU pragma: export
#include "core/enum/ray_tracing_shader_group_type_khr.hpp"                              // IWYU pragma: export
#include "core/enum/refresh_object_flag_bits_khr.hpp"                                   // IWYU pragma: export
#include "core/enum/render_pass_create_flag_bits.hpp"                                   // IWYU pragma: export
#include "core/enum/rendering_flag_bits.hpp"                                            // IWYU pragma: export
#include "core/enum/resolve_mode_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/sample_count_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/sampler_address_mode.hpp"                                           // IWYU pragma: export
#include "core/enum/sampler_create_flag_bits.hpp"                                       // IWYU pragma: export
#include "core/enum/sampler_mipmap_mode.hpp"                                            // IWYU pragma: export
#include "core/enum/sampler_reduction_mode.hpp"                                         // IWYU pragma: export
#include "core/enum/sampler_ycbcr_model_conversion.hpp"                                 // IWYU pragma: export
#include "core/enum/sampler_ycbcr_range.hpp"                                            // IWYU pragma: export
#include "core/enum/sci_sync_client_type_nv.hpp"                                        // IWYU pragma: export
#include "core/enum/sci_sync_primitive_type_nv.hpp"                                     // IWYU pragma: export
#include "core/enum/scope_khr.hpp"                                                      // IWYU pragma: export
#include "core/enum/semaphore_create_flag_bits.hpp"                                     // IWYU pragma: export
#include "core/enum/semaphore_import_flag_bits.hpp"                                     // IWYU pragma: export
#include "core/enum/semaphore_type.hpp"                                                 // IWYU pragma: export
#include "core/enum/semaphore_wait_flag_bits.hpp"                                       // IWYU pragma: export
#include "core/enum/shader_code_type_ext.hpp"                                           // IWYU pragma: export
#include "core/enum/shader_core_properties_flag_bits_amd.hpp"                           // IWYU pragma: export
#include "core/enum/shader_create_flag_bits_ext.hpp"                                    // IWYU pragma: export
#include "core/enum/shader_float_controls_independence.hpp"                             // IWYU pragma: export
#include "core/enum/shader_group_shader_khr.hpp"                                        // IWYU pragma: export
#include "core/enum/shader_info_type_amd.hpp"                                           // IWYU pragma: export
#include "core/enum/shader_module_create_flag_bits.hpp"                                 // IWYU pragma: export
#include "core/enum/shader_stage_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/shading_rate_palette_entry_nv.hpp"                                  // IWYU pragma: export
#include "core/enum/sharing_mode.hpp"                                                   // IWYU pragma: export
#include "core/enum/sparse_image_format_flag_bits.hpp"                                  // IWYU pragma: export
#include "core/enum/sparse_memory_bind_flag_bits.hpp"                                   // IWYU pragma: export
#include "core/enum/stencil_face_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/stencil_op.hpp"                                                     // IWYU pragma: export
#include "core/enum/structure_type.hpp"                                                 // IWYU pragma: export
#include "core/enum/subgroup_feature_flag_bits.hpp"                                     // IWYU pragma: export
#include "core/enum/submit_flag_bits.hpp"                                               // IWYU pragma: export
#include "core/enum/subpass_contents.hpp"                                               // IWYU pragma: export
#include "core/enum/subpass_description_flag_bits.hpp"                                  // IWYU pragma: export
#include "core/enum/subpass_merge_status_ext.hpp"                                       // IWYU pragma: export
#include "core/enum/surface_counter_flag_bits_ext.hpp"                                  // IWYU pragma: export
#include "core/enum/surface_transform_flag_bits_khr.hpp"                                // IWYU pragma: export
#include "core/enum/swapchain_create_flag_bits_khr.hpp"                                 // IWYU pragma: export
#include "core/enum/swapchain_image_usage_flag_bits_android.hpp"                        // IWYU pragma: export
#include "core/enum/system_allocation_scope.hpp"                                        // IWYU pragma: export
#include "core/enum/tessellation_domain_origin.hpp"                                     // IWYU pragma: export
#include "core/enum/time_domain_khr.hpp"                                                // IWYU pragma: export
#include "core/enum/tool_purpose_flag_bits.hpp"                                         // IWYU pragma: export
#include "core/enum/validation_cache_header_version_ext.hpp"                            // IWYU pragma: export
#include "core/enum/validation_check_ext.hpp"                                           // IWYU pragma: export
#include "core/enum/validation_feature_disable_ext.hpp"                                 // IWYU pragma: export
#include "core/enum/validation_feature_enable_ext.hpp"                                  // IWYU pragma: export
#include "core/enum/vendor_id.hpp"                                                      // IWYU pragma: export
#include "core/enum/vertex_input_rate.hpp"                                              // IWYU pragma: export
#include "core/enum/video_capability_flag_bits_khr.hpp"                                 // IWYU pragma: export
#include "core/enum/video_chroma_subsampling_flag_bits_khr.hpp"                         // IWYU pragma: export
#include "core/enum/video_codec_operation_flag_bits_khr.hpp"                            // IWYU pragma: export
#include "core/enum/video_coding_control_flag_bits_khr.hpp"                             // IWYU pragma: export
#include "core/enum/video_component_bit_depth_flag_bits_khr.hpp"                        // IWYU pragma: export
#include "core/enum/video_decode_capability_flag_bits_khr.hpp"                          // IWYU pragma: export
#include "core/enum/video_decode_h264_picture_layout_flag_bits_khr.hpp"                 // IWYU pragma: export
#include "core/enum/video_decode_usage_flag_bits_khr.hpp"                               // IWYU pragma: export
#include "core/enum/video_encode_av1_capability_flag_bits_khr.hpp"                      // IWYU pragma: export
#include "core/enum/video_encode_av1_prediction_mode_khr.hpp"                           // IWYU pragma: export
#include "core/enum/video_encode_av1_rate_control_flag_bits_khr.hpp"                    // IWYU pragma: export
#include "core/enum/video_encode_av1_rate_control_group_khr.hpp"                        // IWYU pragma: export
#include "core/enum/video_encode_av1_std_flag_bits_khr.hpp"                             // IWYU pragma: export
#include "core/enum/video_encode_av1_superblock_size_flag_bits_khr.hpp"                 // IWYU pragma: export
#include "core/enum/video_encode_capability_flag_bits_khr.hpp"                          // IWYU pragma: export
#include "core/enum/video_encode_content_flag_bits_khr.hpp"                             // IWYU pragma: export
#include "core/enum/video_encode_feedback_flag_bits_khr.hpp"                            // IWYU pragma: export
#include "core/enum/video_encode_flag_bits_khr.hpp"                                     // IWYU pragma: export
#include "core/enum/video_encode_h264_capability_flag_bits_khr.hpp"                     // IWYU pragma: export
#include "core/enum/video_encode_h264_rate_control_flag_bits_khr.hpp"                   // IWYU pragma: export
#include "core/enum/video_encode_h264_std_flag_bits_khr.hpp"                            // IWYU pragma: export
#include "core/enum/video_encode_h265_capability_flag_bits_khr.hpp"                     // IWYU pragma: export
#include "core/enum/video_encode_h265_ctb_size_flag_bits_khr.hpp"                       // IWYU pragma: export
#include "core/enum/video_encode_h265_rate_control_flag_bits_khr.hpp"                   // IWYU pragma: export
#include "core/enum/video_encode_h265_std_flag_bits_khr.hpp"                            // IWYU pragma: export
#include "core/enum/video_encode_h265_transform_block_size_flag_bits_khr.hpp"           // IWYU pragma: export
#include "core/enum/video_encode_rate_control_mode_flag_bits_khr.hpp"                   // IWYU pragma: export
#include "core/enum/video_encode_tuning_mode_khr.hpp"                                   // IWYU pragma: export
#include "core/enum/video_encode_usage_flag_bits_khr.hpp"                               // IWYU pragma: export
#include "core/enum/video_session_create_flag_bits_khr.hpp"                             // IWYU pragma: export
#include "core/enum/video_session_parameters_create_flag_bits_khr.hpp"                  // IWYU pragma: export
#include "core/enum/viewport_coordinate_swizzle_nv.hpp"                                 // IWYU pragma: export
#include "core/enum/wayland_surface_create_flag_bits_khr.hpp"                           // IWYU pragma: export
#include "core/result.hpp"                                                              // IWYU pragma: export

#endif // FUBUKI_CORE_ENUMS_HPP
