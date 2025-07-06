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

#ifndef FUBUKI_TEST_FUYU_RESOURCES_FOR_SWAPCHAIN_HPP
#define FUBUKI_TEST_FUYU_RESOURCES_FOR_SWAPCHAIN_HPP

#include <source_location>

#include <fuyu/information/swapchain.hpp>
#include <fuyu/render_pass.hpp>
#include <fuyu/surface.hpp>
#include <io/display.hpp>
#include <io/window.hpp>

namespace fubuki::test
{

struct resources_for_swapchain
{
    fubuki::io::display      display;
    fubuki::io::window       window;
    fuyu::surface            surface;
    fuyu::surface_properties surface_properties;

    [[nodiscard]] static std::expected<resources_for_swapchain, fubuki::api_call_info> make(std::reference_wrapper<const fuyu::instance> instance,
                                                                                            physical_device_handle physical_device) noexcept
    {
        constexpr auto transform = [](const auto& i) noexcept -> api_call_info
        { return api_call_info{.result = {}, .call_literal = i.call_literal(), .location = i.location()}; };

        auto dp = fubuki::io::display::make();

        if(not dp)
        {
            return std::unexpected{transform(dp.error())};
        }

        auto w = fubuki::io::window::make(
            *dp,
            {
                .title = "", .size = {512, 512},
                     .coordinates = {0,   0  },
                     .opacity = 0.f, .style = fubuki::io::window_style::os_default
        });

        if(not w)
        {
            return std::unexpected{transform(dp.error())};
        }

        std::ignore = w->hide();

        auto surface = fuyu::surface::make(instance, *w);

        if(not surface)
        {
            return std::unexpected{surface.error()};
        }

        auto surface_properties = fuyu::properties(physical_device, *surface);

        if(not surface_properties)
        {
            return std::unexpected{surface_properties.error()};
        }

        return resources_for_swapchain{*std::move(dp), *std::move(w), *std::move(surface), *std::move(surface_properties)};
    }

    [[nodiscard]] static std::expected<fuyu::render_pass, api_call_info> make_compatible_render_pass(fuyu::device_cref              device,
                                                                                                     const resources_for_swapchain& rc) noexcept
    {
        return fuyu::render_pass::make(
            device,
            {
                .flags                  = {},
                .attachments            = {{.flags          = {},
                                            .format         = rc.surface_properties.formats.front().format,
                                            .samples        = VK_SAMPLE_COUNT_1_BIT,
                                            .loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR,
                                            .storeOp        = VK_ATTACHMENT_STORE_OP_STORE,
                                            .stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_CLEAR,
                                            .stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE,
                                            .initialLayout  = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
                                            .finalLayout    = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL}},
                .subpasses              = {{
                                 .flags       = {},
                                 .bind_point  = VK_PIPELINE_BIND_POINT_GRAPHICS,
                                 .attachments = {.input         = {},
                                                 .colour        = {{.attachment = 0, .layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL}},
                                                 .resolve       = {},
                                                 .depth_stencil = {},
                                                 .preserve      = {}},
                }},
                .subpasses_dependencies = {{
                    .source           = {.subpass = fuyu::subpass::dependency::stage::external, .stage_mask = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT},
                    .destination      = {.subpass = 0, .stage_mask = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT},
                    .dependency_flags = {},
                }},
            });
    }
};

[[nodiscard]] inline fuyu::information::swapchain make_swapchain_info(const fuyu::surface_properties& surface_properties,
                                                                      std::optional<std::string>      name = {}) noexcept
{
    return {
        .flags   = {},
        .image   = {.minimum_count = surface_properties.capabilities.minImageCount + 1,
                    .format        = surface_properties.formats.front().format,
                    .colour_space  = surface_properties.formats.front().colorSpace,
                    .extent        = surface_properties.capabilities.currentExtent,
                    .array_layers  = 1,
                    .usage         = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT},
        .present = {.mode = surface_properties.present_modes.front()},
        .name    = std::move(name),
    };
}

[[nodiscard]] inline fuyu::information::swapchain make_swapchain_info(const fuyu::surface_properties& surface_properties,
                                                                      std::source_location            s = std::source_location::current()) noexcept
{
    return make_swapchain_info(surface_properties, std::string{s.file_name()} + " at l. " + std::to_string(s.line()));
}

[[nodiscard]] inline fuyu::information::swapchain make_swapchain_info(const resources_for_swapchain& rc,
                                                                      std::optional<std::string>     name = {}) noexcept
{
    return make_swapchain_info(rc.surface_properties, std::move(name));
}

[[nodiscard]] inline fuyu::information::swapchain make_swapchain_info(const resources_for_swapchain& rc,
                                                                      std::source_location           s = std::source_location::current()) noexcept
{
    return make_swapchain_info(rc.surface_properties, s);
}

} // namespace fubuki::test

#endif // FUBUKI_TEST_FUYU_RESOURCES_FOR_SWAPCHAIN_HPP
