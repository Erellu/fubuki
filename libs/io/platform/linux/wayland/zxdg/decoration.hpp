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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_ZXDG_DECORATION_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_ZXDG_DECORATION_HPP

#include <optional>
#include <utility>

#include <core/config/macros.hpp>

#include "io/platform/linux/wayland/xdg/toplevel.hpp"

extern "C"
{

struct zxdg_toplevel_decoration_v1;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland::zxdg
{

/**
 * Representation of a `zxdg_toplevel_decoration_v1`, that is, and object that adds server-side decorations to a window.
 * @see https://wayland.app/protocols/xdg-decoration-unstable-v1
 */
class decoration
{
    struct token
    {
    };

public:

    /**
     * Constructor.
     * @param parent Parent xdg::toplevel.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    decoration(xdg::toplevel& parent)
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    decoration(const decoration&)            = delete;
    decoration& operator=(const decoration&) = delete;

    /// Move constructor.
    decoration(decoration&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)} {}

    /// Move assignment operator.
    decoration& operator=(decoration&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent xdg::toplevel.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<decoration, error::api_call> make(xdg::toplevel& parent) noexcept
    {
        auto result = decoration{token{}};

        if(const auto error = result.create(parent))
        {
            return std::unexpected{error::api_call{}};
        }

        return result;
    }

    /**
     * Destructor. Destroys the underlying handle if it is not nullptr.
     */
    FUBUKI_IO_PLATFORM_API
    ~decoration() noexcept;

    /// Returns the underlying Wayland ZXDG handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland ZXDG handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Swaps two objects.
    void swap(decoration& other) noexcept { std::swap(m_handle, other.m_handle); }

    /// Swaps two objects.
    friend void swap(decoration& a, decoration& b) noexcept { a.swap(b); }

private:

    decoration(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(xdg::toplevel& parent) noexcept;

    zxdg_toplevel_decoration_v1* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::wayland::zxdg

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_ZXDG_DECORATION_HPP
