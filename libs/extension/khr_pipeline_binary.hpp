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

#ifndef FUBUKI_EXTENSION_KHR_PIPELINE_BINARY_HPP
#define FUBUKI_EXTENSION_KHR_PIPELINE_BINARY_HPP

#include <core/as_span.hpp>
#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_pipeline_binary.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_pipeline_binary
{

#if defined(VK_KHR_pipeline_binary)

namespace information
{

struct data
{
    using underlying_type = VkPipelineBinaryDataInfoKHR;

    pipeline_binary_khr_handle handle = {};

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const data> cref) noexcept
    {
        return underlying_type{.sType = structure_type_v<underlying_type>, .pNext = {}, .pipelineBinary = cref.get().handle.vk};
    }
};

} // namespace information

struct binary_data
{
    VkPipelineBinaryKeyKHR  key      = {.sType = structure_type_v<VkPipelineBinaryKeyKHR>, .pNext = {}, .keySize = {}, .key = {}};
    small_vector<std::byte> contents = {};
};

namespace detail
{

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineKeyKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
get_pipeline_key(const functions& ext, device_handle device, const VkPipelineCreateInfoKHR& info, VkPipelineBinaryKeyKHR& result) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineKeyKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<binary_data, api_call_info>
get_pipeline_binary_data(const functions& ext, device_handle device, const VkPipelineBinaryDataInfoKHR& info) noexcept;

[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<pipeline_binary_khr_handle>, api_call_info> create_pipeline_binaries(
    const functions& ext, device_handle device, const VkPipelineBinaryCreateInfoKHR& create_info, const VkAllocationCallbacks* allocator) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyPipelineBinaryKHR.html
void destroy_pipeline_binaries(const functions&                      ext,
                               device_handle                         device,
                               std::span<pipeline_binary_khr_handle> pipeline_binaries,
                               const VkAllocationCallbacks*          allocator) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseCapturedPipelineDataKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> release_captured_pipeline_data(const functions& ext,
                                                                                                     device_handle    device,
                                                                                                     const VkReleaseCapturedPipelineDataInfoKHR& info,
                                                                                                     const VkAllocationCallbacks* allocator) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseCapturedPipelineDataKHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> release_captured_pipeline_data(const functions&                ext,
                                                                                       device_handle                   device,
                                                                                       any_pipeline                    pipeline,
                                                                                       const VkAllocationCallbacks*    allocator,
                                                                                       const pnext_chain<elements...>& pnext) noexcept
{
    auto vk_info     = fubuki::make<VkReleaseCapturedPipelineDataInfoKHR>();
    vk_info.pipeline = std::visit([](const auto& h) noexcept { return h.vk; }, pipeline);
    fubuki::extend(vk_info, pnext);

    return release_captured_pipeline_data(ext, device, vk_info, allocator);
}

} // namespace detail

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreatePipelineBinariesKHR.html
[[nodiscard]] inline std::expected<small_vector<pipeline_binary_khr_handle>, api_call_info> create_pipeline_binaries(
    const functions& ext, device_handle device, const VkPipelineBinaryCreateInfoKHR& create_info, const VkAllocationCallbacks& allocator) noexcept
{
    return detail::create_pipeline_binaries(ext, device, create_info, std::addressof(allocator));
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreatePipelineBinariesKHR.html
[[nodiscard]] inline std::expected<small_vector<pipeline_binary_khr_handle>, api_call_info>
create_pipeline_binaries(const functions& ext, device_handle device, const VkPipelineBinaryCreateInfoKHR& create_info) noexcept
{
    return detail::create_pipeline_binaries(ext, device, create_info, nullptr);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyPipelineBinaryKHR.html
inline void destroy_pipeline_binaries(const functions&                      ext,
                                      device_handle                         device,
                                      std::span<pipeline_binary_khr_handle> pipeline_binaries,
                                      const VkAllocationCallbacks&          allocator) noexcept
{
    return detail::destroy_pipeline_binaries(ext, device, pipeline_binaries, std::addressof(allocator));
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyPipelineBinaryKHR.html
inline void destroy_pipeline_binaries(const functions& ext, device_handle device, std::span<pipeline_binary_khr_handle> pipeline_binaries) noexcept
{
    return detail::destroy_pipeline_binaries(ext, device, pipeline_binaries, nullptr);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyPipelineBinaryKHR.html
inline void destroy_pipeline_binary(const functions& ext, device_handle device, pipeline_binary_khr_handle pipeline_binary) noexcept
{
    return destroy_pipeline_binaries(ext, device, fubuki::as_span(pipeline_binary));
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyPipelineBinaryKHR.html
inline void destroy_pipeline_binary(const functions&             ext,
                                    device_handle                device,
                                    pipeline_binary_khr_handle   pipeline_binary,
                                    const VkAllocationCallbacks& allocator) noexcept
{
    return destroy_pipeline_binaries(ext, device, fubuki::as_span(pipeline_binary), allocator);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineKeyKHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkPipelineBinaryKeyKHR, api_call_info>
get_pipeline_key(const functions& ext, device_handle device, const pnext_chain<elements...>& pnext) noexcept
{
    auto info = fubuki::make<VkPipelineCreateInfoKHR>();
    fubuki::extend(info, pnext);

    auto result = fubuki::make<VkPipelineBinaryKeyKHR>();

    if(const auto check = detail::get_pipeline_key(ext, device, info, result); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineKeyKHR.html
[[nodiscard]] inline auto get_pipeline_key(const functions& ext, device_handle device) noexcept
{
    return get_pipeline_key(ext, device, empty_pnext_chain);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineBinaryDataKHR.html
template<typename... elements>
[[nodiscard]] inline auto
get_pipeline_binary_data(const functions& ext, device_handle device, const information::data& data, const pnext_chain<elements...>& pnext) noexcept
{
    auto vk_data = to_underlying(data);
    fubuki::extend(vk_data, pnext);

    return detail::get_pipeline_binary_data(ext, device, vk_data);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPipelineBinaryDataKHR.html
[[nodiscard]] inline auto get_pipeline_binary_data(const functions& ext, device_handle device, const information::data& data) noexcept
{
    return get_pipeline_binary_data(ext, device, data, empty_pnext_chain);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseCapturedPipelineDataKHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info>
release_captured_pipeline_data(const functions& ext, device_handle device, any_pipeline pipeline, const pnext_chain<elements...>& pnext) noexcept
{
    return detail::release_captured_pipeline_data(ext, device, pipeline, nullptr, pnext);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseCapturedPipelineDataKHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> release_captured_pipeline_data(const functions&                ext,
                                                                                       device_handle                   device,
                                                                                       any_pipeline                    pipeline,
                                                                                       const VkAllocationCallbacks&    allocator,
                                                                                       const pnext_chain<elements...>& pnext) noexcept
{
    return detail::release_captured_pipeline_data(ext, device, pipeline, std::addressof(allocator), pnext);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseCapturedPipelineDataKHR.html
[[nodiscard]] inline std::expected<void, api_call_info>
release_captured_pipeline_data(const functions& ext, device_handle device, any_pipeline pipeline) noexcept
{
    return release_captured_pipeline_data(ext, device, pipeline, empty_pnext_chain);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkReleaseCapturedPipelineDataKHR.html
[[nodiscard]] inline std::expected<void, api_call_info>
release_captured_pipeline_data(const functions& ext, device_handle device, any_pipeline pipeline, const VkAllocationCallbacks& allocator) noexcept
{
    return release_captured_pipeline_data(ext, device, pipeline, allocator, empty_pnext_chain);
}

#endif // defined(VK_KHR_pipeline_binary)

} // namespace fubuki::extension::khr_pipeline_binary

#endif // FUBUKI_EXTENSION_KHR_PIPELINE_BINARY_HPP
