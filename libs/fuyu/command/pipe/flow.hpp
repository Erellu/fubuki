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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_FLOW_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_FLOW_HPP

#include <optional>

#include "fuyu/command/pipe/error.hpp"
#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu::command::pipe::detail
{

class flow
{
public:
    flow(const flow&)           = delete;
    flow operator=(const flow&) = delete;

    flow(flow&&) noexcept           = default;
    flow operator=(flow&&) noexcept = delete;

    [[nodiscard]] constexpr auto        command_buffer() const noexcept { return m_command_buffer; }
    [[nodiscard]] constexpr const auto& error() const noexcept { return m_error; }

private:

    flow(command_buffer_view c) noexcept : m_command_buffer{c} {}
    flow(command_buffer_view c, error::any error) noexcept : m_command_buffer{c}, m_error{error} {}

    command_buffer_view       m_command_buffer;
    std::optional<error::any> m_error = {};

    friend struct record; // Can only be created using flow::record
    friend struct submit; // Required to force a std::move() upon submission
};

namespace traits
{

template<typename T>
struct is_flow : std::false_type
{
};

template<>
struct is_flow<flow> : std::true_type
{
};

template<typename T>
concept flow = is_flow<T>::value;

} // namespace traits

} // namespace fubuki::fuyu::command::pipe::detail

#endif // FUBUKI_FUYU_COMMAND_PIPE_PIPELINE_HPP
