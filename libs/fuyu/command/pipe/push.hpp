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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_PUSH_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_PUSH_HPP

#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"
#include "fuyu/command/push.hpp"

namespace fubuki::fuyu::command::pipe::detail::push
{

struct constants
{
    auto operator()(pipeline_layout_handle layout, VkShaderStageFlags stage, std::uint32_t offset, std::span<const std::byte> data) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::constants(f.command_buffer(), layout, stage, offset, data);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(pipeline_layout_handle          layout,
                    VkShaderStageFlags              stage,
                    std::uint32_t                   offset,
                    std::span<const std::byte>      data,
                    const pnext_chain<elements...>& pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::constants(f.command_buffer(), layout, stage, offset, data, pnext);
                                   return f;
                               }};
    }
};

struct descriptor_set
{
    auto operator()(VkPipelineBindPoint                   bind_point,
                    pipeline_layout_handle                layout,
                    std::uint32_t                         set,
                    std::span<const VkWriteDescriptorSet> writes) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set(f.command_buffer(), bind_point, layout, set, writes);
                                   return f;
                               }};
    }

    auto operator()(VkPipelineBindPoint                         bind_point,
                    pipeline_layout_handle                      layout,
                    std::uint32_t                               set,
                    std::initializer_list<VkWriteDescriptorSet> writes) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set(f.command_buffer(), bind_point, layout, set, writes);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(VkShaderStageFlags                    flags,
                    pipeline_layout_handle                layout,
                    std::uint32_t                         set,
                    std::span<const VkWriteDescriptorSet> writes,
                    const pnext_chain<elements...>&       pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set(f.command_buffer(), flags, layout, set, writes, pnext);
                                   return f;
                               }};
    }
};

struct descriptor_set_with_template
{
    template<typename T>
    auto
    operator()(descriptor_update_template_handle update, pipeline_layout_handle layout, std::uint32_t set, std::span<const T> data) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set_with_template(f.command_buffer(), update, layout, set, data);
                                   return f;
                               }};
    }

    template<typename T, typename... elements>
    auto operator()(descriptor_update_template_handle update,
                    pipeline_layout_handle            layout,
                    std::uint32_t                     set,
                    std::span<const T>                data,
                    const pnext_chain<elements...>&   pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set_with_template(f.command_buffer(), update, layout, set, data, pnext);
                                   return f;
                               }};
    }

    template<typename T>
    auto operator()(descriptor_update_template_handle update, pipeline_layout_handle layout, std::uint32_t set, const T& data) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set_with_template(f.command_buffer(), update, layout, set, data);
                                   return f;
                               }};
    }

    template<typename T, typename... elements>
    auto operator()(descriptor_update_template_handle update,
                    pipeline_layout_handle            layout,
                    std::uint32_t                     set,
                    const T&                          data,
                    const pnext_chain<elements...>&   pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set_with_template(f.command_buffer(), update, layout, set, data, pnext);
                                   return f;
                               }};
    }

    template<typename T>
    auto operator()(descriptor_update_template_handle update,
                    pipeline_layout_handle            layout,
                    std::uint32_t                     set,
                    std::initializer_list<T>          data) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set_with_template(f.command_buffer(), update, layout, set, data);
                                   return f;
                               }};
    }

    template<typename T, typename... elements>
    auto operator()(descriptor_update_template_handle update,
                    pipeline_layout_handle            layout,
                    std::uint32_t                     set,
                    std::initializer_list<T>          data,
                    const pnext_chain<elements...>&   pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::push::descriptor_set_with_template(f.command_buffer(), update, layout, set, data, pnext);
                                   return f;
                               }};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail::push

#endif // FUBUKI_FUYU_COMMAND_PIPE_PUSH_HPP
