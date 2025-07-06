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

#include <gtest/gtest.h>

#include <core/traits/tuple.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

#define STATIC_EXPECT_FALSE(x) \
    static_assert(not(x));     \
    EXPECT_FALSE((x))

namespace
{

TEST(tuple_traits, tuple_concept)
{
    using fubuki::traits::tuple::type;
    using fubuki::traits::tuple::detail::is_std_tuple;

    STATIC_EXPECT_TRUE((is_std_tuple<std::tuple<int>>::value));
    STATIC_EXPECT_TRUE((is_std_tuple<std::tuple<int, float>>::value));
    STATIC_EXPECT_TRUE((type<std::tuple<int>>) );
    STATIC_EXPECT_TRUE((type<std::tuple<int, float>>) );
    STATIC_EXPECT_TRUE((type<const std::tuple<int, float>>) );
    STATIC_EXPECT_TRUE((type<const std::tuple<int, float>&>) );
    STATIC_EXPECT_TRUE((type<std::tuple<int, float>&>) );
    STATIC_EXPECT_TRUE((type<std::tuple<int, float>&&>) );

    STATIC_EXPECT_FALSE(type<int>);
    STATIC_EXPECT_FALSE(type<std::string>);
    STATIC_EXPECT_FALSE(type<const float>);
    STATIC_EXPECT_FALSE(type<double&>);
    STATIC_EXPECT_FALSE(type<const char&>);
    STATIC_EXPECT_FALSE(type<unsigned&&>);

    STATIC_EXPECT_FALSE((is_std_tuple<const std::tuple<int, float>>::value));
    STATIC_EXPECT_FALSE((is_std_tuple<const std::tuple<int, float>&>::value));
    STATIC_EXPECT_FALSE((is_std_tuple<std::tuple<int, float>&>::value));
    STATIC_EXPECT_FALSE((is_std_tuple<std::tuple<int, float>&&>::value));
    STATIC_EXPECT_FALSE(is_std_tuple<int>::value);
    STATIC_EXPECT_FALSE(is_std_tuple<std::string>::value);
    STATIC_EXPECT_FALSE(is_std_tuple<const float>::value);
    STATIC_EXPECT_FALSE(is_std_tuple<double&>::value);
    STATIC_EXPECT_FALSE(is_std_tuple<const char&>::value);
    STATIC_EXPECT_FALSE(is_std_tuple<unsigned&&>::value);
}

TEST(tuple_traits, count)
{
    using fubuki::traits::tuple::count;

    using t0 = std::tuple<>;
    using t1 = std::tuple<int>;
    using t2 = std::tuple<int, int>;
    using t3 = std::tuple<int, int, int>;
    using t4 = std::tuple<int, int, int, int>;
    using t5 = std::tuple<float>;
    using t6 = std::tuple<float, int>;
    using t7 = std::tuple<double, float, int, char, int>;
    using t8 = std::tuple<char, char, char, int, char, int, double, float, int>;

    STATIC_EXPECT_TRUE((count<int>(t0{}) == 0u));
    STATIC_EXPECT_TRUE((count<int>(t1{}) == 1u));
    STATIC_EXPECT_TRUE((count<int>(t2{}) == 2u));
    STATIC_EXPECT_TRUE((count<int>(t3{}) == 3u));
    STATIC_EXPECT_TRUE((count<int>(t4{}) == 4u));
    STATIC_EXPECT_TRUE((count<int>(t5{}) == 0u));
    STATIC_EXPECT_TRUE((count<int>(t6{}) == 1u));
    STATIC_EXPECT_TRUE((count<int>(t7{}) == 2u));
    STATIC_EXPECT_TRUE((count<int>(t8{}) == 3u));
}

TEST(tuple_traits, contains)
{
    using fubuki::traits::tuple::contains;

    using t1 = std::tuple<int>;
    using t2 = std::tuple<int, float>;
    using t3 = std::tuple<float, int>;
    using t4 = std::tuple<float, float, int, float, float>;

    using t5 = std::tuple<>;
    using t6 = std::tuple<float>;
    using t7 = std::tuple<double, float>;
    using t8 = std::tuple<float, double, char>;
    using t9 = std::tuple<float, float, float, float>;

    STATIC_EXPECT_TRUE((contains<int>(t1{})));
    STATIC_EXPECT_TRUE((contains<int>(t2{})));
    STATIC_EXPECT_TRUE((contains<int>(t3{})));
    STATIC_EXPECT_TRUE((contains<int>(t4{})));

    STATIC_EXPECT_FALSE((contains<int>(t5{})));
    STATIC_EXPECT_FALSE((contains<int>(t6{})));
    STATIC_EXPECT_FALSE((contains<int>(t7{})));
    STATIC_EXPECT_FALSE((contains<int>(t8{})));
    STATIC_EXPECT_FALSE((contains<int>(t9{})));
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
#undef STATIC_EXPECT_FALSE
