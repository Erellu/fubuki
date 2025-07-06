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

#ifndef FUBUKI_FUYU_DEBUG_LAYER_MESSAGE_HPP
#define FUBUKI_FUYU_DEBUG_LAYER_MESSAGE_HPP

#include <array>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include <core/enum/object_type.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu::debug
{

/// A printable representation of a message sent by a validation layer.
/// Unlike a layer_message_view, there is no need to synchronise the lifetime of this structure with the VkDebugUtilsMessengerCallbackDataEXT.
/// Use this structure when you need to keep track of the messages sent.
struct layer_message
{
    /// A representation of the message identifier.
    struct identifier
    {
        struct view
        {
            std::int32_t     number  = 0;
            std::string_view message = "<Unknown>";

            template<typename char_type, typename traits = std::char_traits<char_type>>
            friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const view& i)
            {
                return out << "{id: " << i.number << ", message: " << std::quoted(i.message) << "}";
            }

#if defined(VK_EXT_debug_utils)
            [[nodiscard]] static constexpr view from_vk(const VkDebugUtilsMessengerCallbackDataEXT&&) = delete; // Temporaries not allowed
            [[nodiscard]] static constexpr view from_vk(const VkDebugUtilsMessengerCallbackDataEXT& vk)
            {
                return {.number = vk.messageIdNumber, .message = vk.pMessageIdName != nullptr ? vk.pMessageIdName : ""};
            }
#endif // defined(VK_EXT_debug_utils)
        };

        std::int32_t number  = 0;
        std::string  message = "<Unknown>";

        [[nodiscard]] constexpr operator view() const
        {
            return {
                .number  = number,
                .message = message,
            };
        }

        template<typename char_type, typename traits = std::char_traits<char_type>>
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const identifier& i)
        {
            return out << static_cast<view>(i);
        }
    };

    /// A representation of a label.
    struct label
    {
        struct view
        {
            static constexpr std::array<std::uint8_t, 3> default_rgb = {255, 255, 255}; // NOLINT(cppcoreguidelines-avoid-magic-numbers)

            std::string_view                 name = "<Unnamed label>";
            std::span<const std::uint8_t, 3> rgb  = {default_rgb};

            template<typename char_type, typename traits = std::char_traits<char_type>>
            friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const view& l)
            {
                return out << "\033[38;2;" << static_cast<int>(l.rgb[0]) << ";" << static_cast<int>(l.rgb[1]) << ";" << static_cast<int>(l.rgb[2])
                           << "m" << l.name << "\033[0m";
            }
        };

        label() = default;

#if defined(VK_EXT_debug_utils)
        label(const VkDebugUtilsLabelEXT& vk)
            : name{vk.pLabelName != nullptr ? vk.pLabelName : "<Unnamed label>"},
              rgb{
                  static_cast<std::uint8_t>(vk.color[0] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                  static_cast<std::uint8_t>(vk.color[1] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                  static_cast<std::uint8_t>(vk.color[2] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
              }
        {
        }
#endif // defined(VK_EXT_debug_utils)

        std::string                 name = "<Unnamed label>";
        std::array<std::uint8_t, 3> rgb  = view::default_rgb;

        [[nodiscard]] constexpr operator view() const
        {
            return {
                .name = name,
                .rgb  = rgb,
            };
        }

        template<typename char_type, typename traits = std::char_traits<char_type>>
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const label& l)
        {
            return out << static_cast<view>(l);
        }
    };

    /// A representation of an object name and handle.
    struct object_name
    {
        struct view
        {
            VkObjectType     type   = VK_OBJECT_TYPE_UNKNOWN;
            std::uint64_t    handle = 0;
            std::string_view name   = "<Unnamed object>";

            template<typename char_type, typename traits = std::char_traits<char_type>>
            friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const view& l)
            {
                return out << "{handle: " << l.handle << " type: " << to_string_view(l.type) << " name: " << l.name << "}";
            }
#if defined(VK_EXT_debug_utils)
            [[nodiscard]] static constexpr view from_vk(const VkDebugUtilsObjectNameInfoEXT&&) = delete; // Temporaries not allowed
            [[nodiscard]] static constexpr view from_vk(const VkDebugUtilsObjectNameInfoEXT& vk)
            {
                return {.type = vk.objectType, .handle = vk.objectHandle, .name = vk.pObjectName != nullptr ? vk.pObjectName : "<Unnamed object>"};
            }
#endif // defined(VK_EXT_debug_utils)
        };

        object_name() = default;

#if defined(VK_EXT_debug_utils)
        object_name(const VkDebugUtilsObjectNameInfoEXT& vk)
            : type{vk.objectType},
              handle{vk.objectHandle},
              name{vk.pObjectName != nullptr ? vk.pObjectName : "<Unnamed object>"}
        {
        }
#endif // defined(VK_EXT_debug_utils)

        VkObjectType  type   = VK_OBJECT_TYPE_UNKNOWN;
        std::uint64_t handle = 0;
        std::string   name   = "<Unnamed object>";

        [[nodiscard]] constexpr operator view() const
        {
            return {
                .type   = type,
                .handle = handle,
                .name   = name,
            };
        }

        template<typename char_type, typename traits = std::char_traits<char_type>>
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const object_name& o)
        {
            return out << static_cast<view>(o);
        }
    };

    identifier               id                    = {};
    std::string              message               = {};
    std::vector<label>       queue_labels          = {};
    std::vector<label>       command_buffer_labels = {};
    std::vector<object_name> objects               = {};

#if defined(VK_EXT_debug_utils)
    // Clang isn't able to infer it's safe in this context
    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

    [[nodiscard]] static constexpr layer_message from_vk(const VkDebugUtilsMessengerCallbackDataEXT& data)
    {
        return {
            .id                    = {.number = data.messageIdNumber, .message = data.pMessageIdName != nullptr ? data.pMessageIdName : ""},
            .message               = {data.pMessage != nullptr ? data.pMessage : ""},
            .queue_labels          = {data.pQueueLabels, data.pQueueLabels + data.queueLabelCount},
            .command_buffer_labels = {data.pCmdBufLabels, data.pCmdBufLabels + data.cmdBufLabelCount},
            .objects               = {data.pObjects, data.pObjects + data.objectCount},
        };
    }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif

#endif // defined(VK_EXT_debug_utils)

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, [[maybe_unused]] const layer_message& m)
    {
#if defined(VK_EXT_debug_utils)
        out << "layer_message: " << m.id << "\n"
            << "Message: " << m.message << "\n"
            << "Involved queue labels: ";

        for(const auto& queue_label : m.queue_labels)
        {
            out << queue_label << ", ";
        }

        out << "\nInvolved command buffer labels: ";

        for(const auto& command_buffer_label : m.command_buffer_labels)
        {
            out << command_buffer_label << ", ";
        }

        out << "\nInvolved objects: ";

        for(const auto& object : m.objects)
        {
            out << object << ", ";
        }
#endif // defined(VK_EXT_debug_utils)
        return out;
    }
};

/// A printable view of a VkDebugUtilsMessengerCallbackDataEXT.
struct layer_message_view
{
    using identifier  = layer_message::identifier::view;
    using label       = layer_message::label::view;
    using object_name = layer_message::object_name::view;

#if defined(VK_EXT_debug_utils)
    identifier                                     id                    = {};
    std::string_view                               message               = {};
    std::span<const VkDebugUtilsLabelEXT>          queue_labels          = {};
    std::span<const VkDebugUtilsLabelEXT>          command_buffer_labels = {};
    std::span<const VkDebugUtilsObjectNameInfoEXT> objects               = {};

    // Clang isn't able to infer it's safe in this context
    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

    // Temporaries are not allowed
    [[nodiscard]] static constexpr layer_message_view from_vk(const VkDebugUtilsMessengerCallbackDataEXT&& d) noexcept = delete;
    [[nodiscard]] static constexpr layer_message_view from_vk(const VkDebugUtilsMessengerCallbackDataEXT& d) noexcept
    {
        return layer_message_view{
            .id                    = {.number = d.messageIdNumber, .message = d.pMessageIdName != nullptr ? d.pMessageIdName : ""},
            .message               = {d.pMessage != nullptr ? d.pMessage : ""},
            .queue_labels          = std::span{d.pQueueLabels, d.pQueueLabels + d.queueLabelCount},
            .command_buffer_labels = std::span{d.pCmdBufLabels, d.pCmdBufLabels + d.cmdBufLabelCount},
            .objects               = std::span{d.pObjects, d.pObjects + d.objectCount},
        };
    }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif

#endif // defined(VK_EXT_debug_utils)

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, [[maybe_unused]] const layer_message_view& v)
    {
#if defined(VK_EXT_debug_utils)

    // Clang isn't able to infer it's safe in this context
    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

        out << "layer_message: " << v.id << "\n"
            << "Message: " << v.message << "\n"
            << "Involved queue labels: ";

        for(const auto& l : v.queue_labels)
        {
            const std::string_view            label_name = {l.pLabelName != nullptr ? l.pLabelName : "<Unnamed label>"};
            const std::array<std::uint8_t, 3> rgb        = {
                static_cast<std::uint8_t>(l.color[0] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                static_cast<std::uint8_t>(l.color[1] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                static_cast<std::uint8_t>(l.color[2] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
            };

            out << label{.name = label_name, .rgb = rgb} << ", ";
        }

        out << "\nInvolved command buffer labels: ";

        for(const auto& l : v.command_buffer_labels)
        {
            const std::string_view            label_name = {l.pLabelName != nullptr ? l.pLabelName : "<Unnamed label>"};
            const std::array<std::uint8_t, 3> rgb        = {
                static_cast<std::uint8_t>(l.color[0] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                static_cast<std::uint8_t>(l.color[1] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                static_cast<std::uint8_t>(l.color[2] * 255.F), // NOLINT(cppcoreguidelines-avoid-magic-numbers)
            };

            out << label{.name = label_name, .rgb = rgb} << ", ";
        }

        out << "\nInvolved objects: ";

        for(const auto& object : v.objects)
        {
            out << object_name::from_vk(object) << ", ";
        }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif

#endif // defined(VK_EXT_debug_utils)

        return out;
    }
};

} // namespace fubuki::fuyu::debug

#endif // FUBUKI_FUYU_DEBUG_LAYER_MESSAGE_HPP
