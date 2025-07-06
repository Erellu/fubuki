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

#include <fuyu/surface.hpp>
#include <io/display.hpp>
#include <io/window.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

#if defined(VK_KHR_surface)
namespace
{

using namespace fubuki::test;
namespace fuyu = fubuki::fuyu;

using vk_handle       = VkSurfaceKHR;
using resource_handle = fubuki::surface_khr_handle;

using resource_raii = fubuki::fuyu::surface;

TEST(surface, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
}

TEST(surface, ctor)
{
    auto dp = fubuki::io::display::make();

    if(not dp)
    {
        FAIL() << "Failed to created a display: " << dp.error();
    }

    // clang-format off
    auto w = fubuki::io::window::make(*dp,
                                      {
                                          .title       = "",
                                          .size        = {16, 16},
                                          .coordinates = {0,  0 },
                                          .opacity     = 0.f,
                                          .style       = fubuki::io::window_style::os_default,
                                      });

    // clang-format on

    if(not w)
    {
        FAIL() << "Failed to created a display: " << w.error();
    }

    // Don't show the window in this unit test
    ASSERT_TRUE(w->hide());

    // Throwing ctor
    try
    {
        {
            const resource_raii rc{context::instance(), *w};
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
            const auto rc = resource_raii::make(context::instance(), *w);
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(surface, external_handle)
{
    auto dp = fubuki::io::display::make();

    if(not dp)
    {
        FAIL() << "Failed to created a display: " << dp.error();
    }

    // clang-format off
    auto w = fubuki::io::window::make(*dp,
                                      {
                                          .title       = "",
                                          .size        = {16, 16},
                                          .coordinates = {0,  0 },
                                          .opacity     = 0.f,
                                          .style       = fubuki::io::window_style::os_default,
                                          });

    // clang-format on

    if(not w)
    {
        FAIL() << "Failed to created a display: " << w.error();
    }

    // Don't show the window in this unit test
    ASSERT_TRUE(w->hide());

    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1{context::instance(), *w};
                const resource_raii rc2{{fuyu::take_ownership{rc1.handle()}}, context::instance(), rc1.info()};

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
                const resource_raii rc1{context::instance(), *w};
                const resource_raii rc2{{fuyu::borrow{rc1.handle()}}, context::instance(), rc1.info()};

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
                auto rc1 = resource_raii::make(context::instance(), *w);
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::take_ownership{rc1->handle()}}, context::instance(), rc1->info());
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
                auto rc1 = resource_raii::make(context::instance(), *w);
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{rc1->handle()}}, context::instance(), rc1->info());
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

TEST(surface, view)
{
    {
        auto dp = fubuki::io::display::make();

        if(not dp)
        {
            FAIL() << "Failed to created a display: " << dp.error();
        }

        // clang-format off
        auto w = fubuki::io::window::make(*dp,
                                          {
                                              .title       = "",
                                              .size        = {16, 16},
                                              .coordinates = {0,  0 },
                                              .opacity     = 0.f,
                                              .style       = fubuki::io::window_style::os_default,
                                              });

        // clang-format on

        if(not w)
        {
            FAIL() << "Failed to created a display: " << w.error();
        }

        // Don't show the window in this unit test
        ASSERT_TRUE(w->hide());

        const resource_raii       rc{context::instance(), *w};
        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.instance.get()), std::addressof(rc.instance()));
        EXPECT_EQ(view.platform_data, rc.platform_info());
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(surface, rebind)
{
    {
        auto dp = fubuki::io::display::make();

        if(not dp)
        {
            FAIL() << "Failed to created a display: " << dp.error();
        }

        // clang-format off
        auto w = fubuki::io::window::make(*dp,
                                          {
                                              .title       = "",
                                              .size        = {16, 16},
                                              .coordinates = {0,  0 },
                                              .opacity     = 0.f,
                                              .style       = fubuki::io::window_style::os_default,
                                              });

        // clang-format on

        if(not w)
        {
            FAIL() << "Failed to created a display: " << w.error();
        }

        // Don't show the window in this unit test
        ASSERT_TRUE(w->hide());

        resource_raii rc{context::instance(), *w};
        ASSERT_TRUE(rc.rebind({context::instance()}));
        ASSERT_TRUE(rebind(rc, {context::instance()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace
#endif // #if defined(VK_KHR_surface)

#undef STATIC_EXPECT_TRUE
