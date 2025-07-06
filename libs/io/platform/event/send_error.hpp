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

#ifndef FUBUKI_DISPLAY_PLATFORM_EVENT_SEND_ERROR_HPP
#define FUBUKI_DISPLAY_PLATFORM_EVENT_SEND_ERROR_HPP

#include <ostream>
#include <variant>

#include "io/platform/error.hpp"
#include "io/platform/event/events.hpp"

/// Errors that can occur when attempting to send events to a window.
namespace fubuki::io::platform::event::send_error
{

using unknown = error::unknown;

/// Indicates an event is not supported.
struct not_supported
{
    event::any cause = {}; ///< The event that was not supported.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const not_supported& p)
    {
        return out << "event::send_error::not_supported:{" << p.cause << "}";
    }

    void swap(not_supported& other) noexcept { cause.swap(other.cause); }

    friend void swap(not_supported& a, not_supported& b) noexcept { a.swap(b); }
};

/// Indicates an OS API call failed.
using os = error::api_call;

/// Indicates an operation is not supported on a given platform.
using operation_not_supported = error::operation_not_supported;

/// Any error that can occur when triggering an event.
struct any
{
    using value_type = std::variant<unknown, not_supported, operation_not_supported, os>;

    value_type value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const any& error)
    {
        return std::visit([&out](const auto& e) -> auto& { return out << e; }, error.value);
    }

    void swap(any& other) noexcept { value.swap(other.value); }

    friend void swap(any& a, any& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::event::send_error

#endif // FUBUKI_DISPLAY_PLATFORM_EVENT_SEND_ERROR_HPP
