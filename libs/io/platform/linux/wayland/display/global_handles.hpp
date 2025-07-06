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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_HANDLES_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_HANDLES_HPP

#include <utility>

extern "C"
{

struct xdg_wm_base;
struct zxdg_decoration_manager_v1;

struct wl_compositor;
struct wl_subcompositor;
struct wl_shm;
struct wl_seat;
struct wl_output;

} //  extern "C"

namespace fubuki::io::platform::linux_bsd::wayland::display_parts
{

struct global_handle
{
    wl_compositor*    compositor    = nullptr;
    wl_subcompositor* subcompositor = nullptr;
    wl_shm*           shm           = nullptr;
    wl_seat*          seat          = nullptr;
    wl_output*        output        = nullptr;

    xdg_wm_base*                wm_base            = nullptr;
    zxdg_decoration_manager_v1* decoration_manager = nullptr;

    void swap(global_handle& other) noexcept
    {
        std::swap(compositor, other.compositor);
        std::swap(subcompositor, other.subcompositor);
        std::swap(shm, other.shm);
        std::swap(seat, other.seat);
        std::swap(output, other.output);

        std::swap(wm_base, other.wm_base);
        std::swap(decoration_manager, other.decoration_manager);
    }

    friend void swap(global_handle& a, global_handle& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::linux_bsd::wayland::display_parts

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_HANDLES_HPP
