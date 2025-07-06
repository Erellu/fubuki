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

#include "core/functions/device_core.hpp"

#include "core/assertion.hpp"
#include "core/pfn.hpp"
#include "core/vulkan.hpp"

// Extracted from vulkan_core.h (Apache 2.0)
// Allows to compile with VK_NO_PROTOTYPES
extern "C"
{

// NOLINTBEGIN(readability-identifier-naming)
extern VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkInstance*                  pInstance);

extern VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);

extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                             ::uint32_t*            pPropertyCount,
                                                                             VkExtensionProperties* pProperties);

extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(::uint32_t* pPropertyCount, VkLayerProperties* pProperties);

extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceVersion(::uint32_t* pApiVersion);

} // extern "C"
// NOLINTEND(readability-identifier-naming)

namespace fubuki
{

[[nodiscard]] device_core_functions load(instance_handle instance, version_number version, device_handle device) noexcept
{
    fubuki_assert(instance != null_handle, "Instance must not be a null handle.");
    fubuki_assert(version >= version_number(1, 0, 0), "Invalid version.");
    fubuki_assert(device != null_handle, "Device must not be a null handle.");

    auto* const getter = pfn<"vkGetDeviceProcAddr">(instance);

#if defined(VK_VERSION_1_0)
    device_core_functions::vk10_core_functions vk10 = {};

    if(version >= version_number{1, 0, 0})
    {
        // clang-format off
        vk10 =
        {
            .get_device_queue = pfn<"vkGetDeviceQueue">(instance, device, getter),
            .queue_submit = pfn<"vkQueueSubmit">(instance, device, getter),
            .queue_wait_idle = pfn<"vkQueueWaitIdle">(instance, device, getter),
            .device_wait_idle = pfn<"vkDeviceWaitIdle">(instance, device, getter),
            .allocate_memory = pfn<"vkAllocateMemory">(instance, device, getter),
            .free_memory = pfn<"vkFreeMemory">(instance, device, getter),
            .map_memory = pfn<"vkMapMemory">(instance, device, getter),
            .unmap_memory = pfn<"vkUnmapMemory">(instance, device, getter),
            .flush_mapped_memory_ranges = pfn<"vkFlushMappedMemoryRanges">(instance, device, getter),
            .invalidate_mapped_memory_ranges = pfn<"vkInvalidateMappedMemoryRanges">(instance, device, getter),
            .get_device_memory_commitment = pfn<"vkGetDeviceMemoryCommitment">(instance, device, getter),
            .bind_buffer_memory = pfn<"vkBindBufferMemory">(instance, device, getter),
            .bind_image_memory = pfn<"vkBindImageMemory">(instance, device, getter),
            .get_buffer_memory_requirements = pfn<"vkGetBufferMemoryRequirements">(instance, device, getter),
            .get_image_memory_requirements = pfn<"vkGetImageMemoryRequirements">(instance, device, getter),
            .get_image_sparse_memory_requirements = pfn<"vkGetImageSparseMemoryRequirements">(instance, device, getter),
            .queue_bind_sparse = pfn<"vkQueueBindSparse">(instance, device, getter),
            .create_fence = pfn<"vkCreateFence">(instance, device, getter),
            .destroy_fence = pfn<"vkDestroyFence">(instance, device, getter),
            .reset_fences = pfn<"vkResetFences">(instance, device, getter),
            .get_fence_status = pfn<"vkGetFenceStatus">(instance, device, getter),
            .wait_for_fences = pfn<"vkWaitForFences">(instance, device, getter),
            .create_semaphore = pfn<"vkCreateSemaphore">(instance, device, getter),
            .destroy_semaphore = pfn<"vkDestroySemaphore">(instance, device, getter),
            .create_event = pfn<"vkCreateEvent">(instance, device, getter),
            .destroy_event = pfn<"vkDestroyEvent">(instance, device, getter),
            .get_event_status = pfn<"vkGetEventStatus">(instance, device, getter),
            .set_event = pfn<"vkSetEvent">(instance, device, getter),
            .reset_event = pfn<"vkResetEvent">(instance, device, getter),
            .create_query_pool = pfn<"vkCreateQueryPool">(instance, device, getter),
            .destroy_query_pool = pfn<"vkDestroyQueryPool">(instance, device, getter),
            .get_query_pool_results = pfn<"vkGetQueryPoolResults">(instance, device, getter),
            .create_buffer = pfn<"vkCreateBuffer">(instance, device, getter),
            .destroy_buffer = pfn<"vkDestroyBuffer">(instance, device, getter),
            .create_buffer_view = pfn<"vkCreateBufferView">(instance, device, getter),
            .destroy_buffer_view = pfn<"vkDestroyBufferView">(instance, device, getter),
            .create_image = pfn<"vkCreateImage">(instance, device, getter),
            .destroy_image = pfn<"vkDestroyImage">(instance, device, getter),
            .get_image_subresource_layout = pfn<"vkGetImageSubresourceLayout">(instance, device, getter),
            .create_image_view = pfn<"vkCreateImageView">(instance, device, getter),
            .destroy_image_view = pfn<"vkDestroyImageView">(instance, device, getter),
            .create_shader_module = pfn<"vkCreateShaderModule">(instance, device, getter),
            .destroy_shader_module = pfn<"vkDestroyShaderModule">(instance, device, getter),
            .create_pipeline_cache = pfn<"vkCreatePipelineCache">(instance, device, getter),
            .destroy_pipeline_cache = pfn<"vkDestroyPipelineCache">(instance, device, getter),
            .get_pipeline_cache_data = pfn<"vkGetPipelineCacheData">(instance, device, getter),
            .merge_pipeline_caches = pfn<"vkMergePipelineCaches">(instance, device, getter),
            .create_graphics_pipelines = pfn<"vkCreateGraphicsPipelines">(instance, device, getter),
            .create_compute_pipelines = pfn<"vkCreateComputePipelines">(instance, device, getter),
            .destroy_pipeline = pfn<"vkDestroyPipeline">(instance, device, getter),
            .create_pipeline_layout = pfn<"vkCreatePipelineLayout">(instance, device, getter),
            .destroy_pipeline_layout = pfn<"vkDestroyPipelineLayout">(instance, device, getter),
            .create_sampler = pfn<"vkCreateSampler">(instance, device, getter),
            .destroy_sampler = pfn<"vkDestroySampler">(instance, device, getter),
            .create_descriptor_set_layout = pfn<"vkCreateDescriptorSetLayout">(instance, device, getter),
            .destroy_descriptor_set_layout = pfn<"vkDestroyDescriptorSetLayout">(instance, device, getter),
            .create_descriptor_pool = pfn<"vkCreateDescriptorPool">(instance, device, getter),
            .destroy_descriptor_pool = pfn<"vkDestroyDescriptorPool">(instance, device, getter),
            .reset_descriptor_pool = pfn<"vkResetDescriptorPool">(instance, device, getter),
            .allocate_descriptor_sets = pfn<"vkAllocateDescriptorSets">(instance, device, getter),
            .free_descriptor_sets = pfn<"vkFreeDescriptorSets">(instance, device, getter),
            .update_descriptor_sets = pfn<"vkUpdateDescriptorSets">(instance, device, getter),
            .create_framebuffer = pfn<"vkCreateFramebuffer">(instance, device, getter),
            .destroy_framebuffer = pfn<"vkDestroyFramebuffer">(instance, device, getter),
            .create_render_pass = pfn<"vkCreateRenderPass">(instance, device, getter),
            .destroy_render_pass = pfn<"vkDestroyRenderPass">(instance, device, getter),
            .get_render_area_granularity = pfn<"vkGetRenderAreaGranularity">(instance, device, getter),
            .create_command_pool = pfn<"vkCreateCommandPool">(instance, device, getter),
            .destroy_command_pool = pfn<"vkDestroyCommandPool">(instance, device, getter),
            .reset_command_pool = pfn<"vkResetCommandPool">(instance, device, getter),
            .allocate_command_buffers = pfn<"vkAllocateCommandBuffers">(instance, device, getter),
            .free_command_buffers = pfn<"vkFreeCommandBuffers">(instance, device, getter),
            .begin_command_buffer = pfn<"vkBeginCommandBuffer">(instance, device, getter),
            .end_command_buffer = pfn<"vkEndCommandBuffer">(instance, device, getter),
            .reset_command_buffer = pfn<"vkResetCommandBuffer">(instance, device, getter),

            .cmd =
            {
                .bind_pipeline = pfn<"vkCmdBindPipeline">(instance, device, getter),
                .set_viewport = pfn<"vkCmdSetViewport">(instance, device, getter),
                .set_scissor = pfn<"vkCmdSetScissor">(instance, device, getter),
                .set_line_width = pfn<"vkCmdSetLineWidth">(instance, device, getter),
                .set_depth_bias = pfn<"vkCmdSetDepthBias">(instance, device, getter),
                .set_blend_constants = pfn<"vkCmdSetBlendConstants">(instance, device, getter),
                .set_depth_bounds = pfn<"vkCmdSetDepthBounds">(instance, device, getter),
                .set_stencil_compare_mask = pfn<"vkCmdSetStencilCompareMask">(instance, device, getter),
                .set_stencil_write_mask = pfn<"vkCmdSetStencilWriteMask">(instance, device, getter),
                .set_stencil_reference = pfn<"vkCmdSetStencilReference">(instance, device, getter),
                .bind_descriptor_sets = pfn<"vkCmdBindDescriptorSets">(instance, device, getter),
                .bind_index_buffer = pfn<"vkCmdBindIndexBuffer">(instance, device, getter),
                .bind_vertex_buffers = pfn<"vkCmdBindVertexBuffers">(instance, device, getter),
                .draw = pfn<"vkCmdDraw">(instance, device, getter),
                .draw_indexed = pfn<"vkCmdDrawIndexed">(instance, device, getter),
                .draw_indirect = pfn<"vkCmdDrawIndirect">(instance, device, getter),
                .draw_indexed_indirect = pfn<"vkCmdDrawIndexedIndirect">(instance, device, getter),
                .dispatch = pfn<"vkCmdDispatch">(instance, device, getter),
                .dispatch_indirect = pfn<"vkCmdDispatchIndirect">(instance, device, getter),
                .copy_buffer = pfn<"vkCmdCopyBuffer">(instance, device, getter),
                .copy_image = pfn<"vkCmdCopyImage">(instance, device, getter),
                .blit_image = pfn<"vkCmdBlitImage">(instance, device, getter),
                .copy_buffer_to_image = pfn<"vkCmdCopyBufferToImage">(instance, device, getter),
                .copy_image_to_buffer = pfn<"vkCmdCopyImageToBuffer">(instance, device, getter),
                .update_buffer = pfn<"vkCmdUpdateBuffer">(instance, device, getter),
                .fill_buffer = pfn<"vkCmdFillBuffer">(instance, device, getter),
                .clear_color_image = pfn<"vkCmdClearColorImage">(instance, device, getter),
                .clear_depth_stencil_image = pfn<"vkCmdClearDepthStencilImage">(instance, device, getter),
                .clear_attachments = pfn<"vkCmdClearAttachments">(instance, device, getter),
                .resolve_image = pfn<"vkCmdResolveImage">(instance, device, getter),
                .set_event = pfn<"vkCmdSetEvent">(instance, device, getter),
                .reset_event = pfn<"vkCmdResetEvent">(instance, device, getter),
                .wait_events = pfn<"vkCmdWaitEvents">(instance, device, getter),
                .pipeline_barrier = pfn<"vkCmdPipelineBarrier">(instance, device, getter),
                .begin_query = pfn<"vkCmdBeginQuery">(instance, device, getter),
                .end_query = pfn<"vkCmdEndQuery">(instance, device, getter),
                .reset_query_pool = pfn<"vkCmdResetQueryPool">(instance, device, getter),
                .write_timestamp = pfn<"vkCmdWriteTimestamp">(instance, device, getter),
                .copy_query_pool_results = pfn<"vkCmdCopyQueryPoolResults">(instance, device, getter),
                .push_constants = pfn<"vkCmdPushConstants">(instance, device, getter),
                .begin_render_pass = pfn<"vkCmdBeginRenderPass">(instance, device, getter),
                .next_subpass = pfn<"vkCmdNextSubpass">(instance, device, getter),
                .end_render_pass = pfn<"vkCmdEndRenderPass">(instance, device, getter),
                .execute_commands = pfn<"vkCmdExecuteCommands">(instance, device, getter),

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
    device_core_functions::vk11_core_functions vk11 = {};

    if(version >= version_number{1, 1, 0})
    {
        // clang-format off
        vk11 =
        {
            .bind_buffer_memory2 = pfn<"vkBindBufferMemory2">(instance, device, getter),
            .bind_image_memory2 = pfn<"vkBindImageMemory2">(instance, device, getter),
            .get_device_group_peer_memory_features = pfn<"vkGetDeviceGroupPeerMemoryFeatures">(instance, device, getter),
            .get_image_memory_requirements2 = pfn<"vkGetImageMemoryRequirements2">(instance, device, getter),
            .get_buffer_memory_requirements2 = pfn<"vkGetBufferMemoryRequirements2">(instance, device, getter),
            .get_image_sparse_memory_requirements2 = pfn<"vkGetImageSparseMemoryRequirements2">(instance, device, getter),
            .trim_command_pool = pfn<"vkTrimCommandPool">(instance, device, getter),
            .get_device_queue2 = pfn<"vkGetDeviceQueue2">(instance, device, getter),
            .create_sampler_ycbcr_conversion = pfn<"vkCreateSamplerYcbcrConversion">(instance, device, getter),
            .destroy_sampler_ycbcr_conversion = pfn<"vkDestroySamplerYcbcrConversion">(instance, device, getter),
            .create_descriptor_update_template = pfn<"vkCreateDescriptorUpdateTemplate">(instance, device, getter),
            .destroy_descriptor_update_template = pfn<"vkDestroyDescriptorUpdateTemplate">(instance, device, getter),
            .update_descriptor_set_with_template = pfn<"vkUpdateDescriptorSetWithTemplate">(instance, device, getter),
            .get_descriptor_set_layout_support = pfn<"vkGetDescriptorSetLayoutSupport">(instance, device, getter),

            .cmd =
            {
                .set_device_mask = pfn<"vkCmdSetDeviceMask">(instance, device, getter),
                .dispatch_base = pfn<"vkCmdDispatchBase">(instance, device, getter),

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    device_core_functions::vk12_core_functions vk12 = {};

    if(version >= version_number{1, 2, 0})
    {
        // clang-format off
        vk12 =
        {
            .create_render_pass2 = pfn<"vkCreateRenderPass2">(instance, device, getter),
            .reset_query_pool = pfn<"vkResetQueryPool">(instance, device, getter),
            .get_semaphore_counter_value = pfn<"vkGetSemaphoreCounterValue">(instance, device, getter),
            .wait_semaphores = pfn<"vkWaitSemaphores">(instance, device, getter),
            .signal_semaphore = pfn<"vkSignalSemaphore">(instance, device, getter),
            .get_buffer_device_address = pfn<"vkGetBufferDeviceAddress">(instance, device, getter),
            .get_buffer_opaque_capture_address = pfn<"vkGetBufferOpaqueCaptureAddress">(instance, device, getter),
            .get_device_memory_opaque_capture_address = pfn<"vkGetDeviceMemoryOpaqueCaptureAddress">(instance, device, getter),

            .cmd =
            {
                .draw_indirect_count = pfn<"vkCmdDrawIndirectCount">(instance, device, getter),
                .draw_indexed_indirect_count = pfn<"vkCmdDrawIndexedIndirectCount">(instance, device, getter),
                .begin_render_pass2 = pfn<"vkCmdBeginRenderPass2">(instance, device, getter),
                .next_subpass2 = pfn<"vkCmdNextSubpass2">(instance, device, getter),
                .end_render_pass2 = pfn<"vkCmdEndRenderPass2">(instance, device, getter),

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    device_core_functions::vk13_core_functions vk13 = {};

    if(version >= version_number{1, 3, 0})
    {
        // clang-format off
        vk13 =
        {
            .create_private_data_slot = pfn<"vkCreatePrivateDataSlot">(instance, device, getter),
            .destroy_private_data_slot = pfn<"vkDestroyPrivateDataSlot">(instance, device, getter),
            .set_private_data = pfn<"vkSetPrivateData">(instance, device, getter),
            .get_private_data = pfn<"vkGetPrivateData">(instance, device, getter),
            .queue_submit2 = pfn<"vkQueueSubmit2">(instance, device, getter),
            .get_device_buffer_memory_requirements = pfn<"vkGetDeviceBufferMemoryRequirements">(instance, device, getter),
            .get_device_image_memory_requirements = pfn<"vkGetDeviceImageMemoryRequirements">(instance, device, getter),
            .get_device_image_sparse_memory_requirements = pfn<"vkGetDeviceImageSparseMemoryRequirements">(instance, device, getter),

            .cmd =
            {
                .set_event2 = pfn<"vkCmdSetEvent2">(instance, device, getter),
                .reset_event2 = pfn<"vkCmdResetEvent2">(instance, device, getter),
                .wait_events2 = pfn<"vkCmdWaitEvents2">(instance, device, getter),
                .pipeline_barrier2 = pfn<"vkCmdPipelineBarrier2">(instance, device, getter),
                .write_timestamp2 = pfn<"vkCmdWriteTimestamp2">(instance, device, getter),
                .copy_buffer2 = pfn<"vkCmdCopyBuffer2">(instance, device, getter),
                .copy_image2 = pfn<"vkCmdCopyImage2">(instance, device, getter),
                .copy_buffer_to_image2 = pfn<"vkCmdCopyBufferToImage2">(instance, device, getter),
                .copy_image_to_buffer2 = pfn<"vkCmdCopyImageToBuffer2">(instance, device, getter),
                .blit_image2 = pfn<"vkCmdBlitImage2">(instance, device, getter),
                .resolve_image2 = pfn<"vkCmdResolveImage2">(instance, device, getter),
                .begin_rendering = pfn<"vkCmdBeginRendering">(instance, device, getter),
                .end_rendering = pfn<"vkCmdEndRendering">(instance, device, getter),
                .set_cull_mode = pfn<"vkCmdSetCullMode">(instance, device, getter),
                .set_front_face = pfn<"vkCmdSetFrontFace">(instance, device, getter),
                .set_primitive_topology = pfn<"vkCmdSetPrimitiveTopology">(instance, device, getter),
                .set_viewport_with_count = pfn<"vkCmdSetViewportWithCount">(instance, device, getter),
                .set_scissor_with_count = pfn<"vkCmdSetScissorWithCount">(instance, device, getter),
                .bind_vertex_buffers2 = pfn<"vkCmdBindVertexBuffers2">(instance, device, getter),
                .set_depth_test_enable = pfn<"vkCmdSetDepthTestEnable">(instance, device, getter),
                .set_depth_write_enable = pfn<"vkCmdSetDepthWriteEnable">(instance, device, getter),
                .set_depth_compare_op = pfn<"vkCmdSetDepthCompareOp">(instance, device, getter),
                .set_depth_bounds_test_enable = pfn<"vkCmdSetDepthBoundsTestEnable">(instance, device, getter),
                .set_stencil_test_enable = pfn<"vkCmdSetStencilTestEnable">(instance, device, getter),
                .set_stencil_op = pfn<"vkCmdSetStencilOp">(instance, device, getter),
                .set_rasterizer_discard_enable = pfn<"vkCmdSetRasterizerDiscardEnable">(instance, device, getter),
                .set_depth_bias_enable = pfn<"vkCmdSetDepthBiasEnable">(instance, device, getter),
                .set_primitive_restart_enable = pfn<"vkCmdSetPrimitiveRestartEnable">(instance, device, getter),

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    device_core_functions::vk14_core_functions vk14 = {};

    if(version >= version_number{1, 4, 0})
    {
        // clang-format off
        vk14 =
        {
            .map_memory2 = pfn<"vkMapMemory2">(instance, device, getter),
            .unmap_memory2 = pfn<"vkUnmapMemory2">(instance, device, getter),
            .get_rendering_area_granularity = pfn<"vkGetRenderingAreaGranularity">(instance, device, getter),
            .get_device_image_subresource_layout = pfn<"vkGetDeviceImageSubresourceLayout">(instance, device, getter),
            .get_image_subresource_layout2 = pfn<"vkGetImageSubresourceLayout2">(instance, device, getter),
            .copy_memory_to_image = pfn<"vkCopyMemoryToImage">(instance, device, getter),
            .copy_image_to_memory = pfn<"vkCopyImageToMemory">(instance, device, getter),
            .copy_image_to_image = pfn<"vkCopyImageToImage">(instance, device, getter),
            .transition_image_layout = pfn<"vkTransitionImageLayout">(instance, device, getter),

            .cmd =
            {
                .set_line_stipple = pfn<"vkCmdSetLineStipple">(instance, device, getter),
                .bind_index_buffer2 = pfn<"vkCmdBindIndexBuffer2">(instance, device, getter),
                .push_descriptor_set = pfn<"vkCmdPushDescriptorSet">(instance, device, getter),
                .push_descriptor_set_with_template = pfn<"vkCmdPushDescriptorSetWithTemplate">(instance, device, getter),
                .set_rendering_attachment_locations = pfn<"vkCmdSetRenderingAttachmentLocations">(instance, device, getter),
                .set_rendering_input_attachment_indices = pfn<"vkCmdSetRenderingInputAttachmentIndices">(instance, device, getter),
                .bind_descriptor_sets2 = pfn<"vkCmdBindDescriptorSets2">(instance, device, getter),
                .push_constants2 = pfn<"vkCmdPushConstants2">(instance, device, getter),
                .push_descriptor_set2 = pfn<"vkCmdPushDescriptorSet2">(instance, device, getter),
                .push_descriptor_set_with_template2 = pfn<"vkCmdPushDescriptorSetWithTemplate2">(instance, device, getter),

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_4)

    return {

#if defined(VK_VERSION_1_0)
        vk10,
#endif //  #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
        vk11,
#endif //  #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
        vk12,
#endif //  #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
        vk13,
#endif //  #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
        vk14,
#endif //  #if defined(VK_VERSION_1_4)
    };
}

} // namespace fubuki
