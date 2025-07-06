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

#include "extension/nv_optical_flow.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::nv_optical_flow
{

#if defined(VK_NV_optical_flow)

[[nodiscard]]
std::expected<std::vector<VkOpticalFlowImageFormatPropertiesNV>, api_call_info> get_physical_device_optical_flow_image_formats(
    const functions& ext, physical_device_handle physical_device, const VkOpticalFlowImageFormatInfoNV& optical_flow_image_format_info)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceOpticalFlowImageFormatsNV">(ext, physical_device.vk, &optical_flow_image_format_info, &count, nullptr));
                                              not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkOpticalFlowImageFormatPropertiesNV> result = {};
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected,
        fubuki::invoke<"vkGetPhysicalDeviceOpticalFlowImageFormatsNV">(ext, physical_device.vk, &optical_flow_image_format_info, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<optical_flow_session_nv_handle, api_call_info> create_optical_flow_session(const functions&                        ext,
                                                                                         device_handle                           device,
                                                                                         const VkOpticalFlowSessionCreateInfoNV& create_info,
                                                                                         const VkAllocationCallbacks&            allocator) noexcept
{
    optical_flow_session_nv_handle result = {};

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateOpticalFlowSessionNV">(ext, device.vk, std::addressof(create_info), std::addressof(allocator), std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<optical_flow_session_nv_handle, api_call_info>
create_optical_flow_session(const functions& ext, device_handle device, const VkOpticalFlowSessionCreateInfoNV& create_info) noexcept
{
    optical_flow_session_nv_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateOpticalFlowSessionNV">(ext, device.vk, &create_info, nullptr, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_optical_flow_session(const functions&                ext,
                                  device_handle                   device,
                                  optical_flow_session_nv_handle& session,
                                  const VkAllocationCallbacks&    allocator) noexcept
{
    fubuki::invoke<"vkDestroyOpticalFlowSessionNV">(ext, device.vk, session.vk, std::addressof(allocator));

    session = null_handle;
}

void destroy_optical_flow_session(const functions& ext, device_handle device, optical_flow_session_nv_handle& session) noexcept
{
    fubuki::invoke<"vkDestroyOpticalFlowSessionNV">(ext, device.vk, session.vk, nullptr);

    session = null_handle;
}

[[nodiscard]]
std::expected<void, api_call_info> bind_optical_flow_session_image(const functions&                   ext,
                                                                   device_handle                      device,
                                                                   optical_flow_session_nv_handle     session,
                                                                   VkOpticalFlowSessionBindingPointNV binding_point,
                                                                   image_view_handle                  view,
                                                                   VkImageLayout                      layout) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkBindOpticalFlowSessionImageNV">(ext, device.vk, session.vk, binding_point, view.vk, layout)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

#endif // defined(VK_NV_optical_flow)

namespace cmd
{

#if defined(VK_NV_optical_flow)

void optical_flow_execute(const functions&                  ext,
                          command_buffer_handle             command_buffer,
                          optical_flow_session_nv_handle    session,
                          const VkOpticalFlowExecuteInfoNV& execute_info) noexcept
{
    return fubuki::invoke<"vkCmdOpticalFlowExecuteNV">(ext, command_buffer.vk, session.vk, &execute_info);
}

#endif // defined(VK_NV_optical_flow)

} // namespace cmd

} // namespace fubuki::extension::nv_optical_flow
