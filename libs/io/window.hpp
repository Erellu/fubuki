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

#ifndef FUBUKI_IO_WINDOW_HPP
#define FUBUKI_IO_WINDOW_HPP

#include <expected>
#include <memory>

#include <core/config/macros.hpp>
#include <core/surface_data.hpp>
#include <io/platform/current_platform.hpp>
#include <io/platform/error.hpp>
#include <io/platform/views/display.hpp>

#include "io/event/dispatcher.hpp"
#include "io/information/window.hpp"

namespace fubuki::io
{

/**
 * A window displayed on the screen.
 */
class window
{
    struct token
    {
    };

public:

    using information = io::information::window;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param parent Parent display.
     * @param info Information about the window.
     * @throws platform::call_exception This constructor throws an instance of platform::call_exception if the creation failed.
     */
    FUBUKI_IO_API
    window(platform::views::display parent, information info);

    /**
     * Equivalent of a noexcept constructor.
     * @returns The window, or an instance of platform::any_call_info describing the call that failed.
     */
    [[nodiscard]] FUBUKI_IO_API static std::expected<window, platform::error::api_call> make(platform::views::display parent,
                                                                                             information              info) noexcept;

    FUBUKI_IO_API
    ~window() noexcept;

    /// Move constructor.
    FUBUKI_IO_API window(window&& other) noexcept;

    /// Move assignment operator.
    FUBUKI_IO_API window& operator=(window&& other) noexcept;

    window(const window&)            = delete;
    window& operator=(const window&) = delete;

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns the information known about this object.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API const information& info() const noexcept;

    /// Returns the current state of the window.
    /// @note If you directly manipulate platform-specific handles, this state may be out of sync.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API const window_state& state() const noexcept;

    /// Returns the platform-specific handle to the window surface.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API platform::current::surface_handle handle() const noexcept;

    /// Returns the information required to construct a surface from the window.
    /// The caller is responsible for not messing with platform (OS)-specific mechanics such as destroying the underlying resources owned by Fubuki.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API platform::current::platform_data platform_data() const noexcept;

    /// Returns the information required to construct a surface from the window.
    /// The caller is responsible for not messing with platform (OS)-specific mechanics such as destroying the underlying resources owned by Fubuki.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API surface_data data() const noexcept;

    /// Returns the information required to construct a surface from the window.
    /// The caller is responsible for not messing with platform (OS)-specific mechanics such as destroying the underlying resources owned by Fubuki.
    [[nodiscard]] FUBUKI_SEMI_PURE operator surface_data() const noexcept { return data(); }

    /// Returns the event dispatcher associated to this window. Event handlers can be added and inspected through this object.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API event::dispatcher& event_dispatcher() noexcept;

    /// Returns the event dispatcher associated to this window. Event handlers can be inspected through this object.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API const event::dispatcher& event_dispatcher() const noexcept;

    /// Returns an opaque pointer to underlying window.
    /// @note DO NOT ATTEMPT TO USE DIRECTLY unless you REALLY need to access platform-specific functionalities.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API const platform::current::window& underlying() const;

    /// Returns a view of the parent display.
    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_IO_API platform::views::display parent() const noexcept;

    /// Shows the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> show() noexcept;

    /// Hides the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> hide() noexcept;

    /// Closes the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> close() noexcept;

    /// Enables or disables the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> enable(bool) noexcept;

    /// Enables the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    std::expected<void, platform::error::any> enable() noexcept { return enable(true); }

    /// Disables the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    std::expected<void, platform::error::any> disable() noexcept { return enable(false); }

    /// Sets window opacity.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> set_opacity(float) noexcept;

    /// Moves the window to a position.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> move(position2d) noexcept;

    /// Resizes the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> resize(dimension2d) noexcept;

    /// Renames the window.
    /// @returns Nothing, or an instance of platform::error::any that indicates what went wrong. This value can be ignored if no handling is required
    /// or possible.
    FUBUKI_IO_API
    std::expected<void, platform::error::any> rename(std::string);

    /// Swaps two objects.
    FUBUKI_IO_API
    void swap(window& other) noexcept;

    /// Swaps two objects.
    friend void swap(window& a, window& b) noexcept { a.swap(b); }

private:

    FUBUKI_IO_API
    window(token) noexcept;

    struct implementation;

    std::unique_ptr<implementation> m_implementation; ///< Underlying platform-specific window.
};

} // namespace fubuki::io

#endif // FUBUKI_IO_WINDOW_HPP
