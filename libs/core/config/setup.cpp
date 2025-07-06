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

#include <cstdlib> // IWYU pragma : keep

#include "core/config/setup.hpp"

namespace fubuki
{

namespace
{

inline constexpr auto fubuki_build_configuration = configuration::current();

} // anonymous namespace

#if defined(_WIN32)
FUBUKI_TRUE_PURE
#endif
[[nodiscard]] auto configuration::current_window_system() noexcept -> configuration::window_system
{
#if defined(_WIN32)
    return configuration::window_system::win32;
#elif defined(__unix__)
    // See https://stackoverflow.com/questions/45536141/how-i-can-find-out-if-a-linux-system-uses-wayland-or-x11
    // Specifically: https://stackoverflow.com/a/45537237/11910702
    // License: CC BY-SA 3.0
    static const auto result
        = (std::getenv("WAYLAND_DISPLAY") != nullptr) ? configuration::window_system::wayland : configuration::window_system::xlib;
    return result;
#else
    return configuration::window_system::unknown;
#endif
}

[[nodiscard]] FUBUKI_TRUE_PURE const configuration& build_configuration() noexcept
{
    // Hide this in the .cpp so it does not get the wrong information from user setup
    return fubuki_build_configuration;
}

} // namespace fubuki
