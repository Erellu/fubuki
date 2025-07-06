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

#include <type_traits>

#include <gtest/gtest.h>

#include <core/pfn.hpp>
#include <core/vulkan.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 4883)
#endif

namespace
{

TEST(pfn, types)
{
    using fubuki::compile_time_hash;

#define DO_PFN_TEST(pfn_name)                                                                 \
    do                                                                                        \
    {                                                                                         \
        using expected_pfn_t = PFN_##pfn_name;                                                \
                                                                                              \
        using traits = fubuki::detail::traits::vk_function<compile_time_hash(#pfn_name)>;     \
                                                                                              \
        using from_pfn_device   = std::decay_t<decltype(fubuki::pfn<#pfn_name>({}, {}, {}))>; \
        using from_pfn_instance = std::decay_t<decltype(fubuki::pfn<#pfn_name>({}))>;         \
                                                                                              \
        STATIC_EXPECT_TRUE((std::is_same_v<typename traits::type, expected_pfn_t>) );         \
        STATIC_EXPECT_TRUE((std::is_same_v<expected_pfn_t, from_pfn_device>) );               \
        STATIC_EXPECT_TRUE((std::is_same_v<expected_pfn_t, from_pfn_instance>) );             \
    }                                                                                         \
    while(false)

#ifdef VULKAN_CORE_H_
    DO_PFN_TEST(vkCreateInstance);
    DO_PFN_TEST(vkDestroyInstance);
    DO_PFN_TEST(vkEnumeratePhysicalDevices);
    DO_PFN_TEST(vkGetPhysicalDeviceFeatures);
    DO_PFN_TEST(vkGetPhysicalDeviceFormatProperties);
    DO_PFN_TEST(vkGetPhysicalDeviceImageFormatProperties);
    DO_PFN_TEST(vkGetPhysicalDeviceProperties);
    DO_PFN_TEST(vkGetPhysicalDeviceQueueFamilyProperties);
    DO_PFN_TEST(vkGetPhysicalDeviceMemoryProperties);
    DO_PFN_TEST(vkGetInstanceProcAddr);
    DO_PFN_TEST(vkGetDeviceProcAddr);
    DO_PFN_TEST(vkCreateDevice);
    DO_PFN_TEST(vkDestroyDevice);
    DO_PFN_TEST(vkEnumerateInstanceExtensionProperties);
    DO_PFN_TEST(vkEnumerateDeviceExtensionProperties);
    DO_PFN_TEST(vkEnumerateInstanceLayerProperties);
    DO_PFN_TEST(vkEnumerateDeviceLayerProperties);
    DO_PFN_TEST(vkGetDeviceQueue);
    DO_PFN_TEST(vkQueueSubmit);
    DO_PFN_TEST(vkQueueWaitIdle);
    DO_PFN_TEST(vkDeviceWaitIdle);
    DO_PFN_TEST(vkAllocateMemory);
    DO_PFN_TEST(vkFreeMemory);
    DO_PFN_TEST(vkMapMemory);
    DO_PFN_TEST(vkUnmapMemory);
    DO_PFN_TEST(vkFlushMappedMemoryRanges);
    DO_PFN_TEST(vkInvalidateMappedMemoryRanges);
    DO_PFN_TEST(vkGetDeviceMemoryCommitment);
    DO_PFN_TEST(vkBindBufferMemory);
    DO_PFN_TEST(vkBindImageMemory);
    DO_PFN_TEST(vkGetBufferMemoryRequirements);
    DO_PFN_TEST(vkGetImageMemoryRequirements);
    DO_PFN_TEST(vkGetImageSparseMemoryRequirements);
    DO_PFN_TEST(vkGetPhysicalDeviceSparseImageFormatProperties);
    DO_PFN_TEST(vkQueueBindSparse);
    DO_PFN_TEST(vkCreateFence);
    DO_PFN_TEST(vkDestroyFence);
    DO_PFN_TEST(vkResetFences);
    DO_PFN_TEST(vkGetFenceStatus);
    DO_PFN_TEST(vkWaitForFences);
    DO_PFN_TEST(vkCreateSemaphore);
    DO_PFN_TEST(vkDestroySemaphore);
    DO_PFN_TEST(vkCreateEvent);
    DO_PFN_TEST(vkDestroyEvent);
    DO_PFN_TEST(vkGetEventStatus);
    DO_PFN_TEST(vkSetEvent);
    DO_PFN_TEST(vkResetEvent);
    DO_PFN_TEST(vkCreateQueryPool);
    DO_PFN_TEST(vkDestroyQueryPool);
    DO_PFN_TEST(vkGetQueryPoolResults);
    DO_PFN_TEST(vkCreateBuffer);
    DO_PFN_TEST(vkDestroyBuffer);
    DO_PFN_TEST(vkCreateBufferView);
    DO_PFN_TEST(vkDestroyBufferView);
    DO_PFN_TEST(vkCreateImage);
    DO_PFN_TEST(vkDestroyImage);
    DO_PFN_TEST(vkGetImageSubresourceLayout);
    DO_PFN_TEST(vkCreateImageView);
    DO_PFN_TEST(vkDestroyImageView);
    DO_PFN_TEST(vkCreateShaderModule);
    DO_PFN_TEST(vkDestroyShaderModule);
    DO_PFN_TEST(vkCreatePipelineCache);
    DO_PFN_TEST(vkDestroyPipelineCache);
    DO_PFN_TEST(vkGetPipelineCacheData);
    DO_PFN_TEST(vkMergePipelineCaches);
    DO_PFN_TEST(vkCreateGraphicsPipelines);
    DO_PFN_TEST(vkCreateComputePipelines);
    DO_PFN_TEST(vkDestroyPipeline);
    DO_PFN_TEST(vkCreatePipelineLayout);
    DO_PFN_TEST(vkDestroyPipelineLayout);
    DO_PFN_TEST(vkCreateSampler);
    DO_PFN_TEST(vkDestroySampler);
    DO_PFN_TEST(vkCreateDescriptorSetLayout);
    DO_PFN_TEST(vkDestroyDescriptorSetLayout);
    DO_PFN_TEST(vkCreateDescriptorPool);
    DO_PFN_TEST(vkDestroyDescriptorPool);
    DO_PFN_TEST(vkResetDescriptorPool);
    DO_PFN_TEST(vkAllocateDescriptorSets);
    DO_PFN_TEST(vkFreeDescriptorSets);
    DO_PFN_TEST(vkUpdateDescriptorSets);
    DO_PFN_TEST(vkCreateFramebuffer);
    DO_PFN_TEST(vkDestroyFramebuffer);
    DO_PFN_TEST(vkCreateRenderPass);
    DO_PFN_TEST(vkDestroyRenderPass);
    DO_PFN_TEST(vkGetRenderAreaGranularity);
    DO_PFN_TEST(vkCreateCommandPool);
    DO_PFN_TEST(vkDestroyCommandPool);
    DO_PFN_TEST(vkResetCommandPool);
    DO_PFN_TEST(vkAllocateCommandBuffers);
    DO_PFN_TEST(vkFreeCommandBuffers);
    DO_PFN_TEST(vkBeginCommandBuffer);
    DO_PFN_TEST(vkEndCommandBuffer);
    DO_PFN_TEST(vkResetCommandBuffer);
    DO_PFN_TEST(vkCmdBindPipeline);
    DO_PFN_TEST(vkCmdSetViewport);
    DO_PFN_TEST(vkCmdSetScissor);
    DO_PFN_TEST(vkCmdSetLineWidth);
    DO_PFN_TEST(vkCmdSetDepthBias);
    DO_PFN_TEST(vkCmdSetBlendConstants);
    DO_PFN_TEST(vkCmdSetDepthBounds);
    DO_PFN_TEST(vkCmdSetStencilCompareMask);
    DO_PFN_TEST(vkCmdSetStencilWriteMask);
    DO_PFN_TEST(vkCmdSetStencilReference);
    DO_PFN_TEST(vkCmdBindDescriptorSets);
    DO_PFN_TEST(vkCmdBindIndexBuffer);
    DO_PFN_TEST(vkCmdBindVertexBuffers);
    DO_PFN_TEST(vkCmdDraw);
    DO_PFN_TEST(vkCmdDrawIndexed);
    DO_PFN_TEST(vkCmdDrawIndirect);
    DO_PFN_TEST(vkCmdDrawIndexedIndirect);
    DO_PFN_TEST(vkCmdDispatch);
    DO_PFN_TEST(vkCmdDispatchIndirect);
    DO_PFN_TEST(vkCmdCopyBuffer);
    DO_PFN_TEST(vkCmdCopyImage);
    DO_PFN_TEST(vkCmdBlitImage);
    DO_PFN_TEST(vkCmdCopyBufferToImage);
    DO_PFN_TEST(vkCmdCopyImageToBuffer);
    DO_PFN_TEST(vkCmdUpdateBuffer);
    DO_PFN_TEST(vkCmdFillBuffer);
    DO_PFN_TEST(vkCmdClearColorImage);
    DO_PFN_TEST(vkCmdClearDepthStencilImage);
    DO_PFN_TEST(vkCmdClearAttachments);
    DO_PFN_TEST(vkCmdResolveImage);
    DO_PFN_TEST(vkCmdSetEvent);
    DO_PFN_TEST(vkCmdResetEvent);
    DO_PFN_TEST(vkCmdWaitEvents);
    DO_PFN_TEST(vkCmdPipelineBarrier);
    DO_PFN_TEST(vkCmdBeginQuery);
    DO_PFN_TEST(vkCmdEndQuery);
    DO_PFN_TEST(vkCmdResetQueryPool);
    DO_PFN_TEST(vkCmdWriteTimestamp);
    DO_PFN_TEST(vkCmdCopyQueryPoolResults);
    DO_PFN_TEST(vkCmdPushConstants);
    DO_PFN_TEST(vkCmdBeginRenderPass);
    DO_PFN_TEST(vkCmdNextSubpass);
    DO_PFN_TEST(vkCmdEndRenderPass);
    DO_PFN_TEST(vkCmdExecuteCommands);

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkEnumerateInstanceVersion);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkBindBufferMemory2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkBindImageMemory2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetDeviceGroupPeerMemoryFeatures);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkCmdSetDeviceMask);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkCmdDispatchBase);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkEnumeratePhysicalDeviceGroups);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetImageMemoryRequirements2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetBufferMemoryRequirements2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetImageSparseMemoryRequirements2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceFeatures2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceProperties2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceFormatProperties2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceImageFormatProperties2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceQueueFamilyProperties2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceMemoryProperties2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceSparseImageFormatProperties2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkTrimCommandPool);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetDeviceQueue2);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkCreateSamplerYcbcrConversion);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkDestroySamplerYcbcrConversion);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkCreateDescriptorUpdateTemplate);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkDestroyDescriptorUpdateTemplate);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkUpdateDescriptorSetWithTemplate);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceExternalBufferProperties);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceExternalFenceProperties);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetPhysicalDeviceExternalSemaphoreProperties);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_1
    DO_PFN_TEST(vkGetDescriptorSetLayoutSupport);
    #endif // VK_VERSION_1_1

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkCmdDrawIndirectCount);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkCmdDrawIndexedIndirectCount);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkCreateRenderPass2);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkCmdBeginRenderPass2);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkCmdNextSubpass2);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkCmdEndRenderPass2);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkResetQueryPool);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkGetSemaphoreCounterValue);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkWaitSemaphores);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkSignalSemaphore);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkGetBufferDeviceAddress);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkGetBufferOpaqueCaptureAddress);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_2
    DO_PFN_TEST(vkGetDeviceMemoryOpaqueCaptureAddress);
    #endif // VK_VERSION_1_2

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkGetPhysicalDeviceToolProperties);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCreatePrivateDataSlot);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkDestroyPrivateDataSlot);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkSetPrivateData);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkGetPrivateData);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetEvent2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdResetEvent2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdWaitEvents2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdPipelineBarrier2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdWriteTimestamp2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkQueueSubmit2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdCopyBuffer2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdCopyImage2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdCopyBufferToImage2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdCopyImageToBuffer2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdBlitImage2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdResolveImage2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdBeginRendering);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdEndRendering);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetCullMode);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetFrontFace);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetPrimitiveTopology);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetViewportWithCount);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetScissorWithCount);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdBindVertexBuffers2);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetDepthTestEnable);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetDepthWriteEnable);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetDepthCompareOp);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetDepthBoundsTestEnable);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetStencilTestEnable);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetStencilOp);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetRasterizerDiscardEnable);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetDepthBiasEnable);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkCmdSetPrimitiveRestartEnable);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkGetDeviceBufferMemoryRequirements);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkGetDeviceImageMemoryRequirements);
    #endif // VK_VERSION_1_3

    #ifdef VK_VERSION_1_3
    DO_PFN_TEST(vkGetDeviceImageSparseMemoryRequirements);
    #endif // VK_VERSION_1_3

    #ifdef VK_KHR_surface
    DO_PFN_TEST(vkDestroySurfaceKHR);
    #endif // VK_KHR_surface

    #ifdef VK_KHR_surface
    DO_PFN_TEST(vkGetPhysicalDeviceSurfaceSupportKHR);
    #endif // VK_KHR_surface

    #ifdef VK_KHR_surface
    DO_PFN_TEST(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    #endif // VK_KHR_surface

    #ifdef VK_KHR_surface
    DO_PFN_TEST(vkGetPhysicalDeviceSurfaceFormatsKHR);
    #endif // VK_KHR_surface

    #ifdef VK_KHR_surface
    DO_PFN_TEST(vkGetPhysicalDeviceSurfacePresentModesKHR);
    #endif // VK_KHR_surface

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkCreateSwapchainKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkDestroySwapchainKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkGetSwapchainImagesKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkAcquireNextImageKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkQueuePresentKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkGetDeviceGroupPresentCapabilitiesKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkGetDeviceGroupSurfacePresentModesKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkGetPhysicalDevicePresentRectanglesKHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_swapchain
    DO_PFN_TEST(vkAcquireNextImage2KHR);
    #endif // VK_KHR_swapchain

    #ifdef VK_KHR_display
    DO_PFN_TEST(vkGetPhysicalDeviceDisplayPropertiesKHR);
    #endif // VK_KHR_display

    #ifdef VK_KHR_display
    DO_PFN_TEST(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    #endif // VK_KHR_display

    #ifdef VK_KHR_display
    DO_PFN_TEST(vkGetDisplayPlaneSupportedDisplaysKHR);
    #endif // VK_KHR_display

    #ifdef VK_KHR_display
    DO_PFN_TEST(vkGetDisplayModePropertiesKHR);
    #endif // VK_KHR_display

    #ifdef VK_KHR_display
    DO_PFN_TEST(vkCreateDisplayModeKHR);
    #endif // VK_KHR_display

    #ifdef VK_KHR_display
    DO_PFN_TEST(vkGetDisplayPlaneCapabilitiesKHR);
    #endif // VK_KHR_display

    #ifdef VK_KHR_display
    DO_PFN_TEST(vkCreateDisplayPlaneSurfaceKHR);
    #endif // VK_KHR_display

    #ifdef VK_KHR_display_swapchain
    DO_PFN_TEST(vkCreateSharedSwapchainsKHR);
    #endif // VK_KHR_display_swapchain

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkGetPhysicalDeviceVideoCapabilitiesKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkGetPhysicalDeviceVideoFormatPropertiesKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkCreateVideoSessionKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkDestroyVideoSessionKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkGetVideoSessionMemoryRequirementsKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkBindVideoSessionMemoryKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkCreateVideoSessionParametersKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkUpdateVideoSessionParametersKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkDestroyVideoSessionParametersKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkCmdBeginVideoCodingKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkCmdEndVideoCodingKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_queue
    DO_PFN_TEST(vkCmdControlVideoCodingKHR);
    #endif // VK_KHR_video_queue

    #ifdef VK_KHR_video_decode_queue
    DO_PFN_TEST(vkCmdDecodeVideoKHR);
    #endif // VK_KHR_video_decode_queue

    #ifdef VK_KHR_dynamic_rendering
    DO_PFN_TEST(vkCmdBeginRenderingKHR);
    #endif // VK_KHR_dynamic_rendering

    #ifdef VK_KHR_dynamic_rendering
    DO_PFN_TEST(vkCmdEndRenderingKHR);
    #endif // VK_KHR_dynamic_rendering

    #ifdef VK_KHR_get_physical_device_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceFeatures2KHR);
    #endif // VK_KHR_get_physical_device_properties2

    #ifdef VK_KHR_get_physical_device_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceProperties2KHR);
    #endif // VK_KHR_get_physical_device_properties2

    #ifdef VK_KHR_get_physical_device_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceFormatProperties2KHR);
    #endif // VK_KHR_get_physical_device_properties2

    #ifdef VK_KHR_get_physical_device_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceImageFormatProperties2KHR);
    #endif // VK_KHR_get_physical_device_properties2

    #ifdef VK_KHR_get_physical_device_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    #endif // VK_KHR_get_physical_device_properties2

    #ifdef VK_KHR_get_physical_device_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceMemoryProperties2KHR);
    #endif // VK_KHR_get_physical_device_properties2

    #ifdef VK_KHR_get_physical_device_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    #endif // VK_KHR_get_physical_device_properties2

    #ifdef VK_KHR_device_group
    DO_PFN_TEST(vkGetDeviceGroupPeerMemoryFeaturesKHR);
    #endif // VK_KHR_device_group

    #ifdef VK_KHR_device_group
    DO_PFN_TEST(vkCmdSetDeviceMaskKHR);
    #endif // VK_KHR_device_group

    #ifdef VK_KHR_device_group
    DO_PFN_TEST(vkCmdDispatchBaseKHR);
    #endif // VK_KHR_device_group

    #ifdef VK_KHR_maintenance1
    DO_PFN_TEST(vkTrimCommandPoolKHR);
    #endif // VK_KHR_maintenance1

    #ifdef VK_KHR_device_group_creation
    DO_PFN_TEST(vkEnumeratePhysicalDeviceGroupsKHR);
    #endif // VK_KHR_device_group_creation

    #ifdef VK_KHR_external_memory_capabilities
    DO_PFN_TEST(vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    #endif // VK_KHR_external_memory_capabilities

    #ifdef VK_KHR_external_memory_fd
    DO_PFN_TEST(vkGetMemoryFdKHR);
    #endif // VK_KHR_external_memory_fd

    #ifdef VK_KHR_external_memory_fd
    DO_PFN_TEST(vkGetMemoryFdPropertiesKHR);
    #endif // VK_KHR_external_memory_fd

    #ifdef VK_KHR_external_semaphore_capabilities
    DO_PFN_TEST(vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    #endif // VK_KHR_external_semaphore_capabilities

    #ifdef VK_KHR_external_semaphore_fd
    DO_PFN_TEST(vkImportSemaphoreFdKHR);
    #endif // VK_KHR_external_semaphore_fd

    #ifdef VK_KHR_external_semaphore_fd
    DO_PFN_TEST(vkGetSemaphoreFdKHR);
    #endif // VK_KHR_external_semaphore_fd

    #ifdef VK_KHR_push_descriptor
    DO_PFN_TEST(vkCmdPushDescriptorSetKHR);
    #endif // VK_KHR_push_descriptor

    #ifdef VK_KHR_push_descriptor
    DO_PFN_TEST(vkCmdPushDescriptorSetWithTemplateKHR);
    #endif // VK_KHR_push_descriptor

    #ifdef VK_KHR_descriptor_update_template
    DO_PFN_TEST(vkCreateDescriptorUpdateTemplateKHR);
    #endif // VK_KHR_descriptor_update_template

    #ifdef VK_KHR_descriptor_update_template
    DO_PFN_TEST(vkDestroyDescriptorUpdateTemplateKHR);
    #endif // VK_KHR_descriptor_update_template

    #ifdef VK_KHR_descriptor_update_template
    DO_PFN_TEST(vkUpdateDescriptorSetWithTemplateKHR);
    #endif // VK_KHR_descriptor_update_template

    #ifdef VK_KHR_create_renderpass2
    DO_PFN_TEST(vkCreateRenderPass2KHR);
    #endif // VK_KHR_create_renderpass2

    #ifdef VK_KHR_create_renderpass2
    DO_PFN_TEST(vkCmdBeginRenderPass2KHR);
    #endif // VK_KHR_create_renderpass2

    #ifdef VK_KHR_create_renderpass2
    DO_PFN_TEST(vkCmdNextSubpass2KHR);
    #endif // VK_KHR_create_renderpass2

    #ifdef VK_KHR_create_renderpass2
    DO_PFN_TEST(vkCmdEndRenderPass2KHR);
    #endif // VK_KHR_create_renderpass2

    #ifdef VK_KHR_shared_presentable_image
    DO_PFN_TEST(vkGetSwapchainStatusKHR);
    #endif // VK_KHR_shared_presentable_image

    #ifdef VK_KHR_external_fence_capabilities
    DO_PFN_TEST(vkGetPhysicalDeviceExternalFencePropertiesKHR);
    #endif // VK_KHR_external_fence_capabilities

    #ifdef VK_KHR_external_fence_fd
    DO_PFN_TEST(vkImportFenceFdKHR);
    #endif // VK_KHR_external_fence_fd

    #ifdef VK_KHR_external_fence_fd
    DO_PFN_TEST(vkGetFenceFdKHR);
    #endif // VK_KHR_external_fence_fd

    #ifdef VK_KHR_performance_query
    DO_PFN_TEST(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    #endif // VK_KHR_performance_query

    #ifdef VK_KHR_performance_query
    DO_PFN_TEST(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    #endif // VK_KHR_performance_query

    #ifdef VK_KHR_performance_query
    DO_PFN_TEST(vkAcquireProfilingLockKHR);
    #endif // VK_KHR_performance_query

    #ifdef VK_KHR_performance_query
    DO_PFN_TEST(vkReleaseProfilingLockKHR);
    #endif // VK_KHR_performance_query

    #ifdef VK_KHR_get_surface_capabilities2
    DO_PFN_TEST(vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    #endif // VK_KHR_get_surface_capabilities2

    #ifdef VK_KHR_get_surface_capabilities2
    DO_PFN_TEST(vkGetPhysicalDeviceSurfaceFormats2KHR);
    #endif // VK_KHR_get_surface_capabilities2

    #ifdef VK_KHR_get_display_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceDisplayProperties2KHR);
    #endif // VK_KHR_get_display_properties2

    #ifdef VK_KHR_get_display_properties2
    DO_PFN_TEST(vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    #endif // VK_KHR_get_display_properties2

    #ifdef VK_KHR_get_display_properties2
    DO_PFN_TEST(vkGetDisplayModeProperties2KHR);
    #endif // VK_KHR_get_display_properties2

    #ifdef VK_KHR_get_display_properties2
    DO_PFN_TEST(vkGetDisplayPlaneCapabilities2KHR);
    #endif // VK_KHR_get_display_properties2

    #ifdef VK_KHR_get_memory_requirements2
    DO_PFN_TEST(vkGetImageMemoryRequirements2KHR);
    #endif // VK_KHR_get_memory_requirements2

    #ifdef VK_KHR_get_memory_requirements2
    DO_PFN_TEST(vkGetBufferMemoryRequirements2KHR);
    #endif // VK_KHR_get_memory_requirements2

    #ifdef VK_KHR_get_memory_requirements2
    DO_PFN_TEST(vkGetImageSparseMemoryRequirements2KHR);
    #endif // VK_KHR_get_memory_requirements2

    #ifdef VK_KHR_sampler_ycbcr_conversion
    DO_PFN_TEST(vkCreateSamplerYcbcrConversionKHR);
    #endif // VK_KHR_sampler_ycbcr_conversion

    #ifdef VK_KHR_sampler_ycbcr_conversion
    DO_PFN_TEST(vkDestroySamplerYcbcrConversionKHR);
    #endif // VK_KHR_sampler_ycbcr_conversion

    #ifdef VK_KHR_bind_memory2
    DO_PFN_TEST(vkBindBufferMemory2KHR);
    #endif // VK_KHR_bind_memory2

    #ifdef VK_KHR_bind_memory2
    DO_PFN_TEST(vkBindImageMemory2KHR);
    #endif // VK_KHR_bind_memory2

    #ifdef VK_KHR_maintenance3
    DO_PFN_TEST(vkGetDescriptorSetLayoutSupportKHR);
    #endif // VK_KHR_maintenance3

    #ifdef VK_KHR_draw_indirect_count
    DO_PFN_TEST(vkCmdDrawIndirectCountKHR);
    #endif // VK_KHR_draw_indirect_count

    #ifdef VK_KHR_draw_indirect_count
    DO_PFN_TEST(vkCmdDrawIndexedIndirectCountKHR);
    #endif // VK_KHR_draw_indirect_count

    #ifdef VK_KHR_timeline_semaphore
    DO_PFN_TEST(vkGetSemaphoreCounterValueKHR);
    #endif // VK_KHR_timeline_semaphore

    #ifdef VK_KHR_timeline_semaphore
    DO_PFN_TEST(vkWaitSemaphoresKHR);
    #endif // VK_KHR_timeline_semaphore

    #ifdef VK_KHR_timeline_semaphore
    DO_PFN_TEST(vkSignalSemaphoreKHR);
    #endif // VK_KHR_timeline_semaphore

    #ifdef VK_KHR_fragment_shading_rate
    DO_PFN_TEST(vkGetPhysicalDeviceFragmentShadingRatesKHR);
    #endif // VK_KHR_fragment_shading_rate

    #ifdef VK_KHR_fragment_shading_rate
    DO_PFN_TEST(vkCmdSetFragmentShadingRateKHR);
    #endif // VK_KHR_fragment_shading_rate

    #ifdef VK_KHR_present_wait
    DO_PFN_TEST(vkWaitForPresentKHR);
    #endif // VK_KHR_present_wait

    #ifdef VK_KHR_buffer_device_address
    DO_PFN_TEST(vkGetBufferDeviceAddressKHR);
    #endif // VK_KHR_buffer_device_address

    #ifdef VK_KHR_buffer_device_address
    DO_PFN_TEST(vkGetBufferOpaqueCaptureAddressKHR);
    #endif // VK_KHR_buffer_device_address

    #ifdef VK_KHR_buffer_device_address
    DO_PFN_TEST(vkGetDeviceMemoryOpaqueCaptureAddressKHR);
    #endif // VK_KHR_buffer_device_address

    #ifdef VK_KHR_deferred_host_operations
    DO_PFN_TEST(vkCreateDeferredOperationKHR);
    #endif // VK_KHR_deferred_host_operations

    #ifdef VK_KHR_deferred_host_operations
    DO_PFN_TEST(vkDestroyDeferredOperationKHR);
    #endif // VK_KHR_deferred_host_operations

    #ifdef VK_KHR_deferred_host_operations
    DO_PFN_TEST(vkGetDeferredOperationMaxConcurrencyKHR);
    #endif // VK_KHR_deferred_host_operations

    #ifdef VK_KHR_deferred_host_operations
    DO_PFN_TEST(vkGetDeferredOperationResultKHR);
    #endif // VK_KHR_deferred_host_operations

    #ifdef VK_KHR_deferred_host_operations
    DO_PFN_TEST(vkDeferredOperationJoinKHR);
    #endif // VK_KHR_deferred_host_operations

    #ifdef VK_KHR_pipeline_executable_properties
    DO_PFN_TEST(vkGetPipelineExecutablePropertiesKHR);
    #endif // VK_KHR_pipeline_executable_properties

    #ifdef VK_KHR_pipeline_executable_properties
    DO_PFN_TEST(vkGetPipelineExecutableStatisticsKHR);
    #endif // VK_KHR_pipeline_executable_properties

    #ifdef VK_KHR_pipeline_executable_properties
    DO_PFN_TEST(vkGetPipelineExecutableInternalRepresentationsKHR);
    #endif // VK_KHR_pipeline_executable_properties

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkCmdSetEvent2KHR);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkCmdResetEvent2KHR);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkCmdWaitEvents2KHR);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkCmdPipelineBarrier2KHR);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkCmdWriteTimestamp2KHR);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkQueueSubmit2KHR);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkCmdWriteBufferMarker2AMD);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_synchronization2
    DO_PFN_TEST(vkGetQueueCheckpointData2NV);
    #endif // VK_KHR_synchronization2

    #ifdef VK_KHR_copy_commands2
    DO_PFN_TEST(vkCmdCopyBuffer2KHR);
    #endif // VK_KHR_copy_commands2

    #ifdef VK_KHR_copy_commands2
    DO_PFN_TEST(vkCmdCopyImage2KHR);
    #endif // VK_KHR_copy_commands2

    #ifdef VK_KHR_copy_commands2
    DO_PFN_TEST(vkCmdCopyBufferToImage2KHR);
    #endif // VK_KHR_copy_commands2

    #ifdef VK_KHR_copy_commands2
    DO_PFN_TEST(vkCmdCopyImageToBuffer2KHR);
    #endif // VK_KHR_copy_commands2

    #ifdef VK_KHR_copy_commands2
    DO_PFN_TEST(vkCmdBlitImage2KHR);
    #endif // VK_KHR_copy_commands2

    #ifdef VK_KHR_copy_commands2
    DO_PFN_TEST(vkCmdResolveImage2KHR);
    #endif // VK_KHR_copy_commands2

    #ifdef VK_KHR_ray_tracing_maintenance1
    DO_PFN_TEST(vkCmdTraceRaysIndirect2KHR);
    #endif // VK_KHR_ray_tracing_maintenance1

    #ifdef VK_KHR_maintenance4
    DO_PFN_TEST(vkGetDeviceBufferMemoryRequirementsKHR);
    #endif // VK_KHR_maintenance4

    #ifdef VK_KHR_maintenance4
    DO_PFN_TEST(vkGetDeviceImageMemoryRequirementsKHR);
    #endif // VK_KHR_maintenance4

    #ifdef VK_KHR_maintenance4
    DO_PFN_TEST(vkGetDeviceImageSparseMemoryRequirementsKHR);
    #endif // VK_KHR_maintenance4

    #ifdef VK_EXT_debug_report
    DO_PFN_TEST(vkCreateDebugReportCallbackEXT);
    #endif // VK_EXT_debug_report

    #ifdef VK_EXT_debug_report
    DO_PFN_TEST(vkDestroyDebugReportCallbackEXT);
    #endif // VK_EXT_debug_report

    #ifdef VK_EXT_debug_report
    DO_PFN_TEST(vkDebugReportMessageEXT);
    #endif // VK_EXT_debug_report

    #ifdef VK_EXT_debug_marker
    DO_PFN_TEST(vkDebugMarkerSetObjectTagEXT);
    #endif // VK_EXT_debug_marker

    #ifdef VK_EXT_debug_marker
    DO_PFN_TEST(vkDebugMarkerSetObjectNameEXT);
    #endif // VK_EXT_debug_marker

    #ifdef VK_EXT_debug_marker
    DO_PFN_TEST(vkCmdDebugMarkerBeginEXT);
    #endif // VK_EXT_debug_marker

    #ifdef VK_EXT_debug_marker
    DO_PFN_TEST(vkCmdDebugMarkerEndEXT);
    #endif // VK_EXT_debug_marker

    #ifdef VK_EXT_debug_marker
    DO_PFN_TEST(vkCmdDebugMarkerInsertEXT);
    #endif // VK_EXT_debug_marker

    #ifdef VK_EXT_transform_feedback
    DO_PFN_TEST(vkCmdBindTransformFeedbackBuffersEXT);
    #endif // VK_EXT_transform_feedback

    #ifdef VK_EXT_transform_feedback
    DO_PFN_TEST(vkCmdBeginTransformFeedbackEXT);
    #endif // VK_EXT_transform_feedback

    #ifdef VK_EXT_transform_feedback
    DO_PFN_TEST(vkCmdEndTransformFeedbackEXT);
    #endif // VK_EXT_transform_feedback

    #ifdef VK_EXT_transform_feedback
    DO_PFN_TEST(vkCmdBeginQueryIndexedEXT);
    #endif // VK_EXT_transform_feedback

    #ifdef VK_EXT_transform_feedback
    DO_PFN_TEST(vkCmdEndQueryIndexedEXT);
    #endif // VK_EXT_transform_feedback

    #ifdef VK_EXT_transform_feedback
    DO_PFN_TEST(vkCmdDrawIndirectByteCountEXT);
    #endif // VK_EXT_transform_feedback

    #ifdef VK_NVX_binary_import
    DO_PFN_TEST(vkCreateCuModuleNVX);
    #endif // VK_NVX_binary_import

    #ifdef VK_NVX_binary_import
    DO_PFN_TEST(vkCreateCuFunctionNVX);
    #endif // VK_NVX_binary_import

    #ifdef VK_NVX_binary_import
    DO_PFN_TEST(vkDestroyCuModuleNVX);
    #endif // VK_NVX_binary_import

    #ifdef VK_NVX_binary_import
    DO_PFN_TEST(vkDestroyCuFunctionNVX);
    #endif // VK_NVX_binary_import

    #ifdef VK_NVX_binary_import
    DO_PFN_TEST(vkCmdCuLaunchKernelNVX);
    #endif // VK_NVX_binary_import

    #ifdef VK_NVX_image_view_handle
    DO_PFN_TEST(vkGetImageViewHandleNVX);
    #endif // VK_NVX_image_view_handle

    #ifdef VK_NVX_image_view_handle
    DO_PFN_TEST(vkGetImageViewAddressNVX);
    #endif // VK_NVX_image_view_handle

    #ifdef VK_AMD_draw_indirect_count
    DO_PFN_TEST(vkCmdDrawIndirectCountAMD);
    #endif // VK_AMD_draw_indirect_count

    #ifdef VK_AMD_draw_indirect_count
    DO_PFN_TEST(vkCmdDrawIndexedIndirectCountAMD);
    #endif // VK_AMD_draw_indirect_count

    #ifdef VK_AMD_shader_info
    DO_PFN_TEST(vkGetShaderInfoAMD);
    #endif // VK_AMD_shader_info

    #ifdef VK_NV_external_memory_capabilities
    DO_PFN_TEST(vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
    #endif // VK_NV_external_memory_capabilities

    #ifdef VK_EXT_conditional_rendering
    DO_PFN_TEST(vkCmdBeginConditionalRenderingEXT);
    #endif // VK_EXT_conditional_rendering

    #ifdef VK_EXT_conditional_rendering
    DO_PFN_TEST(vkCmdEndConditionalRenderingEXT);
    #endif // VK_EXT_conditional_rendering

    #ifdef VK_NV_clip_space_w_scaling
    DO_PFN_TEST(vkCmdSetViewportWScalingNV);
    #endif // VK_NV_clip_space_w_scaling

    #ifdef VK_EXT_direct_mode_display
    DO_PFN_TEST(vkReleaseDisplayEXT);
    #endif // VK_EXT_direct_mode_display

    #ifdef VK_EXT_display_surface_counter
    DO_PFN_TEST(vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    #endif // VK_EXT_display_surface_counter

    #ifdef VK_EXT_display_control
    DO_PFN_TEST(vkDisplayPowerControlEXT);
    #endif // VK_EXT_display_control

    #ifdef VK_EXT_display_control
    DO_PFN_TEST(vkRegisterDeviceEventEXT);
    #endif // VK_EXT_display_control

    #ifdef VK_EXT_display_control
    DO_PFN_TEST(vkRegisterDisplayEventEXT);
    #endif // VK_EXT_display_control

    #ifdef VK_EXT_display_control
    DO_PFN_TEST(vkGetSwapchainCounterEXT);
    #endif // VK_EXT_display_control

    #ifdef VK_GOOGLE_display_timing
    DO_PFN_TEST(vkGetRefreshCycleDurationGOOGLE);
    #endif // VK_GOOGLE_display_timing

    #ifdef VK_GOOGLE_display_timing
    DO_PFN_TEST(vkGetPastPresentationTimingGOOGLE);
    #endif // VK_GOOGLE_display_timing

    #ifdef VK_EXT_discard_rectangles
    DO_PFN_TEST(vkCmdSetDiscardRectangleEXT);
    #endif // VK_EXT_discard_rectangles

    #ifdef VK_EXT_discard_rectangles
    DO_PFN_TEST(vkCmdSetDiscardRectangleEnableEXT);
    #endif // VK_EXT_discard_rectangles

    #ifdef VK_EXT_discard_rectangles
    DO_PFN_TEST(vkCmdSetDiscardRectangleModeEXT);
    #endif // VK_EXT_discard_rectangles

    #ifdef VK_EXT_hdr_metadata
    DO_PFN_TEST(vkSetHdrMetadataEXT);
    #endif // VK_EXT_hdr_metadata

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkSetDebugUtilsObjectNameEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkSetDebugUtilsObjectTagEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkQueueBeginDebugUtilsLabelEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkQueueEndDebugUtilsLabelEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkQueueInsertDebugUtilsLabelEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkCmdBeginDebugUtilsLabelEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkCmdEndDebugUtilsLabelEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkCmdInsertDebugUtilsLabelEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkCreateDebugUtilsMessengerEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkDestroyDebugUtilsMessengerEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_debug_utils
    DO_PFN_TEST(vkSubmitDebugUtilsMessageEXT);
    #endif // VK_EXT_debug_utils

    #ifdef VK_EXT_sample_locations
    DO_PFN_TEST(vkCmdSetSampleLocationsEXT);
    #endif // VK_EXT_sample_locations

    #ifdef VK_EXT_sample_locations
    DO_PFN_TEST(vkGetPhysicalDeviceMultisamplePropertiesEXT);
    #endif // VK_EXT_sample_locations

    #ifdef VK_EXT_image_drm_format_modifier
    DO_PFN_TEST(vkGetImageDrmFormatModifierPropertiesEXT);
    #endif // VK_EXT_image_drm_format_modifier

    #ifdef VK_EXT_validation_cache
    DO_PFN_TEST(vkCreateValidationCacheEXT);
    #endif // VK_EXT_validation_cache

    #ifdef VK_EXT_validation_cache
    DO_PFN_TEST(vkDestroyValidationCacheEXT);
    #endif // VK_EXT_validation_cache

    #ifdef VK_EXT_validation_cache
    DO_PFN_TEST(vkMergeValidationCachesEXT);
    #endif // VK_EXT_validation_cache

    #ifdef VK_EXT_validation_cache
    DO_PFN_TEST(vkGetValidationCacheDataEXT);
    #endif // VK_EXT_validation_cache

    #ifdef VK_NV_shading_rate_image
    DO_PFN_TEST(vkCmdBindShadingRateImageNV);
    #endif // VK_NV_shading_rate_image

    #ifdef VK_NV_shading_rate_image
    DO_PFN_TEST(vkCmdSetViewportShadingRatePaletteNV);
    #endif // VK_NV_shading_rate_image

    #ifdef VK_NV_shading_rate_image
    DO_PFN_TEST(vkCmdSetCoarseSampleOrderNV);
    #endif // VK_NV_shading_rate_image

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkCreateAccelerationStructureNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkDestroyAccelerationStructureNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkGetAccelerationStructureMemoryRequirementsNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkBindAccelerationStructureMemoryNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkCmdBuildAccelerationStructureNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkCmdCopyAccelerationStructureNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkCmdTraceRaysNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkCreateRayTracingPipelinesNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkGetRayTracingShaderGroupHandlesKHR);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkGetRayTracingShaderGroupHandlesNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkGetAccelerationStructureHandleNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkCmdWriteAccelerationStructuresPropertiesNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_NV_ray_tracing
    DO_PFN_TEST(vkCompileDeferredNV);
    #endif // VK_NV_ray_tracing

    #ifdef VK_EXT_external_memory_host
    DO_PFN_TEST(vkGetMemoryHostPointerPropertiesEXT);
    #endif // VK_EXT_external_memory_host

    #ifdef VK_AMD_buffer_marker
    DO_PFN_TEST(vkCmdWriteBufferMarkerAMD);
    #endif // VK_AMD_buffer_marker

    #ifdef VK_EXT_calibrated_timestamps
    DO_PFN_TEST(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
    #endif // VK_EXT_calibrated_timestamps

    #ifdef VK_EXT_calibrated_timestamps
    DO_PFN_TEST(vkGetCalibratedTimestampsEXT);
    #endif // VK_EXT_calibrated_timestamps

    #ifdef VK_NV_mesh_shader
    DO_PFN_TEST(vkCmdDrawMeshTasksNV);
    #endif // VK_NV_mesh_shader

    #ifdef VK_NV_mesh_shader
    DO_PFN_TEST(vkCmdDrawMeshTasksIndirectNV);
    #endif // VK_NV_mesh_shader

    #ifdef VK_NV_mesh_shader
    DO_PFN_TEST(vkCmdDrawMeshTasksIndirectCountNV);
    #endif // VK_NV_mesh_shader

    #ifdef VK_NV_scissor_exclusive
    DO_PFN_TEST(vkCmdSetExclusiveScissorEnableNV);
    #endif // VK_NV_scissor_exclusive

    #ifdef VK_NV_scissor_exclusive
    DO_PFN_TEST(vkCmdSetExclusiveScissorNV);
    #endif // VK_NV_scissor_exclusive

    #ifdef VK_NV_device_diagnostic_checkpoints
    DO_PFN_TEST(vkCmdSetCheckpointNV);
    #endif // VK_NV_device_diagnostic_checkpoints

    #ifdef VK_NV_device_diagnostic_checkpoints
    DO_PFN_TEST(vkGetQueueCheckpointDataNV);
    #endif // VK_NV_device_diagnostic_checkpoints

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkInitializePerformanceApiINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkUninitializePerformanceApiINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkCmdSetPerformanceMarkerINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkCmdSetPerformanceStreamMarkerINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkCmdSetPerformanceOverrideINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkAcquirePerformanceConfigurationINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkReleasePerformanceConfigurationINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkQueueSetPerformanceConfigurationINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_INTEL_performance_query
    DO_PFN_TEST(vkGetPerformanceParameterINTEL);
    #endif // VK_INTEL_performance_query

    #ifdef VK_AMD_display_native_hdr
    DO_PFN_TEST(vkSetLocalDimmingAMD);
    #endif // VK_AMD_display_native_hdr

    #ifdef VK_EXT_buffer_device_address
    DO_PFN_TEST(vkGetBufferDeviceAddressEXT);
    #endif // VK_EXT_buffer_device_address

    #ifdef VK_EXT_tooling_info
    DO_PFN_TEST(vkGetPhysicalDeviceToolPropertiesEXT);
    #endif // VK_EXT_tooling_info

    #ifdef VK_NV_cooperative_matrix
    DO_PFN_TEST(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
    #endif // VK_NV_cooperative_matrix

    #ifdef VK_NV_coverage_reduction_mode
    DO_PFN_TEST(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
    #endif // VK_NV_coverage_reduction_mode

    #ifdef VK_EXT_headless_surface
    DO_PFN_TEST(vkCreateHeadlessSurfaceEXT);
    #endif // VK_EXT_headless_surface

    #ifdef VK_EXT_line_rasterization
    DO_PFN_TEST(vkCmdSetLineStippleEXT);
    #endif // VK_EXT_line_rasterization

    #ifdef VK_EXT_host_query_reset
    DO_PFN_TEST(vkResetQueryPoolEXT);
    #endif // VK_EXT_host_query_reset

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetCullModeEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetFrontFaceEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetPrimitiveTopologyEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetViewportWithCountEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetScissorWithCountEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdBindVertexBuffers2EXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetDepthTestEnableEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetDepthWriteEnableEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetDepthCompareOpEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetDepthBoundsTestEnableEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetStencilTestEnableEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_extended_dynamic_state
    DO_PFN_TEST(vkCmdSetStencilOpEXT);
    #endif // VK_EXT_extended_dynamic_state

    #ifdef VK_EXT_swapchain_maintenance1
    DO_PFN_TEST(vkReleaseSwapchainImagesEXT);
    #endif // VK_EXT_swapchain_maintenance1

    #ifdef VK_NV_device_generated_commands
    DO_PFN_TEST(vkGetGeneratedCommandsMemoryRequirementsNV);
    #endif // VK_NV_device_generated_commands

    #ifdef VK_NV_device_generated_commands
    DO_PFN_TEST(vkCmdPreprocessGeneratedCommandsNV);
    #endif // VK_NV_device_generated_commands

    #ifdef VK_NV_device_generated_commands
    DO_PFN_TEST(vkCmdExecuteGeneratedCommandsNV);
    #endif // VK_NV_device_generated_commands

    #ifdef VK_NV_device_generated_commands
    DO_PFN_TEST(vkCmdBindPipelineShaderGroupNV);
    #endif // VK_NV_device_generated_commands

    #ifdef VK_NV_device_generated_commands
    DO_PFN_TEST(vkCreateIndirectCommandsLayoutNV);
    #endif // VK_NV_device_generated_commands

    #ifdef VK_NV_device_generated_commands
    DO_PFN_TEST(vkDestroyIndirectCommandsLayoutNV);
    #endif // VK_NV_device_generated_commands

    #ifdef VK_EXT_acquire_drm_display
    DO_PFN_TEST(vkAcquireDrmDisplayEXT);
    #endif // VK_EXT_acquire_drm_display

    #ifdef VK_EXT_acquire_drm_display
    DO_PFN_TEST(vkGetDrmDisplayEXT);
    #endif // VK_EXT_acquire_drm_display

    #ifdef VK_EXT_private_data
    DO_PFN_TEST(vkCreatePrivateDataSlotEXT);
    #endif // VK_EXT_private_data

    #ifdef VK_EXT_private_data
    DO_PFN_TEST(vkDestroyPrivateDataSlotEXT);
    #endif // VK_EXT_private_data

    #ifdef VK_EXT_private_data
    DO_PFN_TEST(vkSetPrivateDataEXT);
    #endif // VK_EXT_private_data

    #ifdef VK_EXT_private_data
    DO_PFN_TEST(vkGetPrivateDataEXT);
    #endif // VK_EXT_private_data

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetDescriptorSetLayoutSizeEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetDescriptorSetLayoutBindingOffsetEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetDescriptorEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkCmdBindDescriptorBuffersEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkCmdSetDescriptorBufferOffsetsEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkCmdBindDescriptorBufferEmbeddedSamplersEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetBufferOpaqueCaptureDescriptorDataEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetImageOpaqueCaptureDescriptorDataEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetImageViewOpaqueCaptureDescriptorDataEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetSamplerOpaqueCaptureDescriptorDataEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_EXT_descriptor_buffer
    DO_PFN_TEST(vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT);
    #endif // VK_EXT_descriptor_buffer

    #ifdef VK_NV_fragment_shading_rate_enums
    DO_PFN_TEST(vkCmdSetFragmentShadingRateEnumNV);
    #endif // VK_NV_fragment_shading_rate_enums

    #ifdef VK_EXT_image_compression_control
    DO_PFN_TEST(vkGetImageSubresourceLayout2EXT);
    #endif // VK_EXT_image_compression_control

    #ifdef VK_EXT_device_fault
    DO_PFN_TEST(vkGetDeviceFaultInfoEXT);
    #endif // VK_EXT_device_fault

    #ifdef VK_EXT_vertex_input_dynamic_state
    DO_PFN_TEST(vkCmdSetVertexInputEXT);
    #endif // VK_EXT_vertex_input_dynamic_state

    #ifdef VK_HUAWEI_subpass_shading
    DO_PFN_TEST(vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI);
    #endif // VK_HUAWEI_subpass_shading

    #ifdef VK_HUAWEI_subpass_shading
    DO_PFN_TEST(vkCmdSubpassShadingHUAWEI);
    #endif // VK_HUAWEI_subpass_shading

    #ifdef VK_HUAWEI_invocation_mask
    DO_PFN_TEST(vkCmdBindInvocationMaskHUAWEI);
    #endif // VK_HUAWEI_invocation_mask

    #ifdef VK_NV_external_memory_rdma
    DO_PFN_TEST(vkGetMemoryRemoteAddressNV);
    #endif // VK_NV_external_memory_rdma

    #ifdef VK_EXT_pipeline_properties
    DO_PFN_TEST(vkGetPipelinePropertiesEXT);
    #endif // VK_EXT_pipeline_properties

    #ifdef VK_EXT_extended_dynamic_state2
    DO_PFN_TEST(vkCmdSetPatchControlPointsEXT);
    #endif // VK_EXT_extended_dynamic_state2

    #ifdef VK_EXT_extended_dynamic_state2
    DO_PFN_TEST(vkCmdSetRasterizerDiscardEnableEXT);
    #endif // VK_EXT_extended_dynamic_state2

    #ifdef VK_EXT_extended_dynamic_state2
    DO_PFN_TEST(vkCmdSetDepthBiasEnableEXT);
    #endif // VK_EXT_extended_dynamic_state2

    #ifdef VK_EXT_extended_dynamic_state2
    DO_PFN_TEST(vkCmdSetLogicOpEXT);
    #endif // VK_EXT_extended_dynamic_state2

    #ifdef VK_EXT_extended_dynamic_state2
    DO_PFN_TEST(vkCmdSetPrimitiveRestartEnableEXT);
    #endif // VK_EXT_extended_dynamic_state2

    #ifdef VK_EXT_color_write_enable
    DO_PFN_TEST(vkCmdSetColorWriteEnableEXT);
    #endif // VK_EXT_color_write_enable

    #ifdef VK_EXT_multi_draw
    DO_PFN_TEST(vkCmdDrawMultiEXT);
    #endif // VK_EXT_multi_draw

    #ifdef VK_EXT_multi_draw
    DO_PFN_TEST(vkCmdDrawMultiIndexedEXT);
    #endif // VK_EXT_multi_draw

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCreateMicromapEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkDestroyMicromapEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCmdBuildMicromapsEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkBuildMicromapsEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCopyMicromapEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCopyMicromapToMemoryEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCopyMemoryToMicromapEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkWriteMicromapsPropertiesEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCmdCopyMicromapEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCmdCopyMicromapToMemoryEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCmdCopyMemoryToMicromapEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkCmdWriteMicromapsPropertiesEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkGetDeviceMicromapCompatibilityEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_EXT_opacity_micromap
    DO_PFN_TEST(vkGetMicromapBuildSizesEXT);
    #endif // VK_EXT_opacity_micromap

    #ifdef VK_HUAWEI_cluster_culling_shader
    DO_PFN_TEST(vkCmdDrawClusterHUAWEI);
    #endif // VK_HUAWEI_cluster_culling_shader

    #ifdef VK_HUAWEI_cluster_culling_shader
    DO_PFN_TEST(vkCmdDrawClusterIndirectHUAWEI);
    #endif // VK_HUAWEI_cluster_culling_shader

    #ifdef VK_EXT_pageable_device_local_memory
    DO_PFN_TEST(vkSetDeviceMemoryPriorityEXT);
    #endif // VK_EXT_pageable_device_local_memory

    #ifdef VK_VALVE_descriptor_set_host_mapping
    DO_PFN_TEST(vkGetDescriptorSetLayoutHostMappingInfoVALVE);
    #endif // VK_VALVE_descriptor_set_host_mapping

    #ifdef VK_VALVE_descriptor_set_host_mapping
    DO_PFN_TEST(vkGetDescriptorSetHostMappingVALVE);
    #endif // VK_VALVE_descriptor_set_host_mapping

    #ifdef VK_NV_copy_memory_indirect
    DO_PFN_TEST(vkCmdCopyMemoryIndirectNV);
    #endif // VK_NV_copy_memory_indirect

    #ifdef VK_NV_copy_memory_indirect
    DO_PFN_TEST(vkCmdCopyMemoryToImageIndirectNV);
    #endif // VK_NV_copy_memory_indirect

    #ifdef VK_NV_memory_decompression
    DO_PFN_TEST(vkCmdDecompressMemoryNV);
    #endif // VK_NV_memory_decompression

    #ifdef VK_NV_memory_decompression
    DO_PFN_TEST(vkCmdDecompressMemoryIndirectCountNV);
    #endif // VK_NV_memory_decompression

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetTessellationDomainOriginEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetDepthClampEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetPolygonModeEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetRasterizationSamplesEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetSampleMaskEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetAlphaToCoverageEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetAlphaToOneEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetLogicOpEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetColorBlendEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetColorBlendEquationEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetColorWriteMaskEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetRasterizationStreamEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetConservativeRasterizationModeEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetExtraPrimitiveOverestimationSizeEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetDepthClipEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetSampleLocationsEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetColorBlendAdvancedEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetProvokingVertexModeEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetLineRasterizationModeEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetLineStippleEnableEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetDepthClipNegativeOneToOneEXT);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetViewportWScalingEnableNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetViewportSwizzleNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetCoverageToColorEnableNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetCoverageToColorLocationNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetCoverageModulationModeNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetCoverageModulationTableEnableNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetCoverageModulationTableNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetShadingRateImageEnableNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetRepresentativeFragmentTestEnableNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_extended_dynamic_state3
    DO_PFN_TEST(vkCmdSetCoverageReductionModeNV);
    #endif // VK_EXT_extended_dynamic_state3

    #ifdef VK_EXT_shader_module_identifier
    DO_PFN_TEST(vkGetShaderModuleIdentifierEXT);
    #endif // VK_EXT_shader_module_identifier

    #ifdef VK_EXT_shader_module_identifier
    DO_PFN_TEST(vkGetShaderModuleCreateInfoIdentifierEXT);
    #endif // VK_EXT_shader_module_identifier

    #ifdef VK_NV_optical_flow
    DO_PFN_TEST(vkGetPhysicalDeviceOpticalFlowImageFormatsNV);
    #endif // VK_NV_optical_flow

    #ifdef VK_NV_optical_flow
    DO_PFN_TEST(vkCreateOpticalFlowSessionNV);
    #endif // VK_NV_optical_flow

    #ifdef VK_NV_optical_flow
    DO_PFN_TEST(vkDestroyOpticalFlowSessionNV);
    #endif // VK_NV_optical_flow

    #ifdef VK_NV_optical_flow
    DO_PFN_TEST(vkBindOpticalFlowSessionImageNV);
    #endif // VK_NV_optical_flow

    #ifdef VK_NV_optical_flow
    DO_PFN_TEST(vkCmdOpticalFlowExecuteNV);
    #endif // VK_NV_optical_flow

    #ifdef VK_QCOM_tile_properties
    DO_PFN_TEST(vkGetFramebufferTilePropertiesQCOM);
    #endif // VK_QCOM_tile_properties

    #ifdef VK_QCOM_tile_properties
    DO_PFN_TEST(vkGetDynamicRenderingTilePropertiesQCOM);
    #endif // VK_QCOM_tile_properties

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCreateAccelerationStructureKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkDestroyAccelerationStructureKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCmdBuildAccelerationStructuresKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCmdBuildAccelerationStructuresIndirectKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkBuildAccelerationStructuresKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCopyAccelerationStructureKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCopyAccelerationStructureToMemoryKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCopyMemoryToAccelerationStructureKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkWriteAccelerationStructuresPropertiesKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCmdCopyAccelerationStructureKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCmdCopyAccelerationStructureToMemoryKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCmdCopyMemoryToAccelerationStructureKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkGetAccelerationStructureDeviceAddressKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkCmdWriteAccelerationStructuresPropertiesKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkGetDeviceAccelerationStructureCompatibilityKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_acceleration_structure
    DO_PFN_TEST(vkGetAccelerationStructureBuildSizesKHR);
    #endif // VK_KHR_acceleration_structure

    #ifdef VK_KHR_ray_tracing_pipeline
    DO_PFN_TEST(vkCmdTraceRaysKHR);
    #endif // VK_KHR_ray_tracing_pipeline

    #ifdef VK_KHR_ray_tracing_pipeline
    DO_PFN_TEST(vkCreateRayTracingPipelinesKHR);
    #endif // VK_KHR_ray_tracing_pipeline

    #ifdef VK_KHR_ray_tracing_pipeline
    DO_PFN_TEST(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
    #endif // VK_KHR_ray_tracing_pipeline

    #ifdef VK_KHR_ray_tracing_pipeline
    DO_PFN_TEST(vkCmdTraceRaysIndirectKHR);
    #endif // VK_KHR_ray_tracing_pipeline

    #ifdef VK_KHR_ray_tracing_pipeline
    DO_PFN_TEST(vkGetRayTracingShaderGroupStackSizeKHR);
    #endif // VK_KHR_ray_tracing_pipeline

    #ifdef VK_KHR_ray_tracing_pipeline
    DO_PFN_TEST(vkCmdSetRayTracingPipelineStackSizeKHR);
    #endif // VK_KHR_ray_tracing_pipeline

    #ifdef VK_EXT_mesh_shader
    DO_PFN_TEST(vkCmdDrawMeshTasksEXT);
    #endif // VK_EXT_mesh_shader

    #ifdef VK_EXT_mesh_shader
    DO_PFN_TEST(vkCmdDrawMeshTasksIndirectEXT);
    #endif // VK_EXT_mesh_shader

    #ifdef VK_EXT_mesh_shader
    DO_PFN_TEST(vkCmdDrawMeshTasksIndirectCountEXT);
    #endif // VK_EXT_mesh_shader

#endif // #ifdef VULKAN_CORE_H_

#ifdef VULKAN_ANDROID_H_

    #ifdef VK_KHR_android_surface
    DO_PFN_TEST(vkCreateAndroidSurfaceKHR);
    #endif // VK_KHR_android_surface

    #ifdef VK_ANDROID_external_memory_android_hardware_buffer
    DO_PFN_TEST(vkGetAndroidHardwareBufferPropertiesANDROID);
    #endif // VK_ANDROID_external_memory_android_hardware_buffer

    #ifdef VK_ANDROID_external_memory_android_hardware_buffer
    DO_PFN_TEST(vkGetMemoryAndroidHardwareBufferANDROID);
    #endif // VK_ANDROID_external_memory_android_hardware_buffer

#endif // #ifdef VULKAN_ANDROID_H_

#ifdef VULKAN_FUCHSIA_H_

    #ifdef VK_FUCHSIA_imagepipe_surface
    DO_PFN_TEST(vkCreateImagePipeSurfaceFUCHSIA);
    #endif // VK_FUCHSIA_imagepipe_surface

    #ifdef VK_FUCHSIA_external_memory
    DO_PFN_TEST(vkGetMemoryZirconHandleFUCHSIA);
    #endif // VK_FUCHSIA_external_memory

    #ifdef VK_FUCHSIA_external_memory
    DO_PFN_TEST(vkGetMemoryZirconHandlePropertiesFUCHSIA);
    #endif // VK_FUCHSIA_external_memory

    #ifdef VK_FUCHSIA_external_semaphore
    DO_PFN_TEST(vkImportSemaphoreZirconHandleFUCHSIA);
    #endif // VK_FUCHSIA_external_semaphore

    #ifdef VK_FUCHSIA_external_semaphore
    DO_PFN_TEST(vkGetSemaphoreZirconHandleFUCHSIA);
    #endif // VK_FUCHSIA_external_semaphore

    #ifdef VK_FUCHSIA_buffer_collection
    DO_PFN_TEST(vkCreateBufferCollectionFUCHSIA);
    #endif // VK_FUCHSIA_buffer_collection

    #ifdef VK_FUCHSIA_buffer_collection
    DO_PFN_TEST(vkSetBufferCollectionImageConstraintsFUCHSIA);
    #endif // VK_FUCHSIA_buffer_collection

    #ifdef VK_FUCHSIA_buffer_collection
    DO_PFN_TEST(vkSetBufferCollectionBufferConstraintsFUCHSIA);
    #endif // VK_FUCHSIA_buffer_collection

    #ifdef VK_FUCHSIA_buffer_collection
    DO_PFN_TEST(vkDestroyBufferCollectionFUCHSIA);
    #endif // VK_FUCHSIA_buffer_collection

    #ifdef VK_FUCHSIA_buffer_collection
    DO_PFN_TEST(vkGetBufferCollectionPropertiesFUCHSIA);
    #endif // VK_FUCHSIA_buffer_collection

#endif // #ifdef VULKAN_FUCHSIA_H_

#ifdef VULKAN_IOS_H_

    #ifdef VK_MVK_ios_surface
    DO_PFN_TEST(vkCreateIOSSurfaceMVK);
    #endif // VK_MVK_ios_surface

#endif // #ifdef VULKAN_IOS_H_

#ifdef VULKAN_MACOS_H_

    #ifdef VK_MVK_macos_surface
    DO_PFN_TEST(vkCreateMacOSSurfaceMVK);
    #endif // VK_MVK_macos_surface

#endif // #ifdef VULKAN_MACOS_H_

#ifdef VULKAN_METAL_H_

    #ifdef VK_EXT_metal_surface
    DO_PFN_TEST(vkCreateMetalSurfaceEXT);
    #endif // VK_EXT_metal_surface

    #ifdef VK_EXT_metal_objects
    DO_PFN_TEST(vkExportMetalObjectsEXT);
    #endif // VK_EXT_metal_objects

#endif // #ifdef VULKAN_METAL_H_

#ifdef VULKAN_VI_H_

    #ifdef VK_NN_vi_surface
    DO_PFN_TEST(vkCreateViSurfaceNN);
    #endif // VK_NN_vi_surface

#endif // #ifdef VULKAN_VI_H_

#ifdef VULKAN_WAYLAND_H_

    #ifdef VK_KHR_wayland_surface
    DO_PFN_TEST(vkCreateWaylandSurfaceKHR);
    #endif // VK_KHR_wayland_surface

    #ifdef VK_KHR_wayland_surface
    DO_PFN_TEST(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
    #endif // VK_KHR_wayland_surface

#endif // #ifdef VULKAN_WAYLAND_H_

#ifdef VULKAN_WIN32_H_

    #ifdef VK_KHR_win32_surface
    DO_PFN_TEST(vkCreateWin32SurfaceKHR);
    #endif // VK_KHR_win32_surface

    #ifdef VK_KHR_win32_surface
    DO_PFN_TEST(vkGetPhysicalDeviceWin32PresentationSupportKHR);
    #endif // VK_KHR_win32_surface

    #ifdef VK_KHR_external_memory_win32
    DO_PFN_TEST(vkGetMemoryWin32HandleKHR);
    #endif // VK_KHR_external_memory_win32

    #ifdef VK_KHR_external_memory_win32
    DO_PFN_TEST(vkGetMemoryWin32HandlePropertiesKHR);
    #endif // VK_KHR_external_memory_win32

    #ifdef VK_KHR_external_semaphore_win32
    DO_PFN_TEST(vkImportSemaphoreWin32HandleKHR);
    #endif // VK_KHR_external_semaphore_win32

    #ifdef VK_KHR_external_semaphore_win32
    DO_PFN_TEST(vkGetSemaphoreWin32HandleKHR);
    #endif // VK_KHR_external_semaphore_win32

    #ifdef VK_KHR_external_fence_win32
    DO_PFN_TEST(vkImportFenceWin32HandleKHR);
    #endif // VK_KHR_external_fence_win32

    #ifdef VK_KHR_external_fence_win32
    DO_PFN_TEST(vkGetFenceWin32HandleKHR);
    #endif // VK_KHR_external_fence_win32

    #ifdef VK_NV_external_memory_win32
    DO_PFN_TEST(vkGetMemoryWin32HandleNV);
    #endif // VK_NV_external_memory_win32

    #ifdef VK_EXT_full_screen_exclusive
    DO_PFN_TEST(vkGetPhysicalDeviceSurfacePresentModes2EXT);
    #endif // VK_EXT_full_screen_exclusive

    #ifdef VK_EXT_full_screen_exclusive
    DO_PFN_TEST(vkAcquireFullScreenExclusiveModeEXT);
    #endif // VK_EXT_full_screen_exclusive

    #ifdef VK_EXT_full_screen_exclusive
    DO_PFN_TEST(vkReleaseFullScreenExclusiveModeEXT);
    #endif // VK_EXT_full_screen_exclusive

    #ifdef VK_EXT_full_screen_exclusive
    DO_PFN_TEST(vkGetDeviceGroupSurfacePresentModes2EXT);
    #endif // VK_EXT_full_screen_exclusive

    #ifdef VK_NV_acquire_winrt_display
    DO_PFN_TEST(vkAcquireWinrtDisplayNV);
    #endif // VK_NV_acquire_winrt_display

    #ifdef VK_NV_acquire_winrt_display
    DO_PFN_TEST(vkGetWinrtDisplayNV);
    #endif // VK_NV_acquire_winrt_display

#endif // #ifdef VULKAN_WIN32_H_

#ifdef VULKAN_XCB_H_

    #ifdef VK_KHR_xcb_surface
    DO_PFN_TEST(vkCreateXcbSurfaceKHR);
    #endif // VK_KHR_xcb_surface

    #ifdef VK_KHR_xcb_surface
    DO_PFN_TEST(vkGetPhysicalDeviceXcbPresentationSupportKHR);
    #endif // VK_KHR_xcb_surface

#endif // #ifdef VULKAN_XCB_H_

#ifdef VULKAN_XLIB_H_

    #ifdef VK_KHR_xlib_surface
    DO_PFN_TEST(vkCreateXlibSurfaceKHR);
    #endif // VK_KHR_xlib_surface

    #ifdef VK_KHR_xlib_surface
    DO_PFN_TEST(vkGetPhysicalDeviceXlibPresentationSupportKHR);
    #endif // VK_KHR_xlib_surface

#endif // #ifdef VULKAN_XLIB_H_

#ifdef VULKAN_DIRECTFB_H_

    #ifdef VK_EXT_directfb_surface
    DO_PFN_TEST(vkCreateDirectFBSurfaceEXT);
    #endif // VK_EXT_directfb_surface

    #ifdef VK_EXT_directfb_surface
    DO_PFN_TEST(vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
    #endif // VK_EXT_directfb_surface

#endif // #ifdef VULKAN_DIRECTFB_H_

#ifdef VULKAN_XLIB_XRANDR_H_

    #ifdef VK_EXT_acquire_xlib_display
    DO_PFN_TEST(vkAcquireXlibDisplayEXT);
    #endif // VK_EXT_acquire_xlib_display

    #ifdef VK_EXT_acquire_xlib_display
    DO_PFN_TEST(vkGetRandROutputDisplayEXT);
    #endif // VK_EXT_acquire_xlib_display

#endif // #ifdef VULKAN_XLIB_XRANDR_H_

#ifdef VULKAN_GGP_H_

    #ifdef VK_GGP_stream_descriptor_surface
    DO_PFN_TEST(vkCreateStreamDescriptorSurfaceGGP);
    #endif // VK_GGP_stream_descriptor_surface

#endif // #ifdef VULKAN_GGP_H_

#ifdef VULKAN_SCREEN_H_

    #ifdef VK_QNX_screen_surface
    DO_PFN_TEST(vkCreateScreenSurfaceQNX);
    #endif // VK_QNX_screen_surface

    #ifdef VK_QNX_screen_surface
    DO_PFN_TEST(vkGetPhysicalDeviceScreenPresentationSupportQNX);
    #endif // VK_QNX_screen_surface

#endif // #ifdef VULKAN_SCREEN_H_

#if 1 // VULKAN_BETA_H_ // NOLINT(readability-avoid-unconditional-preprocessor-if)

    #ifdef VK_KHR_video_encode_queue
    DO_PFN_TEST(vkCmdEncodeVideoKHR);
    #endif // VK_KHR_video_encode_queue

#endif // #if 1 // VULKAN_BETA_H_

#undef DO_PFN_TEST
}

#undef STATIC_EXPECT_TRUE

} // anonymous namespace

#if defined(_MSC_VER)
    #pragma warning(pop)
#endif
