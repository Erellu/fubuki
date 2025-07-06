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

#include "extension/khr_pipeline_executable_properties.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_pipeline_executable_properties
{

#if defined(VK_KHR_pipeline_executable_properties)

[[nodiscard]]
std::expected<std::vector<VkPipelineExecutablePropertiesKHR>, api_call_info>
get_pipeline_executable_properties(const functions& ext, device_handle device, const VkPipelineInfoKHR& pipeline_info)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineExecutablePropertiesKHR">(ext, device.vk, &pipeline_info, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkPipelineExecutablePropertiesKHR> result;
    result.resize(count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineExecutablePropertiesKHR">(ext, device.vk, &pipeline_info, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<std::vector<VkPipelineExecutableStatisticKHR>, api_call_info>
get_pipeline_executable_statistics(const functions& ext, device_handle device, const VkPipelineExecutableInfoKHR& executable_info)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineExecutableStatisticsKHR">(ext, device.vk, &executable_info, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }
    std::vector<VkPipelineExecutableStatisticKHR> result;
    result.resize(count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineExecutableStatisticsKHR">(ext, device.vk, &executable_info, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<std::vector<VkPipelineExecutableInternalRepresentationKHR>, api_call_info>
get_pipeline_executable_internal_representations(const functions& ext, device_handle device, const VkPipelineExecutableInfoKHR& executable_info)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineExecutableInternalRepresentationsKHR">(ext, device.vk, &executable_info, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkPipelineExecutableInternalRepresentationKHR> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPipelineExecutableInternalRepresentationsKHR">(ext, device.vk, &executable_info, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_KHR_pipeline_executable_properties)

} // namespace fubuki::extension::khr_pipeline_executable_properties
