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

#include <core/small_vector.hpp>

namespace
{

namespace test_type = fubuki::test::contiguous_container::types;

namespace small_vector_detail = fubuki::detail::small_vector;

template<typename T, std::size_t small_buffer_size = small_vector_detail::automatic_sbo_size, typename allocator = std::allocator<T>>
using small_vector = fubuki::small_vector<T, small_buffer_size, allocator>;

// NOLINTBEGIN(readability-else-after-return)

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

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

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

template<typename T, std::size_t N>
requires(N == 0 or N == 1 or N == 10)
constexpr auto make_data()
{
    if constexpr(N == 0)
    {
        return small_vector<T>{};
    }
    else if constexpr(N == 1)
    {
        return small_vector<T>(std::initializer_list<T>{0});
    }
    else if constexpr(N == 10)
    {
        return small_vector<T>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
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
}

template<typename T, std::size_t N>
constexpr void test_default_constructor()
{
    small_vector<T> v; // NOLINT(misc-const-correctness)

    if(v.size() != 0) // NOLINT(readability-container-size-empty)
    {
        throw std::logic_error{"Size mismatch"}; // Fail compilation
    }

    if(not v.empty())
    {
        throw std::logic_error{"Size mismatch"}; // Fail compilation
    }
}

template<typename T, std::size_t N>
constexpr void test_default_constructor_bounds_and_contiguous_iterators(std::size_t sz)
{
    CONSTEXPR_ASSERT_TRUE(sz <= N); // Test ill formed if it's true

    small_vector<T> v(sz); // NOLINT(misc-const-correctness)
    using diff_type = typename small_vector<T>::difference_type;

    CONSTEXPR_ASSERT_TRUE(v.size() == sz);

    for(std::size_t i = 0; i != sz; ++i)
    {
        CONSTEXPR_ASSERT_TRUE(v[i] == T{});
    }

    // contiguous
    for(std::size_t i = 0; i < v.size(); ++i)
    {
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
        using container = small_vector<T>;
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
    using container = small_vector<T>;

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
[[nodiscard]]
bool test_ctors()
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

#if !defined(__clang__) || __clang_major__ > 19
    // Clang bug causes constexpr use of std::variant<std::vector<int>> to be ill-formed before clang-19,
    // see https://godbolt.org/z/xYKacfbcM
    static_assert(implementation(), "CONSTEXPR TESTS FAILED");
#endif

    return implementation(); // Runtime
}

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

TEST(small_vector, ctors)
{
    ASSERT_TRUE((test_ctors<int, 0>()));
    ASSERT_TRUE((test_ctors<int, 1>()));
    ASSERT_TRUE((test_ctors<int, 10>()));

    { // copy construct
        small_vector<int> a = {0, 1, 2};
        ASSERT_TRUE(a.size() == std::size_t{3});
        small_vector<int> b(a);
        ASSERT_TRUE(b.size() == std::size_t{3});

        ASSERT_TRUE(std::ranges::equal(a, b));
    }

    { // move construct
        using move_only = std::unique_ptr<int>;
        small_vector<move_only> a(3);
        ASSERT_TRUE(a.size() == std::size_t{3});
        const small_vector<move_only> b(std::move(a));
        ASSERT_TRUE(b.size() == std::size_t{3});
        ASSERT_TRUE(a.size() == std::size_t{3}); // NOLINT(bugprone-use-after-move,clang-analyzer-cplusplus.Move)
    }
}

TEST(small_vector, capacity)
{
    { // capacity
        small_vector<int> a;
        ASSERT_TRUE(a.empty());
        for(std::size_t i = 0; i != 10; ++i)
        {
            a.push_back(0);
        }
        ASSERT_TRUE(a.size() == 10);
        ASSERT_TRUE(!a.empty());
    }
}

TEST(small_vector, resize)
{
    { // resize copyable
        using copyable = int;
        small_vector<copyable> a(10, 5);
        ASSERT_EQ(a.size(), 10);
        ASSERT_GE(a.capacity(), 10);
        // test_contiguous(a);
        for(std::size_t i = 0; i != 10; ++i)
        {
            ASSERT_EQ(a[i], 5);
        }
        a.resize(5);
        ASSERT_EQ(a.size(), 5);

        ASSERT_GE(a.capacity(), 10);
        // test_contiguous(a);
        a.resize(9);
        ASSERT_EQ(a[4], 5);
        for(std::size_t i = 5; i != 9; ++i)
        {
            ASSERT_EQ(a[i], 0);
        }
        ASSERT_EQ(a.size(), 9);
        ASSERT_GE(a.capacity(), 10);
        // test_contiguous(a);
        a.resize(10, 3);
        ASSERT_EQ(a[4], 5);
        ASSERT_EQ(a[8], 0);
        ASSERT_EQ(a[9], 3);
        ASSERT_EQ(a.size(), 10);
        ASSERT_GE(a.capacity(), 10);
        a.resize(5, 2);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_EQ(a[i], 5);
        }
        // test_contiguous(a);
        a.resize(12);
        ASSERT_EQ(a.capacity(), 12);
    }
    { // resize move-only
        using move_only = std::unique_ptr<int>;
        small_vector<move_only> a(10);
        ASSERT_EQ(a.size(), 10);
        ASSERT_GE(a.capacity(), 10);
        a.resize(5);
        // test_contiguous(a);
        ASSERT_EQ(a.size(), 5);
        ASSERT_GE(a.capacity(), 10);
        a.resize(9);
        ASSERT_EQ(a.size(), 9);
        ASSERT_GE(a.capacity(), 10);
    }

    { // resize value:
        using copyable = int;
        small_vector<copyable> a(10);
        ASSERT_EQ(a.size(), 10);
        ASSERT_GE(a.capacity(), 10);
        // test_contiguous(a);
        for(std::size_t i = 0; i != 10; ++i)
        {
            ASSERT_EQ(a[i], 0);
        }
        a.resize(5);
        ASSERT_EQ(a.size(), 5);
        ASSERT_GE(a.capacity(), 10);
        // test_contiguous(a);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_EQ(a[i], 0);
        }
        a.resize(9, 5);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_EQ(a[i], 0);
        }
        for(std::size_t i = 5; i != 9; ++i)
        {
            ASSERT_EQ(a[i], 5);
        }
        ASSERT_EQ(a.size(), 9);
        ASSERT_GE(a.capacity(), 10);
        // test_contiguous(a);
        a.resize(10, 3);
        for(std::size_t i = 0; i != 5; ++i)
        {
            ASSERT_EQ(a[i], 0);
        }
        for(std::size_t i = 5; i != 9; ++i)
        {
            ASSERT_EQ(a[i], 5);
        }
        ASSERT_EQ(a[9], 3);
        ASSERT_EQ(a.size(), 10);
        ASSERT_GE(a.capacity(), 10);
        // test_contiguous(a);
    }
}

TEST(small_vector, assign_copy)
{
    small_vector<int> a = {0, 1, 2};
    ASSERT_EQ(a.size(), std::size_t{3});
    small_vector<int> b;
    ASSERT_EQ(b.size(), std::size_t{0});
    b = a;
    ASSERT_EQ(b.size(), std::size_t{3});
    ASSERT_TRUE(std::ranges::equal(a, b));
}

TEST(small_vector, assign_move)
{
    using move_only = std::unique_ptr<int>;
    small_vector<move_only> a(3);
    ASSERT_EQ(a.size(), std::size_t{3});
    small_vector<move_only> b;
    ASSERT_EQ(b.size(), std::size_t{0});
    b = std::move(a);
    ASSERT_EQ(b.size(), std::size_t{3});
}

TEST(small_vector, back_front)
{
    { // mutable
        using container = small_vector<int>;
        container c(1);
        ASSERT_EQ(c.back(), 0);
        ASSERT_EQ(c.front(), 0);
        ASSERT_EQ(c[0], 0);
        c.clear();
        constexpr int one = 1;
        c.push_back(one);
        ASSERT_EQ(c.back(), 1);
        ASSERT_EQ(c.front(), 1);
        ASSERT_EQ(c[0], 1);
        ASSERT_EQ(c.size(), 1);
        c.push_back(2);
        ASSERT_EQ(c.back(), 2);
        ASSERT_EQ(c.front(), 1);
        ASSERT_EQ(c[0], 1);
        ASSERT_EQ(c[1], 2);
        ASSERT_EQ(c.size(), 2);
        c.pop_back();
        ASSERT_EQ(c.front(), 1);
        ASSERT_EQ(c[0], 1);
        ASSERT_EQ(c.back(), 1);
        c.pop_back();
        ASSERT_TRUE(c.empty());
    }

    { // const
        using container = small_vector<int>;
        const container c(1);
        ASSERT_EQ(c.back(), 0);
        ASSERT_EQ(c.front(), 0);
        ASSERT_EQ(c[0], 0);
        ASSERT_EQ(c.size(), 1);
    }
}

TEST(small_vector, swap)
{
    using container = small_vector<int>;
    container c0(3, 5);
    container c1(5, 1);
    container c2(0);
    ASSERT_EQ(c0.size(), std::size_t(3));
    ASSERT_EQ(c1.size(), 5);
    ASSERT_EQ(c2.size(), std::size_t(0));
    for(std::size_t i = 0; i != 3; ++i)
    {
        ASSERT_EQ(c0[i], 5);
    }
    for(std::size_t i = 0; i != 5; ++i)
    {
        ASSERT_EQ(c1[i], 1);
    }
    c0.swap(c1);
    ASSERT_EQ(c0.size(), 5);
    ASSERT_EQ(c1.size(), std::size_t(3));
    for(std::size_t i = 0; i != 5; ++i)
    {
        ASSERT_EQ(c0[i], 1);
    }
    for(std::size_t i = 0; i != 3; ++i)
    {
        ASSERT_EQ(c1[i], 5);
    }
    c2.swap(c1);
    ASSERT_EQ(c1.size(), std::size_t(0));
    ASSERT_EQ(c2.size(), std::size_t(3));
    for(std::size_t i = 0; i != 3; ++i)
    {
        ASSERT_EQ(c2[i], 5);
    }
}

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

TEST(small_vector, emplace)
{
    {
        small_vector<test_type::non_copyable> c;
        auto                                  iterator = c.emplace(c.cbegin(), 2, 3.5);
        ASSERT_EQ(iterator, c.begin());
        ASSERT_EQ(c.size(), 1);
        ASSERT_EQ(c.front().i(), 2);
        ASSERT_EQ(c.front().d(), 3.5);
        iterator = c.emplace(c.cend(), 3, 4.5);
        ASSERT_EQ(iterator, c.end() - 1);
        ASSERT_EQ(c.size(), 2);
        ASSERT_EQ(c.front().i(), 2);
        ASSERT_EQ(c.front().d(), 3.5);
        ASSERT_EQ(c.back().i(), 3);
        ASSERT_EQ(c.back().d(), 4.5);
        iterator = c.emplace(c.cbegin() + 1, 4, 6.5);
        ASSERT_EQ(iterator, c.begin() + 1);
        ASSERT_EQ(c.size(), 3);
        ASSERT_EQ(c.front().i(), 2);
        ASSERT_EQ(c.front().d(), 3.5);
        ASSERT_EQ(c[1].i(), 4);
        ASSERT_EQ(c[1].d(), 6.5);
        ASSERT_EQ(c.back().i(), 3);
        ASSERT_EQ(c.back().d(), 4.5);
    }
    {
        small_vector<test_type::non_copyable> c;
        auto                                  iterator = c.emplace(c.cbegin(), 2, 3.5);
        ASSERT_EQ(iterator, c.begin());
        ASSERT_EQ(c.size(), 1);
        ASSERT_EQ(c.front().i(), 2);
        ASSERT_EQ(c.front().d(), 3.5);
        iterator = c.emplace(c.cend(), 3, 4.5);
        ASSERT_EQ(iterator, c.end() - 1);
        ASSERT_EQ(c.size(), 2);
        ASSERT_EQ(c.front().i(), 2);
        ASSERT_EQ(c.front().d(), 3.5);
        ASSERT_EQ(c.back().i(), 3);
        ASSERT_EQ(c.back().d(), 4.5);
        iterator = c.emplace(c.cbegin() + 1, 4, 6.5);
        ASSERT_EQ(iterator, c.begin() + 1);
        ASSERT_EQ(c.size(), 3);
        ASSERT_EQ(c.front().i(), 2);
        ASSERT_EQ(c.front().d(), 3.5);
        ASSERT_EQ(c[1].i(), 4);
        ASSERT_EQ(c[1].d(), 6.5);
        ASSERT_EQ(c.back().i(), 3);
        ASSERT_EQ(c.back().d(), 4.5);
    }
    {
        small_vector<int> v;
        v = {1, 2, 3};

        v.emplace(v.cbegin(), v.back());
        ASSERT_EQ(v[0], 3);
    }
    {
        small_vector<int> v;
        v = {1, 2, 3};
        v.emplace(v.cbegin(), v.back());
        ASSERT_EQ(v[0], 3);
    }
}

TEST(small_vector, emplace_back)
{
    small_vector<test_type::non_copyable> c;
    c.emplace_back(2, 3.5);
    ASSERT_EQ(c.size(), 1);
    ASSERT_EQ(c.front().i(), 2);
    ASSERT_EQ(c.front().d(), 3.5);
    c.emplace_back(3, 4.5);
    ASSERT_EQ(c.size(), 2);
    ASSERT_EQ(c.front().i(), 2);
    ASSERT_EQ(c.front().d(), 3.5);
    ASSERT_EQ(c.back().i(), 3);
    ASSERT_EQ(c.back().d(), 4.5);
}

TEST(small_vector, erase)
{
    { // erase(it)
        using it       = small_vector<int>::iterator;
        using const_it = small_vector<int>::const_iterator;

        constexpr std::array<int, 3> a1 = {1, 2, 3};
        small_vector<int>            l1(a1.data(), a1.data() + a1.size());
        ASSERT_TRUE(l1.size() == 3);
        const_it const_iterator = l1.begin(); // NOLINT(clazy-strict-iterators)
        ++const_iterator;
        it j = l1.erase(const_iterator);
        ASSERT_TRUE(l1.size() == 2);
        ASSERT_TRUE(std::distance(l1.begin(), l1.end()) == 2);
        ASSERT_TRUE(*j == 3);
        ASSERT_TRUE(*l1.begin() == 1);
        ASSERT_TRUE(*std::next(l1.begin()) == 3);
        j = l1.erase(const_it{j});
        ASSERT_TRUE(j == l1.end());
        ASSERT_TRUE(l1.size() == 1);
        ASSERT_TRUE(std::distance(l1.begin(), l1.end()) == 1);
        ASSERT_TRUE(*l1.begin() == 1);
        j = l1.erase(l1.cbegin());
        ASSERT_TRUE(j == l1.end());
        ASSERT_TRUE(l1.empty());
        ASSERT_TRUE(std::distance(l1.begin(), l1.end()) == 0);
    }

    { // erase(it, it)
        constexpr std::array<int, 3> a1 = {1, 2, 3};
        using vec_t                     = small_vector<int>;
        {
            vec_t           l1(a1.data(), a1.data() + a1.size());
            vec_t::iterator i = l1.erase(l1.cbegin(), l1.cbegin());
            ASSERT_TRUE(l1.size() == 3);
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 3);
            ASSERT_TRUE(i == l1.begin());
        }
        {
            vec_t           l1(a1.data(), a1.data() + a1.size());
            vec_t::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin()));
            ASSERT_TRUE(l1.size() == 2);
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 2);
            ASSERT_TRUE(i == l1.begin());
            ASSERT_TRUE(l1 == vec_t(a1.data() + 1, a1.data() + a1.size()));
        }
        {
            vec_t           l1(a1.data(), a1.data() + a1.size());
            vec_t::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 2));
            ASSERT_TRUE(l1.size() == 1);
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 1);
            ASSERT_TRUE(i == l1.begin());
            ASSERT_TRUE(l1 == vec_t(a1.data() + 2, a1.data() + a1.size()));
        }
        {
            vec_t           l1(a1.data(), a1.data() + a1.size());
            vec_t::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 3));
            ASSERT_TRUE(l1.empty());
            ASSERT_TRUE(std::distance(l1.cbegin(), l1.cend()) == 0);
            ASSERT_TRUE(i == l1.begin());
        }
        {
            small_vector<vec_t> outer(2, vec_t(1));
            outer.erase(outer.cbegin(), outer.cbegin());
            ASSERT_TRUE(outer.size() == 2);
            ASSERT_TRUE(outer[0].size() == 1);
            ASSERT_TRUE(outer[1].size() == 1);
        }
    }
}

TEST(small_vector, insert_initializer_list)
{
    small_vector<int>           d(10, 1);
    small_vector<int>::iterator i = d.insert(d.cbegin() + 2, {3, 4, 5, 6});
    ASSERT_EQ(d.size(), 14);
    ASSERT_EQ(i, d.begin() + 2);
    ASSERT_EQ(d[0], 1);
    ASSERT_EQ(d[1], 1);
    ASSERT_EQ(d[2], 3);
    ASSERT_EQ(d[3], 4);
    ASSERT_EQ(d[4], 5);
    ASSERT_EQ(d[5], 6);
    ASSERT_EQ(d[6], 1);
    ASSERT_EQ(d[7], 1);
    ASSERT_EQ(d[8], 1);
    ASSERT_EQ(d[9], 1);
    ASSERT_EQ(d[10], 1);
    ASSERT_EQ(d[11], 1);
    ASSERT_EQ(d[12], 1);
    ASSERT_EQ(d[13], 1);
}

TEST(small_vector, insert_iterator_iterator)
{
    {
        small_vector<int>           v(100);
        std::array                  a = {1, 2, 3, 4, 5};
        small_vector<int>::iterator i = v.insert(v.cbegin() + 10, (a.data()), (a.data() + a.size()));
        ASSERT_EQ(v.size(), 100 + a.size());
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        for(std::size_t k = 0; k < a.size(); ++j, ++k)
        {
            ASSERT_EQ(v[j], a[k]); // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
        }
        for(; j < 105; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
    {
        small_vector<int>           v(100);
        const std::size_t           sz = v.size();
        constexpr std::array        a  = {1, 2, 3, 4, 5};
        small_vector<int>::iterator i  = v.insert(v.cbegin() + 10, a.begin(), a.end());
        ASSERT_EQ(v.size(), sz + a.size());
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        for(std::size_t k = 0; k < a.size(); ++j, ++k)
        {
            ASSERT_EQ(v[j], a[k]); // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
        }
        for(; j < v.size(); ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
}

TEST(small_vector, insert_iter_rvalue)
{
    small_vector<test_type::moint>           v(100);
    small_vector<test_type::moint>::iterator i = v.insert(v.cbegin() + 10, test_type::moint(3));
    ASSERT_EQ(v.size(), 101);
    ASSERT_EQ(i, v.begin() + 10);
    std::size_t j = {};
    for(j = 0; j < 10; ++j)
    {
        ASSERT_EQ(v[j], test_type::moint());
    }
    ASSERT_EQ(v[j], test_type::moint(3));
    for(++j; j < 101; ++j)
    {
        ASSERT_EQ(v[j], test_type::moint());
    }
}

TEST(small_vector, size_after_insert)
{
    {
        small_vector<int>           v(100);
        small_vector<int>::iterator i = v.insert(v.cbegin() + 10, 5, 1);
        ASSERT_EQ(v.size(), 105);
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        for(; j < 15; ++j)
        {
            ASSERT_EQ(v[j], 1);
        }
        for(++j; j < 105; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
    {
        small_vector<int>           v(100);
        const std::size_t           sz = v.size();
        small_vector<int>::iterator i  = v.insert(v.cbegin() + 10, 5, 1);
        ASSERT_EQ(v.size(), sz + 5);
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        for(; j < 15; ++j)
        {
            ASSERT_EQ(v[j], 1);
        }
        for(++j; j < v.size(); ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
    {
        small_vector<int>           v(100);
        const size_t                sz = v.size();
        small_vector<int>::iterator i  = v.insert(v.cbegin() + 10, 5, 1);
        ASSERT_EQ(v.size(), sz + 5);
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        for(; j < 15; ++j)
        {
            ASSERT_EQ(v[j], 1);
        }
        for(++j; j < v.size(); ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
}

TEST(small_vector, insert_iter_lvalue)
{
    {
        small_vector<int>           v(100);
        small_vector<int>::iterator i = v.insert(v.cbegin() + 10, 1);
        ASSERT_EQ(v.size(), 101);
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        ASSERT_EQ(v[j], 1);
        for(++j; j < 101; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
    {
        small_vector<int>           v(100);
        const std::size_t           sz = v.size();
        small_vector<int>::iterator i  = v.insert(v.cbegin() + 10, 1);
        ASSERT_EQ(v.size(), sz + 1);
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        ASSERT_EQ(v[j], 1);
        for(++j; j < v.size(); ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
    {
        small_vector<int> v(100);
        v.pop_back();
        v.pop_back(); // force no reallocation
        const std::size_t           sz = v.size();
        small_vector<int>::iterator i  = v.insert(v.cbegin() + 10, 1);
        ASSERT_EQ(v.size(), sz + 1);
        ASSERT_EQ(i, v.begin() + 10);
        std::size_t j = {};
        for(j = 0; j < 10; ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
        ASSERT_EQ(v[j], 1);
        for(++j; j < v.size(); ++j)
        {
            ASSERT_EQ(v[j], 0);
        }
    }
}

TEST(small_vector, converting_iter)
{ // converting iter
    // Float -> int (implicit conversions)
    {
        constexpr std::array<float, 3> contents = {1.f, 2.f, 3.f};
        using vec                               = small_vector<int>;
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), l1.cbegin());
            ASSERT_EQ(l1.size(), 3);
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 3);
            ASSERT_EQ(i, l1.begin());
        }
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin()));
            ASSERT_EQ(l1.size(), 2);
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 2);
            ASSERT_EQ(i, l1.begin());
            ASSERT_EQ(l1, vec(contents.data() + 1, contents.data() + contents.size()));
        }
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 2));
            ASSERT_EQ(l1.size(), 1);
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 1);
            ASSERT_EQ(i, l1.begin());
            ASSERT_EQ(l1, vec(contents.data() + 2, contents.data() + contents.size()));
        }
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 3));
            ASSERT_TRUE(l1.empty());
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 0);
            ASSERT_EQ(i, l1.begin());
        }
        {
            small_vector<vec> outer(2, vec(1));
            outer.erase(outer.cbegin(), outer.cbegin());
            ASSERT_EQ(outer.size(), 2);
            ASSERT_EQ(outer[0].size(), 1);
            ASSERT_EQ(outer[1].size(), 1);
        }
    }

    // Int -> struct (explicit ctor)
    {
        constexpr std::array<int, 4> contents = {4, 5, 6, 7};

        using vec = small_vector<test_type::constructible_from_int>;
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), l1.cbegin());
            ASSERT_EQ(l1.size(), 4); // Doesn't change the size: the range given to erase() is zero-size
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 4);
            ASSERT_EQ(i, l1.begin());
        }
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin()));
            ASSERT_EQ(l1.size(), 3);
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 3);
            ASSERT_EQ(i, l1.begin());
            ASSERT_EQ(l1, vec(contents.data() + 1, contents.data() + contents.size()));
        }
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 2));
            ASSERT_EQ(l1.size(), 2);
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 2);
            ASSERT_EQ(i, l1.begin());
            ASSERT_EQ(l1, vec(contents.data() + 2, contents.data() + contents.size()));
        }
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 3));
            ASSERT_EQ(l1.size(), 1);
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 1);
            ASSERT_EQ(i, l1.begin());
            ASSERT_EQ(l1, vec(contents.data() + 3, contents.data() + contents.size()));
        }
        {
            vec           l1(contents.data(), contents.data() + contents.size());
            vec::iterator i = l1.erase(l1.cbegin(), std::next(l1.cbegin(), 4));
            ASSERT_TRUE(l1.empty());
            ASSERT_EQ(std::distance(l1.cbegin(), l1.cend()), 0);
            ASSERT_EQ(i, l1.begin());
        }
    }
}

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

TEST(small_vector, push_back)
{ // push back move only
    {
        small_vector<test_type::moint> c;
        c.push_back(test_type::moint(0));
        ASSERT_EQ(c.size(), 1);
        for(std::size_t j = 0; j < c.size(); ++j)
        {
            ASSERT_EQ(c[j], test_type::moint(j));
        }
        c.push_back(test_type::moint(1));
        ASSERT_EQ(c.size(), 2);
        for(std::size_t j = 0; j < c.size(); ++j)
        {
            ASSERT_EQ(c[j], test_type::moint(j));
        }
        c.push_back(test_type::moint(2));
        ASSERT_EQ(c.size(), 3);
        for(std::size_t j = 0; j < c.size(); ++j)
        {
            ASSERT_EQ(c[j], test_type::moint(j));
        }
        c.push_back(test_type::moint(3));
        ASSERT_EQ(c.size(), 4);
        for(std::size_t j = 0; j < c.size(); ++j)
        {
            ASSERT_EQ(c[j], test_type::moint(j));
        }
        c.push_back(test_type::moint(4));
        ASSERT_EQ(c.size(), 5);
        for(std::size_t j = 0; j < c.size(); ++j)
        {
            ASSERT_EQ(c[j], test_type::moint(j));
        }
    }
}

TEST(small_vector, api)
{
    { // old tests
        using vec_t = small_vector<int>;
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
            ASSERT_EQ(vec1[0], 0);
            ASSERT_EQ(vec1[4], 4);
            ASSERT_EQ(vec2[0], 5);
            ASSERT_EQ(vec2[4], 9);
        }
        {
            auto vec2 = vec1; // NOLINT(performance-unnecessary-copy-initialization)
            ASSERT_EQ(vec2[0], 0);
            ASSERT_EQ(vec2[4], 4);
            ASSERT_EQ(vec1[0], 0);
            ASSERT_EQ(vec1[4], 4);
        }
        {

            for(int counter = 0; auto i : vec1)
            {
                ASSERT_EQ(i, counter);
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
            std::ranges::copy(vec2, std::begin(vec));

            for(int counter = 4; auto i : vec)
            {
                ASSERT_EQ(i, counter);
                counter--;
            }
        }
    }
}

TEST(small_vector, range_concepts)
{
    STATIC_EXPECT_TRUE((std::ranges::range<small_vector<int>>) );
    STATIC_EXPECT_TRUE((std::ranges::range<small_vector<std::unique_ptr<int>>>) );
    STATIC_EXPECT_TRUE((std::ranges::range<small_vector<int, 0>>) );
    STATIC_EXPECT_TRUE((std::ranges::range<small_vector<std::unique_ptr<int>, 0>>) );
    STATIC_EXPECT_TRUE((std::ranges::range<small_vector<int, 10>>) );
    STATIC_EXPECT_TRUE((std::ranges::range<small_vector<std::unique_ptr<int>, 10>>) );

    STATIC_EXPECT_TRUE((std::ranges::contiguous_range<small_vector<int>>) );
    STATIC_EXPECT_TRUE((std::ranges::contiguous_range<small_vector<std::unique_ptr<int>>>) );
    STATIC_EXPECT_TRUE((std::ranges::contiguous_range<small_vector<int, 0>>) );
    STATIC_EXPECT_TRUE((std::ranges::contiguous_range<small_vector<std::unique_ptr<int>, 0>>) );
    STATIC_EXPECT_TRUE((std::ranges::contiguous_range<small_vector<int, 10>>) );
    STATIC_EXPECT_TRUE((std::ranges::contiguous_range<small_vector<std::unique_ptr<int>, 10>>) );
}

#undef STATIC_EXPECT_TRUE
#undef CONSTEXPR_ASSERT_TRUE

} // anonymous namespace
