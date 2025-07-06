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

#ifndef FUBUKI_CORE_FUNCTIONSDEVICE_HPP
#define FUBUKI_CORE_FUNCTIONSDEVICE_HPP

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#include "core/config/macros.hpp"
#include "core/detail/pfn.hpp"
#include "core/handle.hpp"
#include "core/version_number.hpp"
#include "core/vulkan.hpp"

namespace fubuki
{

struct device_core_functions
{

#if defined(VK_VERSION_1_0)
    struct vk10_core_functions
    {
        struct command
        {
            PFN_vkCmdBindPipeline           bind_pipeline             = nullptr;
            PFN_vkCmdSetViewport            set_viewport              = nullptr;
            PFN_vkCmdSetScissor             set_scissor               = nullptr;
            PFN_vkCmdSetLineWidth           set_line_width            = nullptr;
            PFN_vkCmdSetDepthBias           set_depth_bias            = nullptr;
            PFN_vkCmdSetBlendConstants      set_blend_constants       = nullptr;
            PFN_vkCmdSetDepthBounds         set_depth_bounds          = nullptr;
            PFN_vkCmdSetStencilCompareMask  set_stencil_compare_mask  = nullptr;
            PFN_vkCmdSetStencilWriteMask    set_stencil_write_mask    = nullptr;
            PFN_vkCmdSetStencilReference    set_stencil_reference     = nullptr;
            PFN_vkCmdBindDescriptorSets     bind_descriptor_sets      = nullptr;
            PFN_vkCmdBindIndexBuffer        bind_index_buffer         = nullptr;
            PFN_vkCmdBindVertexBuffers      bind_vertex_buffers       = nullptr;
            PFN_vkCmdDraw                   draw                      = nullptr;
            PFN_vkCmdDrawIndexed            draw_indexed              = nullptr;
            PFN_vkCmdDrawIndirect           draw_indirect             = nullptr;
            PFN_vkCmdDrawIndexedIndirect    draw_indexed_indirect     = nullptr;
            PFN_vkCmdDispatch               dispatch                  = nullptr;
            PFN_vkCmdDispatchIndirect       dispatch_indirect         = nullptr;
            PFN_vkCmdCopyBuffer             copy_buffer               = nullptr;
            PFN_vkCmdCopyImage              copy_image                = nullptr;
            PFN_vkCmdBlitImage              blit_image                = nullptr;
            PFN_vkCmdCopyBufferToImage      copy_buffer_to_image      = nullptr;
            PFN_vkCmdCopyImageToBuffer      copy_image_to_buffer      = nullptr;
            PFN_vkCmdUpdateBuffer           update_buffer             = nullptr;
            PFN_vkCmdFillBuffer             fill_buffer               = nullptr;
            PFN_vkCmdClearColorImage        clear_color_image         = nullptr;
            PFN_vkCmdClearDepthStencilImage clear_depth_stencil_image = nullptr;
            PFN_vkCmdClearAttachments       clear_attachments         = nullptr;
            PFN_vkCmdResolveImage           resolve_image             = nullptr;
            PFN_vkCmdSetEvent               set_event                 = nullptr;
            PFN_vkCmdResetEvent             reset_event               = nullptr;
            PFN_vkCmdWaitEvents             wait_events               = nullptr;
            PFN_vkCmdPipelineBarrier        pipeline_barrier          = nullptr;
            PFN_vkCmdBeginQuery             begin_query               = nullptr;
            PFN_vkCmdEndQuery               end_query                 = nullptr;
            PFN_vkCmdResetQueryPool         reset_query_pool          = nullptr;
            PFN_vkCmdWriteTimestamp         write_timestamp           = nullptr;
            PFN_vkCmdCopyQueryPoolResults   copy_query_pool_results   = nullptr;
            PFN_vkCmdPushConstants          push_constants            = nullptr;
            PFN_vkCmdBeginRenderPass        begin_render_pass         = nullptr;
            PFN_vkCmdNextSubpass            next_subpass              = nullptr;
            PFN_vkCmdEndRenderPass          end_render_pass           = nullptr;
            PFN_vkCmdExecuteCommands        execute_commands          = nullptr;
        };

        PFN_vkGetDeviceQueue                   get_device_queue                     = nullptr;
        PFN_vkQueueSubmit                      queue_submit                         = nullptr;
        PFN_vkQueueWaitIdle                    queue_wait_idle                      = nullptr;
        PFN_vkDeviceWaitIdle                   device_wait_idle                     = nullptr;
        PFN_vkAllocateMemory                   allocate_memory                      = nullptr;
        PFN_vkFreeMemory                       free_memory                          = nullptr;
        PFN_vkMapMemory                        map_memory                           = nullptr;
        PFN_vkUnmapMemory                      unmap_memory                         = nullptr;
        PFN_vkFlushMappedMemoryRanges          flush_mapped_memory_ranges           = nullptr;
        PFN_vkInvalidateMappedMemoryRanges     invalidate_mapped_memory_ranges      = nullptr;
        PFN_vkGetDeviceMemoryCommitment        get_device_memory_commitment         = nullptr;
        PFN_vkBindBufferMemory                 bind_buffer_memory                   = nullptr;
        PFN_vkBindImageMemory                  bind_image_memory                    = nullptr;
        PFN_vkGetBufferMemoryRequirements      get_buffer_memory_requirements       = nullptr;
        PFN_vkGetImageMemoryRequirements       get_image_memory_requirements        = nullptr;
        PFN_vkGetImageSparseMemoryRequirements get_image_sparse_memory_requirements = nullptr;
        PFN_vkQueueBindSparse                  queue_bind_sparse                    = nullptr;
        PFN_vkCreateFence                      create_fence                         = nullptr;
        PFN_vkDestroyFence                     destroy_fence                        = nullptr;
        PFN_vkResetFences                      reset_fences                         = nullptr;
        PFN_vkGetFenceStatus                   get_fence_status                     = nullptr;
        PFN_vkWaitForFences                    wait_for_fences                      = nullptr;
        PFN_vkCreateSemaphore                  create_semaphore                     = nullptr;
        PFN_vkDestroySemaphore                 destroy_semaphore                    = nullptr;
        PFN_vkCreateEvent                      create_event                         = nullptr;
        PFN_vkDestroyEvent                     destroy_event                        = nullptr;
        PFN_vkGetEventStatus                   get_event_status                     = nullptr;
        PFN_vkSetEvent                         set_event                            = nullptr;
        PFN_vkResetEvent                       reset_event                          = nullptr;
        PFN_vkCreateQueryPool                  create_query_pool                    = nullptr;
        PFN_vkDestroyQueryPool                 destroy_query_pool                   = nullptr;
        PFN_vkGetQueryPoolResults              get_query_pool_results               = nullptr;
        PFN_vkCreateBuffer                     create_buffer                        = nullptr;
        PFN_vkDestroyBuffer                    destroy_buffer                       = nullptr;
        PFN_vkCreateBufferView                 create_buffer_view                   = nullptr;
        PFN_vkDestroyBufferView                destroy_buffer_view                  = nullptr;
        PFN_vkCreateImage                      create_image                         = nullptr;
        PFN_vkDestroyImage                     destroy_image                        = nullptr;
        PFN_vkGetImageSubresourceLayout        get_image_subresource_layout         = nullptr;
        PFN_vkCreateImageView                  create_image_view                    = nullptr;
        PFN_vkDestroyImageView                 destroy_image_view                   = nullptr;
        PFN_vkCreateShaderModule               create_shader_module                 = nullptr;
        PFN_vkDestroyShaderModule              destroy_shader_module                = nullptr;
        PFN_vkCreatePipelineCache              create_pipeline_cache                = nullptr;
        PFN_vkDestroyPipelineCache             destroy_pipeline_cache               = nullptr;
        PFN_vkGetPipelineCacheData             get_pipeline_cache_data              = nullptr;
        PFN_vkMergePipelineCaches              merge_pipeline_caches                = nullptr;
        PFN_vkCreateGraphicsPipelines          create_graphics_pipelines            = nullptr;
        PFN_vkCreateComputePipelines           create_compute_pipelines             = nullptr;
        PFN_vkDestroyPipeline                  destroy_pipeline                     = nullptr;
        PFN_vkCreatePipelineLayout             create_pipeline_layout               = nullptr;
        PFN_vkDestroyPipelineLayout            destroy_pipeline_layout              = nullptr;
        PFN_vkCreateSampler                    create_sampler                       = nullptr;
        PFN_vkDestroySampler                   destroy_sampler                      = nullptr;
        PFN_vkCreateDescriptorSetLayout        create_descriptor_set_layout         = nullptr;
        PFN_vkDestroyDescriptorSetLayout       destroy_descriptor_set_layout        = nullptr;
        PFN_vkCreateDescriptorPool             create_descriptor_pool               = nullptr;
        PFN_vkDestroyDescriptorPool            destroy_descriptor_pool              = nullptr;
        PFN_vkResetDescriptorPool              reset_descriptor_pool                = nullptr;
        PFN_vkAllocateDescriptorSets           allocate_descriptor_sets             = nullptr;
        PFN_vkFreeDescriptorSets               free_descriptor_sets                 = nullptr;
        PFN_vkUpdateDescriptorSets             update_descriptor_sets               = nullptr;
        PFN_vkCreateFramebuffer                create_framebuffer                   = nullptr;
        PFN_vkDestroyFramebuffer               destroy_framebuffer                  = nullptr;
        PFN_vkCreateRenderPass                 create_render_pass                   = nullptr;
        PFN_vkDestroyRenderPass                destroy_render_pass                  = nullptr;
        PFN_vkGetRenderAreaGranularity         get_render_area_granularity          = nullptr;
        PFN_vkCreateCommandPool                create_command_pool                  = nullptr;
        PFN_vkDestroyCommandPool               destroy_command_pool                 = nullptr;
        PFN_vkResetCommandPool                 reset_command_pool                   = nullptr;
        PFN_vkAllocateCommandBuffers           allocate_command_buffers             = nullptr;
        PFN_vkFreeCommandBuffers               free_command_buffers                 = nullptr;
        PFN_vkBeginCommandBuffer               begin_command_buffer                 = nullptr;
        PFN_vkEndCommandBuffer                 end_command_buffer                   = nullptr;
        PFN_vkResetCommandBuffer               reset_command_buffer                 = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk10_core_functions&() const { return vk10; }
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
    struct vk11_core_functions
    {
        struct command
        {
            PFN_vkCmdSetDeviceMask set_device_mask = nullptr;
            PFN_vkCmdDispatchBase  dispatch_base   = nullptr;
        };

        PFN_vkBindBufferMemory2                 bind_buffer_memory2                   = nullptr;
        PFN_vkBindImageMemory2                  bind_image_memory2                    = nullptr;
        PFN_vkGetDeviceGroupPeerMemoryFeatures  get_device_group_peer_memory_features = nullptr;
        PFN_vkGetImageMemoryRequirements2       get_image_memory_requirements2        = nullptr;
        PFN_vkGetBufferMemoryRequirements2      get_buffer_memory_requirements2       = nullptr;
        PFN_vkGetImageSparseMemoryRequirements2 get_image_sparse_memory_requirements2 = nullptr;
        PFN_vkTrimCommandPool                   trim_command_pool                     = nullptr;
        PFN_vkGetDeviceQueue2                   get_device_queue2                     = nullptr;
        PFN_vkCreateSamplerYcbcrConversion      create_sampler_ycbcr_conversion       = nullptr;
        PFN_vkDestroySamplerYcbcrConversion     destroy_sampler_ycbcr_conversion      = nullptr;
        PFN_vkCreateDescriptorUpdateTemplate    create_descriptor_update_template     = nullptr;
        PFN_vkDestroyDescriptorUpdateTemplate   destroy_descriptor_update_template    = nullptr;
        PFN_vkUpdateDescriptorSetWithTemplate   update_descriptor_set_with_template   = nullptr;
        PFN_vkGetDescriptorSetLayoutSupport     get_descriptor_set_layout_support     = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk11_core_functions&() const { return vk11; }
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    struct vk12_core_functions
    {
        struct command
        {
            PFN_vkCmdDrawIndirectCount        draw_indirect_count         = nullptr;
            PFN_vkCmdDrawIndexedIndirectCount draw_indexed_indirect_count = nullptr;
            PFN_vkCmdBeginRenderPass2         begin_render_pass2          = nullptr;
            PFN_vkCmdNextSubpass2             next_subpass2               = nullptr;
            PFN_vkCmdEndRenderPass2           end_render_pass2            = nullptr;
        };

        PFN_vkCreateRenderPass2                   create_render_pass2                      = nullptr;
        PFN_vkResetQueryPool                      reset_query_pool                         = nullptr;
        PFN_vkGetSemaphoreCounterValue            get_semaphore_counter_value              = nullptr;
        PFN_vkWaitSemaphores                      wait_semaphores                          = nullptr;
        PFN_vkSignalSemaphore                     signal_semaphore                         = nullptr;
        PFN_vkGetBufferDeviceAddress              get_buffer_device_address                = nullptr;
        PFN_vkGetBufferOpaqueCaptureAddress       get_buffer_opaque_capture_address        = nullptr;
        PFN_vkGetDeviceMemoryOpaqueCaptureAddress get_device_memory_opaque_capture_address = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk12_core_functions&() const { return vk12; }
#endif // #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    struct vk13_core_functions
    {
        struct command
        {
            PFN_vkCmdSetEvent2                  set_event2                    = nullptr;
            PFN_vkCmdResetEvent2                reset_event2                  = nullptr;
            PFN_vkCmdWaitEvents2                wait_events2                  = nullptr;
            PFN_vkCmdPipelineBarrier2           pipeline_barrier2             = nullptr;
            PFN_vkCmdWriteTimestamp2            write_timestamp2              = nullptr;
            PFN_vkCmdCopyBuffer2                copy_buffer2                  = nullptr;
            PFN_vkCmdCopyImage2                 copy_image2                   = nullptr;
            PFN_vkCmdCopyBufferToImage2         copy_buffer_to_image2         = nullptr;
            PFN_vkCmdCopyImageToBuffer2         copy_image_to_buffer2         = nullptr;
            PFN_vkCmdBlitImage2                 blit_image2                   = nullptr;
            PFN_vkCmdResolveImage2              resolve_image2                = nullptr;
            PFN_vkCmdBeginRendering             begin_rendering               = nullptr;
            PFN_vkCmdEndRendering               end_rendering                 = nullptr;
            PFN_vkCmdSetCullMode                set_cull_mode                 = nullptr;
            PFN_vkCmdSetFrontFace               set_front_face                = nullptr;
            PFN_vkCmdSetPrimitiveTopology       set_primitive_topology        = nullptr;
            PFN_vkCmdSetViewportWithCount       set_viewport_with_count       = nullptr;
            PFN_vkCmdSetScissorWithCount        set_scissor_with_count        = nullptr;
            PFN_vkCmdBindVertexBuffers2         bind_vertex_buffers2          = nullptr;
            PFN_vkCmdSetDepthTestEnable         set_depth_test_enable         = nullptr;
            PFN_vkCmdSetDepthWriteEnable        set_depth_write_enable        = nullptr;
            PFN_vkCmdSetDepthCompareOp          set_depth_compare_op          = nullptr;
            PFN_vkCmdSetDepthBoundsTestEnable   set_depth_bounds_test_enable  = nullptr;
            PFN_vkCmdSetStencilTestEnable       set_stencil_test_enable       = nullptr;
            PFN_vkCmdSetStencilOp               set_stencil_op                = nullptr;
            PFN_vkCmdSetRasterizerDiscardEnable set_rasterizer_discard_enable = nullptr;
            PFN_vkCmdSetDepthBiasEnable         set_depth_bias_enable         = nullptr;
            PFN_vkCmdSetPrimitiveRestartEnable  set_primitive_restart_enable  = nullptr;
        };

        PFN_vkCreatePrivateDataSlot                  create_private_data_slot                    = nullptr;
        PFN_vkDestroyPrivateDataSlot                 destroy_private_data_slot                   = nullptr;
        PFN_vkSetPrivateData                         set_private_data                            = nullptr;
        PFN_vkGetPrivateData                         get_private_data                            = nullptr;
        PFN_vkQueueSubmit2                           queue_submit2                               = nullptr;
        PFN_vkGetDeviceBufferMemoryRequirements      get_device_buffer_memory_requirements       = nullptr;
        PFN_vkGetDeviceImageMemoryRequirements       get_device_image_memory_requirements        = nullptr;
        PFN_vkGetDeviceImageSparseMemoryRequirements get_device_image_sparse_memory_requirements = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk13_core_functions&() const { return vk13; }
#endif // #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    struct vk14_core_functions
    {
        struct command
        {
            PFN_vkCmdSetLineStipple                     set_line_stipple                       = nullptr;
            PFN_vkCmdBindIndexBuffer2                   bind_index_buffer2                     = nullptr;
            PFN_vkCmdPushDescriptorSet                  push_descriptor_set                    = nullptr;
            PFN_vkCmdPushDescriptorSetWithTemplate      push_descriptor_set_with_template      = nullptr;
            PFN_vkCmdSetRenderingAttachmentLocations    set_rendering_attachment_locations     = nullptr;
            PFN_vkCmdSetRenderingInputAttachmentIndices set_rendering_input_attachment_indices = nullptr;
            PFN_vkCmdBindDescriptorSets2                bind_descriptor_sets2                  = nullptr;
            PFN_vkCmdPushConstants2                     push_constants2                        = nullptr;
            PFN_vkCmdPushDescriptorSet2                 push_descriptor_set2                   = nullptr;
            PFN_vkCmdPushDescriptorSetWithTemplate2     push_descriptor_set_with_template2     = nullptr;
        };

        PFN_vkMapMemory2                      map_memory2                         = nullptr;
        PFN_vkUnmapMemory2                    unmap_memory2                       = nullptr;
        PFN_vkGetRenderingAreaGranularity     get_rendering_area_granularity      = nullptr;
        PFN_vkGetDeviceImageSubresourceLayout get_device_image_subresource_layout = nullptr;
        PFN_vkGetImageSubresourceLayout2      get_image_subresource_layout2       = nullptr;
        PFN_vkCopyMemoryToImage               copy_memory_to_image                = nullptr;
        PFN_vkCopyImageToMemory               copy_image_to_memory                = nullptr;
        PFN_vkCopyImageToImage                copy_image_to_image                 = nullptr;
        PFN_vkTransitionImageLayout           transition_image_layout             = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk14_core_functions&() const { return vk14; }
#endif // #if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    vk10_core_functions vk10 = {};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
    vk11_core_functions vk11 = {};
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    vk12_core_functions vk12 = {};
#endif // #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    vk13_core_functions vk13 = {};
#endif // #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    vk14_core_functions vk14 = {};
#endif // #if defined(VK_VERSION_1_4)
};

[[nodiscard]] FUBUKI_CORE_API device_core_functions load(instance_handle instance, version_number version, device_handle device) noexcept;

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a device_core_functions struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<device_core_functions, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const device_core_functions&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, version_struct, fubuki_name)                               \
    template<>                                                                                            \
    struct get_from<device_core_functions, #vk_function_name>                                             \
    {                                                                                                     \
                                                                                                          \
        static constexpr bool                valid = true;                                                \
        [[nodiscard]] constexpr static auto* get(const device_core_functions& functions) noexcept         \
        {                                                                                                 \
            static_assert(                                                                                \
                requires {                                                                                \
                    { functions.version_struct.fubuki_name };                                             \
                }, "Internal error. Bad name or version structure.");                                     \
                                                                                                          \
            auto pfn = functions.version_struct.fubuki_name;                                              \
                                                                                                          \
            using expected_pfn_type = PFN_##vk_function_name;                                             \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                        \
                                                                                                          \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch."); \
                                                                                                          \
            return pfn;                                                                                   \
        }                                                                                                 \
    }

FUBUKI_MAKE_GET_FROM(vkGetDeviceQueue, vk10, get_device_queue);
FUBUKI_MAKE_GET_FROM(vkQueueSubmit, vk10, queue_submit);
FUBUKI_MAKE_GET_FROM(vkQueueWaitIdle, vk10, queue_wait_idle);
FUBUKI_MAKE_GET_FROM(vkDeviceWaitIdle, vk10, device_wait_idle);
FUBUKI_MAKE_GET_FROM(vkAllocateMemory, vk10, allocate_memory);
FUBUKI_MAKE_GET_FROM(vkFreeMemory, vk10, free_memory);
FUBUKI_MAKE_GET_FROM(vkMapMemory, vk10, map_memory);
FUBUKI_MAKE_GET_FROM(vkUnmapMemory, vk10, unmap_memory);
FUBUKI_MAKE_GET_FROM(vkFlushMappedMemoryRanges, vk10, flush_mapped_memory_ranges);
FUBUKI_MAKE_GET_FROM(vkInvalidateMappedMemoryRanges, vk10, invalidate_mapped_memory_ranges);
FUBUKI_MAKE_GET_FROM(vkGetDeviceMemoryCommitment, vk10, get_device_memory_commitment);
FUBUKI_MAKE_GET_FROM(vkBindBufferMemory, vk10, bind_buffer_memory);
FUBUKI_MAKE_GET_FROM(vkBindImageMemory, vk10, bind_image_memory);
FUBUKI_MAKE_GET_FROM(vkGetBufferMemoryRequirements, vk10, get_buffer_memory_requirements);
FUBUKI_MAKE_GET_FROM(vkGetImageMemoryRequirements, vk10, get_image_memory_requirements);
FUBUKI_MAKE_GET_FROM(vkGetImageSparseMemoryRequirements, vk10, get_image_sparse_memory_requirements);
FUBUKI_MAKE_GET_FROM(vkQueueBindSparse, vk10, queue_bind_sparse);
FUBUKI_MAKE_GET_FROM(vkCreateFence, vk10, create_fence);
FUBUKI_MAKE_GET_FROM(vkDestroyFence, vk10, destroy_fence);
FUBUKI_MAKE_GET_FROM(vkResetFences, vk10, reset_fences);
FUBUKI_MAKE_GET_FROM(vkGetFenceStatus, vk10, get_fence_status);
FUBUKI_MAKE_GET_FROM(vkWaitForFences, vk10, wait_for_fences);
FUBUKI_MAKE_GET_FROM(vkCreateSemaphore, vk10, create_semaphore);
FUBUKI_MAKE_GET_FROM(vkDestroySemaphore, vk10, destroy_semaphore);
FUBUKI_MAKE_GET_FROM(vkCreateEvent, vk10, create_event);
FUBUKI_MAKE_GET_FROM(vkDestroyEvent, vk10, destroy_event);
FUBUKI_MAKE_GET_FROM(vkGetEventStatus, vk10, get_event_status);
FUBUKI_MAKE_GET_FROM(vkSetEvent, vk10, set_event);
FUBUKI_MAKE_GET_FROM(vkResetEvent, vk10, reset_event);
FUBUKI_MAKE_GET_FROM(vkCreateQueryPool, vk10, create_query_pool);
FUBUKI_MAKE_GET_FROM(vkDestroyQueryPool, vk10, destroy_query_pool);
FUBUKI_MAKE_GET_FROM(vkGetQueryPoolResults, vk10, get_query_pool_results);
FUBUKI_MAKE_GET_FROM(vkCreateBuffer, vk10, create_buffer);
FUBUKI_MAKE_GET_FROM(vkDestroyBuffer, vk10, destroy_buffer);
FUBUKI_MAKE_GET_FROM(vkCreateBufferView, vk10, create_buffer_view);
FUBUKI_MAKE_GET_FROM(vkDestroyBufferView, vk10, destroy_buffer_view);
FUBUKI_MAKE_GET_FROM(vkCreateImage, vk10, create_image);
FUBUKI_MAKE_GET_FROM(vkDestroyImage, vk10, destroy_image);
FUBUKI_MAKE_GET_FROM(vkGetImageSubresourceLayout, vk10, get_image_subresource_layout);
FUBUKI_MAKE_GET_FROM(vkCreateImageView, vk10, create_image_view);
FUBUKI_MAKE_GET_FROM(vkDestroyImageView, vk10, destroy_image_view);
FUBUKI_MAKE_GET_FROM(vkCreateShaderModule, vk10, create_shader_module);
FUBUKI_MAKE_GET_FROM(vkDestroyShaderModule, vk10, destroy_shader_module);
FUBUKI_MAKE_GET_FROM(vkCreatePipelineCache, vk10, create_pipeline_cache);
FUBUKI_MAKE_GET_FROM(vkDestroyPipelineCache, vk10, destroy_pipeline_cache);
FUBUKI_MAKE_GET_FROM(vkGetPipelineCacheData, vk10, get_pipeline_cache_data);
FUBUKI_MAKE_GET_FROM(vkMergePipelineCaches, vk10, merge_pipeline_caches);
FUBUKI_MAKE_GET_FROM(vkCreateGraphicsPipelines, vk10, create_graphics_pipelines);
FUBUKI_MAKE_GET_FROM(vkCreateComputePipelines, vk10, create_compute_pipelines);
FUBUKI_MAKE_GET_FROM(vkDestroyPipeline, vk10, destroy_pipeline);
FUBUKI_MAKE_GET_FROM(vkCreatePipelineLayout, vk10, create_pipeline_layout);
FUBUKI_MAKE_GET_FROM(vkDestroyPipelineLayout, vk10, destroy_pipeline_layout);
FUBUKI_MAKE_GET_FROM(vkCreateSampler, vk10, create_sampler);
FUBUKI_MAKE_GET_FROM(vkDestroySampler, vk10, destroy_sampler);
FUBUKI_MAKE_GET_FROM(vkCreateDescriptorSetLayout, vk10, create_descriptor_set_layout);
FUBUKI_MAKE_GET_FROM(vkDestroyDescriptorSetLayout, vk10, destroy_descriptor_set_layout);
FUBUKI_MAKE_GET_FROM(vkCreateDescriptorPool, vk10, create_descriptor_pool);
FUBUKI_MAKE_GET_FROM(vkDestroyDescriptorPool, vk10, destroy_descriptor_pool);
FUBUKI_MAKE_GET_FROM(vkResetDescriptorPool, vk10, reset_descriptor_pool);
FUBUKI_MAKE_GET_FROM(vkAllocateDescriptorSets, vk10, allocate_descriptor_sets);
FUBUKI_MAKE_GET_FROM(vkFreeDescriptorSets, vk10, free_descriptor_sets);
FUBUKI_MAKE_GET_FROM(vkUpdateDescriptorSets, vk10, update_descriptor_sets);
FUBUKI_MAKE_GET_FROM(vkCreateFramebuffer, vk10, create_framebuffer);
FUBUKI_MAKE_GET_FROM(vkDestroyFramebuffer, vk10, destroy_framebuffer);
FUBUKI_MAKE_GET_FROM(vkCreateRenderPass, vk10, create_render_pass);
FUBUKI_MAKE_GET_FROM(vkDestroyRenderPass, vk10, destroy_render_pass);
FUBUKI_MAKE_GET_FROM(vkGetRenderAreaGranularity, vk10, get_render_area_granularity);
FUBUKI_MAKE_GET_FROM(vkCreateCommandPool, vk10, create_command_pool);
FUBUKI_MAKE_GET_FROM(vkDestroyCommandPool, vk10, destroy_command_pool);
FUBUKI_MAKE_GET_FROM(vkResetCommandPool, vk10, reset_command_pool);
FUBUKI_MAKE_GET_FROM(vkAllocateCommandBuffers, vk10, allocate_command_buffers);
FUBUKI_MAKE_GET_FROM(vkFreeCommandBuffers, vk10, free_command_buffers);
FUBUKI_MAKE_GET_FROM(vkBeginCommandBuffer, vk10, begin_command_buffer);
FUBUKI_MAKE_GET_FROM(vkEndCommandBuffer, vk10, end_command_buffer);
FUBUKI_MAKE_GET_FROM(vkResetCommandBuffer, vk10, reset_command_buffer);
FUBUKI_MAKE_GET_FROM(vkCmdBindPipeline, vk10.cmd, bind_pipeline);
FUBUKI_MAKE_GET_FROM(vkCmdSetViewport, vk10.cmd, set_viewport);
FUBUKI_MAKE_GET_FROM(vkCmdSetScissor, vk10.cmd, set_scissor);
FUBUKI_MAKE_GET_FROM(vkCmdSetLineWidth, vk10.cmd, set_line_width);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthBias, vk10.cmd, set_depth_bias);
FUBUKI_MAKE_GET_FROM(vkCmdSetBlendConstants, vk10.cmd, set_blend_constants);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthBounds, vk10.cmd, set_depth_bounds);
FUBUKI_MAKE_GET_FROM(vkCmdSetStencilCompareMask, vk10.cmd, set_stencil_compare_mask);
FUBUKI_MAKE_GET_FROM(vkCmdSetStencilWriteMask, vk10.cmd, set_stencil_write_mask);
FUBUKI_MAKE_GET_FROM(vkCmdSetStencilReference, vk10.cmd, set_stencil_reference);
FUBUKI_MAKE_GET_FROM(vkCmdBindDescriptorSets, vk10.cmd, bind_descriptor_sets);
FUBUKI_MAKE_GET_FROM(vkCmdBindIndexBuffer, vk10.cmd, bind_index_buffer);
FUBUKI_MAKE_GET_FROM(vkCmdBindVertexBuffers, vk10.cmd, bind_vertex_buffers);
FUBUKI_MAKE_GET_FROM(vkCmdDraw, vk10.cmd, draw);
FUBUKI_MAKE_GET_FROM(vkCmdDrawIndexed, vk10.cmd, draw_indexed);
FUBUKI_MAKE_GET_FROM(vkCmdDrawIndirect, vk10.cmd, draw_indirect);
FUBUKI_MAKE_GET_FROM(vkCmdDrawIndexedIndirect, vk10.cmd, draw_indexed_indirect);
FUBUKI_MAKE_GET_FROM(vkCmdDispatch, vk10.cmd, dispatch);
FUBUKI_MAKE_GET_FROM(vkCmdDispatchIndirect, vk10.cmd, dispatch_indirect);
FUBUKI_MAKE_GET_FROM(vkCmdCopyBuffer, vk10.cmd, copy_buffer);
FUBUKI_MAKE_GET_FROM(vkCmdCopyImage, vk10.cmd, copy_image);
FUBUKI_MAKE_GET_FROM(vkCmdBlitImage, vk10.cmd, blit_image);
FUBUKI_MAKE_GET_FROM(vkCmdCopyBufferToImage, vk10.cmd, copy_buffer_to_image);
FUBUKI_MAKE_GET_FROM(vkCmdCopyImageToBuffer, vk10.cmd, copy_image_to_buffer);
FUBUKI_MAKE_GET_FROM(vkCmdUpdateBuffer, vk10.cmd, update_buffer);
FUBUKI_MAKE_GET_FROM(vkCmdFillBuffer, vk10.cmd, fill_buffer);
FUBUKI_MAKE_GET_FROM(vkCmdClearColorImage, vk10.cmd, clear_color_image);
FUBUKI_MAKE_GET_FROM(vkCmdClearDepthStencilImage, vk10.cmd, clear_depth_stencil_image);
FUBUKI_MAKE_GET_FROM(vkCmdClearAttachments, vk10.cmd, clear_attachments);
FUBUKI_MAKE_GET_FROM(vkCmdResolveImage, vk10.cmd, resolve_image);
FUBUKI_MAKE_GET_FROM(vkCmdSetEvent, vk10.cmd, set_event);
FUBUKI_MAKE_GET_FROM(vkCmdResetEvent, vk10.cmd, reset_event);
FUBUKI_MAKE_GET_FROM(vkCmdWaitEvents, vk10.cmd, wait_events);
FUBUKI_MAKE_GET_FROM(vkCmdPipelineBarrier, vk10.cmd, pipeline_barrier);
FUBUKI_MAKE_GET_FROM(vkCmdBeginQuery, vk10.cmd, begin_query);
FUBUKI_MAKE_GET_FROM(vkCmdEndQuery, vk10.cmd, end_query);
FUBUKI_MAKE_GET_FROM(vkCmdResetQueryPool, vk10.cmd, reset_query_pool);
FUBUKI_MAKE_GET_FROM(vkCmdWriteTimestamp, vk10.cmd, write_timestamp);
FUBUKI_MAKE_GET_FROM(vkCmdCopyQueryPoolResults, vk10.cmd, copy_query_pool_results);
FUBUKI_MAKE_GET_FROM(vkCmdPushConstants, vk10.cmd, push_constants);
FUBUKI_MAKE_GET_FROM(vkCmdBeginRenderPass, vk10.cmd, begin_render_pass);
FUBUKI_MAKE_GET_FROM(vkCmdNextSubpass, vk10.cmd, next_subpass);
FUBUKI_MAKE_GET_FROM(vkCmdEndRenderPass, vk10.cmd, end_render_pass);
FUBUKI_MAKE_GET_FROM(vkCmdExecuteCommands, vk10.cmd, execute_commands);
FUBUKI_MAKE_GET_FROM(vkBindBufferMemory2, vk11, bind_buffer_memory2);
FUBUKI_MAKE_GET_FROM(vkBindImageMemory2, vk11, bind_image_memory2);
FUBUKI_MAKE_GET_FROM(vkGetDeviceGroupPeerMemoryFeatures, vk11, get_device_group_peer_memory_features);
FUBUKI_MAKE_GET_FROM(vkGetImageMemoryRequirements2, vk11, get_image_memory_requirements2);
FUBUKI_MAKE_GET_FROM(vkGetBufferMemoryRequirements2, vk11, get_buffer_memory_requirements2);
FUBUKI_MAKE_GET_FROM(vkGetImageSparseMemoryRequirements2, vk11, get_image_sparse_memory_requirements2);
FUBUKI_MAKE_GET_FROM(vkTrimCommandPool, vk11, trim_command_pool);
FUBUKI_MAKE_GET_FROM(vkGetDeviceQueue2, vk11, get_device_queue2);
FUBUKI_MAKE_GET_FROM(vkCreateSamplerYcbcrConversion, vk11, create_sampler_ycbcr_conversion);
FUBUKI_MAKE_GET_FROM(vkDestroySamplerYcbcrConversion, vk11, destroy_sampler_ycbcr_conversion);
FUBUKI_MAKE_GET_FROM(vkCreateDescriptorUpdateTemplate, vk11, create_descriptor_update_template);
FUBUKI_MAKE_GET_FROM(vkDestroyDescriptorUpdateTemplate, vk11, destroy_descriptor_update_template);
FUBUKI_MAKE_GET_FROM(vkUpdateDescriptorSetWithTemplate, vk11, update_descriptor_set_with_template);
FUBUKI_MAKE_GET_FROM(vkGetDescriptorSetLayoutSupport, vk11, get_descriptor_set_layout_support);
FUBUKI_MAKE_GET_FROM(vkCmdSetDeviceMask, vk11.cmd, set_device_mask);
FUBUKI_MAKE_GET_FROM(vkCmdDispatchBase, vk11.cmd, dispatch_base);
FUBUKI_MAKE_GET_FROM(vkCreateRenderPass2, vk12, create_render_pass2);
FUBUKI_MAKE_GET_FROM(vkResetQueryPool, vk12, reset_query_pool);
FUBUKI_MAKE_GET_FROM(vkGetSemaphoreCounterValue, vk12, get_semaphore_counter_value);
FUBUKI_MAKE_GET_FROM(vkWaitSemaphores, vk12, wait_semaphores);
FUBUKI_MAKE_GET_FROM(vkSignalSemaphore, vk12, signal_semaphore);
FUBUKI_MAKE_GET_FROM(vkGetBufferDeviceAddress, vk12, get_buffer_device_address);
FUBUKI_MAKE_GET_FROM(vkGetBufferOpaqueCaptureAddress, vk12, get_buffer_opaque_capture_address);
FUBUKI_MAKE_GET_FROM(vkGetDeviceMemoryOpaqueCaptureAddress, vk12, get_device_memory_opaque_capture_address);
FUBUKI_MAKE_GET_FROM(vkCmdDrawIndirectCount, vk12.cmd, draw_indirect_count);
FUBUKI_MAKE_GET_FROM(vkCmdDrawIndexedIndirectCount, vk12.cmd, draw_indexed_indirect_count);
FUBUKI_MAKE_GET_FROM(vkCmdBeginRenderPass2, vk12.cmd, begin_render_pass2);
FUBUKI_MAKE_GET_FROM(vkCmdNextSubpass2, vk12.cmd, next_subpass2);
FUBUKI_MAKE_GET_FROM(vkCmdEndRenderPass2, vk12.cmd, end_render_pass2);
FUBUKI_MAKE_GET_FROM(vkCreatePrivateDataSlot, vk13, create_private_data_slot);
FUBUKI_MAKE_GET_FROM(vkDestroyPrivateDataSlot, vk13, destroy_private_data_slot);
FUBUKI_MAKE_GET_FROM(vkSetPrivateData, vk13, set_private_data);
FUBUKI_MAKE_GET_FROM(vkGetPrivateData, vk13, get_private_data);
FUBUKI_MAKE_GET_FROM(vkQueueSubmit2, vk13, queue_submit2);
FUBUKI_MAKE_GET_FROM(vkGetDeviceBufferMemoryRequirements, vk13, get_device_buffer_memory_requirements);
FUBUKI_MAKE_GET_FROM(vkGetDeviceImageMemoryRequirements, vk13, get_device_image_memory_requirements);
FUBUKI_MAKE_GET_FROM(vkGetDeviceImageSparseMemoryRequirements, vk13, get_device_image_sparse_memory_requirements);
FUBUKI_MAKE_GET_FROM(vkCmdSetEvent2, vk13.cmd, set_event2);
FUBUKI_MAKE_GET_FROM(vkCmdResetEvent2, vk13.cmd, reset_event2);
FUBUKI_MAKE_GET_FROM(vkCmdWaitEvents2, vk13.cmd, wait_events2);
FUBUKI_MAKE_GET_FROM(vkCmdPipelineBarrier2, vk13.cmd, pipeline_barrier2);
FUBUKI_MAKE_GET_FROM(vkCmdWriteTimestamp2, vk13.cmd, write_timestamp2);
FUBUKI_MAKE_GET_FROM(vkCmdCopyBuffer2, vk13.cmd, copy_buffer2);
FUBUKI_MAKE_GET_FROM(vkCmdCopyImage2, vk13.cmd, copy_image2);
FUBUKI_MAKE_GET_FROM(vkCmdCopyBufferToImage2, vk13.cmd, copy_buffer_to_image2);
FUBUKI_MAKE_GET_FROM(vkCmdCopyImageToBuffer2, vk13.cmd, copy_image_to_buffer2);
FUBUKI_MAKE_GET_FROM(vkCmdBlitImage2, vk13.cmd, blit_image2);
FUBUKI_MAKE_GET_FROM(vkCmdResolveImage2, vk13.cmd, resolve_image2);
FUBUKI_MAKE_GET_FROM(vkCmdBeginRendering, vk13.cmd, begin_rendering);
FUBUKI_MAKE_GET_FROM(vkCmdEndRendering, vk13.cmd, end_rendering);
FUBUKI_MAKE_GET_FROM(vkCmdSetCullMode, vk13.cmd, set_cull_mode);
FUBUKI_MAKE_GET_FROM(vkCmdSetFrontFace, vk13.cmd, set_front_face);
FUBUKI_MAKE_GET_FROM(vkCmdSetPrimitiveTopology, vk13.cmd, set_primitive_topology);
FUBUKI_MAKE_GET_FROM(vkCmdSetViewportWithCount, vk13.cmd, set_viewport_with_count);
FUBUKI_MAKE_GET_FROM(vkCmdSetScissorWithCount, vk13.cmd, set_scissor_with_count);
FUBUKI_MAKE_GET_FROM(vkCmdBindVertexBuffers2, vk13.cmd, bind_vertex_buffers2);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthTestEnable, vk13.cmd, set_depth_test_enable);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthWriteEnable, vk13.cmd, set_depth_write_enable);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthCompareOp, vk13.cmd, set_depth_compare_op);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthBoundsTestEnable, vk13.cmd, set_depth_bounds_test_enable);
FUBUKI_MAKE_GET_FROM(vkCmdSetStencilTestEnable, vk13.cmd, set_stencil_test_enable);
FUBUKI_MAKE_GET_FROM(vkCmdSetStencilOp, vk13.cmd, set_stencil_op);
FUBUKI_MAKE_GET_FROM(vkCmdSetRasterizerDiscardEnable, vk13.cmd, set_rasterizer_discard_enable);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthBiasEnable, vk13.cmd, set_depth_bias_enable);
FUBUKI_MAKE_GET_FROM(vkCmdSetPrimitiveRestartEnable, vk13.cmd, set_primitive_restart_enable);
FUBUKI_MAKE_GET_FROM(vkMapMemory2, vk14, map_memory2);
FUBUKI_MAKE_GET_FROM(vkUnmapMemory2, vk14, unmap_memory2);
FUBUKI_MAKE_GET_FROM(vkGetRenderingAreaGranularity, vk14, get_rendering_area_granularity);
FUBUKI_MAKE_GET_FROM(vkGetDeviceImageSubresourceLayout, vk14, get_device_image_subresource_layout);
FUBUKI_MAKE_GET_FROM(vkGetImageSubresourceLayout2, vk14, get_image_subresource_layout2);
FUBUKI_MAKE_GET_FROM(vkCopyMemoryToImage, vk14, copy_memory_to_image);
FUBUKI_MAKE_GET_FROM(vkCopyImageToMemory, vk14, copy_image_to_memory);
FUBUKI_MAKE_GET_FROM(vkCopyImageToImage, vk14, copy_image_to_image);
FUBUKI_MAKE_GET_FROM(vkTransitionImageLayout, vk14, transition_image_layout);
FUBUKI_MAKE_GET_FROM(vkCmdSetLineStipple, vk14.cmd, set_line_stipple);
FUBUKI_MAKE_GET_FROM(vkCmdBindIndexBuffer2, vk14.cmd, bind_index_buffer2);
FUBUKI_MAKE_GET_FROM(vkCmdPushDescriptorSet, vk14.cmd, push_descriptor_set);
FUBUKI_MAKE_GET_FROM(vkCmdPushDescriptorSetWithTemplate, vk14.cmd, push_descriptor_set_with_template);
FUBUKI_MAKE_GET_FROM(vkCmdSetRenderingAttachmentLocations, vk14.cmd, set_rendering_attachment_locations);
FUBUKI_MAKE_GET_FROM(vkCmdSetRenderingInputAttachmentIndices, vk14.cmd, set_rendering_input_attachment_indices);
FUBUKI_MAKE_GET_FROM(vkCmdBindDescriptorSets2, vk14.cmd, bind_descriptor_sets2);
FUBUKI_MAKE_GET_FROM(vkCmdPushConstants2, vk14.cmd, push_constants2);
FUBUKI_MAKE_GET_FROM(vkCmdPushDescriptorSet2, vk14.cmd, push_descriptor_set2);
FUBUKI_MAKE_GET_FROM(vkCmdPushDescriptorSetWithTemplate2, vk14.cmd, push_descriptor_set_with_template2);

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_CORE_FUNCTIONSDEVICE_HPP
