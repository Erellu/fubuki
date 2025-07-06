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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_SUBMIT_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_SUBMIT_HPP

#include "fuyu/command/pipe/flow.hpp"
#include "fuyu/command/pipe/tag.hpp"
#include "fuyu/command/submit.hpp" // IWYU pragma: export
#include "fuyu/functions/command_buffer.hpp"

namespace fubuki::fuyu::command::pipe::detail
{

struct submission
{
};

struct submit
{
    [[nodiscard]]
    std::expected<void, error::any> operator()(queue                                    q,
                                               flow                                     f, // Pass by value - force to move
                                               std::optional<fence_handle>              fence             = {},
                                               std::span<const command::wait_semaphore> wait_semaphores   = {},
                                               std::span<const semaphore_handle>        signal_semaphores = {}) const noexcept
    {
        if(f.error().has_value())
        {
            return std::unexpected{*f.error()}; // NOLINT(bugprone-unchecked-optional-access): false positive
        }

        if(const auto end = fuyu::end(f.command_buffer()); not end)
        {
            return std::unexpected{error::any{error::end{end.error()}}};
        }

        // TODO : multiple submits
        if(const auto s = fuyu::submit(q, f.command_buffer(), fence, wait_semaphores, signal_semaphores); not s)
        {
            return std::unexpected{error::any{error::submit{s.error()}}};
        }

        return {};
    }

    [[nodiscard]]
    std::expected<void, error::any> operator()(queue                   q,
                                               flow                    f, // Pass by value - force to move
                                               const fuyu::submission& sub) const noexcept
    {
        if(f.error().has_value())
        {
            return std::unexpected{*f.error()}; // NOLINT(bugprone-unchecked-optional-access): false positive
        }

        if(const auto end = fuyu::end(f.command_buffer()); not end)
        {
            return std::unexpected{error::any{error::end{end.error()}}};
        }

        // TODO : multiple submits
        if(const auto s = fuyu::submit(q, f.command_buffer(), sub); not s)
        {
            return std::unexpected{error::any{error::submit{s.error()}}};
        }

        return {};
    }

    [[nodiscard]]
    std::expected<void, error::any> operator()(queue                                    q,
                                               already_ended                            f, // Pass by value - force to move
                                               std::optional<fence_handle>              fence             = {},
                                               std::span<const command::wait_semaphore> wait_semaphores   = {},
                                               std::span<const semaphore_handle>        signal_semaphores = {}) const noexcept
    {
        if(f.pipe.error().has_value())
        {
            return std::unexpected{*f.pipe.error()}; // NOLINT(bugprone-unchecked-optional-access): false positive
        }

        // TODO : multiple submits
        if(const auto s = fuyu::submit(q, f.pipe.command_buffer(), fence, wait_semaphores, signal_semaphores); not s)
        {
            return std::unexpected{error::any{error::submit{s.error()}}};
        }

        return {};
    }

    [[nodiscard]]
    std::expected<void, error::any> operator()(queue                   q,
                                               already_ended           f, // Pass by value - force to move
                                               const fuyu::submission& sub) const noexcept
    {
        if(f.pipe.error().has_value())
        {
            return std::unexpected{*f.pipe.error()}; // NOLINT(bugprone-unchecked-optional-access): false positive
        }

        // TODO : multiple submits
        if(const auto s = fuyu::submit(q, f.pipe.command_buffer(), sub); not s)
        {
            return std::unexpected{error::any{error::submit{s.error()}}};
        }

        return {};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail

#endif // FUBUKI_FUYU_COMMAND_PIPE_SUBMIT_HPP
