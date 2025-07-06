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

#ifndef FUBUKI_EXTENSION_EXT_EXTENDED_DYNAMIC_STATE_HPP
#define FUBUKI_EXTENSION_EXT_EXTENDED_DYNAMIC_STATE_HPP

#include <initializer_list>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_extended_dynamic_state.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_extended_dynamic_state::cmd
{

#if defined(VK_EXT_extended_dynamic_state)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCullModeEXT.html
FUBUKI_EXTENSION_API
void set_cull_mode(const functions& ext, command_buffer_handle command_buffer, VkCullModeFlags cull_mode) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetFrontFaceEXT.html
FUBUKI_EXTENSION_API
void set_front_face(const functions& ext, command_buffer_handle command_buffer, VkFrontFace front_face) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPrimitiveTopologyEXT.html
FUBUKI_EXTENSION_API
void set_primitive_topology(const functions& ext, command_buffer_handle command_buffer, VkPrimitiveTopology primitive_topology) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportWithCountEXT.html
FUBUKI_EXTENSION_API
void set_viewport_with_count(const functions& ext, command_buffer_handle command_buffer, std::span<const VkViewport> viewports) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportWithCountEXT.html
inline void set_viewport_with_count(const functions& ext, command_buffer_handle command_buffer, std::initializer_list<VkViewport> viewports) noexcept
{
    return set_viewport_with_count(ext, command_buffer, std::span{viewports});
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissorWithCountEXT.html
FUBUKI_EXTENSION_API
void set_scissor_with_count(const functions& ext, command_buffer_handle command_buffer, std::span<const VkRect2D> scissors) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissorWithCountEXT.html
inline void set_scissor_with_count(const functions& ext, command_buffer_handle command_buffer, std::initializer_list<VkRect2D> scissors) noexcept
{
    return set_scissor_with_count(ext, command_buffer, std::span{scissors});
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers2EXT.html
FUBUKI_EXTENSION_API
void bind_vertex_buffers2(const functions&               ext,
                          command_buffer_handle          command_buffer,
                          std::uint32_t                  first_binding,
                          std::span<const buffer_handle> buffers,
                          std::span<const VkDeviceSize>  offsets,
                          std::span<const VkDeviceSize>  sizes,
                          std::span<const VkDeviceSize>  strides) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthTestEnableEXT.html
FUBUKI_EXTENSION_API
void set_depth_test_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_test_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthWriteEnableEXT.html
FUBUKI_EXTENSION_API
void set_depth_write_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_write_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthCompareOpEXT.html
FUBUKI_EXTENSION_API
void set_depth_compare_op(const functions& ext, command_buffer_handle command_buffer, VkCompareOp depth_compare_op) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBoundsTestEnableEXT.html
FUBUKI_EXTENSION_API
void set_depth_bounds_test_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_bounds_test_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilTestEnableEXT.html
FUBUKI_EXTENSION_API
void set_stencil_test_enable(const functions& ext, command_buffer_handle command_buffer, bool stencil_test_enable) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilOpEXT.html
FUBUKI_EXTENSION_API
void set_stencil_op(const functions&      ext,
                    command_buffer_handle command_buffer,
                    VkStencilFaceFlags    face_mask,
                    VkStencilOp           fail_op,
                    VkStencilOp           pass_op,
                    VkStencilOp           depth_fail_op,
                    VkCompareOp           compare_op) noexcept;

#endif // defined(VK_EXT_extended_dynamic_state)

} // namespace fubuki::extension::ext_extended_dynamic_state::cmd

#endif // FUBUKI_EXTENSION_EXT_EXTENDED_DYNAMIC_STATE_HPP
