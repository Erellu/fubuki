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

#include "extension/khr_ray_tracing_pipeline.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::khr_ray_tracing_pipeline
{

#if defined(VK_KHR_ray_tracing_pipeline)

[[nodiscard]]
std::expected<small_vector<ray_tracing_pipeline_khr_handle>, api_call_info> create(const functions&              ext,
                                                                                   device_handle                 device,
                                                                                   deferred_operation_khr_handle deferred_operation,
                                                                                   pipeline_cache_handle         pipeline_cache,
                                                                                   std::span<const VkRayTracingPipelineCreateInfoKHR> create_infos,
                                                                                   const VkAllocationCallbacks&                       allocator)
{
    small_vector<VkPipeline> result(create_infos.size());
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateRayTracingPipelinesKHR">(ext, device.vk, deferred_operation.vk, pipeline_cache.vk, vk_size(create_infos), create_infos.data(), std::addressof(allocator), result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<ray_tracing_pipeline_khr_handle>{result.begin(), result.end()};
}

[[nodiscard]]
std::expected<small_vector<ray_tracing_pipeline_khr_handle>, api_call_info> create(const functions&              ext,
                                                                                   device_handle                 device,
                                                                                   deferred_operation_khr_handle deferred_operation,
                                                                                   pipeline_cache_handle         pipeline_cache,
                                                                                   std::span<const VkRayTracingPipelineCreateInfoKHR> create_infos)
{
    small_vector<VkPipeline> result(create_infos.size());

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateRayTracingPipelinesKHR">(ext, device.vk, deferred_operation.vk, pipeline_cache.vk, vk_size(create_infos), create_infos.data(), nullptr, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<ray_tracing_pipeline_khr_handle>{result.begin(), result.end()};
}

[[nodiscard]]
std::expected<void, api_call_info> get_ray_tracing_capture_replay_shader_group_handles(const functions&                ext,
                                                                                       device_handle                   device,
                                                                                       ray_tracing_pipeline_khr_handle pipeline,
                                                                                       std::uint32_t                   first_group,
                                                                                       std::uint32_t                   group_count,
                                                                                       std::span<std::byte>            data) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetRayTracingCaptureReplayShaderGroupHandlesKHR">(ext, device.vk, pipeline.vk, first_group, group_count, data.size(), data.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
VkDeviceSize get_ray_tracing_shader_group_stack_size(const functions&                ext,
                                                     device_handle                   device,
                                                     ray_tracing_pipeline_khr_handle pipeline,
                                                     std::uint32_t                   group,
                                                     VkShaderGroupShaderKHR          group_shader) noexcept
{
    return fubuki::invoke<"vkGetRayTracingShaderGroupStackSizeKHR">(ext, device.vk, pipeline.vk, group, group_shader);
}

#endif // defined(VK_KHR_ray_tracing_pipeline)

namespace cmd
{

#if defined(VK_KHR_ray_tracing_pipeline)

void trace_rays(const functions&      ext,
                command_buffer_handle command_buffer,
                const binding_table&  table,
                std::uint32_t         width,
                std::uint32_t         height,
                std::uint32_t         depth) noexcept
{
    return fubuki::invoke<"vkCmdTraceRaysKHR">(
        ext, command_buffer.vk, &table.ray_gen, &table.miss, &table.hit, &table.callable, width, height, depth);
}

void trace_rays_indirect(const functions&      ext,
                         command_buffer_handle command_buffer,
                         const binding_table&  table,
                         VkDeviceAddress       indirect_device_address) noexcept
{
    return fubuki::invoke<"vkCmdTraceRaysIndirectKHR">(
        ext, command_buffer.vk, &table.ray_gen, &table.miss, &table.hit, &table.callable, indirect_device_address);
}

void set_ray_tracing_pipeline_stack_size(const functions& ext, command_buffer_handle command_buffer, std::uint32_t pipeline_stack_size) noexcept
{
    return fubuki::invoke<"vkCmdSetRayTracingPipelineStackSizeKHR">(ext, command_buffer.vk, pipeline_stack_size);
}

#endif // defined(VK_KHR_ray_tracing_pipeline)

} // namespace cmd

} // namespace fubuki::extension::khr_ray_tracing_pipeline
