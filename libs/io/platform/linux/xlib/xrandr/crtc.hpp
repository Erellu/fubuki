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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_CRTC_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_CRTC_HPP

#include "io/platform/linux/xlib/error.hpp"
#include "io/platform/linux/xlib/xrandr/output.hpp"

#include <X11/extensions/Xrandr.h>

namespace fubuki::io::platform::linux_bsd::xlib::xrandr
{

class crtc
{
    struct token
    {
    };

public:

    crtc(output& parent, std::size_t idx) : crtc{token{}, parent, idx}
    {
        if(m_handle == nullptr)
        {
            throw call_exception{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetCrtcInfo"}
            };
        }
    }

    [[nodiscard]] static std::expected<crtc, error::api_call> make(output& parent, std::size_t idx) noexcept
    {
        crtc result{token{}, parent, idx};

        if(result.m_handle == nullptr)
        {
            return std::unexpected{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetCrtcInfo"}
            };
        }

        return result;
    }

    crtc(const crtc&) = delete;
    crtc(crtc&& other) noexcept { swap(other); }
    crtc& operator=(const crtc&) = delete;
    crtc& operator=(crtc&& other) noexcept
    {
        swap(other);
        return *this;
    }

    ~crtc() noexcept
    {
        if(m_handle)
        {
            XRRFreeCrtcInfo(m_handle);
        }
    }

    [[nodiscard]] const auto* data() const noexcept { return m_handle; }
    [[nodiscard]] auto*       data() noexcept { return m_handle; }
    [[nodiscard]] auto*       operator->() noexcept { return m_handle; }
    [[nodiscard]] const auto* operator->() const noexcept { return m_handle; }

    constexpr void        swap(crtc& other) noexcept { std::swap(m_handle, other.m_handle); }
    constexpr friend void swap(crtc& a, crtc& b) noexcept { a.swap(b); }

private:

    crtc(token, output& parent, std::size_t idx) noexcept
    {
        fubuki_assert(parent.parent().parent(), "Invalid parent: underlying display handle is nullptr.");
        fubuki_assert(idx < static_cast<std::size_t>(parent.handle()->ncrtc), "Invalid index (" << idx << ", max: " << parent.handle()->ncrtc << ")");

// Unfortunately, this is the only way the C API allows to access the underlying buffer
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

        m_handle = XRRGetCrtcInfo(parent.parent().parent(), parent.parent().handle(), parent.handle()->crtcs[idx]);

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
    }

    XRRCrtcInfo* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::xlib::xrandr

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_CRTC_HPP
