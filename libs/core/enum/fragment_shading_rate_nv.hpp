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

#ifndef FUBUKI_CORE_ENUM_FRAGMENT_SHADING_RATE_NV_HPP
#define FUBUKI_CORE_ENUM_FRAGMENT_SHADING_RATE_NV_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_NV_fragment_shading_rate_enums)

/// Returns a std::string_view corresponding to a VkFragmentShadingRateNV.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkFragmentShadingRateNV e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums) 
        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

        FUBUKI_MAKE_CASE(VK_FRAGMENT_SHADING_RATE_MAX_ENUM_NV);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkFragmentShadingRateNV.
[[nodiscard]] inline auto to_string(VkFragmentShadingRateNV e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_NV_fragment_shading_rate_enums)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_FRAGMENT_SHADING_RATE_NV_HPP
