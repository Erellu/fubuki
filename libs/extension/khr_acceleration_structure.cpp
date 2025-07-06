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

#include "extension/khr_acceleration_structure.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>
#include <core/structure_type.hpp>

namespace fubuki::extension::khr_acceleration_structure
{

#if defined(VK_KHR_acceleration_structure)

namespace
{

[[nodiscard]]
std::expected<acceleration_structure_khr_handle, api_call_info> create(const functions&                            ext,
                                                                       device_handle                               device,
                                                                       const VkAccelerationStructureCreateInfoKHR& create_info,
                                                                       const VkAllocationCallbacks*                allocator) noexcept
{
    acceleration_structure_khr_handle result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateAccelerationStructureKHR">(ext, device.vk, std::addressof(create_info), allocator, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // anonymous namespace

[[nodiscard]]
std::expected<acceleration_structure_khr_handle, api_call_info> create(const functions&                            ext,
                                                                       device_handle                               device,
                                                                       const VkAccelerationStructureCreateInfoKHR& create_info,
                                                                       const VkAllocationCallbacks&                allocator) noexcept
{
    return create(ext, device, create_info, std::addressof(allocator));
}

[[nodiscard]]
std::expected<acceleration_structure_khr_handle, api_call_info>
create(const functions& ext, device_handle device, const VkAccelerationStructureCreateInfoKHR& create_info) noexcept
{
    return create(ext, device, create_info, nullptr);
}

void destroy(const functions&                   ext,
             device_handle                      device,
             acceleration_structure_khr_handle& acceleration_structure,
             const VkAllocationCallbacks&       allocator) noexcept
{
    fubuki::invoke<"vkDestroyAccelerationStructureKHR">(ext, device.vk, acceleration_structure.vk, std::addressof(allocator));
    acceleration_structure = null_handle;
}

void destroy(const functions& ext, device_handle device, acceleration_structure_khr_handle& acceleration_structure) noexcept
{
    fubuki::invoke<"vkDestroyAccelerationStructureKHR">(ext, device.vk, acceleration_structure.vk, nullptr);
    acceleration_structure = null_handle;
}

[[nodiscard]]
result build_acceleration_structures(const functions&                                                  ext,
                                     device_handle                                                     device,
                                     deferred_operation_khr_handle                                     deferred_operation,
                                     std::span<const VkAccelerationStructureBuildGeometryInfoKHR>      infos,
                                     const md_vector_view<VkAccelerationStructureBuildRangeInfoKHR, 2> build_range_infos) noexcept
{
    fubuki_assert(infos.size() == build_range_infos.size(), "Invalid argument. Sizes must match.");

    const auto r = fubuki::invoke<"vkBuildAccelerationStructuresKHR">(
        ext, device.vk, deferred_operation.vk, vk_size(infos), infos.data(), build_range_infos.data());

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
result copy_acceleration_structure(const functions&                          ext,
                                   device_handle                             device,
                                   deferred_operation_khr_handle             deferred_operation,
                                   const VkCopyAccelerationStructureInfoKHR& info) noexcept
{
    const auto r = fubuki::invoke<"vkCopyAccelerationStructureKHR">(ext, device.vk, deferred_operation.vk, std::addressof(info));

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
result copy_acceleration_structure_to_memory(const functions&                                  ext,
                                             device_handle                                     device,
                                             deferred_operation_khr_handle                     deferred_operation,
                                             const VkCopyAccelerationStructureToMemoryInfoKHR& info) noexcept
{
    const auto r = fubuki::invoke<"vkCopyAccelerationStructureToMemoryKHR">(ext, device.vk, deferred_operation.vk, std::addressof(info));

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
result copy_memory_to_acceleration_structure(const functions&                                  ext,
                                             device_handle                                     device,
                                             deferred_operation_khr_handle                     deferred_operation,
                                             const VkCopyMemoryToAccelerationStructureInfoKHR& info) noexcept
{
    const auto r = fubuki::invoke<"vkCopyMemoryToAccelerationStructureKHR">(ext, device.vk, deferred_operation.vk, std::addressof(info));

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
result write_acceleration_structures_properties(const functions&                                   ext,
                                                device_handle                                      device,
                                                std::span<const acceleration_structure_khr_handle> acceleration_structures,
                                                VkQueryType                                        query_type,
                                                std::span<std::byte>                               data,
                                                std::size_t                                        stride) noexcept
{
    auto handles = collect<VkAccelerationStructureKHR>(acceleration_structures);

    const auto r = fubuki::invoke<"vkWriteAccelerationStructuresPropertiesKHR">(
        ext, device.vk, vk_size(acceleration_structures), handles.data(), query_type, data.size(), data.data(), stride);

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
VkDeviceAddress get_acceleration_structure_device_address(const functions&                                   ext,
                                                          device_handle                                      device,
                                                          const VkAccelerationStructureDeviceAddressInfoKHR& info) noexcept
{
    return fubuki::invoke<"vkGetAccelerationStructureDeviceAddressKHR">(ext, device.vk, std::addressof(info));
}

[[nodiscard]]
VkAccelerationStructureCompatibilityKHR get_device_acceleration_structure_compatibility(
    const functions& ext, device_handle device, const VkAccelerationStructureVersionInfoKHR& version_info) noexcept
{
    VkAccelerationStructureCompatibilityKHR r = {};

    fubuki::invoke<"vkGetDeviceAccelerationStructureCompatibilityKHR">(ext, device.vk, std::addressof(version_info), std::addressof(r));

    return r;
}

[[nodiscard]]
VkAccelerationStructureBuildSizesInfoKHR get_acceleration_structure_build_sizes(const functions&                                   ext,
                                                                                device_handle                                      device,
                                                                                VkAccelerationStructureBuildTypeKHR                build_type,
                                                                                const VkAccelerationStructureBuildGeometryInfoKHR& build_info,
                                                                                std::span<const std::uint32_t> max_primitive_counts) noexcept
{
    auto r = fubuki::make<VkAccelerationStructureBuildSizesInfoKHR>();

    fubuki::invoke<"vkGetAccelerationStructureBuildSizesKHR">(
        ext, device.vk, build_type, std::addressof(build_info), max_primitive_counts.data(), std::addressof(r));

    return r;
}

#endif // defined(VK_KHR_acceleration_structure)

namespace cmd
{

#if defined(VK_KHR_acceleration_structure)

void build_acceleration_structures(const functions&                                                  ext,
                                   command_buffer_handle                                             command_buffer,
                                   std::span<const VkAccelerationStructureBuildGeometryInfoKHR>      infos,
                                   const md_vector_view<VkAccelerationStructureBuildRangeInfoKHR, 2> build_range_infos) noexcept
{
    fubuki_assert(infos.size() == build_range_infos.size(), "Invalid argument. Sizes must match.");

    return fubuki::invoke<"vkCmdBuildAccelerationStructuresKHR">(ext, command_buffer.vk, vk_size(infos), infos.data(), build_range_infos.data());
}

void build_acceleration_structures_indirect(const functions&                                             ext,
                                            command_buffer_handle                                        command_buffer,
                                            std::span<const VkAccelerationStructureBuildGeometryInfoKHR> infos,
                                            std::span<const VkDeviceAddress>                             indirect_device_addresses,
                                            std::span<const std::uint32_t>                               indirect_strides,
                                            const md_vector_view<std::uint32_t, 2>                       max_primitive_counts) noexcept
{
    fubuki_assert(infos.size() == indirect_device_addresses.size(), "Invalid argument. Sizes must match.");
    fubuki_assert(infos.size() == indirect_strides.size(), "Invalid argument. Sizes must match.");
    fubuki_assert(infos.size() == max_primitive_counts.size(), "Invalid argument. Sizes must match.");

    return fubuki::invoke<"vkCmdBuildAccelerationStructuresIndirectKHR">(
        ext, command_buffer.vk, vk_size(infos), infos.data(), indirect_device_addresses.data(), indirect_strides.data(), max_primitive_counts.data());
}

void copy_acceleration_structure(const functions& ext, command_buffer_handle command_buffer, const VkCopyAccelerationStructureInfoKHR& info) noexcept
{
    return fubuki::invoke<"vkCmdCopyAccelerationStructureKHR">(ext, command_buffer.vk, std::addressof(info));
}

void copy_acceleration_structure_to_memory(const functions&                                  ext,
                                           command_buffer_handle                             command_buffer,
                                           const VkCopyAccelerationStructureToMemoryInfoKHR& info) noexcept
{
    return fubuki::invoke<"vkCmdCopyAccelerationStructureToMemoryKHR">(ext, command_buffer.vk, std::addressof(info));
}

void copy_memory_to_acceleration_structure(const functions&                                  ext,
                                           command_buffer_handle                             command_buffer,
                                           const VkCopyMemoryToAccelerationStructureInfoKHR& info) noexcept
{
    return fubuki::invoke<"vkCmdCopyMemoryToAccelerationStructureKHR">(ext, command_buffer.vk, std::addressof(info));
}

void write_acceleration_structures_properties(const functions&                                   ext,
                                              command_buffer_handle                              command_buffer,
                                              std::span<const acceleration_structure_khr_handle> acceleration_structures,
                                              VkQueryType                                        query_type,
                                              query_pool_handle                                  query_pool,
                                              std::uint32_t                                      first_query) noexcept
{
    auto handles = collect<VkAccelerationStructureKHR>(acceleration_structures);

    return fubuki::invoke<"vkCmdWriteAccelerationStructuresPropertiesKHR">(
        ext, command_buffer.vk, vk_size(handles), handles.data(), query_type, query_pool.vk, first_query);
}

#endif // defined(VK_KHR_acceleration_structure)

} // namespace cmd

} // namespace fubuki::extension::khr_acceleration_structure
