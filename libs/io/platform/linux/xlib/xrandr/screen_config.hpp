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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_SCREEN_CONFIG_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_SCREEN_CONFIG_HPP

#include <core/assertion.hpp>

#include "io/platform/linux/xlib/display.hpp"
#include "io/platform/linux/xlib/error.hpp"

#include <X11/extensions/Xrandr.h>

namespace fubuki::io::platform::linux_bsd::xlib::xrandr
{

class screen_config
{
    struct token
    {
    };

public:

    screen_config(Display* d) : screen_config{token{}, d}
    {
        if(m_handle == nullptr)
        {
            throw call_exception{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetScreenInfo"}
            };
        }
    }

    screen_config(display_view::xlib d) : screen_config{d.handle} {}

    [[nodiscard]] static std::expected<screen_config, error::api_call> make(Display* parent) noexcept
    {
        screen_config result{token{}, parent};

        if(result.m_handle == nullptr)
        {
            return std::unexpected{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetScreenInfo"}
            };
        }

        return result;
    }

    [[nodiscard]] static std::expected<screen_config, error::api_call> make(display_view::xlib parent) noexcept { return make(parent.handle); }

    screen_config(const screen_config&) = delete;
    screen_config(screen_config&& other) noexcept { swap(other); }
    screen_config& operator=(const screen_config&) = delete;
    screen_config& operator=(screen_config&& other) noexcept
    {
        swap(other);
        return *this;
    }

    ~screen_config() noexcept
    {
        if(m_handle)
        {
            XRRFreeScreenConfigInfo(m_handle);
        }
    }

    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }
    [[nodiscard]] auto*       handle() noexcept { return m_handle; }
    [[nodiscard]] auto*       operator->() noexcept { return m_handle; }
    [[nodiscard]] const auto* operator->() const noexcept { return m_handle; }

    constexpr void        swap(screen_config& other) noexcept { std::swap(m_handle, other.m_handle); }
    constexpr friend void swap(screen_config& a, screen_config& b) noexcept { a.swap(b); }

private:
    screen_config(token, Display* d) noexcept
    {
        fubuki_assert(d, "Invalid display: must not be nullptr.");
        m_handle = XRRGetScreenInfo(d, RootWindow(d, 0));
    }

    XRRScreenConfiguration* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::xlib::xrandr

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_SCREEN_CONFIG_HPP
