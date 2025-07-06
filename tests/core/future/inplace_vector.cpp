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

#include "contiguous_container_test_types.hpp"

#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <core/future/inplace_vector.hpp>

/*
 * Implementation details of fubuki::inplace_vector.
 * Based on the reference implementation (available at https://godbolt.org/z/5P78aG5xE) by Gonzalo Brito Gadeschi,
 * licensed under the MIT license.
 *
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

#ifndef __cpp_lib_inplace_vector // We don't test the Standard Library

    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

namespace
{

// NOLINTBEGIN(readability-else-after-return)

    #define CONSTEXPR_ASSERT_TRUE(c)             \
        do                                       \
        {                                        \
            if(not(c))                           \
            {                                    \
                if(std::is_constant_evaluated()) \
                {                                \
                    throw std::logic_error{#c};  \
                }                                \
                else                             \
                {                                \
                    ASSERT_TRUE((c)) << #c;      \
                }                                \
            }                                    \
        }                                        \
        while(false)

// NOLINTEND(readability-else-after-return)

namespace inplace_vector_detail = fubuki::future::detail::inplace_vector;
template<typename T, std::size_t capacity>
using inplace_vector = fubuki::future::inplace_vector<T, capacity>;

namespace test_type = fubuki::test::contiguous_container::types;

} // anonymous namespace

template struct inplace_vector_detail::storage::empty<int>;
template struct inplace_vector_detail::storage::standard<int, 10>;
template struct inplace_vector_detail::storage::standard<std::unique_ptr<int>, 10>;

// empty:
template class fubuki::future::inplace_vector<int, 0>;

// trivial non-empty:
template class fubuki::future::inplace_vector<int, 1>;
template class fubuki::future::inplace_vector<int, 2>;

// non-trivial
template class fubuki::future::inplace_vector<std::string, 3>;

// move-only:
template class fubuki::future::inplace_vector<std::unique_ptr<int>, 3>;

// Explicit instantiations
template class fubuki::future::inplace_vector<test_type::tint, 0>; // trivial empty
template class fubuki::future::inplace_vector<test_type::tint, 1>; // trivial non-empty
template class fubuki::future::inplace_vector<test_type::tint, 2>; // trivial non-empty
template class fubuki::future::inplace_vector<test_type::tint, 3>; // trivial non-empty

namespace
{

template<typename T, std::size_t N>
requires(N == 0 or N == 1 or N == 10)
constexpr auto make_data()
{
    if constexpr(N == 0)
    {
        return inplace_vector<T, N>{};
    }
    else if constexpr(N == 1)
    {
        return inplace_vector<T, N>(std::initializer_list<T>{0});
    }
    else if constexpr(N == 10)
    {
        return inplace_vector<T, N>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    }
}

template<typename T, std::size_t N>
requires(N == 0 or N == 1 or N == 10)
constexpr void test_il_constructor()
{
    auto v = make_data<T, N>(); // NOLINT(misc-const-correctness)
    if(v.size() != N)
    {
        throw std::logic_error{"Size mismatch"}; // Fail compilation
    }

    for(size_t i = 0; i < N; ++i)
    {
        CONSTEXPR_ASSERT_TRUE(v[i] == T(i));
    }
    if(v.size() != N)
    {
        throw std::exception{}; // Fail compilation
    }

    if(not std::is_constant_evaluated())
    {
        EXPECT_THROW(([&] { const inplace_vector<T, N> x({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}); }()), std::bad_alloc);
    }
}

template<typename T, std::size_t N>
constexpr void test_il_assignment()
{
    auto v = make_data<T, N>(); // NOLINT(misc-const-correctness)

    if(v.size() != N)
    {
        throw std::logic_error{"Size mismatch"}; // Fail compilation
    }

    for(size_t i = 0; i < N; ++i)
    {
        CONSTEXPR_ASSERT_TRUE(v[i] == T(i));
    }
    if(not std::is_constant_evaluated())
    {
        EXPECT_THROW(([&] { const inplace_vector<T, N> x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; }()), std::bad_alloc);
    }
}

template<typename T, std::size_t N>
constexpr void test_default_constructor()
{
    inplace_vector<T, N> v; // NOLINT(misc-const-correctness)

    if(v.size() != 0) // NOLINT(readability-container-size-empty)
    {
        throw std::logic_error{"Size mismatch"}; // Fail compilation
    }

    if(not v.empty())
    {
        throw std::logic_error{"Size mismatch"}; // Fail compilation
    }

    if(v.capacity() != N)
    {
        throw std::logic_error{"Size mismatch"}; // Fail compilation
    }
}

template<typename T, std::size_t N>
constexpr void test_default_constructor_bounds_and_contiguous_iterators(std::size_t sz)
{
    CONSTEXPR_ASSERT_TRUE(sz <= N); // Test ill formed if it's true

    inplace_vector<T, N> v(sz); // NOLINT(misc-const-correctness)
    using diff_type = typename inplace_vector<T, N>::difference_type;

    CONSTEXPR_ASSERT_TRUE(v.size() == sz);
    CONSTEXPR_ASSERT_TRUE(v.max_size() == N);
    CONSTEXPR_ASSERT_TRUE(v.capacity() == N);
    for(std::size_t i = 0; i != sz; ++i)
    {
        CONSTEXPR_ASSERT_TRUE(v[i] == T{});
    }
    for(std::size_t i = 0; i < v.size(); ++i)
    { // contiguous
        CONSTEXPR_ASSERT_TRUE(*(v.begin() + i) == *(std::addressof(*v.begin()) + i));
        CONSTEXPR_ASSERT_TRUE(*(v.cbegin() + i) == *(std::addressof(*v.cbegin()) + i));
        CONSTEXPR_ASSERT_TRUE(*(v.rbegin() + static_cast<diff_type>(i)) == *(std::addressof(*v.rbegin()) - i));
        CONSTEXPR_ASSERT_TRUE(*(v.crbegin() + static_cast<diff_type>(i)) == *(std::addressof(*v.crbegin()) - i));
    }
    // iterators
    if(v.size() == 0) // NOLINT(readability-container-size-empty)
    {
        CONSTEXPR_ASSERT_TRUE(v.empty());
        CONSTEXPR_ASSERT_TRUE(v.begin() == v.end());
        CONSTEXPR_ASSERT_TRUE(v.cbegin() == v.cend());
        CONSTEXPR_ASSERT_TRUE(v.rbegin() == v.rend());
        CONSTEXPR_ASSERT_TRUE(v.crbegin() == v.crend());
    }
    else
    {
        CONSTEXPR_ASSERT_TRUE(!v.empty());
        CONSTEXPR_ASSERT_TRUE(v.begin() != v.end());
        CONSTEXPR_ASSERT_TRUE(v.cbegin() != v.cend());
        CONSTEXPR_ASSERT_TRUE(v.rbegin() != v.rend());
        CONSTEXPR_ASSERT_TRUE(v.crbegin() != v.crend());
        CONSTEXPR_ASSERT_TRUE(static_cast<decltype(v.size())>(std::distance(v.begin(), v.end())) == v.size());
        CONSTEXPR_ASSERT_TRUE(static_cast<decltype(v.size())>(std::distance(v.cbegin(), v.cend())) == v.size());
        CONSTEXPR_ASSERT_TRUE(static_cast<decltype(v.size())>(std::distance(v.rbegin(), v.rend())) == v.size());
        CONSTEXPR_ASSERT_TRUE(static_cast<decltype(v.size())>(std::distance(v.crbegin(), v.crend())) == v.size());
        CONSTEXPR_ASSERT_TRUE(v.back() == T{});
        CONSTEXPR_ASSERT_TRUE(v.front() == T{});
    }
}

template<typename T, std::size_t N>
constexpr void test_iterators()
{
    { // N3644 testing
        using container = inplace_vector<T, N>;
        typename container::iterator       ii1{}, ii2{};
        typename container::iterator       ii4 = ii1;
        typename container::const_iterator cii{};
        CONSTEXPR_ASSERT_TRUE(ii1 == ii2);
        CONSTEXPR_ASSERT_TRUE(ii1 == ii4);

        CONSTEXPR_ASSERT_TRUE(!(ii1 != ii2));

        CONSTEXPR_ASSERT_TRUE((ii1 == cii));
        CONSTEXPR_ASSERT_TRUE((cii == ii1));
        CONSTEXPR_ASSERT_TRUE(!(ii1 != cii));
        CONSTEXPR_ASSERT_TRUE(!(cii != ii1));
        CONSTEXPR_ASSERT_TRUE(!(ii1 < cii));
        CONSTEXPR_ASSERT_TRUE(!(cii < ii1));
        CONSTEXPR_ASSERT_TRUE((ii1 <= cii));
        CONSTEXPR_ASSERT_TRUE((cii <= ii1));
        CONSTEXPR_ASSERT_TRUE(!(ii1 > cii));
        CONSTEXPR_ASSERT_TRUE(!(cii > ii1));
        CONSTEXPR_ASSERT_TRUE((ii1 >= cii));
        CONSTEXPR_ASSERT_TRUE((cii >= ii1));
        CONSTEXPR_ASSERT_TRUE((cii - ii1) == 0);
        CONSTEXPR_ASSERT_TRUE((ii1 - cii) == 0);
    }
}

template<typename T, std::size_t N>
requires(N < 11) // Purely artifical
constexpr void test_constructor_input_iterators()
{
    using container = inplace_vector<T, N>;

    const std::array t = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    container        c(std::begin(t), std::begin(t) + N);
    CONSTEXPR_ASSERT_TRUE(c.size() == N);
    CONSTEXPR_ASSERT_TRUE(std::equal(std::begin(t), std::begin(t) + N, std::begin(c), std::end(c)));

    for(typename container::iterator i = c.begin(); i != c.end(); ++i)
    {
        auto idx = i - c.begin();
        auto o   = t[static_cast<typename container::size_type>(idx)]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
        CONSTEXPR_ASSERT_TRUE(*i == o);
        *i = 2 * o;
        CONSTEXPR_ASSERT_TRUE(*i == (2 * o));
        CONSTEXPR_ASSERT_TRUE(std::distance(c.begin(), i) == idx);
        CONSTEXPR_ASSERT_TRUE(static_cast<decltype(c.size())>(std::distance(i, c.end()))
                              == c.size() - static_cast<typename container::size_type>(idx));
    }
}

template<typename T, std::size_t N>
void test_all()
{
    constexpr auto implementation = []() constexpr -> bool
    {
        test_il_constructor<T, N>();
        test_il_assignment<T, N>();
        test_default_constructor<T, N>();
        for(const std::size_t i : std::views::iota(0U, N))
        {
            test_default_constructor_bounds_and_contiguous_iterators<T, N>(i);
        }
        test_iterators<T, N>();
        test_constructor_input_iterators<T, N>();
        return true;
    };

    static_assert(implementation(), "CONSTEXPR TESTS FAILED");
    implementation(); // Runtime
}

// NOLINTBEGIN
// The following is extracted from the reference implementation

TEST(inplace_vector, api)
{
    { // storage
        using inplace_vector_detail::storage_t;
        using inplace_vector_detail::storage::aligned_bytes;
        using inplace_vector_detail::storage::empty;
        using inplace_vector_detail::storage::standard;

        static_assert(std::is_same<storage_t<int, 0>, empty<int>>{});
        static_assert(std::is_same<storage_t<int, 10>, standard<int, 10>>{});
        static_assert(std::is_same<storage_t<std::unique_ptr<int>, 10>, standard<std::unique_ptr<int>, 10>>{});
    }

    test_all<int, 0>();
    test_all<int, 1>();
    test_all<int, 10>();

    { // capacity
        inplace_vector<int, 10> a;
        static_assert(a.capacity() == 10);
        ASSERT_TRUE(a.empty());
        for(std::size_t i = 0; i != 10; ++i)
        {
            a.push_back(0);
        }
        static_assert(a.capacity() == 10);
        ASSERT_TRUE(a.size() == 10);
        ASSERT_TRUE(!a.empty());
        EXPECT_THROW(a.push_back(0), std::bad_alloc);
        ASSERT_TRUE(nullptr == a.try_push_back(0));
    }

    { // resize copyable
        using copyable = int;
        inplace_vector<copyable, 10> a(10, 5);
        ASSERT_TRUE(a.size() == 10);
        static_assert(a.capacity() == 10);
        // test_contiguous(a);
        for(std::size_t i = 0; i != 10; ++i)
        {
            ASSERT_TRUE(a[i] == 5);
        }
        a.resize(5);
        ASSERT_TRUE(a.size() == 5);

        static_assert(a.capacity() == 10);
        // test_contiguous(a);
        a.resize(9);
        ASSERT_TRUE(a[4] == 5);
        for(std::size_t i = 5; i != 9; ++i)
        {
            ASSERT_TRUE(a[i] == 0);
        }
        ASSERT_TRUE(a.size() == 9);
        static_assert(a.capacity() == 10);
        // test_contiguous(a);
        a.resize(10, 3);
        ASSERT_TRUE(a[4] == 5);
        ASSERT_TRUE(a[8] == 0);
        ASSERT_TRUE(a[9] == 3);
        ASSERT_TRUE(a.size() == 10);
        static_assert(a.capacity() == 10);
        a.resize(5, 2);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(a[i] == 5);
        }
        // test_contiguous(a);
        EXPECT_THROW(a.resize(12), std::bad_alloc);
    }
    { // resize move-only
        using move_only = std::unique_ptr<int>;
        inplace_vector<move_only, 10> a(10);
        ASSERT_TRUE(a.size() == 10);
        static_assert(a.capacity() == 10);
        a.resize(5);
        // test_contiguous(a);
        ASSERT_TRUE(a.size() == 5);
        static_assert(a.capacity() == 10);
        a.resize(9);
        ASSERT_TRUE(a.size() == 9);
        static_assert(a.capacity() == 10);
    }

    { // resize value:
        using copyable = int;
        inplace_vector<copyable, 10> a(10);
        ASSERT_TRUE(a.size() == 10);
        static_assert(a.capacity() == 10);
        // test_contiguous(a);
        for(std::size_t i = 0; i != 10; ++i)
        {
            ASSERT_TRUE(a[i] == 0);
        }
        a.resize(5);
        ASSERT_TRUE(a.size() == 5);
        static_assert(a.capacity() == 10);
        // test_contiguous(a);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(a[i] == 0);
        }
        a.resize(9, 5);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(a[i] == 0);
        }
        for(std::size_t i = 5; i != 9; ++i)
        {
            ASSERT_TRUE(a[i] == 5);
        }
        ASSERT_TRUE(a.size() == 9);
        static_assert(a.capacity() == 10);
        // test_contiguous(a);
        a.resize(10, 3);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(a[i] == 0);
        }
        for(std::size_t i = 5; i != 9; ++i)
        {
            ASSERT_TRUE(a[i] == 5);
        }
        ASSERT_TRUE(a[9] == 3);
        ASSERT_TRUE(a.size() == 10);
        static_assert(a.capacity() == 10);
        // test_contiguous(a);
    }

    { // assign copy
        inplace_vector<int, 3> a = {0, 1, 2};
        ASSERT_TRUE(a.size() == std::size_t{3});
        inplace_vector<int, 3> b;
        ASSERT_TRUE(b.size() == std::size_t{0});
        b = a;
        ASSERT_TRUE(b.size() == std::size_t{3});
        ASSERT_TRUE(std::equal(std::begin(a), std::end(a), std::begin(b), std::end(b)));
    }

    { // copy construct
        inplace_vector<int, 3> a = {0, 1, 2};
        ASSERT_TRUE(a.size() == std::size_t{3});
        inplace_vector<int, 3> b(a);
        ASSERT_TRUE(b.size() == std::size_t{3});

        ASSERT_TRUE(std::equal(std::begin(a), std::end(a), std::begin(b), std::end(b)));
    }

    { // assign move
        using move_only = std::unique_ptr<int>;
        inplace_vector<move_only, 3> a(3);
        ASSERT_TRUE(a.size() == std::size_t{3});
        inplace_vector<move_only, 3> b;
        ASSERT_TRUE(b.size() == std::size_t{0});
        b = std::move(a);
        ASSERT_TRUE(b.size() == std::size_t{3});
        ASSERT_TRUE(a.size() == std::size_t{0}); // NOLINT(bugprone-use-after-move)
    }

    { // move construct
        using move_only = std::unique_ptr<int>;
        inplace_vector<move_only, 3> a(3);
        ASSERT_TRUE(a.size() == std::size_t{3});
        const inplace_vector<move_only, 3> b(std::move(a));
        ASSERT_TRUE(b.size() == std::size_t{3});
        ASSERT_TRUE(a.size() == std::size_t{0}); // NOLINT(bugprone-use-after-move)
    }

    { // old tests
        using vec_t = inplace_vector<int, 5>;
        vec_t vec1(5);
        vec1[0] = 0;
        vec1[1] = 1;
        vec1[2] = 2;
        vec1[3] = 3;
        vec1[4] = 4;
        {
            vec_t vec2;
            vec2.push_back(5);
            vec2.push_back(6);
            vec2.push_back(7);
            vec2.push_back(8);
            vec2.push_back(9);
            ASSERT_TRUE(vec1[0] == 0);
            ASSERT_TRUE(vec1[4] == 4);
            ASSERT_TRUE(vec2[0] == 5);
            ASSERT_TRUE(vec2[4] == 9);
        }
        {
            vec_t vec2;
            vec2.try_push_back(5);
            vec2.try_push_back(6);
            vec2.try_push_back(7);
            vec2.try_push_back(8);
            vec2.try_push_back(9);
            ASSERT_TRUE(vec1[0] == 0);
            ASSERT_TRUE(vec1[4] == 4);
            ASSERT_TRUE(vec2[0] == 5);
            ASSERT_TRUE(vec2[4] == 9);
        }
        {
            vec_t vec2;
            vec2.unchecked_push_back(5);
            vec2.unchecked_push_back(6);
            vec2.unchecked_push_back(7);
            vec2.unchecked_push_back(8);
            vec2.unchecked_push_back(9);
            ASSERT_TRUE(vec1[0] == 0);
            ASSERT_TRUE(vec1[4] == 4);
            ASSERT_TRUE(vec2[0] == 5);
            ASSERT_TRUE(vec2[4] == 9);
        }
        {
            auto vec2 = vec1;
            ASSERT_TRUE(vec2[0] == 0);
            ASSERT_TRUE(vec2[4] == 4);
            ASSERT_TRUE(vec1[0] == 0);
            ASSERT_TRUE(vec1[4] == 4);
        }
        {

            for(int counter = 0; auto i : vec1)
            {
                ASSERT_TRUE(i == counter);
                counter++;
            }
        }

        {
            std::vector<int> vec2(5);
            vec2[0] = 4;
            vec2[1] = 3;
            vec2[2] = 2;
            vec2[3] = 1;
            vec2[4] = 0;
            vec_t vec(vec2.size());
            copy(std::begin(vec2), std::end(vec2), std::begin(vec));

            for(int counter = 4; auto i : vec)
            {
                ASSERT_TRUE(i == counter);
                counter--;
            }
        }
    }
    {
        using vec_t = inplace_vector<int, 0>;
        static_assert(sizeof(vec_t) == 1);

        constexpr auto a = vec_t{};
        static_assert(a.size() == std::size_t{0});
    }

    { // back and front:
        using container = inplace_vector<int, 2>;
        container c(1);
        ASSERT_TRUE(c.back() == 0);
        ASSERT_TRUE(c.front() == 0);
        ASSERT_TRUE(c[0] == 0);
        c.clear();
        constexpr int one = 1;
        c.push_back(one);
        ASSERT_TRUE(c.back() == 1);
        ASSERT_TRUE(c.front() == 1);
        ASSERT_TRUE(c[0] == 1);
        ASSERT_TRUE(c.size() == 1);
        c.push_back(2);
        ASSERT_TRUE(c.back() == 2);
        ASSERT_TRUE(c.front() == 1);
        ASSERT_TRUE(c[0] == 1);
        ASSERT_TRUE(c[1] == 2);
        ASSERT_TRUE(c.size() == 2);
        c.pop_back();
        ASSERT_TRUE(c.front() == 1);
        ASSERT_TRUE(c[0] == 1);
        ASSERT_TRUE(c.back() == 1);
        c.pop_back();
        ASSERT_TRUE(c.empty());
    }

    { // const back:
        using container = inplace_vector<int, 2>;
        constexpr container c(1);
        static_assert(c.back() == 0);
        static_assert(c.front() == 0);
        static_assert(c[0] == 0);
        static_assert(c.size() == 1);
    }

    { // swap: same type
        using container = inplace_vector<int, 5>;
        container c0(3, 5);
        container c1(5, 1);
        container c2(0);
        ASSERT_TRUE(c0.size() == std::size_t(3));
        ASSERT_TRUE(c1.size() == 5);
        ASSERT_TRUE(c2.size() == std::size_t(0));
        for(std::size_t i = 0; i != 3; ++i)
        {
            ASSERT_TRUE(c0[i] == 5);
        }
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(c1[i] == 1);
        }
        c0.swap(c1);
        ASSERT_TRUE(c0.size() == 5);
        ASSERT_TRUE(c1.size() == std::size_t(3));
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(c0[i] == 1);
        }
        for(std::size_t i = 0; i != 3; ++i)
        {
            ASSERT_TRUE(c1[i] == 5);
        }
        c2.swap(c1);
        ASSERT_TRUE(c1.size() == std::size_t(0));
        ASSERT_TRUE(c2.size() == std::size_t(3));
        for(std::size_t i = 0; i != 3; ++i)
        {
            ASSERT_TRUE(c2[i] == 5);
        }
    }

    { // std::swap: same type
        using container = inplace_vector<int, 5>;
        container c0(3, 5);
        container c1(5, 1);
        container c2(0);
        ASSERT_TRUE(c0.size() == std::size_t(3));
        ASSERT_TRUE(c1.size() == 5);
        ASSERT_TRUE(c2.size() == std::size_t(0));
        for(std::size_t i = 0; i != 3; ++i)
        {
            ASSERT_TRUE(c0[i] == 5);
        }
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(c1[i] == 1);
        }
        std::swap(c0, c1);
        ASSERT_TRUE(c0.size() == 5);
        ASSERT_TRUE(c1.size() == std::size_t(3));
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_TRUE(c0[i] == 1);
        }
        for(std::size_t i = 0; i != 3; ++i)
        {
            ASSERT_TRUE(c1[i] == 5);
        }
        std::swap(c2, c1);
        ASSERT_TRUE(c1.size() == std::size_t(0));
        ASSERT_TRUE(c2.size() == std::size_t(3));
        for(std::size_t i = 0; i != 3; ++i)
        {
            ASSERT_TRUE(c2[i] == 5);
        }
    }

    {
        constexpr inplace_vector<int, 5> v{};
        static_assert(v.data() != nullptr);

        constexpr inplace_vector<int, 0> v0 = {};
        static_assert(v0.data() == nullptr);
    }
    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wfloat-equal"
    #elif defined(__GNUC__)
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wfloat-equal"
    #endif
    { // emplace:
        {
            inplace_vector<test_type::non_copyable, 3>           c;
            inplace_vector<test_type::non_copyable, 3>::iterator i = c.emplace(c.cbegin(), 2, 3.5);
            ASSERT_TRUE(i == c.begin());
            ASSERT_TRUE(c.size() == 1);
            ASSERT_TRUE(c.front().i() == 2);
            ASSERT_TRUE(c.front().d() == 3.5);
            i = c.emplace(c.cend(), 3, 4.5);
            ASSERT_TRUE(i == c.end() - 1);
            ASSERT_TRUE(c.size() == 2);
            ASSERT_TRUE(c.front().i() == 2);
            ASSERT_TRUE(c.front().d() == 3.5);
            ASSERT_TRUE(c.back().i() == 3);
            ASSERT_TRUE(c.back().d() == 4.5);
            i = c.emplace(c.cbegin() + 1, 4, 6.5);
            ASSERT_TRUE(i == c.begin() + 1);
            ASSERT_TRUE(c.size() == 3);
            ASSERT_TRUE(c.front().i() == 2);
            ASSERT_TRUE(c.front().d() == 3.5);
            ASSERT_TRUE(c[1].i() == 4);
            ASSERT_TRUE(c[1].d() == 6.5);
            ASSERT_TRUE(c.back().i() == 3);
            ASSERT_TRUE(c.back().d() == 4.5);
            EXPECT_THROW(c.emplace(c.cbegin(), 2, 3.5), std::bad_alloc);
        }
        {
            inplace_vector<test_type::non_copyable, 3>           c;
            inplace_vector<test_type::non_copyable, 3>::iterator i = c.emplace(c.cbegin(), 2, 3.5);
            ASSERT_TRUE(i == c.begin());
            ASSERT_TRUE(c.size() == 1);
            ASSERT_TRUE(c.front().i() == 2);
            ASSERT_TRUE(c.front().d() == 3.5);
            i = c.emplace(c.cend(), 3, 4.5);
            ASSERT_TRUE(i == c.end() - 1);
            ASSERT_TRUE(c.size() == 2);
            ASSERT_TRUE(c.front().i() == 2);
            ASSERT_TRUE(c.front().d() == 3.5);
            ASSERT_TRUE(c.back().i() == 3);
            ASSERT_TRUE(c.back().d() == 4.5);
            i = c.emplace(c.cbegin() + 1, 4, 6.5);
            ASSERT_TRUE(i == c.begin() + 1);
            ASSERT_TRUE(c.size() == 3);
            ASSERT_TRUE(c.front().i() == 2);
            ASSERT_TRUE(c.front().d() == 3.5);
            ASSERT_TRUE(c[1].i() == 4);
            ASSERT_TRUE(c[1].d() == 6.5);
            ASSERT_TRUE(c.back().i() == 3);
            ASSERT_TRUE(c.back().d() == 4.5);
        }
    }

    { // emplace_back
        inplace_vector<test_type::non_copyable, 2> c;
        c.emplace_back(2, 3.5);
        ASSERT_TRUE(c.size() == 1);
        ASSERT_TRUE(c.front().i() == 2);
        ASSERT_TRUE(c.front().d() == 3.5);
        c.emplace_back(3, 4.5);
        ASSERT_TRUE(c.size() == 2);
        ASSERT_TRUE(c.front().i() == 2);
        ASSERT_TRUE(c.front().d() == 3.5);
        ASSERT_TRUE(c.back().i() == 3);
        ASSERT_TRUE(c.back().d() == 4.5);
        EXPECT_THROW(c.emplace_back(2, 3.5), std::bad_alloc);
    }
    { // try_emplace_back
        inplace_vector<test_type::non_copyable, 2> c;
        ASSERT_TRUE(c.begin() == c.try_emplace_back(2, 3.5));
        ASSERT_TRUE(c.size() == 1);
        ASSERT_TRUE(c.front().i() == 2);
        ASSERT_TRUE(c.front().d() == 3.5);
        ASSERT_TRUE((c.begin() + 1) == c.try_emplace_back(3, 4.5));
        ASSERT_TRUE(c.size() == 2);
        ASSERT_TRUE(c.front().i() == 2);
        ASSERT_TRUE(c.front().d() == 3.5);
        ASSERT_TRUE(c.back().i() == 3);
        ASSERT_TRUE(c.back().d() == 4.5);
        ASSERT_TRUE(nullptr == c.try_emplace_back(2, 3.5));
    }
    { // unchecked_emplace_back
        inplace_vector<test_type::non_copyable, 2> c;
        ASSERT_TRUE(c.begin() == std::addressof(c.unchecked_emplace_back(2, 3.5)));
        ASSERT_TRUE(c.size() == 1);
        ASSERT_TRUE(c.front().i() == 2);
        ASSERT_TRUE(c.front().d() == 3.5);
        ASSERT_TRUE((c.begin() + 1) == std::addressof(c.unchecked_emplace_back(3, 4.5)));
        ASSERT_TRUE(c.size() == 2);
        ASSERT_TRUE(c.front().i() == 2);
        ASSERT_TRUE(c.front().d() == 3.5);
        ASSERT_TRUE(c.back().i() == 3);
        ASSERT_TRUE(c.back().d() == 4.5);
    }
    #if defined(__clang__)
        #pragma clang diagnostic pop
    #elif defined(__GNUC__)
        #pragma GCC diagnostic pop)
    #endif

    {     // emplace extra:
        { //
            inplace_vector<int, 4> v;
            v = {1, 2, 3};

            v.emplace(v.begin(), v.back()); // NOLINT(clazy-strict-iterators)
            ASSERT_TRUE(v[0] == 3);
        }
        {
            inplace_vector<int, 4> v;
            v = {1, 2, 3};
            v.emplace(v.begin(), v.back()); // NOLINT(clazy-strict-iterators)
            ASSERT_TRUE(v[0] == 3);
        }
    }

    { // erase
        {
            int                    a1[] = {1, 2, 3}; // NOLINT(cppcoreguidelines-avoid-c-arrays)
            inplace_vector<int, 4> l1(a1, a1 + 3);
            ASSERT_TRUE(l1.size() == 3);
            inplace_vector<int, 4>::const_iterator i = l1.begin(); // NOLINT(clazy-strict-iterators)
            ++i;
            inplace_vector<int, 4>::iterator j = l1.erase(i);
            ASSERT_TRUE(l1.size() == 2);
            ASSERT_TRUE(std::distance(l1.begin(), l1.end()) == 2);
            ASSERT_TRUE(*j == 3);
            ASSERT_TRUE(*l1.begin() == 1);
            ASSERT_TRUE(*std::next(l1.begin()) == 3);
            j = l1.erase(j); // NOLINT(clazy-strict-iterators)
            ASSERT_TRUE(j == l1.end());
            ASSERT_TRUE(l1.size() == 1);
            ASSERT_TRUE(std::distance(l1.begin(), l1.end()) == 1);
            ASSERT_TRUE(*l1.begin() == 1);
            j = l1.erase(l1.begin()); // NOLINT(clazy-strict-iterators)
            ASSERT_TRUE(j == l1.end());
            ASSERT_TRUE(l1.empty());
            ASSERT_TRUE(std::distance(l1.begin(), l1.end()) == 0);
        }
    }

    { // erase iter iter
        int a1[]    = {1, 2, 3};
        using vec_t = inplace_vector<int, 5>;
        {
            vec_t           l1(a1, a1 + 3);
            vec_t::iterator i = l1.erase(l1.cbegin(), l1.cbegin());
            ASSERT_TRUE(l1.size() == 3);
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 3);
            ASSERT_TRUE(i == l1.begin());
        }
        {
            vec_t           l1(a1, a1 + 3);
            vec_t::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin()));
            ASSERT_TRUE(l1.size() == 2);
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 2);
            ASSERT_TRUE(i == l1.begin());
            ASSERT_TRUE(l1 == vec_t(a1 + 1, a1 + 3));
        }
        {
            vec_t           l1(a1, a1 + 3);
            vec_t::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 2));
            ASSERT_TRUE(l1.size() == 1);
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 1);
            ASSERT_TRUE(i == l1.begin());
            ASSERT_TRUE(l1 == vec_t(a1 + 2, a1 + 3));
        }
        {
            vec_t           l1(a1, a1 + 3);
            vec_t::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 3));
            ASSERT_TRUE(l1.empty());
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 0);
            ASSERT_TRUE(i == l1.begin());
        }
        {
            inplace_vector<vec_t, 3> outer(2, vec_t(1));
            outer.erase(outer.begin(), outer.begin()); // NOLINT(clazy-strict-iterators)
            ASSERT_TRUE(outer.size() == 2);
            ASSERT_TRUE(outer[0].size() == 1);
            ASSERT_TRUE(outer[1].size() == 1);
        }
    }

    { // insert init list
        {
            inplace_vector<int, 15>           d(10, 1);
            inplace_vector<int, 15>::iterator i = d.insert(d.cbegin() + 2, {3, 4, 5, 6});
            ASSERT_TRUE(d.size() == 14);
            ASSERT_TRUE(i == d.begin() + 2);
            ASSERT_TRUE(d[0] == 1);
            ASSERT_TRUE(d[1] == 1);
            ASSERT_TRUE(d[2] == 3);
            ASSERT_TRUE(d[3] == 4);
            ASSERT_TRUE(d[4] == 5);
            ASSERT_TRUE(d[5] == 6);
            ASSERT_TRUE(d[6] == 1);
            ASSERT_TRUE(d[7] == 1);
            ASSERT_TRUE(d[8] == 1);
            ASSERT_TRUE(d[9] == 1);
            ASSERT_TRUE(d[10] == 1);
            ASSERT_TRUE(d[11] == 1);
            ASSERT_TRUE(d[12] == 1);
            ASSERT_TRUE(d[13] == 1);
            EXPECT_THROW(d.insert(d.cbegin(), {2, 3, 4, 5}), std::bad_alloc);
        }
    }

    { // insert iter iter
        {
            inplace_vector<int, 120>           v(100);
            int                                a[] = {1, 2, 3, 4, 5};
            const std::size_t                  n   = sizeof(a) / sizeof(a[0]);
            inplace_vector<int, 120>::iterator i   = v.insert(v.cbegin() + 10, (a + 0), (a + n));
            ASSERT_TRUE(v.size() == 100 + n);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            for(std::size_t k = 0; k < n; ++j, ++k)
            {
                ASSERT_TRUE(v[j] == a[k]);
            }
            for(; j < 105; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
        {
            inplace_vector<int, 120>           v(100);
            size_t                             sz  = v.size();
            int                                a[] = {1, 2, 3, 4, 5};
            const unsigned                     n   = sizeof(a) / sizeof(a[0]);
            inplace_vector<int, 120>::iterator i   = v.insert(v.cbegin() + 10, (a + 0), (a + n));
            ASSERT_TRUE(v.size() == sz + n);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            for(std::size_t k = 0; k < n; ++j, ++k)
            {
                ASSERT_TRUE(v[j] == a[k]);
            }
            for(; j < v.size(); ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
    }

    { // insert iter rvalue
        {
            inplace_vector<test_type::moint, 103>           v(100);
            inplace_vector<test_type::moint, 103>::iterator i = v.insert(v.cbegin() + 10, test_type::moint(3));
            ASSERT_TRUE(v.size() == 101);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == test_type::moint());
            }
            ASSERT_TRUE(v[j] == test_type::moint(3));
            for(++j; j < 101; ++j)
            {
                ASSERT_TRUE(v[j] == test_type::moint());
            }
        }
    }

    { // insert iter size
        {
            inplace_vector<int, 130>           v(100);
            inplace_vector<int, 130>::iterator i = v.insert(v.cbegin() + 10, 5, 1);
            ASSERT_TRUE(v.size() == 105);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            for(; j < 15; ++j)
            {
                ASSERT_TRUE(v[j] == 1);
            }
            for(++j; j < 105; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
        {
            inplace_vector<int, 130>           v(100);
            size_t                             sz = v.size();
            inplace_vector<int, 130>::iterator i  = v.insert(v.cbegin() + 10, 5, 1);
            ASSERT_TRUE(v.size() == sz + 5);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            for(; j < 15; ++j)
            {
                ASSERT_TRUE(v[j] == 1);
            }
            for(++j; j < v.size(); ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
        {
            inplace_vector<int, 130>           v(100);
            const size_t                       sz = v.size();
            inplace_vector<int, 130>::iterator i  = v.insert(v.cbegin() + 10, 5, 1);
            ASSERT_TRUE(v.size() == sz + 5);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            for(; j < 15; ++j)
            {
                ASSERT_TRUE(v[j] == 1);
            }
            for(++j; j < v.size(); ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
    }

    { // iter value:
        {
            inplace_vector<int, 130>           v(100);
            inplace_vector<int, 130>::iterator i = v.insert(v.cbegin() + 10, 1);
            ASSERT_TRUE(v.size() == 101);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            ASSERT_TRUE(v[j] == 1);
            for(++j; j < 101; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
        {
            inplace_vector<int, 130>           v(100);
            size_t                             sz = v.size();
            inplace_vector<int, 130>::iterator i  = v.insert(v.cbegin() + 10, 1);
            ASSERT_TRUE(v.size() == sz + 1);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            ASSERT_TRUE(v[j] == 1);
            for(++j; j < v.size(); ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
        {
            inplace_vector<int, 130> v(100);
            v.pop_back();
            v.pop_back(); // force no reallocation
            size_t                             sz = v.size();
            inplace_vector<int, 130>::iterator i  = v.insert(v.cbegin() + 10, 1);
            ASSERT_TRUE(v.size() == sz + 1);
            ASSERT_TRUE(i == v.begin() + 10);
            std::size_t j;
            for(j = 0; j < 10; ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
            ASSERT_TRUE(v[j] == 1);
            for(++j; j < v.size(); ++j)
            {
                ASSERT_TRUE(v[j] == 0);
            }
        }
    }

    { // push back move only
        {
            inplace_vector<test_type::moint, 6> c;
            c.push_back(test_type::moint(0));
            ASSERT_TRUE(c.size() == 1);
            for(std::size_t j = 0; j < c.size(); ++j)
            {
                ASSERT_TRUE(c[j] == test_type::moint(j));
            }
            c.push_back(test_type::moint(1));
            ASSERT_TRUE(c.size() == 2);
            for(std::size_t j = 0; j < c.size(); ++j)
            {
                ASSERT_TRUE(c[j] == test_type::moint(j));
            }
            c.push_back(test_type::moint(2));
            ASSERT_TRUE(c.size() == 3);
            for(std::size_t j = 0; j < c.size(); ++j)
            {
                ASSERT_TRUE(c[j] == test_type::moint(j));
            }
            c.push_back(test_type::moint(3));
            ASSERT_TRUE(c.size() == 4);
            for(std::size_t j = 0; j < c.size(); ++j)
            {
                ASSERT_TRUE(c[j] == test_type::moint(j));
            }
            c.push_back(test_type::moint(4));
            ASSERT_TRUE(c.size() == 5);
            for(std::size_t j = 0; j < c.size(); ++j)
            {
                ASSERT_TRUE(c[j] == test_type::moint(j));
            }
        }

        {
            inplace_vector<test_type::moint, 6> c;

            {
                const auto i = c.try_push_back(test_type::moint(0));
                ASSERT_TRUE(c.size() == 1);
                ASSERT_TRUE((c.begin() + 0) == i);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }

            {
                const auto i = c.try_push_back(test_type::moint(1));
                ASSERT_TRUE(c.size() == 2);
                ASSERT_TRUE((c.begin() + 1) == i);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }

            {
                const auto i = c.try_push_back(test_type::moint(2));
                ASSERT_TRUE((c.begin() + 2) == i);
                ASSERT_TRUE(c.size() == 3);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }

            {
                const auto i = c.try_push_back(test_type::moint(3));
                ASSERT_TRUE((c.begin() + 3) == i);
                ASSERT_TRUE(c.size() == 4);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }

            {
                const auto i = c.try_push_back(test_type::moint(4));
                ASSERT_TRUE((c.begin() + 4) == i);
                ASSERT_TRUE(c.size() == 5);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }
        }
        {
            inplace_vector<test_type::moint, 6> c;
            {
                const auto i = std::addressof(c.unchecked_push_back(test_type::moint(0)));
                ASSERT_TRUE(c.size() == 1);
                ASSERT_TRUE((c.begin() + 0) == i);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }
            {
                const auto i = std::addressof(c.unchecked_push_back(test_type::moint(1)));
                ASSERT_TRUE(c.size() == 2);
                ASSERT_TRUE((c.begin() + 1) == i);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }

            {
                const auto i = std::addressof(c.unchecked_push_back(test_type::moint(2)));
                ASSERT_TRUE((c.begin() + 2) == i);
                ASSERT_TRUE(c.size() == 3);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }
            {
                const auto i = std::addressof(c.unchecked_push_back(test_type::moint(3)));
                ASSERT_TRUE((c.begin() + 3) == i);
                ASSERT_TRUE(c.size() == 4);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }
            {
                const auto i = std::addressof(c.unchecked_push_back(test_type::moint(4)));
                ASSERT_TRUE((c.begin() + 4) == i);
                ASSERT_TRUE(c.size() == 5);
                for(std::size_t j = 0; j < c.size(); ++j)
                {
                    ASSERT_TRUE(c[j] == test_type::moint(j));
                }
            }
        }
    }
}

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif

    #undef CONSTEXPR_ASSERT_TRUE

// NOLINTEND

} // anonymous namespace

#endif // #ifndef __cpp_lib_inplace_vector
