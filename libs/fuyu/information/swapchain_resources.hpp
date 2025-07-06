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

#ifndef FUBUKI_FUYU_INFORMATION_SWAPCHAIN_RESOURCES_HPP
#define FUBUKI_FUYU_INFORMATION_SWAPCHAIN_RESOURCES_HPP

#include <ostream>
#include <variant>

#include <core/compare/component_mapping.hpp>
#include <core/compare/extent2d.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/render_pass.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::swapchain_resources.
struct swapchain_resources
{
    /// Tag struct indicating render targets are obtained through render passes (VkRenderPass) rendering to framebuffers (VkFrameBuffer).
    /// An instance of fuyu::framebuffer is created for each swapchain image.
    struct render_pass
    {
        /// Render pass to use for the framebuffers.
        /// If an existing handle is specified, then it is used as a parent to the framebuffers.
        /// If an instance of fubuki::fuyu::information::render_pass is specified, then a render pass is created as part of the swapchain resources.
        std::variant<render_pass_handle, information::render_pass> source = {};

        friend constexpr bool operator==(const render_pass&, const render_pass&) noexcept = default;
        friend constexpr bool operator!=(const render_pass&, const render_pass&) noexcept = default;

        template<typename char_type, typename traits = std::char_traits<char_type> >
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const render_pass& r)
        {
            out << "fubuki::fuyu::information::swapchain_resources::render_pass{";

            if(const auto* const handle = std::get_if<render_pass_handle>(std::addressof(r.source)))
            {
                out << "handle: " << handle->vk;
            }
            else if(/*const auto* const info = */ std::get_if<information::render_pass>(std::addressof(r.source)))
            {
                out << "info: " << "{}";
            }

            return out << "}";
        }
    };

    /// Tag struct indicating render targets are obtained through dynamic rendering.
    /// No framebuffer is created.
    struct dynamic_rendering
    {
        friend constexpr bool operator==(const dynamic_rendering&, const dynamic_rendering&) noexcept  = default;
        friend constexpr bool operator!=(const dynamic_rendering&, const dynamic_rendering&) noexcept  = default;
        friend constexpr auto operator<=>(const dynamic_rendering&, const dynamic_rendering&) noexcept = default;

        template<typename char_type, typename traits = std::char_traits<char_type> >
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const dynamic_rendering&)
        {
            return out << "fubuki::fuyu::information::swapchain_resources::dynamic_rendering{}";
        }
    };

    struct any_render_target
    {
        using value_type = std::variant<render_pass, dynamic_rendering>;

        value_type value;

        friend constexpr bool operator==(const any_render_target&, const any_render_target&) noexcept = default;
        friend constexpr bool operator!=(const any_render_target&, const any_render_target&) noexcept = default;

        template<typename char_type, typename traits = std::char_traits<char_type> >
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const any_render_target& t)
        {
            return std::visit([&out](const auto& v) -> std::basic_ostream<char_type, traits>& { return out << v; }, t.value);
        }
    };

    /// Indicates how the render targets are specified.
    /// If not specified, a framebuffer is created for each image.
    /// When using dynamic rendering, use swapchain_resources::dynamic_rendering{}.
    any_render_target render_target;

    friend constexpr bool operator==(const swapchain_resources&, const swapchain_resources&) noexcept = default;
    friend constexpr bool operator!=(const swapchain_resources&, const swapchain_resources&) noexcept = default;
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_SWAPCHAIN_RESOURCES_HPP
