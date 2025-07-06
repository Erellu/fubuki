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
#include "pipeline_resources.hpp"
#include "shader_resources.hpp"
#include "validation.hpp"

#include <gtest/gtest.h>

#include <core/detail/handle_traits.hpp>
#include <core/handle.hpp>
#include <fuyu/graphics_pipeline.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;

namespace fuyu = fubuki::fuyu;

using vk_handle = VkPipeline;
using vk_info   = VkGraphicsPipelineCreateInfo;

using resource_handle = fubuki::graphics_pipeline_handle;
using resource_raii   = fubuki::fuyu::graphics_pipeline;

using required_resources = resources_for_pipeline;

namespace detail
{

[[nodiscard]] auto make_required_resources() noexcept { return required_resources::make(context::device()); }

[[nodiscard]] resource_raii::information resource_info(const required_resources& rc) noexcept { return {.layout = rc.layout}; }

[[nodiscard]] resource_raii::information::complements resource_complements() noexcept
{
    namespace spirv = resources::shader::spirv;
    using state     = resource_raii::state;

    // clang-format off
    return {
        .stage
        = {.vertex = {{.shader = fuyu::shader_stage::spirv{spirv::vertex}}}, .fragment = {{.shader = fuyu::shader_stage::spirv{spirv::fragment}}}},
        .state =
        {
           .vertex_input   = {{
                .bindings =
                {
                    //Geometry
                    {
                        .binding   = 0,
                        .stride    = std::size_t{3u} * sizeof(float), //sizeof(vec3)
                        .inputRate = VK_VERTEX_INPUT_RATE_VERTEX
                    },
                     //Instancing
                    {
                        .binding   = 1,
                        .stride    = std::size_t{4u} * std::size_t{4u} * sizeof(float), //sizeof(mat4x4)
                        .inputRate = VK_VERTEX_INPUT_RATE_INSTANCE
                    }
                },
                // See fubuki::test::resources::shader::vertex
                .attributes =
                {
                     // in_position
                    {
                          .location = 0,
                          .binding  = 0, //See above
                          .format   = VK_FORMAT_R32G32B32_SFLOAT,
                          .offset   = 0
                    },
                    // in_instance_transform (split by columns)
                    {
                          .location = 1,
                          .binding  = 1, //See above
                          .format   = VK_FORMAT_R32G32B32A32_SFLOAT,
                          .offset   = 0
                    },
                    {
                          .location = 2,
                          .binding  = 1,     //See above
                          .format   = VK_FORMAT_R32G32B32A32_SFLOAT,
                          .offset   = std::size_t{4u} * sizeof(float)
                    },
                    {
                          .location = 3,
                          .binding  = 1,     //See above
                          .format   = VK_FORMAT_R32G32B32A32_SFLOAT,
                          .offset   = std::size_t{2u} *  std::size_t{4u} * sizeof(float)
                    },
                    {
                          .location = 4,
                          .binding  = 1,     //See above
                          .format   = VK_FORMAT_R32G32B32A32_SFLOAT,
                          .offset   = std::size_t{3u} *  std::size_t{4u} * sizeof(float)
                    },
                }
            }},
            .input_assembly = {{.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN}},
            .viewport       = {{.viewports = {VkViewport{}}, .scissors = {VkRect2D{}}}},
            .rasterisation  = {state::rasterisation{}},
            .multisample    = {state::multisample{}},
            .depth_stencil  = {state::depth_stencil{}},
            .dynamic        = {{.states = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR}}},
        }
    };
    // clang-format on
}

} // namespace detail

TEST(graphics_pipeline, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(graphics_pipeline, ctor)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::graphics_pipeline. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        {
            const resource_raii rc{parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements()};
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
            const auto rc = resource_raii::make(parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements());
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(graphics_pipeline, external_handle)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::graphics_pipeline. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1{parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements()};
                const resource_raii rc2{{fuyu::take_ownership{rc1.handle()}}, rc1.cache(), rc1.info()};

                EXPECT_EQ(rc1.handle(), rc2.handle());
                EXPECT_EQ(rc1.info(), rc2.info());
                EXPECT_EQ(rc1.cache(), rc2.cache());
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
                const resource_raii rc1{parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements()};
                const resource_raii rc2{{fuyu::borrow{rc1.handle()}}, rc1.cache(), rc1.info()};

                EXPECT_EQ(rc1.handle(), rc2.handle());
                EXPECT_EQ(rc1.info(), rc2.info());
                EXPECT_EQ(rc1.cache(), rc2.cache());
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
                auto rc1 = resource_raii::make(parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::take_ownership{rc1->handle()}}, rc1->cache(), rc1->info());
                ASSERT_TRUE(rc2.has_value()) << "API call failed: " << rc2.error();

                EXPECT_EQ(rc1->handle(), rc2->handle());
                EXPECT_EQ(rc1->info(), rc2->info());
                EXPECT_EQ(rc1->cache(), rc2->cache());
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
                auto rc1 = resource_raii::make(parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements());
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{rc1->handle()}}, rc1->cache(), rc1->info());
                ASSERT_TRUE(rc2.has_value()) << "API call failed: " << rc2.error();

                EXPECT_EQ(rc1->handle(), rc2->handle());
                EXPECT_EQ(rc1->info(), rc2->info());
                EXPECT_EQ(rc1->cache(), rc2->cache());
                EXPECT_FALSE(rc2->owns());
                EXPECT_TRUE(rc2->borrows());
            }
            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }
    }
}

TEST(graphics_pipeline, view)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::graphics_pipeline. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();
        const resource_raii rc{parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements()};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
        EXPECT_EQ(view.cache, rc.cache());
        EXPECT_EQ(view.layout, rc.info().layout);
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(graphics_pipeline, rebind)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        resource_raii rc{parent_resources->cache, detail::resource_info(*parent_resources), detail::resource_complements()};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(graphics_pipeline, functions) { /*None yet*/ }

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
