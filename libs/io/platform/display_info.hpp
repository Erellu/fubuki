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

#ifndef FUBUKI_IO_PLATFORM_DISPLAY_INFO_HPP
#define FUBUKI_IO_PLATFORM_DISPLAY_INFO_HPP

#include <optional>

#include <core/config/setup.hpp>

namespace fubuki::io::platform::information
{

/// Platform-specific hints for fubuki::io::window and related facilities.
struct display
{
    /// Name of the display to connect to.
    /// On Linux, this is forwarded to XOpenDisplay or to wl_display_connect.
    /// On Windows, this hint is ignored.
    std::optional<const char*> display_name = {};

    /// Window system to prefer.
    /// On Linux, the value is ignored if it is not configuration::window_system::xlib or configuration::window_system::wayland.
    /// On Windows, this hint is ignored.
    std::optional<configuration::window_system> window_system = {};

    void swap(display& other) noexcept
    {
        display_name.swap(other.display_name);
        window_system.swap(other.window_system);
    }

    friend void swap(display& a, display& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::information

#endif // FUBUKI_IO_PLATFORM_DISPLAY_INFO_HPP
