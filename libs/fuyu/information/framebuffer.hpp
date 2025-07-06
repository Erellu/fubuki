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

#ifndef FUBUKI_FUYU_INFORMATION_FRAMEBUFFER_HPP
#define FUBUKI_FUYU_INFORMATION_FRAMEBUFFER_HPP

#include <functional>
#include <optional>
#include <string>

#include <core/collect.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to construct an instance of fuyu::framebuffer.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkFramebufferCreateInfo.html
struct framebuffer
{
    using underlying_type = VkFramebufferCreateInfo;

    VkFramebufferCreateFlags        flags       = {}; ///< Framebuffer flags.
    small_vector<image_view_handle> attachments = {}; ///< Attachments used by this framebuffer.

    std::uint32_t width  = 1u; ///< Width of the framebuffer.
    std::uint32_t height = 1u; ///< Height of the framebuffer.
    std::uint32_t layers = 1u; ///< Number of layers for this framebuffer.

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const framebuffer& a, const framebuffer& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const framebuffer& a, const framebuffer& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type
    to_underlying(std::reference_wrapper<const framebuffer> cref, render_pass_handle pass, std::span<const VkImageView> vk_attachments) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType           = structure_type_v<VkFramebufferCreateInfo>,
            .pNext           = {},
            .flags           = s.flags,
            .renderPass      = pass.vk,
            .attachmentCount = vk_size(vk_attachments),
            .pAttachments    = vk_attachments.data(),
            .width           = s.width,
            .height          = s.height,
            .layers          = s.layers,
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_FRAMEBUFFER_HPP
