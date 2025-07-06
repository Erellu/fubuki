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

#include "extension/ext_debug_utils.hpp"

#include <core/invoke.hpp>
#include <core/structure_type.hpp>

namespace fubuki::extension::ext_debug_utils
{

#if defined(VK_EXT_debug_utils)

[[nodiscard]]
std::expected<debug_utils_messenger_ext_handle, api_call_info>
create(const functions& ext, instance_handle instance, const VkDebugUtilsMessengerCreateInfoEXT& info) noexcept
{
    debug_utils_messenger_ext_handle messenger;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDebugUtilsMessengerEXT">(ext, instance.vk, std::addressof(info), nullptr, std::addressof(messenger.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return messenger;
}

[[nodiscard]]
std::expected<debug_utils_messenger_ext_handle, api_call_info> create(const functions&                          ext,
                                                                      instance_handle                           instance,
                                                                      const VkDebugUtilsMessengerCreateInfoEXT& info,
                                                                      const VkAllocationCallbacks&              callbacks) noexcept
{
    debug_utils_messenger_ext_handle messenger{};

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDebugUtilsMessengerEXT">(ext, instance.vk, std::addressof(info), std::addressof(callbacks), std::addressof(messenger.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return messenger;
}

void destroy(const functions& ext, instance_handle instance, debug_utils_messenger_ext_handle& messenger) noexcept
{
    fubuki::invoke<"vkDestroyDebugUtilsMessengerEXT">(ext, instance.vk, messenger.vk, nullptr);
    messenger = null_handle;
}

//------------------------------------------------------------------------------

void destroy(const functions&                  ext,
             instance_handle                   instance,
             debug_utils_messenger_ext_handle& messenger,
             const VkAllocationCallbacks&      callbacks) noexcept
{
    fubuki::invoke<"vkDestroyDebugUtilsMessengerEXT">(ext, instance.vk, messenger.vk, std::addressof(callbacks));
    messenger = null_handle;
}

#endif // defined(VK_EXT_debug_utils)

/********************************************************************************/
/*                                 COMMANDS                                     */
/********************************************************************************/

namespace cmd
{

#if defined(VK_EXT_debug_utils)

void begin_label(const functions& ext, command_buffer_handle command_buffer, const VkDebugUtilsLabelEXT& info) noexcept
{
    return fubuki::invoke<"vkCmdBeginDebugUtilsLabelEXT">(ext, command_buffer.vk, std::addressof(info));
}

//------------------------------------------------------------------------------

void end_label(const functions& ext, command_buffer_handle command_buffer) noexcept
{
    return fubuki::invoke<"vkCmdEndDebugUtilsLabelEXT">(ext, command_buffer.vk);
}

//------------------------------------------------------------------------------

void insert_label(const functions& ext, command_buffer_handle command_buffer, const VkDebugUtilsLabelEXT& info) noexcept
{
    return fubuki::invoke<"vkCmdInsertDebugUtilsLabelEXT">(ext, command_buffer.vk, std::addressof(info));
}

#endif // defined(VK_EXT_debug_utils)

} // namespace cmd

/********************************************************************************/
/*                                   QUEUE                                      */
/********************************************************************************/

namespace queue
{

#if defined(VK_EXT_debug_utils)

void begin_label(const functions& ext, queue_handle queue, const VkDebugUtilsLabelEXT& info) noexcept
{
    return fubuki::invoke<"vkQueueBeginDebugUtilsLabelEXT">(ext, queue.vk, std::addressof(info));
}

//------------------------------------------------------------------------------

void end_label(const functions& ext, queue_handle queue) noexcept { return fubuki::invoke<"vkQueueEndDebugUtilsLabelEXT">(ext, queue.vk); }

//------------------------------------------------------------------------------

void insert_label(const functions& ext, queue_handle queue, const VkDebugUtilsLabelEXT& info) noexcept
{
    return fubuki::invoke<"vkQueueInsertDebugUtilsLabelEXT">(ext, queue.vk, std::addressof(info));
}

#endif // defined(VK_EXT_debug_utils)

} // namespace queue

/********************************************************************************/
/*                              OBJECT MARKING                                  */
/********************************************************************************/

namespace object
{

#if defined(VK_EXT_debug_utils)

std::expected<void, api_call_info>
set_name(const functions& ext, device_handle device, std::uint64_t object, VkObjectType type, const char* const object_name) noexcept
{
    const VkDebugUtilsObjectNameInfoEXT info = {.sType        = structure_type_v<VkDebugUtilsObjectNameInfoEXT>,
                                                .pNext        = nullptr,
                                                .objectType   = type,
                                                .objectHandle = object,
                                                .pObjectName  = object_name};

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkSetDebugUtilsObjectNameEXT">(ext, device.vk, std::addressof(info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

//------------------------------------------------------------------------------

std::expected<void, api_call_info>
set_tag(const functions& ext, device_handle device, std::uint64_t object, VkObjectType type, const VkDebugUtilsObjectTagInfoEXT& info) noexcept
{
    const VkDebugUtilsObjectTagInfoEXT marker = {
        .sType        = structure_type_v<VkDebugUtilsObjectTagInfoEXT>,
        .pNext        = info.pNext,
        .objectType   = type,
        .objectHandle = object,
        .tagName      = info.tagName,
        .tagSize      = info.tagSize,
        .pTag         = info.pTag,
    };

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkSetDebugUtilsObjectTagEXT">(ext, device.vk, std::addressof(marker))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

#endif // defined(VK_EXT_debug_utils)

} // namespace object

/********************************************************************************/
/*                                   SUBMIT                                     */
/********************************************************************************/

#if defined(VK_EXT_debug_utils)

void submit_message(const functions&                       ext,
                    instance_handle                        instance,
                    VkDebugUtilsMessageSeverityFlagBitsEXT severity,
                    VkDebugUtilsMessageTypeFlagsEXT        type) noexcept
{
    return fubuki::invoke<"vkSubmitDebugUtilsMessageEXT">(ext, instance.vk, severity, type, nullptr);
}

void submit_message(const functions&                            ext,
                    instance_handle                             instance,
                    VkDebugUtilsMessageSeverityFlagBitsEXT      severity,
                    VkDebugUtilsMessageTypeFlagsEXT             type,
                    const VkDebugUtilsMessengerCallbackDataEXT& callback) noexcept
{
    return fubuki::invoke<"vkSubmitDebugUtilsMessageEXT">(ext, instance.vk, severity, type, std::addressof(callback));
}

#endif // defined(VK_EXT_debug_utils)

} // namespace fubuki::extension::ext_debug_utils
