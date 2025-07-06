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

#include "fuyu/command/event.hpp"

#include <core/collect.hpp>

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command::event
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

void reset(command_buffer_view command_buffer, event_handle event, VkPipelineStageFlags stage_mask) noexcept
{
    return fuyu::invoke<"vkCmdResetEvent">(command_buffer, event.vk, stage_mask);
}

void set(command_buffer_view command_buffer, event_handle event, VkPipelineStageFlags stage_mask) noexcept
{
    return fuyu::invoke<"vkCmdSetEvent">(command_buffer, event.vk, stage_mask);
}

void wait(command_buffer_view                    command_buffer,
          std::span<const event_handle>          events,
          VkPipelineStageFlags                   source_stage,
          VkPipelineStageFlags                   dest_stage,
          std::span<const VkMemoryBarrier>       memory_barriers,
          std::span<const VkBufferMemoryBarrier> buffer_memory_barriers,
          std::span<const VkImageMemoryBarrier>  image_memory_barriers)
{
    const auto events_handles                 = collect<VkEvent>(events);
    const auto memory_barriers_handles        = collect<VkMemoryBarrier>(memory_barriers);
    const auto buffer_memory_barriers_handles = collect<VkBufferMemoryBarrier>(buffer_memory_barriers);
    const auto image_memory_barriers_handles  = collect<VkImageMemoryBarrier>(image_memory_barriers);

    return fuyu::invoke<"vkCmdWaitEvents">(command_buffer,
                                           vk_size(events),
                                           events_handles.data(),
                                           source_stage,
                                           dest_stage,
                                           vk_size(memory_barriers_handles),
                                           memory_barriers_handles.empty() ? nullptr : memory_barriers_handles.data(),
                                           vk_size(buffer_memory_barriers_handles),
                                           buffer_memory_barriers_handles.empty() ? nullptr : buffer_memory_barriers_handles.data(),
                                           vk_size(image_memory_barriers_handles),
                                           image_memory_barriers_handles.empty() ? nullptr : image_memory_barriers_handles.data());
}

/********************************************************************************/
/*                                  VULKAN 1.3                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_3)

void reset(command_buffer_view command_buffer, event_handle event, VkPipelineStageFlags2 stage_mask) noexcept
{
    return fuyu::invoke<"vkCmdResetEvent2">(command_buffer, event.vk, stage_mask);
}

void set(command_buffer_view command_buffer, event_handle event, const VkDependencyInfo& dependency) noexcept
{
    return fuyu::invoke<"vkCmdSetEvent2">(command_buffer, event.vk, &dependency);
}

void wait(command_buffer_view command_buffer, std::span<const event_handle> events, std::span<const VkDependencyInfo> dependencies)
{
    const auto events_handles       = collect<VkEvent>(events);
    const auto dependencies_handles = collect<VkDependencyInfo>(dependencies);

    return fuyu::invoke<"vkCmdWaitEvents2">(command_buffer, vk_size(events_handles), events_handles.data(), dependencies_handles.data());
}

#endif // defined(VK_VERSION_1_3)

} // namespace fubuki::fuyu::command::event
