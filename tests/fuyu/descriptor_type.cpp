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

#include <fuyu/detail/descriptor_pool_size.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

namespace fuyu = fubuki::fuyu;
namespace type = fuyu::detail::descriptor_type;

TEST(descriptor_type, aliases)
{
    STATIC_EXPECT_TRUE((std::is_same_v<type::ubo, type::uniform_buffer>) );
    STATIC_EXPECT_TRUE((std::is_same_v<type::ssbo, type::storage_buffer>) );

    STATIC_EXPECT_TRUE((std::is_same_v<type::dynamic_ubo, type::dynamic_uniform_buffer>) );
    STATIC_EXPECT_TRUE((std::is_same_v<type::dynamic_ssbo, type::dynamic_storage_buffer>) );
}

TEST(descriptor_type, id)
{
    STATIC_EXPECT_TRUE(type::sampler::id == VK_DESCRIPTOR_TYPE_SAMPLER);
    STATIC_EXPECT_TRUE(type::combined_image_sampler::id == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER);
    STATIC_EXPECT_TRUE(type::sampled_image::id == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE);
    STATIC_EXPECT_TRUE(type::storage_image::id == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE);
    STATIC_EXPECT_TRUE(type::uniform_texel_buffer::id == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER);
    STATIC_EXPECT_TRUE(type::storage_texel_buffer::id == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER);
    STATIC_EXPECT_TRUE(type::uniform_buffer::id == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER);
    STATIC_EXPECT_TRUE(type::storage_buffer::id == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
    STATIC_EXPECT_TRUE(type::dynamic_uniform_buffer::id == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC);
    STATIC_EXPECT_TRUE(type::dynamic_storage_buffer::id == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC);
    STATIC_EXPECT_TRUE(type::input_attachment::id == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT);

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE(type::inline_uniform_block::id == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK);
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE(type::acceleration_structure_khr::id == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR);
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE(type::acceleration_structure_nv::id == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV);
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
    STATIC_EXPECT_TRUE(type::sample_weight_image_qcom::id == VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM);
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    STATIC_EXPECT_TRUE(type::block_match_image_qcom::id == VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM);
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
    STATIC_EXPECT_TRUE(type::mutable_ext::id == VK_DESCRIPTOR_TYPE_MUTABLE_EXT);
#endif // defined(VK_EXT_mutable_descriptor_type)
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
