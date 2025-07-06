/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2022-2023, Erwan DUHAMEL
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

#ifndef FUBUKI_DISPLAY_PLATFORM_LINUX_X11_WINDOW_HPP
#define FUBUKI_DISPLAY_PLATFORM_LINUX_X11_WINDOW_HPP

#include <core/assertion.hpp>
#include <core/surface_data.hpp>

#include "io/platform/current_platform.hpp"
#include "io/platform/event/dispatcher.hpp"
#include "io/platform/event/queue.hpp"
#include "io/platform/linux/event/mouse_state.hpp"
#include "io/platform/linux/xlib/display.hpp"
#include "io/platform/linux/xlib/error.hpp"
#include "io/platform/window_info.hpp"

// NOLINTBEGIN
// Extracted from <X11/Xdefs.h>
extern "C"
{

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wreserved-identifier"
#endif

using Atom = unsigned long;
union _XEvent;
using XEvent = _XEvent;

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

} // extern "C"
// NOLINTEND

namespace fubuki::io::platform::linux_bsd
{

#if defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wredundant-decls"
#endif

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<int>
                                     process_next_user_event(event::queue&) noexcept; // Required to be forward-defined for custom events

#if defined(__GNUC__)
    #pragma GCC diagnostic pop
#endif

namespace xlib
{

class window
{

    struct token
    {
    };

public:

    using information = window_info;

    struct input_state
    {
        using pointer = linux_bsd::mouse_state;

        pointer mouse = {};

        [[nodiscard]] friend constexpr bool operator==(const input_state& a, const input_state& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const input_state& a, const input_state& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const input_state& a, const input_state& b) noexcept = default;

        /// Swaps two objects.
        void swap(input_state& other) noexcept { mouse.swap(other.mouse); }

        /// Swaps two objects.
        friend void swap(input_state& a, input_state& b) noexcept { a.swap(b); }
    };

    window(platform::views::display::xlib d, information info)
        : window{token{},
                 d.handle,
                 [d]()
                 {
                     auto atoms = xlib::atoms_of(d);

                     if(not atoms)
                     {
                         throw call_exception{any_call_info{atoms.error().value}};
                     }

                     return *atoms;
                 }(),
                 std::move(info)}
    {
        fubuki_assert(d.handle, "Invalid display: must not be nullptr");

        if(const auto success = create(); not success)
        {
            throw call_exception{any_call_info{success.error()}};
        }
    }

    window(const window&)            = delete;
    window& operator=(const window&) = delete;
    window(window&& other) noexcept { swap(other); }
    window& operator=(window&& other) noexcept
    {
        swap(other);
        return *this;
    }

    FUBUKI_IO_PLATFORM_API
    ~window() noexcept;

    [[nodiscard]] static std::expected<window, error::api_call> make(platform::views::display::xlib d, platform::window_info info) noexcept
    {
        auto atoms = xlib::atoms_of(d);

        if(not atoms)
        {
            return std::unexpected{atoms.error()};
        }

        window result{token{}, d.handle, *atoms, std::move(info)};

        if(const auto success = result.create(); not success)
        {
            return std::unexpected{success.error()};
        }

        return result;
    }

    [[nodiscard]] surface_handle handle() noexcept { return m_handle; }
    [[nodiscard]] surface_handle handle() const noexcept { return m_handle; }

    [[nodiscard]] const auto&              atoms() const noexcept { return m_atoms; }
    [[nodiscard]] const auto&              info() const noexcept { return m_info; }
    [[nodiscard]] const window_state&      state() const noexcept { return m_state; }
    [[nodiscard]] event::dispatcher&       event_dispatcher() noexcept { return m_event_dispatcher; }
    [[nodiscard]] const event::dispatcher& event_dispatcher() const noexcept { return m_event_dispatcher; }

    [[nodiscard]] platform::current::platform_data platform_data() const noexcept
    {
        return {
            surface_data::xlib{.dpy = m_parent, .window = m_handle.value}
        };
    }

    [[nodiscard]] surface_data data() const noexcept
    {
        return {
            surface_data::xlib{.dpy = m_parent, .window = m_handle.value}
        };
    }

    /// Returns a view of the parent display.
    [[nodiscard]] platform::views::display parent() const noexcept { return {platform::views::display::xlib{m_parent}}; }

    FUBUKI_IO_PLATFORM_API
    void        swap(window& other) noexcept;
    friend void swap(window& a, window& b) noexcept { a.swap(b); }

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> show() noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> hide() noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> close() noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> enable(bool) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> set_opacity(float o) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> move(position2d p) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> resize(dimension2d d) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> rename(std::string name) noexcept;

    /// Process an OS event.
    FUBUKI_IO_PLATFORM_API void os_event(XEvent& e) noexcept;

private:

    window(token, Display* d, display::internal_atoms atoms, information info) noexcept : m_parent{d}, m_info{std::move(info)}, m_atoms{atoms} {}

    friend std::optional<int> linux_bsd::process_next_user_event(event::queue&) noexcept; // Required for custom event queues

    FUBUKI_IO_PLATFORM_API
    void user_event(const event::any& e) noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, any_call_info> create() noexcept;

    [[nodiscard]] static constexpr std::optional<code> validate(Window w) noexcept
    {
        using enum xlib::code;
        const auto value = static_cast<xlib::code>(w);
        switch(value)
        {
            case(bad_alloc):
            case(bad_colour):
            case(bad_cursor):
            case(bad_match):
            case(bad_pixmap):
            case(bad_value):
            case(bad_window): return value;

            // Other codes are theorically valid values for xlib window handles
            case(success):
            case(bad_request):
            case(bad_atom):
            case(bad_drawable):
            case(bad_access):
            case(bad_gc):
            case(bad_id_choice):
            case(bad_name):
            case(bad_length):
            case(bad_font):
            case(bad_implementation):
            case(unknown):

            default: return {};
        }
    }

    Display*                m_parent           = nullptr;
    surface_handle          m_handle           = {static_cast<Window>(xlib::code::bad_window)};
    information             m_info             = {};
    platform::window_state  m_state            = {}; ///< Window state.
    input_state             m_input            = {};
    event::dispatcher       m_event_dispatcher = {}; ///< Dispatcher for events.
    display::internal_atoms m_atoms            = {};
};

} // namespace xlib

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_DISPLAY_PLATFORM_LINUX_X11_WINDOW_HPP
