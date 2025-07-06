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

#include <future>

#include <gtest/gtest.h>

#include <core/detail/handle_traits.hpp>
#include <core/handle.hpp>
#include <fuyu/semaphore.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;
namespace fuyu = fubuki::fuyu;

using vk_handle = VkSemaphore;
using vk_info   = VkSemaphoreCreateInfo;

using resource_handle = fubuki::semaphore_handle;
using resource_raii   = fubuki::fuyu::semaphore;

namespace detail
{

[[nodiscard]] FUBUKI_TRUE_PURE auto resource_info() noexcept { return resource_raii::information{}; }

} // namespace detail

TEST(semaphore, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(semaphore, ctor)
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

TEST(semaphore, external_handle)
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

TEST(semaphore, view)
{
    {
        const resource_raii rc{context::device(), detail::resource_info()};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(semaphore, rebind)
{
    {
        resource_raii rc{context::device(), detail::resource_info()};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(semaphore, functions)
{
#if defined(VK_VERSION_1_2)
    {
        using std::chrono_literals::operator""ns;

        constexpr std::uint64_t initial = 1;
        constexpr auto          delay   = 500ns;

        VkSemaphoreTypeCreateInfo type{.sType = {}, .pNext = {}, .semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE, .initialValue = initial};

        const resource_raii rc{context::device(), detail::resource_info(), fubuki::pnext_chain{type}};

        {
            const auto current = fubuki::fuyu::counter_value(rc);
            ASSERT_TRUE(current.has_value()) << "API call failed: " << current.error();
            EXPECT_EQ(*current, initial);
        }

        {
            const auto r = fubuki::fuyu::signal(rc, initial + 1);
            EXPECT_TRUE(r) << "API call failed: " << r.error();
        }

        {
            const auto current = fubuki::fuyu::counter_value(rc);
            ASSERT_TRUE(current.has_value()) << "API call failed: " << current.error();
            EXPECT_EQ(*current, initial + 1);
        }

        auto future = std::async(std::launch::async,
                                 [&rc]()
                                 {
                                     const auto r = fubuki::fuyu::signal(rc, initial + 2);
                                     EXPECT_TRUE(r) << "API call failed: " << r.error();
                                 });
        EXPECT_NO_THROW(future.get()); // Force to wait for the semaphore to be signaled before executing the test below

        {
            const auto r = fubuki::fuyu::wait_on(rc, initial + 2, delay, {/*no flags*/});
            EXPECT_TRUE(r) << "API call failed: " << r.error();
        }
    }
#endif // #if defined(VK_VERSION_1_2)

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
