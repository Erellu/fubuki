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

#ifndef FUBUKI_EXTENSION_INTEL_PERFORMANCE_QUERY_HPP
#define FUBUKI_EXTENSION_INTEL_PERFORMANCE_QUERY_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/intel_performance_query.hpp" // IWYU pragma: export

namespace fubuki::extension::intel_performance_query
{

#if defined(VK_INTEL_performance_query)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkInitializePerformanceApiINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
initialize_performance_api(const functions& ext, device_handle device, const VkInitializePerformanceApiInfoINTEL& initialize_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUninitializePerformanceApiINTEL.html
FUBUKI_EXTENSION_API
void uninitialize_performance_api(const functions& ext, device_handle device) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkAcquirePerformanceConfigurationINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<performance_configuration_intel_handle, api_call_info> acquire_performance_configuration(
    const functions& ext, device_handle device, const VkPerformanceConfigurationAcquireInfoINTEL& acquire_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleasePerformanceConfigurationINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
release_performance_configuration(const functions& ext, device_handle device, performance_configuration_intel_handle& configuration) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSetPerformanceConfigurationINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
queue_set_performance_configuration(const functions& ext, queue_handle queue, performance_configuration_intel_handle configuration) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPerformanceParameterINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<VkPerformanceValueINTEL, api_call_info>
get_performance_parameter(const functions& ext, device_handle device, VkPerformanceParameterTypeINTEL parameter) noexcept;

#endif // defined(VK_INTEL_performance_query)

namespace cmd
{

#if defined(VK_INTEL_performance_query)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPerformanceMarkerINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
set_performance_marker(const functions& ext, command_buffer_handle command_buffer, const VkPerformanceMarkerInfoINTEL& marker_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPerformanceStreamMarkerINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> set_performance_stream_marker(
    const functions& ext, command_buffer_handle command_buffer, const VkPerformanceStreamMarkerInfoINTEL& marker_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPerformanceOverrideINTEL.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
set_performance_override(const functions& ext, command_buffer_handle command_buffer, const VkPerformanceOverrideInfoINTEL& override_info) noexcept;

#endif // defined(VK_INTEL_performance_query)

} // namespace cmd

} // namespace fubuki::extension::intel_performance_query

#endif // FUBUKI_EXTENSION_INTEL_PERFORMANCE_QUERY_HPP
