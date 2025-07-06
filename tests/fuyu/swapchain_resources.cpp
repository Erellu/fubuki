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
#include "resources_for_swapchain.hpp"
#include "validation.hpp"

#include <array>
#include <source_location>
#include <utility>

#include <gtest/gtest.h>

#include <fuyu/device.hpp>
#include <fuyu/render_pass.hpp>
#include <fuyu/swapchain.hpp>
#include <fuyu/swapchain_resources.hpp>

namespace
{

using namespace fubuki::test;
namespace fuyu = fubuki::fuyu;

using resource_raii = fuyu::swapchain_resources;

namespace detail
{

namespace render_target
{

using render_pass       = resource_raii::information::render_pass;
using dynamic_rendering = resource_raii::information::dynamic_rendering;

using any = resource_raii::information::any_render_target;

} // namespace render_target

struct setup
{
    std::array<render_target::any, 3> render_target;
};

struct required_resources
{
    resources_for_swapchain for_parent;
    fuyu::swapchain         swapchain;
    fuyu::render_pass       render_pass;
};

[[nodiscard]] std::expected<required_resources, fubuki::api_call_info> make_required_resources(std::source_location s
                                                                                               = std::source_location::current()) noexcept
{
    auto parent_resources = resources_for_swapchain::make(context::instance(), context::device().physical_device());

    if(not parent_resources)
    {
        return std::unexpected{parent_resources.error()};
    }

    auto parent = fuyu::swapchain::make(context::device(), parent_resources->surface, make_swapchain_info(*parent_resources, s));

    if(not parent)
    {
        return std::unexpected{parent.error()};
    }

    auto render_pass = resources_for_swapchain::make_compatible_render_pass(context::device(), *parent_resources);

    if(not render_pass)
    {
        return std::unexpected{render_pass.error()};
    }

    return required_resources{*std::move(parent_resources), *std::move(parent), *std::move(render_pass)};
}

[[nodiscard]] resource_raii::information resource_info(render_target::any rt) noexcept { return {.render_target = std::move(rt)}; }

[[nodiscard]] setup available_setups(const required_resources& rc)
{
    using any = render_target::any;

    // clang-format off
    return
    {
        .render_target =
        {
            any{render_target::render_pass{rc.render_pass}},        // Existing render pass
            any{render_target::render_pass{rc.render_pass.info()}}, // New render pass, created as part of fuyu::swapchain_resources
            any{render_target::dynamic_rendering{}},                // Dynamic render target
        },
    };
    // clang-format on
}

} // namespace detail

TEST(swapchain_resources, ctor)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::swapchain_resources. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        const auto available_setups = detail::available_setups(*parent_resources);

        for(const auto& rt_setup : available_setups.render_target)
        {
            // Throwing ctor
            try
            {
                {
                    const resource_raii rc{parent_resources->swapchain, detail::resource_info(rt_setup)};
                }
                EXPECT_TRUE(no_errors()) << "Errors for setup " << rt_setup
                                         << " with the following validation messages: " << print_and_clear_errors();
                EXPECT_TRUE(no_warnings()) << "Warning for setup " << rt_setup
                                           << " with the following validation messages: " << print_and_clear_warnings();
            }
            catch(const fubuki::api_call_exception& error)
            {
                ADD_FAILURE() << "Failed to create object with the following error: " << error;
            }

            // Expected
            {
                {
                    const auto rc = resource_raii::make(parent_resources->swapchain, detail::resource_info(rt_setup));
                    EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
                }
                EXPECT_TRUE(no_errors()) << "Errors for setup " << rt_setup
                                         << " with the following validation messages: " << print_and_clear_errors();
                EXPECT_TRUE(no_warnings()) << "Warning for setup " << rt_setup
                                           << " with the following validation messages: " << print_and_clear_warnings();
            }
        }
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(swapchain_resources, view)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::swapchain_resources. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        const auto available_setups = detail::available_setups(*parent_resources);

        for(const auto& rt_setup : available_setups.render_target)
        {
            const auto rc = resource_raii::make(parent_resources->swapchain, detail::resource_info(rt_setup));
            ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();

            const resource_raii::view v = *rc;

            // View range
            {
                EXPECT_EQ(v.size(), rc->size());
                EXPECT_EQ(v.empty(), rc->empty());
            }

            // View element access
            {
                for(const std::size_t idx : std::views::iota(0U, v.size()))
                {
                    EXPECT_NO_THROW(std::ignore = v.at(idx));
                    EXPECT_NO_THROW(std::ignore = rc->at(idx));

                    EXPECT_EQ(v.at(idx), rc->at(idx));
                    EXPECT_EQ(v.at(idx), v[idx]);
                    EXPECT_EQ(v[idx], (*rc)[idx]);
                }

                EXPECT_THROW(std::ignore = v.at(v.size()), std::out_of_range);
                EXPECT_THROW(std::ignore = rc->at(v.size()), std::out_of_range);
            }
        }
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(swapchain_resources, rebind)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        const auto available_setups = detail::available_setups(*parent_resources);

        for(const auto& rt_setup : available_setups.render_target)
        {
            resource_raii rc = {parent_resources->swapchain, detail::resource_info(rt_setup)};

            ASSERT_TRUE(rc.rebind({context::device()}));
            ASSERT_TRUE(rebind(rc, {context::device()}));
        }
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(swapchain_resources, functions)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::swapchain_resources. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        const auto available_setups = detail::available_setups(*parent_resources);

        for(const auto& rt_setup : available_setups.render_target)
        {
            auto rc = resource_raii::make(parent_resources->swapchain, detail::resource_info(rt_setup));
            ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();

            // Recreate
            {
                {
                    const auto result = fuyu::recreate(parent_resources->swapchain, *rc);
                    EXPECT_TRUE(result.has_value()) << "API call failed: " << result.error();
                }

                EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
                EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
            }
        }
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace
