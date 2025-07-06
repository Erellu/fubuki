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

#include <cstring>

#include "io/platform/linux/xlib/event_loop.hpp"

#include "io/platform/linux/event/stop_loop.hpp"
#include "io/platform/linux/window_registry.hpp"
#include "io/platform/linux/xlib/display_lock.hpp"
#include "io/platform/linux/xlib/window.hpp"

#include <X11/Xlib.h>

namespace fubuki::io::platform::linux_bsd::xlib
{

std::expected<std::optional<int>, event::loop_routines::error::external_surface> process_next_system_event(views::display::xlib dp) noexcept
{
    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    const display_lock _{dp};

    if(not XPending(dp.handle))
    {
        return {};
    }

    {
        XEvent next = {};

        XNextEvent(dp.handle, std::addressof(next));

        XAnyEvent general_info = {};
        std::memcpy(&general_info, std::addressof(next), sizeof(XAnyEvent));

        if(auto w = window_registry::window_of(surface_handle{general_info.window}))
        {
            w->get().os_event(next);
        }
        else
        {
            return std::unexpected{
                event::loop_routines::error::external_surface{.surface = {surface_data::xlib{dp.handle, general_info.window}}, .event = next}
            };
        }
    }

    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    return event_loop_exit_requested();
}

} // namespace fubuki::io::platform::linux_bsd::xlib
