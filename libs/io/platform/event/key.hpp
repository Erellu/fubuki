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

#ifndef FUBUKI_IO_PLATFORM_EVENT_KEY_HPP
#define FUBUKI_IO_PLATFORM_EVENT_KEY_HPP

#include <concepts>
#include <ostream>

#include "io/platform/event/source.hpp"
#include "io/platform/keyboard_key.hpp"

namespace fubuki::io::platform::event::key
{

/*
 * TODO:
 * - Keyboard layout change
 */

using code          = io::keyboard::key;
using modifier      = io::keyboard::modifier;
using modifier_mask = io::keyboard::modifier_mask;

//------------------------------------------------------------------------------

/// A key has been pressed.
struct press
{
    code          which  = {}; ///< The key pressed.
    modifier_mask mod    = {}; ///< Active modifiers when the key was pressed (combination of ctrl, shift, alt, caps lock).
    cause         source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const press& p)
    {
        out << "event::key::press:{key: " << p.which << ", modifier: ";
        io::keyboard::to_stream(out, p.mod) << "}";
        return out;
    }

    friend constexpr bool operator==(const press&, const press&) noexcept  = default;
    friend constexpr bool operator!=(const press&, const press&) noexcept  = default;
    friend constexpr auto operator<=>(const press&, const press&) noexcept = default;

    constexpr void swap(press& other) noexcept
    {
        std::swap(which, other.which);
        mod.swap(other.mod);
        source.swap(other.source);
    }

    constexpr friend void swap(press& a, press& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

/// A key has been released.
struct release
{
    code          which  = {}; ///< The key pressed.
    modifier_mask mod    = {}; ///< Active modifiers when the key was pressed (combination of ctrl, shift, alt, caps lock).
    cause         source = {}; ///< What triggered this event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const release& p)
    {
        out << "event::key::release:{key: " << p.which << ", mod: ";
        io::keyboard::to_stream(out, p.mod) << "}";
        return out;
    }

    friend constexpr bool operator==(const release&, const release&) noexcept  = default;
    friend constexpr bool operator!=(const release&, const release&) noexcept  = default;
    friend constexpr auto operator<=>(const release&, const release&) noexcept = default;

    constexpr void swap(release& other) noexcept
    {
        std::swap(which, other.which);
        mod.swap(other.mod);
        source.swap(other.source);
    }

    constexpr friend void swap(release& a, release& b) noexcept { a.swap(b); }
};

//------------------------------------------------------------------------------

template<typename T>
concept any = std::same_as<T, press> or std::same_as<T, release>;

} // namespace fubuki::io::platform::event::key

#endif // FUBUKI_IO_PLATFORM_EVENT_KEY_HPP
