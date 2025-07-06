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

#ifndef FUBUKI_EXTENSION_NV_DEVICE_GENERATED_COMMANDS_HPP
#define FUBUKI_EXTENSION_NV_DEVICE_GENERATED_COMMANDS_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_device_generated_commands.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_device_generated_commands
{

#if defined(VK_NV_device_generated_commands)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetGeneratedCommandsMemoryRequirementsNV.html
FUBUKI_EXTENSION_API
VkMemoryRequirements2 get_generated_commands_memory_requirements(const functions&                                   ext,
                                                                 device_handle                                      device,
                                                                 const VkGeneratedCommandsMemoryRequirementsInfoNV& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectCommandsLayoutNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<indirect_commands_layout_nv_handle, api_call_info>
                                   create_indirect_commands_layout(const functions&                            ext,
                                                                   device_handle                               device,
                                                                   const VkIndirectCommandsLayoutCreateInfoNV& create_info,
                                                                   const VkAllocationCallbacks&                allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectCommandsLayoutNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<indirect_commands_layout_nv_handle, api_call_info>
create_indirect_commands_layout(const functions& ext, device_handle device, const VkIndirectCommandsLayoutCreateInfoNV& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectCommandsLayoutNV.html
FUBUKI_EXTENSION_API
void destroy_indirect_commands_layout(const functions&                    ext,
                                      device_handle                       device,
                                      indirect_commands_layout_nv_handle& indirect_commands_layout,
                                      const VkAllocationCallbacks&        allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectCommandsLayoutNV.html
FUBUKI_EXTENSION_API
void destroy_indirect_commands_layout(const functions&                    ext,
                                      device_handle                       device,
                                      indirect_commands_layout_nv_handle& indirect_commands_layout) noexcept;

#endif // defined(VK_NV_device_generated_commands)

namespace cmd
{

#if defined(VK_NV_device_generated_commands)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPreprocessGeneratedCommandsNV.html
FUBUKI_EXTENSION_API
void preprocess_generated_commands(const functions&                 ext,
                                   command_buffer_handle            command_buffer,
                                   const VkGeneratedCommandsInfoNV& generated_commands_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdExecuteGeneratedCommandsNV.html
FUBUKI_EXTENSION_API
void execute_generated_commands(const functions&                 ext,
                                command_buffer_handle            command_buffer,
                                bool                             is_preprocessed,
                                const VkGeneratedCommandsInfoNV& generated_commands_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindPipelineShaderGroupNV.html
FUBUKI_EXTENSION_API
void bind_pipeline_shader_group(const functions&      ext,
                                command_buffer_handle command_buffer,
                                VkPipelineBindPoint   pipeline_bind_point,
                                pipeline_handle       pipeline,
                                std::uint32_t         group_index) noexcept;

#endif // defined(VK_NV_device_generated_commands)

} // namespace cmd

} // namespace fubuki::extension::nv_device_generated_commands

#endif // FUBUKI_EXTENSION_NV_DEVICE_GENERATED_COMMANDS_HPP
