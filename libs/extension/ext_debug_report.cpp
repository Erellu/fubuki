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

#include "extension/ext_debug_report.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::ext_debug_report
{

#if defined(VK_EXT_debug_report)

[[nodiscard]] std::expected<debug_report_callback_ext_handle, api_call_info>
create_debug_report_callback(const functions&                          ext,
                             instance_handle                           instance,
                             const VkDebugReportCallbackCreateInfoEXT& create_info,
                             const VkAllocationCallbacks&              allocator) noexcept
{
    debug_report_callback_ext_handle result;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDebugReportCallbackEXT">(ext, instance.vk, std::addressof(create_info), std::addressof(allocator), std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]] std::expected<debug_report_callback_ext_handle, api_call_info>
create_debug_report_callback(const functions& ext, instance_handle instance, const VkDebugReportCallbackCreateInfoEXT& create_info) noexcept
{
    debug_report_callback_ext_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDebugReportCallbackEXT">(ext, instance.vk, std::addressof(create_info), nullptr, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy_debug_report_callback(const functions& ext, instance_handle instance, debug_report_callback_ext_handle& callback) noexcept
{
    fubuki::invoke<"vkDestroyDebugReportCallbackEXT">(ext, instance.vk, callback.vk, nullptr);
    callback = null_handle;
}

void destroy_debug_report_callback(const functions&                  ext,
                                   instance_handle                   instance,
                                   debug_report_callback_ext_handle& callback,
                                   const VkAllocationCallbacks&      allocator) noexcept
{
    fubuki::invoke<"vkDestroyDebugReportCallbackEXT">(ext, instance.vk, callback.vk, std::addressof(allocator));
    callback = null_handle;
}

void debug_report_message(const functions&           ext,
                          instance_handle            instance,
                          VkDebugReportFlagsEXT      flags,
                          VkDebugReportObjectTypeEXT object_type,
                          std::uint64_t              object,
                          std::size_t                location,
                          std::int32_t               message_code,
                          const char*                p_layer_prefix,
                          const char*                p_message) noexcept
{
    return fubuki::invoke<"vkDebugReportMessageEXT">(ext, instance.vk, flags, object_type, object, location, message_code, p_layer_prefix, p_message);
}

#endif // defined(VK_EXT_debug_report)

} // namespace fubuki::extension::ext_debug_report
