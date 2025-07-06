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
#include <fuyu/memory.hpp>
#include <fuyu/memory_requirements.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

namespace fuyu = fubuki::fuyu;

using namespace fubuki::test;

using vk_handle = VkDeviceMemory;
using vk_info   = VkMemoryAllocateInfo;

using resource_handle = fubuki::device_memory_handle;
using resource_raii   = fubuki::fuyu::memory;

namespace detail
{

// Allocates an image to avoid having to guess random memory requirements
[[nodiscard]] auto make_boundable_resource()
{
    const auto info = fubuki::fuyu::buffer::information{
        .flags        = {},
        .size         = 128,
        .usage        = VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT,
        .sharing_mode = {fuyu::sharing_mode::exclusive{}},
    };

    return fubuki::fuyu::buffer::make(context::device(), info);
}

[[nodiscard]] auto memory_for_resource(const fubuki::fuyu::buffer& rc, VkMemoryPropertyFlags properties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
{
    // NOTE: Generally speaking, this isn't a good idea to have one fragment of memory per image or per resource.
    // Memory gets fragmented very fast, which is likely to reduce the overall performance.
    // All resources sharing the same memory type should be put in the same chunck, one after another.
    // In other words, a real engine should first query all requirements for persistent resources first, and then allocate memory by pools.
    // For the purpose of simplificty, unit tests don't do that kind of optimisation.

    // clang-format off
    return fubuki::fuyu::memory
    {
            context::device(),
            {
                .requirements = fubuki::fuyu::information::memory::make_requirements(fubuki::memory_requirements(rc)),
                .properties   = properties,
            }
    };
    // clang-format on
}

[[nodiscard]] auto make_memory_for_resource(const fubuki::fuyu::buffer& rc, VkMemoryPropertyFlags properties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
{
    // NOTE: Generally speaking, this isn't a good idea to have one fragment of memory per image or per resource.
    // Memory gets fragmented very fast, which is likely to reduce the overall performance.
    // All resources sharing the same memory type should be put in the same chunck, one after another.
    // In other words, a real engine should first query all requirements for persistent resources first, and then allocate memory by pools.
    // For the purpose of simplificty, unit tests don't do that kind of optimisation.

    // clang-format off
    return fubuki::fuyu::memory::make(

            context::device(),
            {
                .requirements = fubuki::fuyu::information::memory::make_requirements(fubuki::memory_requirements(rc)),
                .properties   = properties,
            }
    );
    // clang-format on
}

} // namespace detail

TEST(memory, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(memory, ctor)
{
    auto required_resources = detail::make_boundable_resource();

    ASSERT_TRUE(required_resources.has_value()) << "Failed to create the required resources for fuyu::memory. API call error:"
                                                << required_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        {
            const auto rc = detail::memory_for_resource(*required_resources);
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
        const auto intermediate_rc = detail::make_boundable_resource();
        {
            const auto rc = detail::make_memory_for_resource(*required_resources);
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(memory, external_handle)
{
    auto required_resources = detail::make_boundable_resource();

    ASSERT_TRUE(required_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:"
                                                << required_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1 = detail::memory_for_resource(*required_resources);
                const resource_raii rc2{{fuyu::take_ownership{rc1.handle()}}, rc1.device(), rc1.info()};

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
                const resource_raii rc1 = detail::memory_for_resource(*required_resources);
                const resource_raii rc2{{fuyu::borrow{rc1.handle()}}, rc1.device(), rc1.info()};

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
                auto rc1 = detail::make_memory_for_resource(*required_resources);
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::take_ownership{rc1->handle()}}, rc1->device(), rc1->info());
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
                auto rc1 = detail::make_memory_for_resource(*required_resources);
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{rc1->handle()}}, rc1->device(), rc1->info());
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

TEST(memory, view)
{
    {
        auto required_resources = detail::make_boundable_resource();

        ASSERT_TRUE(required_resources.has_value())
            << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:" << required_resources.error()
            << "\nValidation errors: " << print_and_clear_errors();

        const auto rc = detail::memory_for_resource(*required_resources, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
        EXPECT_EQ(view.requirements.size, rc.size());
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(memory, rebind)
{
    {
        auto required_resources = detail::make_boundable_resource();

        ASSERT_TRUE(required_resources.has_value())
            << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:" << required_resources.error()
            << "\nValidation errors: " << print_and_clear_errors();

        auto rc = detail::memory_for_resource(*required_resources, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(memory, functions)
{
    {
        auto required_resources = detail::make_boundable_resource();

        ASSERT_TRUE(required_resources.has_value())
            << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:" << required_resources.error()
            << "\nValidation errors: " << print_and_clear_errors();

        const auto rc = detail::memory_for_resource(*required_resources, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

        const auto map = fubuki::fuyu::map(rc);
        ASSERT_TRUE(map.has_value()) << "API call failed: " << map.error();

        fubuki::fuyu::unmap(rc);
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
