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

#include "context.hpp"
#include "validation.hpp"

#include <gtest/gtest.h>

#include <core/detail/handle_traits.hpp>
#include <core/handle.hpp>
#include <core/result.hpp>
#include <fuyu/device.hpp>
#include <fuyu/query_pool.hpp>
#include <fuyu/queue.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;
namespace fuyu = fubuki::fuyu;

using vk_handle = VkQueryPool;
using vk_info   = VkQueryPoolCreateInfo;

using resource_handle = fubuki::query_pool_handle;
using resource_raii   = fubuki::fuyu::query_pool;

namespace detail
{

[[nodiscard]] constexpr auto resource_info() noexcept
{
    return resource_raii::information{.type = VK_QUERY_TYPE_TIMESTAMP, .count = 1, .pipeline_statistics = {}};
}

} // namespace detail

TEST(query_pool, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(query_pool, ctor)
{
    // Throwing ctor
    try
    {
        {
            const resource_raii rc{context::device(), detail::resource_info()};
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }

    // Expected
    {
        {
            const auto rc = resource_raii::make(context::device(), detail::resource_info());
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(query_pool, external_handle)
{
    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1{context::device(), detail::resource_info()};
                const resource_raii rc2{{fuyu::take_ownership{rc1.handle()}}, context::device(), rc1.info()};

                EXPECT_EQ(rc1.handle(), rc2.handle());
                EXPECT_EQ(rc1.info(), rc2.info());
                EXPECT_TRUE(rc2.owns());
                EXPECT_FALSE(rc2.borrows());

                std::ignore = rc1.release();
            }
            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }

        // Borrow
        {
            {
                const resource_raii rc1{context::device(), detail::resource_info()};
                const resource_raii rc2{{fuyu::borrow{rc1.handle()}}, context::device(), rc1.info()};

                EXPECT_EQ(rc1.handle(), rc2.handle());
                EXPECT_EQ(rc1.info(), rc2.info());
                EXPECT_FALSE(rc2.owns());
                EXPECT_TRUE(rc2.borrows());
            }
            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }

    // Expected
    {
        // Take ownership
        {
            {
                auto rc1 = resource_raii::make(context::device(), detail::resource_info());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::take_ownership{rc1->handle()}}, context::device(), rc1->info());
                ASSERT_TRUE(rc2.has_value()) << "API call failed: " << rc2.error();

                EXPECT_EQ(rc1->handle(), rc2->handle());
                EXPECT_EQ(rc1->info(), rc2->info());
                EXPECT_TRUE(rc2->owns());
                EXPECT_FALSE(rc2->borrows());

                std::ignore = rc1->release();
            }
            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }

        // Borrow
        {
            {
                auto rc1 = resource_raii::make(context::device(), detail::resource_info());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{rc1->handle()}}, context::device(), rc1->info());
                ASSERT_TRUE(rc2.has_value()) << "API call failed: " << rc2.error();

                EXPECT_EQ(rc1->handle(), rc2->handle());
                EXPECT_EQ(rc1->info(), rc2->info());
                EXPECT_FALSE(rc2->owns());
                EXPECT_TRUE(rc2->borrows());
            }
            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }
    }
}

TEST(query_pool, view)
{
    {
        const resource_raii rc{context::device(), detail::resource_info()};

        const resource_raii::view view = rc;

        EXPECT_TRUE(std::holds_alternative<fubuki::fuyu::views::query_pool>(view));

        const auto& view_v = std::get<fubuki::fuyu::views::query_pool>(view);

        EXPECT_EQ(view_v.handle, rc.handle());
        EXPECT_EQ(std::addressof(view_v.device.get()), std::addressof(rc.device()));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(query_pool, rebind)
{
    {
        resource_raii rc{context::device(), detail::resource_info()};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(query_pool, functions)
{
    {
        const resource_raii rc{context::device(), detail::resource_info()};

        // Required by the specs before performing other operations.
        fubuki::fuyu::reset(rc, 0, rc.info().count);

        for(const std::uint32_t first_query : std::views::iota(0U, rc.info().count - 1U))
        {
            const auto count = rc.info().count - first_query;

            // 32-bit
            {
                const auto storage = fubuki::fuyu::allocate_buffer(rc, 0, rc.info().count, {});
                EXPECT_EQ(storage.stride, sizeof(std::uint32_t)); // Unless 64_BIT flag is specified, this holds unsigned 32-bit values
                EXPECT_TRUE(std::holds_alternative<std::vector<std::uint32_t>>(storage.storage));
                EXPECT_EQ(std::get<std::vector<std::uint32_t>>(storage.storage).size(), count);
            }

            // 64-bit
            {
                const auto storage = fubuki::fuyu::allocate_buffer(rc, 0, rc.info().count, VK_QUERY_RESULT_64_BIT);
                EXPECT_EQ(storage.stride, sizeof(std::uint64_t)); // Unless 64_BIT flag is specified, this holds unsigned 32-bit values
                EXPECT_TRUE(std::holds_alternative<std::vector<std::uint64_t>>(storage.storage));
                EXPECT_EQ(std::get<std::vector<std::uint64_t>>(storage.storage).size(), count);
            }
        }
    }

    // TODO: test result_of
    // fubuki::fuyu::cmd::begin_query(...);
    // fubuki::fuyu::cmd::end_query(...);

    // // If VK_QUERY_RESULT_WAIT_BIT isn't set, this call may result in VK_NOT_READY
    // EXPECT_NO_THROW([&rc]() { std::ignore = fubuki::results_of(rc, 0, rc.info().count, VK_QUERY_RESULT_WAIT_BIT); }());

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
