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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XLIB_DISPLAY_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XLIB_DISPLAY_HPP

#include <expected>

#include <core/config/macros.hpp>
#include <core/detail/platform_forward.hpp>

#include "io/platform/display_info.hpp"
#include "io/platform/error.hpp"
#include "io/platform/views/display.hpp"

// NOLINTBEGIN
// Extracted from <X11/Xdefs.h>
extern "C"
{

using Atom = unsigned long;

} // extern "C"
// NOLINTEND

namespace fubuki::io::platform::linux_bsd::xlib
{

class display
{
    struct token
    {
    };

public:

    using information = information::display;
    using view        = display_view;

    struct internal_atoms
    {
        Atom wm_protocols      = {};
        Atom wm_delete_message = {};
        Atom wm_window_opacity = {};

        [[nodiscard]] friend constexpr bool operator==(const internal_atoms& a, const internal_atoms& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const internal_atoms& a, const internal_atoms& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const internal_atoms& a, const internal_atoms& b) noexcept = default;

        constexpr void swap(internal_atoms& other) noexcept
        {
            std::swap(wm_protocols, other.wm_protocols);
            std::swap(wm_delete_message, other.wm_delete_message);
            std::swap(wm_window_opacity, other.wm_window_opacity);
        }

        constexpr friend void swap(internal_atoms& a, internal_atoms& b) noexcept { a.swap(b); }
    };

    /**
     * Constructor.
     * @param i Information about the connection.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    FUBUKI_IO_PLATFORM_API
    display(information i);

    /**
     * Constructor.  Connects to the default display.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    display() : display{{}} {}

    display(const display&)            = delete;
    display& operator=(const display&) = delete;

    /// Move constructor.
    display(display&& other) noexcept { swap(other); }

    /// Move assignment operator.
    display& operator=(display&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param i Information about the connection.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] FUBUKI_IO_PLATFORM_API static std::expected<display, error::api_call> make(information i) noexcept;

    /**
     * Equivalent of a noexcept constructor. Connects to the default display.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<display, error::api_call> make() noexcept { return make({}); }

    /**
     * Destructor. Destroys the underlying handle if it is not nullptr.
     */
    FUBUKI_IO_PLATFORM_API
    ~display() noexcept;

    /// Returns the underlying Xlib handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Xlib handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Obtains a view of this object.
    [[nodiscard]] operator view() const noexcept { return view{view::xlib{.handle = m_handle}}; }

    /// Returns all information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    /// Returns the display atoms.
    [[nodiscard]] const auto& atoms() const noexcept { return m_atoms; }

    /// Swaps two objects.
    void swap(display& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        m_info.swap(other.m_info);
        m_atoms.swap(other.m_atoms);
    }

    /// Swaps two objects.
    friend void swap(display& a, display& b) noexcept { a.swap(b); }

private:
    display(token, information i) noexcept : m_info{i} {}

    Display*       m_handle = nullptr;
    information    m_info   = {};
    internal_atoms m_atoms  = {};
};

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<display::internal_atoms, error::api_call> atoms_of(Display* dp) noexcept;

[[nodiscard]] inline auto atoms_of(views::display::xlib dp) noexcept { return atoms_of(dp.handle); }

} // namespace fubuki::io::platform::linux_bsd::xlib

#endif // FUBUKI_IO_PLATFORM_LINUX_XLIB_DISPLAY_HPP
