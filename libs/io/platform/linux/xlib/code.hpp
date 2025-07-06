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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_CODE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_CODE_HPP

#include <ostream>

namespace fubuki::io::platform::linux_bsd::xlib
{

/// X11 error codes.
enum class code
{
    success,
    bad_request,
    bad_value,
    bad_window,
    bad_pixmap,
    bad_atom,
    bad_cursor,
    bad_font,
    bad_match,
    bad_drawable,
    bad_access,
    bad_alloc,
    bad_colour,
    bad_gc,
    bad_id_choice,
    bad_name,
    bad_length,
    bad_implementation,
    unknown,
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, code p)
{
    switch(p)
    {
        case code::success           : return out << "xlib::code::success";
        case code::bad_request       : return out << "xlib::code::bad_request";
        case code::bad_value         : return out << "xlib::code::bad_value";
        case code::bad_window        : return out << "xlib::code::bad_window";
        case code::bad_pixmap        : return out << "xlib::code::bad_pixmap";
        case code::bad_atom          : return out << "xlib::code::bad_atom";
        case code::bad_cursor        : return out << "xlib::code::bad_cursor";
        case code::bad_font          : return out << "xlib::code::bad_font";
        case code::bad_match         : return out << "xlib::code::bad_match";
        case code::bad_drawable      : return out << "xlib::code::bad_drawable";
        case code::bad_access        : return out << "xlib::code::bad_access";
        case code::bad_alloc         : return out << "xlib::code::bad_alloc";
        case code::bad_colour        : return out << "xlib::code::bad_colour";
        case code::bad_gc            : return out << "xlib::code::bad_gc";
        case code::bad_id_choice     : return out << "xlib::code::bad_id_choice";
        case code::bad_name          : return out << "xlib::code::bad_name";
        case code::bad_length        : return out << "xlib::code::bad_length";
        case code::bad_implementation: return out << "xlib::code::bad_implementation";
        case code::unknown           :
        default                      : return out << "xlib::code::unknown";
    }
}

struct result
{
    code c = {};

    [[nodiscard]] friend constexpr bool operator==(const result& a, const result& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const result& a, const result& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const result& a, const result& b) noexcept = default;

    [[nodiscard]] constexpr const auto& value() const noexcept { return c; }

    [[nodiscard]] constexpr operator bool() const noexcept { return c == code::success; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const result& r)
    {
        return out << "xlib::result{" << r.c << "}";
    }
};

} // namespace fubuki::io::platform::linux_bsd::xlib

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_CODE_HPP
