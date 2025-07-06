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
#include <fuyu/descriptor_pool.hpp>
#include <fuyu/device.hpp>
#include <fuyu/physical_device.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

using namespace fubuki::test;

using vk_handle = VkDescriptorPool;
using vk_info   = VkDescriptorPoolCreateInfo;

using resource_handle = fubuki::descriptor_pool_handle;
using resource_raii   = fubuki::fuyu::descriptor_pool;

namespace fuyu = fubuki::fuyu;

namespace detail
{

[[nodiscard]] auto resource_info(const fuyu::device& d) noexcept
{
    const fuyu::descriptor_pool_size size{

        .sampler                = 1,
        .combined_image_sampler = 1,
        .sampled_image          = 1,
        .storage_image          = 1,
        .uniform_texel_buffer   = 1,
        .storage_texel_buffer   = 1,
        .uniform_buffer         = 1,
        .storage_buffer         = 1,
        .dynamic_uniform_buffer = 1,
        .dynamic_storage_buffer = 1,
        .input_attachment       = 1,

#if defined(VK_VERSION_1_3)
        .inline_uniform_block = 0, // Requires extra information in the pnext chain. This is tested, but doesn't make sense to use that
#endif                             // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
        .acceleration_structure_khr = d.function().ext.khr_acceleration_structure ? 1u : 0u,
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
        .acceleration_structure_nv = d.function().ext.nv_ray_tracing ? 1u : 0u,
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
        .sample_weight_image_qcom = 0, // Likely to not be available
#endif                                 // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
        .block_match_image_qcom = 0, // Likely to not be available
#endif                               // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
        .mutable_ext = 0, // Feature not enabled in the context yet
#endif
    };

    return resource_raii::information{.flags = {}, .max_set = fuyu::descriptor_type::alternatives, .size = size, .callbacks = {}, .name = {}};
}

} // namespace detail

TEST(descriptor_pool, types)
{
    STATIC_EXPECT_TRUE((std::is_same_v<resource_handle::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<resource_raii::handle_type, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::underlying_type, vk_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::handle, resource_handle>) );
    STATIC_EXPECT_TRUE((std::is_same_v<fubuki::detail::handle_traits<resource_handle>::vk_info, vk_info>) );
}

TEST(descriptor_pool, ctor)
{
    // Throwing ctor
    try
    {
        {
            const resource_raii rc{context::device(), detail::resource_info(context::device())};
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }

#if defined(VK_VERSION_1_3)
    // Throwing ctor with chain
    try
    {
        {
            auto inline_uniform_block                          = fubuki::make<VkDescriptorPoolInlineUniformBlockCreateInfo>();
            inline_uniform_block.maxInlineUniformBlockBindings = 1;

            const resource_raii rc{context::device(), detail::resource_info(context::device()), fubuki::pnext_chain{inline_uniform_block}};
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
    catch(const fubuki::api_call_exception& error)
    {
        ADD_FAILURE() << "Failed to create object with the following error: " << error;
    }
#endif // defined(VK_VERSION_1_3)

    // Expected
    {
        {
            const auto rc = resource_raii::make(context::device(), detail::resource_info(context::device()));
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }
        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }

#if defined(VK_VERSION_1_3)
    // Expected with chain
    {
        {
            auto inline_uniform_block                          = fubuki::make<VkDescriptorPoolInlineUniformBlockCreateInfo>();
            inline_uniform_block.maxInlineUniformBlockBindings = 1;

            const auto rc
                = resource_raii::make(context::device(), detail::resource_info(context::device()), fubuki::pnext_chain{inline_uniform_block});
            EXPECT_TRUE(rc.has_value()) << "API call failed: " << rc.error();
        }

        EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
        EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
    }
#endif // defined(VK_VERSION_1_3)
}

TEST(descriptor_pool, external_handle)
{
    // Throwing ctor
    try
    {
        // Take ownership
        {
            {
                resource_raii       rc1{context::device(), detail::resource_info(context::device())};
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
                const resource_raii rc1{context::device(), detail::resource_info(context::device())};
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
                auto rc1 = resource_raii::make(context::device(), detail::resource_info(context::device()));
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
                auto rc1 = resource_raii::make(context::device(), detail::resource_info(context::device()));
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

TEST(descriptor_pool, view)
{
    {
        const resource_raii rc{context::device(), detail::resource_info(context::device())};

        const resource_raii::view view = rc;

        EXPECT_EQ(view.handle, rc.handle());
        EXPECT_EQ(std::addressof(view.device.get()), std::addressof(rc.device()));
    }

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(descriptor_pool, rebind)
{
    {
        resource_raii rc{context::device(), detail::resource_info(context::device())};

        ASSERT_TRUE(rc.rebind({context::device()}));
        ASSERT_TRUE(rebind(rc, {context::device()}));
    }
    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

TEST(descriptor_pool, functions)
{
    const resource_raii rc{context::device(), detail::resource_info(context::device())};

    EXPECT_TRUE(fuyu::reset(rc));

    EXPECT_TRUE(no_errors()) << "Following validation errors occured: " << print_and_clear_errors();
    EXPECT_TRUE(no_warnings()) << "Following validation warnings occured: " << print_and_clear_warnings();
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
