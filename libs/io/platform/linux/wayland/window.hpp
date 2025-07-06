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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_WINDOW_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_WINDOW_HPP

#include <optional>
#include <utility>

#include <core/config/macros.hpp>
#include <core/surface_data.hpp>

#include "io/platform/current_platform.hpp"
#include "io/platform/event/queue.hpp"
#include "io/platform/linux/wayland/window_parts.hpp"

namespace fubuki::io::platform::linux_bsd
{

#if defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wredundant-decls"
#endif

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<int>
process_next_user_event(io::platform::event::queue&) noexcept; // Required to be forward-defined for custom events

#if defined(__GNUC__)
    #pragma GCC diagnostic pop
#endif

namespace wayland
{

/**
 * A window, displayed on the screen.
 */
class window
{
    struct token
    {
    };

public:

    using information = window_info;
    using parts       = window_parts;

    window(platform::views::display::wayland parent, window_info i) : m_parts{parent, std::move(i)}
    {
        if(const auto error = create())
        {
            throw call_exception{*error};
        }
    }

    window(const window&)            = delete;
    window& operator=(const window&) = delete;

    FUBUKI_IO_PLATFORM_API
    window(window&& other) noexcept;

    window& operator=(window&& other) noexcept
    {
        swap(other);
        return *this;
    }

    FUBUKI_IO_PLATFORM_API
    ~window() noexcept;

    [[nodiscard]] static std::expected<window, error::api_call> make(platform::views::display::wayland parent, window_info i) noexcept
    {
        auto parts = parts::make(parent, std::move(i));

        if(not parts)
        {
            return std::unexpected{parts.error()};
        }

        window result{
            token{},
            *std::move(parts),
        };

        if(const auto error = result.create())
        {
            return std::unexpected{*error};
        }

        return result;
    }

    // NOTE: not const auto* for compatibility with Vulkan and fubuki::surface_data

    [[nodiscard]] surface_handle handle() noexcept { return {m_parts.wl.surface.handle()}; }
    [[nodiscard]] surface_handle handle() const noexcept { return {m_parts.wl.surface.handle()}; }

    [[nodiscard]] const auto& pool() const noexcept { return m_parts.wl.pool; }
    [[nodiscard]] const auto& buffer() const noexcept { return m_parts.wl.buffer; }
    [[nodiscard]] const auto& wm_base() const noexcept { return m_parts.xdg.wm_base; }
    [[nodiscard]] const auto& surface() const noexcept { return m_parts.wl.surface; }
    [[nodiscard]] const auto& xdg_surface() const noexcept { return m_parts.xdg.surface; }
    [[nodiscard]] const auto& toplevel() const noexcept { return m_parts.xdg.toplevel; }

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> show() noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> hide() noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> close() noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> enable(bool) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> set_opacity(float o) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> move(position2d p) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> resize(dimension2d d) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> rename(std::string name);

    [[nodiscard]] const information&               info() const noexcept { return m_parts.info; }
    [[nodiscard]] const window_state&              state() const noexcept { return m_parts.state; }
    [[nodiscard]] event::dispatcher&               event_dispatcher() noexcept { return m_parts.event_dispatcher; }
    [[nodiscard]] const event::dispatcher&         event_dispatcher() const noexcept { return m_parts.event_dispatcher; }
    [[nodiscard]] platform::current::platform_data platform_data() const noexcept { return m_parts.platform_data(); }
    [[nodiscard]] surface_data                     data() const noexcept { return m_parts.data(); }

    /// Returns a view of the parent display.
    [[nodiscard]] platform::views::display parent() const noexcept { return {m_parts.display}; }

    FUBUKI_IO_PLATFORM_API void swap(window& other) noexcept;

    friend void swap(window& a, window& b) noexcept { a.swap(b); }

    // These events are triggered through listeners of the display's globals
    decltype(auto) os_event(const event::key::any auto& event) noexcept
    {
        if(not m_parts.state.closed and m_parts.state.enabled)
        {
            return m_parts.event_dispatcher.process(data(), event);
        }
    }
    decltype(auto) os_event(const event::mouse::any auto& event) noexcept
    {
        if(not m_parts.state.closed and m_parts.state.enabled)
        {
            return m_parts.event_dispatcher.process(data(), event);
        }
    }

    void os_event(const event::window::focus& e) noexcept
    {
        m_parts.state.focused = e.next;
        m_parts.event_dispatcher.process(data(), e);
    }

private:

    window(token, parts c) noexcept : m_parts{std::move(c)} {}

    friend std::optional<int> linux_bsd::process_next_user_event(event::queue&) noexcept; // Required for custom event queues

    FUBUKI_IO_PLATFORM_API
    void user_event(const event::any& e) noexcept;

    [[nodiscard]]
    std::optional<any_call_info> create() noexcept;

    parts m_parts;
};

} // namespace wayland

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_WINDOW_HPP
