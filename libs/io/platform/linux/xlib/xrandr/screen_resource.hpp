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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_SCREEN_RESOURCE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_SCREEN_RESOURCE_HPP

#include <ranges>
#include <utility>

#include <core/assertion.hpp>

#include "io/platform/error.hpp"
#include "io/platform/linux/xlib/display.hpp"
#include "io/platform/linux/xlib/error.hpp"

#include <X11/extensions/Xrandr.h>

namespace fubuki::io::platform::linux_bsd::xlib::xrandr
{

class screen_resource
{
    struct token
    {
    };

public:

    screen_resource(Display* d) : screen_resource{token{}, d}
    {
        if(m_handle == nullptr)
        {
            throw call_exception{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetScreenResources"}
            };
        }
    }

    screen_resource(display_view::xlib d) : screen_resource{d.handle} {}

    [[nodiscard]] static std::expected<screen_resource, error::api_call> make(Display* d) noexcept
    {
        screen_resource result{token{}, d};

        if(result.m_handle == nullptr)
        {
            return std::unexpected{
                call_info{.result = {code::unknown}, .call_literal = "XRRGetScreenResources"}
            };
        }

        return result;
    }

    [[nodiscard]] static std::expected<screen_resource, error::api_call> make(display_view::xlib d) noexcept { return make(d.handle); }

    screen_resource(const screen_resource&) = delete;
    screen_resource(screen_resource&& other) noexcept { swap(other); }
    screen_resource& operator=(const screen_resource&) = delete;
    screen_resource& operator=(screen_resource&& other) noexcept
    {
        swap(other);
        return *this;
    }

    ~screen_resource() noexcept
    {
        if(m_handle)
        {
            XRRFreeScreenResources(m_handle);
        }
    }

    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }
    [[nodiscard]] auto*       handle() noexcept { return m_handle; }
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

    [[nodiscard]] auto*       parent() noexcept { return m_parent; }
    [[nodiscard]] const auto* parent() const noexcept { return m_parent; }

    constexpr void swap(screen_resource& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
    }

    constexpr friend void swap(screen_resource& a, screen_resource& b) noexcept { a.swap(b); }

private:

    screen_resource(token, Display* d) noexcept : m_parent{d}
    {
        fubuki_assert(m_parent, "Invalid display: must not be nullptr.");
// This is the expected usage of the API
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
        m_handle = XRRGetScreenResources(d, DefaultRootWindow(d));
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
    }

    Display*            m_parent = nullptr;
    XRRScreenResources* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::xlib::xrandr

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_XRANDR_SCREEN_RESOURCE_HPP
