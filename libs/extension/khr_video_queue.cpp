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

#include "extension/khr_video_queue.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::khr_video_queue
{

#if defined(VK_KHR_video_queue)

namespace detail
{

[[nodiscard]]
std::optional<api_call_info> get_physical_device_video_capabilities(const functions&             ext,
                                                                    physical_device_handle       physical_device,
                                                                    const VkVideoProfileInfoKHR& video_profile,
                                                                    VkVideoCapabilitiesKHR&      result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceVideoCapabilitiesKHR">(ext, physical_device.vk, &video_profile, &result)); not check)
    {
        return check.error();
    }

    return {};
}

} // namespace detail

[[nodiscard]]
std::expected<std::vector<VkVideoFormatPropertiesKHR>, api_call_info> get_physical_device_video_format_properties(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceVideoFormatInfoKHR& video_format_info) noexcept
{
    std::uint32_t count = 0;

    if(auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceVideoFormatPropertiesKHR">(ext, physical_device.vk, &video_format_info, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkVideoFormatPropertiesKHR> result;
    result.resize(count);

    if(auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceVideoFormatPropertiesKHR">(ext, physical_device.vk, &video_format_info, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<video_session_khr_handle, api_call_info> create_video_session(const functions&                   ext,
                                                                            device_handle                      device,
                                                                            const VkVideoSessionCreateInfoKHR& create_info,
                                                                            const VkAllocationCallbacks&       allocator) noexcept
{
    video_session_khr_handle result = {};

    if(auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateVideoSessionKHR">(ext, device.vk, &create_info, std::addressof(allocator), &result.vk));
                                                                              not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<video_session_khr_handle, api_call_info>
create_video_session(const functions& ext, device_handle device, const VkVideoSessionCreateInfoKHR& create_info) noexcept
{
    video_session_khr_handle result = {};

    if(auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateVideoSessionKHR">(ext, device.vk, std::addressof(create_info), nullptr, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_video_session(const functions&             ext,
                           device_handle                device,
                           video_session_khr_handle&    video_session,
                           const VkAllocationCallbacks& allocator)
{
    fubuki::invoke<"vkDestroyVideoSessionKHR">(ext, device.vk, video_session.vk, std::addressof(allocator));

    video_session = null_handle;
}

void destroy_video_session(const functions& ext, device_handle device, video_session_khr_handle& video_session)
{
    fubuki::invoke<"vkDestroyVideoSessionKHR">(ext, device.vk, video_session.vk, nullptr);

    video_session = null_handle;
}

[[nodiscard]]
std::expected<std::vector<VkVideoSessionMemoryRequirementsKHR>, api_call_info>
get_video_session_memory_requirements(const functions& ext, device_handle device, video_session_khr_handle video_session)
{
    std::uint32_t count = 0;

    if(auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetVideoSessionMemoryRequirementsKHR">(ext, device.vk, video_session.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkVideoSessionMemoryRequirementsKHR> result;
    result.resize(count);

    if(auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetVideoSessionMemoryRequirementsKHR">(ext, device.vk, video_session.vk, &count, result.data())) ; not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<void, api_call_info> bind_video_session_memory(const functions&                                 ext,
                                                             device_handle                                    device,
                                                             video_session_khr_handle                         video_session,
                                                             std::span<const VkBindVideoSessionMemoryInfoKHR> infos) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkBindVideoSessionMemoryKHR">(ext, device.vk, video_session.vk, vk_size(infos), infos.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<video_session_parameters_khr_handle, api_call_info>
create_video_session_parameters(const functions&                             ext,
                                device_handle                                device,
                                const VkVideoSessionParametersCreateInfoKHR& create_info,
                                const VkAllocationCallbacks&                 allocator) noexcept
{
    video_session_parameters_khr_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateVideoSessionParametersKHR">(ext, device.vk, std::addressof(create_info), std::addressof(allocator), &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<video_session_parameters_khr_handle, api_call_info>
create_video_session_parameters(const functions& ext, device_handle device, const VkVideoSessionParametersCreateInfoKHR& create_info) noexcept
{
    video_session_parameters_khr_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateVideoSessionParametersKHR">(ext, device.vk, std::addressof(create_info), nullptr, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<void, api_call_info> update_video_session_parameters(const functions&                             ext,
                                                                   device_handle                                device,
                                                                   video_session_parameters_khr_handle          video_session_parameters,
                                                                   const VkVideoSessionParametersUpdateInfoKHR& update_info) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkUpdateVideoSessionParametersKHR">(ext, device.vk, video_session_parameters.vk, std::addressof(update_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

void destroy_video_session_parameters(const functions&                     ext,
                                      device_handle                        device,
                                      video_session_parameters_khr_handle& video_session_parameters,
                                      const VkAllocationCallbacks&         allocator) noexcept
{
    fubuki::invoke<"vkDestroyVideoSessionParametersKHR">(ext, device.vk, video_session_parameters.vk, std::addressof(allocator));

    video_session_parameters = null_handle;
}

void destroy_video_session_parameters(const functions&                     ext,
                                      device_handle                        device,
                                      video_session_parameters_khr_handle& video_session_parameters) noexcept
{
    fubuki::invoke<"vkDestroyVideoSessionParametersKHR">(ext, device.vk, video_session_parameters.vk, nullptr);

    video_session_parameters = null_handle;
}

#endif // defined(VK_KHR_video_queue)

namespace cmd
{

#if defined(VK_KHR_video_queue)

void begin_video_coding(const functions& ext, command_buffer_handle command_buffer, const VkVideoBeginCodingInfoKHR& begin_info) noexcept
{
    return fubuki::invoke<"vkCmdBeginVideoCodingKHR">(ext, command_buffer.vk, &begin_info);
}

void end_video_coding(const functions& ext, command_buffer_handle command_buffer, const VkVideoEndCodingInfoKHR& end_coding_info) noexcept
{
    return fubuki::invoke<"vkCmdEndVideoCodingKHR">(ext, command_buffer.vk, &end_coding_info);
}

void control_video_coding(const functions& ext, command_buffer_handle command_buffer, const VkVideoCodingControlInfoKHR& coding_control_info) noexcept
{
    return fubuki::invoke<"vkCmdControlVideoCodingKHR">(ext, command_buffer.vk, &coding_control_info);
}

#endif // defined(VK_KHR_video_queue)

} // namespace cmd

} // namespace fubuki::extension::khr_video_queue
