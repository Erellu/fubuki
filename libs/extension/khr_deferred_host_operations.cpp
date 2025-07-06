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

#include "extension/khr_deferred_host_operations.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_deferred_host_operations
{

#if defined(VK_KHR_deferred_host_operations)

namespace
{

[[nodiscard]]
std::expected<deferred_operation_khr_handle, api_call_info>
create(const functions& ext, device_handle device, const VkAllocationCallbacks* allocator) noexcept
{
    deferred_operation_khr_handle result = {};

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDeferredOperationKHR">(ext, device.vk, allocator, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // namespace

[[nodiscard]]
std::expected<deferred_operation_khr_handle, api_call_info>
create(const functions& ext, device_handle device, const VkAllocationCallbacks& allocator) noexcept
{
    return create(ext, device, std::addressof(allocator));
}

[[nodiscard]]
std::expected<deferred_operation_khr_handle, api_call_info> create(const functions& ext, device_handle device) noexcept
{
    return create(ext, device, nullptr);
}

void destroy(const functions& ext, device_handle device, deferred_operation_khr_handle& operation, const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyDeferredOperationKHR">(ext, device.vk, operation.vk, std::addressof(allocator));

    operation = null_handle;
}

void destroy(const functions& ext, device_handle device, deferred_operation_khr_handle& operation) noexcept
{
    fubuki::invoke<"vkDestroyDeferredOperationKHR">(ext, device.vk, operation.vk, nullptr);

    operation = null_handle;
}

[[nodiscard]]
std::uint32_t get_deferred_operation_max_concurrency(const functions& ext, device_handle device, deferred_operation_khr_handle operation) noexcept
{
    return fubuki::invoke<"vkGetDeferredOperationMaxConcurrencyKHR">(ext, device.vk, operation.vk);
}

[[nodiscard]]
VkResult get_deferred_operation_result(const functions& ext, device_handle device, deferred_operation_khr_handle operation) noexcept
{
    return fubuki::invoke<"vkGetDeferredOperationResultKHR">(ext, device.vk, operation.vk);
}

[[nodiscard]]
VkResult deferred_operation_join(const functions& ext, device_handle device, deferred_operation_khr_handle operation) noexcept
{
    return fubuki::invoke<"vkDeferredOperationJoinKHR">(ext, device.vk, operation.vk);
}

#endif // defined(VK_KHR_deferred_host_operations)

} // namespace fubuki::extension::khr_deferred_host_operations
