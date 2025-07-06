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

#include "extension/functions/khr_ray_tracing_pipeline.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
khr_ray_tracing_pipeline khr_ray_tracing_pipeline::load([[maybe_unused]] instance_handle instance,
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
#if defined(VK_KHR_ray_tracing_pipeline)
        .create_ray_tracing_pipelines_khr = pfn<"vkCreateRayTracingPipelinesKHR">(instance, device, device_get),
        .get_ray_tracing_shader_group_handles_khr = pfn<"vkGetRayTracingShaderGroupHandlesKHR">(instance, device, device_get),
        .get_ray_tracing_capture_replay_shader_group_handles_khr = pfn<"vkGetRayTracingCaptureReplayShaderGroupHandlesKHR">(instance, device, device_get),
        .get_ray_tracing_shader_group_stack_size_khr = pfn<"vkGetRayTracingShaderGroupStackSizeKHR">(instance, device, device_get),

        .cmd =
        {
            .trace_rays_khr = pfn<"vkCmdTraceRaysKHR">(instance, device, device_get),
            .trace_rays_indirect_khr = pfn<"vkCmdTraceRaysIndirectKHR">(instance, device, device_get),
            .set_ray_tracing_pipeline_stack_size_khr = pfn<"vkCmdSetRayTracingPipelineStackSizeKHR">(instance, device, device_get),

        },
#endif // defined(VK_KHR_ray_tracing_pipeline)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
