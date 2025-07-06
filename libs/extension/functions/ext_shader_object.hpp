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

#ifndef FUBUKI_EXTENSION_FUNCTION_EXT_SHADER_OBJECT_HPP
#define FUBUKI_EXTENSION_FUNCTION_EXT_SHADER_OBJECT_HPP

#include <core/config/macros.hpp>
#include <core/detail/pfn.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

namespace fubuki
{

namespace extension
{

namespace functions
{

struct ext_shader_object
{
#if defined(VK_EXT_shader_object)

    struct command
    {
        PFN_vkCmdBindShadersEXT                         bind_shaders_ext                            = nullptr;
        PFN_vkCmdSetCullModeEXT                         set_cull_mode_ext                           = nullptr;
        PFN_vkCmdSetFrontFaceEXT                        set_front_face_ext                          = nullptr;
        PFN_vkCmdSetPrimitiveTopologyEXT                set_primitive_topology_ext                  = nullptr;
        PFN_vkCmdSetViewportWithCountEXT                set_viewport_with_count_ext                 = nullptr;
        PFN_vkCmdSetScissorWithCountEXT                 set_scissor_with_count_ext                  = nullptr;
        PFN_vkCmdBindVertexBuffers2EXT                  bind_vertex_buffers2_ext                    = nullptr;
        PFN_vkCmdSetDepthTestEnableEXT                  set_depth_test_enable_ext                   = nullptr;
        PFN_vkCmdSetDepthWriteEnableEXT                 set_depth_write_enable_ext                  = nullptr;
        PFN_vkCmdSetDepthCompareOpEXT                   set_depth_compare_op_ext                    = nullptr;
        PFN_vkCmdSetDepthBoundsTestEnableEXT            set_depth_bounds_test_enable_ext            = nullptr;
        PFN_vkCmdSetStencilTestEnableEXT                set_stencil_test_enable_ext                 = nullptr;
        PFN_vkCmdSetStencilOpEXT                        set_stencil_op_ext                          = nullptr;
        PFN_vkCmdSetVertexInputEXT                      set_vertex_input_ext                        = nullptr;
        PFN_vkCmdSetPatchControlPointsEXT               set_patch_control_points_ext                = nullptr;
        PFN_vkCmdSetRasterizerDiscardEnableEXT          set_rasterizer_discard_enable_ext           = nullptr;
        PFN_vkCmdSetDepthBiasEnableEXT                  set_depth_bias_enable_ext                   = nullptr;
        PFN_vkCmdSetLogicOpEXT                          set_logic_op_ext                            = nullptr;
        PFN_vkCmdSetPrimitiveRestartEnableEXT           set_primitive_restart_enable_ext            = nullptr;
        PFN_vkCmdSetTessellationDomainOriginEXT         set_tessellation_domain_origin_ext          = nullptr;
        PFN_vkCmdSetDepthClampEnableEXT                 set_depth_clamp_enable_ext                  = nullptr;
        PFN_vkCmdSetPolygonModeEXT                      set_polygon_mode_ext                        = nullptr;
        PFN_vkCmdSetRasterizationSamplesEXT             set_rasterization_samples_ext               = nullptr;
        PFN_vkCmdSetSampleMaskEXT                       set_sample_mask_ext                         = nullptr;
        PFN_vkCmdSetAlphaToCoverageEnableEXT            set_alpha_to_coverage_enable_ext            = nullptr;
        PFN_vkCmdSetAlphaToOneEnableEXT                 set_alpha_to_one_enable_ext                 = nullptr;
        PFN_vkCmdSetLogicOpEnableEXT                    set_logic_op_enable_ext                     = nullptr;
        PFN_vkCmdSetColorBlendEnableEXT                 set_color_blend_enable_ext                  = nullptr;
        PFN_vkCmdSetColorBlendEquationEXT               set_color_blend_equation_ext                = nullptr;
        PFN_vkCmdSetColorWriteMaskEXT                   set_color_write_mask_ext                    = nullptr;
        PFN_vkCmdSetRasterizationStreamEXT              set_rasterization_stream_ext                = nullptr;
        PFN_vkCmdSetConservativeRasterizationModeEXT    set_conservative_rasterization_mode_ext     = nullptr;
        PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT set_extra_primitive_overestimation_size_ext = nullptr;
        PFN_vkCmdSetDepthClipEnableEXT                  set_depth_clip_enable_ext                   = nullptr;
        PFN_vkCmdSetSampleLocationsEnableEXT            set_sample_locations_enable_ext             = nullptr;
        PFN_vkCmdSetColorBlendAdvancedEXT               set_color_blend_advanced_ext                = nullptr;
        PFN_vkCmdSetProvokingVertexModeEXT              set_provoking_vertex_mode_ext               = nullptr;
        PFN_vkCmdSetLineRasterizationModeEXT            set_line_rasterization_mode_ext             = nullptr;
        PFN_vkCmdSetLineStippleEnableEXT                set_line_stipple_enable_ext                 = nullptr;
        PFN_vkCmdSetDepthClipNegativeOneToOneEXT        set_depth_clip_negative_one_to_one_ext      = nullptr;
        PFN_vkCmdSetViewportWScalingEnableNV            set_viewport_w_scaling_enable_nv            = nullptr;
        PFN_vkCmdSetViewportSwizzleNV                   set_viewport_swizzle_nv                     = nullptr;
        PFN_vkCmdSetCoverageToColorEnableNV             set_coverage_to_color_enable_nv             = nullptr;
        PFN_vkCmdSetCoverageToColorLocationNV           set_coverage_to_color_location_nv           = nullptr;
        PFN_vkCmdSetCoverageModulationModeNV            set_coverage_modulation_mode_nv             = nullptr;
        PFN_vkCmdSetCoverageModulationTableEnableNV     set_coverage_modulation_table_enable_nv     = nullptr;
        PFN_vkCmdSetCoverageModulationTableNV           set_coverage_modulation_table_nv            = nullptr;
        PFN_vkCmdSetShadingRateImageEnableNV            set_shading_rate_image_enable_nv            = nullptr;
        PFN_vkCmdSetRepresentativeFragmentTestEnableNV  set_representative_fragment_test_enable_nv  = nullptr;
        PFN_vkCmdSetCoverageReductionModeNV             set_coverage_reduction_mode_nv              = nullptr;
        PFN_vkCmdSetDepthClampRangeEXT                  set_depth_clamp_range_ext                   = nullptr;
    };

    PFN_vkCreateShadersEXT       create_shaders_ext         = nullptr;
    PFN_vkDestroyShaderEXT       destroy_shader_ext         = nullptr;
    PFN_vkGetShaderBinaryDataEXT get_shader_binary_data_ext = nullptr;

    command cmd = {};

#endif // defined(VK_EXT_shader_object)

    /// Loads the extension.
    [[nodiscard]] FUBUKI_EXTENSION_API static ext_shader_object
    load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept;
};

} // namespace functions

/**
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_EXT_shader_object.html
 */
namespace ext_shader_object
{

/// Name of the extension.
inline constexpr auto name = "VK_EXT_shader_object";

using functions = extension::functions::ext_shader_object;

/// Loads the extension.
[[nodiscard]] inline functions
load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept
{
    return functions::load(instance, vk_version, device);
}

} // namespace ext_shader_object

} // namespace extension

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a extension::functions::ext_shader_object struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<extension::functions::ext_shader_object, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const extension::functions::ext_shader_object&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, fubuki_name)                                                         \
    template<>                                                                                                      \
    struct get_from<extension::functions::ext_shader_object, #vk_function_name>                                     \
    {                                                                                                               \
        static constexpr bool valid = true;                                                                         \
                                                                                                                    \
        [[nodiscard]] constexpr static auto* get(const extension::functions::ext_shader_object& functions) noexcept \
        {                                                                                                           \
            static_assert(                                                                                          \
                requires {                                                                                          \
                    {                                                                                               \
                        functions.fubuki_name                                                                       \
                    };                                                                                              \
                }, "Internal error. Bad name or version structure.");                                               \
                                                                                                                    \
            auto pfn = functions.fubuki_name;                                                                       \
                                                                                                                    \
            using expected_pfn_type = PFN_##vk_function_name;                                                       \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                                  \
                                                                                                                    \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch.");           \
                                                                                                                    \
            return pfn;                                                                                             \
        }                                                                                                           \
    }

#if defined(VK_EXT_shader_object)
FUBUKI_MAKE_GET_FROM(vkCreateShadersEXT, create_shaders_ext);
FUBUKI_MAKE_GET_FROM(vkDestroyShaderEXT, destroy_shader_ext);
FUBUKI_MAKE_GET_FROM(vkGetShaderBinaryDataEXT, get_shader_binary_data_ext);
FUBUKI_MAKE_GET_FROM(vkCmdBindShadersEXT, cmd.bind_shaders_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetCullModeEXT, cmd.set_cull_mode_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetFrontFaceEXT, cmd.set_front_face_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetPrimitiveTopologyEXT, cmd.set_primitive_topology_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetViewportWithCountEXT, cmd.set_viewport_with_count_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetScissorWithCountEXT, cmd.set_scissor_with_count_ext);
FUBUKI_MAKE_GET_FROM(vkCmdBindVertexBuffers2EXT, cmd.bind_vertex_buffers2_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthTestEnableEXT, cmd.set_depth_test_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthWriteEnableEXT, cmd.set_depth_write_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthCompareOpEXT, cmd.set_depth_compare_op_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthBoundsTestEnableEXT, cmd.set_depth_bounds_test_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetStencilTestEnableEXT, cmd.set_stencil_test_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetStencilOpEXT, cmd.set_stencil_op_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetVertexInputEXT, cmd.set_vertex_input_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetPatchControlPointsEXT, cmd.set_patch_control_points_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetRasterizerDiscardEnableEXT, cmd.set_rasterizer_discard_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthBiasEnableEXT, cmd.set_depth_bias_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetLogicOpEXT, cmd.set_logic_op_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetPrimitiveRestartEnableEXT, cmd.set_primitive_restart_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetTessellationDomainOriginEXT, cmd.set_tessellation_domain_origin_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthClampEnableEXT, cmd.set_depth_clamp_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetPolygonModeEXT, cmd.set_polygon_mode_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetRasterizationSamplesEXT, cmd.set_rasterization_samples_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetSampleMaskEXT, cmd.set_sample_mask_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetAlphaToCoverageEnableEXT, cmd.set_alpha_to_coverage_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetAlphaToOneEnableEXT, cmd.set_alpha_to_one_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetLogicOpEnableEXT, cmd.set_logic_op_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetColorBlendEnableEXT, cmd.set_color_blend_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetColorBlendEquationEXT, cmd.set_color_blend_equation_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetColorWriteMaskEXT, cmd.set_color_write_mask_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetRasterizationStreamEXT, cmd.set_rasterization_stream_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetConservativeRasterizationModeEXT, cmd.set_conservative_rasterization_mode_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetExtraPrimitiveOverestimationSizeEXT, cmd.set_extra_primitive_overestimation_size_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthClipEnableEXT, cmd.set_depth_clip_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetSampleLocationsEnableEXT, cmd.set_sample_locations_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetColorBlendAdvancedEXT, cmd.set_color_blend_advanced_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetProvokingVertexModeEXT, cmd.set_provoking_vertex_mode_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetLineRasterizationModeEXT, cmd.set_line_rasterization_mode_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetLineStippleEnableEXT, cmd.set_line_stipple_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthClipNegativeOneToOneEXT, cmd.set_depth_clip_negative_one_to_one_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetViewportWScalingEnableNV, cmd.set_viewport_w_scaling_enable_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetViewportSwizzleNV, cmd.set_viewport_swizzle_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetCoverageToColorEnableNV, cmd.set_coverage_to_color_enable_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetCoverageToColorLocationNV, cmd.set_coverage_to_color_location_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetCoverageModulationModeNV, cmd.set_coverage_modulation_mode_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetCoverageModulationTableEnableNV, cmd.set_coverage_modulation_table_enable_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetCoverageModulationTableNV, cmd.set_coverage_modulation_table_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetShadingRateImageEnableNV, cmd.set_shading_rate_image_enable_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetRepresentativeFragmentTestEnableNV, cmd.set_representative_fragment_test_enable_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetCoverageReductionModeNV, cmd.set_coverage_reduction_mode_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthClampRangeEXT, cmd.set_depth_clamp_range_ext);

#endif // defined(VK_EXT_shader_object)

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_EXTENSION_EXT_SHADER_OBJECT_HPP
