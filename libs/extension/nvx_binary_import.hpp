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

#ifndef FUBUKI_EXTENSION_NVX_BINARY_IMPORT_HPP
#define FUBUKI_EXTENSION_NVX_BINARY_IMPORT_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nvx_binary_import.hpp" // IWYU pragma: export

namespace fubuki::extension::nvx_binary_import
{

#if defined(VK_NVX_binary_import)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCuModuleNVX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cu_module_nvx_handle, api_call_info> create_cu_module(
    const functions& ext, device_handle device, const VkCuModuleCreateInfoNVX& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCuModuleNVX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cu_module_nvx_handle, api_call_info>
                                   create_cu_module(const functions& ext, device_handle device, const VkCuModuleCreateInfoNVX& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCuFunctionNVX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cu_function_nvx_handle, api_call_info> create_cu_function(
    const functions& ext, device_handle device, const VkCuFunctionCreateInfoNVX& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCuFunctionNVX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cu_function_nvx_handle, api_call_info>
create_cu_function(const functions& ext, device_handle device, const VkCuFunctionCreateInfoNVX& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCuModuleNVX.html
FUBUKI_EXTENSION_API
void destroy_cu_module(const functions& ext, device_handle device, cu_module_nvx_handle& module, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCuModuleNVX.html
FUBUKI_EXTENSION_API
void destroy_cu_module(const functions& ext, device_handle device, cu_module_nvx_handle& module) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCuFunctionNVX.html
FUBUKI_EXTENSION_API
void destroy_cu_function(const functions&             ext,
                         device_handle                device,
                         cu_function_nvx_handle&      function,
                         const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCuFunctionNVX.html
FUBUKI_EXTENSION_API
void destroy_cu_function(const functions& ext, device_handle device, cu_function_nvx_handle& function) noexcept;

#endif // defined(VK_NVX_binary_import)

namespace cmd
{

#if defined(VK_NVX_binary_import)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCuLaunchKernelNVX.html
FUBUKI_EXTENSION_API
void cu_launch_kernel(const functions& ext, command_buffer_handle command_buffer, const VkCuLaunchInfoNVX& launch_info) noexcept;

#endif // defined(VK_NVX_binary_import)

} // namespace cmd

} // namespace fubuki::extension::nvx_binary_import

#endif // FUBUKI_EXTENSION_NVX_BINARY_IMPORT_HPP
