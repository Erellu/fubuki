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

#ifndef FUBUKI_FUYU_INFORMATION_GRAPHICS_PIPELINE_HPP
#define FUBUKI_FUYU_INFORMATION_GRAPHICS_PIPELINE_HPP

#include <cstdint>
#include <functional>
#include <optional>
#include <string>

#include <core/collect.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/detail/graphics_pipeline_stage.hpp"
#include "fuyu/detail/graphics_pipeline_state.hpp"
#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/**
 * Information extending the information about graphics pipeline creation.
 */
template<detail::graphics_pipeline::traits::stages_extension stage_extension, detail::graphics_pipeline::traits::states_extension state_extension>
struct graphics_pipeline_extension
{
    using stages = stage_extension;
    using states = state_extension;

    stages stage = {}; ///< Chains extending each shader stage.
    states state = {}; ///< Chains extending each state.
};

/**
 * Information required to construct an instance of fuyu::graphics_pipeline.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkGraphicsPipelineCreateInfo.html
 *
 * @note Note that pipeline derivatives are not supported by fuyu::graphics_pipeline (nor by fuyu::compute_pipeline).
 * Pipelines derivatives are not widely supported by implementations, notably on mobile devices.
 *
 * Claim sources:
 * - https://stackoverflow.com/a/59312390/11910702
 * - https://developer.nvidia.com/blog/vulkan-dos-donts/
 * - https://developer.samsung.com/galaxy-gamedev/resources/articles/usage.html
 */
struct graphics_pipeline
{
    using underlying_type = VkGraphicsPipelineCreateInfo;

    using stages = detail::graphics_pipeline::stages;
    using states = detail::graphics_pipeline::states;

    /**
     * Informaton about the render pass the pipeline is used in.
     */
    struct render_pass
    {
        render_pass_handle handle  = {}; ///< The render pass this graphics_pipeline will be used in.
        std::uint32_t      subpass = {}; ///< The index of the subpass the pipeline will be used in.

        [[nodiscard]] friend constexpr bool operator==(const render_pass& a, const render_pass& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const render_pass& a, const render_pass& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const render_pass& a, const render_pass& b) noexcept = default;
    };

    /**
     * Additional information required upon construction, but not kept for the lifetime of the object.
     */
    struct complements
    {
        stages stage = {}; ///< The different stages of the pipeline.
        states state = {}; ///< The different states of the pipeline.

        [[nodiscard]] friend constexpr bool operator==(const complements& a, const complements& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const complements& a, const complements& b) noexcept = default;
    };

    template<detail::graphics_pipeline::traits::stages_extension stage_extension, detail::graphics_pipeline::traits::states_extension state_extension>
    using extension = graphics_pipeline_extension<stage_extension, state_extension>;

    VkPipelineCreateFlags      flags  = {}; ///< A bitmask of VkPipelineCreateFlagBits specifying how the pipeline will be generated.
    pipeline_layout_handle     layout = {}; ///< The layout describing the resources this pipeline has access to.
    std::optional<render_pass> pass   = {}; ///< The pass this pipeline will be used to.

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const graphics_pipeline& a, const graphics_pipeline& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const graphics_pipeline& a, const graphics_pipeline& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const graphics_pipeline>       info,
                                                                 std::reference_wrapper<const stages::underlying_type> underlying_stages,
                                                                 std::reference_wrapper<const states::underlying_type> underlying_states) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s      = info.get();
        const auto& stages = underlying_stages.get();
        const auto& states = underlying_states.get();

        return {
            .sType               = structure_type_v<VkGraphicsPipelineCreateInfo>,
            .pNext               = nullptr,
            .flags               = s.flags,
            .stageCount          = vk_size(stages.stages),
            .pStages             = stages.stages.data(),
            .pVertexInputState   = states.vertex_input.has_value() ? std::addressof(*states.vertex_input) : nullptr,
            .pInputAssemblyState = states.input_assembly.has_value() ? std::addressof(*states.input_assembly) : nullptr,
            .pTessellationState  = states.tesselation.has_value() ? std::addressof(*states.tesselation) : nullptr,
            .pViewportState      = states.viewport.has_value() ? std::addressof(*states.viewport) : nullptr,
            .pRasterizationState = states.rasterisation.has_value() ? std::addressof(*states.rasterisation) : nullptr,
            .pMultisampleState   = states.multisample.has_value() ? std::addressof(*states.multisample) : nullptr,
            .pDepthStencilState  = states.depth_stencil.has_value() ? std::addressof(*states.depth_stencil) : nullptr,
            .pColorBlendState    = states.colour_blend.has_value() ? std::addressof(*states.colour_blend) : nullptr,
            .pDynamicState       = states.dynamic.has_value() ? std::addressof(*states.dynamic) : nullptr,
            .layout              = s.layout.vk,
            .renderPass          = s.pass.has_value() ? s.pass->handle.vk : render_pass_handle{}.vk,
            .subpass             = s.pass.has_value() ? s.pass->subpass : 0,
            .basePipelineHandle  = {}, // Not supported
            .basePipelineIndex   = {}, // Not supported
        };
    }
};

//------------------------------------------------------------------------------
// Traits

namespace traits
{

template<typename...>
struct is_graphics_pipeline_extension : std::false_type
{
};

template<typename stage_extension, typename state_extension>
struct is_graphics_pipeline_extension<graphics_pipeline_extension<stage_extension, state_extension>> : std::true_type
{
};

template<typename T>
concept graphics_pipeline_extension = is_graphics_pipeline_extension<T>::value;

} // namespace traits

//------------------------------------------------------------------------------
// Deduction guides

graphics_pipeline_extension() -> graphics_pipeline_extension<
    detail::graphics_pipeline::stages_extension<pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>>,
    detail::graphics_pipeline::
        states_extension<pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>>>;

template<typename stage_vertex_pnext,
         typename stage_tesselation_control_pnext,
         typename stage_tessalation_evaluation_pnext,
         typename stage_geometry_pnext,
         typename stage_fragment_pnext,

         typename vertex_input_state_pnext,
         typename input_assembly_state_pnext,
         typename tesselation_state_pnext,
         typename viewport_state_pnext,
         typename rasterisation_state_pnext,
         typename multisample_state_pnext,
         typename colour_blend_state_pnext,
         typename dynamic_state_pnext>
graphics_pipeline_extension(detail::graphics_pipeline::stages_extension<stage_vertex_pnext,
                                                                        stage_tesselation_control_pnext,
                                                                        stage_tessalation_evaluation_pnext,
                                                                        stage_geometry_pnext,
                                                                        stage_fragment_pnext>,
                            detail::graphics_pipeline::states_extension<vertex_input_state_pnext,
                                                                        input_assembly_state_pnext,
                                                                        tesselation_state_pnext,
                                                                        viewport_state_pnext,
                                                                        rasterisation_state_pnext,
                                                                        multisample_state_pnext,
                                                                        colour_blend_state_pnext,
                                                                        dynamic_state_pnext>)
    -> graphics_pipeline_extension<detail::graphics_pipeline::stages_extension<stage_vertex_pnext,
                                                                               stage_tesselation_control_pnext,
                                                                               stage_tessalation_evaluation_pnext,
                                                                               stage_geometry_pnext,
                                                                               stage_fragment_pnext>,
                                   detail::graphics_pipeline::states_extension<vertex_input_state_pnext,
                                                                               input_assembly_state_pnext,
                                                                               tesselation_state_pnext,
                                                                               viewport_state_pnext,
                                                                               rasterisation_state_pnext,
                                                                               multisample_state_pnext,
                                                                               colour_blend_state_pnext,
                                                                               dynamic_state_pnext>>;

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_GRAPHICS_PIPELINE_HPP
