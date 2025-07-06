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

#ifndef FUBUKI_FUYU_COMMAND_MANIPULATION_HPP
#define FUBUKI_FUYU_COMMAND_MANIPULATION_HPP

#include <cstdint>
#include <span>

#include <core/as_span.hpp>
#include <core/collect.hpp>
#include <core/config/macros.hpp>
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
 * Fill a region of a buffer with a fixed value.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdFillBuffer.html
 */
FUBUKI_FUYU_API
extern void fill(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, VkDeviceSize size, std::uint32_t data) noexcept;

//------------------------------------------------------------------------------

/**
 * Update a buffer's contents from host memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdUpdateBuffer.html
 */
FUBUKI_FUYU_API
extern void update(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, VkDeviceSize size, const void* data) noexcept;

//------------------------------------------------------------------------------

/**
 * Updat a buffer's contents from host memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdUpdateBuffer.html
 */
inline void update(command_buffer_view command_buffer, buffer_handle buffer, const VkDeviceSize offset, std::span<const std::byte> data) noexcept
{
    return update(command_buffer, buffer, offset, device_size(data), data.data());
}

//------------------------------------------------------------------------------

/**
 * Copy regions of an image, potentially performing format conversion.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBlitImage.html
 */
FUBUKI_FUYU_API
extern void blit(command_buffer_view          command_buffer,
                 image_handle                 source,
                 VkImageLayout                source_layout,
                 image_handle                 dest,
                 VkImageLayout                dest_layout,
                 std::span<const VkImageBlit> regions,
                 VkFilter                     filter) noexcept;

/**
 * Copy regions of an image, potentially performing format conversion.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBlitImage.html
 */
inline void blit(command_buffer_view                command_buffer,
                 image_handle                       source,
                 VkImageLayout                      source_layout,
                 image_handle                       dest,
                 VkImageLayout                      dest_layout,
                 std::initializer_list<VkImageBlit> regions,
                 VkFilter                           filter) noexcept
{
    return blit(command_buffer, source, source_layout, dest, dest_layout, std::span{regions}, filter);
}

//------------------------------------------------------------------------------

/**
 * Resolve regions of an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResolveImage.html
 */
FUBUKI_FUYU_API
extern void resolve(command_buffer_view             command_buffer,
                    image_handle                    source,
                    VkImageLayout                   source_layout,
                    image_handle                    dest,
                    VkImageLayout                   dest_layout,
                    std::span<const VkImageResolve> regions) noexcept;

/**
 * Resolve regions of an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResolveImage.html
 */
inline void resolve(command_buffer_view                   command_buffer,
                    image_handle                          source,
                    VkImageLayout                         source_layout,
                    image_handle                          dest,
                    VkImageLayout                         dest_layout,
                    std::initializer_list<VkImageResolve> regions)
{
    return resolve(command_buffer, source, source_layout, dest, dest_layout, std::span{regions});
}

//------------------------------------------------------------------------------

/**
 * Clear regions of a colour image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdClearColorImage.html
 */
FUBUKI_FUYU_API
extern void clear(command_buffer_view                      command_buffer,
                  image_handle                             image,
                  VkImageLayout                            image_layout,
                  const VkClearColorValue&                 colour,
                  std::span<const VkImageSubresourceRange> ranges) noexcept;

/**
 * Clear regions of a colour image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdClearColorImage.html
 */
inline void clear(command_buffer_view                            command_buffer,
                  image_handle                                   image,
                  VkImageLayout                                  image_layout,
                  const VkClearColorValue&                       colour,
                  std::initializer_list<VkImageSubresourceRange> ranges) noexcept
{
    return clear(command_buffer, image, image_layout, colour, std::span{ranges});
}

/**
 * Clear regions of a colour image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdClearColorImage.html
 */
inline void clear(command_buffer_view            command_buffer,
                  image_handle                   image,
                  VkImageLayout                  image_layout,
                  const VkClearColorValue&       colour,
                  const VkImageSubresourceRange& range) noexcept
{
    return clear(command_buffer, image, image_layout, colour, fubuki::as_span(range));
}

//------------------------------------------------------------------------------

/**
 * Fill regions of a combined depth/stencil image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdClearDepthStencilImage.html
 */
FUBUKI_FUYU_API
extern void clear(command_buffer_view                      command_buffer,
                  image_handle                             image,
                  VkImageLayout                            image_layout,
                  const VkClearDepthStencilValue&          depth_stencil,
                  std::span<const VkImageSubresourceRange> ranges) noexcept;

/**
 * Fill regions of a combined depth/stencil image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdClearDepthStencilImage.html
 */
inline void clear(command_buffer_view                            command_buffer,
                  image_handle                                   image,
                  VkImageLayout                                  image_layout,
                  const VkClearDepthStencilValue&                depth_stencil,
                  std::initializer_list<VkImageSubresourceRange> ranges) noexcept
{
    return clear(command_buffer, image, image_layout, depth_stencil, std::span{ranges});
}

/**
 * Fill regions of a combined depth/stencil image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdClearDepthStencilImage.html
 */
inline void clear(command_buffer_view             command_buffer,
                  image_handle                    image,
                  VkImageLayout                   image_layout,
                  const VkClearDepthStencilValue& depth_stencil,
                  const VkImageSubresourceRange&  range) noexcept
{
    return clear(command_buffer, image, image_layout, depth_stencil, fubuki::as_span(range));
}

//------------------------------------------------------------------------------

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_MANIPULATION_HPP
