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

#include <algorithm>
#include <ranges>

#include "io/platform/linux/wayland/window.hpp"

#include "io/platform/linux/wayland/xdg/interface.hpp"
#include "io/platform/linux/window_registry.hpp"

#include <linux/input-event-codes.h>
#include <sys/mman.h>
#include <sys/timerfd.h>
#include <xkbcommon/xkbcommon.h>

namespace fubuki::io::platform::linux_bsd::wayland
{

namespace
{

void apply_opacity(shm_buffer& buffer, float opacity)
{
    constexpr auto scale = 255.f;

    std::ranges::fill(buffer.memory() | std::views::enumerate
                          | std::views::filter(
                              [](const auto& t) noexcept
                              {
                                  const auto& [index, byte] = t;
                                  std::ignore               = byte;
                                  return (index % 4 == 3); // The only format supported is A8R8G8B8, little-endian, thus this byte
                              })
                          | std::views::values,
                      static_cast<std::byte>(opacity * scale));
}

// NOLINTBEGIN(bugprone-easily-swappable-parameters)
namespace callback::xdg
{

namespace surface
{

[[nodiscard]] bool is_for(const window::parts& w, const xdg_surface* surface) noexcept
{
    return w.xdg.surface.has_value() and w.xdg.surface->handle() == surface;
}

void configure(void* data, xdg_surface* surface, std::uint32_t serial)
{
    if(data == nullptr)
    {
        return;
    }

    auto* const w = static_cast<window::parts*>(data);

    if(not is_for(*w, surface))
    {
        return;
    }

    xdg_surface_ack_configure(surface, serial);

    apply_opacity(w->wl.buffer, w->info.opacity);
    wl_surface_attach(w->wl.surface.handle(), w->wl.buffer.handle(), 0, 0);

    if(w->xdg.surface.has_value())
    {
        xdg_surface_set_window_geometry(
            w->xdg.surface->handle(), w->info.coordinates.x, w->info.coordinates.y, w->info.size.width, w->info.size.height);
    }

    if(w->xdg.toplevel.has_value())
    {
        xdg_toplevel_set_title(w->xdg.toplevel->handle(), w->info.title.c_str());
    }

    wl_surface_commit(w->wl.surface.handle());

    // On Wayland, this function is called when the xdg_toplevel is configured. Since this handle is destroyed when hiding the window, it is not
    // necessarily the first time the window is shown we reach this code
    if(not w->state.activated)
    {
        w->state.activated = true;
        w->event_dispatcher.process(w->data(), event::window::activate{.source = {}});
    }
}

} // namespace surface

namespace toplevel
{

[[nodiscard]] bool is_for(const window::parts& w, const xdg_toplevel* toplevel) noexcept
{
    return w.xdg.toplevel.has_value() and w.xdg.toplevel->handle() == toplevel;
}

void configure(void* data, xdg_toplevel* toplevel, std::int32_t width, std::int32_t height, wl_array* /*states*/) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const w = static_cast<window::parts*>(data);

    if(not is_for(*w, toplevel))
    {
        return;
    }

    // According to the docs:
    // "If the width or height arguments are zero, it means the client should decide its own window dimension"
    if(width != 0 and height != 0)
    {
        const dimension2d old_size = w->info.size;
        const dimension2d new_size = {width, height};
        w->info.size               = new_size;
        w->event_dispatcher.process(w->data(), event::window::resize{.previous = old_size, .next = new_size, .source = {}});
    }
}

void close(void* data, xdg_toplevel* toplevel) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const w = static_cast<window::parts*>(data);

    if(not is_for(*w, toplevel) or w->state.closed)
    {
        return;
    }

    w->state.closed = w->event_dispatcher.process(w->data(), event::window::close{.source = {}});

    if(w->state.closed)
    {
        xdg_toplevel_set_minimized(toplevel);
    }
}

void configure_bounds(void* /*data*/, xdg_toplevel* /*toplevel*/, std::int32_t /*width*/, std::int32_t /*height*/) noexcept {}

void wm_capabilities(void* /*data*/, xdg_toplevel* /*toplevel*/, wl_array* /*capabilities*/) noexcept {}

} // namespace toplevel

} // namespace callback::xdg
// NOLINTEND(bugprone-easily-swappable-parameters)

namespace listener::xdg
{

constexpr xdg_surface_listener surface = {
    .configure = callback::xdg::surface::configure,
};

constexpr xdg_toplevel_listener toplevel{
    .configure        = callback::xdg::toplevel::configure,
    .close            = callback::xdg::toplevel::close,
    .configure_bounds = callback::xdg::toplevel::configure_bounds,
    .wm_capabilities  = callback::xdg::toplevel::wm_capabilities,
};

} // namespace listener::xdg

} // namespace

window::window(window&& other) noexcept : m_parts{std::move(other.m_parts)}
{
    if(m_parts.xdg.surface.has_value())
    {
        xdg_surface_set_user_data(m_parts.xdg.surface->handle(), std::addressof(m_parts));
    }

    if(m_parts.xdg.toplevel.has_value())
    {
        xdg_toplevel_set_user_data(m_parts.xdg.toplevel->handle(), std::addressof(m_parts));
    }

    window_registry::swap(handle(), *this);
}

[[nodiscard]]
std::optional<any_call_info> window::create() noexcept
{
    constexpr auto all_black = 0x00;

    std::ranges::fill(m_parts.wl.buffer.memory(), std::byte{all_black});
    apply_opacity(m_parts.wl.buffer, m_parts.info.opacity);

    if(m_parts.xdg.surface.has_value())
    {
        xdg_surface_add_listener(m_parts.xdg.surface->handle(), std::addressof(listener::xdg::surface), std::addressof(m_parts));
        xdg_surface_set_window_geometry(
            m_parts.xdg.surface->handle(), m_parts.info.coordinates.x, m_parts.info.coordinates.y, m_parts.info.size.width, m_parts.info.size.height);
    }

    if(m_parts.xdg.toplevel.has_value())
    {
        xdg_toplevel_add_listener(m_parts.xdg.toplevel->handle(), std::addressof(listener::xdg::toplevel), std::addressof(m_parts));
        xdg_toplevel_set_title(m_parts.xdg.toplevel->handle(), m_parts.info.title.c_str());
    }

    window_registry::add(handle(), *this);

    wl_surface_commit(m_parts.wl.surface.handle());

    m_parts.state.visible = true; // On wayland, windows are shown by default

    return {};
}

window::~window() noexcept
{
    if(m_parts.wl.surface.handle() != nullptr)
    {
        window_registry::remove(handle());
    }
}

[[nodiscard]]
std::expected<void, platform::error::any> window::show() noexcept // NOLINT(readability-convert-member-functions-to-static)
{
    if(m_parts.state.visible)
    {
        return {};
    }

    if(not m_parts.state.activated)
    {
        return {};
    }

    // Recreate handles
    {
        if(auto surface = xdg::surface::make(m_parts.xdg.wm_base, m_parts.wl.surface.handle()))
        {
            m_parts.xdg.surface = *std::move(surface);
        }
        else
        {
            return std::unexpected{surface.error()};
        }

        if(auto toplevel = xdg::toplevel::make(*m_parts.xdg.surface))
        {
            m_parts.xdg.toplevel = *std::move(toplevel);
        }
        else
        {
            m_parts.xdg.surface = {};
            return std::unexpected{toplevel.error()};
        }

        if(auto deco = window_parts::make_decoration_for(*m_parts.xdg.toplevel, m_parts.info))
        {
            m_parts.deco = *std::move(deco);
        }
        else
        {
            m_parts.xdg.toplevel = {};
            m_parts.xdg.surface  = {};
        }
    }

    // NOLINTNEXTLINE(bugprone-unchecked-optional-access)
    xdg_surface_add_listener(m_parts.xdg.surface->handle(), std::addressof(listener::xdg::surface), std::addressof(m_parts));

    // NOLINTNEXTLINE(bugprone-unchecked-optional-access)
    xdg_toplevel_add_listener(m_parts.xdg.toplevel->handle(), std::addressof(listener::xdg::toplevel), std::addressof(m_parts));

    apply_opacity(m_parts.wl.buffer, m_parts.info.opacity);
    wl_surface_attach(m_parts.wl.surface.handle(), m_parts.wl.buffer.handle(), 0, 0);

    wl_surface_commit(m_parts.wl.surface.handle());

    m_parts.state.visible = true;

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::hide() noexcept // NOLINT(readability-convert-member-functions-to-static)
{
    if(not m_parts.state.visible)
    {
        return {};
    }

    // Destroy handles that maintain the window visible
    m_parts.xdg.toplevel = {};
    m_parts.xdg.surface  = {};
    m_parts.deco         = {};

    wl_surface_attach(m_parts.wl.surface.handle(), nullptr, 0, 0);
    wl_surface_commit(m_parts.wl.surface.handle());

    m_parts.state.visible = false;

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::close() noexcept
{
    if(not m_parts.state.closed)
    {
        m_parts.state.closed = m_parts.event_dispatcher.process(data(), event::window::close{.source = {}});
    }

    if(m_parts.state.closed)
    {
        if(auto toplevel = m_parts.xdg.toplevel.transform([](auto& x) noexcept { return x.handle(); }))
        {
            xdg_toplevel_set_minimized(*toplevel);
        }
    }

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::enable(bool b) noexcept
{
    m_parts.state.enabled = b;

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::set_opacity(float o) noexcept
{
    m_parts.info.opacity = std::clamp(o, 0.f, 1.f);

    apply_opacity(m_parts.wl.buffer, m_parts.info.opacity);

    wl_surface_commit(m_parts.wl.surface.handle());

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::move(position2d /*p*/) noexcept // NOLINT(readability-convert-member-functions-to-static)
{
    return std::unexpected{platform::error::operation_not_supported{configuration::window_system::wayland}};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::resize(dimension2d d) noexcept
{
    // TODO: may be set in events... Check

    if(d != m_parts.info.size)
    {
        constexpr std::size_t format_stride = 4; // 32-bit, 4 bytes

        if(static_cast<std::size_t>(d.width * d.height) * format_stride > m_parts.wl.pool.size_bytes())
        {
            return std::unexpected{platform::error::operation_not_supported{configuration::window_system::wayland}};
        }

        m_parts.info.size = d;

        {
            auto new_buffer = shm_buffer::make(m_parts.wl.pool, {.index = 0, .width = d.width, .height = d.height});

            if(not new_buffer)
            {
                return std::unexpected{platform::error::operation_not_supported{configuration::window_system::wayland}};
            }

            m_parts.wl.buffer = *std::move(new_buffer);
        }

        // Re-give the buffer some data
        {
            constexpr auto all_black = 0x00;

            // auto* const data = reinterpret_cast<std::uint32_t*>(c.buffers.front().memory().data());
            std::ranges::fill(m_parts.wl.buffer.memory(), std::byte{all_black});

            apply_opacity(m_parts.wl.buffer, m_parts.info.opacity);
        }

        wl_surface_attach(m_parts.wl.surface.handle(), m_parts.wl.buffer.handle(), 0, 0);

        if(m_parts.xdg.surface.has_value())
        {
            xdg_surface_set_window_geometry(m_parts.xdg.surface->handle(),
                                            m_parts.info.coordinates.x,
                                            m_parts.info.coordinates.y,
                                            m_parts.info.size.width,
                                            m_parts.info.size.height);
        }

        wl_surface_commit(m_parts.wl.surface.handle());
    }

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::rename(std::string name)
{
    m_parts.info.title = std::move(name);

    if(auto toplevel = m_parts.xdg.toplevel.transform([](auto& x) noexcept { return x.handle(); }))
    {
        xdg_toplevel_set_title(*toplevel, m_parts.info.title.c_str());
    }

    wl_surface_commit(m_parts.wl.surface.handle());

    return {};
}

void window::swap(window& other) noexcept
{
    m_parts.swap(other.m_parts);

    if(m_parts.xdg.surface.has_value())
    {
        xdg_surface_set_user_data(m_parts.xdg.surface->handle(), std::addressof(m_parts));
    }

    if(other.m_parts.xdg.surface.has_value())
    {
        xdg_surface_set_user_data(other.m_parts.xdg.surface->handle(), std::addressof(other.m_parts));
    }

    if(m_parts.xdg.toplevel.has_value())
    {
        xdg_toplevel_set_user_data(m_parts.xdg.toplevel->handle(), std::addressof(m_parts));
    }

    if(other.m_parts.xdg.toplevel.has_value())
    {
        xdg_toplevel_set_user_data(other.m_parts.xdg.toplevel->handle(), std::addressof(other.m_parts));
    }

    window_registry::swap(handle(), *this);
    window_registry::swap(other.handle(), other);
}

void window::user_event(const event::any& e) noexcept
{
    if(m_parts.state.closed)
    {
        return;
    }

    if(const auto* close_event = std::get_if<event::window::close>(std::addressof(e.value)))
    {
        m_parts.state.closed = m_parts.event_dispatcher.process(data(), *close_event);

        return;
    }

    if(const auto* focus_event = std::get_if<event::window::focus>(std::addressof(e.value)))
    {
        m_parts.state.focused = focus_event->next;
    }

    return std::visit([this](const auto& event) noexcept { m_parts.event_dispatcher.process(data(), event); }, e.value);
}

} // namespace fubuki::io::platform::linux_bsd::wayland
