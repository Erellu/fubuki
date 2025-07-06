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

#ifndef FUBUKI_CORE_VALIDATE_HPP
#define FUBUKI_CORE_VALIDATE_HPP

#include <expected>
#include <optional>
#include <source_location>
#include <sstream>
#include <stdexcept>
#include <type_traits>

#include "core/assertion.hpp" // IWYU pragma: keep (unused in release builds)
#include "core/config/macros.hpp"
#include "core/result.hpp"
#include "core/string_literal.hpp"

namespace fubuki
{

/// Information about a call.
template<typename T>
requires requires(const T t) {
    { t.operator bool() };
} and std::is_default_constructible_v<T> and std::is_nothrow_invocable_v<decltype(&T::operator bool), const T>
struct call_info
{
    using result_type = T;

    result_type                   result       = {};                              ///< Result returned by a call.
    std::optional<string_literal> call_literal = {};                              ///< Call evaluated.
    std::source_location          location     = std::source_location::current(); ///< Location of the error

    /// Converts a result to a boolean.
    [[nodiscard]]
    constexpr explicit operator bool() const noexcept
    {
        return result.operator bool();
    }

    /// Converts a result to the underlying Vulkan result code.
    [[nodiscard]]
    constexpr operator VkResult() const noexcept
    requires requires(result_type t) {
        { t.operator VkResult() };
    }
    // FIXME: this triggers an internal compiler error in MSVC
    /*and std::is_nothrow_invocable_v<decltype(&result_type::operator VkResult), result_type>*/
    {
        return result.operator VkResult();
    }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const call_info& c)
    {
        out << "Call: ";

        // Cannot use value_or, which will attempt to construct a fubuki::string_literal in a non-constexpr context
        if(c.call_literal.has_value())
        {
            out << *c.call_literal << "\n";
        }
        else
        {
            out << "<Unspecified - consider using the macro fubuki_validate>\n";
        }

        out << "Result: ";

        if constexpr(requires { out << c.result; })
        {
            out << c.result << "\n";
        }
        else
        {
            out << "<unavailable - provide operator<< for your type>\n";
        }

        return out << "File: " << c.location.file_name() << "\n"
                   << "Line: " << c.location.line() << "\n"
                   << "Column: " << c.location.column() << "\n"
                   << "Function: " << c.location.function_name() << "\n";
    }
};

template<typename T>
call_info(T, std::optional<string_literal>, std::source_location) -> call_info<T>;

template<typename T>
call_info(T, string_literal, std::source_location) -> call_info<T>;

template<typename T>
call_info(T, string_literal) -> call_info<T>;

template<typename result>
struct call_exception : std::runtime_error
{
    call_exception(call_info<result> c) : std::runtime_error{(std::ostringstream{} << c).str()}, call{c} {}

    call_info<result> call = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const call_exception& c)
    {
        return out << c.call;
    }
};

template<typename T>
call_exception(call_info<T>) -> call_exception<T>;

/// Information about a Vulkan API call.
using api_call_info = call_info<result>;

/// An exception that CAN be thrown when an API call fails.
using api_call_exception = call_exception<result>;

namespace detail::validate_by
{

struct throw_call_exception
{
};

struct assertion
{
};

struct expected
{
};

template<typename T>
concept method = std::is_same_v<T, throw_call_exception> or std::is_same_v<T, assertion> or std::is_same_v<T, expected>;

/**
 *  Validates a bool-like object is true and throws an instance of call_info if it's 'false'.
 *  For convenience reasons, you should usually prefer fubuki_validate macro.
 *  @param code Bool-like object to check.
 *  @param call_literal (optional) The call to check as a string_literal.
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 *
 *  @warning fubuki::call_info DOES NOT INHERIT FROM std::exception. You MUST handle this type explicitely in try/catch blocks.
 */
template<typename T>
inline constexpr void validate_call(throw_call_exception,
                                    T&&                  code,
                                    const string_literal call_literal = "<Unspecified>",
                                    std::source_location location     = std::source_location::current())
{
    if(not code)
    {
        throw call_exception{
            call_info{
                      .result       = std::forward<T>(code),
                      .call_literal = call_literal,
                      .location     = location,
                      }
        };
    }
}

/**
 *  Validates a bool-like object by fubuki::assertion in debug builds, and does nothing in release builds.
 *  @param code Bool-like object to check.
 *  @param call_literal (optional) The call to check as a string_literal.
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 */
template<typename T>
inline constexpr void validate_call(assertion,
                                    [[maybe_unused]] T&&                  code,
                                    [[maybe_unused]] const string_literal call_literal = "<Unspecified>",
                                    [[maybe_unused]] std::source_location location     = std::source_location::current()) noexcept
{
    if(not code)
    {
#if defined(FUBUKI_DEBUG_BUILD)
        if(std::is_constant_evaluated())
        {
            fubuki::assertion(static_cast<bool>(std::forward<T>(code)), (fubuki::detail::dummy_stream{} << "Call failed"), call_literal, location);
        }
        else
        {
            fubuki::assertion(static_cast<bool>(std::forward<T>(code)), (std::ostringstream{} << "Call failed."), call_literal, location);
        }
#endif
    }
}

/**
 *  Validates a bool-like object. Returns an instance of std::expected<void, call_info> holding a call_info if the result is 'false'.
 *  @param code Bool-like object to check.
 *  @param call_literal (optional) The call to check as a string_literal..
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 */
template<typename T>
[[nodiscard]]
inline constexpr std::expected<void, call_info<T>> validate_call(expected,
                                                                 T&&                  code,
                                                                 const string_literal call_literal = "<Unspecified>",
                                                                 std::source_location location     = std::source_location::current()) noexcept
{
    if(not code)
    {
        return std::unexpected{
            call_info<T>{
                         .result       = std::forward<T>(code),
                         .call_literal = call_literal,
                         .location     = location,
                         }
        };
    }

    return {};
}

/**
 *  Validates a VkResult and throws an instance of call_info if it's not VK_SUCCESS.
 *  For convenience reasons, you should usually prefer fubuki_validate macro.
 *  @param code Vulkan result code to check.
 *  @param call_literal (optional) The call to check as a string_literal.
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 *
 *  @warning fubuki::call_info DOES NOT INHERIT FROM std::exception. You MUST handle this type explicitely in try/catch blocks.
 */
inline constexpr void validate_call(throw_call_exception,
                                    const VkResult       code,
                                    const string_literal call_literal = "<Unspecified>",
                                    std::source_location location     = std::source_location::current())
{
    return validate_call(throw_call_exception{}, result{code}, call_literal, location);
}

/**
 *  Validates a VkResult by fubuki::assertion in debug builds, and does nothing in release builds.
 *  @param code Vulkan result code to check.
 *  @param call_literal (optional) The call to check as a string_literal.
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 */
inline constexpr void validate_call(assertion,
                                    const VkResult       code,
                                    const string_literal call_literal = "<Unspecified>",
                                    std::source_location location     = std::source_location::current()) noexcept
{
    return validate_call(assertion{}, result{code}, call_literal, location);
}

/**
 *  Validates a VkResult. Returns an instance of std::expected<void, call_info> holding a call_info if the result is not VK_SUCCESS.
 *  @param code Vulkan result code to check.
 *  @param call_literal (optional) The call to check as a string_literal..
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 */
[[nodiscard]]
inline constexpr auto validate_call(expected,
                                    const VkResult       code,
                                    const string_literal call_literal = "<Unspecified>",
                                    std::source_location location     = std::source_location::current()) noexcept
{
    return validate_call(expected{}, result{code}, call_literal, location);
}

} // namespace detail::validate_by

using detail::validate_by::validate_call;

//------------------------------------------------------------------------------

/**
 *  Validates a VkResult (crashes if it is not success).
 *  For convenience reasons, you should usually prefer fubuki_assert macro.
 *  @param code Vulkan result code to check.
 *  @param call_literal (optional) Condition as string literal. Prints "<No condition literal specified>"
 *  if not specified or {} is passed.
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 */
FUBUKI_CORE_API
void assertion(VkResult code, string_literal call_literal = "<Unspecified>", std::source_location location = std::source_location::current());

//------------------------------------------------------------------------------

/// The various methods of validations for fubuki_validate.
namespace validate_by
{

inline constexpr auto throw_call_exception
    = detail::validate_by::throw_call_exception{};                  ///< If this call fails, throw an instance of fubuki::call_exception.
inline constexpr auto expected  = detail::validate_by::expected{};  ///< Return a std::expected<T, fubuki::call_info>.
inline constexpr auto assertion = detail::validate_by::assertion{}; ///< If this call fails, trigger an assert.

} // namespace validate_by

#define fubuki_validate(validation_method, call) ::fubuki::validate_call(validation_method, call, #call)

} // namespace fubuki

#endif // FUBUKI_CORE_VALIDATE_HPP
