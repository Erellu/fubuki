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

#ifndef FUBUKI_EXTENSION_FUNCTIONS_INSTANCE_HPP
#define FUBUKI_EXTENSION_FUNCTIONS_INSTANCE_HPP

#include <memory>
#include <string_view>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_acquire_drm_display.hpp"
#include "extension/functions/ext_acquire_xlib_display.hpp"
#include "extension/functions/ext_debug_report.hpp"
#include "extension/functions/ext_debug_utils.hpp"
#include "extension/functions/ext_direct_mode_display.hpp"
#include "extension/functions/ext_display_surface_counter.hpp"
#include "extension/functions/ext_layer_settings.hpp"
#include "extension/functions/ext_surface_maintenance1.hpp"
#include "extension/functions/ext_swapchain_colorspace.hpp"
#include "extension/functions/ext_validation_features.hpp"
#include "extension/functions/ext_validation_flags.hpp"
#include "extension/functions/google_surfaceless_query.hpp"
#include "extension/functions/khr_device_group_creation.hpp"
#include "extension/functions/khr_display.hpp"
#include "extension/functions/khr_external_fence_capabilities.hpp"
#include "extension/functions/khr_external_memory_capabilities.hpp"
#include "extension/functions/khr_external_semaphore_capabilities.hpp"
#include "extension/functions/khr_get_display_properties2.hpp"
#include "extension/functions/khr_get_physical_device_properties2.hpp"
#include "extension/functions/khr_get_surface_capabilities2.hpp"
#include "extension/functions/khr_portability_enumeration.hpp"
#include "extension/functions/khr_surface.hpp"
#include "extension/functions/khr_surface_protected_capabilities.hpp"
#include "extension/functions/lunarg_direct_driver_loading.hpp"
#include "extension/functions/nv_display_stereo.hpp"
#include "extension/functions/nv_external_memory_capabilities.hpp"

//------------------------------------------------------------------------------
// Macros

//------------------------------------------------------------------------------

namespace fubuki
{

namespace extension
{

#if defined(FUBUKI_DECLARE_EXT)
    #error "FUBUKI_DECLARE_EXT is already defined."
#endif

#define FUBUKI_DECLARE_EXT(name)                                                                                 \
                                                                                                                 \
    std::unique_ptr<extension::functions::name> name;                                                            \
                                                                                                                 \
    [[nodiscard]] constexpr operator const extension::functions::name*() const noexcept { return (name).get(); } \
    [[nodiscard]] constexpr operator const extension::functions::name&() const noexcept                          \
    {                                                                                                            \
        fubuki_assert((name) != nullptr, "Extension not loaded");                                                \
        return *(name);                                                                                          \
    }

struct instance_functions
{

    FUBUKI_DECLARE_EXT(khr_surface)
    FUBUKI_DECLARE_EXT(khr_display)
    FUBUKI_DECLARE_EXT(ext_debug_report)
    FUBUKI_DECLARE_EXT(nv_external_memory_capabilities)
    FUBUKI_DECLARE_EXT(khr_get_physical_device_properties2)
    FUBUKI_DECLARE_EXT(ext_validation_flags)
    FUBUKI_DECLARE_EXT(khr_device_group_creation)
    FUBUKI_DECLARE_EXT(khr_external_memory_capabilities)
    FUBUKI_DECLARE_EXT(khr_external_semaphore_capabilities)
    FUBUKI_DECLARE_EXT(ext_direct_mode_display)
    FUBUKI_DECLARE_EXT(ext_acquire_xlib_display)
    FUBUKI_DECLARE_EXT(ext_display_surface_counter)
    FUBUKI_DECLARE_EXT(ext_swapchain_colorspace)
    FUBUKI_DECLARE_EXT(khr_external_fence_capabilities)
    FUBUKI_DECLARE_EXT(khr_get_surface_capabilities2)
    FUBUKI_DECLARE_EXT(khr_get_display_properties2)
    FUBUKI_DECLARE_EXT(ext_debug_utils)
    FUBUKI_DECLARE_EXT(khr_surface_protected_capabilities)
    FUBUKI_DECLARE_EXT(ext_validation_features)
    FUBUKI_DECLARE_EXT(ext_surface_maintenance1)
    FUBUKI_DECLARE_EXT(ext_acquire_drm_display)
    FUBUKI_DECLARE_EXT(khr_portability_enumeration)
    FUBUKI_DECLARE_EXT(google_surfaceless_query)
    FUBUKI_DECLARE_EXT(lunarg_direct_driver_loading)
    FUBUKI_DECLARE_EXT(ext_layer_settings)
    FUBUKI_DECLARE_EXT(nv_display_stereo)

    FUBUKI_EXTENSION_API
    instance_functions();

    FUBUKI_EXTENSION_API
    instance_functions(instance_functions&&) noexcept;

    FUBUKI_EXTENSION_API
    instance_functions& operator=(instance_functions&&) noexcept;

    FUBUKI_EXTENSION_API
    ~instance_functions();

    instance_functions(const instance_functions&)            = delete;
    instance_functions& operator=(const instance_functions&) = delete;
};

#undef FUBUKI_DECLARE_EXT

//------------------------------------------------------------------------------

/// Loads an extension functions, if Fubuki supports it.
/// @returns A boolean indicating if the operation succeeded.
[[nodiscard]] FUBUKI_EXTENSION_API bool
load(instance_functions& functions, instance_handle instance, version_number version, std::string_view extension);

} // namespace extension

using instance_ext_functions = extension::instance_functions;

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

#if defined(VK_KHR_surface)
template<>
struct get_from<extension::instance_functions, "vkDestroySurfaceKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroySurfaceKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_surface)
        if(functions.khr_surface)
        {
            static_assert(
                requires {
                    { functions.khr_surface };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_surface, "vkDestroySurfaceKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_surface, "vkDestroySurfaceKHR">::get(*functions.khr_surface);
        }
    #endif // defined(VK_KHR_surface)

        return nullptr;
    }
};
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSurfaceSupportKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfaceSupportKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_surface)
        if(functions.khr_surface)
        {
            static_assert(
                requires {
                    { functions.khr_surface };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfaceSupportKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfaceSupportKHR">::get(*functions.khr_surface);
        }
    #endif // defined(VK_KHR_surface)

        return nullptr;
    }
};
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_surface)
        if(functions.khr_surface)
        {
            static_assert(
                requires {
                    { functions.khr_surface };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR">::get(*functions.khr_surface);
        }
    #endif // defined(VK_KHR_surface)

        return nullptr;
    }
};
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSurfaceFormatsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfaceFormatsKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_surface)
        if(functions.khr_surface)
        {
            static_assert(
                requires {
                    { functions.khr_surface };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfaceFormatsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfaceFormatsKHR">::get(*functions.khr_surface);
        }
    #endif // defined(VK_KHR_surface)

        return nullptr;
    }
};
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSurfacePresentModesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfacePresentModesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_surface)
        if(functions.khr_surface)
        {
            static_assert(
                requires {
                    { functions.khr_surface };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfacePresentModesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_surface, "vkGetPhysicalDeviceSurfacePresentModesKHR">::get(*functions.khr_surface);
        }
    #endif // defined(VK_KHR_surface)

        return nullptr;
    }
};
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_display)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceDisplayPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceDisplayPropertiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_display)
        if(functions.khr_display)
        {
            static_assert(
                requires {
                    { functions.khr_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display, "vkGetPhysicalDeviceDisplayPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display, "vkGetPhysicalDeviceDisplayPropertiesKHR">::get(*functions.khr_display);
        }
    #endif // defined(VK_KHR_display)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_display)
        if(functions.khr_display)
        {
            static_assert(
                requires {
                    { functions.khr_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR">::get(*functions.khr_display);
        }
    #endif // defined(VK_KHR_display)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct get_from<extension::instance_functions, "vkGetDisplayPlaneSupportedDisplaysKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDisplayPlaneSupportedDisplaysKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_display)
        if(functions.khr_display)
        {
            static_assert(
                requires {
                    { functions.khr_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display, "vkGetDisplayPlaneSupportedDisplaysKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display, "vkGetDisplayPlaneSupportedDisplaysKHR">::get(*functions.khr_display);
        }
    #endif // defined(VK_KHR_display)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct get_from<extension::instance_functions, "vkGetDisplayModePropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDisplayModePropertiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_display)
        if(functions.khr_display)
        {
            static_assert(
                requires {
                    { functions.khr_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display, "vkGetDisplayModePropertiesKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display, "vkGetDisplayModePropertiesKHR">::get(*functions.khr_display);
        }
    #endif // defined(VK_KHR_display)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct get_from<extension::instance_functions, "vkCreateDisplayModeKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateDisplayModeKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_display)
        if(functions.khr_display)
        {
            static_assert(
                requires {
                    { functions.khr_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display, "vkCreateDisplayModeKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display, "vkCreateDisplayModeKHR">::get(*functions.khr_display);
        }
    #endif // defined(VK_KHR_display)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct get_from<extension::instance_functions, "vkGetDisplayPlaneCapabilitiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDisplayPlaneCapabilitiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_display)
        if(functions.khr_display)
        {
            static_assert(
                requires {
                    { functions.khr_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display, "vkGetDisplayPlaneCapabilitiesKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display, "vkGetDisplayPlaneCapabilitiesKHR">::get(*functions.khr_display);
        }
    #endif // defined(VK_KHR_display)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct get_from<extension::instance_functions, "vkCreateDisplayPlaneSurfaceKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateDisplayPlaneSurfaceKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_display)
        if(functions.khr_display)
        {
            static_assert(
                requires {
                    { functions.khr_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_display, "vkCreateDisplayPlaneSurfaceKHR">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::khr_display, "vkCreateDisplayPlaneSurfaceKHR">::get(*functions.khr_display);
        }
    #endif // defined(VK_KHR_display)

        return nullptr;
    }
};
#endif // defined(VK_KHR_display)

#if defined(VK_EXT_debug_report)
template<>
struct get_from<extension::instance_functions, "vkCreateDebugReportCallbackEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateDebugReportCallbackEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_report)
        if(functions.ext_debug_report)
        {
            static_assert(
                requires {
                    { functions.ext_debug_report };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_report, "vkCreateDebugReportCallbackEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_report, "vkCreateDebugReportCallbackEXT">::get(*functions.ext_debug_report);
        }
    #endif // defined(VK_EXT_debug_report)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_report)

#if defined(VK_EXT_debug_report)
template<>
struct get_from<extension::instance_functions, "vkDestroyDebugReportCallbackEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyDebugReportCallbackEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_report)
        if(functions.ext_debug_report)
        {
            static_assert(
                requires {
                    { functions.ext_debug_report };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_report, "vkDestroyDebugReportCallbackEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_report, "vkDestroyDebugReportCallbackEXT">::get(*functions.ext_debug_report);
        }
    #endif // defined(VK_EXT_debug_report)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_report)

#if defined(VK_EXT_debug_report)
template<>
struct get_from<extension::instance_functions, "vkDebugReportMessageEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDebugReportMessageEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_report)
        if(functions.ext_debug_report)
        {
            static_assert(
                requires {
                    { functions.ext_debug_report };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_report, "vkDebugReportMessageEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_report, "vkDebugReportMessageEXT">::get(*functions.ext_debug_report);
        }
    #endif // defined(VK_EXT_debug_report)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_report)

#if defined(VK_NV_external_memory_capabilities)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_NV_external_memory_capabilities)
        if(functions.nv_external_memory_capabilities)
        {
            static_assert(
                requires {
                    { functions.nv_external_memory_capabilities };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::nv_external_memory_capabilities, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::nv_external_memory_capabilities, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV">::get(
                *functions.nv_external_memory_capabilities);
        }
    #endif // defined(VK_NV_external_memory_capabilities)

        return nullptr;
    }
};
#endif // defined(VK_NV_external_memory_capabilities)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceFeatures2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceFeatures2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_physical_device_properties2)
        if(functions.khr_get_physical_device_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_physical_device_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceFeatures2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceFeatures2KHR">::get(
                *functions.khr_get_physical_device_properties2);
        }
    #endif // defined(VK_KHR_get_physical_device_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_physical_device_properties2)
        if(functions.khr_get_physical_device_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_physical_device_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceProperties2KHR">::get(
                *functions.khr_get_physical_device_properties2);
        }
    #endif // defined(VK_KHR_get_physical_device_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceFormatProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceFormatProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_physical_device_properties2)
        if(functions.khr_get_physical_device_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_physical_device_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceFormatProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceFormatProperties2KHR">::get(
                *functions.khr_get_physical_device_properties2);
        }
    #endif // defined(VK_KHR_get_physical_device_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceImageFormatProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceImageFormatProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_physical_device_properties2)
        if(functions.khr_get_physical_device_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_physical_device_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceImageFormatProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceImageFormatProperties2KHR">::get(
                *functions.khr_get_physical_device_properties2);
        }
    #endif // defined(VK_KHR_get_physical_device_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceQueueFamilyProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_physical_device_properties2)
        if(functions.khr_get_physical_device_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_physical_device_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceQueueFamilyProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceQueueFamilyProperties2KHR">::get(
                *functions.khr_get_physical_device_properties2);
        }
    #endif // defined(VK_KHR_get_physical_device_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceMemoryProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceMemoryProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_physical_device_properties2)
        if(functions.khr_get_physical_device_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_physical_device_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceMemoryProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceMemoryProperties2KHR">::get(
                *functions.khr_get_physical_device_properties2);
        }
    #endif // defined(VK_KHR_get_physical_device_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_physical_device_properties2)
        if(functions.khr_get_physical_device_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_physical_device_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_physical_device_properties2, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR">::get(
                *functions.khr_get_physical_device_properties2);
        }
    #endif // defined(VK_KHR_get_physical_device_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_device_group_creation)
template<>
struct get_from<extension::instance_functions, "vkEnumeratePhysicalDeviceGroupsKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkEnumeratePhysicalDeviceGroupsKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_device_group_creation)
        if(functions.khr_device_group_creation)
        {
            static_assert(
                requires {
                    { functions.khr_device_group_creation };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_device_group_creation, "vkEnumeratePhysicalDeviceGroupsKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_device_group_creation, "vkEnumeratePhysicalDeviceGroupsKHR">::get(
                *functions.khr_device_group_creation);
        }
    #endif // defined(VK_KHR_device_group_creation)

        return nullptr;
    }
};
#endif // defined(VK_KHR_device_group_creation)

#if defined(VK_KHR_external_memory_capabilities)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceExternalBufferPropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_memory_capabilities)
        if(functions.khr_external_memory_capabilities)
        {
            static_assert(
                requires {
                    { functions.khr_external_memory_capabilities };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_memory_capabilities, "vkGetPhysicalDeviceExternalBufferPropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_memory_capabilities, "vkGetPhysicalDeviceExternalBufferPropertiesKHR">::get(
                *functions.khr_external_memory_capabilities);
        }
    #endif // defined(VK_KHR_external_memory_capabilities)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_memory_capabilities)

#if defined(VK_KHR_external_semaphore_capabilities)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_semaphore_capabilities)
        if(functions.khr_external_semaphore_capabilities)
        {
            static_assert(
                requires {
                    { functions.khr_external_semaphore_capabilities };
                }, "Internal error. Bad name or version structure.");

            static_assert(
                get_from<extension::functions::khr_external_semaphore_capabilities, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR">::valid,
                "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_semaphore_capabilities, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR">::get(
                *functions.khr_external_semaphore_capabilities);
        }
    #endif // defined(VK_KHR_external_semaphore_capabilities)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_semaphore_capabilities)

#if defined(VK_EXT_direct_mode_display)
template<>
struct get_from<extension::instance_functions, "vkReleaseDisplayEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkReleaseDisplayEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_direct_mode_display)
        if(functions.ext_direct_mode_display)
        {
            static_assert(
                requires {
                    { functions.ext_direct_mode_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_direct_mode_display, "vkReleaseDisplayEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_direct_mode_display, "vkReleaseDisplayEXT">::get(*functions.ext_direct_mode_display);
        }
    #endif // defined(VK_EXT_direct_mode_display)

        return nullptr;
    }
};
#endif // defined(VK_EXT_direct_mode_display)

#if defined(VK_EXT_acquire_xlib_display)
template<>
struct get_from<extension::instance_functions, "vkAcquireXlibDisplayEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquireXlibDisplayEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_acquire_xlib_display)
        if(functions.ext_acquire_xlib_display)
        {
            static_assert(
                requires {
                    { functions.ext_acquire_xlib_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_acquire_xlib_display, "vkAcquireXlibDisplayEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_acquire_xlib_display, "vkAcquireXlibDisplayEXT">::get(*functions.ext_acquire_xlib_display);
        }
    #endif // defined(VK_EXT_acquire_xlib_display)

        return nullptr;
    }
};
#endif // defined(VK_EXT_acquire_xlib_display)

#if defined(VK_EXT_acquire_xlib_display)
template<>
struct get_from<extension::instance_functions, "vkGetRandROutputDisplayEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetRandROutputDisplayEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_acquire_xlib_display)
        if(functions.ext_acquire_xlib_display)
        {
            static_assert(
                requires {
                    { functions.ext_acquire_xlib_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_acquire_xlib_display, "vkGetRandROutputDisplayEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_acquire_xlib_display, "vkGetRandROutputDisplayEXT">::get(*functions.ext_acquire_xlib_display);
        }
    #endif // defined(VK_EXT_acquire_xlib_display)

        return nullptr;
    }
};
#endif // defined(VK_EXT_acquire_xlib_display)

#if defined(VK_EXT_display_surface_counter)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSurfaceCapabilities2EXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_display_surface_counter)
        if(functions.ext_display_surface_counter)
        {
            static_assert(
                requires {
                    { functions.ext_display_surface_counter };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_display_surface_counter, "vkGetPhysicalDeviceSurfaceCapabilities2EXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_display_surface_counter, "vkGetPhysicalDeviceSurfaceCapabilities2EXT">::get(
                *functions.ext_display_surface_counter);
        }
    #endif // defined(VK_EXT_display_surface_counter)

        return nullptr;
    }
};
#endif // defined(VK_EXT_display_surface_counter)

#if defined(VK_KHR_external_fence_capabilities)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceExternalFencePropertiesKHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_external_fence_capabilities)
        if(functions.khr_external_fence_capabilities)
        {
            static_assert(
                requires {
                    { functions.khr_external_fence_capabilities };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_external_fence_capabilities, "vkGetPhysicalDeviceExternalFencePropertiesKHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_external_fence_capabilities, "vkGetPhysicalDeviceExternalFencePropertiesKHR">::get(
                *functions.khr_external_fence_capabilities);
        }
    #endif // defined(VK_KHR_external_fence_capabilities)

        return nullptr;
    }
};
#endif // defined(VK_KHR_external_fence_capabilities)

#if defined(VK_KHR_get_surface_capabilities2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSurfaceCapabilities2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_surface_capabilities2)
        if(functions.khr_get_surface_capabilities2)
        {
            static_assert(
                requires {
                    { functions.khr_get_surface_capabilities2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_surface_capabilities2, "vkGetPhysicalDeviceSurfaceCapabilities2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_surface_capabilities2, "vkGetPhysicalDeviceSurfaceCapabilities2KHR">::get(
                *functions.khr_get_surface_capabilities2);
        }
    #endif // defined(VK_KHR_get_surface_capabilities2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceSurfaceFormats2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceSurfaceFormats2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_surface_capabilities2)
        if(functions.khr_get_surface_capabilities2)
        {
            static_assert(
                requires {
                    { functions.khr_get_surface_capabilities2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_surface_capabilities2, "vkGetPhysicalDeviceSurfaceFormats2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_surface_capabilities2, "vkGetPhysicalDeviceSurfaceFormats2KHR">::get(
                *functions.khr_get_surface_capabilities2);
        }
    #endif // defined(VK_KHR_get_surface_capabilities2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceDisplayProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceDisplayProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_display_properties2)
        if(functions.khr_get_display_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_display_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_display_properties2, "vkGetPhysicalDeviceDisplayProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_display_properties2, "vkGetPhysicalDeviceDisplayProperties2KHR">::get(
                *functions.khr_get_display_properties2);
        }
    #endif // defined(VK_KHR_get_display_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_display_properties2)
        if(functions.khr_get_display_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_display_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_display_properties2, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_display_properties2, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR">::get(
                *functions.khr_get_display_properties2);
        }
    #endif // defined(VK_KHR_get_display_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetDisplayModeProperties2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDisplayModeProperties2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_display_properties2)
        if(functions.khr_get_display_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_display_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_display_properties2, "vkGetDisplayModeProperties2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_display_properties2, "vkGetDisplayModeProperties2KHR">::get(
                *functions.khr_get_display_properties2);
        }
    #endif // defined(VK_KHR_get_display_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct get_from<extension::instance_functions, "vkGetDisplayPlaneCapabilities2KHR">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDisplayPlaneCapabilities2KHR get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_KHR_get_display_properties2)
        if(functions.khr_get_display_properties2)
        {
            static_assert(
                requires {
                    { functions.khr_get_display_properties2 };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::khr_get_display_properties2, "vkGetDisplayPlaneCapabilities2KHR">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::khr_get_display_properties2, "vkGetDisplayPlaneCapabilities2KHR">::get(
                *functions.khr_get_display_properties2);
        }
    #endif // defined(VK_KHR_get_display_properties2)

        return nullptr;
    }
};
#endif // defined(VK_KHR_get_display_properties2)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkSetDebugUtilsObjectNameEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetDebugUtilsObjectNameEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkSetDebugUtilsObjectNameEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkSetDebugUtilsObjectNameEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkSetDebugUtilsObjectTagEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSetDebugUtilsObjectTagEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkSetDebugUtilsObjectTagEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkSetDebugUtilsObjectTagEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkQueueBeginDebugUtilsLabelEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkQueueBeginDebugUtilsLabelEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkQueueBeginDebugUtilsLabelEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkQueueBeginDebugUtilsLabelEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkQueueEndDebugUtilsLabelEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkQueueEndDebugUtilsLabelEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkQueueEndDebugUtilsLabelEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkQueueEndDebugUtilsLabelEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkQueueInsertDebugUtilsLabelEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkQueueInsertDebugUtilsLabelEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkQueueInsertDebugUtilsLabelEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkQueueInsertDebugUtilsLabelEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkCreateDebugUtilsMessengerEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCreateDebugUtilsMessengerEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkCreateDebugUtilsMessengerEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkCreateDebugUtilsMessengerEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkDestroyDebugUtilsMessengerEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkDestroyDebugUtilsMessengerEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkDestroyDebugUtilsMessengerEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkDestroyDebugUtilsMessengerEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkSubmitDebugUtilsMessageEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkSubmitDebugUtilsMessageEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkSubmitDebugUtilsMessageEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkSubmitDebugUtilsMessageEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkCmdBeginDebugUtilsLabelEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdBeginDebugUtilsLabelEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkCmdBeginDebugUtilsLabelEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkCmdBeginDebugUtilsLabelEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkCmdEndDebugUtilsLabelEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdEndDebugUtilsLabelEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkCmdEndDebugUtilsLabelEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkCmdEndDebugUtilsLabelEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct get_from<extension::instance_functions, "vkCmdInsertDebugUtilsLabelEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkCmdInsertDebugUtilsLabelEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_debug_utils)
        if(functions.ext_debug_utils)
        {
            static_assert(
                requires {
                    { functions.ext_debug_utils };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_debug_utils, "vkCmdInsertDebugUtilsLabelEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_debug_utils, "vkCmdInsertDebugUtilsLabelEXT">::get(*functions.ext_debug_utils);
        }
    #endif // defined(VK_EXT_debug_utils)

        return nullptr;
    }
};
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_EXT_acquire_drm_display)
template<>
struct get_from<extension::instance_functions, "vkAcquireDrmDisplayEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkAcquireDrmDisplayEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_acquire_drm_display)
        if(functions.ext_acquire_drm_display)
        {
            static_assert(
                requires {
                    { functions.ext_acquire_drm_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_acquire_drm_display, "vkAcquireDrmDisplayEXT">::valid,
                          "Internal error. Wrong extension");

            return get_from<extension::functions::ext_acquire_drm_display, "vkAcquireDrmDisplayEXT">::get(*functions.ext_acquire_drm_display);
        }
    #endif // defined(VK_EXT_acquire_drm_display)

        return nullptr;
    }
};
#endif // defined(VK_EXT_acquire_drm_display)

#if defined(VK_EXT_acquire_drm_display)
template<>
struct get_from<extension::instance_functions, "vkGetDrmDisplayEXT">
{
    static constexpr bool valid = true;

    [[nodiscard]] constexpr static PFN_vkGetDrmDisplayEXT get(const extension::instance_functions& functions) noexcept
    {

    #if defined(VK_EXT_acquire_drm_display)
        if(functions.ext_acquire_drm_display)
        {
            static_assert(
                requires {
                    { functions.ext_acquire_drm_display };
                }, "Internal error. Bad name or version structure.");

            static_assert(get_from<extension::functions::ext_acquire_drm_display, "vkGetDrmDisplayEXT">::valid, "Internal error. Wrong extension");

            return get_from<extension::functions::ext_acquire_drm_display, "vkGetDrmDisplayEXT">::get(*functions.ext_acquire_drm_display);
        }
    #endif // defined(VK_EXT_acquire_drm_display)

        return nullptr;
    }
};
#endif // defined(VK_EXT_acquire_drm_display)

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_CORE_FUNCTIONS_INSTANCE_EXTENSIONS_HPP
