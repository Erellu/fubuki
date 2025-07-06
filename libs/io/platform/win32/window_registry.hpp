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

#ifndef FUBUKI_IO_PLATFORM_WIN32_WINDOW_REGISTRY_HPP
#define FUBUKI_IO_PLATFORM_WIN32_WINDOW_REGISTRY_HPP

#include <optional>

#include <core/config/macros.hpp>
#include <core/detail/platform_forward.hpp>

#include "io/platform/current_platform.hpp"
#include "io/platform/views/display.hpp"

namespace fubuki::io::platform::win32
{

class window;

/// Registry keeping track of the windows in the application.
namespace window_registry
{

FUBUKI_IO_PLATFORM_API
bool empty() noexcept;

FUBUKI_IO_PLATFORM_API
void add(surface_handle h, window_ref w) noexcept;

FUBUKI_IO_PLATFORM_API
void swap(surface_handle h, window_ref w) noexcept;

FUBUKI_IO_PLATFORM_API
void remove(surface_handle h) noexcept;

/// Removes closed windows from the registry, and returns the number of remaining windows.
[[nodiscard]] FUBUKI_IO_PLATFORM_API std::size_t remove_closed() noexcept;

FUBUKI_IO_PLATFORM_API
void clear() noexcept;

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<window_ref> window_of(surface_handle hwnd) noexcept;

[[nodiscard]] inline bool contains(surface_handle hwnd) noexcept { return window_of(hwnd).has_value(); }

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<int> peek_messages() noexcept;

[[nodiscard]] FUBUKI_IO_PLATFORM_API bool event_pending(platform::views::display) noexcept;

} // namespace window_registry

} // namespace fubuki::io::platform::win32

#endif // FUBUKI_IO_PLATFORM_WIN32_WINDOW_REGISTRY_HPP
