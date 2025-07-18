﻿/*
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

#ifndef FUBUKI_EXTENSION_NV_CLUSTER_ACCELERATION_STRUCTURE_HPP
#define FUBUKI_EXTENSION_NV_CLUSTER_ACCELERATION_STRUCTURE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_cluster_acceleration_structure.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_cluster_acceleration_structure
{

#if defined(VK_NV_cluster_acceleration_structure)

namespace detail
{

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetClusterAccelerationStructureBuildSizesNV.html
FUBUKI_EXTENSION_API void get_cluster_acceleration_structure_build_sizes(const functions&                                 ext,
                                                                         device_handle                                    device,
                                                                         const VkClusterAccelerationStructureInputInfoNV& info,
                                                                         VkAccelerationStructureBuildSizesInfoKHR&        result) noexcept;

} // namespace detail

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetClusterAccelerationStructureBuildSizesNV.html

template<typename... elements>
inline auto get_cluster_acceleration_structure_build_sizes(const functions&                                 ext,
                                                           device_handle                                    device,
                                                           const VkClusterAccelerationStructureInputInfoNV& info,
                                                           const pnext_chain<elements...>&                  pnext) noexcept
{
    auto result = fubuki::make<VkAccelerationStructureBuildSizesInfoKHR>();
    fubuki::extend(result, pnext);

    detail::get_cluster_acceleration_structure_build_sizes(ext, device, info, result);

    return result;
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetClusterAccelerationStructureBuildSizesNV.html
inline auto get_cluster_acceleration_structure_build_sizes(const functions&                                 ext,
                                                           device_handle                                    device,
                                                           const VkClusterAccelerationStructureInputInfoNV& info) noexcept
{
    return get_cluster_acceleration_structure_build_sizes(ext, device, info, empty_pnext_chain);
}

#endif // defined(VK_NV_cluster_acceleration_structure)

namespace cmd
{

#if defined(VK_NV_cluster_acceleration_structure)
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBuildClusterAccelerationStructureIndirectNV.html
FUBUKI_EXTENSION_API void build_cluster_acceleration_structure_indirect(const functions&                                    ext,
                                                                        command_buffer_handle                               command_buffer,
                                                                        const VkClusterAccelerationStructureCommandsInfoNV& command_infos) noexcept;

#endif // defined(VK_NV_cluster_acceleration_structure)

} // namespace cmd

} // namespace fubuki::extension::nv_cluster_acceleration_structure

#endif // FUBUKI_EXTENSION_NV_CLUSTER_ACCELERATION_STRUCTURE_HPP
