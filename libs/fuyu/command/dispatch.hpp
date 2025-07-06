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

#ifndef FUBUKI_FUYU_COMMAND_DISPATCH_HPP
#define FUBUKI_FUYU_COMMAND_DISPATCH_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

/// Dispatch commands for compute pipelines.
namespace command::dispatch
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Dispatch compute work items.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatch.html
 */
FUBUKI_FUYU_API
extern void
direct(command_buffer_view command_buffer, std::uint32_t group_count_x, std::uint32_t group_count_y, std::uint32_t group_count_z) noexcept;

/**
 * Dispatch compute work items with indirect parameters.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchIndirect.html
 */
FUBUKI_FUYU_API
extern void indirect(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset) noexcept;

/********************************************************************************/
/*                                  VULKAN 1.1                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_1)

/**
 * Dispatch compute work items with non-zero base values for the workgroup IDs.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchBase.html
 */
FUBUKI_FUYU_API
extern void base(command_buffer_view command_buffer,
                 std::uint32_t       base_group_x,
                 std::uint32_t       base_group_y,
                 std::uint32_t       base_group_z,
                 std::uint32_t       group_count_x,
                 std::uint32_t       group_count_y,
                 std::uint32_t       group_count_z) noexcept;

#endif // defined(VK_VERSION_1_1)

} // namespace command::dispatch

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_DISPATCH_HPP
