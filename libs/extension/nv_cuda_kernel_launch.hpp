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

#ifndef FUBUKI_EXTENSION_NV_CUDA_KERNEL_LAUNCH_HPP
#define FUBUKI_EXTENSION_NV_CUDA_KERNEL_LAUNCH_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_cuda_kernel_launch.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_cuda_kernel_launch
{

#if defined(VK_NV_cuda_kernel_launch)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCudaModuleNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cuda_module_nv_handle, api_call_info> create_cuda_module(
    const functions& ext, device_handle device, const VkCudaModuleCreateInfoNV& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCudaModuleNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cuda_module_nv_handle, api_call_info>
create_cuda_module(const functions& ext, device_handle device, const VkCudaModuleCreateInfoNV& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetCudaModuleCacheNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<std::byte>, api_call_info>
                                   get_cuda_module_cache(const functions& ext, device_handle device, VkCudaModuleNV module);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCudaFunctionNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cuda_function_nv_handle, api_call_info> create_cuda_function(
    const functions& ext, device_handle device, const VkCudaFunctionCreateInfoNV& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateCudaFunctionNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<cuda_function_nv_handle, api_call_info>
create_cuda_function(const functions& ext, device_handle device, const VkCudaFunctionCreateInfoNV& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCudaModuleNV.html
FUBUKI_EXTENSION_API
void destroy_cuda_module(const functions& ext, device_handle device, cuda_module_nv_handle& module, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCudaModuleNV.html
FUBUKI_EXTENSION_API
void destroy_cuda_module(const functions& ext, device_handle device, cuda_module_nv_handle& module) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCudaFunctionNV.html
FUBUKI_EXTENSION_API
void destroy_cuda_function(const functions& ext, device_handle device, cuda_function_nv_handle& function) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyCudaFunctionNV.html
FUBUKI_EXTENSION_API
void destroy_cuda_function(const functions&             ext,
                           device_handle                device,
                           cuda_function_nv_handle&     function,
                           const VkAllocationCallbacks& allocator) noexcept;

#endif // defined(VK_NV_cuda_kernel_launch)

namespace cmd
{

#if defined(VK_NV_cuda_kernel_launch)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCudaLaunchKernelNV.html
FUBUKI_EXTENSION_API
void cuda_launch_kernel(const functions& ext, command_buffer_handle command_buffer, const VkCudaLaunchInfoNV& launch_info) noexcept;

#endif // defined(VK_NV_cuda_kernel_launch)

} // namespace cmd

} // namespace fubuki::extension::nv_cuda_kernel_launch

#endif // FUBUKI_EXTENSION_NV_CUDA_KERNEL_LAUNCH_HPP
