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

#include "extension/khr_display.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::khr_display
{

#if defined(VK_KHR_display)

namespace
{

[[nodiscard]]
std::expected<display_mode_khr_handle, api_call_info> create_display_mode(const functions&                  ext,
                                                                          physical_device_handle            physical_device,
                                                                          display_khr_handle                display,
                                                                          const VkDisplayModeCreateInfoKHR& create_info,
                                                                          const VkAllocationCallbacks*      allocator) noexcept
{
    display_mode_khr_handle result = {};

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDisplayModeKHR">(ext, physical_device.vk, display.vk, &create_info, allocator, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<surface_khr_handle, api_call_info> create_display_plane_surface(const functions&                     ext,
                                                                              instance_handle                      instance,
                                                                              const VkDisplaySurfaceCreateInfoKHR& create_info,
                                                                              const VkAllocationCallbacks*         allocator) noexcept
{
    surface_khr_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDisplayPlaneSurfaceKHR">(ext, instance.vk, &create_info, allocator, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // namespace

[[nodiscard]]
std::expected<small_vector<VkDisplayPropertiesKHR>, api_call_info> get_physical_device_display_properties(const functions&       ext,
                                                                                                          physical_device_handle physical_device)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayPropertiesKHR">(ext, physical_device.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkDisplayPropertiesKHR> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayPropertiesKHR">(ext, physical_device.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<small_vector<VkDisplayPlanePropertiesKHR>, api_call_info>
get_physical_device_display_plane_properties(const functions& ext, physical_device_handle physical_device)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayPlanePropertiesKHR">(ext, physical_device.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkDisplayPlanePropertiesKHR> result;
    result.resize(count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceDisplayPlanePropertiesKHR">(ext, physical_device.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<small_vector<display_khr_handle>, api_call_info>
get_display_plane_supported_displays(const functions& ext, physical_device_handle physical_device, std::uint32_t plane_index)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayPlaneSupportedDisplaysKHR">(ext, physical_device.vk, plane_index, &count, nullptr));
                                              not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkDisplayKHR> displays;
    displays.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayPlaneSupportedDisplaysKHR">(ext, physical_device.vk, plane_index, &count, displays.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<display_khr_handle>{displays.begin(), displays.end()};
}

[[nodiscard]]
std::expected<small_vector<VkDisplayModePropertiesKHR>, api_call_info>
get_display_mode_properties(const functions& ext, physical_device_handle physical_device, display_khr_handle display)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayModePropertiesKHR">(ext, physical_device.vk, display.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkDisplayModePropertiesKHR> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayModePropertiesKHR">(ext, physical_device.vk, display.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<display_mode_khr_handle, api_call_info> create_display_mode(const functions&                  ext,
                                                                          physical_device_handle            physical_device,
                                                                          display_khr_handle                display,
                                                                          const VkDisplayModeCreateInfoKHR& create_info,
                                                                          const VkAllocationCallbacks&      allocator) noexcept
{
    return create_display_mode(ext, physical_device, display, create_info, std::addressof(allocator));
}

[[nodiscard]]
std::expected<display_mode_khr_handle, api_call_info> create_display_mode(const functions&                  ext,
                                                                          physical_device_handle            physical_device,
                                                                          display_khr_handle                display,
                                                                          const VkDisplayModeCreateInfoKHR& create_info) noexcept
{
    return create_display_mode(ext, physical_device, display, create_info, nullptr);
}

[[nodiscard]]
std::expected<VkDisplayPlaneCapabilitiesKHR, api_call_info> get_display_plane_capabilities(const functions&        ext,
                                                                                           physical_device_handle  physical_device,
                                                                                           display_mode_khr_handle mode,
                                                                                           std::uint32_t           plane_index) noexcept
{
    VkDisplayPlaneCapabilitiesKHR result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDisplayPlaneCapabilitiesKHR">(ext, physical_device.vk, mode.vk, plane_index, &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<surface_khr_handle, api_call_info> create_display_plane_surface(const functions&                     ext,
                                                                              instance_handle                      instance,
                                                                              const VkDisplaySurfaceCreateInfoKHR& create_info,
                                                                              const VkAllocationCallbacks&         allocator) noexcept
{
    return create_display_plane_surface(ext, instance, create_info, std::addressof(allocator));
}

[[nodiscard]]
std::expected<surface_khr_handle, api_call_info>
create_display_plane_surface(const functions& ext, instance_handle instance, const VkDisplaySurfaceCreateInfoKHR& create_info) noexcept
{
    return create_display_plane_surface(ext, instance, create_info, nullptr);
}

#endif // defined(VK_KHR_display)

} // namespace fubuki::extension::khr_display
