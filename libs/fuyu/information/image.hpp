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

#ifndef FUBUKI_FUYU_INFORMATION_IMAGE_HPP
#define FUBUKI_FUYU_INFORMATION_IMAGE_HPP

#include <functional>
#include <optional>
#include <string>

#include <core/compare/extent3d.hpp>
#include <core/handle.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"
#include "fuyu/sharing_mode.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::image.
/// @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkImageCreateInfo.html
struct image
{
    using underlying_type = VkImageCreateInfo;

    VkImageCreateFlags flags = {}; ///< Image flags.
    VkImageType        type
        = {}; ///< The basic dimensionality of the image. Layers in array textures do not count as a dimension for the purposes of the image type.
    VkFormat              format         = {}; ///< The format and type of the texel blocks that will be contained in the image.
    VkExtent3D            extent         = {}; ///< The number of data elements in each dimension of the base level.
    std::uint32_t         mip_levels     = {}; ///< The number of levels of detail available for minified sampling of the image.
    std::uint32_t         array_layers   = {}; ///< The number of layers in the image.
    VkSampleCountFlagBits samples        = {}; ///< The number of samples per texel.
    VkImageTiling         tiling         = {}; ///< The tiling arrangement of the texel blocks in memory.
    VkImageUsageFlags     usage          = {}; ///< The intended usage of the image.
    sharing_mode::any     sharing_mode   = {}; ///< Sharing mode of the image when it will be accessed by multiple queue families.
    VkImageLayout         initial_layout = {}; ///< Initial layout in which the image is created.

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const image& a, const image& b) noexcept
    {
        // Required to be explicitly implemented to bring fubuki::operator== in the current scope
        // Clang and GCC do this automagically, MSVC doesn't

        // clang-format off
        return (a.flags == b.flags)
                and (a.type == b.type)
                and (a.format == b.format)
                and (a.extent == b.extent)
                and (a.mip_levels == b.mip_levels)
                and (a.array_layers == b.array_layers)
                and (a.samples == b.samples)
                and (a.tiling == b.tiling)
                and (a.usage == b.usage)
                and (a.sharing_mode == b.sharing_mode)
                and (a.initial_layout == b.initial_layout)
                and (a.callbacks == b.callbacks)
                and (a.name == b.name);
        // clang-format on
    }
    [[nodiscard]] friend constexpr bool operator!=(const image& a, const image& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const image> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                 = structure_type_v<underlying_type>,
            .pNext                 = {},
            .flags                 = s.flags,
            .imageType             = s.type,
            .format                = s.format,
            .extent                = s.extent,
            .mipLevels             = s.mip_levels,
            .arrayLayers           = s.array_layers,
            .samples               = s.samples,
            .tiling                = s.tiling,
            .usage                 = s.usage,
            .sharingMode           = to_underlying(s.sharing_mode),
            .queueFamilyIndexCount = queue_count(s.sharing_mode),
            .pQueueFamilyIndices   = queue_data(s.sharing_mode),
            .initialLayout         = s.initial_layout,
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_IMAGE_HPP
