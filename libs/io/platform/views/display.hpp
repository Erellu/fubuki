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

#ifndef FUBUKI_IO_PLATFORM_VIEWS_DISPLAY_HPP
#define FUBUKI_IO_PLATFORM_VIEWS_DISPLAY_HPP

#include <variant>

#include <core/detail/platform_forward.hpp>

namespace fubuki::io::platform
{

namespace views
{

/// View of a display, in the sense of Linux' XOpenDisplay/wl_display_connect.
struct display
{
    using invalid = std::monostate;

    struct wayland
    {
        wl_display* handle = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const wayland&, const wayland&)  = default;
        [[nodiscard]] friend constexpr bool operator!=(const wayland&, const wayland&)  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const wayland&, const wayland&) = default;

        /// Swaps two objects.
        void swap(wayland& other) noexcept { std::swap(handle, other.handle); }

        /// Swaps two objects.
        friend void swap(wayland& a, wayland& b) noexcept { a.swap(b); }
    };

    struct win32
    {
        [[nodiscard]] friend constexpr bool operator==(const win32&, const win32&)  = default;
        [[nodiscard]] friend constexpr bool operator!=(const win32&, const win32&)  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const win32&, const win32&) = default;

        /// Swaps two objects.
        void swap(win32&) noexcept {}

        /// Swaps two objects.
        friend void swap(win32& a, win32& b) noexcept { a.swap(b); }
    };

    struct xlib
    {
        Display* handle = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const xlib&, const xlib&)  = default;
        [[nodiscard]] friend constexpr bool operator!=(const xlib&, const xlib&)  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const xlib&, const xlib&) = default;

        /// Swaps two objects.
        void swap(xlib& other) noexcept { std::swap(handle, other.handle); }

        /// Swaps two objects.
        friend void swap(xlib& a, xlib& b) noexcept { a.swap(b); }
    };

    using any = std::variant<invalid, wayland, win32, xlib>;

    any value = {};

    [[nodiscard]] friend constexpr bool operator==(const display&, const display&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const display&, const display&)  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const display&, const display&) = default;

    /// Swaps two objects.
    void swap(display& other) noexcept { value.swap(other.value); }

    /// Swaps two objects.
    friend void swap(display& a, display& b) noexcept { a.swap(b); }
};

} // namespace views

using display_view = views::display;

} // namespace fubuki::io::platform

#endif // FUBUKI_IO_PLATFORM_VIEWS_DISPLAY_HPP
