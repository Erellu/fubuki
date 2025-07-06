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

#ifndef FUBUKI_EXTENSION_KHR_DEFERRED_HOST_OPERATIONS_HPP
#define FUBUKI_EXTENSION_KHR_DEFERRED_HOST_OPERATIONS_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_deferred_host_operations.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_deferred_host_operations
{

#if defined(VK_KHR_deferred_host_operations)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateDeferredOperationKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<deferred_operation_khr_handle, api_call_info>
                                   create(const functions& ext, device_handle device, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateDeferredOperationKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<deferred_operation_khr_handle, api_call_info> create(const functions& ext,
                                                                                                      device_handle    device) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyDeferredOperationKHR.html
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, deferred_operation_khr_handle& operation, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyDeferredOperationKHR.html
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, deferred_operation_khr_handle& operation) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeferredOperationMaxConcurrencyKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::uint32_t
get_deferred_operation_max_concurrency(const functions& ext, device_handle device, deferred_operation_khr_handle operation) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeferredOperationResultKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkResult get_deferred_operation_result(const functions&              ext,
                                                                          device_handle                 device,
                                                                          deferred_operation_khr_handle operation) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDeferredOperationJoinKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkResult deferred_operation_join(const functions&              ext,
                                                                    device_handle                 device,
                                                                    deferred_operation_khr_handle operation) noexcept;

#endif // defined(VK_KHR_deferred_host_operations)

} // namespace fubuki::extension::khr_deferred_host_operations

#endif // FUBUKI_EXTENSION_KHR_DEFERRED_HOST_OPERATIONS_HPP
