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

#ifndef FUBUKI_IO_EVENT_SEND_HPP
#define FUBUKI_IO_EVENT_SEND_HPP

#include <expected>
#include <span>

#include <core/as_span.hpp>
#include <core/config/macros.hpp>

#include "io/event.hpp"
#include "io/event/queue.hpp"
#include "io/platform/event/send_error.hpp"

namespace fubuki::io
{

class window;

namespace event
{

namespace send_error = io::platform::event::send_error;

/**
 * Sends a succession of events on a list of windows.
 * @param q The queue that will receive user events or events not supported by the native system event queue.
 * @param windows The windows that will receive the events.
 * @param events The events to send.
 * @returns Nothing, or the call that failed.
 * @throws This function CAN throw an instance of std::bad_alloc if some allocation failed.
 */
[[nodiscard]] FUBUKI_IO_API std::expected<void, send_error::any>
                            send(queue& q, std::span<const std::reference_wrapper<io::window>> windows, std::span<const io::event::any> events);

/**
 * Sends a succession of events on a list of windows.
 * @param q The queue that will receive user events or events not supported by the native system event queue.
 * @param windows The windows that will receive the events.
 * @param events The events to send.
 * @returns Nothing, or the call that failed.
 * @throws This function CAN throw an instance of std::bad_alloc if some allocation failed.
 */
[[nodiscard]]
inline auto send(queue& q, const std::initializer_list<std::reference_wrapper<io::window>>& windows, const std::span<const io::event::any> events)
{
    return send(q, std::span{windows}, events);
}

/**
 * Sends a succession of events on a list of windows.
 * @param q The queue that will receive user events or events not supported by the native system event queue.
 * @param windows The windows that will receive the events.
 * @param events The events to send.
 * @returns Nothing, or the call that failed.
 * @throws This function CAN throw an instance of std::bad_alloc if some allocation failed.
 */
[[nodiscard]]
inline auto
send(queue& q, const std::span<const std::reference_wrapper<io::window>> windows, const std::initializer_list<const io::event::any>& events)
{
    return send(q, windows, std::span{events});
}

/**
 * Sends a succession of events on a list of windows.
 * @param q The queue that will receive user events or events not supported by the native system event queue.
 * @param windows The windows that will receive the events.
 * @param events The events to send.
 * @returns Nothing, or the call that failed.
 * @throws This function CAN throw an instance of std::bad_alloc if some allocation failed.
 */
[[nodiscard]]
inline auto
send(queue& q, const std::initializer_list<std::reference_wrapper<io::window>>& windows, const std::initializer_list<const io::event::any>& events)
{
    return send(q, std::span{windows}, std::span{events});
}

//------------------------------------------------------------------------------

/**
 * Sends a succession of events on a window.
 * @param q The queue that will receive user events or events not supported by the native system event queue.
 * @param w The window that will receive the events.
 * @param events The events to send.
 * @returns Nothing, or the call that failed.
 * @throws This function CAN throw an instance of std::bad_alloc if some allocation failed.
 */
[[nodiscard]]
inline auto send(queue& q, io::window& w, const std::span<const io::event::any>& events)
{
    return send(q, {std::ref(w)}, events);
}

/**
 * Sends a succession of events on a window.
 * @param q The queue that will receive user events or events not supported by the native system event queue.
 * @param w The window that will receive the events.
 * @param events The events to send.
 * @returns Nothing, or the call that failed.
 * @throws This function CAN throw an instance of std::bad_alloc if some allocation failed.
 */
[[nodiscard]]
inline auto send(queue& q, io::window& w, const std::initializer_list<io::event::any>& events)
{
    return send(q, w, std::span{events});
}

} //    namespace event

} // namespace fubuki::io

#endif // FUBUKI_IO_EVENT_SEND_HPP
