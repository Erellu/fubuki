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

#include <gtest/gtest.h>

#include <core/collect.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp> // Get platform-specific handles

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

TEST(handle, handle_type)
{
    using namespace fubuki;

#ifdef VULKAN_CORE_H_
    STATIC_EXPECT_TRUE((std::is_same_v<VkBuffer, buffer_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkImage, image_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkInstance, instance_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkPhysicalDevice, physical_device_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkDevice, device_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkQueue, queue_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkSemaphore, semaphore_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkCommandBuffer, command_buffer_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkFence, fence_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkDeviceMemory, device_memory_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkEvent, event_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkQueryPool, query_pool_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkBufferView, buffer_view_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkImageView, image_view_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkShaderModule, shader_module_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkPipelineCache, pipeline_cache_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkPipelineLayout, pipeline_layout_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkPipeline, pipeline_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkRenderPass, render_pass_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkDescriptorSetLayout, descriptor_set_layout_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkSampler, sampler_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkDescriptorSet, descriptor_set_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkDescriptorPool, descriptor_pool_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkFramebuffer, framebuffer_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkCommandPool, command_pool_handle::underlying_type>) );

    #ifdef VK_VERSION_1_1
    STATIC_EXPECT_TRUE((std::is_same_v<VkSamplerYcbcrConversion, sampler_ycbcr_conversion_handle::underlying_type>) );
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    STATIC_EXPECT_TRUE((std::is_same_v<VkDescriptorUpdateTemplate, descriptor_update_template_handle::underlying_type>) );
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_3
    STATIC_EXPECT_TRUE((std::is_same_v<VkPrivateDataSlot, private_data_slot_handle::underlying_type>) );
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    STATIC_EXPECT_TRUE((std::is_same_v<VkSurfaceKHR, surface_khr_handle::underlying_type>) );
    #endif // VK_VERSION_1_3

    #ifdef VK_KHR_swapchain
    STATIC_EXPECT_TRUE((std::is_same_v<VkSwapchainKHR, swapchain_khr_handle::underlying_type>) );
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_display
    STATIC_EXPECT_TRUE((std::is_same_v<VkDisplayKHR, display_khr_handle::underlying_type>) );
    #endif // VK_KHR_display

    #ifdef VK_KHR_display
    STATIC_EXPECT_TRUE((std::is_same_v<VkDisplayModeKHR, display_mode_khr_handle::underlying_type>) );
    #endif // VK_KHR_display

    #ifdef VK_KHR_video_queue
    STATIC_EXPECT_TRUE((std::is_same_v<VkVideoSessionKHR, video_session_khr_handle::underlying_type>) );
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    STATIC_EXPECT_TRUE((std::is_same_v<VkVideoSessionParametersKHR, video_session_parameters_khr_handle::underlying_type>) );
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_deferred_host_operations
    STATIC_EXPECT_TRUE((std::is_same_v<VkDeferredOperationKHR, deferred_operation_khr_handle::underlying_type>) );
    #endif // VK_KHR_deferred_host_operations

    #ifdef VK_EXT_debug_report
    STATIC_EXPECT_TRUE((std::is_same_v<VkDebugReportCallbackEXT, debug_report_callback_ext_handle::underlying_type>) );
    #endif // VK_EXT_debug_report

    #ifdef VK_NVX_binary_import
    STATIC_EXPECT_TRUE((std::is_same_v<VkCuModuleNVX, cu_module_nvx_handle::underlying_type>) );
    #endif // VK_NVX_binary_import

    #ifdef VK_NVX_binary_import
    STATIC_EXPECT_TRUE((std::is_same_v<VkCuFunctionNVX, cu_function_nvx_handle::underlying_type>) );
    #endif // VK_NVX_binary_import

    #ifdef VK_EXT_debug_utils
    STATIC_EXPECT_TRUE((std::is_same_v<VkDebugUtilsMessengerEXT, debug_utils_messenger_ext_handle::underlying_type>) );
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_validation_cache
    STATIC_EXPECT_TRUE((std::is_same_v<VkValidationCacheEXT, validation_cache_ext_handle::underlying_type>) );
    #endif // VK_EXT_validation_cache

    #ifdef VK_NV_ray_tracing
    STATIC_EXPECT_TRUE((std::is_same_v<VkAccelerationStructureNV, acceleration_structure_nv_handle::underlying_type>) );
    #endif // VK_NV_ray_tracing

    #ifdef VK_INTEL_performance_query
    STATIC_EXPECT_TRUE((std::is_same_v<VkPerformanceConfigurationINTEL, performance_configuration_intel_handle::underlying_type>) );
    #endif // VK_INTEL_performance_query

    #ifdef VK_NV_device_generated_commands
    STATIC_EXPECT_TRUE((std::is_same_v<VkIndirectCommandsLayoutNV, indirect_commands_layout_nv_handle::underlying_type>) );
    #endif // VK_NV_device_generated_commands

    #ifdef VK_EXT_descriptor_buffer
    STATIC_EXPECT_TRUE((std::is_same_v<VkAccelerationStructureKHR, acceleration_structure_khr_handle::underlying_type>) );
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_opacity_micromap
    STATIC_EXPECT_TRUE((std::is_same_v<VkMicromapEXT, micromap_ext_handle::underlying_type>) );
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_NV_optical_flow
    STATIC_EXPECT_TRUE((std::is_same_v<VkOpticalFlowSessionNV, optical_flow_session_nv_handle::underlying_type>) );
    #endif // VK_NV_optical_flow

#endif // #ifdef VULKAN_CORE_H_

#ifdef VULKAN_ANDROID_H_

#endif // #ifdef VULKAN_ANDROID_H_

#ifdef VULKAN_FUCHSIA_H_

    #ifdef VK_FUCHSIA_buffer_collection
    STATIC_EXPECT_TRUE((std::is_same_v<VkBufferCollectionFUCHSIA, buffer_collection_fuchsia_handle::underlying_type>) );
    #endif // VK_FUCHSIA_buffer_collection

#endif // #ifdef VULKAN_FUCHSIA_H_

#ifdef VULKAN_IOS_H_

#endif // #ifdef VULKAN_IOS_H_

#ifdef VULKAN_MACOS_H_

#endif // #ifdef VULKAN_MACOS_H_

#ifdef VULKAN_METAL_H_

#endif // #ifdef VULKAN_METAL_H_

#ifdef VULKAN_VI_H_

#endif // #ifdef VULKAN_VI_H_

#ifdef VULKAN_WAYLAND_H_

#endif // #ifdef VULKAN_WAYLAND_H_

#ifdef VULKAN_WIN32_H_

#endif // #ifdef VULKAN_WIN32_H_

#ifdef VULKAN_XCB_H_

#endif // #ifdef VULKAN_XCB_H_

#ifdef VULKAN_XLIB_H_

#endif // #ifdef VULKAN_XLIB_H_

#ifdef VULKAN_DIRECTFB_H_

#endif // #ifdef VULKAN_DIRECTFB_H_

#ifdef VULKAN_XLIB_XRANDR_H_

#endif // #ifdef VULKAN_XLIB_XRANDR_H_

#ifdef VULKAN_GGP_H_

#endif // #ifdef VULKAN_GGP_H_

#ifdef VULKAN_SCREEN_H_

#endif // #ifdef VULKAN_SCREEN_H_

#if 1 // VULKAN_BETA_H_ // NOLINT(readability-avoid-unconditional-preprocessor-if)

#endif // #if 1 // VULKAN_BETA_H_

    // Manual handles
    STATIC_EXPECT_TRUE((std::is_same_v<VkPipeline, graphics_pipeline_handle::underlying_type>) );
    STATIC_EXPECT_TRUE((std::is_same_v<VkPipeline, compute_pipeline_handle::underlying_type>) );
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
