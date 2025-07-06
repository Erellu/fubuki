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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_INPUT_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_INPUT_HPP

#include <optional>

#include "io/platform/linux/fd_timer.hpp"
#include "io/platform/linux/wayland/display/input_state.hpp"
#include "io/platform/linux/wayland/seat.hpp"
#include "io/platform/linux/xkb/context.hpp"
#include "io/platform/linux/xkb/keymap.hpp"
#include "io/platform/linux/xkb/state.hpp"

namespace fubuki::io::platform::linux_bsd::wayland::display_parts
{

struct input
{
    using state = display_parts::input_state;

    struct ctx
    {
        struct kb
        {
            xkb::context               handle;
            fd_timer                   repeat_timer;
            std::optional<xkb::keymap> keymap = {};
            std::optional<xkb::state>  state  = {};

            /// Swaps two objects.
            void swap(kb& other) noexcept
            {
                handle.swap(other.handle);
                repeat_timer.swap(other.repeat_timer);
                keymap.swap(other.keymap);
                state.swap(other.state);
            }

            /// Swaps two objects.
            friend void swap(kb& a, kb& b) noexcept { a.swap(b); }
        };

        std::optional<kb> keyboard = {};

        /// Swaps two objects.
        void swap(ctx& other) noexcept { keyboard.swap(other.keyboard); }

        /// Swaps two objects.
        friend void swap(ctx& a, ctx& b) noexcept { a.swap(b); }
    };

    std::optional<wayland::seat> seat    = {};
    ctx                          context = {};
    state                        status  = {};

    /// Swaps two objects.
    void swap(input& other) noexcept
    {
        seat.swap(other.seat);
        context.swap(other.context);
    }

    /// Swaps two objects.
    friend void swap(input& a, input& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::linux_bsd::wayland::display_parts

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_INPUT_HPP
