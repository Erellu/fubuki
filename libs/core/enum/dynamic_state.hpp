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

#ifndef FUBUKI_CORE_ENUM_DYNAMIC_STATE_HPP
#define FUBUKI_CORE_ENUM_DYNAMIC_STATE_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_0)

/// Returns a std::string_view corresponding to a VkDynamicState.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkDynamicState e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_SCISSOR);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LINE_WIDTH);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_BIAS);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_BLEND_CONSTANTS);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_BOUNDS);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_STENCIL_WRITE_MASK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_STENCIL_REFERENCE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_CULL_MODE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_FRONT_FACE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_COMPARE_OP);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_STENCIL_OP);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LINE_STIPPLE);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_NV_clip_space_w_scaling) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV);
#endif // #if defined (VK_NV_clip_space_w_scaling)

#if defined(VK_EXT_discard_rectangles) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT);
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT);
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT);
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_EXT_sample_locations) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT);
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_KHR_ray_tracing_pipeline) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR);
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_shading_rate_image) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV);
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV);
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_scissor_exclusive) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV);
#endif // #if defined (VK_NV_scissor_exclusive)

#if defined(VK_NV_scissor_exclusive) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV);
#endif // #if defined (VK_NV_scissor_exclusive)

#if defined(VK_KHR_fragment_shading_rate) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_EXT_line_rasterization) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LINE_STIPPLE_EXT);
#endif // #if defined (VK_EXT_line_rasterization)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_CULL_MODE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_FRONT_FACE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_COMPARE_OP_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_STENCIL_OP_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_vertex_input_dynamic_state) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VERTEX_INPUT_EXT);
#endif // #if defined (VK_EXT_vertex_input_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state2) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LOGIC_OP_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_color_write_enable) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT);
#endif // #if defined (VK_EXT_color_write_enable)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_POLYGON_MODE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_SAMPLE_MASK_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_attachment_feedback_loop_dynamic_state) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT);
#endif // #if defined (VK_EXT_attachment_feedback_loop_dynamic_state)

#if defined(VK_KHR_line_rasterization) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_LINE_STIPPLE_KHR);
#endif // #if defined (VK_KHR_line_rasterization)

#if defined(VK_EXT_depth_clamp_control) 
        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_DEPTH_CLAMP_RANGE_EXT);
#endif // #if defined (VK_EXT_depth_clamp_control)

        FUBUKI_MAKE_CASE(VK_DYNAMIC_STATE_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkDynamicState.
[[nodiscard]] inline auto to_string(VkDynamicState e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_0)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_DYNAMIC_STATE_HPP
