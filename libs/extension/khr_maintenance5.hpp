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

#ifndef FUBUKI_EXTENSION_KHR_MAINTENANCE5_HPP
#define FUBUKI_EXTENSION_KHR_MAINTENANCE5_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_maintenance5.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_maintenance5
{

#if defined(VK_KHR_maintenance5)

namespace detail
{

FUBUKI_EXTENSION_API
void get_device_image_subresource_layout(const functions&                       ext,
                                         device_handle                          device,
                                         const VkDeviceImageSubresourceInfoKHR& info,
                                         VkSubresourceLayout2KHR&               result) noexcept;

FUBUKI_EXTENSION_API void get_image_subresource_layout2(const functions&              ext,
                                                        device_handle                 device,
                                                        image_handle                  image,
                                                        const VkImageSubresource2KHR& subresource,
                                                        VkSubresourceLayout2KHR&      result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetRenderingAreaGranularityKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkExtent2D get_rendering_area_granularity(const functions&              ext,
                                                                             device_handle                 device,
                                                                             const VkRenderingAreaInfoKHR& rendering_area_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceImageSubresourceLayoutKHR.html
template<typename... elements>
[[nodiscard]]
inline VkSubresourceLayout2KHR get_device_image_subresource_layout(const functions&                       ext,
                                                                   device_handle                          device,
                                                                   const VkDeviceImageSubresourceInfoKHR& info,
                                                                   const pnext_chain<elements...>&        pnext) noexcept
{
    auto result = fubuki::make<VkSubresourceLayout2KHR>();
    fubuki::extend(result, pnext);

    detail::get_device_image_subresource_layout(ext, device, info, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceImageSubresourceLayoutKHR.html
[[nodiscard]]
inline VkSubresourceLayout2KHR
get_device_image_subresource_layout(const functions& ext, device_handle device, const VkDeviceImageSubresourceInfoKHR& info) noexcept
{
    return get_device_image_subresource_layout(ext, device, info, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageSubresourceLayout2KHR.html
template<typename... element>
[[nodiscard]] inline VkSubresourceLayout2KHR get_image_subresource_layout2(const functions&               ext,
                                                                           device_handle                  device,
                                                                           image_handle                   image,
                                                                           const VkImageSubresource2KHR&  subresource,
                                                                           const pnext_chain<element...>& pnext) noexcept
{
    auto result = fubuki::make<VkSubresourceLayout2KHR>();
    fubuki::extend(result, pnext);

    detail::get_image_subresource_layout2(ext, device, image, subresource, result);

    return result;
}
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageSubresourceLayout2KHR.html
[[nodiscard]] inline VkSubresourceLayout2KHR
get_image_subresource_layout2(const functions& ext, device_handle device, image_handle image, const VkImageSubresource2KHR& subresource) noexcept
{
    return get_image_subresource_layout2(ext, device, image, subresource, empty_pnext_chain);
}

#endif // defined(VK_KHR_maintenance5)

namespace cmd
{

#if defined(VK_KHR_maintenance5)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindIndexBuffer2KHR.html
FUBUKI_EXTENSION_API
void bind_index_buffer2(const functions&      ext,
                        command_buffer_handle command_buffer,
                        buffer_handle         buffer,
                        VkDeviceSize          offset,
                        VkDeviceSize          size,
                        VkIndexType           index_type) noexcept;

#endif // defined(VK_KHR_maintenance5)

} // namespace cmd

} // namespace fubuki::extension::khr_maintenance5

#endif // FUBUKI_EXTENSION_KHR_MAINTENANCE5_HPP
