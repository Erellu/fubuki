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

#include "io/platform/linux/wayland/window_parts.hpp"

#include "io/platform/linux/wayland/screen.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

namespace
{

[[nodiscard]] shm_pool construct_pool(platform::views::display::wayland parent)
{
    const auto reqs = window_parts::pool_requirements(parent);

    if(not reqs)
    {
        throw call_exception{reqs.error().value};
    }

    return shm_pool{
        parent, {.width = reqs->width, .height = reqs->height, .layers = reqs->layers}
    };
}

[[nodiscard]] shm_buffer construct_buffer(shm_pool& pool, const window_info& i)
{
    return shm_buffer{
        pool, {.index = 0, .width = i.size.width, .height = i.size.height}
    };
}

[[nodiscard]] window_parts::xdg_objects construct_xdg_objects(views::display::wayland parent, wl_surface* surface)
{
    xdg::wm_base  base{parent};
    xdg::surface  surf{base, surface};
    xdg::toplevel toplevel{surf};

    return {std::move(base), std::move(surf), std::move(toplevel)};
}

} // anonymous namespace

[[nodiscard]] std::expected<shm_pool::information, platform::error::api_call>
window_parts::pool_requirements(platform::views::display::wayland parent) noexcept
{
    const auto available_screens = screen::enumerate(parent);

    if(not available_screens)
    {
        return std::unexpected{available_screens.error()};
    }

    std::size_t width  = 0;
    std::size_t height = 0;

    for(const auto& s : *available_screens)
    {
        width += static_cast<std::size_t>(s.area.extent.width);
        height += static_cast<std::size_t>(s.area.extent.height);
    }

    width  = std::max(std::size_t{1}, width);
    height = std::max(std::size_t{1}, height);

    return shm_pool::information{.width = width, .height = height, .layers = 1};
}

[[nodiscard]] std::optional<decoration> window_parts::decoration_for(xdg::toplevel& toplevel, const window_info& i)
{
    if(i.style == window_style::borderless)
    {
        return std::nullopt;
    }

    // Not supported by GNOME as of the time of writing
    if(toplevel.globals().decoration_manager != nullptr)
    {
        return std::optional<decoration>{std::in_place, decoration{decoration::server_side{toplevel}}}; // May throw call_exception
    }

    return decoration{decoration::client_side{}};
}

window_parts::window_parts(views::display::wayland parent, window_info i)
    : display{parent},
      wl{
          .pool{construct_pool(parent)},
          .buffer{construct_buffer(wl.pool, i)},
          .surface{parent},
      },
      xdg{construct_xdg_objects(parent, wl.surface.handle())},
      deco{decoration_for(*xdg.toplevel, i)}, // NOLINT(bugprone-unchecked-optional-access): it's created witha  value
      info{std::move(i)},
      state{},
      event_dispatcher{}
{
}

window_parts::window_parts(window_parts&& other) noexcept
    : display{other.display},
      wl{std::move(other.wl)},
      xdg{std::move(other.xdg)},
      deco{std::move(other.deco)},
      info{std::move(other.info)},
      state{std::exchange(other.state, window_state{})},
      event_dispatcher{std::move(other.event_dispatcher)}
{
}

} // namespace fubuki::io::platform::linux_bsd::wayland
