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

#ifndef FUBUKI_FUYU_RENDERING_AREA_HPP
#define FUBUKI_FUYU_RENDERING_AREA_HPP

#include <core/collect.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu
{

/**
 * Structure describing rendering area granularity query info.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkRenderingAreaInfo.html
 */
struct rendering_area
{
#if defined(VK_VERSION_1_4)
    using underlying_type = VkRenderingAreaInfo;
#endif // defined(VK_VERSION_1_4)

    small_vector<VkFormat> colour    = {};
    VkFormat               depth     = {};
    VkFormat               stencil   = {};
    std::uint32_t          view_mask = {};

    [[nodiscard]] friend constexpr bool operator==(const rendering_area& a, const rendering_area& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const rendering_area& a, const rendering_area& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const rendering_area& a, const rendering_area& b) noexcept = default;

#if defined(VK_VERSION_1_4)
    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const rendering_area> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                   = structure_type_v<underlying_type>,
            .pNext                   = {},
            .viewMask                = s.view_mask,
            .colorAttachmentCount    = vk_size(s.colour),
            .pColorAttachmentFormats = s.colour.data(),
            .depthAttachmentFormat   = s.depth,
            .stencilAttachmentFormat = s.stencil,
        };
    }
#endif // defined(VK_VERSION_1_4)
};

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_RENDERING_AREA_HPP
