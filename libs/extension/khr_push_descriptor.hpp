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

#ifndef FUBUKI_EXTENSION_KHR_PUSH_DESCRIPTOR_HPP
#define FUBUKI_EXTENSION_KHR_PUSH_DESCRIPTOR_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_push_descriptor.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_push_descriptor::cmd
{

#if defined(VK_KHR_push_descriptor)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetKHR.html
FUBUKI_EXTENSION_API
void push_descriptor_set(const functions&                      ext,
                         command_buffer_handle                 command_buffer,
                         VkPipelineBindPoint                   pipeline_bind_point,
                         pipeline_layout_handle                layout,
                         std::uint32_t                         set,
                         std::span<const VkWriteDescriptorSet> writes) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplateKHR.html
FUBUKI_EXTENSION_API
void push_descriptor_set_with_template(const functions&                  ext,
                                       command_buffer_handle             command_buffer,
                                       descriptor_update_template_handle descriptor_update_template,
                                       pipeline_layout_handle            layout,
                                       std::uint32_t                     set,
                                       const void*                       p_data) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplateKHR.html
template<typename T>
requires(std::is_same_v<T, VkDescriptorImageInfo> or std::is_same_v<T, VkDescriptorBufferInfo> or std::is_same_v<T, VkBufferView>)
inline void push_descriptor_set_with_template(const functions&                  ext,
                                              command_buffer_handle             command_buffer,
                                              descriptor_update_template_handle descriptor_update_template,
                                              pipeline_layout_handle            layout,
                                              std::uint32_t                     set,
                                              const T&                          data) noexcept
{
    return push_descriptor_set_with_template(ext, command_buffer, descriptor_update_template, layout, set, std::addressof(data));
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplateKHR.html
template<typename T>
requires(std::is_same_v<T, VkDescriptorImageInfo> or std::is_same_v<T, VkDescriptorBufferInfo> or std::is_same_v<T, VkBufferView>)
inline void push_descriptor_set_with_template(const functions&                  ext,
                                              command_buffer_handle             command_buffer,
                                              descriptor_update_template_handle descriptor_update_template,
                                              pipeline_layout_handle            layout,
                                              std::uint32_t                     set,
                                              std::span<const T>                data) noexcept
{
    return push_descriptor_set_with_template(ext, command_buffer, descriptor_update_template, layout, set, data.data());
}

#endif // defined(VK_KHR_push_descriptor)

} // namespace fubuki::extension::khr_push_descriptor::cmd

#endif // FUBUKI_EXTENSION_KHR_PUSH_DESCRIPTOR_HPP
