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

#include "extension/ext_transform_feedback.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>
#include <core/pfn.hpp>
#include <core/vulkan.hpp>

namespace fubuki::extension::ext_transform_feedback::cmd
{

#if defined(VK_EXT_transform_feedback)

void bind_transform_feedback_buffers(const functions&               ext,
                                     command_buffer_handle          command_buffer,
                                     std::uint32_t                  first_binding,
                                     std::span<const buffer_handle> buffers,
                                     std::span<const VkDeviceSize>  offsets,
                                     std::span<const VkDeviceSize>  sizes) noexcept
{
    fubuki_assert(buffers.size() == offsets.size() and buffers.size() == sizes.size(), "Invalid argument. Sizes must match");

    auto buffers_handles = collect<VkBuffer>(buffers);

    return fubuki::invoke<"vkCmdBindTransformFeedbackBuffersEXT">(
        ext, command_buffer.vk, first_binding, vk_size(buffers_handles), buffers_handles.data(), offsets.data(), sizes.data());
}

void begin_transform_feedback(const functions&               ext,
                              command_buffer_handle          command_buffer,
                              std::uint32_t                  first_counter_buffer,
                              std::span<const buffer_handle> counter_buffers,
                              std::span<const VkDeviceSize>  offsets) noexcept
{
    fubuki_assert(counter_buffers.size() == offsets.size(), "Invalid argument. Sizes must match");

    auto buffers_handles = collect<VkBuffer>(counter_buffers);

    return fubuki::invoke<"vkCmdBeginTransformFeedbackEXT">(
        ext, command_buffer.vk, first_counter_buffer, vk_size(buffers_handles), buffers_handles.data(), offsets.data());
}

void end_transform_feedback(const functions&               ext,
                            command_buffer_handle          command_buffer,
                            std::uint32_t                  first_counter_buffer,
                            std::span<const buffer_handle> counter_buffers,
                            std::span<const VkDeviceSize>  offsets) noexcept
{
    fubuki_assert(counter_buffers.size() == offsets.size(), "Invalid argument. Sizes must match");

    auto buffers_handles = collect<VkBuffer>(counter_buffers);

    return fubuki::invoke<"vkCmdEndTransformFeedbackEXT">(
        ext, command_buffer.vk, first_counter_buffer, vk_size(buffers_handles), buffers_handles.data(), offsets.data());
}

void begin_query_indexed(const functions&      ext,
                         command_buffer_handle command_buffer,
                         query_pool_handle     query_pool,
                         std::uint32_t         query,
                         VkQueryControlFlags   flags,
                         std::uint32_t         index) noexcept
{
    return fubuki::invoke<"vkCmdBeginQueryIndexedEXT">(ext, command_buffer.vk, query_pool.vk, query, flags, index);
}

void end_query_indexed(
    const functions& ext, command_buffer_handle command_buffer, query_pool_handle query_pool, std::uint32_t query, std::uint32_t index)
{
    return fubuki::invoke<"vkCmdEndQueryIndexedEXT">(ext, command_buffer.vk, query_pool.vk, query, index);
}

void draw_indirect_byte_count(const functions&      ext,
                              command_buffer_handle command_buffer,
                              std::uint32_t         instance_count,
                              std::uint32_t         first_instance,
                              buffer_handle         counter_buffer,
                              VkDeviceSize          counter_buffer_offset,
                              std::uint32_t         counter_offset,
                              std::uint32_t         vertex_stride) noexcept
{
    return fubuki::invoke<"vkCmdDrawIndirectByteCountEXT">(
        ext, command_buffer.vk, instance_count, first_instance, counter_buffer.vk, counter_buffer_offset, counter_offset, vertex_stride);
}

#endif // defined(VK_EXT_transform_feedback)

} // namespace fubuki::extension::ext_transform_feedback::cmd
