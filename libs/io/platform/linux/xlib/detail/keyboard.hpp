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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_DETAIL_KEYBOARD_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_DETAIL_KEYBOARD_HPP

#include <optional>

#include <core/detail/platform_forward.hpp>

#include "io/platform/keyboard_key.hpp"

#include <X11/keysym.h>
#include <X11/Xlib.h>

// NOLINTBEGIN
// The following are extracted from the respective APIS (Windows, Xlib, Wayland...).
// Don't touch!

extern "C"
{

using KeySym = XID;

} // extern "C"
// NOLINTEND

namespace fubuki::io::platform::linux_bsd::xlib::keyboard
{

using io::keyboard::key;
using io::keyboard::modifier;
using io::keyboard::modifier_mask;

namespace detail
{

[[nodiscard]]
inline constexpr std::optional<key> from_key_sym(const KeySym key_sym) noexcept
{
    switch(key_sym)
    {
        case XK_BackSpace  : return key::backspace;
        case XK_Tab        : return key::tab;
        case XK_Clear      : return key::clear;
        case XK_Return     : return key::enter;
        case XK_Shift_L    : return key::shift;
        case XK_Control_L  : return key::ctrl;
        case XK_Alt_L      : return key::alt;
        case XK_Pause      : return key::pause;
        case XK_Caps_Lock  : return key::caps_lock;
        case XK_Escape     : return key::esc;
        case XK_space      : return key::space;
        case XK_Page_Up    : return key::page_up;
        case XK_Page_Down  : return key::page_down;
        case XK_End        : return key::end;
        case XK_Home       : return key::home;
        case XK_Left       : return key::left_arrow;
        case XK_Up         : return key::up_arrow;
        case XK_Right      : return key::right_arrow;
        case XK_Down       : return key::down_arrow;
        case XK_Print      : return key::print;
        case XK_Insert     : return key::insert;
        case XK_Delete     : return key::del;
        case XK_Help       : return key::help;
        case XK_Cancel     : return key::cancel;
        case XK_0          : return key::key_0;
        case XK_1          : return key::key_1;
        case XK_2          : return key::key_2;
        case XK_3          : return key::key_3;
        case XK_4          : return key::key_4;
        case XK_5          : return key::key_5;
        case XK_6          : return key::key_6;
        case XK_7          : return key::key_7;
        case XK_8          : return key::key_8;
        case XK_9          : return key::key_9;
        case XK_a          :
        case XK_A          : return key::a;
        case XK_b          :
        case XK_B          : return key::b;
        case XK_c          :
        case XK_C          : return key::c;
        case XK_d          :
        case XK_D          : return key::d;
        case XK_e          :
        case XK_E          : return key::e;
        case XK_f          :
        case XK_F          : return key::f;
        case XK_g          :
        case XK_G          : return key::g;
        case XK_h          :
        case XK_H          : return key::h;
        case XK_i          :
        case XK_I          : return key::i;
        case XK_j          :
        case XK_J          : return key::j;
        case XK_k          :
        case XK_K          : return key::k;
        case XK_l          :
        case XK_L          : return key::l;
        case XK_m          :
        case XK_M          : return key::m;
        case XK_n          :
        case XK_N          : return key::n;
        case XK_o          :
        case XK_O          : return key::o;
        case XK_p          :
        case XK_P          : return key::p;
        case XK_q          :
        case XK_Q          : return key::q;
        case XK_r          :
        case XK_R          : return key::r;
        case XK_s          :
        case XK_S          : return key::s;
        case XK_t          :
        case XK_T          : return key::t;
        case XK_u          :
        case XK_U          : return key::u;
        case XK_v          :
        case XK_V          : return key::v;
        case XK_w          :
        case XK_W          : return key::w;
        case XK_x          :
        case XK_X          : return key::x;
        case XK_y          :
        case XK_Y          : return key::y;
        case XK_z          :
        case XK_Z          : return key::z;
        case XK_Super_L    : return key::super_left;
        case XK_Super_R    : return key::super_right;
        case XK_KP_0       : return key::numpad_0;
        case XK_KP_1       : return key::numpad_1;
        case XK_KP_2       : return key::numpad_2;
        case XK_KP_3       : return key::numpad_3;
        case XK_KP_4       : return key::numpad_4;
        case XK_KP_5       : return key::numpad_5;
        case XK_KP_6       : return key::numpad_6;
        case XK_KP_7       : return key::numpad_7;
        case XK_KP_8       : return key::numpad_8;
        case XK_KP_9       : return key::numpad_9;
        case XK_KP_Multiply: return key::multiply;
        case XK_KP_Add     : return key::add;
        case XK_KP_Subtract: return key::substract;
        case XK_KP_Decimal : return key::decimal;
        case XK_KP_Divide  : return key::divide;
        case XK_F1         : return key::f1;
        case XK_F2         : return key::f2;
        case XK_F3         : return key::f3;
        case XK_F4         : return key::f4;
        case XK_F5         : return key::f5;
        case XK_F6         : return key::f6;
        case XK_F7         : return key::f7;
        case XK_F8         : return key::f8;
        case XK_F9         : return key::f9;
        case XK_F10        : return key::f10;
        case XK_F11        : return key::f11;
        case XK_F12        : return key::f12;
        case XK_F13        : return key::f13;
        case XK_F14        : return key::f14;
        case XK_F15        : return key::f15;
        case XK_F16        : return key::f16;
        case XK_F17        : return key::f17;
        case XK_F18        : return key::f18;
        case XK_F19        : return key::f19;
        case XK_F20        : return key::f20;
        case XK_F21        : return key::f21;
        case XK_F22        : return key::f22;
        case XK_F23        : return key::f23;
        case XK_F24        : return key::f24;
        case XK_Num_Lock   : return key::numlock;
        case XK_Scroll_Lock: return key::scroll_lock;
        case XK_plus       : return key::plus;
        case XK_minus      : return key::minus;
        case XK_comma      : return key::comma;
        case XK_period     : return key::period;
        case XK_Shift_R    : return key::shift_right;
        case XK_Control_R  : return key::ctrl_right;
        case XK_Alt_R:
            return key::alt_right;
            // For XLib, their is no distinction between shift and left shitft
        // case XK_Shift_L    : return key::;
        // case XK_Control_L  : return key::;
        // case XK_Alt_L      : return key::;
        default: return {};
    }
}

/// Returns the key sym associated to a keyboard::key.
[[nodiscard]] inline constexpr std::optional<KeySym> to_xlib_sym(key k) noexcept
{
    switch(k)
    {
        case key::backspace   : return XK_BackSpace;
        case key::tab         : return XK_Tab;
        case key::clear       : return XK_Clear;
        case key::enter       : return XK_Return;
        case key::shift       : return XK_Shift_L;
        case key::ctrl        : return XK_Control_L;
        case key::alt         : return XK_Alt_L;
        case key::pause       : return XK_Pause;
        case key::caps_lock   : return XK_Caps_Lock;
        case key::escape      : return XK_Escape;
        case key::space       : return XK_space;
        case key::page_up     : return XK_Page_Up;
        case key::page_down   : return XK_Page_Down;
        case key::end         : return XK_End;
        case key::home        : return XK_Home;
        case key::left_arrow  : return XK_Left;
        case key::up_arrow    : return XK_Up;
        case key::right_arrow : return XK_Right;
        case key::down_arrow  : return XK_Down;
        case key::print       : return XK_Print;
        case key::print_screen: return {}; // XK_PrintScreen does not exist
        case key::insert      : return XK_Insert;
        case key::del         : return XK_Delete;
        case key::help        : return XK_Help;
        case key::cancel      : return XK_Cancel;
        case key::key_0       : return XK_0;
        case key::key_1       : return XK_1;
        case key::key_2       : return XK_2;
        case key::key_3       : return XK_3;
        case key::key_4       : return XK_4;
        case key::key_5       : return XK_5;
        case key::key_6       : return XK_6;
        case key::key_7       : return XK_7;
        case key::key_8       : return XK_8;
        case key::key_9       : return XK_9;
        case key::a           : return XK_A;
        case key::b           : return XK_B;
        case key::c           : return XK_C;
        case key::d           : return XK_D;
        case key::e           : return XK_E;
        case key::f           : return XK_F;
        case key::g           : return XK_G;
        case key::h           : return XK_H;
        case key::i           : return XK_I;
        case key::j           : return XK_J;
        case key::k           : return XK_K;
        case key::l           : return XK_L;
        case key::m           : return XK_M;
        case key::n           : return XK_N;
        case key::o           : return XK_O;
        case key::p           : return XK_P;
        case key::q           : return XK_Q;
        case key::r           : return XK_R;
        case key::s           : return XK_S;
        case key::t           : return XK_T;
        case key::u           : return XK_U;
        case key::v           : return XK_V;
        case key::w           : return XK_W;
        case key::x           : return XK_X;
        case key::y           : return XK_Y;
        case key::z           : return XK_Z;
        case key::super_left  : return XK_Super_L;
        case key::super_right : return XK_Super_R;
        case key::apps        : return {}; // NOLINT(bugprone-branch-clone): XK_Apps does not exist
        case key::sleep       : return {}; // XK_Sleep does not exist
        case key::numpad_0    : return XK_KP_0;
        case key::numpad_1    : return XK_KP_1;
        case key::numpad_2    : return XK_KP_2;
        case key::numpad_3    : return XK_KP_3;
        case key::numpad_4    : return XK_KP_4;
        case key::numpad_5    : return XK_KP_5;
        case key::numpad_6    : return XK_KP_6;
        case key::numpad_7    : return XK_KP_7;
        case key::numpad_8    : return XK_KP_8;
        case key::numpad_9    : return XK_KP_9;
        case key::multiply    : return XK_KP_Multiply;
        case key::add         : return XK_KP_Add;
        case key::substract   : return XK_KP_Subtract;
        case key::decimal     : return XK_KP_Decimal;
        case key::divide      : return XK_KP_Divide;
        case key::f1          : return XK_F1;
        case key::f2          : return XK_F2;
        case key::f3          : return XK_F3;
        case key::f4          : return XK_F4;
        case key::f5          : return XK_F5;
        case key::f6          : return XK_F6;
        case key::f7          : return XK_F7;
        case key::f8          : return XK_F8;
        case key::f9          : return XK_F9;
        case key::f10         : return XK_F10;
        case key::f11         : return XK_F11;
        case key::f12         : return XK_F12;
        case key::f13         : return XK_F13;
        case key::f14         : return XK_F14;
        case key::f15         : return XK_F15;
        case key::f16         : return XK_F16;
        case key::f17         : return XK_F17;
        case key::f18         : return XK_F18;
        case key::f19         : return XK_F19;
        case key::f20         : return XK_F20;
        case key::f21         : return XK_F21;
        case key::f22         : return XK_F22;
        case key::f23         : return XK_F23;
        case key::f24         : return XK_F24;
        case key::numlock     : return XK_Num_Lock;
        case key::scroll_lock : return XK_Scroll_Lock;
        case key::plus        : return XK_plus;
        case key::minus       : return XK_minus;
        case key::comma       : return XK_comma;
        case key::period      : return XK_period;
        case key::shift_left  : return XK_Shift_L;
        case key::shift_right : return XK_Shift_R;
        case key::ctrl_left   : return XK_Control_L;
        case key::ctrl_right  : return XK_Control_R;
        case key::alt_left    : return XK_Alt_L;
        case key::alt_right:
            return XK_Alt_R;
            // NOLINTBEGIN(bugprone-branch-clone)
        case key::browser_back      : return {}; // XK_Browser_Back does not exist
        case key::browser_forward   : return {}; // XK_Browser_Forward does not exist
        case key::browser_refresh   : return {}; // XK_Browser_Refresh does not exist
        case key::browser_stop      : return {}; // XK_Browser_Stop does not exist
        case key::browser_search    : return {}; // XK_Browser_Search does not exist
        case key::browser_favourites: return {}; // XK_Browser_Favourites does not exist
        case key::browser_home      : return {}; // XK_Browser_Home does not exist
        case key::volume_mute       : return {}; // XK_Volume_Mute does not exist
        case key::volume_down       : return {}; // XK_Volume_Down does not exist
        case key::volume_up         : return {}; // XK_Volume_Up does not exist
        case key::media_select      : return {}; // XK_Media_Select does not exist
        case key::media_next        : return {}; // XK_Media_Next does not exist
        case key::media_previous    : return {}; // XK_Media_Previous does not exist
        case key::media_stop        : return {}; // XK_Media_Stop does not exist
        case key::media_play_pause  : return {}; // XK_Media_Play_Pause does not exist
        case key::mail              : return {}; // XK_Mail does not exist
        case key::launch_app_1      : return {};       // XK_Launch_App_1 does not exist
        case key::launch_app_2:
            return {}; // XK_Launch_App_2 does not exist
            // NOLINTEND(bugprone-branch-clone)
        case key::unknown:
        default          : return {};
    }
}

} // namespace detail

} // namespace fubuki::io::platform::linux_bsd::xlib::keyboard

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_DETAIL_KEYBOARD_HPP
