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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#include <functional>
#include <unordered_map>
#include <unordered_set> // IWYU pragma: keep (Needed in instance, but not in device. However, it's simpler to generate both with the same template)

#include "extension/functions/instance_ext.hpp"

#include <core/vulkan.hpp>

namespace fubuki::extension
{

#if defined(FUBUKI_MAKE_LOADER)
    #error "Internal error. Must not be defined."
#endif

#define FUBUKI_MAKE_LOADER(ext_name)                                                                              \
    {ext_name::name,                                                                                              \
     [](instance_ext_functions& f, instance_handle i, version_number vk_ver)                                      \
     {                                                                                                            \
         if(f.ext_name == nullptr)                                                                                \
         {                                                                                                        \
             f.ext_name = std::make_unique<extension::ext_name::functions>(extension::ext_name::load(i, vk_ver)); \
         }                                                                                                        \
     }}

// Avoid the inlining of these functions, they make object code grow by A LOT
instance_functions::instance_functions()                                         = default;
instance_functions::~instance_functions()                                        = default;
instance_functions::instance_functions(instance_functions&&) noexcept            = default;
instance_functions& instance_functions::operator=(instance_functions&&) noexcept = default;

//------------------------------------------------------------------------------

[[nodiscard]]
bool load(instance_functions& functions, instance_handle instance, version_number version, std::string_view extension)
{
    using loader = std::function<void(instance_functions & functions, instance_handle instance, version_number version)>;

    static const std::unordered_set<std::string_view> surface_ext = {
        "VK_MVK_ios_surface",
        "VK_NN_vi_surface",
        "VK_EXT_metal_surface",
        "VK_KHR_win32_surface",
        "VK_KHR_xcb_surface",
        "VK_GGP_stream_descriptor_surface",
        "VK_MVK_macos_surface",
        "VK_FUCHSIA_imagepipe_surface",
        "VK_EXT_directfb_surface",
        "VK_KHR_wayland_surface",
        "VK_EXT_headless_surface",
        "VK_QNX_screen_surface",
        "VK_KHR_android_surface",
        "VK_KHR_xlib_surface",

    };

    if(surface_ext.contains(extension))
    {
        // The support for these extensions is embedded in VK_KHR_surface
        extension = "VK_KHR_surface";
    }

    // clang-format off
    static const std::unordered_map<std::string_view, loader> supported_extensions
    {
        FUBUKI_MAKE_LOADER(khr_surface),
        FUBUKI_MAKE_LOADER(khr_display),
        FUBUKI_MAKE_LOADER(ext_debug_report),
        FUBUKI_MAKE_LOADER(nv_external_memory_capabilities),
        FUBUKI_MAKE_LOADER(khr_get_physical_device_properties2),
        FUBUKI_MAKE_LOADER(ext_validation_flags),
        FUBUKI_MAKE_LOADER(khr_device_group_creation),
        FUBUKI_MAKE_LOADER(khr_external_memory_capabilities),
        FUBUKI_MAKE_LOADER(khr_external_semaphore_capabilities),
        FUBUKI_MAKE_LOADER(ext_direct_mode_display),
        FUBUKI_MAKE_LOADER(ext_acquire_xlib_display),
        FUBUKI_MAKE_LOADER(ext_display_surface_counter),
        FUBUKI_MAKE_LOADER(ext_swapchain_colorspace),
        FUBUKI_MAKE_LOADER(khr_external_fence_capabilities),
        FUBUKI_MAKE_LOADER(khr_get_surface_capabilities2),
        FUBUKI_MAKE_LOADER(khr_get_display_properties2),
        FUBUKI_MAKE_LOADER(ext_debug_utils),
        FUBUKI_MAKE_LOADER(khr_surface_protected_capabilities),
        FUBUKI_MAKE_LOADER(ext_validation_features),
        FUBUKI_MAKE_LOADER(ext_surface_maintenance1),
        FUBUKI_MAKE_LOADER(ext_acquire_drm_display),
        FUBUKI_MAKE_LOADER(khr_portability_enumeration),
        FUBUKI_MAKE_LOADER(google_surfaceless_query),
        FUBUKI_MAKE_LOADER(lunarg_direct_driver_loading),
        FUBUKI_MAKE_LOADER(ext_layer_settings),
        FUBUKI_MAKE_LOADER(nv_display_stereo),

    };
    // clang-format on

    if(const auto it = supported_extensions.find(extension); it != supported_extensions.end())
    {
        const auto& ext_loader = it->second;
        ext_loader(functions, instance, version);
        return true;
    }

    return false;
}

#undef FUBUKI_MAKE_LOADER

} // namespace fubuki::extension
