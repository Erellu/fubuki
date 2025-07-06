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

#include "extension/ext_extended_dynamic_state.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>
#include <core/pfn.hpp>
#include <core/vulkan.hpp>

namespace fubuki::extension::ext_extended_dynamic_state::cmd
{

#if defined(VK_EXT_extended_dynamic_state)

void set_cull_mode(const functions& ext, command_buffer_handle command_buffer, VkCullModeFlags cull_mode) noexcept
{
    return fubuki::invoke<"vkCmdSetCullModeEXT">(ext, command_buffer.vk, cull_mode);
}

void set_front_face(const functions& ext, command_buffer_handle command_buffer, VkFrontFace front_face) noexcept
{
    return fubuki::invoke<"vkCmdSetFrontFaceEXT">(ext, command_buffer.vk, front_face);
}

void set_primitive_topology(const functions& ext, command_buffer_handle command_buffer, VkPrimitiveTopology primitive_topology) noexcept
{
    return fubuki::invoke<"vkCmdSetPrimitiveTopologyEXT">(ext, command_buffer.vk, primitive_topology);
}

void set_viewport_with_count(const functions& ext, command_buffer_handle command_buffer, std::span<const VkViewport> viewports) noexcept
{
    return fubuki::invoke<"vkCmdSetViewportWithCountEXT">(ext, command_buffer.vk, vk_size(viewports), viewports.data());
}

void set_scissor_with_count(const functions& ext, command_buffer_handle command_buffer, std::span<const VkRect2D> scissors) noexcept
{
    return fubuki::invoke<"vkCmdSetScissorWithCountEXT">(ext, command_buffer.vk, vk_size(scissors), scissors.data());
}

void bind_vertex_buffers2(const functions&               ext,
                          command_buffer_handle          command_buffer,
                          std::uint32_t                  first_binding,
                          std::span<const buffer_handle> buffers,
                          std::span<const VkDeviceSize>  offsets,
                          std::span<const VkDeviceSize>  sizes,
                          std::span<const VkDeviceSize>  strides) noexcept
{
    auto buffer_handles = collect<VkBuffer>(buffers);

    return fubuki::invoke<"vkCmdBindVertexBuffers2EXT">(
        ext, command_buffer.vk, first_binding, vk_size(buffers), buffer_handles.data(), offsets.data(), sizes.data(), strides.data());
}

void set_depth_test_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_test_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthTestEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(depth_test_enable));
}

void set_depth_write_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_write_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthWriteEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(depth_write_enable));
}

void set_depth_compare_op(const functions& ext, command_buffer_handle command_buffer, VkCompareOp depth_compare_op) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthCompareOpEXT">(ext, command_buffer.vk, depth_compare_op);
}

void set_depth_bounds_test_enable(const functions& ext, command_buffer_handle command_buffer, bool depth_bounds_test_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthBoundsTestEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(depth_bounds_test_enable));
}

void set_stencil_test_enable(const functions& ext, command_buffer_handle command_buffer, bool stencil_test_enable) noexcept
{
    return fubuki::invoke<"vkCmdSetStencilTestEnableEXT">(ext, command_buffer.vk, static_cast<VkBool32>(stencil_test_enable));
}

void set_stencil_op(const functions&      ext,
                    command_buffer_handle command_buffer,
                    VkStencilFaceFlags    face_mask,
                    VkStencilOp           fail_op,
                    VkStencilOp           pass_op,
                    VkStencilOp           depth_fail_op,
                    VkCompareOp           compare_op) noexcept
{
    return fubuki::invoke<"vkCmdSetStencilOpEXT">(ext, command_buffer.vk, face_mask, fail_op, pass_op, depth_fail_op, compare_op);
}

#endif // defined(VK_EXT_extended_dynamic_state)

} // namespace fubuki::extension::ext_extended_dynamic_state::cmd
