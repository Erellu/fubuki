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

#ifndef FUBUKI_IO_PLATFORM_EVENT_QUEUE_HPP
#define FUBUKI_IO_PLATFORM_EVENT_QUEUE_HPP

#include <algorithm> // IWYU pragma: keep (used when __cpp_lib_containers_ranges is not defined)
#include <optional>
#include <queue>

#include <core/as_span.hpp>
#include <core/config/macros.hpp>

#include "io/platform/current_platform.hpp"
#include "io/platform/event/events.hpp"

namespace fubuki::io::platform::event
{

/**
 * A queue for events to send to a window.
 * @note Access to a queue must be externally synchronised. Instances of this `class` are NOT thread-safe.
 */
class queue
{

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    // NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
    struct entry
    {
        platform::current::window_ref window;
        event::any                    event = {};
    };
    // NOLINTEND(cppcoreguidelines-pro-type-member-init)

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    queue() noexcept = default;
    ~queue()         = default;

    queue(const queue&)            = delete;
    queue& operator=(const queue&) = delete;

    queue(queue&&) noexcept            = default;
    queue& operator=(queue&&) noexcept = default;

    /********************************************************************************/
    /*                                  ELEMENT ACCESS                              */
    /********************************************************************************/

    /**
     * Pops the next event to process, or std::nullopt if the queue is empty.
     */
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<entry> next_event();

    /********************************************************************************/
    /*                                    CAPACITY                                  */
    /********************************************************************************/

    /// Indicates if events are pending in the internal event queue.
    [[nodiscard]] bool empty() const noexcept { return m_entries.empty(); }

    /********************************************************************************/
    /*                          PUBLIC MEMBER FUNCTIONS                             */
    /********************************************************************************/

    /**
     * Pushes a range of entries to the event queue.
     * @param w The window on which the events will be triggered.
     * @param range The events to push to the queue.
     * @pre The window must have been created through `fubuki::io::window`.
     */
    template<std::ranges::range event_range>
    void push(platform::current::surface_handle w, event_range&& range)
    {
        std::ranges::for_each(std::forward<event_range>(range),
                              [this, w]<typename event_type>(event_type&& ev) { m_entries.push({w, std::forward<event_type>(ev)}); });
    }

    /**
     * Pushes a new entry to the event queue.
     * @param w The window on which the events will be triggered.
     * @param e Event to push to the queue.
     * @pre The window must have been created through `fubuki::io::window`.
     */
    void push(platform::current::surface_handle w, event::any e) { return push(w, fubuki::as_span(e)); }

    void swap(queue& other) noexcept { m_entries.swap(other.m_entries); }

    friend void swap(queue& a, queue& b) noexcept { a.swap(b); }

private:

    struct internal_entry
    {
        current::surface_handle platform_data = {};
        event::any              event         = {};
    };

    std::queue<internal_entry> m_entries = {};
};

} // namespace fubuki::io::platform::event

#endif // FUBUKI_IO_PLATFORM_EVENT_QUEUE_HPP
