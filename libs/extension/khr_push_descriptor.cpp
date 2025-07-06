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

#include "extension/khr_push_descriptor.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::khr_push_descriptor::cmd
{

#if defined(VK_KHR_push_descriptor)

void push_descriptor_set(const functions&                      ext,
                         command_buffer_handle                 command_buffer,
                         VkPipelineBindPoint                   pipeline_bind_point,
                         pipeline_layout_handle                layout,
                         std::uint32_t                         set,
                         std::span<const VkWriteDescriptorSet> writes) noexcept
{
    return fubuki::invoke<"vkCmdPushDescriptorSetKHR">(ext, command_buffer.vk, pipeline_bind_point, layout.vk, set, vk_size(writes), writes.data());
}

void push_descriptor_set_with_template(const functions&                  ext,
                                       command_buffer_handle             command_buffer,
                                       descriptor_update_template_handle descriptor_update_template,
                                       pipeline_layout_handle            layout,
                                       std::uint32_t                     set,
                                       const void*                       p_data) noexcept
{
    return fubuki::invoke<"vkCmdPushDescriptorSetWithTemplateKHR">(ext, command_buffer.vk, descriptor_update_template.vk, layout.vk, set, p_data);
}

#endif // defined(VK_KHR_push_descriptor)

} // namespace fubuki::extension::khr_push_descriptor::cmd
