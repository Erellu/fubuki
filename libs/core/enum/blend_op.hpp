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

#ifndef FUBUKI_CORE_ENUM_BLEND_OP_HPP
#define FUBUKI_CORE_ENUM_BLEND_OP_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_0)

/// Returns a std::string_view corresponding to a VkBlendOp.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkBlendOp e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_ADD);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SUBTRACT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_REVERSE_SUBTRACT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_MIN);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_MAX);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_ZERO_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SRC_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_DST_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SRC_OVER_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_DST_OVER_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SRC_IN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_DST_IN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SRC_OUT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_DST_OUT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SRC_ATOP_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_DST_ATOP_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_XOR_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_MULTIPLY_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SCREEN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_OVERLAY_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_DARKEN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_LIGHTEN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_COLORDODGE_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_COLORBURN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_HARDLIGHT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_SOFTLIGHT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_DIFFERENCE_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_EXCLUSION_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_INVERT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_INVERT_RGB_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_LINEARDODGE_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_LINEARBURN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_VIVIDLIGHT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_LINEARLIGHT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_PINLIGHT_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_HARDMIX_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_HSL_HUE_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_HSL_SATURATION_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_HSL_COLOR_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_HSL_LUMINOSITY_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_PLUS_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_PLUS_CLAMPED_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_PLUS_DARKER_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_MINUS_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_MINUS_CLAMPED_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_CONTRAST_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_INVERT_OVG_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_RED_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_GREEN_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced) 
        FUBUKI_MAKE_CASE(VK_BLEND_OP_BLUE_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

        FUBUKI_MAKE_CASE(VK_BLEND_OP_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkBlendOp.
[[nodiscard]] inline auto to_string(VkBlendOp e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_0)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_BLEND_OP_HPP
