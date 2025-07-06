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

#include "extension/ext_multi_draw.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_multi_draw::cmd
{

#if defined(VK_EXT_multi_draw)

void draw_multi(const functions&                    ext,
                command_buffer_handle               command_buffer,
                std::span<const VkMultiDrawInfoEXT> vertex_info,
                std::uint32_t                       instance_count,
                std::uint32_t                       first_instance) noexcept
{
    return fubuki::invoke<"vkCmdDrawMultiEXT">(
        ext, command_buffer.vk, vk_size(vertex_info), vertex_info.data(), instance_count, first_instance, vk_size(sizeof(VkMultiDrawInfoEXT)));
}

void draw_multi_indexed(const functions&                           ext,
                        command_buffer_handle                      command_buffer,
                        std::span<const VkMultiDrawIndexedInfoEXT> index_info,
                        std::uint32_t                              instance_count,
                        std::uint32_t                              first_instance,
                        std::optional<std::int32_t>                vertex_offset) noexcept
{
    const auto* offset = vertex_offset.has_value() ? &vertex_offset.value() : nullptr;

    return fubuki::invoke<"vkCmdDrawMultiIndexedEXT">(ext,
                                                      command_buffer.vk,
                                                      vk_size(index_info),
                                                      index_info.data(),
                                                      instance_count,
                                                      first_instance,
                                                      vk_size(sizeof(VkMultiDrawIndexedInfoEXT)),
                                                      offset);
}

#endif // defined(VK_EXT_multi_draw)

} // namespace fubuki::extension::ext_multi_draw::cmd
