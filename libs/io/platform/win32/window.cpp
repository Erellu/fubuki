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

#include <algorithm>

#include "io/platform/win32/window.hpp"

#include "io/platform/event/events.hpp"
#include "io/platform/win32/error.hpp"
#include "io/platform/win32/keyboard.hpp"
#include "io/platform/win32/window_registry.hpp"

#include <dwmapi.h>
#include <windowsx.h>

namespace fubuki::io::platform::win32
{

/********************************************************************************/
/*                               FREE FUNCTIONS                                 */
/********************************************************************************/

namespace
{

[[nodiscard]]
constexpr event::cause from_windows(const INPUT_MESSAGE_SOURCE& origin) noexcept
{
    event::cause result = {};

    switch(origin.originId)
    {
        default:
        case IMO_UNAVAILABLE: result.provenance = event::origin::unknown; break;
        case IMO_HARDWARE   : result.provenance = event::origin::hardware; break;
        case IMO_INJECTED   : result.provenance = event::origin::artificial; break;
        case IMO_SYSTEM     : result.provenance = event::origin::system; break;
    }

    switch(origin.deviceType)
    {
        default:
        case IMDT_UNAVAILABLE: result.from = event::device::unknown; break;
        case IMDT_KEYBOARD   : result.from = event::device::keyboard; break;
        case IMDT_MOUSE      : result.from = event::device::mouse; break;
        case IMDT_TOUCH      : result.from = event::device::touchscreen; break;
        case IMDT_PEN        : result.from = event::device::pen; break;
#if WINVER >= 0x0603 // Required for MinGW with LLVM (clang-17)
        case IMDT_TOUCHPAD: result.from = event::device::touchpad; break;
#endif
    }

    return result;
}

[[nodiscard]]
auto current_event_source() noexcept
{
    // The current implementation sets events triggered by PostMessage to be of "unknown" source.
    // That makes sense, see https://stackoverflow.com/a/53437908/11910702.
    // Microsoft seems to recommand SendInput too:
    // - https://learn.microsoft.com/en-gb/windows/win32/api/winuser/nf-winuser-sendinput
    // - https://devblogs.microsoft.com/oldnewthing/20050530-11/?p=35513
    // This makes MUCH more sense any way (at least for keyboard/mouse), and produces the correct behaviour here
    // And we can send multiple events at the time (though window events still have to get "simulated" with another mechanism).
    // This is an easy optimisation because we can just std::views::filter the events we're interested in.
    // Alternatively, we may consider having a fallback to inspect what gets passed to SetWindowsHookEx.

    constexpr INPUT_MESSAGE_SOURCE unknown_source = {.deviceType = IMDT_UNAVAILABLE, .originId = IMO_UNAVAILABLE};
    auto                           source         = unknown_source;

    if(GetCurrentInputMessageSource(&source) == TRUE)
    {
        return from_windows(source);
    }

    return from_windows(unknown_source);
}

/// Windows API callback function.
LRESULT CALLBACK winproc(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param) noexcept
{
    if(auto w = window_registry::window_of({hwnd}); w.has_value())
    {
        auto& win = w->get();

        if(process(win, msg, w_param, l_param))
        {
            return 0;
        }
    }

    return DefWindowProc(hwnd, msg, w_param, l_param);
}

//------------------------------------------------------------------------------

// TODO: change style dynamically (possible with SWP_FRAMECHANGED in SetWindowPos)

[[nodiscard]]
constexpr DWORD windows_style_mask(const window_style s) noexcept
{
    // See https://docs.microsoft.com/en-gb/windows/win32/winmsg/window-styles

    switch(s)
    {
        case window_style::borderless: return WS_POPUP | WS_THICKFRAME | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX;
        case window_style::os_default:
        case window_style::windowed  :
        default                      : return WS_OVERLAPPEDWINDOW; // So that transparency is settable
    }
}

} // anonymous namespace

[[nodiscard]] bool process(window& w, auto&&... params) noexcept
{
    constexpr auto impl = [](window& win, UINT msg, WPARAM w_param, LPARAM l_param) noexcept -> bool // NOLINT(bugprone-easily-swappable-parameters)
    {
        namespace win32_keyboard = io::platform::win32::keyboard;

        const auto source = current_event_source();

        switch(msg)
        {
            // ------------------------------ Window events ------------------------------- //
            case(WM_DESTROY):
            {
                win.m_event_dispatcher.process(win.data(), event::window::destroy_start{});

                win.m_state.closed = true;

                return true;
            }

            case(WM_NCDESTROY):
            {
                // This is necessarly AFTER WM_DESTROY, i.e handle has already been removed from registry
                // User cannot trigger this event through display::trigger.
                win.m_event_dispatcher.process(win.data(), event::window::destroy_end{});

                return true;
            }

            case(WM_PAINT):
            {
                PAINTSTRUCT ps;
                HDC         hdc = BeginPaint(win.platform_data().hwnd, &ps);
                FillRect(
                    hdc,
                    &ps.rcPaint,
                    reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1)); // NOLINT(performance-no-int-to-ptr, cppcoreguidelines-pro-type-reinterpret-cast)
                EndPaint(win.platform_data().hwnd, &ps);
                // TODO: event
                return true;
            }

            case(WM_SIZE):
            {
                RECT rect;
                if(GetWindowRect(win.platform_data().hwnd, &rect))
                {
                    const auto old_size = win.m_info.size;
                    const auto width    = rect.right - rect.left;
                    const auto height   = rect.bottom - rect.top;

                    win.m_info.size = {static_cast<std::int32_t>(width), static_cast<std::int32_t>(height)};

                    const event::window::resize event{
                        .previous = old_size,
                        .next     = win.m_info.size,
                        .source   = source,
                    };

                    win.m_event_dispatcher.process(win.data(), event);
                }

                return true;
            }

            case(WM_MOVE):
            {
                RECT rect;
                if(GetWindowRect(win.platform_data().hwnd, &rect))
                {
                    const auto old_position = win.m_info.coordinates;
                    const auto x            = rect.left;
                    const auto y            = rect.top;

                    win.m_info.coordinates = {static_cast<std::int32_t>(x), static_cast<std::int32_t>(y)};

                    const event::window::move event{
                        .previous = old_position,
                        .next     = win.info().coordinates,
                        .source   = source,
                    };

                    win.m_event_dispatcher.process(win.data(), event);
                }

                return true;
            }

            case(WM_CLOSE):
            {
                const auto event = event::window::close{
                    .source = source,
                };

                if(win.m_event_dispatcher.process(win.data(), event))
                {
                    win.m_state.closed = true;
                    DestroyWindow(win.m_data.hwnd);
                    win.m_data.hwnd = nullptr;
                    return true;
                } // else: ignore, user canceled

                break;
            }

            case(WM_ENABLE):
            {
                const event::window::enable event{
                    .previous = win.m_state.enabled,
                    .next     = static_cast<bool>(w_param),
                    .source   = source,
                };

                win.m_state.enabled = static_cast<bool>(w_param);

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_ACTIVATE):
            {
                win.m_state.activated = true;

                const event::window::activate event{
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case WM_SETFOCUS:
            {
                const event::window::focus event{
                    .previous = win.m_state.focused,
                    .next     = true,
                    .source   = source,
                };

                win.m_state.focused = true;

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case WM_KILLFOCUS:
            {
                const event::window::focus event{
                    .previous = win.m_state.focused,
                    .next     = false,
                    .source   = source,
                };

                win.m_state.focused = false;

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

                // ------------------------------ Mouse events -------------------------------- //

                //-------------------------------------
                // Left button

            case(WM_LBUTTONDOWN):
            {
                const event::mouse::click event{
                    .which  = io::mouse::button::left,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_LBUTTONUP):
            {
                const event::mouse::release event{
                    .which  = io::mouse::button::left,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_LBUTTONDBLCLK):
            {
                const event::mouse::double_click event{
                    .which  = io::mouse::button::left,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

                //-------------------------------------
                // Right button

            case(WM_RBUTTONDOWN):
            {
                const event::mouse::click event{
                    .which  = io::mouse::button::right,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_RBUTTONUP):
            {
                const event::mouse::release event{
                    .which  = io::mouse::button::right,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_RBUTTONDBLCLK):
            {
                const event::mouse::double_click event{
                    .which  = io::mouse::button::right,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

                //-------------------------------------
                // Central button

            case(WM_MBUTTONDOWN):
            {
                const event::mouse::click event{
                    .which  = io::mouse::button::central,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_MBUTTONUP):
            {
                const event::mouse::release event{
                    .which  = io::mouse::button::central,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_MBUTTONDBLCLK):
            {
                const event::mouse::double_click event{
                    .which  = io::mouse::button::central,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

                //-------------------------------------
                // Extra buttons

            case(WM_XBUTTONDOWN):
            {
                const auto win32_x_button = GET_XBUTTON_WPARAM(w_param);
                const auto button         = win32_x_button == XBUTTON1 ? io::mouse::button::ex_1 : io::mouse::button::ex_2;

                const event::mouse::click event{
                    .which  = button,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_XBUTTONUP):
            {
                const auto win32_x_button = GET_XBUTTON_WPARAM(w_param);
                const auto button         = win32_x_button == XBUTTON1 ? io::mouse::button::ex_1 : io::mouse::button::ex_2;

                const event::mouse::release event{
                    .which  = button,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_XBUTTONDBLCLK):
            {

                const auto win32_x_button = GET_XBUTTON_WPARAM(w_param);
                const auto button         = win32_x_button == XBUTTON1 ? io::mouse::button::ex_1 : io::mouse::button::ex_2;

                const event::mouse::double_click event{
                    .which  = button,
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

                //-------------------------------------
                // Other

            case(WM_MOUSEMOVE):
            {
                const event::mouse::move event{
                    .where  = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_MOUSEWHEEL):
            {
                const event::mouse::scroll event{
                    .ticks       = GET_WHEEL_DELTA_WPARAM(w_param) / WHEEL_DELTA,
                    .orientation = event::mouse::scroll::direction::vertical,
                    .where       = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod         = win32_keyboard::current_modifiers(),
                    .source      = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_MOUSEHWHEEL):
            {
                const event::mouse::scroll event{
                    .ticks       = GET_WHEEL_DELTA_WPARAM(w_param) / WHEEL_DELTA,
                    .orientation = event::mouse::scroll::direction::horizontal,
                    .where       = {.x = GET_X_LPARAM(l_param), .y = GET_Y_LPARAM(l_param)},
                    .mod         = win32_keyboard::current_modifiers(),
                    .source      = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

                // ----------------------------- Keyboard events ------------------------------ //

            case(WM_KEYDOWN):
            {
                const event::key::press event{
                    .which  = win32_keyboard::from_windows(w_param),
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            case(WM_KEYUP):
            {
                const event::key::release event{
                    .which  = win32_keyboard::from_windows(w_param),
                    .mod    = win32_keyboard::current_modifiers(),
                    .source = source,
                };

                win.m_event_dispatcher.process(win.data(), event);

                return true;
            }

            default:
            {
                break;
            }
        }

        return false;
    };

    return std::invoke(impl, w, std::forward<decltype(params)>(params)...);
}

[[nodiscard]] std::optional<any_call_info> window::create() noexcept
{
    m_info.opacity = std::clamp(m_info.opacity, 0.f, 1.f);

    const std::basic_string<TCHAR> tchar_class_name = {m_data.class_name.begin(), m_data.class_name.end()};

    const WNDCLASSEX wc{
        .cbSize = sizeof(WNDCLASSEX),
        .style  = CS_DBLCLKS           // Allow double clicks
            | CS_HREDRAW | CS_VREDRAW, // Redraw when dimensions changes
        .lpfnWndProc   = winproc,
        .cbClsExtra    = 0,
        .cbWndExtra    = 0,
        .hInstance     = m_data.hinstance,
        .hIcon         = LoadIcon(nullptr, IDI_APPLICATION),                    // TODO
        .hCursor       = LoadCursor(nullptr, IDC_ARROW),                        // TODO
        .hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH)), // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        .lpszMenuName  = nullptr,
        .lpszClassName = tchar_class_name.c_str(),
        .hIconSm       = LoadIcon(nullptr, IDI_APPLICATION), // TODO
    };

    m_atoms.class_id = RegisterClassEx(std::addressof(wc));

    if(m_atoms.class_id == 0)
    {
        const auto error = GetLastError();

        return call_info{.result = static_cast<code>(error), .call_literal = "RegisterClassEx"_literal};
    }

    m_data.hwnd = CreateWindowEx(WS_EX_LAYERED, // Allow to set transparency
                                 tchar_class_name.c_str(),
                                 nullptr,
                                 windows_style_mask(m_info.style),
                                 CW_USEDEFAULT,
                                 CW_USEDEFAULT,
                                 CW_USEDEFAULT,
                                 CW_USEDEFAULT,
                                 nullptr,
                                 nullptr,
                                 m_data.hinstance,
                                 nullptr);

    if(m_data.hwnd == nullptr)
    {
        const auto error = GetLastError();

        return call_info{.result = static_cast<code>(error), .call_literal = "CreateWindowEx"_literal};
    }

    if(const auto check = rename(std::move(m_info.title)); not check)
    {
        const auto& error = check.error();
        if(const auto* const generic = std::get_if<platform::error::api_call>(std::addressof(error.value)))
        {
            return generic->value;
        }

        return call_info{.result = {}, .call_literal = "rename"_literal};
    }

    if(const auto check = move(m_info.coordinates); not check)
    {
        const auto& error = check.error();
        if(const auto* const generic = std::get_if<platform::error::api_call>(std::addressof(error.value)))
        {
            return generic->value;
        }

        return call_info{.result = {}, .call_literal = "rename"_literal};
    }

    if(const auto check = set_opacity(m_info.opacity); not check)
    {
        const auto& error = check.error();
        if(const auto* const generic = std::get_if<platform::error::api_call>(std::addressof(error.value)))
        {
            return generic->value;
        }

        return call_info{.result = {}, .call_literal = "rename"_literal};
    }

    window_registry::add(handle(), *this);

    return {};
}

void window::swap(window& other) noexcept
{
    m_data.swap(other.m_data);
    m_info.swap(other.m_info);
    m_state.swap(other.m_state);
    m_event_dispatcher.swap(other.m_event_dispatcher);
    m_atoms.swap(other.m_atoms);
    window_registry::swap(handle(), *this);

    // Can happen after move
    if(other.m_data.hwnd != nullptr)
    {
        window_registry::swap(other.handle(), other);
    }
}

window::~window() noexcept
{
    if(m_data.hwnd != nullptr)
    {
        window_registry::remove(handle());
        DestroyWindow(m_data.hwnd);
    }
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::show() noexcept
{
    if(m_state.visible)
    {
        return {};
    }

    ShowWindow(m_data.hwnd, SW_SHOW);

    if(const auto x = UpdateWindow(m_data.hwnd); x == 0)
    {
        const auto error = GetLastError();

        return std::unexpected{
            platform::error::any{any_call_info{call_info{.result = static_cast<code>(error), .call_literal = "UpdateWindow"_literal}}}};
    }

    m_state.visible = true;

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::hide() noexcept
{
    if(not m_state.visible)
    {
        return {};
    }

    ShowWindow(m_data.hwnd, SW_HIDE);

    if(const auto x = UpdateWindow(m_data.hwnd); x == 0)
    {
        const auto error = GetLastError();

        return std::unexpected{
            platform::error::any{any_call_info{call_info{.result = static_cast<code>(error), .call_literal = "UpdateWindow"_literal}}}};
    }

    m_state.visible = false;

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::close() noexcept
{
    m_state.closed = m_event_dispatcher.process(data(), event::window::close{.source = {}});

    if(m_state.closed)
    {
        if(const auto x = DestroyWindow(m_data.hwnd); x == 0)
        {
            const auto error = GetLastError();

            return std::unexpected{
                platform::error::any{any_call_info{call_info{.result = static_cast<code>(error), .call_literal = "UpdateWindow"_literal}}}};
        }

        m_data.hwnd = nullptr;
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::enable(bool b) noexcept
{
    // No need to set m_state.enabled here, it is updated by event
    EnableWindow(m_data.hwnd, static_cast<BOOL>(b));

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::set_opacity(float opacity) noexcept
{
    constexpr auto scale = 255.f;
    m_info.opacity       = std::clamp(opacity, 0.f, 1.f);
    SetLayeredWindowAttributes(m_data.hwnd, RGB(0, 0, 0), static_cast<BYTE>(m_info.opacity * scale), LWA_ALPHA);

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::move(position2d p) noexcept
{
    // No need to set m_info.coordinates here, it is updated by event
    SetWindowPos(m_data.hwnd, HWND_TOP, p.x, p.y, m_info.size.width, m_info.size.height, SWP_SHOWWINDOW);

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::resize(dimension2d d) noexcept
{
    // No need to set m_info.size here, it is updated by event
    SetWindowPos(m_data.hwnd, HWND_TOP, m_info.coordinates.x, m_info.coordinates.y, d.width, d.height, SWP_SHOWWINDOW);

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, platform::error::any> window::rename(std::string s)
{
    m_info.title = std::move(s);
    const std::basic_string<TCHAR> name{m_info.title.begin(), m_info.title.end()};

    SetWindowText(m_data.hwnd, name.c_str());

    return {};
}
//------------------------------------------------------------------------------

void window::user_event(const event::any& e) noexcept
{
    if(const auto* close_event = std::get_if<event::window::close>(std::addressof(e.value)))
    {
        if(m_event_dispatcher.process(data(), *close_event))
        {
            m_state.closed = true;
        }

        return;
    }

    if(const auto* focus_event = std::get_if<event::window::focus>(std::addressof(e.value)))
    {
        m_state.focused = focus_event->next;
    }

    return std::visit([this](const auto& event) noexcept { m_event_dispatcher.process(data(), event); }, e.value);
}

} // namespace fubuki::io::platform::win32
