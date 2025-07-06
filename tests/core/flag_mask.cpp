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

#include <cstdint>

#include <gtest/gtest.h>

#include <core/flag_mask.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

#define STATIC_EXPECT_FALSE(x) \
    static_assert(not(x));     \
    EXPECT_FALSE((x))

namespace
{

enum class bitmask : std::uint8_t
{
    a = 0b0001,
    b = 0b0010,
    c = 0b0100,
};

TEST(flag_mask, types)
{
    using fubuki::flag_mask;

    STATIC_EXPECT_TRUE((std::is_same_v<typename flag_mask<bitmask>::bit, bitmask>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flag_mask<bitmask>::value_type, std::uint8_t>) );
    STATIC_EXPECT_TRUE((std::is_same_v<typename flag_mask<bitmask>::value_type, std::underlying_type_t<bitmask>>) );
}

TEST(flag_mask, ctor_assign)
{
    using flag_mask = fubuki::flag_mask<bitmask>;

    {
        constexpr flag_mask m{};
        STATIC_EXPECT_TRUE(m.value() == 0u);

        constexpr flag_mask m1{};
        STATIC_EXPECT_TRUE(m.value() == m1.value());
    }

    {
        constexpr flag_mask m{bitmask::a};
        STATIC_EXPECT_TRUE(m.value() == std::to_underlying(bitmask::a));

        constexpr flag_mask m1 = m;
        STATIC_EXPECT_TRUE(m.value() == m1.value());

        flag_mask m2 = {};
        m2           = m1;
        EXPECT_EQ(m1.value(), m2.value());
    }

    {
        flag_mask m{bitmask::a};
        EXPECT_EQ(m.value(), std::to_underlying(bitmask::a));

        auto m1 = std::move(m); // NOLINT(performance-move-const-arg): this is the purpose of the test
        EXPECT_EQ(m1.value(), std::to_underlying(bitmask::a));

        flag_mask m2 = {};
        m2           = std::move(m1); // NOLINT(performance-move-const-arg): this is the purpose of the test
        EXPECT_EQ(m2.value(), std::to_underlying(bitmask::a));
    }
}

TEST(flag_mask, or)
{
    using flag_mask  = fubuki::flag_mask<bitmask>;
    using value_type = typename flag_mask::value_type;

    constexpr flag_mask m = flag_mask{} | bitmask::a;
    STATIC_EXPECT_TRUE(m.value() == std::to_underlying(bitmask::a));

    constexpr auto m1 = m | bitmask::b;
    STATIC_EXPECT_TRUE(m1.value() == static_cast<value_type>(std::to_underlying(bitmask::a) | std::to_underlying(bitmask::b)));

    constexpr auto m1_bis = m1 | bitmask::b;
    STATIC_EXPECT_TRUE(m1.value() == m1_bis.value());
}

TEST(flag_mask, bit_or)
{
    using flag_mask  = fubuki::flag_mask<bitmask>;
    using value_type = typename flag_mask::value_type;

    flag_mask m = flag_mask{} |= bitmask::a;
    EXPECT_EQ(m.value(), std::to_underlying(bitmask::a));

    m |= bitmask::b;
    EXPECT_EQ(m.value(), static_cast<value_type>(std::to_underlying(bitmask::a) | std::to_underlying(bitmask::b)));

    m |= bitmask::b;
    EXPECT_EQ(m.value(), static_cast<value_type>(std::to_underlying(bitmask::a) | std::to_underlying(bitmask::b)));
}

TEST(flag_mask, and)
{
    using flag_mask = fubuki::flag_mask<bitmask>;

    constexpr flag_mask m = flag_mask{bitmask::a} | bitmask::a;
    STATIC_EXPECT_TRUE(m & bitmask::a);
    STATIC_EXPECT_FALSE(m & bitmask::b);
    STATIC_EXPECT_FALSE(m & bitmask::c);

    constexpr auto m1 = m | bitmask::b;
    STATIC_EXPECT_TRUE(m1 & bitmask::a);
    STATIC_EXPECT_TRUE(m1 & bitmask::b);
    STATIC_EXPECT_FALSE(m & bitmask::c);
}

TEST(flag_mask, bit_and)
{
    using flag_mask = fubuki::flag_mask<bitmask>;

    flag_mask m = flag_mask{bitmask::a} | bitmask::a;
    m &= bitmask::a;
    EXPECT_TRUE(m & bitmask::a);
    EXPECT_FALSE(m & bitmask::b);
    EXPECT_FALSE(m & bitmask::c);

    m &= bitmask::b;
    EXPECT_FALSE(m & bitmask::a);
    EXPECT_FALSE(m & bitmask::b); // &= does not add, must not be set
    EXPECT_FALSE(m & bitmask::c);
}

TEST(flag_mask, compare)
{
    using flag_mask = fubuki::flag_mask<bitmask>;

    constexpr flag_mask m = flag_mask{bitmask::a} | bitmask::a;
    STATIC_EXPECT_TRUE(m == bitmask::a);
    STATIC_EXPECT_TRUE(m != bitmask::b);
    STATIC_EXPECT_TRUE(m != bitmask::c);

    STATIC_EXPECT_FALSE(m != bitmask::a);
    STATIC_EXPECT_FALSE(m == bitmask::b);
    STATIC_EXPECT_FALSE(m == bitmask::c);
}

} // namespace

#undef STATIC_EXPECT_TRUE
#undef STATIC_EXPECT_FALSE
