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

#ifndef FUBUKI_IO_PLATFORM_WIN32_WINDOW_HPP
#define FUBUKI_IO_PLATFORM_WIN32_WINDOW_HPP

#include <string>
#include <utility>

#include <core/surface_data.hpp>

#include "io/platform/current_platform.hpp"
#include "io/platform/error.hpp"
#include "io/platform/event/dispatcher.hpp"
#include "io/platform/event/queue.hpp"
#include "io/platform/views/display.hpp"
#include "io/platform/win32/window_data.hpp"
#include "io/platform/window_info.hpp"

namespace fubuki::io::platform::win32
{

class window
{
    struct token
    {
    };

public:

    struct internal_atoms
    {
        unsigned short class_id = {}; // NOLINT(google-runtime-int): meant to match <windows.h>

        [[nodiscard]] friend constexpr bool operator==(const internal_atoms& a, const internal_atoms& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const internal_atoms& a, const internal_atoms& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const internal_atoms& a, const internal_atoms& b) noexcept = default;

        constexpr void swap(internal_atoms& other) noexcept { std::swap(class_id, other.class_id); }

        constexpr friend void swap(internal_atoms& a, internal_atoms& b) noexcept { a.swap(b); }
    };

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    window(platform::views::display, window_info info) : window(token{}, std::move(info))
    {
        if(const auto error = create())
        {
            throw call_exception{*error};
        }
    }

    [[nodiscard]] static std::expected<window, error::api_call> make(platform::views::display, window_info info) noexcept
    {
        window result(token{}, std::move(info));

        if(const auto error = result.create())
        {
            return std::unexpected{*error};
        }

        return result;
    }

    FUBUKI_IO_PLATFORM_API
    ~window() noexcept;

    window(window&& other) noexcept { swap(other); }
    window& operator=(window&& other) noexcept
    {
        swap(other);
        return *this;
    }

    window(const window&)            = delete;
    window& operator=(const window&) = delete;

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    [[nodiscard]] surface_handle handle() const noexcept { return {m_data.hwnd}; }

    /// Returns the information required to construct a surface from the window.
    /// The caller is responsible for not messing with platform (OS)-specific mechanics such as destroying the underlying resources owned by Fubuki.
    [[nodiscard]] fubuki::surface_data data() const noexcept { return {platform_data()}; }

    /// Returns the information required to construct a surface from the window.
    /// The caller is responsible for not messing with platform (OS)-specific mechanics such as destroying the underlying resources owned by Fubuki.
    [[nodiscard]] platform::current::platform_data platform_data() const noexcept
    {
        return {
            .hinstance = m_data.hinstance,
            .hwnd      = m_data.hwnd,
        };
    }

    /// Returns the information required to construct a surface from the window.
    /// The caller is responsible for not messing with platform (OS)-specific mechanics such as destroying the underlying resources owned by Fubuki.
    [[nodiscard]] operator fubuki::surface_data() const noexcept { return data(); }

    //------------------------------------------------------------------------------

    [[nodiscard]] const auto& info() const noexcept { return m_info; }
    [[nodiscard]] const auto& atoms() const noexcept { return m_atoms; }
    [[nodiscard]] const auto& state() const noexcept { return m_state; }

    //------------------------------------------------------------------------------

    /// Returns the event dispatcher associated to this window. Event handlers can be added and inspected through this object.
    [[nodiscard]] FUBUKI_SEMI_PURE event::dispatcher& event_dispatcher() noexcept { return m_event_dispatcher; }

    /// Returns the event dispatcher associated to this window. Event handlers can be inspected through this object.
    [[nodiscard]] FUBUKI_SEMI_PURE const event::dispatcher& event_dispatcher() const noexcept { return m_event_dispatcher; }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    [[nodiscard]] platform::views::display parent() const noexcept { return {platform::views::display::win32{}}; }

    FUBUKI_IO_PLATFORM_API
    void swap(window& other) noexcept;

    friend void swap(window& a, window& b) noexcept { a.swap(b); }

    /********************************************************************************/
    /*                          PUBLIC MEMBER FUNCTIONS                             */
    /********************************************************************************/

    /// Shows the window.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> show() noexcept;

    /// Hides the window.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> hide() noexcept;

    /// Closes the window.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> close() noexcept;

    /// Enables or disables window.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> enable(bool) noexcept;

    /// Sets window opacity.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> set_opacity(float) noexcept;

    /// Moves the window to a position.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> move(position2d) noexcept;

    /// Resizes the window.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> resize(dimension2d) noexcept;

    /// Renames the window.
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::expected<void, platform::error::any> rename(std::string);

private:

    window(token, window_info info) noexcept : m_info{std::move(info)} {}

    friend std::optional<int> process_next_user_event(event::queue&) noexcept; // Required for custom event queues

    friend bool process(window& win, auto&&...) noexcept;

    FUBUKI_IO_PLATFORM_API
    void user_event(const event::any& e) noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    window_data       m_data             = {}; ///< Platform-specific window data.
    window_info       m_info             = {}; ///< Window information.
    window_state      m_state            = {}; ///< Window state.
    event::dispatcher m_event_dispatcher = {}; ///< Dispatcher for events.
    internal_atoms    m_atoms            = {};
};

} // namespace fubuki::io::platform::win32

#endif // FUBUKI_IO_PLATFORM_WIN32_WINDOW_HPP
