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

#include "fd_timer.hpp"

#include <sys/timerfd.h>

namespace fubuki::io::platform::linux_bsd
{

namespace
{

[[nodiscard]] constexpr auto to_linux(fd_timer::id i) noexcept
{
    switch(i)
    {
        case fd_timer::id::realtime      : return CLOCK_REALTIME;
        case fd_timer::id::monotonic     : return CLOCK_MONOTONIC;
        case fd_timer::id::boot_time     : return CLOCK_BOOTTIME;
        case fd_timer::id::realtime_alarm: return CLOCK_REALTIME_ALARM;
        case fd_timer::id::bootime_alarm : return CLOCK_BOOTTIME_ALARM;
        default                          : fubuki_assert(false, "Invalid value, maybe static_cast?"); return CLOCK_REALTIME;
    }
}

[[nodiscard]] constexpr int to_linux(flag_mask<fd_timer::flag> f) noexcept
{
    using flag = fd_timer::flag;

    int r = {};

    if(f & flag::non_block)
    {
        r |= TFD_CLOEXEC;
    }

    if(f & flag::clo_exec)
    {
        r |= TFD_CLOEXEC;
    }

    return r;
}

} // namespace

[[nodiscard]] std::optional<any_call_info> fd_timer::create() noexcept
{
    auto fd = timerfd_create(to_linux(m_id), to_linux(m_flags));

    if(fd == -1)
    {
        const auto error = errno;
        return any_call_info{
            linux_call_info{.result       = static_cast<linux_bsd::code>(error),
                            .call_literal = "posix_fallocate(fd, 0, static_cast<::off_t>(size_bytes)"_literal}
        };
    }

    m_fd = file_descriptor{file_descriptor::handle{fd}};

    return {};
}

} // namespace fubuki::io::platform::linux_bsd
