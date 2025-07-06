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

#include <core/assertion.hpp>

namespace
{

TEST(assertion, triggers)
{
    // NOLINTBEGIN(cppcoreguidelines-pro-type-vararg, misc-const-correctness, modernize-use-std-print)
    EXPECT_DEATH({ fubuki::assertion(false, fubuki::detail::dummy_stream{}); }, "");
    EXPECT_DEATH({ fubuki::assertion(false, std::ostringstream{}); }, "");
    EXPECT_DEATH({ fubuki::crash(); }, "");
#if defined(FUBUKI_DEBUG_BUILD)
    EXPECT_DEATH({ fubuki_assert(false, ""); }, "");
    EXPECT_DEATH({ fubuki_assert_if(true, false, ""); }, "");
#else
    EXPECT_NO_FATAL_FAILURE({ fubuki_assert(false, ""); });
    EXPECT_NO_FATAL_FAILURE({ fubuki_assert_if(true, false, ""); });
#endif
    // NOLINTEND(cppcoreguidelines-pro-type-vararg, misc-const-correctness, modernize-use-std-print)
}

TEST(assertion, does_not_trigger)
{
    // NOLINTBEGIN(cppcoreguidelines-pro-type-vararg, misc-const-correctness, modernize-use-std-print)
    EXPECT_NO_FATAL_FAILURE({ fubuki::assertion(true, fubuki::detail::dummy_stream{}); });
    EXPECT_NO_FATAL_FAILURE({ fubuki::assertion(true, std::ostringstream{}); });
#if defined(FUBUKI_DEBUG_BUILD)
    EXPECT_NO_FATAL_FAILURE({ fubuki_assert(true, ""); });
    EXPECT_NO_FATAL_FAILURE({ fubuki_assert_if(true, true, ""); });
    EXPECT_NO_FATAL_FAILURE({ fubuki_assert_if(false, false, ""); });
    EXPECT_NO_FATAL_FAILURE({ fubuki_assert_if(false, true, ""); });
#endif
    // NOLINTEND(cppcoreguidelines-pro-type-vararg, misc-const-correctness, modernize-use-std-print)
}

} // anonymous namespace
