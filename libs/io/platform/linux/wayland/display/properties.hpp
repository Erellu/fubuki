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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_PROPERTIES_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_PROPERTIES_HPP

#include <cstdint>
#include <string>

#include <core/small_vector.hpp>

#include "io/platform/screen_properties.hpp"

namespace fubuki::io::platform::linux_bsd::wayland::display_parts
{

struct properties
{
    struct seat_capabilities
    {
        std::uint32_t flags = {};
        std::string   name  = {};

        void swap(seat_capabilities& other) noexcept
        {
            std::swap(flags, other.flags);
            name.swap(other.name);
        }

        friend void swap(seat_capabilities& a, seat_capabilities& b) noexcept { a.swap(b); }
    };

    seat_capabilities                                                         seat    = {};
    small_vector<screen_properties, screen_properties::typical_monitor_count> screens = {};

    void swap(properties& other) noexcept
    {
        seat.swap(other.seat);
        screens.swap(other.screens);
    }

    friend void swap(properties& a, properties& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::linux_bsd::wayland::display_parts

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_PROPERTIES_HPP
