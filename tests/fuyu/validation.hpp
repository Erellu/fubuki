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

#ifndef FUBUKI_TEST_FUYU_VALIDATION_HPP
#define FUBUKI_TEST_FUYU_VALIDATION_HPP

#include <functional>
#include <ostream>
#include <span>

#include <core/vulkan.hpp>
#include <fuyu/debug/layer_message.hpp>

namespace fubuki::test
{

/// Function used by test::context::init.
VkBool32 validation_layer_callback(VkDebugUtilsMessageSeverityFlagBitsEXT      severity,
                                   VkDebugUtilsMessageTypeFlagsEXT             type,
                                   const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
                                   void*                                       user_data);

/// Helper struct to print a range of messages. Use as std::cout << print_layer_messages{a_range};
struct print_layer_messages
{
    print_layer_messages(std::span<const fuyu::debug::layer_message> m, std::function<void(void)> clear) noexcept
        : messages{m},
          clear_logs{std::move(clear)}
    {
    }

    ~print_layer_messages() { clear_logs(); }

    std::span<const fuyu::debug::layer_message> messages;
    std::function<void(void)>                   clear_logs;

    template<typename char_type, typename traits = std::char_traits<char_type> >
    friend std::ostream& operator<<(std::basic_ostream<char_type, traits>& out, const print_layer_messages& p)
    {
        for(const auto& m : p.messages)
        {
            out << m << "\n";
        }

        return out;
    }
};

/// Returns the validation errors that occurred in the current thread.
[[nodiscard]]
std::span<const fuyu::debug::layer_message> errors() noexcept;

/// Returns the validation errors that occurred in the current thread.
[[nodiscard]]
std::span<const fuyu::debug::layer_message> warnings() noexcept;

/// Indicates if a validation error occurred in the current thread.
[[nodiscard]]
inline bool no_errors() noexcept
{
    return errors().empty();
}

/// Indicates if a validation error occurred in the current thread.
[[nodiscard]]
inline bool no_warnings() noexcept
{
    return warnings().empty();
}

/// Clears errors(). Use this to isolate validation errors.
void clear_errors();

/// Clears warnings(). Use this to isolate validation errors.
void clear_warnings();

[[nodiscard]]
inline auto print_and_clear_errors()
{
    return print_layer_messages{errors(), clear_errors};
}

[[nodiscard]]
inline auto print_and_clear_warnings()
{
    return print_layer_messages{warnings(), clear_warnings};
}

} // namespace fubuki::test

#endif // FUBUKI_TEST_FUYU_VALIDATION_HPP
