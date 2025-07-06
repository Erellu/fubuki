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

#ifndef FUBUKI_FUYU_DETAIL_GRAPHICS_PIPELINE_STATE_HPP
#define FUBUKI_FUYU_DETAIL_GRAPHICS_PIPELINE_STATE_HPP

#include <algorithm>
#include <array>

#include <core/collect.hpp>
#include <core/compare/pipeline_color_blend_attachment_state.hpp>
#include <core/compare/rect2d.hpp>
#include <core/compare/stencil_op_state.hpp>
#include <core/compare/vertex_input_attribute_description.hpp>
#include <core/compare/vertex_input_binding_description.hpp>
#include <core/compare/viewport.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/vulkan.hpp>

#include "fuyu/sampling_rate.hpp"

namespace fubuki::fuyu::detail::graphics_pipeline
{

/// Description of the inputs of the vertex shader.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineVertexInputStateCreateInfo.html
struct vertex_input_state
{
    using underlying_type = VkPipelineVertexInputStateCreateInfo;

    VkPipelineVertexInputStateCreateFlags           flags      = {};
    small_vector<VkVertexInputBindingDescription>   bindings   = {};
    small_vector<VkVertexInputAttributeDescription> attributes = {};

    [[nodiscard]] friend constexpr bool operator==(const vertex_input_state& a, const vertex_input_state& b) noexcept
    {
        constexpr auto compare = []<typename U>(const U& x, const U& y) constexpr noexcept
        {
            using fubuki::operator==;
            return x == y;
        };

        return (a.flags == b.flags) and std::ranges::equal(a.bindings, b.bindings, compare)
            and std::ranges::equal(a.attributes, b.attributes, compare);
    }

    [[nodiscard]] friend constexpr bool operator!=(const vertex_input_state& a, const vertex_input_state& b) noexcept { return not(a == b); }

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {.sType                           = structure_type_v<underlying_type>,
                .pNext                           = nullptr,
                .flags                           = flags,
                .vertexBindingDescriptionCount   = vk_size(bindings),
                .pVertexBindingDescriptions      = bindings.data(),
                .vertexAttributeDescriptionCount = vk_size(attributes),
                .pVertexAttributeDescriptions    = attributes.data()};
    }
};

/// Indicates how the pipeline assembles the input.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineInputAssemblyStateCreateInfo.html
struct input_assembly_state
{
    using underlying_type = VkPipelineInputAssemblyStateCreateInfo;

    VkPipelineInputAssemblyStateCreateFlags flags                    = {};
    VkPrimitiveTopology                     topology                 = {};
    bool                                    primitive_restart_enable = {};

    [[nodiscard]] friend constexpr bool operator==(const input_assembly_state& a, const input_assembly_state& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const input_assembly_state& a, const input_assembly_state& b) noexcept = default;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType                  = structure_type_v<underlying_type>,
            .pNext                  = nullptr,
            .flags                  = flags,
            .topology               = topology,
            .primitiveRestartEnable = static_cast<VkBool32>(primitive_restart_enable),
        };
    }
};

/// Indicates how the tesselation stage is handle.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineTessellationStateCreateInfo.html
struct tesselation_state
{
    using underlying_type = VkPipelineTessellationStateCreateInfo;

    VkPipelineTessellationStateCreateFlags flags                = {};
    uint32_t                               patch_control_points = {};

    [[nodiscard]] friend constexpr bool operator==(const tesselation_state& a, const tesselation_state& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const tesselation_state& a, const tesselation_state& b) noexcept = default;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType              = structure_type_v<underlying_type>,
            .pNext              = nullptr,
            .flags              = flags,
            .patchControlPoints = patch_control_points,
        };
    }
};

/// Indicates how the viewport is handle.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineViewportStateCreateInfo.html
struct viewport_state
{
    using underlying_type = VkPipelineViewportStateCreateInfo;

    VkPipelineViewportStateCreateFlags flags     = {};
    small_vector<VkViewport>           viewports = {};
    small_vector<VkRect2D>             scissors  = {};

    [[nodiscard]] friend constexpr bool operator==(const viewport_state& a, const viewport_state& b) noexcept
    {
        constexpr auto compare = []<typename T>(const T& x, const T& y) constexpr noexcept
        {
            using fubuki::operator==;
            return x == y;
        };

        return (a.flags == b.flags) and (std::ranges::equal(a.viewports, b.viewports, compare))
            and (std::ranges::equal(a.scissors, b.scissors, compare));
    }

    [[nodiscard]] friend constexpr bool operator!=(const viewport_state& a, const viewport_state& b) noexcept { return not(a == b); }

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {.sType         = structure_type_v<underlying_type>,
                .pNext         = nullptr,
                .flags         = flags,
                .viewportCount = vk_size(viewports),
                .pViewports    = viewports.data(),
                .scissorCount  = vk_size(scissors),
                .pScissors     = scissors.data()};
    }
};

/// Indicates how rasterisation is handled in this pipeline.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineRasterizationStateCreateInfo.html
struct rasterisation_state
{
    using underlying_type = VkPipelineRasterizationStateCreateInfo;

    struct depth_bias_options
    {
        bool  enable          = {};
        float constant_factor = {};
        float clamp           = {};
        float slope_factor    = {};

        [[nodiscard]] friend constexpr bool operator==(const depth_bias_options& a, const depth_bias_options& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const depth_bias_options& a, const depth_bias_options& b) noexcept = default;
    };

    VkPipelineRasterizationStateCreateFlags flags              = {};
    bool                                    depth_clamp        = {};
    bool                                    rasterizer_discard = {};
    VkPolygonMode                           polygon_mode       = {};
    VkCullModeFlags                         cull_mode          = {};
    VkFrontFace                             front_face         = {};
    depth_bias_options                      depth_bias         = {};
    float                                   line_width         = 1.f;

    [[nodiscard]] friend constexpr bool operator==(const rasterisation_state& a, const rasterisation_state& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const rasterisation_state& a, const rasterisation_state& b) noexcept = default;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType                   = structure_type_v<underlying_type>,
            .pNext                   = nullptr,
            .flags                   = flags,
            .depthClampEnable        = static_cast<VkBool32>(depth_clamp),
            .rasterizerDiscardEnable = static_cast<VkBool32>(rasterizer_discard),
            .polygonMode             = polygon_mode,
            .cullMode                = cull_mode,
            .frontFace               = front_face,
            .depthBiasEnable         = depth_bias.enable,
            .depthBiasConstantFactor = depth_bias.constant_factor,
            .depthBiasClamp          = depth_bias.clamp,
            .depthBiasSlopeFactor    = depth_bias.slope_factor,
            .lineWidth               = line_width,
        };
    }
};

/// Indicates how multisampling is handled in this pipeline.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineMultisampleStateCreateInfo.html
struct multisample_state
{
    using underlying_type = VkPipelineMultisampleStateCreateInfo;

    struct shading
    {
        bool  enable = {};
        float min    = {};

        [[nodiscard]] friend constexpr bool operator==(const shading& a, const shading& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const shading& a, const shading& b) noexcept = default;
    };

    VkPipelineMultisampleStateCreateFlags flags             = {};
    sampling_rate::any                    samples           = {};
    shading                               sample_shading    = {};
    bool                                  alpha_to_coverage = {};
    bool                                  alpha_to_one      = {};

    [[nodiscard]] friend constexpr bool operator==(const multisample_state& a, const multisample_state& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const multisample_state& a, const multisample_state& b) noexcept = default;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        const auto visitor = [this]<typename variant>(const variant& sampling_variant) constexpr noexcept -> underlying_type
        {
            underlying_type result = {
                .sType                 = structure_type_v<underlying_type>,
                .pNext                 = nullptr,
                .flags                 = flags,
                .rasterizationSamples  = variant::vk,
                .sampleShadingEnable   = sample_shading.enable,
                .minSampleShading      = sample_shading.min,
                .pSampleMask           = nullptr,
                .alphaToCoverageEnable = static_cast<VkBool32>(alpha_to_coverage),
                .alphaToOneEnable      = static_cast<VkBool32>(alpha_to_one),
            };

            if constexpr(requires { sampling_variant.mask; })
            {
                result.pSampleMask = sampling_variant.mask.data();
            }

            return result;
        };

        return std::visit(visitor, samples);
    }
};

/// Indicates how depth and stencil buffers are handled in this pipeline.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineDepthStencilStateCreateInfo.html
struct depth_stencil_state
{
    using underlying_type = VkPipelineDepthStencilStateCreateInfo;

    struct bounds
    {
        bool  test = {};
        float min  = {};
        float max  = {};

        [[nodiscard]] friend constexpr bool operator==(const bounds& a, const bounds& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const bounds& a, const bounds& b) noexcept = default;
    };

    struct stencil_setup
    {
        bool             test  = {};
        VkStencilOpState front = {};
        VkStencilOpState back  = {};

        [[nodiscard]] friend constexpr bool operator==(const stencil_setup& a, const stencil_setup& b) noexcept
        {
            using fubuki::operator==;
            return (a.test == b.test) and (a.front == b.front) and (a.back == b.back);
        }

        [[nodiscard]] friend constexpr bool operator!=(const stencil_setup& a, const stencil_setup& b) noexcept { return not(a == b); }
    };

    VkPipelineDepthStencilStateCreateFlags flags        = {};
    bool                                   depth_test   = {};
    bool                                   depth_write  = {};
    VkCompareOp                            compare_op   = {};
    stencil_setup                          stencil      = {};
    bounds                                 depth_bounds = {};

    [[nodiscard]] friend constexpr bool operator==(const depth_stencil_state& a, const depth_stencil_state& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const depth_stencil_state& a, const depth_stencil_state& b) noexcept = delete;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType                 = structure_type_v<underlying_type>,
            .pNext                 = nullptr,
            .flags                 = flags,
            .depthTestEnable       = static_cast<VkBool32>(depth_test),
            .depthWriteEnable      = static_cast<VkBool32>(depth_write),
            .depthCompareOp        = compare_op,
            .depthBoundsTestEnable = static_cast<VkBool32>(depth_bounds.test),
            .stencilTestEnable     = static_cast<VkBool32>(stencil.test),
            .front                 = stencil.front,
            .back                  = stencil.back,
            .minDepthBounds        = depth_bounds.min,
            .maxDepthBounds        = depth_bounds.max,
        };
    }
};

/// Describes how blending occurs in a pipeline.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineColorBlendStateCreateInfo.html
struct colour_blend_state
{
    using attachment      = VkPipelineColorBlendAttachmentState;
    using underlying_type = VkPipelineColorBlendStateCreateInfo;

    struct blend_logic
    {
        bool      enable    = {};
        VkLogicOp operation = {};

        [[nodiscard]] friend constexpr bool operator==(const blend_logic& a, const blend_logic& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const blend_logic& a, const blend_logic& b) noexcept = default;
    };

    VkPipelineColorBlendStateCreateFlags flags           = {}; ///< A bitmask of VkPipelineColorBlendStateCreateFlagBits.
    blend_logic                          logic           = {}; ///< The logical operation to perform.
    small_vector<attachment>             attachments     = {}; ///< Information about how blending occurs for each colour attachment.
    std::array<float, 4>                 blend_constants = {}; ///< The blending constants.

    [[nodiscard]] friend constexpr bool operator==(const colour_blend_state& a, const colour_blend_state& b) noexcept
    {
        constexpr auto compare = [](const attachment& x, const attachment& y) constexpr noexcept
        {
            using fubuki::operator==;
            return x == y;
        };

        return (a.flags == b.flags) and (a.logic == b.logic) and std::ranges::equal(a.attachments, b.attachments, compare)
            and (a.blend_constants == b.blend_constants);
    }

    [[nodiscard]] friend constexpr bool operator!=(const colour_blend_state& a, const colour_blend_state& b) noexcept { return not(a == b); }

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType           = structure_type_v<underlying_type>,
            .pNext           = nullptr,
            .flags           = flags,
            .logicOpEnable   = static_cast<VkBool32>(logic.enable),
            .logicOp         = logic.operation,
            .attachmentCount = vk_size(attachments),
            .pAttachments    = attachments.data(),
            .blendConstants  = {blend_constants[0], blend_constants[1], blend_constants[2], blend_constants[3]}
        };
    }
};

/// Indicates the dynamic states of a pipeline.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineDynamicStateCreateInfo.html
struct dynamic_state
{
    using underlying_type = VkPipelineDynamicStateCreateInfo;

    VkPipelineDynamicStateCreateFlags flags  = {};
    small_vector<VkDynamicState>      states = {};

    [[nodiscard]] friend constexpr bool operator==(const dynamic_state& a, const dynamic_state& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const dynamic_state& a, const dynamic_state& b) noexcept = default;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType             = structure_type_v<underlying_type>,
            .pNext             = nullptr,
            .flags             = flags,
            .dynamicStateCount = vk_size(states),
            .pDynamicStates    = states.data(),
        };
    }
};

/// Describes how the pipeline handles its inputs at the various stages.
struct states
{
    struct underlying_type
    {
        std::optional<vertex_input_state::underlying_type>   vertex_input   = {};
        std::optional<input_assembly_state::underlying_type> input_assembly = {};
        std::optional<tesselation_state::underlying_type>    tesselation    = {};
        std::optional<viewport_state::underlying_type>       viewport       = {};
        std::optional<rasterisation_state::underlying_type>  rasterisation  = {};
        std::optional<multisample_state::underlying_type>    multisample    = {};
        std::optional<depth_stencil_state::underlying_type>  depth_stencil  = {};
        std::optional<colour_blend_state::underlying_type>   colour_blend   = {};
        std::optional<dynamic_state::underlying_type>        dynamic        = {};
    };

    std::optional<vertex_input_state>   vertex_input   = {}; ///< Description of the inputs of the vertex shader.
    std::optional<input_assembly_state> input_assembly = {}; ///< Description of the input assembly process.
    std::optional<tesselation_state>    tesselation    = {}; ///< Description of the tesselation process.
    std::optional<viewport_state>       viewport       = {}; ///< Description of the viewports.
    std::optional<rasterisation_state>  rasterisation  = {}; ///< Description of the rasterisation process.
    std::optional<multisample_state>    multisample    = {}; ///< Description of the multisampling process.
    std::optional<depth_stencil_state>  depth_stencil  = {}; ///< Description of how the pipeline interacts with the depth/stencil buffers
    std::optional<colour_blend_state>   colour_blend   = {}; ///< Description of the blending occurs.
    std::optional<dynamic_state>        dynamic        = {}; ///< Description of dynamic states of the pipeline.

    [[nodiscard]] friend constexpr bool operator==(const states& a, const states& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const states& a, const states& b) noexcept = default;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        constexpr auto to_underlying = []<typename U>(const std::optional<U>& v) constexpr noexcept -> std::optional<typename U::underlying_type>
        {
            if(not v.has_value())
            {
                return {};
            }

            return static_cast<typename U::underlying_type>(*v);
        };

        return {
            .vertex_input   = to_underlying(vertex_input),
            .input_assembly = to_underlying(input_assembly),
            .tesselation    = to_underlying(tesselation),
            .viewport       = to_underlying(viewport),
            .rasterisation  = to_underlying(rasterisation),
            .multisample    = to_underlying(multisample),
            .depth_stencil  = to_underlying(depth_stencil),
            .colour_blend   = to_underlying(colour_blend),
            .dynamic        = to_underlying(dynamic),
        };
    }
};

/// Describes additional information about the various states of a graphics pipeline, that is required upon construction but not kept for the lifetime
/// of the object.
template<fubuki::traits::pnext_chain::type vertex_input_state_pnext   = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type input_assembly_state_pnext = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type tesselation_state_pnext    = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type viewport_state_pnext       = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type rasterisation_state_pnext  = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type multisample_state_pnext    = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type colour_blend_state_pnext   = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type dynamic_state_pnext        = fubuki::pnext_chain<>>
struct states_extension
{
    vertex_input_state_pnext   vertex_input   = {}; ///< Chain extending VkPipelineVertexInputStateCreateInfo.
    input_assembly_state_pnext input_assembly = {}; ///< Chain extending VkPipelineInputAssemblyStateCreateInfo.
    tesselation_state_pnext    tesselation    = {}; ///< Chain extending VkPipelineTessellationStateCreateInfo.
    viewport_state_pnext       viewport       = {}; ///< Chain extending VkPipelineViewportStateCreateInfo.
    rasterisation_state_pnext  rasterisation  = {}; ///< Chain extending VkPipelineRasterizationStateCreateInfo.
    multisample_state_pnext    multisample    = {}; ///< Chain extending VkPipelineMultisampleStateCreateInfo.
    colour_blend_state_pnext   colour_blend   = {}; ///< Chain extending VkPipelineColorBlendStateCreateInfo.
    dynamic_state_pnext        dynamic        = {}; ///< Chain extending VkPipelineDynamicStateCreateInfo.
};

//------------------------------------------------------------------------------
// Traits

namespace traits
{

template<typename...>
struct is_states_extension;

template<typename...>
struct is_states_extension : std::false_type
{
};

template<typename vertex_input_state_pnext,
         typename input_assembly_state_pnext,
         typename tesselation_state_pnext,
         typename viewport_state_pnext,
         typename rasterisation_state_pnext,
         typename multisample_state_pnext,
         typename colour_blend_state_pnext,
         typename dynamic_state_pnext>
struct is_states_extension<states_extension<vertex_input_state_pnext,
                                            input_assembly_state_pnext,
                                            tesselation_state_pnext,
                                            viewport_state_pnext,
                                            rasterisation_state_pnext,
                                            multisample_state_pnext,
                                            colour_blend_state_pnext,
                                            dynamic_state_pnext>> : std::true_type
{
};

template<typename T>
concept states_extension = is_states_extension<T>::value;

} // namespace traits

//------------------------------------------------------------------------------
// Deduction guides

states_extension()
    -> states_extension<pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>>;

template<typename... vertex_input_state_pnext_elements,
         typename... input_assembly_state_pnext_elements,
         typename... tesselation_state_pnext_elements,
         typename... viewport_state_pnext_elements,
         typename... rasterisation_state_pnext_elements,
         typename... multisample_state_pnext_elements,
         typename... colour_blend_state_pnext_elements,
         typename... dynamic_state_pnext_elements>
states_extension(pnext_chain<vertex_input_state_pnext_elements...>,
                 pnext_chain<input_assembly_state_pnext_elements...>,
                 pnext_chain<tesselation_state_pnext_elements...>,
                 pnext_chain<viewport_state_pnext_elements...>,
                 pnext_chain<rasterisation_state_pnext_elements...>,
                 pnext_chain<multisample_state_pnext_elements...>,
                 pnext_chain<colour_blend_state_pnext_elements...>,
                 pnext_chain<dynamic_state_pnext_elements...>) -> states_extension<pnext_chain<vertex_input_state_pnext_elements...>,
                                                                                   pnext_chain<input_assembly_state_pnext_elements...>,
                                                                                   pnext_chain<tesselation_state_pnext_elements...>,
                                                                                   pnext_chain<viewport_state_pnext_elements...>,
                                                                                   pnext_chain<rasterisation_state_pnext_elements...>,
                                                                                   pnext_chain<multisample_state_pnext_elements...>,
                                                                                   pnext_chain<colour_blend_state_pnext_elements...>,
                                                                                   pnext_chain<dynamic_state_pnext_elements...>>;

//------------------------------------------------------------------------------
// Inline functions

template<traits::states_extension extension>
[[nodiscard]]
inline constexpr states::underlying_type to_underlying(const states&& s, const extension& ext) noexcept
    = delete; // Forbid temporaries

template<traits::states_extension extension>
[[nodiscard]]
inline constexpr states::underlying_type to_underlying(const states& s, const extension& ext) noexcept
{
    states::underlying_type result = s;

    if(result.vertex_input.has_value())
    {
        fubuki::extend(*result.vertex_input, ext.vertex_input);
    }

    if(result.input_assembly.has_value())
    {
        fubuki::extend(*result.input_assembly, ext.input_assembly);
    }

    if(result.tesselation.has_value())
    {
        fubuki::extend(*result.tesselation, ext.tesselation);
    }

    if(result.viewport.has_value())
    {
        fubuki::extend(*result.viewport, ext.viewport);
    }

    if(result.rasterisation.has_value())
    {
        fubuki::extend(*result.rasterisation, ext.rasterisation);
    }

    if(result.multisample.has_value())
    {
        fubuki::extend(*result.multisample, ext.multisample);
    }

    // Depth stencil state cannot be extended

    if(result.colour_blend.has_value())
    {
        fubuki::extend(*result.colour_blend, ext.colour_blend);
    }

    if(result.dynamic.has_value())
    {
        fubuki::extend(*result.dynamic, ext.dynamic);
    }

    return result;
}

[[nodiscard]]
constexpr states::underlying_type to_underlying(const states&& s) noexcept
    = delete; // Forbid temporaries

[[nodiscard]]
inline constexpr states::underlying_type to_underlying(const states& s) noexcept
{
    return s;
}

} // namespace fubuki::fuyu::detail::graphics_pipeline

#endif // FUBUKI_FUYU_DETAIL_GRAPHICS_PIPELINE_STATE_HPP
