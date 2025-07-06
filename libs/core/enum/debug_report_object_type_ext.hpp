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

#ifndef FUBUKI_CORE_ENUM_DEBUG_REPORT_OBJECT_TYPE_EXT_HPP
#define FUBUKI_CORE_ENUM_DEBUG_REPORT_OBJECT_TYPE_EXT_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_EXT_debug_marker)

/// Returns a std::string_view corresponding to a VkDebugReportObjectTypeEXT.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkDebugReportObjectTypeEXT e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) && !(defined(VK_EXT_debug_report))
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) && !(defined(VK_EXT_debug_report))
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_NVX_binary_import) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT);
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_KHR_descriptor_update_template) && !(defined(VK_EXT_debug_report))
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR_EXT);
#endif // #if defined (VK_KHR_descriptor_update_template)

#if defined(VK_KHR_acceleration_structure) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_sampler_ycbcr_conversion) && !(defined(VK_EXT_debug_report))
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR_EXT);
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_NV_ray_tracing) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_cuda_kernel_launch) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_MODULE_NV_EXT);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_FUNCTION_NV_EXT);
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_FUCHSIA_buffer_collection) 
        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT);
#endif // #if defined (VK_FUCHSIA_buffer_collection)

        FUBUKI_MAKE_CASE(VK_DEBUG_REPORT_OBJECT_TYPE_MAX_ENUM_EXT);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkDebugReportObjectTypeEXT.
[[nodiscard]] inline auto to_string(VkDebugReportObjectTypeEXT e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_EXT_debug_marker)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_DEBUG_REPORT_OBJECT_TYPE_EXT_HPP
