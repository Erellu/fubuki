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

#ifndef FUBUKI_IO_PLATFORM_WINDOW_INFO_HPP
#define FUBUKI_IO_PLATFORM_WINDOW_INFO_HPP

#include <ostream>
#include <string>

#include <core/dim.hpp>
#include <core/pos.hpp>

namespace fubuki::io::platform
{

/// Window styles supported
enum class window_style
{
    os_default,
    windowed,
    borderless,
    // TODO: fullscreen
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, window_style s)
{
    switch(s)
    {
        case window_style::os_default: out << "style: os_default"; break;
        case window_style::windowed  : out << "style: windowed"; break;
        case window_style::borderless: out << "style: borderless"; break;
        default                      : out << "<Invalid style. Perhaps static_cast?>"; break;
    }

    return out;
}

//------------------------------------------------------------------------------

/// Information required to create a window.
struct window_info
{
    static constexpr std::int32_t default_width  = 512;
    static constexpr std::int32_t default_height = 512;

    std::string  title       = "Fubuki window";                 ///< Window title.
    dimension2d  size        = {default_width, default_height}; ///< Size in pixels.
    position2d   coordinates = {0, 0};                          ///< Position on the screen in pixels.
    float        opacity     = 1.f;                             ///< Window opacity. Clamped in {0.f, 1.f}
    window_style style       = window_style::os_default;        ///< Window style.

    // TODO: icon

    [[nodiscard]] friend constexpr bool operator==(const window_info& a, const window_info& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const window_info& a, const window_info& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const window_info& a, const window_info& b) noexcept = default;

    void swap(window_info& other) noexcept
    {
        title.swap(other.title);
        size.swap(other.size);
        coordinates.swap(other.coordinates);
        std::swap(opacity, other.opacity);
        std::swap(style, other.style);
    }

    friend void swap(window_info& a, window_info& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const window_info& w)
    {
        return out << "window:{"
                   << "title: " << w.title << "\t"
                   << "size: " << w.size << "\t"
                   << "coordinates: " << w.coordinates << "\t"
                   << "opacity: " << w.opacity << "\t"
                   << "style: " << w.style << "\t"
                   << "}";
    }
};

//------------------------------------------------------------------------------

/// Generic information about a windows current state.
struct window_state
{
    bool visible   = false;
    bool closed    = false;
    bool activated = false;
    bool focused   = false;
    bool enabled   = true;
    // TODO: more

    void swap(window_state& other) noexcept
    {
        std::swap(visible, other.visible);
        std::swap(closed, other.closed);
        std::swap(activated, other.activated);
        std::swap(focused, other.focused);
        std::swap(enabled, other.enabled);
    }

    friend void swap(window_state& a, window_state& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const window_state s)
    {
        return out << "\"window_state\":{"
                   << "visible:" << s.visible << "\t"
                   << "closed: " << s.closed << "\t"
                   << "activated: " << s.activated << "\t"
                   << "focused: " << s.focused << "\t"
                   << "enabled: " << s.enabled << "\t"
                   << "}";
    }
};

} // namespace fubuki::io::platform

#endif // FUBUKI_IO_PLATFORM_WINDOW_INFO_HPP
