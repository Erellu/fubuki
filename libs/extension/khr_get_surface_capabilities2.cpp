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

#include "extension/khr_get_surface_capabilities2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_get_surface_capabilities2
{

#if defined(VK_KHR_get_surface_capabilities2)

namespace detail
{

[[nodiscard]]
std::optional<api_call_info> get_physical_device_surface_capabilities2(const functions&                       ext,
                                                                       physical_device_handle                 physical_device,
                                                                       const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                                                       VkSurfaceCapabilities2KHR&             result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfaceCapabilities2KHR">(ext, physical_device.vk, &surface_info, &result));
                                              not check)
    {
        return check.error();
    }

    return {};
}

} // namespace detail

[[nodiscard]]
std::expected<std::vector<VkSurfaceFormat2KHR>, api_call_info> get_physical_device_surface_formats2(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceSurfaceInfo2KHR& surface_info)
{
    std::uint32_t count = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfaceFormats2KHR">(ext, physical_device.vk, &surface_info, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkSurfaceFormat2KHR> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceSurfaceFormats2KHR">(ext, physical_device.vk, &surface_info, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_KHR_get_surface_capabilities2)

} // namespace fubuki::extension::khr_get_surface_capabilities2
