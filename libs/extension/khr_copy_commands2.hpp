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

#ifndef FUBUKI_EXTENSION_KHR_COPY_COMMANDS2_HPP
#define FUBUKI_EXTENSION_KHR_COPY_COMMANDS2_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_copy_commands2.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_copy_commands2::cmd
{

#if defined(VK_KHR_copy_commands2)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyBuffer2KHR.html
FUBUKI_EXTENSION_API
void copy_buffer2(const functions& ext, command_buffer_handle command_buffer, const VkCopyBufferInfo2& copy_buffer_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyImage2KHR.html
FUBUKI_EXTENSION_API
void copy_image2(const functions& ext, command_buffer_handle command_buffer, const VkCopyImageInfo2& copy_image_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyBufferToImage2KHR.html
FUBUKI_EXTENSION_API
void copy_buffer_to_image2(const functions&                ext,
                           command_buffer_handle           command_buffer,
                           const VkCopyBufferToImageInfo2& copy_buffer_to_image_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyImageToBuffer2KHR.html
FUBUKI_EXTENSION_API
void copy_image_to_buffer2(const functions&                ext,
                           command_buffer_handle           command_buffer,
                           const VkCopyImageToBufferInfo2& copy_image_to_buffer_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBlitImage2KHR.html
FUBUKI_EXTENSION_API
void blit_image2(const functions& ext, command_buffer_handle command_buffer, const VkBlitImageInfo2& blit_image_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResolveImage2KHR.html
FUBUKI_EXTENSION_API
void resolve_image2(const functions& ext, command_buffer_handle command_buffer, const VkResolveImageInfo2& resolve_image_info) noexcept;

#endif // defined(VK_KHR_copy_commands2)

} // namespace fubuki::extension::khr_copy_commands2::cmd

#endif // FUBUKI_EXTENSION_KHR_COPY_COMMANDS2_HPP
