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

#include "extension/nv_ray_tracing.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>
#include <core/structure_type.hpp>

namespace fubuki::extension::nv_ray_tracing
{

#if defined(VK_NV_ray_tracing)

[[nodiscard]]
std::expected<acceleration_structure_nv_handle, api_call_info> create_acceleration_structure(const functions&                           ext,
                                                                                             device_handle                              device,
                                                                                             const VkAccelerationStructureCreateInfoNV& create_info,
                                                                                             const VkAllocationCallbacks& allocator) noexcept
{
    acceleration_structure_nv_handle result = {};

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateAccelerationStructureNV">(ext, device.vk, std::addressof(create_info), std::addressof(allocator), std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<acceleration_structure_nv_handle, api_call_info>
create_acceleration_structure(const functions& ext, device_handle device, const VkAccelerationStructureCreateInfoNV& create_info) noexcept
{
    acceleration_structure_nv_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateAccelerationStructureNV">(ext, device.vk, std::addressof(create_info), nullptr, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_acceleration_structure(const functions&                  ext,
                                    device_handle                     device,
                                    acceleration_structure_nv_handle& acceleration_structure,
                                    const VkAllocationCallbacks&      allocator) noexcept
{
    fubuki::invoke<"vkDestroyAccelerationStructureNV">(ext, device.vk, acceleration_structure.vk, std::addressof(allocator));

    acceleration_structure = null_handle;
}

void destroy_acceleration_structure(const functions& ext, device_handle device, acceleration_structure_nv_handle& acceleration_structure) noexcept
{
    fubuki::invoke<"vkDestroyAccelerationStructureNV">(ext, device.vk, acceleration_structure.vk, nullptr);

    acceleration_structure = null_handle;
}

[[nodiscard]]
VkMemoryRequirements2KHR get_acceleration_structure_memory_requirements(const functions&                                       ext,
                                                                        device_handle                                          device,
                                                                        const VkAccelerationStructureMemoryRequirementsInfoNV& info) noexcept
{
    auto result = fubuki::make<VkMemoryRequirements2KHR>();

    fubuki::invoke<"vkGetAccelerationStructureMemoryRequirementsNV">(ext, device.vk, std::addressof(info), std::addressof(result));

    return result;
}

[[nodiscard]]
std::expected<void, api_call_info> bind_acceleration_structure_memory(const functions&                                         ext,
                                                                      device_handle                                            device,
                                                                      std::span<const VkBindAccelerationStructureMemoryInfoNV> bind_infos) noexcept
{
    const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkBindAccelerationStructureMemoryNV">(ext, device.vk, vk_size(bind_infos), bind_infos.data()));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<small_vector<ray_tracing_pipeline_nv_handle>, api_call_info>
create_ray_tracing_pipelines(const functions&                                  ext,
                             device_handle                                     device,
                             pipeline_cache_handle                             pipeline_cache,
                             std::span<const VkRayTracingPipelineCreateInfoNV> create_infos,
                             const VkAllocationCallbacks&                      allocator)
{
    small_vector<VkPipeline> pipelines;
    pipelines.resize(create_infos.size());

    const auto check
        = fubuki_validate(validate_by::expected,
        fubuki::invoke<"vkCreateRayTracingPipelinesNV">(ext, device.vk, pipeline_cache.vk, vk_size(create_infos), create_infos.data(), std::addressof(allocator), pipelines.data()));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<ray_tracing_pipeline_nv_handle>{pipelines.begin(), pipelines.end()};
}

[[nodiscard]]
std::expected<small_vector<ray_tracing_pipeline_nv_handle>, api_call_info> create_ray_tracing_pipelines(
    const functions& ext, device_handle device, pipeline_cache_handle pipeline_cache, std::span<const VkRayTracingPipelineCreateInfoNV> create_infos)
{
    small_vector<VkPipeline> pipelines;
    pipelines.resize(create_infos.size());

    const auto check = fubuki_validate(validate_by::expected,
        fubuki::invoke<"vkCreateRayTracingPipelinesNV">(ext, device.vk, pipeline_cache.vk, vk_size(create_infos), create_infos.data(), nullptr, pipelines.data()));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<ray_tracing_pipeline_nv_handle>{pipelines.begin(), pipelines.end()};
}

[[nodiscard]]
std::expected<void, api_call_info> get_ray_tracing_shader_group_handles(const functions&               ext,
                                                                        device_handle                  device,
                                                                        ray_tracing_pipeline_nv_handle pipeline,
                                                                        std::uint32_t                  first_group,
                                                                        std::uint32_t                  group_count,
                                                                        std::span<std::byte>           data) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetRayTracingShaderGroupHandlesNV">(ext, device.vk, pipeline.vk, first_group, group_count, data.size_bytes(), data.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info> get_acceleration_structure_handle(const functions&                 ext,
                                                                     device_handle                    device,
                                                                     acceleration_structure_nv_handle acceleration_structure,
                                                                     std::span<std::byte>             data) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetAccelerationStructureHandleNV">(ext, device.vk, acceleration_structure.vk, data.size_bytes(), data.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info>
compile_deferred(const functions& ext, device_handle device, ray_tracing_pipeline_nv_handle pipeline, std::uint32_t shader) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCompileDeferredNV">(ext, device.vk, pipeline.vk, shader)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

#endif // defined(VK_NV_ray_tracing)

namespace cmd
{

#if defined(VK_NV_ray_tracing)

void build_acceleration_structure(const functions&                     ext,
                                  command_buffer_handle                command_buffer,
                                  const VkAccelerationStructureInfoNV& info,
                                  buffer_handle                        instance_data,
                                  VkDeviceSize                         instance_offset,
                                  VkBool32                             update,
                                  acceleration_structure_nv_handle     dst,
                                  acceleration_structure_nv_handle     src,
                                  buffer_handle                        scratch,
                                  VkDeviceSize                         scratch_offset) noexcept
{
    return fubuki::invoke<"vkCmdBuildAccelerationStructureNV">(
        ext, command_buffer.vk, std::addressof(info), instance_data.vk, instance_offset, update, dst.vk, src.vk, scratch.vk, scratch_offset);
}

void copy_acceleration_structure(const functions&                   ext,
                                 command_buffer_handle              command_buffer,
                                 acceleration_structure_nv_handle   dst,
                                 acceleration_structure_nv_handle   src,
                                 VkCopyAccelerationStructureModeKHR mode) noexcept
{
    return fubuki::invoke<"vkCmdCopyAccelerationStructureNV">(ext, command_buffer.vk, dst.vk, src.vk, mode);
}

void trace_rays(const functions&      ext,
                command_buffer_handle command_buffer,
                const binding_table&  table,
                std::uint32_t         width,
                std::uint32_t         height,
                std::uint32_t         depth) noexcept
{
    return fubuki::invoke<"vkCmdTraceRaysNV">(ext,
                                              command_buffer.vk,
                                              table.ray_gen.buffer.vk,
                                              table.ray_gen.offset,
                                              table.miss.buffer.vk,
                                              table.miss.offset,
                                              table.miss.stride,
                                              table.hit.buffer.vk,
                                              table.hit.offset,
                                              table.hit.stride,
                                              table.callable.buffer.vk,
                                              table.callable.offset,
                                              table.callable.stride,
                                              width,
                                              height,
                                              depth);
}

void write_acceleration_structures_properties(const functions&                            ext,
                                              command_buffer_handle                       command_buffer,
                                              std::span<acceleration_structure_nv_handle> acceleration_structures,
                                              VkQueryType                                 query_type,
                                              query_pool_handle                           query_pool,
                                              std::uint32_t                               first_query) noexcept
{
    auto handles = collect<VkAccelerationStructureNV>(acceleration_structures);

    return fubuki::invoke<"vkCmdWriteAccelerationStructuresPropertiesNV">(
        ext, command_buffer.vk, vk_size(handles), handles.data(), query_type, query_pool.vk, first_query);
}

#endif // defined(VK_NV_ray_tracing)

} // namespace cmd

} // namespace fubuki::extension::nv_ray_tracing
