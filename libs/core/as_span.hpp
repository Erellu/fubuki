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

#ifndef FUBUKI_CORE_AS_SPAN_HPP
#define FUBUKI_CORE_AS_SPAN_HPP

#include <span>

namespace fubuki
{

#if defined(__clang__) && __clang_major__ >= 19
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-container"
#endif

/**
 * Wraps a variable into a span containing one element.
 * @param v The variable to wrap.
 * @note This function does NOT use the parameter underlying storage if the parameter is a container.
 *
 * @section example Example
 *
 * @code{.cpp}
 *
 * int i = {};
 *
 * auto i_as_span = fubuki::as_span(i); // span<int>
 *
 * std::vector<int> v = {};
 *
 * auto v_as_span = fubuki::as_span(v); // span<std::vector<int>>
 *
 * @endcode
 */
[[nodiscard]] inline constexpr auto as_span(auto& v) noexcept { return std::span{std::addressof(v), 1u}; }

/**
 * Wraps a variable into a span containing one element.
 * @param v The variable to wrap.
 * @note This function does NOT use the parameter underlying storage if the parameter is a container.
 *
 * @section example Example
 *
 * @code{.cpp}
 *
 * const int i = {};
 *
 * auto i_as_span = fubuki::as_span(i); // span<const int>
 *
 * const std::vector<int> v = {};
 *
 * auto v_as_span = fubuki::as_span(v); // span<const std::vector<int>>
 *
 * @endcode
 */
[[nodiscard]] inline constexpr auto as_span(const auto& v) noexcept { return std::span{std::addressof(v), 1u}; }

[[nodiscard]] inline constexpr auto as_span(const auto&& v) noexcept = delete; // Temporaries not allowed

#if defined(__clang__) && __clang_major__ >= 19
    #pragma clang diagnostic pop
#endif
} // namespace fubuki

#endif // FUBUKI_CORE_AS_SPAN_HPP
