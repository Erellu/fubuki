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

#ifndef FUBUKI_CORE_DETAIL_PLATFORM_FORWARD_HPP
#define FUBUKI_CORE_DETAIL_PLATFORM_FORWARD_HPP

#include <cstdint>

// Avoid #including <windows.h>, <xlib.h>, etc.
// Per-platform Vulkan headers only need a few typedefs, there is no need to expose these headers everywhere.
// This is provided as a separate header to avoid having to expose Vulkan headers where they are not needed

// NOLINTBEGIN
// The following are extracted from the respective APIS (Windows, Xlib, Wayland...).
// Don't touch!

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wreserved-identifier"
#endif

extern "C"
{

//------------------------------------------------------------------------------
// Android

// Nothing yet, vulkan_android.h provides the forward declarations it needs

//------------------------------------------------------------------------------
// Fuschia

using zx_handle_t = std::uint32_t;

//------------------------------------------------------------------------------
// IOS

// Nothing required yet

//------------------------------------------------------------------------------
// MacOS

// Nothing required yet

//------------------------------------------------------------------------------
// Metal

// Nothing required yet

//------------------------------------------------------------------------------
// Vi

// Nothing required yet

//------------------------------------------------------------------------------
// Wayland

struct wl_display;
struct wl_surface;

//------------------------------------------------------------------------------
// Win32

struct HINSTANCE__;
struct HWND__;
struct HMONITOR__;
struct _SECURITY_ATTRIBUTES;

typedef unsigned long        DWORD;
typedef const wchar_t*       LPCWSTR;
typedef void*                HANDLE;
typedef HINSTANCE__*         HINSTANCE;
typedef HWND__*              HWND;
typedef HMONITOR__*          HMONITOR;
typedef _SECURITY_ATTRIBUTES SECURITY_ATTRIBUTES;

//------------------------------------------------------------------------------
// XCB

using xcb_window_t   = std::uint32_t;
using xcb_visualid_t = std::uint32_t;
struct xcb_connection_t;

//------------------------------------------------------------------------------
// Xlib

struct _XDisplay;

using XID      = unsigned long;
using VisualID = unsigned long;
using Window   = XID;
using Display  = _XDisplay;

//------------------------------------------------------------------------------
// Direct FB

struct _IDirectFB;
struct _IDirectFBSurface;

using IDirectFB        = _IDirectFB;
using IDirectFBSurface = _IDirectFBSurface;

//------------------------------------------------------------------------------
// Xlib Xrandr

using RROutput = XID;
using RRCrtc   = XID;
using RRMode   = XID;

//------------------------------------------------------------------------------
// GGP

using GgpStreamDescriptor = std::uint32_t;
using GgpFrameToken       = std::uint64_t;

//------------------------------------------------------------------------------
// QNX Screen

// Nothing required yet

} // extern "C"

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif // defined(__clang__)

// NOLINTEND

#endif // FUBUKI_CORE_DETAIL_PLATFORM_FORWARD_HPP
