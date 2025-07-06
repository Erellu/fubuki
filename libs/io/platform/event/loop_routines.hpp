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

#ifndef FUBUKI_IO_PLATFORM_EVENT_LOOP_ROUTINES_HPP
#define FUBUKI_IO_PLATFORM_EVENT_LOOP_ROUTINES_HPP

#include <any>

#include <core/detail/platform_forward.hpp>
#include <core/future/move_only_function.hpp>
#include <core/surface_data.hpp>

namespace fubuki::io::platform::event
{

/**
 * Customisation points for the event loop.
 * Allows to perform user-defined actions at various timings while waiting for events.
 * The event loop is equivalent to the following code:
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
struct loop_routines
{
    static constexpr void no_op() noexcept {} ///< Default callable for all members. Does nothing.

    struct step
    {
        using executable = move_only_function<void() noexcept>;

        executable before = no_op;
        executable after  = no_op;
    };

    struct error
    {
        /// Indicates an event is for a surface not known to Fubuki.
        struct external_surface
        {
            static constexpr void no_op(const external_surface&) noexcept {} ///< Default callable when a surface is not found. Does nothing.

            /// The surface that received the event.
            surface_data surface = {};

            /**
             *  The event that does not match any window owned by Fubuki.
             * The type it holds depends on the current window system.
             * - On Linux with Xlib, it is guaranteed to hold an instance of ::XEvent.
             */
            std::any event = {};
        };
    };

    step loop           = {}; ///< Executed once, before starting the loop and before returning from the event loop.
    step system_event   = {}; ///< Executed each iteration, before and after handling system events.
    step internal_event = {}; ///< Executed each iteration, before and after handling internal events.

    /**
     * Invoked when the call of io::event::loop::next::system attempts to process an event that is not for a window owned by Fubuki.
     */
    move_only_function<void(const error::external_surface&) noexcept> external_surface = error::external_surface::no_op;
};

} // namespace fubuki::io::platform::event

#endif // FUBUKI_IO_PLATFORM_EVENT_LOOP_ROUTINES_HPP
