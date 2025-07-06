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

#include "io/platform/linux/wayland/event_loop.hpp"

#include "io/platform/linux/event/stop_loop.hpp"
#include "io/platform/linux/wayland/interface.hpp"
#include "io/platform/linux/window_registry.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

std::optional<int> process_next_system_event(platform::views::display::wayland dp) noexcept
{
    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    if(wl_display_prepare_read(dp.handle) != 0)
    {
        return event_loop_exit_requested();
    }

    if(wl_display_dispatch_pending(dp.handle) == -1)
    {
        wl_display_cancel_read(dp.handle);
        return event_loop_exit_requested();
    }

    wl_display_flush(dp.handle);
    wl_display_read_events(dp.handle);
    wl_display_dispatch_pending(dp.handle);

    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    return event_loop_exit_requested();
}

} // namespace fubuki::io::platform::linux_bsd::wayland
