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

#include <gtest/gtest.h>

#include <extension/khr_swapchain.hpp>
#include <fuyu/command/barrier.hpp>
#include <fuyu/command_buffer_array.hpp>
#include <fuyu/command_pool.hpp>
#include <fuyu/device.hpp>
#include <fuyu/semaphore.hpp>
#include <fuyu/swapchain.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

#if defined(VK_KHR_swapchain)

namespace
{

using namespace fubuki::test;

namespace fuyu = fubuki::fuyu;

using vk_handle = VkSwapchainKHR;
using vk_info   = VkSwapchainCreateInfoKHR;

using resource_handle = fubuki::swapchain_khr_handle;
using resource_raii   = fubuki::fuyu::swapchain;

namespace detail
{

using required_resources = resources_for_swapchain;

[[nodiscard]] std::expected<required_resources, fubuki::api_call_info> make_required_resources() noexcept
{
    return required_resources::make(context::instance(), context::device().physical_device());
}

[[nodiscard]] resource_raii::information resource_info(const required_resources& rc,
                                                       std::source_location      s = std::source_location::current()) noexcept
{
    return make_swapchain_info(rc, s);
}
[[nodiscard]] resource_raii::information resource_info(const fuyu::surface_properties& properties,
                                                       std::source_location            s = std::source_location::current()) noexcept
{
    return make_swapchain_info(properties, s);
}

} // namespace detail

TEST(swapchain, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(swapchain, ctor)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::graphics_pipeline. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        {
            const resource_raii rc{context::device(), parent_resources->surface, detail::resource_info(*parent_resources)};
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
            const auto rc = resource_raii::make(context::device(), parent_resources->surface, detail::resource_info(*parent_resources));
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
}

TEST(swapchain, external_handle)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1{context::device(), parent_resources->surface, detail::resource_info(*parent_resources)};
                const resource_raii rc2{{fuyu::take_ownership{rc1.handle()}}, rc1.device(), rc1.surface(), rc1.info()};

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
                const resource_raii rc1{context::device(), parent_resources->surface, detail::resource_info(*parent_resources)};
                const resource_raii rc2{{fuyu::borrow{rc1.handle()}}, rc1.device(), rc1.surface(), rc1.info()};

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
                auto rc1 = resource_raii::make(context::device(), parent_resources->surface, detail::resource_info(*parent_resources));
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::take_ownership{rc1->handle()}}, rc1->device(), rc1->surface(), rc1->info());
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
                auto rc1 = resource_raii::make(context::device(), parent_resources->surface, detail::resource_info(*parent_resources));
                ASSERT_TRUE(rc1.has_value()) << "API call failed: " << rc1.error();

                auto rc2 = resource_raii::make({fuyu::borrow{rc1->handle()}}, rc1->device(), rc1->surface(), rc1->info());
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

TEST(swapchain, view)
{
    auto parent_resources = detail::make_required_resources();

    ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:"
                                              << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

    const auto rc = resource_raii::make(context::device(), parent_resources->surface, detail::resource_info(*parent_resources));
    ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();

    const resource_raii::view view = *rc;

    EXPECT_EQ(view.handle, rc->handle());
    EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc->device()));
}

TEST(swapchain, rebind)
{
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_pack. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        resource_raii rc{context::device(), parent_resources->surface, detail::resource_info(*parent_resources)};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(swapchain, functions)
{
    using std::chrono_literals::operator""ns;

    // Recreate
    {
        auto parent_resources = detail::make_required_resources();

        ASSERT_TRUE(parent_resources.has_value()) << "Failed to create the required resources for fuyu::descriptor_set_layout. API call error:"
                                                  << parent_resources.error() << "\nValidation errors: " << print_and_clear_errors();

        auto rc = resource_raii::make(context::device(), parent_resources->surface, detail::resource_info(*parent_resources));
        ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();

        {
            const auto result = fuyu::recreate(*rc);
            EXPECT_TRUE(result.has_value()) << "API call failed: " << result.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }

    {
        const auto context_surface_properties = fuyu::properties(context::physical_device(), context::surface());

        ASSERT_TRUE(context_surface_properties.has_value()) << "API call failed: " << context_surface_properties.error();

        // Must be a separate resource to guarantee context::device().queues().presentable.front() can be used to present()
        auto rc = resource_raii::make(context::device(), context::surface(), detail::resource_info(*context_surface_properties));
        ASSERT_TRUE(rc.has_value()) << "API call failed: " << rc.error();

        std::optional<std::uint32_t> present_image_index = {};

        auto wait_semaphore = fuyu::semaphore::make(
            context::device(),
            {
        },
            fubuki::owning_pnext_chain{
                VkSemaphoreTypeCreateInfo{.sType = {}, .pNext = {}, .semaphoreType = VK_SEMAPHORE_TYPE_BINARY, .initialValue = 0}}
                .chain());
        ASSERT_TRUE(wait_semaphore.has_value()) << "API call failed: " << wait_semaphore.error();

        // Present, acquire next image
        {
            {
                using std::chrono_literals::operator""ns;

                const auto result = fuyu::acquire_next_image(*rc,
                                                             {
                                                                 .timeout   = 5000ns,
                                                                 .semaphore = *wait_semaphore,
                                                             });
                EXPECT_TRUE(result.has_value()) << "API call failed: " << result.error();
                present_image_index = *result;
            }

            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }

        ASSERT_TRUE(present_image_index.has_value()) << "acquire_next_image failed, cannot test present()";

        // Present
        if(present_image_index) // Redundant check for static analyser
        {
            ASSERT_TRUE(not context::device().queues().presentable.empty()) << "No presentable queue available.";

            const auto queue = context::device().queues().presentable.front();

            // Transition the image into the correct layout
            {
                const auto images = fuyu::images(*rc);
                ASSERT_TRUE(images.has_value()) << "API call failed: " << images.error();

                auto pool = fuyu::command_pool::make(context::device(), {.queue_family = queue.family});
                ASSERT_TRUE(pool.has_value()) << "API call failed:" << pool.error();
                auto command_buffers = fuyu::command_buffer_array::make(*pool, {.count = 1, .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY});
                ASSERT_TRUE(command_buffers.has_value()) << "API call failed:" << command_buffers.error();

                {
                    const auto record = fuyu::recorded_scope{command_buffers->front()};
                    ASSERT_TRUE(record.active()) << "Could not record scope";

                    fuyu::cmd::barrier(
                        command_buffers->front(),
                        fuyu::cmd::image_memory_barrier{
                            .source      = {.access_mask        = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
                                            .queue_family_index = queue.family,
                                            .layout             = VK_IMAGE_LAYOUT_UNDEFINED},
                            .destination = {.access_mask = {}, .queue_family_index = queue.family, .layout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR},
                            .target      = {.handle            = (*images)[*present_image_index],
                                            .subresource_range = {.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                                                                  .baseMipLevel   = 0,
                                                                  .levelCount     = 1,
                                                                  .baseArrayLayer = 0,
                                                                  .layerCount     = 1}}
                    },
                        fuyu::cmd::pipeline_barrier::stages{
                            .source      = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                            .destination = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                        });
                }

                const auto submit = fuyu::submit(context::device().queues().all.front(), command_buffers->front());
                ASSERT_TRUE(submit) << "API call failed: " << submit.error();

                const auto wait = fuyu::wait_idle(context::device().queues().all.front());
                ASSERT_TRUE(wait) << "API call failed: " << wait.error();
            }

            {
                const auto result = fuyu::present(queue, *rc, {.wait_semaphores = {*wait_semaphore}});
                EXPECT_TRUE(result.has_value()) << "API call failed: " << result.error();

                const auto wait_result = fuyu::wait_idle(queue);
                EXPECT_TRUE(wait_result) << "API call failed: " << wait_result.error();
            }

            EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
            EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
        }
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace

#endif // #if defined(VK_KHR_swapchain)

#undef STATIC_EXPECT_TRUE
