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

#include "extension/nv_copy_memory_indirect.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::nv_copy_memory_indirect::cmd
{

#if defined(VK_NV_copy_memory_indirect)

void copy_memory_indirect(const functions&      ext,
                          command_buffer_handle command_buffer,
                          VkDeviceAddress       copy_buffer_address,
                          std::uint32_t         copy_count,
                          std::uint32_t         stride) noexcept
{
    return fubuki::invoke<"vkCmdCopyMemoryIndirectNV">(ext, command_buffer.vk, copy_buffer_address, copy_count, stride);
}

void copy_memory_to_image_indirect(const functions&                          ext,
                                   command_buffer_handle                     command_buffer,
                                   VkDeviceAddress                           copy_buffer_address,
                                   std::uint32_t                             stride,
                                   image_handle                              dst_image,
                                   VkImageLayout                             dst_image_layout,
                                   std::span<const VkImageSubresourceLayers> image_subresources) noexcept
{
    return fubuki::invoke<"vkCmdCopyMemoryToImageIndirectNV">(
        ext, command_buffer.vk, copy_buffer_address, vk_size(image_subresources), stride, dst_image.vk, dst_image_layout, image_subresources.data());
}

#endif // defined(VK_NV_copy_memory_indirect)

} // namespace fubuki::extension::nv_copy_memory_indirect::cmd
