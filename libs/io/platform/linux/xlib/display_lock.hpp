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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_DISPLAY_LOCK_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_DISPLAY_LOCK_HPP

#include <mutex>

#include <core/config/macros.hpp>

#include "io/platform/views/display.hpp"

namespace fubuki::io::platform::linux_bsd::xlib
{

/**
 * Locks a display for a given scope. Equivalent to a call to `XLockDisplay` upon construction, and a call to `XUnlockDisplay` upon destruction.
 */
class display_lock
{
public:

    FUBUKI_IO_PLATFORM_API display_lock(views::display::xlib) noexcept;
    FUBUKI_IO_PLATFORM_API display_lock(std::adopt_lock_t, views::display::xlib dp) noexcept : m_display{dp} {}

    FUBUKI_IO_PLATFORM_API ~display_lock() noexcept;

    display_lock(const display_lock&)            = delete;
    display_lock& operator=(const display_lock&) = delete;
    display_lock(display_lock&&)                 = delete;
    display_lock& operator=(display_lock&&)      = delete;

    /// Returns the underlying display.
    [[nodiscard]] auto display() const noexcept { return m_display; }

private:

    views::display::xlib m_display = {};
    bool                 m_active  = true;
};

} // namespace fubuki::io::platform::linux_bsd::xlib

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_DISPLAY_LOCK_HPP
