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

#ifndef FUBUKI_CORE_TEST_CONTIGUOUS_CONTAINER_TEST_TYPES_HPP
#define FUBUKI_CORE_TEST_CONTIGUOUS_CONTAINER_TEST_TYPES_HPP

#include <cstddef>
#include <initializer_list>
#include <type_traits>

/*
 * Test types for contiguous containers provided by Fubuki.
 *
 * Based on the reference implementation of std::inplace_vector (available at https://godbolt.org/z/5P78aG5xE) by Gonzalo Brito Gadeschi,
 * licensed under the MIT license.
 * It is itself based on the tests of libc++, under the following license:
 *
 * //===----------------------------------------------------------------------===//
 * //
 * //                     The LLVM Compiler Infrastructure
 * //
 * // This file is dual licensed under the MIT and the University of Illinois Open
 * // Source Licenses. See LICENSE.TXT for details.
 * //
 * //===----------------------------------------------------------------------===//
 */

#include <ostream>

namespace fubuki::test::contiguous_container::types
{

struct tint
{
    std::size_t i;

    // explicit operator std::size_t() { return i; }

    friend constexpr bool operator==(const tint&, const tint&) noexcept  = default;
    friend constexpr bool operator!=(const tint&, const tint&) noexcept  = default;
    friend constexpr auto operator<=>(const tint&, const tint&) noexcept = default;

    template<typename char_type, typename traits>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const tint& m)
    {
        return out << "tint{i=" << m.i << "}";
    }
};

struct moint final
{
    std::size_t i                      = 0;
    moint() noexcept                   = default;
    moint(const moint&)                = delete;
    moint& operator=(const moint&)     = delete;
    moint(moint&&) noexcept            = default;
    moint& operator=(moint&&) noexcept = default;
    // ~moint()                       = default;
    explicit constexpr moint(std::size_t j) noexcept : i(j) {}
    // it seems that deleting the copy constructor is not enough to make
    // this non-trivial using libstdc++:
    virtual void foo() {}

    friend constexpr bool operator==(const moint&, const moint&) noexcept  = default;
    friend constexpr bool operator!=(const moint&, const moint&) noexcept  = default;
    friend constexpr auto operator<=>(const moint&, const moint&) noexcept = default;

    template<typename char_type, typename traits>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const moint& m)
    {
        return out << "moint{i=" << m.i << "}";
    }
};

class non_copyable
{
    int    m_i;
    double m_d;

public:
    non_copyable(const non_copyable&)            = delete;
    non_copyable& operator=(const non_copyable&) = delete;

    non_copyable(int i, double d) noexcept : m_i(i), m_d(d) {} // NOLINT(bugprone-easily-swappable-parameters)

    non_copyable(non_copyable&& a) noexcept : m_i(a.m_i), m_d(a.m_d)
    {
        a.m_i = 0;
        a.m_d = 0;
    }

    non_copyable& operator=(non_copyable&& a) noexcept
    {
        m_i   = a.m_i;
        m_d   = a.m_d;
        a.m_i = 0;
        a.m_d = 0;
        return *this;
    }

    int    i() const noexcept { return m_i; }
    double d() const noexcept { return m_d; }

    friend constexpr bool operator==(const non_copyable&, const non_copyable&) noexcept  = default;
    friend constexpr bool operator!=(const non_copyable&, const non_copyable&) noexcept  = default;
    friend constexpr auto operator<=>(const non_copyable&, const non_copyable&) noexcept = default;

    template<typename char_type, typename traits>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const non_copyable& m)
    {
        return out << "non_copyable{i=" << m.m_i << ", d: " << m.m_d << "}";
    }
};

template<typename T, int N>
struct vec
{
    vec() noexcept = default;
    vec(std::initializer_list<T> /*il*/) noexcept {}

    friend constexpr bool operator==(const vec&, const vec&) noexcept  = default;
    friend constexpr bool operator!=(const vec&, const vec&) noexcept  = default;
    friend constexpr auto operator<=>(const vec&, const vec&) noexcept = default;

    template<typename char_type, typename traits>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const vec&)
    {
        return out << "vec{}";
    }
};

struct constructible_from_int
{
    explicit constructible_from_int(int j) noexcept : i{j} {}

    friend constexpr bool operator==(const constructible_from_int&, const constructible_from_int&) noexcept  = default;
    friend constexpr bool operator!=(const constructible_from_int&, const constructible_from_int&) noexcept  = default;
    friend constexpr auto operator<=>(const constructible_from_int&, const constructible_from_int&) noexcept = default;

    int i = {};

    template<typename char_type, typename traits>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const constructible_from_int& m)
    {
        return out << "constructible_from_int{i=" << m.i << "}";
    }
};

static_assert(std::is_trivial_v<tint> and std::is_copy_constructible_v<tint> and std::is_move_constructible_v<tint>);

static_assert(not std::is_trivial_v<moint> and not std::is_copy_constructible_v<moint> and std::is_move_constructible_v<moint>);

} // namespace fubuki::test::contiguous_container::types

#endif // FUBUKI_CORE_TEST_CONTIGUOUS_CONTAINER_TEST_TYPES_HPP
