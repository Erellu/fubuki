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

#include "extension/ext_discard_rectangles.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_discard_rectangles::cmd
{

#if defined(VK_EXT_discard_rectangles)

void set_discard_rectangle(const functions&          ext,
                           command_buffer_handle     command_buffer,
                           std::uint32_t             first_discard_rectangle,
                           std::span<const VkRect2D> discard_rectangles) noexcept
{
    return fubuki::invoke<"vkCmdSetDiscardRectangleEXT">(
        ext, command_buffer.vk, first_discard_rectangle, vk_size(discard_rectangles), discard_rectangles.data());
}

void set_discard_rectangle_enable(const functions& ext, command_buffer_handle command_buffer, VkBool32 discard_rectangle_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetDiscardRectangleEnableEXT">(ext, command_buffer.vk, discard_rectangle_enable);
}

void set_discard_rectangle_mode(const functions& ext, command_buffer_handle command_buffer, VkDiscardRectangleModeEXT discard_rectangle_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetDiscardRectangleModeEXT">(ext, command_buffer.vk, discard_rectangle_mode);
}

#endif // defined(VK_EXT_discard_rectangles)

} // namespace fubuki::extension::ext_discard_rectangles::cmd
