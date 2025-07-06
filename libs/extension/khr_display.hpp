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

#ifndef FUBUKI_EXTENSION_KHR_DISPLAY_HPP
#define FUBUKI_EXTENSION_KHR_DISPLAY_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_display.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_display
{

#if defined(VK_KHR_display)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceDisplayPropertiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkDisplayPropertiesKHR>, api_call_info>
                                   get_physical_device_display_properties(const functions& ext, physical_device_handle physical_device);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceDisplayPlanePropertiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkDisplayPlanePropertiesKHR>, api_call_info>
                                   get_physical_device_display_plane_properties(const functions& ext, physical_device_handle physical_device);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDisplayPlaneSupportedDisplaysKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<display_khr_handle>, api_call_info>
get_display_plane_supported_displays(const functions& ext, physical_device_handle physical_device, std::uint32_t plane_index);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDisplayModePropertiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkDisplayModePropertiesKHR>, api_call_info>
get_display_mode_properties(const functions& ext, physical_device_handle physical_device, display_khr_handle display);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateDisplayModeKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<display_mode_khr_handle, api_call_info>
                                   create_display_mode(const functions&                  ext,
                                                       physical_device_handle            physical_device,
                                                       display_khr_handle                display,
                                                       const VkDisplayModeCreateInfoKHR& create_info,
                                                       const VkAllocationCallbacks&      allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateDisplayModeKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<display_mode_khr_handle, api_call_info> create_display_mode(
    const functions& ext, physical_device_handle physical_device, display_khr_handle display, const VkDisplayModeCreateInfoKHR& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDisplayPlaneCapabilitiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<VkDisplayPlaneCapabilitiesKHR, api_call_info> get_display_plane_capabilities(
    const functions& ext, physical_device_handle physical_device, display_mode_khr_handle mode, std::uint32_t plane_index) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateDisplayPlaneSurfaceKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<surface_khr_handle, api_call_info>
                                   create_display_plane_surface(const functions&                     ext,
                                                                instance_handle                      instance,
                                                                const VkDisplaySurfaceCreateInfoKHR& create_info,
                                                                const VkAllocationCallbacks&         allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateDisplayPlaneSurfaceKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<surface_khr_handle, api_call_info>
create_display_plane_surface(const functions& ext, instance_handle instance, const VkDisplaySurfaceCreateInfoKHR& create_info) noexcept;

#endif // defined(VK_KHR_display)

} // namespace fubuki::extension::khr_display

#endif // FUBUKI_EXTENSION_KHR_DISPLAY_HPP
