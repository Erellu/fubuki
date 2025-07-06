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

#ifndef FUBUKI_IO_PLATFORM_CURRENT_PLATFORM_HPP
#define FUBUKI_IO_PLATFORM_CURRENT_PLATFORM_HPP

#include <functional>

#include <core/surface_data.hpp>

namespace fubuki::io::platform
{

namespace win32
{

class display; // NOLINT(bugprone-forward-declaration-namespace)
class window;  // NOLINT(bugprone-forward-declaration-namespace)

using platform_data = fubuki::surface_data::win32;

using window_ref  = std::reference_wrapper<window>;
using window_cref = std::reference_wrapper<const window>;

struct surface_handle
{
    using value_type = ::HWND;

    value_type value = {};

    friend constexpr bool operator==(const surface_handle&, const surface_handle&) noexcept  = default;
    friend constexpr bool operator!=(const surface_handle&, const surface_handle&) noexcept  = default;
    friend constexpr auto operator<=>(const surface_handle&, const surface_handle&) noexcept = default;

    /// Swaps two objects.
    void swap(surface_handle& other) noexcept { std::swap(value, other.value); }

    /// Swaps two objects.
    friend void swap(surface_handle& a, surface_handle& b) noexcept { a.swap(b); }
};

} // namespace win32

namespace linux_bsd
{

namespace xlib
{

class display; // NOLINT(bugprone-forward-declaration-namespace)
class window;  // NOLINT(bugprone-forward-declaration-namespace)

using platform_data = fubuki::surface_data::xlib;

using window_ref  = std::reference_wrapper<window>;
using window_cref = std::reference_wrapper<const window>;

struct surface_handle
{
    using value_type = ::Window;

    value_type value = {};

    friend constexpr bool operator==(const surface_handle&, const surface_handle&) noexcept  = default;
    friend constexpr bool operator!=(const surface_handle&, const surface_handle&) noexcept  = default;
    friend constexpr auto operator<=>(const surface_handle&, const surface_handle&) noexcept = default;

    /// Swaps two objects.
    void swap(surface_handle& other) noexcept { std::swap(value, other.value); }

    /// Swaps two objects.
    friend void swap(surface_handle& a, surface_handle& b) noexcept { a.swap(b); }
};

} // namespace xlib

namespace wayland
{

class display; // NOLINT(bugprone-forward-declaration-namespace)
class window;  // NOLINT(bugprone-forward-declaration-namespace)

using platform_data = fubuki::surface_data::wayland;

using window_ref  = std::reference_wrapper<window>;
using window_cref = std::reference_wrapper<const window>;

struct surface_handle
{
    using value_type = ::wl_surface*;

    value_type value = {};

    friend constexpr bool operator==(const surface_handle&, const surface_handle&) noexcept  = default;
    friend constexpr bool operator!=(const surface_handle&, const surface_handle&) noexcept  = default;
    friend constexpr auto operator<=>(const surface_handle&, const surface_handle&) noexcept = default;

    /// Swaps two objects.
    void swap(surface_handle& other) noexcept { std::swap(value, other.value); }

    /// Swaps two objects.
    friend void swap(surface_handle& a, surface_handle& b) noexcept { a.swap(b); }
};

} // namespace wayland

class display; // NOLINT(bugprone-forward-declaration-namespace)
class window;  // NOLINT(bugprone-forward-declaration-namespace)

using platform_data  = std::variant<fubuki::surface_data::xlib, fubuki::surface_data::wayland>;
using surface_handle = std::variant<xlib::surface_handle, wayland::surface_handle>;

using window_ref  = std::variant<xlib::window_ref, wayland::window_ref>;
using window_cref = std::variant<xlib::window_cref, wayland::window_cref>;

} // namespace linux_bsd

#if defined(_WIN32)
namespace current = win32;
#elif defined(__unix__)
namespace current = linux_bsd;
#else
    #error Unsupported platform
#endif

} // namespace fubuki::io::platform

#endif // FUBUKI_IO_PLATFORM_CURRENT_PLATFORM_HPP
