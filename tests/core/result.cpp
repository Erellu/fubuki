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

#include <array>
#include <ranges>
#include <utility>

#include <gtest/gtest.h>

#include <core/result.hpp>
#include <core/validate.hpp>

namespace
{

#define MAKE_VK_RESULT(x) std::pair<VkResult, std::string_view>(x, #x)

inline constexpr std::array vk_results = {
    MAKE_VK_RESULT(VK_SUCCESS),
#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_NOT_READY),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_TIMEOUT),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_EVENT_SET),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_EVENT_RESET),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_INCOMPLETE),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_OUT_OF_HOST_MEMORY),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_OUT_OF_DEVICE_MEMORY),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_INITIALIZATION_FAILED),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_DEVICE_LOST),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_MEMORY_MAP_FAILED),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_LAYER_NOT_PRESENT),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_EXTENSION_NOT_PRESENT),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_FEATURE_NOT_PRESENT),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_INCOMPATIBLE_DRIVER),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_TOO_MANY_OBJECTS),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_FORMAT_NOT_SUPPORTED),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_FRAGMENTED_POOL),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_UNKNOWN),
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
    MAKE_VK_RESULT(VK_ERROR_OUT_OF_POOL_MEMORY),
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
    MAKE_VK_RESULT(VK_ERROR_INVALID_EXTERNAL_HANDLE),
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    MAKE_VK_RESULT(VK_ERROR_FRAGMENTATION),
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
    MAKE_VK_RESULT(VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS),
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    MAKE_VK_RESULT(VK_PIPELINE_COMPILE_REQUIRED),
#endif // #if defined (VK_VERSION_1_3)

#if defined(VKSC_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_VALIDATION_FAILED),
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_INVALID_PIPELINE_CACHE_DATA),
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
    MAKE_VK_RESULT(VK_ERROR_NO_PIPELINE_MATCH),
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VK_KHR_surface)
    MAKE_VK_RESULT(VK_ERROR_SURFACE_LOST_KHR),
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_surface)
    MAKE_VK_RESULT(VK_ERROR_NATIVE_WINDOW_IN_USE_KHR),
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_swapchain)
    MAKE_VK_RESULT(VK_SUBOPTIMAL_KHR),
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
    MAKE_VK_RESULT(VK_ERROR_OUT_OF_DATE_KHR),
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_display_swapchain)
    MAKE_VK_RESULT(VK_ERROR_INCOMPATIBLE_DISPLAY_KHR),
#endif // #if defined (VK_KHR_display_swapchain)

#if defined(VK_EXT_debug_report)
    MAKE_VK_RESULT(VK_ERROR_VALIDATION_FAILED_EXT),
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_NV_glsl_shader)
    MAKE_VK_RESULT(VK_ERROR_INVALID_SHADER_NV),
#endif // #if defined (VK_NV_glsl_shader)

#if defined(VK_KHR_video_queue)
    MAKE_VK_RESULT(VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR),
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    MAKE_VK_RESULT(VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR),
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    MAKE_VK_RESULT(VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR),
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    MAKE_VK_RESULT(VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR),
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    MAKE_VK_RESULT(VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR),
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
    MAKE_VK_RESULT(VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR),
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_EXT_image_drm_format_modifier)
    MAKE_VK_RESULT(VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT),
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_KHR_global_priority)
    MAKE_VK_RESULT(VK_ERROR_NOT_PERMITTED_KHR),
#endif // #if defined (VK_KHR_global_priority)

#if defined(VK_EXT_full_screen_exclusive)
    MAKE_VK_RESULT(VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT),
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_KHR_deferred_host_operations)
    MAKE_VK_RESULT(VK_THREAD_IDLE_KHR),
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
    MAKE_VK_RESULT(VK_THREAD_DONE_KHR),
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
    MAKE_VK_RESULT(VK_OPERATION_DEFERRED_KHR),
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
    MAKE_VK_RESULT(VK_OPERATION_NOT_DEFERRED_KHR),
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_video_encode_queue)
    MAKE_VK_RESULT(VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR),
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_EXT_image_compression_control)
    MAKE_VK_RESULT(VK_ERROR_COMPRESSION_EXHAUSTED_EXT),
#endif // #if defined (VK_EXT_image_compression_control)

#if defined(VK_EXT_shader_object)
    MAKE_VK_RESULT(VK_INCOMPATIBLE_SHADER_BINARY_EXT),
#endif // #if defined (VK_EXT_shader_object)

};

#undef MAKE_VK_RESULT

TEST(result, to_string)
{
    for(const auto& [value, str] : vk_results)
    {
        // When an extension gets promotted from EXT to KHR or from KHR to core, the suffix changes, but not the result
        EXPECT_TRUE(str.starts_with(fubuki::to_string_view(value)));
        EXPECT_TRUE(std::string{str}.starts_with(fubuki::to_string(value)));
    }
}

TEST(result, result)
{
    for(const auto& [value, str] : vk_results)
    {
        const auto fvk_result = fubuki::result{value};

        const std::string      as_string      = fvk_result;
        const bool             as_bool        = fvk_result.operator bool();
        const VkResult         as_result      = fvk_result;
        const std::string_view as_string_view = fvk_result;

        EXPECT_TRUE((value == VK_SUCCESS and as_bool) or (value != VK_SUCCESS and not as_bool)) << "Failed for " << str << ": as_bool is " << as_bool;

        EXPECT_EQ(fvk_result.code, value) << "Failed for " << str;
        EXPECT_EQ(fvk_result.code, as_result) << "Failed for " << str;

        EXPECT_EQ(as_string_view, fubuki::to_string_view(value));
        EXPECT_EQ(as_string, fubuki::to_string(value));
    }
}

TEST(result, api_call_info)
{
    for(const auto& [value, str] : vk_results)
    {
        const fubuki::api_call_info call{.result = {.code = value}, .call_literal = {}, .location = std::source_location::current()};

        const auto fvk_result = fubuki::result{value};

        const VkResult as_result = call;

        EXPECT_EQ(static_cast<bool>(call), static_cast<bool>(fvk_result)) << "Failed for " << str;
        EXPECT_EQ(as_result, static_cast<VkResult>(fvk_result)) << "Failed for " << str;
        EXPECT_EQ(as_result, static_cast<VkResult>(call)) << "Failed for " << str;
        EXPECT_EQ(as_result, value) << "Failed for " << str;
    }
}

TEST(result, validate_call)
{
    for(const auto& [result, str] : vk_results | std::views::drop(1))
    {
        EXPECT_THROW(fubuki_validate(fubuki::validate_by::throw_call_exception, result), fubuki::api_call_exception) << "Failed for " << str;
    }

    EXPECT_NO_THROW(fubuki_validate(fubuki::validate_by::throw_call_exception, VK_SUCCESS)) << "Failed for VK_SUCCESS";
}

} // anonymous namespace
