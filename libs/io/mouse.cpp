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

#include <io/platform/current_platform.hpp>

#if defined(_WIN32)
    #include <io/platform/win32/mouse.hpp>
#elif defined(__unix__)
    #include <io/platform/linux/mouse.hpp>
#endif

#include "io/mouse.hpp"

namespace fubuki::io::mouse
{

[[nodiscard]]
std::expected<bool, platform::error::any> poll(platform::views::display dp, button b) noexcept
{
    return platform::current::mouse::poll(dp, b);
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<state::buttons, platform::error::any> buttons_state(platform::views::display dp) noexcept
{
    return platform::current::mouse::buttons_state(dp);
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<state, platform::error::any> current_state(platform::views::display dp) noexcept
{
    return platform::current::mouse::current_state(dp);
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<position2d, platform::error::any> pos(platform::views::display dp) noexcept
{
    return platform::current::mouse::pos(dp);
}

} // namespace fubuki::io::mouse
