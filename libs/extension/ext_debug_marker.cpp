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

#include "extension/ext_debug_marker.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::ext_debug_marker
{

#if defined(VK_EXT_debug_marker)

[[nodiscard]] std::expected<void, api_call_info>
debug_marker_set_object_tag(const functions& ext, device_handle device, const VkDebugMarkerObjectTagInfoEXT& tag_info) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkDebugMarkerSetObjectTagEXT">(ext, device.vk, std::addressof(tag_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]] std::expected<void, api_call_info>
debug_marker_set_object_name(const functions& ext, device_handle device, const VkDebugMarkerObjectNameInfoEXT& name_info) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkDebugMarkerSetObjectNameEXT">(ext, device.vk, std::addressof(name_info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

#endif // defined(VK_EXT_debug_marker)

namespace cmd
{

#if defined(VK_EXT_debug_marker)

void begin(const functions& ext, command_buffer_handle command_buffer, const VkDebugMarkerMarkerInfoEXT& marker_info) noexcept
{
    return fubuki::invoke<"vkCmdDebugMarkerBeginEXT">(ext, command_buffer.vk, std::addressof(marker_info));
}

void end(const functions& ext, command_buffer_handle command_buffer) noexcept
{
    return fubuki::invoke<"vkCmdDebugMarkerEndEXT">(ext, command_buffer.vk);
}

void insert(const functions& ext, command_buffer_handle command_buffer, const VkDebugMarkerMarkerInfoEXT& marker_info) noexcept
{
    return fubuki::invoke<"vkCmdDebugMarkerInsertEXT">(ext, command_buffer.vk, std::addressof(marker_info));
}

#endif // defined(VK_EXT_debug_marker)

} // namespace cmd

} // namespace fubuki::extension::ext_debug_marker
