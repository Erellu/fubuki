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

#include "io/platform/linux/wayland/seat.hpp"

#include "io/platform/linux/wayland/display.hpp"
#include "io/platform/linux/wayland/error.hpp"
#include "io/platform/linux/wayland/interface.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

seat::seat(views::display::wayland parent)
{
    const auto& globals = globals_of(fubuki::validate_by::throw_call_exception, parent).get();

    if(globals.property.seat.flags & WL_SEAT_CAPABILITY_KEYBOARD)
    {
        m_components.keyboard = keyboard{parent};
    }

    if(globals.property.seat.flags & WL_SEAT_CAPABILITY_POINTER)
    {
        m_components.mouse = pointer{parent};
    }

    m_handle = globals.handle.seat;
}

seat::seat(wl_seat* handle, std::uint32_t flags) : m_handle{handle}
{
    if(handle == nullptr)
    {
        throw call_exception{any_call_info{call_info{.result = {code::unknown{}}, .call_literal = "handle == nullptr"_literal}}};
    }

    if(flags & WL_SEAT_CAPABILITY_KEYBOARD)
    {
        m_components.keyboard = keyboard{handle, flags};
    }

    if(flags & WL_SEAT_CAPABILITY_POINTER)
    {
        m_components.mouse = pointer{handle, flags};
    }
}

[[nodiscard]] std::expected<seat, error::api_call> seat::make(views::display::wayland parent) noexcept
{
    auto globals = globals_of(parent);

    if(not globals)
    {
        return std::unexpected{globals.error()};
    }

    return make(globals->get().handle.seat, globals->get().property.seat.flags);
}

[[nodiscard]] std::expected<seat, error::api_call> seat::make(wl_seat* handle, std::uint32_t flags) noexcept
{
    if(handle == nullptr)
    {
        return std::unexpected{
            call_info{.result = {code::unknown{}}, .call_literal = "handle == nullptr"_literal}
        };
    }

    std::optional<keyboard> kb = {};

    if(flags & WL_SEAT_CAPABILITY_KEYBOARD)
    {
        auto k = keyboard::make(handle, flags);

        if(not k)
        {
            return std::unexpected{k.error()};
        }

        kb = *std::move(k);
    }

    std::optional<pointer> point = {};

    if(flags & WL_SEAT_CAPABILITY_POINTER)
    {
        auto p = pointer::make(handle, flags);

        if(not p)
        {
            return std::unexpected{p.error()};
        }

        point = *std::move(p);
    }

    return seat{token{}, std::move(kb), std::move(point), handle};
}

} // namespace fubuki::io::platform::linux_bsd::wayland
