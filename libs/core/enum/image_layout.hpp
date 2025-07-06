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

#ifndef FUBUKI_CORE_ENUM_IMAGE_LAYOUT_HPP
#define FUBUKI_CORE_ENUM_IMAGE_LAYOUT_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_0)

/// Returns a std::string_view corresponding to a VkImageLayout.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkImageLayout e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_UNDEFINED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_GENERAL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_PREINITIALIZED);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL);
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_KHR_swapchain) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_video_decode_queue) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR);
#endif // #if defined (VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR);
#endif // #if defined (VK_KHR_video_decode_queue)

#if defined(VK_KHR_video_decode_queue) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR);
#endif // #if defined (VK_KHR_video_decode_queue)

#if defined(VK_KHR_shared_presentable_image) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR);
#endif // #if defined (VK_KHR_shared_presentable_image)

#if defined(VK_KHR_maintenance2) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_maintenance2)

#if defined(VK_KHR_maintenance2) && !(defined(VK_VERSION_1_1))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_maintenance2)

#if defined(VK_NV_shading_rate_image) && !(defined(VK_KHR_fragment_shading_rate))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV);
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_EXT_fragment_density_map) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT);
#endif // #if defined (VK_EXT_fragment_density_map)

#if defined(VK_KHR_fragment_shading_rate) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_dynamic_rendering_local_read) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ_KHR);
#endif // #if defined (VK_KHR_dynamic_rendering_local_read)

#if defined(VK_KHR_separate_depth_stencil_layouts) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_separate_depth_stencil_layouts)

#if defined(VK_KHR_separate_depth_stencil_layouts) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_separate_depth_stencil_layouts)

#if defined(VK_KHR_separate_depth_stencil_layouts) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_separate_depth_stencil_layouts)

#if defined(VK_KHR_separate_depth_stencil_layouts) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_separate_depth_stencil_layouts)

#if defined(VK_KHR_video_encode_queue) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR);
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_synchronization2) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR);
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_EXT_attachment_feedback_loop_layout) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT);
#endif // #if defined (VK_EXT_attachment_feedback_loop_layout)

#if defined(VK_KHR_video_encode_quantization_map) 
        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_VIDEO_ENCODE_QUANTIZATION_MAP_KHR);
#endif // #if defined (VK_KHR_video_encode_quantization_map)

        FUBUKI_MAKE_CASE(VK_IMAGE_LAYOUT_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkImageLayout.
[[nodiscard]] inline auto to_string(VkImageLayout e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_0)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_IMAGE_LAYOUT_HPP
