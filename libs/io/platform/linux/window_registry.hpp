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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WINDOW_REGISTRY_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WINDOW_REGISTRY_HPP

#include <optional>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>

#include "io/platform/current_platform.hpp"
#include "io/platform/views/display.hpp"

namespace fubuki::io::platform::linux_bsd::window_registry
{

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::size_t size() noexcept;

[[nodiscard]] FUBUKI_IO_PLATFORM_API bool empty() noexcept;

FUBUKI_IO_PLATFORM_API
void add(surface_handle data, window_ref w) noexcept;

FUBUKI_IO_PLATFORM_API
void swap(surface_handle data, window_ref w) noexcept;

FUBUKI_IO_PLATFORM_API
void remove(surface_handle data) noexcept;

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::size_t remove_closed() noexcept;

FUBUKI_IO_PLATFORM_API void clear();

[[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<window_ref> window_of(surface_handle data) noexcept;

inline std::optional<wayland::window_ref> window_of(wayland::surface_handle handle) noexcept
{
    return window_of(linux_bsd::surface_handle{handle})
        .and_then(
            [](window_ref r) noexcept -> std::optional<wayland::window_ref>
            {
                if(auto* const wayland_window = std::get_if<wayland::window_ref>(std::addressof(r)))
                {
                    return *wayland_window;
                }
                return std::nullopt;
            });
}

inline std::optional<xlib::window_ref> window_of(xlib::surface_handle handle) noexcept
{
    return window_of(linux_bsd::surface_handle{handle})
        .and_then(
            [](window_ref r) noexcept -> std::optional<xlib::window_ref>
            {
                if(auto* const xlib_window = std::get_if<xlib::window_ref>(std::addressof(r)))
                {
                    return *xlib_window;
                }
                return std::nullopt;
            });
}

[[nodiscard]] inline bool contains(surface_handle data) noexcept { return window_of(data).has_value(); }

[[nodiscard]] FUBUKI_IO_PLATFORM_API bool event_pending(platform::views::display dp) noexcept;

} // namespace fubuki::io::platform::linux_bsd::window_registry

#endif // FUBUKI_IO_PLATFORM_LINUX_WINDOW_REGISTRY_HPP
