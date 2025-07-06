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

#ifndef FUBUKI_EXTENSION_EXT_DISPLAY_CONTROL_HPP
#define FUBUKI_EXTENSION_EXT_DISPLAY_CONTROL_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_display_control.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_display_control
{

#if defined(VK_EXT_display_control)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDisplayPowerControlEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> display_power_control(const functions&             ext,
                                                                                            device_handle                device,
                                                                                            display_khr_handle           display,
                                                                                            const VkDisplayPowerInfoEXT& display_power_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkRegisterDeviceEventEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<fence_handle, api_call_info>
register_device_event(const functions& ext, device_handle device, const VkDeviceEventInfoEXT& device_event_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkRegisterDeviceEventEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<fence_handle, api_call_info> register_device_event(const functions&             ext,
                                                                                                    device_handle                device,
                                                                                                    const VkDeviceEventInfoEXT&  device_event_info,
                                                                                                    const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkRegisterDisplayEventEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<fence_handle, api_call_info> register_display_event(
    const functions& ext, device_handle device, display_khr_handle display, const VkDisplayEventInfoEXT& display_event_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkRegisterDisplayEventEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<fence_handle, api_call_info> register_display_event(const functions&             ext,
                                                                                                     device_handle                device,
                                                                                                     display_khr_handle           display,
                                                                                                     const VkDisplayEventInfoEXT& display_event_info,
                                                                                                     const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetSwapchainCounterEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::uint64_t, api_call_info>
get_swapchain_counter(const functions& ext, device_handle device, swapchain_khr_handle swapchain, VkSurfaceCounterFlagBitsEXT counter) noexcept;

#endif // defined(VK_EXT_display_control)

} // namespace fubuki::extension::ext_display_control

#endif // FUBUKI_EXTENSION_EXT_DISPLAY_CONTROL_HPP
