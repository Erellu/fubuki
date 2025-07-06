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

#ifndef FUBUKI_TEST_FUYU_DESCRIPTOR_SET_RESOURCES_HPP
#define FUBUKI_TEST_FUYU_DESCRIPTOR_SET_RESOURCES_HPP

#include <core/validate.hpp>
#include <fuyu/descriptor_pool.hpp>
#include <fuyu/descriptor_set_layout.hpp>

namespace fubuki::test
{

/// Resources required across test needing descriptor sets layouts (pipeline_layout, descriptor_set_pack...)
struct resources_for_descriptor_set
{
    struct layouts
    {
        fuyu::descriptor_set_layout first;
        fuyu::descriptor_set_layout second;
        fuyu::descriptor_set_layout third;
    };

    fuyu::descriptor_pool pool;
    layouts               layout;

    [[nodiscard]] static std::expected<resources_for_descriptor_set, api_call_info> make(const fuyu::device& device) noexcept
    {
        auto pool = fuyu::descriptor_pool::make(
            device, {.flags = {},
                .max_set = fuyu::descriptor_type::alternatives,
                .size =
                {
                    .sampler        = 3,
                    .storage_image  = 3,
                    .uniform_buffer = 3,
                    .storage_buffer = 6,
                },
                .callbacks = {},
                .name = {}});

        if(not pool)
        {
            return std::unexpected{pool.error()};
        }

        namespace binding = fuyu::descriptor_binding;
        using any         = binding::any;

        const fuyu::descriptor_set_layout::information layout_info{
            .flags = {},
            // Bindings defined here are defined to match the shaders used in the tests involving pipelines (graphics_pipeline/compute_pipeline)
            // See resources::shader::spirv
            .bindings = {
                      any{binding ::uniform_buffer{.binding = 0, .count = 1, .stage_flags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_COMPUTE_BIT}},
                      any{binding ::storage_image{.binding = 1, .count = 1, .stage_flags = VK_SHADER_STAGE_COMPUTE_BIT}},
                      any{binding ::combined_image_sampler{.binding = 2, .count = 1, .stage_flags = VK_SHADER_STAGE_COMPUTE_BIT}},
                      any{binding ::storage_buffer{.binding = 3, .count = 1, .stage_flags = VK_SHADER_STAGE_COMPUTE_BIT}},
                      any{binding ::storage_buffer{.binding = 4, .count = 1, .stage_flags = VK_SHADER_STAGE_COMPUTE_BIT}},
                      }
        };

        auto first_set = fuyu::descriptor_set_layout::make(*pool, layout_info);

        if(not first_set)
        {
            return std::unexpected{first_set.error()};
        }

        auto second_set = fuyu::descriptor_set_layout::make(*pool, layout_info);

        if(not second_set)
        {
            return std::unexpected{second_set.error()};
        }

        auto third_set = fuyu::descriptor_set_layout::make(*pool, layout_info);

        if(not third_set)
        {
            return std::unexpected{third_set.error()};
        }

        return resources_for_descriptor_set
        {
                .pool   = *std::move(pool),
                .layout =
                {
                    .first  = *std::move(first_set),
                    .second = *std::move(second_set),
                    .third  = *std::move(third_set),
                },
        };
    }
};

} // namespace fubuki::test

#endif // FUBUKI_TEST_FUYU_DESCRIPTOR_SET_RESOURCES_HPP
