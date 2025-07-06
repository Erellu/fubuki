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

#include "extension/khr_copy_commands2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_copy_commands2::cmd
{

#if defined(VK_KHR_copy_commands2)

void copy_buffer2(const functions& ext, command_buffer_handle command_buffer, const VkCopyBufferInfo2& copy_buffer_info) noexcept
{
    return fubuki::invoke<"vkCmdCopyBuffer2KHR">(ext, command_buffer.vk, &copy_buffer_info);
}

void copy_image2(const functions& ext, command_buffer_handle command_buffer, const VkCopyImageInfo2& copy_image_info) noexcept
{
    return fubuki::invoke<"vkCmdCopyImage2KHR">(ext, command_buffer.vk, &copy_image_info);
}

void copy_buffer_to_image2(const functions&                ext,
                           command_buffer_handle           command_buffer,
                           const VkCopyBufferToImageInfo2& copy_buffer_to_image_info) noexcept
{
    return fubuki::invoke<"vkCmdCopyBufferToImage2KHR">(ext, command_buffer.vk, &copy_buffer_to_image_info);
}

void copy_image_to_buffer2(const functions&                ext,
                           command_buffer_handle           command_buffer,
                           const VkCopyImageToBufferInfo2& copy_image_to_buffer_info) noexcept
{
    return fubuki::invoke<"vkCmdCopyImageToBuffer2KHR">(ext, command_buffer.vk, &copy_image_to_buffer_info);
}

void blit_image2(const functions& ext, command_buffer_handle command_buffer, const VkBlitImageInfo2& blit_image_info) noexcept
{
    return fubuki::invoke<"vkCmdBlitImage2KHR">(ext, command_buffer.vk, &blit_image_info);
}

void resolve_image2(const functions& ext, command_buffer_handle command_buffer, const VkResolveImageInfo2& resolve_image_info) noexcept
{
    return fubuki::invoke<"vkCmdResolveImage2KHR">(ext, command_buffer.vk, &resolve_image_info);
}

#endif // defined(VK_KHR_copy_commands2)

} // namespace fubuki::extension::khr_copy_commands2::cmd
