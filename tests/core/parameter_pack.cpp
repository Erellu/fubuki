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

#include <core/traits/parameter_pack.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

#define STATIC_EXPECT_FALSE(x) \
    static_assert(not(x));     \
    EXPECT_FALSE((x))

namespace
{

TEST(parameter_pack_traits, same_types)
{
    using fubuki::traits::parameter_pack::same_types_v;

    STATIC_EXPECT_TRUE((same_types_v<int, int>) );
    STATIC_EXPECT_TRUE((same_types_v<float, float>) );
    STATIC_EXPECT_TRUE((same_types_v<int&&, int&&>) );
    STATIC_EXPECT_TRUE((same_types_v<const int&, const int&>) );
    STATIC_EXPECT_TRUE((same_types_v<typename std::vector<int>::value_type, int>) );
    STATIC_EXPECT_TRUE((same_types_v<std::add_const_t<const int>, const int>) );

    STATIC_EXPECT_FALSE((same_types_v<int, int&>) );
    STATIC_EXPECT_FALSE((same_types_v<int&&, int&>) );
    STATIC_EXPECT_FALSE((same_types_v<const int, int>) );
    STATIC_EXPECT_FALSE((same_types_v<const int&, int&>) );
    STATIC_EXPECT_FALSE((same_types_v<std::add_const_t<int>, int>) );
}

TEST(parameter_pack_traits, count)
{
    using fubuki::traits::parameter_pack::count;
    using fubuki::traits::parameter_pack::count_v;

    STATIC_EXPECT_TRUE((count<int, float>() == 0u));
    STATIC_EXPECT_TRUE((count_v<int, float> == 0u));

    STATIC_EXPECT_TRUE((count<int, int>() == 1u));
    STATIC_EXPECT_TRUE((count_v<int, int> == 1u));
    STATIC_EXPECT_TRUE((count<int, float, int>() == 1u));
    STATIC_EXPECT_TRUE((count_v<int, float, int> == 1u));

    STATIC_EXPECT_TRUE((count<int, int, int>() == 2u));
    STATIC_EXPECT_TRUE((count_v<int, int, int> == 2u));
    STATIC_EXPECT_TRUE((count<int, double, float, int, char, int>() == 2u));
    STATIC_EXPECT_TRUE((count_v<int, double, float, int, char, int> == 2u));

    STATIC_EXPECT_TRUE((count<int, int, int, int>() == 3u));
    STATIC_EXPECT_TRUE((count_v<int, int, int, int> == 3u));
    STATIC_EXPECT_TRUE((count<int, char, char, char, int, char, int, double, float, int>() == 3u));
    STATIC_EXPECT_TRUE((count_v<int, char, char, char, int, char, int, double, float, int> == 3u));
}

TEST(parameter_pack_traits, contains)
{
    using fubuki::traits::parameter_pack::contains;
    using fubuki::traits::parameter_pack::contains_v;

    STATIC_EXPECT_TRUE((contains<int, int>()));
    STATIC_EXPECT_TRUE((contains<int, int, float>()));
    STATIC_EXPECT_TRUE((contains<int, float, int>()));
    STATIC_EXPECT_TRUE((contains<int, float, float, int, float, float>()));

    STATIC_EXPECT_TRUE((contains_v<int, int>) );
    STATIC_EXPECT_TRUE((contains_v<int, int, float>) );
    STATIC_EXPECT_TRUE((contains_v<int, float, int>) );
    STATIC_EXPECT_TRUE((contains_v<int, float, float, int, float, float>) );

    STATIC_EXPECT_FALSE((contains<int, float>()));
    STATIC_EXPECT_FALSE((contains<int, double, float>()));
    STATIC_EXPECT_FALSE((contains<int, float, double, char>()));
    STATIC_EXPECT_FALSE((contains<int, float, float, float, float>()));

    STATIC_EXPECT_FALSE((contains_v<int, float>) );
    STATIC_EXPECT_FALSE((contains_v<int, double, float>) );
    STATIC_EXPECT_FALSE((contains_v<int, float, double>) );
    STATIC_EXPECT_FALSE((contains_v<int, float, float, float, float, float>) );
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
#undef STATIC_EXPECT_FALSE
