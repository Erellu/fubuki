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

#include "fuyu/command/push.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command::push
{

#if defined(VK_VERSION_1_4)

namespace detail
{

void constants(command_buffer_view command_buffer, const VkPushConstantsInfo& info) noexcept
{
    return fuyu::invoke<"vkCmdPushConstants2">(command_buffer, std::addressof(info));
}

void descriptor_set(command_buffer_view command_buffer, const VkPushDescriptorSetInfo& info) noexcept
{
    return fuyu::invoke<"vkCmdPushDescriptorSet2">(command_buffer, std::addressof(info));
}

void descriptor_set_with_template(command_buffer_view               command_buffer,
                                  descriptor_update_template_handle update,
                                  pipeline_layout_handle            layout,
                                  std::uint32_t                     set,
                                  const void*                       data) noexcept
{
    return fuyu::invoke<"vkCmdPushDescriptorSetWithTemplate">(command_buffer, update.vk, layout.vk, set, data);
}

void descriptor_set_with_template(command_buffer_view command_buffer, const VkPushDescriptorSetWithTemplateInfo& info) noexcept
{
    return fuyu::invoke<"vkCmdPushDescriptorSetWithTemplate2">(command_buffer, std::addressof(info));
}

} // namespace detail
#endif // defined(VK_VERSION_1_4)

void constants(command_buffer_view        command_buffer,
               pipeline_layout_handle     layout,
               VkShaderStageFlags         stage,
               std::uint32_t              offset,
               std::span<const std::byte> data) noexcept
{
    return fuyu::invoke<"vkCmdPushConstants">(command_buffer, layout.vk, stage, offset, vk_size(data), data.data());
}

#if defined(VK_VERSION_1_4)

void descriptor_set(command_buffer_view                   command_buffer,
                    VkPipelineBindPoint                   bind_point,
                    pipeline_layout_handle                layout,
                    std::uint32_t                         set,
                    std::span<const VkWriteDescriptorSet> writes) noexcept
{
    return fuyu::invoke<"vkCmdPushDescriptorSet">(command_buffer, bind_point, layout.vk, set, vk_size(writes), writes.data());
}

#endif // defined(VK_VERSION_1_4)

} // namespace fubuki::fuyu::command::push
