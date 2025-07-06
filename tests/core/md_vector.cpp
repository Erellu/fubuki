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

#include <core/md_vector.hpp>

// Clang isn't able to infer it's safe in this context
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

namespace
{

TEST(md_vector, ctor_access_iterators)
{
    constexpr auto        fill    = 33;
    constexpr std::size_t rows    = 3;
    constexpr std::size_t columns = 2;

    // const
    {
        const fubuki::md_vector<int, 2> v = {fill, rows, columns};

        EXPECT_EQ(v.size(), rows);

        for(const auto& row : v)
        {
            EXPECT_EQ(row.size(), columns);

            for(const auto& value : row)
            {
                EXPECT_EQ(value, fill);
            }
        }

        // NOLINTNEXTLINE(modernize-loop-convert)
        for(std::size_t x = 0; x < v.size(); ++x)
        {
            EXPECT_EQ(v[x].size(), columns);

            for(std::size_t y = 0; y < v[x].size(); ++y)
            {
                EXPECT_EQ(v[x][y], fill);
            }
        }
    }

    // Mutable
    {
        fubuki::md_vector<int, 2> v = {fill, rows, columns};

        EXPECT_EQ(v.size(), rows);

        for(auto& row : v)
        {
            EXPECT_EQ(row.size(), columns);

            for(auto& value : row)
            {
                EXPECT_EQ(value, fill);
            }
        }

        // NOLINTNEXTLINE(modernize-loop-convert)
        for(std::size_t x = 0; x < v.size(); ++x)
        {
            EXPECT_EQ(v[x].size(), columns);

            for(std::size_t y = 0; y < v[x].size(); ++y)
            {
                EXPECT_EQ(v[x][y], fill);
            }
        }
    }
}

TEST(md_vector, view)
{
    constexpr auto        fill    = 756;
    constexpr std::size_t rows    = 4;
    constexpr std::size_t columns = 3;

    // const
    {
        const fubuki::md_vector<int, 2> v = {fill, rows, columns};

        const fubuki::md_vector_view<const int, 2> view{v};

        for(std::size_t x = 0; x < v.size(); ++x)
        {
            for(std::size_t y = 0; y < v[x].size(); ++y)
            {
                EXPECT_EQ(v[x][y], fill);
                EXPECT_EQ(view[x][y], v[x][y]);
            }
        }
    }

    // Mutable
    {
        constexpr auto new_fill = 217;

        fubuki::md_vector<int, 2> v = {fill, rows, columns};

        fubuki::md_vector_view<int, 2> view{v};

        for(std::size_t x = 0; x < v.size(); ++x)
        {
            for(std::size_t y = 0; y < v[x].size(); ++y)
            {
                EXPECT_EQ(v[x][y], fill);
                EXPECT_EQ(view[x][y], v[x][y]);
                view[x][y] = new_fill;
                EXPECT_EQ(v[x][y], new_fill);
                EXPECT_EQ(view[x][y], v[x][y]);
            }
        }
    }
}

TEST(md_vector, resize)
{
    constexpr auto init_v = 2;
    constexpr auto new_v  = 3;

    constexpr auto init_x = 3;
    constexpr auto init_y = 4;

    constexpr auto new_x = 4;
    constexpr auto new_y = 3;

    fubuki::md_vector<int, 2> v{init_v, init_x, init_y};

    v.resize(new_v, new_x, new_y);

    EXPECT_EQ(v.size(), new_x);

    for(const auto& row : v)
    {
        EXPECT_EQ(row.size(), new_y);

        for(const auto& element : row)
        {
            EXPECT_TRUE((element == init_v) or (element == new_v));
        }
    }
}

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

} // anonymous namespace
