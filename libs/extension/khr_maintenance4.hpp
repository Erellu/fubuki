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

#ifndef FUBUKI_EXTENSION_KHR_MAINTENANCE4_HPP
#define FUBUKI_EXTENSION_KHR_MAINTENANCE4_HPP

#include <vector>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_maintenance4.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_maintenance4
{

#if defined(VK_KHR_maintenance4)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceBufferMemoryRequirementsKHR.html
FUBUKI_EXTENSION_API
void get_device_buffer_memory_requirements(const functions&                        ext,
                                           device_handle                           device,
                                           const VkDeviceBufferMemoryRequirements& info,
                                           VkMemoryRequirements2&                  result) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceImageMemoryRequirementsKHR.html
FUBUKI_EXTENSION_API
void get_device_image_memory_requirements(const functions&                       ext,
                                          device_handle                          device,
                                          const VkDeviceImageMemoryRequirements& info,
                                          VkMemoryRequirements2&                 result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceBufferMemoryRequirementsKHR.html

template<typename... elements>
[[nodiscard]] inline auto get_device_buffer_memory_requirements(const functions&                        ext,
                                                                device_handle                           device,
                                                                const VkDeviceBufferMemoryRequirements& info,
                                                                const pnext_chain<elements...>&         pnext) noexcept
{
    auto result = fubuki::make<VkMemoryRequirements2>();
    fubuki::extend(result, pnext);

    detail::get_device_buffer_memory_requirements(ext, device, info, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceBufferMemoryRequirementsKHR.html
[[nodiscard]] inline auto
get_device_buffer_memory_requirements(const functions& ext, device_handle device, const VkDeviceBufferMemoryRequirements& info) noexcept
{
    return get_device_buffer_memory_requirements(ext, device, info, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceImageMemoryRequirementsKHR.html
template<typename... elements>
[[nodiscard]] inline auto get_device_image_memory_requirements(const functions&                       ext,
                                                               device_handle                          device,
                                                               const VkDeviceImageMemoryRequirements& info,
                                                               const pnext_chain<elements...>&        pnext) noexcept
{
    auto result = fubuki::make<VkMemoryRequirements2>();
    fubuki::extend(result, pnext);

    detail::get_device_image_memory_requirements(ext, device, info, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceImageMemoryRequirementsKHR.html
[[nodiscard]] inline auto
get_device_image_memory_requirements(const functions& ext, device_handle device, const VkDeviceImageMemoryRequirements& info) noexcept
{
    return get_device_image_memory_requirements(ext, device, info, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceImageSparseMemoryRequirementsKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::vector<VkSparseImageMemoryRequirements2>
get_device_image_sparse_memory_requirements(const functions& ext, device_handle device, const VkDeviceImageMemoryRequirements& info);

#endif // defined(VK_KHR_maintenance4)

} // namespace fubuki::extension::khr_maintenance4

#endif // FUBUKI_EXTENSION_KHR_MAINTENANCE4_HPP
