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

#ifndef FUBUKI_EXTENSION_KHR_DRAW_INDIRECT_COUNT_HPP
#define FUBUKI_EXTENSION_KHR_DRAW_INDIRECT_COUNT_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_draw_indirect_count.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_draw_indirect_count::cmd
{

#if defined(VK_KHR_draw_indirect_count)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndirectCountKHR.html
FUBUKI_EXTENSION_API
void draw_indirect_count(const functions&      ext,
                         command_buffer_handle command_buffer,
                         buffer_handle         buffer,
                         VkDeviceSize          offset,
                         buffer_handle         count_buffer,
                         VkDeviceSize          count_buffer_offset,
                         std::uint32_t         max_draw_count,
                         std::uint32_t         stride) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexedIndirectCountKHR.html
FUBUKI_EXTENSION_API
void draw_indexed_indirect_count(const functions&      ext,
                                 command_buffer_handle command_buffer,
                                 buffer_handle         buffer,
                                 VkDeviceSize          offset,
                                 buffer_handle         count_buffer,
                                 VkDeviceSize          count_buffer_offset,
                                 std::uint32_t         max_draw_count,
                                 std::uint32_t         stride) noexcept;

#endif // defined(VK_KHR_draw_indirect_count)

} // namespace fubuki::extension::khr_draw_indirect_count::cmd

#endif // FUBUKI_EXTENSION_KHR_DRAW_INDIRECT_COUNT_HPP
