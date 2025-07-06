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

#ifndef FUBUKI_EXTENSION_KHR_CREATE_RENDERPASS2_HPP
#define FUBUKI_EXTENSION_KHR_CREATE_RENDERPASS2_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_create_renderpass2.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_create_renderpass2
{

#if defined(VK_KHR_create_renderpass2)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRenderPass2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<render_pass_handle, api_call_info> create_render_pass2(
    const functions& ext, device_handle device, const VkRenderPassCreateInfo2& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRenderPass2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<render_pass_handle, api_call_info>
create_render_pass2(const functions& ext, device_handle device, const VkRenderPassCreateInfo2& create_info) noexcept;

#endif // defined(VK_KHR_create_renderpass2)

namespace cmd
{

#if defined(VK_KHR_create_renderpass2)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRenderPass2KHR.html
FUBUKI_EXTENSION_API
void begin_render_pass2(const functions&             ext,
                        command_buffer_handle        command_buffer,
                        const VkRenderPassBeginInfo& render_pass_begin,
                        const VkSubpassBeginInfo&    subpass_begin_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdNextSubpass2KHR.html
FUBUKI_EXTENSION_API
void next_subpass2(const functions&          ext,
                   command_buffer_handle     command_buffer,
                   const VkSubpassBeginInfo& subpass_begin_info,
                   const VkSubpassEndInfo&   subpass_end_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndRenderPass2KHR.html
FUBUKI_EXTENSION_API
void end_render_pass2(const functions& ext, command_buffer_handle command_buffer, const VkSubpassEndInfo& subpass_end_info) noexcept;

#endif // defined(VK_KHR_create_renderpass2)

} // namespace cmd

} // namespace fubuki::extension::khr_create_renderpass2

#endif // FUBUKI_EXTENSION_KHR_CREATE_RENDERPASS2_HPP
