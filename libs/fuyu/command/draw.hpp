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

#ifndef FUBUKI_FUYU_COMMAND_DRAW_HPP
#define FUBUKI_FUYU_COMMAND_DRAW_HPP

#include <cstdint>

#include <core/config/macros.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

/// Commands performing draw calls.
namespace command::draw
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Draw primitives.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDraw.html
 */
FUBUKI_FUYU_API
extern void call(command_buffer_view command_buffer,
                 std::uint32_t       vertex_count,
                 std::uint32_t       instance_count,
                 std::uint32_t       first_vertex,
                 std::uint32_t       first_instance) noexcept;

//------------------------------------------------------------------------------

/**
 * Draw primitives with indexed vertices.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexed.html
 */
FUBUKI_FUYU_API
extern void indexed(command_buffer_view command_buffer,
                    std::uint32_t       index_count,
                    std::uint32_t       instance_count,
                    std::uint32_t       first_index,
                    std::int32_t        vertex_offset,
                    std::uint32_t       first_instance) noexcept;

//------------------------------------------------------------------------------

/**
 * Draw primitives with indirect parameters and indexed vertices.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexedIndirect.html
 */
FUBUKI_FUYU_API
extern void indexed_indirect(
    command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, std::uint32_t draw_count, std::uint32_t stride) noexcept;

//------------------------------------------------------------------------------

/**
 * Draw primitives with indirect parameters.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndirect.html
 */
FUBUKI_FUYU_API
extern void
indirect(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, std::uint32_t draw_count, std::uint32_t stride) noexcept;

/********************************************************************************/
/*                                  VULKAN 1.2                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_2)

/**
 * Draw parameters with indirect parameters, indexed vertices, and draw count.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexedIndirectCount.html
 */
FUBUKI_FUYU_API
extern void indexed_indirect_count(command_buffer_view command_buffer,
                                   buffer_handle       buffer,
                                   VkDeviceSize        offset,
                                   buffer_handle       count_buffer,
                                   VkDeviceSize        count_offset,
                                   std::uint32_t       max_draw_count,
                                   std::uint32_t       stride) noexcept;

/**
 * Draw primitives with indirect parameters and draw count.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndirectCount.html
 */
FUBUKI_FUYU_API
extern void indirect_count(command_buffer_view command_buffer,
                           buffer_handle       buffer,
                           VkDeviceSize        offset,
                           buffer_handle       count_buffer,
                           VkDeviceSize        count_offset,
                           std::uint32_t       max_draw_count,
                           std::uint32_t       stride) noexcept;

#endif // defined(VK_VERSION_1_2)

} // namespace command::draw

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_DRAW_HPP
