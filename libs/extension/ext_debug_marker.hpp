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

#ifndef FUBUKI_EXTENSION_EXT_DEBUG_MARKER_HPP
#define FUBUKI_EXTENSION_EXT_DEBUG_MARKER_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_debug_marker.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_debug_marker
{

#if defined(VK_EXT_debug_marker)
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDebugMarkerSetObjectTagEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
debug_marker_set_object_tag(const functions& ext, device_handle device, const VkDebugMarkerObjectTagInfoEXT& tag_info) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDebugMarkerSetObjectNameEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
debug_marker_set_object_name(const functions& ext, device_handle device, const VkDebugMarkerObjectNameInfoEXT& name_info) noexcept;

#endif // defined(VK_EXT_debug_marker)

namespace cmd
{

#if defined(VK_EXT_debug_marker)
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDebugMarkerBeginEXT.html
FUBUKI_EXTENSION_API void begin(const functions& ext, command_buffer_handle command_buffer, const VkDebugMarkerMarkerInfoEXT& marker_info) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDebugMarkerEndEXT.html
FUBUKI_EXTENSION_API void end(const functions& ext, command_buffer_handle command_buffer) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDebugMarkerInsertEXT.html
FUBUKI_EXTENSION_API void insert(const functions& ext, command_buffer_handle command_buffer, const VkDebugMarkerMarkerInfoEXT& marker_info) noexcept;

/**
 * A RAII object to label a scope for a command buffer.
 * Equivalent to a call to begin() when the object is created, and to end() at the scope exit.
 */
class scoped_label
{
public:

    scoped_label(const functions& ext, command_buffer_handle command_buffer, const VkDebugMarkerMarkerInfoEXT& info) noexcept
        : m_ext{ext},
          m_command_buffer{command_buffer}
    {
        begin(m_ext, m_command_buffer, info);
    }

    ~scoped_label() noexcept { end(m_ext, m_command_buffer); }

    scoped_label(const scoped_label&) noexcept            = delete;
    scoped_label(scoped_label&&) noexcept                 = delete;
    scoped_label& operator=(const scoped_label&) noexcept = delete;
    scoped_label& operator=(scoped_label&&) noexcept      = delete;

private:
    std::reference_wrapper<const functions> m_ext;
    command_buffer_handle                   m_command_buffer;
};

#endif // defined(VK_EXT_debug_marker)

} // namespace cmd

} // namespace fubuki::extension::ext_debug_marker

#endif // FUBUKI_EXTENSION_EXT_DEBUG_MARKER_HPP
