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

#include <gtest/gtest.h>

#include <core/compare/descriptor_pool_size.hpp>
#include <fuyu/detail/descriptor_pool_size.hpp>
#include <fuyu/information/descriptor_pool.hpp>

namespace
{

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace fuyu = fubuki::fuyu;

TEST(descriptor_pool_size, total)
{
    {
        constexpr fuyu::descriptor_pool_size size = {
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
            .inline_uniform_block = 1,
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
            .acceleration_structure_khr = 1,
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
            .acceleration_structure_nv = 1,
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
            .sample_weight_image_qcom = 1,
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
            .block_match_image_qcom = 1,
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
            .mutable_ext = 1,
#endif

#if defined(VK_NV_partitioned_acceleration_structure)
            .partitioned_acceleration_structure = 1,

#endif // defined(VK_EXT_mutable_descriptor_type)

        };

        STATIC_EXPECT_TRUE(size.total() == fuyu::descriptor_type::alternatives);
    }

    {
        constexpr fuyu::descriptor_pool_size size = {};
        STATIC_EXPECT_TRUE(size.total() == 0);
    }

    {
        fuyu::descriptor_pool_size size = {};
        EXPECT_EQ(size.total(), 0);
        size.input_attachment = 45;
        EXPECT_EQ(size.total(), 45);
    }
}

TEST(descriptor_pool_size, empty)
{
    {
        constexpr fuyu::descriptor_pool_size size = {};
        STATIC_EXPECT_TRUE(size.empty());
    }

    {
        constexpr fuyu::descriptor_pool_size size = {.uniform_buffer = 3};
        STATIC_EXPECT_TRUE(not size.empty());
    }

    {
        fuyu::descriptor_pool_size size = {};
        EXPECT_TRUE(size.empty());
        size.input_attachment = 45;
        EXPECT_FALSE(size.empty());
    }
}

// Overloads with VkDescriptorPoolSize are implicitly tested through descriptor_type_test
// because we test the conversion there
TEST(descriptor_pool_size, operator_plus)
{
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::sampler{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.sampler, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::combined_image_sampler{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.combined_image_sampler, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::sampled_image{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.sampled_image, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::storage_image{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.storage_image, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::uniform_texel_buffer{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.uniform_texel_buffer, 3);
    }
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::storage_texel_buffer{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.storage_texel_buffer, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::uniform_buffer{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.uniform_buffer, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::storage_buffer{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.storage_buffer, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::dynamic_ubo{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.dynamic_uniform_buffer, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::dynamic_ssbo{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.dynamic_storage_buffer, 3);
    }

    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::input_attachment{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.input_attachment, 3);
    }

#if defined(VK_VERSION_1_3)
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::inline_uniform_block{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.inline_uniform_block, 3);
    }
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::acceleration_structure_khr{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.acceleration_structure_khr, 3);
    }
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::acceleration_structure_nv{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.acceleration_structure_nv, 3);
    }
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::sample_weight_image_qcom{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.sample_weight_image_qcom, 3);
    }
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::block_match_image_qcom{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.block_match_image_qcom, 3);
    }
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
    {
        fuyu::descriptor_pool_size s = {};
        s += fuyu::descriptor_type::mutable_ext{.count = 3};

        EXPECT_EQ(s.total(), 3);
        EXPECT_FALSE(s.empty());
        EXPECT_EQ(s.mutable_ext, 3);
    }
#endif //  defined(VK_EXT_mutable_descriptor_type)
}

// Overloads with VkDescriptorPoolSize are implicitly tested through descriptor_type_test
// because we test the conversion there
TEST(descriptor_pool_size, operator_minus)
{
    {
        fuyu::descriptor_pool_size s = {.sampler = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.sampler, 4);

        s -= fuyu::descriptor_type::sampler{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.sampler, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.combined_image_sampler = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.combined_image_sampler, 4);

        s -= fuyu::descriptor_type::combined_image_sampler{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.combined_image_sampler, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.sampled_image = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.sampled_image, 4);

        s -= fuyu::descriptor_type::sampled_image{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.sampled_image, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.storage_image = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.storage_image, 4);

        s -= fuyu::descriptor_type::storage_image{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.storage_image, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.uniform_texel_buffer = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.uniform_texel_buffer, 4);

        s -= fuyu::descriptor_type::uniform_texel_buffer{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.uniform_texel_buffer, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.storage_texel_buffer = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.storage_texel_buffer, 4);

        s -= fuyu::descriptor_type::storage_texel_buffer{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.storage_texel_buffer, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.uniform_buffer = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.uniform_buffer, 4);

        s -= fuyu::descriptor_type::uniform_buffer{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.uniform_buffer, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.storage_buffer = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.storage_buffer, 4);

        s -= fuyu::descriptor_type::storage_buffer{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.storage_buffer, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.dynamic_uniform_buffer = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.dynamic_uniform_buffer, 4);

        s -= fuyu::descriptor_type::dynamic_ubo{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.dynamic_uniform_buffer, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.dynamic_storage_buffer = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.dynamic_storage_buffer, 4);

        s -= fuyu::descriptor_type::dynamic_ssbo{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.dynamic_storage_buffer, 1);
    }

    {
        fuyu::descriptor_pool_size s = {.input_attachment = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.input_attachment, 4);

        s -= fuyu::descriptor_type::input_attachment{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.input_attachment, 1);
    }

#if defined(VK_VERSION_1_3)
    {
        fuyu::descriptor_pool_size s = {.inline_uniform_block = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.inline_uniform_block, 4);

        s -= fuyu::descriptor_type::inline_uniform_block{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.inline_uniform_block, 1);
    }

#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
    {
        fuyu::descriptor_pool_size s = {.acceleration_structure_khr = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.acceleration_structure_khr, 4);

        s -= fuyu::descriptor_type::acceleration_structure_khr{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.acceleration_structure_khr, 1);
    }

#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    {
        fuyu::descriptor_pool_size s = {.acceleration_structure_nv = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.acceleration_structure_nv, 4);

        s -= fuyu::descriptor_type::acceleration_structure_nv{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.acceleration_structure_nv, 1);
    }

#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
    {
        fuyu::descriptor_pool_size s = {.sample_weight_image_qcom = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.sample_weight_image_qcom, 4);

        s -= fuyu::descriptor_type::sample_weight_image_qcom{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.sample_weight_image_qcom, 1);
    }

#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    {
        fuyu::descriptor_pool_size s = {.block_match_image_qcom = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.block_match_image_qcom, 4);

        s -= fuyu::descriptor_type::block_match_image_qcom{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.block_match_image_qcom, 1);
    }

#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
    {
        fuyu::descriptor_pool_size s = {.mutable_ext = 4};

        EXPECT_EQ(s.total(), 4);
        EXPECT_EQ(s.mutable_ext, 4);

        s -= fuyu::descriptor_type::mutable_ext{.count = 3};

        EXPECT_EQ(s.total(), 1);
        EXPECT_EQ(s.mutable_ext, 1);
    }

#endif //  defined(VK_EXT_mutable_descriptor_type)
}

TEST(descriptor_pool_size, from_range)
{
    {
        constexpr std::array range = {
            VkDescriptorPoolSize{.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, .descriptorCount = 4},
            VkDescriptorPoolSize{.type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, .descriptorCount = 2},
        };

        constexpr auto size = fuyu::descriptor_pool_size::from_range(range);

        STATIC_EXPECT_TRUE(size.total() == 6);
        STATIC_EXPECT_TRUE(size.uniform_buffer == 4);
        STATIC_EXPECT_TRUE(size.storage_buffer == 2);
    }

    // std::initializer_list
    {

        constexpr auto size = fuyu::descriptor_pool_size::from_range({
            VkDescriptorPoolSize{.type = VK_DESCRIPTOR_TYPE_SAMPLER,          .descriptorCount = 8},
            VkDescriptorPoolSize{.type = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, .descriptorCount = 3},
        });

        STATIC_EXPECT_TRUE(size.total() == 11);
        STATIC_EXPECT_TRUE(size.sampler == 8);
        STATIC_EXPECT_TRUE(size.input_attachment == 3);
    }
}

TEST(descriptor_pool_size, as_array)
{
    {
        constexpr auto array = as_array(fuyu::descriptor_pool_size{});

        STATIC_EXPECT_TRUE(array.size() == fuyu::descriptor_type::alternatives);
    }
}

TEST(descriptor_pool_size, pack)
{
    using fubuki::operator==;

    {
        constexpr fuyu::descriptor_pool_size s    = {.sampler = 1};
        constexpr auto                       pack = to_underlying(s);

        STATIC_EXPECT_TRUE(pack.size() == 1);
        STATIC_EXPECT_TRUE(pack[0] == VkDescriptorPoolSize(VK_DESCRIPTOR_TYPE_SAMPLER, 1));
    }

    {
        constexpr fuyu::descriptor_pool_size s    = {.sampler = 8, .uniform_buffer = 4};
        constexpr auto                       pack = to_underlying(s);

        STATIC_EXPECT_TRUE(pack.size() == 2);
        STATIC_EXPECT_TRUE(pack[0] == VkDescriptorPoolSize(VK_DESCRIPTOR_TYPE_SAMPLER, 8));
        STATIC_EXPECT_TRUE(pack[1] == VkDescriptorPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 4));
    }
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
