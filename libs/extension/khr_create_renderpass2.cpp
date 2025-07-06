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

#include "extension/khr_create_renderpass2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_create_renderpass2
{

#if defined(VK_KHR_create_renderpass2)

namespace
{

[[nodiscard]]
std::expected<render_pass_handle, api_call_info> create_render_pass2(const functions&               ext,
                                                                     device_handle                  device,
                                                                     const VkRenderPassCreateInfo2& create_info,
                                                                     const VkAllocationCallbacks*   allocator) noexcept
{
    render_pass_handle result;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateRenderPass2KHR">(ext, device.vk, &create_info, allocator, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // namespace

[[nodiscard]]
std::expected<render_pass_handle, api_call_info> create_render_pass2(const functions&               ext,
                                                                     device_handle                  device,
                                                                     const VkRenderPassCreateInfo2& create_info,
                                                                     const VkAllocationCallbacks&   allocator) noexcept
{
    return create_render_pass2(ext, device, create_info, std::addressof(allocator));
}

[[nodiscard]]
std::expected<render_pass_handle, api_call_info>
create_render_pass2(const functions& ext, device_handle device, const VkRenderPassCreateInfo2& create_info) noexcept
{
    return create_render_pass2(ext, device, create_info, nullptr);
}

#endif // defined(VK_KHR_create_renderpass2)

namespace cmd
{

#if defined(VK_KHR_create_renderpass2)

void begin_render_pass2(const functions&             ext,
                        command_buffer_handle        command_buffer,
                        const VkRenderPassBeginInfo& render_pass_begin,
                        const VkSubpassBeginInfo&    subpass_begin_info) noexcept
{
    return fubuki::invoke<"vkCmdBeginRenderPass2KHR">(ext, command_buffer.vk, &render_pass_begin, &subpass_begin_info);
}

void next_subpass2(const functions&          ext,
                   command_buffer_handle     command_buffer,
                   const VkSubpassBeginInfo& subpass_begin_info,
                   const VkSubpassEndInfo&   subpass_end_info) noexcept
{
    return fubuki::invoke<"vkCmdNextSubpass2KHR">(ext, command_buffer.vk, &subpass_begin_info, &subpass_end_info);
}

void end_render_pass2(const functions& ext, command_buffer_handle command_buffer, const VkSubpassEndInfo& subpass_end_info) noexcept
{
    return fubuki::invoke<"vkCmdEndRenderPass2KHR">(ext, command_buffer.vk, &subpass_end_info);
}

#endif // defined(VK_KHR_create_renderpass2)

} // namespace cmd

} // namespace fubuki::extension::khr_create_renderpass2
