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

#ifndef FUBUKI_EXTENSION_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_HPP
#define FUBUKI_EXTENSION_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_get_physical_device_properties2.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_get_physical_device_properties2
{

#if defined(VK_KHR_get_physical_device_properties2)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceMemoryProperties2KHR.html
FUBUKI_EXTENSION_API void get_physical_device_memory_properties2(const functions&                   ext,
                                                                 physical_device_handle             physical_device,
                                                                 VkPhysicalDeviceMemoryProperties2& result) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceImageFormatProperties2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info>
                                   get_physical_device_image_format_properties2(const functions&                        ext,
                                                                                physical_device_handle                  physical_device,
                                                                                const VkPhysicalDeviceImageFormatInfo2& image_format_info,
                                                                                VkImageFormatProperties2&               result) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceFormatProperties2KHR.html
FUBUKI_EXTENSION_API void get_physical_device_format_properties2(const functions&       ext,
                                                                 physical_device_handle physical_device,
                                                                 VkFormat               format,
                                                                 VkFormatProperties2&   result) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceProperties2KHR.html
FUBUKI_EXTENSION_API void
get_physical_device_properties2(const functions& ext, physical_device_handle physical_device, VkPhysicalDeviceProperties2& result) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceFeatures2KHR.html
FUBUKI_EXTENSION_API void
get_physical_device_features2(const functions& ext, physical_device_handle physical_device, VkPhysicalDeviceFeatures2& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceFeatures2KHR.html
template<typename... elements>
[[nodiscard]] inline auto
get_physical_device_features2(const functions& ext, physical_device_handle physical_device, const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkPhysicalDeviceFeatures2>();
    fubuki::extend(result, pnext);

    detail::get_physical_device_features2(ext, physical_device, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceFeatures2KHR.html
[[nodiscard]] inline auto get_physical_device_features2(const functions& ext, physical_device_handle physical_device) noexcept
{
    return get_physical_device_features2(ext, physical_device, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceProperties2KHR.html
template<typename... elements>
[[nodiscard]] inline VkPhysicalDeviceProperties2
get_physical_device_properties2(const functions& ext, physical_device_handle physical_device, const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkPhysicalDeviceProperties2>();
    fubuki::extend(result, pnext);

    detail::get_physical_device_properties2(ext, physical_device, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceProperties2KHR.html
[[nodiscard]] inline VkPhysicalDeviceProperties2 get_physical_device_properties2(const functions&       ext,
                                                                                 physical_device_handle physical_device) noexcept
{
    return get_physical_device_properties2(ext, physical_device, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceFormatProperties2KHR.html
template<typename... elements>
[[nodiscard]] inline auto get_physical_device_format_properties2(const functions&                ext,
                                                                 physical_device_handle          physical_device,
                                                                 VkFormat                        format,
                                                                 const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkFormatProperties2>();
    fubuki::extend(result, pnext);

    detail::get_physical_device_format_properties2(ext, physical_device, format, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceFormatProperties2KHR.html
[[nodiscard]] inline auto
get_physical_device_format_properties2(const functions& ext, physical_device_handle physical_device, VkFormat format) noexcept
{
    return get_physical_device_format_properties2(ext, physical_device, format, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceImageFormatProperties2KHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkImageFormatProperties2, api_call_info>
get_physical_device_image_format_properties2(const functions&                        ext,
                                             physical_device_handle                  physical_device,
                                             const VkPhysicalDeviceImageFormatInfo2& image_format_info,
                                             const pnext_chain<elements...>&         pnext) noexcept
{
    auto result = fubuki::make<VkImageFormatProperties2>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_physical_device_image_format_properties2(ext, physical_device, image_format_info, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceImageFormatProperties2KHR.html
[[nodiscard]] inline auto get_physical_device_image_format_properties2(const functions&                        ext,
                                                                       physical_device_handle                  physical_device,
                                                                       const VkPhysicalDeviceImageFormatInfo2& image_format_info) noexcept
{
    return get_physical_device_image_format_properties2(ext, physical_device, image_format_info, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceQueueFamilyProperties2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::vector<VkQueueFamilyProperties2>
                                   get_physical_device_queue_family_properties2(const functions& ext, physical_device_handle physical_device);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceMemoryProperties2KHR.html
template<typename... elements>
[[nodiscard]] inline auto
get_physical_device_memory_properties2(const functions& ext, physical_device_handle physical_device, const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkPhysicalDeviceMemoryProperties2>();
    fubuki::extend(result, pnext);

    detail::get_physical_device_memory_properties2(ext, physical_device, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceMemoryProperties2KHR.html
[[nodiscard]] inline auto get_physical_device_memory_properties2(const functions& ext, physical_device_handle physical_device) noexcept
{
    return get_physical_device_memory_properties2(ext, physical_device, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceSparseImageFormatProperties2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::vector<VkSparseImageFormatProperties2> get_physical_device_sparse_image_format_properties2(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceSparseImageFormatInfo2& format_info);

#endif // defined(VK_KHR_get_physical_device_properties2)

} // namespace fubuki::extension::khr_get_physical_device_properties2

#endif // FUBUKI_EXTENSION_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_HPP
