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

#include "extension/nv_device_generated_commands_compute.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::nv_device_generated_commands_compute
{

#if defined(VK_NV_device_generated_commands_compute)

void get_pipeline_indirect_memory_requirements(const functions&                   ext,
                                               device_handle                      device,
                                               const VkComputePipelineCreateInfo& create_info,
                                               VkMemoryRequirements2&             memory_requirements) noexcept
{
    return fubuki::invoke<"vkGetPipelineIndirectMemoryRequirementsNV">(
        ext, device.vk, std::addressof(create_info), std::addressof(memory_requirements));
}

[[nodiscard]]
VkDeviceAddress get_pipeline_indirect_device_address(const functions& ext, device_handle device, const VkPipelineIndirectDeviceAddressInfoNV& info)
{
    return fubuki::invoke<"vkGetPipelineIndirectDeviceAddressNV">(ext, device.vk, std::addressof(info));
}

#endif // defined(VK_NV_device_generated_commands_compute)

namespace cmd
{

#if defined(VK_NV_device_generated_commands_compute)

void update_pipeline_indirect_buffer(const functions&      ext,
                                     command_buffer_handle command_buffer,
                                     VkPipelineBindPoint   pipeline_bind_point,
                                     pipeline_handle       pipeline) noexcept
{
    return fubuki::invoke<"vkCmdUpdatePipelineIndirectBufferNV">(ext, command_buffer.vk, pipeline_bind_point, pipeline.vk);
}

#endif // defined(VK_NV_device_generated_commands_compute)

} // namespace cmd

} // namespace fubuki::extension::nv_device_generated_commands_compute
