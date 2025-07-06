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

#include <ranges>

#include <gtest/gtest.h>

#include <core/version_number.hpp>
#include <core/vulkan.hpp>

namespace
{

TEST(version_number, vk)
{
    for(const auto major : std::views::iota(1U, 10U))
    {
        for(const auto minor : std::views::iota(0U, 100U))
        {
            for(const auto patch : std::views::iota(0U, 100U))
            {
                const auto          v    = fubuki::version_number{major, minor, patch};
                const std::uint32_t hash = v;

                EXPECT_EQ(hash, VK_MAKE_API_VERSION(0, major, minor, patch));
            }
        }
    }
}

TEST(version_number, comparison)
{
    constexpr fubuki::version_number v1{1, 2, 3};
    constexpr fubuki::version_number v2{1, 2, 4};
    constexpr fubuki::version_number v3{1, 3, 3};

    // >, >=
    {
        EXPECT_GT(v2, v1);
        EXPECT_GT(v3, v2);
        EXPECT_GT(v3, v1);

        EXPECT_GE(v2, v1);
        EXPECT_GE(v3, v2);
        EXPECT_GE(v3, v1);
    }

    // <, <=
    {
        EXPECT_LT(v1, v2);
        EXPECT_LT(v2, v3);
        EXPECT_LT(v1, v3);

        EXPECT_LE(v1, v2);
        EXPECT_LE(v2, v3);
        EXPECT_LE(v1, v3);
    }

    // ==, !=
    {
        EXPECT_NE(v1, v2);
        EXPECT_NE(v1, v3);

        EXPECT_NE(v2, v1);
        EXPECT_NE(v2, v3);

        EXPECT_NE(v3, v1);
        EXPECT_NE(v3, v2);
    }
}

} // anonymous namespace
