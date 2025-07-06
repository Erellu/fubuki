/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2022-2023, Erwan DUHAMEL
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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_MOUSE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_MOUSE_HPP

#include <expected>

#include <core/config/macros.hpp>
#include <core/detail/platform_forward.hpp>

#include "io/platform/error.hpp"
#include "io/platform/mouse_button.hpp"
#include "io/platform/mouse_state.hpp"

namespace fubuki::io::platform::linux_bsd::xlib::mouse
{

using io::mouse::button;
using io::mouse::state;

[[nodiscard]]
FUBUKI_IO_PLATFORM_API std::expected<state, error::any> current_state(Display* d) noexcept;

[[nodiscard]]
inline std::expected<bool, error::any> poll(Display* dp, button b) noexcept
{
    return current_state(dp).transform(
        [b](const state& s) noexcept
        {
            switch(b)
            {
                case mouse::button::left   : return s.button.left;
                case mouse::button::central: return s.button.central;
                case mouse::button::right  : return s.button.right;
                case mouse::button::ex_1   : return s.button.ex_1;
                case mouse::button::ex_2   : return s.button.ex_2;
                default                    : fubuki_assert(false, "Invalid button"); return false;
            }
        });
}

[[nodiscard]]
inline std::expected<state::buttons, error::any> buttons_state(Display* dp) noexcept
{
    return current_state(dp).transform([](const state& s) noexcept { return s.button; });
}

[[nodiscard]]
inline std::expected<position2d, error::any> pos(Display* dp) noexcept
{
    return current_state(dp).transform([](const state& s) noexcept { return s.pos; });
}

} // namespace fubuki::io::platform::linux_bsd::xlib::mouse

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_MOUSE_HPP
