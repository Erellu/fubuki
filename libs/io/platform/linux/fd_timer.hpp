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

#ifndef FUBUKI_IO_PLATFORM_LINUX_FD_TIMER_HPP
#define FUBUKI_IO_PLATFORM_LINUX_FD_TIMER_HPP

#include <core/config/macros.hpp>
#include <core/flag_mask.hpp>

#include "io/platform/error.hpp"
#include "io/platform/linux/file_descriptor.hpp"

namespace fubuki::io::platform::linux_bsd
{

/**
 * A file descriptor timer.
 */
class fd_timer
{
    struct token
    {
    };

public:

    /// Timer types.
    enum class id
    {
        realtime,
        monotonic,
        boot_time,
        realtime_alarm,
        bootime_alarm,
    };

    /// Timer flags.
    enum class flag
    {
        non_block,
        clo_exec,
    };

    /// The default timer flags, used if the flags are not specified.
    static constexpr auto default_flags = flag_mask<flag>{flag::non_block} | flag::clo_exec;

    /**
     * Constructor.
     * @param i Timer type.
     * @param f (optional) Timer flags. Defaults to fd_timer::default_flags.
     * @throws call_exception This constructor throws an instance of call_exception if a call failed.
     * @see https://man7.org/linux/man-pages/man2/timerfd_create.2.html
     */
    fd_timer(id i, flag_mask<flag> f = default_flags) : fd_timer{token{}, i, f}
    {
        if(const auto error = create())
        {
            throw call_exception{*error};
        }
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param i Timer type.
     * @param f (optional) Timer flags. Defaults to fd_timer::default_flags.
     * @returns A valid instance of fd_timer, or an instance of error::api_call describing the call that failed.
     * @see https://man7.org/linux/man-pages/man2/timerfd_create.2.html
     */
    [[nodiscard]] static std::expected<fd_timer, error::api_call> make(id i, flag_mask<flag> f = default_flags) noexcept
    {
        fd_timer result{token{}, i, f};

        if(const auto error = result.create())
        {
            return std::unexpected{*error};
        }

        return result;
    }

    fd_timer(const fd_timer&)                = delete;
    fd_timer& operator=(const fd_timer&)     = delete;
    fd_timer(fd_timer&&) noexcept            = default;
    fd_timer& operator=(fd_timer&&) noexcept = default;

    [[nodiscard]] auto                    type() const noexcept { return m_id; }
    [[nodiscard]] auto                    flags() const noexcept { return m_flags; }
    [[nodiscard]] file_descriptor::handle handle() const noexcept { return m_fd.get(); }

    /// Swaps two objects.
    void swap(fd_timer& other) noexcept
    {
        std::swap(m_id, other.m_id);
        m_flags.swap(other.m_flags);
        m_fd.swap(other.m_fd);
    }

    /// Swaps two objects.
    friend void swap(fd_timer& a, fd_timer& b) noexcept { a.swap(b); }

private:

    fd_timer(token, id i, flag_mask<flag> f) noexcept : m_id{i}, m_flags{f} {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create() noexcept;

    id              m_id    = {};
    flag_mask<flag> m_flags = {};
    file_descriptor m_fd;
};

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_FD_TIMER_HPP
