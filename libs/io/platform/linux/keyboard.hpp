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

#ifndef FUBUKI_IO_PLATFORM_LINUX_KEYBOARD_HPP
#define FUBUKI_IO_PLATFORM_LINUX_KEYBOARD_HPP

#include "io/platform/keyboard_key.hpp"
#include "io/platform/linux/xlib/keyboard.hpp"
#include "io/platform/views/display.hpp"

namespace fubuki::io::platform::linux_bsd::keyboard
{

using key           = io::keyboard::key;
using modifier_mask = io::keyboard::modifier_mask;

[[nodiscard]]
inline std::expected<bool, error::any> poll(views::display d, key k) noexcept
{
    using dp = views::display;

    if(const auto* xlib_display = std::get_if<dp::xlib>(std::addressof(d.value)))
    {
        return xlib::keyboard::poll(xlib_display->handle, k);
    }

    if(std::holds_alternative<dp::wayland>(d.value))
    {
        return std::unexpected{error::operation_not_supported{configuration::window_system::wayland}};
    }

    return std::unexpected{error::unknown{}};
}

[[nodiscard]]
inline std::expected<modifier_mask, error::any> current_modifiers(views::display d) noexcept
{
    using dp = views::display;

    if(const auto* xlib_display = std::get_if<dp::xlib>(std::addressof(d.value)))
    {
        return xlib::keyboard::current_modifiers(xlib_display->handle);
    }

    if(std::holds_alternative<dp::wayland>(d.value))
    {
        return std::unexpected{error::operation_not_supported{configuration::window_system::wayland}};
    }

    return std::unexpected{error::unknown{}};
}

} // namespace fubuki::io::platform::linux_bsd::keyboard

#endif // FUBUKI_IO_PLATFORM_LINUX_KEYBOARD_HPP
