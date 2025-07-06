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
#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_SURFACE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_SURFACE_HPP

#include <optional>
#include <utility>

#include <core/config/setup.hpp>

#include "io/platform/linux/wayland/xdg/wm_base.hpp"

extern "C"
{

struct xdg_surface;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland::xdg
{

/**
 * Representation of an `xdg_surface`.
 * @see https://wayland.app/protocols/xdg-shell
 */
class surface
{
    struct token
    {
    };

public:

    /**
     * Constructor.
     * @param base Parent wm_base.
     * @param surf The surface the XDG handles uses.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    surface(wm_base& base, wl_surface* surf) : surface{token{}, base.globals()}
    {
        if(const auto error = create(base.handle(), surf))
        {
            throw call_exception{*error};
        }
    }

    surface(const surface&)            = delete;
    surface& operator=(const surface&) = delete;

    /// Move constructor.
    surface(surface&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)}, m_globals{other.m_globals} {}

    /// Move assignment operator.
    surface& operator=(surface&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Destructor. Destroys the underlying handles if they are not nullptr.
     */
    FUBUKI_IO_PLATFORM_API
    ~surface() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param base Parent wm_base.
     * @param surf The surface the XDG handles uses.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<surface, error::api_call> make(wm_base& base, wl_surface* surf) noexcept
    {
        surface result{token{}, base.globals()};

        if(const auto error = result.create(base.handle(), surf))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /// Returns the underlying Wayland XDG m_handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland XDG m_handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Returns a reference to the globals retrieved by this object from the parent display registry.
    [[nodiscard]] const auto& globals() const noexcept { return m_globals; }

    /// Swaps two objects.
    void swap(surface& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        m_globals.swap(other.m_globals);
    }

    /// Swaps two objects.
    friend void swap(surface& a, surface& b) noexcept { a.swap(b); }

private:

    surface(token, display_parts::global_handle g) noexcept : m_globals{g} {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(xdg_wm_base* base, wl_surface* surf) noexcept;

    xdg_surface*                 m_handle  = {};
    display_parts::global_handle m_globals = {};
};

} // namespace fubuki::io::platform::linux_bsd::wayland::xdg

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_SURFACE_HPP
