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

#include "extension/functions/intel_performance_query.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
intel_performance_query intel_performance_query::load([[maybe_unused]] instance_handle instance,
                                                      [[maybe_unused]] version_number  vk_version,
                                                      [[maybe_unused]] device_handle   device) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");
    fubuki_assert(device != null_handle, "Device cannot be null_handle.");

    [[maybe_unused]] auto* const device_get = pfn<"vkGetDeviceProcAddr">(instance);
    fubuki_assert(device_get != nullptr, "Could not retrieve vkGetDeviceProcAddr function pointer.");

    // clang-format off
    return
    {
#if defined(VK_INTEL_performance_query)
        .initialize_performance_api_intel = pfn<"vkInitializePerformanceApiINTEL">(instance, device, device_get),
        .uninitialize_performance_api_intel = pfn<"vkUninitializePerformanceApiINTEL">(instance, device, device_get),
        .acquire_performance_configuration_intel = pfn<"vkAcquirePerformanceConfigurationINTEL">(instance, device, device_get),
        .release_performance_configuration_intel = pfn<"vkReleasePerformanceConfigurationINTEL">(instance, device, device_get),
        .queue_set_performance_configuration_intel = pfn<"vkQueueSetPerformanceConfigurationINTEL">(instance, device, device_get),
        .get_performance_parameter_intel = pfn<"vkGetPerformanceParameterINTEL">(instance, device, device_get),

        .cmd =
        {
            .set_performance_marker_intel = pfn<"vkCmdSetPerformanceMarkerINTEL">(instance, device, device_get),
            .set_performance_stream_marker_intel = pfn<"vkCmdSetPerformanceStreamMarkerINTEL">(instance, device, device_get),
            .set_performance_override_intel = pfn<"vkCmdSetPerformanceOverrideINTEL">(instance, device, device_get),

        },
#endif // defined(VK_INTEL_performance_query)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
