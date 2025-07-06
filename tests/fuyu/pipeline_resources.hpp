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

#ifndef FUBUKI_TEST_FUYU_PIPELINE_RESOURCES_HPP
#define FUBUKI_TEST_FUYU_PIPELINE_RESOURCES_HPP

#include "descriptor_set_resources.hpp"

#include <fuyu/pipeline_cache.hpp>
#include <fuyu/pipeline_layout.hpp>

namespace fubuki::test
{

/// Resources required across test needing a pipeline (graphics_pipeline, compute_pipeline, ...)
struct resources_for_pipeline
{
    fuyu::pipeline_cache         cache;
    resources_for_descriptor_set descriptor;
    fuyu::pipeline_layout        layout;

    [[nodiscard]] static std::expected<resources_for_pipeline, fubuki::api_call_info> make(const fuyu::device& device) noexcept
    {
        auto cache = fuyu::pipeline_cache::make(device, {});

        if(not cache)
        {
            return std::unexpected{cache.error()};
        }

        auto descriptor = resources_for_descriptor_set::make(device);

        if(not descriptor)
        {
            return std::unexpected{descriptor.error()};
        }

        // clang-format off
        // For some reason, clang-format goes wild here
        auto layout = fuyu::pipeline_layout::make(device,
                                                  {
                                                      .flags = {},
                                                      .set_layouts = {descriptor->layout.first, descriptor->layout.second, descriptor->layout.third},
                                                      .push_constants = {}
                                                  });
        // clang-format on

        if(not layout)
        {
            return std::unexpected{layout.error()};
        }

        return resources_for_pipeline{.cache = *std::move(cache), .descriptor = *std::move(descriptor), .layout = *std::move(layout)};
    }
};

} // namespace fubuki::test

#endif // FUBUKI_TEST_FUYU_PIPELINE_RESOURCES_HPP
