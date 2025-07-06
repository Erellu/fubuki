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

#include "extension/khr_maintenance5.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_maintenance5
{

#if defined(VK_KHR_maintenance5)

namespace detail
{

void get_device_image_subresource_layout(const functions&                       ext,
                                         device_handle                          device,
                                         const VkDeviceImageSubresourceInfoKHR& info,
                                         VkSubresourceLayout2KHR&               result) noexcept
{
    return fubuki::invoke<"vkGetDeviceImageSubresourceLayoutKHR">(ext, device.vk, std::addressof(info), &result);
}

void get_image_subresource_layout2(const functions&              ext,
                                   device_handle                 device,
                                   image_handle                  image,
                                   const VkImageSubresource2KHR& subresource,
                                   VkSubresourceLayout2KHR&      result) noexcept
{
    return fubuki::invoke<"vkGetImageSubresourceLayout2KHR">(ext, device.vk, image.vk, &subresource, &result);
}

} // namespace detail

[[nodiscard]]
VkExtent2D get_rendering_area_granularity(const functions& ext, device_handle device, const VkRenderingAreaInfoKHR& rendering_area_info) noexcept
{
    VkExtent2D result = {};

    fubuki::invoke<"vkGetRenderingAreaGranularityKHR">(ext, device.vk, &rendering_area_info, std::addressof(result));

    return result;
}

#endif // defined(VK_KHR_maintenance5)

namespace cmd
{

#if defined(VK_KHR_maintenance5)

void bind_index_buffer2(const functions&      ext,
                        command_buffer_handle command_buffer,
                        buffer_handle         buffer,
                        VkDeviceSize          offset,
                        VkDeviceSize          size,
                        VkIndexType           index_type) noexcept
{
    return fubuki::invoke<"vkCmdBindIndexBuffer2KHR">(ext, command_buffer.vk, buffer.vk, offset, size, index_type);
}

#endif // defined(VK_KHR_maintenance5)

} // namespace cmd

} // namespace fubuki::extension::khr_maintenance5
