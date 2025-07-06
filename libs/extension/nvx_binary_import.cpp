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

#include "extension/nvx_binary_import.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::nvx_binary_import
{

#if defined(VK_NVX_binary_import)

[[nodiscard]]
std::expected<cu_module_nvx_handle, api_call_info> create_cu_module(const functions&               ext,
                                                                    device_handle                  device,
                                                                    const VkCuModuleCreateInfoNVX& create_info,
                                                                    const VkAllocationCallbacks&   allocator) noexcept
{
    cu_module_nvx_handle result = {};

    const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCuModuleNVX">(ext, device.vk, std::addressof(create_info), std::addressof(allocator), std::addressof(result.vk)));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<cu_module_nvx_handle, api_call_info>
create_cu_module(const functions& ext, device_handle device, const VkCuModuleCreateInfoNVX& create_info) noexcept
{
    cu_module_nvx_handle result = {};

    const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCuModuleNVX">(ext, device.vk, std::addressof(create_info), nullptr, std::addressof(result.vk)));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<cu_function_nvx_handle, api_call_info> create_cu_function(const functions&                 ext,
                                                                        device_handle                    device,
                                                                        const VkCuFunctionCreateInfoNVX& create_info,
                                                                        const VkAllocationCallbacks&     allocator) noexcept
{
    cu_function_nvx_handle result = {};

    const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCuFunctionNVX">(ext, device.vk, std::addressof(create_info), std::addressof(allocator), std::addressof(result.vk)));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<cu_function_nvx_handle, api_call_info>
create_cu_function(const functions& ext, device_handle device, const VkCuFunctionCreateInfoNVX& create_info) noexcept
{
    cu_function_nvx_handle result = {};

    const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateCuFunctionNVX">(ext, device.vk, std::addressof(create_info), nullptr, std::addressof(result.vk)));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_cu_module(const functions& ext, device_handle device, cu_module_nvx_handle& module, const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyCuModuleNVX">(ext, device.vk, module.vk, std::addressof(allocator));

    module = null_handle;
}

void destroy_cu_module(const functions& ext, device_handle device, cu_module_nvx_handle& module) noexcept
{
    fubuki::invoke<"vkDestroyCuModuleNVX">(ext, device.vk, module.vk, nullptr);

    module = null_handle;
}

void destroy_cu_function(const functions&             ext,
                         device_handle                device,
                         cu_function_nvx_handle&      function,
                         const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyCuFunctionNVX">(ext, device.vk, function.vk, std::addressof(allocator));

    function = null_handle;
}

void destroy_cu_function(const functions& ext, device_handle device, cu_function_nvx_handle& function) noexcept
{
    fubuki::invoke<"vkDestroyCuFunctionNVX">(ext, device.vk, function.vk, nullptr);

    function = null_handle;
}

#endif // defined(VK_NVX_binary_import)

namespace cmd
{

#if defined(VK_NVX_binary_import)

void cu_launch_kernel(const functions& ext, command_buffer_handle command_buffer, const VkCuLaunchInfoNVX& launch_info) noexcept
{
    return fubuki::invoke<"vkCmdCuLaunchKernelNVX">(ext, command_buffer.vk, &launch_info);
}

#endif // defined(VK_NVX_binary_import)

} // namespace cmd

} // namespace fubuki::extension::nvx_binary_import
