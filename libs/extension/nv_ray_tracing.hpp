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

#ifndef FUBUKI_EXTENSION_NV_RAY_TRACING_HPP
#define FUBUKI_EXTENSION_NV_RAY_TRACING_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_ray_tracing.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_ray_tracing
{

#if defined(VK_NV_ray_tracing)

struct ray_tracing_shader_buffer
{
    buffer_handle buffer = {};
    VkDeviceSize  offset = 0u;
};

/// A strided device memory region, i.e. VkStridedDeviceAddressRegionKHR but for VK_NV_ray_tracing.
struct strided_ray_tracing_shader_buffer
{
    buffer_handle buffer = {};
    VkDeviceSize  offset = 0u;
    VkDeviceSize  stride = 0u;
};

/// Binding table for ray tracing shaders.
struct binding_table
{
    ray_tracing_shader_buffer         ray_gen  = {}; ///< The table for the ray generation shader stage.
    strided_ray_tracing_shader_buffer miss     = {}; ///< The table for the miss shader stage.
    strided_ray_tracing_shader_buffer hit      = {}; ///< The table for the hit shader stage.
    strided_ray_tracing_shader_buffer callable = {}; ///< The table for the callable shader stage.
};

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateAccelerationStructureNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<acceleration_structure_nv_handle, api_call_info>
                                   create_acceleration_structure(const functions&                           ext,
                                                                 device_handle                              device,
                                                                 const VkAccelerationStructureCreateInfoNV& create_info,
                                                                 const VkAllocationCallbacks&               allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateAccelerationStructureNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<acceleration_structure_nv_handle, api_call_info>
create_acceleration_structure(const functions& ext, device_handle device, const VkAccelerationStructureCreateInfoNV& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyAccelerationStructureNV.html
FUBUKI_EXTENSION_API
void destroy_acceleration_structure(const functions&                  ext,
                                    device_handle                     device,
                                    acceleration_structure_nv_handle& acceleration_structure,
                                    const VkAllocationCallbacks&      allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyAccelerationStructureNV.html
FUBUKI_EXTENSION_API
void destroy_acceleration_structure(const functions& ext, device_handle device, acceleration_structure_nv_handle& acceleration_structure) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAccelerationStructureMemoryRequirementsNV.html
[[nodiscard]] FUBUKI_EXTENSION_API VkMemoryRequirements2KHR get_acceleration_structure_memory_requirements(
    const functions& ext, device_handle device, const VkAccelerationStructureMemoryRequirementsInfoNV& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkBindAccelerationStructureMemoryNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> bind_acceleration_structure_memory(
    const functions& ext, device_handle device, std::span<const VkBindAccelerationStructureMemoryInfoNV> bind_infos) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRayTracingPipelinesNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<ray_tracing_pipeline_nv_handle>, api_call_info>
                                   create_ray_tracing_pipelines(const functions&                                  ext,
                                                                device_handle                                     device,
                                                                pipeline_cache_handle                             pipeline_cache,
                                                                std::span<const VkRayTracingPipelineCreateInfoNV> create_infos,
                                                                const VkAllocationCallbacks&                      allocator);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateRayTracingPipelinesNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<ray_tracing_pipeline_nv_handle>, api_call_info> create_ray_tracing_pipelines(
    const functions& ext, device_handle device, pipeline_cache_handle pipeline_cache, std::span<const VkRayTracingPipelineCreateInfoNV> create_infos);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetRayTracingShaderGroupHandlesNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_ray_tracing_shader_group_handles(const functions&               ext,
                                                                                                           device_handle                  device,
                                                                                                           ray_tracing_pipeline_nv_handle pipeline,
                                                                                                           std::uint32_t                  first_group,
                                                                                                           std::uint32_t                  group_count,
                                                                                                           std::span<std::byte> data) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAccelerationStructureHandleNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_acceleration_structure_handle(
    const functions& ext, device_handle device, acceleration_structure_nv_handle acceleration_structure, std::span<std::byte> data) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCompileDeferredNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
compile_deferred(const functions& ext, device_handle device, ray_tracing_pipeline_nv_handle pipeline, std::uint32_t shader) noexcept;

#endif // defined(VK_NV_ray_tracing)

namespace cmd
{

#if defined(VK_NV_ray_tracing)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBuildAccelerationStructureNV.html
FUBUKI_EXTENSION_API
void build_acceleration_structure(const functions&                     ext,
                                  command_buffer_handle                command_buffer,
                                  const VkAccelerationStructureInfoNV& info,
                                  buffer_handle                        instance_data,
                                  VkDeviceSize                         instance_offset,
                                  VkBool32                             update,
                                  acceleration_structure_nv_handle     dst,
                                  acceleration_structure_nv_handle     src,
                                  buffer_handle                        scratch,
                                  VkDeviceSize                         scratch_offset) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyAccelerationStructureNV.html
FUBUKI_EXTENSION_API
void copy_acceleration_structure(const functions&                   ext,
                                 command_buffer_handle              command_buffer,
                                 acceleration_structure_nv_handle   dst,
                                 acceleration_structure_nv_handle   src,
                                 VkCopyAccelerationStructureModeKHR mode) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdTraceRaysNV.html
FUBUKI_EXTENSION_API
void trace_rays(const functions&      ext,
                command_buffer_handle command_buffer,
                const binding_table&  table,
                std::uint32_t         width,
                std::uint32_t         height,
                std::uint32_t         depth) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteAccelerationStructuresPropertiesNV.html
FUBUKI_EXTENSION_API
void write_acceleration_structures_properties(const functions&                        ext,
                                              command_buffer_handle                   command_buffer,
                                              std::uint32_t                           acceleration_structure_count,
                                              const acceleration_structure_nv_handle* p_acceleration_structures,
                                              VkQueryType                             query_type,
                                              query_pool_handle                       query_pool,
                                              std::uint32_t                           first_query) noexcept;

#endif // defined(VK_NV_ray_tracing)

} // namespace cmd

} // namespace fubuki::extension::nv_ray_tracing

#endif // FUBUKI_EXTENSION_NV_RAY_TRACING_HPP
