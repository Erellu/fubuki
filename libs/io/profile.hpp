/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2022-2024, Erwan DUHAMEL
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

#ifndef FUBUKI_IO_PROFILE_HPP
#define FUBUKI_IO_PROFILE_HPP

#include <chrono>
#include <cstdint>
#include <ctime>
#include <expected>
#include <functional>
#include <type_traits>
#include <variant>

#include <core/config/macros.hpp>
#include <io/platform/error.hpp>
#include <io/platform/profile_data.hpp>

namespace fubuki::io
{

using profile_data = platform::profile_data::any;

[[nodiscard]] FUBUKI_IO_API std::expected<profile_data, platform::error::api_call> begin_profile() noexcept;

[[nodiscard]] FUBUKI_IO_API std::expected<std::chrono::microseconds, platform::error::api_call> end_profile(const profile_data& begin) noexcept;

template<typename func, typename... args>
requires(std::invocable<func, args...>)
struct profile_result
{
    using invoke_result = std::invoke_result_t<func, args...>;
    using value_type    = std::conditional_t<std::is_void_v<invoke_result>, std::monostate, invoke_result>;

    FUBUKI_NO_UNIQUE_ADDRESS value_type result;
    std::chrono::microseconds           duration;
};

/**
 * @brief Profiles the execution of a function.
 * @param f Call to profile.
 * @param arguments Arguments to provide to the function upon call.
 *
 * @section example Example
 *
 * @code{.cpp}
 *
 * const auto r = fubuki::profile([&]() noexcept{something();});
 * if(r.has_value())
 * {
 *     std::print("Execution took {} us", r.duration);
 *     use(r.result);
 * }
 * else
 * {
 *     handle(r.error());
 * }
 * @endcode
 */
template<typename func, typename... args>
[[nodiscard]]
inline std::expected<profile_result<func, args...>, platform::error::api_call>
profile(func&& f, args&&... arguments) noexcept(std::is_nothrow_invocable_v<func, args...>)
{
    using invoke_result = typename profile_result<func, args...>::invoke_result;

    constexpr auto invoke = []<typename invocable_t, typename... arguments_t>(invocable_t&& invocable, arguments_t&&... a) noexcept(
                                std::is_nothrow_invocable_v<func, args...>) -> profile_result<func, args...>
    {
        if constexpr(std::is_void_v<invoke_result>)
        {
            std::invoke(std::forward<func>(invocable), std::forward<args>(a)...);
            return {};
        }
        else
        {
            return {.result = std::invoke(std::forward<func>(invocable), std::forward<args>(a)...), .duration = {}};
        }
    };

    const auto begin = begin_profile();

    if(not begin.has_value())
    {
        return std::unexpected{begin.error()};
    }

    auto result = invoke(std::forward<func>(f), std::forward<args>(arguments)...);

    const auto end = end_profile(*begin);

    if(not end.has_value())
    {
        return std::unexpected{end.error()};
    }

    result.duration = *end;

    return result;
}

} // namespace fubuki::io

#endif // FUBUKI_IO_PROFILE_HPP
