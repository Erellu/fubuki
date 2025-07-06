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
#include "extension/amdx_shader_enqueue.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

// NOLINTBEGIN(modernize-concat-nested-namespaces): no, they can't

namespace fubuki::extension::amdx_shader_enqueue
{

#if defined(VK_AMDX_shader_enqueue)

namespace detail
{

[[nodiscard]]
std::optional<api_call_info> get_execution_graph_pipeline_scratch_size(const functions&                         ext,
                                                                       device_handle                            device,
                                                                       execution_graph_pipeline_handle          execution_graph,
                                                                       VkExecutionGraphPipelineScratchSizeAMDX& result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetExecutionGraphPipelineScratchSizeAMDX">(ext, device.vk, execution_graph.vk, std::addressof(result))); not check)
    {
        return check.error();
    }

    return {};
}

[[nodiscard]]
std::expected<small_vector<execution_graph_pipeline_handle>, api_call_info>
create_execution_graph_pipelines(const functions&                                        ext,
                                 device_handle                                           device,
                                 pipeline_cache_handle                                   pipeline_cache,
                                 std::span<const VkExecutionGraphPipelineCreateInfoAMDX> create_infos,
                                 const VkAllocationCallbacks*                            allocator)
{
    small_vector<VkPipeline> result;
    result.resize(create_infos.size());

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateExecutionGraphPipelinesAMDX">(ext, device.vk, pipeline_cache.vk, vk_size(create_infos), create_infos.data(), allocator, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<execution_graph_pipeline_handle>{result.begin(), result.end()};
}

} // namespace detail

[[nodiscard]]
std::expected<small_vector<execution_graph_pipeline_handle>, api_call_info>
create_execution_graph_pipelines(const functions&                                        ext,
                                 device_handle                                           device,
                                 pipeline_cache_handle                                   pipeline_cache,
                                 std::span<const VkExecutionGraphPipelineCreateInfoAMDX> create_infos,
                                 const VkAllocationCallbacks&                            allocator)
{
    return detail::create_execution_graph_pipelines(ext, device, pipeline_cache, create_infos, std::addressof(allocator));
}

[[nodiscard]]
std::expected<small_vector<execution_graph_pipeline_handle>, api_call_info>
create_execution_graph_pipelines(const functions&                                        ext,
                                 device_handle                                           device,
                                 pipeline_cache_handle                                   pipeline_cache,
                                 std::span<const VkExecutionGraphPipelineCreateInfoAMDX> create_infos)
{
    return detail::create_execution_graph_pipelines(ext, device, pipeline_cache, create_infos, nullptr);
}

[[nodiscard]]
std::expected<std::uint32_t, api_call_info> get_execution_graph_pipeline_node_index(const functions&                               ext,
                                                                                    device_handle                                  device,
                                                                                    execution_graph_pipeline_handle                execution_graph,
                                                                                    const VkPipelineShaderStageNodeCreateInfoAMDX& node_info) noexcept
{
    std::uint32_t result = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetExecutionGraphPipelineNodeIndexAMDX">(ext, device.vk, execution_graph.vk, std::addressof(node_info), &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_AMDX_shader_enqueue)

namespace cmd
{

#if defined(VK_AMDX_shader_enqueue)

void initialize_graph_scratch_memory(const functions&                ext,
                                     command_buffer_handle           command_buffer,
                                     execution_graph_pipeline_handle pipeline,
                                     VkDeviceAddress                 scratch,
                                     VkDeviceAddress                 scratch_size) noexcept
{
    return fubuki::invoke<"vkCmdInitializeGraphScratchMemoryAMDX">(ext, command_buffer.vk, pipeline.vk, scratch, scratch_size);
}

void dispatch_graph(const functions&                    ext,
                    command_buffer_handle               command_buffer,
                    VkDeviceAddress                     scratch,
                    VkDeviceAddress                     scratch_size,
                    const VkDispatchGraphCountInfoAMDX& count_info) noexcept
{
    return fubuki::invoke<"vkCmdDispatchGraphAMDX">(ext, command_buffer.vk, scratch, scratch_size, std::addressof(count_info));
}

void dispatch_graph_indirect(const functions&                    ext,
                             command_buffer_handle               command_buffer,
                             VkDeviceAddress                     scratch,
                             VkDeviceAddress                     scratch_size,
                             const VkDispatchGraphCountInfoAMDX& count_info) noexcept
{
    return fubuki::invoke<"vkCmdDispatchGraphIndirectAMDX">(ext, command_buffer.vk, scratch, scratch_size, std::addressof(count_info));
}

void dispatch_graph_indirect_count(const functions&      ext,
                                   command_buffer_handle command_buffer,
                                   VkDeviceAddress       scratch,
                                   VkDeviceAddress       scratch_size,
                                   VkDeviceAddress       count_info) noexcept
{
    return fubuki::invoke<"vkCmdDispatchGraphIndirectCountAMDX">(ext, command_buffer.vk, scratch, scratch_size, count_info);
}

#endif // defined(VK_AMDX_shader_enqueue)

} // namespace cmd

} // namespace fubuki::extension::amdx_shader_enqueue

// NOLINTEND(modernize-concat-nested-namespaces): no, they can't
