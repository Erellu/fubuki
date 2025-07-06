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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_COMMAND_BUFFER_INHERITANCE_INFO_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_COMMAND_BUFFER_INHERITANCE_INFO_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_0)

template<typename structure_type>
struct chain_validator<VkCommandBufferInheritanceInfo, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkExternalFormatANDROID>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_QCOM_render_pass_transform)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderPassTransformInfoQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_render_pass_transform)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkRenderingAttachmentLocationInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

    #if defined(VK_AMD_mixed_attachment_samples)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkAttachmentSampleCountInfoAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_mixed_attachment_samples)

    #if defined(VK_NVX_multiview_per_view_attributes)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkMultiviewPerViewAttributesInfoNVX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NVX_multiview_per_view_attributes)

    #if defined(VK_VERSION_1_3)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceRenderingInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_3)

    #if defined(VK_NV_inherited_viewport_scissor)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceViewportScissorInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_inherited_viewport_scissor)

    #if defined(VK_EXT_conditional_rendering)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkCommandBufferInheritanceConditionalRenderingInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_conditional_rendering)

    #if defined(VK_VERSION_1_4)
template<>
struct chain_validator<VkCommandBufferInheritanceInfo, VkRenderingInputAttachmentIndexInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_4)

#endif // #if defined(VK_VERSION_1_0)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_COMMAND_BUFFER_INHERITANCE_INFO_HPP
