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

#ifndef FUBUKI_FUYU_VIEWS_EVENT_HPP
#define FUBUKI_FUYU_VIEWS_EVENT_HPP

#include <ostream>
#include <utility>

#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/device_ref.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki
{

namespace fuyu
{

namespace views
{

struct event
{
    /// State of an event.
    enum class state
    {
        set,    ///< The event is set.
        reset,  ///< The event has been reset or was not set yet.
        unknown ///< The state is unknown: the result code is not handled by Fubuki. Please open an issue.
    };

    event_handle handle = {}; ///< Event handle.
    device_cref  device;      ///< Device on which the semaphore is allocated.

    [[nodiscard]] constexpr operator event_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const event& a, const event& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const event& a, const event& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const event& a, const event& b) noexcept { return a.handle <=> b.handle; }
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, event::state state)
{
    switch(state)
    {
        case event::state::set    : out << "event::state::set"; break;
        case event::state::reset  : out << "event::state::reset"; break;
        case event::state::unknown: out << "event::state::unknown"; break;
        default                   : out << "event::state::<Invalid value> - perhaps static_cast?"; break;
    }
    return out;
}

} // namespace views

using event_view  = views::event;
using event_state = event_view::state;

using views::operator<<; // Don't force user to make that alias.

} // namespace fuyu

using fuyu::views::operator<<; // Don't force user to make that alias.

} // namespace fubuki

namespace std
{

template<>
struct hash<fubuki::fuyu::event_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::event_view& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

template<>
struct hash<fubuki::fuyu::event_state>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::event_state& v) const noexcept
    {
        return std::hash<std::underlying_type_t<fubuki::fuyu::event_state>>{}(std::to_underlying(v));
    }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_EVENT_HPP
