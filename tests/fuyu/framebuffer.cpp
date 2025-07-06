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
#include <fuyu/framebuffer.hpp>
#include <fuyu/image.hpp>
#include <fuyu/image_view.hpp>
#include <fuyu/memory.hpp>
#include <fuyu/memory_requirements.hpp>
#include <fuyu/render_pass.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;
namespace fuyu = fubuki::fuyu;

using vk_handle = VkFramebuffer;
using vk_info   = VkFramebufferCreateInfo;

using resource_handle = fubuki::framebuffer_handle;
using resource_raii   = fubuki::fuyu::framebuffer;

namespace detail
{

struct required_resources
{
    fuyu::image       image;
    fuyu::memory      memory;
    fuyu::image_view  image_view;
    fuyu::render_pass render_pass;
};

[[nodiscard]] std::expected<required_resources, fubuki::api_call_info> make_required_resources() noexcept
{
    auto image = fuyu::image::make(context::device(),
                                   {
                                       .flags          = {},
                                       .type           = VK_IMAGE_TYPE_2D,
                                       .format         = VK_FORMAT_R8G8B8A8_SNORM,
                                       .extent         = {256, 256, 1},
                                       .mip_levels     = 1,
                                       .array_layers   = 1,
                                       .samples        = VK_SAMPLE_COUNT_1_BIT,
                                       .tiling         = VK_IMAGE_TILING_OPTIMAL,
                                       .usage          = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                                       .sharing_mode   = {fuyu::sharing_mode::exclusive{}},
                                       .initial_layout = VK_IMAGE_LAYOUT_UNDEFINED,
    });

    if(not image)
    {
        return std::unexpected{image.error()};
    }

    auto memory = fuyu::memory::make(context::device(),
                                     {
                                         .requirements = fuyu::information::memory::make_requirements(fubuki::memory_requirements(*image)),
                                         .properties   = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                     });

    if(not memory)
    {
        return std::unexpected{memory.error()};
    }

    if(const auto bound = fuyu::bind(*image, *memory); not bound)
    {
        return std::unexpected{bound.error()};
    }

    auto image_view = fuyu::image_view::make(*image,
                                             {
                                                 .flags             = {},
                                                 .type              = VK_IMAGE_VIEW_TYPE_2D,
                                                 .format            = image->info().format,
                                                 .components        = {},
                                                 .subresource_range = {
                                                                       .aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                                                                       .baseMipLevel   = 0,
                                                                       .levelCount     = VK_REMAINING_MIP_LEVELS,
                                                                       .baseArrayLayer = 0,
                                                                       .layerCount     = VK_REMAINING_ARRAY_LAYERS,
                                                                       }
    });

    if(not image_view)
    {
        return std::unexpected{image_view.error()};
    }

    auto render_pass = fuyu::render_pass::make(
        context::device(),
        {
            .flags                  = {},
            .attachments            = {{.flags          = {},
                                        .format         = VK_FORMAT_R8G8B8A8_SNORM,
                                        .samples        = VK_SAMPLE_COUNT_1_BIT,
                                        .loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR,
                                        .storeOp        = VK_ATTACHMENT_STORE_OP_STORE,
                                        .stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_CLEAR,
                                        .stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE,
                                        .initialLayout  = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
                                        .finalLayout    = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL}},
            .subpasses              = {{
                             .flags       = {},
                             .bind_point  = VK_PIPELINE_BIND_POINT_GRAPHICS,
                             .attachments = {.input         = {},
                                             .colour        = {{.attachment = 0, .layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL}},
                                             .resolve       = {},
                                             .depth_stencil = {},
                                             .preserve      = {}},
            }},
            .subpasses_dependencies = {{
                .source           = {.subpass = fuyu::subpass::dependency::stage::external, .stage_mask = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT},
                .destination      = {.subpass = 0, .stage_mask = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT},
                .dependency_flags = {},
            }},
        });

    if(not render_pass)
    {
        return std::unexpected{render_pass.error()};
    }

    return required_resources{
        .image       = *std::move(image),
        .memory      = *std::move(memory),
        .image_view  = *std::move(image_view),
        .render_pass = *std::move(render_pass),
    };
}

[[nodiscard]] resource_raii::information resource_info(const required_resources& rc) noexcept
{
    return {
        .flags       = {},
        .attachments = {rc.image_view},
        .width       = rc.image.info().extent.width,
        .height      = rc.image.info().extent.height,
        .layers      = rc.image.info().array_layers,
    };
}

} // namespace detail

TEST(framebuffer, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(framebuffer, ctor)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::pipeline_layout. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        {
            const resource_raii rc{parent_resources->render_pass, detail::resource_info(*parent_resources)};
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
            const auto rc = resource_raii::make(parent_resources->render_pass, detail::resource_info(*parent_resources));
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(framebuffer, external_handle)
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
                resource_raii       rc1{parent_resources->render_pass, detail::resource_info(*parent_resources)};
                const resource_raii rc2{{fuyu::take_ownership{rc1.handle()}}, parent_resources->render_pass, rc1.info()};

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
                const resource_raii rc1{parent_resources->render_pass, detail::resource_info(*parent_resources)};
                const resource_raii rc2{{fuyu::borrow{rc1.handle()}}, parent_resources->render_pass, rc1.info()};

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
                auto rc1 = resource_raii::make(parent_resources->render_pass, detail::resource_info(*parent_resources));
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::take_ownership{rc1->handle()}}, parent_resources->render_pass, rc1->info());
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
                auto rc1 = resource_raii::make(parent_resources->render_pass, detail::resource_info(*parent_resources));
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{rc1->handle()}}, parent_resources->render_pass, rc1->info());
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

TEST(framebuffer, view)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::pipeline_layout. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        const resource_raii rc{parent_resources->render_pass, detail::resource_info(*parent_resources)};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(framebuffer, rebind)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        resource_raii rc{parent_resources->render_pass, detail::resource_info(*parent_resources)};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(framebuffer, functions) { /* None yet */ }

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
