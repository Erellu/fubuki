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

#ifndef FUBUKI_EXTENSION_KHR_SYNCHRONIZATION2_HPP
#define FUBUKI_EXTENSION_KHR_SYNCHRONIZATION2_HPP

#include <initializer_list>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_synchronization2.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_synchronization2
{

#if defined(VK_KHR_synchronization2)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
queue_submit2(const functions& ext, queue_handle queue, std::span<const VkSubmitInfo2> submits, fence_handle fence = null_handle) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit2KHR.html
[[nodiscard]] inline auto
queue_submit2(const functions& ext, queue_handle queue, std::initializer_list<VkSubmitInfo2> submits, fence_handle fence = null_handle) noexcept
{
    return queue_submit2(ext, queue, std::span{submits}, fence);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetQueueCheckpointData2NV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::vector<VkCheckpointData2NV> get_queue_checkpoint_data2(const functions& ext, queue_handle queue);

#endif // defined(VK_KHR_synchronization2)

namespace cmd
{

#if defined(VK_KHR_synchronization2)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetEvent2KHR.html
FUBUKI_EXTENSION_API
void set_event2(const functions& ext, command_buffer_handle command_buffer, event_handle event, const VkDependencyInfo& dependency_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResetEvent2KHR.html
FUBUKI_EXTENSION_API
void reset_event2(const functions& ext, command_buffer_handle command_buffer, event_handle event, VkPipelineStageFlags2 stage_mask) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents2KHR.html
FUBUKI_EXTENSION_API
void wait_events2(const functions&                  ext,
                  command_buffer_handle             command_buffer,
                  std::span<const event_handle>     events,
                  std::span<const VkDependencyInfo> dependency_infos);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier2KHR.html
FUBUKI_EXTENSION_API
void pipeline_barrier2(const functions& ext, command_buffer_handle command_buffer, const VkDependencyInfo& dependency_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteTimestamp2KHR.html
FUBUKI_EXTENSION_API
void write_timestamp2(const functions&      ext,
                      command_buffer_handle command_buffer,
                      VkPipelineStageFlags2 stage,
                      query_pool_handle     query_pool,
                      std::uint32_t         query) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteBufferMarker2AMD.html
FUBUKI_EXTENSION_API
void write_buffer_marker2(const functions&      ext,
                          command_buffer_handle command_buffer,
                          VkPipelineStageFlags2 stage,
                          buffer_handle         dst_buffer,
                          VkDeviceSize          dst_offset,
                          std::uint32_t         marker) noexcept;

#endif // defined(VK_KHR_synchronization2)

} // namespace cmd

} // namespace fubuki::extension::khr_synchronization2

#endif // FUBUKI_EXTENSION_KHR_SYNCHRONIZATION2_HPP
