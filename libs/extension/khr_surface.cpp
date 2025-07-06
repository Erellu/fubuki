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

#include "extension/khr_surface.hpp"

#include <core/invoke.hpp>
#include <core/traits/surface.hpp>

namespace fubuki::extension::khr_surface
{

#if defined(VK_KHR_surface)

[[nodiscard]]
std::expected<surface_khr_handle, api_call_info>
create(const functions& ext, instance_handle instance, const traits::platform::surface::underlying& platform_info) noexcept
{
    fubuki_assert(ext.create_surface_khr != nullptr, "Extension must be loaded.");

    surface_khr_handle surface{};

    if(const auto check
       = fubuki_validate(validate_by::expected, ext.create_surface_khr(instance, platform_info, nullptr, std::addressof(surface.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return surface;
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<surface_khr_handle, api_call_info> create(const functions&                             ext,
                                                        instance_handle                              instance,
                                                        const traits::platform::surface::underlying& platform_info,
                                                        const VkAllocationCallbacks&                 callbacks) noexcept
{
    fubuki_assert(ext.create_surface_khr != nullptr, "Extension must be loaded.");

    surface_khr_handle surface{};

    if(const auto check = fubuki_validate(validate_by::expected, ext.create_surface_khr(instance, platform_info, std::addressof(callbacks), std::addressof(surface.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return surface;
}

//------------------------------------------------------------------------------

void destroy(const functions& ext, instance_handle instance, surface_khr_handle& surface) noexcept
{
    fubuki::invoke<"vkDestroySurfaceKHR">(ext, instance.vk, surface.vk, nullptr);
    surface = null_handle;
}

//------------------------------------------------------------------------------

void destroy(const functions& ext, instance_handle instance, surface_khr_handle& surface, const VkAllocationCallbacks& callbacks) noexcept
{
    fubuki::invoke<"vkDestroySurfaceKHR">(ext, instance.vk, surface.vk, &callbacks);
    surface = null_handle;
}

/********************************************************************************/
/*                                PROPERTIES                                    */
/********************************************************************************/

[[nodiscard]]
std::expected<VkSurfaceCapabilitiesKHR, api_call_info>
capabilities(const functions& ext, physical_device_handle device, surface_khr_handle surface) noexcept
{
    VkSurfaceCapabilitiesKHR capabilities;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfaceCapabilitiesKHR">(ext, device.vk, surface.vk, std::addressof(capabilities))); not check)
    {
        return std::unexpected{check.error()};
    }

    return capabilities;
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<small_vector<VkSurfaceFormatKHR>, api_call_info>
formats(const functions& ext, physical_device_handle device, surface_khr_handle surface)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfaceFormatsKHR">(ext, device.vk, surface.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkSurfaceFormatKHR> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfaceFormatsKHR">(ext, device.vk, surface.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<small_vector<VkPresentModeKHR>, api_call_info>
present_modes(const functions& ext, physical_device_handle device, surface_khr_handle surface)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfacePresentModesKHR">(ext, device.vk, surface.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkPresentModeKHR> result;
    result.resize(static_cast<std::size_t>(count));

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfacePresentModesKHR">(ext, device.vk, surface.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<bool, api_call_info>
support(const functions& ext, physical_device_handle device, surface_khr_handle surface, std::uint32_t queue_family_index) noexcept
{
    VkBool32 result = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfaceSupportKHR">(ext, device.vk, queue_family_index, surface.vk, &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return static_cast<bool>(result);
}

#endif // defined(VK_KHR_surface)

} // namespace fubuki::extension::khr_surface
