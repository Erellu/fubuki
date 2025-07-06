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

#ifndef FUBUKI_CORE_DETAIL_COMPARE_HPP
#define FUBUKI_CORE_DETAIL_COMPARE_HPP

#include <algorithm>
#include <compare>
#include <cstdint>
#include <ranges>

namespace fubuki::detail::compare
{

template<typename T>
struct three_way_result
{
    using type = std::compare_three_way_result_t<T>;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<typename T, std::size_t N>
struct three_way_result<T[N]>
{
    using type = std::compare_three_way_result_t<T>;
};

template<typename T, std::size_t N, std::size_t M>
struct three_way_result<T[N][M]>
{
    using type = std::compare_three_way_result_t<T>;
};

template<typename T, std::size_t N, std::size_t M, std::size_t L>
struct three_way_result<T[N][M][L]>
{
    using type = std::compare_three_way_result_t<T>;
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<typename T>
using three_way_result_t = three_way_result<T>::type;

template<typename T>
[[nodiscard]]
inline constexpr T to_ordering(const std::int32_t v) noexcept
{
    if(v < 0)
    {
        return T::less;
    }

    if(v == 0)
    {
        return T::equivalent;
    }

    return T::greater;
}

template<typename T>
[[nodiscard]] inline constexpr std::int32_t to_int(const T v) noexcept
{
    if(v == T::less)
    {
        return -1;
    }

    if(v == T::equivalent)
    {
        return 0;
    }

    return 1; // greater
}

// clang-format off
// Clang format panics here

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wfloat-equal"
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wfloat-equal"
#endif

template<typename T>
[[nodiscard]] constexpr auto do_three_way(const T& a, const T& b) noexcept
{
    return a <=> b;
}

template<std::ranges::range R, typename comparator>
[[nodiscard]] inline constexpr auto lexicographical_compare_three_way(R&& a, R&& b, comparator&& c) noexcept
{
    return std::lexicographical_compare_three_way(std::ranges::begin(a), std::ranges::end(std::forward<R>(a)), std::ranges::begin(b), std::ranges::end(std::forward<R>(b)), std::forward<comparator>(c));
}

template<std::ranges::range R>
[[nodiscard]] inline constexpr auto lexicographical_compare_three_way(R&& a, R&& b) noexcept
{
    constexpr auto comparator = []<typename U>(U&& x, U&& y) constexpr noexcept
    {
        return do_three_way(std::forward<U>(x), std::forward<U>(y));
    };

    return std::lexicographical_compare_three_way(std::ranges::begin(a), std::ranges::end(std::forward<R>(a)), std::ranges::begin(b), std::ranges::end(std::forward<R>(b)), comparator);
}

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<typename T, std::size_t N>
[[nodiscard]] constexpr auto do_three_way(const T (&a)[N], const T (&b)[N]) noexcept
{
    return lexicographical_compare_three_way(a, b);
}

template<typename T, std::size_t N, std::size_t M>
[[nodiscard]] constexpr auto do_three_way(const T (&a) [N][M], const T (&b) [N][M]) noexcept
{
    constexpr auto comp = []<std::ranges::range R>(R&& x, R&& y) constexpr noexcept
    {
        return lexicographical_compare_three_way(std::forward<R>(x), std::forward<R>(y));
    };

    return lexicographical_compare_three_way(a, b, comp);
}

template<typename T, std::size_t N, std::size_t M, std::size_t L>
[[nodiscard]] constexpr auto do_three_way(const T (&a) [N][M][L], const T (&b) [N][M][L]) noexcept
{
    constexpr auto comp = []<std::ranges::range R>(R&& x, R&& y) constexpr noexcept
    {
        constexpr auto do_comp = []<std::ranges::range R1>(R1&& z, R1&& w) constexpr noexcept
        {
            return lexicographical_compare_three_way(std::forward<R1>(z), std::forward<R1>(w));
        };

        return lexicographical_compare_three_way(std::forward<R>(x), std::forward<R>(y), do_comp);
    };

    return lexicographical_compare_three_way(a, b, comp);
}
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<typename T>
[[nodiscard]]
inline constexpr std::int32_t three_way(T&& a, T&& b) noexcept
{
    return to_int(do_three_way(std::forward<T>(a), std::forward<T>(b)));
}

template<typename T>
[[nodiscard]]
inline constexpr bool equal(const T& a, const T& b) noexcept
{
    if constexpr(std::ranges::range<T>)
    {
        constexpr auto do_compare = []<typename U>(const U& x, const U& y) constexpr noexcept -> bool
        {
            // Handle multi-dimensional C-arrays
            if constexpr(std::ranges::range<U>)
            {
                return equal(x, y);
            }
            else
            {
                return x == y;
            }
        };

        return std::ranges::equal(a, b, do_compare);
    }
    else
    {
        return a == b;
    }
}

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop)
#endif
// clang-format on

} // namespace fubuki::detail::compare

#endif // FUBUKI_CORE_DETAIL_COMPARE_HPP
