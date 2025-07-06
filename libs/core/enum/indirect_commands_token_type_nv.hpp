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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#ifndef FUBUKI_CORE_ENUM_INDIRECT_COMMANDS_TOKEN_TYPE_NV_HPP
#define FUBUKI_CORE_ENUM_INDIRECT_COMMANDS_TOKEN_TYPE_NV_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_NV_device_generated_commands)

/// Returns a std::string_view corresponding to a VkIndirectCommandsTokenTypeNV.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkIndirectCommandsTokenTypeNV e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV);
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_EXT_mesh_shader) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV);
#endif // #if defined (VK_EXT_mesh_shader)

#if defined(VK_NV_device_generated_commands_compute) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NV);
#endif // #if defined (VK_NV_device_generated_commands_compute)

#if defined(VK_NV_device_generated_commands_compute) 
        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NV);
#endif // #if defined (VK_NV_device_generated_commands_compute)

        FUBUKI_MAKE_CASE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_MAX_ENUM_NV);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkIndirectCommandsTokenTypeNV.
[[nodiscard]] inline auto to_string(VkIndirectCommandsTokenTypeNV e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_NV_device_generated_commands)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_INDIRECT_COMMANDS_TOKEN_TYPE_NV_HPP
