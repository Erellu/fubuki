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

#ifndef FUBUKI_IO_PLATFORM_SCREEN_PROPERTIES_HPP
#define FUBUKI_IO_PLATFORM_SCREEN_PROPERTIES_HPP

#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

#include <core/types.hpp>

namespace fubuki::io::platform
{

/// Information about a screen (monitor).
struct screen_properties
{
    static constexpr std::size_t typical_monitor_count = 2;

    /// A configuration supported by a screen (monitor).
    struct config
    {
        dimension2d   resolution   = {}; ///< Resolution in px by px.
        std::uint32_t refresh_rate = {}; ///< Refresh rate in Hz.

        [[nodiscard]] friend constexpr bool operator==(const config& a, const config& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const config& a, const config& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const config& a, const config& b) noexcept = default;

        constexpr void swap(config& other) noexcept
        {
            resolution.swap(other.resolution);
            std::swap(refresh_rate, other.refresh_rate);
        }

        constexpr friend void swap(config& a, config& b) noexcept { a.swap(b); }
    };

    std::uint32_t       device         = {}; ///< Device index (when relevant).
    std::string         name           = {}; ///< Screen name. Note that it may not be displayable. Should not be relied on.
    rectangle2d         area           = {}; ///< Screen render area.
    std::uint32_t       refresh_rate   = {}; ///< Screen refresh rate in Hz.
    std::vector<config> configurations = {}; ///< Supported configurations.

    [[nodiscard]] friend constexpr bool operator==(const screen_properties& a, const screen_properties& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const screen_properties& a, const screen_properties& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const screen_properties& a, const screen_properties& b) noexcept = default;

    void swap(screen_properties& other) noexcept
    {
        std::swap(device, other.device);
        name.swap(other.name);
        area.swap(other.area);
        std::swap(refresh_rate, other.refresh_rate);
        configurations.swap(other.configurations);
    }

    friend void swap(screen_properties& a, screen_properties& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const screen_properties& i)
    {
        out << "screen:{"
            << "device: " << i.device << "\t"
            << " name: " << i.name << "\t"
            << " area: " << i.area << "px^2"
            << "\t"
            << " refresh rate: " << i.refresh_rate << "Hz"
            << "\n"
            << "supported configurations:\n";

        for(const auto& c : i.configurations)
        {
            out << "{" << c.resolution << ", " << c.refresh_rate << "Hz"
                << "}"
                << "\n";
        }

        return out << "}";
    }
};

} // namespace fubuki::io::platform

#endif // FUBUKI_IO_PLATFORM_SCREEN_PROPERTIES_HPP
