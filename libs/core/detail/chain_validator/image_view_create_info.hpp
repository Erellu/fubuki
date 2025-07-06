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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_IMAGE_VIEW_CREATE_INFO_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_IMAGE_VIEW_CREATE_INFO_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_0)

template<typename structure_type>
struct chain_validator<VkImageViewCreateInfo, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_EXT_image_sliced_view_of_3d)
template<>
struct chain_validator<VkImageViewCreateInfo, VkImageViewSlicedCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_sliced_view_of_3d)

    #if defined(VK_EXT_metal_objects)
template<>
struct chain_validator<VkImageViewCreateInfo, VkExportMetalObjectCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_image_view_min_lod)
template<>
struct chain_validator<VkImageViewCreateInfo, VkImageViewMinLodCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_view_min_lod)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkImageViewCreateInfo, VkImageViewUsageCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_QCOM_image_processing)
template<>
struct chain_validator<VkImageViewCreateInfo, VkImageViewSampleWeightCreateInfoQCOM>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QCOM_image_processing)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkImageViewCreateInfo, VkSamplerYcbcrConversionInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_EXT_astc_decode_mode)
template<>
struct chain_validator<VkImageViewCreateInfo, VkImageViewASTCDecodeModeEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_astc_decode_mode)

    #if defined(VK_EXT_descriptor_buffer)
template<>
struct chain_validator<VkImageViewCreateInfo, VkOpaqueCaptureDescriptorDataCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_descriptor_buffer)

#endif // #if defined(VK_VERSION_1_0)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_IMAGE_VIEW_CREATE_INFO_HPP
