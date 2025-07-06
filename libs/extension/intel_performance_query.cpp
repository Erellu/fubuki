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

#include "extension/intel_performance_query.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::intel_performance_query
{

#if defined(VK_INTEL_performance_query)

[[nodiscard]]
std::expected<void, api_call_info>
initialize_performance_api(const functions& ext, device_handle device, const VkInitializePerformanceApiInfoINTEL& initialize_info) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkInitializePerformanceApiINTEL">(ext, device.vk, std::addressof(initialize_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

void uninitialize_performance_api(const functions& ext, device_handle device) noexcept
{
    return fubuki::invoke<"vkUninitializePerformanceApiINTEL">(ext, device.vk);
}

[[nodiscard]]
std::expected<performance_configuration_intel_handle, api_call_info>
acquire_performance_configuration(const functions& ext, device_handle device, const VkPerformanceConfigurationAcquireInfoINTEL& acquire_info) noexcept
{
    performance_configuration_intel_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkAcquirePerformanceConfigurationINTEL">(ext, device.vk, &acquire_info, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<void, api_call_info>
release_performance_configuration(const functions& ext, device_handle device, performance_configuration_intel_handle& configuration) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected,fubuki::invoke<"vkReleasePerformanceConfigurationINTEL">(ext, device.vk, configuration.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    configuration = null_handle;

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info>
queue_set_performance_configuration(const functions& ext, queue_handle queue, performance_configuration_intel_handle configuration) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkQueueSetPerformanceConfigurationINTEL">(ext, queue.vk, configuration.vk));
}

[[nodiscard]]
std::expected<VkPerformanceValueINTEL, api_call_info>
get_performance_parameter(const functions& ext, device_handle device, VkPerformanceParameterTypeINTEL parameter) noexcept
{
    VkPerformanceValueINTEL result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPerformanceParameterINTEL">(ext, device.vk, parameter, std::addressof(result))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_INTEL_performance_query)

namespace cmd
{

#if defined(VK_INTEL_performance_query)

[[nodiscard]]
std::expected<void, api_call_info>
set_performance_marker(const functions& ext, command_buffer_handle command_buffer, const VkPerformanceMarkerInfoINTEL& marker_info) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkCmdSetPerformanceMarkerINTEL">(ext, command_buffer.vk, std::addressof(marker_info)));
}

[[nodiscard]]
std::expected<void, api_call_info> set_performance_stream_marker(const functions&                          ext,
                                                                 command_buffer_handle                     command_buffer,
                                                                 const VkPerformanceStreamMarkerInfoINTEL& marker_info) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkCmdSetPerformanceStreamMarkerINTEL">(ext, command_buffer.vk, std::addressof(marker_info)));
}

[[nodiscard]]
std::expected<void, api_call_info>
set_performance_override(const functions& ext, command_buffer_handle command_buffer, const VkPerformanceOverrideInfoINTEL& override_info) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkCmdSetPerformanceOverrideINTEL">(ext, command_buffer.vk, &override_info));
}

#endif // defined(VK_INTEL_performance_query)

} // namespace cmd

} // namespace fubuki::extension::intel_performance_query
