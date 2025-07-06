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

#ifndef FUBUKI_EXTENSION_EXT_EXTENDED_DYNAMIC_STATE3_HPP
#define FUBUKI_EXTENSION_EXT_EXTENDED_DYNAMIC_STATE3_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_extended_dynamic_state3.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_extended_dynamic_state3::cmd
{

#if defined(VK_EXT_extended_dynamic_state3)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetTessellationDomainOriginEXT.html
FUBUKI_EXTENSION_API
void set_tessellation_domain_origin(const functions& ext, command_buffer_handle command_buffer, VkTessellationDomainOrigin domain_origin) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthClampEnableEXT.html
FUBUKI_EXTENSION_API
void set_depth_clamp_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_clamp_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPolygonModeEXT.html
FUBUKI_EXTENSION_API
void set_polygon_mode(const functions& ext, command_buffer_handle command_buffer, VkPolygonMode polygon_mode) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRasterizationSamplesEXT.html
FUBUKI_EXTENSION_API
void set_rasterization_samples(const functions& ext, command_buffer_handle command_buffer, VkSampleCountFlagBits rasterization_samples) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetSampleMaskEXT.html
FUBUKI_EXTENSION_API
void set_sample_mask(const functions&              ext,
                     command_buffer_handle         command_buffer,
                     VkSampleCountFlagBits         samples,
                     std::span<const VkSampleMask> masks) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetAlphaToCoverageEnableEXT.html
FUBUKI_EXTENSION_API
void set_alpha_to_coverage_enable(const functions& ext, command_buffer_handle command_buffer, bool alpha_to_coverage_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetAlphaToOneEnableEXT.html
FUBUKI_EXTENSION_API
void set_alpha_to_one_enable(const functions& ext, command_buffer_handle command_buffer, bool alpha_to_one_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetLogicOpEnableEXT.html
FUBUKI_EXTENSION_API
void set_logic_op_enable(const functions& ext, command_buffer_handle command_buffer, bool logic_op_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetColorBlendEnableEXT.html
FUBUKI_EXTENSION_API
void set_color_blend_enable(const functions&          ext,
                            command_buffer_handle     command_buffer,
                            std::uint32_t             first_attachment,
                            std::span<const VkBool32> enables) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetColorBlendEquationEXT.html
FUBUKI_EXTENSION_API
void set_color_blend_equation(const functions&                         ext,
                              command_buffer_handle                    command_buffer,
                              std::uint32_t                            first_attachment,
                              std::span<const VkColorBlendEquationEXT> equations) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetColorWriteMaskEXT.html
FUBUKI_EXTENSION_API
void set_color_write_mask(const functions&                       ext,
                          command_buffer_handle                  command_buffer,
                          std::uint32_t                          first_attachment,
                          std::span<const VkColorComponentFlags> write_masks) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRasterizationStreamEXT.html
FUBUKI_EXTENSION_API
void set_rasterization_stream(const functions& ext, command_buffer_handle command_buffer, std::uint32_t rasterization_stream) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetConservativeRasterizationModeEXT.html
FUBUKI_EXTENSION_API
void set_conservative_rasterization_mode(const functions&                   ext,
                                         command_buffer_handle              command_buffer,
                                         VkConservativeRasterizationModeEXT conservative_rasterization_mode) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetExtraPrimitiveOverestimationSizeEXT.html
FUBUKI_EXTENSION_API
void set_extra_primitive_overestimation_size(const functions&      ext,
                                             command_buffer_handle command_buffer,
                                             float                 extra_primitive_overestimation_size) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthClipEnableEXT.html
FUBUKI_EXTENSION_API
void set_depth_clip_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_clip_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetSampleLocationsEnableEXT.html
FUBUKI_EXTENSION_API
void set_sample_locations_enable(const functions& ext, command_buffer_handle command_buffer, bool sample_locations_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetColorBlendAdvancedEXT.html
FUBUKI_EXTENSION_API
void set_color_blend_advanced(const functions&                         ext,
                              command_buffer_handle                    command_buffer,
                              std::uint32_t                            first_attachment,
                              std::span<const VkColorBlendAdvancedEXT> blend_advanced) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetProvokingVertexModeEXT.html
FUBUKI_EXTENSION_API
void set_provoking_vertex_mode(const functions& ext, command_buffer_handle command_buffer, VkProvokingVertexModeEXT provoking_vertex_mode) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetLineRasterizationModeEXT.html
FUBUKI_EXTENSION_API
void set_line_rasterization_mode(const functions&           ext,
                                 command_buffer_handle      command_buffer,
                                 VkLineRasterizationModeEXT line_rasterization_mode) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetLineStippleEnableEXT.html
FUBUKI_EXTENSION_API
void set_line_stipple_enable(const functions& ext, command_buffer_handle command_buffer, bool stippled_line_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthClipNegativeOneToOneEXT.html
FUBUKI_EXTENSION_API
void set_depth_clip_negative_one_to_one(const functions& ext, command_buffer_handle command_buffer, bool negative_one_to_one) noexcept;

    #if defined(VK_NV_clip_space_w_scaling)
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportWScalingEnableNV.html
FUBUKI_EXTENSION_API
void set_viewport_w_scaling_enable(const functions& ext, command_buffer_handle command_buffer, bool viewport_w_scaling_enable) noexcept;
    #endif // defined(VK_NV_clip_space_w_scaling)

    #if defined(VK_NV_viewport_swizzle)
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportSwizzleNV.html
FUBUKI_EXTENSION_API
void set_viewport_swizzle(const functions&                     ext,
                          command_buffer_handle                command_buffer,
                          std::uint32_t                        first_viewport,
                          std::span<const VkViewportSwizzleNV> swizzles) noexcept;
    #endif // defined(VK_NV_viewport_swizzle)

    #if defined(VK_NV_fragment_coverage_to_color)
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoverageToColorEnableNV.html
FUBUKI_EXTENSION_API
void set_coverage_to_color_enable(const functions& ext, command_buffer_handle command_buffer, bool coverage_to_color_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoverageToColorLocationNV.html
FUBUKI_EXTENSION_API
void set_coverage_to_color_location(const functions& ext, command_buffer_handle command_buffer, std::uint32_t coverage_to_color_location) noexcept;
    #endif // defined(VK_NV_fragment_coverage_to_color)

    #if defined(VK_NV_framebuffer_mixed_samples)
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoverageModulationModeNV.html
FUBUKI_EXTENSION_API
void set_coverage_modulation_mode(const functions&           ext,
                                  command_buffer_handle      command_buffer,
                                  VkCoverageModulationModeNV coverage_modulation_mode) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoverageModulationTableEnableNV.html
FUBUKI_EXTENSION_API
void set_coverage_modulation_table_enable(const functions& ext, command_buffer_handle command_buffer, bool coverage_modulation_table_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoverageModulationTableNV.html
FUBUKI_EXTENSION_API
void set_coverage_modulation_table(const functions&      ext,
                                   command_buffer_handle command_buffer,
                                   std::uint32_t         coverage_modulation_table_count,
                                   const float*          p_coverage_modulation_table) noexcept;
    #endif // defined(VK_NV_framebuffer_mixed_samples)

    #if defined(VK_NV_shading_rate_image)
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetShadingRateImageEnableNV.html
FUBUKI_EXTENSION_API
void set_shading_rate_image_enable(const functions& ext, command_buffer_handle command_buffer, bool shading_rate_image_enable) noexcept;
    #endif // defined(VK_NV_shading_rate_image)

    #if defined(VK_NV_representative_fragment_test)
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRepresentativeFragmentTestEnableNV.html
FUBUKI_EXTENSION_API
void set_representative_fragment_test_enable(const functions&      ext,
                                             command_buffer_handle command_buffer,
                                             bool                  representative_fragment_test_enable) noexcept;
    #endif // defined(VK_NV_representative_fragment_test)

    #if defined(VK_NV_coverage_reduction_mode)
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoverageReductionModeNV.html
FUBUKI_EXTENSION_API
void set_coverage_reduction_mode(const functions&          ext,
                                 command_buffer_handle     command_buffer,
                                 VkCoverageReductionModeNV coverage_reduction_mode) noexcept;
    #endif // defined(VK_NV_coverage_reduction_mode)

#endif // defined(VK_EXT_extended_dynamic_state3)

} // namespace fubuki::extension::ext_extended_dynamic_state3::cmd

#endif // FUBUKI_EXTENSION_EXT_EXTENDED_DYNAMIC_STATE3_HPP
