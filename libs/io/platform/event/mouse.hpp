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

#ifndef FUBUKI_IO_PLATFORM_EVENT_MOUSE_HPP
#define FUBUKI_IO_PLATFORM_EVENT_MOUSE_HPP

#include <concepts>
#include <cstdint>
#include <ostream>

#include <core/pos.hpp>

#include "io/platform/event/source.hpp"
#include "io/platform/keyboard_key.hpp"
#include "io/platform/mouse_button.hpp"

namespace fubuki::io::platform::event::mouse
{

using scroll_direction = io::mouse::scroll_direction;
using button           = io::mouse::button;
using modifier_mask    = io::keyboard::modifier_mask;

//------------------------------------------------------------------------------

/// Mouse click event.
struct click
{
    button        which  = {}; ///< Which button is pressed.
    position2d    where  = {}; ///< Position in window space in pixels.
    modifier_mask mod    = {}; ///< Active modifiers when the key was pressed (combination of ctrl, shift, alt, caps lock).
    cause         source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const click& p)
    {
        out << "mouse click event: {button: " << p.which << ", position: " << p.where << ", mod: ";
        io::keyboard::to_stream(out, p.mod) << "}";
        return out;
    }

    friend constexpr bool operator==(const click&, const click&) noexcept  = default;
    friend constexpr bool operator!=(const click&, const click&) noexcept  = default;
    friend constexpr auto operator<=>(const click&, const click&) noexcept = default;

    constexpr void swap(click& other) noexcept
    {
        std::swap(which, other.which);
        where.swap(other.where);
        mod.swap(other.mod);
        source.swap(other.source);
    }

    constexpr friend void swap(click& a, click& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Mouse double click event.
struct double_click
{
    button        which  = {}; ///< Which button is pressed.
    position2d    where  = {}; ///< Position in window space in pixels.
    modifier_mask mod    = {}; ///< Active modifiers when the key was pressed (combination of ctrl, shift, alt, caps lock).
    cause         source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const double_click& p)
    {
        out << "event::mouse::double_click: {button: " << p.which << ", position: " << p.where << ", mod: ";
        io::keyboard::to_stream(out, p.mod) << "}";
        return out;
    }

    friend constexpr bool operator==(const double_click&, const double_click&) noexcept  = default;
    friend constexpr bool operator!=(const double_click&, const double_click&) noexcept  = default;
    friend constexpr auto operator<=>(const double_click&, const double_click&) noexcept = default;

    constexpr void swap(double_click& other) noexcept
    {
        std::swap(which, other.which);
        where.swap(other.where);
        mod.swap(other.mod);
        source.swap(other.source);
    }

    constexpr friend void swap(double_click& a, double_click& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Mouse release event.
struct release
{
    button        which  = {}; ///< Which button is pressed.
    position2d    where  = {}; ///< Position in window space in pixels.
    modifier_mask mod    = {}; ///< Active modifiers when the key was pressed (combination of ctrl, shift, alt, caps lock).
    cause         source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const release& p)
    {
        out << "event::mouse::release:{button: " << p.which << " position: " << p.where << " mod: ";
        io::keyboard::to_stream(out, p.mod) << "}";
        return out;
    }

    friend constexpr bool operator==(const release&, const release&) noexcept  = default;
    friend constexpr bool operator!=(const release&, const release&) noexcept  = default;
    friend constexpr auto operator<=>(const release&, const release&) noexcept = default;

    constexpr void swap(release& other) noexcept
    {
        std::swap(which, other.which);
        where.swap(other.where);
        mod.swap(other.mod);
        source.swap(other.source);
    }

    constexpr friend void swap(release& a, release& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// Mouse wheel event.
struct wheel
{
    using direction = scroll_direction;

    std::int32_t  ticks       = {}; ///< Ticks. Negative when scrolling down, positive when scrolling back.
    direction     orientation = {}; ///< The direction of the scroll.
    position2d    where       = {}; ///< Current mouse position.
    modifier_mask mod         = {}; ///< Active modifiers when the key was pressed (combination of ctrl, shift, alt, caps lock).
    cause         source      = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const wheel& p)
    {
        out << "event::mouse::scroll:{ticks: " << p.ticks << ", orientation: " << p.orientation << ", position: " << p.where << " mod: ";
        io::keyboard::to_stream(out, p.mod) << "}";
        return out;
    }

    friend constexpr bool operator==(const wheel&, const wheel&) noexcept  = default;
    friend constexpr bool operator!=(const wheel&, const wheel&) noexcept  = default;
    friend constexpr auto operator<=>(const wheel&, const wheel&) noexcept = default;

    constexpr void swap(wheel& other) noexcept
    {
        std::swap(ticks, other.ticks);
        std::swap(orientation, other.orientation);
        where.swap(other.where);
        mod.swap(other.mod);
        source.swap(other.source);
    }

    constexpr friend void swap(wheel& a, wheel& b) noexcept { a.swap(b); }
};

using scroll = wheel;

//------------------------------------------------------------------------------

/// Mouse move event.
struct move
{
    position2d where  = {}; ///< Position in window space in pixels.
    cause      source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const move& p)
    {
        return out << "event::mouse::move:{position: " << p.where << "}";
    }

    friend constexpr bool operator==(const move&, const move&) noexcept  = default;
    friend constexpr bool operator!=(const move&, const move&) noexcept  = default;
    friend constexpr auto operator<=>(const move&, const move&) noexcept = default;

    constexpr void swap(move& other) noexcept
    {
        where.swap(other.where);
        source.swap(other.source);
    }

    constexpr friend void swap(move& a, move& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

template<typename T>
concept any = std::same_as<T, click> or std::same_as<T, double_click> or std::same_as<T, release> or std::same_as<T, wheel> or std::same_as<T, move>;

} // namespace fubuki::io::platform::event::mouse

#endif // FUBUKI_EVENT_MOUSE_HPP
