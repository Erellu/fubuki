﻿/*
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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_CUSTOM_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_CUSTOM_HPP

#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail
{

struct custom
{
    template<typename function, typename... arguments>
    requires(std::is_invocable_v<function, flow, arguments...> and std::same_as<std::invoke_result_t<function, flow, arguments...>, flow>)
    auto operator()(function&& func, arguments&&... args) const noexcept
    {
        return adaptor_closure{[... a = std::forward<arguments>(args), executable = std::forward<function>(func)](flow f) mutable noexcept(
                                   std::is_nothrow_invocable_v<function, flow, arguments...>) -> flow
                               { return std::invoke(executable, std::move(f), std::forward<decltype(a)>(a)...); }};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail

#endif // FUBUKI_FUYU_COMMAND_PIPE_CUSTOM_HPP
