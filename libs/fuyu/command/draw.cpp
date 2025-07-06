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

#include "fuyu/command/draw.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command::draw
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

void call(command_buffer_view command_buffer,
          std::uint32_t       vertex_count,
          std::uint32_t       instance_count,
          std::uint32_t       first_vertex,
          std::uint32_t       first_instance) noexcept
{
    return fuyu::invoke<"vkCmdDraw">(command_buffer, vertex_count, instance_count, first_vertex, first_instance);
}

void indexed(command_buffer_view command_buffer,
             std::uint32_t       index_count,
             std::uint32_t       instance_count,
             std::uint32_t       first_index,
             std::int32_t        vertex_offset,
             std::uint32_t       first_instance) noexcept
{
    return fuyu::invoke<"vkCmdDrawIndexed">(command_buffer, index_count, instance_count, first_index, vertex_offset, first_instance);
}

void indexed_indirect(command_buffer_view command_buffer,
                      buffer_handle       buffer,
                      const VkDeviceSize  offset,
                      const std::uint32_t draw_count,
                      const std::uint32_t stride) noexcept
{
    return fuyu::invoke<"vkCmdDrawIndexedIndirect">(command_buffer, buffer.vk, offset, draw_count, stride);
}

void indirect(command_buffer_view command_buffer,
              buffer_handle       buffer,
              const VkDeviceSize  offset,
              const std::uint32_t draw_count,
              const std::uint32_t stride) noexcept
{
    return fuyu::invoke<"vkCmdDrawIndirect">(command_buffer, buffer.vk, offset, draw_count, stride);
}

/********************************************************************************/
/*                                  VULKAN 1.2                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_2)

void indexed_indirect_count(command_buffer_view command_buffer,
                            buffer_handle       buffer,
                            const VkDeviceSize  offset,
                            buffer_handle       count_buffer,
                            const VkDeviceSize  count_offset,
                            const std::uint32_t max_draw_count,
                            const std::uint32_t stride) noexcept
{
    return fuyu::invoke<"vkCmdDrawIndexedIndirectCount">(command_buffer, buffer.vk, offset, count_buffer.vk, count_offset, max_draw_count, stride);
}

void indirect_count(command_buffer_view command_buffer,
                    buffer_handle       buffer,
                    const VkDeviceSize  offset,
                    buffer_handle       count_buffer,
                    const VkDeviceSize  count_offset,
                    const std::uint32_t max_draw_count,
                    const std::uint32_t stride) noexcept
{
    return fuyu::invoke<"vkCmdDrawIndirectCount">(command_buffer, buffer.vk, offset, count_buffer.vk, count_offset, max_draw_count, stride);
}

#endif // defined(VK_VERSION_1_2)

} // namespace fubuki::fuyu::command::draw
