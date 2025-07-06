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

#ifndef FUBUKI_IO_PLATFORM_WIN32_DETAIL_SEND_EVENT_HPP
#define FUBUKI_IO_PLATFORM_WIN32_DETAIL_SEND_EVENT_HPP

#include <expected>

#include <core/constants.hpp>
#include <core/surface_data.hpp>

#include "io/platform/event/events.hpp"
#include "io/platform/event/send_error.hpp"
#include "io/platform/win32/error.hpp"
#include "io/platform/win32/keyboard.hpp"

namespace fubuki::io::platform::win32::detail::send_event
{

struct message
{
    UINT   id      = {};
    WPARAM w_param = {};
    LPARAM l_param = {};
};

using any_translation = std::variant<std::monostate, INPUT, message>;

inline constexpr LPARAM make_lparam(const position2d& p) noexcept { return MAKELPARAM(p.x, p.y); }

inline constexpr LPARAM make_lparam(const dimension2d& p) noexcept { return MAKELPARAM(p.width, p.height); }

template<typename event_type>
[[nodiscard]] inline std::expected<message, event::send_error::any> to_message(const event_type& e) noexcept
{
    namespace error          = event::send_error;
    namespace win32_keyboard = io::platform::win32::keyboard;

    if constexpr(std::is_same_v<event_type, event::key::press>)
    {
        // LPARAM not supported yet for this message
        return message{WM_KEYDOWN, static_cast<WPARAM>(win32_keyboard::to_windows(e.which)), {}};
    }

    else if constexpr(std::is_same_v<event_type, event::key::release>)
    {
        // LPARAM not supported yet for this message
        return message{WM_KEYUP, static_cast<WPARAM>(win32_keyboard::to_windows(e.which)), {}};
    }

    // ------------------------------ Mouse events -------------------------------- //

    else if constexpr(std::is_same_v<event_type, event::mouse::click>)
    {
        using io::mouse::button;
        switch(e.which)
        {
            case(button::left):
            {
                return message{WM_LBUTTONDOWN, {}, make_lparam(e.where)};
            }
            case(button::central):
            {
                return message{WM_MBUTTONDOWN, {}, make_lparam(e.where)};
            }
            case(button::right):
            {
                return message{WM_RBUTTONDOWN, {}, make_lparam(e.where)};
            }
            case(button::ex_1):
            {
                return message{WM_XBUTTONDOWN, MAKEWPARAM(0, XBUTTON1), make_lparam(e.where)};
            }
            case(button::ex_2):
            {
                return message{WM_XBUTTONDOWN, MAKEWPARAM(0, XBUTTON2), make_lparam(e.where)};
            }
            default:
            {
                fubuki_assert(false, "Unreachable code. Perhaps static_cast?");
                return std::unexpected{error::any{error::unknown{}}};
            }
        }
    }

    else if constexpr(std::is_same_v<event_type, event::mouse::double_click>)
    {
        using io::mouse::button;
        switch(e.which)
        {
            case(button::left):
            {
                return message{WM_LBUTTONDBLCLK, {}, make_lparam(e.where)};
            }
            case(button::central):
            {
                return message{WM_MBUTTONDBLCLK, {}, make_lparam(e.where)};
            }
            case(button::right):
            {
                return message{WM_RBUTTONDBLCLK, {}, make_lparam(e.where)};
            }
            case(button::ex_1):
            {
                return message{WM_XBUTTONDBLCLK, MAKEWPARAM(0, XBUTTON1), make_lparam(e.where)};
            }
            case(button::ex_2):
            {
                return message{WM_XBUTTONDBLCLK, MAKEWPARAM(0, XBUTTON2), make_lparam(e.where)};
            }
            default:
            {
                fubuki_assert(false, "Unreachable code. Perhaps static_cast?");
                return std::unexpected{error::any{error::unknown{}}};
            }
        }
    }

    else if constexpr(std::is_same_v<event_type, event::mouse::release>)
    {
        using io::mouse::button;
        switch(e.which)
        {
            case(button::left):
            {
                return message{WM_LBUTTONUP, {}, make_lparam(e.where)};
            }
            case(button::central):
            {
                return message{WM_MBUTTONUP, {}, make_lparam(e.where)};
            }
            case(button::right):
            {
                return message{WM_RBUTTONUP, {}, make_lparam(e.where)};
            }
            case(button::ex_1):
            {
                return message{WM_XBUTTONUP, MAKEWPARAM(0, XBUTTON1), make_lparam(e.where)};
            }
            case(button::ex_2):
            {
                return message{WM_XBUTTONUP, MAKEWPARAM(0, XBUTTON2), make_lparam(e.where)};
            }
            default:
            {
                fubuki_assert(false, "Unreachable code. Perhaps static_cast?");
                return std::unexpected{error::any{error::unknown{}}};
            }
        }
    }

    else if constexpr(std::is_same_v<event_type, event::mouse::wheel>)
    {
        // No support for lower word of wparam yet
        // In fact, it's useless since it's used to precise the state of keyboard / mouse keys, which fubuki already provides.
        return message{WM_MOUSEWHEEL, MAKEWPARAM(0, e.ticks * WHEEL_DELTA), make_lparam(e.where)};
    }

    else if constexpr(std::is_same_v<event_type, event::mouse::move>)
    {
        return message{WM_MOUSEMOVE, {}, make_lparam(e.where)};
    }

    // ------------------------------ Window events ------------------------------- //

    else if constexpr(std::is_same_v<event_type, event::window::move>)
    {
        return message{WM_MOVE, {}, make_lparam(e.next)};
    }

    else if constexpr(std::is_same_v<event_type, event::window::resize>)
    {
        return message{WM_SIZE, {}, make_lparam(e.next)};
    }

    else if constexpr(std::is_same_v<event_type, event::window::focus>)
    {
        const auto message_id = e.next ? static_cast<UINT>(WM_SETFOCUS) : static_cast<UINT>(WM_KILLFOCUS);

        return message{message_id, {}, {}};
    }

    else if constexpr(std::is_same_v<event_type, event::window::close>)
    {
        return message{WM_CLOSE, {}, {}};
    }

    else if constexpr(std::is_same_v<event_type, event::window::enable>)
    {
        return message{WM_ENABLE, static_cast<WPARAM>(e.next), {}};
    }

    // ------------------------------ Invalid events  ------------------------------- //

    else if constexpr(std::is_same_v<event_type, event::window::activate> or std::is_same_v<event_type, event::window::destroy_start>
                      or std::is_same_v<event_type, event::window::destroy_end> or std::is_same_v<event_type, event::user::custom>)
    {
        return std::unexpected{error::any{error::not_supported{{e}}}};
    }

    // ------------------------------ Invalid argument type  ------------------------------- //

    else
    {
        static_assert(fubuki::detail::always_false<event_type>,
                      "Invalid template argument. Some event has been added but this function has "
                      "not "
                      "been "
                      "updated"
                      ".");
        return {};
    }
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-union-access)

template<event::mouse::any mouse_event_type>
[[nodiscard]] inline std::expected<any_translation, event::send_error::any> translate(const mouse_event_type& event) noexcept
{
    namespace error = event::send_error;

    if constexpr(std::is_same_v<mouse_event_type, event::mouse::double_click>)
    {
        return to_message(event); // Not possible using send_input
    }
    else // NOTE: this is split like this to please MSVC, which otherwise complains about unreachable code
    {
        DWORD mouse_data = {}; // NOLINT(misc-const-correctness): may be written to depending on template parameter
        DWORD dw_flags   = {}; // NOLINT(misc-const-correctness): may be written to depending on template parameter
        LONG  dx         = 0;  // NOLINT(misc-const-correctness): may be written to depending on template parameter
        LONG  dy         = 0;  // NOLINT(misc-const-correctness): may be written to depending on template parameter

        if constexpr(std::is_same_v<mouse_event_type, event::mouse::click>)
        {
            using io::mouse::button;
            switch(event.which)
            {
                case(button::left):
                {
                    dw_flags = MOUSEEVENTF_LEFTDOWN;
                    break;
                }
                case(button::central):
                {
                    dw_flags = MOUSEEVENTF_MIDDLEDOWN;
                    break;
                }
                case(button::right):
                {
                    dw_flags = MOUSEEVENTF_RIGHTDOWN;
                    break;
                }
                case(button::ex_1):
                {
                    dw_flags   = MOUSEEVENTF_XDOWN;
                    mouse_data = XBUTTON1;
                    break;
                }
                case(button::ex_2):
                {
                    dw_flags   = MOUSEEVENTF_XDOWN;
                    mouse_data = XBUTTON2;
                    break;
                }
                default:
                {
                    fubuki_assert(false, "Unreachable code. Perhaps static_cast?");
                    return std::unexpected{error::any{error::unknown{}}};
                }
            }
        }
        else if constexpr(std::is_same_v<mouse_event_type, event::mouse::release>)
        {
            using io::mouse::button;
            switch(event.which)
            {
                case(button::left):
                {
                    dw_flags = MOUSEEVENTF_LEFTUP;
                    break;
                }
                case(button::central):
                {
                    dw_flags = MOUSEEVENTF_MIDDLEUP;
                    break;
                }
                case(event::mouse::button::right):
                {
                    dw_flags = MOUSEEVENTF_RIGHTUP;
                    break;
                }
                case(event::mouse::button::ex_1):
                {
                    dw_flags   = MOUSEEVENTF_XUP;
                    mouse_data = XBUTTON1;
                    break;
                }
                case(event::mouse::button::ex_2):
                {
                    dw_flags   = MOUSEEVENTF_XUP;
                    mouse_data = XBUTTON2;
                    break;
                }
                default:
                {
                    fubuki_assert(false, "Unreachable code. Perhaps static_cast?");
                    return std::unexpected{error::any{error::unknown{}}};
                }
            }
        }
        else if constexpr(std::is_same_v<mouse_event_type, event::mouse::scroll>)
        {
            dw_flags   = MOUSEEVENTF_WHEEL;
            mouse_data = static_cast<DWORD>(event.ticks * WHEEL_DELTA); // NOLINT(bugprone-misplaced-widening-cast)
        }
        else if constexpr(std::is_same_v<mouse_event_type, event::mouse::move>)
        {
            dw_flags = MOUSEEVENTF_ABSOLUTE;
            dx       = event.where.x;
            dy       = event.where.y;
        }

        INPUT result = {};
        result.type  = INPUT_MOUSE;
        result.mi    = {
               .dx          = dx,         // Always absolute
               .dy          = dy,         // Always absolute
               .mouseData   = mouse_data, //
               .dwFlags     = dw_flags,   //
               .time        = 0,          // Let the system decide for the timestamp
               .dwExtraInfo = {},
        };

        return any_translation{result};
    }
}

template<event::key::any key_event_type>
[[nodiscard]] inline std::expected<any_translation, event::send_error::any> translate(const key_event_type& event) noexcept
{
    namespace win32_keyboard = io::platform::win32::keyboard;

    // Only two types
    constexpr auto type = std::is_same_v<std::decay_t<key_event_type>, event::key::press> ? 0x00 : KEYEVENTF_KEYUP;

    INPUT result = {};
    result.type  = INPUT_KEYBOARD;
    result.ki    = {
           .wVk         = static_cast<WORD>(win32_keyboard::to_windows(event.which)),
           .wScan       = {}, // TODO: unicode stuff
           .dwFlags     = type,
           .time        = 0, // Let the system decide for the timestamp
           .dwExtraInfo = {},
    };

    return result;
}

template<event::window::any window_event_type>
[[nodiscard]] inline std::expected<any_translation, event::send_error::any> translate(const window_event_type& event) noexcept
{
    // The doc says the following, but this looks like a typo...
    /*
     * wParamL
     *
     *   Type: WORD
     *
     *   The low-order word of the lParam parameter for uMsg.
     *
     * wParamH
     *
     *   Type: WORD
     *
     *   The high-order word of the lParam parameter for uMsg.
     */
    // BUT the following seems to work, so I guess it's correct

    const auto as_message = to_message(event);

    if(not as_message)
    {
        return std::unexpected{as_message.error()};
    }

    INPUT result = {};
    result.type  = INPUT_HARDWARE;
    result.hi    = {
           .uMsg    = as_message->id,
           .wParamL = LOWORD(as_message->l_param),
           .wParamH = HIWORD(as_message->l_param),
    };

    return any_translation{result};
}

[[nodiscard]] inline std::expected<any_translation, event::send_error::any> translate(const event::user::custom&) noexcept
{
    // monostate, put in the custom event queue (caught in translate(span))
    // This function exists for template compatibility
    return any_translation{};
}

[[nodiscard]] inline std::expected<any_translation, event::send_error::any> translate(const event::any& event) noexcept
{
    return std::visit([](const auto& e) noexcept { return translate(e); }, event.value);
}

[[nodiscard]] inline std::expected<void, event::send_error::any> send(const surface_data::win32& data, const message& event) noexcept
{
    namespace error = event::send_error;

    const auto handle = data.hwnd;

    // PostMessage is better than SendMessage: https://stackoverflow.com/questions/18526961/sendmessage-and-postmessage-which-one-is-better-to-use
    // TL;DR : it's asynchronous, which is what we want here

    // ----------------------------- Keyboard events ------------------------------ //

    if(const auto r = PostMessage(handle, event.id, event.w_param, event.l_param); r == FALSE)
    {
        const auto win32_error_code = GetLastError();
        const auto error_code       = static_cast<code>(win32_error_code);

        return std::unexpected{error::any{
            error::os{call_info{.result = {error_code}, .call_literal = "PostMessage(handle, event.id, event.w_param, event.l_param)"_literal}}}};
    }

    return {};
}

// NOLINTEND(cppcoreguidelines-pro-type-union-access)

} // namespace fubuki::io::platform::win32::detail::send_event

#endif // FUBUKI_IO_PLATFORM_WIN32_DETAIL_SEND_EVENT_HPP
