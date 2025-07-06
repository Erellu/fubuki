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

#ifndef FUBUKI_EXTENSION_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_HPP
#define FUBUKI_EXTENSION_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_external_semaphore_capabilities.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_external_semaphore_capabilities
{

#if defined(VK_KHR_external_semaphore_capabilities)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceExternalSemaphorePropertiesKHR.html
FUBUKI_EXTENSION_API void get_physical_device_external_semaphore_properties(const functions&                             ext,
                                                                            physical_device_handle                       physical_device,
                                                                            const VkPhysicalDeviceExternalSemaphoreInfo& external_semaphore_info,
                                                                            VkExternalSemaphoreProperties&               result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceExternalSemaphorePropertiesKHR.html
template<typename... elements>
[[nodiscard]] inline auto get_physical_device_external_semaphore_properties(const functions&                             ext,
                                                                            physical_device_handle                       physical_device,
                                                                            const VkPhysicalDeviceExternalSemaphoreInfo& external_semaphore_info,
                                                                            const pnext_chain<elements...>&              pnext) noexcept
{
    auto result = fubuki::make<VkExternalSemaphoreProperties>();
    fubuki::extend(result, pnext);

    detail::get_physical_device_external_semaphore_properties(ext, physical_device, external_semaphore_info, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceExternalSemaphorePropertiesKHR.html
[[nodiscard]] inline auto get_physical_device_external_semaphore_properties(
    const functions& ext, physical_device_handle physical_device, const VkPhysicalDeviceExternalSemaphoreInfo& external_semaphore_info) noexcept
{
    return get_physical_device_external_semaphore_properties(ext, physical_device, external_semaphore_info, empty_pnext_chain);
}

#endif // defined(VK_KHR_external_semaphore_capabilities)

} // namespace fubuki::extension::khr_external_semaphore_capabilities

#endif // FUBUKI_EXTENSION_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_HPP
