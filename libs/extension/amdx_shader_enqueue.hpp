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

#ifndef FUBUKI_EXTENSION_AMDX_SHADER_ENQUEUE_HPP
#define FUBUKI_EXTENSION_AMDX_SHADER_ENQUEUE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/amdx_shader_enqueue.hpp" // IWYU pragma: export

// NOLINTBEGIN(modernize-concat-nested-namespaces): no, they can't

namespace fubuki::extension::amdx_shader_enqueue
{

/********************************************************************************/
/*                                FREE FUNCTIONS                                */
/********************************************************************************/

#if defined(VK_AMDX_shader_enqueue)

namespace detail
{

[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info>
                                   get_execution_graph_pipeline_scratch_size(const functions&                         ext,
                                                                             device_handle                            device,
                                                                             execution_graph_pipeline_handle          execution_graph,
                                                                             VkExecutionGraphPipelineScratchSizeAMDX& result) noexcept;

[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<execution_graph_pipeline_handle>, api_call_info>
                                   create_execution_graph_pipelines(const functions&                                        ext,
                                                                    device_handle                                           device,
                                                                    pipeline_cache_handle                                   pipeline_cache,
                                                                    std::span<const VkExecutionGraphPipelineCreateInfoAMDX> create_infos,
                                                                    const VkAllocationCallbacks*                            allocator);

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateExecutionGraphPipelinesAMDX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<execution_graph_pipeline_handle>, api_call_info>
                                   create_execution_graph_pipelines(const functions&                                        ext,
                                                                    device_handle                                           device,
                                                                    pipeline_cache_handle                                   pipeline_cache,
                                                                    std::span<const VkExecutionGraphPipelineCreateInfoAMDX> create_infos,
                                                                    const VkAllocationCallbacks&                            allocator);

[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<execution_graph_pipeline_handle>, api_call_info>
                                   create_execution_graph_pipelines(const functions&                                        ext,
                                                                    device_handle                                           device,
                                                                    pipeline_cache_handle                                   pipeline_cache,
                                                                    std::span<const VkExecutionGraphPipelineCreateInfoAMDX> create_infos);

template<typename... elements>
[[nodiscard]] inline std::expected<VkExecutionGraphPipelineScratchSizeAMDX, api_call_info> get_execution_graph_pipeline_scratch_size(
    const functions& ext, device_handle device, execution_graph_pipeline_handle execution_graph, const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkExecutionGraphPipelineScratchSizeAMDX>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_execution_graph_pipeline_scratch_size(ext, device, execution_graph, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]] inline auto
get_execution_graph_pipeline_scratch_size(const functions& ext, device_handle device, execution_graph_pipeline_handle execution_graph) noexcept
{
    return get_execution_graph_pipeline_scratch_size(ext, device, execution_graph, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetExecutionGraphPipelineNodeIndexAMDX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::uint32_t, api_call_info>
                                   get_execution_graph_pipeline_node_index(const functions&                               ext,
                                                                           device_handle                                  device,
                                                                           execution_graph_pipeline_handle                execution_graph,
                                                                           const VkPipelineShaderStageNodeCreateInfoAMDX& node_info) noexcept;

#endif // defined(VK_AMDX_shader_enqueue)

namespace cmd
{

#if defined(VK_AMDX_shader_enqueue)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdInitializeGraphScratchMemoryAMDX.html
FUBUKI_EXTENSION_API
void initialize_graph_scratch_memory(const functions&                ext,
                                     command_buffer_handle           command_buffer,
                                     execution_graph_pipeline_handle pipeline,
                                     VkDeviceAddress                 scratch,
                                     VkDeviceAddress                 scratch_size) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchGraphAMDX.html
FUBUKI_EXTENSION_API
void dispatch_graph(const functions&                    ext,
                    command_buffer_handle               command_buffer,
                    VkDeviceAddress                     scratch,
                    VkDeviceAddress                     scratch_size,
                    const VkDispatchGraphCountInfoAMDX& count_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchGraphIndirectAMDX.html
FUBUKI_EXTENSION_API
void dispatch_graph_indirect(const functions&                    ext,
                             command_buffer_handle               command_buffer,
                             VkDeviceAddress                     scratch,
                             VkDeviceAddress                     scratch_size,
                             const VkDispatchGraphCountInfoAMDX& count_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchGraphIndirectCountAMDX.html
FUBUKI_EXTENSION_API
void dispatch_graph_indirect_count(const functions&      ext,
                                   command_buffer_handle command_buffer,
                                   VkDeviceAddress       scratch,
                                   VkDeviceAddress       scratch_size,
                                   VkDeviceAddress       count_info) noexcept;

#endif // defined(VK_AMDX_shader_enqueue)

} // namespace cmd

} // namespace fubuki::extension::amdx_shader_enqueue

// NOLINTEND(modernize-concat-nested-namespaces)

#endif // FUBUKI_EXTENSION_AMDX_SHADER_ENQUEUE_HPP
