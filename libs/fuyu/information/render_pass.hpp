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

#ifndef FUBUKI_FUYU_INFORMATION_RENDER_PASS_HPP
#define FUBUKI_FUYU_INFORMATION_RENDER_PASS_HPP

#include <functional>
#include <optional>
#include <string>

#include <core/collect.hpp>
#include <core/compare/attachment_description.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>

#include "fuyu/information/callbacks.hpp"
#include "fuyu/subpass.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::render_pass.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkRenderPassCreateInfo.html
struct render_pass
{
    using underlying_type = VkRenderPassCreateInfo;

    VkRenderPassCreateFlags               flags                  = {};
    small_vector<VkAttachmentDescription> attachments            = {};
    small_vector<subpass>                 subpasses              = {};
    small_vector<subpass::dependency>     subpasses_dependencies = {};

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const render_pass& a, const render_pass& b) noexcept
    {
        // Required because we have operator== for Vulkan structures in namespace fubuki (so they can't be used through the facilities of the
        // Standard Library)
        constexpr auto compare = [](const VkAttachmentDescription& x, const VkAttachmentDescription& y) constexpr noexcept { return x == y; };

        return (a.flags == b.flags) and (std::ranges::equal(a.attachments, b.attachments, compare)) and (a.subpasses == b.subpasses)
            and (a.subpasses_dependencies == b.subpasses_dependencies) and (a.callbacks == b.callbacks) and (a.name == b.name);
    }

    [[nodiscard]] friend constexpr bool operator!=(const render_pass& a, const render_pass& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const render_pass> cref,
                                                                 std::span<const VkSubpassDescription>     passes,
                                                                 std::span<const VkSubpassDependency>      deps) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();
        return {
            .sType           = structure_type_v<underlying_type>,
            .pNext           = {},
            .flags           = s.flags,
            .attachmentCount = vk_size(s.attachments),
            .pAttachments    = s.attachments.data(),
            .subpassCount    = vk_size(passes),
            .pSubpasses      = passes.data(),
            .dependencyCount = vk_size(deps),
            .pDependencies   = deps.data(),
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_RENDER_PASS_HPP
