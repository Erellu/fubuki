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

#ifndef FUBUKI_CORE_HANDLE_HPP
#define FUBUKI_CORE_HANDLE_HPP

#include <cstddef>
#include <cstdint>
#include <functional>

#include "core/compile_time_hash.hpp"
#include "core/detail/manual_handle.hpp"
#include "core/detail/null_handle.hpp"
#include "core/vulkan.hpp"

namespace fubuki
{

template<std::uint64_t hash, typename T>
struct handle;

#define FUBUKI_MAKE_HANDLE(vk_handle, type_name)                                                       \
    template<>                                                                                         \
    struct handle<compile_time_hash(#vk_handle), vk_handle>                                            \
    {                                                                                                  \
        static constexpr auto name      = #vk_handle;                                                  \
        static constexpr auto name_hash = compile_time_hash(#vk_handle);                               \
        using underlying_type           = vk_handle;                                                   \
        using self_type                 = handle<name_hash, underlying_type>;                          \
                                                                                                       \
        constexpr explicit handle(underlying_type h) noexcept : vk{h} {}                               \
        constexpr handle(detail::null_handle_type = {}) noexcept {}                                    \
                                                                                                       \
        underlying_type vk = {};                                                                       \
                                                                                                       \
        constexpr auto& operator=(detail::null_handle_type) noexcept                                   \
        {                                                                                              \
            vk = {};                                                                                   \
            return *this;                                                                              \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]]                                                                                  \
        friend constexpr bool operator==(const self_type& h, const detail::null_handle_type&) noexcept \
        {                                                                                              \
            return h.vk == self_type::underlying_type{};                                               \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]]                                                                                  \
        friend constexpr bool operator==(const detail::null_handle_type&, const self_type& h) noexcept \
        {                                                                                              \
            return h.vk == self_type::underlying_type{};                                               \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]]                                                                                  \
        friend constexpr bool operator!=(const self_type& h, const detail::null_handle_type&) noexcept \
        {                                                                                              \
            return not(h == null_handle);                                                              \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]]                                                                                  \
        friend constexpr bool operator!=(const detail::null_handle_type&, const self_type& h) noexcept \
        {                                                                                              \
            return not(h == null_handle);                                                              \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]] friend constexpr auto operator<=>(const self_type&, const self_type&) = default; \
        [[nodiscard]] friend constexpr bool operator==(const self_type&, const self_type&)  = default; \
        [[nodiscard]] friend constexpr bool operator!=(const self_type&, const self_type&)  = default; \
    };                                                                                                 \
                                                                                                       \
    using type_name##_handle = handle<compile_time_hash(#vk_handle), vk_handle>

//------------------------------------------------------------------------------
// clang-format off

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkInstance, instance); // instance_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkPhysicalDevice, physical_device); // physical_device_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkDevice, device); // device_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkQueue, queue); // queue_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkCommandBuffer, command_buffer); // command_buffer_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkDeviceMemory, device_memory); // device_memory_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkCommandPool, command_pool); // command_pool_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkBuffer, buffer); // buffer_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkBufferView, buffer_view); // buffer_view_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkImage, image); // image_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkImageView, image_view); // image_view_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkShaderModule, shader_module); // shader_module_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkPipeline, pipeline); // pipeline_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkPipelineLayout, pipeline_layout); // pipeline_layout_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkSampler, sampler); // sampler_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkDescriptorSet, descriptor_set); // descriptor_set_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkDescriptorSetLayout, descriptor_set_layout); // descriptor_set_layout_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkDescriptorPool, descriptor_pool); // descriptor_pool_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkFence, fence); // fence_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkSemaphore, semaphore); // semaphore_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkEvent, event); // event_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkQueryPool, query_pool); // query_pool_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkFramebuffer, framebuffer); // framebuffer_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkRenderPass, render_pass); // render_pass_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    FUBUKI_MAKE_HANDLE(VkPipelineCache, pipeline_cache); // pipeline_cache_handle
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_KHR_pipeline_binary)
    FUBUKI_MAKE_HANDLE(VkPipelineBinaryKHR, pipeline_binary_khr); // pipeline_binary_khr_handle
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_NV_device_generated_commands)
    FUBUKI_MAKE_HANDLE(VkIndirectCommandsLayoutNV, indirect_commands_layout_nv); // indirect_commands_layout_nv_handle
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_HANDLE(VkIndirectCommandsLayoutEXT, indirect_commands_layout_ext); // indirect_commands_layout_ext_handle
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
    FUBUKI_MAKE_HANDLE(VkIndirectExecutionSetEXT, indirect_execution_set_ext); // indirect_execution_set_ext_handle
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_HANDLE(VkDescriptorUpdateTemplate, descriptor_update_template); // descriptor_update_template_handle
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    FUBUKI_MAKE_HANDLE(VkSamplerYcbcrConversion, sampler_ycbcr_conversion); // sampler_ycbcr_conversion_handle
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_EXT_validation_cache)
    FUBUKI_MAKE_HANDLE(VkValidationCacheEXT, validation_cache_ext); // validation_cache_ext_handle
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_KHR_acceleration_structure)
    FUBUKI_MAKE_HANDLE(VkAccelerationStructureKHR, acceleration_structure_khr); // acceleration_structure_khr_handle
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    FUBUKI_MAKE_HANDLE(VkAccelerationStructureNV, acceleration_structure_nv); // acceleration_structure_nv_handle
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_INTEL_performance_query)
    FUBUKI_MAKE_HANDLE(VkPerformanceConfigurationINTEL, performance_configuration_intel); // performance_configuration_intel_handle
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_FUCHSIA_buffer_collection)
    FUBUKI_MAKE_HANDLE(VkBufferCollectionFUCHSIA, buffer_collection_fuchsia); // buffer_collection_fuchsia_handle
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_KHR_deferred_host_operations)
    FUBUKI_MAKE_HANDLE(VkDeferredOperationKHR, deferred_operation_khr); // deferred_operation_khr_handle
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_VERSION_1_3)
    FUBUKI_MAKE_HANDLE(VkPrivateDataSlot, private_data_slot); // private_data_slot_handle
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_NVX_binary_import)
    FUBUKI_MAKE_HANDLE(VkCuModuleNVX, cu_module_nvx); // cu_module_nvx_handle
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
    FUBUKI_MAKE_HANDLE(VkCuFunctionNVX, cu_function_nvx); // cu_function_nvx_handle
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NV_optical_flow)
    FUBUKI_MAKE_HANDLE(VkOpticalFlowSessionNV, optical_flow_session_nv); // optical_flow_session_nv_handle
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_EXT_opacity_micromap)
    FUBUKI_MAKE_HANDLE(VkMicromapEXT, micromap_ext); // micromap_ext_handle
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_shader_object)
    FUBUKI_MAKE_HANDLE(VkShaderEXT, shader_ext); // shader_ext_handle
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_KHR_display)
    FUBUKI_MAKE_HANDLE(VkDisplayKHR, display_khr); // display_khr_handle
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
    FUBUKI_MAKE_HANDLE(VkDisplayModeKHR, display_mode_khr); // display_mode_khr_handle
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_surface)
    FUBUKI_MAKE_HANDLE(VkSurfaceKHR, surface_khr); // surface_khr_handle
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_swapchain)
    FUBUKI_MAKE_HANDLE(VkSwapchainKHR, swapchain_khr); // swapchain_khr_handle
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_EXT_debug_report)
    FUBUKI_MAKE_HANDLE(VkDebugReportCallbackEXT, debug_report_callback_ext); // debug_report_callback_ext_handle
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_utils)
    FUBUKI_MAKE_HANDLE(VkDebugUtilsMessengerEXT, debug_utils_messenger_ext); // debug_utils_messenger_ext_handle
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_HANDLE(VkVideoSessionKHR, video_session_khr); // video_session_khr_handle
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    FUBUKI_MAKE_HANDLE(VkVideoSessionParametersKHR, video_session_parameters_khr); // video_session_parameters_khr_handle
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_NV_external_sci_sync2)
    FUBUKI_MAKE_HANDLE(VkSemaphoreSciSyncPoolNV, semaphore_sci_sync_pool_nv); // semaphore_sci_sync_pool_nv_handle
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_cuda_kernel_launch)
    FUBUKI_MAKE_HANDLE(VkCudaModuleNV, cuda_module_nv); // cuda_module_nv_handle
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
    FUBUKI_MAKE_HANDLE(VkCudaFunctionNV, cuda_function_nv); // cuda_function_nv_handle
#endif // #if defined (VK_NV_cuda_kernel_launch)

// clang-format on
//------------------------------------------------------------------------------

} // namespace fubuki

#undef FUBUKI_MAKE_HANDLE

namespace std
{

template<std::uint64_t h, typename T>
struct hash<fubuki::handle<h, T>>
{
    [[nodiscard]] auto operator()(const fubuki::handle<h, T>& v) const noexcept { return std::hash<T>{}(v.vk); }
};

} // namespace std

#endif // FUBUKI_CORE_HANDLE_HPP
