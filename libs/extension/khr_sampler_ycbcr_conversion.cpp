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

#include "extension/khr_sampler_ycbcr_conversion.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_sampler_ycbcr_conversion
{

#if defined(VK_KHR_sampler_ycbcr_conversion)

[[nodiscard]]
std::expected<sampler_ycbcr_conversion_handle, api_call_info> create_sampler_ycbcr_conversion(const functions&                          ext,
                                                                                              device_handle                             device,
                                                                                              const VkSamplerYcbcrConversionCreateInfo& create_info,
                                                                                              const VkAllocationCallbacks& allocator) noexcept
{
    sampler_ycbcr_conversion_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateSamplerYcbcrConversionKHR">(ext, device.vk, &create_info, std::addressof(allocator), &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]] std::expected<sampler_ycbcr_conversion_handle, api_call_info>
create_sampler_ycbcr_conversion(const functions& ext, device_handle device, const VkSamplerYcbcrConversionCreateInfo& create_info) noexcept
{
    sampler_ycbcr_conversion_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateSamplerYcbcrConversionKHR">(ext, device.vk, &create_info, nullptr, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_sampler_ycbcr_conversion(const functions&                 ext,
                                      device_handle                    device,
                                      sampler_ycbcr_conversion_handle& ycbcr_conversion,
                                      const VkAllocationCallbacks&     allocator) noexcept
{
    fubuki::invoke<"vkDestroySamplerYcbcrConversionKHR">(ext, device.vk, ycbcr_conversion.vk, std::addressof(allocator));
    ycbcr_conversion = null_handle;
}

void destroy_sampler_ycbcr_conversion(const functions& ext, device_handle device, sampler_ycbcr_conversion_handle& ycbcr_conversion) noexcept
{
    fubuki::invoke<"vkDestroySamplerYcbcrConversionKHR">(ext, device.vk, ycbcr_conversion.vk, nullptr);
    ycbcr_conversion = null_handle;
}

#endif // defined(VK_KHR_sampler_ycbcr_conversion)

} // namespace fubuki::extension::khr_sampler_ycbcr_conversion
