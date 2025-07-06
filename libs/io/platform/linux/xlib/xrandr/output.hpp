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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_OUTPUT_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_OUTPUT_HPP

#include "io/platform/linux/xlib/error.hpp"
#include "io/platform/linux/xlib/xrandr/screen_resource.hpp"

#include <X11/extensions/Xrandr.h>

namespace fubuki::io::platform::linux_bsd::xlib::xrandr
{

class output
{
    struct token
    {
    };

public:

    output(screen_resource& parent, std::size_t idx) : output{token{}, parent, idx}
    {
        if(m_handle == nullptr)
        {
            throw call_exception{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetOutputInfo"}
            };
        }
    }

    [[nodiscard]] static std::expected<output, error::api_call> make(screen_resource& parent, std::size_t idx) noexcept
    {
        output result{token{}, parent, idx};

        if(result.m_handle == nullptr)
        {
            return std::unexpected{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetOutputInfo"}
            };
        }

        return result;
    }

    output(const output&) = delete;
    output(output&& other) noexcept : m_parent{other.m_parent} { std::swap(m_handle, other.m_handle); }

    output& operator=(const output&) = delete;
    output& operator=(output&& other) noexcept
    {
        swap(other);
        return *this;
    }

    ~output() noexcept
    {
        if(m_handle)
        {
            XRRFreeOutputInfo(m_handle);
        }
    }

    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }
    [[nodiscard]] auto*       handle() noexcept { return m_handle; }
    [[nodiscard]] auto&       parent() noexcept { return m_parent.get(); }
    [[nodiscard]] const auto& parent() const noexcept { return m_parent.get(); }
    [[nodiscard]] auto*       operator->() noexcept { return m_handle; }
    [[nodiscard]] const auto* operator->() const noexcept { return m_handle; }

    [[nodiscard]] auto modes() const noexcept
    {
        fubuki_assert(m_handle, "Internal error: should not be nullptr.");
// This is the expected usage of the API
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
        return std::ranges::subrange{m_handle->modes, m_handle->modes + static_cast<std::size_t>(m_handle->nmode)};
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
    }

    constexpr void swap(output& other) noexcept
    {
        std::swap(m_parent, other.m_parent);
        std::swap(m_handle, other.m_handle);
    }

    constexpr friend void swap(output& a, output& b) noexcept { a.swap(b); }

private:

    output(token, screen_resource& parent, std::size_t idx) noexcept : m_parent{parent}
    {
        fubuki_assert(parent.parent(), "Invalid parent: underlying handle is nullptr.");
        fubuki_assert(idx < static_cast<std::size_t>(parent.handle()->noutput),
                      "Invalid index (" << idx << ", max: " << parent.handle()->noutput << ")");
        fubuki_assert(parent.parent(), "Invalid parent: underlying handle is nullptr.");

// Unfortunately, this is the only way the C API allows to access the underlying buffer
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
        m_handle = XRRGetOutputInfo(parent.parent(), parent.handle(), parent->outputs[idx]);
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
    }

    std::reference_wrapper<screen_resource> m_parent;
    XRROutputInfo*                          m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::xlib::xrandr

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_OUTPUT_HPP
