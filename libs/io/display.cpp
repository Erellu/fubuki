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

#include "io/display.hpp"

#if defined(_WIN32)
    #include <io/platform/win32/display.hpp>
#elif defined(__unix__)
    #include <io/platform/linux/display.hpp>
#endif

#include <io/platform/current_platform.hpp>

namespace fubuki::io
{

struct display::implementation
{
    implementation(platform::current::display dp) noexcept : d{std::move(dp)} {}

    implementation(information i) : d{i} {}

    static std::expected<std::unique_ptr<implementation>, platform::error::api_call> make_unique(display::information info) noexcept
    {
        auto dp = platform::current::display::make(info);

        if(not dp)
        {
            return std::unexpected{dp.error()};
        }

        return std::make_unique<implementation>(*std::move(dp));
    }

    [[nodiscard]] operator display::view() const noexcept { return d; }

    platform::current::display d;
};

display::display(token) noexcept {}

display::display(information info) : m_implementation{std::make_unique<implementation>(info)} {}

[[nodiscard]] std::expected<display, platform::error::api_call> display::make(information info) noexcept
{
    display result{token{}};

    auto impl = implementation::make_unique(info);

    if(not impl)
    {
        return std::unexpected{impl.error()};
    }

    result.m_implementation = *std::move(impl);

    return result;
}

display::~display() noexcept                          = default;
display::display(display&& other) noexcept            = default;
display& display::operator=(display&& other) noexcept = default;

[[nodiscard]] FUBUKI_TRUE_PURE display::operator view() const noexcept { return *m_implementation; }

[[nodiscard]] FUBUKI_SEMI_PURE const display::information& display::info() const noexcept { return m_implementation->d.info(); }

[[nodiscard]] FUBUKI_SEMI_PURE platform::current::display& display::underlying() noexcept { return m_implementation->d; }

[[nodiscard]] FUBUKI_SEMI_PURE const platform::current::display& display::underlying() const noexcept { return m_implementation->d; }

void display::swap(display& other) noexcept { m_implementation.swap(other.m_implementation); }

} // namespace fubuki::io
