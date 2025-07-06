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

#ifndef FUBUKI_CORE_FORMAT_HPP
#define FUBUKI_CORE_FORMAT_HPP

#include <climits>
#include <cstddef>
#include <cstdint>
#include <optional>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>

// In such environnements, there will be mismatches between sizes for the GPU and CPU. Not taking risks.
// NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
static_assert(CHAR_BIT == 8, "Fubuki does not support systems for which a byte is not 8 bits.");

namespace fubuki
{

//------------------------------------------------------------------------------

struct format_description
{
    struct rgba
    {
        struct component
        {
            enum class numeric
            {
                unorm,
                snorm,
                uscaled,
                sscaled,
                sint,
                uint,
                sfloat,
                ufloat,
                srgb,
                sfixed5,
            };

            std::size_t                bits           = {}; ///< The size in bits.
            numeric                    numeric_format = {}; ///< The numeric format for this component.
            std::optional<std::size_t> plane_index    = {}; ///< The index of the plane for this component, or nullopt.
        };

        std::optional<component> r = {}; ///< How the R format is represented, or nullopt if there is none for this format.
        std::optional<component> g = {}; ///< How the G format is represented, or nullopt if there is none for this format.
        std::optional<component> b = {}; ///< How the B format is represented, or nullopt if there is none for this format.
        std::optional<component> a = {}; ///< How the A format is represented, or nullopt if there is none for this format.
    };

    struct plane
    {
        std::size_t width_divisor  = 1;  ///< The width divisor of this plane.
        std::size_t height_divisor = 1;  ///< The height divisor of this plane.
        VkFormat    compatible     = {}; ///< A format with which this plane is compatible.
    };

    VkFormat                                           format           = {}; ///< Format.
    std::size_t                                        block_size       = {}; ///< Texel block size in bytes.
    VkExtent3D                                         block_extent     = {}; ///< Texel block extent
    std::uint32_t                                      texels_per_block = {}; ///< Number of texels per blocks.
    rgba                                               components       = {}; ///< The components of the format.
    std::optional<std::uint32_t>                       chroma           = {}; ///< The chroma for planar formats, or nullopt for others.
    std::optional<std::size_t>                         packing          = {}; ///< The packing for packed formats, or nullopt for others.
    std::optional<std::array<std::optional<plane>, 3>> planes           = {}; ///< Information about the planes for planar formats, or nullopt.
};

//------------------------------------------------------------------------------

/// Returns information about the features supported by a device for a format.
FUBUKI_CORE_API
extern VkFormatProperties properties(physical_device_handle d, VkFormat f) noexcept;

//------------------------------------------------------------------------------

/// Returns information about a VkFormat.
[[nodiscard]]
inline constexpr format_description description(const VkFormat f) noexcept
{
    // See https://registry.khronos.org/vulkan/specs/1.3/html/chap34.html#formats-compatibility-classes
    // See also https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkFormat.html

    using enum format_description::rgba::component::numeric;

    format_description result;
    result.format = f;

    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, bugprone-branch-clone)
    // clang-format off
    switch(f)
    {

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R4G4_UNORM_PACK8):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {8};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R4G4B4A4_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B4G4R4A4_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R5G6B5_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 6, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B5G6R5_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 6, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R5G5B5A1_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 1, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B5G5R5A1_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 1, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A1R5G5B5_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 1, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_4)
        case(VK_FORMAT_A1B5G5R5_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 5, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 1, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
        case(VK_FORMAT_A8_UNORM):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8_UNORM):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8_SNORM):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8_USCALED):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8_SSCALED):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8_UINT):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8_SINT):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8_SRGB):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8_UNORM):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8_SNORM):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8_USCALED):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8_SSCALED):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8_UINT):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8_SINT):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8_SRGB):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8_SNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8_USCALED):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8_SSCALED):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8_UINT):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8_SINT):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8_SRGB):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8_SNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8_USCALED):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8_SSCALED):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8_UINT):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8_SINT):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8_SRGB):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8A8_UNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8A8_SNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8A8_USCALED):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8A8_SSCALED):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8A8_UINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8A8_SINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R8G8B8A8_SRGB):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8A8_UNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8A8_SNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8A8_USCALED):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8A8_SSCALED):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8A8_UINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8A8_SINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B8G8R8A8_SRGB):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A8B8G8R8_UNORM_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A8B8G8R8_SNORM_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = snorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A8B8G8R8_USCALED_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = uscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A8B8G8R8_SSCALED_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = sscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A8B8G8R8_UINT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A8B8G8R8_SINT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A8B8G8R8_SRGB_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 8, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2R10G10B10_UNORM_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2R10G10B10_SNORM_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = snorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2R10G10B10_USCALED_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = uscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2R10G10B10_SSCALED_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = sscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2R10G10B10_UINT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2R10G10B10_SINT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2B10G10R10_UNORM_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2B10G10R10_SNORM_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = snorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2B10G10R10_USCALED_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = uscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2B10G10R10_SSCALED_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = sscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2B10G10R10_UINT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_A2B10G10R10_SINT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 2, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16_UNORM):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16_SNORM):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16_USCALED):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16_SSCALED):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16_UINT):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16_SINT):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16_SFLOAT):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16_UNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16_SNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16_USCALED):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16_SSCALED):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16_UINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16_SINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16_SFLOAT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16_UNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16_SNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16_USCALED):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16_SSCALED):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16_UINT):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16_SINT):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16_SFLOAT):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16A16_UNORM):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16A16_SNORM):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.components.a     = {.bits = 16, .numeric_format = snorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16A16_USCALED):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.components.a     = {.bits = 16, .numeric_format = uscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16A16_SSCALED):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.components.a     = {.bits = 16, .numeric_format = sscaled, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16A16_UINT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 16, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16A16_SINT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 16, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R16G16B16A16_SFLOAT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 16, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32_UINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32_SINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32_SFLOAT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32_UINT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32_SINT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32_SFLOAT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32B32_UINT):
        {
            result.block_size       = 12;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32B32_SINT):
        {
            result.block_size       = 12;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32B32_SFLOAT):
        {
            result.block_size       = 12;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32B32A32_UINT):
        {
            result.block_size       = 16;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 32, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32B32A32_SINT):
        {
            result.block_size       = 16;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 32, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R32G32B32A32_SFLOAT):
        {
            result.block_size       = 16;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 32, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64_UINT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64_SINT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64_SFLOAT):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64_UINT):
        {
            result.block_size       = 16;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64_SINT):
        {
            result.block_size       = 16;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64_SFLOAT):
        {
            result.block_size       = 16;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64B64_UINT):
        {
            result.block_size       = 24;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64B64_SINT):
        {
            result.block_size       = 24;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64B64_SFLOAT):
        {
            result.block_size       = 24;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64B64A64_UINT):
        {
            result.block_size       = 32;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.b     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.components.a     = {.bits = 64, .numeric_format = uint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64B64A64_SINT):
        {
            result.block_size       = 32;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.b     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.components.a     = {.bits = 64, .numeric_format = sint, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_R64G64B64A64_SFLOAT):
        {
            result.block_size       = 32;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 64, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_B10G11R11_UFLOAT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 11, .numeric_format = ufloat, .plane_index={},};
            result.components.g     = {.bits = 11, .numeric_format = ufloat, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = ufloat, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 9, .numeric_format = ufloat, .plane_index={},};
            result.components.g     = {.bits = 9, .numeric_format = ufloat, .plane_index={},};
            result.components.b     = {.bits = 9, .numeric_format = ufloat, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_D16_UNORM):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_X8_D24_UNORM_PACK32):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {32};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_D32_SFLOAT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_S8_UINT):
        {
            result.block_size       = 1;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_D16_UNORM_S8_UINT):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_D24_UNORM_S8_UINT):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_D32_SFLOAT_S8_UINT):
        {
            result.block_size       = 5;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC1_RGB_UNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC1_RGB_SRGB_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC1_RGBA_UNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC1_RGBA_SRGB_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC2_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC2_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC3_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC3_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC4_UNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC4_SNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC5_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC5_SNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC6H_UFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = ufloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = ufloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = ufloat, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC6H_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC7_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_BC7_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_EAC_R11_UNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 11, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_EAC_R11_SNORM_BLOCK):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 11, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_EAC_R11G11_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 11, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 11, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_EAC_R11G11_SNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 11, .numeric_format = snorm, .plane_index={},};
            result.components.g     = {.bits = 11, .numeric_format = snorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_4x4_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_4x4_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_5x4_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {5, 4, 1};
            result.texels_per_block = 20;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_5x4_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {5, 4, 1};
            result.texels_per_block = 20;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_5x5_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {5, 5, 1};
            result.texels_per_block = 25;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_5x5_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {5, 5, 1};
            result.texels_per_block = 25;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_6x5_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {6, 5, 1};
            result.texels_per_block = 30;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_6x5_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {6, 5, 1};
            result.texels_per_block = 30;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_6x6_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {6, 6, 1};
            result.texels_per_block = 36;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_6x6_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {6, 6, 1};
            result.texels_per_block = 36;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_8x5_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 5, 1};
            result.texels_per_block = 40;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_8x5_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 5, 1};
            result.texels_per_block = 40;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_8x6_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 6, 1};
            result.texels_per_block = 48;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_8x6_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 6, 1};
            result.texels_per_block = 48;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_8x8_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 8, 1};
            result.texels_per_block = 64;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_8x8_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 8, 1};
            result.texels_per_block = 64;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x5_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 5, 1};
            result.texels_per_block = 50;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x5_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 5, 1};
            result.texels_per_block = 50;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x6_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 6, 1};
            result.texels_per_block = 60;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x6_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 6, 1};
            result.texels_per_block = 60;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x8_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 8, 1};
            result.texels_per_block = 80;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x8_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 8, 1};
            result.texels_per_block = 80;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x10_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 10, 1};
            result.texels_per_block = 100;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_10x10_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 10, 1};
            result.texels_per_block = 100;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_12x10_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {12, 10, 1};
            result.texels_per_block = 120;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_12x10_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {12, 10, 1};
            result.texels_per_block = 120;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_12x12_UNORM_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {12, 12, 1};
            result.texels_per_block = 144;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_0)
        case(VK_FORMAT_ASTC_12x12_SRGB_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {12, 12, 1};
            result.texels_per_block = 144;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_0)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G8B8G8R8_422_UNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_B8G8R8G8_422_UNORM):
        {
            result.block_size       = 4;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R8_UNORM,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G8_B8R8_2PLANE_420_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R8G8_UNORM,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G8_B8R8_2PLANE_422_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R8G8_UNORM,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_R10X6_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_R10X6G10X6_UNORM_2PACK16):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {444};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16):
        {
            result.block_size       = 8;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16):
        {
            result.block_size       = 8;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R10X6G10X6_UNORM_2PACK16,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R10X6G10X6_UNORM_2PACK16,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_R12X4_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_R12X4G12X4_UNORM_2PACK16):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16):
        {
            result.block_size       = 8;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {444};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16):
        {
            result.block_size       = 8;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16):
        {
            result.block_size       = 8;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R12X4G12X4_UNORM_2PACK16,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R12X4G12X4_UNORM_2PACK16,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G16B16G16R16_422_UNORM):
        {
            result.block_size       = 8;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_B16G16R16G16_422_UNORM):
        {
            result.block_size       = 8;
            result.block_extent     = {2, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R16_UNORM,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G16_B16R16_2PLANE_420_UNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {420};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 2, .compatible = VK_FORMAT_R16G16_UNORM,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G16_B16R16_2PLANE_422_UNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {422};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 2, .height_divisor = 1, .compatible = VK_FORMAT_R16G16_UNORM,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
        case(VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index=2,};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {8, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {8, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {8, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {8, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG):
        {
            result.block_size       = 8;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = srgb, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_IMG_format_pvrtc)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {4, 4, 1};
            result.texels_per_block = 16;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {5, 4, 1};
            result.texels_per_block = 20;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {5, 5, 1};
            result.texels_per_block = 25;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {6, 5, 1};
            result.texels_per_block = 30;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {6, 6, 1};
            result.texels_per_block = 36;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 5, 1};
            result.texels_per_block = 40;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 6, 1};
            result.texels_per_block = 48;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {8, 8, 1};
            result.texels_per_block = 64;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 5, 1};
            result.texels_per_block = 50;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 6, 1};
            result.texels_per_block = 60;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 8, 1};
            result.texels_per_block = 80;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {10, 10, 1};
            result.texels_per_block = 100;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {12, 10, 1};
            result.texels_per_block = 120;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK):
        {
            result.block_size       = 16;
            result.block_extent     = {12, 12, 1};
            result.texels_per_block = 144;
            result.components.r     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.g     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.b     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.components.a     = {.bits = 0, .numeric_format = sfloat, .plane_index={},};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_G8_B8R8_2PLANE_444_UNORM):
        {
            result.block_size       = 3;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 8, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 8, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8_UNORM,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R8G8_UNORM,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 10, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 10, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6_UNORM_PACK16,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R10X6G10X6_UNORM_2PACK16,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 12, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 12, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {16};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4_UNORM_PACK16,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R12X4G12X4_UNORM_2PACK16,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_G16_B16R16_2PLANE_444_UNORM):
        {
            result.block_size       = 6;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.g     = {.bits = 16, .numeric_format = unorm, .plane_index=0,};
            result.components.b     = {.bits = 16, .numeric_format = unorm, .plane_index=1,};
            result.components.a     = {};
            result.chroma           = {444};
            result.packing          = {};
            result.planes           = 
            {
                {
                    {
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16_UNORM,}},
                        {{.width_divisor = 1, .height_divisor = 1, .compatible = VK_FORMAT_R16G16_UNORM,}},
                        {},
                    }
                }
            };
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_A4R4G4B4_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_3)
        case(VK_FORMAT_A4B4G4R4_UNORM_PACK16):
        {
            result.block_size       = 2;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.g     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.b     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.components.a     = {.bits = 4, .numeric_format = unorm, .plane_index={},};
            result.chroma           = {};
            result.packing          = {16};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_optical_flow)
        case(VK_FORMAT_R16G16_SFIXED5_NV):
        {
            result.block_size       = 4;
            result.block_extent     = {1, 1, 1};
            result.texels_per_block = 1;
            result.components.r     = {.bits = 16, .numeric_format = sfixed5, .plane_index={},};
            result.components.g     = {.bits = 16, .numeric_format = sfixed5, .plane_index={},};
            result.components.b     = {};
            result.components.a     = {};
            result.chroma           = {};
            result.packing          = {};
            result.planes           = {};
            break;
        }
    #endif // #if defined(VK_NV_optical_flow)


            //---------------------------------------
            // Invalid values

        default:
        case(VK_FORMAT_UNDEFINED):
        case(VK_FORMAT_MAX_ENUM):
        {
            break;
        }
    }
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, bugprone-branch-clone)
    // clang-format on
    return result;
}

} // namespace fubuki

#endif // FUBUKI_CORE_FORMAT_HPP
