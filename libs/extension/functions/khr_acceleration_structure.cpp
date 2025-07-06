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

#include "extension/functions/khr_acceleration_structure.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
khr_acceleration_structure khr_acceleration_structure::load([[maybe_unused]] instance_handle instance,
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
#if defined(VK_KHR_acceleration_structure)
        .create_acceleration_structure_khr = pfn<"vkCreateAccelerationStructureKHR">(instance, device, device_get),
        .destroy_acceleration_structure_khr = pfn<"vkDestroyAccelerationStructureKHR">(instance, device, device_get),
        .build_acceleration_structures_khr = pfn<"vkBuildAccelerationStructuresKHR">(instance, device, device_get),
        .copy_acceleration_structure_khr = pfn<"vkCopyAccelerationStructureKHR">(instance, device, device_get),
        .copy_acceleration_structure_to_memory_khr = pfn<"vkCopyAccelerationStructureToMemoryKHR">(instance, device, device_get),
        .copy_memory_to_acceleration_structure_khr = pfn<"vkCopyMemoryToAccelerationStructureKHR">(instance, device, device_get),
        .write_acceleration_structures_properties_khr = pfn<"vkWriteAccelerationStructuresPropertiesKHR">(instance, device, device_get),
        .get_acceleration_structure_device_address_khr = pfn<"vkGetAccelerationStructureDeviceAddressKHR">(instance, device, device_get),
        .get_device_acceleration_structure_compatibility_khr = pfn<"vkGetDeviceAccelerationStructureCompatibilityKHR">(instance, device, device_get),
        .get_acceleration_structure_build_sizes_khr = pfn<"vkGetAccelerationStructureBuildSizesKHR">(instance, device, device_get),

        .cmd =
        {
            .build_acceleration_structures_khr = pfn<"vkCmdBuildAccelerationStructuresKHR">(instance, device, device_get),
            .build_acceleration_structures_indirect_khr = pfn<"vkCmdBuildAccelerationStructuresIndirectKHR">(instance, device, device_get),
            .copy_acceleration_structure_khr = pfn<"vkCmdCopyAccelerationStructureKHR">(instance, device, device_get),
            .copy_acceleration_structure_to_memory_khr = pfn<"vkCmdCopyAccelerationStructureToMemoryKHR">(instance, device, device_get),
            .copy_memory_to_acceleration_structure_khr = pfn<"vkCmdCopyMemoryToAccelerationStructureKHR">(instance, device, device_get),
            .write_acceleration_structures_properties_khr = pfn<"vkCmdWriteAccelerationStructuresPropertiesKHR">(instance, device, device_get),

        },
#endif // defined(VK_KHR_acceleration_structure)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
