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

#ifndef FUBUKI_IO_PLATFORM_LINUX_SEND_EVENT_HPP
#define FUBUKI_IO_PLATFORM_LINUX_SEND_EVENT_HPP

#include <concepts>
#include <expected>
#include <ranges>

#include "io/platform/current_platform.hpp"
#include "io/platform/event/queue.hpp"
#include "io/platform/event/send_error.hpp"
#include "io/platform/linux/window.hpp" // IWYU pragma: keep (required to have the type complete upon checking detail::send_event::window_range)

namespace fubuki::io::platform::linux_bsd
{

namespace detail::send_event
{

template<typename range>
concept window_range = std::ranges::range<range> and requires(std::ranges::range_value_t<range> e) {
    { e.handle() } -> std::convertible_to<surface_handle>;
};

} // namespace detail::send_event

template<detail::send_event::window_range window_range>
[[nodiscard]]
inline std::expected<void, event::send_error::any> send(event::queue& q, window_range&& windows, const std::span<const event::any> events)
{
    for(auto&& w : std::forward<window_range>(windows))
    {
        q.push(w.handle(), events); // On Linux, to keep the same behaviour between Xlib and Wayland, all events are sent to a queue
    }

    return {};
}

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_SEND_EVENT_HPP
