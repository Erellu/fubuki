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

#ifndef FUBUKI_IO_PLATFORM_WIN32_KEYBOARD_HPP
#define FUBUKI_IO_PLATFORM_WIN32_KEYBOARD_HPP

#include <expected>

#include <core/assertion.hpp>

#include "io/platform/keyboard_key.hpp"
#include "io/platform/views/display.hpp"

#include <windows.h>

namespace fubuki::io::platform::win32::keyboard
{

using io::keyboard::key;
using io::keyboard::modifier;
using io::keyboard::modifier_mask;

/// Converts Windows virtual key codes to fubuki::io::keyboard::key codes.
[[nodiscard]] FUBUKI_TRUE_PURE inline constexpr key from_windows(WPARAM w) noexcept
{
    // See https://docs.microsoft.com/en-gb/windows/win32/inputdev/virtual-key-codes
    // Hopefully I did not make any mistake.

    /*
      Windows has key codes for the following keys / shortcuts.
      fubuki does not provide mapping for those yet.

      Available keys are based on godot:
      https://github.com/godotengine/godot/blob/master/platform/windows/key_mapping_windows.cpp

      IME are not supported:

        ime_kana,               ///< IME kana mode key. Can only be triggered on Windows.
        ime_hanguel = ime_kana, ///< IME hanguel mode key. Can only be triggered on Windows.
        ime_hangul  = ime_kana, ///< IME hangul mode key. Can only be triggered on Windows.
        ime_on,                 ///< IME 'on' key. Can only be triggered on Windows.
        ime_junja,              ///< IME junja mode key . Can only be triggered on Windows.
        ime_final,              ///< IME final mode key . Can only be triggered on Windows.
        ime_kanji,              ///< IME kanji mode key . Can only be triggered on Windows.
        ime_hanja = ime_kanji,  ///< IME hanja mode key . Can only be triggered on Windows.
        ime_off,                ///< IME 'off' key. Can only be triggered on Windows.
        ime_convert,            ///< IME 'convert' key. Can only be triggered on Windows.
        ime_non_convert,        ///< IME 'non-convert' key. Can only be triggered on Windows.
        ime_accept,             ///< IME 'accept' key. Can only be triggered on Windows.
        ime_mode_change,        ///< IME 'mode change' key. Can only be triggered on Windows.
        ime_process,            ///< IME 'process' key. Can only be triggered on Windows.

        Additionally, fubuki does not provide maps for old keys that are not present anymore on modern hardware:

            select,    ///< 'Select' key.
            execute,   ///< 'Execute' key.
            separator, ///< Numpad separator key.
            exsel,     ///< ExSel key.
            erof,      ///< Erase EOF key.
            zoom,      ///< Zoom key.
            pa1,       ///< PA1 key.

            packet,    ///< Used to pass Unicode characters as if they were keystrokes. Can only be triggered on Windows.

        Similarly, fubuki does not provide mapping for OEM specific-keys EXCEPT +/-/,/. which are pratical.
            oem_clear,  ///< Clear key. Can only be triggered on Windows.
            oem_1,      ///< Miscellanous. Can only be triggered on Windows.
            oem_2,      ///< Miscellanous. Can only be triggered on Windows.
            oem_3,      ///< Miscellanous. Can only be triggered on Windows.
            oem_4,      ///< Miscellanous. Can only be triggered on Windows.
            oem_5,      ///< Miscellanous. Can only be triggered on Windows.
            oem_6,      ///< Miscellanous. Can only be triggered on Windows.
            oem_7,      ///< Miscellanous. Can only be triggered on Windows.
            oem_8,      ///< Miscellanous. Can only be triggered on Windows.
            oem_102,    ///< Miscellanous. Can only be triggered on Windows.

            oem_specific_0, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_1, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_2, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_3, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_4, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_5, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_6, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_7, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_8, ///< Various meaning depending on OEM. Can only be triggered on Windows.

            oem_specific_9, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_10, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_11, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_12, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_13, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_14, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_15, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_16, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_17, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_18, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_19, ///< Various meaning depending on OEM. Can only be triggered on Windows.
            oem_specific_20, ///< Various meaning depending on OEM. Can only be triggered on Windows.

       Some are mapped to other keys:

        attn  -> escape
        crsel -> tab
        play, -> media_play_pause


        For documentation purposes, cases are left commented with fubuki style enum identifier

     */

    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
    switch(w)
    {
        case(VK_BACK)   : return key::backspace;
        case(VK_TAB)    : return key::tab;
        case(VK_CLEAR)  : return key::clear;
        case(VK_RETURN) : return key::enter;
        case(VK_SHIFT)  : return key::shift;
        case(VK_CONTROL): return key::ctrl;
        case(VK_MENU)   : return key::alt;
        case(VK_PAUSE)  : return key::pause;
        case(VK_CAPITAL):
            return key::caps_lock;

            // case(0x15):      return key::ime_kana; // VK_KANA or VK_HANGUEL or VK_HANGUL are the same value
            // case(VK_JUNJA):   return key::ime_junja;
            // case(VK_FINAL):   return key::ime_final;
            // case(0x19):       return key::ime_kanji; // VK_KANJI and VK_HANJA have the same value
            // case(VK_IME_OFF): return key::ime_off;

        case(VK_ESCAPE):
            return key::esc;
            // case(VK_CONVERT):    return key::ime_convert;
            // case(VK_NONCONVERT): return key::ime_non_convert;
            // case(VK_ACCEPT):     return key::ime_accept;
            // case(VK_MODECHANGE): return key::ime_mode_change;

        case(VK_SPACE): return key::space;
        case(VK_PRIOR): return key::page_up;
        case(VK_NEXT) : return key::page_down;
        case(VK_END)  : return key::end;
        case(VK_HOME) : return key::home;
        case(VK_LEFT) : return key::left_arrow;

        case(VK_UP)   : return key::up_arrow;
        case(VK_RIGHT): return key::right_arrow;
        case(VK_DOWN) : return key::down_arrow;
        // case(VK_SELECT):   return key::select;
        case(VK_PRINT): return key::print;
        // case(VK_EXECUTE):  return key::execute;
        case(VK_SNAPSHOT): return key::print_screen;
        case(VK_INSERT)  : return key::insert;
        case(VK_DELETE)  : return key::del;
        case(VK_HELP)    : return key::help;
        case(VK_CANCEL)  : return key::cancel;

        case(0x30): return key::key_0;
        case(0x31): return key::key_1;
        case(0x32): return key::key_2;
        case(0x33): return key::key_3;
        case(0x34): return key::key_4;
        case(0x35): return key::key_5;
        case(0x36): return key::key_6;
        case(0x37): return key::key_7;
        case(0x38): return key::key_8;
        case(0x39): return key::key_9;

        case(0x41): return key::a;
        case(0x42): return key::b;
        case(0x43): return key::c;
        case(0x44): return key::d;
        case(0x45): return key::e;
        case(0x46): return key::f;
        case(0x47): return key::g;
        case(0x48): return key::h;
        case(0x49): return key::i;
        case(0x4a): return key::j;
        case(0x4b): return key::k;
        case(0x4c): return key::l;
        case(0x4d): return key::m;
        case(0x4e): return key::n;
        case(0x4f): return key::o;
        case(0x50): return key::p;
        case(0x51): return key::q;
        case(0x52): return key::r;
        case(0x53): return key::s;
        case(0x54): return key::t;
        case(0x55): return key::u;
        case(0x56): return key::v;
        case(0x57): return key::w;
        case(0x58): return key::x;
        case(0x59): return key::y;
        case(0x5A): return key::z;

        case(VK_LWIN)    : return key::super_left;
        case(VK_RWIN)    : return key::super_right;
        case(VK_APPS)    : return key::apps;
        case(VK_SLEEP)   : return key::sleep;
        case(VK_NUMPAD0) : return key::numpad_0;
        case(VK_NUMPAD1) : return key::numpad_1;
        case(VK_NUMPAD2) : return key::numpad_2;
        case(VK_NUMPAD3) : return key::numpad_3;
        case(VK_NUMPAD4) : return key::numpad_4;
        case(VK_NUMPAD5) : return key::numpad_5;
        case(VK_NUMPAD6) : return key::numpad_6;
        case(VK_NUMPAD7) : return key::numpad_7;
        case(VK_NUMPAD8) : return key::numpad_8;
        case(VK_NUMPAD9) : return key::numpad_9;
        case(VK_MULTIPLY): return key::multiply;
        case(VK_ADD)     : return key::add;
        // case(VK_SEPARATOR): return key::separator;
        case(VK_SUBTRACT): return key::substract;
        case(VK_DECIMAL) : return key::decimal;
        case(VK_DIVIDE)  : return key::divide;

        case(VK_F1) : return key::f1;
        case(VK_F2) : return key::f2;
        case(VK_F3) : return key::f3;
        case(VK_F4) : return key::f4;
        case(VK_F5) : return key::f5;
        case(VK_F6) : return key::f6;
        case(VK_F7) : return key::f7;
        case(VK_F8) : return key::f8;
        case(VK_F9) : return key::f9;
        case(VK_F10): return key::f10;
        case(VK_F11): return key::f11;
        case(VK_F12): return key::f12;
        case(VK_F13): return key::f13;
        case(VK_F14): return key::f14;
        case(VK_F15): return key::f15;
        case(VK_F16): return key::f16;
        case(VK_F17): return key::f17;
        case(VK_F18): return key::f18;
        case(VK_F19): return key::f19;
        case(VK_F20): return key::f20;
        case(VK_F21): return key::f21;
        case(VK_F22): return key::f22;
        case(VK_F23): return key::f23;
        case(VK_F24): return key::f24;

        case(VK_NUMLOCK): return key::numlock;
        case(VK_SCROLL):
            return key::scroll_lock;

            // case(0x92): return key::oem_specific_0;
            // case(0x93): return key::oem_specific_1;
            // case(0x94): return key::oem_specific_2;
            // case(0x95): return key::oem_specific_3;
            // case(0x96): return key::oem_specific_4;

        case(VK_LSHIFT)  : return key::shift_left;
        case(VK_RSHIFT)  : return key::shift_right;
        case(VK_LCONTROL): return key::ctrl_left;
        case(VK_RCONTROL): return key::ctrl_right;
        case(VK_LMENU)   : return key::alt_left;
        case(VK_RMENU)   : return key::alt_right;

        case(VK_BROWSER_BACK)     : return key::browser_back;
        case(VK_BROWSER_FORWARD)  : return key::browser_forward;
        case(VK_BROWSER_REFRESH)  : return key::browser_refresh;
        case(VK_BROWSER_STOP)     : return key::browser_stop;
        case(VK_BROWSER_SEARCH)   : return key::browser_search;
        case(VK_BROWSER_FAVORITES): return key::browser_favourites;
        case(VK_BROWSER_HOME)     : return key::browser_home;

        case(VK_VOLUME_MUTE): return key::volume_mute;
        case(VK_VOLUME_DOWN): return key::volume_up;
        case(VK_VOLUME_UP)  : return key::volume_down;

        case(VK_MEDIA_NEXT_TRACK)   : return key::media_next;
        case(VK_MEDIA_PREV_TRACK)   : return key::media_previous;
        case(VK_MEDIA_STOP)         : return key::media_stop;
        case(VK_MEDIA_PLAY_PAUSE)   : return key::media_play_pause;
        case(VK_LAUNCH_MAIL)        : return key::mail;
        case(VK_LAUNCH_MEDIA_SELECT): return key::media_select;

        case(VK_LAUNCH_APP1): return key::launch_app_1;
        case(VK_LAUNCH_APP2): return key::launch_app_2;

        // case(VK_OEM_1):      return key::oem_1;
        case(VK_OEM_PLUS) : return key::plus;
        case(VK_OEM_COMMA): return key::comma;
        case(VK_OEM_MINUS): return key::minus;
        case(VK_OEM_PERIOD):
            return key::period;
            // case(VK_OEM_2):      return key::oem_2;
            // case(VK_OEM_3):      return key::oem_3;
            // case(VK_OEM_4):      return key::oem_4;
            // case(VK_OEM_5):      return key::oem_5;
            // case(VK_OEM_6):      return key::oem_6;
            // case(VK_OEM_7):      return key::oem_7;
            // case(VK_OEM_8):      return key::oem_8;
            // case(0xE1):          return key::oem_specific_5;
            // case(VK_OEM_102):    return key::oem_102;

            // case(VK_PROCESSKEY): return key::ime_process;

            // case(0xe6):      return key::oem_specific_6;
            // case(VK_PACKET): return key::packet;

            // case(0xe9): return key::oem_specific_7;
            // case(0xea): return key::oem_specific_8;
            // case(0xeb): return key::oem_specific_9;
            // case(0xec): return key::oem_specific_10;
            // case(0xed): return key::oem_specific_11;
            // case(0xee): return key::oem_specific_12;
            // case(0xef): return key::oem_specific_13;
            // case(0xf0): return key::oem_specific_14;
            // case(0xf1): return key::oem_specific_15;
            // case(0xf2): return key::oem_specific_16;
            // case(0xf3): return key::oem_specific_17;
            // case(0xf4): return key::oem_specific_18;
            // case(0xf5): return key::oem_specific_19;

        case(VK_ATTN) : return key::esc;
        case(VK_CRSEL): return key::tab;
        // case(VK_EXSEL):     return key::exsel;
        // case(VK_EREOF):     return key::erof;
        case(VK_PLAY): return key::media_play_pause;
        // case(VK_ZOOM):      return key::zoom;
        // case(VK_PA1):       return key::pa1;
        case(VK_OEM_CLEAR):
            return key::clear;

            /*
             * Undefined:
             * - 0x07
             * - 0x0e -> 0x0f
             * - 0x3a -> 0x40
             */

            /*
             *  Reserved:
             * - 0x0a -> 0x0b
             * - 0x5e
             * - 0xb8 -> 0xb9
             * - 0xc1 -> 0xd7
             * - 0xe0
             * - VK_NONAME
             */

            /*
             * Unassigned:
             * - 0x88 -> 0x8f
             * - 0x97 -> 0x9f
             * - 0xd8 -> 0xda
             * - 0xe8
             */

        default: return key::unknown;
    }
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
}

//------------------------------------------------------------------------------

/// Converts fubuki::io::keyboard::key codes to Windows virtual key codes.
[[nodiscard]] FUBUKI_TRUE_PURE inline constexpr int to_windows(key k) noexcept
{
    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
    switch(k)
    {
        case key::backspace         : return VK_BACK;
        case key::tab               : return VK_TAB;
        case key::clear             : return VK_CLEAR;
        case key::enter             : return VK_RETURN;
        case key::shift             : return VK_SHIFT;
        case key::ctrl              : return VK_CONTROL;
        case key::alt               : return VK_MENU;
        case key::pause             : return VK_PAUSE;
        case key::caps_lock         : return VK_CAPITAL;
        case key::escape            : return VK_ESCAPE;
        case key::space             : return VK_SPACE;
        case key::page_up           : return VK_PRIOR;
        case key::page_down         : return VK_NEXT;
        case key::end               : return VK_END;
        case key::home              : return VK_HOME;
        case key::left_arrow        : return VK_LEFT;
        case key::up_arrow          : return (VK_UP);
        case key::right_arrow       : return VK_RIGHT;
        case key::down_arrow        : return VK_DOWN;
        case key::print             : return VK_PRINT;
        case key::print_screen      : return VK_SNAPSHOT;
        case key::insert            : return VK_INSERT;
        case key::del               : return VK_DELETE;
        case key::help              : return VK_HELP;
        case key::cancel            : return VK_CANCEL;
        case key::key_0             : return 0x30;
        case key::key_1             : return 0x31;
        case key::key_2             : return 0x32;
        case key::key_3             : return 0x33;
        case key::key_4             : return 0x34;
        case key::key_5             : return 0x35;
        case key::key_6             : return 0x36;
        case key::key_7             : return 0x37;
        case key::key_8             : return 0x38;
        case key::key_9             : return 0x39;
        case key::a                 : return 0x41;
        case key::b                 : return 0x42;
        case key::c                 : return 0x43;
        case key::d                 : return 0x44;
        case key::e                 : return 0x45;
        case key::f                 : return 0x46;
        case key::g                 : return 0x47;
        case key::h                 : return 0x48;
        case key::i                 : return 0x49;
        case key::j                 : return 0x4a;
        case key::k                 : return 0x4b;
        case key::l                 : return 0x4c;
        case key::m                 : return 0x4d;
        case key::n                 : return 0x4e;
        case key::o                 : return 0x4f;
        case key::p                 : return 0x50;
        case key::q                 : return 0x51;
        case key::r                 : return 0x52;
        case key::s                 : return 0x53;
        case key::t                 : return 0x54;
        case key::u                 : return 0x55;
        case key::v                 : return 0x56;
        case key::w                 : return 0x57;
        case key::x                 : return 0x58;
        case key::y                 : return 0x59;
        case key::z                 : return 0x5A;
        case key::super_left        : return VK_LWIN;
        case key::super_right       : return VK_RWIN;
        case key::apps              : return VK_APPS;
        case key::sleep             : return VK_SLEEP;
        case key::numpad_0          : return VK_NUMPAD0;
        case key::numpad_1          : return VK_NUMPAD1;
        case key::numpad_2          : return VK_NUMPAD2;
        case key::numpad_3          : return VK_NUMPAD3;
        case key::numpad_4          : return VK_NUMPAD4;
        case key::numpad_5          : return VK_NUMPAD5;
        case key::numpad_6          : return VK_NUMPAD6;
        case key::numpad_7          : return VK_NUMPAD7;
        case key::numpad_8          : return VK_NUMPAD8;
        case key::numpad_9          : return VK_NUMPAD9;
        case key::multiply          : return VK_MULTIPLY;
        case key::add               : return VK_ADD;
        case key::substract         : return VK_SUBTRACT;
        case key::decimal           : return VK_DECIMAL;
        case key::divide            : return VK_DIVIDE;
        case key::f1                : return VK_F1;
        case key::f2                : return VK_F2;
        case key::f3                : return VK_F3;
        case key::f4                : return VK_F4;
        case key::f5                : return VK_F5;
        case key::f6                : return VK_F6;
        case key::f7                : return VK_F7;
        case key::f8                : return VK_F8;
        case key::f9                : return VK_F9;
        case key::f10               : return VK_F10;
        case key::f11               : return VK_F11;
        case key::f12               : return VK_F12;
        case key::f13               : return VK_F13;
        case key::f14               : return VK_F14;
        case key::f15               : return VK_F15;
        case key::f16               : return VK_F16;
        case key::f17               : return VK_F17;
        case key::f18               : return VK_F18;
        case key::f19               : return VK_F19;
        case key::f20               : return VK_F20;
        case key::f21               : return VK_F21;
        case key::f22               : return VK_F22;
        case key::f23               : return VK_F23;
        case key::f24               : return VK_F24;
        case key::numlock           : return VK_NUMLOCK;
        case key::scroll_lock       : return VK_SCROLL;
        case key::plus              : return VK_OEM_PLUS;
        case key::minus             : return VK_OEM_MINUS;
        case key::comma             : return VK_OEM_COMMA;
        case key::period            : return VK_OEM_PERIOD;
        case key::shift_left        : return VK_LSHIFT;
        case key::shift_right       : return VK_RSHIFT;
        case key::ctrl_left         : return VK_LCONTROL;
        case key::ctrl_right        : return VK_RCONTROL;
        case key::alt_right         : return VK_RMENU;
        case key::alt_left          : return VK_LMENU;
        case key::browser_back      : return VK_BROWSER_BACK;
        case key::browser_forward   : return VK_BROWSER_FORWARD;
        case key::browser_refresh   : return VK_BROWSER_REFRESH;
        case key::browser_stop      : return VK_BROWSER_STOP;
        case key::browser_search    : return VK_BROWSER_SEARCH;
        case key::browser_favourites: return VK_BROWSER_FAVORITES;
        case key::browser_home      : return VK_BROWSER_HOME;
        case key::volume_mute       : return VK_VOLUME_MUTE;
        case key::volume_down       : return VK_VOLUME_DOWN;
        case key::volume_up         : return VK_VOLUME_UP;
        case key::media_select      : return VK_LAUNCH_MEDIA_SELECT;
        case key::media_next        : return VK_MEDIA_NEXT_TRACK;
        case key::media_previous    : return VK_MEDIA_PREV_TRACK;
        case key::media_stop        : return VK_MEDIA_STOP;
        case key::media_play_pause  : return VK_MEDIA_PLAY_PAUSE;
        case key::mail              : return VK_LAUNCH_MAIL;
        case key::launch_app_1      : return VK_LAUNCH_APP1;
        case key::launch_app_2      : return VK_LAUNCH_APP2;
        case key::unknown           :
        default                     : fubuki_assert(false, "Invalid key code. Perhaps static_cast?"); return {};
    }
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
}

[[nodiscard]]
inline bool poll(platform::views::display, key k) noexcept
{
    return (GetKeyState(to_windows(k)) < 0);
}

//------------------------------------------------------------------------------

[[nodiscard]]
inline modifier_mask current_modifiers(platform::views::display = {}) noexcept
{
    // NOLINTNEXTLINE(misc-redundant-expression)
    modifier_mask result = {};

    // Ctrl
    if(GetKeyState(VK_CONTROL) < 0)
    {
        result |= modifier::ctrl;
    }

    // Alt
    if(GetKeyState(VK_MENU) < 0)
    {
        result |= modifier::alt;
    }

    // Shift
    if(GetKeyState(VK_SHIFT) < 0)
    {
        result |= modifier::shift;
    }

    // Caps
    if(GetKeyState(VK_CAPITAL) < 0)
    {
        result |= modifier::caps;
    }

    return result;
}

} // namespace fubuki::io::platform::win32::keyboard

#endif // FUBUKI_IO_PLATFORM_WIN32_KEYBOARD_HPP
