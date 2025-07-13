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

#ifndef FUBUKI_IO_PLATFORM_EVENT_WINDOW_HPP
#define FUBUKI_IO_PLATFORM_EVENT_WINDOW_HPP

#include <concepts>
#include <ostream>

#include <core/config/macros.hpp>
#include <core/dim.hpp>
#include <core/pos.hpp>

#include "io/platform/event/source.hpp"

namespace fubuki::io::platform::event::window
{

/// Window move event.
struct move
{
    position2d previous = {}; ///< Where the window previously was.
    position2d next     = {}; ///< Where the window is being moved.
    cause      source   = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const window::move& p)
    {
        return out << "event::window::move:{previous: " << p.previous << ", next: " << p.next << "}";
    }

    friend constexpr bool operator==(const move&, const move&) noexcept  = default;
    friend constexpr bool operator!=(const move&, const move&) noexcept  = default;
    friend constexpr auto operator<=>(const move&, const move&) noexcept = default;

    constexpr void swap(move& other) noexcept
    {
        previous.swap(other.previous);
        next.swap(other.next);
        source.swap(other.source);
    }

    constexpr friend void swap(move& a, move& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Window resize event.
struct resize
{
    dimension2d previous = {}; ///< Window previous size.
    dimension2d next     = {}; ///< Window new size.
    cause       source   = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const window::resize& p)
    {
        return out << "event::window::resize:{previous: " << p.previous << ", next: " << p.next << "}";
    }

    friend constexpr bool operator==(const resize&, const resize&) noexcept  = default;
    friend constexpr bool operator!=(const resize&, const resize&) noexcept  = default;
    friend constexpr auto operator<=>(const resize&, const resize&) noexcept = default;

    constexpr void swap(resize& other) noexcept
    {
        previous.swap(other.previous);
        next.swap(other.next);
        source.swap(other.source);
    }

    constexpr friend void swap(resize& a, resize& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Event sent when a window gains or loses focus.
struct focus
{
    bool  previous = {}; ///< Previous state in which the window was before this event.
    bool  next     = {}; ///< Next state.
    cause source   = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const window::focus& p)
    {
        return out << "event::window::focus:{previous: " << p.previous << ", next: " << p.next << "}";
    }

    friend constexpr bool operator==(const focus&, const focus&) noexcept  = default;
    friend constexpr bool operator!=(const focus&, const focus&) noexcept  = default;
    friend constexpr auto operator<=>(const focus&, const focus&) noexcept = default;

    constexpr void swap(focus& other) noexcept
    {
        std::swap(previous, other.previous);
        std::swap(next, other.next);
        source.swap(other.source);
    }

    constexpr friend void swap(focus& a, focus& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Event sent when the user requests to close a window.
struct close
{
    cause source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const close&)
    {
        return out << "event::window::close{}";
    }

    friend constexpr bool operator==(const close&, const close&) noexcept  = default;
    friend constexpr bool operator!=(const close&, const close&) noexcept  = default;
    friend constexpr auto operator<=>(const close&, const close&) noexcept = default;

    constexpr void swap(close& other) noexcept { source.swap(other.source); }

    constexpr friend void swap(close& a, close& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Event sent when a window is enabled or disabled.
struct enable
{
    bool  previous = {}; ///< Previous state in which the window was before this event.
    bool  next     = {}; ///< Next state.
    cause source   = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const window::enable& p)
    {
        return out << "event::window::enable:{previous: " << p.previous << ", next: " << p.next << "}";
    }

    friend constexpr bool operator==(const enable&, const enable&) noexcept  = default;
    friend constexpr bool operator!=(const enable&, const enable&) noexcept  = default;
    friend constexpr auto operator<=>(const enable&, const enable&) noexcept = default;

    constexpr void swap(enable& other) noexcept
    {
        std::swap(previous, other.previous);
        std::swap(next, other.next);
        source.swap(other.source);
    }

    constexpr friend void swap(enable& a, enable& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Event sent when a window is activated (displayed) for the first time.
struct activate
{
    cause source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const activate&)
    {
        return out << "event::window::activate:{}";
    }

    friend constexpr bool operator==(const activate&, const activate&) noexcept  = default;
    friend constexpr bool operator!=(const activate&, const activate&) noexcept  = default;
    friend constexpr auto operator<=>(const activate&, const activate&) noexcept = default;

    constexpr void swap(activate& other) noexcept { source.swap(other.source); }

    constexpr friend void swap(activate& a, activate& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Event sent when a window is about to be destroyed.
struct destroy_start
{
    cause source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const destroy_start&)
    {
        return out << "event::window::destroy_start:{}";
    }

    friend constexpr bool operator==(const destroy_start&, const destroy_start&) noexcept  = default;
    friend constexpr bool operator!=(const destroy_start&, const destroy_start&) noexcept  = default;
    friend constexpr auto operator<=>(const destroy_start&, const destroy_start&) noexcept = default;

    constexpr void swap(destroy_start& other) noexcept { source.swap(other.source); }

    constexpr friend void swap(destroy_start& a, destroy_start& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Event sent when a window destruction has ended.
struct destroy_end
{
    cause source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const destroy_end&)
    {
        return out << "event::window::destroy_end:{}";
    }

    friend constexpr bool operator==(const destroy_end&, const destroy_end&) noexcept  = default;
    friend constexpr bool operator!=(const destroy_end&, const destroy_end&) noexcept  = default;
    friend constexpr auto operator<=>(const destroy_end&, const destroy_end&) noexcept = default;

    constexpr void swap(destroy_end& other) noexcept { source.swap(other.source); }

    constexpr friend void swap(destroy_end& a, destroy_end& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

template<typename T>
concept any = std::same_as<T, move> or std::same_as<T, resize> or std::same_as<T, focus> or std::same_as<T, close> or std::same_as<T, enable>
    or std::same_as<T, activate> or std::same_as<T, destroy_start> or std::same_as<T, destroy_end>;

} // namespace fubuki::io::platform::event::window

#endif // FUBUKI_IO_PLATFORM_EVENT_WINDOW_HPP
