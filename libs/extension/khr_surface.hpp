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

#ifndef FUBUKI_EXTENSION_KHR_SURFACE_HPP
#define FUBUKI_EXTENSION_KHR_SURFACE_HPP

#include <cstdint>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/surface_data.hpp>
#include <core/traits/surface.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_surface.hpp" // IWYU pragma: export

/**
 * The VK_KHR_surface extension is an instance extension.
 * It introduces VkSurfaceKHR objects, which abstract native platform surface or window objects for use with Vulkan.
 * It also provides a way to determine whether a queue family in a physical device supports presenting to particular surface.
 * Separate extensions for each platform provide the mechanisms for creating VkSurfaceKHR objects, but once created they may be used
 * in this and other platform-independent extensions, in particular the VK_KHR_swapchain extension.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_KHR_surface.html
 */
namespace fubuki::extension::khr_surface
{

#if defined(VK_KHR_surface)

/// Creates a surface for an instance.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<surface_khr_handle, api_call_info>
create(const functions& ext, instance_handle instance, const traits::platform::surface::underlying& platform_info) noexcept;

//------------------------------------------------------------------------------

/// Creates a surface for an instance.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<surface_khr_handle, api_call_info> create(const functions&                             ext,
                                                                                           instance_handle                              instance,
                                                                                           const traits::platform::surface::underlying& platform_info,
                                                                                           const VkAllocationCallbacks& callbacks) noexcept;

//------------------------------------------------------------------------------

/// Destroys a surface for an instance.
FUBUKI_EXTENSION_API
void destroy(const functions& ext, instance_handle instance, surface_khr_handle& surface) noexcept;

//------------------------------------------------------------------------------

/// Destroys a surface for an instance.
FUBUKI_EXTENSION_API
void destroy(const functions& ext, instance_handle instance, surface_khr_handle& surface, const VkAllocationCallbacks& callbacks) noexcept;

/// Returns a surface capabilities.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<VkSurfaceCapabilitiesKHR, api_call_info>
                                   capabilities(const functions& ext, physical_device_handle device, surface_khr_handle surface) noexcept;

/// Returns the formats supported by a surface.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkSurfaceFormatKHR>, api_call_info>
                                   formats(const functions& ext, physical_device_handle device, surface_khr_handle surface);

/// Returns all presentation modes supported by a surface.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkPresentModeKHR>, api_call_info>
                                   present_modes(const functions& ext, physical_device_handle device, surface_khr_handle surface);

/// Indicates if a queue family supports present operations.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<bool, api_call_info>
support(const functions& ext, physical_device_handle device, surface_khr_handle surface, std::uint32_t queue_family_index) noexcept;

#endif // defined(VK_KHR_surface)

} // namespace fubuki::extension::khr_surface

#endif // FUBUKI_EXTENSION_KHR_SURFACE_HPP
