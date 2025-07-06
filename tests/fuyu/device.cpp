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
#include <extension/khr_surface.hpp>
#include <fuyu/device.hpp>
#include <fuyu/hardware.hpp>
#include <fuyu/instance.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;
namespace fuyu = fubuki::fuyu;

using vk_handle = VkDevice;
using vk_info   = VkDeviceCreateInfo;

using resource_handle = fubuki::device_handle;
using resource_raii   = fuyu::device;

namespace detail
{

[[nodiscard]] auto resource_complements()
{
    return resource_raii::information::complements{
        .queues     = {{
                           .type     = VK_QUEUE_GRAPHICS_BIT,
                           .flags    = {},
                           .priority = +0.f,
                   }, {
                           .type     = VK_QUEUE_COMPUTE_BIT,
                           .flags    = {},
                           .priority = +0.f,
                   }, {
                           .type     = VK_QUEUE_TRANSFER_BIT,
                           .flags    = {},
                           .priority = +0.f,
                   }},
        .extensions = {},
        .surfaces   = {context::surface()}, // None in this test suite
        .features   = {},
    };
}

} // namespace detail

TEST(device, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(device, ctor)
{
    const auto available = fuyu::hardware::physical_devices(context::instance());

    ASSERT_TRUE(available.has_value()) << "An error occured while enumerating physical devices: " << available.error();
    ASSERT_TRUE(not available->empty()) << "No GPU available for the tests :(.";

    const auto physical_device = available->front();

    // Throwing ctor
    try
    {
        {
            const resource_raii rc{context::instance(), physical_device, {}, detail::resource_complements()};
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }

    // Throwing ctor with a chain
    try
    {
        {
            auto physical_device_info = fuyu::hardware::physical_device_information(context::instance(), physical_device);
            ASSERT_TRUE(physical_device_info.has_value())
                << "An error occured while retrieving physical device info: " << physical_device_info.error();

            // Enable all core features supported by the device
            const fubuki::pnext_chain chain{
                physical_device_info->features.vk11,
                physical_device_info->features.vk12,
                physical_device_info->features.vk13,
            };

            const resource_raii rc{context::instance(), physical_device, {}, detail::resource_complements(), chain};
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
            const auto rc = resource_raii::make(context::instance(), physical_device, resource_raii::information{}, detail::resource_complements());
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }

    // Expected with a chain
    {
        {
            auto physical_device_info = fuyu::hardware::physical_device_information(context::instance(), physical_device);
            ASSERT_TRUE(physical_device_info.has_value())
                << "An error occured while retrieving physical device info: " << physical_device_info.error();

            // Enable all core features supported by the device
            const fubuki::pnext_chain chain{
                physical_device_info->features.vk11,
                physical_device_info->features.vk12,
                physical_device_info->features.vk13,
            };

            const auto rc
                = resource_raii::make(context::instance(), physical_device, resource_raii::information{}, detail::resource_complements(), chain);
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(device, external_handle)
{
    const auto available = fuyu::hardware::physical_devices(context::instance());

    ASSERT_TRUE(available.has_value()) << "An error occured while enumerating physical devices: " << available.error();
    ASSERT_TRUE(not available->empty()) << "No GPU available for the tests :(.";

    const auto physical_device = available->front();

    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1{context::instance(), physical_device, {}, detail::resource_complements()};
                const resource_raii rc2{
                    {fuyu::take_ownership{rc1.handle()}}, context::instance(), physical_device, rc1.info(), detail::resource_complements()};

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
                const resource_raii rc1{context::instance(), physical_device, {}, detail::resource_complements()};
                const resource_raii rc2{
                    {fuyu::borrow{rc1.handle()}}, context::instance(), physical_device, rc1.info(), detail::resource_complements()};

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
                auto rc1 = resource_raii::make(context::instance(), physical_device, {}, detail::resource_complements());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make(
                    {fuyu::take_ownership{rc1->handle()}}, context::instance(), physical_device, rc1->info(), detail::resource_complements());
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
                auto rc1 = resource_raii::make(context::instance(), physical_device, {}, detail::resource_complements());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make(
                    {fuyu::borrow{rc1->handle()}}, context::instance(), physical_device, rc1->info(), detail::resource_complements());
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

TEST(device, view)
{
    {
        const auto available = fuyu::hardware::physical_devices(context::instance());

        ASSERT_TRUE(available.has_value()) << "An error occured while enumerating physical devices: " << available.error();
        ASSERT_TRUE(not available->empty()) << "No GPU available for the tests :(.";

        const auto physical_device = available->front();

        const resource_raii rc{context::instance(), physical_device, {}, detail::resource_complements()};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.instance.get()), std::addressof(rc.instance()));
        EXPECT_EQ(view.version, rc.instance().info().application.vulkan_version);
        EXPECT_EQ(std::addressof(view.functions.get()), std::addressof(rc.function()));
        EXPECT_EQ(view.hardware, rc.physical_device());
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(device, rebind)
{
    {
        const auto available = fuyu::hardware::physical_devices(context::instance());

        ASSERT_TRUE(available.has_value()) << "An error occured while enumerating physical devices: " << available.error();
        ASSERT_TRUE(not available->empty()) << "No GPU available for the tests :(.";

        const auto physical_device = available->front();

        resource_raii rc{context::instance(), physical_device, {}, detail::resource_complements()};

        ASSERT_TRUE(rc.rebind({context::instance()}));
        ASSERT_TRUE(rebind(rc, {context::instance()}));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(device, queues)
{
    {
        const auto available = fuyu::hardware::physical_devices(context::instance());

        ASSERT_TRUE(available.has_value()) << "An error occured while enumerating physical devices: " << available.error();
        ASSERT_TRUE(not available->empty()) << "No GPU available for the tests :(.";

        const auto physical_device = (*available)[0];

        const resource_raii rc{context::instance(), physical_device, {}, detail::resource_complements()};

        const auto queues = rc.queues();

        // Queue handles
        for(const auto& q : queues.all)
        {
            EXPECT_TRUE(q.handle != fubuki::null_handle);
            EXPECT_EQ(std::addressof(q.device.get()), std::addressof(rc));
        }

        // Presentable queues
        {
            const auto supports_present
                = [hardware = rc.physical_device()](const fuyu::queue& q) noexcept -> std::expected<bool, fubuki::api_call_info>
            {
                const auto surface = context::surface();
                return fubuki::extension::khr_surface::support(surface.instance.get().function().ext, hardware, surface, q.family);
            };

            for(const auto& q : queues.presentable)
            {
                const auto has_support = supports_present(q);

                ASSERT_TRUE(has_support.has_value()) << " API call failed: " << has_support.error();
                EXPECT_TRUE(*has_support);
            }
        }

        // Dedicated queue search
        {
            const auto queue_properties = fuyu::hardware::queue_properties(rc);

            if(const auto compute = fuyu::hardware::queue_family_index(queue_properties, VK_QUEUE_COMPUTE_BIT))
            {
                if(const auto dedicated = fuyu::queue::compute_dedicated(queues.all)) // Silence clang-tidy
                {
                    EXPECT_EQ(*compute, dedicated->family);
                }
            }

            if(const auto transfer = fuyu::hardware::queue_family_index(queue_properties, VK_QUEUE_TRANSFER_BIT))
            {
                if(const auto dedicated = fuyu::queue::transfer_dedicated(queues.all))
                {
                    EXPECT_EQ(*transfer, dedicated->family);
                }
            }
        }
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

#undef STATIC_EXPECT_TRUE

} // anonymous namespace
