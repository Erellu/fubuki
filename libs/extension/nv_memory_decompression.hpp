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

#ifndef FUBUKI_EXTENSION_NV_MEMORY_DECOMPRESSION_HPP
#define FUBUKI_EXTENSION_NV_MEMORY_DECOMPRESSION_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_memory_decompression.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_memory_decompression::cmd
{

#if defined(VK_NV_memory_decompression)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDecompressMemoryNV.html
FUBUKI_EXTENSION_API
void decompress_memory(const functions&                            ext,
                       command_buffer_handle                       command_buffer,
                       std::span<const VkDecompressMemoryRegionNV> decompress_memory_regions) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDecompressMemoryIndirectCountNV.html
FUBUKI_EXTENSION_API
void decompress_memory_indirect_count(const functions&      ext,
                                      command_buffer_handle command_buffer,
                                      VkDeviceAddress       indirect_commands_address,
                                      VkDeviceAddress       indirect_commands_count_address,
                                      std::uint32_t         stride) noexcept;

#endif // defined(VK_NV_memory_decompression)

} // namespace fubuki::extension::nv_memory_decompression::cmd

#endif // FUBUKI_EXTENSION_NV_MEMORY_DECOMPRESSION_HPP
