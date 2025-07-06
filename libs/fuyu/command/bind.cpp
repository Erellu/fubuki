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

#include "fuyu/command/bind.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command::bind
{

namespace detail
{

void pipeline(command_buffer_view command_buffer, VkPipelineBindPoint point, VkPipeline p) noexcept
{
    return fuyu::invoke<"vkCmdBindPipeline">(command_buffer, point, p);
}

#if defined(VK_VERSION_1_4)

void descriptor_sets(command_buffer_view command_buffer, const VkBindDescriptorSetsInfo& info) noexcept
{
    return fuyu::invoke<"vkCmdBindDescriptorSets2">(command_buffer, std::addressof(info));
}

#endif // defined(VK_VERSION_1_4)

} // namespace detail

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

void index_buffer(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, VkIndexType index_type) noexcept
{
    return fuyu::invoke<"vkCmdBindIndexBuffer">(command_buffer, buffer.vk, offset, index_type);
}

//------------------------------------------------------------------------------

void vertex_buffers(command_buffer_view                  command_buffer,
                    const std::uint32_t                  first_binding,
                    const std::span<const buffer_handle> buffers,
                    const std::span<const VkDeviceSize>  offsets)
{
    const auto buffer_handles = collect<VkBuffer>(buffers);

    return fuyu::invoke<"vkCmdBindVertexBuffers">(command_buffer, first_binding, vk_size(buffer_handles), buffer_handles.data(), offsets.data());
}

void descriptor_sets(command_buffer_view                    command_buffer,
                     VkPipelineBindPoint                    bind_point,
                     pipeline_layout_handle                 layout,
                     uint32_t                               first_set,
                     std::span<const descriptor_set_handle> sets,
                     std::span<const std::uint32_t>         dynamic_offsets)
{
    const auto handles = collect<VkDescriptorSet>(sets);

    return fuyu::invoke<"vkCmdBindDescriptorSets">(
        command_buffer, bind_point, layout.vk, first_set, vk_size(handles), handles.data(), vk_size(dynamic_offsets), dynamic_offsets.data());
}

void pipeline(command_buffer_view command_buffer, graphics_pipeline_handle p) noexcept
{
    return detail::pipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, p.vk);
}

void pipeline(command_buffer_view command_buffer, compute_pipeline_handle p) noexcept
{
    return detail::pipeline(command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, p.vk);
}

#if defined(VK_KHR_ray_tracing_pipeline)
void pipeline(command_buffer_view command_buffer, ray_tracing_pipeline_khr_handle p) noexcept
{
    return detail::pipeline(command_buffer, VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR, p.vk);
}
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
void pipeline(command_buffer_view command_buffer, ray_tracing_pipeline_nv_handle p) noexcept
{
    return detail::pipeline(command_buffer, VK_PIPELINE_BIND_POINT_RAY_TRACING_NV, p.vk);
}
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_VERSION_1_3)

void vertex_buffers(command_buffer_view                                 command_buffer,
                    const std::uint32_t                                 first_binding,
                    std::span<const buffer_handle>                      buffers,
                    const std::span<const VkDeviceSize>                 offsets,
                    const std::optional<std::span<const VkDeviceSize> > sizes,
                    const std::optional<std::span<const VkDeviceSize> > strides)
{
    const auto buffer_handles = collect<VkBuffer>(buffers);

    const auto* const raw_buffers = buffer_handles.data();
    const auto* const raw_offsets = offsets.data();
    const auto* const raw_sizes   = sizes.has_value() ? sizes->data() : nullptr;
    const auto* const raw_strides = strides.has_value() ? strides->data() : nullptr;

    return fuyu::invoke<"vkCmdBindVertexBuffers2">(command_buffer, first_binding, vk_size(buffers), raw_buffers, raw_offsets, raw_sizes, raw_strides);
}

#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)

void index_buffer(command_buffer_view command_buffer, buffer_handle buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType index_type) noexcept
{
    return fuyu::invoke<"vkCmdBindIndexBuffer2">(command_buffer, buffer.vk, offset, size, index_type);
}

#endif // defined(VK_VERSION_1_4)

} // namespace fubuki::fuyu::command::bind
