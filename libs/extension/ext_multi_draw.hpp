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

#ifndef FUBUKI_EXTENSION_EXT_MULTI_DRAW_HPP
#define FUBUKI_EXTENSION_EXT_MULTI_DRAW_HPP

#include <optional>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_multi_draw.hpp" // IWYU pragma: export

/**
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_EXT_multi_draw.html
 */
namespace fubuki::extension::ext_multi_draw::cmd
{

#if defined(VK_EXT_multi_draw)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawMultiEXT.html
FUBUKI_EXTENSION_API
void draw_multi(const functions&                    ext,
                command_buffer_handle               command_buffer,
                std::span<const VkMultiDrawInfoEXT> vertex_info,
                std::uint32_t                       instance_count = 0,
                std::uint32_t                       first_instance = 0) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawMultiIndexedEXT.html
FUBUKI_EXTENSION_API
void draw_multi_indexed(const functions&                           ext,
                        command_buffer_handle                      command_buffer,
                        std::span<const VkMultiDrawIndexedInfoEXT> index_info,
                        std::uint32_t                              instance_count = 0,
                        std::uint32_t                              first_instance = 0,
                        std::optional<std::int32_t>                vertex_offset  = {}) noexcept;

#endif // defined(VK_EXT_multi_draw)

} // namespace fubuki::extension::ext_multi_draw::cmd

#endif // FUBUKI_EXTENSION_EXT_MULTI_DRAW_HPP
