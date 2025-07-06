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

#include "io/platform/linux/event/loop.hpp"

#include "io/platform/linux/event/stop_loop.hpp"
#include "io/platform/linux/wayland/event_loop.hpp"
#include "io/platform/linux/wayland/window.hpp"
#include "io/platform/linux/window_registry.hpp"
#include "io/platform/linux/xlib/event_loop.hpp"
#include "io/platform/linux/xlib/window.hpp"

namespace fubuki::io::platform::linux_bsd
{

[[nodiscard]]
std::expected<std::optional<int>, event::loop_routines::error::external_surface> process_next_system_event(platform::views::display d) noexcept
{
    using dp = platform::views::display;

    if(const auto* const xlib_display = std::get_if<dp::xlib>(std::addressof(d.value)))
    {
        return xlib::process_next_system_event(*xlib_display);
    }

    if(const auto* const wayland_display = std::get_if<dp::wayland>(std::addressof(d.value)))
    {
        return wayland::process_next_system_event(*wayland_display);
    }

    // May be reached when called with an invalid view
    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    return event_loop_exit_requested();
}

[[nodiscard]] std::optional<int> process_next_user_event(event::queue& q) noexcept
{
    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    if(auto next_entry = q.next_event(); next_entry.has_value())
    {
        if(const auto* const xlib_window = std::get_if<xlib::window_ref>(std::addressof(next_entry->window)))
        {
            xlib_window->get().user_event(next_entry->event);
        }

        if(const auto* const wayland_window = std::get_if<wayland::window_ref>(std::addressof(next_entry->window)))
        {
            wayland_window->get().user_event(next_entry->event);
        }
    }

    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    return event_loop_exit_requested();
}

void exit_event_loop(int exit_code) noexcept { request_event_loop_exit(exit_code); }

} // namespace fubuki::io::platform::linux_bsd
