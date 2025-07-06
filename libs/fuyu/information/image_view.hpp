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

#ifndef FUBUKI_FUYU_INFORMATION_IMAGE_VIEW_HPP
#define FUBUKI_FUYU_INFORMATION_IMAGE_VIEW_HPP

#include <functional>
#include <optional>
#include <string>

#include <core/compare/component_mapping.hpp>
#include <core/compare/image_subresource_range.hpp>
#include <core/handle.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::image_view.
/// @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkImageViewCreateInfo.html
struct image_view
{
    using underlying_type = VkImageViewCreateInfo;

    VkImageViewCreateFlags flags      = {}; ///< Bitmask of VkImageViewCreateFlagBits specifying additional parameters of the image view.
    VkImageViewType        type       = {}; ///< Type of the image view.
    VkFormat               format     = {}; ///< Format of the image view.
    VkComponentMapping     components = {}; ///< Remapping of colour components.

    /// Selection of the set of mipmap levels and array layers to be accessible to the view.
    VkImageSubresourceRange subresource_range = {}; // NOTE: this is an invalid value. This MUST be overriden

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const image_view& a, const image_view& b) noexcept
    {
        // Required to be explicitly implemented to bring fubuki::operator== in the current scope
        // Clang and GCC do this automagically, MSVC doesn't

        return (a.flags == b.flags) and (a.type == b.type) and (a.format == b.format) and (a.components == b.components)
            and (a.subresource_range == b.subresource_range) and (a.callbacks == b.callbacks) and (a.name == b.name);
    }

    [[nodiscard]] friend constexpr bool operator!=(const image_view& a, const image_view& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const image_view> cref, image_handle image) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType            = structure_type_v<underlying_type>,
            .pNext            = nullptr,
            .flags            = s.flags,
            .image            = image.vk,
            .viewType         = s.type,
            .format           = s.format,
            .components       = s.components,
            .subresourceRange = s.subresource_range,
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_IMAGE_VIEW_HPP
