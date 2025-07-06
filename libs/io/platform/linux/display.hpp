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

#ifndef FUBUKI_IO_PLATFORM_LINUX_DISPLAY_HPP
#define FUBUKI_IO_PLATFORM_LINUX_DISPLAY_HPP

#include <variant>

#include <core/config/setup.hpp>

#include "io/platform/display_info.hpp"
#include "io/platform/error.hpp"
#include "io/platform/linux/wayland/display.hpp"
#include "io/platform/linux/wayland/error.hpp"
#include "io/platform/linux/xlib/display.hpp"
#include "io/platform/views/display.hpp"

namespace fubuki::io::platform::linux_bsd
{

/**
 * Common interface wrapping either an X11 (Xlib) display or a Wayland display.
 */
class display
{
    struct token
    {
    };

public:

    using information = information::display;
    using view        = views::display;

    display(information i) : m_value{make_value(i)} {}

    display(display&&) noexcept            = default;
    display& operator=(display&&) noexcept = default;

    display(const display&)            = delete;
    display& operator=(const display&) = delete;

    [[nodiscard]] static std::expected<display, error::api_call> make(information i) noexcept
    {
        const auto window_system = i.window_system.value_or(configuration::current_window_system());

        if(window_system == configuration::window_system::xlib)
        {
            auto impl = xlib::display::make(i);

            if(not impl)
            {
                return std::unexpected{impl.error()};
            }

            return display{token{}, *std::move(impl)};
        }

        if(window_system == configuration::window_system::wayland)
        {
            auto impl = wayland::display::make(i);

            if(not impl)
            {
                return std::unexpected{impl.error()};
            }

            return display{token{}, *std::move(impl)};
        }

        fubuki_assert(false,
                      "Invalid window system: expected either window_system::x11 or window_system::wayland, but got"
                          << window_system << "(" << std::to_underlying(window_system) << ")");

        return std::unexpected{any_call_info{wayland::call_info{.result = {}, .call_literal = "Invalid window system"}}};
    }

    [[nodiscard]] operator view() const noexcept
    {
        return std::visit([](const auto& var) noexcept -> view { return static_cast<view>(var); }, m_value);
    }

    [[nodiscard]] FUBUKI_SEMI_PURE const information& info() const noexcept
    {
        return std::visit([]<typename T>(const T& variant) noexcept -> const information& { return variant.info(); }, m_value);
    }

    [[nodiscard]] std::optional<std::reference_wrapper<xlib::display>> xlib() noexcept
    {
        if(auto* const xlib = std::get_if<xlib::display>(std::addressof(m_value)))
        {
            return std::ref(*xlib);
        }

        return {};
    }

    [[nodiscard]] std::optional<std::reference_wrapper<wayland::display>> wayland() noexcept
    {
        if(auto* const wayland = std::get_if<wayland::display>(std::addressof(m_value)))
        {
            return std::ref(*wayland);
        }

        return {};
    }

private:

    using value_type = std::variant<xlib::display, wayland::display>;

    display(token, xlib::display d) noexcept : m_value{std::in_place_type<xlib::display>, std::move(d)} {}
    display(token, wayland::display d) noexcept : m_value{std::in_place_type<wayland::display>, std::move(d)} {}

    [[nodiscard]]
    static value_type make_value(information i)
    {
        const auto window_system = i.window_system.value_or(configuration::current_window_system());

        if(window_system == configuration::window_system::xlib)
        {
            return value_type{std::in_place_type<xlib::display>, xlib::display({i})};
        }

        if(window_system == configuration::window_system::wayland)
        {
            return value_type{std::in_place_type<wayland::display>, wayland::display{i}};
        }

        fubuki_assert(false,
                      "Invalid window system: expected either window_system::x11 or window_system::wayland, but got"
                          << window_system << "(" << std::to_underlying(window_system) << ")");
        return {};
    }

    value_type m_value;
};

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_DISPLAY_HPP
