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

#include "extension/ext_extended_dynamic_state2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::ext_extended_dynamic_state2::cmd
{

#if defined(VK_EXT_extended_dynamic_state2)

void set_patch_control_points(const functions& ext, command_buffer_handle command_buffer, std::uint32_t patch_control_points) noexcept
{
    return fubuki::invoke<"vkCmdSetPatchControlPointsEXT">(ext, command_buffer.vk, patch_control_points);
}

void set_rasterizer_discard_enable(const functions& ext, command_buffer_handle command_buffer, bool rasterizer_discard_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetRasterizerDiscardEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(rasterizer_discard_enable));
}

void set_depth_bias_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_bias_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthBiasEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(depth_bias_enable));
}

void set_logic_op(const functions& ext, command_buffer_handle command_buffer, VkLogicOp logic_op) noexcept
{
    return fubuki::invoke<"vkCmdSetLogicOpEXT">(ext, command_buffer.vk, logic_op);
}

void set_primitive_restart_enable(const functions& ext, command_buffer_handle command_buffer, bool primitive_restart_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetPrimitiveRestartEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(primitive_restart_enable));
}

#endif // defined(VK_EXT_extended_dynamic_state2)

} // namespace fubuki::extension::ext_extended_dynamic_state2::cmd
