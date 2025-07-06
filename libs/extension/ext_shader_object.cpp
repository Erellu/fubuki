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

#include <ranges>

#include "extension/ext_shader_object.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_shader_object
{

#if defined(VK_EXT_shader_object)

[[nodiscard]]
std::expected<small_vector<shader_ext_handle>, api_call_info> create_shaders(const functions&                       ext,
                                                                             device_handle                          device,
                                                                             std::span<const VkShaderCreateInfoEXT> create_infos,
                                                                             const VkAllocationCallbacks&           allocator)
{
    small_vector<VkShaderEXT> result;
    result.resize(create_infos.size());

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateShadersEXT">(ext, device.vk, vk_size(create_infos), create_infos.data(), std::addressof(allocator), result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    auto fubuki_handles = result | std::views::transform([](const auto& vk) constexpr noexcept { return shader_ext_handle{vk}; });
    return small_vector<shader_ext_handle>{fubuki_handles.begin(), fubuki_handles.end()};
}

[[nodiscard]]
std::expected<small_vector<shader_ext_handle>, api_call_info>
create_shaders(const functions& ext, device_handle device, std::span<const VkShaderCreateInfoEXT> create_infos)
{
    small_vector<VkShaderEXT> result;
    result.resize(create_infos.size());

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateShadersEXT">(ext, device.vk, vk_size(create_infos), create_infos.data(), nullptr, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    auto fubuki_handles = result | std::views::transform([](const auto& vk) constexpr noexcept { return shader_ext_handle{vk}; });
    return small_vector<shader_ext_handle>{fubuki_handles.begin(), fubuki_handles.end()};
}

void destroy_shader(const functions& ext, device_handle device, shader_ext_handle& shader, const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyShaderEXT">(ext, device.vk, shader.vk, std::addressof(allocator));
    shader = null_handle;
}

void destroy_shader(const functions& ext, device_handle device, shader_ext_handle& shader) noexcept
{
    fubuki::invoke<"vkDestroyShaderEXT">(ext, device.vk, shader.vk, nullptr);
    shader = null_handle;
}

[[nodiscard]]
std::expected<std::vector<std::byte>, api_call_info> get_shader_binary_data(const functions& ext, device_handle device, VkShaderEXT shader)
{
    std::size_t byte_count = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetShaderBinaryDataEXT">(ext, device.vk, shader, &byte_count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<std::byte> result;
    result.resize(byte_count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetShaderBinaryDataEXT">(ext, device.vk, shader, &byte_count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_EXT_shader_object)

namespace cmd
{

#if defined(VK_EXT_shader_object)

void bind_shaders(const functions&                       ext,
                  command_buffer_handle                  command_buffer,
                  std::span<const VkShaderStageFlagBits> stages,
                  std::span<const shader_ext_handle>     shaders) noexcept
{
    auto shaders_handles = collect<VkShaderEXT>(shaders);

    return fubuki::invoke<"vkCmdBindShadersEXT">(ext, command_buffer.vk, vk_size(stages), stages.data(), shaders_handles.data());
}

void set_depth_clamp_range(const functions&            ext,
                           command_buffer_handle       command_buffer,
                           VkDepthClampModeEXT         depth_clamp_mode,
                           const VkDepthClampRangeEXT& depth_clamp_range) noexcept
{
    return fubuki::invoke<"vkCmdSetDepthClampRangeEXT">(ext, command_buffer.vk, depth_clamp_mode, std::addressof(depth_clamp_range));
}

#endif // defined(VK_EXT_shader_object)

} // namespace cmd

} // namespace fubuki::extension::ext_shader_object
