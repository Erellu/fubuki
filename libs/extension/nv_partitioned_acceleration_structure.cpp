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

#include "extension/nv_partitioned_acceleration_structure.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::nv_partitioned_acceleration_structure
{

#if defined(VK_NV_partitioned_acceleration_structure)

namespace detail
{

void get_partitioned_acceleration_structures_build_sizes(const functions&                                          ext,
                                                         device_handle                                             device,
                                                         const VkPartitionedAccelerationStructureInstancesInputNV& info,
                                                         VkAccelerationStructureBuildSizesInfoKHR&                 result) noexcept
{
    return fubuki::invoke<"vkGetPartitionedAccelerationStructuresBuildSizesNV">(ext, device.vk, std::addressof(info), std::addressof(result));
}

} // namespace detail

#endif // defined(VK_NV_partitioned_acceleration_structure)

namespace cmd
{

#if defined(VK_NV_partitioned_acceleration_structure)

void build_partitioned_acceleration_structures(const functions&                                     ext,
                                               command_buffer_handle                                command_buffer,
                                               const VkBuildPartitionedAccelerationStructureInfoNV& build_info) noexcept
{
    return fubuki::invoke<"vkCmdBuildPartitionedAccelerationStructuresNV">(ext, command_buffer.vk, std::addressof(build_info));
}

#endif // defined(VK_NV_partitioned_acceleration_structure)

} // namespace cmd

} // namespace fubuki::extension::nv_partitioned_acceleration_structure
