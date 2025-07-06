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

#ifndef FUBUKI_CORE_ENUM_DRIVER_ID_HPP
#define FUBUKI_CORE_ENUM_DRIVER_ID_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_2)

/// Returns a std::string_view corresponding to a VkDriverId.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkDriverId e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_AMD_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_AMD_OPEN_SOURCE);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_RADV);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_NVIDIA_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_IMAGINATION_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_QUALCOMM_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_ARM_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_GOOGLE_SWIFTSHADER);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_GGP_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_BROADCOM_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_LLVMPIPE);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MOLTENVK);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_COREAVI_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_JUICE_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_VERISILICON_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_TURNIP);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_V3DV);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_PANVK);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_SAMSUNG_PROPRIETARY);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_VENUS);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_DOZEN);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_NVK);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_HONEYKRISP);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2) 
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_VULKAN_SC_EMULATION_ON_VULKAN);
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_AMD_PROPRIETARY_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_AMD_OPEN_SOURCE_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MESA_RADV_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_NVIDIA_PROPRIETARY_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_IMAGINATION_PROPRIETARY_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_QUALCOMM_PROPRIETARY_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_ARM_PROPRIETARY_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_GOOGLE_SWIFTSHADER_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_GGP_PROPRIETARY_KHR);
#endif // #if defined (VK_KHR_driver_properties)

#if defined(VK_KHR_driver_properties) && !(defined(VK_VERSION_1_2))
        FUBUKI_MAKE_CASE(VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR);
#endif // #if defined (VK_KHR_driver_properties)

        FUBUKI_MAKE_CASE(VK_DRIVER_ID_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkDriverId.
[[nodiscard]] inline auto to_string(VkDriverId e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_2)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_DRIVER_ID_HPP
