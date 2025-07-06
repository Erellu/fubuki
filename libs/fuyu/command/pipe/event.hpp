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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_EVENT_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_EVENT_HPP

#include "fuyu/command/event.hpp"
#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail::event
{

struct set
{
    auto operator()(event_handle event, VkPipelineStageFlags stage_mask) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::set(f.command_buffer(), event, stage_mask);
                                   return f;
                               }};
    }

#if defined(VK_VERSION_1_3)
    auto operator()(event_handle event, VkDependencyInfo dependency) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::set(f.command_buffer(), event, dependency);
                                   return f;
                               }};
    }
#endif // #if defined(VK_VERSION_1_3)
};

struct reset
{
    auto operator()(event_handle event, VkPipelineStageFlags stage_mask) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::reset(f.command_buffer(), event, stage_mask);
                                   return f;
                               }};
    }

#if defined(VK_VERSION_1_3)
    auto operator()(event_handle event, VkPipelineStageFlags2 stage_mask) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::reset(f.command_buffer(), event, stage_mask);
                                   return f;
                               }};
    }
#endif // #if defined(VK_VERSION_1_3)
};

struct wait
{
    auto operator()(std::span<const event_handle>          events,
                    VkPipelineStageFlags                   source_stage,
                    VkPipelineStageFlags                   dest_stage,
                    std::span<const VkMemoryBarrier>       memory_barriers,
                    std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>  image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>    events,
                    VkPipelineStageFlags                   source_stage,
                    VkPipelineStageFlags                   dest_stage,
                    std::span<const VkMemoryBarrier>       memory_barriers,
                    std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>  image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::span<const event_handle>          events,
                    VkPipelineStageFlags                   source_stage,
                    VkPipelineStageFlags                   dest_stage,
                    std::initializer_list<VkMemoryBarrier> memory_barriers,
                    std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>  image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::span<const event_handle>                events,
                    VkPipelineStageFlags                         source_stage,
                    VkPipelineStageFlags                         dest_stage,
                    std::span<const VkMemoryBarrier>             memory_barriers,
                    std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>        image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::span<const event_handle>               events,
                    VkPipelineStageFlags                        source_stage,
                    VkPipelineStageFlags                        dest_stage,
                    std::span<const VkMemoryBarrier>            memory_barriers,
                    std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                    std::initializer_list<VkImageMemoryBarrier> image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>    events,
                    VkPipelineStageFlags                   source_stage,
                    VkPipelineStageFlags                   dest_stage,
                    std::initializer_list<VkMemoryBarrier> memory_barriers,
                    std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>  image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>          events,
                    VkPipelineStageFlags                         source_stage,
                    VkPipelineStageFlags                         dest_stage,
                    std::span<const VkMemoryBarrier>             memory_barriers,
                    std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>        image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>         events,
                    VkPipelineStageFlags                        source_stage,
                    VkPipelineStageFlags                        dest_stage,
                    std::span<const VkMemoryBarrier>            memory_barriers,
                    std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                    std::initializer_list<VkImageMemoryBarrier> image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::span<const event_handle>                events,
                    VkPipelineStageFlags                         source_stage,
                    VkPipelineStageFlags                         dest_stage,
                    std::initializer_list<VkMemoryBarrier>       memory_barriers,
                    std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>        image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::span<const event_handle>               events,
                    VkPipelineStageFlags                        source_stage,
                    VkPipelineStageFlags                        dest_stage,
                    std::initializer_list<VkMemoryBarrier>      memory_barriers,
                    std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                    std::initializer_list<VkImageMemoryBarrier> image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::span<const event_handle>                events,
                    VkPipelineStageFlags                         source_stage,
                    VkPipelineStageFlags                         dest_stage,
                    std::span<const VkMemoryBarrier>             memory_barriers,
                    std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::initializer_list<VkImageMemoryBarrier>  image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>          events,
                    VkPipelineStageFlags                         source_stage,
                    VkPipelineStageFlags                         dest_stage,
                    std::initializer_list<VkMemoryBarrier>       memory_barriers,
                    std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::span<const VkImageMemoryBarrier>        image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>          events,
                    VkPipelineStageFlags                         source_stage,
                    VkPipelineStageFlags                         dest_stage,
                    std::span<const VkMemoryBarrier>             memory_barriers,
                    std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::initializer_list<VkImageMemoryBarrier>  image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>         events,
                    VkPipelineStageFlags                        source_stage,
                    VkPipelineStageFlags                        dest_stage,
                    std::initializer_list<VkMemoryBarrier>      memory_barriers,
                    std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                    std::initializer_list<VkImageMemoryBarrier> image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

    auto operator()(std::initializer_list<event_handle>          events,
                    VkPipelineStageFlags                         source_stage,
                    VkPipelineStageFlags                         dest_stage,
                    std::initializer_list<VkMemoryBarrier>       memory_barriers,
                    std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                    std::initializer_list<VkImageMemoryBarrier>  image_memory_barriers) const noexcept
    {
        return adaptor_closure{
            [=](flow f) mutable noexcept -> flow
            {
                fuyu::cmd::event::wait(
                    f.command_buffer(), events, source_stage, dest_stage, memory_barriers, buffer_memory_barriers, image_memory_barriers);
                return f;
            }};
    }

#if defined(VK_VERSION_1_3)
    auto operator()(std::span<const event_handle> events, std::span<const VkDependencyInfo> dependencies) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::wait(f.command_buffer(), events, dependencies);
                                   return f;
                               }};
    }

    auto operator()(std::initializer_list<event_handle> events, std::span<const VkDependencyInfo> dependencies) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::wait(f.command_buffer(), events, dependencies);
                                   return f;
                               }};
    }

    auto operator()(std::span<const event_handle> events, std::initializer_list<VkDependencyInfo> dependencies) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::wait(f.command_buffer(), events, dependencies);
                                   return f;
                               }};
    }

    auto operator()(std::initializer_list<event_handle> events, std::initializer_list<VkDependencyInfo> dependencies) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::wait(f.command_buffer(), events, dependencies);
                                   return f;
                               }};
    }

    auto operator()(event_handle events, VkDependencyInfo dependencies) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::event::wait(f.command_buffer(), events, dependencies);
                                   return f;
                               }};
    }

#endif // #if defined(VK_VERSION_1_3)
};

} // namespace fubuki::fuyu::command::pipe::detail::event

#endif // FUBUKI_FUYU_COMMAND_PIPE_EVENT_HPP
