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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_COPY_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_COPY_HPP

#include "fuyu/command/copy.hpp"
#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail
{

struct copy
{
    auto operator()(buffer_handle source, buffer_handle dest, std::span<const VkBufferCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, dest, regions);
                                   return f;
                               }};
    }

    auto operator()(buffer_handle source, buffer_handle dest, std::initializer_list<VkBufferCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, dest, regions);
                                   return f;
                               }};
    }

    auto operator()(buffer_handle source, image_handle dest, VkImageLayout image_layout, std::span<const VkBufferImageCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, dest, image_layout, regions);
                                   return f;
                               }};
    }

    auto
    operator()(buffer_handle source, image_handle dest, VkImageLayout image_layout, std::initializer_list<VkBufferImageCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, dest, image_layout, regions);
                                   return f;
                               }};
    }

    auto operator()(image_handle source, VkImageLayout image_layout, buffer_handle dest, std::span<const VkBufferImageCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, image_layout, dest, regions);
                                   return f;
                               }};
    }

    auto
    operator()(image_handle source, VkImageLayout image_layout, buffer_handle dest, std::initializer_list<VkBufferImageCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, image_layout, dest, regions);
                                   return f;
                               }};
    }

    auto operator()(image_handle                 source,
                    VkImageLayout                source_layout,
                    image_handle                 dest,
                    VkImageLayout                destination_layout,
                    std::span<const VkImageCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, source_layout, dest, destination_layout, regions);
                                   return f;
                               }};
    }

    auto operator()(image_handle                       source,
                    VkImageLayout                      source_layout,
                    image_handle                       dest,
                    VkImageLayout                      destination_layout,
                    std::initializer_list<VkImageCopy> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::copy(f.command_buffer(), source, source_layout, dest, destination_layout, regions);
                                   return f;
                               }};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail

#endif // FUBUKI_FUYU_COMMAND_PIPE_COPY_HPP
