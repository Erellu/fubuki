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

#include "validation.hpp"

#include <gtest/gtest.h>

#include <core/collect.hpp>
#include <core/detail/handle_traits.hpp>
#include <fuyu/hardware.hpp>
#include <fuyu/instance.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;

namespace fuyu = fubuki::fuyu;

using vk_handle = VkInstance;
using vk_info   = VkInstanceCreateInfo;

using resource_handle = fubuki::instance_handle;
using resource_raii   = fubuki::fuyu::instance;

namespace detail
{

[[nodiscard]] FUBUKI_TRUE_PURE auto resource_info()
{
    // clang-format off
    return fubuki::fuyu::instance::information
    {
        .application =
        {
            .name           = "Fubuki - Testing",
            .version        = {1, 0, 0},
            .vulkan_version = {1, 3, 0},
            .engine         =
            {
                .name = "Fubuki - Fuyu",
                .version = {1, 3, 0}
            }
        },
        .flags  = {},
        .callbacks   = {}
    };
    // clang-format on
}

} // namespace detail

TEST(instance, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(instance, ctor)
{
    const auto supported_extensions = fuyu::hardware::supported_instance_extensions();
    ASSERT_TRUE(supported_extensions.has_value()) << "Failed to query instance extensions. API error: " << supported_extensions.error();

    // Throwing ctor
    try
    {
        {
            const resource_raii instance{detail::resource_info(), {}};
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }

    // Throwing ctor with a chain
#if defined(VK_EXT_validation_flags)
    try
    {
        if(supported_extensions->names.contains("VK_EXT_validation_flags"))
        {
            constexpr std::array checks = {VK_VALIDATION_CHECK_ALL_EXT, VK_VALIDATION_CHECK_SHADERS_EXT};

            VkValidationFlagsEXT ext         = {};
            ext.disabledValidationCheckCount = fubuki::vk_size(checks);
            ext.pDisabledValidationChecks    = checks.data();

            const fubuki::pnext_chain chain{ext};

            const resource_raii instance{detail::resource_info(), {}, chain};
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }
#endif // defined(VK_EXT_validation_flags>

    // Expected
    {
        {
            const auto rc = resource_raii::make(detail::resource_info(), {});
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }

    // Expected with a chain
#if defined(VK_EXT_validation_flags)
    {
        if(supported_extensions->names.contains("VK_EXT_validation_flags"))
        {
            constexpr std::array checks = {VK_VALIDATION_CHECK_ALL_EXT, VK_VALIDATION_CHECK_SHADERS_EXT};

            VkValidationFlagsEXT ext         = {};
            ext.disabledValidationCheckCount = fubuki::vk_size(checks);
            ext.pDisabledValidationChecks    = checks.data();

            const fubuki::pnext_chain chain{ext};

            const auto rc = resource_raii::make(detail::resource_info(), {}, chain);
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
#endif // defined(VK_EXT_validation_flags>
}

TEST(instance, external_handle)
{
    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1{detail::resource_info(), {}};
                const resource_raii rc2{{fuyu::take_ownership{rc1.handle()}}, rc1.info(), {}};

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
                const resource_raii rc1{detail::resource_info(), {}};
                const resource_raii rc2{{fuyu::borrow{rc1.handle()}}, rc1.info(), {}};

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
                auto rc1 = resource_raii::make(detail::resource_info(), {});
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::take_ownership{rc1->handle()}}, rc1->info(), {});
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
                auto rc1 = resource_raii::make(detail::resource_info(), {});
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{rc1->handle()}}, rc1->info(), {});
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

TEST(instance, view)
{
    {
        const resource_raii rc{detail::resource_info(), {}};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(view.version, rc.info().application.vulkan_version);
        EXPECT_EQ(std::addressof(view.functions.get()), std::addressof(rc.function()));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

#undef STATIC_EXPECT_TRUE

} // anonymous namespace
