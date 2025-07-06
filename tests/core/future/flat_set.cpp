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

#include <array>
#include <cstdint>
#include <set>
#include <source_location>
#include <string_view>

#include <gtest/gtest.h>

#include <core/future/flat_set.hpp>

// No need to test the Standard Library version
#ifndef __cpp_lib_flat_set

namespace
{

    #define STATIC_EXPECT_TRUE(x) \
        static_assert((x));       \
        EXPECT_TRUE((x))

template<typename T, typename comparison = std::less<T>>
void compare(const fubuki::flat_set<T, comparison>& flat,
             const std::set<T, comparison>&         expectations,
             const std::source_location             origin = std::source_location::current())
{
    EXPECT_EQ(flat.size(), expectations.size()) << " From " << origin.function_name() << " in " << origin.file_name() << " at line " << origin.line()
                                                << " at column " << origin.column();

    for(std::ptrdiff_t i = 0; const auto& expected_v : expectations)
    {
        EXPECT_EQ(expected_v, *(flat.cbegin() + i))
            << " From " << origin.function_name() << " in " << origin.file_name() << " at line " << origin.line() << " at column " << origin.column();
        ++i;
    }
}

TEST(flat_set, types)
{
    using key_type       = int;
    using compare_type   = std::less<int>;
    using container_type = std::vector<int>;
    using flat_set       = fubuki::flat_set<key_type, compare_type, container_type>;

    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::key_type, key_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::value_type, key_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::key_compare, compare_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::value_compare, compare_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::reference, key_type&>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::const_reference, const key_type&>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::size_type, typename container_type::size_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::difference_type, typename container_type::difference_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::iterator, typename container_type::iterator>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::const_iterator, typename container_type::const_iterator>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::reverse_iterator, typename container_type::reverse_iterator>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::const_reverse_iterator, typename container_type::const_reverse_iterator>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flat_set::container_type, container_type>) );
}

TEST(flat_set, ctor)
{
    using fubuki::flat_set;

    // flat_set()
    {
        const flat_set<std::uint8_t> s;
        EXPECT_TRUE(s.empty());
        EXPECT_EQ(s.size(), 0u);
    }

    // flat_set(container_type)
    {
        std::vector<std::uint32_t>    data   = {1, 3, 4, 5, 6, 7, 0};
        const std::set<std::uint32_t> as_set = {data.begin(), data.end()};
        const flat_set<std::uint32_t> flat{std::move(data)};

        compare(flat, as_set);
    }

    // flat_set(const container_type&, const allocator&)
    {
        const std::vector<std::uint32_t> data   = {1, 3, 4, 5, 6, 7, 0, 0, 0};
        const std::set<std::uint32_t>    as_set = {data.begin(), data.end()};
        const flat_set<std::uint32_t>    flat   = {data, std::allocator<std::uint32_t>()};

        compare(flat, as_set);
    }

    // flat_set(sorted_unique_t, container_type)
    {
        const flat_set<int> s(fubuki::sorted_unique, std::vector<int>{1, 2, 3});
        compare(s, {1, 2, 3});
    }

    // flat_set(sorted_unique_t, const container_type&, const allocator&)
    {
        const std::vector<int> data = {1, 2, 3, 4, 5, 6};

        const flat_set<int> s(fubuki::sorted_unique, data, std::allocator<int>{});
        compare(s, {data.cbegin(), data.cend()});
    }

    // flat_set(const key_compare&)
    {
        const flat_set<std::uint32_t, std::greater<int>> flat{std::greater<int>{}};
        EXPECT_TRUE(flat.empty());
    }

    // flat_set(const key_compare&, const allocator&)
    {
        const flat_set<std::uint32_t, std::greater<int>> flat{std::greater<int>{}, std::allocator<std::uint32_t>()};
        EXPECT_TRUE(flat.empty());
    }

    // flat_set(input_iterator, input_iterator, const key_compare& = key_compare())
    {
        const std::vector<int> data{1, 2, 3, 4, 5, 6, 0, 3};

        const flat_set<int, std::greater<>> flat     = {data.cbegin(), data.cend()};
        const std::set<int, std::greater<>> non_flat = {data.cbegin(), data.cend()};

        compare(flat, non_flat);
    }

    // flat_set(input_iterator, input_iterator, const key_compare&, const allocator&)
    {
        const std::vector<int> data = {1, 2, 3, 4, 5, 6, 0, 3};

        const flat_set<int, std::greater<>> flat     = {data.cbegin(), data.cend(), std::greater<>{}, std::allocator<int>{}};
        const std::set<int, std::greater<>> non_flat = {data.cbegin(), data.cend()};

        compare(flat, non_flat);
    }

    // flat_set(input_iterator, input_iterator, const allocator&)
    {
        const std::vector<int> data = {1, 2, 3, 4, 5, 6, 0, 3};

        const flat_set<int, std::greater<>> flat     = {data.cbegin(), data.cend(), std::allocator<int>{}};
        const std::set<int, std::greater<>> non_flat = {data.cbegin(), data.cend()};

        compare(flat, non_flat);
    }

    // flat_set(sorted_unique_t, input_iterator, input_iterator, const key_compare& = key_compare())
    {
        const std::vector<int> data = {-1, 0, 1, 2, 3, 4, 5, 6};

        const flat_set<int> flat     = {fubuki::sorted_unique, data.cbegin(), data.cend()};
        const std::set<int> non_flat = {data.cbegin(), data.cend()};

        compare(flat, non_flat);
    }

    // flat_set(sorted_unique_t, input_iterator, input_iterator, const key_compare&, const allocator&)
    {
        const std::vector<int> data = {-1, 0, 1, 2, 3, 4, 5, 6};

        const flat_set<int> flat     = {fubuki::sorted_unique, data.cbegin(), data.cend(), std::less<int>{}, std::allocator<int>{}};
        const std::set<int> non_flat = {data.cbegin(), data.cend()};

        compare(flat, non_flat);
    }

    // flat_set(sorted_unique_t, input_iterator, input_iterator, const allocator&)
    {
        const std::vector<int> data = {-1, 0, 1, 2, 3, 4, 5, 6};

        const flat_set<int> flat     = {fubuki::sorted_unique, data.cbegin(), data.cend(), std::allocator<int>{}};
        const std::set<int> non_flat = {data.cbegin(), data.cend()};

        compare(flat, non_flat);
    }

    // flat_set(std::initializer_list<key_type>, const key_compare& = key_compare())
    {
        const std::initializer_list<int> data = {-1, 0, 1, 2, 3, 4, 5, 6, 0, 23, 2};

        const flat_set<int> flat     = {data};
        const std::set<int> non_flat = {data};

        compare(flat, non_flat);
    }

    // flat_set(std::initializer_list<key_type>, const key_compare&, const allocator&)
    {
        const std::initializer_list<int> data{-1, 0, 1, 2, 3, 4, 5, 6, -2};

        const flat_set<int, std::greater<>> flat     = {data, std::greater<>{}, std::allocator<int>{}};
        const std::set<int, std::greater<>> non_flat = {data};

        compare(flat, non_flat);
    }

    // flat_set(std::initializer_list<key_type>, const allocator&)
    {
        const std::initializer_list<int> data = {0, 1, 2, 3, 4, 5, 6, -1};

        const flat_set<int, std::greater<>> flat     = {data, std::allocator<int>{}};
        const std::set<int, std::greater<>> non_flat = {data};

        compare(flat, non_flat);
    }

    // flat_set(sorted_unique_t, std::initializer_list<key_type>, const key_compare& = key_compare())
    {
        const std::initializer_list<int> data = {
            0,
            1,
            2,
            3,
            4,
            5,
            6,
        };

        const flat_set<int> flat     = {fubuki::sorted_unique, data};
        const std::set<int> non_flat = {data};

        compare(flat, non_flat);
    }

    // flat_set(sorted_unique_t, std::initializer_list<key_type>, const key_compare&, const allocator&)
    {
        const std::initializer_list<int> data{
            0,
            1,
            2,
            3,
            4,
            5,
            6,
        };

        const flat_set<int> flat     = {fubuki::sorted_unique, data, std::less<int>{}, std::allocator<int>{}};
        const std::set<int> non_flat = {data};

        compare(flat, non_flat);
    }

    // flat_set(sorted_unique_t, std::initializer_list<key_type>, const allocator&)
    {
        const std::initializer_list<int> data{
            0,
            1,
            2,
            3,
            4,
            5,
            6,
        };

        const flat_set<int> flat{fubuki::sorted_unique, data, std::allocator<int>{}};
        const std::set<int> non_flat{data};

        compare(flat, non_flat);
    }
}

TEST(flat_set, iterators)
{
    using fubuki::flat_set;

    // begin/end
    {
        {
            flat_set<int> mutable_set = {1, 2, 3};

            EXPECT_EQ(1, *mutable_set.begin());
            EXPECT_EQ(2, *(mutable_set.begin() + 1));
            EXPECT_EQ(3, *(mutable_set.begin() + 2));
            EXPECT_EQ(3, *(mutable_set.end() - 1));
        }

        {
            const flat_set<int> const_set = {1, 2, 3};

            EXPECT_EQ(1, *const_set.begin());
            EXPECT_EQ(2, *(const_set.begin() + 1));
            EXPECT_EQ(3, *(const_set.begin() + 2));
            EXPECT_EQ(3, *(const_set.end() - 1));
        }
    }

    // rbegin/rend
    {
        {
            flat_set<int> mutable_set = {1, 2, 3};

            EXPECT_EQ(3, *mutable_set.rbegin());
            EXPECT_EQ(2, *(mutable_set.rbegin() + 1));
            EXPECT_EQ(1, *(mutable_set.rbegin() + 2));
            EXPECT_EQ(1, *(mutable_set.rend() - 1));
        }

        {
            const flat_set<int> const_set = {1, 2, 3};

            EXPECT_EQ(3, *const_set.rbegin());
            EXPECT_EQ(2, *(const_set.rbegin() + 1));
            EXPECT_EQ(1, *(const_set.rbegin() + 2));
            EXPECT_EQ(1, *(const_set.rend() - 1));
        }
    }

    // cbegin/cend
    {
        {
            flat_set<int> mutable_set = {1, 2, 3}; // NOLINT(misc-const-correctness)

            EXPECT_EQ(1, *mutable_set.cbegin());
            EXPECT_EQ(2, *(mutable_set.cbegin() + 1));
            EXPECT_EQ(3, *(mutable_set.cbegin() + 2));
            EXPECT_EQ(3, *(mutable_set.cend() - 1));
        }

        {
            const flat_set<int> const_set = {1, 2, 3};

            EXPECT_EQ(1, *const_set.cbegin());
            EXPECT_EQ(2, *(const_set.cbegin() + 1));
            EXPECT_EQ(3, *(const_set.cbegin() + 2));
            EXPECT_EQ(3, *(const_set.cend() - 1));
        }
    }

    // crbegin/crend
    {
        {
            flat_set<int> mutable_set = {1, 2, 3}; // NOLINT(misc-const-correctness)

            EXPECT_EQ(3, *mutable_set.crbegin());
            EXPECT_EQ(2, *(mutable_set.crbegin() + 1));
            EXPECT_EQ(1, *(mutable_set.crbegin() + 2));
            EXPECT_EQ(1, *(mutable_set.crend() - 1));
        }

        {
            const flat_set<int> const_set = {1, 2, 3};

            EXPECT_EQ(3, *const_set.crbegin());
            EXPECT_EQ(2, *(const_set.crbegin() + 1));
            EXPECT_EQ(1, *(const_set.crbegin() + 2));
            EXPECT_EQ(1, *(const_set.crend() - 1));
        }
    }
}

TEST(flat_set, capacity)
{
    using fubuki::flat_set;

    const flat_set<std::string_view> empty;
    const flat_set<std::string_view> not_empty = {"0", "1", "2", "3", "4"};

    // empty
    {
        EXPECT_TRUE(empty.empty());
        EXPECT_FALSE(not_empty.empty());
    }

    // size
    {
        EXPECT_EQ(empty.size(), 0u);
        EXPECT_EQ(not_empty.size(), 5u);
    }

    // max_size
    {
        EXPECT_EQ(empty.max_size(), flat_set<std::string_view>::container_type{}.max_size());
    }
}

TEST(flat_set, modifiers)
{
    using fubuki::flat_set;

    // emplace
    {
        flat_set<std::string_view> flat;

        const auto emplace_1 = flat.emplace("foo");
        const auto emplace_2 = flat.emplace("bar");
        const auto emplace_3 = flat.emplace("bar"); // Second time, should do nothing

        EXPECT_TRUE(emplace_1.second);
        EXPECT_TRUE(emplace_2.second);
        EXPECT_FALSE(emplace_3.second);

        // Insertion position is tested in compare()

        compare(flat, {"foo", "bar"});
    }

    // emplace_hint
    {
        flat_set<int> flat   = {1, 2, 3, 4};
        const auto    result = flat.emplace_hint(flat.begin(), 0);

        EXPECT_EQ(result, flat.begin());

        compare(flat, {0, 1, 2, 3, 4});
    }

    // insert
    {
        // insert(const value_type&>
        {
            const std::string_view data_1 = "foo";
            const std::string_view data_2 = "bar";

            flat_set<std::string_view> flat;
            const auto                 insert_1 = flat.insert(data_1);
            const auto                 insert_2 = flat.insert(data_2);
            const auto                 insert_3 = flat.insert(data_2); // Second time, should do nothing

            EXPECT_TRUE(insert_1.second);
            EXPECT_TRUE(insert_2.second);
            EXPECT_FALSE(insert_3.second);

            // Insertion position is tested in compare()

            compare(flat, {"foo", "bar"});
        }

        // insert(value_type&&)
        {
            flat_set<std::string_view> flat;
            const auto                 insert_1 = flat.insert(std::string_view{"bar"});
            const auto                 insert_2 = flat.insert(std::string_view{"foo"});
            const auto                 insert_3 = flat.insert(std::string_view{"foo"}); // Second time, should do nothing

            EXPECT_TRUE(insert_1.second);
            EXPECT_TRUE(insert_2.second);
            EXPECT_FALSE(insert_3.second);

            // Insertion position is tested in compare()

            compare(flat, {"foo", "bar"});
        }

        // insert(K&&)
        {
            struct converts_to_int
            {
                int v = {};

                [[nodiscard]] constexpr operator int() const noexcept { return v; }
            };

            flat_set<int> flat;
            const auto    insert_1 = flat.insert(converts_to_int{1});
            const auto    insert_2 = flat.insert(converts_to_int{2});
            const auto    insert_3 = flat.insert(converts_to_int{3});
            const auto    insert_4 = flat.insert(converts_to_int{3}); // Should do nothing

            EXPECT_TRUE(insert_1.second);
            EXPECT_TRUE(insert_2.second);
            EXPECT_TRUE(insert_3.second);
            EXPECT_FALSE(insert_4.second);

            // Insertion position is tested in compare()

            compare(flat, {1, 2, 3});
        }

        // insert(const_iterator, const value_type&)
        {
            const std::string_view data_1 = "foo";
            const std::string_view data_2 = "bar";

            flat_set<std::string_view> flat;
            flat.insert(flat.begin(), data_1);
            flat.insert(flat.begin(), data_2);
            flat.insert(flat.begin(), data_2); // Second time, should do nothing

            // Insertion position is tested in compare()

            compare(flat, {"foo", "bar"});
        }

        // insert(const_iterator, value_type&&)
        {
            flat_set<std::string_view> flat;
            flat.insert(flat.begin(), std::string_view{"foo"});
            flat.insert(flat.begin(), std::string_view{"bar"});
            flat.insert(flat.begin(), std::string_view{"bar"}); // Second time, should do nothing

            // Insertion position is tested in compare()

            compare(flat, {"foo", "bar"});
        }

        // insert(const_iterator, K&&)
        {
            flat_set<std::string_view> flat;
            flat.insert(flat.begin(), "foo");
            flat.insert(flat.begin(), "bar");
            flat.insert(flat.begin(), "bar"); // Second time, should do nothing

            // Insertion position is tested in compare()

            compare(flat, {"foo", "bar"});
        }

        // insert(input_iterator, input_iterator)
        {
            const std::initializer_list<int> data = {1, 2, 3, 4, 5, 6, 7, -1};

            flat_set<int> flat;
            flat.insert(data.begin(), data.end());

            compare(flat, {data});
        }

        // insert(sorted_unique_t, input_iterator, input_iterator)
        {
            const std::initializer_list<int> data = {1, 2, 3, 4, 5, 6, 7};

            flat_set<int> flat;
            flat.insert(fubuki::sorted_unique, data.begin(), data.end());

            compare(flat, {data});
        }

        // insert(std::initializer_list<key_type>)
        {
            std::initializer_list<int> data = {1, 2, 3, 4, 5, 6, 7}; // NOLINT(misc-const-correctness)

            flat_set<int> flat;
            flat.insert(fubuki::sorted_unique, data);

            compare(flat, {data});
        }

        //  insert(sorted_unique_t, std::initializer_list<key_type>)
        {
            const std::initializer_list<int> data = {1, 2, 3, 4, 5, 6, 7};

            flat_set<int> flat;
            flat.insert(fubuki::sorted_unique, data);

            compare(flat, {data});
        }
    }

    // insert_range
    {
        flat_set<int>            s;
        const std::array<int, 4> data = {-1, -2, 1, 3};

        s.insert_range(data);
        compare(s,
                {
                    {-1, -2, 1, 3}
        });
    }

    // extract
    {
        const std::vector<int> expected_contents = {0, 1, 2, 3, 4, 5};

        auto contents = flat_set<int>{
            {1,
             2, 3,
             4, 5,
             0, 1}
        }.extract();

        EXPECT_EQ(expected_contents, contents);
    }

    // replace
    {
        std::vector<int> new_contents = {0, 1, 2, 3, 4, 5};

        flat_set<int> flat;
        flat.replace(std::move(new_contents));

        compare(flat, {0, 1, 2, 3, 4, 5});
    }

    // erase
    {
        struct converts_to_str_view
        {
            std::string_view str = {};

            [[nodiscard]] constexpr operator std::string_view() const noexcept { return str; }
        };

        // erase(iterator)
        {
            flat_set<std::string_view> flat{"foo", "bar", "zog"};
            flat.erase(flat.begin() + 1);

            EXPECT_EQ(flat.size(), 2u);
            compare(flat, {"bar", "zog"});
        }

        // erase(const_iterator)
        {
            flat_set<std::string_view> flat{"foo", "bar", "zog"};
            flat.erase(flat.cbegin() + 1);

            EXPECT_EQ(flat.size(), 2u);
            compare(flat, {"bar", "zog"});
        }

        // erase(const key_type&)
        {
            flat_set<std::string_view> flat{"foo", "bar", "zog"};
            flat.erase("foo");

            EXPECT_EQ(flat.size(), 2u);
            compare(flat, {"bar", "zog"});
        }

        // erase(K&&)
        {
            flat_set<std::string_view> flat{"foo", "bar", "zog"};
            flat.erase(converts_to_str_view{"foo"});

            EXPECT_EQ(flat.size(), 2u);
            compare(flat, {"bar", "zog"});
        }

        // erase(const_iterator, const_iterator)
        {
            flat_set<std::string_view> flat{"foo", "bar", "zog"};
            flat.erase(flat.begin(), flat.begin() + 2);

            EXPECT_EQ(flat.size(), 1u);
            compare(flat, {"zog"});
        }
    }

    // swap
    {
        flat_set<int> flat_a{1, 2, 3};
        flat_set<int> flat_b{4, 5, 6};

        flat_a.swap(flat_b);

        compare(flat_a, {4, 5, 6});
        compare(flat_b, {1, 2, 3});
    }

    // clear
    {
        flat_set<std::string_view> flat{"foo", "bar", "zog"};
        flat.clear();

        EXPECT_TRUE(flat.empty());
    }
}

TEST(flat_set, observers)
{
    using fubuki::flat_set;

    // key_comp
    {
        const flat_set<std::string_view> flat;

        STATIC_EXPECT_TRUE((std::is_same_v<std::decay_t<decltype(flat.key_comp())>, std::less<std::string_view>>) );
    }

    // value_comp
    {
        const flat_set<int, std::greater<int>> flat;

        STATIC_EXPECT_TRUE((std::is_same_v<std::decay_t<decltype(flat.value_comp())>, std::greater<int>>) );
    }
}

TEST(flat_set, set_operations)
{
    using fubuki::flat_set;

    struct converts_to_str_view
    {
        std::string_view str = {};

        [[nodiscard]] constexpr operator std::string_view() const noexcept { return str; }
    };

    // Purposefully not const to test const and non-const overloads
    flat_set<std::string_view> flat{"bar", "cat", "f", "zog"};

    // find
    {
        // find(const key_type&)
        {
            const auto should_exist = flat.find("cat");
            EXPECT_NE(should_exist, flat.end());
            EXPECT_EQ(*should_exist, "cat");

            const auto should_not_exist = flat.find("tac");
            EXPECT_EQ(should_not_exist, flat.end());
        }

        // find(const key_type&) const
        {
            const auto should_exist = std::as_const(flat).find("cat");
            EXPECT_NE(should_exist, std::as_const(flat).end());
            EXPECT_EQ(*should_exist, "cat");

            const auto should_not_exist = std::as_const(flat).find("tac");
            EXPECT_EQ(should_not_exist, std::as_const(flat).end());
        }

        // find(const K&)
        {
            const auto should_exist = flat.find(converts_to_str_view{"cat"});
            EXPECT_NE(should_exist, flat.end());
            EXPECT_EQ(*should_exist, "cat");

            const auto should_not_exist = flat.find(converts_to_str_view{"tac"});
            EXPECT_EQ(should_not_exist, flat.end());
        }

        // find(const K&) const
        {
            const auto should_exist = std::as_const(flat).find(converts_to_str_view{"cat"});
            EXPECT_NE(should_exist, std::as_const(flat).end());
            EXPECT_EQ(*should_exist, "cat");

            const auto should_not_exist = std::as_const(flat).find(converts_to_str_view{"tac"});
            EXPECT_EQ(should_not_exist, std::as_const(flat).end());
        }
    }

    // count
    {
        // count(const key_type&)
        {
            EXPECT_EQ(flat.count("f"), 1);
            EXPECT_EQ(flat.count("bar"), 1);
            EXPECT_EQ(flat.count("zog"), 1);
            EXPECT_EQ(flat.count("cat"), 1);
            EXPECT_EQ(flat.count("taaa"), 0);
        }

        // count(const K&)
        {
            EXPECT_EQ(flat.count(converts_to_str_view{"f"}), 1);
            EXPECT_EQ(flat.count(converts_to_str_view{"bar"}), 1);
            EXPECT_EQ(flat.count(converts_to_str_view{"zog"}), 1);
            EXPECT_EQ(flat.count(converts_to_str_view{"cat"}), 1);
            EXPECT_EQ(flat.count(converts_to_str_view{"taaa"}), 0);
        }
    }

    // contains
    {
        // contains(const key_type&)
        {
            EXPECT_TRUE(flat.contains("f"));
            EXPECT_TRUE(flat.contains("bar"));
            EXPECT_TRUE(flat.contains("zog"));
            EXPECT_TRUE(flat.contains("cat"));
            EXPECT_FALSE(flat.contains("goz"));
        }

        // contains(const K&)
        {
            EXPECT_TRUE(flat.contains(converts_to_str_view{"f"}));
            EXPECT_TRUE(flat.contains(converts_to_str_view{"bar"}));
            EXPECT_TRUE(flat.contains(converts_to_str_view{"zog"}));
            EXPECT_TRUE(flat.contains(converts_to_str_view{"cat"}));
            EXPECT_FALSE(flat.contains(converts_to_str_view{"goz"}));
        }
    }

    // lower_bound
    {
        // lower_bound(const key_type&)
        {
            EXPECT_EQ(flat.lower_bound("bar"), flat.begin());
            EXPECT_EQ(flat.lower_bound("cat"), flat.begin() + 1);
            EXPECT_EQ(flat.lower_bound("f"), flat.begin() + 2);
            EXPECT_EQ(flat.lower_bound("zog"), flat.begin() + 3);
        }

        // lower_bound(const key_type&) const
        {
            EXPECT_EQ(std::as_const(flat).lower_bound("bar"), std::as_const(flat).begin());
            EXPECT_EQ(std::as_const(flat).lower_bound("cat"), std::as_const(flat).begin() + 1);
            EXPECT_EQ(std::as_const(flat).lower_bound("f"), std::as_const(flat).begin() + 2);
            EXPECT_EQ(std::as_const(flat).lower_bound("zog"), std::as_const(flat).begin() + 3);
        }

        // lower_bound(const K&)
        {
            EXPECT_EQ(flat.lower_bound(converts_to_str_view{"bar"}), flat.begin());
            EXPECT_EQ(flat.lower_bound(converts_to_str_view{"cat"}), flat.begin() + 1);
            EXPECT_EQ(flat.lower_bound(converts_to_str_view{"f"}), flat.begin() + 2);
            EXPECT_EQ(flat.lower_bound(converts_to_str_view{"zog"}), flat.begin() + 3);
        }

        // lower_bound(const K&) const
        {
            EXPECT_EQ(std::as_const(flat).lower_bound(converts_to_str_view{"bar"}), std::as_const(flat).begin());
            EXPECT_EQ(std::as_const(flat).lower_bound(converts_to_str_view{"cat"}), std::as_const(flat).begin() + 1);
            EXPECT_EQ(std::as_const(flat).lower_bound(converts_to_str_view{"f"}), std::as_const(flat).begin() + 2);
            EXPECT_EQ(std::as_const(flat).lower_bound(converts_to_str_view{"zog"}), std::as_const(flat).begin() + 3);
        }
    }

    // upper_bound
    {
        // upper_bound(const key_type&)
        {
            EXPECT_EQ(flat.upper_bound("bar"), flat.begin() + 1);
            EXPECT_EQ(flat.upper_bound("cat"), flat.begin() + 2);
            EXPECT_EQ(flat.upper_bound("f"), flat.begin() + 3);
            EXPECT_EQ(flat.upper_bound("zog"), flat.end()); // Last
        }

        // upper_bound(const key_type&) const
        {
            EXPECT_EQ(std::as_const(flat).upper_bound("bar"), std::as_const(flat).begin() + 1);
            EXPECT_EQ(std::as_const(flat).upper_bound("cat"), std::as_const(flat).begin() + 2);
            EXPECT_EQ(std::as_const(flat).upper_bound("f"), std::as_const(flat).begin() + 3);
            EXPECT_EQ(std::as_const(flat).upper_bound("zog"), std::as_const(flat).end());
        }

        // upper_bound(const K&)
        {
            EXPECT_EQ(flat.upper_bound(converts_to_str_view{"bar"}), flat.begin() + 1);
            EXPECT_EQ(flat.upper_bound(converts_to_str_view{"cat"}), flat.begin() + 2);
            EXPECT_EQ(flat.upper_bound(converts_to_str_view{"f"}), flat.begin() + 3);
            EXPECT_EQ(flat.upper_bound(converts_to_str_view{"zog"}), flat.end());
        }

        // upper_bound(const K&) const
        {
            EXPECT_EQ(std::as_const(flat).upper_bound(converts_to_str_view{"bar"}), std::as_const(flat).begin() + 1);
            EXPECT_EQ(std::as_const(flat).upper_bound(converts_to_str_view{"cat"}), std::as_const(flat).begin() + 2);
            EXPECT_EQ(std::as_const(flat).upper_bound(converts_to_str_view{"f"}), std::as_const(flat).begin() + 3);
            EXPECT_EQ(std::as_const(flat).upper_bound(converts_to_str_view{"zog"}), std::as_const(flat).end());
        }
    }

    // equal_range
    {
        // equal_range(const key_type&)
        {
            EXPECT_EQ(flat.equal_range("bar"), std::make_pair(flat.begin() + 0, flat.begin() + 1));
            EXPECT_EQ(flat.equal_range("cat"), std::make_pair(flat.begin() + 1, flat.begin() + 2));
            EXPECT_EQ(flat.equal_range("f"), std::make_pair(flat.begin() + 2, flat.begin() + 3));
            EXPECT_EQ(flat.equal_range("zog"), std::make_pair(flat.begin() + 3, flat.end()));
        }

        // equal_range(const key_type&) const
        {
            EXPECT_EQ(std::as_const(flat).equal_range("bar"), std::make_pair(std::as_const(flat).begin() + 0, std::as_const(flat).begin() + 1));
            EXPECT_EQ(std::as_const(flat).equal_range("cat"), std::make_pair(std::as_const(flat).begin() + 1, std::as_const(flat).begin() + 2));
            EXPECT_EQ(std::as_const(flat).equal_range("f"), std::make_pair(std::as_const(flat).begin() + 2, std::as_const(flat).begin() + 3));
            EXPECT_EQ(std::as_const(flat).equal_range("zog"), std::make_pair(std::as_const(flat).begin() + 3, std::as_const(flat).end()));
        }

        // equal_range(const K&)
        {
            EXPECT_EQ(flat.equal_range(converts_to_str_view{"bar"}), std::make_pair(flat.begin() + 0, flat.begin() + 1));
            EXPECT_EQ(flat.equal_range(converts_to_str_view{"cat"}), std::make_pair(flat.begin() + 1, flat.begin() + 2));
            EXPECT_EQ(flat.equal_range(converts_to_str_view{"f"}), std::make_pair(flat.begin() + 2, flat.begin() + 3));
            EXPECT_EQ(flat.equal_range(converts_to_str_view{"zog"}), std::make_pair(flat.begin() + 3, flat.end()));
        }

        // equal_range(const K&) const
        {
            EXPECT_EQ(std::as_const(flat).equal_range(converts_to_str_view{"bar"}),
                      std::make_pair(std::as_const(flat).begin() + 0, std::as_const(flat).begin() + 1));
            EXPECT_EQ(std::as_const(flat).equal_range(converts_to_str_view{"cat"}),
                      std::make_pair(std::as_const(flat).begin() + 1, std::as_const(flat).begin() + 2));
            EXPECT_EQ(std::as_const(flat).equal_range(converts_to_str_view{"f"}),
                      std::make_pair(std::as_const(flat).begin() + 2, std::as_const(flat).begin() + 3));
            EXPECT_EQ(std::as_const(flat).equal_range(converts_to_str_view{"zog"}),
                      std::make_pair(std::as_const(flat).begin() + 3, std::as_const(flat).end()));
        }
    }
}

TEST(flat_set, operators)
{
    using fubuki::flat_set;

    // operator=
    {
        flat_set<int> flat;
        flat = {0, 1, 3, 4, 5, -1};

        compare(flat, {0, 1, 3, 4, 5, -1});
    }

    // operator==
    {
        const std::vector<int> contents_a         = {1, 2, 3, 4, 5};
        const auto             another_contents_a = contents_a; // NOLINT(performance-unnecessary-copy-initialization)
        const std::vector<int> contents_b         = {6, 7, 8, 9, 10};

        // NOLINTBEGIN(performance-unnecessary-copy-initialization)
        const flat_set<int> flat_a{contents_a.begin(), contents_a.end()};
        const flat_set<int> another_flat_a = flat_a;
        const flat_set<int> flat_b{contents_b.begin(), contents_b.end()};
        // NOLINTEND(performance-unnecessary-copy-initialization)

        EXPECT_EQ(flat_a, another_flat_a);
        EXPECT_FALSE(flat_a == flat_b);
    }

    // operator<=>
    {
        const std::vector<int> contents_a = {1, 2, 3, 4, 5};
        const std::vector<int> contents_b = {6, 7, 8, 9, 10};

        const flat_set<int> flat_a{contents_a.begin(), contents_a.end()};
        const flat_set<int> flat_b{contents_b.begin(), contents_b.end()};

        EXPECT_EQ((flat_a <=> flat_b), (contents_a <=> contents_b));
    }
}

    #undef STATIC_EXPECT_TRUE

} // anonymous namespace

#endif // #ifdef __cpp_lib_flat_set
