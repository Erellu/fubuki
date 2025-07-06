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

#ifndef FUBUKI_FUYU_COMMAND_EVENT_HPP
#define FUBUKI_FUYU_COMMAND_EVENT_HPP

#include <initializer_list>
#include <span>

#include <core/as_span.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

/// Commands related to event states.
namespace command::event
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Reset an event object to non-signaled state.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResetEvent.html
 */
FUBUKI_FUYU_API
extern void reset(command_buffer_view command_buffer, event_handle event, VkPipelineStageFlags stage_mask) noexcept;

/**
 * Set an event object to signaled state.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetEvent.html
 */
FUBUKI_FUYU_API
extern void set(command_buffer_view command_buffer, event_handle event, VkPipelineStageFlags stage_mask) noexcept;

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
FUBUKI_FUYU_API
extern void wait(command_buffer_view                    command_buffer,
                 std::span<const event_handle>          events,
                 VkPipelineStageFlags                   source_stage,
                 VkPipelineStageFlags                   dest_stage,
                 std::span<const VkMemoryBarrier>       memory_barriers,
                 std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>  image_memory_barriers);

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                    command_buffer,
                 std::initializer_list<event_handle>    events,
                 VkPipelineStageFlags                   source_stage,
                 VkPipelineStageFlags                   dest_stage,
                 std::span<const VkMemoryBarrier>       memory_barriers,
                 std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>  image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                    command_buffer,
                 std::span<const event_handle>          events,
                 VkPipelineStageFlags                   source_stage,
                 VkPipelineStageFlags                   dest_stage,
                 std::initializer_list<VkMemoryBarrier> memory_barriers,
                 std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>  image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                          command_buffer,
                 std::span<const event_handle>                events,
                 VkPipelineStageFlags                         source_stage,
                 VkPipelineStageFlags                         dest_stage,
                 std::span<const VkMemoryBarrier>             memory_barriers,
                 std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>        image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                         command_buffer,
                 std::span<const event_handle>               events,
                 VkPipelineStageFlags                        source_stage,
                 VkPipelineStageFlags                        dest_stage,
                 std::span<const VkMemoryBarrier>            memory_barriers,
                 std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                 std::initializer_list<VkImageMemoryBarrier> image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                    command_buffer,
                 std::initializer_list<event_handle>    events,
                 VkPipelineStageFlags                   source_stage,
                 VkPipelineStageFlags                   dest_stage,
                 std::initializer_list<VkMemoryBarrier> memory_barriers,
                 std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>  image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                          command_buffer,
                 std::initializer_list<event_handle>          events,
                 VkPipelineStageFlags                         source_stage,
                 VkPipelineStageFlags                         dest_stage,
                 std::span<const VkMemoryBarrier>             memory_barriers,
                 std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>        image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                         command_buffer,
                 std::initializer_list<event_handle>         events,
                 VkPipelineStageFlags                        source_stage,
                 VkPipelineStageFlags                        dest_stage,
                 std::span<const VkMemoryBarrier>            memory_barriers,
                 std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                 std::initializer_list<VkImageMemoryBarrier> image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                          command_buffer,
                 std::span<const event_handle>                events,
                 VkPipelineStageFlags                         source_stage,
                 VkPipelineStageFlags                         dest_stage,
                 std::initializer_list<VkMemoryBarrier>       memory_barriers,
                 std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>        image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                         command_buffer,
                 std::span<const event_handle>               events,
                 VkPipelineStageFlags                        source_stage,
                 VkPipelineStageFlags                        dest_stage,
                 std::initializer_list<VkMemoryBarrier>      memory_barriers,
                 std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                 std::initializer_list<VkImageMemoryBarrier> image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                          command_buffer,
                 std::span<const event_handle>                events,
                 VkPipelineStageFlags                         source_stage,
                 VkPipelineStageFlags                         dest_stage,
                 std::span<const VkMemoryBarrier>             memory_barriers,
                 std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::initializer_list<VkImageMemoryBarrier>  image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                          command_buffer,
                 std::initializer_list<event_handle>          events,
                 VkPipelineStageFlags                         source_stage,
                 VkPipelineStageFlags                         dest_stage,
                 std::initializer_list<VkMemoryBarrier>       memory_barriers,
                 std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::span<const VkImageMemoryBarrier>        image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                          command_buffer,
                 std::initializer_list<event_handle>          events,
                 VkPipelineStageFlags                         source_stage,
                 VkPipelineStageFlags                         dest_stage,
                 std::span<const VkMemoryBarrier>             memory_barriers,
                 std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::initializer_list<VkImageMemoryBarrier>  image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                         command_buffer,
                 std::initializer_list<event_handle>         events,
                 VkPipelineStageFlags                        source_stage,
                 VkPipelineStageFlags                        dest_stage,
                 std::initializer_list<VkMemoryBarrier>      memory_barriers,
                 std::span<const VkBufferMemoryBarrier>      buffer_memory_barriers,
                 std::initializer_list<VkImageMemoryBarrier> image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/**
 * Wait for one or more events and insert a set of memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html.
 */
inline void wait(command_buffer_view                          command_buffer,
                 std::initializer_list<event_handle>          events,
                 VkPipelineStageFlags                         source_stage,
                 VkPipelineStageFlags                         dest_stage,
                 std::initializer_list<VkMemoryBarrier>       memory_barriers,
                 std::initializer_list<VkBufferMemoryBarrier> buffer_memory_barriers,
                 std::initializer_list<VkImageMemoryBarrier>  image_memory_barriers)
{
    return wait(command_buffer,
                std::span{events},
                source_stage,
                dest_stage,
                std::span{memory_barriers},
                std::span{buffer_memory_barriers},
                std::span{image_memory_barriers});
}

/********************************************************************************/
/*                                  VULKAN 1.3                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_3)

/**
 * Reset an event object to non-signaled state.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResetEvent2KHR.html
 */
FUBUKI_FUYU_API void reset(command_buffer_view command_buffer, event_handle event, VkPipelineStageFlags2 stage_mask) noexcept;

/**
 * Reset an event object to non-signaled state.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetEvent2KHR.html
 */
FUBUKI_FUYU_API
extern void set(command_buffer_view command_buffer, event_handle event, const VkDependencyInfo& dependency) noexcept;

/**
 * Wait for one or more events.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents2KHR.html
 */
FUBUKI_FUYU_API
extern void wait(command_buffer_view command_buffer, std::span<const event_handle> events, std::span<const VkDependencyInfo> dependencies);

/**
 * Wait for one or more events.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents2KHR.html
 */
inline void wait(command_buffer_view command_buffer, std::initializer_list<event_handle> events, std::span<const VkDependencyInfo> dependencies)
{
    return wait(command_buffer, std::span{events}, dependencies);
}

/**
 * Wait for one event.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents2KHR.html
 */
inline void wait(command_buffer_view command_buffer, event_handle event, const VkDependencyInfo& dependency)
{
    return wait(command_buffer, fubuki::as_span(event), fubuki::as_span(dependency));
}

/**
 * Wait for one or more events.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents2KHR.html
 */
inline void wait(command_buffer_view command_buffer, std::span<const event_handle> events, std::initializer_list<VkDependencyInfo> dependencies)
{
    return wait(command_buffer, events, std::span{dependencies});
}

/**
 * Wait for one or more events.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents2KHR.html
 */
inline void wait(command_buffer_view command_buffer, std::initializer_list<event_handle> events, std::initializer_list<VkDependencyInfo> dependencies)
{
    return wait(command_buffer, std::span{events}, std::span{dependencies});
}
#endif // defined(VK_VERSION_1_3)

} // namespace command::event

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_EVENT_HPP
