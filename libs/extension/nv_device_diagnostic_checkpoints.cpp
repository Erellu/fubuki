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

#include "extension/nv_device_diagnostic_checkpoints.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::nv_device_diagnostic_checkpoints
{

#if defined(VK_NV_device_diagnostic_checkpoints)

[[nodiscard]]
std::vector<VkCheckpointDataNV> get_queue_checkpoint_data(const functions& ext, queue_handle queue)
{
    std::uint32_t count = 0;

    fubuki::invoke<"vkGetQueueCheckpointDataNV">(ext, queue.vk, &count, nullptr);

    std::vector<VkCheckpointDataNV> result;
    result.resize(count);

    fubuki::invoke<"vkGetQueueCheckpointDataNV">(ext, queue.vk, &count, result.data());

    return result;
}

[[nodiscard]] std::vector<VkCheckpointData2NV> get_queue_checkpoint_data_2(const functions& ext, queue_handle queue)
{
    std::uint32_t count = 0;

    fubuki::invoke<"vkGetQueueCheckpointData2NV">(ext, queue.vk, &count, nullptr);

    std::vector<VkCheckpointData2NV> result;
    result.resize(count);

    fubuki::invoke<"vkGetQueueCheckpointData2NV">(ext, queue.vk, &count, result.data());

    return result;
}

#endif // defined(VK_NV_device_diagnostic_checkpoints)

namespace cmd
{

#if defined(VK_NV_device_diagnostic_checkpoints)

void set_checkpoint(const functions& ext, command_buffer_handle command_buffer, const void* p_checkpoint_marker) noexcept
{
    return fubuki::invoke<"vkCmdSetCheckpointNV">(ext, command_buffer.vk, p_checkpoint_marker);
}

#endif // defined(VK_NV_device_diagnostic_checkpoints)

} // namespace cmd

} // namespace fubuki::extension::nv_device_diagnostic_checkpoints
