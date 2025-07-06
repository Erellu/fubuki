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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_BASE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_BASE_HPP

#include <expected>
#include <optional>

#include <core/config/macros.hpp>

#include "io/platform/error.hpp"
#include "io/platform/linux/wayland/display/global_handles.hpp"
#include "io/platform/views/display.hpp"

extern "C"
{

struct xdg_wm_base;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland::xdg
{

/**
 * Inteface for xdg_wm_base objects.
 * This object does **not** free the underlying handle, that is global to the display.
 * @see https://wayland.app/protocols/xdg-shell
 */
class wm_base
{
    struct token
    {
    };

public:

    /**
     * Constructor.
     * @param parent Parent display.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    wm_base(platform::views::display::wayland parent) : wm_base{token{}}
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    wm_base(const wm_base&)            = delete;
    wm_base& operator=(const wm_base&) = delete;

    /// Move constructor.
    wm_base(wm_base&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)}, m_globals{other.m_globals} {}

    /// Move assignment operator.
    wm_base& operator=(wm_base&& other) noexcept
    {
        swap(other);
        return *this;
    }

    // Does NOT call xdg_wm_base_destroy, the handle is *global* and destroying it invalidates all xdg_surfaces linked to it.
    // This object exists to answer ping-pong events.
    ~wm_base() noexcept = default;

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent display.
     * @returns The resulting object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<wm_base, error::api_call> make(platform::views::display::wayland parent) noexcept
    {
        auto result = wm_base{token{}};

        if(const auto error = result.create(parent))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /// Returns the underlying Wayland XDG handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland XDG handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Returns the list of globals retrieved from the parent display.
    [[nodiscard]] const auto& globals() const noexcept { return m_globals; }

    /// Swaps two objects.
    void swap(wm_base& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        m_globals.swap(other.m_globals);
    }

    /// Swaps two objects.
    friend void swap(wm_base& a, wm_base& b) noexcept { a.swap(b); }

private:

    wm_base(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(platform::views::display::wayland parent) noexcept;

    xdg_wm_base*                 m_handle  = nullptr;
    display_parts::global_handle m_globals = {};
};

} // namespace fubuki::io::platform::linux_bsd::wayland::xdg

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_BASE_HPP
