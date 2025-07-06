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

#ifndef FUBUKI_EXTENSION_EXT_FULL_SCREEN_EXCLUSIVE_HPP
#define FUBUKI_EXTENSION_EXT_FULL_SCREEN_EXCLUSIVE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_full_screen_exclusive.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_full_screen_exclusive
{

#if defined(VK_EXT_full_screen_exclusive)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceSurfacePresentModes2EXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkPresentModeKHR>, api_call_info> get_physical_device_surface_present_modes(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceSurfaceInfo2KHR& surface_info);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkAcquireFullScreenExclusiveModeEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
acquire_full_screen_exclusive_mode(const functions& ext, device_handle device, swapchain_khr_handle swapchain) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseFullScreenExclusiveModeEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
release_full_screen_exclusive_mode(const functions& ext, device_handle device, swapchain_khr_handle swapchain) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceGroupSurfacePresentModes2EXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<VkDeviceGroupPresentModeFlagsKHR, api_call_info>
get_device_group_surface_present_modes(const functions& ext, device_handle device, const VkPhysicalDeviceSurfaceInfo2KHR& surface_info) noexcept;

#endif // defined(VK_EXT_full_screen_exclusive)

} // namespace fubuki::extension::ext_full_screen_exclusive

#endif // FUBUKI_EXTENSION_EXT_FULL_SCREEN_EXCLUSIVE_HPP
