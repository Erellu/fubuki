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

#ifndef FUBUKI_FUYU_INFORMATION_DEBUG_MESSENGER_HPP
#define FUBUKI_FUYU_INFORMATION_DEBUG_MESSENGER_HPP

#include <functional>
#include <optional>

#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/debug/layers.hpp"
#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::debug::messenger.
struct debug_messenger
{
#if defined(VK_EXT_debug_utils)
    using underlying_type = VkDebugUtilsMessengerCreateInfoEXT;

    struct messages
    {
        VkDebugUtilsMessageSeverityFlagsEXT  severity  = default_severity;                       ///< Message severity enabled for this messenger.
        VkDebugUtilsMessageTypeFlagsEXT      type      = default_messages;                       ///< Message types enabled for this messenger.
        PFN_vkDebugUtilsMessengerCallbackEXT callback  = debug::layer_callback::standard_output; ///< The callback handling messages.
        void*                                user_data = nullptr;                                ///< Custom user data.

        [[nodiscard]] friend constexpr bool operator==(const messages& a, const messages& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const messages& a, const messages& b) noexcept = default;
    };

    static constexpr auto default_severity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    static constexpr auto default_messages = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;

    messages message = {}; ///< Specifies how and what messages are handled by this messenger.

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callbacks.

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const debug_messenger> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType           = structure_type_v<underlying_type>,
            .pNext           = nullptr,
            .flags           = 0, // Currently reserved
            .messageSeverity = s.message.severity,
            .messageType     = s.message.type,
            .pfnUserCallback = s.message.callback,
            .pUserData       = s.message.user_data,
        };
    }

#endif // defined(VK_EXT_debug_utils)

    [[nodiscard]] friend constexpr bool operator==(const debug_messenger& a, const debug_messenger& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const debug_messenger& a, const debug_messenger& b) noexcept = default;
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_DEBUG_MESSENGER_HPP
