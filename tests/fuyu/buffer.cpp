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
#include <fuyu/buffer.hpp>
#include <fuyu/buffer_view.hpp>
#include <fuyu/memory.hpp>
#include <fuyu/memory_requirements.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;

namespace fuyu = fubuki::fuyu;

using vk_handle = VkBuffer;
using vk_info   = VkBufferCreateInfo;

using vk_view_handle = VkBufferView;
using vk_view_info   = VkBufferViewCreateInfo;

using resource_handle = fubuki::buffer_handle;
using resource_raii   = fubuki::fuyu::buffer;

using view_handle = fubuki::buffer_view_handle;
using view_raii   = fubuki::fuyu::buffer_view;

namespace detail
{

[[nodiscard]] FUBUKI_TRUE_PURE auto resource_info() noexcept
{
    return resource_raii::information{
        .flags        = {},
        .size         = 128,
        .usage        = VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
        .sharing_mode = {fuyu::sharing_mode::exclusive{}},
    };
}

[[nodiscard]] constexpr auto view_info() noexcept
{
    return view_raii::information{.format = VK_FORMAT_R8_UNORM, .offset = 0, .range = VK_WHOLE_SIZE};
}

[[nodiscard]] auto memory_for_resource(const resource_raii& rc) noexcept
{
    // NOTE: Generally speaking, this isn't a good idea to have one fragment of memory per image or per resource.
    // Memory gets fragmented very fast, which is likely to reduce the overall performance.
    // All resources sharing the same memory type should be put in the same chunck, one after another.
    // In other words, a real engine should first query all requirements for persistent resources first, and then allocate memory by pools.
    // For the purpose of simplificty, unit tests don't do that kind of optimisation.

    return fubuki::fuyu::memory::make(context::device(),
                                      {
                                          .requirements = fubuki::fuyu::information::memory::make_requirements(fubuki::memory_requirements(rc)),
                                          .properties   = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                      });
}

} // namespace detail

//-----------------------------------------------------------------------------
// Buffer

TEST(buffer, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(buffer, ctor)
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

TEST(buffer, external_handle)
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

TEST(buffer, view)
{
    {
        const resource_raii rc{context::device(), detail::resource_info()};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
        EXPECT_EQ(view.flags, rc.info().flags);
        EXPECT_EQ(view.size, rc.info().size);
        EXPECT_EQ(view.usage, rc.info().usage);
        EXPECT_EQ(view.sharing_mode, rc.info().sharing_mode);
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(buffer, rebind)
{
    {
        resource_raii rc{context::device(), detail::resource_info()};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(buffer, functions)
{
    {
        const resource_raii rc{context::device(), detail::resource_info()};
        const auto          rc_memory = detail::memory_for_resource(rc);
        ASSERT_TRUE(rc_memory.has_value()) << "API call failed: " << rc_memory.error();
        std::ignore = fubuki::fuyu::bind(rc, *rc_memory);
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

//-----------------------------------------------------------------------------
// Buffer view

TEST(buffer_view, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<view_handle::underlying_type, vk_view_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<view_raii::handle_type, view_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<view_handle>::underlying_type, vk_view_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<view_handle>::handle, view_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<view_handle>::vk_info, vk_view_info>) );
}

TEST(buffer_view, ctor)
{
    const auto rc = resource_raii::make(context::device(), detail::resource_info());
    ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
    const auto rc_memory = detail::memory_for_resource(*rc);
    ASSERT_TRUE(rc_memory.has_value()) << "API call failed: " << rc_memory.error();

    const auto bound = fubuki::fuyu::bind(*rc, *rc_memory);
    ASSERT_TRUE(bound.has_value()) << "API call failed: " << bound.error();

    // Throwing ctor
    try
    {
        {
            const view_raii view{*rc, detail::view_info()};
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }

    // Expected
    try
    {
        {
            const auto view = view_raii::make(*rc, detail::view_info());
            EXPECT_TRUE(view.has_value()) << "API call failed: " << view.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }
}

TEST(buffer_view, external_handle)
{
    const auto rc = resource_raii::make(context::device(), detail::resource_info());
    ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
    const auto rc_memory = detail::memory_for_resource(*rc);
    ASSERT_TRUE(rc_memory.has_value()) << "API call failed: " << rc_memory.error();

    const auto bound = fubuki::fuyu::bind(*rc, *rc_memory);
    ASSERT_TRUE(bound.has_value()) << "API call failed: " << bound.error();

    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                view_raii       rc1{*rc, detail::view_info()};
                const view_raii rc2{{fuyu::take_ownership{rc1.handle()}}, *rc, rc1.info()};

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
                const view_raii rc1{*rc, detail::view_info()};
                const view_raii rc2{{fuyu::borrow{rc1.handle()}}, *rc, rc1.info()};

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
                auto rc1 = view_raii::make(*rc, detail::view_info());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = view_raii::make({fuyu::take_ownership{rc1->handle()}}, *rc, rc1->info());
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
                auto rc1 = view_raii::make(*rc, detail::view_info());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = view_raii::make({fuyu::borrow{rc1->handle()}}, *rc, rc1->info());
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

TEST(buffer_view, view)
{
    {
        const auto rc = resource_raii::make(context::device(), detail::resource_info());
        ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        const auto rc_memory = detail::memory_for_resource(*rc);
        ASSERT_TRUE(rc_memory.has_value()) << "API call failed: " << rc_memory.error();

        const auto bound = fubuki::fuyu::bind(*rc, *rc_memory);
        ASSERT_TRUE(bound.has_value()) << "API call failed: " << bound.error();

        const view_raii view{*rc, detail::view_info()};

        const view_raii::view view_desc = view;

        EXPECT_EQ(view_desc.handle, view.handle());
        EXPECT_EQ(std::addressof(view_desc.device.get()), std::addressof(view.device()));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(buffer_view, rebind)
{
    {
        const auto rc = resource_raii::make(context::device(), detail::resource_info());
        ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        const auto rc_memory = detail::memory_for_resource(*rc);
        ASSERT_TRUE(rc_memory.has_value()) << "API call failed: " << rc_memory.error();

        const auto bound = fubuki::fuyu::bind(*rc, *rc_memory);
        ASSERT_TRUE(bound.has_value()) << "API call failed: " << bound.error();

        view_raii view{*rc, detail::view_info()};

        ASSERT_TRUE(view.rebind({context::device()}));
        ASSERT_TRUE(rebind(view, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
