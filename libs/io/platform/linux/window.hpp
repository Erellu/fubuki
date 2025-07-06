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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WINDOW_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WINDOW_HPP

#include <variant>

#include "io/platform/current_platform.hpp"
#include "io/platform/error.hpp"
#include "io/platform/linux/wayland/window.hpp"
#include "io/platform/linux/xlib/window.hpp"
#include "io/platform/window_info.hpp"

namespace fubuki::io::platform::linux_bsd
{

/**
 * Common interface wrapping either an X11 (Xlib) window or a Wayland display.
 */
class window
{
    struct token
    {
    };

public:

    using information = window_info;

    /**
     * Constructor.
     * @param parent Parent display.
     * @param info Information about the window.
     * @throws platform::call_exception This constructor throws an instance of platform::call_exception if the creation failed.
     */
    window(platform::views::display parent, information info) : m_value{make_value(parent, std::move(info))} {}

    /**
     * Equivalent of a noexcept construction.
     * @param parent Parent display.
     * @param info Information about the window.
     * @returns The object, or an instance of `platform::error::api_call` describing the call that failed.
     */
    [[nodiscard]] static std::expected<window, error::api_call> make(platform::views::display parent, information info) noexcept
    {
        using dp = platform::views::display;
        if(const auto* xlib_display = std::get_if<dp::xlib>(std::addressof(parent.value)))
        {
            auto xlib_window = xlib::window::make(*xlib_display, std::move(info));

            if(not xlib_window)
            {
                return std::unexpected{xlib_window.error()};
            }

            return window{token{}, *std::move(xlib_window)};
        }

        if(const auto* const wayland_display = std::get_if<dp::wayland>(std::addressof(parent.value)))
        {
            auto wayland_window = wayland::window::make(*wayland_display, std::move(info));

            if(not wayland_window)
            {
                return std::unexpected{wayland_window.error()};
            }

            return window{token{}, *std::move(wayland_window)};
        }

        return std::unexpected{any_call_info{linux_call_info{.result = {}, .call_literal = "parent.wayland() or parent.xlib()"_literal}}};
    }

    /// Move constructor.
    window(window&& other) noexcept = default;

    /// Move assignment operator.
    window& operator=(window&& other) noexcept = default;

    window(const window&)            = delete;
    window& operator=(const window&) = delete;

    [[nodiscard]] const information& info() const noexcept
    {
        return std::visit([]<typename T>(const T& variant) noexcept -> const information& { return variant.info(); }, m_value);
    }

    [[nodiscard]] const window_state& state() const noexcept
    {
        return std::visit([]<typename T>(const T& variant) noexcept -> const window_state& { return variant.state(); }, m_value);
    }

    [[nodiscard]] platform::current::surface_handle handle() const noexcept
    {
        return std::visit([]<typename T>(const T& variant) noexcept -> platform::current::surface_handle { return {variant.handle()}; }, m_value);
    }

    [[nodiscard]] platform::current::platform_data platform_data() const noexcept
    {
        return std::visit([]<typename T>(const T& variant) noexcept -> platform::current::platform_data { return variant.platform_data(); }, m_value);
    }

    [[nodiscard]] surface_data data() const noexcept
    {
        return std::visit([]<typename T>(const T& variant) noexcept -> surface_data { return variant.data(); }, m_value);
    }

    /// Returns the event dispatcher associated to this window. Event handlers can be added and inspected through this object.
    [[nodiscard]] event::dispatcher& event_dispatcher() noexcept
    {
        return std::visit([]<typename T>(T& variant) noexcept -> event::dispatcher& { return variant.event_dispatcher(); }, m_value);
    }

    /// Returns the event dispatcher associated to this window. Event handlers can be inspected through this object.
    [[nodiscard]] const event::dispatcher& event_dispatcher() const noexcept
    {
        return std::visit([]<typename T>(T& variant) noexcept -> const event::dispatcher& { return variant.event_dispatcher(); }, m_value);
    }

    /// Returns a view of the parent display.
    [[nodiscard]] platform::views::display parent() const noexcept
    {
        return std::visit([]<typename T>(T& variant) noexcept -> platform::views::display { return variant.parent(); }, m_value);
    }

    /// Shows the window.
    std::expected<void, platform::error::any> show() noexcept
    {
        return std::visit([]<typename T>(T& variant) noexcept { return variant.show(); }, m_value);
    }

    /// Hides the window.
    std::expected<void, platform::error::any> hide() noexcept
    {
        return std::visit([]<typename T>(T& variant) noexcept { return variant.hide(); }, m_value);
    }

    /// Closes the window.
    std::expected<void, platform::error::any> close() noexcept
    {
        return std::visit([]<typename T>(T& variant) noexcept { return variant.close(); }, m_value);
    }

    /// Enables or disables the window.
    std::expected<void, platform::error::any> enable(bool b) noexcept
    {
        return std::visit([b]<typename T>(T& variant) noexcept { return variant.enable(b); }, m_value);
    }

    /// Sets window opacity.
    std::expected<void, platform::error::any> set_opacity(float o) noexcept
    {
        return std::visit([o]<typename T>(T& variant) noexcept { return variant.set_opacity(o); }, m_value);
    }

    /// Moves the window to a position.
    std::expected<void, platform::error::any> move(position2d p) noexcept
    {
        return std::visit([p]<typename T>(T& variant) noexcept { return variant.move(p); }, m_value);
    }

    /// Resizes the window.
    std::expected<void, platform::error::any> resize(dimension2d d) noexcept
    {
        return std::visit([d]<typename T>(T& variant) noexcept { return variant.resize(d); }, m_value);
    }

    /// Renames the window.
    std::expected<void, platform::error::any> rename(std::string s)
    {
        return std::visit([x = std::move(s)]<typename T>(T& variant) { return variant.rename(std::move(x)); }, m_value);
    }

    [[nodiscard]] std::optional<xlib::window_ref> xlib() noexcept
    {
        if(auto* const xlib = std::get_if<xlib::window>(std::addressof(m_value)))
        {
            return std::ref(*xlib);
        }

        return {};
    }

    [[nodiscard]] std::optional<xlib::window_cref> xlib() const noexcept
    {
        if(auto* const xlib = std::get_if<xlib::window>(std::addressof(m_value)))
        {
            return std::ref(*xlib);
        }

        return {};
    }

    [[nodiscard]] std::optional<wayland::window_ref> wayland() noexcept
    {
        if(auto* const wayland = std::get_if<wayland::window>(std::addressof(m_value)))
        {
            return std::ref(*wayland);
        }

        return {};
    }

    [[nodiscard]] std::optional<wayland::window_cref> wayland() const noexcept
    {
        if(auto* const wayland = std::get_if<wayland::window>(std::addressof(m_value)))
        {
            return std::ref(*wayland);
        }

        return {};
    }

private:

private:

    using value_type = std::variant<xlib::window, wayland::window>;

    window(token, xlib::window d) noexcept : m_value{std::in_place_type<xlib::window>, std::move(d)} {}
    window(token, wayland::window d) noexcept : m_value{std::in_place_type<wayland::window>, std::move(d)} {}

    [[nodiscard]]
    static value_type make_value(platform::views::display parent, information i)
    {
        using dp = platform::views::display;
        if(const auto* const xlib_display = std::get_if<dp::xlib>(std::addressof(parent.value)))
        {
            return value_type{
                std::in_place_type<xlib::window>, xlib::window{*xlib_display, std::move(i)}
            };
        }

        if(const auto* const wayland_display = std::get_if<dp::wayland>(std::addressof(parent.value)))
        {
            return value_type{
                std::in_place_type<wayland::window>, wayland::window{*wayland_display, std::move(i)}
            };
        }

        throw call_exception{
            linux_call_info{.result = {}, .call_literal = "parent.wayland() or parent.xlib()"_literal}
        };
    }

    value_type m_value;
};

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_WINDOW_HPP
