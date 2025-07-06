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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XKB_KEY_CODE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XKB_KEY_CODE_HPP

#include "io/platform/keyboard_key.hpp"

#include <xkbcommon/xkbcommon-keysyms.h>

namespace fubuki::io::platform::linux_bsd::xkb
{

[[nodiscard]] constexpr keyboard::key from(std::uint32_t k) noexcept
{
    using key = keyboard::key;

    switch(k)
    {
        case(XKB_KEY_BackSpace)  : return key::backspace;
        case(XKB_KEY_Tab)        : return key::tab;
        case(XKB_KEY_Linefeed)   : return key::enter;
        case(XKB_KEY_Clear)      : return key::clear;
        case(XKB_KEY_Return)     : return key::enter;
        case(XKB_KEY_Pause)      : return key::pause;
        case(XKB_KEY_Scroll_Lock): return key::scroll_lock;
        case(XKB_KEY_Escape)     : return key::escape;
        case(XKB_KEY_Delete)     : return key::del;

        case(XKB_KEY_Home) : return key::home;
        case(XKB_KEY_Left) : return key::left_arrow;
        case(XKB_KEY_Up)   : return key::up_arrow;
        case(XKB_KEY_Right): return key::right_arrow;
        case(XKB_KEY_Down) : return key::down_arrow;
        case(XKB_KEY_Prior): return key::page_up;   // XKB_KEY_Prior is an alias to XKB_KEY_Page_Up
        case(XKB_KEY_Next) : return key::page_down; // XKB_KEY_Next is an alias to XKB_KEY_Page_Down
        case(XKB_KEY_End)  : return key::end;
        // case(XKB_KEY_Select       ): return key::select;
        case(XKB_KEY_Print): return key::print;
        // case(XKB_KEY_Execute      ): return key::;
        case(XKB_KEY_Insert): return key::insert;
        // case(XKB_KEY_Undo         ): return key::undo;
        // case(XKB_KEY_Redo         ): return key::redo;
        // case(XKB_KEY_Menu         ): return key::menu;
        case(XKB_KEY_Find)  : return key::browser_search;
        case(XKB_KEY_Cancel): return key::cancel;
        case(XKB_KEY_Help)  : return key::help;
        case(XKB_KEY_Break) : return key::cancel;
        // case(XKB_KEY_Mode_switch  ): return key::mode_switch; // XKB_KEY_script_switch
        case(XKB_KEY_Num_Lock): return key::numlock;

        case(XKB_KEY_F1) : return key::f1;
        case(XKB_KEY_F2) : return key::f2;
        case(XKB_KEY_F3) : return key::f3;
        case(XKB_KEY_F4) : return key::f4;
        case(XKB_KEY_F5) : return key::f5;
        case(XKB_KEY_F6) : return key::f6;
        case(XKB_KEY_F7) : return key::f7;
        case(XKB_KEY_F8) : return key::f8;
        case(XKB_KEY_F9) : return key::f9;
        case(XKB_KEY_F10): return key::f10;
        case(XKB_KEY_F11): return key::f11;
        case(XKB_KEY_F12): return key::f12;
        case(XKB_KEY_F13): return key::f13;
        case(XKB_KEY_F14): return key::f14;
        case(XKB_KEY_F15): return key::f15;
        case(XKB_KEY_F16): return key::f16;
        case(XKB_KEY_F17): return key::f17;
        case(XKB_KEY_F18): return key::f18;
        case(XKB_KEY_F19): return key::f19;
        case(XKB_KEY_F20): return key::f20;
        case(XKB_KEY_F21): return key::f21;
        case(XKB_KEY_F22): return key::f22;
        case(XKB_KEY_F23): return key::f23;
        case(XKB_KEY_F24): return key::f24;

        case(XKB_KEY_Shift_L)  : return key::shift_left;
        case(XKB_KEY_Shift_R)  : return key::shift_right;
        case(XKB_KEY_Control_L): return key::ctrl_left;
        case(XKB_KEY_Control_R): return key::ctrl_right;
        case(XKB_KEY_Caps_Lock): return key::caps_lock;

        case(XKB_KEY_Alt_L)  : return key::alt_left;
        case(XKB_KEY_Alt_R)  : return key::alt_right;
        case(XKB_KEY_Super_L): return key::super_left;
        case(XKB_KEY_Super_R): return key::super_right;

        case(XKB_KEY_space): return key::space;
        // case(XKB_KEY_exclam                    ): return key::ex;
        // case(XKB_KEY_quotedbl                  ): return key::;
        // case(XKB_KEY_numbersign                ): return key::;
        // case(XKB_KEY_dollar                    ): return key::dol;
        // case(XKB_KEY_percent                   ): return key::per;
        // case(XKB_KEY_ampersand                 ): return key::amp;
        // case(XKB_KEY_apostrophe                ): return key::apo;
        // case(XKB_KEY_quoteright                ): return key::qu;
        // case(XKB_KEY_parenleft                 ): return key::;
        // case(XKB_KEY_parenright                ): return key::;
        // case(XKB_KEY_asterisk                  ): return key::as;
        case(XKB_KEY_plus)  : return key::plus;
        case(XKB_KEY_comma) : return key::comma;
        case(XKB_KEY_minus) : return key::minus;
        case(XKB_KEY_period): return key::period;
        case(XKB_KEY_slash) : return key::divide;

        case(XKB_KEY_KP_0)       : return key::numpad_0;
        case(XKB_KEY_KP_1)       : return key::numpad_1;
        case(XKB_KEY_KP_2)       : return key::numpad_2;
        case(XKB_KEY_KP_3)       : return key::numpad_3;
        case(XKB_KEY_KP_4)       : return key::numpad_4;
        case(XKB_KEY_KP_5)       : return key::numpad_5;
        case(XKB_KEY_KP_6)       : return key::numpad_6;
        case(XKB_KEY_KP_7)       : return key::numpad_7;
        case(XKB_KEY_KP_8)       : return key::numpad_8;
        case(XKB_KEY_KP_9)       : return key::numpad_9;
        case(XKB_KEY_KP_Multiply): return key::multiply;
        case(XKB_KEY_KP_Add)     : return key::add;
        case(XKB_KEY_KP_Subtract): return key::substract;
        case(XKB_KEY_KP_Decimal) : return key::decimal;
        case(XKB_KEY_KP_Divide)  : return key::divide;

        case(XKB_KEY_0): return key::key_0;
        case(XKB_KEY_1): return key::key_1;
        case(XKB_KEY_2): return key::key_2;
        case(XKB_KEY_3): return key::key_3;
        case(XKB_KEY_4): return key::key_4;
        case(XKB_KEY_5): return key::key_5;
        case(XKB_KEY_6): return key::key_6;
        case(XKB_KEY_7): return key::key_7;
        case(XKB_KEY_8): return key::key_8;
        case(XKB_KEY_9):
            return key::key_9;
            // case(XKB_KEY_colon)       : return key :;
            // case(XKB_KEY_semicolon                 ): return key::semicolon;
            // case(XKB_KEY_less                      ): return key::less;
            // case(XKB_KEY_equal                     ): return key::equal;
            // case(XKB_KEY_greater                   ): return key::;
            // case(XKB_KEY_question                  ): return key::;
            // case(XKB_KEY_at                        ): return key::;
        case(XKB_KEY_a):
        case(XKB_KEY_A): return key::a;
        case(XKB_KEY_b):
        case(XKB_KEY_B): return key::b;
        case(XKB_KEY_c):
        case(XKB_KEY_C): return key::c;
        case(XKB_KEY_d):
        case(XKB_KEY_D): return key::d;
        case(XKB_KEY_e):
        case(XKB_KEY_E): return key::e;
        case(XKB_KEY_f):
        case(XKB_KEY_F): return key::f;
        case(XKB_KEY_g):
        case(XKB_KEY_G): return key::g;
        case(XKB_KEY_h):
        case(XKB_KEY_H): return key::h;
        case(XKB_KEY_i):
        case(XKB_KEY_I): return key::i;
        case(XKB_KEY_j):
        case(XKB_KEY_J): return key::j;
        case(XKB_KEY_k):
        case(XKB_KEY_K): return key::k;
        case(XKB_KEY_l):
        case(XKB_KEY_L): return key::l;
        case(XKB_KEY_m):
        case(XKB_KEY_M): return key::m;
        case(XKB_KEY_n):
        case(XKB_KEY_N): return key::n;
        case(XKB_KEY_o):
        case(XKB_KEY_O): return key::o;
        case(XKB_KEY_p):
        case(XKB_KEY_P): return key::p;
        case(XKB_KEY_q):
        case(XKB_KEY_Q): return key::q;
        case(XKB_KEY_r):
        case(XKB_KEY_R): return key::r;
        case(XKB_KEY_s):
        case(XKB_KEY_S): return key::s;
        case(XKB_KEY_t):
        case(XKB_KEY_T): return key::t;
        case(XKB_KEY_u):
        case(XKB_KEY_U): return key::u;
        case(XKB_KEY_v):
        case(XKB_KEY_V): return key::v;
        case(XKB_KEY_w):
        case(XKB_KEY_W): return key::w;
        case(XKB_KEY_x):
        case(XKB_KEY_X): return key::x;
        case(XKB_KEY_y):
        case(XKB_KEY_Y): return key::y;
        case(XKB_KEY_z):
        case(XKB_KEY_Z):
            return key::z;
            // case(XKB_KEY_bracketleft               ): return key::;
            // case(XKB_KEY_backslash                 ): return key::ba;
            // case(XKB_KEY_bracketright              ): return key::;
            // case(XKB_KEY_asciicircum               ): return key::;
            // case(XKB_KEY_underscore                ): return key::;
            // case(XKB_KEY_grave                     ): return key::;
            // case(XKB_KEY_quoteleft                 ): return key::;

            // Keys not supported by Fubuki
            // Misc
            // case(XKB_KEY_Sys_Req):

            // Japanese input
            // case(XKB_KEY_Multi_key):
            // case(XKB_KEY_Codeinput): // XKB_KEY_Kanji_Bangou
            // case(XKB_KEY_SingleCandidate):
            // case(XKB_KEY_MultipleCandidate): // XKB_KEY_Zen_Koho
            // case(XKB_KEY_PreviousCandidate): // XKB_KEY_Mae_Koho
            // case(XKB_KEY_Kanji):
            // case(XKB_KEY_Muhenkan):
            // case(XKB_KEY_Henkan_Mode): // XKB_KEY_Henkan
            // case(XKB_KEY_Romaji):
            // case(XKB_KEY_Hiragana):
            // case(XKB_KEY_Katakana):
            // case(XKB_KEY_Hiragana_Katakana):
            // case(XKB_KEY_Zenkaku):
            // case(XKB_KEY_Hankaku):
            // case(XKB_KEY_Zenkaku_Hankaku):
            // case(XKB_KEY_Touroku):
            // case(XKB_KEY_Massyo):
            // case(XKB_KEY_Kana_Lock):
            // case(XKB_KEY_Kana_Shift):
            // case(XKB_KEY_Eisu_Shift):
            // case(XKB_KEY_Eisu_toggle):

            // Begin key - not sure what this is, or was
            // case(XKB_KEY_Begin):

            // Keypad
            // case(XKB_KEY_KP_Space):
            // case(XKB_KEY_KP_Tab):
            // case(XKB_KEY_KP_Enter):
            // case(XKB_KEY_KP_F1):
            // case(XKB_KEY_KP_F2):
            // case(XKB_KEY_KP_F3):
            // case(XKB_KEY_KP_F4):
            // case(XKB_KEY_KP_Home):
            // case(XKB_KEY_KP_Left):
            // case(XKB_KEY_KP_Up):
            // case(XKB_KEY_KP_Right):
            // case(XKB_KEY_KP_Down):
            // case(XKB_KEY_KP_Prior):
            // case(XKB_KEY_KP_Page_Up):
            // case(XKB_KEY_KP_Next):
            // case(XKB_KEY_KP_Page_Down):
            // case(XKB_KEY_KP_End):
            // case(XKB_KEY_KP_Begin):
            // case(XKB_KEY_KP_Insert):
            // case(XKB_KEY_KP_Delete):
            // case(XKB_KEY_KP_Equal):
            // case(XKB_KEY_KP_Multiply):
            // case(XKB_KEY_KP_Add):
            // case(XKB_KEY_KP_Separator):
            // case(XKB_KEY_KP_Subtract):
            // case(XKB_KEY_KP_Decimal):
            // case(XKB_KEY_KP_Divide):
            // case(XKB_KEY_KP_0):
            // case(XKB_KEY_KP_1):
            // case(XKB_KEY_KP_2):
            // case(XKB_KEY_KP_3):
            // case(XKB_KEY_KP_4):
            // case(XKB_KEY_KP_5):
            // case(XKB_KEY_KP_6):
            // case(XKB_KEY_KP_7):
            // case(XKB_KEY_KP_8):
            // case(XKB_KEY_KP_9):

            // F25 - F35
            // case(XKB_KEY_F25): return key::f25;
            // case(XKB_KEY_F26): return key::f26;
            // case(XKB_KEY_F27): return key::f27;
            // case(XKB_KEY_F28): return key::f28;
            // case(XKB_KEY_F29): return key::f29;
            // case(XKB_KEY_F30): return key::f30;
            // case(XKB_KEY_F31): return key::f31;
            // case(XKB_KEY_F32): return key::f32;
            // case(XKB_KEY_F33): return key::f33;
            // case(XKB_KEY_F34): return key::f34;
            // case(XKB_KEY_F35): return key::f35;

            // Modifiers
            // case( XKB_KEY_Shift_Lock ): return key::shift_lock;
            // case( XKB_KEY_Meta_L     ): return key::;
            // case( XKB_KEY_Meta_R     ): return key::;
            // case( XKB_KEY_Hyper_L    ): return key::;
            // case( XKB_KEY_Hyper_R    ): return key::;

        default: return key::unknown;
    }
}

} // namespace fubuki::io::platform::linux_bsd::xkb

#endif // FUBUKI_IO_PLATFORM_LINUX_XKB_KEY_CODE_HPP
