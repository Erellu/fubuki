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

#ifndef FUBUKI_IO_PLATFORM_WIN32_DISPLAY_HPP
#define FUBUKI_IO_PLATFORM_WIN32_DISPLAY_HPP

#include "io/platform/display_info.hpp"
#include "io/platform/error.hpp"
#include "io/platform/views/display.hpp"

namespace fubuki::io::platform::win32
{

class display
{
public:

    using information = platform::information::display;
    using view        = platform::views::display;

    display(information i) noexcept : m_info{i} {}

    display(const display&)            = delete;
    display& operator=(const display&) = delete;
    display(display&&)                 = default;
    display& operator=(display&&)      = default;
    ~display() noexcept                = default;

    [[nodiscard]] static std::expected<display, error::api_call> make(information i) noexcept
    {
        display result{i};
        return result;
    }

    [[nodiscard]] operator view() const noexcept { return view{view::win32{}}; }

    [[nodiscard]] FUBUKI_SEMI_PURE const information& info() const noexcept { return m_info; }

private:

    information m_info = {};
};

} // namespace fubuki::io::platform::win32

#endif // DISPLAY_HPP
