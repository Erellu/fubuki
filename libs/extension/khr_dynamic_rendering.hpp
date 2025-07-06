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

#ifndef FUBUKI_EXTENSION_KHR_DYNAMIC_RENDERING_HPP
#define FUBUKI_EXTENSION_KHR_DYNAMIC_RENDERING_HPP

#include <functional>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_dynamic_rendering.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_dynamic_rendering::cmd
{

#if defined(VK_KHR_dynamic_rendering)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRenderingKHR.html
FUBUKI_EXTENSION_API
void begin_rendering(const functions& ext, command_buffer_handle command_buffer, const VkRenderingInfo& rendering_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndRenderingKHR.html
FUBUKI_EXTENSION_API
void end_rendering(const functions& ext, command_buffer_handle command_buffer) noexcept;

/// A RAII object that can be used to record in the current scope.
/// Equivalent of an immediate call to begin_rendering and a call end_rendering at the end of the current scope.
class rendering_scope
{
public:

    rendering_scope(const functions& ext, command_buffer_handle command_buffer, const VkRenderingInfo& rendering_info) noexcept
        : m_ext{ext},
          m_command_buffer{command_buffer}
    {
        begin_rendering(m_ext, m_command_buffer, rendering_info);
    }

    ~rendering_scope() noexcept { end_rendering(m_ext, m_command_buffer); }

    rendering_scope(const rendering_scope&) noexcept            = delete;
    rendering_scope(rendering_scope&&) noexcept                 = delete;
    rendering_scope& operator=(const rendering_scope&) noexcept = delete;
    rendering_scope& operator=(rendering_scope&&) noexcept      = delete;

private:
    std::reference_wrapper<const functions> m_ext;
    command_buffer_handle                   m_command_buffer;
};

#endif // defined(VK_KHR_dynamic_rendering)

} // namespace fubuki::extension::khr_dynamic_rendering::cmd

#endif // FUBUKI_EXTENSION_KHR_DYNAMIC_RENDERING_HPP
