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

#ifndef FUBUKI_CORE_TRAITS_TUPLE_HPP
#define FUBUKI_CORE_TRAITS_TUPLE_HPP

#include <cstddef>
#include <tuple>
#include <type_traits>

namespace fubuki::traits::tuple
{

namespace detail
{

template<typename>
struct is_std_tuple : std::false_type
{
};

template<typename... elements_type>
struct is_std_tuple<std::tuple<elements_type...>> : std::true_type
{
};

// https://stackoverflow.com/a/25958302/11910702
// License: CC BY-SA 3.0

template<typename T, typename U>
struct has_type;

template<typename T>
struct has_type<T, std::tuple<>> : std::false_type
{
};

template<typename T, typename U, typename... Ts>
struct has_type<T, std::tuple<U, Ts...>> : has_type<T, std::tuple<Ts...>>
{
};

template<typename T, typename... Ts>
struct has_type<T, std::tuple<T, Ts...>> : std::true_type
{
};

template<typename T, typename... Ts>
inline constexpr bool has_type_v = has_type<T, Ts...>::value;

// https://stackoverflow.com/a/41200732/11910702
// License: CC BY-SA 3.0

template<typename S1, typename S2>
struct intersect
{
    template<std::size_t... indices>
    static constexpr auto make_intersection(std::index_sequence<indices...>)
    {
        return std::tuple_cat(
            std::conditional_t<has_type_v<std::tuple_element_t<indices, S1>, S2>, std::tuple<std::tuple_element_t<indices, S1>>, std::tuple<>>{}...);
    }

    using type = decltype(make_intersection(std::make_index_sequence<std::tuple_size_v<S1>>{}));
};

} // namespace detail

template<typename T>
concept type = detail::is_std_tuple<std::decay_t<T>>::value;

template<typename T, template<typename...> typename tuple_like_type, typename... elements>
[[nodiscard]] constexpr std::size_t count(const tuple_like_type<elements...>&&) noexcept
{
    std::size_t result = 0;

    ((result += static_cast<std::size_t>(std::is_same_v<T, elements>)), ...);

    return result;
}

template<typename T, template<typename...> typename tuple_like_type, typename... elements>
[[nodiscard]] constexpr bool contains(const tuple_like_type<elements...>&&) noexcept
{
    return (std::is_same_v<T, elements> or ...);
}

/// Indicates the intersection of two tuple types, returned as std::tuple.
template<typename S1, typename S2>
using intersection_t = detail::intersect<S1, S2>::type;

} // namespace fubuki::traits::tuple

#endif // FUBUKI_CORE_TRAITS_TUPLE_HPP
