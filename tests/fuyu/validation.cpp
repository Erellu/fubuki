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

#include "validation.hpp"

#include <map>
#include <mutex>
#include <thread>
#include <tuple>

#include <gtest/gtest.h>

namespace fubuki::test
{

namespace
{

[[nodiscard]] auto& error_messages()
{
    static std::map<std::thread::id, std::vector<fuyu::debug::layer_message>> m;
    return m;
}

[[nodiscard]] auto& warning_messages()
{
    static std::map<std::thread::id, std::vector<fuyu::debug::layer_message>> m;
    return m;
}

struct mutexes
{
    std::mutex error;
    std::mutex warning;
};

[[nodiscard]] auto& mutex()
{
    static mutexes m;
    return m;
}

} // anonymous namespace

VkBool32 validation_layer_callback(VkDebugUtilsMessageSeverityFlagBitsEXT      severity,
                                   VkDebugUtilsMessageTypeFlagsEXT             type,
                                   const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
                                   void*                                       user_data)
{
    std::ignore = type;
    std::ignore = user_data;

    static constexpr VkDebugUtilsMessengerCallbackDataEXT empty_placeholder = {};

    if(severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
    {
        const std::scoped_lock<std::mutex> lock{mutex().error};

        auto message = fuyu::debug::layer_message::from_vk(callback_data == nullptr ? empty_placeholder : *callback_data);

        error_messages()[std::this_thread::get_id()].emplace_back(std::move(message));
    }

    if(severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
    {
        const std::scoped_lock<std::mutex> lock{mutex().warning};

        auto message = fuyu::debug::layer_message::from_vk(callback_data == nullptr ? empty_placeholder : *callback_data);

        warning_messages()[std::this_thread::get_id()].emplace_back(std::move(message));
    }

    // We don't test 'info' and 'verbose'

    return VK_FALSE;
}

std::span<const fuyu::debug::layer_message> errors() noexcept
{
    const auto it = error_messages().find(std::this_thread::get_id());

    return it == error_messages().cend() ? std::span<const fuyu::debug::layer_message>{} : it->second;
}

std::span<const fuyu::debug::layer_message> warnings() noexcept
{
    const auto it = warning_messages().find(std::this_thread::get_id());

    return it == warning_messages().cend() ? std::span<const fuyu::debug::layer_message>{} : it->second;
}

void clear_errors()
{
    const std::scoped_lock<std::mutex> lock{mutex().error};
    error_messages().clear();
}

void clear_warnings()
{
    const std::scoped_lock<std::mutex> lock{mutex().warning};
    warning_messages().clear();
}

} // namespace fubuki::test
