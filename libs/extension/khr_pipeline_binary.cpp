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

#include "extension/khr_pipeline_binary.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_pipeline_binary::detail
{

#if defined(VK_KHR_pipeline_binary)

[[nodiscard]] std::expected<void, api_call_info>
get_pipeline_key(const functions& ext, device_handle device, const VkPipelineCreateInfoKHR& info, VkPipelineBinaryKeyKHR& result) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineKeyKHR">(ext, device.vk, std::addressof(info), std::addressof(result)));
}

[[nodiscard]] std::expected<binary_data, api_call_info>
get_pipeline_binary_data(const functions& ext, device_handle device, const VkPipelineBinaryDataInfoKHR& info) noexcept
{
    binary_data result = {};

    std::size_t binaries_size = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineBinaryDataKHR">(ext, device.vk, std::addressof(info), std::addressof(result.key), std::addressof(binaries_size), nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    result.contents.resize(binaries_size);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineBinaryDataKHR">(ext, device.vk, std::addressof(info), std::addressof(result.key), std::addressof(binaries_size), result.contents.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]] std::expected<small_vector<pipeline_binary_khr_handle>, api_call_info> create_pipeline_binaries(
    const functions& ext, device_handle device, const VkPipelineBinaryCreateInfoKHR& create_info, const VkAllocationCallbacks* allocator) noexcept
{
    VkPipelineBinaryHandlesInfoKHR binaries_info = {
        .sType               = structure_type_v<VkPipelineBinaryHandlesInfoKHR>,
        .pNext               = {},
        .pipelineBinaryCount = 0,
        .pPipelineBinaries   = nullptr,
    };

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreatePipelineBinariesKHR">(ext, device.vk, std::addressof(create_info), allocator, std::addressof(binaries_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkPipelineBinaryKHR> result;
    result.resize(binaries_info.pipelineBinaryCount);

    binaries_info.pPipelineBinaries = result.data();

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreatePipelineBinariesKHR">(ext, device.vk, std::addressof(create_info), allocator, std::addressof(binaries_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<pipeline_binary_khr_handle>{result.begin(), result.end()};
}

void destroy_pipeline_binaries(const functions&                      ext,
                               device_handle                         device,
                               std::span<pipeline_binary_khr_handle> pipeline_binaries,
                               const VkAllocationCallbacks*          allocator) noexcept
{
    for(auto& b : pipeline_binaries)
    {
        fubuki::invoke<"vkDestroyPipelineBinaryKHR">(ext, device.vk, b.vk, allocator);
        b = null_handle;
    }
}

[[nodiscard]] std::expected<void, api_call_info> release_captured_pipeline_data(const functions&                            ext,
                                                                                device_handle                               device,
                                                                                const VkReleaseCapturedPipelineDataInfoKHR& info,
                                                                                const VkAllocationCallbacks*                allocator) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkReleaseCapturedPipelineDataKHR">(ext, device.vk, std::addressof(info), allocator));
}

#endif // defined(VK_KHR_pipeline_binary)

} // namespace fubuki::extension::khr_pipeline_binary::detail
