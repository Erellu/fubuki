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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_IMAGE_CREATE_INFO_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_IMAGE_CREATE_INFO_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_0)

template<typename structure_type>
struct chain_validator<VkImageCreateInfo, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_NV_optical_flow)
template<>
struct chain_validator<VkImageCreateInfo, VkOpticalFlowImageFormatInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_optical_flow)

    #if defined(VK_KHR_video_queue)
template<>
struct chain_validator<VkImageCreateInfo, VkVideoProfileListInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_video_queue)

    #if defined(VK_EXT_descriptor_buffer)
template<>
struct chain_validator<VkImageCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_descriptor_buffer)

    #if defined(VK_QNX_external_memory_screen_buffer)
template<>
struct chain_validator<VkImageCreateInfo, VkExternalFormatQNX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkImageCreateInfo, VkImageFormatListCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkImageCreateInfo, VkExternalMemoryImageCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_image_drm_format_modifier)
template<>
struct chain_validator<VkImageCreateInfo, VkImageDrmFormatModifierListCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_EXT_metal_objects)
template<>
struct chain_validator<VkImageCreateInfo, VkImportMetalIOSurfaceInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_metal_objects)

    #if defined(VK_MESA_image_alignment_control)
template<>
struct chain_validator<VkImageCreateInfo, VkImageAlignmentControlCreateInfoMESA>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_MESA_image_alignment_control)

    #if defined(VK_NV_external_memory)
template<>
struct chain_validator<VkImageCreateInfo, VkExternalMemoryImageCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory)

    #if defined(VK_EXT_image_compression_control)
template<>
struct chain_validator<VkImageCreateInfo, VkImageCompressionControlEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_compression_control)

    #if defined(VK_EXT_metal_objects)
template<>
struct chain_validator<VkImageCreateInfo, VkImportMetalTextureInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_metal_objects)
template<>
struct chain_validator<VkImageCreateInfo, VkExportMetalObjectCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_image_drm_format_modifier)
template<>
struct chain_validator<VkImageCreateInfo, VkImageDrmFormatModifierExplicitCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_drm_format_modifier)

    #if defined(VK_FUCHSIA_buffer_collection)
template<>
struct chain_validator<VkImageCreateInfo, VkBufferCollectionImageCreateInfoFUCHSIA>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_NV_dedicated_allocation)
template<>
struct chain_validator<VkImageCreateInfo, VkDedicatedAllocationImageCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_dedicated_allocation)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct chain_validator<VkImageCreateInfo, VkExternalFormatANDROID>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkImageCreateInfo, VkImageStencilUsageCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_KHR_device_group)
template<>
struct chain_validator<VkImageCreateInfo, VkImageSwapchainCreateInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_device_group)

#endif // #if defined(VK_VERSION_1_0)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_IMAGE_CREATE_INFO_HPP
