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

#include "extension/functions/khr_display.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
khr_display khr_display::load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");

    // clang-format off
    return
    {
#if defined(VK_KHR_display)
        .get_physical_device_display_properties_khr = pfn<"vkGetPhysicalDeviceDisplayPropertiesKHR">(instance),
        .get_physical_device_display_plane_properties_khr = pfn<"vkGetPhysicalDeviceDisplayPlanePropertiesKHR">(instance),
        .get_display_plane_supported_displays_khr = pfn<"vkGetDisplayPlaneSupportedDisplaysKHR">(instance),
        .get_display_mode_properties_khr = pfn<"vkGetDisplayModePropertiesKHR">(instance),
        .create_display_mode_khr = pfn<"vkCreateDisplayModeKHR">(instance),
        .get_display_plane_capabilities_khr = pfn<"vkGetDisplayPlaneCapabilitiesKHR">(instance),
        .create_display_plane_surface_khr = pfn<"vkCreateDisplayPlaneSurfaceKHR">(instance),

        .cmd =
        {

        },
#endif // defined(VK_KHR_display)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
