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

#include "extension/nv_cuda_kernel_launch.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::nv_cuda_kernel_launch
{

#if defined(VK_NV_cuda_kernel_launch)

[[nodiscard]]
std::expected<cuda_module_nv_handle, api_call_info> create_cuda_module(const functions&                ext,
                                                                       device_handle                   device,
                                                                       const VkCudaModuleCreateInfoNV& create_info,
                                                                       const VkAllocationCallbacks&    allocator) noexcept
{
    cuda_module_nv_handle result;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCudaModuleNV">(ext, device.vk, std::addressof(create_info), std::addressof(allocator), std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<cuda_module_nv_handle, api_call_info>
create_cuda_module(const functions& ext, device_handle device, const VkCudaModuleCreateInfoNV& create_info) noexcept
{
    cuda_module_nv_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCudaModuleNV">(ext, device.vk, std::addressof(create_info), nullptr, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<std::vector<std::byte>, api_call_info> get_cuda_module_cache(const functions& ext, device_handle device, VkCudaModuleNV module)
{
    std::size_t byte_count = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetCudaModuleCacheNV">(ext, device.vk, module, &byte_count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<std::byte> result;
    result.resize(byte_count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetCudaModuleCacheNV">(ext, device.vk, module, &byte_count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<cuda_function_nv_handle, api_call_info> create_cuda_function(const functions&                  ext,
                                                                           device_handle                     device,
                                                                           const VkCudaFunctionCreateInfoNV& create_info,
                                                                           const VkAllocationCallbacks&      allocator) noexcept
{
    cuda_function_nv_handle result;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCudaFunctionNV">(ext, device.vk, std::addressof(create_info), std::addressof(allocator), std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<cuda_function_nv_handle, api_call_info>
create_cuda_function(const functions& ext, device_handle device, const VkCudaFunctionCreateInfoNV& create_info) noexcept
{
    cuda_function_nv_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCudaFunctionNV">(ext, device.vk, std::addressof(create_info), nullptr, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_cuda_module(const functions& ext, device_handle device, cuda_module_nv_handle& module, const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyCudaModuleNV">(ext, device.vk, module.vk, std::addressof(allocator));
    module = null_handle;
}

void destroy_cuda_module(const functions& ext, device_handle device, cuda_module_nv_handle& module) noexcept
{
    fubuki::invoke<"vkDestroyCudaModuleNV">(ext, device.vk, module.vk, nullptr);
    module = null_handle;
}

void destroy_cuda_function(const functions&             ext,
                           device_handle                device,
                           cuda_function_nv_handle&     function,
                           const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyCudaFunctionNV">(ext, device.vk, function.vk, std::addressof(allocator));
    function = null_handle;
}

void destroy_cuda_function(const functions& ext, device_handle device, cuda_function_nv_handle& function) noexcept
{
    fubuki::invoke<"vkDestroyCudaFunctionNV">(ext, device.vk, function.vk, nullptr);
    function = null_handle;
}

#endif // defined(VK_NV_cuda_kernel_launch)

namespace cmd
{

#if defined(VK_NV_cuda_kernel_launch)

void cuda_launch_kernel(const functions& ext, command_buffer_handle command_buffer, const VkCudaLaunchInfoNV& launch_info) noexcept
{
    return fubuki::invoke<"vkCmdCudaLaunchKernelNV">(ext, command_buffer.vk, &launch_info);
}

#endif // defined(VK_NV_cuda_kernel_launch)

} // namespace cmd

} // namespace fubuki::extension::nv_cuda_kernel_launch
