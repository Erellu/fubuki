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

#include <mutex>
#include <sstream>

#include "io/platform/win32/screen.hpp"

#include <core/small_vector.hpp>

#include "io/platform/win32/error.hpp"

#include <windows.h> // #include last, don't risk interferences with #define directives in this header

namespace fubuki::io::platform::win32::screen
{

namespace
{

namespace globals
{

/// Last collected information about the available screens
[[nodiscard]] auto& collected_info()
{
    static small_vector<properties, properties::typical_monitor_count> s;
    return s;
}

[[nodiscard]] auto& sync()
{
    static std::mutex m;
    return m;
}

} // namespace globals

/// Proc function called by EnumDisplayMonitors. Fills globals::collected_info.
BOOL CALLBACK proc(HMONITOR /*monitor*/, HDC /*device_context*/, LPRECT rect, LPARAM) noexcept
{
    auto& screens = globals::collected_info();

    const auto x = rect->left;
    const auto y = rect->top;

    const auto width  = rect->right - rect->left;
    const auto height = rect->bottom - rect->top;

    properties i{
        .device         = {}, // Set afterwards
        .name           = "", // Set afterwards
        .area           = {.offset = {x, y}, .extent = {width, height}},
        .refresh_rate   = {}, // Set afterwards
        .configurations = {}  // Set afterwards
    };

    i.configurations.reserve(15); // Completely arbitrary // NOLINT(cppcoreguidelines-avoid-magic-numbers)

    screens.push_back(std::move(i));

    return true;
}

} // anonymous namespace

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<small_vector<properties, properties::typical_monitor_count>, error::any> enumerate(display_view /*unused on Windows*/)
{
    static constexpr auto make_display_name = [](const DISPLAY_DEVICE& d) -> std::string
    {
        std::stringstream stream;
        stream << d.DeviceName << " " << d.DeviceString; // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)
        return stream.str();
    };

    const std::scoped_lock<std::mutex> lock{globals::sync()};

    // Clear previous information in case user plugged monitor on the fly
    globals::collected_info().clear();

    if(EnumDisplayMonitors(nullptr, nullptr, proc, 0))
    {
        // Taken from https://stackoverflow.com/a/60229570
        // Code available under the CC BY-SA license (https://creativecommons.org/licenses/by-sa/4.0/)
        // And slightly edited
        {
            DISPLAY_DEVICE device = {};
            device.cb             = sizeof(DISPLAY_DEVICE);

            DEVMODE mode = {};
            mode.dmSize  = sizeof(DEVMODE);

            DWORD device_index = 0;
            while(EnumDisplayDevices(nullptr, device_index, &device, EDD_GET_DEVICE_INTERFACE_NAME))
            {
                // Current configuration
                {
                    if(!EnumDisplayDevices(nullptr, device_index, &device, EDD_GET_DEVICE_INTERFACE_NAME))
                    {
                        break;
                    }

                    if(!EnumDisplaySettings(static_cast<LPCSTR>(device.DeviceName), ENUM_CURRENT_SETTINGS, &mode))
                    {
                        break;
                    }

                    auto& i = globals::collected_info().at(static_cast<std::size_t>(device_index));

                    i.device = static_cast<std::uint32_t>(device_index);
                    i.name   = make_display_name(device);
                    // info.area magically filled by proc when calling EnumDisplayMonitors
                    i.refresh_rate = static_cast<std::uint32_t>(mode.dmDisplayFrequency);
                }

                // Configurations available
                {
                    DWORD mode_counter = 0;
                    while(EnumDisplaySettings(static_cast<LPCSTR>(device.DeviceName), mode_counter, &mode))
                    {
                        auto& i = globals::collected_info().at(static_cast<std::size_t>(device_index));

                        const dimension2d dim
                            = {.width = static_cast<std::int32_t>(mode.dmPelsWidth), .height = static_cast<std::int32_t>(mode.dmPelsWidth)};

                        const auto refresh = static_cast<std::uint32_t>(mode.dmDisplayFrequency);

                        i.configurations.emplace_back(dim, refresh);
                        ++mode_counter;
                    }
                }

                ++device_index;
            }
        }
    }
    else
    {
        return std::unexpected{error::api_call{call_info{
            .result       = code{},
            .call_literal = "EnumDisplayDevices"_literal,
        }}};
    }

    return globals::collected_info();
}

} // namespace fubuki::io::platform::win32::screen
