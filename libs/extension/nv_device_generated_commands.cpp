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

#include "extension/nv_device_generated_commands.hpp"

#include <core/invoke.hpp>
#include <core/structure_type.hpp>

namespace fubuki::extension::nv_device_generated_commands
{

#if defined(VK_NV_device_generated_commands)

VkMemoryRequirements2 get_generated_commands_memory_requirements(const functions&                                   ext,
                                                                 device_handle                                      device,
                                                                 const VkGeneratedCommandsMemoryRequirementsInfoNV& info) noexcept
{
    auto result = fubuki::make<VkMemoryRequirements2>();

    fubuki::invoke<"vkGetGeneratedCommandsMemoryRequirementsNV">(ext, device.vk, std::addressof(info), std::addressof(result));

    return result;
}

[[nodiscard]]
std::expected<indirect_commands_layout_nv_handle, api_call_info>
create_indirect_commands_layout(const functions&                            ext,
                                device_handle                               device,
                                const VkIndirectCommandsLayoutCreateInfoNV& create_info,
                                const VkAllocationCallbacks&                allocator) noexcept
{
    indirect_commands_layout_nv_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateIndirectCommandsLayoutNV">(ext, device.vk, &create_info, std::addressof(allocator), std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<indirect_commands_layout_nv_handle, api_call_info>
create_indirect_commands_layout(const functions& ext, device_handle device, const VkIndirectCommandsLayoutCreateInfoNV& create_info) noexcept
{
    indirect_commands_layout_nv_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateIndirectCommandsLayoutNV">(ext, device.vk, std::addressof(create_info), nullptr, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_indirect_commands_layout(const functions&                    ext,
                                      device_handle                       device,
                                      indirect_commands_layout_nv_handle& indirect_commands_layout,
                                      const VkAllocationCallbacks&        allocator) noexcept
{
    fubuki::invoke<"vkDestroyIndirectCommandsLayoutNV">(ext, device.vk, indirect_commands_layout.vk, std::addressof(allocator));

    indirect_commands_layout = null_handle;
}

void destroy_indirect_commands_layout(const functions&                    ext,
                                      device_handle                       device,
                                      indirect_commands_layout_nv_handle& indirect_commands_layout) noexcept
{
    fubuki::invoke<"vkDestroyIndirectCommandsLayoutNV">(ext, device.vk, indirect_commands_layout.vk, nullptr);

    indirect_commands_layout = null_handle;
}

#endif // defined(VK_NV_device_generated_commands)

namespace cmd
{

#if defined(VK_NV_device_generated_commands)

void preprocess_generated_commands(const functions&                 ext,
                                   command_buffer_handle            command_buffer,
                                   const VkGeneratedCommandsInfoNV& generated_commands_info) noexcept
{
    return fubuki::invoke<"vkCmdPreprocessGeneratedCommandsNV">(ext, command_buffer.vk, std::addressof(generated_commands_info));
}

void execute_generated_commands(const functions&                 ext,
                                command_buffer_handle            command_buffer,
                                bool                             is_preprocessed,
                                const VkGeneratedCommandsInfoNV& generated_commands_info) noexcept
{
    return fubuki::invoke<"vkCmdExecuteGeneratedCommandsNV">(
        ext, command_buffer.vk, static_cast<VkBool32>(is_preprocessed), std::addressof(generated_commands_info));
}

void bind_pipeline_shader_group(const functions&      ext,
                                command_buffer_handle command_buffer,
                                VkPipelineBindPoint   pipeline_bind_point,
                                pipeline_handle       pipeline,
                                std::uint32_t         group_index) noexcept
{
    return fubuki::invoke<"vkCmdBindPipelineShaderGroupNV">(ext, command_buffer.vk, pipeline_bind_point, pipeline.vk, group_index);
}

#endif // defined(VK_NV_device_generated_commands)

} // namespace cmd

} // namespace fubuki::extension::nv_device_generated_commands
