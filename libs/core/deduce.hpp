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

#ifndef FUBUKI_CORE_DEDUCE_HPP
#define FUBUKI_CORE_DEDUCE_HPP

#include <compare> // IWYU pragma: keep (needed for clang)
#include <variant>

namespace fubuki
{

namespace detail
{

struct deduce_type
{
    friend constexpr bool operator==(const deduce_type&, const deduce_type&) noexcept  = default;
    friend constexpr bool operator!=(const deduce_type&, const deduce_type&) noexcept  = default;
    friend constexpr auto operator<=>(const deduce_type&, const deduce_type&) noexcept = default;
};

} // namespace detail

/// A tag struct that can be used to indicate a parameter or a behaviour must be deduced from something.
inline constexpr auto deduce = detail::deduce_type{};

template<typename T>
using deduced_or = std::variant<detail::deduce_type, T>;

/// Indicates if an instance of deduced_or<T> is in the "deduced" state.
template<typename T>
inline constexpr bool deduced(const deduced_or<T>& v) noexcept
{
    return std::holds_alternative<detail::deduce_type>(v);
}

} // namespace fubuki

#endif // FUBUKI_CORE_DEDUCE_HPP
