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

#ifndef FUBUKI_EXTENSION_KHR_GET_DISPLAY_PROPERTIES2_HPP
#define FUBUKI_EXTENSION_KHR_GET_DISPLAY_PROPERTIES2_HPP

#include <vector>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_get_display_properties2.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_get_display_properties2
{

#if defined(VK_KHR_get_display_properties2)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDisplayPlaneCapabilities2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info> get_display_plane_capabilities(const functions&                ext,
                                                                                               physical_device_handle          physical_device,
                                                                                               const VkDisplayPlaneInfo2KHR&   display_plane_info,
                                                                                               VkDisplayPlaneCapabilities2KHR& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceDisplayProperties2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkDisplayProperties2KHR>, api_call_info>
                                   get_physical_device_display_properties(const functions& ext, physical_device_handle physical_device);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceDisplayPlaneProperties2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkDisplayPlaneProperties2KHR>, api_call_info>
                                   get_physical_device_display_plane_properties(const functions& ext, physical_device_handle physical_device);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDisplayModeProperties2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkDisplayModeProperties2KHR>, api_call_info>
get_display_mode_properties(const functions& ext, physical_device_handle physical_device, display_khr_handle display);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDisplayPlaneCapabilities2KHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkDisplayPlaneCapabilities2KHR, api_call_info>
get_display_plane_capabilities(const functions&                ext,
                               physical_device_handle          physical_device,
                               const VkDisplayPlaneInfo2KHR&   display_plane_info,
                               const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkDisplayPlaneCapabilities2KHR>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_display_plane_capabilities(ext, physical_device, display_plane_info, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDisplayPlaneCapabilities2KHR.html
[[nodiscard]] inline auto get_display_plane_capabilities(const functions&              ext,
                                                         physical_device_handle        physical_device,
                                                         const VkDisplayPlaneInfo2KHR& display_plane_info) noexcept
{
    return get_display_plane_capabilities(ext, physical_device, display_plane_info, empty_pnext_chain);
}

#endif // defined(VK_KHR_get_display_properties2)

} // namespace fubuki::extension::khr_get_display_properties2

#endif // FUBUKI_EXTENSION_KHR_GET_DISPLAY_PROPERTIES2_HPP
