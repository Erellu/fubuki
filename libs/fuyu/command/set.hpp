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

#ifndef FUBUKI_FUYU_COMMAND_SET_HPP
#define FUBUKI_FUYU_COMMAND_SET_HPP

#include <initializer_list>
#include <span>

#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

/// Commands modifying dynamic states during recording of a command buffer.
namespace command::set
{

namespace detail
{

#if defined(VK_VERSION_1_4)

/**
 * Set color attachment location mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingAttachmentLocations.html
 */
FUBUKI_FUYU_API void rendering_attachment_locations(command_buffer_view command_buffer, const VkRenderingAttachmentLocationInfo& locations) noexcept;

/**
 * Set input attachment index mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingInputAttachmentIndices.html
 */
FUBUKI_FUYU_API void rendering_attachment_indices(command_buffer_view command_buffer, const VkRenderingInputAttachmentIndexInfo& indices) noexcept;

#endif // defined(VK_VERSION_1_4)

} // namespace detail

/**
 * Set the viewport dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewport.html
 */
FUBUKI_FUYU_API void viewport(command_buffer_view command_buffer, std::uint32_t first, std::span<const VkViewport> viewports) noexcept;

/**
 * Set the viewport dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewport.html
 */
inline void viewport(command_buffer_view command_buffer, std::uint32_t first, std::initializer_list<VkViewport> viewports) noexcept
{
    return viewport(command_buffer, first, std::span{viewports});
}

/**
 * Set scissor rectangles dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissor.html
 */
FUBUKI_FUYU_API void scissor(command_buffer_view command_buffer, std::uint32_t first, std::span<const VkRect2D> scissors) noexcept;

/**
 * Set scissor rectangles dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissor.html
 */
inline void scissor(command_buffer_view command_buffer, std::uint32_t first, std::initializer_list<VkRect2D> scissors) noexcept
{
    return scissor(command_buffer, first, std::span{scissors});
}

/**
 * Set line width dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetLineWidth.html
 */
FUBUKI_FUYU_API void line_width(command_buffer_view command_buffer, float width) noexcept;

/**
 * Set the values of blend constants.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetBlendConstants.html
 */
FUBUKI_FUYU_API void blend_constants(command_buffer_view command_buffer, std::span<const float, 4> constants) noexcept;

/**
 * Set the values of blend constants.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetBlendConstants.html
 */
inline void blend_constants(command_buffer_view command_buffer, std::array<float, 4> constants) noexcept
{
    return blend_constants(command_buffer, std::span{constants});
}

namespace depth
{

/**
 * Set depth bias factors and clamp dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBias.html
 */
FUBUKI_FUYU_API void bias(command_buffer_view command_buffer, float constant_factor, float clamp, float slope_factor) noexcept;

/**
 * Set depth bounds range dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBounds.html
 */
FUBUKI_FUYU_API void bounds(command_buffer_view command_buffer, float min, float max) noexcept;

#if defined(VK_VERSION_1_3)

/**
 * Set depth test enable dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthTestEnable.html
 */
FUBUKI_FUYU_API void test_enable(command_buffer_view command_buffer, bool enable) noexcept;

/**
 * Set depth write enable dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthWriteEnable.html
 */
FUBUKI_FUYU_API void write_enable(command_buffer_view command_buffer, bool enable) noexcept;

/**
 * Set depth comparison operator dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthCompareOp.html
 */
FUBUKI_FUYU_API void compare_op(command_buffer_view command_buffer, VkCompareOp op) noexcept;

/**
 * Set depth bounds test enable dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBoundsTestEnable.html
 */
FUBUKI_FUYU_API void bounds_test_enable(command_buffer_view command_buffer, bool enable) noexcept;

/**
 * Control whether to bias fragment depth values dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBiasEnable.html
 */
FUBUKI_FUYU_API void bias_enable(command_buffer_view command_buffer, bool enable) noexcept;

#endif // #if defined(VK_VERSION_1_3)

} // namespace depth

namespace stencil
{

/**
 * Set stencil compare mask dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilCompareMask.html
 */
FUBUKI_FUYU_API void compare_mask(command_buffer_view command_buffer, VkStencilFaceFlags face, std::uint32_t mask) noexcept;

/**
 * Set stencil write mask dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilWriteMask.html
 */
FUBUKI_FUYU_API void write_mask(command_buffer_view command_buffer, VkStencilFaceFlags face, std::uint32_t mask) noexcept;

/**
 * Set stencil reference value dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilReference.html
 */
FUBUKI_FUYU_API void reference(command_buffer_view command_buffer, VkStencilFaceFlags face, std::uint32_t reference) noexcept;

#if defined(VK_VERSION_1_3)

/**
 * Set stencil test enable dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilTestEnable.html
 */
FUBUKI_FUYU_API void test_enable(command_buffer_view command_buffer, bool enable) noexcept;

/**
 * Set stencil operation dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilOp.html
 */
FUBUKI_FUYU_API void op(command_buffer_view command_buffer,
                        VkStencilFaceFlags  face,
                        VkStencilOp         fail,
                        VkStencilOp         pass,
                        VkStencilOp         depth_fail,
                        VkCompareOp         compare) noexcept;

#endif // #if defined(VK_VERSION_1_3)

} // namespace stencil

#if defined(VK_VERSION_1_1)
/**
 * Modify device mask of a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDeviceMask.html
 */
FUBUKI_FUYU_API void device_mask(command_buffer_view command_buffer, std::uint32_t mask) noexcept;
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
/**
 * Set cull mode dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCullMode.html
 */
FUBUKI_FUYU_API void cull_mode(command_buffer_view command_buffer, VkCullModeFlags flags) noexcept;

/**
 * Set front face orientation dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetFrontFace.html
 */
FUBUKI_FUYU_API void front_face(command_buffer_view command_buffer, VkFrontFace face) noexcept;

/**
 * Set primitive topology state dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPrimitiveTopology.html
 */
FUBUKI_FUYU_API void primitive_topology(command_buffer_view command_buffer, VkPrimitiveTopology topology) noexcept;

/**
 * Set the viewport count and viewports dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportWithCount.html
 */
FUBUKI_FUYU_API void viewport_with_count(command_buffer_view command_buffer, std::span<const VkViewport> viewports) noexcept;

/**
 * Set the viewport count and viewports dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportWithCount.html
 */
inline void viewport_with_count(command_buffer_view command_buffer, std::initializer_list<VkViewport> viewports) noexcept
{
    return viewport_with_count(command_buffer, std::span{viewports});
}

/**
 * Set the scissor count and scissor rectangular bounds dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissorWithCount.html
 */
FUBUKI_FUYU_API void scissor_with_count(command_buffer_view command_buffer, std::span<const VkRect2D> scissors) noexcept;

/**
 * Set the scissor count and scissor rectangular bounds dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissorWithCount.html
 */
inline void scissor_with_count(command_buffer_view command_buffer, std::initializer_list<VkRect2D> scissors) noexcept
{
    return scissor_with_count(command_buffer, std::span{scissors});
}

/**
 * Control whether primitives are discarded before the rasterization stage dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRasterizerDiscardEnable.html
 */
FUBUKI_FUYU_API void rasterizer_discard_enable(command_buffer_view command_buffer, bool enable) noexcept;

/**
 * Set primitive assembly restart state dynamically for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPrimitiveRestartEnable.html
 */
FUBUKI_FUYU_API void primitive_restart_enable(command_buffer_view command_buffer, bool enable) noexcept;

#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)

/**
 * Set line stipple dynamically for a command buffer
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetLineStipple.html
 */
FUBUKI_FUYU_API void line_stipple(command_buffer_view command_buffer, std::uint32_t factor, std::uint16_t pattern) noexcept;

/**
 * Set colour attachment location mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingAttachmentLocations.html
 */
template<typename... elements>
inline void rendering_attachment_locations(command_buffer_view             command_buffer,
                                           std::span<const std::uint32_t>  locations,
                                           const pnext_chain<elements...>& pnext) noexcept
{
    VkRenderingAttachmentLocationInfo vk_info{
        .sType                     = structure_type_v<VkRenderingAttachmentLocationInfo>,
        .pNext                     = {},
        .colorAttachmentCount      = vk_size(locations),
        .pColorAttachmentLocations = locations.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::rendering_attachment_locations(command_buffer, vk_info);
}

/**
 * Set colour attachment location mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingAttachmentLocations.html
 */
template<typename... elements>
inline void rendering_attachment_locations(command_buffer_view                  command_buffer,
                                           std::initializer_list<std::uint32_t> locations,
                                           const pnext_chain<elements...>&      pnext) noexcept
{
    return rendering_attachment_locations(command_buffer, locations, pnext);
}

/**
 * Set colour attachment location mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingAttachmentLocations.html
 */
inline void rendering_attachment_locations(command_buffer_view command_buffer, std::span<const std::uint32_t> locations) noexcept
{
    return rendering_attachment_locations(command_buffer, locations, empty_pnext_chain);
}

/**
 * Set colour attachment location mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingAttachmentLocations.html
 */
inline void rendering_attachment_locations(command_buffer_view command_buffer, std::initializer_list<std::uint32_t> locations) noexcept
{
    return rendering_attachment_locations(command_buffer, std::span{locations});
}

/**
 * Set input attachment index mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingInputAttachmentIndices.html
 */
template<typename... elements>
inline void rendering_attachment_indices(command_buffer_view             command_buffer,
                                         std::span<const std::uint32_t>  colour_attachment_indices,
                                         std::optional<std::uint32_t>    depth_index,
                                         std::optional<std::uint32_t>    stencil_index,
                                         const pnext_chain<elements...>& pnext) noexcept
{
    const auto depth   = depth_index.value_or(0);
    const auto stencil = stencil_index.value_or(0);

    VkRenderingInputAttachmentIndexInfo vk_info{
        .sType                        = structure_type_v<VkRenderingInputAttachmentIndexInfo>,
        .pNext                        = {},
        .colorAttachmentCount         = vk_size(colour_attachment_indices),
        .pColorAttachmentInputIndices = colour_attachment_indices.data(),
        .pDepthInputAttachmentIndex   = depth_index.has_value() ? std::addressof(depth) : nullptr,
        .pStencilInputAttachmentIndex = stencil_index.has_value() ? std::addressof(stencil) : nullptr,
    };

    fubuki::extend(vk_info, pnext);

    return detail::rendering_attachment_indices(command_buffer, vk_info);
}

/**
 * Set input attachment index mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingInputAttachmentIndices.html
 */
template<typename... elements>
inline void rendering_attachment_indices(command_buffer_view                  command_buffer,
                                         std::initializer_list<std::uint32_t> colour_attachment_indices,
                                         std::optional<std::uint32_t>         depth_index,
                                         std::optional<std::uint32_t>         stencil_index,
                                         const pnext_chain<elements...>&      pnext) noexcept
{
    return rendering_attachment_indices(command_buffer, std::span{colour_attachment_indices}, depth_index, stencil_index, pnext);
}

/**
 * Set input attachment index mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingInputAttachmentIndices.html
 */
inline void rendering_attachment_indices(command_buffer_view            command_buffer,
                                         std::span<const std::uint32_t> colour_attachment_indices,
                                         std::optional<std::uint32_t>   depth_index   = {},
                                         std::optional<std::uint32_t>   stencil_index = {}) noexcept
{
    return rendering_attachment_indices(command_buffer, colour_attachment_indices, depth_index, stencil_index, empty_pnext_chain);
}

/**
 * Set input attachment index mappings for a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingInputAttachmentIndices.html
 */
inline void rendering_attachment_indices(command_buffer_view                  command_buffer,
                                         std::initializer_list<std::uint32_t> colour_attachment_indices,
                                         std::optional<std::uint32_t>         depth_index   = {},
                                         std::optional<std::uint32_t>         stencil_index = {}) noexcept
{
    return rendering_attachment_indices(command_buffer, std::span{colour_attachment_indices}, depth_index, stencil_index);
}

#endif // defined(VK_VERSION_1_4)

} // namespace command::set

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_SET_HPP
