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

#ifndef FUBUKI_EXTENSION_KHR_BUFFER_DEVICE_ADDRESS_HPP
#define FUBUKI_EXTENSION_KHR_BUFFER_DEVICE_ADDRESS_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_buffer_device_address.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_buffer_device_address
{

#if defined(VK_KHR_buffer_device_address)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferDeviceAddressKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkDeviceAddress get_buffer_device_address(const functions&                 ext,
                                                                             device_handle                    device,
                                                                             const VkBufferDeviceAddressInfo& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferOpaqueCaptureAddressKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::uint64_t
get_buffer_opaque_capture_address(const functions& ext, device_handle device, const VkBufferDeviceAddressInfo& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceMemoryOpaqueCaptureAddressKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::uint64_t
get_device_memory_opaque_capture_address(const functions& ext, device_handle device, const VkDeviceMemoryOpaqueCaptureAddressInfo& info) noexcept;

#endif // defined(VK_KHR_buffer_device_address)

} // namespace fubuki::extension::khr_buffer_device_address

#endif // FUBUKI_EXTENSION_KHR_BUFFER_DEVICE_ADDRESS_HPP
