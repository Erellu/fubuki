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

#ifndef FUBUKI_EXTENSION_KHR_VIDEO_QUEUE_HPP
#define FUBUKI_EXTENSION_KHR_VIDEO_QUEUE_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_video_queue.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_video_queue
{

#if defined(VK_KHR_video_queue)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceVideoCapabilitiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info> get_physical_device_video_capabilities(const functions&             ext,
                                                                                                       physical_device_handle       physical_device,
                                                                                                       const VkVideoProfileInfoKHR& video_profile,
                                                                                                       VkVideoCapabilitiesKHR&      result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceVideoCapabilitiesKHR.html
template<typename... pnext_elements>
[[nodiscard]] inline std::expected<VkVideoCapabilitiesKHR, api_call_info>
get_physical_device_video_capabilities(const functions&                     ext,
                                       physical_device_handle               physical_device,
                                       const VkVideoProfileInfoKHR&         video_profile,
                                       const pnext_chain<pnext_elements...> chain) noexcept
{
    auto result = fubuki::make<VkVideoCapabilitiesKHR>();
    extend(result, chain);

    if(auto error = detail::get_physical_device_video_capabilities(ext, physical_device, video_profile, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceVideoCapabilitiesKHR.html
[[nodiscard]] inline std::expected<VkVideoCapabilitiesKHR, api_call_info> get_physical_device_video_capabilities(
    const functions& ext, physical_device_handle physical_device, const VkVideoProfileInfoKHR& video_profile) noexcept
{
    return get_physical_device_video_capabilities(ext, physical_device, video_profile, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceVideoFormatPropertiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkVideoFormatPropertiesKHR>, api_call_info> get_physical_device_video_format_properties(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceVideoFormatInfoKHR& video_format_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateVideoSessionKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<video_session_khr_handle, api_call_info> create_video_session(
    const functions& ext, device_handle device, const VkVideoSessionCreateInfoKHR& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateVideoSessionKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<video_session_khr_handle, api_call_info>
create_video_session(const functions& ext, device_handle device, const VkVideoSessionCreateInfoKHR& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyVideoSessionKHR.html
FUBUKI_EXTENSION_API
void destroy_video_session(const functions&             ext,
                           device_handle                device,
                           video_session_khr_handle     video_session,
                           const VkAllocationCallbacks* p_allocator);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyVideoSessionKHR.html
FUBUKI_EXTENSION_API
void destroy_video_session(const functions& ext, device_handle device, video_session_khr_handle& video_session);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetVideoSessionMemoryRequirementsKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkVideoSessionMemoryRequirementsKHR>, api_call_info>
get_video_session_memory_requirements(const functions& ext, device_handle device, video_session_khr_handle video_session);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkBindVideoSessionMemoryKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   bind_video_session_memory(const functions&                                 ext,
                                                             device_handle                                    device,
                                                             video_session_khr_handle                         video_session,
                                                             std::span<const VkBindVideoSessionMemoryInfoKHR> infos) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkBindVideoSessionMemoryKHR.html
[[nodiscard]] inline std::expected<void, api_call_info>
bind_video_session_memory(const functions&                                       ext,
                          device_handle                                          device,
                          video_session_khr_handle                               video_session,
                          std::initializer_list<VkBindVideoSessionMemoryInfoKHR> infos) noexcept
{
    return bind_video_session_memory(ext, device, video_session, std::span{infos});
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateVideoSessionParametersKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<video_session_parameters_khr_handle, api_call_info>
                                   create_video_session_parameters(const functions&                             ext,
                                                                   device_handle                                device,
                                                                   const VkVideoSessionParametersCreateInfoKHR& create_info,
                                                                   const VkAllocationCallbacks&                 allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateVideoSessionParametersKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<video_session_parameters_khr_handle, api_call_info>
create_video_session_parameters(const functions& ext, device_handle device, const VkVideoSessionParametersCreateInfoKHR& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateVideoSessionParametersKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   update_video_session_parameters(const functions&                             ext,
                                                                   device_handle                                device,
                                                                   video_session_parameters_khr_handle          video_session_parameters,
                                                                   const VkVideoSessionParametersUpdateInfoKHR& update_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyVideoSessionParametersKHR.html
FUBUKI_EXTENSION_API
void destroy_video_session_parameters(const functions&                     ext,
                                      device_handle                        device,
                                      video_session_parameters_khr_handle& video_session_parameters,
                                      const VkAllocationCallbacks&         allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyVideoSessionParametersKHR.html
FUBUKI_EXTENSION_API
void destroy_video_session_parameters(const functions&                     ext,
                                      device_handle                        device,
                                      video_session_parameters_khr_handle& video_session_parameters) noexcept;

#endif // defined(VK_KHR_video_queue)

namespace cmd
{

#if defined(VK_KHR_video_queue)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginVideoCodingKHR.html
FUBUKI_EXTENSION_API
void begin_video_coding(const functions& ext, command_buffer_handle command_buffer, const VkVideoBeginCodingInfoKHR& begin_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndVideoCodingKHR.html
FUBUKI_EXTENSION_API
void end_video_coding(const functions& ext, command_buffer_handle command_buffer, const VkVideoEndCodingInfoKHR& end_coding_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdControlVideoCodingKHR.html
FUBUKI_EXTENSION_API
void control_video_coding(const functions&                   ext,
                          command_buffer_handle              command_buffer,
                          const VkVideoCodingControlInfoKHR& coding_control_info) noexcept;

#endif // defined(VK_KHR_video_queue)

} // namespace cmd

} // namespace fubuki::extension::khr_video_queue

#endif // FUBUKI_EXTENSION_KHR_VIDEO_QUEUE_HPP
