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

#ifndef FUBUKI_IO_MOUSE_HPP
#define FUBUKI_IO_MOUSE_HPP

#include <core/config/macros.hpp>
#include <io/platform/error.hpp>
#include <io/platform/mouse_button.hpp>
#include <io/platform/mouse_state.hpp>
#include <io/platform/views/display.hpp>

namespace fubuki::io::mouse
{

/// Polls for one button state.
[[nodiscard]] FUBUKI_IO_API std::expected<bool, platform::error::any> poll(platform::views::display dp, button b) noexcept;

/// Returns the current state of the mouse buttons.
[[nodiscard]] FUBUKI_IO_API std::expected<state::buttons, platform::error::any> buttons_state(platform::views::display dp) noexcept;

/// Returns the mouse current state.
[[nodiscard]] FUBUKI_IO_API std::expected<state, platform::error::any> current_state(platform::views::display dp) noexcept;

/// Returns the mouse current position.
[[nodiscard]] FUBUKI_IO_API std::expected<position2d, platform::error::any> pos(platform::views::display dp) noexcept;

} // namespace fubuki::io::mouse

#endif // FUBUKI_IO_MOUSE_HPP
