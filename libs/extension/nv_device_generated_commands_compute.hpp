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

#ifndef FUBUKI_EXTENSION_NV_DEVICE_GENERATED_COMMANDS_COMPUTE_HPP
#define FUBUKI_EXTENSION_NV_DEVICE_GENERATED_COMMANDS_COMPUTE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_device_generated_commands_compute.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_device_generated_commands_compute
{

#if defined(VK_NV_device_generated_commands_compute)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineIndirectMemoryRequirementsNV.html
FUBUKI_EXTENSION_API
void get_pipeline_indirect_memory_requirements(const functions&                   ext,
                                               device_handle                      device,
                                               const VkComputePipelineCreateInfo& create_info,
                                               VkMemoryRequirements2&             memory_requirements) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineIndirectDeviceAddressNV.html
[[nodiscard]] FUBUKI_EXTENSION_API VkDeviceAddress get_pipeline_indirect_device_address(const functions&                             ext,
                                                                                        device_handle                                device,
                                                                                        const VkPipelineIndirectDeviceAddressInfoNV& info);

#endif // defined(VK_NV_device_generated_commands_compute)

namespace cmd
{

#if defined(VK_NV_device_generated_commands_compute)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdUpdatePipelineIndirectBufferNV.html
FUBUKI_EXTENSION_API
void update_pipeline_indirect_buffer(const functions&      ext,
                                     command_buffer_handle command_buffer,
                                     VkPipelineBindPoint   pipeline_bind_point,
                                     pipeline_handle       pipeline) noexcept;

#endif // defined(VK_NV_device_generated_commands_compute)

} // namespace cmd

} // namespace fubuki::extension::nv_device_generated_commands_compute

#endif // FUBUKI_EXTENSION_NV_DEVICE_GENERATED_COMMANDS_COMPUTE_HPP
