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

#ifndef FUBUKI_EXTENSION_EXT_DISPLAY_SURFACE_COUNTER_HPP
#define FUBUKI_EXTENSION_EXT_DISPLAY_SURFACE_COUNTER_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_display_surface_counter.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_display_surface_counter
{

#if defined(VK_EXT_display_surface_counter)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceSurfaceCapabilities2EXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info> get_physical_device_surface_capabilities(const functions&           ext,
                                                                                                         physical_device_handle     physical_device,
                                                                                                         surface_khr_handle         surface,
                                                                                                         VkSurfaceCapabilities2EXT& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceSurfaceCapabilities2EXT.html
template<typename... elements>
std::expected<VkSurfaceCapabilities2EXT, api_call_info> get_physical_device_surface_capabilities(const functions&                ext,
                                                                                                 physical_device_handle          physical_device,
                                                                                                 surface_khr_handle              surface,
                                                                                                 const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkSurfaceCapabilities2EXT>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_physical_device_surface_capabilities(ext, physical_device, surface, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceSurfaceCapabilities2EXT.html
[[nodiscard]] inline auto
get_physical_device_surface_capabilities(const functions& ext, physical_device_handle physical_device, surface_khr_handle surface)
{
    return get_physical_device_surface_capabilities(ext, physical_device, surface, empty_pnext_chain);
}

#endif // defined(VK_EXT_display_surface_counter)

} // namespace fubuki::extension::ext_display_surface_counter

#endif // FUBUKI_EXTENSION_EXT_DISPLAY_SURFACE_COUNTER_HPP
