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

#include <memory>

#include "fuyu/command/render.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command
{

namespace detail
{

void begin_render_pass(const command_buffer_view command_buffer, const VkRenderPassBeginInfo& target, const VkSubpassContents contents) noexcept
{
    return fuyu::invoke<"vkCmdBeginRenderPass">(command_buffer, std::addressof(target), contents);
}

#if defined(VK_VERSION_1_3)
void begin_rendering(command_buffer_view command_buffer, const VkRenderingInfo& target)
{
    return fuyu::invoke<"vkCmdBeginRendering">(command_buffer, std::addressof(target));
}
#endif // defined(VK_VERSION_1_3)

} // namespace detail

void end_render_pass(const command_buffer_view command_buffer) noexcept { return fuyu::invoke<"vkCmdEndRenderPass">(command_buffer); }

void next_subpass(const command_buffer_view command_buffer, const VkSubpassContents contents) noexcept
{
    return fuyu::invoke<"vkCmdNextSubpass">(command_buffer, contents);
}

#if defined(VK_VERSION_1_3)
void end_rendering(command_buffer_view command_buffer) { return fuyu::invoke<"vkCmdEndRendering">(command_buffer); }
#endif // defined(VK_VERSION_1_3)

} // namespace fubuki::fuyu::command
