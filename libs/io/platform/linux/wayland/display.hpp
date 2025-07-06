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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_HPP

#include <expected>

#include "io/platform/display_info.hpp"
#include "io/platform/error.hpp"
#include "io/platform/linux/wayland/display_global.hpp"
#include "io/platform/views/display.hpp"

extern "C"
{

struct wl_display;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland
{

/**
 * A RAII object representing a connection to a Wayland display.
 */
class display
{
    struct token
    {
    };

public:

    using information = information::display;
    using view        = display_view;
    using global      = display_global;

    /**
     * Constructor.
     * @param i Information about the connection.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    display(information i) : m_info{i}
    {
        if(const auto error = create())
        {
            throw call_exception{*error};
        }
    }

    /**
     * Constructor. Connects to the default display.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    display() : display{information{}} {}

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
     * @returns The object, or an instance of platform::error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<display, error::api_call> make(information i) noexcept
    {
        display result{token{}, i};

        if(const auto error = result.create())
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /**
     * Equivalent of a noexcept constructor. Connects to the default display.
     * @returns The object, or an instance of platform::error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<display, error::api_call> make() noexcept { return make({}); }

    /**
     * Destructor. Destroys the underlying handle if it is not nullptr.
     */
    FUBUKI_IO_PLATFORM_API
    ~display() noexcept;

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Obtains a view of this object.
    [[nodiscard]] operator view() const noexcept { return view{view::wayland{.handle = m_handle}}; }

    [[nodiscard]] operator view::wayland() const noexcept { return {m_handle}; }

    /// Returns all information known about this object.
    [[nodiscard]] FUBUKI_SEMI_PURE const information& info() const noexcept { return m_info; }

    /// Swaps two objects.
    void swap(display& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        m_info.swap(other.m_info);
    }

    /// Swaps two objects.
    friend void swap(display& a, display& b) noexcept { a.swap(b); }

private:
    display(token, information i) noexcept : m_info{i} {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create() noexcept;

    wl_display* m_handle = nullptr;
    information m_info   = {};
};

/**
 * Retrieve cached or acquire the globals of a display.
 * @param dp Wayland display.
 * @pre dp.value != nullptr.
 * @returns A const reference to the globals, or an instance of error::api_call describing the call that failed.
 */
[[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<std::reference_wrapper<const display::global>, error::api_call>
                                     globals_of(views::display::wayland dp) noexcept;

/**
 * Retrieve cached display globals. The globals are not acquired, even if they are unknown to Fubuki.
 * @param dp Wayland display.
 * @pre dp.value != nullptr.
 * @returns A const reference to the globals, or std::nullopt if the display is unknown to Fubuki.
 */
[[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<std::reference_wrapper<const display::global>>
                                     peek_at_globals_of(views::display::wayland dp) noexcept;

/**
 * Retrieve cached or acquire the globals of a display.
 * @param dp Wayland display.
 * @pre dp.value != nullptr.
 * @returns A const reference to the globals.
 * @throws fubuki::io::platform::call_exception This function throws an instance of fubuki::io::platform::call_exception if a call failed.
 */
[[nodiscard]] inline auto globals_of(fubuki::detail::validate_by::throw_call_exception, views::display::wayland dp)
{
    auto r = globals_of(dp);

    if(not r)
    {
        throw call_exception{r.error().value};
    }

    return *r;
}

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_HPP
