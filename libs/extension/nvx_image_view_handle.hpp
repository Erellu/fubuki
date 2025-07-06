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

#ifndef FUBUKI_EXTENSION_NVX_IMAGE_VIEW_HANDLE_HPP
#define FUBUKI_EXTENSION_NVX_IMAGE_VIEW_HANDLE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nvx_image_view_handle.hpp" // IWYU pragma: export

namespace fubuki::extension::nvx_image_view_handle
{

#if defined(VK_NVX_image_view_handle)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageViewHandleNVX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::uint32_t
                                   get_image_view_handle(const functions& ext, device_handle device, const VkImageViewHandleInfoNVX& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageViewHandle64NVX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::uint64_t
get_image_view_handle_64(const functions& ext, device_handle device, const VkImageViewHandleInfoNVX& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageViewAddressNVX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<VkImageViewAddressPropertiesNVX, api_call_info>
                                   get_image_view_address(const functions& ext, device_handle device, image_view_handle image_view) noexcept;

#endif // defined(VK_NVX_image_view_handle)

} // namespace fubuki::extension::nvx_image_view_handle

#endif // FUBUKI_EXTENSION_NVX_IMAGE_VIEW_HANDLE_HPP
