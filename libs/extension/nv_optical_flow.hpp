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

#ifndef FUBUKI_EXTENSION_NV_OPTICAL_FLOW_HPP
#define FUBUKI_EXTENSION_NV_OPTICAL_FLOW_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_optical_flow.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_optical_flow
{

#if defined(VK_NV_optical_flow)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceOpticalFlowImageFormatsNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkOpticalFlowImageFormatPropertiesNV>, api_call_info>
                                   get_physical_device_optical_flow_image_formats(const functions&                      ext,
                                                                                  physical_device_handle                physical_device,
                                                                                  const VkOpticalFlowImageFormatInfoNV& optical_flow_image_format_info);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateOpticalFlowSessionNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<optical_flow_session_nv_handle, api_call_info> create_optical_flow_session(
    const functions& ext, device_handle device, const VkOpticalFlowSessionCreateInfoNV& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateOpticalFlowSessionNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<optical_flow_session_nv_handle, api_call_info>
create_optical_flow_session(const functions& ext, device_handle device, const VkOpticalFlowSessionCreateInfoNV& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyOpticalFlowSessionNV.html
FUBUKI_EXTENSION_API
void destroy_optical_flow_session(const functions&                ext,
                                  device_handle                   device,
                                  optical_flow_session_nv_handle& session,
                                  const VkAllocationCallbacks&    allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyOpticalFlowSessionNV.html
FUBUKI_EXTENSION_API
void destroy_optical_flow_session(const functions& ext, device_handle device, optical_flow_session_nv_handle& session) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkBindOpticalFlowSessionImageNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   bind_optical_flow_session_image(const functions&                   ext,
                                                                   device_handle                      device,
                                                                   optical_flow_session_nv_handle     session,
                                                                   VkOpticalFlowSessionBindingPointNV binding_point,
                                                                   image_view_handle                  view,
                                                                   VkImageLayout                      layout) noexcept;

#endif // defined(VK_NV_optical_flow)

namespace cmd
{

#if defined(VK_NV_optical_flow)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdOpticalFlowExecuteNV.html
FUBUKI_EXTENSION_API
void optical_flow_execute(const functions&                  ext,
                          command_buffer_handle             command_buffer,
                          optical_flow_session_nv_handle    session,
                          const VkOpticalFlowExecuteInfoNV& execute_info) noexcept;

#endif // defined(VK_NV_optical_flow)

} // namespace cmd

} // namespace fubuki::extension::nv_optical_flow

#endif // FUBUKI_EXTENSION_NV_OPTICAL_FLOW_HPP
