# fubuki::extension

> [!IMPORTANT]
> This file is _not_ a substitue for the in-code documentation.
> Its goal is to advertise the features available through `fubuki::extension`.
> For examples and detailed documentation, see the `doxygen`.

## CMake

### Externally

```cmake
target_link_libraries(your_target <PUBLIC|PRIVATE> fubuki::extension)
```

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "extension"
                   PRIVATE_DEPENDENCIES "..."
                   HEADERS              "..."
                   SOURCES              "..."
                   PUBLIC_LINK          "..."
                   PRIVATE_LINK         "..."
                   SYSTEM_PUBLIC_LINK   "..." 
                   SYSTEM_PRIVATE_LINK  "..."
                  )
```

## Nomenclature

| Name                 | Type                     | Category                       | Description    | Notes                  |
| -------------------- | ------------------------ | ------------------------------ | -------------- | ---------------------- |
| Name of the facility | Type, in the C++ meaning | What this facility relates to. | What this does | Additional information |

## Overview

`fubuki::extension` is an interface library meant to simplify the access to features exposed through Vulkan extensions.

## Public API

For all extensions, the following facilities are generated:

- `fubuki::extension::functions::`**`<extension_lower_case_name>`** (without the `vk` prefix to the extension name)
    - **Examples**:
        - `VK_KHR_swapchain_mutable_format` -> `fubuki::extension::functions::khr_swapchain_mutable_format`
        - `VK_FUCHSIA_buffer_collection` -> `fubuki::extension::functions::fuchsia_buffer_collection`
        - `VK_EXT_debug_utils` -> `fubuki::extension::functions::ext_debug_utils`
        - etc.
- Associated `fubuki::extension::`**`<extension_lower_case_name>`**`::load`
- Associated `fubuki::get_from` traits (enabling `fubuki::get_from<"vkFunctionName">(...)`)
- Free functions with reduced names (the corresponding Vulkan function is documented).
    - **Examples**:
        - `vkCreateSwapchainKHR` becomes `khr_swapchain::create`
        - `vkAcquireNextImageKHR` becomes `khr_swapchain::images`
        - etc.
    - Overloads accepting `std::span` and `std::initialiazer_list` are added when relevant.
    - **Note:** all these functions use Fubuki's handles.
- An entry is added to `extension::device_functions` or `extension::instance_function`.
- Associated `fubuki::get_from` traits for  `extension::device_functions` or `extension::instance_function`.

> [!TIP]
> Some extensions benefit from special treatment and get additional quality-of-life features beyond free-functions. For example:
> - `ext_debug_utils` (`VK_EXT_debug_utils`) gets RAII objects for labels, traits for handle names, ...
> - `khr_swapchain` (`VK_KHR_swapchain`) gets `presentation::success`, `presentation::error`, and `presentation::result` that diminish the range of codes to check upon submission. 
> - etc.
> For more information about these extra features, refer to the doxygen documentation.

### Loading

| Name                     | Type          | Category  | Description                                                                                            | Notes                                                                      |
| ------------------------ | ------------- | --------- | ------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------- |
| `load`                   | Free function | Extension | Loads an extension for an instance of `extension::device_functions` or `extension::instance_functions` | An overload exists for device extensions, and one for instance extensions. |
| `<extension name>::load` | Free function | Extension | Loads the function pointers for an extension                                                           | N.A.                                                                       |

## Supported extension

Below follows the list of the extensions currently supported by Fubuki.
For all extensions below, Fubuki provides a mechanism for automatic loading of function pointers and a C++-ish interface.

> [!NOTE]
> Support for `VkSurface`-related facilities is provided through `VK_KHR_surface`. There is no separate mechanism per-platform.

### Instance

- [ ] VK_EXT_application_parameters
- [x] VK_EXT_acquire_drm_display
- [x] VK_EXT_acquire_xlib_display
- [x] VK_EXT_debug_report
- [x] VK_EXT_debug_utils
- [x] VK_EXT_direct_mode_display
- [x] VK_EXT_directfb_surface
- [x] VK_EXT_display_surface_counter
- [x] VK_EXT_headless_surface
- [x] VK_EXT_layer_settings
- [x] VK_EXT_metal_surface
- [x] VK_EXT_surface_maintenance1
- [x] VK_EXT_swapchain_colorspace
- [x] VK_EXT_validation_features
- [x] VK_EXT_validation_flags
- [x] VK_FUCHSIA_imagepipe_surface
- [x] VK_GGP_stream_descriptor_surface
- [x] VK_GOOGLE_surfaceless_query
- [x] VK_KHR_android_surface
- [x] VK_KHR_device_group_creation
- [x] VK_KHR_display
- [x] VK_KHR_external_fence_capabilities
- [x] VK_KHR_external_memory_capabilities
- [x] VK_KHR_external_semaphore_capabilities
- [x] VK_KHR_get_display_properties2
- [x] VK_KHR_get_physical_device_properties2
- [x] VK_KHR_get_surface_capabilities2
- [x] VK_KHR_portability_enumeration
- [x] VK_KHR_surface
- [x] VK_KHR_surface_protected_capabilities
- [x] VK_KHR_wayland_surface
- [x] VK_KHR_win32_surface
- [x] VK_KHR_xcb_surface
- [x] VK_KHR_xlib_surface
- [x] VK_LUNARG_direct_driver_loading
- [x] VK_MVK_ios_surface
- [x] VK_MVK_macos_surface
- [x] VK_NN_vi_surface
- [x] VK_NV_external_memory_capabilities
- [x] VK_QNX_screen_surface

### Device

- [ ] VK_KHR_object_refresh
- [ ] VK_NV_external_memory_sci_buf
- [ ] VK_NV_external_sci_sync
- [ ] VK_NV_external_sci_sync2
- [ ] VK_NV_private_vendor_info
- [x] VK_AMDX_shader_enqueue
- [x] VK_AMD_anti_lag
- [x] VK_AMD_buffer_marker
- [x] VK_AMD_device_coherent_memory
- [x] VK_AMD_display_native_hdr
- [x] VK_AMD_draw_indirect_count
- [x] VK_AMD_gcn_shader
- [x] VK_AMD_gpu_shader_half_float
- [x] VK_AMD_gpu_shader_int16
- [x] VK_AMD_memory_overallocation_behavior
- [x] VK_AMD_mixed_attachment_samples
- [x] VK_AMD_negative_viewport_height
- [x] VK_AMD_pipeline_compiler_control
- [x] VK_AMD_rasterization_order
- [x] VK_AMD_shader_ballot
- [x] VK_AMD_shader_core_properties
- [x] VK_AMD_shader_core_properties2
- [x] VK_AMD_shader_early_and_late_fragment_tests
- [x] VK_AMD_shader_explicit_vertex_parameter
- [x] VK_AMD_shader_fragment_mask
- [x] VK_AMD_shader_image_load_store_lod
- [x] VK_AMD_shader_info
- [x] VK_AMD_shader_trinary_minmax
- [x] VK_AMD_texture_gather_bias_lod
- [x] VK_ANDROID_external_format_resolve
- [x] VK_ANDROID_external_memory_android_hardware_buffer
- [x] VK_ARM_rasterization_order_attachment_access
- [x] VK_ARM_render_pass_striped
- [x] VK_ARM_scheduling_controls
- [x] VK_ARM_shader_core_builtins
- [x] VK_ARM_shader_core_properties
- [x] VK_EXT_4444_formats
- [x] VK_EXT_astc_decode_mode
- [x] VK_EXT_attachment_feedback_loop_dynamic_state
- [x] VK_EXT_attachment_feedback_loop_layout
- [x] VK_EXT_blend_operation_advanced
- [x] VK_EXT_border_color_swizzle
- [x] VK_EXT_buffer_device_address
- [x] VK_EXT_calibrated_timestamps
- [x] VK_EXT_color_write_enable
- [x] VK_EXT_conditional_rendering
- [x] VK_EXT_conservative_rasterization
- [x] VK_EXT_custom_border_color
- [x] VK_EXT_debug_marker
- [x] VK_EXT_depth_bias_control
- [x] VK_EXT_depth_clamp_zero_one
- [x] VK_EXT_depth_clip_control
- [x] VK_EXT_depth_clip_enable
- [x] VK_EXT_depth_range_unrestricted
- [x] VK_EXT_descriptor_buffer
- [x] VK_EXT_descriptor_indexing
- [x] VK_EXT_device_address_binding_report
- [x] VK_EXT_device_fault
- [x] VK_EXT_device_memory_report
- [x] VK_EXT_discard_rectangles
- [x] VK_EXT_display_control
- [x] VK_EXT_dynamic_rendering_unused_attachments
- [x] VK_EXT_extended_dynamic_state
- [x] VK_EXT_extended_dynamic_state2
- [x] VK_EXT_extended_dynamic_state3
- [x] VK_EXT_external_memory_acquire_unmodified
- [x] VK_EXT_external_memory_dma_buf
- [x] VK_EXT_external_memory_host
- [x] VK_EXT_filter_cubic
- [x] VK_EXT_fragment_density_map
- [x] VK_EXT_fragment_density_map2
- [x] VK_EXT_fragment_shader_interlock
- [x] VK_EXT_frame_boundary
- [x] VK_EXT_full_screen_exclusive
- [x] VK_EXT_global_priority
- [x] VK_EXT_global_priority_query
- [x] VK_EXT_graphics_pipeline_library
- [x] VK_EXT_hdr_metadata
- [x] VK_EXT_host_image_copy
- [x] VK_EXT_host_query_reset
- [x] VK_EXT_image_2d_view_of_3d
- [x] VK_EXT_image_compression_control
- [x] VK_EXT_image_compression_control_swapchain
- [x] VK_EXT_image_drm_format_modifier
- [x] VK_EXT_image_robustness
- [x] VK_EXT_image_sliced_view_of_3d
- [x] VK_EXT_image_view_min_lod
- [x] VK_EXT_index_type_uint8
- [x] VK_EXT_inline_uniform_block
- [x] VK_EXT_legacy_dithering
- [x] VK_EXT_legacy_vertex_attributes
- [x] VK_EXT_line_rasterization
- [x] VK_EXT_load_store_op_none
- [x] VK_EXT_map_memory_placed
- [x] VK_EXT_memory_budget
- [x] VK_EXT_memory_priority
- [x] VK_EXT_mesh_shader
- [x] VK_EXT_metal_objects
- [x] VK_EXT_multi_draw
- [x] VK_EXT_multisampled_render_to_single_sampled
- [x] VK_EXT_mutable_descriptor_type
- [x] VK_EXT_nested_command_buffer
- [x] VK_EXT_non_seamless_cube_map
- [x] VK_EXT_opacity_micromap
- [x] VK_EXT_pageable_device_local_memory
- [x] VK_EXT_pci_bus_info
- [x] VK_EXT_physical_device_drm
- [x] VK_EXT_pipeline_creation_cache_control
- [x] VK_EXT_pipeline_creation_feedback
- [x] VK_EXT_pipeline_library_group_handles
- [x] VK_EXT_pipeline_properties
- [x] VK_EXT_pipeline_protected_access
- [x] VK_EXT_pipeline_robustness
- [x] VK_EXT_post_depth_coverage
- [x] VK_EXT_primitive_topology_list_restart
- [x] VK_EXT_primitives_generated_query
- [x] VK_EXT_private_data
- [x] VK_EXT_provoking_vertex
- [x] VK_EXT_queue_family_foreign
- [x] VK_EXT_rasterization_order_attachment_access
- [x] VK_EXT_rgba10x6_formats
- [x] VK_EXT_robustness2
- [x] VK_EXT_sample_locations
- [x] VK_EXT_sampler_filter_minmax
- [x] VK_EXT_scalar_block_layout
- [x] VK_EXT_separate_stencil_usage
- [x] VK_EXT_shader_atomic_float
- [x] VK_EXT_shader_atomic_float2
- [x] VK_EXT_shader_demote_to_helper_invocation
- [x] VK_EXT_shader_image_atomic_int64
- [x] VK_EXT_shader_module_identifier
- [x] VK_EXT_shader_object
- [x] VK_EXT_shader_replicated_composites
- [x] VK_EXT_shader_stencil_export
- [x] VK_EXT_shader_subgroup_ballot
- [x] VK_EXT_shader_subgroup_vote
- [x] VK_EXT_shader_tile_image
- [x] VK_EXT_shader_viewport_index_layer
- [x] VK_EXT_subgroup_size_control
- [x] VK_EXT_subpass_merge_feedback
- [x] VK_EXT_swapchain_maintenance1
- [x] VK_EXT_texel_buffer_alignment
- [x] VK_EXT_texture_compression_astc_hdr
- [x] VK_EXT_tooling_info
- [x] VK_EXT_transform_feedback
- [x] VK_EXT_validation_cache
- [x] VK_EXT_vertex_attribute_divisor
- [x] VK_EXT_vertex_input_dynamic_state
- [x] VK_EXT_ycbcr_2plane_444_formats
- [x] VK_EXT_ycbcr_image_arrays
- [x] VK_FUCHSIA_buffer_collection
- [x] VK_FUCHSIA_external_memory
- [x] VK_FUCHSIA_external_semaphore
- [x] VK_GGP_frame_token
- [x] VK_GOOGLE_decorate_string
- [x] VK_GOOGLE_display_timing
- [x] VK_GOOGLE_hlsl_functionality1
- [x] VK_GOOGLE_user_type
- [x] VK_HUAWEI_cluster_culling_shader
- [x] VK_HUAWEI_invocation_mask
- [x] VK_HUAWEI_subpass_shading
- [x] VK_IMG_filter_cubic
- [x] VK_IMG_format_pvrtc
- [x] VK_IMG_relaxed_line_rasterization
- [x] VK_INTEL_performance_query
- [x] VK_INTEL_shader_integer_functions2
- [x] VK_KHR_16bit_storage
- [x] VK_KHR_8bit_storage
- [x] VK_KHR_acceleration_structure
- [x] VK_KHR_bind_memory2
- [x] VK_KHR_buffer_device_address
- [x] VK_KHR_calibrated_timestamps
- [x] VK_KHR_cooperative_matrix
- [x] VK_KHR_copy_commands2
- [x] VK_KHR_create_renderpass2
- [x] VK_KHR_dedicated_allocation
- [x] VK_KHR_deferred_host_operations
- [x] VK_KHR_depth_stencil_resolve
- [x] VK_KHR_descriptor_update_template
- [x] VK_KHR_device_group
- [x] VK_KHR_display_swapchain
- [x] VK_KHR_draw_indirect_count
- [x] VK_KHR_driver_properties
- [x] VK_KHR_dynamic_rendering
- [x] VK_KHR_dynamic_rendering_local_read
- [x] VK_KHR_external_fence
- [x] VK_KHR_external_fence_fd
- [x] VK_KHR_external_fence_win32
- [x] VK_KHR_external_memory
- [x] VK_KHR_external_memory_fd
- [x] VK_KHR_external_memory_win32
- [x] VK_KHR_external_semaphore
- [x] VK_KHR_external_semaphore_fd
- [x] VK_KHR_external_semaphore_win32
- [x] VK_KHR_format_feature_flags2
- [x] VK_KHR_fragment_shader_barycentric
- [x] VK_KHR_fragment_shading_rate
- [x] VK_KHR_get_memory_requirements2
- [x] VK_KHR_global_priority
- [x] VK_KHR_image_format_list
- [x] VK_KHR_imageless_framebuffer
- [x] VK_KHR_incremental_present
- [x] VK_KHR_index_type_uint8
- [x] VK_KHR_line_rasterization
- [x] VK_KHR_load_store_op_none
- [x] VK_KHR_maintenance1
- [x] VK_KHR_maintenance2
- [x] VK_KHR_maintenance3
- [x] VK_KHR_maintenance4
- [x] VK_KHR_maintenance5
- [x] VK_KHR_maintenance6
- [x] VK_KHR_maintenance7
- [x] VK_KHR_map_memory2
- [x] VK_KHR_multiview
- [x] VK_KHR_performance_query
- [x] VK_KHR_pipeline_executable_properties
- [x] VK_KHR_pipeline_library
- [x] VK_KHR_portability_subset
- [x] VK_KHR_present_id
- [x] VK_KHR_present_wait
- [x] VK_KHR_push_descriptor
- [x] VK_KHR_ray_query
- [x] VK_KHR_ray_tracing_maintenance1
- [x] VK_KHR_ray_tracing_pipeline
- [x] VK_KHR_ray_tracing_position_fetch
- [x] VK_KHR_relaxed_block_layout
- [x] VK_KHR_sampler_mirror_clamp_to_edge
- [x] VK_KHR_sampler_ycbcr_conversion
- [x] VK_KHR_separate_depth_stencil_layouts
- [x] VK_KHR_shader_atomic_int64
- [x] VK_KHR_shader_clock
- [x] VK_KHR_shader_draw_parameters
- [x] VK_KHR_shader_expect_assume
- [x] VK_KHR_shader_float16_int8
- [x] VK_KHR_shader_float_controls
- [x] VK_KHR_shader_float_controls2
- [x] VK_KHR_shader_integer_dot_product
- [x] VK_KHR_shader_maximal_reconvergence
- [x] VK_KHR_shader_non_semantic_info
- [x] VK_KHR_shader_quad_control
- [x] VK_KHR_shader_relaxed_extended_instruction
- [x] VK_KHR_shader_subgroup_extended_types
- [x] VK_KHR_shader_subgroup_rotate
- [x] VK_KHR_shader_subgroup_uniform_control_flow
- [x] VK_KHR_shader_terminate_invocation
- [x] VK_KHR_shared_presentable_image
- [x] VK_KHR_spirv_1_4
- [x] VK_KHR_storage_buffer_storage_class
- [x] VK_KHR_swapchain
- [x] VK_KHR_swapchain_mutable_format
- [x] VK_KHR_synchronization2
- [x] VK_KHR_timeline_semaphore
- [x] VK_KHR_uniform_buffer_standard_layout
- [x] VK_KHR_variable_pointers
- [x] VK_KHR_vertex_attribute_divisor
- [x] VK_KHR_video_decode_av1
- [x] VK_KHR_video_decode_h264
- [x] VK_KHR_video_decode_h265
- [x] VK_KHR_video_decode_queue
- [x] VK_KHR_video_encode_h264
- [x] VK_KHR_video_encode_h265
- [x] VK_KHR_video_encode_queue
- [x] VK_KHR_video_maintenance1
- [x] VK_KHR_video_queue
- [x] VK_KHR_vulkan_memory_model
- [x] VK_KHR_win32_keyed_mutex
- [x] VK_KHR_workgroup_memory_explicit_layout
- [x] VK_KHR_zero_initialize_workgroup_memory
- [x] VK_MESA_image_alignment_control
- [x] VK_MSFT_layered_driver
- [x] VK_NVX_binary_import
- [x] VK_NVX_image_view_handle
- [x] VK_NVX_multiview_per_view_attributes
- [x] VK_NV_acquire_winrt_display
- [x] VK_NV_clip_space_w_scaling
- [x] VK_NV_compute_shader_derivatives
- [x] VK_NV_cooperative_matrix
- [x] VK_NV_copy_memory_indirect
- [x] VK_NV_corner_sampled_image
- [x] VK_NV_coverage_reduction_mode
- [x] VK_NV_cuda_kernel_launch
- [x] VK_NV_dedicated_allocation
- [x] VK_NV_dedicated_allocation_image_aliasing
- [x] VK_NV_descriptor_pool_overallocation
- [x] VK_NV_device_diagnostic_checkpoints
- [x] VK_NV_device_diagnostics_config
- [x] VK_NV_device_generated_commands
- [x] VK_NV_device_generated_commands_compute
- [x] VK_NV_displacement_micromap
- [x] VK_NV_extended_sparse_address_space
- [x] VK_NV_external_memory
- [x] VK_NV_external_memory_rdma
- [x] VK_NV_external_memory_win32
- [x] VK_NV_fill_rectangle
- [x] VK_NV_fragment_coverage_to_color
- [x] VK_NV_fragment_shader_barycentric
- [x] VK_NV_fragment_shading_rate_enums
- [x] VK_NV_framebuffer_mixed_samples
- [x] VK_NV_geometry_shader_passthrough
- [x] VK_NV_glsl_shader
- [x] VK_NV_inherited_viewport_scissor
- [x] VK_NV_linear_color_attachment
- [x] VK_NV_low_latency
- [x] VK_NV_low_latency2
- [x] VK_NV_memory_decompression
- [x] VK_NV_mesh_shader
- [x] VK_NV_optical_flow
- [x] VK_NV_per_stage_descriptor_set
- [x] VK_NV_present_barrier
- [x] VK_NV_raw_access_chains
- [x] VK_NV_ray_tracing
- [x] VK_NV_ray_tracing_invocation_reorder
- [x] VK_NV_ray_tracing_motion_blur
- [x] VK_NV_ray_tracing_validation
- [x] VK_NV_representative_fragment_test
- [x] VK_NV_sample_mask_override_coverage
- [x] VK_NV_scissor_exclusive
- [x] VK_NV_shader_atomic_float16_vector
- [x] VK_NV_shader_image_footprint
- [x] VK_NV_shader_sm_builtins
- [x] VK_NV_shader_subgroup_partitioned
- [x] VK_NV_shading_rate_image
- [x] VK_NV_viewport_array2
- [x] VK_NV_viewport_swizzle
- [x] VK_NV_win32_keyed_mutex
- [x] VK_QCOM_filter_cubic_clamp
- [x] VK_QCOM_filter_cubic_weights
- [x] VK_QCOM_fragment_density_map_offset
- [x] VK_QCOM_image_processing
- [x] VK_QCOM_image_processing2
- [x] VK_QCOM_multiview_per_view_render_areas
- [x] VK_QCOM_multiview_per_view_viewports
- [x] VK_QCOM_render_pass_shader_resolve
- [x] VK_QCOM_render_pass_store_ops
- [x] VK_QCOM_render_pass_transform
- [x] VK_QCOM_rotated_copy_commands
- [x] VK_QCOM_tile_properties
- [x] VK_QCOM_ycbcr_degamma
- [x] VK_QNX_external_memory_screen_buffer
- [x] VK_SEC_amigo_profiling
- [x] VK_VALVE_descriptor_set_host_mapping
- [x] VK_VALVE_mutable_descriptor_type
