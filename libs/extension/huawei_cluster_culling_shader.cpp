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

#include "extension/huawei_cluster_culling_shader.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::huawei_cluster_culling_shader::cmd
{

#if defined(VK_HUAWEI_cluster_culling_shader)

void draw_cluster(const functions&      ext,
                  command_buffer_handle command_buffer,
                  std::uint32_t         group_count_x,
                  std::uint32_t         group_count_y,
                  std::uint32_t         group_count_z) noexcept
{
    return fubuki::invoke<"vkCmdDrawClusterHUAWEI">(ext, command_buffer.vk, group_count_x, group_count_y, group_count_z);
}

void draw_cluster_indirect(const functions& ext, command_buffer_handle command_buffer, buffer_handle buffer, VkDeviceSize offset) noexcept
{
    return fubuki::invoke<"vkCmdDrawClusterIndirectHUAWEI">(ext, command_buffer.vk, buffer.vk, offset);
}

#endif // defined(VK_HUAWEI_cluster_culling_shader)

} // namespace fubuki::extension::huawei_cluster_culling_shader::cmd
