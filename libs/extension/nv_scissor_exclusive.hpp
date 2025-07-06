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

#ifndef FUBUKI_EXTENSION_NV_SCISSOR_EXCLUSIVE_HPP
#define FUBUKI_EXTENSION_NV_SCISSOR_EXCLUSIVE_HPP

#include <initializer_list>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_scissor_exclusive.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_scissor_exclusive::cmd
{

#if defined(VK_NV_scissor_exclusive)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetExclusiveScissorEnableNV.html
FUBUKI_EXTENSION_API
void set_exclusive_scissor_enable(const functions&          ext,
                                  command_buffer_handle     command_buffer,
                                  std::uint32_t             first_exclusive_scissor,
                                  std::span<const VkBool32> exclusive_scissor_enables) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetExclusiveScissorEnableNV.html
inline void set_exclusive_scissor_enable(const functions&                ext,
                                         command_buffer_handle           command_buffer,
                                         std::uint32_t                   first_exclusive_scissor,
                                         std::initializer_list<VkBool32> exclusive_scissor_enables) noexcept
{
    return set_exclusive_scissor_enable(ext, command_buffer, first_exclusive_scissor, std::span{exclusive_scissor_enables});
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetExclusiveScissorNV.html
FUBUKI_EXTENSION_API
void set_exclusive_scissor(const functions&          ext,
                           command_buffer_handle     command_buffer,
                           std::uint32_t             first_exclusive_scissor,
                           std::span<const VkRect2D> exclusive_scissors) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetExclusiveScissorNV.html
inline void set_exclusive_scissor(const functions&                ext,
                                  command_buffer_handle           command_buffer,
                                  std::uint32_t                   first_exclusive_scissor,
                                  std::initializer_list<VkRect2D> exclusive_scissors) noexcept
{
    return set_exclusive_scissor(ext, command_buffer, first_exclusive_scissor, std::span{exclusive_scissors});
}

#endif // defined(VK_NV_scissor_exclusive)

} // namespace fubuki::extension::nv_scissor_exclusive::cmd

#endif // FUBUKI_EXTENSION_NV_SCISSOR_EXCLUSIVE_HPP
