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

#include "extension/ext_shader_module_identifier.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::ext_shader_module_identifier::detail
{

#if defined(VK_EXT_shader_module_identifier)

void get_shader_module_identifier(const functions&             ext,
                                  device_handle                device,
                                  shader_module_handle         shader_module,
                                  VkShaderModuleIdentifierEXT& result) noexcept
{
    return fubuki::invoke<"vkGetShaderModuleIdentifierEXT">(ext, device.vk, shader_module.vk, &result);
}

void get_shader_module_create_info_identifier(const functions&                ext,
                                              device_handle                   device,
                                              const VkShaderModuleCreateInfo& create_info,
                                              VkShaderModuleIdentifierEXT&    result) noexcept
{
    return fubuki::invoke<"vkGetShaderModuleCreateInfoIdentifierEXT">(ext, device.vk, &create_info, &result);
}
#endif // defined(VK_EXT_shader_module_identifier)

} // namespace fubuki::extension::ext_shader_module_identifier::detail
