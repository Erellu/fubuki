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

#ifndef FUBUKI_EXTENSION_KHR_RAY_TRACING_PIPELINE_HPP
#define FUBUKI_EXTENSION_KHR_RAY_TRACING_PIPELINE_HPP

#include <core/as_span.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_ray_tracing_pipeline.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_ray_tracing_pipeline
{

#if defined(VK_KHR_ray_tracing_pipeline)

/// Binding table for ray tracing shaders.
struct binding_table
{
    VkStridedDeviceAddressRegionKHR ray_gen  = {}; ///< The table for the ray generation shader stage.
    VkStridedDeviceAddressRegionKHR miss     = {}; ///< The table for the miss shader stage.
    VkStridedDeviceAddressRegionKHR hit      = {}; ///< The table for the hit shader stage.
    VkStridedDeviceAddressRegionKHR callable = {}; ///< The table for the callable shader stage.
};

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRayTracingPipelinesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<ray_tracing_pipeline_khr_handle>, api_call_info>
                                   create(const functions&                                   ext,
                                          device_handle                                      device,
                                          deferred_operation_khr_handle                      deferred_operation,
                                          pipeline_cache_handle                              pipeline_cache,
                                          std::span<const VkRayTracingPipelineCreateInfoKHR> create_infos,
                                          const VkAllocationCallbacks&                       allocator);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRayTracingPipelinesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<ray_tracing_pipeline_khr_handle>, api_call_info>
                                   create(const functions&                                   ext,
                                          device_handle                                      device,
                                          deferred_operation_khr_handle                      deferred_operation,
                                          pipeline_cache_handle                              pipeline_cache,
                                          std::span<const VkRayTracingPipelineCreateInfoKHR> create_infos);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRayTracingPipelinesKHR.html
[[nodiscard]]
inline std::expected<ray_tracing_pipeline_khr_handle, api_call_info> create(const functions&                         ext,
                                                                            device_handle                            device,
                                                                            deferred_operation_khr_handle            deferred_operation,
                                                                            pipeline_cache_handle                    pipeline_cache,
                                                                            const VkRayTracingPipelineCreateInfoKHR& create_info,
                                                                            const VkAllocationCallbacks&             allocator) noexcept
{
    const auto result = create(ext, device, deferred_operation, pipeline_cache, fubuki::as_span(create_info), allocator);

    if(not result)
    {
        return std::unexpected{result.error()};
    }

    return (*result)[0];
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRayTracingPipelinesKHR.html
[[nodiscard]]
inline std::expected<ray_tracing_pipeline_khr_handle, api_call_info> create(const functions&                         ext,
                                                                            device_handle                            device,
                                                                            deferred_operation_khr_handle            deferred_operation,
                                                                            pipeline_cache_handle                    pipeline_cache,
                                                                            const VkRayTracingPipelineCreateInfoKHR& create_info)
{
    const auto result = create(ext, device, deferred_operation, pipeline_cache, fubuki::as_span(create_info));

    if(not result)
    {
        return std::unexpected{result.error()};
    }

    return (*result)[0];
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetRayTracingCaptureReplayShaderGroupHandlesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   get_ray_tracing_capture_replay_shader_group_handles(const functions&                ext,
                                                                                       device_handle                   device,
                                                                                       ray_tracing_pipeline_khr_handle pipeline,
                                                                                       std::uint32_t                   first_group,
                                                                                       std::uint32_t                   group_count,
                                                                                       std::span<std::byte>            data) noexcept;

template<typename T>
[[nodiscard]]
inline auto get_ray_tracing_capture_replay_shader_group_handles(const functions&                ext,
                                                                device_handle                   device,
                                                                ray_tracing_pipeline_khr_handle pipeline,
                                                                std::uint32_t                   first_group,
                                                                std::uint32_t                   group_count,
                                                                std::span<T>                    data)
{
    return get_ray_tracing_capture_replay_shader_group_handles(ext, device, pipeline, first_group, group_count, std::as_bytes(data));
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetRayTracingShaderGroupStackSizeKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkDeviceSize get_ray_tracing_shader_group_stack_size(const functions&                ext,
                                                                                        device_handle                   device,
                                                                                        ray_tracing_pipeline_khr_handle pipeline,
                                                                                        std::uint32_t                   group,
                                                                                        VkShaderGroupShaderKHR          group_shader) noexcept;

#endif // defined(VK_KHR_ray_tracing_pipeline)

namespace cmd
{

#if defined(VK_KHR_ray_tracing_pipeline)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdTraceRaysKHR.html
FUBUKI_EXTENSION_API
void trace_rays(const functions&      ext,
                command_buffer_handle command_buffer,
                const binding_table&  table,
                std::uint32_t         width,
                std::uint32_t         height,
                std::uint32_t         depth) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdTraceRaysIndirectKHR.html
FUBUKI_EXTENSION_API
void trace_rays_indirect(const functions&      ext,
                         command_buffer_handle command_buffer,
                         const binding_table&  table,
                         VkDeviceAddress       indirect_device_address) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRayTracingPipelineStackSizeKHR.html
FUBUKI_EXTENSION_API
void set_ray_tracing_pipeline_stack_size(const functions& ext, command_buffer_handle command_buffer, std::uint32_t pipeline_stack_size) noexcept;

#endif // defined(VK_KHR_ray_tracing_pipeline)

} // namespace cmd

} // namespace fubuki::extension::khr_ray_tracing_pipeline

#endif // FUBUKI_EXTENSION_KHR_RAY_TRACING_PIPELINE_HPP
