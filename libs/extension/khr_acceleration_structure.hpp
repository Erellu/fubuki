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

#ifndef FUBUKI_EXTENSION_KHR_ACCELERATION_STRUCTURE_HPP
#define FUBUKI_EXTENSION_KHR_ACCELERATION_STRUCTURE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/md_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_acceleration_structure.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_acceleration_structure
{

#if defined(VK_KHR_acceleration_structure)

struct success
{
    /// Codes indicating an error occurred during an operation.
    enum class code : std::underlying_type_t<VkResult>
    {
        normal       = VK_SUCCESS,
        deferred     = VK_OPERATION_DEFERRED_KHR,
        not_deferred = VK_OPERATION_NOT_DEFERRED_KHR,
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const success& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

struct error
{
    /// Codes indicating an error occurred during an operation.
    enum class code : std::underlying_type_t<VkResult>
    {
        out_of_host_memory   = VK_ERROR_OUT_OF_HOST_MEMORY,
        out_of_device_memory = VK_ERROR_OUT_OF_DEVICE_MEMORY,
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const error& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

using result = std::expected<success, error>;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateAccelerationStructureKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<acceleration_structure_khr_handle, api_call_info>
                                   create(const functions&                            ext,
                                          device_handle                               device,
                                          const VkAccelerationStructureCreateInfoKHR& create_info,
                                          const VkAllocationCallbacks&                allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateAccelerationStructureKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<acceleration_structure_khr_handle, api_call_info>
create(const functions& ext, device_handle device, const VkAccelerationStructureCreateInfoKHR& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyAccelerationStructureKHR.html
FUBUKI_EXTENSION_API
void destroy(const functions&                   ext,
             device_handle                      device,
             acceleration_structure_khr_handle& acceleration_structure,
             const VkAllocationCallbacks&       allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyAccelerationStructureKHR.html
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, acceleration_structure_khr_handle& acceleration_structure) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkBuildAccelerationStructuresKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API result
build_acceleration_structures(const functions&                                             ext,
                              device_handle                                                device,
                              deferred_operation_khr_handle                                deferred_operation,
                              std::span<const VkAccelerationStructureBuildGeometryInfoKHR> infos,
                              md_vector_view<VkAccelerationStructureBuildRangeInfoKHR, 2>  build_range_infos) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyAccelerationStructureKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API result copy_acceleration_structure(const functions&                          ext,
                                                                      device_handle                             device,
                                                                      deferred_operation_khr_handle             deferred_operation,
                                                                      const VkCopyAccelerationStructureInfoKHR& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyAccelerationStructureToMemoryKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API result copy_acceleration_structure_to_memory(const functions&                                  ext,
                                                                                device_handle                                     device,
                                                                                deferred_operation_khr_handle                     deferred_operation,
                                                                                const VkCopyAccelerationStructureToMemoryInfoKHR& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMemoryToAccelerationStructureKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API result copy_memory_to_acceleration_structure(const functions&                                  ext,
                                                                                device_handle                                     device,
                                                                                deferred_operation_khr_handle                     deferred_operation,
                                                                                const VkCopyMemoryToAccelerationStructureInfoKHR& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWriteAccelerationStructuresPropertiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API result
write_acceleration_structures_properties(const functions&                                   ext,
                                         device_handle                                      device,
                                         std::span<const acceleration_structure_khr_handle> acceleration_structures,
                                         VkQueryType                                        query_type,
                                         std::span<std::byte>                               data,
                                         std::size_t                                        stride) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWriteAccelerationStructuresPropertiesKHR.html
template<typename T>
[[nodiscard]]
inline auto write_acceleration_structures_properties(const functions&                                   ext,
                                                     device_handle                                      device,
                                                     std::span<const acceleration_structure_khr_handle> acceleration_structures,
                                                     VkQueryType                                        query_type,
                                                     std::span<T>                                       data) noexcept
{
    constexpr auto stride = sizeof(T);

    auto as_bytes = std::as_bytes(data);

    return write_acceleration_structures_properties(ext, device, acceleration_structures, query_type, as_bytes, stride);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAccelerationStructureDeviceAddressKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkDeviceAddress get_acceleration_structure_device_address(
    const functions& ext, device_handle device, const VkAccelerationStructureDeviceAddressInfoKHR& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceAccelerationStructureCompatibilityKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkAccelerationStructureCompatibilityKHR get_device_acceleration_structure_compatibility(
    const functions& ext, device_handle device, const VkAccelerationStructureVersionInfoKHR& version_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAccelerationStructureBuildSizesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkAccelerationStructureBuildSizesInfoKHR
get_acceleration_structure_build_sizes(const functions&                                   ext,
                                       device_handle                                      device,
                                       VkAccelerationStructureBuildTypeKHR                build_type,
                                       const VkAccelerationStructureBuildGeometryInfoKHR& build_info,
                                       std::span<const std::uint32_t>                     max_primitive_counts) noexcept;

#endif // defined(VK_KHR_acceleration_structure)

namespace cmd
{

#if defined(VK_KHR_acceleration_structure)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBuildAccelerationStructuresKHR.html
FUBUKI_EXTENSION_API
void build_acceleration_structures(const functions&                                             ext,
                                   command_buffer_handle                                        command_buffer,
                                   std::span<const VkAccelerationStructureBuildGeometryInfoKHR> infos,
                                   md_vector_view<VkAccelerationStructureBuildRangeInfoKHR, 2>  build_range_infos) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBuildAccelerationStructuresIndirectKHR.html
FUBUKI_EXTENSION_API
void build_acceleration_structures_indirect(const functions&                                             ext,
                                            command_buffer_handle                                        command_buffer,
                                            std::span<const VkAccelerationStructureBuildGeometryInfoKHR> infos,
                                            std::span<const VkDeviceAddress>                             indirect_device_addresses,
                                            std::span<const std::uint32_t>                               indirect_strides,
                                            md_vector_view<std::uint32_t, 2>                             max_primitive_counts) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyAccelerationStructureKHR.html
FUBUKI_EXTENSION_API
void copy_acceleration_structure(const functions& ext, command_buffer_handle command_buffer, const VkCopyAccelerationStructureInfoKHR& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyAccelerationStructureToMemoryKHR.html
FUBUKI_EXTENSION_API
void copy_acceleration_structure_to_memory(const functions&                                  ext,
                                           command_buffer_handle                             command_buffer,
                                           const VkCopyAccelerationStructureToMemoryInfoKHR& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyMemoryToAccelerationStructureKHR.html
FUBUKI_EXTENSION_API
void copy_memory_to_acceleration_structure(const functions&                                  ext,
                                           command_buffer_handle                             command_buffer,
                                           const VkCopyMemoryToAccelerationStructureInfoKHR& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteAccelerationStructuresPropertiesKHR.html
FUBUKI_EXTENSION_API
void write_acceleration_structures_properties(const functions&                                   ext,
                                              command_buffer_handle                              command_buffer,
                                              std::span<const acceleration_structure_khr_handle> acceleration_structures,
                                              VkQueryType                                        query_type,
                                              query_pool_handle                                  query_pool,
                                              std::uint32_t                                      first_query) noexcept;

#endif // defined(VK_KHR_acceleration_structure)

} // namespace cmd

} // namespace fubuki::extension::khr_acceleration_structure

#endif // FUBUKI_EXTENSION_KHR_ACCELERATION_STRUCTURE_HPP
