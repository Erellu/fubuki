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

#ifndef FUBUKI_FUYU_DEBUG_LAYERS_HPP
#define FUBUKI_FUYU_DEBUG_LAYERS_HPP

#include <string>
#include <vector>

#include <core/config/macros.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu::debug
{

/// Returns all available validation layers names and properties.
[[nodiscard]] FUBUKI_FUYU_API std::expected<std::vector<VkLayerProperties>, api_call_info> layers();

//------------------------------------------------------------------------------

/// Indicates if at least a validation layer is available.
[[nodiscard]]
inline bool validation_layers_available()
{
    const auto available_layers = layers();

    return available_layers.has_value() and not layers()->empty();
}

/// Filters the extension names to only return the ones currently supported, as a contiguous C string array.
[[nodiscard]] FUBUKI_FUYU_API small_vector<const char*> validate_layers(std::span<const std::string> requested_layers);

namespace layer_callback
{

#if defined(VK_EXT_debug_utils)
/// A callback function that prints to std::cerr if the message is an error or a warning, or to std::clog otherwise.
FUBUKI_FUYU_API
extern VKAPI_ATTR VkBool32 VKAPI_CALL standard_output(VkDebugUtilsMessageSeverityFlagBitsEXT      severity,
                                                      VkDebugUtilsMessageTypeFlagsEXT             type,
                                                      const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
                                                      void*                                       user_data);
#endif // defined(VK_EXT_debug_utils)

} // namespace layer_callback

} // namespace fubuki::fuyu::debug

#endif // FUBUKI_FUYU_DEBUG_LAYERS_HPP
