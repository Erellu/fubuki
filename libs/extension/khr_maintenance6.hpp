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

#ifndef FUBUKI_EXTENSION_KHR_MAINTENANCE6_HPP
#define FUBUKI_EXTENSION_KHR_MAINTENANCE6_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_maintenance6.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_maintenance6::cmd
{

#if defined(VK_KHR_maintenance6)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets2KHR.html
FUBUKI_EXTENSION_API
void bind_descriptor_sets2(const functions&                   ext,
                           command_buffer_handle              command_buffer,
                           const VkBindDescriptorSetsInfoKHR& bind_descriptor_sets_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushConstants2KHR.html
FUBUKI_EXTENSION_API
void push_constants2(const functions& ext, command_buffer_handle command_buffer, const VkPushConstantsInfoKHR& push_constants_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSet2KHR.html
FUBUKI_EXTENSION_API
void push_descriptor_set2(const functions&                  ext,
                          command_buffer_handle             command_buffer,
                          const VkPushDescriptorSetInfoKHR& push_descriptor_set_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate2KHR.html
FUBUKI_EXTENSION_API
void push_descriptor_set_with_template2(const functions&                              ext,
                                        command_buffer_handle                         command_buffer,
                                        const VkPushDescriptorSetWithTemplateInfoKHR& push_descriptor_set_with_template_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDescriptorBufferOffsets2EXT.html
FUBUKI_EXTENSION_API
void set_descriptor_buffer_offsets2(const functions&                           ext,
                                    command_buffer_handle                      command_buffer,
                                    const VkSetDescriptorBufferOffsetsInfoEXT& set_descriptor_buffer_offsets_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorBufferEmbeddedSamplers2EXT.html
FUBUKI_EXTENSION_API
void bind_descriptor_buffer_embedded_samplers2(
    const functions&                                     ext,
    command_buffer_handle                                command_buffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT& bind_descriptor_buffer_embedded_samplers_info) noexcept;

#endif // defined(VK_KHR_maintenance6)

} // namespace fubuki::extension::khr_maintenance6::cmd

#endif // FUBUKI_EXTENSION_KHR_MAINTENANCE6_HPP
