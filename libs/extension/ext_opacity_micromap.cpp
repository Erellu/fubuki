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

#include "extension/ext_opacity_micromap.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_opacity_micromap
{

#if defined(VK_EXT_opacity_micromap)

namespace detail
{

void get_micromap_build_sizes(const functions&                    ext,
                              device_handle                       device,
                              VkAccelerationStructureBuildTypeKHR build_type,
                              const VkMicromapBuildInfoEXT&       build_info,
                              VkMicromapBuildSizesInfoEXT&        result) noexcept
{
    return fubuki::invoke<"vkGetMicromapBuildSizesEXT">(ext, device.vk, build_type, &build_info, &result);
}

} // namespace detail

namespace
{

[[nodiscard]]
std::expected<micromap_ext_handle, api_call_info>
create(const functions& ext, device_handle device, const VkMicromapCreateInfoEXT& create_info, const VkAllocationCallbacks* allocator) noexcept
{
    micromap_ext_handle result;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateMicromapEXT">(ext, device.vk, &create_info, allocator, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // anonymous namespace

[[nodiscard]] std::expected<micromap_ext_handle, api_call_info>
create(const functions& ext, device_handle device, const VkMicromapCreateInfoEXT& create_info, const VkAllocationCallbacks& allocator) noexcept
{
    return create(ext, device, create_info, std::addressof(allocator));
}

[[nodiscard]]
std::expected<micromap_ext_handle, api_call_info>
create(const functions& ext, device_handle device, const VkMicromapCreateInfoEXT& create_info) noexcept
{
    return create(ext, device, create_info, nullptr);
}

void destroy(const functions& ext, device_handle device, micromap_ext_handle& micromap, const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyMicromapEXT">(ext, device.vk, micromap.vk, std::addressof(allocator));

    micromap = null_handle;
}

void destroy(const functions& ext, device_handle device, micromap_ext_handle& micromap) noexcept
{
    fubuki::invoke<"vkDestroyMicromapEXT">(ext, device.vk, micromap.vk, nullptr);

    micromap = null_handle;
}

[[nodiscard]]
result build_micromaps(const functions&                        ext,
                       device_handle                           device,
                       deferred_operation_khr_handle           deferred_operation,
                       std::span<const VkMicromapBuildInfoEXT> infos) noexcept
{
    const auto r = fubuki::invoke<"vkBuildMicromapsEXT">(ext, device.vk, deferred_operation.vk, vk_size(infos), infos.data());

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
result copy_micromap(const functions&              ext,
                     device_handle                 device,
                     deferred_operation_khr_handle deferred_operation,
                     const VkCopyMicromapInfoEXT&  info) noexcept
{
    const auto r = fubuki::invoke<"vkCopyMicromapEXT">(ext, device.vk, deferred_operation.vk, std::addressof(info));

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
result copy_micromap_to_memory(const functions&                     ext,
                               device_handle                        device,
                               deferred_operation_khr_handle        deferred_operation,
                               const VkCopyMicromapToMemoryInfoEXT& info) noexcept
{
    const auto r = fubuki::invoke<"vkCopyMicromapToMemoryEXT">(ext, device.vk, deferred_operation.vk, std::addressof(info));

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
result copy_memory_to_micromap(const functions&                     ext,
                               device_handle                        device,
                               deferred_operation_khr_handle        deferred_operation,
                               const VkCopyMemoryToMicromapInfoEXT& info) noexcept
{
    const auto r = fubuki::invoke<"vkCopyMemoryToMicromapEXT">(ext, device.vk, deferred_operation.vk, std::addressof(info));

    if(r == VK_SUCCESS or r == VK_OPERATION_DEFERRED_KHR or r == VK_OPERATION_NOT_DEFERRED_KHR)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

[[nodiscard]]
std::expected<void, api_call_info> write_micromaps_properties(const functions&                     ext,
                                                              device_handle                        device,
                                                              std::span<const micromap_ext_handle> micromaps,
                                                              VkQueryType                          query_type,
                                                              std::span<std::byte>                 raw_data,
                                                              std::size_t                          stride) noexcept
{
    auto micromaps_handles = collect<VkMicromapEXT>(micromaps);

    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkWriteMicromapsPropertiesEXT">(ext, device.vk, vk_size(micromaps_handles), micromaps_handles.data(), query_type, vk_size(raw_data), raw_data.data(), stride));
}

[[nodiscard]]
VkAccelerationStructureCompatibilityKHR
get_device_micromap_compatibility(const functions& ext, device_handle device, const VkMicromapVersionInfoEXT& version_info) noexcept
{
    VkAccelerationStructureCompatibilityKHR r = VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR;

    fubuki::invoke<"vkGetDeviceMicromapCompatibilityEXT">(ext, device.vk, std::addressof(version_info), std::addressof(r));

    return r;
}

#endif // defined(VK_EXT_opacity_micromap)

namespace cmd
{

#if defined(VK_EXT_opacity_micromap)

void build_micromaps(const functions& ext, command_buffer_handle command_buffer, std::span<const VkMicromapBuildInfoEXT> infos) noexcept
{
    return fubuki::invoke<"vkCmdBuildMicromapsEXT">(ext, command_buffer.vk, vk_size(infos), infos.data());
}

void copy_micromap(const functions& ext, command_buffer_handle command_buffer, const VkCopyMicromapInfoEXT& info) noexcept
{
    return fubuki::invoke<"vkCmdCopyMicromapEXT">(ext, command_buffer.vk, &info);
}

void copy_micromap_to_memory(const functions& ext, command_buffer_handle command_buffer, const VkCopyMicromapToMemoryInfoEXT& info) noexcept
{
    return fubuki::invoke<"vkCmdCopyMicromapToMemoryEXT">(ext, command_buffer.vk, &info);
}

void copy_memory_to_micromap(const functions& ext, command_buffer_handle command_buffer, const VkCopyMemoryToMicromapInfoEXT& info) noexcept
{
    return fubuki::invoke<"vkCmdCopyMemoryToMicromapEXT">(ext, command_buffer.vk, &info);
}

void write_micromaps_properties(const functions&                     ext,
                                command_buffer_handle                command_buffer,
                                std::span<const micromap_ext_handle> micromaps,
                                VkQueryType                          query_type,
                                query_pool_handle                    query_pool,
                                std::uint32_t                        first_query) noexcept
{
    auto micromaps_handles = collect<VkMicromapEXT>(micromaps);

    return fubuki::invoke<"vkCmdWriteMicromapsPropertiesEXT">(
        ext, command_buffer.vk, vk_size(micromaps_handles), micromaps_handles.data(), query_type, query_pool.vk, first_query);
}

#endif // defined(VK_EXT_opacity_micromap)

} // namespace cmd

} // namespace fubuki::extension::ext_opacity_micromap
