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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_QUERY_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_QUERY_HPP

#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"
#include "fuyu/command/query.hpp"

namespace fubuki::fuyu::command::pipe::detail::query
{

struct scope
{
    template<typename function, typename... arguments>
    requires(std::invocable<function, flow> and std::same_as<std::invoke_result_t<function, flow>, flow>)
    auto
    operator()(fuyu::any_query_pool_view pool, std::uint32_t query, VkQueryControlFlags flags, function&& func, arguments&&... args) const noexcept
    {
        return adaptor_closure{[p = pool, query, flags, f = std::forward<function>(func), ... a = std::forward<arguments>(args)](
                                   flow pipe) mutable noexcept(std::is_nothrow_invocable_v<function, flow, arguments...>) -> flow
                               {
                                   const fuyu::cmd::query_scope s{pipe.command_buffer(), p, query, flags};
                                   return std::invoke(f, std::move(pipe), std::forward<decltype(a)>(a)...);
                               }};
    }

    template<typename function, typename... arguments>
    requires(std::invocable<function, flow> and std::same_as<std::invoke_result_t<function, flow>, flow>)
    auto operator()(fuyu::any_query_pool_view pool, std::uint32_t query, function&& func, arguments&&... args) const noexcept
    {
        return adaptor_closure{[p = pool, query, f = std::forward<function>(func), ... a = std::forward<arguments>(args)](flow pipe) mutable noexcept(
                                   std::is_nothrow_invocable_v<function, flow, arguments...>) -> flow
                               {
                                   const fuyu::cmd::query_scope s{pipe.command_buffer(), p, query};
                                   return std::invoke(f, std::move(pipe), std::forward<decltype(a)>(a)...);
                               }};
    }
};

struct reset_pool
{
    auto operator()(fuyu::any_query_pool_view pool, std::uint32_t first_query, std::uint32_t query_count) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::query::reset_pool(f.command_buffer(), pool, first_query, query_count);
                                   return f;
                               }};
    }
};

struct copy_pool_results
{
    auto operator()(fuyu::any_query_pool_view query_pool,
                    std::uint32_t             first_query,
                    std::uint32_t             query_count,
                    buffer_handle             destination,
                    VkDeviceSize              offset,
                    VkDeviceSize              stride,
                    VkQueryResultFlags        flags = {}) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::query::copy_pool_results(
                                       f.command_buffer(), query_pool, first_query, query_count, destination, offset, stride, flags = {});
                                   return f;
                               }};
    }
};

struct write_timestamp
{
    auto operator()(VkPipelineStageFlagBits stage, fuyu::any_query_pool_view pool, std::uint32_t query) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::query::write_timestamp(f.command_buffer(), stage, pool, query);
                                   return f;
                               }};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail::query

#endif // FUBUKI_FUYU_COMMAND_PIPE_QUERY_HPP
