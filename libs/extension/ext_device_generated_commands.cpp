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

#include "extension/ext_device_generated_commands.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_device_generated_commands
{

#if defined(VK_EXT_device_generated_commands)

namespace detail
{

void get_generated_commands_memory_requirements(const functions&                                    ext,
                                                device_handle                                       device,
                                                const VkGeneratedCommandsMemoryRequirementsInfoEXT& info,
                                                VkMemoryRequirements2&                              result) noexcept
{
    return fubuki::invoke<"vkGetGeneratedCommandsMemoryRequirementsEXT">(ext, device.vk, std::addressof(info), std::addressof(result));
}

[[nodiscard]] std::expected<indirect_commands_layout_ext_handle, api_call_info>
create_indirect_commands_layout(const functions&                             ext,
                                device_handle                                device,
                                const VkIndirectCommandsLayoutCreateInfoEXT& create_info,
                                const VkAllocationCallbacks*                 allocator) noexcept
{
    indirect_commands_layout_ext_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateIndirectCommandsLayoutEXT">(ext, device.vk, std::addressof(create_info), allocator, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_indirect_commands_layout(const functions&                     ext,
                                      device_handle                        device,
                                      indirect_commands_layout_ext_handle& indirect_commands_layout,
                                      const VkAllocationCallbacks*         allocator) noexcept
{
    fubuki::invoke<"vkDestroyIndirectCommandsLayoutEXT">(ext, device.vk, indirect_commands_layout.vk, allocator);
    indirect_commands_layout = null_handle;
}

[[nodiscard]] std::expected<indirect_execution_set_ext_handle, api_call_info>
create_indirect_execution_set(const functions&                           ext,
                              device_handle                              device,
                              const VkIndirectExecutionSetCreateInfoEXT& create_info,
                              const VkAllocationCallbacks*               allocator) noexcept
{
    indirect_execution_set_ext_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateIndirectExecutionSetEXT">(ext, device.vk, std::addressof(create_info), allocator, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_indirect_execution_set(const functions&                   ext,
                                    device_handle                      device,
                                    indirect_execution_set_ext_handle& indirect_execution_set,
                                    const VkAllocationCallbacks*       allocator) noexcept
{
    fubuki::invoke<"vkDestroyIndirectExecutionSetEXT">(ext, device.vk, indirect_execution_set.vk, allocator);
    indirect_execution_set = null_handle;
}

} // namespace detail

void update_indirect_execution_set_pipeline(const functions&                                        ext,
                                            device_handle                                           device,
                                            indirect_execution_set_ext_handle                       indirect_execution_set,
                                            std::span<const VkWriteIndirectExecutionSetPipelineEXT> execution_set_writes) noexcept
{
    return fubuki::invoke<"vkUpdateIndirectExecutionSetPipelineEXT">(
        ext, device.vk, indirect_execution_set.vk, vk_size(execution_set_writes), execution_set_writes.data());
}

void update_indirect_execution_set_shader(const functions&                                      ext,
                                          device_handle                                         device,
                                          indirect_execution_set_ext_handle                     indirect_execution_set,
                                          std::span<const VkWriteIndirectExecutionSetShaderEXT> execution_set_writes) noexcept
{
    return fubuki::invoke<"vkUpdateIndirectExecutionSetShaderEXT">(
        ext, device.vk, indirect_execution_set.vk, vk_size(execution_set_writes), execution_set_writes.data());
}

#endif // defined(VK_EXT_device_generated_commands)

namespace cmd
{

#if defined(VK_EXT_device_generated_commands)

void preprocess_generated_commands(const functions&                  ext,
                                   command_buffer_handle             command_buffer,
                                   const VkGeneratedCommandsInfoEXT& generated_commands_info,
                                   command_buffer_handle             state_command_buffer) noexcept
{
    return fubuki::invoke<"vkCmdPreprocessGeneratedCommandsEXT">(
        ext, command_buffer.vk, std::addressof(generated_commands_info), state_command_buffer.vk);
}

void execute_generated_commands(const functions&                  ext,
                                command_buffer_handle             command_buffer,
                                bool                              is_preprocessed,
                                const VkGeneratedCommandsInfoEXT& generated_commands_info) noexcept
{
    return fubuki::invoke<"vkCmdExecuteGeneratedCommandsEXT">(
        ext, command_buffer.vk, static_cast<VkBool32>(is_preprocessed), std::addressof(generated_commands_info));
}

#endif // defined(VK_EXT_device_generated_commands)

} // namespace cmd

} // namespace fubuki::extension::ext_device_generated_commands
