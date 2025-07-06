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

#ifndef FUBUKI_EXTENSION_EXT_SHADER_OBJECT_HPP
#define FUBUKI_EXTENSION_EXT_SHADER_OBJECT_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_shader_object.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_shader_object
{

#if defined(VK_EXT_shader_object)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateShadersEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<shader_ext_handle>, api_call_info> create_shaders(
    const functions& ext, device_handle device, std::span<const VkShaderCreateInfoEXT> create_infos, const VkAllocationCallbacks& allocator);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateShadersEXT.html
[[nodiscard]] inline auto create_shaders(const functions&                             ext,
                                         device_handle                                device,
                                         std::initializer_list<VkShaderCreateInfoEXT> create_infos,
                                         const VkAllocationCallbacks&                 allocator)
{
    return create_shaders(ext, device, std::span{create_infos}, allocator);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateShadersEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<shader_ext_handle>, api_call_info>
                                   create_shaders(const functions& ext, device_handle device, std::span<const VkShaderCreateInfoEXT> create_infos);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateShadersEXT.html
[[nodiscard]] inline auto create_shaders(const functions& ext, device_handle device, std::initializer_list<VkShaderCreateInfoEXT> create_infos)
{
    return create_shaders(ext, device, std::span{create_infos});
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyShaderEXT.html
FUBUKI_EXTENSION_API
void destroy_shader(const functions& ext, device_handle device, shader_ext_handle& shader, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyShaderEXT.html
FUBUKI_EXTENSION_API
void destroy_shader(const functions& ext, device_handle device, shader_ext_handle& shader) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetShaderBinaryDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<std::byte>, api_call_info>
                                   get_shader_binary_data(const functions& ext, device_handle device, VkShaderEXT shader);

#endif // defined(VK_EXT_shader_object)

namespace cmd
{

#if defined(VK_EXT_shader_object)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindShadersEXT.html
FUBUKI_EXTENSION_API
void bind_shaders(const functions&                       ext,
                  command_buffer_handle                  command_buffer,
                  std::span<const VkShaderStageFlagBits> stages,
                  std::span<const shader_ext_handle>     shaders = {}) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthClampRangeEXT.html
FUBUKI_EXTENSION_API void set_depth_clamp_range(const functions&            ext,
                                                command_buffer_handle       command_buffer,
                                                VkDepthClampModeEXT         depth_clamp_mode,
                                                const VkDepthClampRangeEXT& depth_clamp_range) noexcept;

#endif // defined(VK_EXT_shader_object)

} // namespace cmd

} // namespace fubuki::extension::ext_shader_object

#endif // FUBUKI_EXTENSION_EXT_SHADER_OBJECT_HPP
