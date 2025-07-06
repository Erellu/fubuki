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

#ifndef FUBUKI_IO_PLATFORM_EVENT_USER_HPP
#define FUBUKI_IO_PLATFORM_EVENT_USER_HPP

#include <any>
#include <cstdint>
#include <ostream>
#include <utility>

#include "io/platform/event/source.hpp"

namespace fubuki::io::platform::event::user
{

/// An enum akin to std::byte, that allows user to specify some additional information regarding the contents of custom events
/// and user information.
enum class marker : std::uint32_t
{
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const marker t)
{
    return out << "event::user::tag{" << std::to_underlying(t) << "}";
}

/// User-defined data.
struct data
{
    marker   tag;   ///< A user-defined tag that can be used to extract some information about the data.
    std::any value; ///< A user-defined value.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const data& d)
    {
        return out << "event::user::data{" << d.tag << ", data:{type name:" << d.value.type().name() << "}"
                   << "}";
    }

    void swap(data& other) noexcept
    {
        std::swap(tag, other.tag);
        value.swap(other.value);
    }

    friend void swap(data& a, data& b) noexcept { a.swap(b); }
};

/// A custom event.
/// Events from this type go to the Fubuki event queue and never reach the system event queue, on any platform.
struct custom
{
    data  contents = {}; ///< The contents of the event.
    cause source   = {}; ///< The source of the event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const custom& e)
    {
        return out << "event::user::custom{" << e.contents << "}";
    }

    void swap(custom& other) noexcept
    {
        contents.swap(other.contents);
        source.swap(other.source);
    }

    friend void swap(custom& a, custom& b) noexcept { a.swap(b); }
};

/// Creates a user::tag from an integer. Shortcut for static_cast (consider using fubuki::event::user::make_tag; somewhere)
[[nodiscard]] inline constexpr auto make_tag(std::uint32_t v) noexcept { return static_cast<marker>(v); }

} // namespace fubuki::io::platform::event::user

#endif // FUBUKI_IO_PLATFORM_EVENT_USER_HPP
