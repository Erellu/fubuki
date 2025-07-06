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

#include "fuyu/command/manipulation.hpp"

#include <core/collect.hpp>

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command
{

void fill(
    command_buffer_view command_buffer, buffer_handle buffer, const VkDeviceSize offset, const VkDeviceSize size, const std::uint32_t data) noexcept
{
    return fuyu::invoke<"vkCmdFillBuffer">(command_buffer, buffer.vk, offset, size, data);
}

void update(command_buffer_view command_buffer, buffer_handle buffer, const VkDeviceSize offset, const VkDeviceSize size, const void* data) noexcept
{
    return fuyu::invoke<"vkCmdUpdateBuffer">(command_buffer, buffer.vk, offset, size, data);
}

void blit(command_buffer_view          command_buffer,
          image_handle                 source,
          VkImageLayout                source_layout,
          image_handle                 dest,
          VkImageLayout                dest_layout,
          std::span<const VkImageBlit> regions,
          VkFilter                     filter) noexcept
{
    return fuyu::invoke<"vkCmdBlitImage">(command_buffer, source.vk, source_layout, dest.vk, dest_layout, vk_size(regions), regions.data(), filter);
}

void resolve(command_buffer_view             command_buffer,
             image_handle                    source,
             VkImageLayout                   source_layout,
             image_handle                    dest,
             VkImageLayout                   dest_layout,
             std::span<const VkImageResolve> regions) noexcept
{
    return fuyu::invoke<"vkCmdResolveImage">(command_buffer, source.vk, source_layout, dest.vk, dest_layout, vk_size(regions), regions.data());
}

void clear(command_buffer_view                      command_buffer,
           image_handle                             image,
           VkImageLayout                            image_layout,
           const VkClearColorValue&                 colour,
           std::span<const VkImageSubresourceRange> ranges) noexcept
{
    return fuyu::invoke<"vkCmdClearColorImage">(command_buffer, image.vk, image_layout, std::addressof(colour), vk_size(ranges), ranges.data());
}

void clear(command_buffer_view                      command_buffer,
           image_handle                             image,
           VkImageLayout                            image_layout,
           const VkClearDepthStencilValue&          depth_stencil,
           std::span<const VkImageSubresourceRange> ranges) noexcept
{
    return fuyu::invoke<"vkCmdClearDepthStencilImage">(
        command_buffer, image.vk, image_layout, std::addressof(depth_stencil), vk_size(ranges), ranges.data());
}

} // namespace fubuki::fuyu::command
