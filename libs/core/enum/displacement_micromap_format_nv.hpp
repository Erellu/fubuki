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

#ifndef FUBUKI_CORE_ENUM_DISPLACEMENT_MICROMAP_FORMAT_NV_HPP
#define FUBUKI_CORE_ENUM_DISPLACEMENT_MICROMAP_FORMAT_NV_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_NV_displacement_micromap)

/// Returns a std::string_view corresponding to a VkDisplacementMicromapFormatNV.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkDisplacementMicromapFormatNV e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_NV_displacement_micromap) 
        FUBUKI_MAKE_CASE(VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV);
#endif // #if defined (VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap) 
        FUBUKI_MAKE_CASE(VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV);
#endif // #if defined (VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap) 
        FUBUKI_MAKE_CASE(VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV);
#endif // #if defined (VK_NV_displacement_micromap)

        FUBUKI_MAKE_CASE(VK_DISPLACEMENT_MICROMAP_FORMAT_MAX_ENUM_NV);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkDisplacementMicromapFormatNV.
[[nodiscard]] inline auto to_string(VkDisplacementMicromapFormatNV e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_NV_displacement_micromap)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_DISPLACEMENT_MICROMAP_FORMAT_NV_HPP
