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

#include <gtest/gtest.h>

#include <core/structure_type.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))
#define STATIC_EXPECT_FALSE(x) \
    static_assert(not(x));     \
    EXPECT_FALSE((x))

#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 4883)
#endif

namespace
{

TEST(structure_type, vk_struct_concept)
{

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkApplicationInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceQueueCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkInstanceCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryAllocateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMappedMemoryRange>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWriteDescriptorSet>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyDescriptorSet>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferUsageFlags2CreateInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferViewCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryBarrier>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferMemoryBarrier>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageMemoryBarrier>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindSparseInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkShaderModuleCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetLayoutCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorPoolCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetAllocateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineShaderStageCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkComputePipelineCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_NV_device_generated_commands_compute)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkComputePipelineIndirectBufferInfoNV>) );
#endif // if defined(VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCreateFlags2CreateInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineVertexInputStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineInputAssemblyStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineTessellationStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRasterizationStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineMultisampleStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineColorBlendStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineDynamicStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineDepthStencilStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGraphicsPipelineCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCacheCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineBinaryCreateInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineBinaryHandlesInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineBinaryKeyKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineBinaryInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkReleaseCapturedPipelineDataInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineBinaryDataInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCreateInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineLayoutCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandPoolCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferAllocateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferInheritanceInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferBeginInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassBeginInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkEventCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFenceCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueryPoolCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFramebufferCreateInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubmitInfo>) );
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_KHR_display)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayModeCreateInfoKHR>) );
#endif // if defined(VK_KHR_display)

#if defined(VK_KHR_display)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplaySurfaceCreateInfoKHR>) );
#endif // if defined(VK_KHR_display)

#if defined(VK_NV_display_stereo)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplaySurfaceStereoCreateInfoNV>) );
#endif // if defined(VK_NV_display_stereo)

#if defined(VK_KHR_display_swapchain)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayPresentInfoKHR>) );
#endif // if defined(VK_KHR_display_swapchain)

#if defined(VK_KHR_android_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAndroidSurfaceCreateInfoKHR>) );
#endif // if defined(VK_KHR_android_surface)

#if defined(VK_NN_vi_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkViSurfaceCreateInfoNN>) );
#endif // if defined(VK_NN_vi_surface)

#if defined(VK_KHR_wayland_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWaylandSurfaceCreateInfoKHR>) );
#endif // if defined(VK_KHR_wayland_surface)

#if defined(VK_KHR_win32_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWin32SurfaceCreateInfoKHR>) );
#endif // if defined(VK_KHR_win32_surface)

#if defined(VK_KHR_xlib_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkXlibSurfaceCreateInfoKHR>) );
#endif // if defined(VK_KHR_xlib_surface)

#if defined(VK_KHR_xcb_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkXcbSurfaceCreateInfoKHR>) );
#endif // if defined(VK_KHR_xcb_surface)

#if defined(VK_EXT_directfb_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDirectFBSurfaceCreateInfoEXT>) );
#endif // if defined(VK_EXT_directfb_surface)

#if defined(VK_FUCHSIA_imagepipe_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImagePipeSurfaceCreateInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_imagepipe_surface)

#if defined(VK_GGP_stream_descriptor_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkStreamDescriptorSurfaceCreateInfoGGP>) );
#endif // if defined(VK_GGP_stream_descriptor_surface)

#if defined(VK_QNX_screen_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkScreenSurfaceCreateInfoQNX>) );
#endif // if defined(VK_QNX_screen_surface)

#if defined(VK_KHR_swapchain)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainCreateInfoKHR>) );
#endif // if defined(VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPresentInfoKHR>) );
#endif // if defined(VK_KHR_swapchain)

#if defined(VK_EXT_debug_report)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugReportCallbackCreateInfoEXT>) );
#endif // if defined(VK_EXT_debug_report)

#if defined(VK_EXT_validation_flags)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkValidationFlagsEXT>) );
#endif // if defined(VK_EXT_validation_flags)

#if defined(VK_EXT_validation_features)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkValidationFeaturesEXT>) );
#endif // if defined(VK_EXT_validation_features)

#if defined(VK_EXT_layer_settings)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkLayerSettingsCreateInfoEXT>) );
#endif // if defined(VK_EXT_layer_settings)

#if defined(VK_EXT_application_parameters)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkApplicationParametersEXT>) );
#endif // if defined(VK_EXT_application_parameters)

#if defined(VK_AMD_rasterization_order)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRasterizationStateRasterizationOrderAMD>) );
#endif // if defined(VK_AMD_rasterization_order)

#if defined(VK_EXT_debug_marker)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugMarkerObjectNameInfoEXT>) );
#endif // if defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugMarkerObjectTagInfoEXT>) );
#endif // if defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugMarkerMarkerInfoEXT>) );
#endif // if defined(VK_EXT_debug_marker)

#if defined(VK_NV_dedicated_allocation)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDedicatedAllocationImageCreateInfoNV>) );
#endif // if defined(VK_NV_dedicated_allocation)

#if defined(VK_NV_dedicated_allocation)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDedicatedAllocationBufferCreateInfoNV>) );
#endif // if defined(VK_NV_dedicated_allocation)

#if defined(VK_NV_dedicated_allocation)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDedicatedAllocationMemoryAllocateInfoNV>) );
#endif // if defined(VK_NV_dedicated_allocation)

#if defined(VK_NV_external_memory)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalMemoryImageCreateInfoNV>) );
#endif // if defined(VK_NV_external_memory)

#if defined(VK_NV_external_memory)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMemoryAllocateInfoNV>) );
#endif // if defined(VK_NV_external_memory)

#if defined(VK_NV_external_memory_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemoryWin32HandleInfoNV>) );
#endif // if defined(VK_NV_external_memory_win32)

#if defined(VK_NV_external_memory_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMemoryWin32HandleInfoNV>) );
#endif // if defined(VK_NV_external_memory_win32)

#if defined(VK_NV_external_memory_sci_buf)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMemorySciBufInfoNV>) );
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemorySciBufInfoNV>) );
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryGetSciBufInfoNV>) );
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemorySciBufPropertiesNV>) );
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalMemorySciBufFeaturesNV>) );
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_win32_keyed_mutex)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWin32KeyedMutexAcquireReleaseInfoNV>) );
#endif // if defined(VK_NV_win32_keyed_mutex)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands_compute)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>) );
#endif // if defined(VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDevicePrivateDataCreateInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPrivateDataSlotCreateInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePrivateDataFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceClusterAccelerationStructurePropertiesNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkClusterAccelerationStructureClustersBottomLevelInputNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkClusterAccelerationStructureTriangleClusterInputNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkClusterAccelerationStructureMoveObjectsInputNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkClusterAccelerationStructureInputInfoNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkClusterAccelerationStructureCommandsInfoNV>) );
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_EXT_multi_draw)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultiDrawPropertiesEXT>) );
#endif // if defined(VK_EXT_multi_draw)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGraphicsShaderGroupCreateInfoNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGraphicsPipelineShaderGroupsCreateInfoNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectCommandsLayoutTokenNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectCommandsLayoutCreateInfoNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeneratedCommandsInfoNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeneratedCommandsMemoryRequirementsInfoNV>) );
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands_compute)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineIndirectDeviceAddressInfoNV>) );
#endif // if defined(VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFeatures2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceProperties2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFormatProperties2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageFormatProperties2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageFormatInfo2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueueFamilyProperties2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMemoryProperties2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSparseImageFormatProperties2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSparseImageFormatInfo2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePushDescriptorProperties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDriverProperties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_KHR_incremental_present)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPresentRegionsKHR>) );
#endif // if defined(VK_KHR_incremental_present)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVariablePointersFeatures>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalImageFormatInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalImageFormatProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalBufferInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalBufferProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceIDProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalMemoryImageCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalMemoryBufferCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMemoryAllocateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_external_memory_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemoryWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMemoryWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_FUCHSIA_external_memory)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemoryZirconHandleInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryZirconHandlePropertiesFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryGetZirconHandleInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_external_memory)

#if defined(VK_KHR_external_memory_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryWin32HandlePropertiesKHR>) );
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryGetWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemoryFdInfoKHR>) );
#endif // if defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryFdPropertiesKHR>) );
#endif // if defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryGetFdInfoKHR>) );
#endif // if defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_win32_keyed_mutex)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWin32KeyedMutexAcquireReleaseInfoKHR>) );
#endif // if defined(VK_KHR_win32_keyed_mutex)

#if defined(VK_EXT_external_memory_metal)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemoryMetalHandleInfoEXT>) );
#endif // if defined(VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryMetalHandlePropertiesEXT>) );
#endif // if defined(VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryGetMetalHandleInfoEXT>) );
#endif // if defined(VK_EXT_external_memory_metal)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalSemaphoreInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalSemaphoreProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportSemaphoreCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_external_semaphore_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportSemaphoreWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportSemaphoreWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkD3D12FenceSubmitInfoKHR>) );
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreGetWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportSemaphoreFdInfoKHR>) );
#endif // if defined(VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_external_semaphore_fd)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreGetFdInfoKHR>) );
#endif // if defined(VK_KHR_external_semaphore_fd)

#if defined(VK_FUCHSIA_external_semaphore)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportSemaphoreZirconHandleInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_external_semaphore)

#if defined(VK_FUCHSIA_external_semaphore)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreGetZirconHandleInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_external_semaphore)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalFenceInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalFenceProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportFenceCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_external_fence_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportFenceWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportFenceWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFenceGetWin32HandleInfoKHR>) );
#endif // if defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportFenceFdInfoKHR>) );
#endif // if defined(VK_KHR_external_fence_fd)

#if defined(VK_KHR_external_fence_fd)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFenceGetFdInfoKHR>) );
#endif // if defined(VK_KHR_external_fence_fd)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportFenceSciSyncInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportFenceSciSyncInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFenceGetSciSyncInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportSemaphoreSciSyncInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportSemaphoreSciSyncInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreGetSciSyncInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSciSyncAttributesInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalSciSyncFeaturesNV>) );
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalSciSync2FeaturesNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreSciSyncPoolCreateInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreSciSyncCreateInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV>) );
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultiviewFeatures>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultiviewProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassMultiviewCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_EXT_display_surface_counter)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceCapabilities2EXT>) );
#endif // if defined(VK_EXT_display_surface_counter)

#if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayPowerInfoEXT>) );
#endif // if defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceEventInfoEXT>) );
#endif // if defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayEventInfoEXT>) );
#endif // if defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainCounterCreateInfoEXT>) );
#endif // if defined(VK_EXT_display_control)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceGroupProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryAllocateFlagsInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindBufferMemoryInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindBufferMemoryDeviceGroupInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindImageMemoryInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindImageMemoryDeviceGroupInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupRenderPassBeginInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupCommandBufferBeginInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupSubmitInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupBindSparseInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_device_group)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupPresentCapabilitiesKHR>) );
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageSwapchainCreateInfoKHR>) );
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindImageMemorySwapchainInfoKHR>) );
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAcquireNextImageInfoKHR>) );
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupPresentInfoKHR>) );
#endif // if defined(VK_KHR_device_group)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupDeviceCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_device_group)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceGroupSwapchainCreateInfoKHR>) );
#endif // if defined(VK_KHR_device_group)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorUpdateTemplateCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_present_id)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePresentIdFeaturesKHR>) );
#endif // if defined(VK_KHR_present_id)

#if defined(VK_KHR_present_id)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPresentIdKHR>) );
#endif // if defined(VK_KHR_present_id)

#if defined(VK_KHR_present_wait)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePresentWaitFeaturesKHR>) );
#endif // if defined(VK_KHR_present_wait)

#if defined(VK_EXT_hdr_metadata)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkHdrMetadataEXT>) );
#endif // if defined(VK_EXT_hdr_metadata)

#if defined(VK_HUAWEI_hdr_vivid)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkHdrVividDynamicMetadataHUAWEI>) );
#endif // if defined(VK_HUAWEI_hdr_vivid)

#if defined(VK_AMD_display_native_hdr)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayNativeHdrSurfaceCapabilitiesAMD>) );
#endif // if defined(VK_AMD_display_native_hdr)

#if defined(VK_AMD_display_native_hdr)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainDisplayNativeHdrCreateInfoAMD>) );
#endif // if defined(VK_AMD_display_native_hdr)

#if defined(VK_GOOGLE_display_timing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPresentTimesInfoGOOGLE>) );
#endif // if defined(VK_GOOGLE_display_timing)

#if defined(VK_MVK_ios_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIOSSurfaceCreateInfoMVK>) );
#endif // if defined(VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMacOSSurfaceCreateInfoMVK>) );
#endif // if defined(VK_MVK_macos_surface)

#if defined(VK_EXT_metal_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMetalSurfaceCreateInfoEXT>) );
#endif // if defined(VK_EXT_metal_surface)

#if defined(VK_NV_clip_space_w_scaling)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportWScalingStateCreateInfoNV>) );
#endif // if defined(VK_NV_clip_space_w_scaling)

#if defined(VK_NV_viewport_swizzle)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportSwizzleStateCreateInfoNV>) );
#endif // if defined(VK_NV_viewport_swizzle)

#if defined(VK_EXT_discard_rectangles)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDiscardRectanglePropertiesEXT>) );
#endif // if defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineDiscardRectangleStateCreateInfoEXT>) );
#endif // if defined(VK_EXT_discard_rectangles)

#if defined(VK_NVX_multiview_per_view_attributes)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>) );
#endif // if defined(VK_NVX_multiview_per_view_attributes)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassInputAttachmentAspectCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_get_surface_capabilities2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSurfaceInfo2KHR>) );
#endif // if defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceCapabilities2KHR>) );
#endif // if defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceFormat2KHR>) );
#endif // if defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_display_properties2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayProperties2KHR>) );
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayPlaneProperties2KHR>) );
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayModeProperties2KHR>) );
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_NV_display_stereo)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayModeStereoPropertiesNV>) );
#endif // if defined(VK_NV_display_stereo)

#if defined(VK_KHR_get_display_properties2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayPlaneInfo2KHR>) );
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDisplayPlaneCapabilities2KHR>) );
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_shared_presentable_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSharedPresentSurfaceCapabilitiesKHR>) );
#endif // if defined(VK_KHR_shared_presentable_image)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevice16BitStorageFeatures>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSubgroupProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferMemoryRequirementsInfo2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceBufferMemoryRequirements>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageMemoryRequirementsInfo2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageSparseMemoryRequirementsInfo2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceImageMemoryRequirements>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryRequirements2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSparseImageMemoryRequirements2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePointClippingProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryDedicatedRequirements>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryDedicatedAllocateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewUsageCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_EXT_image_sliced_view_of_3d)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewSlicedCreateInfoEXT>) );
#endif // if defined(VK_EXT_image_sliced_view_of_3d)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineTessellationDomainOriginStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerYcbcrConversionInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerYcbcrConversionCreateInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindImagePlaneMemoryInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImagePlaneMemoryRequirementsInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSamplerYcbcrConversionFeatures>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerYcbcrConversionImageFormatProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_AMD_texture_gather_bias_lod)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkTextureLODGatherFormatPropertiesAMD>) );
#endif // if defined(VK_AMD_texture_gather_bias_lod)

#if defined(VK_EXT_conditional_rendering)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkConditionalRenderingBeginInfoEXT>) );
#endif // if defined(VK_EXT_conditional_rendering)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkProtectedSubmitInfo>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceProtectedMemoryFeatures>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceProtectedMemoryProperties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceQueueInfo2>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_NV_fragment_coverage_to_color)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCoverageToColorStateCreateInfoNV>) );
#endif // if defined(VK_NV_fragment_coverage_to_color)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSamplerFilterMinmaxProperties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_sample_locations)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSampleLocationsInfoEXT>) );
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassSampleLocationsBeginInfoEXT>) );
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineSampleLocationsStateCreateInfoEXT>) );
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSampleLocationsPropertiesEXT>) );
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMultisamplePropertiesEXT>) );
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerReductionModeCreateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_blend_operation_advanced)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>) );
#endif // if defined(VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_multi_draw)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultiDrawFeaturesEXT>) );
#endif // if defined(VK_EXT_multi_draw)

#if defined(VK_EXT_blend_operation_advanced)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>) );
#endif // if defined(VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineColorBlendAdvancedStateCreateInfoEXT>) );
#endif // if defined(VK_EXT_blend_operation_advanced)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceInlineUniformBlockFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceInlineUniformBlockProperties>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWriteDescriptorSetInlineUniformBlock>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorPoolInlineUniformBlockCreateInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_framebuffer_mixed_samples)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCoverageModulationStateCreateInfoNV>) );
#endif // if defined(VK_NV_framebuffer_mixed_samples)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageFormatListCreateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_validation_cache)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkValidationCacheCreateInfoEXT>) );
#endif // if defined(VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkShaderModuleValidationCacheCreateInfoEXT>) );
#endif // if defined(VK_EXT_validation_cache)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance3Properties>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance4Features>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance4Properties>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance5Features>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance5Properties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance6Features>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance6Properties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_maintenance7)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance7FeaturesKHR>) );
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance7PropertiesKHR>) );
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLayeredApiPropertiesListKHR>) );
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLayeredApiPropertiesKHR>) );
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLayeredApiVulkanPropertiesKHR>) );
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance8)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMaintenance8FeaturesKHR>) );
#endif // if defined(VK_KHR_maintenance8)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderingAreaInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetLayoutSupport>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderDrawParametersFeatures>) );
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderFloat16Int8Features>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFloatControlsProperties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceHostQueryResetFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_ANDROID_native_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkNativeBufferANDROID>) );
#endif // if defined(VK_ANDROID_native_buffer)

#if defined(VK_ANDROID_native_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainImageCreateInfoANDROID>) );
#endif // if defined(VK_ANDROID_native_buffer)

#if defined(VK_ANDROID_native_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePresentationPropertiesANDROID>) );
#endif // if defined(VK_ANDROID_native_buffer)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceQueueGlobalPriorityCreateInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceGlobalPriorityQueryFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueueFamilyGlobalPriorityProperties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_debug_utils)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugUtilsObjectNameInfoEXT>) );
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugUtilsObjectTagInfoEXT>) );
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugUtilsLabelEXT>) );
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugUtilsMessengerCreateInfoEXT>) );
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDebugUtilsMessengerCallbackDataEXT>) );
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_device_memory_report)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>) );
#endif // if defined(VK_EXT_device_memory_report)

#if defined(VK_EXT_device_memory_report)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceDeviceMemoryReportCreateInfoEXT>) );
#endif // if defined(VK_EXT_device_memory_report)

#if defined(VK_EXT_device_memory_report)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceMemoryReportCallbackDataEXT>) );
#endif // if defined(VK_EXT_device_memory_report)

#if defined(VK_EXT_external_memory_host)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemoryHostPointerInfoEXT>) );
#endif // if defined(VK_EXT_external_memory_host)

#if defined(VK_EXT_external_memory_host)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryHostPointerPropertiesEXT>) );
#endif // if defined(VK_EXT_external_memory_host)

#if defined(VK_EXT_external_memory_host)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalMemoryHostPropertiesEXT>) );
#endif // if defined(VK_EXT_external_memory_host)

#if defined(VK_EXT_conservative_rasterization)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceConservativeRasterizationPropertiesEXT>) );
#endif // if defined(VK_EXT_conservative_rasterization)

#if defined(VK_KHR_calibrated_timestamps)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCalibratedTimestampInfoKHR>) );
#endif // if defined(VK_KHR_calibrated_timestamps)

#if defined(VK_AMD_shader_core_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderCorePropertiesAMD>) );
#endif // if defined(VK_AMD_shader_core_properties)

#if defined(VK_AMD_shader_core_properties2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderCoreProperties2AMD>) );
#endif // if defined(VK_AMD_shader_core_properties2)

#if defined(VK_EXT_conservative_rasterization)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRasterizationConservativeStateCreateInfoEXT>) );
#endif // if defined(VK_EXT_conservative_rasterization)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDescriptorIndexingFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDescriptorIndexingProperties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetLayoutBindingFlagsCreateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetVariableDescriptorCountAllocateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetVariableDescriptorCountLayoutSupport>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAttachmentDescription2>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAttachmentReference2>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassDescription2>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassDependency2>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassCreateInfo2>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassBeginInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassEndInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTimelineSemaphoreFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTimelineSemaphoreProperties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreTypeCreateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkTimelineSemaphoreSubmitInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreWaitInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreSignalInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineVertexInputDivisorStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_vertex_attribute_divisor)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>) );
#endif // if defined(VK_EXT_vertex_attribute_divisor)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVertexAttributeDivisorProperties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_pci_bus_info)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePCIBusInfoPropertiesEXT>) );
#endif // if defined(VK_EXT_pci_bus_info)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportAndroidHardwareBufferInfoANDROID>) );
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAndroidHardwareBufferUsageANDROID>) );
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAndroidHardwareBufferPropertiesANDROID>) );
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryGetAndroidHardwareBufferInfoANDROID>) );
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAndroidHardwareBufferFormatPropertiesANDROID>) );
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_EXT_conditional_rendering)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferInheritanceConditionalRenderingInfoEXT>) );
#endif // if defined(VK_EXT_conditional_rendering)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalFormatANDROID>) );
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevice8BitStorageFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_conditional_rendering)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceConditionalRenderingFeaturesEXT>) );
#endif // if defined(VK_EXT_conditional_rendering)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkanMemoryModelFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderAtomicInt64Features>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_shader_atomic_float)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>) );
#endif // if defined(VK_EXT_shader_atomic_float)

#if defined(VK_EXT_shader_atomic_float2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>) );
#endif // if defined(VK_EXT_shader_atomic_float2)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVertexAttributeDivisorFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_NV_device_diagnostic_checkpoints)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueueFamilyCheckpointPropertiesNV>) );
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCheckpointDataNV>) );
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDepthStencilResolveProperties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassDescriptionDepthStencilResolve>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_astc_decode_mode)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewASTCDecodeModeEXT>) );
#endif // if defined(VK_EXT_astc_decode_mode)

#if defined(VK_EXT_astc_decode_mode)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceASTCDecodeFeaturesEXT>) );
#endif // if defined(VK_EXT_astc_decode_mode)

#if defined(VK_EXT_transform_feedback)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTransformFeedbackFeaturesEXT>) );
#endif // if defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTransformFeedbackPropertiesEXT>) );
#endif // if defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRasterizationStateStreamCreateInfoEXT>) );
#endif // if defined(VK_EXT_transform_feedback)

#if defined(VK_NV_representative_fragment_test)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>) );
#endif // if defined(VK_NV_representative_fragment_test)

#if defined(VK_NV_representative_fragment_test)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRepresentativeFragmentTestStateCreateInfoNV>) );
#endif // if defined(VK_NV_representative_fragment_test)

#if defined(VK_NV_scissor_exclusive)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExclusiveScissorFeaturesNV>) );
#endif // if defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_scissor_exclusive)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportExclusiveScissorStateCreateInfoNV>) );
#endif // if defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_corner_sampled_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCornerSampledImageFeaturesNV>) );
#endif // if defined(VK_NV_corner_sampled_image)

#if defined(VK_KHR_compute_shader_derivatives)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>) );
#endif // if defined(VK_KHR_compute_shader_derivatives)

#if defined(VK_KHR_compute_shader_derivatives)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR>) );
#endif // if defined(VK_KHR_compute_shader_derivatives)

#if defined(VK_NV_shader_image_footprint)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderImageFootprintFeaturesNV>) );
#endif // if defined(VK_NV_shader_image_footprint)

#if defined(VK_NV_dedicated_allocation_image_aliasing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>) );
#endif // if defined(VK_NV_dedicated_allocation_image_aliasing)

#if defined(VK_NV_copy_memory_indirect)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>) );
#endif // if defined(VK_NV_copy_memory_indirect)

#if defined(VK_NV_copy_memory_indirect)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCopyMemoryIndirectPropertiesNV>) );
#endif // if defined(VK_NV_copy_memory_indirect)

#if defined(VK_NV_memory_decompression)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMemoryDecompressionFeaturesNV>) );
#endif // if defined(VK_NV_memory_decompression)

#if defined(VK_NV_memory_decompression)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMemoryDecompressionPropertiesNV>) );
#endif // if defined(VK_NV_memory_decompression)

#if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportShadingRateImageStateCreateInfoNV>) );
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShadingRateImageFeaturesNV>) );
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShadingRateImagePropertiesNV>) );
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_HUAWEI_invocation_mask)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>) );
#endif // if defined(VK_HUAWEI_invocation_mask)

#if defined(VK_NV_shading_rate_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>) );
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_NV_mesh_shader)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMeshShaderFeaturesNV>) );
#endif // if defined(VK_NV_mesh_shader)

#if defined(VK_NV_mesh_shader)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMeshShaderPropertiesNV>) );
#endif // if defined(VK_NV_mesh_shader)

#if defined(VK_EXT_mesh_shader)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMeshShaderFeaturesEXT>) );
#endif // if defined(VK_EXT_mesh_shader)

#if defined(VK_EXT_mesh_shader)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMeshShaderPropertiesEXT>) );
#endif // if defined(VK_EXT_mesh_shader)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRayTracingShaderGroupCreateInfoNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRayTracingShaderGroupCreateInfoKHR>) );
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRayTracingPipelineCreateInfoNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRayTracingPipelineCreateInfoKHR>) );
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeometryTrianglesNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeometryAABBNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeometryNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureInfoNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureCreateInfoNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindAccelerationStructureMemoryInfoNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWriteDescriptorSetAccelerationStructureKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWriteDescriptorSetAccelerationStructureNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureMemoryRequirementsInfoNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceAccelerationStructureFeaturesKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingPipelineFeaturesKHR>) );
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayQueryFeaturesKHR>) );
#endif // if defined(VK_KHR_ray_query)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceAccelerationStructurePropertiesKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingPipelinePropertiesKHR>) );
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingPropertiesNV>) );
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>) );
#endif // if defined(VK_KHR_ray_tracing_maintenance1)

#if defined(VK_EXT_image_drm_format_modifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDrmFormatModifierPropertiesListEXT>) );
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageDrmFormatModifierInfoEXT>) );
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageDrmFormatModifierListCreateInfoEXT>) );
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageDrmFormatModifierExplicitCreateInfoEXT>) );
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageDrmFormatModifierPropertiesEXT>) );
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageStencilUsageCreateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_AMD_memory_overallocation_behavior)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceMemoryOverallocationCreateInfoAMD>) );
#endif // if defined(VK_AMD_memory_overallocation_behavior)

#if defined(VK_EXT_fragment_density_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentDensityMapFeaturesEXT>) );
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_EXT_fragment_density_map2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>) );
#endif // if defined(VK_EXT_fragment_density_map2)

#if defined(VK_QCOM_fragment_density_map_offset)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>) );
#endif // if defined(VK_QCOM_fragment_density_map_offset)

#if defined(VK_EXT_fragment_density_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentDensityMapPropertiesEXT>) );
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_EXT_fragment_density_map2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>) );
#endif // if defined(VK_EXT_fragment_density_map2)

#if defined(VK_QCOM_fragment_density_map_offset)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>) );
#endif // if defined(VK_QCOM_fragment_density_map_offset)

#if defined(VK_EXT_fragment_density_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassFragmentDensityMapCreateInfoEXT>) );
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_QCOM_fragment_density_map_offset)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassFragmentDensityMapOffsetEndInfoQCOM>) );
#endif // if defined(VK_QCOM_fragment_density_map_offset)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceScalarBlockLayoutFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_KHR_surface_protected_capabilities)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceProtectedCapabilitiesKHR>) );
#endif // if defined(VK_KHR_surface_protected_capabilities)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceUniformBufferStandardLayoutFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_depth_clip_enable)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDepthClipEnableFeaturesEXT>) );
#endif // if defined(VK_EXT_depth_clip_enable)

#if defined(VK_EXT_depth_clip_enable)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRasterizationDepthClipStateCreateInfoEXT>) );
#endif // if defined(VK_EXT_depth_clip_enable)

#if defined(VK_EXT_memory_budget)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMemoryBudgetPropertiesEXT>) );
#endif // if defined(VK_EXT_memory_budget)

#if defined(VK_EXT_memory_priority)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMemoryPriorityFeaturesEXT>) );
#endif // if defined(VK_EXT_memory_priority)

#if defined(VK_EXT_memory_priority)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryPriorityAllocateInfoEXT>) );
#endif // if defined(VK_EXT_memory_priority)

#if defined(VK_EXT_pageable_device_local_memory)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>) );
#endif // if defined(VK_EXT_pageable_device_local_memory)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceBufferDeviceAddressFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_buffer_device_address)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>) );
#endif // if defined(VK_EXT_buffer_device_address)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferDeviceAddressInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferOpaqueCaptureAddressCreateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_buffer_device_address)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferDeviceAddressCreateInfoEXT>) );
#endif // if defined(VK_EXT_buffer_device_address)

#if defined(VK_EXT_filter_cubic)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageViewImageFormatInfoEXT>) );
#endif // if defined(VK_EXT_filter_cubic)

#if defined(VK_EXT_filter_cubic)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFilterCubicImageViewImageFormatPropertiesEXT>) );
#endif // if defined(VK_EXT_filter_cubic)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImagelessFramebufferFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFramebufferAttachmentsCreateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFramebufferAttachmentImageInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassAttachmentBeginInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTextureCompressionASTCHDRFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_cooperative_matrix)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeMatrixFeaturesNV>) );
#endif // if defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_cooperative_matrix)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeMatrixPropertiesNV>) );
#endif // if defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_cooperative_matrix)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCooperativeMatrixPropertiesNV>) );
#endif // if defined(VK_NV_cooperative_matrix)

#if defined(VK_EXT_ycbcr_image_arrays)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>) );
#endif // if defined(VK_EXT_ycbcr_image_arrays)

#if defined(VK_NVX_image_view_handle)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewHandleInfoNVX>) );
#endif // if defined(VK_NVX_image_view_handle)

#if defined(VK_NVX_image_view_handle)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewAddressPropertiesNVX>) );
#endif // if defined(VK_NVX_image_view_handle)

#if defined(VK_GGP_frame_token)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPresentFrameTokenGGP>) );
#endif // if defined(VK_GGP_frame_token)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCreationFeedbackCreateInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_full_screen_exclusive)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceFullScreenExclusiveInfoEXT>) );
#endif // if defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceFullScreenExclusiveWin32InfoEXT>) );
#endif // if defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceCapabilitiesFullScreenExclusiveEXT>) );
#endif // if defined(VK_EXT_full_screen_exclusive)

#if defined(VK_NV_present_barrier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePresentBarrierFeaturesNV>) );
#endif // if defined(VK_NV_present_barrier)

#if defined(VK_NV_present_barrier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfaceCapabilitiesPresentBarrierNV>) );
#endif // if defined(VK_NV_present_barrier)

#if defined(VK_NV_present_barrier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainPresentBarrierCreateInfoNV>) );
#endif // if defined(VK_NV_present_barrier)

#if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePerformanceQueryFeaturesKHR>) );
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePerformanceQueryPropertiesKHR>) );
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceCounterKHR>) );
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceCounterDescriptionKHR>) );
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueryPoolPerformanceCreateInfoKHR>) );
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAcquireProfilingLockInfoKHR>) );
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceQuerySubmitInfoKHR>) );
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    // STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceQueryReservationInfoKHR>));
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_EXT_headless_surface)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkHeadlessSurfaceCreateInfoEXT>) );
#endif // if defined(VK_EXT_headless_surface)

#if defined(VK_NV_coverage_reduction_mode)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCoverageReductionModeFeaturesNV>) );
#endif // if defined(VK_NV_coverage_reduction_mode)

#if defined(VK_NV_coverage_reduction_mode)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCoverageReductionStateCreateInfoNV>) );
#endif // if defined(VK_NV_coverage_reduction_mode)

#if defined(VK_NV_coverage_reduction_mode)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFramebufferMixedSamplesCombinationNV>) );
#endif // if defined(VK_NV_coverage_reduction_mode)

#if defined(VK_INTEL_shader_integer_functions2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>) );
#endif // if defined(VK_INTEL_shader_integer_functions2)

#if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkInitializePerformanceApiInfoINTEL>) );
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueryPoolPerformanceQueryCreateInfoINTEL>) );
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceMarkerInfoINTEL>) );
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceStreamMarkerInfoINTEL>) );
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceOverrideInfoINTEL>) );
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPerformanceConfigurationAcquireInfoINTEL>) );
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_KHR_shader_clock)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderClockFeaturesKHR>) );
#endif // if defined(VK_KHR_shader_clock)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceIndexTypeUint8Features>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_NV_shader_sm_builtins)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>) );
#endif // if defined(VK_NV_shader_sm_builtins)

#if defined(VK_NV_shader_sm_builtins)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>) );
#endif // if defined(VK_NV_shader_sm_builtins)

#if defined(VK_EXT_fragment_shader_interlock)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>) );
#endif // if defined(VK_EXT_fragment_shader_interlock)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAttachmentReferenceStencilLayout>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_primitive_topology_list_restart)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>) );
#endif // if defined(VK_EXT_primitive_topology_list_restart)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAttachmentDescriptionStencilLayout>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>) );
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineExecutablePropertiesKHR>) );
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineExecutableInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineExecutableStatisticKHR>) );
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineExecutableInternalRepresentationKHR>) );
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_texel_buffer_alignment)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>) );
#endif // if defined(VK_EXT_texel_buffer_alignment)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTexelBufferAlignmentProperties>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSubgroupSizeControlFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSubgroupSizeControlProperties>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_HUAWEI_subpass_shading)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassShadingPipelineCreateInfoHUAWEI>) );
#endif // if defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_subpass_shading)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSubpassShadingPropertiesHUAWEI>) );
#endif // if defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_cluster_culling_shader)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI>) );
#endif // if defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryOpaqueCaptureAddressAllocateInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceMemoryOpaqueCaptureAddressInfo>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLineRasterizationFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLineRasterizationProperties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRasterizationLineStateCreateInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineCreationCacheControlFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan11Features>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan11Properties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan12Features>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan12Properties>) );
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan13Features>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan13Properties>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan14Features>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkan14Properties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_AMD_pipeline_compiler_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineCompilerControlCreateInfoAMD>) );
#endif // if defined(VK_AMD_pipeline_compiler_control)

#if defined(VK_AMD_device_coherent_memory)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCoherentMemoryFeaturesAMD>) );
#endif // if defined(VK_AMD_device_coherent_memory)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFaultData>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFaultCallbackInfo>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceToolProperties>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_custom_border_color)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerCustomBorderColorCreateInfoEXT>) );
#endif // if defined(VK_EXT_custom_border_color)

#if defined(VK_EXT_custom_border_color)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCustomBorderColorPropertiesEXT>) );
#endif // if defined(VK_EXT_custom_border_color)

#if defined(VK_EXT_custom_border_color)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCustomBorderColorFeaturesEXT>) );
#endif // if defined(VK_EXT_custom_border_color)

#if defined(VK_EXT_border_color_swizzle)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerBorderColorComponentMappingCreateInfoEXT>) );
#endif // if defined(VK_EXT_border_color_swizzle)

#if defined(VK_EXT_border_color_swizzle)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>) );
#endif // if defined(VK_EXT_border_color_swizzle)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureGeometryTrianglesDataKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureGeometryAabbsDataKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureGeometryInstancesDataKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureGeometryLinearSweptSpheresDataNV>) );
#endif // if defined(VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureGeometrySpheresDataNV>) );
#endif // if defined(VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureGeometryKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureBuildGeometryInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureCreateInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureDeviceAddressInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureVersionInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyAccelerationStructureInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyAccelerationStructureToMemoryInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyMemoryToAccelerationStructureInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRayTracingPipelineInterfaceCreateInfoKHR>) );
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_pipeline_library)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineLibraryCreateInfoKHR>) );
#endif // if defined(VK_KHR_pipeline_library)

#if defined(VK_KHR_object_refresh)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRefreshObjectListKHR>) );
#endif // if defined(VK_KHR_object_refresh)

#if defined(VK_EXT_extended_dynamic_state)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>) );
#endif // if defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>) );
#endif // if defined(VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>) );
#endif // if defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExtendedDynamicState3PropertiesEXT>) );
#endif // if defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_QCOM_render_pass_transform)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassTransformBeginInfoQCOM>) );
#endif // if defined(VK_QCOM_render_pass_transform)

#if defined(VK_QCOM_rotated_copy_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyCommandTransformInfoQCOM>) );
#endif // if defined(VK_QCOM_rotated_copy_commands)

#if defined(VK_QCOM_render_pass_transform)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferInheritanceRenderPassTransformInfoQCOM>) );
#endif // if defined(VK_QCOM_render_pass_transform)

#if defined(VK_NV_partitioned_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>) );
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV>) );
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPartitionedAccelerationStructureFlagsNV>) );
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWriteDescriptorSetPartitionedAccelerationStructureNV>) );
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPartitionedAccelerationStructureInstancesInputNV>) );
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBuildPartitionedAccelerationStructureInfoNV>) );
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_device_diagnostics_config)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDiagnosticsConfigFeaturesNV>) );
#endif // if defined(VK_NV_device_diagnostics_config)

#if defined(VK_NV_device_diagnostics_config)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceDiagnosticsConfigCreateInfoNV>) );
#endif // if defined(VK_NV_device_diagnostics_config)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineOfflineCreateInfo>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_shader_subgroup_uniform_control_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>) );
#endif // if defined(VK_KHR_shader_subgroup_uniform_control_flow)

#if defined(VK_EXT_robustness2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRobustness2FeaturesEXT>) );
#endif // if defined(VK_EXT_robustness2)

#if defined(VK_EXT_robustness2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRobustness2PropertiesEXT>) );
#endif // if defined(VK_EXT_robustness2)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageRobustnessFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_workgroup_memory_explicit_layout)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>) );
#endif // if defined(VK_KHR_workgroup_memory_explicit_layout)

#if defined(VK_KHR_portability_subset) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePortabilitySubsetFeaturesKHR>) );
#endif // if defined(VK_KHR_portability_subset)

#if defined(VK_KHR_portability_subset) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePortabilitySubsetPropertiesKHR>) );
#endif // if defined(VK_KHR_portability_subset)

#if defined(VK_EXT_4444_formats)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevice4444FormatsFeaturesEXT>) );
#endif // if defined(VK_EXT_4444_formats)

#if defined(VK_HUAWEI_subpass_shading)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>) );
#endif // if defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_cluster_culling_shader)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>) );
#endif // if defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_HUAWEI_cluster_culling_shader)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI>) );
#endif // if defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCopy2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageCopy2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageBlit2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferImageCopy2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageResolve2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyBufferInfo2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyImageInfo2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBlitImageInfo2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyBufferToImageInfo2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyImageToBufferInfo2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkResolveImageInfo2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_shader_image_atomic_int64)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>) );
#endif // if defined(VK_EXT_shader_image_atomic_int64)

#if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFragmentShadingRateAttachmentInfoKHR>) );
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineFragmentShadingRateStateCreateInfoKHR>) );
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShadingRateFeaturesKHR>) );
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShadingRatePropertiesKHR>) );
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShadingRateKHR>) );
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderTerminateInvocationFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_fragment_shading_rate_enums)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>) );
#endif // if defined(VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>) );
#endif // if defined(VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineFragmentShadingRateEnumStateCreateInfoNV>) );
#endif // if defined(VK_NV_fragment_shading_rate_enums)

#if defined(VK_KHR_acceleration_structure)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureBuildSizesInfoKHR>) );
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_EXT_image_2d_view_of_3d)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>) );
#endif // if defined(VK_EXT_image_2d_view_of_3d)

#if defined(VK_EXT_image_sliced_view_of_3d)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>) );
#endif // if defined(VK_EXT_image_sliced_view_of_3d)

#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>) );
#endif // if defined(VK_EXT_attachment_feedback_loop_dynamic_state)

#if defined(VK_EXT_legacy_vertex_attributes)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>) );
#endif // if defined(VK_EXT_legacy_vertex_attributes)

#if defined(VK_EXT_legacy_vertex_attributes)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT>) );
#endif // if defined(VK_EXT_legacy_vertex_attributes)

#if defined(VK_EXT_mutable_descriptor_type)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>) );
#endif // if defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_EXT_mutable_descriptor_type)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMutableDescriptorTypeCreateInfoEXT>) );
#endif // if defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_EXT_depth_clip_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDepthClipControlFeaturesEXT>) );
#endif // if defined(VK_EXT_depth_clip_control)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeneratedCommandsPipelineInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeneratedCommandsShaderInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeneratedCommandsMemoryRequirementsInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectExecutionSetPipelineInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectExecutionSetShaderLayoutInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectExecutionSetShaderInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectExecutionSetCreateInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGeneratedCommandsInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWriteIndirectExecutionSetPipelineEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkWriteIndirectExecutionSetShaderEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectCommandsLayoutCreateInfoEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkIndirectCommandsLayoutTokenEXT>) );
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_depth_clip_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportDepthClipControlCreateInfoEXT>) );
#endif // if defined(VK_EXT_depth_clip_control)

#if defined(VK_EXT_depth_clamp_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDepthClampControlFeaturesEXT>) );
#endif // if defined(VK_EXT_depth_clamp_control)

#if defined(VK_EXT_depth_clamp_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineViewportDepthClampControlCreateInfoEXT>) );
#endif // if defined(VK_EXT_depth_clamp_control)

#if defined(VK_EXT_vertex_input_dynamic_state)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>) );
#endif // if defined(VK_EXT_vertex_input_dynamic_state)

#if defined(VK_NV_external_memory_rdma)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>) );
#endif // if defined(VK_NV_external_memory_rdma)

#if defined(VK_KHR_shader_relaxed_extended_instruction)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>) );
#endif // if defined(VK_KHR_shader_relaxed_extended_instruction)

#if defined(VK_EXT_shader_object)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVertexInputBindingDescription2EXT>) );
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVertexInputAttributeDescription2EXT>) );
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_color_write_enable)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceColorWriteEnableFeaturesEXT>) );
#endif // if defined(VK_EXT_color_write_enable)

#if defined(VK_EXT_color_write_enable)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineColorWriteCreateInfoEXT>) );
#endif // if defined(VK_EXT_color_write_enable)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryBarrier2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageMemoryBarrier2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferMemoryBarrier2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_maintenance8)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryBarrierAccessFlags3KHR>) );
#endif // if defined(VK_KHR_maintenance8)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDependencyInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSemaphoreSubmitInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferSubmitInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubmitInfo2>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_device_diagnostic_checkpoints)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueueFamilyCheckpointProperties2NV>) );
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCheckpointData2NV>) );
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSynchronization2Features>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceHostImageCopyFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceHostImageCopyProperties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryToImageCopy>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageToMemoryCopy>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyMemoryToImageInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyImageToMemoryInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyImageToImageInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkHostImageLayoutTransitionInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubresourceHostMemcpySize>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkHostImageCopyDevicePerformanceQuery>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkanSC10Properties>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelinePoolSize>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceObjectReservationCreateInfo>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandPoolMemoryReservationCreateInfo>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandPoolMemoryConsumption>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVulkanSC10Features>) );
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VK_EXT_primitives_generated_query)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>) );
#endif // if defined(VK_EXT_primitives_generated_query)

#if defined(VK_EXT_legacy_dithering)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLegacyDitheringFeaturesEXT>) );
#endif // if defined(VK_EXT_legacy_dithering)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>) );
#endif // if defined(VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubpassResolvePerformanceQueryEXT>) );
#endif // if defined(VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMultisampledRenderToSingleSampledInfoEXT>) );
#endif // if defined(VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineProtectedAccessFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueueFamilyVideoPropertiesKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueueFamilyQueryResultStatusPropertiesKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoProfileListInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVideoFormatInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoFormatPropertiesKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeQuantizationMapCapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264QuantizationMapCapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265QuantizationMapCapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1QuantizationMapCapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoFormatQuantizationMapPropertiesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoFormatH265QuantizationMapPropertiesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoFormatAV1QuantizationMapPropertiesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoProfileInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoCapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoSessionMemoryRequirementsKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindVideoSessionMemoryInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoPictureResourceInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoReferenceSlotInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_decode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeCapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeUsageInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVideoMaintenance1FeaturesKHR>) );
#endif // if defined(VK_KHR_video_maintenance1)

#if defined(VK_KHR_video_maintenance2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVideoMaintenance2FeaturesKHR>) );
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoInlineQueryInfoKHR>) );
#endif // if defined(VK_KHR_video_maintenance1)

#if defined(VK_KHR_video_decode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH264ProfileInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH264CapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH264SessionParametersAddInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH264SessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_maintenance2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH264InlineSessionParametersInfoKHR>) );
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH264PictureInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH264DpbSlotInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH265ProfileInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH265CapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH265SessionParametersAddInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH265SessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_maintenance2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH265InlineSessionParametersInfoKHR>) );
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH265PictureInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeH265DpbSlotInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeAV1ProfileInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeAV1CapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeAV1SessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_maintenance2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeAV1InlineSessionParametersInfoKHR>) );
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeAV1PictureInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoDecodeAV1DpbSlotInfoKHR>) );
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoSessionCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoSessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoSessionParametersUpdateInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeSessionParametersGetInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeSessionParametersFeedbackInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoBeginCodingInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEndCodingInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoCodingControlInfoKHR>) );
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeUsageInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeQuantizationMapInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>) );
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueryPoolVideoEncodeFeedbackCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeQualityLevelInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeQualityLevelPropertiesKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeRateControlInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeRateControlLayerInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeCapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264CapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264QualityLevelPropertiesKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264SessionCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264SessionParametersAddInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264SessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264SessionParametersGetInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264SessionParametersFeedbackInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264DpbSlotInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264PictureInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264ProfileInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264NaluSliceInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264RateControlInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264GopRemainingFrameInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH264RateControlLayerInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265CapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265QualityLevelPropertiesKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265SessionCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265SessionParametersAddInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265SessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265SessionParametersGetInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265SessionParametersFeedbackInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265PictureInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265NaluSliceSegmentInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265RateControlInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265GopRemainingFrameInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265RateControlLayerInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265ProfileInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeH265DpbSlotInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1CapabilitiesKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1QualityLevelPropertiesKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1SessionCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1SessionParametersCreateInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1DpbSlotInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1PictureInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1ProfileInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1RateControlInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1GopRemainingFrameInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkVideoEncodeAV1RateControlLayerInfoKHR>) );
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_NV_inherited_viewport_scissor)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceInheritedViewportScissorFeaturesNV>) );
#endif // if defined(VK_NV_inherited_viewport_scissor)

#if defined(VK_NV_inherited_viewport_scissor)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferInheritanceViewportScissorInfoNV>) );
#endif // if defined(VK_NV_inherited_viewport_scissor)

#if defined(VK_EXT_ycbcr_2plane_444_formats)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>) );
#endif // if defined(VK_EXT_ycbcr_2plane_444_formats)

#if defined(VK_EXT_provoking_vertex)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceProvokingVertexFeaturesEXT>) );
#endif // if defined(VK_EXT_provoking_vertex)

#if defined(VK_EXT_provoking_vertex)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceProvokingVertexPropertiesEXT>) );
#endif // if defined(VK_EXT_provoking_vertex)

#if defined(VK_EXT_provoking_vertex)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>) );
#endif // if defined(VK_EXT_provoking_vertex)

#if defined(VK_NVX_binary_import)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCuModuleCreateInfoNVX>) );
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCuModuleTexturingModeCreateInfoNVX>) );
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCuFunctionCreateInfoNVX>) );
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCuLaunchInfoNVX>) );
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDescriptorBufferFeaturesEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDescriptorBufferPropertiesEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorAddressInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorBufferBindingInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorGetInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCaptureDescriptorDataInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageCaptureDescriptorDataInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewCaptureDescriptorDataInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerCaptureDescriptorDataInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureCaptureDescriptorDataInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkOpaqueCaptureDescriptorDataCreateInfoEXT>) );
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderIntegerDotProductFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderIntegerDotProductProperties>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_physical_device_drm)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDrmPropertiesEXT>) );
#endif // if defined(VK_EXT_physical_device_drm)

#if defined(VK_KHR_fragment_shader_barycentric)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>) );
#endif // if defined(VK_KHR_fragment_shader_barycentric)

#if defined(VK_KHR_fragment_shader_barycentric)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>) );
#endif // if defined(VK_KHR_fragment_shader_barycentric)

#if defined(VK_NV_ray_tracing_motion_blur)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>) );
#endif // if defined(VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_ray_tracing_validation)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingValidationFeaturesNV>) );
#endif // if defined(VK_NV_ray_tracing_validation)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>) );
#endif // if defined(VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_NV_ray_tracing_motion_blur)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureGeometryMotionTrianglesDataNV>) );
#endif // if defined(VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_ray_tracing_motion_blur)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureMotionInfoNV>) );
#endif // if defined(VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_external_memory_rdma)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryGetRemoteAddressInfoNV>) );
#endif // if defined(VK_NV_external_memory_rdma)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMemoryBufferCollectionFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCollectionImageCreateInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCollectionBufferCreateInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCollectionCreateInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCollectionPropertiesFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferConstraintsInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSysmemColorSpaceFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageFormatConstraintsInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageConstraintsInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBufferCollectionConstraintsInfoFUCHSIA>) );
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_NV_cuda_kernel_launch)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCudaModuleCreateInfoNV>) );
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCudaFunctionCreateInfoNV>) );
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCudaLaunchInfoNV>) );
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_EXT_rgba10x6_formats)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>) );
#endif // if defined(VK_EXT_rgba10x6_formats)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFormatProperties3>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_image_drm_format_modifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDrmFormatModifierPropertiesList2EXT>) );
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAndroidHardwareBufferFormatProperties2ANDROID>) );
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRenderingCreateInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderingInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderingAttachmentInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_fragment_shading_rate)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderingFragmentShadingRateAttachmentInfoKHR>) );
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_EXT_fragment_density_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderingFragmentDensityMapAttachmentInfoEXT>) );
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDynamicRenderingFeatures>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCommandBufferInheritanceRenderingInfo>) );
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_AMD_mixed_attachment_samples)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAttachmentSampleCountInfoAMD>) );
#endif // if defined(VK_AMD_mixed_attachment_samples)

#if defined(VK_NVX_multiview_per_view_attributes)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMultiviewPerViewAttributesInfoNVX>) );
#endif // if defined(VK_NVX_multiview_per_view_attributes)

#if defined(VK_EXT_image_view_min_lod)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageViewMinLodFeaturesEXT>) );
#endif // if defined(VK_EXT_image_view_min_lod)

#if defined(VK_EXT_image_view_min_lod)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewMinLodCreateInfoEXT>) );
#endif // if defined(VK_EXT_image_view_min_lod)

#if defined(VK_EXT_rasterization_order_attachment_access)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>) );
#endif // if defined(VK_EXT_rasterization_order_attachment_access)

#if defined(VK_NV_linear_color_attachment)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLinearColorAttachmentFeaturesNV>) );
#endif // if defined(VK_NV_linear_color_attachment)

#if defined(VK_EXT_graphics_pipeline_library)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>) );
#endif // if defined(VK_EXT_graphics_pipeline_library)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineBinaryFeaturesKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDevicePipelineBinaryInternalCacheControlKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineBinaryPropertiesKHR>) );
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_EXT_graphics_pipeline_library)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>) );
#endif // if defined(VK_EXT_graphics_pipeline_library)

#if defined(VK_EXT_graphics_pipeline_library)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGraphicsPipelineLibraryCreateInfoEXT>) );
#endif // if defined(VK_EXT_graphics_pipeline_library)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>) );
#endif // if defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetBindingReferenceVALVE>) );
#endif // if defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDescriptorSetLayoutHostMappingInfoVALVE>) );
#endif // if defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_EXT_nested_command_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceNestedCommandBufferFeaturesEXT>) );
#endif // if defined(VK_EXT_nested_command_buffer)

#if defined(VK_EXT_nested_command_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceNestedCommandBufferPropertiesEXT>) );
#endif // if defined(VK_EXT_nested_command_buffer)

#if defined(VK_EXT_shader_module_identifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>) );
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT>) );
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineShaderStageModuleIdentifierCreateInfoEXT>) );
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkShaderModuleIdentifierEXT>) );
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_image_compression_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageCompressionControlEXT>) );
#endif // if defined(VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageCompressionControlFeaturesEXT>) );
#endif // if defined(VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageCompressionPropertiesEXT>) );
#endif // if defined(VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control_swapchain)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>) );
#endif // if defined(VK_EXT_image_compression_control_swapchain)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageSubresource2>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSubresourceLayout2>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_subpass_merge_feedback)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassCreationControlEXT>) );
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassCreationFeedbackCreateInfoEXT>) );
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassSubpassFeedbackCreateInfoEXT>) );
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>) );
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMicromapBuildInfoEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMicromapCreateInfoEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMicromapVersionInfoEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyMicromapInfoEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyMicromapToMemoryInfoEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCopyMemoryToMicromapInfoEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMicromapBuildSizesInfoEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceOpacityMicromapFeaturesEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceOpacityMicromapPropertiesEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureTrianglesOpacityMicromapEXT>) );
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_NV_displacement_micromap) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDisplacementMicromapFeaturesNV>) );
#endif // if defined(VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDisplacementMicromapPropertiesNV>) );
#endif // if defined(VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAccelerationStructureTrianglesDisplacementMicromapNV>) );
#endif // if defined(VK_NV_displacement_micromap)

#if defined(VK_EXT_pipeline_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelinePropertiesIdentifierEXT>) );
#endif // if defined(VK_EXT_pipeline_properties)

#if defined(VK_EXT_pipeline_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelinePropertiesFeaturesEXT>) );
#endif // if defined(VK_EXT_pipeline_properties)

#if defined(VK_AMD_shader_early_and_late_fragment_tests)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>) );
#endif // if defined(VK_AMD_shader_early_and_late_fragment_tests)

#if defined(VK_EXT_external_memory_acquire_unmodified)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalMemoryAcquireUnmodifiedEXT>) );
#endif // if defined(VK_EXT_external_memory_acquire_unmodified)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalObjectCreateInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalObjectsInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalDeviceInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalCommandQueueInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalBufferInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMetalBufferInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalTextureInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMetalTextureInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalIOSurfaceInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMetalIOSurfaceInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExportMetalSharedEventInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportMetalSharedEventInfoEXT>) );
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_non_seamless_cube_map)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>) );
#endif // if defined(VK_EXT_non_seamless_cube_map)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineRobustnessFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineRobustnessCreateInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineRobustnessProperties>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_QCOM_image_processing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageViewSampleWeightCreateInfoQCOM>) );
#endif // if defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageProcessingFeaturesQCOM>) );
#endif // if defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageProcessingPropertiesQCOM>) );
#endif // if defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_tile_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceTilePropertiesFeaturesQCOM>) );
#endif // if defined(VK_QCOM_tile_properties)

#if defined(VK_QCOM_tile_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkTilePropertiesQCOM>) );
#endif // if defined(VK_QCOM_tile_properties)

#if defined(VK_SEC_amigo_profiling)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceAmigoProfilingFeaturesSEC>) );
#endif // if defined(VK_SEC_amigo_profiling)

#if defined(VK_SEC_amigo_profiling)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAmigoProfilingSubmitInfoSEC>) );
#endif // if defined(VK_SEC_amigo_profiling)

#if defined(VK_EXT_attachment_feedback_loop_layout)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>) );
#endif // if defined(VK_EXT_attachment_feedback_loop_layout)

#if defined(VK_EXT_device_address_binding_report)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceAddressBindingReportFeaturesEXT>) );
#endif // if defined(VK_EXT_device_address_binding_report)

#if defined(VK_EXT_device_address_binding_report)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceAddressBindingCallbackDataEXT>) );
#endif // if defined(VK_EXT_device_address_binding_report)

#if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceOpticalFlowFeaturesNV>) );
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceOpticalFlowPropertiesNV>) );
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkOpticalFlowImageFormatInfoNV>) );
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkOpticalFlowImageFormatPropertiesNV>) );
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkOpticalFlowSessionCreateInfoNV>) );
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkOpticalFlowSessionCreatePrivateDataInfoNV>) );
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkOpticalFlowExecuteInfoNV>) );
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_EXT_device_fault)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFaultFeaturesEXT>) );
#endif // if defined(VK_EXT_device_fault)

#if defined(VK_EXT_device_fault)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceFaultCountsEXT>) );
#endif // if defined(VK_EXT_device_fault)

#if defined(VK_EXT_device_fault)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceFaultInfoEXT>) );
#endif // if defined(VK_EXT_device_fault)

#if defined(VK_EXT_pipeline_library_group_handles)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>) );
#endif // if defined(VK_EXT_pipeline_library_group_handles)

#if defined(VK_EXT_depth_bias_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDepthBiasInfoEXT>) );
#endif // if defined(VK_EXT_depth_bias_control)

#if defined(VK_EXT_depth_bias_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDepthBiasRepresentationInfoEXT>) );
#endif // if defined(VK_EXT_depth_bias_control)

#if defined(VK_ARM_shader_core_builtins)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM>) );
#endif // if defined(VK_ARM_shader_core_builtins)

#if defined(VK_ARM_shader_core_builtins)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>) );
#endif // if defined(VK_ARM_shader_core_builtins)

#if defined(VK_EXT_frame_boundary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkFrameBoundaryEXT>) );
#endif // if defined(VK_EXT_frame_boundary)

#if defined(VK_EXT_frame_boundary)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceFrameBoundaryFeaturesEXT>) );
#endif // if defined(VK_EXT_frame_boundary)

#if defined(VK_EXT_dynamic_rendering_unused_attachments)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>) );
#endif // if defined(VK_EXT_dynamic_rendering_unused_attachments)

#if defined(VK_EXT_surface_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfacePresentModeEXT>) );
#endif // if defined(VK_EXT_surface_maintenance1)

#if defined(VK_EXT_surface_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfacePresentScalingCapabilitiesEXT>) );
#endif // if defined(VK_EXT_surface_maintenance1)

#if defined(VK_EXT_surface_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSurfacePresentModeCompatibilityEXT>) );
#endif // if defined(VK_EXT_surface_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>) );
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainPresentFenceInfoEXT>) );
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainPresentModesCreateInfoEXT>) );
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainPresentModeInfoEXT>) );
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainPresentScalingCreateInfoEXT>) );
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkReleaseSwapchainImagesInfoEXT>) );
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_depth_bias_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDepthBiasControlFeaturesEXT>) );
#endif // if defined(VK_EXT_depth_bias_control)

#if defined(VK_NV_ray_tracing_invocation_reorder)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>) );
#endif // if defined(VK_NV_ray_tracing_invocation_reorder)

#if defined(VK_NV_ray_tracing_invocation_reorder)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV>) );
#endif // if defined(VK_NV_ray_tracing_invocation_reorder)

#if defined(VK_NV_extended_sparse_address_space)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>) );
#endif // if defined(VK_NV_extended_sparse_address_space)

#if defined(VK_NV_extended_sparse_address_space)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV>) );
#endif // if defined(VK_NV_extended_sparse_address_space)

#if defined(VK_LUNARG_direct_driver_loading)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDirectDriverLoadingInfoLUNARG>) );
#endif // if defined(VK_LUNARG_direct_driver_loading)

#if defined(VK_LUNARG_direct_driver_loading)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDirectDriverLoadingListLUNARG>) );
#endif // if defined(VK_LUNARG_direct_driver_loading)

#if defined(VK_QCOM_multiview_per_view_viewports)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>) );
#endif // if defined(VK_QCOM_multiview_per_view_viewports)

#if defined(VK_KHR_ray_tracing_position_fetch)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>) );
#endif // if defined(VK_KHR_ray_tracing_position_fetch)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceImageSubresourceInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_ARM_shader_core_properties)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderCorePropertiesARM>) );
#endif // if defined(VK_ARM_shader_core_properties)

#if defined(VK_QCOM_multiview_per_view_render_areas)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>) );
#endif // if defined(VK_QCOM_multiview_per_view_render_areas)

#if defined(VK_QCOM_multiview_per_view_render_areas)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>) );
#endif // if defined(VK_QCOM_multiview_per_view_render_areas)

#if defined(VK_NV_low_latency)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkQueryLowLatencySupportNV>) );
#endif // if defined(VK_NV_low_latency)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryMapInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryUnmapInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_shader_object)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderObjectFeaturesEXT>) );
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderObjectPropertiesEXT>) );
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkShaderCreateInfoEXT>) );
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_tile_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderTileImageFeaturesEXT>) );
#endif // if defined(VK_EXT_shader_tile_image)

#if defined(VK_EXT_shader_tile_image)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderTileImagePropertiesEXT>) );
#endif // if defined(VK_EXT_shader_tile_image)

#if defined(VK_QNX_external_memory_screen_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImportScreenBufferInfoQNX>) );
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkScreenBufferPropertiesQNX>) );
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkScreenBufferFormatPropertiesQNX>) );
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExternalFormatQNX>) );
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>) );
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_KHR_cooperative_matrix)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeMatrixFeaturesKHR>) );
#endif // if defined(VK_KHR_cooperative_matrix)

#if defined(VK_KHR_cooperative_matrix)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCooperativeMatrixPropertiesKHR>) );
#endif // if defined(VK_KHR_cooperative_matrix)

#if defined(VK_KHR_cooperative_matrix)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeMatrixPropertiesKHR>) );
#endif // if defined(VK_KHR_cooperative_matrix)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderEnqueuePropertiesAMDX>) );
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderEnqueueFeaturesAMDX>) );
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExecutionGraphPipelineCreateInfoAMDX>) );
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPipelineShaderStageNodeCreateInfoAMDX>) );
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkExecutionGraphPipelineScratchSizeAMDX>) );
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMD_anti_lag)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceAntiLagFeaturesAMD>) );
#endif // if defined(VK_AMD_anti_lag)

#if defined(VK_AMD_anti_lag)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAntiLagDataAMD>) );
#endif // if defined(VK_AMD_anti_lag)

#if defined(VK_AMD_anti_lag)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAntiLagPresentationInfoAMD>) );
#endif // if defined(VK_AMD_anti_lag)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindMemoryStatus>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindDescriptorSetsInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPushConstantsInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPushDescriptorSetInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPushDescriptorSetWithTemplateInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_maintenance6)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSetDescriptorBufferOffsetsInfoEXT>) );
#endif // if defined(VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBindDescriptorBufferEmbeddedSamplersInfoEXT>) );
#endif // if defined(VK_KHR_maintenance6)

#if defined(VK_QCOM_filter_cubic_clamp)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCubicClampFeaturesQCOM>) );
#endif // if defined(VK_QCOM_filter_cubic_clamp)

#if defined(VK_QCOM_ycbcr_degamma)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>) );
#endif // if defined(VK_QCOM_ycbcr_degamma)

#if defined(VK_QCOM_ycbcr_degamma)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM>) );
#endif // if defined(VK_QCOM_ycbcr_degamma)

#if defined(VK_QCOM_filter_cubic_weights)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCubicWeightsFeaturesQCOM>) );
#endif // if defined(VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_filter_cubic_weights)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerCubicWeightsCreateInfoQCOM>) );
#endif // if defined(VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_filter_cubic_weights)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkBlitImageCubicWeightsInfoQCOM>) );
#endif // if defined(VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_image_processing2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageProcessing2FeaturesQCOM>) );
#endif // if defined(VK_QCOM_image_processing2)

#if defined(VK_QCOM_image_processing2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageProcessing2PropertiesQCOM>) );
#endif // if defined(VK_QCOM_image_processing2)

#if defined(VK_QCOM_image_processing2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSamplerBlockMatchWindowCreateInfoQCOM>) );
#endif // if defined(VK_QCOM_image_processing2)

#if defined(VK_NV_descriptor_pool_overallocation)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>) );
#endif // if defined(VK_NV_descriptor_pool_overallocation)

#if defined(VK_MSFT_layered_driver)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceLayeredDriverPropertiesMSFT>) );
#endif // if defined(VK_MSFT_layered_driver)

#if defined(VK_NV_per_stage_descriptor_set)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePerStageDescriptorSetFeaturesNV>) );
#endif // if defined(VK_NV_per_stage_descriptor_set)

#if defined(VK_ANDROID_external_format_resolve)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>) );
#endif // if defined(VK_ANDROID_external_format_resolve)

#if defined(VK_ANDROID_external_format_resolve)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceExternalFormatResolvePropertiesANDROID>) );
#endif // if defined(VK_ANDROID_external_format_resolve)

#if defined(VK_ANDROID_external_format_resolve)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkAndroidHardwareBufferFormatResolvePropertiesANDROID>) );
#endif // if defined(VK_ANDROID_external_format_resolve)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkLatencySleepModeInfoNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkLatencySleepInfoNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSetLatencyMarkerInfoNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkGetLatencyMarkerInfoNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkLatencyTimingsFrameReportNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkOutOfBandQueueTypeInfoNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkLatencySubmissionPresentIdNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSwapchainLatencyCreateInfoNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkLatencySurfaceCapabilitiesNV>) );
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_cuda_kernel_launch)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCudaKernelLaunchFeaturesNV>) );
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCudaKernelLaunchPropertiesNV>) );
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_ARM_scheduling_controls)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkDeviceQueueShaderCoreControlCreateInfoARM>) );
#endif // if defined(VK_ARM_scheduling_controls)

#if defined(VK_ARM_scheduling_controls)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSchedulingControlsFeaturesARM>) );
#endif // if defined(VK_ARM_scheduling_controls)

#if defined(VK_ARM_scheduling_controls)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceSchedulingControlsPropertiesARM>) );
#endif // if defined(VK_ARM_scheduling_controls)

#if defined(VK_IMG_relaxed_line_rasterization)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>) );
#endif // if defined(VK_IMG_relaxed_line_rasterization)

#if defined(VK_ARM_render_pass_striped)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRenderPassStripedFeaturesARM>) );
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRenderPassStripedPropertiesARM>) );
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassStripeInfoARM>) );
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassStripeBeginInfoARM>) );
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderPassStripeSubmitInfoARM>) );
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_pipeline_opacity_micromap)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>) );
#endif // if defined(VK_ARM_pipeline_opacity_micromap)

#if defined(VK_KHR_shader_maximal_reconvergence)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>) );
#endif // if defined(VK_KHR_shader_maximal_reconvergence)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderSubgroupRotateFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderExpectAssumeFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderFloatControls2Features>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDynamicRenderingLocalReadFeatures>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderingAttachmentLocationInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkRenderingInputAttachmentIndexInfo>) );
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_shader_quad_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderQuadControlFeaturesKHR>) );
#endif // if defined(VK_KHR_shader_quad_control)

#if defined(VK_NV_shader_atomic_float16_vector)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>) );
#endif // if defined(VK_NV_shader_atomic_float16_vector)

#if defined(VK_EXT_map_memory_placed)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>) );
#endif // if defined(VK_EXT_map_memory_placed)

#if defined(VK_EXT_map_memory_placed)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceMapMemoryPlacedPropertiesEXT>) );
#endif // if defined(VK_EXT_map_memory_placed)

#if defined(VK_EXT_map_memory_placed)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkMemoryMapPlacedInfoEXT>) );
#endif // if defined(VK_EXT_map_memory_placed)

#if defined(VK_NV_raw_access_chains)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceRawAccessChainsFeaturesNV>) );
#endif // if defined(VK_NV_raw_access_chains)

#if defined(VK_NV_command_buffer_inheritance)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>) );
#endif // if defined(VK_NV_command_buffer_inheritance)

#if defined(VK_MESA_image_alignment_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageAlignmentControlFeaturesMESA>) );
#endif // if defined(VK_MESA_image_alignment_control)

#if defined(VK_MESA_image_alignment_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceImageAlignmentControlPropertiesMESA>) );
#endif // if defined(VK_MESA_image_alignment_control)

#if defined(VK_MESA_image_alignment_control)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkImageAlignmentControlCreateInfoMESA>) );
#endif // if defined(VK_MESA_image_alignment_control)

#if defined(VK_EXT_shader_replicated_composites)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>) );
#endif // if defined(VK_EXT_shader_replicated_composites)

#if defined(VK_EXT_present_mode_fifo_latest_ready)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT>) );
#endif // if defined(VK_EXT_present_mode_fifo_latest_ready)

#if defined(VK_NV_cooperative_matrix2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeMatrix2FeaturesNV>) );
#endif // if defined(VK_NV_cooperative_matrix2)

#if defined(VK_NV_cooperative_matrix2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeMatrix2PropertiesNV>) );
#endif // if defined(VK_NV_cooperative_matrix2)

#if defined(VK_NV_cooperative_matrix2)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCooperativeMatrixFlexibleDimensionsPropertiesNV>) );
#endif // if defined(VK_NV_cooperative_matrix2)

#if defined(VK_HUAWEI_hdr_vivid)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceHdrVividFeaturesHUAWEI>) );
#endif // if defined(VK_HUAWEI_hdr_vivid)

#if defined(VK_EXT_vertex_attribute_robustness)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>) );
#endif // if defined(VK_EXT_vertex_attribute_robustness)

#if defined(VK_KHR_depth_clamp_zero_one)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>) );
#endif // if defined(VK_KHR_depth_clamp_zero_one)

#if defined(VK_NV_cooperative_vector)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeVectorFeaturesNV>) );
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkCooperativeVectorPropertiesNV>) );
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDeviceCooperativeVectorPropertiesNV>) );
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkConvertCooperativeVectorMatrixInfoNV>) );
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_present_metering) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkSetPresentConfigNV>) );
#endif // if defined(VK_NV_present_metering)

#if defined(VK_NV_present_metering) && defined(VK_ENABLE_BETA_EXTENSIONS)
    STATIC_EXPECT_TRUE((fubuki::vk_struct<VkPhysicalDevicePresentMeteringFeaturesNV>) );
#endif // if defined(VK_NV_present_metering)

    STATIC_EXPECT_FALSE((fubuki::vk_struct<VkBuffer>) );
    STATIC_EXPECT_FALSE((fubuki::vk_struct<int>) );
    STATIC_EXPECT_FALSE((fubuki::vk_struct<fubuki::structure_type<VkBufferCreateInfo>>) );
    STATIC_EXPECT_FALSE((fubuki::vk_struct<fubuki::structure_type<int>>) );
}

TEST(structure_type, make)
{

    // clang-format off
#define DO_MAKE_TEST(vk_structure, vk_enum)                                                  \
    do                                                                                       \
    {                                                                                        \
        constexpr auto structure = fubuki::make<vk_structure>();                          \
        STATIC_EXPECT_TRUE((structure.sType == fubuki::structure_type_v<vk_structure>) ); \
        STATIC_EXPECT_TRUE((structure.sType == (vk_enum)));                                  \
    }                                                                                        \
    while(false)
    // clang-format on

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkDeviceQueueCreateInfo, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkDeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkInstanceCreateInfo, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkMemoryAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkMappedMemoryRange, VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkWriteDescriptorSet, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkCopyDescriptorSet, VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkBufferUsageFlags2CreateInfo, VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkBufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkBufferViewCreateInfo, VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkMemoryBarrier, VK_STRUCTURE_TYPE_MEMORY_BARRIER);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkBufferMemoryBarrier, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkImageMemoryBarrier, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkImageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkImageViewCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkBindSparseInfo, VK_STRUCTURE_TYPE_BIND_SPARSE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkShaderModuleCreateInfo, VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkDescriptorSetLayoutCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkDescriptorPoolCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkDescriptorSetAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineShaderStageCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkComputePipelineCreateInfo, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_NV_device_generated_commands_compute)
    DO_MAKE_TEST(VkComputePipelineIndirectBufferInfoNV, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV);
#endif // if defined(VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPipelineCreateFlags2CreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineVertexInputStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineInputAssemblyStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineTessellationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineViewportStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineRasterizationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineMultisampleStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineColorBlendStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineDynamicStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineDepthStencilStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkGraphicsPipelineCreateInfo, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineCacheCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPipelineBinaryCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPipelineBinaryHandlesInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPipelineBinaryKeyKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPipelineBinaryInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkReleaseCapturedPipelineDataInfoKHR, VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPipelineBinaryDataInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPipelineCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineLayoutCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkSamplerCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkCommandPoolCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkCommandBufferAllocateInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkCommandBufferInheritanceInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkCommandBufferBeginInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkRenderPassBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkRenderPassCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkEventCreateInfo, VK_STRUCTURE_TYPE_EVENT_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkFenceCreateInfo, VK_STRUCTURE_TYPE_FENCE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkSemaphoreCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkQueryPoolCreateInfo, VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkFramebufferCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    DO_MAKE_TEST(VkSubmitInfo, VK_STRUCTURE_TYPE_SUBMIT_INFO);
#endif // if defined(VK_VERSION_1_0)

#if defined(VK_KHR_display)
    DO_MAKE_TEST(VkDisplayModeCreateInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_display)

#if defined(VK_KHR_display)
    DO_MAKE_TEST(VkDisplaySurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_display)

#if defined(VK_NV_display_stereo)
    DO_MAKE_TEST(VkDisplaySurfaceStereoCreateInfoNV, VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV);
#endif // if defined(VK_NV_display_stereo)

#if defined(VK_KHR_display_swapchain)
    DO_MAKE_TEST(VkDisplayPresentInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR);
#endif // if defined(VK_KHR_display_swapchain)

#if defined(VK_KHR_android_surface)
    DO_MAKE_TEST(VkAndroidSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_android_surface)

#if defined(VK_NN_vi_surface)
    DO_MAKE_TEST(VkViSurfaceCreateInfoNN, VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN);
#endif // if defined(VK_NN_vi_surface)

#if defined(VK_KHR_wayland_surface)
    DO_MAKE_TEST(VkWaylandSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_wayland_surface)

#if defined(VK_KHR_win32_surface)
    DO_MAKE_TEST(VkWin32SurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_win32_surface)

#if defined(VK_KHR_xlib_surface)
    DO_MAKE_TEST(VkXlibSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_xlib_surface)

#if defined(VK_KHR_xcb_surface)
    DO_MAKE_TEST(VkXcbSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_xcb_surface)

#if defined(VK_EXT_directfb_surface)
    DO_MAKE_TEST(VkDirectFBSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_directfb_surface)

#if defined(VK_FUCHSIA_imagepipe_surface)
    DO_MAKE_TEST(VkImagePipeSurfaceCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_imagepipe_surface)

#if defined(VK_GGP_stream_descriptor_surface)
    DO_MAKE_TEST(VkStreamDescriptorSurfaceCreateInfoGGP, VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP);
#endif // if defined(VK_GGP_stream_descriptor_surface)

#if defined(VK_QNX_screen_surface)
    DO_MAKE_TEST(VkScreenSurfaceCreateInfoQNX, VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX);
#endif // if defined(VK_QNX_screen_surface)

#if defined(VK_KHR_swapchain)
    DO_MAKE_TEST(VkSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
    DO_MAKE_TEST(VkPresentInfoKHR, VK_STRUCTURE_TYPE_PRESENT_INFO_KHR);
#endif // if defined(VK_KHR_swapchain)

#if defined(VK_EXT_debug_report)
    DO_MAKE_TEST(VkDebugReportCallbackCreateInfoEXT, VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_debug_report)

#if defined(VK_EXT_validation_flags)
    DO_MAKE_TEST(VkValidationFlagsEXT, VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT);
#endif // if defined(VK_EXT_validation_flags)

#if defined(VK_EXT_validation_features)
    DO_MAKE_TEST(VkValidationFeaturesEXT, VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT);
#endif // if defined(VK_EXT_validation_features)

#if defined(VK_EXT_layer_settings)
    DO_MAKE_TEST(VkLayerSettingsCreateInfoEXT, VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_layer_settings)

#if defined(VK_EXT_application_parameters)
    DO_MAKE_TEST(VkApplicationParametersEXT, VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT);
#endif // if defined(VK_EXT_application_parameters)

#if defined(VK_AMD_rasterization_order)
    DO_MAKE_TEST(VkPipelineRasterizationStateRasterizationOrderAMD, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD);
#endif // if defined(VK_AMD_rasterization_order)

#if defined(VK_EXT_debug_marker)
    DO_MAKE_TEST(VkDebugMarkerObjectNameInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT);
#endif // if defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
    DO_MAKE_TEST(VkDebugMarkerObjectTagInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT);
#endif // if defined(VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
    DO_MAKE_TEST(VkDebugMarkerMarkerInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT);
#endif // if defined(VK_EXT_debug_marker)

#if defined(VK_NV_dedicated_allocation)
    DO_MAKE_TEST(VkDedicatedAllocationImageCreateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV);
#endif // if defined(VK_NV_dedicated_allocation)

#if defined(VK_NV_dedicated_allocation)
    DO_MAKE_TEST(VkDedicatedAllocationBufferCreateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV);
#endif // if defined(VK_NV_dedicated_allocation)

#if defined(VK_NV_dedicated_allocation)
    DO_MAKE_TEST(VkDedicatedAllocationMemoryAllocateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV);
#endif // if defined(VK_NV_dedicated_allocation)

#if defined(VK_NV_external_memory)
    DO_MAKE_TEST(VkExternalMemoryImageCreateInfoNV, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV);
#endif // if defined(VK_NV_external_memory)

#if defined(VK_NV_external_memory)
    DO_MAKE_TEST(VkExportMemoryAllocateInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV);
#endif // if defined(VK_NV_external_memory)

#if defined(VK_NV_external_memory_win32)
    DO_MAKE_TEST(VkImportMemoryWin32HandleInfoNV, VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV);
#endif // if defined(VK_NV_external_memory_win32)

#if defined(VK_NV_external_memory_win32)
    DO_MAKE_TEST(VkExportMemoryWin32HandleInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV);
#endif // if defined(VK_NV_external_memory_win32)

#if defined(VK_NV_external_memory_sci_buf)
    DO_MAKE_TEST(VkExportMemorySciBufInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_SCI_BUF_INFO_NV);
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    DO_MAKE_TEST(VkImportMemorySciBufInfoNV, VK_STRUCTURE_TYPE_IMPORT_MEMORY_SCI_BUF_INFO_NV);
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    DO_MAKE_TEST(VkMemoryGetSciBufInfoNV, VK_STRUCTURE_TYPE_MEMORY_GET_SCI_BUF_INFO_NV);
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    DO_MAKE_TEST(VkMemorySciBufPropertiesNV, VK_STRUCTURE_TYPE_MEMORY_SCI_BUF_PROPERTIES_NV);
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    DO_MAKE_TEST(VkPhysicalDeviceExternalMemorySciBufFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV);
#endif // if defined(VK_NV_external_memory_sci_buf)

#if defined(VK_NV_win32_keyed_mutex)
    DO_MAKE_TEST(VkWin32KeyedMutexAcquireReleaseInfoNV, VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV);
#endif // if defined(VK_NV_win32_keyed_mutex)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands_compute)
    DO_MAKE_TEST(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV);
#endif // if defined(VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkDevicePrivateDataCreateInfo, VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPrivateDataSlotCreateInfo, VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDevicePrivateDataFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkPhysicalDeviceClusterAccelerationStructureFeaturesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkPhysicalDeviceClusterAccelerationStructurePropertiesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_PROPERTIES_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV,
                 VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CLUSTER_ACCELERATION_STRUCTURE_CREATE_INFO_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkClusterAccelerationStructureClustersBottomLevelInputNV,
                 VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_CLUSTERS_BOTTOM_LEVEL_INPUT_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkClusterAccelerationStructureTriangleClusterInputNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_TRIANGLE_CLUSTER_INPUT_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkClusterAccelerationStructureMoveObjectsInputNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_MOVE_OBJECTS_INPUT_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkClusterAccelerationStructureInputInfoNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_INPUT_INFO_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    DO_MAKE_TEST(VkClusterAccelerationStructureCommandsInfoNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_COMMANDS_INFO_NV);
#endif // if defined(VK_NV_cluster_acceleration_structure)

#if defined(VK_EXT_multi_draw)
    DO_MAKE_TEST(VkPhysicalDeviceMultiDrawPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT);
#endif // if defined(VK_EXT_multi_draw)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkGraphicsShaderGroupCreateInfoNV, VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkGraphicsPipelineShaderGroupsCreateInfoNV, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkIndirectCommandsLayoutTokenNV, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkIndirectCommandsLayoutCreateInfoNV, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkGeneratedCommandsInfoNV, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    DO_MAKE_TEST(VkGeneratedCommandsMemoryRequirementsInfoNV, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV);
#endif // if defined(VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands_compute)
    DO_MAKE_TEST(VkPipelineIndirectDeviceAddressInfoNV, VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV);
#endif // if defined(VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceFeatures2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceProperties2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkFormatProperties2, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkImageFormatProperties2, VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceImageFormatInfo2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkQueueFamilyProperties2, VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceMemoryProperties2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkSparseImageFormatProperties2, VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceSparseImageFormatInfo2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDevicePushDescriptorProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceDriverProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_KHR_incremental_present)
    DO_MAKE_TEST(VkPresentRegionsKHR, VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR);
#endif // if defined(VK_KHR_incremental_present)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceVariablePointersFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceExternalImageFormatInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExternalImageFormatProperties, VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceExternalBufferInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExternalBufferProperties, VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceIDProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExternalMemoryImageCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExternalMemoryBufferCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExportMemoryAllocateInfo, VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_external_memory_win32)
    DO_MAKE_TEST(VkImportMemoryWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
    DO_MAKE_TEST(VkExportMemoryWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_FUCHSIA_external_memory)
    DO_MAKE_TEST(VkImportMemoryZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
    DO_MAKE_TEST(VkMemoryZirconHandlePropertiesFUCHSIA, VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA);
#endif // if defined(VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
    DO_MAKE_TEST(VkMemoryGetZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_external_memory)

#if defined(VK_KHR_external_memory_win32)
    DO_MAKE_TEST(VkMemoryWin32HandlePropertiesKHR, VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR);
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
    DO_MAKE_TEST(VkMemoryGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)
    DO_MAKE_TEST(VkImportMemoryFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR);
#endif // if defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
    DO_MAKE_TEST(VkMemoryFdPropertiesKHR, VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR);
#endif // if defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
    DO_MAKE_TEST(VkMemoryGetFdInfoKHR, VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR);
#endif // if defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_win32_keyed_mutex)
    DO_MAKE_TEST(VkWin32KeyedMutexAcquireReleaseInfoKHR, VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR);
#endif // if defined(VK_KHR_win32_keyed_mutex)

#if defined(VK_EXT_external_memory_metal)
    DO_MAKE_TEST(VkImportMemoryMetalHandleInfoEXT, VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT);
#endif // if defined(VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
    DO_MAKE_TEST(VkMemoryMetalHandlePropertiesEXT, VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT);
#endif // if defined(VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
    DO_MAKE_TEST(VkMemoryGetMetalHandleInfoEXT, VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT);
#endif // if defined(VK_EXT_external_memory_metal)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceExternalSemaphoreInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExternalSemaphoreProperties, VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExportSemaphoreCreateInfo, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_external_semaphore_win32)
    DO_MAKE_TEST(VkImportSemaphoreWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    DO_MAKE_TEST(VkExportSemaphoreWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    DO_MAKE_TEST(VkD3D12FenceSubmitInfoKHR, VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR);
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    DO_MAKE_TEST(VkSemaphoreGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)
    DO_MAKE_TEST(VkImportSemaphoreFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR);
#endif // if defined(VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_external_semaphore_fd)
    DO_MAKE_TEST(VkSemaphoreGetFdInfoKHR, VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR);
#endif // if defined(VK_KHR_external_semaphore_fd)

#if defined(VK_FUCHSIA_external_semaphore)
    DO_MAKE_TEST(VkImportSemaphoreZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_external_semaphore)

#if defined(VK_FUCHSIA_external_semaphore)
    DO_MAKE_TEST(VkSemaphoreGetZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_external_semaphore)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceExternalFenceInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExternalFenceProperties, VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkExportFenceCreateInfo, VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_external_fence_win32)
    DO_MAKE_TEST(VkImportFenceWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
    DO_MAKE_TEST(VkExportFenceWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
    DO_MAKE_TEST(VkFenceGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR);
#endif // if defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)
    DO_MAKE_TEST(VkImportFenceFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR);
#endif // if defined(VK_KHR_external_fence_fd)

#if defined(VK_KHR_external_fence_fd)
    DO_MAKE_TEST(VkFenceGetFdInfoKHR, VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR);
#endif // if defined(VK_KHR_external_fence_fd)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkExportFenceSciSyncInfoNV, VK_STRUCTURE_TYPE_EXPORT_FENCE_SCI_SYNC_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkImportFenceSciSyncInfoNV, VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkFenceGetSciSyncInfoNV, VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync)
    DO_MAKE_TEST(VkExportSemaphoreSciSyncInfoNV, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_SCI_SYNC_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
    DO_MAKE_TEST(VkImportSemaphoreSciSyncInfoNV, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_SCI_SYNC_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
    DO_MAKE_TEST(VkSemaphoreGetSciSyncInfoNV, VK_STRUCTURE_TYPE_SEMAPHORE_GET_SCI_SYNC_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkSciSyncAttributesInfoNV, VK_STRUCTURE_TYPE_SCI_SYNC_ATTRIBUTES_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync)
    DO_MAKE_TEST(VkPhysicalDeviceExternalSciSyncFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV);
#endif // if defined(VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkPhysicalDeviceExternalSciSync2FeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkSemaphoreSciSyncPoolCreateInfoNV, VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_POOL_CREATE_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkSemaphoreSciSyncCreateInfoNV, VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_CREATE_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    DO_MAKE_TEST(VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV, VK_STRUCTURE_TYPE_DEVICE_SEMAPHORE_SCI_SYNC_POOL_RESERVATION_CREATE_INFO_NV);
#endif // if defined(VK_NV_external_sci_sync2)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceMultiviewFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceMultiviewProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkRenderPassMultiviewCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_EXT_display_surface_counter)
    DO_MAKE_TEST(VkSurfaceCapabilities2EXT, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT);
#endif // if defined(VK_EXT_display_surface_counter)

#if defined(VK_EXT_display_control)
    DO_MAKE_TEST(VkDisplayPowerInfoEXT, VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT);
#endif // if defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    DO_MAKE_TEST(VkDeviceEventInfoEXT, VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT);
#endif // if defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    DO_MAKE_TEST(VkDisplayEventInfoEXT, VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT);
#endif // if defined(VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    DO_MAKE_TEST(VkSwapchainCounterCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_display_control)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceGroupProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkMemoryAllocateFlagsInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkBindBufferMemoryInfo, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkBindBufferMemoryDeviceGroupInfo, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkBindImageMemoryInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkBindImageMemoryDeviceGroupInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDeviceGroupRenderPassBeginInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDeviceGroupCommandBufferBeginInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDeviceGroupSubmitInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDeviceGroupBindSparseInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_device_group)
    DO_MAKE_TEST(VkDeviceGroupPresentCapabilitiesKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    DO_MAKE_TEST(VkImageSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    DO_MAKE_TEST(VkBindImageMemorySwapchainInfoKHR, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR);
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    DO_MAKE_TEST(VkAcquireNextImageInfoKHR, VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR);
#endif // if defined(VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    DO_MAKE_TEST(VkDeviceGroupPresentInfoKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR);
#endif // if defined(VK_KHR_device_group)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDeviceGroupDeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_device_group)
    DO_MAKE_TEST(VkDeviceGroupSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_device_group)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDescriptorUpdateTemplateCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_present_id)
    DO_MAKE_TEST(VkPhysicalDevicePresentIdFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR);
#endif // if defined(VK_KHR_present_id)

#if defined(VK_KHR_present_id)
    DO_MAKE_TEST(VkPresentIdKHR, VK_STRUCTURE_TYPE_PRESENT_ID_KHR);
#endif // if defined(VK_KHR_present_id)

#if defined(VK_KHR_present_wait)
    DO_MAKE_TEST(VkPhysicalDevicePresentWaitFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR);
#endif // if defined(VK_KHR_present_wait)

#if defined(VK_EXT_hdr_metadata)
    DO_MAKE_TEST(VkHdrMetadataEXT, VK_STRUCTURE_TYPE_HDR_METADATA_EXT);
#endif // if defined(VK_EXT_hdr_metadata)

#if defined(VK_HUAWEI_hdr_vivid)
    DO_MAKE_TEST(VkHdrVividDynamicMetadataHUAWEI, VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI);
#endif // if defined(VK_HUAWEI_hdr_vivid)

#if defined(VK_AMD_display_native_hdr)
    DO_MAKE_TEST(VkDisplayNativeHdrSurfaceCapabilitiesAMD, VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD);
#endif // if defined(VK_AMD_display_native_hdr)

#if defined(VK_AMD_display_native_hdr)
    DO_MAKE_TEST(VkSwapchainDisplayNativeHdrCreateInfoAMD, VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD);
#endif // if defined(VK_AMD_display_native_hdr)

#if defined(VK_GOOGLE_display_timing)
    DO_MAKE_TEST(VkPresentTimesInfoGOOGLE, VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE);
#endif // if defined(VK_GOOGLE_display_timing)

#if defined(VK_MVK_ios_surface)
    DO_MAKE_TEST(VkIOSSurfaceCreateInfoMVK, VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK);
#endif // if defined(VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)
    DO_MAKE_TEST(VkMacOSSurfaceCreateInfoMVK, VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK);
#endif // if defined(VK_MVK_macos_surface)

#if defined(VK_EXT_metal_surface)
    DO_MAKE_TEST(VkMetalSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_metal_surface)

#if defined(VK_NV_clip_space_w_scaling)
    DO_MAKE_TEST(VkPipelineViewportWScalingStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_clip_space_w_scaling)

#if defined(VK_NV_viewport_swizzle)
    DO_MAKE_TEST(VkPipelineViewportSwizzleStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_viewport_swizzle)

#if defined(VK_EXT_discard_rectangles)
    DO_MAKE_TEST(VkPhysicalDeviceDiscardRectanglePropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT);
#endif // if defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles)
    DO_MAKE_TEST(VkPipelineDiscardRectangleStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_discard_rectangles)

#if defined(VK_NVX_multiview_per_view_attributes)
    DO_MAKE_TEST(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX);
#endif // if defined(VK_NVX_multiview_per_view_attributes)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkRenderPassInputAttachmentAspectCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_KHR_get_surface_capabilities2)
    DO_MAKE_TEST(VkPhysicalDeviceSurfaceInfo2KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR);
#endif // if defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
    DO_MAKE_TEST(VkSurfaceCapabilities2KHR, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR);
#endif // if defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
    DO_MAKE_TEST(VkSurfaceFormat2KHR, VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR);
#endif // if defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_display_properties2)
    DO_MAKE_TEST(VkDisplayProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR);
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    DO_MAKE_TEST(VkDisplayPlaneProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR);
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    DO_MAKE_TEST(VkDisplayModeProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR);
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_NV_display_stereo)
    DO_MAKE_TEST(VkDisplayModeStereoPropertiesNV, VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV);
#endif // if defined(VK_NV_display_stereo)

#if defined(VK_KHR_get_display_properties2)
    DO_MAKE_TEST(VkDisplayPlaneInfo2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR);
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    DO_MAKE_TEST(VkDisplayPlaneCapabilities2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR);
#endif // if defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_shared_presentable_image)
    DO_MAKE_TEST(VkSharedPresentSurfaceCapabilitiesKHR, VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_shared_presentable_image)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDevice16BitStorageFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceSubgroupProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkBufferMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkDeviceBufferMemoryRequirements, VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkImageMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkImageSparseMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkDeviceImageMemoryRequirements, VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkMemoryRequirements2, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkSparseImageMemoryRequirements2, VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDevicePointClippingProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkMemoryDedicatedRequirements, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkMemoryDedicatedAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkImageViewUsageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_EXT_image_sliced_view_of_3d)
    DO_MAKE_TEST(VkImageViewSlicedCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_image_sliced_view_of_3d)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPipelineTessellationDomainOriginStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkSamplerYcbcrConversionInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkSamplerYcbcrConversionCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkBindImagePlaneMemoryInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkImagePlaneMemoryRequirementsInfo, VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceSamplerYcbcrConversionFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkSamplerYcbcrConversionImageFormatProperties, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_AMD_texture_gather_bias_lod)
    DO_MAKE_TEST(VkTextureLODGatherFormatPropertiesAMD, VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD);
#endif // if defined(VK_AMD_texture_gather_bias_lod)

#if defined(VK_EXT_conditional_rendering)
    DO_MAKE_TEST(VkConditionalRenderingBeginInfoEXT, VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT);
#endif // if defined(VK_EXT_conditional_rendering)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkProtectedSubmitInfo, VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceProtectedMemoryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceProtectedMemoryProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDeviceQueueInfo2, VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_NV_fragment_coverage_to_color)
    DO_MAKE_TEST(VkPipelineCoverageToColorStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_fragment_coverage_to_color)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceSamplerFilterMinmaxProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_sample_locations)
    DO_MAKE_TEST(VkSampleLocationsInfoEXT, VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT);
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    DO_MAKE_TEST(VkRenderPassSampleLocationsBeginInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT);
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    DO_MAKE_TEST(VkPipelineSampleLocationsStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    DO_MAKE_TEST(VkPhysicalDeviceSampleLocationsPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT);
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    DO_MAKE_TEST(VkMultisamplePropertiesEXT, VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT);
#endif // if defined(VK_EXT_sample_locations)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSamplerReductionModeCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_blend_operation_advanced)
    DO_MAKE_TEST(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT);
#endif // if defined(VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_multi_draw)
    DO_MAKE_TEST(VkPhysicalDeviceMultiDrawFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT);
#endif // if defined(VK_EXT_multi_draw)

#if defined(VK_EXT_blend_operation_advanced)
    DO_MAKE_TEST(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT);
#endif // if defined(VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced)
    DO_MAKE_TEST(VkPipelineColorBlendAdvancedStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_blend_operation_advanced)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceInlineUniformBlockFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceInlineUniformBlockProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkWriteDescriptorSetInlineUniformBlock, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkDescriptorPoolInlineUniformBlockCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_framebuffer_mixed_samples)
    DO_MAKE_TEST(VkPipelineCoverageModulationStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_framebuffer_mixed_samples)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkImageFormatListCreateInfo, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_validation_cache)
    DO_MAKE_TEST(VkValidationCacheCreateInfoEXT, VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
    DO_MAKE_TEST(VkShaderModuleValidationCacheCreateInfoEXT, VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_validation_cache)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance3Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance4Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance4Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance5Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance5Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance6Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance6Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_maintenance7)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance7FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR);
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance7PropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR);
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    DO_MAKE_TEST(VkPhysicalDeviceLayeredApiPropertiesListKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR);
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    DO_MAKE_TEST(VkPhysicalDeviceLayeredApiPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR);
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    DO_MAKE_TEST(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR);
#endif // if defined(VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance8)
    DO_MAKE_TEST(VkPhysicalDeviceMaintenance8FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR);
#endif // if defined(VK_KHR_maintenance8)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkRenderingAreaInfo, VK_STRUCTURE_TYPE_RENDERING_AREA_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkDescriptorSetLayoutSupport, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    DO_MAKE_TEST(VkPhysicalDeviceShaderDrawParametersFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);
#endif // if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceShaderFloat16Int8Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceFloatControlsProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceHostQueryResetFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_ANDROID_native_buffer)
    DO_MAKE_TEST(VkNativeBufferANDROID, VK_STRUCTURE_TYPE_NATIVE_BUFFER_ANDROID);
#endif // if defined(VK_ANDROID_native_buffer)

#if defined(VK_ANDROID_native_buffer)
    DO_MAKE_TEST(VkSwapchainImageCreateInfoANDROID, VK_STRUCTURE_TYPE_SWAPCHAIN_IMAGE_CREATE_INFO_ANDROID);
#endif // if defined(VK_ANDROID_native_buffer)

#if defined(VK_ANDROID_native_buffer)
    DO_MAKE_TEST(VkPhysicalDevicePresentationPropertiesANDROID, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_ANDROID);
#endif // if defined(VK_ANDROID_native_buffer)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkDeviceQueueGlobalPriorityCreateInfo, VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceGlobalPriorityQueryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkQueueFamilyGlobalPriorityProperties, VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_debug_utils)
    DO_MAKE_TEST(VkDebugUtilsObjectNameInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT);
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    DO_MAKE_TEST(VkDebugUtilsObjectTagInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT);
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    DO_MAKE_TEST(VkDebugUtilsLabelEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT);
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    DO_MAKE_TEST(VkDebugUtilsMessengerCreateInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    DO_MAKE_TEST(VkDebugUtilsMessengerCallbackDataEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT);
#endif // if defined(VK_EXT_debug_utils)

#if defined(VK_EXT_device_memory_report)
    DO_MAKE_TEST(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT);
#endif // if defined(VK_EXT_device_memory_report)

#if defined(VK_EXT_device_memory_report)
    DO_MAKE_TEST(VkDeviceDeviceMemoryReportCreateInfoEXT, VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_device_memory_report)

#if defined(VK_EXT_device_memory_report)
    DO_MAKE_TEST(VkDeviceMemoryReportCallbackDataEXT, VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT);
#endif // if defined(VK_EXT_device_memory_report)

#if defined(VK_EXT_external_memory_host)
    DO_MAKE_TEST(VkImportMemoryHostPointerInfoEXT, VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT);
#endif // if defined(VK_EXT_external_memory_host)

#if defined(VK_EXT_external_memory_host)
    DO_MAKE_TEST(VkMemoryHostPointerPropertiesEXT, VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT);
#endif // if defined(VK_EXT_external_memory_host)

#if defined(VK_EXT_external_memory_host)
    DO_MAKE_TEST(VkPhysicalDeviceExternalMemoryHostPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT);
#endif // if defined(VK_EXT_external_memory_host)

#if defined(VK_EXT_conservative_rasterization)
    DO_MAKE_TEST(VkPhysicalDeviceConservativeRasterizationPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT);
#endif // if defined(VK_EXT_conservative_rasterization)

#if defined(VK_KHR_calibrated_timestamps)
    DO_MAKE_TEST(VkCalibratedTimestampInfoKHR, VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR);
#endif // if defined(VK_KHR_calibrated_timestamps)

#if defined(VK_AMD_shader_core_properties)
    DO_MAKE_TEST(VkPhysicalDeviceShaderCorePropertiesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD);
#endif // if defined(VK_AMD_shader_core_properties)

#if defined(VK_AMD_shader_core_properties2)
    DO_MAKE_TEST(VkPhysicalDeviceShaderCoreProperties2AMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD);
#endif // if defined(VK_AMD_shader_core_properties2)

#if defined(VK_EXT_conservative_rasterization)
    DO_MAKE_TEST(VkPipelineRasterizationConservativeStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_conservative_rasterization)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceDescriptorIndexingFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceDescriptorIndexingProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkDescriptorSetLayoutBindingFlagsCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkDescriptorSetVariableDescriptorCountAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkDescriptorSetVariableDescriptorCountLayoutSupport, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkAttachmentDescription2, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkAttachmentReference2, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSubpassDescription2, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSubpassDependency2, VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkRenderPassCreateInfo2, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSubpassBeginInfo, VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSubpassEndInfo, VK_STRUCTURE_TYPE_SUBPASS_END_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceTimelineSemaphoreFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceTimelineSemaphoreProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSemaphoreTypeCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkTimelineSemaphoreSubmitInfo, VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSemaphoreWaitInfo, VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSemaphoreSignalInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPipelineVertexInputDivisorStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_vertex_attribute_divisor)
    DO_MAKE_TEST(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT);
#endif // if defined(VK_EXT_vertex_attribute_divisor)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceVertexAttributeDivisorProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_pci_bus_info)
    DO_MAKE_TEST(VkPhysicalDevicePCIBusInfoPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT);
#endif // if defined(VK_EXT_pci_bus_info)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    DO_MAKE_TEST(VkImportAndroidHardwareBufferInfoANDROID, VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID);
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    DO_MAKE_TEST(VkAndroidHardwareBufferUsageANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID);
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    DO_MAKE_TEST(VkAndroidHardwareBufferPropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID);
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    DO_MAKE_TEST(VkMemoryGetAndroidHardwareBufferInfoANDROID, VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID);
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    DO_MAKE_TEST(VkAndroidHardwareBufferFormatPropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID);
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_EXT_conditional_rendering)
    DO_MAKE_TEST(VkCommandBufferInheritanceConditionalRenderingInfoEXT, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT);
#endif // if defined(VK_EXT_conditional_rendering)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    DO_MAKE_TEST(VkExternalFormatANDROID, VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID);
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDevice8BitStorageFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_conditional_rendering)
    DO_MAKE_TEST(VkPhysicalDeviceConditionalRenderingFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT);
#endif // if defined(VK_EXT_conditional_rendering)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceVulkanMemoryModelFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceShaderAtomicInt64Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_shader_atomic_float)
    DO_MAKE_TEST(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT);
#endif // if defined(VK_EXT_shader_atomic_float)

#if defined(VK_EXT_shader_atomic_float2)
    DO_MAKE_TEST(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT);
#endif // if defined(VK_EXT_shader_atomic_float2)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceVertexAttributeDivisorFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_NV_device_diagnostic_checkpoints)
    DO_MAKE_TEST(VkQueueFamilyCheckpointPropertiesNV, VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV);
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
    DO_MAKE_TEST(VkCheckpointDataNV, VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV);
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceDepthStencilResolveProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkSubpassDescriptionDepthStencilResolve, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_astc_decode_mode)
    DO_MAKE_TEST(VkImageViewASTCDecodeModeEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT);
#endif // if defined(VK_EXT_astc_decode_mode)

#if defined(VK_EXT_astc_decode_mode)
    DO_MAKE_TEST(VkPhysicalDeviceASTCDecodeFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT);
#endif // if defined(VK_EXT_astc_decode_mode)

#if defined(VK_EXT_transform_feedback)
    DO_MAKE_TEST(VkPhysicalDeviceTransformFeedbackFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);
#endif // if defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
    DO_MAKE_TEST(VkPhysicalDeviceTransformFeedbackPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT);
#endif // if defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
    DO_MAKE_TEST(VkPipelineRasterizationStateStreamCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_transform_feedback)

#if defined(VK_NV_representative_fragment_test)
    DO_MAKE_TEST(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV);
#endif // if defined(VK_NV_representative_fragment_test)

#if defined(VK_NV_representative_fragment_test)
    DO_MAKE_TEST(VkPipelineRepresentativeFragmentTestStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_representative_fragment_test)

#if defined(VK_NV_scissor_exclusive)
    DO_MAKE_TEST(VkPhysicalDeviceExclusiveScissorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV);
#endif // if defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_scissor_exclusive)
    DO_MAKE_TEST(VkPipelineViewportExclusiveScissorStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_corner_sampled_image)
    DO_MAKE_TEST(VkPhysicalDeviceCornerSampledImageFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV);
#endif // if defined(VK_NV_corner_sampled_image)

#if defined(VK_KHR_compute_shader_derivatives)
    DO_MAKE_TEST(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR);
#endif // if defined(VK_KHR_compute_shader_derivatives)

#if defined(VK_KHR_compute_shader_derivatives)
    DO_MAKE_TEST(VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR);
#endif // if defined(VK_KHR_compute_shader_derivatives)

#if defined(VK_NV_shader_image_footprint)
    DO_MAKE_TEST(VkPhysicalDeviceShaderImageFootprintFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV);
#endif // if defined(VK_NV_shader_image_footprint)

#if defined(VK_NV_dedicated_allocation_image_aliasing)
    DO_MAKE_TEST(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV);
#endif // if defined(VK_NV_dedicated_allocation_image_aliasing)

#if defined(VK_NV_copy_memory_indirect)
    DO_MAKE_TEST(VkPhysicalDeviceCopyMemoryIndirectFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV);
#endif // if defined(VK_NV_copy_memory_indirect)

#if defined(VK_NV_copy_memory_indirect)
    DO_MAKE_TEST(VkPhysicalDeviceCopyMemoryIndirectPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV);
#endif // if defined(VK_NV_copy_memory_indirect)

#if defined(VK_NV_memory_decompression)
    DO_MAKE_TEST(VkPhysicalDeviceMemoryDecompressionFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV);
#endif // if defined(VK_NV_memory_decompression)

#if defined(VK_NV_memory_decompression)
    DO_MAKE_TEST(VkPhysicalDeviceMemoryDecompressionPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV);
#endif // if defined(VK_NV_memory_decompression)

#if defined(VK_NV_shading_rate_image)
    DO_MAKE_TEST(VkPipelineViewportShadingRateImageStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
    DO_MAKE_TEST(VkPhysicalDeviceShadingRateImageFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV);
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
    DO_MAKE_TEST(VkPhysicalDeviceShadingRateImagePropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV);
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_HUAWEI_invocation_mask)
    DO_MAKE_TEST(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI);
#endif // if defined(VK_HUAWEI_invocation_mask)

#if defined(VK_NV_shading_rate_image)
    DO_MAKE_TEST(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_shading_rate_image)

#if defined(VK_NV_mesh_shader)
    DO_MAKE_TEST(VkPhysicalDeviceMeshShaderFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV);
#endif // if defined(VK_NV_mesh_shader)

#if defined(VK_NV_mesh_shader)
    DO_MAKE_TEST(VkPhysicalDeviceMeshShaderPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV);
#endif // if defined(VK_NV_mesh_shader)

#if defined(VK_EXT_mesh_shader)
    DO_MAKE_TEST(VkPhysicalDeviceMeshShaderFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT);
#endif // if defined(VK_EXT_mesh_shader)

#if defined(VK_EXT_mesh_shader)
    DO_MAKE_TEST(VkPhysicalDeviceMeshShaderPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT);
#endif // if defined(VK_EXT_mesh_shader)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkRayTracingShaderGroupCreateInfoNV, VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_pipeline)
    DO_MAKE_TEST(VkRayTracingShaderGroupCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkRayTracingPipelineCreateInfoNV, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_pipeline)
    DO_MAKE_TEST(VkRayTracingPipelineCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkGeometryTrianglesNV, VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkGeometryAABBNV, VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkGeometryNV, VK_STRUCTURE_TYPE_GEOMETRY_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkAccelerationStructureInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkAccelerationStructureCreateInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkBindAccelerationStructureMemoryInfoNV, VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkWriteDescriptorSetAccelerationStructureKHR, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkWriteDescriptorSetAccelerationStructureNV, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkAccelerationStructureMemoryRequirementsInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkPhysicalDeviceAccelerationStructureFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingPipelineFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR);
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_query)
    DO_MAKE_TEST(VkPhysicalDeviceRayQueryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR);
#endif // if defined(VK_KHR_ray_query)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkPhysicalDeviceAccelerationStructurePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingPipelinePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR);
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV);
#endif // if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_maintenance1)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR);
#endif // if defined(VK_KHR_ray_tracing_maintenance1)

#if defined(VK_EXT_image_drm_format_modifier)
    DO_MAKE_TEST(VkDrmFormatModifierPropertiesListEXT, VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT);
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    DO_MAKE_TEST(VkPhysicalDeviceImageDrmFormatModifierInfoEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT);
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    DO_MAKE_TEST(VkImageDrmFormatModifierListCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    DO_MAKE_TEST(VkImageDrmFormatModifierExplicitCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    DO_MAKE_TEST(VkImageDrmFormatModifierPropertiesEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT);
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkImageStencilUsageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_AMD_memory_overallocation_behavior)
    DO_MAKE_TEST(VkDeviceMemoryOverallocationCreateInfoAMD, VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD);
#endif // if defined(VK_AMD_memory_overallocation_behavior)

#if defined(VK_EXT_fragment_density_map)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentDensityMapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT);
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_EXT_fragment_density_map2)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT);
#endif // if defined(VK_EXT_fragment_density_map2)

#if defined(VK_QCOM_fragment_density_map_offset)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM);
#endif // if defined(VK_QCOM_fragment_density_map_offset)

#if defined(VK_EXT_fragment_density_map)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentDensityMapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT);
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_EXT_fragment_density_map2)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT);
#endif // if defined(VK_EXT_fragment_density_map2)

#if defined(VK_QCOM_fragment_density_map_offset)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM);
#endif // if defined(VK_QCOM_fragment_density_map_offset)

#if defined(VK_EXT_fragment_density_map)
    DO_MAKE_TEST(VkRenderPassFragmentDensityMapCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_QCOM_fragment_density_map_offset)
    DO_MAKE_TEST(VkSubpassFragmentDensityMapOffsetEndInfoQCOM, VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM);
#endif // if defined(VK_QCOM_fragment_density_map_offset)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceScalarBlockLayoutFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_KHR_surface_protected_capabilities)
    DO_MAKE_TEST(VkSurfaceProtectedCapabilitiesKHR, VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_surface_protected_capabilities)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceUniformBufferStandardLayoutFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_depth_clip_enable)
    DO_MAKE_TEST(VkPhysicalDeviceDepthClipEnableFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT);
#endif // if defined(VK_EXT_depth_clip_enable)

#if defined(VK_EXT_depth_clip_enable)
    DO_MAKE_TEST(VkPipelineRasterizationDepthClipStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_depth_clip_enable)

#if defined(VK_EXT_memory_budget)
    DO_MAKE_TEST(VkPhysicalDeviceMemoryBudgetPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT);
#endif // if defined(VK_EXT_memory_budget)

#if defined(VK_EXT_memory_priority)
    DO_MAKE_TEST(VkPhysicalDeviceMemoryPriorityFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT);
#endif // if defined(VK_EXT_memory_priority)

#if defined(VK_EXT_memory_priority)
    DO_MAKE_TEST(VkMemoryPriorityAllocateInfoEXT, VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT);
#endif // if defined(VK_EXT_memory_priority)

#if defined(VK_EXT_pageable_device_local_memory)
    DO_MAKE_TEST(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT);
#endif // if defined(VK_EXT_pageable_device_local_memory)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceBufferDeviceAddressFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_buffer_device_address)
    DO_MAKE_TEST(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT);
#endif // if defined(VK_EXT_buffer_device_address)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkBufferDeviceAddressInfo, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkBufferOpaqueCaptureAddressCreateInfo, VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_buffer_device_address)
    DO_MAKE_TEST(VkBufferDeviceAddressCreateInfoEXT, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_buffer_device_address)

#if defined(VK_EXT_filter_cubic)
    DO_MAKE_TEST(VkPhysicalDeviceImageViewImageFormatInfoEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT);
#endif // if defined(VK_EXT_filter_cubic)

#if defined(VK_EXT_filter_cubic)
    DO_MAKE_TEST(VkFilterCubicImageViewImageFormatPropertiesEXT, VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT);
#endif // if defined(VK_EXT_filter_cubic)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceImagelessFramebufferFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkFramebufferAttachmentsCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkFramebufferAttachmentImageInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkRenderPassAttachmentBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceTextureCompressionASTCHDRFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_cooperative_matrix)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeMatrixFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV);
#endif // if defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_cooperative_matrix)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeMatrixPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV);
#endif // if defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_cooperative_matrix)
    DO_MAKE_TEST(VkCooperativeMatrixPropertiesNV, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV);
#endif // if defined(VK_NV_cooperative_matrix)

#if defined(VK_EXT_ycbcr_image_arrays)
    DO_MAKE_TEST(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT);
#endif // if defined(VK_EXT_ycbcr_image_arrays)

#if defined(VK_NVX_image_view_handle)
    DO_MAKE_TEST(VkImageViewHandleInfoNVX, VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX);
#endif // if defined(VK_NVX_image_view_handle)

#if defined(VK_NVX_image_view_handle)
    DO_MAKE_TEST(VkImageViewAddressPropertiesNVX, VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX);
#endif // if defined(VK_NVX_image_view_handle)

#if defined(VK_GGP_frame_token)
    DO_MAKE_TEST(VkPresentFrameTokenGGP, VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP);
#endif // if defined(VK_GGP_frame_token)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPipelineCreationFeedbackCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_full_screen_exclusive)
    DO_MAKE_TEST(VkSurfaceFullScreenExclusiveInfoEXT, VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT);
#endif // if defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
    DO_MAKE_TEST(VkSurfaceFullScreenExclusiveWin32InfoEXT, VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT);
#endif // if defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
    DO_MAKE_TEST(VkSurfaceCapabilitiesFullScreenExclusiveEXT, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT);
#endif // if defined(VK_EXT_full_screen_exclusive)

#if defined(VK_NV_present_barrier)
    DO_MAKE_TEST(VkPhysicalDevicePresentBarrierFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV);
#endif // if defined(VK_NV_present_barrier)

#if defined(VK_NV_present_barrier)
    DO_MAKE_TEST(VkSurfaceCapabilitiesPresentBarrierNV, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV);
#endif // if defined(VK_NV_present_barrier)

#if defined(VK_NV_present_barrier)
    DO_MAKE_TEST(VkSwapchainPresentBarrierCreateInfoNV, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV);
#endif // if defined(VK_NV_present_barrier)

#if defined(VK_KHR_performance_query)
    DO_MAKE_TEST(VkPhysicalDevicePerformanceQueryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    DO_MAKE_TEST(VkPhysicalDevicePerformanceQueryPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    DO_MAKE_TEST(VkPerformanceCounterKHR, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    DO_MAKE_TEST(VkPerformanceCounterDescriptionKHR, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    DO_MAKE_TEST(VkQueryPoolPerformanceCreateInfoKHR, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    DO_MAKE_TEST(VkAcquireProfilingLockInfoKHR, VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    DO_MAKE_TEST(VkPerformanceQuerySubmitInfoKHR, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    // DO_MAKE_TEST(VkPerformanceQueryReservationInfoKHR, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR);
#endif // if defined(VK_KHR_performance_query)

#if defined(VK_EXT_headless_surface)
    DO_MAKE_TEST(VkHeadlessSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_headless_surface)

#if defined(VK_NV_coverage_reduction_mode)
    DO_MAKE_TEST(VkPhysicalDeviceCoverageReductionModeFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV);
#endif // if defined(VK_NV_coverage_reduction_mode)

#if defined(VK_NV_coverage_reduction_mode)
    DO_MAKE_TEST(VkPipelineCoverageReductionStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_coverage_reduction_mode)

#if defined(VK_NV_coverage_reduction_mode)
    DO_MAKE_TEST(VkFramebufferMixedSamplesCombinationNV, VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV);
#endif // if defined(VK_NV_coverage_reduction_mode)

#if defined(VK_INTEL_shader_integer_functions2)
    DO_MAKE_TEST(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL);
#endif // if defined(VK_INTEL_shader_integer_functions2)

#if defined(VK_INTEL_performance_query)
    DO_MAKE_TEST(VkInitializePerformanceApiInfoINTEL, VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL);
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    DO_MAKE_TEST(VkQueryPoolPerformanceQueryCreateInfoINTEL, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL);
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    DO_MAKE_TEST(VkPerformanceMarkerInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL);
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    DO_MAKE_TEST(VkPerformanceStreamMarkerInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL);
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    DO_MAKE_TEST(VkPerformanceOverrideInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL);
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    DO_MAKE_TEST(VkPerformanceConfigurationAcquireInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL);
#endif // if defined(VK_INTEL_performance_query)

#if defined(VK_KHR_shader_clock)
    DO_MAKE_TEST(VkPhysicalDeviceShaderClockFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR);
#endif // if defined(VK_KHR_shader_clock)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceIndexTypeUint8Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_NV_shader_sm_builtins)
    DO_MAKE_TEST(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV);
#endif // if defined(VK_NV_shader_sm_builtins)

#if defined(VK_NV_shader_sm_builtins)
    DO_MAKE_TEST(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV);
#endif // if defined(VK_NV_shader_sm_builtins)

#if defined(VK_EXT_fragment_shader_interlock)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT);
#endif // if defined(VK_EXT_fragment_shader_interlock)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkAttachmentReferenceStencilLayout, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_EXT_primitive_topology_list_restart)
    DO_MAKE_TEST(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT);
#endif // if defined(VK_EXT_primitive_topology_list_restart)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkAttachmentDescriptionStencilLayout, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_KHR_pipeline_executable_properties)
    DO_MAKE_TEST(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR);
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    DO_MAKE_TEST(VkPipelineInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    DO_MAKE_TEST(VkPipelineExecutablePropertiesKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR);
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    DO_MAKE_TEST(VkPipelineExecutableInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    DO_MAKE_TEST(VkPipelineExecutableStatisticKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR);
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    DO_MAKE_TEST(VkPipelineExecutableInternalRepresentationKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR);
#endif // if defined(VK_KHR_pipeline_executable_properties)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_texel_buffer_alignment)
    DO_MAKE_TEST(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT);
#endif // if defined(VK_EXT_texel_buffer_alignment)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceTexelBufferAlignmentProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceSubgroupSizeControlFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceSubgroupSizeControlProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPipelineShaderStageRequiredSubgroupSizeCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_HUAWEI_subpass_shading)
    DO_MAKE_TEST(VkSubpassShadingPipelineCreateInfoHUAWEI, VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI);
#endif // if defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_subpass_shading)
    DO_MAKE_TEST(VkPhysicalDeviceSubpassShadingPropertiesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI);
#endif // if defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_cluster_culling_shader)
    DO_MAKE_TEST(VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI);
#endif // if defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkMemoryOpaqueCaptureAddressAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkDeviceMemoryOpaqueCaptureAddressInfo, VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceLineRasterizationFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceLineRasterizationProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPipelineRasterizationLineStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDevicePipelineCreationCacheControlFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan11Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan11Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan12Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan12Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES);
#endif // if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan13Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan13Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan14Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceVulkan14Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_AMD_pipeline_compiler_control)
    DO_MAKE_TEST(VkPipelineCompilerControlCreateInfoAMD, VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD);
#endif // if defined(VK_AMD_pipeline_compiler_control)

#if defined(VK_AMD_device_coherent_memory)
    DO_MAKE_TEST(VkPhysicalDeviceCoherentMemoryFeaturesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD);
#endif // if defined(VK_AMD_device_coherent_memory)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkFaultData, VK_STRUCTURE_TYPE_FAULT_DATA);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkFaultCallbackInfo, VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceToolProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_custom_border_color)
    DO_MAKE_TEST(VkSamplerCustomBorderColorCreateInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_custom_border_color)

#if defined(VK_EXT_custom_border_color)
    DO_MAKE_TEST(VkPhysicalDeviceCustomBorderColorPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT);
#endif // if defined(VK_EXT_custom_border_color)

#if defined(VK_EXT_custom_border_color)
    DO_MAKE_TEST(VkPhysicalDeviceCustomBorderColorFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT);
#endif // if defined(VK_EXT_custom_border_color)

#if defined(VK_EXT_border_color_swizzle)
    DO_MAKE_TEST(VkSamplerBorderColorComponentMappingCreateInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_border_color_swizzle)

#if defined(VK_EXT_border_color_swizzle)
    DO_MAKE_TEST(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT);
#endif // if defined(VK_EXT_border_color_swizzle)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureGeometryTrianglesDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureGeometryAabbsDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureGeometryInstancesDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    DO_MAKE_TEST(VkAccelerationStructureGeometryLinearSweptSpheresDataNV,
                 VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV);
#endif // if defined(VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    DO_MAKE_TEST(VkAccelerationStructureGeometrySpheresDataNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV);
#endif // if defined(VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureGeometryKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureBuildGeometryInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureCreateInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureDeviceAddressInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureVersionInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkCopyAccelerationStructureInfoKHR, VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkCopyAccelerationStructureToMemoryInfoKHR, VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkCopyMemoryToAccelerationStructureInfoKHR, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    DO_MAKE_TEST(VkRayTracingPipelineInterfaceCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_pipeline_library)
    DO_MAKE_TEST(VkPipelineLibraryCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_pipeline_library)

#if defined(VK_KHR_object_refresh)
    DO_MAKE_TEST(VkRefreshObjectListKHR, VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR);
#endif // if defined(VK_KHR_object_refresh)

#if defined(VK_EXT_extended_dynamic_state)
    DO_MAKE_TEST(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT);
#endif // if defined(VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state2)
    DO_MAKE_TEST(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT);
#endif // if defined(VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state3)
    DO_MAKE_TEST(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT);
#endif // if defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
    DO_MAKE_TEST(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT);
#endif // if defined(VK_EXT_extended_dynamic_state3)

#if defined(VK_QCOM_render_pass_transform)
    DO_MAKE_TEST(VkRenderPassTransformBeginInfoQCOM, VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM);
#endif // if defined(VK_QCOM_render_pass_transform)

#if defined(VK_QCOM_rotated_copy_commands)
    DO_MAKE_TEST(VkCopyCommandTransformInfoQCOM, VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM);
#endif // if defined(VK_QCOM_rotated_copy_commands)

#if defined(VK_QCOM_render_pass_transform)
    DO_MAKE_TEST(VkCommandBufferInheritanceRenderPassTransformInfoQCOM, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM);
#endif // if defined(VK_QCOM_render_pass_transform)

#if defined(VK_NV_partitioned_acceleration_structure)
    DO_MAKE_TEST(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV);
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    DO_MAKE_TEST(VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV);
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    DO_MAKE_TEST(VkPartitionedAccelerationStructureFlagsNV, VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV);
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    DO_MAKE_TEST(VkWriteDescriptorSetPartitionedAccelerationStructureNV,
                 VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV);
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    DO_MAKE_TEST(VkPartitionedAccelerationStructureInstancesInputNV, VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV);
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    DO_MAKE_TEST(VkBuildPartitionedAccelerationStructureInfoNV, VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV);
#endif // if defined(VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_device_diagnostics_config)
    DO_MAKE_TEST(VkPhysicalDeviceDiagnosticsConfigFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV);
#endif // if defined(VK_NV_device_diagnostics_config)

#if defined(VK_NV_device_diagnostics_config)
    DO_MAKE_TEST(VkDeviceDiagnosticsConfigCreateInfoNV, VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV);
#endif // if defined(VK_NV_device_diagnostics_config)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkPipelineOfflineCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_shader_subgroup_uniform_control_flow)
    DO_MAKE_TEST(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR);
#endif // if defined(VK_KHR_shader_subgroup_uniform_control_flow)

#if defined(VK_EXT_robustness2)
    DO_MAKE_TEST(VkPhysicalDeviceRobustness2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT);
#endif // if defined(VK_EXT_robustness2)

#if defined(VK_EXT_robustness2)
    DO_MAKE_TEST(VkPhysicalDeviceRobustness2PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT);
#endif // if defined(VK_EXT_robustness2)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceImageRobustnessFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_workgroup_memory_explicit_layout)
    DO_MAKE_TEST(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR);
#endif // if defined(VK_KHR_workgroup_memory_explicit_layout)

#if defined(VK_KHR_portability_subset) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPhysicalDevicePortabilitySubsetFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR);
#endif // if defined(VK_KHR_portability_subset)

#if defined(VK_KHR_portability_subset) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPhysicalDevicePortabilitySubsetPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR);
#endif // if defined(VK_KHR_portability_subset)

#if defined(VK_EXT_4444_formats)
    DO_MAKE_TEST(VkPhysicalDevice4444FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT);
#endif // if defined(VK_EXT_4444_formats)

#if defined(VK_HUAWEI_subpass_shading)
    DO_MAKE_TEST(VkPhysicalDeviceSubpassShadingFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI);
#endif // if defined(VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_cluster_culling_shader)
    DO_MAKE_TEST(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI);
#endif // if defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_HUAWEI_cluster_culling_shader)
    DO_MAKE_TEST(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI);
#endif // if defined(VK_HUAWEI_cluster_culling_shader)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkBufferCopy2, VK_STRUCTURE_TYPE_BUFFER_COPY_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkImageCopy2, VK_STRUCTURE_TYPE_IMAGE_COPY_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkImageBlit2, VK_STRUCTURE_TYPE_IMAGE_BLIT_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkBufferImageCopy2, VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkImageResolve2, VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkCopyBufferInfo2, VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkCopyImageInfo2, VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkBlitImageInfo2, VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkCopyBufferToImageInfo2, VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkCopyImageToBufferInfo2, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkResolveImageInfo2, VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_shader_image_atomic_int64)
    DO_MAKE_TEST(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT);
#endif // if defined(VK_EXT_shader_image_atomic_int64)

#if defined(VK_KHR_fragment_shading_rate)
    DO_MAKE_TEST(VkFragmentShadingRateAttachmentInfoKHR, VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR);
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    DO_MAKE_TEST(VkPipelineFragmentShadingRateStateCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShadingRateFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR);
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShadingRatePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR);
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShadingRateKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR);
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceShaderTerminateInvocationFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_fragment_shading_rate_enums)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV);
#endif // if defined(VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV);
#endif // if defined(VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums)
    DO_MAKE_TEST(VkPipelineFragmentShadingRateEnumStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV);
#endif // if defined(VK_NV_fragment_shading_rate_enums)

#if defined(VK_KHR_acceleration_structure)
    DO_MAKE_TEST(VkAccelerationStructureBuildSizesInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR);
#endif // if defined(VK_KHR_acceleration_structure)

#if defined(VK_EXT_image_2d_view_of_3d)
    DO_MAKE_TEST(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT);
#endif // if defined(VK_EXT_image_2d_view_of_3d)

#if defined(VK_EXT_image_sliced_view_of_3d)
    DO_MAKE_TEST(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT);
#endif // if defined(VK_EXT_image_sliced_view_of_3d)

#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
    DO_MAKE_TEST(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT);
#endif // if defined(VK_EXT_attachment_feedback_loop_dynamic_state)

#if defined(VK_EXT_legacy_vertex_attributes)
    DO_MAKE_TEST(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT);
#endif // if defined(VK_EXT_legacy_vertex_attributes)

#if defined(VK_EXT_legacy_vertex_attributes)
    DO_MAKE_TEST(VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT);
#endif // if defined(VK_EXT_legacy_vertex_attributes)

#if defined(VK_EXT_mutable_descriptor_type)
    DO_MAKE_TEST(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT);
#endif // if defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_EXT_mutable_descriptor_type)
    DO_MAKE_TEST(VkMutableDescriptorTypeCreateInfoEXT, VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_EXT_depth_clip_control)
    DO_MAKE_TEST(VkPhysicalDeviceDepthClipControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT);
#endif // if defined(VK_EXT_depth_clip_control)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkGeneratedCommandsPipelineInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkGeneratedCommandsShaderInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkGeneratedCommandsMemoryRequirementsInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkIndirectExecutionSetPipelineInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkIndirectExecutionSetShaderLayoutInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkIndirectExecutionSetShaderInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkIndirectExecutionSetCreateInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkGeneratedCommandsInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkWriteIndirectExecutionSetPipelineEXT, VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkWriteIndirectExecutionSetShaderEXT, VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkIndirectCommandsLayoutCreateInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    DO_MAKE_TEST(VkIndirectCommandsLayoutTokenEXT, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT);
#endif // if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_depth_clip_control)
    DO_MAKE_TEST(VkPipelineViewportDepthClipControlCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_depth_clip_control)

#if defined(VK_EXT_depth_clamp_control)
    DO_MAKE_TEST(VkPhysicalDeviceDepthClampControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT);
#endif // if defined(VK_EXT_depth_clamp_control)

#if defined(VK_EXT_depth_clamp_control)
    DO_MAKE_TEST(VkPipelineViewportDepthClampControlCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_depth_clamp_control)

#if defined(VK_EXT_vertex_input_dynamic_state)
    DO_MAKE_TEST(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT);
#endif // if defined(VK_EXT_vertex_input_dynamic_state)

#if defined(VK_NV_external_memory_rdma)
    DO_MAKE_TEST(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV);
#endif // if defined(VK_NV_external_memory_rdma)

#if defined(VK_KHR_shader_relaxed_extended_instruction)
    DO_MAKE_TEST(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR);
#endif // if defined(VK_KHR_shader_relaxed_extended_instruction)

#if defined(VK_EXT_shader_object)
    DO_MAKE_TEST(VkVertexInputBindingDescription2EXT, VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT);
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    DO_MAKE_TEST(VkVertexInputAttributeDescription2EXT, VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT);
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_color_write_enable)
    DO_MAKE_TEST(VkPhysicalDeviceColorWriteEnableFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT);
#endif // if defined(VK_EXT_color_write_enable)

#if defined(VK_EXT_color_write_enable)
    DO_MAKE_TEST(VkPipelineColorWriteCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_color_write_enable)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkMemoryBarrier2, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkImageMemoryBarrier2, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkBufferMemoryBarrier2, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_maintenance8)
    DO_MAKE_TEST(VkMemoryBarrierAccessFlags3KHR, VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR);
#endif // if defined(VK_KHR_maintenance8)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkDependencyInfo, VK_STRUCTURE_TYPE_DEPENDENCY_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkSemaphoreSubmitInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkCommandBufferSubmitInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkSubmitInfo2, VK_STRUCTURE_TYPE_SUBMIT_INFO_2);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_NV_device_diagnostic_checkpoints)
    DO_MAKE_TEST(VkQueueFamilyCheckpointProperties2NV, VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV);
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
    DO_MAKE_TEST(VkCheckpointData2NV, VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV);
#endif // if defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceSynchronization2Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceHostImageCopyFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceHostImageCopyProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkMemoryToImageCopy, VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkImageToMemoryCopy, VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkCopyMemoryToImageInfo, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkCopyImageToMemoryInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkCopyImageToImageInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkHostImageLayoutTransitionInfo, VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkSubresourceHostMemcpySize, VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkHostImageCopyDevicePerformanceQuery, VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY);
#endif // if defined(VK_VERSION_1_4)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkPhysicalDeviceVulkanSC10Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkPipelinePoolSize, VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkDeviceObjectReservationCreateInfo, VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkCommandPoolMemoryReservationCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkCommandPoolMemoryConsumption, VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_CONSUMPTION);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    DO_MAKE_TEST(VkPhysicalDeviceVulkanSC10Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES);
#endif // if defined(VKSC_VERSION_1_0)

#if defined(VK_EXT_primitives_generated_query)
    DO_MAKE_TEST(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT);
#endif // if defined(VK_EXT_primitives_generated_query)

#if defined(VK_EXT_legacy_dithering)
    DO_MAKE_TEST(VkPhysicalDeviceLegacyDitheringFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT);
#endif // if defined(VK_EXT_legacy_dithering)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    DO_MAKE_TEST(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT);
#endif // if defined(VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    DO_MAKE_TEST(VkSubpassResolvePerformanceQueryEXT, VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT);
#endif // if defined(VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    DO_MAKE_TEST(VkMultisampledRenderToSingleSampledInfoEXT, VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT);
#endif // if defined(VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDevicePipelineProtectedAccessFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkQueueFamilyVideoPropertiesKHR, VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkQueueFamilyQueryResultStatusPropertiesKHR, VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoProfileListInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkPhysicalDeviceVideoFormatInfoKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoFormatPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoEncodeQuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoEncodeH264QuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoEncodeH265QuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoEncodeAV1QuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoFormatQuantizationMapPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoFormatH265QuantizationMapPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoFormatAV1QuantizationMapPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoSessionMemoryRequirementsKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkBindVideoSessionMemoryInfoKHR, VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoPictureResourceInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoReferenceSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_decode_queue)
    DO_MAKE_TEST(VkVideoDecodeCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue)
    DO_MAKE_TEST(VkVideoDecodeUsageInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue)
    DO_MAKE_TEST(VkVideoDecodeInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_maintenance1)
    DO_MAKE_TEST(VkPhysicalDeviceVideoMaintenance1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR);
#endif // if defined(VK_KHR_video_maintenance1)

#if defined(VK_KHR_video_maintenance2)
    DO_MAKE_TEST(VkPhysicalDeviceVideoMaintenance2FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR);
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_maintenance1)
    DO_MAKE_TEST(VkVideoInlineQueryInfoKHR, VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR);
#endif // if defined(VK_KHR_video_maintenance1)

#if defined(VK_KHR_video_decode_h264)
    DO_MAKE_TEST(VkVideoDecodeH264ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    DO_MAKE_TEST(VkVideoDecodeH264CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    DO_MAKE_TEST(VkVideoDecodeH264SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    DO_MAKE_TEST(VkVideoDecodeH264SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_maintenance2)
    DO_MAKE_TEST(VkVideoDecodeH264InlineSessionParametersInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR);
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_h264)
    DO_MAKE_TEST(VkVideoDecodeH264PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    DO_MAKE_TEST(VkVideoDecodeH264DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h265)
    DO_MAKE_TEST(VkVideoDecodeH265ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    DO_MAKE_TEST(VkVideoDecodeH265CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    DO_MAKE_TEST(VkVideoDecodeH265SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    DO_MAKE_TEST(VkVideoDecodeH265SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_maintenance2)
    DO_MAKE_TEST(VkVideoDecodeH265InlineSessionParametersInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR);
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_h265)
    DO_MAKE_TEST(VkVideoDecodeH265PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    DO_MAKE_TEST(VkVideoDecodeH265DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_av1)
    DO_MAKE_TEST(VkVideoDecodeAV1ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    DO_MAKE_TEST(VkVideoDecodeAV1CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    DO_MAKE_TEST(VkVideoDecodeAV1SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_maintenance2)
    DO_MAKE_TEST(VkVideoDecodeAV1InlineSessionParametersInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR);
#endif // if defined(VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_av1)
    DO_MAKE_TEST(VkVideoDecodeAV1PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    DO_MAKE_TEST(VkVideoDecodeAV1DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR);
#endif // if defined(VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoSessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoSessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoSessionParametersUpdateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeSessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeSessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoBeginCodingInfoKHR, VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoEndCodingInfoKHR, VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    DO_MAKE_TEST(VkVideoCodingControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR);
#endif // if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeUsageInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoEncodeQuantizationMapInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR,
                 VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    DO_MAKE_TEST(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR);
#endif // if defined(VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkQueryPoolVideoEncodeFeedbackCreateInfoKHR, VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeQualityLevelInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeQualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeRateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeRateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    DO_MAKE_TEST(VkVideoEncodeCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264SessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264SessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264NaluSliceInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    DO_MAKE_TEST(VkVideoEncodeH264RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265SessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265SessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265NaluSliceSegmentInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    DO_MAKE_TEST(VkVideoEncodeH265DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    DO_MAKE_TEST(VkVideoEncodeAV1RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR);
#endif // if defined(VK_KHR_video_encode_av1)

#if defined(VK_NV_inherited_viewport_scissor)
    DO_MAKE_TEST(VkPhysicalDeviceInheritedViewportScissorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV);
#endif // if defined(VK_NV_inherited_viewport_scissor)

#if defined(VK_NV_inherited_viewport_scissor)
    DO_MAKE_TEST(VkCommandBufferInheritanceViewportScissorInfoNV, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV);
#endif // if defined(VK_NV_inherited_viewport_scissor)

#if defined(VK_EXT_ycbcr_2plane_444_formats)
    DO_MAKE_TEST(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT);
#endif // if defined(VK_EXT_ycbcr_2plane_444_formats)

#if defined(VK_EXT_provoking_vertex)
    DO_MAKE_TEST(VkPhysicalDeviceProvokingVertexFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT);
#endif // if defined(VK_EXT_provoking_vertex)

#if defined(VK_EXT_provoking_vertex)
    DO_MAKE_TEST(VkPhysicalDeviceProvokingVertexPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT);
#endif // if defined(VK_EXT_provoking_vertex)

#if defined(VK_EXT_provoking_vertex)
    DO_MAKE_TEST(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT,
                 VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_provoking_vertex)

#if defined(VK_NVX_binary_import)
    DO_MAKE_TEST(VkCuModuleCreateInfoNVX, VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX);
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    DO_MAKE_TEST(VkCuModuleTexturingModeCreateInfoNVX, VK_STRUCTURE_TYPE_CU_MODULE_TEXTURING_MODE_CREATE_INFO_NVX);
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    DO_MAKE_TEST(VkCuFunctionCreateInfoNVX, VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX);
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    DO_MAKE_TEST(VkCuLaunchInfoNVX, VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX);
#endif // if defined(VK_NVX_binary_import)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkPhysicalDeviceDescriptorBufferFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkPhysicalDeviceDescriptorBufferPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkDescriptorAddressInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkDescriptorBufferBindingInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkDescriptorBufferBindingPushDescriptorBufferHandleEXT,
                 VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkDescriptorGetInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkBufferCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkImageCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkImageViewCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkSamplerCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkAccelerationStructureCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    DO_MAKE_TEST(VkOpaqueCaptureDescriptorDataCreateInfoEXT, VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_descriptor_buffer)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceShaderIntegerDotProductFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceShaderIntegerDotProductProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_physical_device_drm)
    DO_MAKE_TEST(VkPhysicalDeviceDrmPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT);
#endif // if defined(VK_EXT_physical_device_drm)

#if defined(VK_KHR_fragment_shader_barycentric)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR);
#endif // if defined(VK_KHR_fragment_shader_barycentric)

#if defined(VK_KHR_fragment_shader_barycentric)
    DO_MAKE_TEST(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR);
#endif // if defined(VK_KHR_fragment_shader_barycentric)

#if defined(VK_NV_ray_tracing_motion_blur)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV);
#endif // if defined(VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_ray_tracing_validation)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingValidationFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV);
#endif // if defined(VK_NV_ray_tracing_validation)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV);
#endif // if defined(VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_NV_ray_tracing_motion_blur)
    DO_MAKE_TEST(VkAccelerationStructureGeometryMotionTrianglesDataNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV);
#endif // if defined(VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_ray_tracing_motion_blur)
    DO_MAKE_TEST(VkAccelerationStructureMotionInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV);
#endif // if defined(VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_external_memory_rdma)
    DO_MAKE_TEST(VkMemoryGetRemoteAddressInfoNV, VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV);
#endif // if defined(VK_NV_external_memory_rdma)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkImportMemoryBufferCollectionFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkBufferCollectionImageCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkBufferCollectionBufferCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkBufferCollectionCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkBufferCollectionPropertiesFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkBufferConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkSysmemColorSpaceFUCHSIA, VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkImageFormatConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkImageConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    DO_MAKE_TEST(VkBufferCollectionConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA);
#endif // if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_NV_cuda_kernel_launch)
    DO_MAKE_TEST(VkCudaModuleCreateInfoNV, VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV);
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    DO_MAKE_TEST(VkCudaFunctionCreateInfoNV, VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV);
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    DO_MAKE_TEST(VkCudaLaunchInfoNV, VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV);
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_EXT_rgba10x6_formats)
    DO_MAKE_TEST(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT);
#endif // if defined(VK_EXT_rgba10x6_formats)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkFormatProperties3, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_EXT_image_drm_format_modifier)
    DO_MAKE_TEST(VkDrmFormatModifierPropertiesList2EXT, VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT);
#endif // if defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    DO_MAKE_TEST(VkAndroidHardwareBufferFormatProperties2ANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID);
#endif // if defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPipelineRenderingCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkRenderingInfo, VK_STRUCTURE_TYPE_RENDERING_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkRenderingAttachmentInfo, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_KHR_fragment_shading_rate)
    DO_MAKE_TEST(VkRenderingFragmentShadingRateAttachmentInfoKHR, VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR);
#endif // if defined(VK_KHR_fragment_shading_rate)

#if defined(VK_EXT_fragment_density_map)
    DO_MAKE_TEST(VkRenderingFragmentDensityMapAttachmentInfoEXT, VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT);
#endif // if defined(VK_EXT_fragment_density_map)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkPhysicalDeviceDynamicRenderingFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    DO_MAKE_TEST(VkCommandBufferInheritanceRenderingInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO);
#endif // if defined(VK_VERSION_1_3)

#if defined(VK_AMD_mixed_attachment_samples)
    DO_MAKE_TEST(VkAttachmentSampleCountInfoAMD, VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD);
#endif // if defined(VK_AMD_mixed_attachment_samples)

#if defined(VK_NVX_multiview_per_view_attributes)
    DO_MAKE_TEST(VkMultiviewPerViewAttributesInfoNVX, VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX);
#endif // if defined(VK_NVX_multiview_per_view_attributes)

#if defined(VK_EXT_image_view_min_lod)
    DO_MAKE_TEST(VkPhysicalDeviceImageViewMinLodFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT);
#endif // if defined(VK_EXT_image_view_min_lod)

#if defined(VK_EXT_image_view_min_lod)
    DO_MAKE_TEST(VkImageViewMinLodCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_image_view_min_lod)

#if defined(VK_EXT_rasterization_order_attachment_access)
    DO_MAKE_TEST(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT);
#endif // if defined(VK_EXT_rasterization_order_attachment_access)

#if defined(VK_NV_linear_color_attachment)
    DO_MAKE_TEST(VkPhysicalDeviceLinearColorAttachmentFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV);
#endif // if defined(VK_NV_linear_color_attachment)

#if defined(VK_EXT_graphics_pipeline_library)
    DO_MAKE_TEST(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT);
#endif // if defined(VK_EXT_graphics_pipeline_library)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPhysicalDevicePipelineBinaryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkDevicePipelineBinaryInternalCacheControlKHR, VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    DO_MAKE_TEST(VkPhysicalDevicePipelineBinaryPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR);
#endif // if defined(VK_KHR_pipeline_binary)

#if defined(VK_EXT_graphics_pipeline_library)
    DO_MAKE_TEST(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT);
#endif // if defined(VK_EXT_graphics_pipeline_library)

#if defined(VK_EXT_graphics_pipeline_library)
    DO_MAKE_TEST(VkGraphicsPipelineLibraryCreateInfoEXT, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_graphics_pipeline_library)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    DO_MAKE_TEST(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE);
#endif // if defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    DO_MAKE_TEST(VkDescriptorSetBindingReferenceVALVE, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE);
#endif // if defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    DO_MAKE_TEST(VkDescriptorSetLayoutHostMappingInfoVALVE, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE);
#endif // if defined(VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_EXT_nested_command_buffer)
    DO_MAKE_TEST(VkPhysicalDeviceNestedCommandBufferFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT);
#endif // if defined(VK_EXT_nested_command_buffer)

#if defined(VK_EXT_nested_command_buffer)
    DO_MAKE_TEST(VkPhysicalDeviceNestedCommandBufferPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT);
#endif // if defined(VK_EXT_nested_command_buffer)

#if defined(VK_EXT_shader_module_identifier)
    DO_MAKE_TEST(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT);
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    DO_MAKE_TEST(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT);
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    DO_MAKE_TEST(VkPipelineShaderStageModuleIdentifierCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    DO_MAKE_TEST(VkShaderModuleIdentifierEXT, VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT);
#endif // if defined(VK_EXT_shader_module_identifier)

#if defined(VK_EXT_image_compression_control)
    DO_MAKE_TEST(VkImageCompressionControlEXT, VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT);
#endif // if defined(VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control)
    DO_MAKE_TEST(VkPhysicalDeviceImageCompressionControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT);
#endif // if defined(VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control)
    DO_MAKE_TEST(VkImageCompressionPropertiesEXT, VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT);
#endif // if defined(VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control_swapchain)
    DO_MAKE_TEST(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT);
#endif // if defined(VK_EXT_image_compression_control_swapchain)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkImageSubresource2, VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkSubresourceLayout2, VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_subpass_merge_feedback)
    DO_MAKE_TEST(VkRenderPassCreationControlEXT, VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT);
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    DO_MAKE_TEST(VkRenderPassCreationFeedbackCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    DO_MAKE_TEST(VkRenderPassSubpassFeedbackCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    DO_MAKE_TEST(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT);
#endif // if defined(VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkMicromapBuildInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkMicromapCreateInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkMicromapVersionInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkCopyMicromapInfoEXT, VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkCopyMicromapToMemoryInfoEXT, VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkCopyMemoryToMicromapInfoEXT, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkMicromapBuildSizesInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkPhysicalDeviceOpacityMicromapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkPhysicalDeviceOpacityMicromapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    DO_MAKE_TEST(VkAccelerationStructureTrianglesOpacityMicromapEXT, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT);
#endif // if defined(VK_EXT_opacity_micromap)

#if defined(VK_NV_displacement_micromap) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPhysicalDeviceDisplacementMicromapFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV);
#endif // if defined(VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPhysicalDeviceDisplacementMicromapPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV);
#endif // if defined(VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkAccelerationStructureTrianglesDisplacementMicromapNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV);
#endif // if defined(VK_NV_displacement_micromap)

#if defined(VK_EXT_pipeline_properties)
    DO_MAKE_TEST(VkPipelinePropertiesIdentifierEXT, VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT);
#endif // if defined(VK_EXT_pipeline_properties)

#if defined(VK_EXT_pipeline_properties)
    DO_MAKE_TEST(VkPhysicalDevicePipelinePropertiesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT);
#endif // if defined(VK_EXT_pipeline_properties)

#if defined(VK_AMD_shader_early_and_late_fragment_tests)
    DO_MAKE_TEST(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD);
#endif // if defined(VK_AMD_shader_early_and_late_fragment_tests)

#if defined(VK_EXT_external_memory_acquire_unmodified)
    DO_MAKE_TEST(VkExternalMemoryAcquireUnmodifiedEXT, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT);
#endif // if defined(VK_EXT_external_memory_acquire_unmodified)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalObjectCreateInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalObjectsInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalDeviceInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalCommandQueueInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalBufferInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkImportMetalBufferInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalTextureInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkImportMetalTextureInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalIOSurfaceInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkImportMetalIOSurfaceInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkExportMetalSharedEventInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    DO_MAKE_TEST(VkImportMetalSharedEventInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT);
#endif // if defined(VK_EXT_metal_objects)

#if defined(VK_EXT_non_seamless_cube_map)
    DO_MAKE_TEST(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT);
#endif // if defined(VK_EXT_non_seamless_cube_map)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDevicePipelineRobustnessFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPipelineRobustnessCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDevicePipelineRobustnessProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_QCOM_image_processing)
    DO_MAKE_TEST(VkImageViewSampleWeightCreateInfoQCOM, VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM);
#endif // if defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    DO_MAKE_TEST(VkPhysicalDeviceImageProcessingFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM);
#endif // if defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    DO_MAKE_TEST(VkPhysicalDeviceImageProcessingPropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM);
#endif // if defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_tile_properties)
    DO_MAKE_TEST(VkPhysicalDeviceTilePropertiesFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM);
#endif // if defined(VK_QCOM_tile_properties)

#if defined(VK_QCOM_tile_properties)
    DO_MAKE_TEST(VkTilePropertiesQCOM, VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM);
#endif // if defined(VK_QCOM_tile_properties)

#if defined(VK_SEC_amigo_profiling)
    DO_MAKE_TEST(VkPhysicalDeviceAmigoProfilingFeaturesSEC, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC);
#endif // if defined(VK_SEC_amigo_profiling)

#if defined(VK_SEC_amigo_profiling)
    DO_MAKE_TEST(VkAmigoProfilingSubmitInfoSEC, VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC);
#endif // if defined(VK_SEC_amigo_profiling)

#if defined(VK_EXT_attachment_feedback_loop_layout)
    DO_MAKE_TEST(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT);
#endif // if defined(VK_EXT_attachment_feedback_loop_layout)

#if defined(VK_EXT_device_address_binding_report)
    DO_MAKE_TEST(VkPhysicalDeviceAddressBindingReportFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT);
#endif // if defined(VK_EXT_device_address_binding_report)

#if defined(VK_EXT_device_address_binding_report)
    DO_MAKE_TEST(VkDeviceAddressBindingCallbackDataEXT, VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT);
#endif // if defined(VK_EXT_device_address_binding_report)

#if defined(VK_NV_optical_flow)
    DO_MAKE_TEST(VkPhysicalDeviceOpticalFlowFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV);
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    DO_MAKE_TEST(VkPhysicalDeviceOpticalFlowPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV);
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    DO_MAKE_TEST(VkOpticalFlowImageFormatInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV);
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    DO_MAKE_TEST(VkOpticalFlowImageFormatPropertiesNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV);
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    DO_MAKE_TEST(VkOpticalFlowSessionCreateInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV);
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    DO_MAKE_TEST(VkOpticalFlowSessionCreatePrivateDataInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV);
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    DO_MAKE_TEST(VkOpticalFlowExecuteInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV);
#endif // if defined(VK_NV_optical_flow)

#if defined(VK_EXT_device_fault)
    DO_MAKE_TEST(VkPhysicalDeviceFaultFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT);
#endif // if defined(VK_EXT_device_fault)

#if defined(VK_EXT_device_fault)
    DO_MAKE_TEST(VkDeviceFaultCountsEXT, VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT);
#endif // if defined(VK_EXT_device_fault)

#if defined(VK_EXT_device_fault)
    DO_MAKE_TEST(VkDeviceFaultInfoEXT, VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT);
#endif // if defined(VK_EXT_device_fault)

#if defined(VK_EXT_pipeline_library_group_handles)
    DO_MAKE_TEST(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT);
#endif // if defined(VK_EXT_pipeline_library_group_handles)

#if defined(VK_EXT_depth_bias_control)
    DO_MAKE_TEST(VkDepthBiasInfoEXT, VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT);
#endif // if defined(VK_EXT_depth_bias_control)

#if defined(VK_EXT_depth_bias_control)
    DO_MAKE_TEST(VkDepthBiasRepresentationInfoEXT, VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT);
#endif // if defined(VK_EXT_depth_bias_control)

#if defined(VK_ARM_shader_core_builtins)
    DO_MAKE_TEST(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM);
#endif // if defined(VK_ARM_shader_core_builtins)

#if defined(VK_ARM_shader_core_builtins)
    DO_MAKE_TEST(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM);
#endif // if defined(VK_ARM_shader_core_builtins)

#if defined(VK_EXT_frame_boundary)
    DO_MAKE_TEST(VkFrameBoundaryEXT, VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT);
#endif // if defined(VK_EXT_frame_boundary)

#if defined(VK_EXT_frame_boundary)
    DO_MAKE_TEST(VkPhysicalDeviceFrameBoundaryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT);
#endif // if defined(VK_EXT_frame_boundary)

#if defined(VK_EXT_dynamic_rendering_unused_attachments)
    DO_MAKE_TEST(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT);
#endif // if defined(VK_EXT_dynamic_rendering_unused_attachments)

#if defined(VK_EXT_surface_maintenance1)
    DO_MAKE_TEST(VkSurfacePresentModeEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT);
#endif // if defined(VK_EXT_surface_maintenance1)

#if defined(VK_EXT_surface_maintenance1)
    DO_MAKE_TEST(VkSurfacePresentScalingCapabilitiesEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT);
#endif // if defined(VK_EXT_surface_maintenance1)

#if defined(VK_EXT_surface_maintenance1)
    DO_MAKE_TEST(VkSurfacePresentModeCompatibilityEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT);
#endif // if defined(VK_EXT_surface_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    DO_MAKE_TEST(VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT);
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    DO_MAKE_TEST(VkSwapchainPresentFenceInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT);
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    DO_MAKE_TEST(VkSwapchainPresentModesCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    DO_MAKE_TEST(VkSwapchainPresentModeInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT);
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    DO_MAKE_TEST(VkSwapchainPresentScalingCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    DO_MAKE_TEST(VkReleaseSwapchainImagesInfoEXT, VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT);
#endif // if defined(VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_depth_bias_control)
    DO_MAKE_TEST(VkPhysicalDeviceDepthBiasControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT);
#endif // if defined(VK_EXT_depth_bias_control)

#if defined(VK_NV_ray_tracing_invocation_reorder)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV);
#endif // if defined(VK_NV_ray_tracing_invocation_reorder)

#if defined(VK_NV_ray_tracing_invocation_reorder)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV);
#endif // if defined(VK_NV_ray_tracing_invocation_reorder)

#if defined(VK_NV_extended_sparse_address_space)
    DO_MAKE_TEST(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV);
#endif // if defined(VK_NV_extended_sparse_address_space)

#if defined(VK_NV_extended_sparse_address_space)
    DO_MAKE_TEST(VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV);
#endif // if defined(VK_NV_extended_sparse_address_space)

#if defined(VK_LUNARG_direct_driver_loading)
    DO_MAKE_TEST(VkDirectDriverLoadingInfoLUNARG, VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG);
#endif // if defined(VK_LUNARG_direct_driver_loading)

#if defined(VK_LUNARG_direct_driver_loading)
    DO_MAKE_TEST(VkDirectDriverLoadingListLUNARG, VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG);
#endif // if defined(VK_LUNARG_direct_driver_loading)

#if defined(VK_QCOM_multiview_per_view_viewports)
    DO_MAKE_TEST(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM);
#endif // if defined(VK_QCOM_multiview_per_view_viewports)

#if defined(VK_KHR_ray_tracing_position_fetch)
    DO_MAKE_TEST(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR);
#endif // if defined(VK_KHR_ray_tracing_position_fetch)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkDeviceImageSubresourceInfo, VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_ARM_shader_core_properties)
    DO_MAKE_TEST(VkPhysicalDeviceShaderCorePropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM);
#endif // if defined(VK_ARM_shader_core_properties)

#if defined(VK_QCOM_multiview_per_view_render_areas)
    DO_MAKE_TEST(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM);
#endif // if defined(VK_QCOM_multiview_per_view_render_areas)

#if defined(VK_QCOM_multiview_per_view_render_areas)
    DO_MAKE_TEST(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM, VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM);
#endif // if defined(VK_QCOM_multiview_per_view_render_areas)

#if defined(VK_NV_low_latency)
    DO_MAKE_TEST(VkQueryLowLatencySupportNV, VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV);
#endif // if defined(VK_NV_low_latency)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkMemoryMapInfo, VK_STRUCTURE_TYPE_MEMORY_MAP_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkMemoryUnmapInfo, VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_EXT_shader_object)
    DO_MAKE_TEST(VkPhysicalDeviceShaderObjectFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT);
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    DO_MAKE_TEST(VkPhysicalDeviceShaderObjectPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT);
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    DO_MAKE_TEST(VkShaderCreateInfoEXT, VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT);
#endif // if defined(VK_EXT_shader_object)

#if defined(VK_EXT_shader_tile_image)
    DO_MAKE_TEST(VkPhysicalDeviceShaderTileImageFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT);
#endif // if defined(VK_EXT_shader_tile_image)

#if defined(VK_EXT_shader_tile_image)
    DO_MAKE_TEST(VkPhysicalDeviceShaderTileImagePropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT);
#endif // if defined(VK_EXT_shader_tile_image)

#if defined(VK_QNX_external_memory_screen_buffer)
    DO_MAKE_TEST(VkImportScreenBufferInfoQNX, VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX);
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    DO_MAKE_TEST(VkScreenBufferPropertiesQNX, VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX);
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    DO_MAKE_TEST(VkScreenBufferFormatPropertiesQNX, VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX);
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    DO_MAKE_TEST(VkExternalFormatQNX, VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX);
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    DO_MAKE_TEST(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX);
#endif // if defined(VK_QNX_external_memory_screen_buffer)

#if defined(VK_KHR_cooperative_matrix)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeMatrixFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR);
#endif // if defined(VK_KHR_cooperative_matrix)

#if defined(VK_KHR_cooperative_matrix)
    DO_MAKE_TEST(VkCooperativeMatrixPropertiesKHR, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR);
#endif // if defined(VK_KHR_cooperative_matrix)

#if defined(VK_KHR_cooperative_matrix)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeMatrixPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR);
#endif // if defined(VK_KHR_cooperative_matrix)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPhysicalDeviceShaderEnqueuePropertiesAMDX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX);
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPhysicalDeviceShaderEnqueueFeaturesAMDX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX);
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkExecutionGraphPipelineCreateInfoAMDX, VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX);
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPipelineShaderStageNodeCreateInfoAMDX, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX);
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkExecutionGraphPipelineScratchSizeAMDX, VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX);
#endif // if defined(VK_AMDX_shader_enqueue)

#if defined(VK_AMD_anti_lag)
    DO_MAKE_TEST(VkPhysicalDeviceAntiLagFeaturesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD);
#endif // if defined(VK_AMD_anti_lag)

#if defined(VK_AMD_anti_lag)
    DO_MAKE_TEST(VkAntiLagDataAMD, VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD);
#endif // if defined(VK_AMD_anti_lag)

#if defined(VK_AMD_anti_lag)
    DO_MAKE_TEST(VkAntiLagPresentationInfoAMD, VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD);
#endif // if defined(VK_AMD_anti_lag)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkBindMemoryStatus, VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkBindDescriptorSetsInfo, VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPushConstantsInfo, VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPushDescriptorSetInfo, VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPushDescriptorSetWithTemplateInfo, VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_maintenance6)
    DO_MAKE_TEST(VkSetDescriptorBufferOffsetsInfoEXT, VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT);
#endif // if defined(VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
    DO_MAKE_TEST(VkBindDescriptorBufferEmbeddedSamplersInfoEXT, VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT);
#endif // if defined(VK_KHR_maintenance6)

#if defined(VK_QCOM_filter_cubic_clamp)
    DO_MAKE_TEST(VkPhysicalDeviceCubicClampFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM);
#endif // if defined(VK_QCOM_filter_cubic_clamp)

#if defined(VK_QCOM_ycbcr_degamma)
    DO_MAKE_TEST(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM);
#endif // if defined(VK_QCOM_ycbcr_degamma)

#if defined(VK_QCOM_ycbcr_degamma)
    DO_MAKE_TEST(VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM);
#endif // if defined(VK_QCOM_ycbcr_degamma)

#if defined(VK_QCOM_filter_cubic_weights)
    DO_MAKE_TEST(VkPhysicalDeviceCubicWeightsFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM);
#endif // if defined(VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_filter_cubic_weights)
    DO_MAKE_TEST(VkSamplerCubicWeightsCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM);
#endif // if defined(VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_filter_cubic_weights)
    DO_MAKE_TEST(VkBlitImageCubicWeightsInfoQCOM, VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM);
#endif // if defined(VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_image_processing2)
    DO_MAKE_TEST(VkPhysicalDeviceImageProcessing2FeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM);
#endif // if defined(VK_QCOM_image_processing2)

#if defined(VK_QCOM_image_processing2)
    DO_MAKE_TEST(VkPhysicalDeviceImageProcessing2PropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM);
#endif // if defined(VK_QCOM_image_processing2)

#if defined(VK_QCOM_image_processing2)
    DO_MAKE_TEST(VkSamplerBlockMatchWindowCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM);
#endif // if defined(VK_QCOM_image_processing2)

#if defined(VK_NV_descriptor_pool_overallocation)
    DO_MAKE_TEST(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV);
#endif // if defined(VK_NV_descriptor_pool_overallocation)

#if defined(VK_MSFT_layered_driver)
    DO_MAKE_TEST(VkPhysicalDeviceLayeredDriverPropertiesMSFT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT);
#endif // if defined(VK_MSFT_layered_driver)

#if defined(VK_NV_per_stage_descriptor_set)
    DO_MAKE_TEST(VkPhysicalDevicePerStageDescriptorSetFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV);
#endif // if defined(VK_NV_per_stage_descriptor_set)

#if defined(VK_ANDROID_external_format_resolve)
    DO_MAKE_TEST(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID);
#endif // if defined(VK_ANDROID_external_format_resolve)

#if defined(VK_ANDROID_external_format_resolve)
    DO_MAKE_TEST(VkPhysicalDeviceExternalFormatResolvePropertiesANDROID,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID);
#endif // if defined(VK_ANDROID_external_format_resolve)

#if defined(VK_ANDROID_external_format_resolve)
    DO_MAKE_TEST(VkAndroidHardwareBufferFormatResolvePropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID);
#endif // if defined(VK_ANDROID_external_format_resolve)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkLatencySleepModeInfoNV, VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkLatencySleepInfoNV, VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkSetLatencyMarkerInfoNV, VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkGetLatencyMarkerInfoNV, VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkLatencyTimingsFrameReportNV, VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkOutOfBandQueueTypeInfoNV, VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkLatencySubmissionPresentIdNV, VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkSwapchainLatencyCreateInfoNV, VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    DO_MAKE_TEST(VkLatencySurfaceCapabilitiesNV, VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV);
#endif // if defined(VK_NV_low_latency2)

#if defined(VK_NV_cuda_kernel_launch)
    DO_MAKE_TEST(VkPhysicalDeviceCudaKernelLaunchFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV);
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    DO_MAKE_TEST(VkPhysicalDeviceCudaKernelLaunchPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV);
#endif // if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_ARM_scheduling_controls)
    DO_MAKE_TEST(VkDeviceQueueShaderCoreControlCreateInfoARM, VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM);
#endif // if defined(VK_ARM_scheduling_controls)

#if defined(VK_ARM_scheduling_controls)
    DO_MAKE_TEST(VkPhysicalDeviceSchedulingControlsFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM);
#endif // if defined(VK_ARM_scheduling_controls)

#if defined(VK_ARM_scheduling_controls)
    DO_MAKE_TEST(VkPhysicalDeviceSchedulingControlsPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM);
#endif // if defined(VK_ARM_scheduling_controls)

#if defined(VK_IMG_relaxed_line_rasterization)
    DO_MAKE_TEST(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG);
#endif // if defined(VK_IMG_relaxed_line_rasterization)

#if defined(VK_ARM_render_pass_striped)
    DO_MAKE_TEST(VkPhysicalDeviceRenderPassStripedFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM);
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    DO_MAKE_TEST(VkPhysicalDeviceRenderPassStripedPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM);
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    DO_MAKE_TEST(VkRenderPassStripeInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM);
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    DO_MAKE_TEST(VkRenderPassStripeBeginInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM);
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    DO_MAKE_TEST(VkRenderPassStripeSubmitInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM);
#endif // if defined(VK_ARM_render_pass_striped)

#if defined(VK_ARM_pipeline_opacity_micromap)
    DO_MAKE_TEST(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM);
#endif // if defined(VK_ARM_pipeline_opacity_micromap)

#if defined(VK_KHR_shader_maximal_reconvergence)
    DO_MAKE_TEST(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR);
#endif // if defined(VK_KHR_shader_maximal_reconvergence)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceShaderSubgroupRotateFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceShaderExpectAssumeFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceShaderFloatControls2Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkPhysicalDeviceDynamicRenderingLocalReadFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkRenderingAttachmentLocationInfo, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    DO_MAKE_TEST(VkRenderingInputAttachmentIndexInfo, VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO);
#endif // if defined(VK_VERSION_1_4)

#if defined(VK_KHR_shader_quad_control)
    DO_MAKE_TEST(VkPhysicalDeviceShaderQuadControlFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR);
#endif // if defined(VK_KHR_shader_quad_control)

#if defined(VK_NV_shader_atomic_float16_vector)
    DO_MAKE_TEST(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV);
#endif // if defined(VK_NV_shader_atomic_float16_vector)

#if defined(VK_EXT_map_memory_placed)
    DO_MAKE_TEST(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT);
#endif // if defined(VK_EXT_map_memory_placed)

#if defined(VK_EXT_map_memory_placed)
    DO_MAKE_TEST(VkPhysicalDeviceMapMemoryPlacedPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT);
#endif // if defined(VK_EXT_map_memory_placed)

#if defined(VK_EXT_map_memory_placed)
    DO_MAKE_TEST(VkMemoryMapPlacedInfoEXT, VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT);
#endif // if defined(VK_EXT_map_memory_placed)

#if defined(VK_NV_raw_access_chains)
    DO_MAKE_TEST(VkPhysicalDeviceRawAccessChainsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV);
#endif // if defined(VK_NV_raw_access_chains)

#if defined(VK_NV_command_buffer_inheritance)
    DO_MAKE_TEST(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV);
#endif // if defined(VK_NV_command_buffer_inheritance)

#if defined(VK_MESA_image_alignment_control)
    DO_MAKE_TEST(VkPhysicalDeviceImageAlignmentControlFeaturesMESA, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA);
#endif // if defined(VK_MESA_image_alignment_control)

#if defined(VK_MESA_image_alignment_control)
    DO_MAKE_TEST(VkPhysicalDeviceImageAlignmentControlPropertiesMESA, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA);
#endif // if defined(VK_MESA_image_alignment_control)

#if defined(VK_MESA_image_alignment_control)
    DO_MAKE_TEST(VkImageAlignmentControlCreateInfoMESA, VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA);
#endif // if defined(VK_MESA_image_alignment_control)

#if defined(VK_EXT_shader_replicated_composites)
    DO_MAKE_TEST(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT);
#endif // if defined(VK_EXT_shader_replicated_composites)

#if defined(VK_EXT_present_mode_fifo_latest_ready)
    DO_MAKE_TEST(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT,
                 VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_EXT);
#endif // if defined(VK_EXT_present_mode_fifo_latest_ready)

#if defined(VK_NV_cooperative_matrix2)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeMatrix2FeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV);
#endif // if defined(VK_NV_cooperative_matrix2)

#if defined(VK_NV_cooperative_matrix2)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeMatrix2PropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV);
#endif // if defined(VK_NV_cooperative_matrix2)

#if defined(VK_NV_cooperative_matrix2)
    DO_MAKE_TEST(VkCooperativeMatrixFlexibleDimensionsPropertiesNV, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV);
#endif // if defined(VK_NV_cooperative_matrix2)

#if defined(VK_HUAWEI_hdr_vivid)
    DO_MAKE_TEST(VkPhysicalDeviceHdrVividFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI);
#endif // if defined(VK_HUAWEI_hdr_vivid)

#if defined(VK_EXT_vertex_attribute_robustness)
    DO_MAKE_TEST(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT);
#endif // if defined(VK_EXT_vertex_attribute_robustness)

#if defined(VK_KHR_depth_clamp_zero_one)
    DO_MAKE_TEST(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR);
#endif // if defined(VK_KHR_depth_clamp_zero_one)

#if defined(VK_NV_cooperative_vector)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeVectorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV);
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    DO_MAKE_TEST(VkCooperativeVectorPropertiesNV, VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV);
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    DO_MAKE_TEST(VkPhysicalDeviceCooperativeVectorPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV);
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    DO_MAKE_TEST(VkConvertCooperativeVectorMatrixInfoNV, VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV);
#endif // if defined(VK_NV_cooperative_vector)

#if defined(VK_NV_present_metering) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkSetPresentConfigNV, VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV);
#endif // if defined(VK_NV_present_metering)

#if defined(VK_NV_present_metering) && defined(VK_ENABLE_BETA_EXTENSIONS)
    DO_MAKE_TEST(VkPhysicalDevicePresentMeteringFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV);
#endif // if defined(VK_NV_present_metering)

#undef DO_MAKE_TEST
}

#undef STATIC_EXPECT_TRUE
#undef STATIC_EXPECT_FALSE

} // anonymous namespace

#if defined(_MSC_VER)
    #pragma warning(pop)
#endif
