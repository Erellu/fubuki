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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_BIND_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_BIND_HPP

#include "fuyu/command/bind.hpp"
#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail::bind
{

struct descriptor_sets
{
    auto operator()(VkPipelineBindPoint                    bind_point,
                    pipeline_layout_handle                 layout,
                    uint32_t                               first_set,
                    std::span<const descriptor_set_handle> sets,
                    std::span<const std::uint32_t>         dynamic_offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), bind_point, layout, first_set, sets, dynamic_offsets);
                                   return f;
                               }};
    }

    auto operator()(VkPipelineBindPoint                          bind_point,
                    pipeline_layout_handle                       layout,
                    uint32_t                                     first_set,
                    std::initializer_list<descriptor_set_handle> sets,
                    std::span<const std::uint32_t>               dynamic_offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), bind_point, layout, first_set, sets, dynamic_offsets);
                                   return f;
                               }};
    }

    auto operator()(VkPipelineBindPoint                    bind_point,
                    pipeline_layout_handle                 layout,
                    uint32_t                               first_set,
                    std::span<const descriptor_set_handle> sets,
                    std::initializer_list<std::uint32_t>   dynamic_offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), bind_point, layout, first_set, sets, dynamic_offsets);
                                   return f;
                               }};
    }

    auto operator()(VkPipelineBindPoint                          bind_point,
                    pipeline_layout_handle                       layout,
                    uint32_t                                     first_set,
                    std::initializer_list<descriptor_set_handle> sets,
                    std::initializer_list<std::uint32_t>         dynamic_offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), bind_point, layout, first_set, sets, dynamic_offsets);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(VkShaderStageFlags                     stages,
                    pipeline_layout_handle                 layout,
                    uint32_t                               first_set,
                    std::span<const descriptor_set_handle> sets,
                    std::span<const std::uint32_t>         dynamic_offsets,
                    const pnext_chain<elements...>&        pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), stages, layout, first_set, sets, dynamic_offsets, pnext);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(VkShaderStageFlags                           stages,
                    pipeline_layout_handle                       layout,
                    uint32_t                                     first_set,
                    std::initializer_list<descriptor_set_handle> sets,
                    std::span<const std::uint32_t>               dynamic_offsets,
                    const pnext_chain<elements...>&              pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), stages, layout, first_set, sets, dynamic_offsets, pnext);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(VkShaderStageFlags                     stages,
                    pipeline_layout_handle                 layout,
                    uint32_t                               first_set,
                    std::span<const descriptor_set_handle> sets,
                    std::initializer_list<std::uint32_t>   dynamic_offsets,
                    const pnext_chain<elements...>&        pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), stages, layout, first_set, sets, dynamic_offsets, pnext);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(VkShaderStageFlags                           stages,
                    pipeline_layout_handle                       layout,
                    uint32_t                                     first_set,
                    std::initializer_list<descriptor_set_handle> sets,
                    std::initializer_list<std::uint32_t>         dynamic_offsets,
                    const pnext_chain<elements...>&              pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::descriptor_sets(f.command_buffer(), stages, layout, first_set, sets, dynamic_offsets, pnext);
                                   return f;
                               }};
    }
};

struct index_buffer
{
    auto operator()(buffer_handle buffer, VkDeviceSize offset, VkIndexType index_type) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::index_buffer(f.command_buffer(), buffer, offset, index_type);
                                   return f;
                               }};
    }

    auto operator()(buffer_handle buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType index_type) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::index_buffer(f.command_buffer(), buffer, offset, size, index_type);
                                   return f;
                               }};
    }
};

struct pipeline
{
    auto operator()(graphics_pipeline_handle p) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::pipeline(f.command_buffer(), p);
                                   return f;
                               }};
    }

    auto operator()(compute_pipeline_handle p) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::pipeline(f.command_buffer(), p);
                                   return f;
                               }};
    }

#if defined(VK_KHR_ray_tracing_pipeline)
    auto operator()(ray_tracing_pipeline_khr_handle p) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::pipeline(f.command_buffer(), p);
                                   return f;
                               }};
    }
#endif // defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    auto operator()(ray_tracing_pipeline_nv_handle p) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::pipeline(f.command_buffer(), p);
                                   return f;
                               }};
    }
#endif // defined(VK_NV_ray_tracing)
};

struct vertex_buffers
{
    auto operator()(std::uint32_t first_binding, std::span<const buffer_handle> buffers, std::span<const VkDeviceSize> offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t first_binding, std::initializer_list<buffer_handle> buffers, std::span<const VkDeviceSize> offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t first_binding, std::span<const buffer_handle> buffers, std::initializer_list<VkDeviceSize> offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets);
                                   return f;
                               }};
    }

    auto
    operator()(std::uint32_t first_binding, std::initializer_list<buffer_handle> buffers, std::initializer_list<VkDeviceSize> offsets) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t                                first_binding,
                    std::span<const buffer_handle>               buffers,
                    std::span<const VkDeviceSize>                offsets,
                    std::optional<std::span<const VkDeviceSize>> sizes,
                    std::optional<std::span<const VkDeviceSize>> stride) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets, sizes, stride);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t                                first_binding,
                    std::initializer_list<buffer_handle>         buffers,
                    std::span<const VkDeviceSize>                offsets,
                    std::optional<std::span<const VkDeviceSize>> sizes,
                    std::optional<std::span<const VkDeviceSize>> stride) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets, sizes, stride);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t                                first_binding,
                    std::span<const buffer_handle>               buffers,
                    std::initializer_list<VkDeviceSize>          offsets,
                    std::optional<std::span<const VkDeviceSize>> sizes,
                    std::optional<std::span<const VkDeviceSize>> strides) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets, sizes, strides);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t                                first_binding,
                    std::initializer_list<buffer_handle>         buffers,
                    std::initializer_list<VkDeviceSize>          offsets,
                    std::optional<std::span<const VkDeviceSize>> sizes,
                    std::optional<std::span<const VkDeviceSize>> stride) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffers(f.command_buffer(), first_binding, buffers, offsets, sizes, stride);
                                   return f;
                               }};
    }
};

struct vertex_buffer
{
    auto operator()(std::uint32_t first_binding, buffer_handle buffer, VkDeviceSize offset) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::bind::vertex_buffer(f.command_buffer(), first_binding, buffer, offset);
                                   return f;
                               }};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail::bind

#endif // FUBUKI_FUYU_COMMAND_PIPE_BIND_HPP
