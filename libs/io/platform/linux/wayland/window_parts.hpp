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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_WINDOW_PARTS_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_WINDOW_PARTS_HPP

#include <optional>
#include <utility>

#include <core/config/macros.hpp>

#include "io/platform/event/dispatcher.hpp"
#include "io/platform/linux/wayland/decoration.hpp"
#include "io/platform/linux/wayland/display.hpp"
#include "io/platform/linux/wayland/shm_buffer.hpp"
#include "io/platform/linux/wayland/surface.hpp"
#include "io/platform/linux/wayland/xdg/surface.hpp"
#include "io/platform/linux/wayland/xdg/toplevel.hpp"
#include "io/platform/linux/wayland/xdg/wm_base.hpp"
#include "io/platform/window_info.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

/**
 * The different parts constituing a `wayland::window`.
 * @note This object should not be used standalone. It exists to simplify `wayland::window`'s interface.
 */
struct window_parts
{
    [[nodiscard]] FUBUKI_IO_PLATFORM_API static std::expected<shm_pool::information, platform::error::api_call>
    pool_requirements(views::display::wayland parent) noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API static std::optional<decoration> decoration_for(xdg::toplevel& toplevel, const window_info& i);

    [[nodiscard]] static std::expected<std::optional<decoration>, error::api_call> make_decoration_for(xdg::toplevel&     toplevel,
                                                                                                       const window_info& i) noexcept
    {
        std::optional<decoration> deco = {};

        // Though Wayland windows are borderless by default (especially on platforms that don't support server-side decorations),
        // the general agreement on desktop is that windows should have at least a close button

        if(i.style != window_style::borderless)
        {
            // Not supported on GNOME as of the time of writing
            if(toplevel.globals().decoration_manager != nullptr)
            {
                auto ssd = decoration::server_side::make(toplevel);

                if(not ssd)
                {
                    return std::unexpected{ssd.error()};
                }

                deco = std::optional<decoration>{std::in_place, decoration{*std::move(ssd)}};
            }

            else
            {
                deco = decoration{decoration::client_side{}};
            }
        }

        return deco;
    }

    struct wayland_objects
    {
        shm_pool         pool;
        shm_buffer       buffer;
        wayland::surface surface;

        /// Swaps two objects.
        void swap(wayland_objects& other) noexcept
        {
            pool.swap(other.pool);
            buffer.swap(other.buffer);
            surface.swap(other.surface);
        }

        /// Swaps two objects.
        friend void swap(wayland_objects& a, wayland_objects& b) noexcept { a.swap(b); }
    };

    struct xdg_objects
    {
        xdg::wm_base                 wm_base;
        std::optional<xdg::surface>  surface;
        std::optional<xdg::toplevel> toplevel;

        /// Swaps two objects.
        void swap(xdg_objects& other) noexcept
        {
            wm_base.swap(other.wm_base);
            surface.swap(other.surface);
            toplevel.swap(other.toplevel);
        }

        /// Swaps two objects.
        friend void swap(xdg_objects& a, xdg_objects& b) noexcept { a.swap(b); }
    };

    views::display::wayland         display;
    wayland_objects                 wl;
    xdg_objects                     xdg;
    std::optional<decoration>       deco;
    window_info                     info;
    window_state                    state;
    io::platform::event::dispatcher event_dispatcher;

    FUBUKI_IO_PLATFORM_API
    window_parts(platform::views::display::wayland parent, window_info i);

    /// Constructor. Constructs this object from exisiting window_parts.
    window_parts(views::display::wayland      parent,
                 shm_pool                     p,
                 shm_buffer                   buf,
                 surface                      surf,
                 xdg::wm_base                 wm,
                 std::optional<xdg::surface>  xdg_surf,
                 std::optional<xdg::toplevel> top,
                 std::optional<decoration>    dec,
                 window_info                  i) noexcept
        : display{parent},
          wl{
              .pool{std::move(p)},
              .buffer{std::move(buf)},
              .surface{std::move(surf)},
          },
          xdg{
              .wm_base{std::move(wm)},
              .surface{std::move(xdg_surf)},
              .toplevel{std::move(top)},
          },
          deco{std::move(dec)},
          info{std::move(i)},
          state{},
          event_dispatcher{}
    {
    }

    [[nodiscard]] static std::expected<window_parts, error::api_call> make(platform::views::display::wayland parent, window_info i) noexcept
    {
        auto globals = globals_of(parent);

        if(not globals)
        {
            return std::unexpected{globals.error()};
        }

        const auto pool_reqs = pool_requirements(parent);

        if(not pool_reqs)
        {
            return std::unexpected{pool_reqs.error()};
        }

        auto pool = shm_pool::make(parent, *pool_reqs);

        if(not pool)
        {
            return std::unexpected{pool.error()};
        }

        auto buffer = shm_buffer::make(*pool, {.index = 0, .width = i.size.width, .height = i.size.height});

        if(not buffer)
        {
            return std::unexpected{buffer.error()};
        }

        auto surf = surface::make(parent);

        if(not surf)
        {
            return std::unexpected{surf.error()};
        }

        auto wm_base = xdg::wm_base::make(parent);

        if(not wm_base)
        {
            return std::unexpected{wm_base.error()};
        }

        auto xdg_surface = xdg::surface::make(*wm_base, surf->handle());

        if(not xdg_surface)
        {
            return std::unexpected{xdg_surface.error()};
        }

        auto toplevel = xdg::toplevel::make(*xdg_surface);

        if(not toplevel)
        {
            return std::unexpected{toplevel.error()};
        }

        auto deco = make_decoration_for(*toplevel, i);

        if(not deco)
        {
            return std::unexpected{deco.error()};
        }

        return window_parts{parent,
                            *std::move(pool),
                            *std::move(buffer),
                            *std::move(surf),
                            *std::move(wm_base),
                            *std::move(xdg_surface),
                            *std::move(toplevel),
                            *std::move(deco),
                            std::move(i)};
    }

    /// Move constructor.
    FUBUKI_IO_PLATFORM_API
    window_parts(window_parts&& other) noexcept;

    /// Move assignment operator.
    window_parts& operator=(window_parts&& other) noexcept
    {
        swap(other);
        return *this;
    }

    window_parts(const window_parts&)            = delete;
    window_parts& operator=(const window_parts&) = delete;

    ~window_parts() noexcept = default;

    [[nodiscard]] platform::current::platform_data platform_data() const noexcept
    {
        return {
            surface_data::wayland{.display = display.handle, .surface = wl.surface.handle()}
        };
    }

    [[nodiscard]] surface_data data() const noexcept
    {
        return {
            surface_data::wayland{.display = display.handle, .surface = wl.surface.handle()}
        };
    }

    /// Swaps two objects.
    void swap(window_parts& other) noexcept
    {
        display.swap(other.display);
        wl.swap(other.wl);
        xdg.swap(other.xdg);
        deco.swap(other.deco);
        info.swap(other.info);
        state.swap(other.state);
        event_dispatcher.swap(other.event_dispatcher);
    }

    /// Swaps two objects.
    friend void swap(window_parts& a, window_parts& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_WINDOW_PARTS_HPP
