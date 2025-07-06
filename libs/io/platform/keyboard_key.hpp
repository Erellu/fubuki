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

#ifndef FUBUKI_IO_KEYBOARD_PLATFORM_KEYBOARD_KEY_HPP
#define FUBUKI_IO_KEYBOARD_PLATFORM_KEYBOARD_KEY_HPP

#include <cstdint>
#include <ostream>

#include <core/config/macros.hpp>
#include <core/flag_mask.hpp>

namespace fubuki
{

namespace io
{

namespace keyboard
{

/// Cross-platform keyboard key code.
enum class key
{
    backspace,         ///< Backspace key.
    tab,               ///< Tab key.
    clear,             ///< Clear key.
    enter,             ///< Enter key.
    shift,             ///< Shift key.
    ctrl,              ///< ctrl key.
    alt,               ///< alt key.
    pause,             ///< Pause key.
    caps_lock,         ///< Caps lock key.
    escape,            ///< Escape key.
    esc = escape,      ///< Escape key.
    space,             ///< Space bar.
    space_bar = space, ///< Space bar.
    page_up,           ///< 'Page up' key.
    prior = page_up,   ///< 'Page up' key.
    page_down,         ///< 'Page down' key.
    next = page_down,  ///< 'Page down' key.
    end,               ///< 'end' key.
    home,              ///< 'Home' key.
    left_arrow,        ///< Left arrow.
    up_arrow,          ///< Up arrow.
    right_arrow,       ///< Right arrow.
    down_arrow,        ///< Down arrow.

    print, ///< 'Print' key.

    print_screen, ///< 'Print screen' key.
    insert,       ///< 'Insert' key.
    ins = insert, ///< 'Insert' key.
    del,          ///< 'Delete' key.
    help,         ///< 'Help' key.
    cancel,       ///< 'Cancel' key.

    // Numbers
    key_0, ///< '0' key.
    key_1, ///< '1' key.
    key_2, ///< '2' key.
    key_3, ///< '3' key.
    key_4, ///< '4' key.
    key_5, ///< '5' key.
    key_6, ///< '6' key.
    key_7, ///< '7' key.
    key_8, ///< '8' key.
    key_9, ///< '9' key.

    // Letters
    a, ///< 'a' key.
    b, ///< 'b' key.
    c, ///< 'c' key.
    d, ///< 'd' key.
    e, ///< 'e' key.
    f, ///< 'f' key.
    g, ///< 'g' key.
    h, ///< 'h' key.
    i, ///< 'i' key.
    j, ///< 'j' key.
    k, ///< 'k' key.
    l, ///< 'l' key.
    m, ///< 'm' key.
    n, ///< 'n' key.
    o, ///< 'o' key.
    p, ///< 'p' key.
    q, ///< 'q' key.
    r, ///< 'r' key.
    s, ///< 's' key.
    t, ///< 't' key.
    u, ///< 'u' key.
    v, ///< 'v' key.
    w, ///< 'w' key.
    x, ///< 'x' key.
    y, ///< 'y' key.
    z, ///< 'z' key.

    // Super, etc.
    super_left,                  ///< Super (windows) left key.
    windows_left = super_left,   ///< Super (windows) left key.
    super_right,                 ///< Super (windows) right key.
    windows_right = super_right, ///< Super (windows) right key.
    apps,                        ///< Applications key. Can only be triggered on Windows.
    sleep,                       ///< Computer sleep key.

    // Numpad
    numpad_0,  ///< Numpad 0 key.
    numpad_1,  ///< Numpad 1 key.
    numpad_2,  ///< Numpad 2 key.
    numpad_3,  ///< Numpad 3 key.
    numpad_4,  ///< Numpad 4 key.
    numpad_5,  ///< Numpad 5 key.
    numpad_6,  ///< Numpad 6 key.
    numpad_7,  ///< Numpad 7 key.
    numpad_8,  ///< Numpad 8 key.
    numpad_9,  ///< Numpad 9 key.
    multiply,  ///< Numpad multiply key.
    add,       ///< Numpad add key.
    substract, ///< Numpad substract key.
    decimal,   ///< Numpad decimal key.
    divide,    ///< Numpad divide key.

    // F1 -> F24
    f1,  ///< F1 key.
    f2,  ///< F2 key.
    f3,  ///< F3 key.
    f4,  ///< F4 key.
    f5,  ///< F5 key.
    f6,  ///< F6 key.
    f7,  ///< F7 key.
    f8,  ///< F8 key.
    f9,  ///< F9 key.
    f10, ///< F10 key.
    f11, ///< F11 key.
    f12, ///< F12 key.
    f13, ///< F13 key.
    f14, ///< F14 key.
    f15, ///< F15 key.
    f16, ///< F16 key.
    f17, ///< F17 key.
    f18, ///< F18 key.
    f19, ///< F19 key.
    f20, ///< F20 key.
    f21, ///< F21 key.
    f22, ///< F22 key.
    f23, ///< F23 key.
    f24, ///< F24 key.

    // Numlock, scroll lock
    numlock,     ///< Numlock key.
    scroll_lock, ///< Scroll lock key.

    // Punctuation, etc.
    plus,   ///< '+' key cross-region.
    minus,  ///< '-' key cross-region.
    comma,  ///< ',' key cross-region.
    period, ///< '.' key cross-region.

    // Shift
    shift_left,  ///< Left alt key.
    shift_right, ///< Right alt key.

    // Ctrl
    ctrl_left,  ///< Left ctrl key.
    ctrl_right, ///< Right ctrl key.

    // Alt
    alt_left,  ///< Left alt key.
    alt_right, ///< Right alt key

    // Browser
    browser_back,       ///< Browser back key.
    browser_forward,    ///< Browser forward key.
    browser_refresh,    ///< Browser refresh key.
    browser_stop,       ///< Browser stop key.
    browser_search,     ///< Browser search key.
    browser_favourites, ///< Browser favourites key.
    browser_home,       ///< Browser home key.

    // Volume
    volume_mute, ///< Volume mute key.
    volume_down, ///< Volume down key.
    volume_up,   ///< Volume up key.

    // Media
    media_select,     ///< Select media key.
    media_next,       ///< Next media key.
    media_previous,   ///< Previous media key.
    media_stop,       ///< Stop media key.
    media_play_pause, ///< Play / pause media key.

    // Mail
    mail, ///< Start mail key.

    // Launch applications
    launch_app_1, ///< Start application 1 shortcut key. Can only be triggered on Windows.
    launch_app_2, ///< Start application 2 shortcut key. Can only be triggered on Windows.

    unknown ///< Unknown key code.
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const key c)
{
    switch(c)
    {
        case key::backspace         : return out << "backspace";
        case key::tab               : return out << "tab";
        case key::clear             : return out << "clear";
        case key::enter             : return out << "enter";
        case key::shift             : return out << "shift";
        case key::ctrl              : return out << "ctrl";
        case key::alt               : return out << "alt";
        case key::pause             : return out << "pause";
        case key::caps_lock         : return out << "caps_lock";
        case key::escape            : return out << "escape";
        case key::space             : return out << "space";
        case key::page_up           : return out << "page_up";   // prior
        case key::page_down         : return out << "page_down"; // next
        case key::end               : return out << "end";
        case key::home              : return out << "home";
        case key::left_arrow        : return out << "left_arrow";
        case key::up_arrow          : return out << "up_arrow";
        case key::right_arrow       : return out << "right_arrow";
        case key::down_arrow        : return out << "down_arrow";
        case key::print             : return out << "print";
        case key::print_screen      : return out << "print_screen";
        case key::insert            : return out << "insert";
        case key::del               : return out << "del";
        case key::help              : return out << "help";
        case key::cancel            : return out << "cancel";
        case key::key_0             : return out << "0";
        case key::key_1             : return out << "1";
        case key::key_2             : return out << "2";
        case key::key_3             : return out << "3";
        case key::key_4             : return out << "4";
        case key::key_5             : return out << "5";
        case key::key_6             : return out << "6";
        case key::key_7             : return out << "7";
        case key::key_8             : return out << "8";
        case key::key_9             : return out << "9";
        case key::a                 : return out << "a";
        case key::b                 : return out << "b";
        case key::c                 : return out << "c";
        case key::d                 : return out << "d";
        case key::e                 : return out << "e";
        case key::f                 : return out << "f";
        case key::g                 : return out << "g";
        case key::h                 : return out << "h";
        case key::i                 : return out << "i";
        case key::j                 : return out << "j";
        case key::k                 : return out << "k";
        case key::l                 : return out << "l";
        case key::m                 : return out << "m";
        case key::n                 : return out << "n";
        case key::o                 : return out << "o";
        case key::p                 : return out << "p";
        case key::q                 : return out << "q";
        case key::r                 : return out << "r";
        case key::s                 : return out << "s";
        case key::t                 : return out << "t";
        case key::u                 : return out << "u";
        case key::v                 : return out << "v";
        case key::w                 : return out << "w";
        case key::x                 : return out << "x";
        case key::y                 : return out << "y";
        case key::z                 : return out << "z";
        case key::super_left        : return out << "super_left / windows_left";
        case key::super_right       : return out << "super_right / windows_right";
        case key::apps              : return out << "apps";
        case key::sleep             : return out << "sleep";
        case key::numpad_0          : return out << "numpad 0";
        case key::numpad_1          : return out << "numpad 1";
        case key::numpad_2          : return out << "numpad 2";
        case key::numpad_3          : return out << "numpad 3";
        case key::numpad_4          : return out << "numpad 4";
        case key::numpad_5          : return out << "numpad 5";
        case key::numpad_6          : return out << "numpad 6";
        case key::numpad_7          : return out << "numpad 7";
        case key::numpad_8          : return out << "numpad 8";
        case key::numpad_9          : return out << "numpad 9";
        case key::multiply          : return out << "* (numpad)";
        case key::add               : return out << "+ (numpad)";
        case key::substract         : return out << "- (numpad)";
        case key::decimal           : return out << ". (numpad)";
        case key::divide            : return out << "/ (numpad)";
        case key::f1                : return out << "f1";
        case key::f2                : return out << "f2";
        case key::f3                : return out << "f3";
        case key::f4                : return out << "f4";
        case key::f5                : return out << "f5";
        case key::f6                : return out << "f6";
        case key::f7                : return out << "f7";
        case key::f8                : return out << "f8";
        case key::f9                : return out << "f9";
        case key::f10               : return out << "f10";
        case key::f11               : return out << "f11";
        case key::f12               : return out << "f12";
        case key::f13               : return out << "f3";
        case key::f14               : return out << "f14";
        case key::f15               : return out << "f15";
        case key::f16               : return out << "f16";
        case key::f17               : return out << "f17";
        case key::f18               : return out << "f18";
        case key::f19               : return out << "f19";
        case key::f20               : return out << "f20";
        case key::f21               : return out << "f21";
        case key::f22               : return out << "f22";
        case key::f23               : return out << "f23";
        case key::f24               : return out << "f24";
        case key::numlock           : return out << "numlock";
        case key::scroll_lock       : return out << "scroll_lock";
        case key::shift_left        : return out << "shift_left";
        case key::shift_right       : return out << "shift_right";
        case key::ctrl_left         : return out << "ctrl_left";
        case key::ctrl_right        : return out << "ctrl_right";
        case key::alt_right         : return out << "alt_right";
        case key::alt_left          : return out << "alt_left";
        case key::browser_back      : return out << "browser_back";
        case key::browser_forward   : return out << "browser_forward";
        case key::browser_refresh   : return out << "browser_refresh";
        case key::browser_stop      : return out << "browser_stop";
        case key::browser_search    : return out << "browser_search";
        case key::browser_favourites: return out << "browser_favourites";
        case key::browser_home      : return out << "browser_home";
        case key::volume_mute       : return out << "volume_mute";
        case key::volume_down       : return out << "volume_down";
        case key::volume_up         : return out << "volume_up";
        case key::media_select      : return out << "media_select";
        case key::media_next        : return out << "media_next";
        case key::media_previous    : return out << "media_previous";
        case key::media_stop        : return out << "media_stop";
        case key::media_play_pause  : return out << "media_play_pause";
        case key::mail              : return out << "mail";
        case key::launch_app_1      : return out << "launch_app_1";
        case key::launch_app_2      : return out << "launch_app_2";
        case key::plus              : return out << "+";
        case key::minus             : return out << "-";
        case key::comma             : return out << ",";
        case key::period            : return out << ".";
        case key::unknown           : return out << "unknown";
        default                     : return out << "<invalid>: perhaps static_cast?";
    }
}

//------------------------------------------------------------------------------

/// Cross-platform keyboard modifier.
enum class modifier : std::uint8_t
{
    none  = 0b0000'0000,
    shift = 0b0000'0001,
    ctrl  = 0b0000'0010,
    alt   = 0b0000'0100,
    caps  = 0b0000'1000
};

/// Modifier mask.
using modifier_mask = flag_mask<modifier>;

//------------------------------------------------------------------------------

/// Bitwise OR operator. Adds a flag.
[[nodiscard]]
inline constexpr modifier_mask operator|(const modifier m1, const modifier m2) noexcept
{
    return modifier_mask{m1} | m2;
}

//------------------------------------------------------------------------------

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, modifier m)
{
    switch(m)
    {
        case modifier::none : return out << "modifer::none";
        case modifier::shift: return out << "modifer::shift";
        case modifier::ctrl : return out << "modifer::ctrl";
        case modifier::alt  : return out << "modifer::alt";
        case modifier::caps : return out << "modifier::caps";
        default             : return out << "modifier::unknown";
    }
}

/// Prints a modifier_mask to a stream.
template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& to_stream(std::basic_ostream<char_type, traits>& out, modifier_mask m)
{
    using mask = modifier_mask;

    // NOLINTBEGIN(misc-redundant-expression)
    switch(m.value())
    {
        // Too lazy to cast, so we use operators which creates a mask for single values.
        case(mask{modifier::none}.value()): return out << "none";

        case(mask{modifier::shift}.value())             : return out << "shift";
        case((modifier::shift | modifier::ctrl).value()): return out << "shift | ctrl";
        case((modifier::shift | modifier::alt).value()) : return out << "shift | alt";
        case((modifier::shift | modifier::caps).value()): return out << "shift | caps";

        case((modifier::shift | modifier::ctrl | modifier::alt).value()) : return out << "shift | ctrl | alt";
        case((modifier::shift | modifier::alt | modifier::caps).value()) : return out << "shift | alt | caps";
        case((modifier::shift | modifier::ctrl | modifier::caps).value()): return out << "shift | ctrl | caps";

        case(mask{modifier::ctrl}.value())                             : return out << "ctrl";
        case((modifier::ctrl | modifier::alt).value())                 : return out << "ctrl | alt";
        case((modifier::ctrl | modifier::caps).value())                : return out << "ctrl | caps";
        case((modifier::ctrl | modifier::alt | modifier::caps).value()): return out << "ctrl | alt | caps";

        case(mask{modifier::alt}.value())             : return out << "alt";
        case((modifier::alt | modifier::caps).value()): return out << "alt | caps";

        case((modifier::caps | modifier::caps).value()): return out << "caps";

        case((modifier::ctrl | modifier::alt | modifier::shift | modifier::caps).value()): return out << "ctrl | alt | shift | caps";

        default: return out << "<invalid mask> : perhaps user-made?";
    }
    // NOLINTEND(misc-redundant-expression)
}

} // namespace keyboard

using keyboard::operator<<;
using keyboard::operator|;
using keyboard::to_stream;

} // namespace io

using io::operator<<;

} // namespace fubuki

#endif // FUBUKI_IO_KEYBOARD_PLATFORM_KEYBOARD_KEY_HPP
