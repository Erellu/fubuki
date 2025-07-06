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

#ifndef FUBUKI_EXTENSION_FUNCTION_KHR_SURFACE_HPP
#define FUBUKI_EXTENSION_FUNCTION_KHR_SURFACE_HPP

#include <array>
#include <functional>

#include <core/config/macros.hpp>
#include <core/detail/pfn.hpp>
#include <core/handle.hpp>
#include <core/string_literal.hpp>
#include <core/surface_data.hpp>
#include <core/traits/surface.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

namespace fubuki
{

namespace extension
{

namespace functions
{

struct khr_surface
{
#if defined(VK_KHR_surface)

    using create_surface
        = std::function<VkResult(instance_handle, const traits::platform::surface::underlying&, const VkAllocationCallbacks*, VkSurfaceKHR*)>;

    struct command
    {
    };

    std::function<VkResult(instance_handle, const traits::platform::surface::underlying&, const VkAllocationCallbacks*, VkSurfaceKHR*)>
                                                  create_surface_khr                            = {};
    PFN_vkDestroySurfaceKHR                       destroy_surface_khr                           = nullptr;
    PFN_vkGetPhysicalDeviceSurfaceSupportKHR      get_physical_device_surface_support_khr       = nullptr;
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR get_physical_device_surface_capabilities_khr  = nullptr;
    PFN_vkGetPhysicalDeviceSurfaceFormatsKHR      get_physical_device_surface_formats_khr       = nullptr;
    PFN_vkGetPhysicalDeviceSurfacePresentModesKHR get_physical_device_surface_present_modes_khr = nullptr;

    command cmd = {};

#endif // defined(VK_KHR_surface)

           /// Loads the extension.
    [[nodiscard]] FUBUKI_EXTENSION_API static khr_surface load([[maybe_unused]] instance_handle instance,
                                                               [[maybe_unused]] version_number  vk_version) noexcept;
};

} // namespace functions

/**
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_KHR_surface.html
 */
namespace khr_surface
{

/// Name of the extension.
inline constexpr auto name = "VK_KHR_surface";

/// Name corresponding to the platform in use.
/// An iterable list of surface extensions provided by Vulkan.
inline constexpr std::array surface_extensions = {
    "VK_KHR_android_surface"_literal,
    "VK_KHR_wayland_surface"_literal,
    "VK_KHR_win32_surface"_literal,
    "VK_KHR_xcb_surface"_literal,
    "VK_KHR_xlib_surface"_literal,
    "VK_EXT_directfb_surface"_literal,
    "VK_EXT_headless_surface"_literal,
    "VK_EXT_metal_surface"_literal,
    "VK_FUCHSIA_imagepipe_surface"_literal,
    "VK_GGP_stream_descriptor_surface"_literal,
    "VK_MVK_ios_surface"_literal,
    "VK_MVK_macos_surface"_literal,
    "VK_NN_vi_surface"_literal,
    "VK_QNX_screen_surface"_literal,
};

using functions = extension::functions::khr_surface;

/// Loads the extension.
[[nodiscard]] inline functions load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version) noexcept
{
    return functions::load(instance, vk_version);
}

} // namespace khr_surface

} // namespace extension

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a extension::functions::khr_surface struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<extension::functions::khr_surface, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const extension::functions::khr_surface&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, fubuki_name)                                                   \
template<>                                                                                                \
    struct get_from<extension::functions::khr_surface, #vk_function_name>                                     \
{                                                                                                         \
        static constexpr bool valid = true;                                                                   \
                                                                                                              \
        [[nodiscard]] constexpr static auto* get(const extension::functions::khr_surface& functions) noexcept \
    {                                                                                                     \
            static_assert(                                                                                    \
                                                                                                              requires {                                                                                    \
                                                                                                                      {                                                                                         \
                                                                                                                                                                                                                functions.fubuki_name                                                                 \
                                                                                                                      };                                                                                        \
                                                                                                              }, "Internal error. Bad name or version structure.");                                         \
                                                                                                              \
            auto pfn = functions.fubuki_name;                                                                 \
                                                                                                              \
            using expected_pfn_type = PFN_##vk_function_name;                                                 \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                            \
                                                                                                              \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch.");     \
                                                                                                              \
            return pfn;                                                                                       \
    }                                                                                                     \
}

#if defined(VK_KHR_surface)
FUBUKI_MAKE_GET_FROM(vkDestroySurfaceKHR, destroy_surface_khr);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceSurfaceSupportKHR, get_physical_device_surface_support_khr);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceSurfaceCapabilitiesKHR, get_physical_device_surface_capabilities_khr);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceSurfaceFormatsKHR, get_physical_device_surface_formats_khr);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceSurfacePresentModesKHR, get_physical_device_surface_present_modes_khr);

#endif // defined(VK_KHR_surface)

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_EXTENSION_KHR_SURFACE_HPP
