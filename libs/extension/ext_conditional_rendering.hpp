﻿/*
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

#ifndef FUBUKI_EXTENSION_EXT_CONDITIONAL_RENDERING_HPP
#define FUBUKI_EXTENSION_EXT_CONDITIONAL_RENDERING_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_conditional_rendering.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_conditional_rendering::cmd
{

#if defined(VK_EXT_conditional_rendering)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginConditionalRenderingEXT.html
FUBUKI_EXTENSION_API
void begin(const functions& ext, command_buffer_handle command_buffer, const VkConditionalRenderingBeginInfoEXT& info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndConditionalRenderingEXT.html
FUBUKI_EXTENSION_API
void end(const functions& ext, command_buffer_handle command_buffer) noexcept;

/**
 * A RAII object to start conditional rendering in a scope.
 * Equivalent to a call to begin() when the object is created, and to end() at the scope exit.
 */
class scoped_rendering
{
public:

    scoped_rendering(const functions& ext, command_buffer_handle command_buffer, const VkConditionalRenderingBeginInfoEXT& info) noexcept
        : m_ext{ext},
          m_command_buffer{command_buffer}
    {
        begin(m_ext, m_command_buffer, info);
    }

    ~scoped_rendering() noexcept { end(m_ext, m_command_buffer); }

    scoped_rendering(const scoped_rendering&) noexcept            = delete;
    scoped_rendering(scoped_rendering&&) noexcept                 = delete;
    scoped_rendering& operator=(const scoped_rendering&) noexcept = delete;
    scoped_rendering& operator=(scoped_rendering&&) noexcept      = delete;

private:
    std::reference_wrapper<const functions> m_ext;
    command_buffer_handle                   m_command_buffer;
};

#endif // defined(VK_EXT_conditional_rendering)

} // namespace fubuki::extension::ext_conditional_rendering::cmd

#endif // FUBUKI_EXTENSION_EXT_CONDITIONAL_RENDERING_HPP
