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

#ifndef FUBUKI_IO_PLATFORM_EVENT_HANDLER_HPP
#define FUBUKI_IO_PLATFORM_EVENT_HANDLER_HPP

#include <core/surface_data.hpp>

#include "io/platform/event/events.hpp" // IWYU pragma: keep

namespace fubuki::io::platform::event
{

/// Answer to an event, when applicable.
enum class answer
{
    accept, ///< Accept the event.
    decline ///< Cancel the event.
};

// The compiler cannot infer the purpose of this class (used in examples/tutorials)
// and therefore suggests to mark it final. This is obviously a spurious warning so we silence it locally.

#if (defined(__GNUC__) or defined(__MINGW32__)) and not defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wsuggest-final-types"
    #pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif

/**
 * An interface to listen and handle events triggered on a window.
 * This `class` is meant to be inherited to `override` relevant overloads of the `handle()` member functions, that perform nothing by default.
 *
 * An event handler can be `enabled` or `disabled`, which indicates if `handle()` will be called when an event is fired.
 * This state can be changed through `enable(b)`, `enable()` or `disable()`.
 *
 * @section example Example
 *
 * @code{.cpp}
struct handle_window_events : fubuki::io::event::handler
{
    void handle(surface_data window_data, const io::event::window::resize&) noexcept override
    {
        ...
    }

    void handle(surface_data window_data, const io::event::window::move&) noexcept override
    {
        ...
    }

    using fubuki::io::event::handler::handle;
};
 * @endcode
 */
class handler
{
public:

    handler()               = default;
    handler(const handler&) = default;
    handler(handler&&)      = default;

    handler& operator=(const handler&) = default;
    handler& operator=(handler&&)      = default;

    virtual ~handler() = default;

    /// Indicates if this handler is enabled, that is, its handle() functions will be called through event::dispatcher.
    [[nodiscard]] bool enabled() const noexcept { return m_enabled; }

    /// Indicates if this handler is disabled.
    [[nodiscard]] bool disabled() const noexcept { return not enabled(); }

    /**
     *  Toggles this handler.
     * @param b State. If `b` is true, then the event::dispatcher that will call `handle() when an event is received.
     * If `b` is false, `handle()` will not be called.
     */
    handler& enable(bool b) noexcept
    {
        m_enabled = b;
        return *this;
    }

    /// Enables this handler.
    handler& enable() noexcept { return enable(true); }

    /// Disables this handler.
    handler& disable() noexcept { return enable(false); }

    // ----------------------------- Keyboard events ------------------------------ //

    /// Called when a keyboard key is pressed.
    virtual void handle(surface_data, const event::key::press&) noexcept {}

    /// Called when a keyboard key is released.
    virtual void handle(surface_data, const event::key::release&) noexcept {}

    // ------------------------------ Mouse events -------------------------------- //

    /// Called when a mouse button is clicked.
    virtual void handle(surface_data, const event::mouse::click&) noexcept {}

    /// Called when a mouse button is double-clicked.
    virtual void handle(surface_data, const event::mouse::double_click&) noexcept {}

    /// Called when a mouse button is released.
    virtual void handle(surface_data, const event::mouse::release&) noexcept {}

    /// Called when mouse wheeled is moved.
    virtual void handle(surface_data, const event::mouse::wheel&) noexcept {}

    /// Called when mouse is moved.
    virtual void handle(surface_data, const event::mouse::move&) noexcept {}

    // ------------------------------ Window events ------------------------------- //

    /// Called when window is moved.
    virtual void handle(surface_data, const event::window::move&) noexcept {}

    /// Called when window is resized.
    virtual void handle(surface_data, const event::window::resize&) noexcept {}

    /// Called when window gets or loses focus.
    virtual void handle(surface_data, const event::window::focus&) noexcept {}

    /// Called when window is request to be closed. Event is ignored if, and only if ALL handlers decline the event.
    virtual answer handle(surface_data, const event::window::close&) noexcept { return answer::accept; }

    /// Called when window is enabled or disabled.
    virtual void handle(surface_data, const event::window::enable&) noexcept {}

    /// Called when window is activated (shown for the first time).
    virtual void handle(surface_data, const event::window::activate&) noexcept {}

    /// Called when window is about to be destroyed.
    virtual void handle(surface_data, const event::window::destroy_start&) noexcept {}

    /// Called when window destruction has ended.
    virtual void handle(surface_data, const event::window::destroy_end&) noexcept {}

    // ------------------------------- User events -------------------------------- //

    /// Called when the window handles a user-triggered event.
    virtual void handle(surface_data, const event::user::custom&) noexcept {}

private:
    bool m_enabled = true; ///< Indicates if this object participates in event handling.
};

#if (defined(__GNUC__) or defined(__MINGW32__)) and not defined(__clang__)
    #pragma GCC diagnostic pop
#endif

} // namespace fubuki::io::platform::event

#endif // FUBUKI_IO_PLATFORM_EVENT_HANDLER_HPP
