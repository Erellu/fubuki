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

#ifndef FUBUKI_CORE_STRUCTURE_TYPE_HPP
#define FUBUKI_CORE_STRUCTURE_TYPE_HPP

#include <concepts>
#include <type_traits>

#include "core/vulkan.hpp"

// clang-format off

namespace fubuki
{

/// Maps between a Vulkan structure and the matching VkStructureType.
template<typename T, typename dummy = VkStructureType>
requires(std::is_same_v<dummy, VkStructureType>)
struct structure_type
{
    static constexpr bool valid = false;
    static constexpr dummy value = dummy::VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO; // Invalid value for generic instantiation
};

/// A valid Vulkan structure.
template<typename T>
concept vk_struct = structure_type<std::decay_t<T>>::valid and structure_type<std::decay_t<T>>::value != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO;

/// Returns the VkStructureType associated to the template parameter, or fails compilation if it does not exists.
template<vk_struct T>
inline constexpr VkStructureType structure_type_v = structure_type<std::decay_t<T>>::value;

#if defined(FUBUKI_MAKE_STRUCTURE_TYPE)
#error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_STRUCTURE_TYPE(vk_struct, vk_enum)                          \
template<typename dummy>                                                        \
requires requires{{dummy::vk_enum};} and std::is_same_v<dummy, VkStructureType> \
struct structure_type<vk_struct, dummy>                                         \
{                                                                               \
    static constexpr bool valid = true;                                         \
    static constexpr dummy value = dummy::vk_enum;                              \
}

//------------------------------------------------------------------------------

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceQueueCreateInfo, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkInstanceCreateInfo, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMappedMemoryRange, VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWriteDescriptorSet, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyDescriptorSet, VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferUsageFlags2CreateInfo, VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferViewCreateInfo, VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryBarrier, VK_STRUCTURE_TYPE_MEMORY_BARRIER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferMemoryBarrier, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageMemoryBarrier, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindSparseInfo, VK_STRUCTURE_TYPE_BIND_SPARSE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkShaderModuleCreateInfo, VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetLayoutCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorPoolCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineShaderStageCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkComputePipelineCreateInfo, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_NV_device_generated_commands_compute)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkComputePipelineIndirectBufferInfoNV, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV);
#endif // #if defined (VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCreateFlags2CreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineVertexInputStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineInputAssemblyStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineTessellationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRasterizationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineMultisampleStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineColorBlendStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineDynamicStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineDepthStencilStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGraphicsPipelineCreateInfo, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCacheCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineBinaryCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineBinaryHandlesInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineBinaryKeyKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineBinaryInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkReleaseCapturedPipelineDataInfoKHR, VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineBinaryDataInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineLayoutCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandPoolCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferAllocateInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferInheritanceInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferBeginInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkEventCreateInfo, VK_STRUCTURE_TYPE_EVENT_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFenceCreateInfo, VK_STRUCTURE_TYPE_FENCE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueryPoolCreateInfo, VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFramebufferCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubmitInfo, VK_STRUCTURE_TYPE_SUBMIT_INFO);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_KHR_display)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayModeCreateInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplaySurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_display)

#if defined(VK_NV_display_stereo)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplaySurfaceStereoCreateInfoNV, VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV);
#endif // #if defined (VK_NV_display_stereo)

#if defined(VK_KHR_display_swapchain)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayPresentInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR);
#endif // #if defined (VK_KHR_display_swapchain)

#if defined(VK_KHR_android_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAndroidSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_android_surface)

#if defined(VK_NN_vi_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkViSurfaceCreateInfoNN, VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN);
#endif // #if defined (VK_NN_vi_surface)

#if defined(VK_KHR_wayland_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWaylandSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_wayland_surface)

#if defined(VK_KHR_win32_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWin32SurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_win32_surface)

#if defined(VK_KHR_xlib_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkXlibSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_xlib_surface)

#if defined(VK_KHR_xcb_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkXcbSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_xcb_surface)

#if defined(VK_EXT_directfb_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDirectFBSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_directfb_surface)

#if defined(VK_FUCHSIA_imagepipe_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImagePipeSurfaceCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_imagepipe_surface)

#if defined(VK_GGP_stream_descriptor_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkStreamDescriptorSurfaceCreateInfoGGP, VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP);
#endif // #if defined (VK_GGP_stream_descriptor_surface)

#if defined(VK_QNX_screen_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkScreenSurfaceCreateInfoQNX, VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX);
#endif // #if defined (VK_QNX_screen_surface)

#if defined(VK_KHR_swapchain)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPresentInfoKHR, VK_STRUCTURE_TYPE_PRESENT_INFO_KHR);
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_EXT_debug_report)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugReportCallbackCreateInfoEXT, VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_validation_flags)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkValidationFlagsEXT, VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT);
#endif // #if defined (VK_EXT_validation_flags)

#if defined(VK_EXT_validation_features)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkValidationFeaturesEXT, VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT);
#endif // #if defined (VK_EXT_validation_features)

#if defined(VK_EXT_layer_settings)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkLayerSettingsCreateInfoEXT, VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_layer_settings)

#if defined(VK_EXT_application_parameters)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkApplicationParametersEXT, VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT);
#endif // #if defined (VK_EXT_application_parameters)

#if defined(VK_AMD_rasterization_order)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRasterizationStateRasterizationOrderAMD, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD);
#endif // #if defined (VK_AMD_rasterization_order)

#if defined(VK_EXT_debug_marker)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugMarkerObjectNameInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT);
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugMarkerObjectTagInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT);
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugMarkerMarkerInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT);
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_NV_dedicated_allocation)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDedicatedAllocationImageCreateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_dedicated_allocation)

#if defined(VK_NV_dedicated_allocation)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDedicatedAllocationBufferCreateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV);
#endif // #if defined (VK_NV_dedicated_allocation)

#if defined(VK_NV_dedicated_allocation)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDedicatedAllocationMemoryAllocateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV);
#endif // #if defined (VK_NV_dedicated_allocation)

#if defined(VK_NV_external_memory)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalMemoryImageCreateInfoNV, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_external_memory)

#if defined(VK_NV_external_memory)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMemoryAllocateInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV);
#endif // #if defined (VK_NV_external_memory)

#if defined(VK_NV_external_memory_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemoryWin32HandleInfoNV, VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV);
#endif // #if defined (VK_NV_external_memory_win32)

#if defined(VK_NV_external_memory_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMemoryWin32HandleInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV);
#endif // #if defined (VK_NV_external_memory_win32)

#if defined(VK_NV_external_memory_sci_buf)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMemorySciBufInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_SCI_BUF_INFO_NV);
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemorySciBufInfoNV, VK_STRUCTURE_TYPE_IMPORT_MEMORY_SCI_BUF_INFO_NV);
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryGetSciBufInfoNV, VK_STRUCTURE_TYPE_MEMORY_GET_SCI_BUF_INFO_NV);
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemorySciBufPropertiesNV, VK_STRUCTURE_TYPE_MEMORY_SCI_BUF_PROPERTIES_NV);
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalMemorySciBufFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV);
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_NV_win32_keyed_mutex)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWin32KeyedMutexAcquireReleaseInfoNV, VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV);
#endif // #if defined (VK_NV_win32_keyed_mutex)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands_compute)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV);
#endif // #if defined (VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDevicePrivateDataCreateInfo, VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPrivateDataSlotCreateInfo, VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePrivateDataFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceClusterAccelerationStructureFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceClusterAccelerationStructurePropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_PROPERTIES_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CLUSTER_ACCELERATION_STRUCTURE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkClusterAccelerationStructureClustersBottomLevelInputNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_CLUSTERS_BOTTOM_LEVEL_INPUT_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkClusterAccelerationStructureTriangleClusterInputNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_TRIANGLE_CLUSTER_INPUT_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkClusterAccelerationStructureMoveObjectsInputNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_MOVE_OBJECTS_INPUT_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkClusterAccelerationStructureInputInfoNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_INPUT_INFO_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkClusterAccelerationStructureCommandsInfoNV, VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_COMMANDS_INFO_NV);
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_EXT_multi_draw)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultiDrawPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_multi_draw)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGraphicsShaderGroupCreateInfoNV, VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGraphicsPipelineShaderGroupsCreateInfoNV, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectCommandsLayoutTokenNV, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectCommandsLayoutCreateInfoNV, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeneratedCommandsInfoNV, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeneratedCommandsMemoryRequirementsInfoNV, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands_compute)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineIndirectDeviceAddressInfoNV, VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV);
#endif // #if defined (VK_NV_device_generated_commands_compute)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFeatures2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceProperties2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFormatProperties2, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageFormatProperties2, VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageFormatInfo2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueueFamilyProperties2, VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMemoryProperties2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSparseImageFormatProperties2, VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSparseImageFormatInfo2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePushDescriptorProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDriverProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_KHR_incremental_present)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPresentRegionsKHR, VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR);
#endif // #if defined (VK_KHR_incremental_present)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVariablePointersFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalImageFormatInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalImageFormatProperties, VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalBufferInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalBufferProperties, VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceIDProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalMemoryImageCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalMemoryBufferCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMemoryAllocateInfo, VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_KHR_external_memory_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemoryWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMemoryWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_memory_win32)

#if defined(VK_FUCHSIA_external_memory)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemoryZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryZirconHandlePropertiesFUCHSIA, VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryGetZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_external_memory)

#if defined(VK_KHR_external_memory_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryWin32HandlePropertiesKHR, VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemoryFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR);
#endif // #if defined (VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryFdPropertiesKHR, VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryGetFdInfoKHR, VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR);
#endif // #if defined (VK_KHR_external_memory_fd)

#if defined(VK_KHR_win32_keyed_mutex)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWin32KeyedMutexAcquireReleaseInfoKHR, VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR);
#endif // #if defined (VK_KHR_win32_keyed_mutex)

#if defined(VK_EXT_external_memory_metal)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemoryMetalHandleInfoEXT, VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT);
#endif // #if defined (VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryMetalHandlePropertiesEXT, VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryGetMetalHandleInfoEXT, VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT);
#endif // #if defined (VK_EXT_external_memory_metal)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalSemaphoreInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalSemaphoreProperties, VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportSemaphoreCreateInfo, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_KHR_external_semaphore_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportSemaphoreWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportSemaphoreWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkD3D12FenceSubmitInfoKHR, VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR);
#endif // #if defined (VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportSemaphoreFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR);
#endif // #if defined (VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_external_semaphore_fd)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreGetFdInfoKHR, VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR);
#endif // #if defined (VK_KHR_external_semaphore_fd)

#if defined(VK_FUCHSIA_external_semaphore)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportSemaphoreZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_external_semaphore)

#if defined(VK_FUCHSIA_external_semaphore)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreGetZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_external_semaphore)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalFenceInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalFenceProperties, VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportFenceCreateInfo, VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_KHR_external_fence_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportFenceWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportFenceWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFenceGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR);
#endif // #if defined (VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportFenceFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR);
#endif // #if defined (VK_KHR_external_fence_fd)

#if defined(VK_KHR_external_fence_fd)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFenceGetFdInfoKHR, VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR);
#endif // #if defined (VK_KHR_external_fence_fd)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportFenceSciSyncInfoNV, VK_STRUCTURE_TYPE_EXPORT_FENCE_SCI_SYNC_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportFenceSciSyncInfoNV, VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFenceGetSciSyncInfoNV, VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportSemaphoreSciSyncInfoNV, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_SCI_SYNC_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportSemaphoreSciSyncInfoNV, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_SCI_SYNC_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreGetSciSyncInfoNV, VK_STRUCTURE_TYPE_SEMAPHORE_GET_SCI_SYNC_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSciSyncAttributesInfoNV, VK_STRUCTURE_TYPE_SCI_SYNC_ATTRIBUTES_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalSciSyncFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV);
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalSciSync2FeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreSciSyncPoolCreateInfoNV, VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_POOL_CREATE_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreSciSyncCreateInfoNV, VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_CREATE_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV, VK_STRUCTURE_TYPE_DEVICE_SEMAPHORE_SCI_SYNC_POOL_RESERVATION_CREATE_INFO_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultiviewFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultiviewProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassMultiviewCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_EXT_display_surface_counter)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceCapabilities2EXT, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT);
#endif // #if defined (VK_EXT_display_surface_counter)

#if defined(VK_EXT_display_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayPowerInfoEXT, VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT);
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceEventInfoEXT, VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT);
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayEventInfoEXT, VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT);
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_EXT_display_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainCounterCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceGroupProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryAllocateFlagsInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindBufferMemoryInfo, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindBufferMemoryDeviceGroupInfo, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindImageMemoryInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindImageMemoryDeviceGroupInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupRenderPassBeginInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupCommandBufferBeginInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupSubmitInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupBindSparseInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_KHR_device_group)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupPresentCapabilitiesKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindImageMemorySwapchainInfoKHR, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR);
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAcquireNextImageInfoKHR, VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR);
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_KHR_device_group)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupPresentInfoKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR);
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupDeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_KHR_device_group)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceGroupSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorUpdateTemplateCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_KHR_present_id)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePresentIdFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR);
#endif // #if defined (VK_KHR_present_id)

#if defined(VK_KHR_present_id)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPresentIdKHR, VK_STRUCTURE_TYPE_PRESENT_ID_KHR);
#endif // #if defined (VK_KHR_present_id)

#if defined(VK_KHR_present_wait)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePresentWaitFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR);
#endif // #if defined (VK_KHR_present_wait)

#if defined(VK_EXT_hdr_metadata)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkHdrMetadataEXT, VK_STRUCTURE_TYPE_HDR_METADATA_EXT);
#endif // #if defined (VK_EXT_hdr_metadata)

#if defined(VK_HUAWEI_hdr_vivid)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkHdrVividDynamicMetadataHUAWEI, VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI);
#endif // #if defined (VK_HUAWEI_hdr_vivid)

#if defined(VK_AMD_display_native_hdr)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayNativeHdrSurfaceCapabilitiesAMD, VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD);
#endif // #if defined (VK_AMD_display_native_hdr)

#if defined(VK_AMD_display_native_hdr)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainDisplayNativeHdrCreateInfoAMD, VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD);
#endif // #if defined (VK_AMD_display_native_hdr)

#if defined(VK_GOOGLE_display_timing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPresentTimesInfoGOOGLE, VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE);
#endif // #if defined (VK_GOOGLE_display_timing)

#if defined(VK_MVK_ios_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIOSSurfaceCreateInfoMVK, VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK);
#endif // #if defined (VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMacOSSurfaceCreateInfoMVK, VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK);
#endif // #if defined (VK_MVK_macos_surface)

#if defined(VK_EXT_metal_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMetalSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_surface)

#if defined(VK_NV_clip_space_w_scaling)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportWScalingStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_clip_space_w_scaling)

#if defined(VK_NV_viewport_swizzle)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportSwizzleStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_viewport_swizzle)

#if defined(VK_EXT_discard_rectangles)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDiscardRectanglePropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineDiscardRectangleStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_NVX_multiview_per_view_attributes)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX);
#endif // #if defined (VK_NVX_multiview_per_view_attributes)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassInputAttachmentAspectCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_KHR_get_surface_capabilities2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSurfaceInfo2KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR);
#endif // #if defined (VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceCapabilities2KHR, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR);
#endif // #if defined (VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceFormat2KHR, VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR);
#endif // #if defined (VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_display_properties2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR);
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayPlaneProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR);
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayModeProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR);
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_NV_display_stereo)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayModeStereoPropertiesNV, VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV);
#endif // #if defined (VK_NV_display_stereo)

#if defined(VK_KHR_get_display_properties2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayPlaneInfo2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR);
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDisplayPlaneCapabilities2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR);
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_KHR_shared_presentable_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSharedPresentSurfaceCapabilitiesKHR, VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_shared_presentable_image)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevice16BitStorageFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSubgroupProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceBufferMemoryRequirements, VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageSparseMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceImageMemoryRequirements, VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryRequirements2, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSparseImageMemoryRequirements2, VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePointClippingProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryDedicatedRequirements, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryDedicatedAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewUsageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_EXT_image_sliced_view_of_3d)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewSlicedCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_image_sliced_view_of_3d)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineTessellationDomainOriginStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerYcbcrConversionInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerYcbcrConversionCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindImagePlaneMemoryInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImagePlaneMemoryRequirementsInfo, VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSamplerYcbcrConversionFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerYcbcrConversionImageFormatProperties, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_AMD_texture_gather_bias_lod)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkTextureLODGatherFormatPropertiesAMD, VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD);
#endif // #if defined (VK_AMD_texture_gather_bias_lod)

#if defined(VK_EXT_conditional_rendering)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkConditionalRenderingBeginInfoEXT, VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT);
#endif // #if defined (VK_EXT_conditional_rendering)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkProtectedSubmitInfo, VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceProtectedMemoryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceProtectedMemoryProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceQueueInfo2, VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_NV_fragment_coverage_to_color)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCoverageToColorStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_fragment_coverage_to_color)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSamplerFilterMinmaxProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_sample_locations)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSampleLocationsInfoEXT, VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT);
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassSampleLocationsBeginInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT);
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineSampleLocationsStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSampleLocationsPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMultisamplePropertiesEXT, VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerReductionModeCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_blend_operation_advanced)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_multi_draw)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultiDrawFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT);
#endif // #if defined (VK_EXT_multi_draw)

#if defined(VK_EXT_blend_operation_advanced)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_EXT_blend_operation_advanced)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineColorBlendAdvancedStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_blend_operation_advanced)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceInlineUniformBlockFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceInlineUniformBlockProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWriteDescriptorSetInlineUniformBlock, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorPoolInlineUniformBlockCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_NV_framebuffer_mixed_samples)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCoverageModulationStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_framebuffer_mixed_samples)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageFormatListCreateInfo, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_validation_cache)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkValidationCacheCreateInfoEXT, VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkShaderModuleValidationCacheCreateInfoEXT, VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance3Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance4Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance4Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance5Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance5Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance6Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance6Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_KHR_maintenance7)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance7FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR);
#endif // #if defined (VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance7PropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLayeredApiPropertiesListKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR);
#endif // #if defined (VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLayeredApiPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance7)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_maintenance7)

#if defined(VK_KHR_maintenance8)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMaintenance8FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR);
#endif // #if defined (VK_KHR_maintenance8)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderingAreaInfo, VK_STRUCTURE_TYPE_RENDERING_AREA_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetLayoutSupport, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderDrawParametersFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderFloat16Int8Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFloatControlsProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceHostQueryResetFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_ANDROID_native_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkNativeBufferANDROID, VK_STRUCTURE_TYPE_NATIVE_BUFFER_ANDROID);
#endif // #if defined (VK_ANDROID_native_buffer)

#if defined(VK_ANDROID_native_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainImageCreateInfoANDROID, VK_STRUCTURE_TYPE_SWAPCHAIN_IMAGE_CREATE_INFO_ANDROID);
#endif // #if defined (VK_ANDROID_native_buffer)

#if defined(VK_ANDROID_native_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePresentationPropertiesANDROID, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_ANDROID);
#endif // #if defined (VK_ANDROID_native_buffer)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceQueueGlobalPriorityCreateInfo, VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceGlobalPriorityQueryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueueFamilyGlobalPriorityProperties, VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_EXT_debug_utils)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugUtilsObjectNameInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT);
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugUtilsObjectTagInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT);
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugUtilsLabelEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT);
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugUtilsMessengerCreateInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDebugUtilsMessengerCallbackDataEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT);
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_device_memory_report)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT);
#endif // #if defined (VK_EXT_device_memory_report)

#if defined(VK_EXT_device_memory_report)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceDeviceMemoryReportCreateInfoEXT, VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_device_memory_report)

#if defined(VK_EXT_device_memory_report)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceMemoryReportCallbackDataEXT, VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT);
#endif // #if defined (VK_EXT_device_memory_report)

#if defined(VK_EXT_external_memory_host)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemoryHostPointerInfoEXT, VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT);
#endif // #if defined (VK_EXT_external_memory_host)

#if defined(VK_EXT_external_memory_host)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryHostPointerPropertiesEXT, VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_external_memory_host)

#if defined(VK_EXT_external_memory_host)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalMemoryHostPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_external_memory_host)

#if defined(VK_EXT_conservative_rasterization)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceConservativeRasterizationPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_conservative_rasterization)

#if defined(VK_KHR_calibrated_timestamps)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCalibratedTimestampInfoKHR, VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR);
#endif // #if defined (VK_KHR_calibrated_timestamps)

#if defined(VK_AMD_shader_core_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderCorePropertiesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD);
#endif // #if defined (VK_AMD_shader_core_properties)

#if defined(VK_AMD_shader_core_properties2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderCoreProperties2AMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD);
#endif // #if defined (VK_AMD_shader_core_properties2)

#if defined(VK_EXT_conservative_rasterization)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRasterizationConservativeStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_conservative_rasterization)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDescriptorIndexingFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDescriptorIndexingProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetLayoutBindingFlagsCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetVariableDescriptorCountAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetVariableDescriptorCountLayoutSupport, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAttachmentDescription2, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAttachmentReference2, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassDescription2, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassDependency2, VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassCreateInfo2, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassBeginInfo, VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassEndInfo, VK_STRUCTURE_TYPE_SUBPASS_END_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTimelineSemaphoreFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTimelineSemaphoreProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreTypeCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkTimelineSemaphoreSubmitInfo, VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreWaitInfo, VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreSignalInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineVertexInputDivisorStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_EXT_vertex_attribute_divisor)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_vertex_attribute_divisor)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVertexAttributeDivisorProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_EXT_pci_bus_info)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePCIBusInfoPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_pci_bus_info)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportAndroidHardwareBufferInfoANDROID, VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID);
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAndroidHardwareBufferUsageANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID);
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAndroidHardwareBufferPropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID);
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryGetAndroidHardwareBufferInfoANDROID, VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID);
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAndroidHardwareBufferFormatPropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID);
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_EXT_conditional_rendering)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferInheritanceConditionalRenderingInfoEXT, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT);
#endif // #if defined (VK_EXT_conditional_rendering)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalFormatANDROID, VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID);
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevice8BitStorageFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_conditional_rendering)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceConditionalRenderingFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT);
#endif // #if defined (VK_EXT_conditional_rendering)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkanMemoryModelFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderAtomicInt64Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_shader_atomic_float)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT);
#endif // #if defined (VK_EXT_shader_atomic_float)

#if defined(VK_EXT_shader_atomic_float2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT);
#endif // #if defined (VK_EXT_shader_atomic_float2)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVertexAttributeDivisorFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_NV_device_diagnostic_checkpoints)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueueFamilyCheckpointPropertiesNV, VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV);
#endif // #if defined (VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCheckpointDataNV, VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV);
#endif // #if defined (VK_NV_device_diagnostic_checkpoints)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDepthStencilResolveProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassDescriptionDepthStencilResolve, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_astc_decode_mode)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewASTCDecodeModeEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT);
#endif // #if defined (VK_EXT_astc_decode_mode)

#if defined(VK_EXT_astc_decode_mode)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceASTCDecodeFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT);
#endif // #if defined (VK_EXT_astc_decode_mode)

#if defined(VK_EXT_transform_feedback)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTransformFeedbackFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTransformFeedbackPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRasterizationStateStreamCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_NV_representative_fragment_test)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV);
#endif // #if defined (VK_NV_representative_fragment_test)

#if defined(VK_NV_representative_fragment_test)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRepresentativeFragmentTestStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_representative_fragment_test)

#if defined(VK_NV_scissor_exclusive)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExclusiveScissorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV);
#endif // #if defined (VK_NV_scissor_exclusive)

#if defined(VK_NV_scissor_exclusive)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportExclusiveScissorStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_scissor_exclusive)

#if defined(VK_NV_corner_sampled_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCornerSampledImageFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV);
#endif // #if defined (VK_NV_corner_sampled_image)

#if defined(VK_KHR_compute_shader_derivatives)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR);
#endif // #if defined (VK_KHR_compute_shader_derivatives)

#if defined(VK_KHR_compute_shader_derivatives)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_compute_shader_derivatives)

#if defined(VK_NV_shader_image_footprint)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderImageFootprintFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV);
#endif // #if defined (VK_NV_shader_image_footprint)

#if defined(VK_NV_dedicated_allocation_image_aliasing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV);
#endif // #if defined (VK_NV_dedicated_allocation_image_aliasing)

#if defined(VK_NV_copy_memory_indirect)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCopyMemoryIndirectFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV);
#endif // #if defined (VK_NV_copy_memory_indirect)

#if defined(VK_NV_copy_memory_indirect)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCopyMemoryIndirectPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV);
#endif // #if defined (VK_NV_copy_memory_indirect)

#if defined(VK_NV_memory_decompression)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMemoryDecompressionFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV);
#endif // #if defined (VK_NV_memory_decompression)

#if defined(VK_NV_memory_decompression)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMemoryDecompressionPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV);
#endif // #if defined (VK_NV_memory_decompression)

#if defined(VK_NV_shading_rate_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportShadingRateImageStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShadingRateImageFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV);
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShadingRateImagePropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV);
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_HUAWEI_invocation_mask)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI);
#endif // #if defined (VK_HUAWEI_invocation_mask)

#if defined(VK_NV_shading_rate_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_mesh_shader)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMeshShaderFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV);
#endif // #if defined (VK_NV_mesh_shader)

#if defined(VK_NV_mesh_shader)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMeshShaderPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV);
#endif // #if defined (VK_NV_mesh_shader)

#if defined(VK_EXT_mesh_shader)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMeshShaderFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT);
#endif // #if defined (VK_EXT_mesh_shader)

#if defined(VK_EXT_mesh_shader)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMeshShaderPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_mesh_shader)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRayTracingShaderGroupCreateInfoNV, VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_pipeline)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRayTracingShaderGroupCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRayTracingPipelineCreateInfoNV, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_pipeline)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRayTracingPipelineCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeometryTrianglesNV, VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeometryAABBNV, VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeometryNV, VK_STRUCTURE_TYPE_GEOMETRY_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureCreateInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindAccelerationStructureMemoryInfoNV, VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWriteDescriptorSetAccelerationStructureKHR, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWriteDescriptorSetAccelerationStructureNV, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureMemoryRequirementsInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceAccelerationStructureFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingPipelineFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR);
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayQueryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR);
#endif // #if defined (VK_KHR_ray_query)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceAccelerationStructurePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingPipelinePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_KHR_ray_tracing_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR);
#endif // #if defined (VK_KHR_ray_tracing_maintenance1)

#if defined(VK_EXT_image_drm_format_modifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDrmFormatModifierPropertiesListEXT, VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT);
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageDrmFormatModifierInfoEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT);
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageDrmFormatModifierListCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageDrmFormatModifierExplicitCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_image_drm_format_modifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageDrmFormatModifierPropertiesEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageStencilUsageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_AMD_memory_overallocation_behavior)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceMemoryOverallocationCreateInfoAMD, VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD);
#endif // #if defined (VK_AMD_memory_overallocation_behavior)

#if defined(VK_EXT_fragment_density_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentDensityMapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT);
#endif // #if defined (VK_EXT_fragment_density_map)

#if defined(VK_EXT_fragment_density_map2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT);
#endif // #if defined (VK_EXT_fragment_density_map2)

#if defined(VK_QCOM_fragment_density_map_offset)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_fragment_density_map_offset)

#if defined(VK_EXT_fragment_density_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentDensityMapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_fragment_density_map)

#if defined(VK_EXT_fragment_density_map2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_fragment_density_map2)

#if defined(VK_QCOM_fragment_density_map_offset)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM);
#endif // #if defined (VK_QCOM_fragment_density_map_offset)

#if defined(VK_EXT_fragment_density_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassFragmentDensityMapCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_fragment_density_map)

#if defined(VK_QCOM_fragment_density_map_offset)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassFragmentDensityMapOffsetEndInfoQCOM, VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM);
#endif // #if defined (VK_QCOM_fragment_density_map_offset)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceScalarBlockLayoutFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_KHR_surface_protected_capabilities)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceProtectedCapabilitiesKHR, VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_surface_protected_capabilities)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceUniformBufferStandardLayoutFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_depth_clip_enable)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDepthClipEnableFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT);
#endif // #if defined (VK_EXT_depth_clip_enable)

#if defined(VK_EXT_depth_clip_enable)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRasterizationDepthClipStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_depth_clip_enable)

#if defined(VK_EXT_memory_budget)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMemoryBudgetPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_memory_budget)

#if defined(VK_EXT_memory_priority)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMemoryPriorityFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT);
#endif // #if defined (VK_EXT_memory_priority)

#if defined(VK_EXT_memory_priority)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryPriorityAllocateInfoEXT, VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT);
#endif // #if defined (VK_EXT_memory_priority)

#if defined(VK_EXT_pageable_device_local_memory)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT);
#endif // #if defined (VK_EXT_pageable_device_local_memory)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceBufferDeviceAddressFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_buffer_device_address)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT);
#endif // #if defined (VK_EXT_buffer_device_address)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferDeviceAddressInfo, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferOpaqueCaptureAddressCreateInfo, VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_buffer_device_address)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferDeviceAddressCreateInfoEXT, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_buffer_device_address)

#if defined(VK_EXT_filter_cubic)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageViewImageFormatInfoEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT);
#endif // #if defined (VK_EXT_filter_cubic)

#if defined(VK_EXT_filter_cubic)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFilterCubicImageViewImageFormatPropertiesEXT, VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_filter_cubic)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImagelessFramebufferFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFramebufferAttachmentsCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFramebufferAttachmentImageInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassAttachmentBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTextureCompressionASTCHDRFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_NV_cooperative_matrix)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeMatrixFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV);
#endif // #if defined (VK_NV_cooperative_matrix)

#if defined(VK_NV_cooperative_matrix)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeMatrixPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV);
#endif // #if defined (VK_NV_cooperative_matrix)

#if defined(VK_NV_cooperative_matrix)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCooperativeMatrixPropertiesNV, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV);
#endif // #if defined (VK_NV_cooperative_matrix)

#if defined(VK_EXT_ycbcr_image_arrays)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT);
#endif // #if defined (VK_EXT_ycbcr_image_arrays)

#if defined(VK_NVX_image_view_handle)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewHandleInfoNVX, VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX);
#endif // #if defined (VK_NVX_image_view_handle)

#if defined(VK_NVX_image_view_handle)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewAddressPropertiesNVX, VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX);
#endif // #if defined (VK_NVX_image_view_handle)

#if defined(VK_GGP_frame_token)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPresentFrameTokenGGP, VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP);
#endif // #if defined (VK_GGP_frame_token)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCreationFeedbackCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_EXT_full_screen_exclusive)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceFullScreenExclusiveInfoEXT, VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT);
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceFullScreenExclusiveWin32InfoEXT, VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT);
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceCapabilitiesFullScreenExclusiveEXT, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT);
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_NV_present_barrier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePresentBarrierFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV);
#endif // #if defined (VK_NV_present_barrier)

#if defined(VK_NV_present_barrier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfaceCapabilitiesPresentBarrierNV, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV);
#endif // #if defined (VK_NV_present_barrier)

#if defined(VK_NV_present_barrier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainPresentBarrierCreateInfoNV, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV);
#endif // #if defined (VK_NV_present_barrier)

#if defined(VK_KHR_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePerformanceQueryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePerformanceQueryPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceCounterKHR, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceCounterDescriptionKHR, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueryPoolPerformanceCreateInfoKHR, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAcquireProfilingLockInfoKHR, VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceQuerySubmitInfoKHR, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
    //FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceQueryReservationInfoKHR, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR);
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_EXT_headless_surface)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkHeadlessSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_headless_surface)

#if defined(VK_NV_coverage_reduction_mode)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCoverageReductionModeFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV);
#endif // #if defined (VK_NV_coverage_reduction_mode)

#if defined(VK_NV_coverage_reduction_mode)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCoverageReductionStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_coverage_reduction_mode)

#if defined(VK_NV_coverage_reduction_mode)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFramebufferMixedSamplesCombinationNV, VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV);
#endif // #if defined (VK_NV_coverage_reduction_mode)

#if defined(VK_INTEL_shader_integer_functions2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL);
#endif // #if defined (VK_INTEL_shader_integer_functions2)

#if defined(VK_INTEL_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkInitializePerformanceApiInfoINTEL, VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL);
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueryPoolPerformanceQueryCreateInfoINTEL, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL);
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceMarkerInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL);
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceStreamMarkerInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL);
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceOverrideInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL);
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPerformanceConfigurationAcquireInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL);
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_KHR_shader_clock)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderClockFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR);
#endif // #if defined (VK_KHR_shader_clock)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceIndexTypeUint8Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_NV_shader_sm_builtins)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV);
#endif // #if defined (VK_NV_shader_sm_builtins)

#if defined(VK_NV_shader_sm_builtins)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV);
#endif // #if defined (VK_NV_shader_sm_builtins)

#if defined(VK_EXT_fragment_shader_interlock)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT);
#endif // #if defined (VK_EXT_fragment_shader_interlock)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAttachmentReferenceStencilLayout, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_EXT_primitive_topology_list_restart)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT);
#endif // #if defined (VK_EXT_primitive_topology_list_restart)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAttachmentDescriptionStencilLayout, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_KHR_pipeline_executable_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR);
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineExecutablePropertiesKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineExecutableInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineExecutableStatisticKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR);
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineExecutableInternalRepresentationKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR);
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_EXT_texel_buffer_alignment)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT);
#endif // #if defined (VK_EXT_texel_buffer_alignment)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTexelBufferAlignmentProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSubgroupSizeControlFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSubgroupSizeControlProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineShaderStageRequiredSubgroupSizeCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_HUAWEI_subpass_shading)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassShadingPipelineCreateInfoHUAWEI, VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI);
#endif // #if defined (VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_subpass_shading)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSubpassShadingPropertiesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI);
#endif // #if defined (VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_cluster_culling_shader)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI);
#endif // #if defined (VK_HUAWEI_cluster_culling_shader)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryOpaqueCaptureAddressAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceMemoryOpaqueCaptureAddressInfo, VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLineRasterizationFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLineRasterizationProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRasterizationLineStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineCreationCacheControlFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan11Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan11Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan12Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan12Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan13Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan13Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan14Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkan14Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_AMD_pipeline_compiler_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineCompilerControlCreateInfoAMD, VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD);
#endif // #if defined (VK_AMD_pipeline_compiler_control)

#if defined(VK_AMD_device_coherent_memory)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCoherentMemoryFeaturesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD);
#endif // #if defined (VK_AMD_device_coherent_memory)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFaultData, VK_STRUCTURE_TYPE_FAULT_DATA);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFaultCallbackInfo, VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceToolProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_EXT_custom_border_color)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerCustomBorderColorCreateInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_custom_border_color)

#if defined(VK_EXT_custom_border_color)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCustomBorderColorPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_custom_border_color)

#if defined(VK_EXT_custom_border_color)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCustomBorderColorFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT);
#endif // #if defined (VK_EXT_custom_border_color)

#if defined(VK_EXT_border_color_swizzle)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerBorderColorComponentMappingCreateInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_border_color_swizzle)

#if defined(VK_EXT_border_color_swizzle)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT);
#endif // #if defined (VK_EXT_border_color_swizzle)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureGeometryTrianglesDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureGeometryAabbsDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureGeometryInstancesDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureGeometryLinearSweptSpheresDataNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV);
#endif // #if defined (VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureGeometrySpheresDataNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV);
#endif // #if defined (VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureGeometryKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureBuildGeometryInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureCreateInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureDeviceAddressInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureVersionInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyAccelerationStructureInfoKHR, VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyAccelerationStructureToMemoryInfoKHR, VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyMemoryToAccelerationStructureInfoKHR, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRayTracingPipelineInterfaceCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_pipeline_library)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineLibraryCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_pipeline_library)

#if defined(VK_KHR_object_refresh)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRefreshObjectListKHR, VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR);
#endif // #if defined (VK_KHR_object_refresh)

#if defined(VK_EXT_extended_dynamic_state)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_QCOM_render_pass_transform)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassTransformBeginInfoQCOM, VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM);
#endif // #if defined (VK_QCOM_render_pass_transform)

#if defined(VK_QCOM_rotated_copy_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyCommandTransformInfoQCOM, VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM);
#endif // #if defined (VK_QCOM_rotated_copy_commands)

#if defined(VK_QCOM_render_pass_transform)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferInheritanceRenderPassTransformInfoQCOM, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM);
#endif // #if defined (VK_QCOM_render_pass_transform)

#if defined(VK_NV_partitioned_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV);
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV);
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPartitionedAccelerationStructureFlagsNV, VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV);
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWriteDescriptorSetPartitionedAccelerationStructureNV, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV);
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPartitionedAccelerationStructureInstancesInputNV, VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV);
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBuildPartitionedAccelerationStructureInfoNV, VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV);
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_device_diagnostics_config)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDiagnosticsConfigFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV);
#endif // #if defined (VK_NV_device_diagnostics_config)

#if defined(VK_NV_device_diagnostics_config)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceDiagnosticsConfigCreateInfoNV, VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV);
#endif // #if defined (VK_NV_device_diagnostics_config)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineOfflineCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_KHR_shader_subgroup_uniform_control_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR);
#endif // #if defined (VK_KHR_shader_subgroup_uniform_control_flow)

#if defined(VK_EXT_robustness2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRobustness2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT);
#endif // #if defined (VK_EXT_robustness2)

#if defined(VK_EXT_robustness2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRobustness2PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_robustness2)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageRobustnessFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_KHR_workgroup_memory_explicit_layout)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR);
#endif // #if defined (VK_KHR_workgroup_memory_explicit_layout)

#if defined(VK_KHR_portability_subset)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePortabilitySubsetFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR);
#endif // #if defined (VK_KHR_portability_subset)

#if defined(VK_KHR_portability_subset)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePortabilitySubsetPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_portability_subset)

#if defined(VK_EXT_4444_formats)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevice4444FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT);
#endif // #if defined (VK_EXT_4444_formats)

#if defined(VK_HUAWEI_subpass_shading)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSubpassShadingFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI);
#endif // #if defined (VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_cluster_culling_shader)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI);
#endif // #if defined (VK_HUAWEI_cluster_culling_shader)

#if defined(VK_HUAWEI_cluster_culling_shader)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI);
#endif // #if defined (VK_HUAWEI_cluster_culling_shader)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCopy2, VK_STRUCTURE_TYPE_BUFFER_COPY_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageCopy2, VK_STRUCTURE_TYPE_IMAGE_COPY_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageBlit2, VK_STRUCTURE_TYPE_IMAGE_BLIT_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferImageCopy2, VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageResolve2, VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyBufferInfo2, VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyImageInfo2, VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBlitImageInfo2, VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyBufferToImageInfo2, VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyImageToBufferInfo2, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkResolveImageInfo2, VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_EXT_shader_image_atomic_int64)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT);
#endif // #if defined (VK_EXT_shader_image_atomic_int64)

#if defined(VK_KHR_fragment_shading_rate)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFragmentShadingRateAttachmentInfoKHR, VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineFragmentShadingRateStateCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShadingRateFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShadingRatePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShadingRateKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderTerminateInvocationFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_NV_fragment_shading_rate_enums)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_NV_fragment_shading_rate_enums)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineFragmentShadingRateEnumStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureBuildSizesInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_EXT_image_2d_view_of_3d)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT);
#endif // #if defined (VK_EXT_image_2d_view_of_3d)

#if defined(VK_EXT_image_sliced_view_of_3d)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT);
#endif // #if defined (VK_EXT_image_sliced_view_of_3d)

#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT);
#endif // #if defined (VK_EXT_attachment_feedback_loop_dynamic_state)

#if defined(VK_EXT_legacy_vertex_attributes)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT);
#endif // #if defined (VK_EXT_legacy_vertex_attributes)

#if defined(VK_EXT_legacy_vertex_attributes)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_legacy_vertex_attributes)

#if defined(VK_EXT_mutable_descriptor_type)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT);
#endif // #if defined (VK_EXT_mutable_descriptor_type)

#if defined(VK_EXT_mutable_descriptor_type)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMutableDescriptorTypeCreateInfoEXT, VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_mutable_descriptor_type)

#if defined(VK_EXT_depth_clip_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDepthClipControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT);
#endif // #if defined (VK_EXT_depth_clip_control)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeneratedCommandsPipelineInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeneratedCommandsShaderInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeneratedCommandsMemoryRequirementsInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectExecutionSetPipelineInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectExecutionSetShaderLayoutInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectExecutionSetShaderInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectExecutionSetCreateInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGeneratedCommandsInfoEXT, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWriteIndirectExecutionSetPipelineEXT, VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkWriteIndirectExecutionSetShaderEXT, VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectCommandsLayoutCreateInfoEXT, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkIndirectCommandsLayoutTokenEXT, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_depth_clip_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportDepthClipControlCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_depth_clip_control)

#if defined(VK_EXT_depth_clamp_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDepthClampControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT);
#endif // #if defined (VK_EXT_depth_clamp_control)

#if defined(VK_EXT_depth_clamp_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineViewportDepthClampControlCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_depth_clamp_control)

#if defined(VK_EXT_vertex_input_dynamic_state)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT);
#endif // #if defined (VK_EXT_vertex_input_dynamic_state)

#if defined(VK_NV_external_memory_rdma)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV);
#endif // #if defined (VK_NV_external_memory_rdma)

#if defined(VK_KHR_shader_relaxed_extended_instruction)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR);
#endif // #if defined (VK_KHR_shader_relaxed_extended_instruction)

#if defined(VK_EXT_shader_object)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVertexInputBindingDescription2EXT, VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVertexInputAttributeDescription2EXT, VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_color_write_enable)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceColorWriteEnableFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT);
#endif // #if defined (VK_EXT_color_write_enable)

#if defined(VK_EXT_color_write_enable)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineColorWriteCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_color_write_enable)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryBarrier2, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageMemoryBarrier2, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferMemoryBarrier2, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_KHR_maintenance8)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryBarrierAccessFlags3KHR, VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR);
#endif // #if defined (VK_KHR_maintenance8)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDependencyInfo, VK_STRUCTURE_TYPE_DEPENDENCY_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSemaphoreSubmitInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferSubmitInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubmitInfo2, VK_STRUCTURE_TYPE_SUBMIT_INFO_2);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_NV_device_diagnostic_checkpoints)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueueFamilyCheckpointProperties2NV, VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV);
#endif // #if defined (VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCheckpointData2NV, VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV);
#endif // #if defined (VK_NV_device_diagnostic_checkpoints)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSynchronization2Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceHostImageCopyFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceHostImageCopyProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryToImageCopy, VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageToMemoryCopy, VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyMemoryToImageInfo, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyImageToMemoryInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyImageToImageInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkHostImageLayoutTransitionInfo, VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubresourceHostMemcpySize, VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkHostImageCopyDevicePerformanceQuery, VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkanSC10Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelinePoolSize, VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceObjectReservationCreateInfo, VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandPoolMemoryReservationCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandPoolMemoryConsumption, VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_CONSUMPTION);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVulkanSC10Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VK_EXT_primitives_generated_query)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT);
#endif // #if defined (VK_EXT_primitives_generated_query)

#if defined(VK_EXT_legacy_dithering)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLegacyDitheringFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT);
#endif // #if defined (VK_EXT_legacy_dithering)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT);
#endif // #if defined (VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubpassResolvePerformanceQueryEXT, VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT);
#endif // #if defined (VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_EXT_multisampled_render_to_single_sampled)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMultisampledRenderToSingleSampledInfoEXT, VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT);
#endif // #if defined (VK_EXT_multisampled_render_to_single_sampled)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineProtectedAccessFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueueFamilyVideoPropertiesKHR, VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueueFamilyQueryResultStatusPropertiesKHR, VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoProfileListInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVideoFormatInfoKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoFormatPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeQuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264QuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265QuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1QuantizationMapCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoFormatQuantizationMapPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoFormatH265QuantizationMapPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoFormatAV1QuantizationMapPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoSessionMemoryRequirementsKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindVideoSessionMemoryInfoKHR, VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoPictureResourceInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoReferenceSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_decode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeUsageInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVideoMaintenance1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR);
#endif // #if defined (VK_KHR_video_maintenance1)

#if defined(VK_KHR_video_maintenance2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVideoMaintenance2FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR);
#endif // #if defined (VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoInlineQueryInfoKHR, VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR);
#endif // #if defined (VK_KHR_video_maintenance1)

#if defined(VK_KHR_video_decode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH264ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH264CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH264SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH264SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_maintenance2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH264InlineSessionParametersInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR);
#endif // #if defined (VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH264PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH264DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h264)

#if defined(VK_KHR_video_decode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH265ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH265CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH265SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH265SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_maintenance2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH265InlineSessionParametersInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR);
#endif // #if defined (VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH265PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeH265DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_h265)

#if defined(VK_KHR_video_decode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeAV1ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeAV1CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeAV1SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_maintenance2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeAV1InlineSessionParametersInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR);
#endif // #if defined (VK_KHR_video_maintenance2)

#if defined(VK_KHR_video_decode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeAV1PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_decode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoDecodeAV1DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR);
#endif // #if defined (VK_KHR_video_decode_av1)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoSessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoSessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoSessionParametersUpdateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeSessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeSessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoBeginCodingInfoKHR, VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEndCodingInfoKHR, VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoCodingControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeUsageInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeQuantizationMapInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_quantization_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueryPoolVideoEncodeFeedbackCreateInfoKHR, VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeQualityLevelInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeQualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeRateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeRateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264SessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264SessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264NaluSliceInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h264)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH264RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h264)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265SessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265SessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265NaluSliceSegmentInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_h265)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeH265DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_h265)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_KHR_video_encode_av1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkVideoEncodeAV1RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR);
#endif // #if defined (VK_KHR_video_encode_av1)

#if defined(VK_NV_inherited_viewport_scissor)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceInheritedViewportScissorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV);
#endif // #if defined (VK_NV_inherited_viewport_scissor)

#if defined(VK_NV_inherited_viewport_scissor)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferInheritanceViewportScissorInfoNV, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV);
#endif // #if defined (VK_NV_inherited_viewport_scissor)

#if defined(VK_EXT_ycbcr_2plane_444_formats)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT);
#endif // #if defined (VK_EXT_ycbcr_2plane_444_formats)

#if defined(VK_EXT_provoking_vertex)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceProvokingVertexFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT);
#endif // #if defined (VK_EXT_provoking_vertex)

#if defined(VK_EXT_provoking_vertex)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceProvokingVertexPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_provoking_vertex)

#if defined(VK_EXT_provoking_vertex)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_provoking_vertex)

#if defined(VK_NVX_binary_import)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCuModuleCreateInfoNVX, VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCuModuleTexturingModeCreateInfoNVX, VK_STRUCTURE_TYPE_CU_MODULE_TEXTURING_MODE_CREATE_INFO_NVX);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCuFunctionCreateInfoNVX, VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCuLaunchInfoNVX, VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDescriptorBufferFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDescriptorBufferPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorAddressInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorBufferBindingInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorBufferBindingPushDescriptorBufferHandleEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorGetInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkOpaqueCaptureDescriptorDataCreateInfoEXT, VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderIntegerDotProductFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderIntegerDotProductProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_EXT_physical_device_drm)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDrmPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_physical_device_drm)

#if defined(VK_KHR_fragment_shader_barycentric)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR);
#endif // #if defined (VK_KHR_fragment_shader_barycentric)

#if defined(VK_KHR_fragment_shader_barycentric)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_fragment_shader_barycentric)

#if defined(VK_NV_ray_tracing_motion_blur)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV);
#endif // #if defined (VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_ray_tracing_validation)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingValidationFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV);
#endif // #if defined (VK_NV_ray_tracing_validation)

#if defined(VK_NV_ray_tracing_linear_swept_spheres)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV);
#endif // #if defined (VK_NV_ray_tracing_linear_swept_spheres)

#if defined(VK_NV_ray_tracing_motion_blur)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureGeometryMotionTrianglesDataNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV);
#endif // #if defined (VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_ray_tracing_motion_blur)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureMotionInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV);
#endif // #if defined (VK_NV_ray_tracing_motion_blur)

#if defined(VK_NV_external_memory_rdma)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryGetRemoteAddressInfoNV, VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV);
#endif // #if defined (VK_NV_external_memory_rdma)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMemoryBufferCollectionFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCollectionImageCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCollectionBufferCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCollectionCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCollectionPropertiesFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSysmemColorSpaceFUCHSIA, VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageFormatConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBufferCollectionConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_NV_cuda_kernel_launch)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCudaModuleCreateInfoNV, VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCudaFunctionCreateInfoNV, VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCudaLaunchInfoNV, VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_EXT_rgba10x6_formats)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT);
#endif // #if defined (VK_EXT_rgba10x6_formats)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFormatProperties3, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_EXT_image_drm_format_modifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDrmFormatModifierPropertiesList2EXT, VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT);
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAndroidHardwareBufferFormatProperties2ANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID);
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRenderingCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderingInfo, VK_STRUCTURE_TYPE_RENDERING_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderingAttachmentInfo, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_KHR_fragment_shading_rate)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderingFragmentShadingRateAttachmentInfoKHR, VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_EXT_fragment_density_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderingFragmentDensityMapAttachmentInfoEXT, VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT);
#endif // #if defined (VK_EXT_fragment_density_map)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDynamicRenderingFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCommandBufferInheritanceRenderingInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_AMD_mixed_attachment_samples)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAttachmentSampleCountInfoAMD, VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD);
#endif // #if defined (VK_AMD_mixed_attachment_samples)

#if defined(VK_NVX_multiview_per_view_attributes)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMultiviewPerViewAttributesInfoNVX, VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX);
#endif // #if defined (VK_NVX_multiview_per_view_attributes)

#if defined(VK_EXT_image_view_min_lod)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageViewMinLodFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT);
#endif // #if defined (VK_EXT_image_view_min_lod)

#if defined(VK_EXT_image_view_min_lod)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewMinLodCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_image_view_min_lod)

#if defined(VK_EXT_rasterization_order_attachment_access)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT);
#endif // #if defined (VK_EXT_rasterization_order_attachment_access)

#if defined(VK_NV_linear_color_attachment)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLinearColorAttachmentFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV);
#endif // #if defined (VK_NV_linear_color_attachment)

#if defined(VK_EXT_graphics_pipeline_library)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT);
#endif // #if defined (VK_EXT_graphics_pipeline_library)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineBinaryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDevicePipelineBinaryInternalCacheControlKHR, VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineBinaryPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_EXT_graphics_pipeline_library)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_graphics_pipeline_library)

#if defined(VK_EXT_graphics_pipeline_library)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGraphicsPipelineLibraryCreateInfoEXT, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_graphics_pipeline_library)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE);
#endif // #if defined (VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetBindingReferenceVALVE, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE);
#endif // #if defined (VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDescriptorSetLayoutHostMappingInfoVALVE, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE);
#endif // #if defined (VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_EXT_nested_command_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceNestedCommandBufferFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT);
#endif // #if defined (VK_EXT_nested_command_buffer)

#if defined(VK_EXT_nested_command_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceNestedCommandBufferPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_nested_command_buffer)

#if defined(VK_EXT_shader_module_identifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT);
#endif // #if defined (VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineShaderStageModuleIdentifierCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkShaderModuleIdentifierEXT, VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT);
#endif // #if defined (VK_EXT_shader_module_identifier)

#if defined(VK_EXT_image_compression_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageCompressionControlEXT, VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT);
#endif // #if defined (VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageCompressionControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT);
#endif // #if defined (VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageCompressionPropertiesEXT, VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_image_compression_control)

#if defined(VK_EXT_image_compression_control_swapchain)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT);
#endif // #if defined (VK_EXT_image_compression_control_swapchain)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageSubresource2, VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSubresourceLayout2, VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_EXT_subpass_merge_feedback)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassCreationControlEXT, VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT);
#endif // #if defined (VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassCreationFeedbackCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassSubpassFeedbackCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_subpass_merge_feedback)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT);
#endif // #if defined (VK_EXT_subpass_merge_feedback)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMicromapBuildInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMicromapCreateInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMicromapVersionInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyMicromapInfoEXT, VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyMicromapToMemoryInfoEXT, VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCopyMemoryToMicromapInfoEXT, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMicromapBuildSizesInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceOpacityMicromapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceOpacityMicromapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureTrianglesOpacityMicromapEXT, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_NV_displacement_micromap)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDisplacementMicromapFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV);
#endif // #if defined (VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDisplacementMicromapPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV);
#endif // #if defined (VK_NV_displacement_micromap)

#if defined(VK_NV_displacement_micromap)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAccelerationStructureTrianglesDisplacementMicromapNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV);
#endif // #if defined (VK_NV_displacement_micromap)

#if defined(VK_EXT_pipeline_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelinePropertiesIdentifierEXT, VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT);
#endif // #if defined (VK_EXT_pipeline_properties)

#if defined(VK_EXT_pipeline_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelinePropertiesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT);
#endif // #if defined (VK_EXT_pipeline_properties)

#if defined(VK_AMD_shader_early_and_late_fragment_tests)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD);
#endif // #if defined (VK_AMD_shader_early_and_late_fragment_tests)

#if defined(VK_EXT_external_memory_acquire_unmodified)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalMemoryAcquireUnmodifiedEXT, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT);
#endif // #if defined (VK_EXT_external_memory_acquire_unmodified)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalObjectCreateInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalObjectsInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalDeviceInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalCommandQueueInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalBufferInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMetalBufferInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalTextureInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMetalTextureInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalIOSurfaceInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMetalIOSurfaceInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExportMetalSharedEventInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_metal_objects)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportMetalSharedEventInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT);
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_EXT_non_seamless_cube_map)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT);
#endif // #if defined (VK_EXT_non_seamless_cube_map)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineRobustnessFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineRobustnessCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineRobustnessProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_QCOM_image_processing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageViewSampleWeightCreateInfoQCOM, VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM);
#endif // #if defined (VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageProcessingFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageProcessingPropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM);
#endif // #if defined (VK_QCOM_image_processing)

#if defined(VK_QCOM_tile_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceTilePropertiesFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_tile_properties)

#if defined(VK_QCOM_tile_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkTilePropertiesQCOM, VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM);
#endif // #if defined (VK_QCOM_tile_properties)

#if defined(VK_SEC_amigo_profiling)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceAmigoProfilingFeaturesSEC, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC);
#endif // #if defined (VK_SEC_amigo_profiling)

#if defined(VK_SEC_amigo_profiling)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAmigoProfilingSubmitInfoSEC, VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC);
#endif // #if defined (VK_SEC_amigo_profiling)

#if defined(VK_EXT_attachment_feedback_loop_layout)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT);
#endif // #if defined (VK_EXT_attachment_feedback_loop_layout)

#if defined(VK_EXT_device_address_binding_report)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceAddressBindingReportFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT);
#endif // #if defined (VK_EXT_device_address_binding_report)

#if defined(VK_EXT_device_address_binding_report)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceAddressBindingCallbackDataEXT, VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT);
#endif // #if defined (VK_EXT_device_address_binding_report)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceOpticalFlowFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceOpticalFlowPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkOpticalFlowImageFormatInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkOpticalFlowImageFormatPropertiesNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkOpticalFlowSessionCreateInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkOpticalFlowSessionCreatePrivateDataInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkOpticalFlowExecuteInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_EXT_device_fault)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFaultFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT);
#endif // #if defined (VK_EXT_device_fault)

#if defined(VK_EXT_device_fault)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceFaultCountsEXT, VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT);
#endif // #if defined (VK_EXT_device_fault)

#if defined(VK_EXT_device_fault)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceFaultInfoEXT, VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT);
#endif // #if defined (VK_EXT_device_fault)

#if defined(VK_EXT_pipeline_library_group_handles)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT);
#endif // #if defined (VK_EXT_pipeline_library_group_handles)

#if defined(VK_EXT_depth_bias_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDepthBiasInfoEXT, VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT);
#endif // #if defined (VK_EXT_depth_bias_control)

#if defined(VK_EXT_depth_bias_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDepthBiasRepresentationInfoEXT, VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT);
#endif // #if defined (VK_EXT_depth_bias_control)

#if defined(VK_ARM_shader_core_builtins)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM);
#endif // #if defined (VK_ARM_shader_core_builtins)

#if defined(VK_ARM_shader_core_builtins)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM);
#endif // #if defined (VK_ARM_shader_core_builtins)

#if defined(VK_EXT_frame_boundary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkFrameBoundaryEXT, VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT);
#endif // #if defined (VK_EXT_frame_boundary)

#if defined(VK_EXT_frame_boundary)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceFrameBoundaryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT);
#endif // #if defined (VK_EXT_frame_boundary)

#if defined(VK_EXT_dynamic_rendering_unused_attachments)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT);
#endif // #if defined (VK_EXT_dynamic_rendering_unused_attachments)

#if defined(VK_EXT_surface_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfacePresentModeEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT);
#endif // #if defined (VK_EXT_surface_maintenance1)

#if defined(VK_EXT_surface_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfacePresentScalingCapabilitiesEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT);
#endif // #if defined (VK_EXT_surface_maintenance1)

#if defined(VK_EXT_surface_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSurfacePresentModeCompatibilityEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT);
#endif // #if defined (VK_EXT_surface_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT);
#endif // #if defined (VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainPresentFenceInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT);
#endif // #if defined (VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainPresentModesCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainPresentModeInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT);
#endif // #if defined (VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainPresentScalingCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_swapchain_maintenance1)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkReleaseSwapchainImagesInfoEXT, VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT);
#endif // #if defined (VK_EXT_swapchain_maintenance1)

#if defined(VK_EXT_depth_bias_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDepthBiasControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT);
#endif // #if defined (VK_EXT_depth_bias_control)

#if defined(VK_NV_ray_tracing_invocation_reorder)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV);
#endif // #if defined (VK_NV_ray_tracing_invocation_reorder)

#if defined(VK_NV_ray_tracing_invocation_reorder)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV);
#endif // #if defined (VK_NV_ray_tracing_invocation_reorder)

#if defined(VK_NV_extended_sparse_address_space)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV);
#endif // #if defined (VK_NV_extended_sparse_address_space)

#if defined(VK_NV_extended_sparse_address_space)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV);
#endif // #if defined (VK_NV_extended_sparse_address_space)

#if defined(VK_LUNARG_direct_driver_loading)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDirectDriverLoadingInfoLUNARG, VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG);
#endif // #if defined (VK_LUNARG_direct_driver_loading)

#if defined(VK_LUNARG_direct_driver_loading)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDirectDriverLoadingListLUNARG, VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG);
#endif // #if defined (VK_LUNARG_direct_driver_loading)

#if defined(VK_QCOM_multiview_per_view_viewports)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_multiview_per_view_viewports)

#if defined(VK_KHR_ray_tracing_position_fetch)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR);
#endif // #if defined (VK_KHR_ray_tracing_position_fetch)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceImageSubresourceInfo, VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_ARM_shader_core_properties)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderCorePropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM);
#endif // #if defined (VK_ARM_shader_core_properties)

#if defined(VK_QCOM_multiview_per_view_render_areas)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_multiview_per_view_render_areas)

#if defined(VK_QCOM_multiview_per_view_render_areas)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM, VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM);
#endif // #if defined (VK_QCOM_multiview_per_view_render_areas)

#if defined(VK_NV_low_latency)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkQueryLowLatencySupportNV, VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV);
#endif // #if defined (VK_NV_low_latency)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryMapInfo, VK_STRUCTURE_TYPE_MEMORY_MAP_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryUnmapInfo, VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_EXT_shader_object)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderObjectFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderObjectPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkShaderCreateInfoEXT, VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_tile_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderTileImageFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT);
#endif // #if defined (VK_EXT_shader_tile_image)

#if defined(VK_EXT_shader_tile_image)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderTileImagePropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_shader_tile_image)

#if defined(VK_QNX_external_memory_screen_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImportScreenBufferInfoQNX, VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX);
#endif // #if defined (VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkScreenBufferPropertiesQNX, VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX);
#endif // #if defined (VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkScreenBufferFormatPropertiesQNX, VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX);
#endif // #if defined (VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExternalFormatQNX, VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX);
#endif // #if defined (VK_QNX_external_memory_screen_buffer)

#if defined(VK_QNX_external_memory_screen_buffer)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX);
#endif // #if defined (VK_QNX_external_memory_screen_buffer)

#if defined(VK_KHR_cooperative_matrix)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeMatrixFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR);
#endif // #if defined (VK_KHR_cooperative_matrix)

#if defined(VK_KHR_cooperative_matrix)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCooperativeMatrixPropertiesKHR, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_cooperative_matrix)

#if defined(VK_KHR_cooperative_matrix)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeMatrixPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR);
#endif // #if defined (VK_KHR_cooperative_matrix)

#if defined(VK_AMDX_shader_enqueue)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderEnqueuePropertiesAMDX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX);
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderEnqueueFeaturesAMDX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX);
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExecutionGraphPipelineCreateInfoAMDX, VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX);
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPipelineShaderStageNodeCreateInfoAMDX, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX);
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkExecutionGraphPipelineScratchSizeAMDX, VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX);
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMD_anti_lag)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceAntiLagFeaturesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD);
#endif // #if defined (VK_AMD_anti_lag)

#if defined(VK_AMD_anti_lag)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAntiLagDataAMD, VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD);
#endif // #if defined (VK_AMD_anti_lag)

#if defined(VK_AMD_anti_lag)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAntiLagPresentationInfoAMD, VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD);
#endif // #if defined (VK_AMD_anti_lag)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindMemoryStatus, VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindDescriptorSetsInfo, VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPushConstantsInfo, VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPushDescriptorSetInfo, VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPushDescriptorSetWithTemplateInfo, VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_KHR_maintenance6)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSetDescriptorBufferOffsetsInfoEXT, VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT);
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBindDescriptorBufferEmbeddedSamplersInfoEXT, VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT);
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_QCOM_filter_cubic_clamp)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCubicClampFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_filter_cubic_clamp)

#if defined(VK_QCOM_ycbcr_degamma)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_ycbcr_degamma)

#if defined(VK_QCOM_ycbcr_degamma)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM);
#endif // #if defined (VK_QCOM_ycbcr_degamma)

#if defined(VK_QCOM_filter_cubic_weights)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCubicWeightsFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_filter_cubic_weights)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerCubicWeightsCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM);
#endif // #if defined (VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_filter_cubic_weights)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkBlitImageCubicWeightsInfoQCOM, VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM);
#endif // #if defined (VK_QCOM_filter_cubic_weights)

#if defined(VK_QCOM_image_processing2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageProcessing2FeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM);
#endif // #if defined (VK_QCOM_image_processing2)

#if defined(VK_QCOM_image_processing2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageProcessing2PropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM);
#endif // #if defined (VK_QCOM_image_processing2)

#if defined(VK_QCOM_image_processing2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSamplerBlockMatchWindowCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM);
#endif // #if defined (VK_QCOM_image_processing2)

#if defined(VK_NV_descriptor_pool_overallocation)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV);
#endif // #if defined (VK_NV_descriptor_pool_overallocation)

#if defined(VK_MSFT_layered_driver)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceLayeredDriverPropertiesMSFT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT);
#endif // #if defined (VK_MSFT_layered_driver)

#if defined(VK_NV_per_stage_descriptor_set)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePerStageDescriptorSetFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV);
#endif // #if defined (VK_NV_per_stage_descriptor_set)

#if defined(VK_ANDROID_external_format_resolve)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID);
#endif // #if defined (VK_ANDROID_external_format_resolve)

#if defined(VK_ANDROID_external_format_resolve)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceExternalFormatResolvePropertiesANDROID, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID);
#endif // #if defined (VK_ANDROID_external_format_resolve)

#if defined(VK_ANDROID_external_format_resolve)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkAndroidHardwareBufferFormatResolvePropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID);
#endif // #if defined (VK_ANDROID_external_format_resolve)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkLatencySleepModeInfoNV, VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkLatencySleepInfoNV, VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSetLatencyMarkerInfoNV, VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkGetLatencyMarkerInfoNV, VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkLatencyTimingsFrameReportNV, VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkOutOfBandQueueTypeInfoNV, VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkLatencySubmissionPresentIdNV, VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSwapchainLatencyCreateInfoNV, VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkLatencySurfaceCapabilitiesNV, VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV);
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_cuda_kernel_launch)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCudaKernelLaunchFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCudaKernelLaunchPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_ARM_scheduling_controls)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkDeviceQueueShaderCoreControlCreateInfoARM, VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM);
#endif // #if defined (VK_ARM_scheduling_controls)

#if defined(VK_ARM_scheduling_controls)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSchedulingControlsFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM);
#endif // #if defined (VK_ARM_scheduling_controls)

#if defined(VK_ARM_scheduling_controls)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceSchedulingControlsPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM);
#endif // #if defined (VK_ARM_scheduling_controls)

#if defined(VK_IMG_relaxed_line_rasterization)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG);
#endif // #if defined (VK_IMG_relaxed_line_rasterization)

#if defined(VK_ARM_render_pass_striped)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRenderPassStripedFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM);
#endif // #if defined (VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRenderPassStripedPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM);
#endif // #if defined (VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassStripeInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM);
#endif // #if defined (VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassStripeBeginInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM);
#endif // #if defined (VK_ARM_render_pass_striped)

#if defined(VK_ARM_render_pass_striped)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderPassStripeSubmitInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM);
#endif // #if defined (VK_ARM_render_pass_striped)

#if defined(VK_ARM_pipeline_opacity_micromap)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM);
#endif // #if defined (VK_ARM_pipeline_opacity_micromap)

#if defined(VK_KHR_shader_maximal_reconvergence)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR);
#endif // #if defined (VK_KHR_shader_maximal_reconvergence)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderSubgroupRotateFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderExpectAssumeFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderFloatControls2Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDynamicRenderingLocalReadFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderingAttachmentLocationInfo, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkRenderingInputAttachmentIndexInfo, VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_KHR_shader_quad_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderQuadControlFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR);
#endif // #if defined (VK_KHR_shader_quad_control)

#if defined(VK_NV_shader_atomic_float16_vector)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV);
#endif // #if defined (VK_NV_shader_atomic_float16_vector)

#if defined(VK_EXT_map_memory_placed)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT);
#endif // #if defined (VK_EXT_map_memory_placed)

#if defined(VK_EXT_map_memory_placed)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceMapMemoryPlacedPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT);
#endif // #if defined (VK_EXT_map_memory_placed)

#if defined(VK_EXT_map_memory_placed)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkMemoryMapPlacedInfoEXT, VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT);
#endif // #if defined (VK_EXT_map_memory_placed)

#if defined(VK_NV_raw_access_chains)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceRawAccessChainsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV);
#endif // #if defined (VK_NV_raw_access_chains)

#if defined(VK_NV_command_buffer_inheritance)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV);
#endif // #if defined (VK_NV_command_buffer_inheritance)

#if defined(VK_MESA_image_alignment_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageAlignmentControlFeaturesMESA, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA);
#endif // #if defined (VK_MESA_image_alignment_control)

#if defined(VK_MESA_image_alignment_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceImageAlignmentControlPropertiesMESA, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA);
#endif // #if defined (VK_MESA_image_alignment_control)

#if defined(VK_MESA_image_alignment_control)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkImageAlignmentControlCreateInfoMESA, VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA);
#endif // #if defined (VK_MESA_image_alignment_control)

#if defined(VK_EXT_shader_replicated_composites)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT);
#endif // #if defined (VK_EXT_shader_replicated_composites)

#if defined(VK_EXT_present_mode_fifo_latest_ready)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_EXT);
#endif // #if defined (VK_EXT_present_mode_fifo_latest_ready)

#if defined(VK_NV_cooperative_matrix2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeMatrix2FeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV);
#endif // #if defined (VK_NV_cooperative_matrix2)

#if defined(VK_NV_cooperative_matrix2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeMatrix2PropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV);
#endif // #if defined (VK_NV_cooperative_matrix2)

#if defined(VK_NV_cooperative_matrix2)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCooperativeMatrixFlexibleDimensionsPropertiesNV, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV);
#endif // #if defined (VK_NV_cooperative_matrix2)

#if defined(VK_HUAWEI_hdr_vivid)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceHdrVividFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI);
#endif // #if defined (VK_HUAWEI_hdr_vivid)

#if defined(VK_EXT_vertex_attribute_robustness)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT);
#endif // #if defined (VK_EXT_vertex_attribute_robustness)

#if defined(VK_KHR_depth_clamp_zero_one)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR);
#endif // #if defined (VK_KHR_depth_clamp_zero_one)

#if defined(VK_NV_cooperative_vector)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeVectorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV);
#endif // #if defined (VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkCooperativeVectorPropertiesNV, VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV);
#endif // #if defined (VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDeviceCooperativeVectorPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV);
#endif // #if defined (VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkConvertCooperativeVectorMatrixInfoNV, VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV);
#endif // #if defined (VK_NV_cooperative_vector)

#if defined(VK_NV_present_metering)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkSetPresentConfigNV, VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV);
#endif // #if defined (VK_NV_present_metering)

#if defined(VK_NV_present_metering)&& defined(VK_ENABLE_BETA_EXTENSIONS)
    FUBUKI_MAKE_STRUCTURE_TYPE(VkPhysicalDevicePresentMeteringFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV);
#endif // #if defined (VK_NV_present_metering)

//------------------------------------------------------------------------------

#undef FUBUKI_MAKE_STRUCTURE_TYPE

/// Creates a Vulkan structure and sets its sType and pNext members to the correct values.
template<vk_struct T>
[[nodiscard]]
inline constexpr auto make() noexcept
{
    T result = {};

    if constexpr(requires{{result.sType} -> std::same_as<VkStructureType&>;})
    {
        result.sType = structure_type_v<T>;
    }

    if constexpr(requires{{result.pNext};})
    {
        result.pNext = nullptr;
    }

    return result;
}

} // namespace fubuki

// clang-format on

#endif // FUBUKI_CORE_STRUCTURE_TYPE_HPP
