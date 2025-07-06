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

#ifndef FUBUKI_FUYU_COMMAND_COPY_HPP
#define FUBUKI_FUYU_COMMAND_COPY_HPP

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

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Copy data between buffer regions.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyBuffer.html
 */
FUBUKI_FUYU_API
extern void copy(command_buffer_view command_buffer, buffer_handle source, buffer_handle dest, std::span<const VkBufferCopy> regions) noexcept;

/**
 * Copies data between buffer regions.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyBuffer.html
 */
inline void copy(command_buffer_view command_buffer, buffer_handle source, buffer_handle dest, std::initializer_list<VkBufferCopy> regions) noexcept
{
    return copy(command_buffer, source, dest, std::span{regions});
}

/**
 * Copy data from a buffer into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyBufferToImage.html
 */
FUBUKI_FUYU_API
extern void copy(command_buffer_view                command_buffer,
                 buffer_handle                      source,
                 image_handle                       dest,
                 VkImageLayout                      image_layout,
                 std::span<const VkBufferImageCopy> regions) noexcept;

/**
 * Copy data from a buffer into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyBufferToImage.html
 */
inline void copy(command_buffer_view                      command_buffer,
                 buffer_handle                            source,
                 image_handle                             dest,
                 VkImageLayout                            image_layout,
                 std::initializer_list<VkBufferImageCopy> regions) noexcept
{
    return copy(command_buffer, source, dest, image_layout, std::span{regions});
}

/**
 * Copy image data into a buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyImageToBuffer.html
 */
FUBUKI_FUYU_API
extern void copy(command_buffer_view                command_buffer,
                 image_handle                       source,
                 VkImageLayout                      image_layout,
                 buffer_handle                      dest,
                 std::span<const VkBufferImageCopy> regions) noexcept;

/**
 * Copy image data into a buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyImageToBuffer.html
 */
inline void copy(command_buffer_view                      command_buffer,
                 image_handle                             source,
                 VkImageLayout                            image_layout,
                 buffer_handle                            dest,
                 std::initializer_list<VkBufferImageCopy> regions) noexcept
{
    return copy(command_buffer, source, image_layout, dest, std::span{regions});
}

/**
 * Copy data between images.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyImage.html
 */
FUBUKI_FUYU_API
extern void copy(command_buffer_view          command_buffer,
                 image_handle                 source,
                 VkImageLayout                source_layout,
                 image_handle                 dest,
                 VkImageLayout                destination_layout,
                 std::span<const VkImageCopy> regions) noexcept;

/**
 * Copy data between images.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyImage.html
 */
inline void copy(command_buffer_view                command_buffer,
                 image_handle                       source,
                 VkImageLayout                      source_layout,
                 image_handle                       dest,
                 VkImageLayout                      destination_layout,
                 std::initializer_list<VkImageCopy> regions) noexcept
{
    return copy(command_buffer, source, source_layout, dest, destination_layout, std::span{regions});
}

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_COPY_HPP
