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

#ifndef FUBUKI_FUYU_COMMAND_BIND_HPP
#define FUBUKI_FUYU_COMMAND_BIND_HPP

#include <cstdint>
#include <initializer_list>
#include <optional>
#include <span>

#include <core/as_span.hpp>
#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

/// Commmands allowing to bind objects (pipelines, descriptor sets, buffers...).
namespace command::bind
{

namespace detail
{

#if defined(VK_VERSION_1_4)

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets2.html
 */
FUBUKI_FUYU_API
void descriptor_sets(command_buffer_view command_buffer, const VkBindDescriptorSetsInfo& info) noexcept;

#endif // defined(VK_VERSION_1_4)

} // namespace detail

/**
 * Bind an index buffer to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindIndexBuffer.html
 */
FUBUKI_FUYU_API
void index_buffer(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, VkIndexType index_type) noexcept;

/**
 * Bind vertex buffers to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers.html
 */
FUBUKI_FUYU_API
void vertex_buffers(command_buffer_view            command_buffer,
                    std::uint32_t                  first_binding,
                    std::span<const buffer_handle> buffers,
                    std::span<const VkDeviceSize>  offsets);

/**
 * Bind vertex buffers to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers.html
 */
inline void vertex_buffers(command_buffer_view                  command_buffer,
                           std::uint32_t                        first_binding,
                           std::initializer_list<buffer_handle> buffers,
                           std::span<const VkDeviceSize>        offsets)
{
    return vertex_buffers(command_buffer, first_binding, std::span{buffers}, offsets);
}

/**
 * Bind vertex buffers to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers.html
 */
inline void vertex_buffers(command_buffer_view                 command_buffer,
                           std::uint32_t                       first_binding,
                           std::span<const buffer_handle>      buffers,
                           std::initializer_list<VkDeviceSize> offsets)
{
    return vertex_buffers(command_buffer, first_binding, buffers, std::span{offsets});
}

/**
 * Bind vertex buffers to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers.html
 */
inline void vertex_buffers(command_buffer_view                  command_buffer,
                           std::uint32_t                        first_binding,
                           std::initializer_list<buffer_handle> buffers,
                           std::initializer_list<VkDeviceSize>  offsets)
{
    return vertex_buffers(command_buffer, first_binding, std::span{buffers}, std::span{offsets});
}

/**
 * Bind vertex buffers to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers.html
 */
inline void vertex_buffers(command_buffer_view command_buffer, std::uint32_t first_binding, buffer_handle buffer, VkDeviceSize offset)
{
    return vertex_buffers(command_buffer, first_binding, fubuki::as_span(buffer), fubuki::as_span(offset));
}

/**
 * Bind vertex buffers to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers.html
 */
inline void vertex_buffer(command_buffer_view command_buffer, std::uint32_t first_binding, buffer_handle buffer, VkDeviceSize offset)
{
    return vertex_buffers(command_buffer, first_binding, fubuki::as_span(buffer), fubuki::as_span(offset));
}

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets.html
 */
FUBUKI_FUYU_API
void descriptor_sets(command_buffer_view                    command_buffer,
                     VkPipelineBindPoint                    bind_point,
                     pipeline_layout_handle                 layout,
                     uint32_t                               first_set,
                     std::span<const descriptor_set_handle> sets,
                     std::span<const std::uint32_t>         dynamic_offsets);

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets.html
 */
inline void descriptor_sets(command_buffer_view                          command_buffer,
                            VkPipelineBindPoint                          bind_point,
                            pipeline_layout_handle                       layout,
                            uint32_t                                     first_set,
                            std::initializer_list<descriptor_set_handle> sets,
                            std::span<const std::uint32_t>               dynamic_offsets)
{
    return descriptor_sets(command_buffer, bind_point, layout, first_set, std::span{sets}, dynamic_offsets);
}

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets.html
 */
inline void descriptor_sets(command_buffer_view                    command_buffer,
                            VkPipelineBindPoint                    bind_point,
                            pipeline_layout_handle                 layout,
                            uint32_t                               first_set,
                            std::span<const descriptor_set_handle> sets,
                            std::initializer_list<std::uint32_t>   dynamic_offsets)
{
    return descriptor_sets(command_buffer, bind_point, layout, first_set, sets, std::span{dynamic_offsets});
}

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets.html
 */
inline void descriptor_sets(command_buffer_view                          command_buffer,
                            VkPipelineBindPoint                          bind_point,
                            pipeline_layout_handle                       layout,
                            uint32_t                                     first_set,
                            std::initializer_list<descriptor_set_handle> sets,
                            std::initializer_list<std::uint32_t>         dynamic_offsets)
{
    return descriptor_sets(command_buffer, bind_point, layout, first_set, std::span{sets}, std::span{dynamic_offsets});
}

/**
 * Bind a pipeline object to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindPipeline.html
 */
FUBUKI_FUYU_API void pipeline(command_buffer_view command_buffer, graphics_pipeline_handle p) noexcept;

/**
 * Bind a pipeline object to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindPipeline.html
 */
FUBUKI_FUYU_API void pipeline(command_buffer_view command_buffer, compute_pipeline_handle p) noexcept;

#if defined(VK_KHR_ray_tracing_pipeline)
/**
 * Bind a pipeline object to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindPipeline.html
 */
FUBUKI_FUYU_API void pipeline(command_buffer_view command_buffer, ray_tracing_pipeline_khr_handle p) noexcept;
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
/**
 * Bind a pipeline object to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindPipeline.html
 */
FUBUKI_FUYU_API void pipeline(command_buffer_view command_buffer, ray_tracing_pipeline_nv_handle p) noexcept;
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_VERSION_1_3)

/**
 * Bind vertex buffers to a command buffer and dynamically sets strides.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers2EXT.html
 */
FUBUKI_FUYU_API void vertex_buffers(command_buffer_view                          command_buffer,
                                    std::uint32_t                                first_binding,
                                    std::span<const buffer_handle>               buffers,
                                    std::span<const VkDeviceSize>                offsets,
                                    std::optional<std::span<const VkDeviceSize>> sizes,
                                    std::optional<std::span<const VkDeviceSize>> strides);

/**
 * Bind vertex buffers to a command buffer and dynamically sets strides.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers2EXT.html
 */
inline void vertex_buffers(command_buffer_view                          command_buffer,
                           std::uint32_t                                first_binding,
                           std::initializer_list<buffer_handle>         buffers,
                           std::span<const VkDeviceSize>                offsets,
                           std::optional<std::span<const VkDeviceSize>> sizes,
                           std::optional<std::span<const VkDeviceSize>> strides)
{
    return vertex_buffers(command_buffer, first_binding, std::span{buffers}, offsets, sizes, strides);
}

/**
 * Bind vertex buffers to a command buffer and dynamically sets strides.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers2EXT.html
 */
inline void vertex_buffers(command_buffer_view                          command_buffer,
                           std::uint32_t                                first_binding,
                           std::span<const buffer_handle>               buffers,
                           std::initializer_list<VkDeviceSize>          offsets,
                           std::optional<std::span<const VkDeviceSize>> sizes,
                           std::optional<std::span<const VkDeviceSize>> strides)
{
    return vertex_buffers(command_buffer, first_binding, buffers, std::span{offsets}, sizes, strides);
}

/**
 * Bind vertex buffers to a command buffer and dynamically sets strides.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindVertexBuffers2EXT.html
 */
inline void vertex_buffers(command_buffer_view                          command_buffer,
                           std::uint32_t                                first_binding,
                           std::initializer_list<buffer_handle>         buffers,
                           std::initializer_list<VkDeviceSize>          offsets,
                           std::optional<std::span<const VkDeviceSize>> sizes,
                           std::optional<std::span<const VkDeviceSize>> strides)
{
    return vertex_buffers(command_buffer, first_binding, std::span{buffers}, std::span{offsets}, sizes, strides);
}

#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)

/**
 * Bind an index buffer to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindIndexBuffer.html
 */
FUBUKI_FUYU_API
void index_buffer(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType index_type) noexcept;

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets2.html
 */
template<typename... elements>
inline void descriptor_sets(command_buffer_view                    command_buffer,
                            VkShaderStageFlags                     stages,
                            pipeline_layout_handle                 layout,
                            uint32_t                               first_set,
                            std::span<const descriptor_set_handle> sets,
                            std::span<const std::uint32_t>         dynamic_offsets,
                            const pnext_chain<elements...>&        pnext)
{
    const auto handles = collect<VkDescriptorSet>(sets);

    VkBindDescriptorSetsInfo vk_info{
        .sType              = structure_type_v<VkBindDescriptorSetsInfo>,
        .pNext              = {},
        .stageFlags         = stages,
        .layout             = layout.vk,
        .firstSet           = first_set,
        .descriptorSetCount = vk_size(handles),
        .pDescriptorSets    = handles.data(),
        .dynamicOffsetCount = vk_size(dynamic_offsets),
        .pDynamicOffsets    = dynamic_offsets.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::descriptor_sets(command_buffer, vk_info);
}

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets2.html
 */
template<typename... elements>
inline void descriptor_sets(command_buffer_view                          command_buffer,
                            VkShaderStageFlags                           stages,
                            pipeline_layout_handle                       layout,
                            uint32_t                                     first_set,
                            std::initializer_list<descriptor_set_handle> sets,
                            std::span<const std::uint32_t>               dynamic_offsets,
                            const pnext_chain<elements...>&              pnext)
{
    return descriptor_sets(command_buffer, stages, layout, first_set, std::span{sets}, dynamic_offsets, pnext);
}

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets2.html
 */
template<typename... elements>
inline void descriptor_sets(command_buffer_view                    command_buffer,
                            VkShaderStageFlags                     stages,
                            pipeline_layout_handle                 layout,
                            uint32_t                               first_set,
                            std::span<const descriptor_set_handle> sets,
                            std::initializer_list<std::uint32_t>   dynamic_offsets,
                            const pnext_chain<elements...>&        pnext)
{
    return descriptor_sets(command_buffer, stages, layout, first_set, sets, std::span{dynamic_offsets}, pnext);
}

/**
 * Bind descriptor sets to a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets2.html
 */
template<typename... elements>
inline void descriptor_sets(command_buffer_view                          command_buffer,
                            VkShaderStageFlags                           stages,
                            pipeline_layout_handle                       layout,
                            uint32_t                                     first_set,
                            std::initializer_list<descriptor_set_handle> sets,
                            std::initializer_list<std::uint32_t>         dynamic_offsets,
                            const pnext_chain<elements...>&              pnext)
{
    return descriptor_sets(command_buffer, stages, layout, first_set, std::span{sets}, std::span{dynamic_offsets}, pnext);
}

#endif // defined(VK_VERSION_1_4)

} // namespace command::bind

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_BIND_HPP
