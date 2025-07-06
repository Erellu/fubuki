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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_GLOBAL_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_GLOBAL_HPP

#include "io/platform/linux/wayland/display/global_handles.hpp"
#include "io/platform/linux/wayland/display/input.hpp"
#include "io/platform/linux/wayland/display/properties.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

/// Global objects retrieved through the registry of each display.
struct display_global
{
    using handles    = display_parts::global_handle;
    using properties = display_parts::properties;
    using inputs     = display_parts::input;

    handles    handle   = {};
    properties property = {};
    inputs     input    = {};

    void swap(display_global& other) noexcept
    {
        handle.swap(other.handle);
        property.swap(other.property);
        input.swap(other.input);
    }

    friend void swap(display_global& a, display_global& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_GLOBAL_HPP
