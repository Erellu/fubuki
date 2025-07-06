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

#ifndef FUBUKI_EXTENSION_KHR_FRAGMENT_SHADING_RATE_HPP
#define FUBUKI_EXTENSION_KHR_FRAGMENT_SHADING_RATE_HPP

#include <array>
#include <span>
#include <vector>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_fragment_shading_rate.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_fragment_shading_rate
{

#if defined(VK_KHR_fragment_shading_rate)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceFragmentShadingRatesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkPhysicalDeviceFragmentShadingRateKHR>, api_call_info>
                                   get_physical_device_fragment_shading_rates(const functions& ext, physical_device_handle physical_device);

#endif // defined(VK_KHR_fragment_shading_rate)

namespace cmd
{

#if defined(VK_KHR_fragment_shading_rate)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetFragmentShadingRateKHR.html
FUBUKI_EXTENSION_API
void set_fragment_shading_rate(const functions&                                       ext,
                               command_buffer_handle                                  command_buffer,
                               const VkExtent2D&                                      fragment_size,
                               std::span<const VkFragmentShadingRateCombinerOpKHR, 2> combiner_ops) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetFragmentShadingRateKHR.html
inline void set_fragment_shading_rate(const functions&                                  ext,
                                      command_buffer_handle                             command_buffer,
                                      const VkExtent2D&                                 fragment_size,
                                      std::array<VkFragmentShadingRateCombinerOpKHR, 2> combiner_ops) noexcept
{
    return set_fragment_shading_rate(ext, command_buffer, fragment_size, std::span{combiner_ops});
}

#endif // defined(VK_KHR_fragment_shading_rate)

} // namespace cmd

} // namespace fubuki::extension::khr_fragment_shading_rate

#endif // FUBUKI_EXTENSION_KHR_FRAGMENT_SHADING_RATE_HPP
