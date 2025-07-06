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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_DISPATCH_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_DISPATCH_HPP

#include "fuyu/command/dispatch.hpp"
#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail::dispatch
{

struct direct
{
    auto operator()(std::uint32_t group_count_x, std::uint32_t group_count_y, std::uint32_t group_count_z) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::dispatch::direct(f.command_buffer(), group_count_x, group_count_y, group_count_z);
                                   return f;
                               }};
    }
};

struct indirect
{
    auto operator()(buffer_handle buffer, VkDeviceSize offset) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::dispatch::indirect(f.command_buffer(), buffer, offset);
                                   return f;
                               }};
    }
};

#if defined(VK_VERSION_1_1)
struct base
{
    auto operator()(std::uint32_t base_group_x,
                    std::uint32_t base_group_y,
                    std::uint32_t base_group_z,
                    std::uint32_t group_count_x,
                    std::uint32_t group_count_y,
                    std::uint32_t group_count_z) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::dispatch::base(
                                       f.command_buffer(), base_group_x, base_group_y, base_group_z, group_count_x, group_count_y, group_count_z);
                                   return f;
                               }};
    }
};
#endif
} // namespace fubuki::fuyu::command::pipe::detail::dispatch

#endif // FUBUKI_FUYU_COMMAND_PIPE_DISPATCH_HPP
