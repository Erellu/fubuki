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

#ifndef FUBUKI_CORE_RESULT_HPP
#define FUBUKI_CORE_RESULT_HPP

#include <ostream>
#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

/// Returns a std::string_view corresponding to a VkResult.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkResult r) noexcept
{

#if defined(FUBUKI_MAKE_CASE)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_CASE(vk_result) \
    case vk_result: return #vk_result

    switch(r)
    {

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_SUCCESS);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_NOT_READY);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_TIMEOUT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_EVENT_SET);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_EVENT_RESET);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_INCOMPLETE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_OUT_OF_HOST_MEMORY);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_OUT_OF_DEVICE_MEMORY);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_INITIALIZATION_FAILED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_DEVICE_LOST);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_MEMORY_MAP_FAILED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_LAYER_NOT_PRESENT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_EXTENSION_NOT_PRESENT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_FEATURE_NOT_PRESENT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_INCOMPATIBLE_DRIVER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_TOO_MANY_OBJECTS);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_FORMAT_NOT_SUPPORTED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_FRAGMENTED_POOL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_UNKNOWN);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
        FUBUKI_MAKE_CASE(VK_ERROR_OUT_OF_POOL_MEMORY);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_EXTERNAL_HANDLE);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
        FUBUKI_MAKE_CASE(VK_ERROR_FRAGMENTATION);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
        FUBUKI_MAKE_CASE(VK_PIPELINE_COMPILE_REQUIRED);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
        FUBUKI_MAKE_CASE(VK_ERROR_NOT_PERMITTED);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VKSC_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_VALIDATION_FAILED);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_PIPELINE_CACHE_DATA);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
        FUBUKI_MAKE_CASE(VK_ERROR_NO_PIPELINE_MATCH);
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VK_KHR_surface)
        FUBUKI_MAKE_CASE(VK_ERROR_SURFACE_LOST_KHR);
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_surface)
        FUBUKI_MAKE_CASE(VK_ERROR_NATIVE_WINDOW_IN_USE_KHR);
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_swapchain)
        FUBUKI_MAKE_CASE(VK_SUBOPTIMAL_KHR);
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
        FUBUKI_MAKE_CASE(VK_ERROR_OUT_OF_DATE_KHR);
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_display_swapchain)
        FUBUKI_MAKE_CASE(VK_ERROR_INCOMPATIBLE_DISPLAY_KHR);
#endif // #if defined (VK_KHR_display_swapchain)

#if defined(VK_EXT_debug_report)
        FUBUKI_MAKE_CASE(VK_ERROR_VALIDATION_FAILED_EXT);
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_NV_glsl_shader)
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_SHADER_NV);
#endif // #if defined (VK_NV_glsl_shader)

#if defined(VK_KHR_video_queue)
        FUBUKI_MAKE_CASE(VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
        FUBUKI_MAKE_CASE(VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
        FUBUKI_MAKE_CASE(VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
        FUBUKI_MAKE_CASE(VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
        FUBUKI_MAKE_CASE(VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
        FUBUKI_MAKE_CASE(VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR);
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_maintenance1) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_ERROR_OUT_OF_POOL_MEMORY_KHR);
#endif // #if defined (VK_KHR_maintenance1)

#if defined(VK_KHR_external_memory) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR);
#endif // #if defined (VK_KHR_external_memory)

#if defined(VK_EXT_image_drm_format_modifier)
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT);
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_descriptor_indexing) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_ERROR_FRAGMENTATION_EXT);
#endif // #if defined (VK_EXT_descriptor_indexing)

#if defined(VK_EXT_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_ERROR_NOT_PERMITTED_EXT);
#endif // #if defined (VK_EXT_global_priority)

#if defined(VK_KHR_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_ERROR_NOT_PERMITTED_KHR);
#endif // #if defined (VK_KHR_global_priority)

#if defined(VK_EXT_buffer_device_address) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_DEVICE_ADDRESS_EXT);
#endif // #if defined (VK_EXT_buffer_device_address)

#if defined(VK_EXT_full_screen_exclusive)
        FUBUKI_MAKE_CASE(VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT);
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_KHR_buffer_device_address) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR);
#endif // #if defined (VK_KHR_buffer_device_address)

#if defined(VK_KHR_deferred_host_operations)
        FUBUKI_MAKE_CASE(VK_THREAD_IDLE_KHR);
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
        FUBUKI_MAKE_CASE(VK_THREAD_DONE_KHR);
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
        FUBUKI_MAKE_CASE(VK_OPERATION_DEFERRED_KHR);
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
        FUBUKI_MAKE_CASE(VK_OPERATION_NOT_DEFERRED_KHR);
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_EXT_pipeline_creation_cache_control) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_PIPELINE_COMPILE_REQUIRED_EXT);
#endif // #if defined (VK_EXT_pipeline_creation_cache_control)

#if defined(VK_EXT_pipeline_creation_cache_control) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT);
#endif // #if defined (VK_EXT_pipeline_creation_cache_control)

#if defined(VK_KHR_video_encode_queue)
        FUBUKI_MAKE_CASE(VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_EXT_image_compression_control)
        FUBUKI_MAKE_CASE(VK_ERROR_COMPRESSION_EXHAUSTED_EXT);
#endif // #if defined (VK_EXT_image_compression_control)

#if defined(VK_EXT_shader_object)
        FUBUKI_MAKE_CASE(VK_INCOMPATIBLE_SHADER_BINARY_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object) && !(defined(VK_EXT_shader_object))
        FUBUKI_MAKE_CASE(VK_ERROR_INCOMPATIBLE_SHADER_BINARY_EXT);
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_KHR_pipeline_binary)
        FUBUKI_MAKE_CASE(VK_PIPELINE_BINARY_MISSING_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
        FUBUKI_MAKE_CASE(VK_ERROR_NOT_ENOUGH_SPACE_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

        FUBUKI_MAKE_CASE(VK_RESULT_MAX_ENUM);

        default: return "";
    }

#undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkResult.
[[nodiscard]] inline auto to_string(VkResult r) { return std::string{to_string_view(r)}; }

//------------------------------------------------------------------------------

/// Vulkan result code.
struct result
{
    VkResult code = VK_ERROR_UNKNOWN; ///< Result code.

    /// Returns a human-readable string corresponding to the result.
    [[nodiscard]] operator std::string() const { return to_string(code); }

    /// Converts a result to a boolean. Converts to 'true' if, and only if the result is VK_SUCCESS.
    [[nodiscard]] explicit constexpr operator bool() const noexcept { return code == VK_SUCCESS; }

    /// Converts a result to the underlying Vulkan result code.
    [[nodiscard]] constexpr operator VkResult() const noexcept { return code; }

    /// Converts a result to a string_view representation of the Vulkan result code.
    [[nodiscard]] constexpr operator std::string_view() const noexcept { return to_string_view(code); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const result& r)
    {
        return out << to_string_view(r.code);
    }

    [[nodiscard]] friend constexpr auto operator<=>(const result&, const result&) = default;
    [[nodiscard]] friend constexpr bool operator==(const result&, const result&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const result&, const result&)  = default;
};

} // namespace fubuki

#endif // FUBUKI_CORE_RESULT_HPP
