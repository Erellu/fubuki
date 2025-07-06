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

#ifndef FUBUKI_IO_DISPLAY_HPP
#define FUBUKI_IO_DISPLAY_HPP

#include <memory>

#include <core/config/setup.hpp>
#include <io/platform/current_platform.hpp>
#include <io/platform/error.hpp>
#include <io/platform/views/display.hpp>

#include "io/information/display.hpp"

namespace fubuki::io
{

/**
 * An object representing a connection to a display server.
 * On Linux, this is an indirection to Wayland/Xlib/... (XOpenDisplay, wl_display_connect, ...).
 * On Windows, this is an articifial indirection to nothing, used to make the API match between platforms.
 */
class display
{
    struct token
    {
    };

public:

    using information = io::information::display;
    using view        = platform::views::display;

    /**
     * Constructor.
     * @param info  Information about the display connection.
     * @throws platform::call_exception This constructor throws an instance of platform::call_exception if the creation failed.
     * @note On Windows, this constructor is equivalent to the default constructor, regardless of the parameters.
     */
    FUBUKI_IO_API explicit display(information info);

    /**
     * Constructor. Uses the default platform display.
     * @throws platform::call_exception This constructor throws an instance of platform::call_exception if the creation failed.
     */
    display()
        : display{
              information{
                          .display_name  = {nullptr},
                          .window_system = configuration::current_window_system(),
                          }
    }
    {
    }

    /**
     * Equivalent of a noexcept constructor.
     *  @param info (optional) Information about the display connection. If not specified, uses the default display.
     * @returns The display, or an instance of platform::error::api_call describing the call that failed.
     * @note On Windows, this function is equivalent to its overload without arguments, regardless of the parameters.
     */
    [[nodiscard]] FUBUKI_IO_API static std::expected<display, platform::error::api_call> make(information info) noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @returns The display, or an instance of platform::error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<display, platform::error::api_call> make() noexcept
    {
        return make(information{
            .display_name  = {nullptr},
            .window_system = configuration::current_window_system(),
        });
    }

    display(const display&)            = delete;
    display& operator=(const display&) = delete;

    FUBUKI_IO_API
    ~display() noexcept;

    /// Move constructor.
    FUBUKI_IO_API display(display&& other) noexcept;

    /// Move assignment operator.
    FUBUKI_IO_API display& operator=(display&& other) noexcept;

    /// Returns a view of this display.
    [[nodiscard]] FUBUKI_TRUE_PURE FUBUKI_IO_API operator view() const noexcept;

    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API const information& info() const noexcept;

    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API platform::current::display& underlying() noexcept;

    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API const platform::current::display& underlying() const noexcept;

    /// Swaps two objects.
    FUBUKI_IO_API
    void swap(display& other) noexcept;

    /// Swaps two objects.
    friend void swap(display& a, display& b) noexcept { a.swap(b); }

private:

    FUBUKI_IO_API
    display(token) noexcept;

    struct implementation;

    std::unique_ptr<implementation> m_implementation;
};

} // namespace fubuki::io

#endif // DISPLAY_HPP
