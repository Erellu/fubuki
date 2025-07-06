/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2025, Erwan DUHAMEL
 * All rights reserved.
 *
 * Redistribution and use in cause and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of cause code must retain the above copyright notice, this
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

#ifndef FUBUKI_IO_PLATFORM_EVENT_SOURCE_HPP
#define FUBUKI_IO_PLATFORM_EVENT_SOURCE_HPP

#include <ostream>

namespace fubuki::io::platform::event
{

// TODO: check how this works with X11 and Wayland
// Pointer: https://askubuntu.com/questions/1130940/x11-recognize-source-device-of-event

/**
 *  Indicates what triggered an event.
 *
 *  Values from this enumeration is also used to specify on which queue an event must be added by fubuki::io::send.
 *  - When source::system is specified, the event is translated into a native event and added to the system event queue.
 *  - When any other value is specified, the event is added to Fubuki's internal event queue.
 *
 *   NOTE: when sending a custom event, io::event::send adds the event to Fubuki's internal event queue, regardless of the
 *   value set by the user.
 */
enum class origin
{
    unknown, ///< The event source is unknown. This can occur in circumstances in which the system is busy processing several events at the same time.
    artificial, ///< The user triggered the event by io::event::send, or a platform-specific mechanism, or even another process.
    system,     ///< The event comes from the system.
    hardware,   ///< The event comes from external hardware (mouse, keyboard, game controllers, drawing devices, etc.).
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const event::origin s)
{
    switch(s)
    {
        case origin::unknown   : return out << "origin::unknown";
        case origin::artificial: return out << "origin::artificial";
        case origin::system    : return out << "origin::system";
        case origin::hardware  : return out << "origin::hardware";
        default                : return out << "<Invalid value> -  Perhaps static_cast?";
    }
}

/**
 * Indicate the nature of the device that triggered an event.
 */
enum class device
{
    unknown,     ///< The device that triggered the event is unknown.
    keyboard,    ///< The event was triggered through keyboard input.
    mouse,       ///< The event was triggered through mouse input.
    touchscreen, ///< The event was triggered by a touch screen
    pen,         ///< The event was triggered by a pen.
    touchpad,    ///< The event was triggered by a touchpad.
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const event::device d)
{
    switch(d)
    {
        case device::unknown    : return out << "device::unknown";
        case device::keyboard   : return out << "device::keyboard";
        case device::mouse      : return out << "device::mouse";
        case device::touchscreen: return out << "device::touchscreen";
        case device::pen        : return out << "device::pen";
        case device::touchpad   : return out << "device::touchpad";
        default                 : return out << "<Invalid value> -  Perhaps static_cast?";
    }
}

/**
 * Information about what triggered an event.
 * Note that the same device on the same computer booting on two different operating systems may NOT trigger event::send with the same contents,
 * based on how the system handles the device, and on Fubuki support.
 */
struct cause
{
    origin provenance = origin::unknown; ///< The origin of the event.
    device from       = device::unknown; ///< The from that triggered the event.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const cause& t)
    {
        return out << "event::cause:{ provenance: " << t.provenance << ", from: " << t.from << ",}";
    }

    friend constexpr bool operator==(const cause&, const cause&) noexcept  = default;
    friend constexpr bool operator!=(const cause&, const cause&) noexcept  = default;
    friend constexpr auto operator<=>(const cause&, const cause&) noexcept = default;

    constexpr void swap(cause& other) noexcept
    {
        std::swap(provenance, other.provenance);
        std::swap(from, other.from);
    }

    constexpr friend void swap(cause& a, cause& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::event

#endif // FUBUKI_IO_PLATFORM_EVENT_SOURCE_HPP
