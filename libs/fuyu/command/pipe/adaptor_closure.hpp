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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_ADAPTOR_CLOSURE_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_ADAPTOR_CLOSURE_HPP

#include <concepts>
#include <type_traits>

#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail
{

template<typename F>
requires(std::is_object_v<F> and std::same_as<F, std::remove_cv_t<F>> and std::invocable<F, flow>
         and std::same_as<std::invoke_result_t<F, flow>, flow>)
struct adaptor_closure
{
    F callable;

    flow operator()(flow pipe) noexcept(std::is_nothrow_invocable_v<F, flow>) { return std::invoke(std::move(callable), std::move(pipe)); }
};

template<typename F>
adaptor_closure(F) -> adaptor_closure<F>;

namespace traits
{

template<typename T>
struct is_adaptor_closure : std::false_type
{
};

template<typename D>
struct is_adaptor_closure<adaptor_closure<D>> : std::true_type
{
};

template<typename T>
concept adaptor_closure = is_adaptor_closure<T>::value;

} // namespace traits

template<traits::adaptor_closure next>
[[nodiscard]] inline decltype(auto) operator|(flow p, next&& next_closure) noexcept(std::is_nothrow_invocable_v<next, flow>)
{
    return std::invoke(std::forward<next>(next_closure), std::move(p));
}

} // namespace fubuki::fuyu::command::pipe::detail

#endif // FUBUKI_FUYU_COMMAND_PIPE_ADAPTOR_CLOSURE_HPP
