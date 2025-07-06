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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_RENDER_SCOPE_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_RENDER_SCOPE_HPP

#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"
#include "fuyu/command/render.hpp"

namespace fubuki::fuyu::command::pipe::detail
{

struct render_scope
{
    template<typename function, typename... arguments>
    requires(std::invocable<function, flow, arguments...> and std::same_as<std::invoke_result_t<function, flow, arguments...>, flow>)
    auto operator()(cmd::render_target target, VkSubpassContents contents, function&& func, arguments&&... args) const noexcept
    {
        return adaptor_closure{[t = std::move(target), contents, f = std::forward<function>(func), ... a = std::forward<arguments>(args)](
                                   flow pipe) mutable noexcept(std::is_nothrow_invocable_v<function, flow, arguments...>) -> flow
                               {
                                   const fuyu::cmd::rendering_scope scope{pipe.command_buffer(), t, contents};
                                   return std::invoke(f, std::move(pipe), std::forward<decltype(a)>(a)...);
                               }};
    }

    template<typename function, typename... arguments, typename... pnext_elements>
    requires(std::invocable<function, flow, arguments...> and std::same_as<std::invoke_result_t<function, flow, arguments...>, flow>)
    auto operator()(cmd::render_target                    target,
                    VkSubpassContents                     contents,
                    const pnext_chain<pnext_elements...>& pnext,
                    function&&                            func,
                    arguments&&... args) const noexcept
    {
        return adaptor_closure{[t = std::move(target), pnext, contents, f = std::forward<function>(func), ... a = std::forward<arguments>(args)](
                                   flow pipe) mutable noexcept(std::is_nothrow_invocable_v<function, flow, arguments...>) -> flow
                               {
                                   const fuyu::cmd::rendering_scope scope{pipe.command_buffer(), t, contents, pnext};
                                   return std::invoke(f, std::move(pipe), std::forward<decltype(a)>(a)...);
                               }};
    }

    template<typename function, typename... arguments>
    requires(std::invocable<function, flow, arguments...> and std::same_as<std::invoke_result_t<function, flow, arguments...>, flow>)
    auto operator()(cmd::dynamic_render_target target, function&& func, arguments&&... args) const noexcept
    {
        return adaptor_closure{[t = std::move(target), f = std::forward<function>(func), ... a = std::forward<arguments>(args)](
                                   flow pipe) mutable noexcept(std::is_nothrow_invocable_v<function, flow, arguments...>) -> flow
                               {
                                   const fuyu::cmd::rendering_scope scope{pipe.command_buffer(), t};
                                   return std::invoke(f, std::move(pipe), std::forward<decltype(a)>(a)...);
                               }};
    }

    template<typename function, typename... arguments, typename... pnext_elements>
    requires(std::invocable<function, flow, arguments...> and std::same_as<std::invoke_result_t<function, flow, arguments...>, flow>)
    auto
    operator()(cmd::dynamic_render_target target, const pnext_chain<pnext_elements...>& pnext, function&& func, arguments&&... args) const noexcept
    {
        return adaptor_closure{[t = std::move(target), pnext, f = std::forward<function>(func), ... a = std::forward<arguments>(args)](
                                   flow pipe) mutable noexcept(std::is_nothrow_invocable_v<function, flow, arguments...>) -> flow
                               {
                                   const fuyu::cmd::rendering_scope scope{pipe.command_buffer(), t, pnext};
                                   return std::invoke(f, std::move(pipe), std::forward<decltype(a)>(a)...);
                               }};
    }
};

struct next_subpass
{
    auto operator()(VkSubpassContents contents) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::next_subpass(f.command_buffer(), contents);
                                   return f;
                               }};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail

#endif // FUBUKI_FUYU_COMMAND_PIPE_RENDER_SCOPE_HPP
