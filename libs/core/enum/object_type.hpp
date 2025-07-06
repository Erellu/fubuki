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

#ifndef FUBUKI_CORE_ENUM_OBJECT_TYPE_HPP
#define FUBUKI_CORE_ENUM_OBJECT_TYPE_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_0)

/// Returns a std::string_view corresponding to a VkObjectType.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkObjectType e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_UNKNOWN);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_INSTANCE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PHYSICAL_DEVICE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DEVICE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_QUEUE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SEMAPHORE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_COMMAND_BUFFER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_FENCE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DEVICE_MEMORY);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_BUFFER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_IMAGE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_EVENT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_QUERY_POOL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_BUFFER_VIEW);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_IMAGE_VIEW);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SHADER_MODULE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PIPELINE_CACHE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PIPELINE_LAYOUT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_RENDER_PASS);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PIPELINE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SAMPLER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DESCRIPTOR_POOL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DESCRIPTOR_SET);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_FRAMEBUFFER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_COMMAND_POOL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_KHR_surface) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SURFACE_KHR);
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_swapchain) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SWAPCHAIN_KHR);
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_display) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DISPLAY_KHR);
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DISPLAY_MODE_KHR);
#endif // #if defined (VK_KHR_display)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_KHR_video_queue) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_VIDEO_SESSION_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_NVX_binary_import) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_CU_MODULE_NVX);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_CU_FUNCTION_NVX);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_KHR_descriptor_update_template) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR);
#endif // #if defined (VK_KHR_descriptor_update_template)

#if defined(VK_EXT_debug_utils) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT);
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_KHR_acceleration_structure) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_EXT_validation_cache) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_VALIDATION_CACHE_EXT);
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_NV_ray_tracing) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_INTEL_performance_query) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL);
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_KHR_deferred_host_operations) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR);
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_EXT_private_data) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT);
#endif // #if defined (VK_EXT_private_data)

#if defined(VK_NV_cuda_kernel_launch) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_CUDA_MODULE_NV);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_CUDA_FUNCTION_NV);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_FUCHSIA_buffer_collection) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_EXT_opacity_micromap) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_MICROMAP_EXT);
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_NV_optical_flow) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV);
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_EXT_shader_object) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SHADER_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_KHR_pipeline_binary) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_PIPELINE_BINARY_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_NV_external_sci_sync2) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_SEMAPHORE_SCI_SYNC_POOL_NV);
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_EXT_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

        FUBUKI_MAKE_CASE(VK_OBJECT_TYPE_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkObjectType.
[[nodiscard]] inline auto to_string(VkObjectType e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_0)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_OBJECT_TYPE_HPP
