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

#ifndef FUBUKI_DISPLAY_PLATFORM_LINUX_X11_DETAIL_CODE_HPP
#define FUBUKI_DISPLAY_PLATFORM_LINUX_X11_DETAIL_CODE_HPP

#include "io/platform/linux/xlib/code.hpp"

#include <X11/Xlib.h>

namespace fubuki::io::platform::linux_bsd::xlib::detail
{

[[nodiscard]] inline constexpr auto from_xlib(const int c) noexcept
{
    switch(c)
    {
        case(Success)          : return code::success;
        case(BadRequest)       : return code::bad_request;
        case(BadValue)         : return code::bad_value;
        case(BadWindow)        : return code::bad_window;
        case(BadPixmap)        : return code::bad_pixmap;
        case(BadAtom)          : return code::bad_atom;
        case(BadCursor)        : return code::bad_cursor;
        case(BadFont)          : return code::bad_font;
        case(BadMatch)         : return code::bad_match;
        case(BadDrawable)      : return code::bad_drawable;
        case(BadAccess)        : return code::bad_access;
        case(BadAlloc)         : return code::bad_alloc;
        case(BadColor)         : return code::bad_colour;
        case(BadGC)            : return code::bad_gc;
        case(BadIDChoice)      : return code::bad_id_choice;
        case(BadName)          : return code::bad_name;
        case(BadLength)        : return code::bad_length;
        case(BadImplementation): return code::bad_implementation;

        default: return code::unknown;
    }
}

} // namespace fubuki::io::platform::linux_bsd::xlib::detail

#endif // FUBUKI_DISPLAY_PLATFORM_LINUX_X11_DETAIL_CODE_HPP
