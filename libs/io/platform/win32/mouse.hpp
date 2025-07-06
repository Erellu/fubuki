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

#ifndef FUBUKI_IO_PLATFORM_WIN32_MOUSE_HPP
#define FUBUKI_IO_PLATFORM_WIN32_MOUSE_HPP

#include <core/assertion.hpp>

#include "io/platform/error.hpp"
#include "io/platform/mouse_button.hpp"
#include "io/platform/mouse_state.hpp"
#include "io/platform/views/display.hpp"
#include "io/platform/win32/error.hpp"

#include <windows.h>

namespace fubuki::io::platform::win32::mouse
{

using io::mouse::button;
using io::mouse::state;

[[nodiscard]]
inline bool poll(platform::views::display, button b) noexcept
{
    switch(b)
    {
        case button::left   : return (GetAsyncKeyState(VK_LBUTTON) < 0);
        case button::central: return (GetAsyncKeyState(VK_MBUTTON) < 0);
        case button::right  : return (GetAsyncKeyState(VK_RBUTTON) < 0);
        case button::ex_1   : return (GetAsyncKeyState(VK_XBUTTON1) < 0);
        case button::ex_2   : return (GetAsyncKeyState(VK_XBUTTON2) < 0);
        default             : fubuki_assert(false, "Invalid button. Perhaps static_cast?"); return false;
    }
}

[[nodiscard]]
inline state::buttons buttons_state(platform::views::display dp) noexcept
{
    return {
        .left    = poll(dp, button::left),
        .central = poll(dp, button::central),
        .right   = poll(dp, button::right),
    };
}

[[nodiscard]]
inline std::expected<position2d, platform::error::any> pos(platform::views::display) noexcept
{
    POINT p{};

    if(GetCursorPos(&p))
    {
        return position2d{static_cast<std::int32_t>(p.x), static_cast<std::int32_t>(p.y)};
    }

    const auto error = GetLastError();

    return std::unexpected{error::any{call_info{.result = static_cast<code>(error), .call_literal = "RegisterClassEx"_literal}}};
}

[[nodiscard]]
inline std::expected<state, platform::error::any> current_state(platform::views::display dp) noexcept
{
    auto p = pos(dp);

    if(not p)
    {
        return std::unexpected{p.error()};
    }

    return state{
        .pos    = *p,
        .button = buttons_state(dp),
    };
}

} // namespace fubuki::io::platform::win32::mouse

#endif // FUBUKI_IO_PLATFORM_WIN32_MOUSE_HPP
