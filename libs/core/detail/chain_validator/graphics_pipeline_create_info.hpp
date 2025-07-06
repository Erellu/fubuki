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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_GRAPHICS_PIPELINE_CREATE_INFO_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_GRAPHICS_PIPELINE_CREATE_INFO_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_0)

template<typename structure_type>
struct chain_validator<VkGraphicsPipelineCreateInfo, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_KHR_pipeline_binary)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineBinaryInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_binary)

    #if defined(VK_AMD_pipeline_compiler_control)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineCompilerControlCreateInfoAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_pipeline_compiler_control)

    #if defined(VK_NV_representative_fragment_test)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineRepresentativeFragmentTestStateCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_representative_fragment_test)

    #if defined(VK_NVX_multiview_per_view_attributes)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkMultiviewPerViewAttributesInfoNVX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_KHR_fragment_shading_rate)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateStateCreateInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_fragment_shading_rate)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineCreationFeedbackCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_AMD_mixed_attachment_samples)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkAttachmentSampleCountInfoAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_EXT_discard_rectangles)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineDiscardRectangleStateCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_discard_rectangles)

    #if defined(VK_NV_device_generated_commands)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineShaderGroupsCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_device_generated_commands)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineRenderingCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineRobustnessCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkRenderingAttachmentLocationInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_EXT_graphics_pipeline_library)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkGraphicsPipelineLibraryCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_graphics_pipeline_library)

    #if defined(VKSC_VERSION_1_0)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineOfflineCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VKSC_VERSION_1_0)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkExternalFormatANDROID>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_NV_fragment_shading_rate_enums)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineFragmentShadingRateEnumStateCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_fragment_shading_rate_enums)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineCreateFlags2CreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkRenderingInputAttachmentIndexInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_KHR_pipeline_library)
template<>
struct chain_validator<VkGraphicsPipelineCreateInfo, VkPipelineLibraryCreateInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_pipeline_library)

#endif // #if defined(VK_VERSION_1_0)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_GRAPHICS_PIPELINE_CREATE_INFO_HPP
