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

#ifndef FUBUKI_IO_EVENT_LOOP_HPP
#define FUBUKI_IO_EVENT_LOOP_HPP

#include <expected>
#include <initializer_list>
#include <optional>
#include <span>

#include <core/config/macros.hpp>
#include <io/platform/event/loop_routines.hpp>
#include <io/platform/views/display.hpp>

#include "io/event/queue.hpp"

namespace fubuki::io
{

class display; // NOLINT(bugprone-forward-declaration-namespace)

namespace event::loop
{

/// @copydoc fubuki::io::platform::event::loop_routines
using routines = io::platform::event::loop_routines;

namespace next
{

/**
 * Processes the next pending system event.
 * @param dp The display which event will be processed.
 * @returns If the next event is for a surface known to Fubuki, a valid 'main' exit code if message requested quit, `std::nullopt` otherwise.
 * If the next event is for an unknown surface, an instance of routines::error::external_surface indicating that can be used to handle the event
 * manually.
 */
[[nodiscard]] FUBUKI_IO_API std::expected<std::optional<int>, routines::error::external_surface> system(platform::views::display dp) noexcept;

/**
 * Processes the next pending event in a user queue.
 * @param q The queue to use.
 * @returns A valid 'main' exit code if message requested quit, `std::nullopt` otherwise.
 * @warning Access to event::queue MUST be externally synchronised. Instances of this object are NOT thread-safe.
 */
[[nodiscard]] FUBUKI_IO_API std::optional<int> user(event::queue& q) noexcept;

} // namespace next

/**
 * Event loop.
 * @returns A valid code for `main`.
 * @param displays Displays participating to the loop.
 * @param queues User event queues participating to the loop.
 * @param r (optional) Routines to execute. @see loop::routines for more information. By default, all are no-op.
 * @note The event loop is equivalent to the following code:
 * @code{.cpp}
 * int event_loop(display_range displays, event_queue_range event_queues, routines r)
 * {
 *     r.loop.before();
 *     while(no_reason_to_exit())
 *     {
 *         // System events are handled first...
 *         for(display& dp : displays)
 *         {
 *             r.system_event.before();
 *
 *             if(const auto system = next::system(dp); not system)
 *             {
 *                 r.external_surface(system.error());
 *             }
 *
 *             r.system_event.after();
 *         }
 *
 *         // ... And events from the user-provided queues are handled next
 *         for(event::queue& q : event_queues)
 *         {
 *             r.internal_event.before();
 *             next_user_event(dp);
 *             r.internal_event.after();
 *         }
 *     }
 *     r.loop.after();
 *     return exit_code();
 * }
 * @endcode
 */
[[nodiscard]] FUBUKI_IO_API int
execute(std::span<const platform::views::display> displays, std::span<const std::reference_wrapper<event::queue>> queues, routines r = {}) noexcept;

/**
 * Event loop.
 * @returns A valid code for `main`.
 * @param displays Displays participating to the loop.
 * @param r (optional) Routines to execute. @see loop::routines for more information. By default, all are no-op.
 */
[[nodiscard]] inline int execute(std::initializer_list<platform::views::display>             displays,
                                 std::initializer_list<std::reference_wrapper<event::queue>> queues,
                                 routines                                                    r = {}) noexcept
{
    return execute(std::span{displays}, std::span{queues}, std::move(r));
}

/**
 * Runs the event loop for a single display.
 * @returns A valid code for `main`.
 * @param display The display receiving the events.
 * @param r (optional) Routines to execute. @see loop::routines for more information. By default, all are no-op.
 */
[[nodiscard]] inline int execute(platform::views::display display, event::queue& q, routines r = {}) noexcept
{
    return execute({display}, {std::ref(q)}, std::move(r));
}

/**
 * Indicates if a display has pending events, without handling the events.
 * @param dp The display to check.
 */
[[nodiscard]] FUBUKI_IO_API bool pending(platform::views::display dp) noexcept;

/**
 * Signals the event loop must be exited by queuing the corresponding event to the queue.
 * @param exit_code (optional) The exit code that will be returned by `loop::execute` or `loop::next::system`.
 */
FUBUKI_IO_API
void exit(int exit_code = 0) noexcept;

} // namespace event::loop

} // namespace fubuki::io

#endif // FUBUKI_IO_EVENT_LOOP_HPP
