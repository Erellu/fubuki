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

#ifndef FUBUKI_CORE_TRAITS_SURFACE_HPP
#define FUBUKI_CORE_TRAITS_SURFACE_HPP

#include <type_traits>

#include "core/string_literal.hpp"
#include "core/structure_type.hpp"
#include "core/surface_data.hpp"
#include "core/vulkan.hpp"

namespace fubuki::traits::platform::surface
{

namespace detail
{

template<typename T>
struct is_surface_platform_data : std::false_type
{
};

template<>
struct is_surface_platform_data<surface_data::android> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::directfb> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::fuchsia> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::ggp> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::headless> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::ios> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::macos> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::metal> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::qnx_screen> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::vi> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::wayland> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::win32> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::xcb> : std::true_type
{
};

template<>
struct is_surface_platform_data<surface_data::xlib> : std::true_type
{
};

} // namespace detail

template<typename T>
inline constexpr bool is_platform_data_v = detail::is_surface_platform_data<T>::value;

template<typename T>
concept platform_data = is_platform_data_v<T>;

template<typename T>
struct provider
{
    static constexpr auto extension = ""_literal;
    static constexpr auto pfn       = ""_literal;
    using pfn_type                  = void;
    using info                      = void;
};

template<typename T>
struct reverse
{
    static constexpr auto extension = ""_literal;
    static constexpr auto pfn       = ""_literal;
    using pfn_type                  = void;
    using info                      = void;
};

// clang-format off
/// Underlying Vulkan type associated to a fubuki::surface_data.
using underlying = std::variant<std::monostate
#if defined(VK_KHR_android_surface)
                                , VkAndroidSurfaceCreateInfoKHR
#endif // defined(VK_KHR_android_surface)

#if defined(VK_KHR_wayland_surface)
                                ,VkWaylandSurfaceCreateInfoKHR
#endif // defined(VK_KHR_wayland_surface)

#if defined(VK_KHR_win32_surface)
                                ,VkWin32SurfaceCreateInfoKHR
#endif // defined(VK_KHR_win32_surface)

#if defined(VK_KHR_xcb_surface)
                                ,VkXcbSurfaceCreateInfoKHR
#endif // defined(VK_KHR_xcb_surface)

#if defined(VK_KHR_xlib_surface)
                                ,VkXlibSurfaceCreateInfoKHR
#endif // defined(VK_KHR_xlib_surface)

#if defined(VK_EXT_directfb_surface)
                                ,VkDirectFBSurfaceCreateInfoEXT
#endif // defined(VK_EXT_directfb_surface)

#if defined(VK_EXT_headless_surface)
                                ,VkHeadlessSurfaceCreateInfoEXT
#endif // defined(VK_EXT_headless_surface)

#if defined(VK_EXT_metal_surface)
                                ,VkMetalSurfaceCreateInfoEXT
#endif // defined(VK_EXT_metal_surface)

#if defined(VK_FUCHSIA_imagepipe_surface)
                                ,VkImagePipeSurfaceCreateInfoFUCHSIA
#endif // defined(VK_FUCHSIA_imagepipe_surface)

#if defined(VK_GGP_stream_descriptor_surface)
                                ,VkStreamDescriptorSurfaceCreateInfoGGP
#endif // defined(VK_GGP_stream_descriptor_surface)

#if defined(VK_MVK_ios_surface)
                                ,VkIOSSurfaceCreateInfoMVK
#endif // defined(VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)
                                ,VkMacOSSurfaceCreateInfoMVK
#endif // defined(VK_MVK_macos_surface)

#if defined(VK_NN_vi_surface)
                                ,VkViSurfaceCreateInfoNN
#endif // defined(VK_NN_vi_surface)

#if defined(VK_QNX_screen_surface)
                                ,VkScreenSurfaceCreateInfoQNX
#endif // defined(VK_QNX_screen_surface)

                                >;
// clang-format on

#ifdef FUBUKI_MAKE_PLATFORM_TRAITS
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_PLATFORM_TRAITS(ext, surface_data_struct, pfn_name, create_structure) \
    template<>                                                                            \
    struct provider<surface_data::surface_data_struct>                                    \
    {                                                                                     \
        static constexpr auto extension = ext##_literal;                                  \
        static constexpr auto pfn       = #pfn_name##_literal;                            \
        using pfn_type                  = PFN_##pfn_name;                                 \
        using info                      = create_structure;                               \
    };                                                                                    \
    template<>                                                                            \
    struct reverse<create_structure>                                                      \
    {                                                                                     \
        static constexpr auto extension = ext##_literal;                                  \
        static constexpr auto pfn       = #pfn_name##_literal;                            \
        using pfn_type                  = PFN_##pfn_name;                                 \
        using info                      = surface_data::surface_data_struct;              \
    }

#if defined(VK_KHR_android_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_KHR_android_surface", android, vkCreateAndroidSurfaceKHR, VkAndroidSurfaceCreateInfoKHR);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkAndroidSurfaceCreateInfoKHR to_underlying(const surface_data::android& d) noexcept
{
    auto base   = make<VkAndroidSurfaceCreateInfoKHR>();
    base.window = d.window;
    return base;
}
#endif // defined(VK_KHR_android_surface)

#if defined(VK_KHR_wayland_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_KHR_wayland_surface", wayland, vkCreateWaylandSurfaceKHR, VkWaylandSurfaceCreateInfoKHR);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkWaylandSurfaceCreateInfoKHR to_underlying(const surface_data::wayland& d) noexcept
{
    auto base    = make<VkWaylandSurfaceCreateInfoKHR>();
    base.display = d.display;
    base.surface = d.surface;
    return base;
}
#endif // defined(VK_KHR_wayland_surface)

#if defined(VK_KHR_win32_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_KHR_win32_surface", win32, vkCreateWin32SurfaceKHR, VkWin32SurfaceCreateInfoKHR);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkWin32SurfaceCreateInfoKHR to_underlying(const surface_data::win32& d) noexcept
{
    auto base      = make<VkWin32SurfaceCreateInfoKHR>();
    base.hinstance = d.hinstance;
    base.hwnd      = d.hwnd;
    return base;
}
#endif // defined(VK_KHR_win32_surface)

#if defined(VK_KHR_xcb_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_KHR_xcb_surface", xcb, vkCreateXcbSurfaceKHR, VkXcbSurfaceCreateInfoKHR);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkXcbSurfaceCreateInfoKHR to_underlying(const surface_data::xcb& d) noexcept
{
    auto base       = make<VkXcbSurfaceCreateInfoKHR>();
    base.connection = d.connection;
    base.window     = d.window;
    return base;
}
#endif // defined(VK_KHR_xcb_surface)

#if defined(VK_KHR_xlib_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_KHR_xlib_surface", xlib, vkCreateXlibSurfaceKHR, VkXlibSurfaceCreateInfoKHR);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkXlibSurfaceCreateInfoKHR to_underlying(const surface_data::xlib& d) noexcept
{
    auto base   = make<VkXlibSurfaceCreateInfoKHR>();
    base.dpy    = d.dpy;
    base.window = d.window;
    return base;
}
#endif // defined(VK_KHR_xlib_surface)

#if defined(VK_EXT_directfb_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_EXT_directfb_surface", directfb, vkCreateDirectFBSurfaceEXT, VkDirectFBSurfaceCreateInfoEXT);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkDirectFBSurfaceCreateInfoEXT to_underlying(const surface_data::directfb& d) noexcept
{
    auto base    = make<VkDirectFBSurfaceCreateInfoEXT>();
    base.dfb     = d.dfb;
    base.surface = d.surface;
    return base;
}
#endif // defined(VK_EXT_directfb_surface)

#if defined(VK_EXT_headless_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_EXT_headless_surface", headless, vkCreateHeadlessSurfaceEXT, VkHeadlessSurfaceCreateInfoEXT);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkHeadlessSurfaceCreateInfoEXT to_underlying(const surface_data::headless&) noexcept
{
    return make<VkHeadlessSurfaceCreateInfoEXT>();
}
#endif // defined(VK_EXT_headless_surface)

#if defined(VK_EXT_metal_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_EXT_metal_surface", metal, vkCreateMetalSurfaceEXT, VkMetalSurfaceCreateInfoEXT);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkMetalSurfaceCreateInfoEXT to_underlying(const surface_data::metal& d) noexcept
{
    auto base   = make<VkMetalSurfaceCreateInfoEXT>();
    base.pLayer = d.layer;
    return base;
}
#endif // defined(VK_EXT_metal_surface)

#if defined(VK_FUCHSIA_imagepipe_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_FUCHSIA_imagepipe_surface", fuchsia, vkCreateImagePipeSurfaceFUCHSIA, VkImagePipeSurfaceCreateInfoFUCHSIA);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkImagePipeSurfaceCreateInfoFUCHSIA to_underlying(const surface_data::fuchsia& d) noexcept
{
    auto base            = make<VkImagePipeSurfaceCreateInfoFUCHSIA>();
    base.imagePipeHandle = d.image_pipe_handle;
    return base;
}
#endif // defined(VK_FUCHSIA_imagepipe_surface)

#if defined(VK_GGP_stream_descriptor_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_GGP_stream_descriptor_surface", ggp, vkCreateStreamDescriptorSurfaceGGP, VkStreamDescriptorSurfaceCreateInfoGGP);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkStreamDescriptorSurfaceCreateInfoGGP to_underlying(const surface_data::ggp& d) noexcept
{
    auto base             = make<VkStreamDescriptorSurfaceCreateInfoGGP>();
    base.streamDescriptor = d.stream_descriptor;
    return base;
}
#endif // defined(VK_GGP_stream_descriptor_surface)

#if defined(VK_MVK_ios_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_MVK_ios_surface", ios, vkCreateIOSSurfaceMVK, VkIOSSurfaceCreateInfoMVK);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkIOSSurfaceCreateInfoMVK to_underlying(const surface_data::ios& d) noexcept
{
    auto base  = make<VkIOSSurfaceCreateInfoMVK>();
    base.pView = d.view;
    return base;
}
#endif // defined(VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_MVK_macos_surface", macos, vkCreateMacOSSurfaceMVK, VkMacOSSurfaceCreateInfoMVK);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkMacOSSurfaceCreateInfoMVK to_underlying(const surface_data::macos& d) noexcept
{
    auto base  = make<VkMacOSSurfaceCreateInfoMVK>();
    base.pView = d.view;
    return base;
}
#endif // defined(VK_MVK_macos_surface)

#if defined(VK_NN_vi_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_NN_vi_surface", vi, vkCreateViSurfaceNN, VkViSurfaceCreateInfoNN);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkViSurfaceCreateInfoNN to_underlying(const surface_data::vi& d) noexcept
{
    auto base   = make<VkViSurfaceCreateInfoNN>();
    base.window = d.window;
    return base;
}
#endif // defined(VK_NN_vi_surface)

#if defined(VK_QNX_screen_surface)
FUBUKI_MAKE_PLATFORM_TRAITS("VK_QNX_screen_surface", qnx_screen, vkCreateScreenSurfaceQNX, VkScreenSurfaceCreateInfoQNX);

/// Creates an instance of the Vulkan structure associated to this data type.
[[nodiscard]] inline constexpr VkScreenSurfaceCreateInfoQNX to_underlying(const surface_data::qnx_screen& d) noexcept
{
    auto base    = make<VkScreenSurfaceCreateInfoQNX>();
    base.context = d.context;
    base.window  = d.window;
    return base;
}
#endif // defined(VK_QNX_screen_surface)

#undef FUBUKI_MAKE_PLATFORM_TRAITS

/// Returns the underlying Vulkan structure for a surface data.
[[nodiscard]] inline constexpr underlying to_underlying(const surface_data& data) noexcept
{
    constexpr auto visitor = []<typename T>(const T& variant) constexpr noexcept -> underlying
    {
        if constexpr(requires { to_underlying(variant); })
        {
            return to_underlying(variant);
        }
        else
        {
            return std::monostate{};
        }
    };

    return std::visit(visitor, data.value);
}

} // namespace fubuki::traits::platform::surface

#endif // FUBUKI_CORE_TRAITS_SURFACE_HPP
