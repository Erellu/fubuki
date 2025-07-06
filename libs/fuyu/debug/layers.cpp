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

#include <iostream>
#include <ranges>

#include "fuyu/debug/layers.hpp"

#include "fuyu/debug/layer_message.hpp"

extern "C"
{

// Extracted from vulkan_core.h (Apache 2.0)
// Allows to compile with VK_NO_PROTOTYPES

// NOLINTBEGIN(readability-identifier-naming)
extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
// NOLINTEND(readability-identifier-naming)

} // extern "C"

namespace fubuki::fuyu::debug
{

[[nodiscard]]
std::expected<std::vector<VkLayerProperties>, api_call_info> layers()
{
    std::vector<VkLayerProperties> result;

    std::uint32_t count = 0;
    if(const auto check = fubuki_validate(validate_by::expected, vkEnumerateInstanceLayerProperties(&count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    result.resize(count);
    if(const auto check = fubuki_validate(validate_by::expected, vkEnumerateInstanceLayerProperties(&count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]]
small_vector<const char*> validate_layers(std::span<const std::string> requested_layers)
{
    const auto available_layers = layers();

    const auto available = [&available_layers](const std::string& layer_name) noexcept
    {
        if(not available_layers)
        {
            return false;
        }

        for(const auto& available_layer : *available_layers)
        {
            if(const auto as_c_str = static_cast<const char*>(available_layer.layerName); layer_name == as_c_str)
            {
                return true;
            }
        }

        return false;
    };

    constexpr auto c_str = [](const std::string& str) noexcept { return str.c_str(); };

    // Safe to take c_str here: we delete validate_layers for temporary std::vector, so the strings are forced to outlive this function
    auto result = requested_layers | std::views::filter(available) | std::views::transform(c_str);

    return {result.begin(), result.end()};
}

//------------------------------------------------------------------------------

namespace layer_callback
{

VKAPI_ATTR VkBool32 VKAPI_CALL standard_output(VkDebugUtilsMessageSeverityFlagBitsEXT           severity,
                                               [[maybe_unused]] VkDebugUtilsMessageTypeFlagsEXT type,
                                               const VkDebugUtilsMessengerCallbackDataEXT*      callback_data,
                                               [[maybe_unused]] void*                           user_data)
{
    if(callback_data != nullptr)
    {
        if(severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT or severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
        {
            std::cerr << fuyu::debug::layer_message_view::from_vk(*callback_data);
        }

        if(severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT or severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT)
        {
            std::clog << fuyu::debug::layer_message_view::from_vk(*callback_data);
        }
    }

    return VK_FALSE;
}
} // namespace layer_callback

} // namespace fubuki::fuyu::debug
