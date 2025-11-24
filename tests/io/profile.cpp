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

#include <thread>
#include <type_traits>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <io/profile.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using fubuki::io::profile;

TEST(io_profile, profile)
{
    using std::chrono_literals::operator""us;

    {
        const auto r      = profile([]() noexcept {});
        using result_type = std::remove_cvref_t<decltype(r)>::value_type;

        STATIC_EXPECT_TRUE((std::is_same_v<result_type::value_type, std::monostate>) );

        ASSERT_TRUE(r.has_value()) << "Profiling failed: " << r.error();
        EXPECT_LE(r->duration, 1us);
    }

    {
        const auto r      = profile([]() noexcept -> std::uint64_t { return 2; });
        using result_type = std::remove_cvref_t<decltype(r)>::value_type;

        STATIC_EXPECT_TRUE((std::is_same_v<result_type::value_type, std::uint64_t>) );

        ASSERT_TRUE(r.has_value()) << "Profiling failed: " << r.error();
        EXPECT_LE(r->duration, 1us);
    }

    {
        using std::chrono_literals::operator""ms;
        constexpr auto in_range = []<typename T>(T lo, T hi) { return testing::AllOf(testing::Ge((lo)), testing::Le((hi))); };

        constexpr auto delay  = 500ms;
        constexpr auto margin = 10ms; // sleep_for is precise to approx. 10ms on Windows

        const auto r = profile([&]() noexcept { std::this_thread::sleep_for(delay); });

        ASSERT_TRUE(r.has_value()) << "Profiling failed: " << r.error();

        EXPECT_THAT(r->duration, in_range(delay - margin, delay + margin));
    }
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
