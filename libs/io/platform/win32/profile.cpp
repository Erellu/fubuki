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

#include <memory>

#include "io/platform/win32/profile.hpp"

#include "io/platform/win32/error.hpp"

// clang-format off
// The order matters for MSVC
#include <windows.h>
#include <synchapi.h>
// clang-format on

namespace fubuki::io::platform::win32
{

[[nodiscard]] std::expected<profile_data::any, platform::error::api_call> begin_profile() noexcept
{
    LARGE_INTEGER start              = {};
    LARGE_INTEGER hardware_frequency = {};

    if(QueryPerformanceFrequency(&hardware_frequency) == 0)
    {
        const auto error = GetLastError();

        return std::unexpected{any_call_info{call_info{.result = static_cast<code>(error), .call_literal = "QueryPerformanceFrequency"_literal}}};
    }

    if(QueryPerformanceCounter(&start) == 0)
    {
        const auto error = GetLastError();

        return std::unexpected{any_call_info{call_info{.result = static_cast<code>(error), .call_literal = "QueryPerformanceCounter"_literal}}};
    }

    return profile_data::win32{.hardware_frequency = hardware_frequency.QuadPart, .start = start.QuadPart};
}

[[nodiscard]] std::expected<std::chrono::microseconds, platform::error::api_call> end_profile(const profile_data::any& begin) noexcept
{
    LARGE_INTEGER end = {};

    if(QueryPerformanceCounter(&end) == 0)
    {
        const auto error = GetLastError();

        return std::unexpected{any_call_info{call_info{.result = static_cast<code>(error), .call_literal = "QueryPerformanceCounter"_literal}}};
    }

    if(const auto* const begin_data = std::get_if<profile_data::win32>(std::addressof(begin)))
    {
        constexpr auto      scale    = 1000000;
        const LARGE_INTEGER duration = {.QuadPart = ((end.QuadPart - begin_data->start) * scale) / begin_data->hardware_frequency};

        return std::chrono::microseconds{duration.QuadPart};
    }

    return std::unexpected{
        any_call_info{call_info{.result = static_cast<win32::code>(-1), .call_literal = "std::get_if<profile_data::win32> != nullptr"_literal}}};
}

} // namespace fubuki::io::platform::win32
