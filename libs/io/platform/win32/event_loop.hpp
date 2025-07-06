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

#ifndef FUBUKI_IO_PLATFORM_WIN32_EVENT_LOOP_HPP
#define FUBUKI_IO_PLATFORM_WIN32_EVENT_LOOP_HPP

#include <optional>

#include <core/config/macros.hpp>

#include "io/platform/event/queue.hpp"
#include "io/platform/win32/window.hpp"
#include "io/platform/win32/window_registry.hpp"

namespace fubuki::io::platform::win32
{

[[nodiscard]]
inline std::optional<int> process_next_system_event(platform::views::display) noexcept
{
    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    // System message
    // TODO: give the possibility to only process messages relative to the windows owned by Fubuki
    const auto r = window_registry::peek_messages();

    if(window_registry::remove_closed() == 0) // No more windows
    {
        if(r)
        {
            return r;
        }

        return 0;
    }

    return r;
}

[[nodiscard]]
inline std::optional<int> process_next_user_event(event::queue& q) noexcept
{
    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    // Custom messages
    if(auto next_entry = q.next_event(); next_entry.has_value())
    {
        next_entry->window.get().user_event(next_entry->event);
    }

    if(window_registry::remove_closed() == 0) // No more windows
    {
        return 0;
    }

    return {};
}

FUBUKI_IO_PLATFORM_API void exit_event_loop(int exit_code = 0) noexcept;

} // namespace fubuki::io::platform::win32

#endif // FUBUKI_IO_PLATFORM_WIN32_EVENT_LOOP_HPP
