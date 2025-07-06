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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PIPELINE_RASTERIZATION_STATE_CREATE_INFO_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PIPELINE_RASTERIZATION_STATE_CREATE_INFO_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_0)

template<typename structure_type>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_EXT_conservative_rasterization)
template<>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationConservativeStateCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_conservative_rasterization)

    #if defined(VK_EXT_depth_clip_enable)
template<>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationDepthClipStateCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_clip_enable)

    #if defined(VK_EXT_transform_feedback)
template<>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateStreamCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_transform_feedback)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationLineStateCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_depth_bias_control)
template<>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, VkDepthBiasRepresentationInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_depth_bias_control)

    #if defined(VK_AMD_rasterization_order)
template<>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationStateRasterizationOrderAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_rasterization_order)

    #if defined(VK_EXT_provoking_vertex)
template<>
struct chain_validator<VkPipelineRasterizationStateCreateInfo, VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_provoking_vertex)

#endif // #if defined(VK_VERSION_1_0)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_PIPELINE_RASTERIZATION_STATE_CREATE_INFO_HPP
