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

#include "extension/khr_video_encode_queue.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_video_encode_queue
{

#if defined(VK_KHR_video_encode_queue)

namespace detail
{

[[nodiscard]]
std::optional<api_call_info>
get_physical_device_video_encode_quality_level_properties(const functions&                                      ext,
                                                          physical_device_handle                                physical_device,
                                                          const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR& quality_level_info,
                                                          VkVideoEncodeQualityLevelPropertiesKHR&               result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR">(ext, physical_device.vk, std::addressof(quality_level_info), std::addressof(result))); not check)
    {
        return check.error();
    }

    return {};
}

} // namespace detail

[[nodiscard]]
std::expected<std::vector<std::byte>, api_call_info> get_encoded_video_session_parameters(
    const functions& ext, device_handle device, const VkVideoEncodeSessionParametersGetInfoKHR& video_session_parameters_info)
{
    std::size_t size = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetEncodedVideoSessionParametersKHR">(ext, device.vk, &video_session_parameters_info, nullptr, &size, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<std::byte> result;
    result.resize(size);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetEncodedVideoSessionParametersKHR">(ext, device.vk, &video_session_parameters_info, nullptr, &size, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<std::vector<std::byte>, api_call_info>
get_encoded_video_session_parameters(const functions&                                ext,
                                     device_handle                                   device,
                                     const VkVideoEncodeSessionParametersGetInfoKHR& video_session_parameters_info,
                                     VkVideoEncodeSessionParametersFeedbackInfoKHR&  feedback_info)
{
    std::size_t size = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetEncodedVideoSessionParametersKHR">(ext, device.vk, &video_session_parameters_info, &feedback_info, &size, nullptr));
                                              not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<std::byte> result;
    result.resize(size);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetEncodedVideoSessionParametersKHR">(ext, device.vk, &video_session_parameters_info, &feedback_info, &size, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_KHR_video_encode_queue)

namespace cmd
{

#if defined(VK_KHR_video_encode_queue)

void encode_video(const functions& ext, command_buffer_handle command_buffer, const VkVideoEncodeInfoKHR& encode_info) noexcept
{
    return fubuki::invoke<"vkCmdEncodeVideoKHR">(ext, command_buffer.vk, &encode_info);
}

#endif // defined(VK_KHR_video_encode_queue)

} // namespace cmd

} // namespace fubuki::extension::khr_video_encode_queue
