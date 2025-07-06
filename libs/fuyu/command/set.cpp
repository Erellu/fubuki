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

#include "fuyu/command/set.hpp"

#include <core/collect.hpp>

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command::set
{

namespace detail
{

#if defined(VK_VERSION_1_4)

void rendering_attachment_locations(command_buffer_view command_buffer, const VkRenderingAttachmentLocationInfo& locations) noexcept
{
    return fuyu::invoke<"vkCmdSetRenderingAttachmentLocations">(command_buffer, std::addressof(locations));
}

void rendering_attachment_indices(command_buffer_view command_buffer, const VkRenderingInputAttachmentIndexInfo& indices) noexcept
{
    return fuyu::invoke<"vkCmdSetRenderingInputAttachmentIndices">(command_buffer, std::addressof(indices));
}

#endif // defined(VK_VERSION_1_4)

} // namespace detail

void viewport(command_buffer_view command_buffer, std::uint32_t first, std::span<const VkViewport> viewports) noexcept
{
    return fuyu::invoke<"vkCmdSetViewport">(command_buffer, first, vk_size(viewports), viewports.data());
}

void scissor(command_buffer_view command_buffer, std::uint32_t first, std::span<const VkRect2D> scissors) noexcept
{
    return fuyu::invoke<"vkCmdSetScissor">(command_buffer, first, vk_size(scissors), scissors.data());
}

void line_width(command_buffer_view command_buffer, float width) noexcept { return fuyu::invoke<"vkCmdSetLineWidth">(command_buffer, width); }

void blend_constants(command_buffer_view command_buffer, std::span<const float, 4> constants) noexcept
{
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
    const float vk_constants[4]{constants[0], constants[1], constants[2], constants[3]};

    return fuyu::invoke<"vkCmdSetBlendConstants">(command_buffer, vk_constants);
}

namespace detph
{

void bias(command_buffer_view command_buffer, float constant_factor, float clamp, float slope_factor) noexcept
{
    return fuyu::invoke<"vkCmdSetDepthBias">(command_buffer, constant_factor, clamp, slope_factor);
}

void bounds(command_buffer_view command_buffer, float min, float max) noexcept
{
    return fuyu::invoke<"vkCmdSetDepthBounds">(command_buffer, min, max);
}

#if defined(VK_VERSION_1_3)

void test_enable(command_buffer_view command_buffer, bool enable) noexcept
{
    return fuyu::invoke<"vkCmdSetDepthTestEnable">(command_buffer, static_cast<VkBool32>(enable));
}

void write_enable(command_buffer_view command_buffer, bool enable) noexcept
{
    return fuyu::invoke<"vkCmdSetDepthWriteEnable">(command_buffer, static_cast<VkBool32>(enable));
}

void compare_op(command_buffer_view command_buffer, VkCompareOp op) noexcept { return fuyu::invoke<"vkCmdSetDepthCompareOp">(command_buffer, op); }

void bounds_test_enable(command_buffer_view command_buffer, bool enable) noexcept
{
    return fuyu::invoke<"vkCmdSetDepthBoundsTestEnable">(command_buffer, static_cast<VkBool32>(enable));
}

void bias_enable(command_buffer_view command_buffer, bool enable) noexcept
{
    return fuyu::invoke<"vkCmdSetDepthBiasEnable">(command_buffer, static_cast<VkBool32>(enable));
}

#endif // #if defined(VK_VERSION_1_3)

} // namespace detph

namespace stencil
{

void compare_mask(command_buffer_view command_buffer, VkStencilFaceFlags face, std::uint32_t mask) noexcept
{
    return fuyu::invoke<"vkCmdSetStencilCompareMask">(command_buffer, face, mask);
}

void write_mask(command_buffer_view command_buffer, VkStencilFaceFlags face, std::uint32_t mask) noexcept
{
    return fuyu::invoke<"vkCmdSetStencilWriteMask">(command_buffer, face, mask);
}

void reference(command_buffer_view command_buffer, VkStencilFaceFlags face, std::uint32_t reference) noexcept
{
    return fuyu::invoke<"vkCmdSetStencilReference">(command_buffer, face, reference);
}

#if defined(VK_VERSION_1_3)

void test_enable(command_buffer_view command_buffer, bool enable) noexcept
{
    return fuyu::invoke<"vkCmdSetStencilTestEnable">(command_buffer, static_cast<VkBool32>(enable));
}

void op(command_buffer_view command_buffer,
        VkStencilFaceFlags  face,
        VkStencilOp         fail,
        VkStencilOp         pass,
        VkStencilOp         depth_fail,
        VkCompareOp         compare) noexcept
{
    return fuyu::invoke<"vkCmdSetStencilOp">(command_buffer, face, fail, pass, depth_fail, compare);
}

#endif // #if defined(VK_VERSION_1_3)

} // namespace stencil

#if defined(VK_VERSION_1_1)
void device_mask(command_buffer_view command_buffer, std::uint32_t mask) noexcept { return fuyu::invoke<"vkCmdSetDeviceMask">(command_buffer, mask); }
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
void cull_mode(command_buffer_view command_buffer, VkCullModeFlags flags) noexcept { return fuyu::invoke<"vkCmdSetCullMode">(command_buffer, flags); }

void front_face(command_buffer_view command_buffer, VkFrontFace face) noexcept { return fuyu::invoke<"vkCmdSetFrontFace">(command_buffer, face); }

void primitive_topology(command_buffer_view command_buffer, VkPrimitiveTopology topology) noexcept
{
    return fuyu::invoke<"vkCmdSetPrimitiveTopology">(command_buffer, topology);
}

void viewport_with_count(command_buffer_view command_buffer, std::span<const VkViewport> viewports) noexcept
{
    return fuyu::invoke<"vkCmdSetViewportWithCount">(command_buffer, vk_size(viewports), viewports.data());
}

void scissor_with_count(command_buffer_view command_buffer, std::span<const VkRect2D> scissors) noexcept
{
    return fuyu::invoke<"vkCmdSetScissorWithCount">(command_buffer, vk_size(scissors), scissors.data());
}

void rasterizer_discard_enable(command_buffer_view command_buffer, bool enable) noexcept
{
    return fuyu::invoke<"vkCmdSetRasterizerDiscardEnable">(command_buffer, static_cast<VkBool32>(enable));
}

void primitive_restart_enable(command_buffer_view command_buffer, bool enable) noexcept
{
    return fuyu::invoke<"vkCmdSetPrimitiveRestartEnable">(command_buffer, static_cast<VkBool32>(enable));
}

#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)

void line_stipple(command_buffer_view command_buffer, std::uint32_t factor, std::uint16_t pattern) noexcept
{
    return fuyu::invoke<"vkCmdSetLineStipple">(command_buffer, factor, pattern);
}

#endif // defined(VK_VERSION_1_4)

} // namespace fubuki::fuyu::command::set
