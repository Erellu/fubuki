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

#ifndef FUBUKI_IO_PLATFORM_WIN32_SEND_EVENT_HPP
#define FUBUKI_IO_PLATFORM_WIN32_SEND_EVENT_HPP

#include <ranges>
#include <span>

#include <core/constants.hpp>
#include <core/small_vector.hpp>

#include "io/platform/event/events.hpp"
#include "io/platform/event/queue.hpp"
#include "io/platform/event/send_error.hpp"
#include "io/platform/win32/detail/send_event.hpp"
#include "io/platform/win32/window.hpp" // IWYU pragma: keep (required to have the type complete upon checking detail::send_event::window_range)

namespace fubuki::io::platform::win32
{

namespace detail::send_event
{

template<typename range>
concept window_range = std::ranges::range<range> and requires(std::ranges::range_value_t<range> e) {
    { e.platform_data() } -> std::convertible_to<platform_data>;
};

struct event_translation
{
    small_vector<INPUT>       io_devices   = {}; ///< Mouse and keyboard events, that can be expressed in terms of SendInput.
    small_vector<std::size_t> user_events  = {}; ///< Indexes of custom user events, sent to Fubuki's event queue.
    small_vector<message>     other_events = {}; ///< Indexes of the events that cannot be expressed in terms of SendInput, sent using PostMessage.
};

[[nodiscard]]
inline std::expected<event_translation, event::send_error::any> translate(const std::span<const event::any> events)
{
    event_translation result = {};

    for(std::size_t i = 0; const auto& event : events)
    {
        if(std::holds_alternative<event::user::custom>(event.value))
        {
            result.user_events.push_back(i);
        }
        else
        {
            const auto translation = translate(event);

            if(not translation)
            {
                return std::unexpected{translation.error()};
            }

            if(std::holds_alternative<INPUT>(*translation))
            {
                result.io_devices.emplace_back(std::get<INPUT>(*translation));
            }
            else if(std::holds_alternative<message>(*translation))
            {
                result.other_events.push_back(std::get<message>(*translation));
            }
            else
            {
                fubuki_assert(false, "Internal error. Failed to translate an event.");
                return std::unexpected{event::send_error::any{event::send_error::unknown{}}};
            }
        }

        ++i;
    }

    return result;
}

} // namespace detail::send_event

//------------------------------------------------------------------------------

template<detail::send_event::window_range window_range>
[[nodiscard]]
inline std::expected<void, event::send_error::any> send(event::queue& q, window_range windows, const std::span<const event::any> events)
{
    namespace error = event::send_error;

    auto translation = detail::send_event::translate(events);

    if(not translation)
    {
        return std::unexpected{translation.error()};
    }

    // TODO: make a range of the user events instead of iterating one by one
    // auto user_events = std::ranges::for_each(translation.user_events, [&events](const std::size_t index) { return std::cref(events[index]); });
    auto user_events
        = translation->user_events | std::views::transform([events](const std::size_t index) noexcept -> const auto& { return events[index]; });

    const auto old_focus = GetFocus();

    for(auto& w : windows)
    {
        const surface_data::win32 data = w.platform_data();

        SetFocus(data.hwnd); // Required for SendInput: it only sends to the active window

        if(not translation->io_devices.empty())
        {
            if(const auto r = SendInput(static_cast<UINT>(translation->io_devices.size()), translation->io_devices.data(), sizeof(INPUT));
               r != translation->io_devices.size())
            {
                const auto win32_error_code = GetLastError();
                const auto error_code       = static_cast<code>(win32_error_code);

                return std::unexpected{error::any{error::os{call_info{
                    .result = {error_code},
                    .call_literal
                    = "SendInput(static_cast<UINT>(translation->io_devices.size()), translation->io_devices.data(), sizeof(INPUT)"_literal}}}};
            }
        }

        for(const auto& message : translation->other_events)
        {
            if(const auto check = detail::send_event::send(data, message); not check)
            {
                return std::unexpected{check.error()};
            }
        }

        q.push(w.handle(), user_events);
    }

    SetFocus(old_focus);

    return {};
}

} // namespace fubuki::io::platform::win32

#endif // FUBUKI_IO_PLATFORM_WIN32_SEND_EVENT_HPP
