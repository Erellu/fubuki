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

#include "extension/functions/ext_extended_dynamic_state3.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
ext_extended_dynamic_state3 ext_extended_dynamic_state3::load([[maybe_unused]] instance_handle instance,
                                                              [[maybe_unused]] version_number  vk_version,
                                                              [[maybe_unused]] device_handle   device) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");
    fubuki_assert(device != null_handle, "Device cannot be null_handle.");

    [[maybe_unused]] auto* const device_get = pfn<"vkGetDeviceProcAddr">(instance);
    fubuki_assert(device_get != nullptr, "Could not retrieve vkGetDeviceProcAddr function pointer.");

    // clang-format off
    return
    {
#if defined(VK_EXT_extended_dynamic_state3)

        .cmd =
        {
            .set_depth_clamp_enable_ext = pfn<"vkCmdSetDepthClampEnableEXT">(instance, device, device_get),
            .set_polygon_mode_ext = pfn<"vkCmdSetPolygonModeEXT">(instance, device, device_get),
            .set_rasterization_samples_ext = pfn<"vkCmdSetRasterizationSamplesEXT">(instance, device, device_get),
            .set_sample_mask_ext = pfn<"vkCmdSetSampleMaskEXT">(instance, device, device_get),
            .set_alpha_to_coverage_enable_ext = pfn<"vkCmdSetAlphaToCoverageEnableEXT">(instance, device, device_get),
            .set_alpha_to_one_enable_ext = pfn<"vkCmdSetAlphaToOneEnableEXT">(instance, device, device_get),
            .set_logic_op_enable_ext = pfn<"vkCmdSetLogicOpEnableEXT">(instance, device, device_get),
            .set_color_blend_enable_ext = pfn<"vkCmdSetColorBlendEnableEXT">(instance, device, device_get),
            .set_color_blend_equation_ext = pfn<"vkCmdSetColorBlendEquationEXT">(instance, device, device_get),
            .set_color_write_mask_ext = pfn<"vkCmdSetColorWriteMaskEXT">(instance, device, device_get),
            .set_tessellation_domain_origin_ext = pfn<"vkCmdSetTessellationDomainOriginEXT">(instance, device, device_get),
            .set_rasterization_stream_ext = pfn<"vkCmdSetRasterizationStreamEXT">(instance, device, device_get),
            .set_conservative_rasterization_mode_ext = pfn<"vkCmdSetConservativeRasterizationModeEXT">(instance, device, device_get),
            .set_extra_primitive_overestimation_size_ext = pfn<"vkCmdSetExtraPrimitiveOverestimationSizeEXT">(instance, device, device_get),
            .set_depth_clip_enable_ext = pfn<"vkCmdSetDepthClipEnableEXT">(instance, device, device_get),
            .set_sample_locations_enable_ext = pfn<"vkCmdSetSampleLocationsEnableEXT">(instance, device, device_get),
            .set_color_blend_advanced_ext = pfn<"vkCmdSetColorBlendAdvancedEXT">(instance, device, device_get),
            .set_provoking_vertex_mode_ext = pfn<"vkCmdSetProvokingVertexModeEXT">(instance, device, device_get),
            .set_line_rasterization_mode_ext = pfn<"vkCmdSetLineRasterizationModeEXT">(instance, device, device_get),
            .set_line_stipple_enable_ext = pfn<"vkCmdSetLineStippleEnableEXT">(instance, device, device_get),
            .set_depth_clip_negative_one_to_one_ext = pfn<"vkCmdSetDepthClipNegativeOneToOneEXT">(instance, device, device_get),
            .set_viewport_w_scaling_enable_nv = pfn<"vkCmdSetViewportWScalingEnableNV">(instance, device, device_get),
            .set_viewport_swizzle_nv = pfn<"vkCmdSetViewportSwizzleNV">(instance, device, device_get),
            .set_coverage_to_color_enable_nv = pfn<"vkCmdSetCoverageToColorEnableNV">(instance, device, device_get),
            .set_coverage_to_color_location_nv = pfn<"vkCmdSetCoverageToColorLocationNV">(instance, device, device_get),
            .set_coverage_modulation_mode_nv = pfn<"vkCmdSetCoverageModulationModeNV">(instance, device, device_get),
            .set_coverage_modulation_table_enable_nv = pfn<"vkCmdSetCoverageModulationTableEnableNV">(instance, device, device_get),
            .set_coverage_modulation_table_nv = pfn<"vkCmdSetCoverageModulationTableNV">(instance, device, device_get),
            .set_shading_rate_image_enable_nv = pfn<"vkCmdSetShadingRateImageEnableNV">(instance, device, device_get),
            .set_representative_fragment_test_enable_nv = pfn<"vkCmdSetRepresentativeFragmentTestEnableNV">(instance, device, device_get),
            .set_coverage_reduction_mode_nv = pfn<"vkCmdSetCoverageReductionModeNV">(instance, device, device_get),

        },
#endif // defined(VK_EXT_extended_dynamic_state3)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
