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

#include "extension/nv_cooperative_vector.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::nv_cooperative_vector
{

#if defined(VK_NV_cooperative_vector)

[[nodiscard]] std::expected<std::vector<VkCooperativeVectorPropertiesNV>, api_call_info>
get_physical_device_cooperative_vector_properties(const functions& ext, physical_device_handle physical_device) noexcept
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceCooperativeVectorPropertiesNV">(ext, physical_device.vk, std::addressof(count), nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkCooperativeVectorPropertiesNV> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceCooperativeVectorPropertiesNV">(ext, physical_device.vk, std::addressof(count), result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]] std::expected<void, api_call_info>
convert_cooperative_vector_matrix(const functions& ext, device_handle device, const VkConvertCooperativeVectorMatrixInfoNV& info) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkConvertCooperativeVectorMatrixNV">(ext, device.vk, std::addressof(info)));
}

#endif // defined(VK_NV_cooperative_vector)

namespace cmd
{

#if defined(VK_NV_cooperative_vector)

void convert_cooperative_vector_matrix(const functions&                                        ext,
                                       command_buffer_handle                                   command_buffer,
                                       std::span<const VkConvertCooperativeVectorMatrixInfoNV> infos) noexcept
{
    return fubuki::invoke<"vkCmdConvertCooperativeVectorMatrixNV">(ext, command_buffer.vk, vk_size(infos), infos.data());
}

#endif // defined(VK_NV_cooperative_vector)

} // namespace cmd

} // namespace fubuki::extension::nv_cooperative_vector
