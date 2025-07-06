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

#ifndef FUBUKI_EXTENSION_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_HPP
#define FUBUKI_EXTENSION_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_HPP

#include <vector>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_device_diagnostic_checkpoints.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_device_diagnostic_checkpoints
{

#if defined(VK_NV_device_diagnostic_checkpoints)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetQueueCheckpointDataNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::vector<VkCheckpointDataNV> get_queue_checkpoint_data(const functions& ext, queue_handle queue);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetQueueCheckpointData2NV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::vector<VkCheckpointData2NV> get_queue_checkpoint_data_2(const functions& ext, queue_handle queue);

#endif // defined(VK_NV_device_diagnostic_checkpoints)

namespace cmd
{

#if defined(VK_NV_device_diagnostic_checkpoints)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCheckpointNV.html
FUBUKI_EXTENSION_API
void set_checkpoint(const functions& ext, command_buffer_handle command_buffer, const void* p_checkpoint_marker) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCheckpointNV.html
template<typename T>
inline void set_checkpoint(const functions& ext, command_buffer_handle command_buffer, const T* const p_checkpoint_marker) noexcept
{
    return set_checkpoint(ext, command_buffer, static_cast<void*>(p_checkpoint_marker));
}

#endif // defined(VK_NV_device_diagnostic_checkpoints)

} // namespace cmd

} // namespace fubuki::extension::nv_device_diagnostic_checkpoints

#endif // FUBUKI_EXTENSION_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_HPP
