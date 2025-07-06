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

#ifndef FUBUKI_CORE_TRAITS_PARAMETER_PACK_HPP
#define FUBUKI_CORE_TRAITS_PARAMETER_PACK_HPP

#include <cstddef>
#include <tuple>
#include <type_traits>

namespace fubuki::traits::parameter_pack
{

/// Indicates how many times a type occurs in a parameter pack.
template<typename T, typename... U>
[[nodiscard]] constexpr std::size_t count() noexcept
{
    std::size_t result = 0;

    ((result += static_cast<std::size_t>(std::is_same_v<T, U>)), ...);

    return result;
}

/// Indicates if a parameter pack contains a type.
template<typename T, typename... U>
[[nodiscard]] constexpr bool contains() noexcept
{
    return (std::is_same_v<T, U> or ...);
}

/// Indicates how many times a type occurs in a parameter pack.
template<typename T, typename... U>
inline constexpr std::size_t count_v = count<T, U...>();

/// Indicates if a parameter pack contains a type.
template<typename T, typename... U>
inline constexpr bool contains_v = contains<T, U...>();

/// Indicates if all types in a parameter type are identical.
template<typename type, typename... other_types>
inline constexpr bool same_types_v = (std::is_same_v<type, other_types> and ...);

template<std::size_t index, typename... pack>
using nth_type = typename std::tuple_element_t<index, std::tuple<pack...>>;

} // namespace fubuki::traits::parameter_pack

#endif // FUBUKI_CORE_TRAITS_PARAMETER_PACK_HPP
