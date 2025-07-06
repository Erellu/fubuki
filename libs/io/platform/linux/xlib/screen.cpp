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

#include "io/platform/linux/xlib/screen.hpp"

#include "io/platform/linux/xlib/xrandr/crtc.hpp"
#include "io/platform/linux/xlib/xrandr/output.hpp"
#include "io/platform/linux/xlib/xrandr/screen_config.hpp"
#include "io/platform/linux/xlib/xrandr/screen_resource.hpp"

namespace fubuki::io::platform::linux_bsd::xlib::screen
{

[[nodiscard]] std::expected<small_vector<screen_properties, screen_properties::typical_monitor_count>, platform::error::api_call>
enumerate(views::display::xlib dp)
{
    if(dp.handle == nullptr)
    {
        return std::unexpected{error::api_call{call_info{.result = {}, .call_literal = "Invalid view: does not refer to a X11 display."}}};
    }

    // Based on https://stackoverflow.com/a/64494888, by https://stackoverflow.com/users/2089675/smac89
    // Code available under CC BY-SA 4.0

    small_vector<screen_properties, screen_properties::typical_monitor_count> result = {};

    auto rc = xrandr::screen_resource::make(dp.handle);

    if(not rc)
    {
        return std::unexpected{rc.error()};
    }

    auto current_config = xrandr::screen_config::make(dp.handle);

    if(not current_config)
    {
        return std::unexpected{current_config.error()};
    }

    for(const std::size_t output_idx : std::views::iota(0uz, static_cast<std::size_t>((*rc)->noutput)))
    {
        auto output = xrandr::output::make(*rc, output_idx);

        if(not output)
        {
            return std::unexpected{output.error()};
        }

        const auto output_modes = output->modes();

        if(output->handle() != nullptr and (*output)->connection == RR_Connected)
        {
            auto screen = screen_properties{
                .device         = static_cast<std::uint32_t>(output_idx),
                .name           = {output->handle()->name, static_cast<std::size_t>(output->handle()->nameLen)},
                .area           = {},
                .refresh_rate   = static_cast<std::uint32_t>(XRRConfigCurrentRate(current_config->handle())),
                .configurations = {},
            };

            for(const std::size_t config_idx : std::views::iota(0uz, static_cast<std::size_t>((*output)->ncrtc)))
            {
                const auto config = xrandr::crtc::make(*output, config_idx);

                if(not config)
                {
                    return std::unexpected{config.error()};
                }

                const auto& config_v = *config;

                if(config_idx == 0)
                {
                    screen.area = {
                        .offset = {.x = config_v->x,                                    .y = config_v->y                                     },
                        .extent = {.width = static_cast<std::int32_t>(config_v->width), .height = static_cast<std::int32_t>(config_v->height)},
                    };
                }
            }

            for(const RRMode& mode : output_modes)
            {
                for(const XRRModeInfo& screen_mode : rc->modes())
                {
                    if(mode == screen_mode.id)
                    {
                        const auto total = static_cast<std::uint64_t>(screen_mode.hTotal) * static_cast<std::uint64_t>(screen_mode.vTotal);

                        screen.configurations.emplace_back(screen_properties::config{
                            .resolution
                            = {.width = static_cast<std::int32_t>(screen_mode.width), .height = static_cast<std::int32_t>(screen_mode.height)},
                            .refresh_rate = static_cast<std::uint32_t>(screen_mode.dotClock / (total)),
                        });
                    }
                }
            }

            result.emplace_back(std::move(screen));
        }
    }

    return result;
}

} // namespace fubuki::io::platform::linux_bsd::xlib::screen
