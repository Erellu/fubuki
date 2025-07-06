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

#include "extension/khr_synchronization2.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::khr_synchronization2
{

#if defined(VK_KHR_synchronization2)

[[nodiscard]]
std::expected<void, api_call_info>
queue_submit2(const functions& ext, queue_handle queue, std::span<const VkSubmitInfo2> submits, fence_handle fence) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkQueueSubmit2KHR">(ext, queue.vk, vk_size(submits), submits.data(), fence.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::vector<VkCheckpointData2NV> get_queue_checkpoint_data2(const functions& ext, queue_handle queue)
{
    std::uint32_t count = 0;

    fubuki::invoke<"vkGetQueueCheckpointData2NV">(ext, queue.vk, &count, nullptr);

    std::vector<VkCheckpointData2NV> result;
    result.resize(count);

    fubuki::invoke<"vkGetQueueCheckpointData2NV">(ext, queue.vk, &count, result.data());

    return result;
}

#endif // defined(VK_KHR_synchronization2)

namespace cmd
{

#if defined(VK_KHR_synchronization2)

void set_event2(const functions& ext, command_buffer_handle command_buffer, event_handle event, const VkDependencyInfo& dependency_info) noexcept
{
    return fubuki::invoke<"vkCmdSetEvent2KHR">(ext, command_buffer.vk, event.vk, &dependency_info);
}

void reset_event2(const functions& ext, command_buffer_handle command_buffer, event_handle event, VkPipelineStageFlags2 stage_mask) noexcept
{
    return fubuki::invoke<"vkCmdResetEvent2KHR">(ext, command_buffer.vk, event.vk, stage_mask);
}

void wait_events2(const functions&                  ext,
                  command_buffer_handle             command_buffer,
                  std::span<const event_handle>     events,
                  std::span<const VkDependencyInfo> dependency_infos)
{
    fubuki_assert(events.size() == dependency_infos.size(), "Sizes must match");

    auto handles = collect<VkEvent>(events);

    return fubuki::invoke<"vkCmdWaitEvents2KHR">(ext, command_buffer.vk, vk_size(events), handles.data(), dependency_infos.data());
}

void pipeline_barrier2(const functions& ext, command_buffer_handle command_buffer, const VkDependencyInfo& dependency_info) noexcept
{
    return fubuki::invoke<"vkCmdPipelineBarrier2KHR">(ext, command_buffer.vk, &dependency_info);
}

void write_timestamp2(const functions&      ext,
                      command_buffer_handle command_buffer,
                      VkPipelineStageFlags2 stage,
                      query_pool_handle     query_pool,
                      std::uint32_t         query) noexcept
{
    return fubuki::invoke<"vkCmdWriteTimestamp2KHR">(ext, command_buffer.vk, stage, query_pool.vk, query);
}

void write_buffer_marker2(const functions&      ext,
                          command_buffer_handle command_buffer,
                          VkPipelineStageFlags2 stage,
                          buffer_handle         dst_buffer,
                          VkDeviceSize          dst_offset,
                          std::uint32_t         marker) noexcept
{
    return fubuki::invoke<"vkCmdWriteBufferMarker2AMD">(ext, command_buffer.vk, stage, dst_buffer.vk, dst_offset, marker);
}

#endif // defined(VK_KHR_synchronization2)

} // namespace cmd

} // namespace fubuki::extension::khr_synchronization2
