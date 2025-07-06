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

#include "fuyu/command/copy.hpp"

#include <core/collect.hpp>

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command
{

void copy(command_buffer_view command_buffer, buffer_handle source, buffer_handle dest, std::span<const VkBufferCopy> regions) noexcept
{
    return fuyu::invoke<"vkCmdCopyBuffer">(command_buffer, source.vk, dest.vk, vk_size(regions), regions.data());
}

//------------------------------------------------------------------------------

void copy(command_buffer_view                command_buffer,
          buffer_handle                      source,
          image_handle                       dest,
          VkImageLayout                      image_layout,
          std::span<const VkBufferImageCopy> regions) noexcept

{
    return fuyu::invoke<"vkCmdCopyBufferToImage">(command_buffer, source.vk, dest.vk, image_layout, vk_size(regions), regions.data());
}

//------------------------------------------------------------------------------

void copy(command_buffer_view                command_buffer,
          image_handle                       source,
          VkImageLayout                      image_layout,
          buffer_handle                      dest,
          std::span<const VkBufferImageCopy> regions) noexcept
{
    return fuyu::invoke<"vkCmdCopyImageToBuffer">(command_buffer, source.vk, image_layout, dest.vk, vk_size(regions), regions.data());
}
//------------------------------------------------------------------------------

void copy(command_buffer_view                command_buffer,
          image_handle                       source,
          VkImageLayout                      source_layout,
          image_handle                       dest,
          VkImageLayout                      destination_layout,
          const std::span<const VkImageCopy> regions) noexcept
{
    return fuyu::invoke<"vkCmdCopyImage">(command_buffer, source.vk, source_layout, dest.vk, destination_layout, vk_size(regions), regions.data());
}

} // namespace fubuki::fuyu::command
