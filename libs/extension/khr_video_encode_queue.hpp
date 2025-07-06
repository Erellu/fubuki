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

#ifndef FUBUKI_EXTENSION_KHR_VIDEO_ENCODE_QUEUE_HPP
#define FUBUKI_EXTENSION_KHR_VIDEO_ENCODE_QUEUE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_video_encode_queue.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_video_encode_queue
{

#if defined(VK_KHR_video_encode_queue)

namespace detail
{

[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info>
                                   get_physical_device_video_encode_quality_level_properties(const functions&                                      ext,
                                                                                             physical_device_handle                                physical_device,
                                                                                             const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR& quality_level_info,
                                                                                             VkVideoEncodeQualityLevelPropertiesKHR&               result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkVideoEncodeQualityLevelPropertiesKHR, api_call_info>
get_physical_device_video_encode_quality_level_properties(const functions&                                      ext,
                                                          physical_device_handle                                physical_device,
                                                          const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR& quality_level_info,
                                                          const pnext_chain<elements...>&                       pnext) noexcept
{
    auto result = fubuki::make<VkVideoEncodeQualityLevelPropertiesKHR>();
    fubuki::extend(result, pnext);

    if(auto error = detail::get_physical_device_video_encode_quality_level_properties(ext, physical_device, quality_level_info, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR.html
[[nodiscard]] inline auto get_physical_device_video_encode_quality_level_properties(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR& quality_level_info) noexcept
{
    return get_physical_device_video_encode_quality_level_properties(ext, physical_device, quality_level_info, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetEncodedVideoSessionParametersKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<std::byte>, api_call_info> get_encoded_video_session_parameters(
    const functions& ext, device_handle device, const VkVideoEncodeSessionParametersGetInfoKHR& video_session_parameters_info);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetEncodedVideoSessionParametersKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<std::byte>, api_call_info>
                                   get_encoded_video_session_parameters(const functions&                                ext,
                                                                        device_handle                                   device,
                                                                        const VkVideoEncodeSessionParametersGetInfoKHR& video_session_parameters_info,
                                                                        VkVideoEncodeSessionParametersFeedbackInfoKHR&  feedback_info);

#endif // defined(VK_KHR_video_encode_queue)

namespace cmd
{

#if defined(VK_KHR_video_encode_queue)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEncodeVideoKHR.html
FUBUKI_EXTENSION_API
void encode_video(const functions& ext, command_buffer_handle command_buffer, const VkVideoEncodeInfoKHR& encode_info) noexcept;

#endif // defined(VK_KHR_video_encode_queue)

} // namespace cmd

} // namespace fubuki::extension::khr_video_encode_queue

#endif // FUBUKI_EXTENSION_KHR_VIDEO_ENCODE_QUEUE_HPP
