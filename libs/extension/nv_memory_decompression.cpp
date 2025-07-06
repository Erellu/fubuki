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

#include "extension/nv_memory_decompression.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::nv_memory_decompression::cmd
{

#if defined(VK_NV_memory_decompression)

void decompress_memory(const functions&                            ext,
                       command_buffer_handle                       command_buffer,
                       std::span<const VkDecompressMemoryRegionNV> decompress_memory_regions) noexcept
{
    return fubuki::invoke<"vkCmdDecompressMemoryNV">(ext, command_buffer.vk, vk_size(decompress_memory_regions), decompress_memory_regions.data());
}

void decompress_memory_indirect_count(const functions&      ext,
                                      command_buffer_handle command_buffer,
                                      VkDeviceAddress       indirect_commands_address,
                                      VkDeviceAddress       indirect_commands_count_address,
                                      std::uint32_t         stride) noexcept
{
    return fubuki::invoke<"vkCmdDecompressMemoryIndirectCountNV">(
        ext, command_buffer.vk, indirect_commands_address, indirect_commands_count_address, stride);
}

#endif // defined(VK_NV_memory_decompression)

} // namespace fubuki::extension::nv_memory_decompression::cmd
