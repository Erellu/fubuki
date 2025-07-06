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

#ifndef FUBUKI_EXTENSION_EXT_SHADER_MODULE_IDENTIFIER_HPP
#define FUBUKI_EXTENSION_EXT_SHADER_MODULE_IDENTIFIER_HPP

#include <variant>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_shader_module_identifier.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_shader_module_identifier
{

#if defined(VK_EXT_shader_module_identifier)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetShaderModuleIdentifierEXT.html
FUBUKI_EXTENSION_API void get_shader_module_identifier(const functions&             ext,
                                                       device_handle                device,
                                                       shader_module_handle         shader_module,
                                                       VkShaderModuleIdentifierEXT& result) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetShaderModuleCreateInfoIdentifierEXT.html
FUBUKI_EXTENSION_API void get_shader_module_create_info_identifier(const functions&                ext,
                                                                   device_handle                   device,
                                                                   const VkShaderModuleCreateInfo& create_info,
                                                                   VkShaderModuleIdentifierEXT&    result) noexcept;

} // namespace detail

template<typename... elements>
inline auto
get_shader_module_identifier(const functions& ext, device_handle device, shader_module_handle shader_module, const pnext_chain<elements...>& pnext)
{
    auto result = fubuki::make<VkShaderModuleIdentifierEXT>();
    fubuki::extend(result, pnext);

    detail::get_shader_module_identifier(ext, device, shader_module, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetShaderModuleIdentifierEXT.html
[[nodiscard]] inline auto get_shader_module_identifier(const functions& ext, device_handle device, shader_module_handle shader_module)
{
    return get_shader_module_identifier(ext, device, shader_module, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetShaderModuleCreateInfoIdentifierEXT.html
template<typename... elements>
[[nodiscard]] inline auto get_shader_module_create_info_identifier(const functions&                ext,
                                                                   device_handle                   device,
                                                                   const VkShaderModuleCreateInfo& create_info,
                                                                   const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkShaderModuleIdentifierEXT>();
    fubuki::extend(result, pnext);

    detail::get_shader_module_create_info_identifier(ext, device, create_info, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetShaderModuleCreateInfoIdentifierEXT.html
[[nodiscard]] inline auto
get_shader_module_create_info_identifier(const functions& ext, device_handle device, const VkShaderModuleCreateInfo& create_info) noexcept
{
    return get_shader_module_create_info_identifier(ext, device, create_info, empty_pnext_chain);
}

/// Generic indirection to either get_shader_module_identifier or get_shader_module_create_info_identifier based on the source type.
template<typename source_type, typename... elements>
requires(std::is_same_v<source_type, VkShaderModuleCreateInfo> or std::is_same_v<source_type, shader_module_handle>)
[[nodiscard]] inline auto
shader_module_identifier(const functions& ext, device_handle device, const source_type& source, const pnext_chain<elements...>& pnext) noexcept
{
    if constexpr(std::is_same_v<source_type, shader_module_handle>)
    {
        return get_shader_module_identifier(ext, device, source, pnext);
    }
    else if constexpr(std::is_same_v<source_type, VkShaderModuleCreateInfo>)
    {
        return get_shader_module_create_info_identifier(ext, device, source, pnext);
    }
    else
    {
        return std::monostate{};
    }
}

/// Generic indirection to either get_shader_module_identifier or get_shader_module_create_info_identifier based on the source type.
template<typename source_type>
[[nodiscard]] inline auto shader_module_identifier(const functions& ext, device_handle device, const source_type& source) noexcept
{
    return shader_module_identifier(ext, device, source, empty_pnext_chain);
}

#endif // defined(VK_EXT_shader_module_identifier)

} // namespace fubuki::extension::ext_shader_module_identifier

#endif // FUBUKI_EXTENSION_EXT_SHADER_MODULE_IDENTIFIER_HPP
