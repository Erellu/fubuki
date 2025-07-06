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

#include <core/string_literal.hpp>

namespace
{
#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

using fubuki::string_literal;
using fubuki::operator""_literal;

TEST(string_literal, empty)
{
    constexpr string_literal s1 = "";
    constexpr string_literal s2 = {};
    constexpr auto           s3 = ""_literal;

    STATIC_EXPECT_TRUE(s1.size() == 0u); // NOLINT(readability-container-size-empty)
    STATIC_EXPECT_TRUE(s2.size() == 0u); // NOLINT(readability-container-size-empty)
    STATIC_EXPECT_TRUE(s3.size() == 0u); // NOLINT(readability-container-size-empty)
    STATIC_EXPECT_TRUE(s1.empty());
    STATIC_EXPECT_TRUE(s2.empty());
    STATIC_EXPECT_TRUE(s3.empty());

    STATIC_EXPECT_TRUE(s1 == s1);
    STATIC_EXPECT_TRUE(s1 == s2);
    STATIC_EXPECT_TRUE(s1 == s3);

    STATIC_EXPECT_TRUE(s2 == s1);
    STATIC_EXPECT_TRUE(s2 == s2);
    STATIC_EXPECT_TRUE(s2 == s3);

    STATIC_EXPECT_TRUE(s3 == s1);
    STATIC_EXPECT_TRUE(s3 == s2);
    STATIC_EXPECT_TRUE(s3 == s3);

    STATIC_EXPECT_TRUE(requires { s1[0]; });
    STATIC_EXPECT_TRUE(requires { s2[0]; });
    STATIC_EXPECT_TRUE(requires { s3[0]; });

    STATIC_EXPECT_TRUE(s1[0] == '\0');
    STATIC_EXPECT_TRUE(s2[0] == '\0');
    STATIC_EXPECT_TRUE(s3[0] == '\0');

    STATIC_EXPECT_TRUE(requires { s1.c_str()[0]; });
    STATIC_EXPECT_TRUE(requires { s2.c_str()[0]; });
    STATIC_EXPECT_TRUE(requires { s3.c_str()[0]; });

    STATIC_EXPECT_TRUE(s1.c_str()[0] == '\0');
    STATIC_EXPECT_TRUE(s2.c_str()[0] == '\0');
    STATIC_EXPECT_TRUE(s3.c_str()[0] == '\0');

    STATIC_EXPECT_TRUE(requires { s1.data()[0]; });
    STATIC_EXPECT_TRUE(requires { s2.data()[0]; });
    STATIC_EXPECT_TRUE(requires { s3.data()[0]; });

    STATIC_EXPECT_TRUE(s1.data()[0] == '\0');
    STATIC_EXPECT_TRUE(s2.data()[0] == '\0');
    STATIC_EXPECT_TRUE(s3.data()[0] == '\0');
}

TEST(string_literal, non_empty)
{
// Clang isn't able to infer it's safe in this context
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

    constexpr string_literal s1   = "abc";
    constexpr auto           s1_1 = "abc"_literal;
    constexpr string_literal s2   = "def";
    constexpr auto           s2_1 = "def"_literal;
    constexpr string_literal s3   = "ghi";
    constexpr auto           s3_1 = "ghi"_literal;

    STATIC_EXPECT_TRUE(s1.size() == 3u);
    STATIC_EXPECT_TRUE(s2.size() == 3u);
    STATIC_EXPECT_TRUE(s3.size() == 3u);
    STATIC_EXPECT_TRUE(not s1.empty());
    STATIC_EXPECT_TRUE(not s2.empty());
    STATIC_EXPECT_TRUE(not s3.empty());

    STATIC_EXPECT_TRUE(s1 == s1);
    STATIC_EXPECT_TRUE(s1 == s1_1);
    STATIC_EXPECT_TRUE(s1 != s2);
    STATIC_EXPECT_TRUE(s1 != s2_1);
    STATIC_EXPECT_TRUE(s1 != s3);
    STATIC_EXPECT_TRUE(s1 != s3_1);

    STATIC_EXPECT_TRUE(s2 != s1);
    STATIC_EXPECT_TRUE(s2 != s1_1);
    STATIC_EXPECT_TRUE(s2 == s2);
    STATIC_EXPECT_TRUE(s2 == s2_1);
    STATIC_EXPECT_TRUE(s2 != s3);
    STATIC_EXPECT_TRUE(s2 != s3_1);

    STATIC_EXPECT_TRUE(s3 != s1);
    STATIC_EXPECT_TRUE(s3 != s1_1);
    STATIC_EXPECT_TRUE(s3 != s2);
    STATIC_EXPECT_TRUE(s3 != s2_1);
    STATIC_EXPECT_TRUE(s3 == s3);
    STATIC_EXPECT_TRUE(s3 == s3_1);

    STATIC_EXPECT_TRUE(requires { s1[0]; });
    STATIC_EXPECT_TRUE(requires { s2[0]; });
    STATIC_EXPECT_TRUE(requires { s3[0]; });

    STATIC_EXPECT_TRUE(s1[0] == 'a');
    STATIC_EXPECT_TRUE(s1[1] == 'b');
    STATIC_EXPECT_TRUE(s1[2] == 'c');
    STATIC_EXPECT_TRUE(s1[3] == '\0');

    STATIC_EXPECT_TRUE(s2[0] == 'd');
    STATIC_EXPECT_TRUE(s2[1] == 'e');
    STATIC_EXPECT_TRUE(s2[2] == 'f');
    STATIC_EXPECT_TRUE(s2[3] == '\0');

    STATIC_EXPECT_TRUE(s3[0] == 'g');
    STATIC_EXPECT_TRUE(s3[1] == 'h');
    STATIC_EXPECT_TRUE(s3[2] == 'i');
    STATIC_EXPECT_TRUE(s3[3] == '\0');

    STATIC_EXPECT_TRUE(requires { s1.c_str()[0]; });
    STATIC_EXPECT_TRUE(requires { s2.c_str()[0]; });
    STATIC_EXPECT_TRUE(requires { s3.c_str()[0]; });

    STATIC_EXPECT_TRUE(s1.c_str()[0] == 'a');
    STATIC_EXPECT_TRUE(s1.c_str()[1] == 'b');
    STATIC_EXPECT_TRUE(s1.c_str()[2] == 'c');
    STATIC_EXPECT_TRUE(s1.c_str()[3] == '\0');

    STATIC_EXPECT_TRUE(s2.c_str()[0] == 'd');
    STATIC_EXPECT_TRUE(s2.c_str()[1] == 'e');
    STATIC_EXPECT_TRUE(s2.c_str()[2] == 'f');
    STATIC_EXPECT_TRUE(s2.c_str()[3] == '\0');

    STATIC_EXPECT_TRUE(s3.c_str()[0] == 'g');
    STATIC_EXPECT_TRUE(s3.c_str()[1] == 'h');
    STATIC_EXPECT_TRUE(s3.c_str()[2] == 'i');
    STATIC_EXPECT_TRUE(s3.c_str()[3] == '\0');

    STATIC_EXPECT_TRUE(requires { s1.data()[0]; });
    STATIC_EXPECT_TRUE(requires { s2.data()[0]; });
    STATIC_EXPECT_TRUE(requires { s3.data()[0]; });

    STATIC_EXPECT_TRUE(s1.data()[0] == 'a');
    STATIC_EXPECT_TRUE(s1.data()[1] == 'b');
    STATIC_EXPECT_TRUE(s1.data()[2] == 'c');
    STATIC_EXPECT_TRUE(s1.data()[3] == '\0');

    STATIC_EXPECT_TRUE(s2.data()[0] == 'd');
    STATIC_EXPECT_TRUE(s2.data()[1] == 'e');
    STATIC_EXPECT_TRUE(s2.data()[2] == 'f');
    STATIC_EXPECT_TRUE(s2.data()[3] == '\0');

    STATIC_EXPECT_TRUE(s3.data()[0] == 'g');
    STATIC_EXPECT_TRUE(s3.data()[1] == 'h');
    STATIC_EXPECT_TRUE(s3.data()[2] == 'i');
    STATIC_EXPECT_TRUE(s3.data()[3] == '\0');

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
}

#undef STATIC_EXPECT_TRUE
} // anonymous namespace
