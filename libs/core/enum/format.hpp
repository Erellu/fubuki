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

#ifndef FUBUKI_CORE_ENUM_FORMAT_HPP
#define FUBUKI_CORE_ENUM_FORMAT_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_0)

/// Returns a std::string_view corresponding to a VkFormat.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkFormat e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_UNDEFINED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R4G4_UNORM_PACK8);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R4G4B4A4_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B4G4R4A4_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R5G6B5_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B5G6R5_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R5G5B5A1_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B5G5R5A1_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A1R5G5B5_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8_SRGB);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8_SRGB);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8_SRGB);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8_SRGB);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8A8_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8A8_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8A8_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8A8_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8A8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8A8_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R8G8B8A8_SRGB);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8A8_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8A8_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8A8_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8A8_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8A8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8A8_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8A8_SRGB);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8B8G8R8_UNORM_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8B8G8R8_SNORM_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8B8G8R8_USCALED_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8B8G8R8_SSCALED_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8B8G8R8_UINT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8B8G8R8_SINT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8B8G8R8_SRGB_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2R10G10B10_UNORM_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2R10G10B10_SNORM_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2R10G10B10_USCALED_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2R10G10B10_SSCALED_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2R10G10B10_UINT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2R10G10B10_SINT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2B10G10R10_UNORM_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2B10G10R10_SNORM_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2B10G10R10_USCALED_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2B10G10R10_SSCALED_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2B10G10R10_UINT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A2B10G10R10_SINT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16A16_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16A16_SNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16A16_USCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16A16_SSCALED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16A16_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16A16_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16B16A16_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32B32_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32B32_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32B32_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32B32A32_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32B32A32_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R32G32B32A32_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64B64_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64B64_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64B64_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64B64A64_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64B64A64_SINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R64G64B64A64_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B10G11R11_UFLOAT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_D16_UNORM);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_X8_D24_UNORM_PACK32);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_D32_SFLOAT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_S8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_D16_UNORM_S8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_D24_UNORM_S8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_D32_SFLOAT_S8_UINT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC1_RGB_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC1_RGB_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC1_RGBA_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC1_RGBA_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC2_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC2_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC3_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC3_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC4_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC4_SNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC5_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC5_SNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC6H_UFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC6H_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC7_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_BC7_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_EAC_R11_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_EAC_R11_SNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_EAC_R11G11_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_EAC_R11G11_SNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x4_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x4_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x5_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x5_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x5_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x5_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x6_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x6_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x8_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x8_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x5_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x5_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x6_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x6_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x8_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x8_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x10_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x10_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x10_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x10_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x12_UNORM_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x12_SRGB_BLOCK);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G8B8G8R8_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8G8_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8R8_2PLANE_420_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8R8_2PLANE_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R10X6_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R10X6G10X6_UNORM_2PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R12X4_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R12X4G12X4_UNORM_2PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G16B16G16R16_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_B16G16R16G16_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16R16_2PLANE_420_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16R16_2PLANE_422_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8R8_2PLANE_444_UNORM);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16R16_2PLANE_444_UNORM);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A4R4G4B4_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A4B4G4R4_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A1B5G5R5_UNORM_PACK16);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_FORMAT_A8_UNORM);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_IMG_format_pvrtc) 
        FUBUKI_MAKE_CASE(VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG);
#endif // #if defined (VK_IMG_format_pvrtc)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_EXT_texture_compression_astc_hdr) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_texture_compression_astc_hdr)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G8B8G8R8_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_B8G8R8G8_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_R10X6_UNORM_PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_R12X4_UNORM_PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G16B16G16R16_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_B16G16R16G16_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_3x3x3_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_3x3x3_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_3x3x3_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x3x3_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x3x3_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x3x3_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4x3_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4x3_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4x3_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4x4_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4x4_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_4x4x4_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x4x4_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x4x4_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x4x4_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5x4_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5x4_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5x4_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5x5_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5x5_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_5x5x5_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x5x5_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x5x5_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x5x5_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6x5_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6x5_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6x5_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6x6_UNORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6x6_SRGB_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_extension_289) 
        FUBUKI_MAKE_CASE(VK_FORMAT_ASTC_6x6x6_SFLOAT_BLOCK_EXT);
#endif // #if defined (VK_EXT_extension_289)

#if defined(VK_EXT_ycbcr_2plane_444_formats) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT);
#endif // #if defined (VK_EXT_ycbcr_2plane_444_formats)

#if defined(VK_EXT_ycbcr_2plane_444_formats) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT);
#endif // #if defined (VK_EXT_ycbcr_2plane_444_formats)

#if defined(VK_EXT_ycbcr_2plane_444_formats) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT);
#endif // #if defined (VK_EXT_ycbcr_2plane_444_formats)

#if defined(VK_EXT_ycbcr_2plane_444_formats) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT);
#endif // #if defined (VK_EXT_ycbcr_2plane_444_formats)

#if defined(VK_EXT_4444_formats) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT);
#endif // #if defined (VK_EXT_4444_formats)

#if defined(VK_EXT_4444_formats) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT);
#endif // #if defined (VK_EXT_4444_formats)

#if defined(VK_NV_optical_flow) 
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_SFIXED5_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow) && !(defined(VK_NV_optical_flow))
        FUBUKI_MAKE_CASE(VK_FORMAT_R16G16_S10_5_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_KHR_maintenance5) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR);
#endif // #if defined (VK_KHR_maintenance5)

#if defined(VK_KHR_maintenance5) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_FORMAT_A8_UNORM_KHR);
#endif // #if defined (VK_KHR_maintenance5)

        FUBUKI_MAKE_CASE(VK_FORMAT_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkFormat.
[[nodiscard]] inline auto to_string(VkFormat e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_0)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_FORMAT_HPP
