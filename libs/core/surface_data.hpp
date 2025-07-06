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

#ifndef FUBUKI_CORE_SURFACE_DATA_HPP
#define FUBUKI_CORE_SURFACE_DATA_HPP

#include <variant>

#include "core/vulkan.hpp"

namespace fubuki
{

/// Platform-specific data required to create a surface.
struct surface_data
{
    using invalid = std::monostate;

    struct android
    {
        ANativeWindow* window = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const android&, const android&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const android&, const android&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const android&, const android&) noexcept = default;
    };

    struct directfb
    {
        IDirectFB*        dfb     = nullptr;
        IDirectFBSurface* surface = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const directfb&, const directfb&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const directfb&, const directfb&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const directfb&, const directfb&) noexcept = default;
    };

    struct fuchsia
    {
        zx_handle_t image_pipe_handle = {};

        [[nodiscard]] friend constexpr bool operator==(const fuchsia&, const fuchsia&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const fuchsia&, const fuchsia&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const fuchsia&, const fuchsia&) noexcept = default;
    };

    struct ggp
    {
        GgpStreamDescriptor stream_descriptor = {};

        [[nodiscard]] friend constexpr bool operator==(const ggp&, const ggp&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const ggp&, const ggp&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const ggp&, const ggp&) noexcept = default;
    };

    struct headless
    {
        [[nodiscard]] friend constexpr bool operator==(const headless&, const headless&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const headless&, const headless&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const headless&, const headless&) noexcept = default;
    };

    struct ios
    {
        const void* view = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const ios&, const ios&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const ios&, const ios&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const ios&, const ios&) noexcept = default;
    };

    struct macos
    {
        const void* view = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const macos&, const macos&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const macos&, const macos&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const macos&, const macos&) noexcept = default;
    };

    struct metal
    {
        const CAMetalLayer* layer = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const metal&, const metal&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const metal&, const metal&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const metal&, const metal&) noexcept = default;
    };

    struct qnx_screen
    {
        _screen_context* context = nullptr;
        _screen_window*  window  = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const qnx_screen&, const qnx_screen&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const qnx_screen&, const qnx_screen&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const qnx_screen&, const qnx_screen&) noexcept = default;
    };

    struct vi
    {
        void* window = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const vi&, const vi&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const vi&, const vi&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const vi&, const vi&) noexcept = default;
    };

    struct wayland
    {
        wl_display* display = nullptr;
        wl_surface* surface = nullptr;

        [[nodiscard]] friend constexpr bool operator==(const wayland&, const wayland&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const wayland&, const wayland&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const wayland&, const wayland&) noexcept = default;
    };

    struct win32
    {
        HINSTANCE hinstance = {};
        HWND      hwnd      = {};

        [[nodiscard]] friend constexpr bool operator==(const win32&, const win32&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const win32&, const win32&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const win32&, const win32&) noexcept = default;
    };

    struct xcb
    {
        xcb_connection_t* connection = nullptr;
        xcb_window_t      window     = {};

        [[nodiscard]] friend constexpr bool operator==(const xcb&, const xcb&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const xcb&, const xcb&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const xcb&, const xcb&) noexcept = default;
    };

    struct xlib
    {
        Display* dpy    = nullptr;
        Window   window = {};

        [[nodiscard]] friend constexpr bool operator==(const xlib&, const xlib&) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const xlib&, const xlib&) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const xlib&, const xlib&) noexcept = default;
    };

    using any = std::variant<invalid, android, directfb, fuchsia, ggp, headless, ios, macos, metal, qnx_screen, vi, wayland, win32, xcb, xlib>;

    any value = {};

    [[nodiscard]] friend constexpr bool operator==(const surface_data&, const surface_data&) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const surface_data&, const surface_data&) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const surface_data&, const surface_data&) noexcept = default;
};

} // namespace fubuki

#endif // FUBUKI_CORE_SURFACE_DATA_HPP
