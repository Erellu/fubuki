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

#include "extension/functions/khr_swapchain.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
khr_swapchain khr_swapchain::load([[maybe_unused]] instance_handle instance,
                    [[maybe_unused]] version_number  vk_version,
                    [[maybe_unused]] device_handle   device) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be nullptr.");
    fubuki_assert(device != null_handle, "Device cannot be nullptr.");

    [[maybe_unused]] auto* const device_get = pfn<"vkGetDeviceProcAddr">(instance);

    fubuki_assert(device_get != nullptr, "Could not retrieve vkGetDeviceProcAddr function pointer.");

           // clang-format off
    khr_swapchain f
        {
#if defined(VK_KHR_swapchain)
            .acquire_next_image_khr   = pfn<"vkAcquireNextImageKHR"  >(instance, device, device_get),
            .create_swapchain_khr     = pfn<"vkCreateSwapchainKHR"   >(instance, device, device_get),
            .destroy_swapchain_khr    = pfn<"vkDestroySwapchainKHR"  >(instance, device, device_get),
            .get_swapchain_images_khr = pfn<"vkGetSwapchainImagesKHR">(instance, device, device_get),
            .queue_present_khr        = pfn<"vkQueuePresentKHR"      >(instance, device, device_get),
    #if defined(VK_VERSION_1_1)
            .vk11 =
            {
                // Filled afterwards if needed
            }
    #endif // defined(VK_VERSION_1_1)
#endif     // defined(VK_KHR_swapchain)
        };
    // clang-format on

#if defined(VK_VERSION_1_1) and defined(VK_KHR_swapchain)
    // clang-format off
    if(vk_version >= version_number{1, 1, 0})
    {
        f.vk11 =
            {
                .acquire_next_image2_khr                    = pfn<"vkAcquireNextImage2KHR"                 >(instance, device, device_get),
                .get_device_group_present_capabilities_khr  = pfn<"vkGetDeviceGroupPresentCapabilitiesKHR" >(instance, device, device_get),
                .get_device_group_surface_present_modes_khr = pfn<"vkGetDeviceGroupSurfacePresentModesKHR" >(instance, device, device_get),
                .get_physical_device_present_rectangles_khr = pfn<"vkGetPhysicalDevicePresentRectanglesKHR">(instance), // This one is instance-level
            };
    }
    // clang-format on
#endif // defined(VK_VERSION_1_1) and defined(VK_KHR_swapchain)

    return f;
}

} // namespace fubuki::extension::functions
