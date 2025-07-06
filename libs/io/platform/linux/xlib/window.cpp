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

#include <cstring>

#include "io/platform/linux/xlib/window.hpp"

#include "io/platform/linux/window_registry.hpp"
#include "io/platform/linux/xlib/detail/code.hpp"
#include "io/platform/linux/xlib/detail/keyboard.hpp"
#include "io/platform/linux/xlib/unique_ptr.hpp"

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace fubuki::io::platform::linux_bsd::xlib
{

namespace
{

constexpr auto event_mask
    = ButtonPressMask | ButtonReleaseMask | KeyPressMask | KeyReleaseMask | StructureNotifyMask | ExposureMask | PointerMotionMask;

[[nodiscard]] constexpr event::key::modifier_mask xlib_modifier(unsigned int state) noexcept
{
    event::key::modifier_mask result = {};

    using modifier = event::key::modifier;

    if(state & ShiftMask)
    {
        result = result | modifier::shift;
    }

    if(state & LockMask)
    {
        result = result | modifier::caps;
    }

    if(state & ControlMask) // Alt
    {
        result = result | modifier::ctrl;
    }

    if(state & Mod1Mask) // Alt
    {
        result = result | modifier::alt;
    }

    // if(state & Mod2Mask) // Numlock
    // {
    // }

    // if(state & Mod3Mask) // ?????
    // {
    // }

    // if(state & Mod4Mask) // Super
    // {
    // }

    // if(state & Mod5Mask) // AltGr
    // {
    // }

    return result;
}

[[nodiscard]] constexpr event::mouse::button xlib_button(unsigned int b) noexcept
{
    constexpr auto ex1 = 8; // Reverse-engineered
    constexpr auto ex2 = 9; // Reverse-engineered

    switch(b)
    {
        case(Button1): return event::mouse::button::left;
        case(Button2): return event::mouse::button::central;
        case(Button3): return event::mouse::button::right;
        case(ex1)    : return event::mouse::button::ex_1;
        case(ex2)    : return event::mouse::button::ex_2;
        default      : return {}; // Map unknown to left click
    }
}

} // anonymous namespace

[[nodiscard]]
std::expected<void, any_call_info> window::create() noexcept
{
    // Window handle
    {
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
        constexpr auto root_window = [](Display* dp, auto screen) noexcept { return RootWindow(dp, screen); };
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
        constexpr auto background = 0xFF'FF'FF'FF;

        constexpr long          visual_mask = VisualScreenMask;                         // NOLINT(google-runtime-int)
        constexpr unsigned long valuemask   = CWBorderPixel | CWColormap | CWEventMask; // NOLINT(google-runtime-int)

        int         number_of_visuals    = {};
        XVisualInfo visual_info_template = {};
        visual_info_template.screen      = DefaultScreen(m_parent);
        xlib::unique_ptr<XVisualInfo> visual_info{XGetVisualInfo(m_parent, visual_mask, &visual_info_template, &number_of_visuals)};

        XSetWindowAttributes window_attributes = {
            .background_pixmap     = {},         /* background or None or ParentRelative */
            .background_pixel      = background, /* background pixel */
            .border_pixmap         = {},         /* border of the window */
            .border_pixel          = 0,          /* border pixel value */
            .bit_gravity           = {},         /* one of bit gravity values */
            .win_gravity           = {},         /* one of the window gravity values */
            .backing_store         = {},         /* NotUseful, WhenMapped, Always */
            .backing_planes        = {},         /* planes to be preserved if possible */
            .backing_pixel         = {},         /* value to use in restoring planes */
            .save_under            = {},         /* should bits under be saved? (popups) */
            .event_mask            = event_mask, /* set of events that should be saved */
            .do_not_propagate_mask = {},         /* set of events that should not propagate */
            .override_redirect     = {},         /* boolean value for override-redirect */
            .colormap              = XCreateColormap(m_parent, root_window(m_parent, visual_info_template.screen), visual_info->visual, AllocNone),
            .cursor                = {},
        };

        m_handle.value = XCreateWindow(m_parent,
                                       root_window(m_parent, visual_info->screen),
                                       m_info.coordinates.x,                           // x
                                       m_info.coordinates.y,                           // y
                                       static_cast<std::uint32_t>(m_info.size.width),  // w
                                       static_cast<std::uint32_t>(m_info.size.height), //  h
                                       0,                                              // border_width
                                       visual_info->depth,
                                       InputOutput,
                                       visual_info->visual,
                                       valuemask,
                                       &window_attributes);

        if(const auto error = validate(m_handle.value))
        {
            return std::unexpected{
                call_info{result{*error}, "XCreateWindow"_literal}
            };
        }
    }

    // Atoms
    {
        XSetWMProtocols(m_parent, m_handle.value, &m_atoms.wm_delete_message, 1);
    }

    if(const auto check = rename(std::move(m_info.title)); not check)
    {
        const auto& error = check.error();

        if(const auto* const generic = std::get_if<platform::error::api_call>(std::addressof(error.value)))
        {
            return std::unexpected{generic->value};
        }

        return std::unexpected{
            call_info{result{}, "rename"_literal}
        };
    }

    if(const auto check = set_opacity(m_info.opacity); not check)
    {
        const auto& error = check.error();

        if(const auto* const generic = std::get_if<platform::error::api_call>(std::addressof(error.value)))
        {
            return std::unexpected{generic->value};
        }

        return std::unexpected{
            call_info{result{}, "set_opacity"_literal}
        };
    }

    window_registry::add(m_handle, *this);

    return {};
}

window::~window() noexcept
{
    if(not validate(m_handle.value).has_value())
    {
        window_registry::remove(m_handle);
        XDestroyWindow(m_parent, m_handle.value);
    }
}

void window::swap(window& other) noexcept
{
    std::swap(m_parent, other.m_parent);
    std::swap(m_handle, other.m_handle);
    m_info.swap(other.m_info);
    m_state.swap(other.m_state);
    m_input.swap(other.m_input);
    m_event_dispatcher.swap(other.m_event_dispatcher);
    m_atoms.swap(other.m_atoms);

    window_registry::swap(m_handle, *this);
    window_registry::swap(other.m_handle, other);
}

[[nodiscard]]
std::expected<void, platform::error::any> window::show() noexcept
{
    if(m_state.closed)
    {
        return {};
    }

    if(m_state.visible)
    {
        return {};
    }

    if(const auto x = XMapWindow(m_parent, m_handle.value); x != 0)
    {
        return std::unexpected{platform::error::any{
            any_call_info{call_info{.result{detail::from_xlib(x)}, .call_literal = "XMapWindow(m_parent, m_handle.value)"_literal}}}};
    }

    m_state.visible = true;

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::hide() noexcept
{
    if(m_state.closed)
    {
        return {};
    }

    if(not m_state.visible)
    {
        return {};
    }

    if(const auto x = XUnmapWindow(m_parent, m_handle.value); x != 0)
    {
        return std::unexpected{platform::error::any{
            any_call_info{call_info{.result{detail::from_xlib(x)}, .call_literal = "XUnmapWindow(m_parent, m_handle.value)"_literal}}}};
    }

    m_state.visible = false;

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::close() noexcept
{
    if(m_state.closed)
    {
        return {};
    }

    m_state.closed = m_event_dispatcher.process(data(), event::window::close{.source = {}});

    if(m_state.closed)
    {
        if(const auto x = XUnmapWindow(m_parent, m_handle.value); x != 0)
        {
            return std::unexpected{platform::error::any{
                any_call_info{call_info{.result{detail::from_xlib(x)}, .call_literal = "XUnmapWindow(m_parent, m_handle.value)"_literal}}}};
        }
    }

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::enable(bool b) noexcept
{
    if(m_state.closed)
    {
        return {};
    }

    if(const auto x = XSelectInput(m_parent, m_handle.value, b ? event_mask : 0); x != 0)
    {
        return std::unexpected{platform::error::any{any_call_info{
            call_info{.result{detail::from_xlib(x)}, .call_literal = "XSelectInput(m_parent, m_handle.value, b ? event_mask : 0)"_literal}}}};
    }

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::set_opacity(float o) noexcept
{
    if(m_state.closed)
    {
        return {};
    }

    m_info.opacity = o;

    const auto opacity = static_cast<std::uint32_t>(static_cast<float>(0xFFFFFFFFUL) * m_info.opacity);

    if(const auto x
       = XChangeProperty(m_parent,
                         m_handle.value,
                         m_atoms.wm_window_opacity,
                         XA_CARDINAL,
                         32 /*bit*/,
                         PropModeReplace,
                         reinterpret_cast<const unsigned char*>(std::addressof(opacity)), // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                         1L);
       x != 1)
    {
        return std::unexpected{platform::error::any{any_call_info{call_info{
            .result{detail::from_xlib(x)},
            .call_literal
            = R"(XChangeProperty(m_parent, m_handle.value, m_atoms.wm_window_opacity, XA_CARDINAL, 32 /*bit*/, PropModeReplace, reinterpret_cast<const unsigned char*>(std::addressof(opacity)), 1L))"_literal}}}};
    }

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::move(position2d p) noexcept
{
    if(m_state.closed)
    {
        return {};
    }

    if(const auto x = XMoveWindow(m_parent, m_handle.value, p.x, p.y); x != 1)
    {
        return std::unexpected{
            platform::error::any{any_call_info{call_info{.result{}, .call_literal = "XMoveWindow(m_parent, m_handle.value, p.x, p.y)"_literal}}}};
    }

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::resize(dimension2d d) noexcept
{
    if(m_state.closed)
    {
        return {};
    }

    if(const auto x = XMoveResizeWindow(m_parent,
                                        m_handle.value,
                                        m_info.coordinates.x,
                                        m_info.coordinates.y,
                                        static_cast<std::uint32_t>(d.width),
                                        static_cast<std::uint32_t>(d.height));
       x != 1)
    {
        return std::unexpected{platform::error::any{any_call_info{call_info{
            .result{},
            .call_literal
            = "XMoveResizeWindow(m_parent, m_handle.value, m_info.coordinates.x, m_info.coordinates.y, static_cast<std::uint32_t>(d.width), static_cast<std::uint32_t>(d.height))"_literal}}}};
    }

    return {};
}

[[nodiscard]]
std::expected<void, platform::error::any> window::rename(std::string name) noexcept
{
    m_info.title = std::move(name);

    if(const auto x = XStoreName(m_parent, m_handle.value, m_info.title.c_str()); x != 1)
    {
        return std::unexpected{platform::error::any{
            any_call_info{call_info{.result{}, .call_literal = "XStoreName(m_parent, m_handle.value, m_info.title.c_str())"_literal}}}};
    }

    return {};
}

void window::os_event(XEvent& e) noexcept
{
    if(m_state.closed)
    {
        return;
    }

    // Avoid UB when reading a member not written in union
    // Cannot use the rule about common init sequence ([class.mem#25], https://timsong-cpp.github.io/cppwp/n4861/class.mem)
    // because there is a primitive type (int) in XEvent
    XAnyEvent general_info = {};
    std::memcpy(&general_info, std::addressof(e), sizeof(XAnyEvent));

    if(general_info.window != m_handle.value)
    {
        return;
    }

    const event::cause source{.provenance = general_info.send_event == 0 ? event::origin::system : event::origin::artificial,
                              .from       = event::device::unknown};

    switch(general_info.type)
    {
        case(MappingNotify):
        {
            // Key mapping (keyboard) or ;odifier mapping (shift, etc.)
            if(e.xmapping.request == MappingKeyboard or e.xmapping.request == MappingModifier)
            {
                XRefreshKeyboardMapping(&e.xmapping);
            }

            // Pointer button (mouse)
            if(e.xmapping.request == MappingPointer)
            {
            }

            break;
        }

        case(KeymapNotify):
        {
            XRefreshKeyboardMapping(&e.xmapping);
            break;
        }

        case(Expose):
        {
            const event::window::activate translation{.source = source};
            m_event_dispatcher.process(data(), translation);
            break;
        }

        case(ConfigureNotify):
        {
            XWindowAttributes xwa = {};
            // XSync(m_parent, 0);// ?
            XGetWindowAttributes(m_parent, m_handle.value, &xwa);

            // Set focus when menu window is re-used.
            // RevertToPointerRoot is used to make sure we don't lose all focus in case
            // a subwindow and its parent are both destroyed.
            if(xwa.map_state == IsViewable /* && !wd.no_focus && !wd.is_popup*/)
            {
                XSetInputFocus(m_parent, m_handle.value, RevertToPointerRoot, CurrentTime);
            }

            {
                // the position in xconfigure is not useful here, obtain it manually
                Window child = {};

                const position2d old_pos = m_info.coordinates;
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
                XTranslateCoordinates(
                    m_parent, m_handle.value, DefaultRootWindow(m_parent), 0, 0, &m_info.coordinates.x, &m_info.coordinates.y, &child);
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
                const auto new_pos = m_info.coordinates;

                if(old_pos != new_pos)
                {
                    const event::window::move translation{.previous = old_pos, .next = new_pos, .source = source};
                    m_event_dispatcher.process(data(), translation);
                }

                const dimension2d old_size = m_info.size;

                m_info.size.width  = e.xconfigure.width;
                m_info.size.height = e.xconfigure.height;

                if(old_size != m_info.size)
                {
                    const event::window::resize translation{.previous = old_size, .next = m_info.size, .source = source};
                    m_event_dispatcher.process(data(), translation);
                }
            }
            break;
        }

        case(ButtonRelease):
        case(ButtonPress):
        {
            const auto& details = e.xbutton;

            const auto modifier = xlib_modifier(details.state);

            // Scroll
            constexpr auto scroll_v_up   = Button4;
            constexpr auto scroll_v_down = Button5;
            constexpr auto scroll_h_up   = 6; // Reverse-engineered
            constexpr auto scroll_h_down = 7; // Reverse-engineered

            if(details.button == scroll_v_up)
            {
                const event::mouse::scroll translation{
                    .ticks       = 1,
                    .orientation = event::mouse::scroll::direction::vertical,
                    .where       = {details.x, details.y},
                    .mod         = modifier,
                    .source      = source,
                };

                m_event_dispatcher.process(data(), translation);
            }

            else if(details.button == scroll_v_down)
            {
                const event::mouse::scroll translation{
                    .ticks       = -1,
                    .orientation = event::mouse::scroll::direction::vertical,
                    .where       = {details.x, details.y},
                    .mod         = modifier,
                    .source      = source,
                };

                m_event_dispatcher.process(data(), translation);
            }

            else if(details.button == scroll_h_up)
            {
                const event::mouse::scroll translation{
                    .ticks       = 1,
                    .orientation = event::mouse::scroll::direction::horizontal,
                    .where       = {details.x, details.y},
                    .mod         = modifier,
                    .source      = source,
                };

                m_event_dispatcher.process(data(), translation);
            }

            else if(details.button == scroll_h_down)
            {
                const event::mouse::scroll translation{
                    .ticks       = -1,
                    .orientation = event::mouse::scroll::direction::horizontal,
                    .where       = {details.x, details.y},
                    .mod         = modifier,
                    .source      = source,
                };

                m_event_dispatcher.process(data(), translation);
            }
            else
            {
                constexpr auto double_click_interval = 500; // 500 ms, as the default on Windows

                const auto button  = xlib_button(details.button); // Unknow buttons are handled as left click
                const bool pressed = general_info.type == ButtonPress;

                constexpr auto moved_between_click = [](std::optional<position2d> previous, std::optional<position2d> next) noexcept -> bool
                {
                    if(not previous.has_value() or not next.has_value())
                    {
                        return true;
                    }

                    return previous != next;
                };

                const auto update_timestamp = [pressed, &details](input_state::pointer::button& b) noexcept
                {
                    if(pressed)
                    {
                        b.last_click_timestamp = {details.time};
                    }
                };

                const auto process_as_single_click = [&]() noexcept
                {
                    if(pressed)
                    {
                        const event::mouse::click translation{
                            .which  = button,
                            .where  = {details.x, details.y},
                            .mod    = modifier,
                            .source = source,
                        };

                        m_event_dispatcher.process(data(), translation);
                    }

                    else
                    {
                        const event::mouse::release translation{
                            .which  = button,
                            .where  = {details.x, details.y},
                            .mod    = modifier,
                            .source = source,
                        };

                        m_event_dispatcher.process(data(), translation);
                    }
                };

                const auto process = [&, this](input_state::pointer::button& b) noexcept
                {
                    const auto old_pos = b.last_position;

                    b.last_position = {details.x, details.y};

                    if(b.last_click_timestamp.has_value())
                    {
                        const auto diff = details.time - *b.last_click_timestamp;

                        if(not pressed and b.next_release_is_double_click)
                        {
                            const auto event = event::mouse::double_click{
                                .which = button, .where = {details.x, details.y},
                                     .mod = modifier, .source = source
                            };

                            m_event_dispatcher.process(data(), event);

                            b.next_release_is_double_click = false;
                        }

                        else if(diff <= double_click_interval and pressed and not moved_between_click(old_pos, b.last_position))
                        {
                            b.next_release_is_double_click = true;
                            // No click event here on purpose for consistency between platforms
                        }

                        else
                        {
                            process_as_single_click();
                        }
                    }
                    else
                    {
                        process_as_single_click();
                    }

                    update_timestamp(b);
                };

                switch(button)
                {
                    case mouse::button::left:
                    {
                        process(m_input.mouse.left);
                        break;
                    }
                    case mouse::button::central:
                    {
                        process(m_input.mouse.centre);
                        break;
                    }
                    case mouse::button::right:
                    {
                        process(m_input.mouse.right);
                        break;
                    }
                    case mouse::button::ex_1:
                    {
                        process(m_input.mouse.ex_1);
                        break;
                    }
                    case mouse::button::ex_2:
                    {
                        process(m_input.mouse.ex_2);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }

            break;
        }

        case(MotionNotify):
        {
            const auto& details = e.xmotion;

            const event::mouse::move translation{
                .where  = {details.x, details.y},
                .source = source,
            };

            m_event_dispatcher.process(data(), translation);
            break;
        }

        case(KeyRelease):
        case(KeyPress):
        {
            static constexpr auto compute_keysym = [](XKeyEvent& key_event) noexcept -> std::optional<KeySym>
            {
                static constexpr std::size_t  buffer_size = 40;
                std::array<char, buffer_size> buffer      = {};

                KeySym result = {};

                if(XLookupString(std::addressof(key_event), buffer.data(), static_cast<int>(buffer.size()), std::addressof(result), nullptr) == 0)
                {
                    return std::nullopt;
                }

                return result;
            };

            if(const auto sym = compute_keysym(e.xkey))
            {
                const auto& details  = e.xkey;
                const auto  key      = xlib::keyboard::detail::from_key_sym(*sym);
                const auto  press    = general_info.type == KeyPress ? true : false;
                const auto  modifier = xlib_modifier(details.state);

                if(key)
                {
                    if(press)
                    {
                        const event::key::press translation{
                            .which  = *key,
                            .mod    = modifier,
                            .source = source,
                        };

                        m_event_dispatcher.process(data(), translation);
                    }
                    else
                    {
                        const event::key::release translation{
                            .which  = *key,
                            .mod    = modifier,
                            .source = source,
                        };

                        m_event_dispatcher.process(data(), translation);
                    }
                }
            }

            break;
        }

        case ClientMessage:
        {
            const auto&    details        = e.xclient;
            constexpr auto indicates_long = 32;

            if(details.message_type == m_atoms.wm_protocols and details.format == indicates_long)
            {
                const auto code = static_cast<Atom>(e.xclient.data.l[0]); // NOLINT(cppcoreguidelines-pro-type-union-access)

                if(code == m_atoms.wm_delete_message)
                {
                    const event::window::close translation{.source = source};

                    m_state.closed = m_event_dispatcher.process(data(), translation);

                    if(m_state.closed)
                    {
                        std::ignore = XUnmapWindow(m_parent, m_handle.value);
                    }
                }
            }

            break;
        }

        default:
        {
        }
    }
}

void window::user_event(const event::any& e) noexcept
{
    if(m_state.closed)
    {
        return;
    }

    if(const auto* close_event = std::get_if<event::window::close>(std::addressof(e.value)))
    {
        m_state.closed = m_event_dispatcher.process(data(), *close_event);
        if(m_state.closed)
        {
            std::ignore = XUnmapWindow(m_parent, m_handle.value);
        }

        return;
    }

    if(const auto* focus_event = std::get_if<event::window::focus>(std::addressof(e.value)))
    {
        m_state.focused = focus_event->next;
    }

    return std::visit([this](const auto& event) noexcept { m_event_dispatcher.process(data(), event); }, e.value);
}

} // namespace fubuki::io::platform::linux_bsd::xlib
