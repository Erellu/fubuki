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

#include "extension/ext_extended_dynamic_state3.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_extended_dynamic_state3::cmd
{

#if defined(VK_EXT_extended_dynamic_state3)

void set_tessellation_domain_origin(const functions& ext, command_buffer_handle command_buffer, VkTessellationDomainOrigin domain_origin) noexcept
{
    return fubuki::invoke<"vkCmdSetTessellationDomainOriginEXT">(ext, command_buffer.vk, domain_origin);
}

void set_depth_clamp_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_clamp_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthClampEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(depth_clamp_enable));
}

void set_polygon_mode(const functions& ext, command_buffer_handle command_buffer, VkPolygonMode polygon_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetPolygonModeEXT">(ext, command_buffer.vk, polygon_mode);
}

void set_rasterization_samples(const functions& ext, command_buffer_handle command_buffer, VkSampleCountFlagBits rasterization_samples) noexcept
{
    return fubuki::invoke<"vkCmdSetRasterizationSamplesEXT">(ext, command_buffer.vk, rasterization_samples);
}

void set_sample_mask(const functions&              ext,
                     command_buffer_handle         command_buffer,
                     VkSampleCountFlagBits         samples,
                     std::span<const VkSampleMask> sample_masks) noexcept
{
    return fubuki::invoke<"vkCmdSetSampleMaskEXT">(ext, command_buffer.vk, samples, sample_masks.data());
}

void set_alpha_to_coverage_enable(const functions& ext, command_buffer_handle command_buffer, bool alpha_to_coverage_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetAlphaToCoverageEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(alpha_to_coverage_enable));
}

void set_alpha_to_one_enable(const functions& ext, command_buffer_handle command_buffer, bool alpha_to_one_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetAlphaToOneEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(alpha_to_one_enable));
}

void set_logic_op_enable(const functions& ext, command_buffer_handle command_buffer, bool logic_op_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetLogicOpEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(logic_op_enable));
}

void set_color_blend_enable(const functions&          ext,
                            command_buffer_handle     command_buffer,
                            std::uint32_t             first_attachment,
                            std::span<const VkBool32> enables) noexcept
{
    return fubuki::invoke<"vkCmdSetColorBlendEnableEXT">(ext, command_buffer.vk, first_attachment, vk_size(enables), enables.data());
}

void set_color_blend_equation(const functions&                         ext,
                              command_buffer_handle                    command_buffer,
                              std::uint32_t                            first_attachment,
                              std::span<const VkColorBlendEquationEXT> equations) noexcept
{
    return fubuki::invoke<"vkCmdSetColorBlendEquationEXT">(ext, command_buffer.vk, first_attachment, vk_size(equations), equations.data());
}

void set_color_write_mask(const functions&                       ext,
                          command_buffer_handle                  command_buffer,
                          std::uint32_t                          first_attachment,
                          std::span<const VkColorComponentFlags> write_masks) noexcept
{
    return fubuki::invoke<"vkCmdSetColorWriteMaskEXT">(ext, command_buffer.vk, first_attachment, vk_size(write_masks), write_masks.data());
}

void set_rasterization_stream(const functions& ext, command_buffer_handle command_buffer, std::uint32_t rasterization_stream) noexcept
{
    return fubuki::invoke<"vkCmdSetRasterizationStreamEXT">(ext, command_buffer.vk, rasterization_stream);
}

void set_conservative_rasterization_mode(const functions&                   ext,
                                         command_buffer_handle              command_buffer,
                                         VkConservativeRasterizationModeEXT conservative_rasterization_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetConservativeRasterizationModeEXT">(ext, command_buffer.vk, conservative_rasterization_mode);
}

void set_extra_primitive_overestimation_size(const functions&      ext,
                                             command_buffer_handle command_buffer,
                                             float                 extra_primitive_overestimation_size) noexcept
{
    return fubuki::invoke<"vkCmdSetExtraPrimitiveOverestimationSizeEXT">(ext, command_buffer.vk, extra_primitive_overestimation_size);
}

void set_depth_clip_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_clip_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthClipEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(depth_clip_enable));
}

void set_sample_locations_enable(const functions& ext, command_buffer_handle command_buffer, bool sample_locations_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetSampleLocationsEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(sample_locations_enable));
}

void set_color_blend_advanced(const functions&                         ext,
                              command_buffer_handle                    command_buffer,
                              std::uint32_t                            first_attachment,
                              std::span<const VkColorBlendAdvancedEXT> blend_advanced) noexcept
{
    return fubuki::invoke<"vkCmdSetColorBlendAdvancedEXT">(ext, command_buffer.vk, first_attachment, vk_size(blend_advanced), blend_advanced.data());
}

void set_provoking_vertex_mode(const functions& ext, command_buffer_handle command_buffer, VkProvokingVertexModeEXT provoking_vertex_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetProvokingVertexModeEXT">(ext, command_buffer.vk, provoking_vertex_mode);
}

void set_line_rasterization_mode(const functions&           ext,
                                 command_buffer_handle      command_buffer,
                                 VkLineRasterizationModeEXT line_rasterization_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetLineRasterizationModeEXT">(ext, command_buffer.vk, line_rasterization_mode);
}

void set_line_stipple_enable(const functions& ext, command_buffer_handle command_buffer, bool stippled_line_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetLineStippleEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(stippled_line_enable));
}

void set_depth_clip_negative_one_to_one(const functions& ext, command_buffer_handle command_buffer, bool negative_one_to_one) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthClipNegativeOneToOneEXT">(ext, command_buffer.vk, static_cast<VkBool32>(negative_one_to_one));
}

    #if defined(VK_NV_clip_space_w_scaling)
void set_viewport_w_scaling_enable(const functions& ext, command_buffer_handle command_buffer, bool viewport_w_scaling_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetViewportWScalingEnableNV">(ext, command_buffer.vk, static_cast<VkBool32>(viewport_w_scaling_enable));
}
    #endif // defined(VK_NV_clip_space_w_scaling)

    #if defined(VK_NV_viewport_swizzle)
void set_viewport_swizzle(const functions&                     ext,
                          command_buffer_handle                command_buffer,
                          std::uint32_t                        first_viewport,
                          std::span<const VkViewportSwizzleNV> swizzles) noexcept
{
    return fubuki::invoke<"vkCmdSetViewportSwizzleNV">(ext, command_buffer.vk, first_viewport, vk_size(swizzles), swizzles.data());
}
    #endif // defined(VK_NV_viewport_swizzle)

    #if defined(VK_NV_fragment_coverage_to_color)
void set_coverage_to_color_enable(const functions& ext, command_buffer_handle command_buffer, bool coverage_to_color_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetCoverageToColorEnableNV">(ext, command_buffer.vk, static_cast<VkBool32>(coverage_to_color_enable));
}

void set_coverage_to_color_location(const functions& ext, command_buffer_handle command_buffer, std::uint32_t coverage_to_color_location) noexcept
{
    return fubuki::invoke<"vkCmdSetCoverageToColorLocationNV">(ext, command_buffer.vk, coverage_to_color_location);
}
    #endif // defined(VK_NV_fragment_coverage_to_color)

    #if defined(VK_NV_framebuffer_mixed_samples)
void set_coverage_modulation_mode(const functions&           ext,
                                  command_buffer_handle      command_buffer,
                                  VkCoverageModulationModeNV coverage_modulation_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetCoverageModulationModeNV">(ext, command_buffer.vk, coverage_modulation_mode);
}

void set_coverage_modulation_table_enable(const functions& ext, command_buffer_handle command_buffer, bool coverage_modulation_table_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetCoverageModulationTableEnableNV">(ext, command_buffer.vk, static_cast<VkBool32>(coverage_modulation_table_enable));
}

void set_coverage_modulation_table(const functions&      ext,
                                   command_buffer_handle command_buffer,
                                   std::uint32_t         coverage_modulation_table_count,
                                   const float*          p_coverage_modulation_table) noexcept
{
    return fubuki::invoke<"vkCmdSetCoverageModulationTableNV">(ext, command_buffer.vk, coverage_modulation_table_count, p_coverage_modulation_table);
}
    #endif // defined(VK_NV_framebuffer_mixed_samples)

    #if defined(VK_NV_shading_rate_image)
void set_shading_rate_image_enable(const functions& ext, command_buffer_handle command_buffer, bool shading_rate_image_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetShadingRateImageEnableNV">(ext, command_buffer.vk, static_cast<VkBool32>(shading_rate_image_enable));
}
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_representative_fragment_test)
void set_representative_fragment_test_enable(const functions&      ext,
                                             command_buffer_handle command_buffer,
                                             bool                  representative_fragment_test_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetRepresentativeFragmentTestEnableNV">(
        ext, command_buffer.vk, static_cast<VkBool32>(representative_fragment_test_enable));
}
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_coverage_reduction_mode)
void set_coverage_reduction_mode(const functions&          ext,
                                 command_buffer_handle     command_buffer,
                                 VkCoverageReductionModeNV coverage_reduction_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetCoverageReductionModeNV">(ext, command_buffer.vk, coverage_reduction_mode);
}
    #endif // defined(VK_NV_coverage_reduction_mode)

#endif // defined(VK_EXT_extended_dynamic_state3)

} // namespace fubuki::extension::ext_extended_dynamic_state3::cmd
