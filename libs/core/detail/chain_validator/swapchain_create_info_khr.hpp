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

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_SWAPCHAIN_CREATE_INFO_KHR_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_SWAPCHAIN_CREATE_INFO_KHR_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_KHR_swapchain)

template<typename structure_type>
struct chain_validator<VkSwapchainCreateInfoKHR, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkImageFormatListCreateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_EXT_full_screen_exclusive)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveWin32InfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_NV_present_barrier)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSwapchainPresentBarrierCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_present_barrier)

    #if defined(VK_EXT_swapchain_maintenance1)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSwapchainPresentScalingCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_NV_low_latency2)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSwapchainLatencyCreateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_low_latency2)

    #if defined(VK_EXT_full_screen_exclusive)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSurfaceFullScreenExclusiveInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_full_screen_exclusive)

    #if defined(VK_EXT_swapchain_maintenance1)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSwapchainPresentModesCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_swapchain_maintenance1)

    #if defined(VK_EXT_display_control)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSwapchainCounterCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_display_control)

    #if defined(VK_EXT_image_compression_control)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkImageCompressionControlEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_image_compression_control)

    #if defined(VK_AMD_display_native_hdr)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkSwapchainDisplayNativeHdrCreateInfoAMD>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_AMD_display_native_hdr)

    #if defined(VK_KHR_device_group)
template<>
struct chain_validator<VkSwapchainCreateInfoKHR, VkDeviceGroupSwapchainCreateInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_device_group)

#endif // #if defined(VK_KHR_swapchain)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_SWAPCHAIN_CREATE_INFO_KHR_HPP
