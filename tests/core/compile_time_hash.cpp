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

#include <core/compile_time_hash.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

TEST(compile_time_hash, hash)
{
    using fubuki::operator""_literal;

    constexpr auto str1 = "a i u e o"_literal;
    constexpr auto str2 = "a i u e   o       aazaze   "_literal;
    constexpr auto str3 = "é71 à あい　う"_literal;

    constexpr auto hash1 = fubuki::compile_time_hash(str1);
    constexpr auto hash2 = fubuki::compile_time_hash(str2);
    constexpr auto hash3 = fubuki::compile_time_hash(str3);

    STATIC_EXPECT_TRUE((hash1 == 0xda707e3e));
    STATIC_EXPECT_TRUE((hash2 == 0x7346893e));
    STATIC_EXPECT_TRUE((hash3 == 0x50457f2));
}

#undef STATIC_EXPECT_TRUE

} // anonymous namespace
