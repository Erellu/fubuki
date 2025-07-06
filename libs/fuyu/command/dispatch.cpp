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

#include "fuyu/command/dispatch.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command::dispatch
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

void direct(command_buffer_view command_buffer, std::uint32_t group_count_x, std::uint32_t group_count_y, std::uint32_t group_count_z) noexcept
{
    return fuyu::invoke<"vkCmdDispatch">(command_buffer, group_count_x, group_count_y, group_count_z);
}

void indirect(command_buffer_view command_buffer, buffer_handle buffer, const VkDeviceSize offset) noexcept
{
    return fuyu::invoke<"vkCmdDispatchIndirect">(command_buffer, buffer.vk, offset);
}

/********************************************************************************/
/*                                  VULKAN 1.1                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_1)

void base(command_buffer_view command_buffer,
          std::uint32_t       base_group_x,
          std::uint32_t       base_group_y,
          std::uint32_t       base_group_z,
          std::uint32_t       group_count_x,
          std::uint32_t       group_count_y,
          std::uint32_t       group_count_z) noexcept
{
    return fuyu::invoke<"vkCmdDispatchBase">(command_buffer, base_group_x, base_group_y, base_group_z, group_count_x, group_count_y, group_count_z);
}

#endif // defined(VK_VERSION_1_1)

} // namespace fubuki::fuyu::command::dispatch
