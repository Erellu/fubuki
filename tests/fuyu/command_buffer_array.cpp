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
#include <fuyu/command/submit.hpp>
#include <fuyu/command_buffer_array.hpp>
#include <fuyu/command_pool.hpp>
#include <fuyu/device.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using fubuki::small_vector;

using namespace fubuki::test;

namespace fuyu = fubuki::fuyu;

using vk_handle = VkCommandBuffer;
using vk_info   = VkCommandBufferAllocateInfo;

using resource_handle = fubuki::command_buffer_handle;
using resource_raii   = fubuki::fuyu::command_buffer_array;

namespace detail
{

using required_resources = fuyu::command_pool;

[[nodiscard]] std::expected<required_resources, fubuki::api_call_info> make_required_resources() noexcept
{
    return required_resources::make(context::device(), {.queue_family = context::device().queues().all.front().family});
}

[[nodiscard]] resource_raii::information resource_info() noexcept
{
    return {
        .count = 4,
        .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY,
    };
}

} // namespace detail

TEST(command_buffer_array, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(command_buffer_array, ctor)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        {
            const resource_raii rc{*parent_resources, detail::resource_info()};
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
            const auto rc = resource_raii::make(*parent_resources, detail::resource_info());
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(command_buffer_array, external_handle)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::pipeline_layout. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii rc1{*parent_resources, detail::resource_info()};

                const resource_raii rc2{{fuyu::take_ownership{small_vector<resource_handle>(rc1.begin(), rc1.end())}}, rc1.pool(), rc1.info()};

                EXPECT_TRUE(std::ranges::equal(rc1.handle(), rc2.handle()));
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
                resource_raii       rc1{*parent_resources, detail::resource_info()};
                const resource_raii rc2{{fuyu::borrow{small_vector<resource_handle>(rc1.begin(), rc1.end())}}, rc1.pool(), rc1.info()};

                EXPECT_TRUE(std::ranges::equal(rc1.handle(), rc2.handle()));
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
                auto rc1 = resource_raii::make(*parent_resources, detail::resource_info());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2
                    = resource_raii::make({fuyu::take_ownership{small_vector<resource_handle>(rc1->begin(), rc1->end())}}, rc1->pool(), rc1->info());
                ASSERT_TRUE(rc2.has_value()) << "API call failed: " << rc2.error();

                EXPECT_TRUE(std::ranges::equal(rc1->handle(), rc2->handle()));
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
                auto rc1 = resource_raii::make(*parent_resources, detail::resource_info());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{small_vector<resource_handle>(rc1->begin(), rc1->end())}}, rc1->pool(), rc1->info());
                ASSERT_TRUE(rc2.has_value()) << "API call failed: " << rc2.error();

                EXPECT_TRUE(std::ranges::equal(rc1->handle(), rc2->handle()));
                EXPECT_EQ(rc1->info(), rc2->info());
                EXPECT_FALSE(rc2->owns());
                EXPECT_TRUE(rc2->borrows());
            }
            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }
    }
}

TEST(command_buffer_array, view)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        const resource_raii       rc{*parent_resources, detail::resource_info()};
        const resource_raii::view view = rc;

        EXPECT_TRUE(std::ranges::equal(view.handles, rc.handle()));
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
        EXPECT_EQ(view.level, rc.info().level);
        ASSERT_EQ(view.size(), rc.size());

        for(const std::size_t i : std::views::iota(0U, rc.size()))
        {
            EXPECT_EQ(view[i], rc[i]);
            EXPECT_EQ(view.at(i), rc.at(i));
        }
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(command_buffer_array, rebind)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        resource_raii rc{*parent_resources, detail::resource_info()};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(command_buffer_array, functions)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        ASSERT_TRUE(not context::device().queues().all.empty()) << "No queue available";
        const resource_raii rc{*parent_resources, detail::resource_info()};
        auto                command_buffer = rc.at(0);

        if(const auto check = fubuki::fuyu::begin(command_buffer); not check)
        {
            ADD_FAILURE() << "API call failed:" << check.error();
        }

        if(const auto check = fubuki::fuyu::end(command_buffer); not check)
        {
            ADD_FAILURE() << "API call failed:" << check.error();
        }

        if(const auto check = fuyu::submit(context::device().queues().all.front(), command_buffer); not check)
        {
            ADD_FAILURE() << "API call failed:" << check.error();
        }

        if(const auto check = fuyu::wait_idle(context::device().queues().all.front()); not check)
        {
            ADD_FAILURE() << "API call failed:" << check.error();
        }
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
