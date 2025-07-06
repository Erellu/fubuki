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

#ifndef FUBUKI_EXTENSION_EXT_OPACITY_MICROMAP_HPP
#define FUBUKI_EXTENSION_EXT_OPACITY_MICROMAP_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_opacity_micromap.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_opacity_micromap
{

#if defined(VK_EXT_opacity_micromap)

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

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMicromapBuildSizesEXT.html
FUBUKI_EXTENSION_API void get_micromap_build_sizes(const functions&                    ext,
                                                   device_handle                       device,
                                                   VkAccelerationStructureBuildTypeKHR build_type,
                                                   const VkMicromapBuildInfoEXT&       build_info,
                                                   VkMicromapBuildSizesInfoEXT&        result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateMicromapEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<micromap_ext_handle, api_call_info>
create(const functions& ext, device_handle device, const VkMicromapCreateInfoEXT& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateMicromapEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<micromap_ext_handle, api_call_info>
                                   create(const functions& ext, device_handle device, const VkMicromapCreateInfoEXT& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyMicromapEXT.html
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, micromap_ext_handle& micromap, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyMicromapEXT.html
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, micromap_ext_handle& micromap) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkBuildMicromapsEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API result build_micromaps(const functions&                        ext,
                                                          device_handle                           device,
                                                          deferred_operation_khr_handle           deferred_operation,
                                                          std::span<const VkMicromapBuildInfoEXT> infos) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMicromapEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API result copy_micromap(const functions&              ext,
                                                        device_handle                 device,
                                                        deferred_operation_khr_handle deferred_operation,
                                                        const VkCopyMicromapInfoEXT&  info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMicromapToMemoryEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API result copy_micromap_to_memory(const functions&                     ext,
                                                                  device_handle                        device,
                                                                  deferred_operation_khr_handle        deferred_operation,
                                                                  const VkCopyMicromapToMemoryInfoEXT& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMemoryToMicromapEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API result copy_memory_to_micromap(const functions&                     ext,
                                                                  device_handle                        device,
                                                                  deferred_operation_khr_handle        deferred_operation,
                                                                  const VkCopyMemoryToMicromapInfoEXT& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWriteMicromapsPropertiesEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> write_micromaps_properties(const functions&                     ext,
                                                                                                 device_handle                        device,
                                                                                                 std::span<const micromap_ext_handle> micromaps,
                                                                                                 VkQueryType                          query_type,
                                                                                                 std::span<std::byte>                 raw_data,
                                                                                                 std::size_t stride) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWriteMicromapsPropertiesEXT.html
template<typename T>
[[nodiscard]]
inline auto write_micromaps_properties(
    const functions& ext, device_handle device, std::span<const micromap_ext_handle> micromaps, VkQueryType query_type, std::span<T> data) noexcept
{
    constexpr auto stride = sizeof(T);

    auto as_bytes = std::as_bytes(data);

    return write_micromaps_properties(ext, device, micromaps, query_type, as_bytes, stride);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceMicromapCompatibilityEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API VkAccelerationStructureCompatibilityKHR
get_device_micromap_compatibility(const functions& ext, device_handle device, const VkMicromapVersionInfoEXT& version_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMicromapBuildSizesEXT.html
template<typename... elements>
[[nodiscard]] inline auto get_micromap_build_sizes(const functions&                    ext,
                                                   device_handle                       device,
                                                   VkAccelerationStructureBuildTypeKHR build_type,
                                                   const VkMicromapBuildInfoEXT&       build_info,
                                                   const pnext_chain<elements...>&     pnext) noexcept
{
    auto r = fubuki::make<VkMicromapBuildSizesInfoEXT>();
    fubuki::extend(r, pnext);

    detail::get_micromap_build_sizes(ext, device, build_type, build_info, r);

    return r;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMicromapBuildSizesEXT.html
[[nodiscard]] inline auto get_micromap_build_sizes(const functions&                    ext,
                                                   device_handle                       device,
                                                   VkAccelerationStructureBuildTypeKHR build_type,
                                                   const VkMicromapBuildInfoEXT&       build_info) noexcept
{
    return get_micromap_build_sizes(ext, device, build_type, build_info, empty_pnext_chain);
}

#endif // defined(VK_EXT_opacity_micromap)

namespace cmd
{

#if defined(VK_EXT_opacity_micromap)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBuildMicromapsEXT.html
FUBUKI_EXTENSION_API
void build_micromaps(const functions& ext, command_buffer_handle command_buffer, std::span<const VkMicromapBuildInfoEXT> infos) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyMicromapEXT.html
FUBUKI_EXTENSION_API
void copy_micromap(const functions& ext, command_buffer_handle command_buffer, const VkCopyMicromapInfoEXT& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyMicromapToMemoryEXT.html
FUBUKI_EXTENSION_API
void copy_micromap_to_memory(const functions& ext, command_buffer_handle command_buffer, const VkCopyMicromapToMemoryInfoEXT& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyMemoryToMicromapEXT.html
FUBUKI_EXTENSION_API
void copy_memory_to_micromap(const functions& ext, command_buffer_handle command_buffer, const VkCopyMemoryToMicromapInfoEXT& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteMicromapsPropertiesEXT.html
FUBUKI_EXTENSION_API
void write_micromaps_properties(const functions&                     ext,
                                command_buffer_handle                command_buffer,
                                std::span<const micromap_ext_handle> micromaps,
                                VkQueryType                          query_type,
                                query_pool_handle                    query_pool,
                                std::uint32_t                        first_query) noexcept;

#endif // defined(VK_EXT_opacity_micromap)

} // namespace cmd

} // namespace fubuki::extension::ext_opacity_micromap

#endif // FUBUKI_EXTENSION_EXT_OPACITY_MICROMAP_HPP
