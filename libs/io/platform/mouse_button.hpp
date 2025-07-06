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

#ifndef FUBUKI_IO_PLATFORM_MOUSE_BUTTON_HPP
#define FUBUKI_IO_PLATFORM_MOUSE_BUTTON_HPP

#include <ostream>

#include <core/config/macros.hpp>

namespace fubuki
{

namespace io
{

namespace mouse
{

/// Mouse button.
enum class button
{
    left,    ///< Left mouse button.
    central, ///< Central mouse button.
    right,   ///< Right mouse button.
    ex_1,    ///< Extra button 1.
    ex_2,    ///< Extra button 2.
};

/// Direction in which a mouse wheel can move.
enum class scroll_direction
{
    vertical,
    horizontal,
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, button b)
{
    using enum button;
    switch(b)
    {
        case left   : return out << "left";
        case right  : return out << "right";
        case central: return out << "central";
        case ex_1   : return out << "ex_1";
        case ex_2   : return out << "ex_2";
        default     : return out << "<invalid>: perhaps static_cast?";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, scroll_direction d)
{
    using enum scroll_direction;
    switch(d)
    {
        case vertical  : return out << "vertical";
        case horizontal: return out << "horizontal";
        default        : return out << "<invalid>: perhaps static_cast?";
    }
}

} // namespace mouse

using mouse::operator<<;

} // namespace io

// Don't force user to make that alias.
using io::operator<<;

} // namespace fubuki

#endif // FUBUKI_IO_PLATFORM_MOUSE_BUTTON_HPP
