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

#include <functional>

#include <gtest/gtest.h>

#include <core/opaque_ptr.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using fubuki::opaque_unique_ptr;

TEST(opaque_ptr, types)
{
    using namespace fubuki::detail::opaque_ptr;

    STATIC_EXPECT_TRUE((std::is_same_v<erased_type<int>, void>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_type<const int>, const void>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_type<int*>, void>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_type<const int*>, void>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_type<int* const>, const void>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_type<const int* const>, const void>) );

    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<int>, void (*)(void*)>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<const int>, void (*)(const void*)>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<int*>, void (*)(void*)>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<const int*>, void (*)(void*)>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<int* const>, void (*)(const void*)>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<const int* const>, void (*)(const void*)>) );

    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<int>, decltype(make_erased_delete<int>())>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<const int>, decltype(make_erased_delete<const int>())>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<int*>, decltype(make_erased_delete<int*>())>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<const int*>, decltype(make_erased_delete<const int*>())>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<int* const>, decltype(make_erased_delete<int* const>())>) );
    STATIC_EXPECT_TRUE((std::is_same_v<erased_deleter<const int* const>, decltype(make_erased_delete<const int* const>())>) );
}

TEST(opaque_ptr, address)
{
    {
        auto unique_ptr = std::make_unique<int>();

        void* address = unique_ptr.get();

        auto ptr = fubuki::make_opaque(std::move(unique_ptr));
        STATIC_EXPECT_TRUE((std::is_same_v<decltype(ptr), opaque_unique_ptr<void>>) );

        EXPECT_EQ(address, ptr.get());
    }

    {
        auto unique_ptr = std::make_unique<const int>();

        const void* address = unique_ptr.get();

        auto ptr = fubuki::make_opaque(std::move(unique_ptr));
        STATIC_EXPECT_TRUE((std::is_same_v<decltype(ptr), opaque_unique_ptr<const void>>) );

        EXPECT_EQ(address, ptr.get());
    }
}

TEST(opaque_ptr, deletion)
{
    struct meow
    {
        std::reference_wrapper<int> i;

        ~meow() noexcept { ++i.get(); }
    };

    {
        int i = 1;

        {
            auto unique_ptr = std::make_unique<meow>(i);

            void* address = unique_ptr.get();

            auto ptr = fubuki::make_opaque(std::move(unique_ptr));
            STATIC_EXPECT_TRUE((std::is_same_v<decltype(ptr), opaque_unique_ptr<void>>) );

            EXPECT_EQ(address, ptr.get());
        }

        EXPECT_EQ(i, 2); // Destructor increments: should be properly called **once**
    }

    {
        int i = 1;

        {
            auto unique_ptr = std::make_unique<const meow>(i);

            const void* address = unique_ptr.get();

            auto ptr = fubuki::make_opaque(std::move(unique_ptr));
            STATIC_EXPECT_TRUE((std::is_same_v<decltype(ptr), opaque_unique_ptr<const void>>) );

            EXPECT_EQ(address, ptr.get());
        }

        EXPECT_EQ(i, 2); // Destructor increments: should be properly called **once**
    }
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
