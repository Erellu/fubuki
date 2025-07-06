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

#ifndef FUBUKI_FUYU_COMMAND_EXECUTE_HPP
#define FUBUKI_FUYU_COMMAND_EXECUTE_HPP

#include <initializer_list>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

namespace command
{

/**
 * Execute secondary command buffers from a primary command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdExecuteCommands.html
 */
FUBUKI_FUYU_API void execute(command_buffer_view command_buffer, std::span<const command_buffer_handle> secondary) noexcept;

/**
 * Execute secondary command buffers from a primary command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdExecuteCommands.html
 */
inline void execute(command_buffer_view command_buffer, std::initializer_list<command_buffer_handle> secondary) noexcept
{
    return execute(command_buffer, std::span{secondary});
}

/**
 * Execute secondary command buffers from a primary command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdExecuteCommands.html
 */
inline void execute(command_buffer_view command_buffer, command_buffer_handle secondary) noexcept { return execute(command_buffer, {secondary}); }

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_EXECUTE_HPP
