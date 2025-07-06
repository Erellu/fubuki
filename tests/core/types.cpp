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

#include <sstream>

#include <gtest/gtest.h>

#include <core/types.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))
#define STATIC_EXPECT_FALSE(x) \
    static_assert(not(x));     \
    EXPECT_FALSE((x))

namespace
{

enum class which
{
    dim,
    pos
};

template<typename T, which type>
void do_test()
{
    using type_3d = std::conditional_t<type == which::dim, fubuki::dim3d<T>, fubuki::pos3d<T>>;
    using type_2d = std::conditional_t<type == which::dim, fubuki::dim2d<T>, fubuki::pos2d<T>>;
    using type_1d = std::conditional_t<type == which::dim, fubuki::dim1d<T>, fubuki::pos1d<T>>;

    constexpr auto x = static_cast<T>(142);
    constexpr auto y = static_cast<T>(23);
    constexpr auto z = static_cast<T>(14);

    constexpr auto other_x = static_cast<T>(14);
    constexpr auto other_y = static_cast<T>(93);
    constexpr auto other_z = static_cast<T>(12);

    constexpr type_3d data_3d = {x, y, z};
    constexpr type_2d data_2d = {x, y};
    constexpr type_1d data_1d = {x};

    constexpr type_3d other_data_3d = {other_x, other_y, other_z};
    constexpr type_2d other_data_2d = {other_x, other_y};
    constexpr type_1d other_data_1d = {other_x};

    constexpr auto data_3d_copy = data_3d;
    constexpr auto data_2d_copy = data_2d;
    constexpr auto data_1d_copy = data_1d;

    // 3D
    {
        constexpr type_2d as_2d_from_3d = data_3d;
        constexpr type_1d as_1d_from_3d = data_3d;
        constexpr T       as_t_from_3d  = as_1d_from_3d;

        STATIC_EXPECT_TRUE((as_2d_from_3d == type_2d{x, y}));
        STATIC_EXPECT_TRUE((as_1d_from_3d == type_1d{x}));
        STATIC_EXPECT_TRUE((as_2d_from_3d == data_2d));
        STATIC_EXPECT_TRUE((as_1d_from_3d == data_1d));
        STATIC_EXPECT_TRUE((as_t_from_3d == x));

        STATIC_EXPECT_TRUE(data_3d == data_3d);      // Self
        STATIC_EXPECT_TRUE(data_3d == data_2d);      // Conversion operator
        STATIC_EXPECT_TRUE(data_3d == data_1d);      // Conversion operator
        STATIC_EXPECT_TRUE(data_3d_copy == data_3d); // Copy
        STATIC_EXPECT_FALSE(data_3d_copy != data_3d);

        STATIC_EXPECT_FALSE(other_data_3d == data_3d);
        STATIC_EXPECT_TRUE(other_data_3d != data_3d);
    }

    // 2D
    {
        constexpr type_1d as_1d_from_2d = data_2d;
        constexpr T       as_t_from_2d  = as_1d_from_2d;

        STATIC_EXPECT_TRUE((as_1d_from_2d == type_1d{x}));
        STATIC_EXPECT_TRUE((as_1d_from_2d == data_1d));
        STATIC_EXPECT_TRUE((as_t_from_2d == x));

        STATIC_EXPECT_TRUE(data_2d == data_2d);      // Self
        STATIC_EXPECT_TRUE(data_2d == data_2d);      // Conversion operator
        STATIC_EXPECT_TRUE(data_2d == data_1d);      // Conversion operator
        STATIC_EXPECT_TRUE(data_2d_copy == data_2d); // Copy
        STATIC_EXPECT_FALSE(data_2d_copy != data_2d);

        STATIC_EXPECT_FALSE(other_data_2d == data_2d);
        STATIC_EXPECT_TRUE(other_data_2d != data_2d);
    }

    // 1D
    {
        constexpr T as_t_from_1d = data_1d;

        STATIC_EXPECT_TRUE((as_t_from_1d == x));

        STATIC_EXPECT_TRUE(data_1d == data_1d);      // Self
        STATIC_EXPECT_TRUE(data_1d == data_1d);      // Conversion operator
        STATIC_EXPECT_TRUE(data_1d == data_1d);      // Conversion operator
        STATIC_EXPECT_TRUE(data_1d_copy == data_1d); // Copy
        STATIC_EXPECT_FALSE(data_1d_copy != data_1d);

        STATIC_EXPECT_FALSE(other_data_1d == data_1d);
        STATIC_EXPECT_TRUE(other_data_1d != data_1d);
    }

    // operator<<
    {
        const auto data_3d_str = (std::stringstream{} << data_3d).str();
        const auto data_2d_str = (std::stringstream{} << data_2d).str();
        const auto data_1d_str = (std::stringstream{} << data_1d).str();

        if constexpr(type == which::dim)
        {
            const auto expected_data_3d_str = (std::stringstream{} << "{w: " << x << ", h: " << y << ", d: " << z << "}").str();
            const auto expected_data_2d_str = (std::stringstream{} << "{w: " << x << ", h: " << y << "}").str();
            const auto expected_data_1d_str = (std::stringstream{} << "{w: " << x << "}").str();

            EXPECT_EQ(data_3d_str, expected_data_3d_str);
            EXPECT_EQ(data_2d_str, expected_data_2d_str);
            EXPECT_EQ(data_1d_str, expected_data_1d_str);
        }
        else // pos
        {
            const auto expected_data_3d_str = (std::stringstream{} << "{x: " << x << ", y: " << y << ", z: " << z << "}").str();
            const auto expected_data_2d_str = (std::stringstream{} << "{x: " << x << ", y: " << y << "}").str();
            const auto expected_data_1d_str = (std::stringstream{} << "{x: " << x << "}").str();

            EXPECT_EQ(data_3d_str, expected_data_3d_str);
            EXPECT_EQ(data_2d_str, expected_data_2d_str);
            EXPECT_EQ(data_1d_str, expected_data_1d_str);
        }
    }
}

//------------------------------------------------------------------------------

TEST(types, dim)
{
    using enum which;

    do_test<std::uint8_t, dim>();
    do_test<std::uint16_t, dim>();
    do_test<std::uint32_t, dim>();
    do_test<std::uint64_t, dim>();

    do_test<std::int8_t, dim>();
    do_test<std::int16_t, dim>();
    do_test<std::int32_t, dim>();
    do_test<std::int64_t, dim>();
}

TEST(types, pos)
{
    using enum which;

    do_test<std::uint8_t, pos>();
    do_test<std::uint16_t, pos>();
    do_test<std::uint32_t, pos>();
    do_test<std::uint64_t, pos>();

    do_test<std::int8_t, pos>();
    do_test<std::int16_t, pos>();
    do_test<std::int32_t, pos>();
    do_test<std::int64_t, pos>();
}

#undef STATIC_EXPECT_TRUE
#undef STATIC_EXPECT_FALSE

} // anonymous namespace
