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

#ifndef FUBUKI_EXTENSION_KHR_MAINTENANCE3_HPP
#define FUBUKI_EXTENSION_KHR_MAINTENANCE3_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_maintenance3.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_maintenance3
{

#if defined(VK_KHR_maintenance3)

namespace detail
{

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDescriptorSetLayoutSupportKHR.html
FUBUKI_EXTENSION_API void get_descriptor_set_layout_support(const functions&                       ext,
                                                            device_handle                          device,
                                                            const VkDescriptorSetLayoutCreateInfo& create_info,
                                                            VkDescriptorSetLayoutSupport&          result) noexcept;

} // namespace detail

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDescriptorSetLayoutSupportKHR.html
template<typename... elements>
[[nodiscard]] inline auto get_descriptor_set_layout_support(const functions&                       ext,
                                                            device_handle                          device,
                                                            const VkDescriptorSetLayoutCreateInfo& create_info,
                                                            const pnext_chain<elements...>&        pnext) noexcept
{
    auto result = fubuki::make<VkDescriptorSetLayoutSupport>();
    fubuki::extend(result, pnext);

    detail::get_descriptor_set_layout_support(ext, device, create_info, result);

    return result;
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDescriptorSetLayoutSupportKHR.html
[[nodiscard]] inline auto
get_descriptor_set_layout_support(const functions& ext, device_handle device, const VkDescriptorSetLayoutCreateInfo& create_info) noexcept
{
    return get_descriptor_set_layout_support(ext, device, create_info, empty_pnext_chain);
}

#endif // defined(VK_KHR_maintenance3)

} // namespace fubuki::extension::khr_maintenance3

#endif // FUBUKI_EXTENSION_KHR_MAINTENANCE3_HPP
