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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_DRAW_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_DRAW_HPP

#include "fuyu/command/draw.hpp"
#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail::draw
{

struct call
{
    auto operator()(std::uint32_t vertex_count, std::uint32_t instance_count, std::uint32_t first_vertex, std::uint32_t first_instance) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::draw::call(f.command_buffer(), vertex_count, instance_count, first_vertex, first_instance);
                                   return f;
                               }};
    }
};

struct indexed
{
    auto operator()(std::uint32_t index_count,
                    std::uint32_t instance_count,
                    std::uint32_t first_index,
                    std::int32_t  vertex_offset,
                    std::uint32_t first_instance) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::draw::indexed(
                                       f.command_buffer(), index_count, instance_count, first_index, vertex_offset, first_instance);
                                   return f;
                               }};
    }
};

struct indirect
{
    auto operator()(buffer_handle buffer, VkDeviceSize offset, std::uint32_t draw_count, std::uint32_t stride) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::draw::indirect(f.command_buffer(), buffer, offset, draw_count, stride);
                                   return f;
                               }};
    }
};

struct indexed_indirect
{
    auto operator()(buffer_handle buffer, VkDeviceSize offset, std::uint32_t draw_count, std::uint32_t stride) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::draw::indexed_indirect(f.command_buffer(), buffer, offset, draw_count, stride);
                                   return f;
                               }};
    }
};

#if defined(VK_VERSION_1_2)
struct indexed_indirect_count
{
    auto operator()(buffer_handle buffer,
                    VkDeviceSize  offset,
                    buffer_handle count_buffer,
                    VkDeviceSize  count_offset,
                    std::uint32_t max_draw_count,
                    std::uint32_t stride) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::draw::indexed_indirect_count(
                                       f.command_buffer(), buffer, offset, count_buffer, count_offset, max_draw_count, stride);
                                   return f;
                               }};
    }
};

struct indirect_count
{
    auto operator()(buffer_handle buffer,
                    VkDeviceSize  offset,
                    buffer_handle count_buffer,
                    VkDeviceSize  count_offset,
                    std::uint32_t max_draw_count,
                    std::uint32_t stride) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::draw::indirect_count(
                                       f.command_buffer(), buffer, offset, count_buffer, count_offset, max_draw_count, stride);
                                   return f;
                               }};
    }
};
#endif // defined(VK_VERSION_1_2)

} // namespace fubuki::fuyu::command::pipe::detail::draw

#endif // FUBUKI_FUYU_COMMAND_PIPE_DRAW_HPP
