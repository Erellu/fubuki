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

#ifndef FUBUKI_CORE_ASSERTION_HPP
#define FUBUKI_CORE_ASSERTION_HPP

#include <optional>
#include <source_location>
#include <sstream>
#include <string_view>

#include "core/config/macros.hpp"
#include "core/string_literal.hpp"

namespace fubuki
{

namespace detail
{

/// Dummy type default-constructible used to replace std::ostringstream in constexpr evaluation of fubuki::assertion.
struct dummy_stream
{
    // Do nothing
    template<typename T>
    constexpr const auto& operator<<(const T&) const
    {
        return *this;
    }

    template<typename T>
    constexpr auto& operator<<(const T&)
    {
        return *this;
    }

    static constexpr auto str() { return "<Unavailable>"; }
};

} // namespace detail

/**
 * Crashes after displaying an error message.
 * @param message (optional) Error message. Prints "<No error message specified>" if not specified or {} is passed.
 * @param condition_literal (optional) Condition as string literal. Prints "<Unspecified>" if not specified.
 * @param location (optional) Location of the crash. Defaults to were this function is called.
 */
[[noreturn]]
FUBUKI_CORE_API void crash(std::optional<std::string_view> message           = {},
                           string_literal                  condition_literal = {"<Unspecified>"},
                           std::source_location            location          = std::source_location::current());

/**
 *  Asserts condition is true. Calls terminate() and displays the error message otherwise.
 *  For convenience reasons, you should usually prefer fubuki_assert macro.
 *  @param condition Condition to evaluate.
 *  @param stream Stream used to form the error message.
 *  @param condition_literal (optional) Condition as string literal. Prints "<Unspecified>".
 *  @param location (optional) Location of the crash. Defaults to were this function is called.
 *  @note Provided as an extra function to help compilers provide nicer errors.
 */
template<typename stream_type>
requires std::is_same_v<std::decay_t<stream_type>, detail::dummy_stream> or std::is_same_v<std::decay_t<stream_type>, std::ostringstream>
inline constexpr void assertion(const bool           condition,
                                const stream_type&   stream,
                                string_literal       condition_literal = {"<Unspecified>"},
                                std::source_location location          = std::source_location::current())
{
    if(not condition)
    {
        if(std::is_constant_evaluated())
        {
            // Throwing in contexpr context is not allowed and fails the compilation
            throw std::logic_error("<Check previous error messages expanding the fubuki_assert macro for more information.>");
        }
        else // NOLINT(readability-else-after-return)
        {
            crash(stream.str(), condition_literal, location);
        }
    }
}

} // namespace fubuki

// NOLINTBEGIN(bugprone-macro-parentheses)
// Omitting parenthesis is required to allow syntax like the following:
// fubuki_assert(foo, "string literal" << bar);
#define fubuki_assert_impl(expression, message)                                                                              \
    do                                                                                                                       \
    {                                                                                                                        \
        if(const bool fubuki_assert_impl_success = (expression); not fubuki_assert_impl_success)                             \
        {                                                                                                                    \
            if(::std::is_constant_evaluated())                                                                               \
            {                                                                                                                \
                ::fubuki::assertion(fubuki_assert_impl_success, (::fubuki::detail::dummy_stream{} << message), #expression); \
            }                                                                                                                \
            else                                                                                                             \
            {                                                                                                                \
                ::fubuki::assertion(fubuki_assert_impl_success, (::std::ostringstream{} << message), #expression);           \
            }                                                                                                                \
        }                                                                                                                    \
    }                                                                                                                        \
    while(false)

#define fubuki_assert_if_impl(condition, expression, message)                                                                         \
    do                                                                                                                                \
    {                                                                                                                                 \
        if((condition))                                                                                                               \
        {                                                                                                                             \
            if(const bool fubuki_assert_if_impl_success = (expression); not fubuki_assert_if_impl_success)                            \
            {                                                                                                                         \
                if(::std::is_constant_evaluated())                                                                                    \
                {                                                                                                                     \
                    ::fubuki::assertion(fubuki_assert_if_impl_success, (::fubuki::detail::dummy_stream{} << (message)), #expression); \
                }                                                                                                                     \
                else                                                                                                                  \
                {                                                                                                                     \
                    ::fubuki::assertion(fubuki_assert_if_impl_success, (::std::ostringstream{} << message), #expression);             \
                }                                                                                                                     \
            }                                                                                                                         \
        }                                                                                                                             \
    }                                                                                                                                 \
    while(false)
// NOLINTEND(bugprone-macro-parentheses)

#if defined(FUBUKI_ENABLE_ASSERTION)

    #define fubuki_assert(expression, message)               fubuki_assert_impl(expression, message)
    #define fubuki_assert_if(condition, expression, message) fubuki_assert_if_impl(condition, expression, message)

#else
    #define fubuki_assert(expression, message)
    #define fubuki_assert_if(condition, expression, message)
#endif

/// Same as fubuki_assert, but this assertion is always enabled, even if FUBUKI_ENABLE_ASSERTION is not defined.
#define fubuki_always_assert(expression, message) fubuki_assert_impl(expression, message)

/// Same as fubuki_assert_if, but this assertion is always enabled, even if FUBUKI_ENABLE_ASSERTION is not defined.
#define fubuki_always_assert_if(expression, message) fubuki_assert_if_impl(expression, message)

#endif // FUBUKI_CORE_ASSERTION_HPP
