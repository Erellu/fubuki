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
#include "descriptor_set_resources.hpp"
#include "validation.hpp"

#include <gtest/gtest.h>

#include <core/detail/handle_traits.hpp>
#include <core/handle.hpp>
#include <fuyu/descriptor_pool.hpp>
#include <fuyu/descriptor_set_layout.hpp>
#include <fuyu/pipeline_layout.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;

namespace fuyu = fubuki::fuyu;

using vk_handle = VkPipelineLayout;
using vk_info   = VkPipelineLayoutCreateInfo;

using resource_handle = fubuki::pipeline_layout_handle;
using resource_raii   = fubuki::fuyu::pipeline_layout;

using required_resources = resources_for_descriptor_set;

namespace detail
{

[[nodiscard]] auto make_required_resources() noexcept { return resources_for_descriptor_set::make(context::device()); }

[[nodiscard]] resource_raii::information resource_info(const required_resources& rc) noexcept
{
    return {
        .flags          = {},
        .set_layouts    = {rc.layout.first, rc.layout.second, rc.layout.third},
        .push_constants = {{.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT, .offset = 0, .size = 4}}
    };
}

} // namespace detail

TEST(pipeline_layout, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(pipeline_layout, ctor)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::pipeline_layout. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        {
            const resource_raii rc{context::device(), detail::resource_info(*parent_resources)};
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
            const auto rc = resource_raii::make(context::device(), detail::resource_info(*parent_resources));
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(pipeline_layout, external_handle)
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
                resource_raii       rc1{context::device(), detail::resource_info(*parent_resources)};
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
                const resource_raii rc1{context::device(), detail::resource_info(*parent_resources)};
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
                auto rc1 = resource_raii::make(context::device(), detail::resource_info(*parent_resources));
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
                auto rc1 = resource_raii::make(context::device(), detail::resource_info(*parent_resources));
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

TEST(pipeline_layout, view)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        const resource_raii rc{context::device(), detail::resource_info(*parent_resources)};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(pipeline_layout, rebind)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        resource_raii rc{context::device(), detail::resource_info(*parent_resources)};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(pipeline_layout, functions) { /*None yet*/ }

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
