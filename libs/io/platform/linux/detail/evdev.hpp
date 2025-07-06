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

#ifndef FUBUKI_IO_PLATFORM_LINUX_DETAIL_EVDEV_HPP
#define FUBUKI_IO_PLATFORM_LINUX_DETAIL_EVDEV_HPP

#include "io/platform/keyboard_key.hpp"

#include <linux/input-event-codes.h>

namespace fubuki::io::platform::linux_bsd::keyboard::detail
{

[[nodiscard]] inline constexpr std::optional<io::keyboard::key> from_evdev(std::uint32_t code) noexcept
{
    using io::keyboard::key;
    switch(code)
    {

        case(KEY_ESC)       : return key::esc;
        case(KEY_1)         : return key::key_1;
        case(KEY_2)         : return key::key_2;
        case(KEY_3)         : return key::key_3;
        case(KEY_4)         : return key::key_4;
        case(KEY_5)         : return key::key_5;
        case(KEY_6)         : return key::key_6;
        case(KEY_7)         : return key::key_7;
        case(KEY_8)         : return key::key_8;
        case(KEY_9)         : return key::key_9;
        case(KEY_0)         : return key::key_0;
        case(KEY_MINUS)     : return key::minus;
        case(KEY_EQUAL)     : return {}; // Not supported by Fubuki because it doesn't exist in Windows virtual keys
        case(KEY_BACKSPACE) : return key::backspace;
        case(KEY_TAB)       : return key::tab;
        case(KEY_Q)         : return key::q;
        case(KEY_W)         : return key::w;
        case(KEY_E)         : return key::e;
        case(KEY_R)         : return key::r;
        case(KEY_T)         : return key::t;
        case(KEY_Y)         : return key::y;
        case(KEY_U)         : return key::u;
        case(KEY_I)         : return key::i;
        case(KEY_O)         : return key::o;
        case(KEY_P)         : return key::p;
        case(KEY_LEFTBRACE) :
        case(KEY_RIGHTBRACE): return {}; // Not supported by Fubuki because it doesn't exist in Windows virtual keys
        case(KEY_ENTER)     : return key::enter;
        case(KEY_LEFTCTRL)  : return key::ctrl;
        case(KEY_A)         : return key::a;
        case(KEY_S)         : return key::s;
        case(KEY_D)         : return key::d;
        case(KEY_F)         : return key::f;
        case(KEY_G)         : return key::g;
        case(KEY_H)         : return key::h;
        case(KEY_J)         : return key::j;
        case(KEY_K)         : return key::k;
        case(KEY_L)         : return key::l;
        case(KEY_SEMICOLON) :
        case(KEY_APOSTROPHE):
        case(KEY_GRAVE)     : return {}; // Not supported by Fubuki because it doesn't exist in Windows virtual keys
        case(KEY_LEFTSHIFT) : return key::shift;
        case(KEY_BACKSLASH) : return {}; // Not supported by Fubuki because it doesn't exist in Windows virtual keys
        case(KEY_Z)         : return key::z;
        case(KEY_X)         : return key::x;
        case(KEY_C)         : return key::c;
        case(KEY_V)         : return key::v;
        case(KEY_B)         : return key::b;
        case(KEY_N)         : return key::n;
        case(KEY_M)         : return key::m;
        case(KEY_COMMA)     : return key::comma;
        case(KEY_DOT)       : return key::period;
        case(KEY_SLASH)     : return {}; // Not supported by Fubuki because it doesn't exist in Windows virtual keys
        case(KEY_RIGHTSHIFT): return key::shift_right;
        case(KEY_KPASTERISK): return key::multiply;
        case(KEY_LEFTALT)   : return key::alt_right;
        case(KEY_SPACE)     : return key::space;
        case(KEY_CAPSLOCK)  : return key::caps_lock;
        case(KEY_F1)        : return key::f1;
        case(KEY_F2)        : return key::f2;
        case(KEY_F3)        : return key::f3;
        case(KEY_F4)        : return key::f4;
        case(KEY_F5)        : return key::f5;
        case(KEY_F6)        : return key::f6;
        case(KEY_F7)        : return key::f7;
        case(KEY_F8)        : return key::f8;
        case(KEY_F9)        : return key::f9;
        case(KEY_F10)       : return key::f10;
        case(KEY_NUMLOCK)   : return key::numlock;
        case(KEY_SCROLLLOCK): return key::scroll_lock;
        case(KEY_KP7)       : return key::numpad_7;
        case(KEY_KP8)       : return key::numpad_8;
        case(KEY_KP9)       : return key::numpad_9;
        case(KEY_KPMINUS)   : return key::substract;
        case(KEY_KP4)       : return key::numpad_4;
        case(KEY_KP5)       : return key::numpad_5;
        case(KEY_KP6)       : return key::numpad_6;
        case(KEY_KPPLUS)    : return key::add;
        case(KEY_KP1)       : return key::numpad_1;
        case(KEY_KP2)       : return key::numpad_2;
        case(KEY_KP3)       : return key::numpad_3;
        case(KEY_KP0)       : return key::numpad_0;
        case(KEY_KPDOT): // Not supported by Fubuki because it doesn't exist in Windows virtual keys

        case(KEY_ZENKAKUHANKAKU):
        case(KEY_102ND)           : return {};
        case(KEY_F11)             : return key::f11;
        case(KEY_F12)             : return key::f12;
        case(KEY_RO)              :
        case(KEY_KATAKANA)        :
        case(KEY_HIRAGANA)        :
        case(KEY_HENKAN)          :
        case(KEY_KATAKANAHIRAGANA):
        case(KEY_MUHENKAN)        :
        case(KEY_KPJPCOMMA)       : return {};
        case(KEY_KPENTER)         : return key::enter;
        case(KEY_RIGHTCTRL)       : return key::ctrl_right;
        case(KEY_KPSLASH)         : return key::divide;
        case(KEY_SYSRQ)           : return {};
        case(KEY_RIGHTALT)        : return key::alt_right;
        case(KEY_LINEFEED)        : return {};
        case(KEY_HOME)            : return key::home;
        case(KEY_UP)              : return key::up_arrow;
        case(KEY_PAGEUP)          : return key::page_up;
        case(KEY_LEFT)            : return key::left_arrow;
        case(KEY_RIGHT)           : return key::right_arrow;
        case(KEY_END)             : return key::end;
        case(KEY_DOWN)            : return key::down_arrow;
        case(KEY_PAGEDOWN)        : return key::page_down;
        case(KEY_INSERT)          : return key::insert;
        case(KEY_DELETE)          : return key::del;
        case(KEY_MACRO)           : return {};
        case(KEY_MUTE)            : return key::volume_mute;
        case(KEY_VOLUMEDOWN)      : return key::volume_down;
        case(KEY_VOLUMEUP)        : return key::volume_up;
        case(KEY_POWER)           :
        case(KEY_KPEQUAL)         :
        case(KEY_KPPLUSMINUS)     : return {};
        case(KEY_PAUSE)           : return key::pause;
        case(KEY_SCALE)           : return {};

        case(KEY_KPCOMMA): return key::decimal;
        case(KEY_HANGEUL):
        case(KEY_HANJA):
        case(KEY_YEN):
        case(KEY_LEFTMETA):
        case(KEY_RIGHTMETA):
        case(KEY_COMPOSE):

        case(KEY_STOP):
        case(KEY_AGAIN):
        case(KEY_PROPS):
        case(KEY_UNDO):
        case(KEY_FRONT):
        case(KEY_COPY):
        case(KEY_OPEN):
        case(KEY_PASTE):
        case(KEY_FIND):
        case(KEY_CUT)           : return {};
        case(KEY_HELP)          : return key::help;
        case(KEY_MENU)          :
        case(KEY_CALC)          :
        case(KEY_SETUP)         : return {};
        case(KEY_SLEEP)         : return key::sleep;
        case(KEY_WAKEUP)        : return {};
        case(KEY_FILE)          :
        case(KEY_SENDFILE)      :
        case(KEY_DELETEFILE)    :
        case(KEY_XFER)          :
        case(KEY_PROG1)         :
        case(KEY_PROG2)         :
        case(KEY_WWW)           :
        case(KEY_MSDOS)         :
        case(KEY_COFFEE)        : // KEY_SCREENLOCK
        case(KEY_ROTATE_DISPLAY): // KEY_DIRECTION
        case(KEY_CYCLEWINDOWS)  :
        case(KEY_MAIL)          : return key::mail;
        case(KEY_BOOKMARKS)     : return key::browser_favourites;
        case(KEY_COMPUTER)      :
        case(KEY_BACK)          : return key::browser_back;
        case(KEY_FORWARD)       : return key::browser_forward;
        case(KEY_CLOSECD)       :
        case(KEY_EJECTCD)       :
        case(KEY_EJECTCLOSECD)  : return {};
        case(KEY_NEXTSONG)      : return key::media_next;
        case(KEY_PLAYPAUSE)     : return key::media_play_pause;
        case(KEY_PREVIOUSSONG)  : return key::media_previous;
        case(KEY_STOPCD)        :
        case(KEY_RECORD)        :
        case(KEY_REWIND)        :
        case(KEY_PHONE)         :
        case(KEY_ISO)           :
        case(KEY_CONFIG)        : return {};
        case(KEY_HOMEPAGE)      : return key::home;
        case(KEY_REFRESH)       : return key::browser_refresh;
        case(KEY_EXIT)          : return key::browser_stop;
        case(KEY_MOVE)          :
        case(KEY_EDIT)          :
        case(KEY_SCROLLUP)      : return key::page_up;
        case(KEY_SCROLLDOWN)    : return key::page_down;
        case(KEY_KPLEFTPAREN)   :
        case(KEY_KPRIGHTPAREN)  :
        case(KEY_NEW)           :
        case(KEY_REDO)          : return {};

        case(KEY_F13): return key::f13;
        case(KEY_F14): return key::f14;
        case(KEY_F15): return key::f15;
        case(KEY_F16): return key::f16;
        case(KEY_F17): return key::f17;
        case(KEY_F18): return key::f18;
        case(KEY_F19): return key::f19;
        case(KEY_F20): return key::f20;
        case(KEY_F21): return key::f21;
        case(KEY_F22): return key::f22;
        case(KEY_F23): return key::f23;
        case(KEY_F24): return key::f24;

        case(KEY_PLAYCD):
        case(KEY_PAUSECD):
        case(KEY_PROG3):
        case(KEY_PROG4):
        case(KEY_ALL_APPLICATIONS): return key::apps; // KEY_DASHBOARD
        case(KEY_SUSPEND)         :
        case(KEY_CLOSE)           : return {};
        case(KEY_PLAY)            : return key::media_play_pause;
        case(KEY_FASTFORWARD)     :
        case(KEY_BASSBOOST)       : return {};
        case(KEY_PRINT)           : return key::print;
        case(KEY_HP)              :
        case(KEY_CAMERA)          :
        case(KEY_SOUND)           :
        case(KEY_QUESTION)        : return {};
        case(KEY_EMAIL)           : return key::mail;
        case(KEY_CHAT)            : return {};
        case(KEY_SEARCH)          : return key::browser_search;
        case(KEY_CONNECT)         :
        case(KEY_FINANCE)         :
        case(KEY_SPORT)           :
        case(KEY_SHOP)            :
        case(KEY_ALTERASE)        : return {};
        case(KEY_CANCEL)          : return key::cancel;
        case(KEY_BRIGHTNESSDOWN):
        case(KEY_BRIGHTNESSUP):
        case(KEY_MEDIA):

        case(KEY_SWITCHVIDEOMODE):
        case(KEY_KBDILLUMTOGGLE):
        case(KEY_KBDILLUMDOWN):
        case(KEY_KBDILLUMUP):

        case(KEY_SEND):
        case(KEY_REPLY):
        case(KEY_FORWARDMAIL):
        case(KEY_SAVE):
        case(KEY_DOCUMENTS):

        case(KEY_BATTERY):

        case(KEY_BLUETOOTH):
        case(KEY_WLAN):
        case(KEY_UWB):

        case(KEY_UNKNOWN):

        case(KEY_VIDEO_NEXT):
        case(KEY_VIDEO_PREV):
        case(KEY_BRIGHTNESS_CYCLE):
        case(KEY_BRIGHTNESS_AUTO): // KEY_BRIGHTNESS_ZERO
        case(KEY_DISPLAY_OFF):

        case(KEY_WWAN): // KEY_WIMAX
        case(KEY_RFKILL):

        case(KEY_MICMUTE):

        case(KEY_OK):
        case(KEY_SELECT):
        case(KEY_GOTO)          : return {};
        case(KEY_CLEAR)         : return key::clear;
        case(KEY_POWER2)        :
        case(KEY_OPTION)        :
        case(KEY_INFO)          :
        case(KEY_TIME)          :
        case(KEY_VENDOR)        :
        case(KEY_ARCHIVE)       :
        case(KEY_PROGRAM)       :
        case(KEY_CHANNEL)       :
        case(KEY_FAVORITES)     :
        case(KEY_EPG)           : return {};
        case(KEY_PVR)           : return key::media_select;
        case(KEY_MHP)           :
        case(KEY_LANGUAGE)      :
        case(KEY_TITLE)         :
        case(KEY_SUBTITLE)      :
        case(KEY_ANGLE)         :
        case(KEY_FULL_SCREEN)   : // KEY_FULL_SCREEN
        case(KEY_MODE)          :
        case(KEY_KEYBOARD)      :
        case(KEY_ASPECT_RATIO)  : // KEY_ASPECT_RATIO
        case(KEY_PC)            :
        case(KEY_TV)            :
        case(KEY_TV2)           :
        case(KEY_VCR)           :
        case(KEY_VCR2)          :
        case(KEY_SAT)           :
        case(KEY_SAT2)          :
        case(KEY_CD)            :
        case(KEY_TAPE)          :
        case(KEY_RADIO)         :
        case(KEY_TUNER)         :
        case(KEY_PLAYER)        :
        case(KEY_TEXT)          :
        case(KEY_DVD)           :
        case(KEY_AUX)           :
        case(KEY_MP3)           :
        case(KEY_AUDIO)         :
        case(KEY_VIDEO)         :
        case(KEY_DIRECTORY)     :
        case(KEY_LIST)          :
        case(KEY_MEMO)          :
        case(KEY_CALENDAR)      :
        case(KEY_RED)           :
        case(KEY_GREEN)         :
        case(KEY_YELLOW)        :
        case(KEY_BLUE)          :
        case(KEY_CHANNELUP)     :
        case(KEY_CHANNELDOWN)   :
        case(KEY_FIRST)         :
        case(KEY_LAST)          :
        case(KEY_AB)            : return {};
        case(KEY_NEXT)          : return key::next;
        case(KEY_RESTART)       :
        case(KEY_SLOW)          :
        case(KEY_SHUFFLE)       :
        case(KEY_BREAK)         :
        case(KEY_PREVIOUS)      : return key::prior;
        case(KEY_DIGITS)        :
        case(KEY_TEEN)          :
        case(KEY_TWEN)          :
        case(KEY_VIDEOPHONE)    :
        case(KEY_GAMES)         :
        case(KEY_ZOOMIN)        :
        case(KEY_ZOOMOUT)       :
        case(KEY_ZOOMRESET)     :
        case(KEY_WORDPROCESSOR) :
        case(KEY_EDITOR)        :
        case(KEY_SPREADSHEET)   :
        case(KEY_GRAPHICSEDITOR):
        case(KEY_PRESENTATION)  :
        case(KEY_DATABASE)      :
        case(KEY_NEWS)          :
        case(KEY_VOICEMAIL)     :
        case(KEY_ADDRESSBOOK)   :
        case(KEY_MESSENGER)     : return key::mail;
        case(KEY_DISPLAYTOGGLE): // KEY_DISPLAYTOGGLE
        case(KEY_SPELLCHECK):
        case(KEY_LOGOFF):

        case(KEY_DOLLAR):
        case(KEY_EURO):

        case(KEY_FRAMEBACK):
        case(KEY_FRAMEFORWARD):
        case(KEY_CONTEXT_MENU):
        case(KEY_MEDIA_REPEAT):
        case(KEY_10CHANNELSUP):
        case(KEY_10CHANNELSDOWN):
        case(KEY_IMAGES):
        case(KEY_NOTIFICATION_CENTER):
        case(KEY_PICKUP_PHONE):
        case(KEY_HANGUP_PHONE):

        case(KEY_DEL_EOL):
        case(KEY_DEL_EOS):
        case(KEY_INS_LINE):
        case(KEY_DEL_LINE):

        case(KEY_FN):
        case(KEY_FN_ESC):
        case(KEY_FN_F1):
        case(KEY_FN_F2):
        case(KEY_FN_F3):
        case(KEY_FN_F4):
        case(KEY_FN_F5):
        case(KEY_FN_F6):
        case(KEY_FN_F7):
        case(KEY_FN_F8):
        case(KEY_FN_F9):
        case(KEY_FN_F10):
        case(KEY_FN_F11):
        case(KEY_FN_F12):
        case(KEY_FN_1):
        case(KEY_FN_2):
        case(KEY_FN_D):
        case(KEY_FN_E):
        case(KEY_FN_F):
        case(KEY_FN_S):
        case(KEY_FN_B):
        case(KEY_FN_RIGHT_SHIFT):

        case(KEY_BRL_DOT1):
        case(KEY_BRL_DOT2):
        case(KEY_BRL_DOT3):
        case(KEY_BRL_DOT4):
        case(KEY_BRL_DOT5):
        case(KEY_BRL_DOT6):
        case(KEY_BRL_DOT7):
        case(KEY_BRL_DOT8):
        case(KEY_BRL_DOT9):
        case(KEY_BRL_DOT10): return {};

        case(KEY_NUMERIC_0)   : return key::key_0;
        case(KEY_NUMERIC_1)   : return key::key_1;
        case(KEY_NUMERIC_2)   : return key::key_2;
        case(KEY_NUMERIC_3)   : return key::key_3;
        case(KEY_NUMERIC_4)   : return key::key_4;
        case(KEY_NUMERIC_5)   : return key::key_5;
        case(KEY_NUMERIC_6)   : return key::key_6;
        case(KEY_NUMERIC_7)   : return key::key_7;
        case(KEY_NUMERIC_8)   : return key::key_8;
        case(KEY_NUMERIC_9)   : return key::key_9;
        case(KEY_NUMERIC_STAR): return key::multiply;
        case(KEY_NUMERIC_POUND):
        case(KEY_NUMERIC_A):
        case(KEY_NUMERIC_B):
        case(KEY_NUMERIC_C):
        case(KEY_NUMERIC_D):

        case(KEY_CAMERA_FOCUS):
        case(KEY_WPS_BUTTON):

        case(KEY_TOUCHPAD_TOGGLE):
        case(KEY_TOUCHPAD_ON):
        case(KEY_TOUCHPAD_OFF):

        case(KEY_CAMERA_ZOOMIN):
        case(KEY_CAMERA_ZOOMOUT):
        case(KEY_CAMERA_UP):
        case(KEY_CAMERA_DOWN):
        case(KEY_CAMERA_LEFT):
        case(KEY_CAMERA_RIGHT):

        case(KEY_ATTENDANT_ON):
        case(KEY_ATTENDANT_OFF):
        case(KEY_ATTENDANT_TOGGLE):
        case(KEY_LIGHTS_TOGGLE):

        default: return {};
    }
}

} // namespace fubuki::io::platform::linux_bsd::keyboard::detail

#endif // FUBUKI_IO_PLATFORM_LINUX_DETAIL_EVDEV_HPP
