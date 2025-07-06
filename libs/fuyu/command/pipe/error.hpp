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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_ERROR_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_ERROR_HPP

#include <ostream>
#include <variant>

#include <core/validate.hpp>

namespace fubuki::fuyu::command::pipe::detail::error
{

/// Indicates an error occurred upon starting the command buffer recording.
struct begin
{
    api_call_info value = {};

    [[nodiscard]] constexpr operator api_call_info() const noexcept { return value; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const begin& e)
    {
        return out << "pipe::error::begin{" << e.value << "}";
    }
};

/// Indicates an error occurred upon ending the command buffer recording.
struct end
{
    api_call_info value = {};

    [[nodiscard]] constexpr operator api_call_info() const noexcept { return value; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const end& e)
    {
        return out << "pipe::error::end{" << e.value << "}";
    }
};

/// Indicates an error occurred upon submission.
struct submit
{
    api_call_info value = {};

    [[nodiscard]] constexpr operator api_call_info() const noexcept { return value; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const submit& e)
    {
        return out << "pipe::error::submit{" << e.value << "}";
    }
};

/// Any error that can happen through pipes.
struct any
{
    using value_type = std::variant<begin, end, submit>;

    [[nodiscard]] constexpr operator api_call_info() const noexcept
    {
        return std::visit([](const auto& variant) noexcept { return variant.value; }, value);
    }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const any& e)
    {
        return std::visit([&out](const auto& variant) noexcept -> auto& { return out << variant; }, e.value);
    }

    value_type value = {};
};

} // namespace fubuki::fuyu::command::pipe::detail::error

#endif // FUBUKI_FUYU_COMMAND_PIPE_ERROR_HPP
