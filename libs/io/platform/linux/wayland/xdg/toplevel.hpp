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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_TOPLEVEL_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_TOPLEVEL_HPP

#include <core/config/macros.hpp>

#include "io/platform/linux/wayland/xdg/surface.hpp"

extern "C"
{

struct xdg_toplevel;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland::xdg
{

/**
 * Representation of an `xdg_toplevel` and the `wl_surface` it refers to.
 * @see https://wayland.app/protocols/xdg-shell
 */
class toplevel
{
    struct token
    {
    };

public:

    /**
     * Constructor.
     * @param parent Parent surface.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    toplevel(surface& parent) : toplevel{token{}, parent.globals()}
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    toplevel(const toplevel&)            = delete;
    toplevel& operator=(const toplevel&) = delete;

    /// Move constructor.
    toplevel(toplevel&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)}, m_globals{other.m_globals} {}

    /// Move assignment operator.
    toplevel& operator=(toplevel&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Destructor. Destroys the underlying handle if it is not nullptr.
     */
    FUBUKI_IO_PLATFORM_API ~toplevel() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent surface.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<toplevel, error::api_call> make(surface& parent) noexcept
    {
        toplevel result{token{}, parent.globals()};

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

    /// Returns a reference to the globals retrieved by this object from the parent display registry.
    [[nodiscard]] const auto& globals() const noexcept { return m_globals; }

    /// Swaps two objects.
    void swap(toplevel& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        m_globals.swap(other.m_globals);
    }

    /// Swaps two objects.
    friend void swap(toplevel& a, toplevel& b) noexcept { a.swap(b); }

private:

    toplevel(token, display_parts::global_handle g) noexcept : m_globals{g} {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(surface& parent) noexcept;

    xdg_toplevel*                m_handle  = nullptr;
    display_parts::global_handle m_globals = {};
};

} // namespace fubuki::io::platform::linux_bsd::wayland::xdg

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_XDG_TOPLEVEL_HPP
