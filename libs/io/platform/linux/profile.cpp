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

#include <cerrno>
#include <memory>

#include "io/platform/linux/profile.hpp"

#include "io/platform/linux/error.hpp"

namespace fubuki::io::platform::linux_bsd
{

namespace
{

// Port of <sys/time.h> timespec_diff_macro
[[nodiscard]] [[maybe_unused]]
constexpr timespec diff(const timespec& a, const timespec& b)
{
    constexpr auto nano_ratio = 1000000000L;

    timespec result = {};

    result.tv_sec  = a.tv_sec - b.tv_sec;
    result.tv_nsec = a.tv_nsec - b.tv_nsec;
    if(result.tv_nsec < 0)
    {
        --result.tv_sec;
        result.tv_nsec += nano_ratio;
    }

    return result;
}

} // anonymous namespace

[[nodiscard]] std::expected<profile_data::any, platform::error::api_call> begin_profile() noexcept
{
    profile_data::linux_bsd r = {};

    if(clock_gettime(CLOCK_MONOTONIC_RAW, &r.start) != 0)
    {
        const auto error = static_cast<linux_bsd::code>(errno);

        return std::unexpected{
            any_call_info{linux_call_info{.result = error, .call_literal = "clock_gettime(CLOCK_MONOTONIC_RAW, &r.start) == 0"_literal}}};
    }

    return r;
}

[[nodiscard]] std::expected<std::chrono::microseconds, platform::error::api_call> end_profile(const profile_data::any& begin) noexcept
{
    std::timespec end = {};

    if(clock_gettime(CLOCK_MONOTONIC_RAW, std::addressof(end)) != 0)
    {
        const auto error = static_cast<linux_bsd::code>(errno);

        return std::unexpected{
            any_call_info{linux_call_info{.result = error, .call_literal = "clock_gettime(CLOCK_MONOTONIC_RAW, &r.start) == 0"_literal}}};
    }

    if(const auto* const begin_data = std::get_if<profile_data::linux_bsd>(std::addressof(begin)))
    {
        const auto                     elapsed = diff(begin_data->start, end);
        const std::chrono::nanoseconds total   = std::chrono::seconds{elapsed.tv_sec} + std::chrono::nanoseconds{elapsed.tv_nsec};

        return std::chrono::duration_cast<std::chrono::microseconds>(total);
    }

    return std::unexpected{any_call_info{
        linux_call_info{.result = static_cast<linux_bsd::code>(-1), .call_literal = "std::get_if<profile_data::linux_bsd> != nullptr"_literal}}};
}

} // namespace fubuki::io::platform::linux_bsd
