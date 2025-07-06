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

#ifndef FUBUKI_FUYU_INFORMATION_COMPUTE_PIPELINE_HPP
#define FUBUKI_FUYU_INFORMATION_COMPUTE_PIPELINE_HPP

#include <functional>
#include <optional>
#include <string>

#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "fuyu/detail/compute_pipeline_stage.hpp"
#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

template<detail::compute_pipeline::traits::stage_extension stage_ext>
struct compute_pipeline_extension
{
    using stages = stage_ext;

    stages stage = {};
};

/**
 * Information required to create an instance of fuyu::compute_pipeline.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkComputePipelineCreateInfo.html
 */
struct compute_pipeline
{
    using underlying_type = VkComputePipelineCreateInfo;

    /**
     * Additional information required upon construction, but not kept for the lifetime of the object.
     */
    struct complements
    {
        using stages = detail::compute_pipeline::stage;
        stages stage = {};
    };

    template<typename pnext>
    using extension = compute_pipeline_extension<pnext>;

    VkPipelineCreateFlags  flags  = {}; ///< A bitmask of VkPipelineCreateFlagBits specifying how the pipeline will be generated.
    pipeline_layout_handle layout = {}; ///< The layout describing the resources this pipeline has access to.

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const compute_pipeline& a, const compute_pipeline& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const compute_pipeline& a, const compute_pipeline& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const compute_pipeline>                     cref1,
                                                                 std::reference_wrapper<const complements::stages::underlying_type> cref2) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s1 = cref1.get();
        const auto& s2 = cref2.get();

        return {
            .sType              = structure_type_v<VkComputePipelineCreateInfo>,
            .pNext              = nullptr,
            .flags              = s1.flags,
            .stage              = s2.stage,
            .layout             = s1.layout.vk,
            .basePipelineHandle = {}, // Not supported
            .basePipelineIndex  = {}, // Not supported
        };
    }
};

//------------------------------------------------------------------------------
// Traits

namespace traits
{

template<typename...>
struct is_compute_pipeline_extension : std::false_type
{
};

template<typename stage_extension>
struct is_compute_pipeline_extension<compute_pipeline_extension<stage_extension>> : std::true_type
{
};

template<typename T>
concept compute_pipeline_extension = is_compute_pipeline_extension<T>::value;

} // namespace traits

//------------------------------------------------------------------------------
// Deduction guides

compute_pipeline_extension() -> compute_pipeline_extension<detail::compute_pipeline::stage_extension<pnext_chain<>>>;

template<typename... elements>
compute_pipeline_extension(detail::compute_pipeline::stage_extension<pnext_chain<elements...>>)
    -> compute_pipeline_extension<detail::compute_pipeline::stage_extension<pnext_chain<elements...>>>;

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_COMPUTE_PIPELINE_HPP
