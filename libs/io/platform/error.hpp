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

#ifndef FUBUKI_IO_PLATFORM_ERROR_HPP
#define FUBUKI_IO_PLATFORM_ERROR_HPP

#include <ostream>
#include <variant>

#include <core/config/setup.hpp>
#include <core/validate.hpp>

#include "io/platform/linux/error.hpp"
#include "io/platform/linux/wayland/code.hpp"
#include "io/platform/linux/xlib/code.hpp"
#include "io/platform/win32/code.hpp"

namespace fubuki::io::platform
{

namespace detail::error
{

template<configuration::window_system w>
struct traits;

template<>
struct traits<configuration::window_system::win32>
{
    using code   = win32::code;
    using result = win32::result;
};

template<>
struct traits<configuration::window_system::xlib>
{
    using code   = linux_bsd::xlib::code;
    using result = linux_bsd::xlib::result;
};

template<>
struct traits<configuration::window_system::wayland>
{
    using code   = linux_bsd::wayland::code::any;
    using result = linux_bsd::wayland::result;
};

template<>
struct traits<configuration::window_system::unknown>
{
    // Works, because win32::code is just an opaque enum like std::byte
    using code   = win32::code;
    using result = win32::result;
};

} // namespace detail::error

template<configuration::window_system w>
class call_result
{
public:

    using code   = typename detail::error::traits<w>::code;
    using result = typename detail::error::traits<w>::result;

    static constexpr auto window_system = w;
    constexpr call_result(code c) noexcept : m_result{c} {}
    constexpr call_result(result r) noexcept : m_result{r} {}

    constexpr call_result() noexcept                              = default;
    constexpr call_result(const call_result&) noexcept            = default;
    constexpr call_result(call_result&&) noexcept                 = default;
    constexpr call_result& operator=(const call_result&) noexcept = default;
    constexpr call_result& operator=(call_result&&) noexcept      = default;
    constexpr ~call_result() noexcept                             = default;

    [[nodiscard]] constexpr operator bool() const noexcept { return m_result.operator bool(); }

    [[nodiscard]] friend constexpr bool operator==(const call_result& a, const call_result& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const call_result& a, const call_result& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const call_result& a, const call_result& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const call_result& r)
    {
        return out << "call_result<" << w << ">{" << r.m_result << "}";
    }

private:

    result m_result = {};
};

/// For Linux API calls unrelated to window systems (mmap, etc.)
class linux_call_result
{

public:
    using code   = linux_bsd ::code;
    using result = linux_bsd::result;

    constexpr linux_call_result(code c) noexcept : m_result{c} {}
    constexpr linux_call_result(result r) noexcept : m_result{r} {}

    constexpr linux_call_result() noexcept                                    = default;
    constexpr linux_call_result(const linux_call_result&) noexcept            = default;
    constexpr linux_call_result(linux_call_result&&) noexcept                 = default;
    constexpr linux_call_result& operator=(const linux_call_result&) noexcept = default;
    constexpr linux_call_result& operator=(linux_call_result&&) noexcept      = default;
    constexpr ~linux_call_result() noexcept                                   = default;

    [[nodiscard]] constexpr operator bool() const noexcept { return m_result.operator bool(); }

    [[nodiscard]] friend constexpr bool operator==(const linux_call_result& a, const linux_call_result& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const linux_call_result& a, const linux_call_result& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const linux_call_result& a, const linux_call_result& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const linux_call_result& r)
    {
        return out << "call_result{" << r.m_result << "}";
    }

private:

    result m_result = {};
};

struct any_call_result
{
    using value_type = std::variant<call_result<configuration::window_system::unknown>,
                                    call_result<configuration::window_system::win32>,
                                    call_result<configuration::window_system::wayland>,
                                    call_result<configuration::window_system::xlib>,
                                    linux_call_result>;

    template<configuration::window_system w, bool b>
    constexpr any_call_result(typename call_result<w>::template tag<b> t) noexcept : value{call_result<w>(t)}
    {
    }

    template<configuration::window_system w>
    constexpr any_call_result(call_result<w> t) noexcept : value{t}
    {
    }

    constexpr any_call_result(value_type v) noexcept : value{v} {}
    constexpr any_call_result() noexcept                                  = default;
    constexpr any_call_result(const any_call_result&) noexcept            = default;
    constexpr any_call_result(any_call_result&&) noexcept                 = default;
    constexpr any_call_result& operator=(const any_call_result&) noexcept = default;
    constexpr any_call_result& operator=(any_call_result&&) noexcept      = default;
    constexpr ~any_call_result() noexcept                                 = default;

    [[nodiscard]] constexpr operator bool() const noexcept
    {
        return std::visit([](const auto& v) noexcept -> bool { return v.operator bool(); }, value);
    }

    [[nodiscard]] friend constexpr bool operator==(const any_call_result& a, const any_call_result& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const any_call_result& a, const any_call_result& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const any_call_result& a, const any_call_result& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const any_call_result& r)
    {
        return std::visit([&out](const auto& variant) -> std::basic_ostream<char_type, traits>& { return out << variant; }, r.value);
    }

    value_type value = {};
};

template<configuration::window_system w>
using call_info = fubuki::call_info<call_result<w>>;

using linux_call_info = fubuki::call_info<linux_call_result>;

/// An structure describing a platform-specific call error.
struct any_call_info
{
    using value_type = std::variant<call_info<configuration::window_system::unknown>,
                                    call_info<configuration::window_system::win32>,
                                    call_info<configuration::window_system::wayland>,
                                    call_info<configuration::window_system::xlib>,
                                    linux_call_info>;

    template<configuration::window_system w>
    constexpr any_call_info(call_info<w> t) noexcept : value{t}
    {
    }

    constexpr any_call_info(linux_call_info t) noexcept : value{t} {}

    constexpr any_call_info(value_type v) noexcept : value{v} {}
    constexpr any_call_info() noexcept                                = default;
    constexpr any_call_info(const any_call_info&) noexcept            = default;
    constexpr any_call_info(any_call_info&&) noexcept                 = default;
    constexpr any_call_info& operator=(const any_call_info&) noexcept = default;
    constexpr any_call_info& operator=(any_call_info&&) noexcept      = default;
    constexpr ~any_call_info() noexcept                               = default;

    [[nodiscard]] constexpr operator bool() const noexcept
    {
        return std::visit([](const auto& v) noexcept -> bool { return v.operator bool(); }, value);
    }

    [[nodiscard]] const auto& call_literal() const noexcept
    {
        return std::visit([](const auto& variant) noexcept -> const auto& { return variant.call_literal; }, value);
    }

    [[nodiscard]] const auto& location() const noexcept
    {
        return std::visit([](const auto& variant) noexcept -> const auto& { return variant.location; }, value);
    }

    [[nodiscard]] friend constexpr bool operator==(const any_call_info& a, const any_call_info& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const any_call_info& a, const any_call_info& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const any_call_info& c)
    {
        return std::visit([&out](const auto& v) -> std::basic_ostream<char_type, traits>& { return out << v; }, c.value);
    }

    value_type value = {};
};

/// An exception thrown when a platform-specific call failed throwing overloads of functions or constructors in fubuki::io::platform.
struct call_exception : std::runtime_error
{
    call_exception(any_call_info c) : std::runtime_error{(std::ostringstream{} << c).str()}, call{c} {}

    any_call_info call = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const call_exception& c)
    {
        return out << "call_exception{" << c.call << "}";
    }
};

namespace error
{

/// An unknown error occurred.
struct unknown
{
    [[nodiscard]] friend constexpr bool operator==(const unknown& a, const unknown& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const unknown& a, const unknown& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const unknown& a, const unknown& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const unknown&)
    {
        return out << "io::platform::error::unknown{}";
    }
};

/// Indicates a platform API call failed.
struct api_call
{
    constexpr api_call(any_call_info t) noexcept : value{t} {}

    template<configuration::window_system w>
    constexpr api_call(call_info<w> t) noexcept : value{t}
    {
    }

    constexpr api_call(linux_call_info t) noexcept : value{t} {}
    constexpr api_call(any_call_info::value_type v) noexcept : value{v} {}

    constexpr api_call() noexcept                           = default;
    constexpr api_call(const api_call&) noexcept            = default;
    constexpr api_call(api_call&&) noexcept                 = default;
    constexpr api_call& operator=(const api_call&) noexcept = default;
    constexpr api_call& operator=(api_call&&) noexcept      = default;
    constexpr ~api_call() noexcept                          = default;

    any_call_info value = {};

    [[nodiscard]] const auto& call_literal() const noexcept { return value.call_literal(); }
    [[nodiscard]] const auto& location() const noexcept { return value.location(); }

    [[nodiscard]] friend constexpr bool operator==(const api_call& a, const api_call& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const api_call& a, const api_call& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const api_call& a, const api_call& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const api_call& r)
    {
        return out << "io::platform::error::api_call{" << r.value << "};";
    }
};

/// Indicates an operation is not supported on a given platform.
/// For example, it is not possible to move windows on Wayland.
struct operation_not_supported
{
    configuration::window_system platform = configuration::window_system::unknown;

    [[nodiscard]] friend constexpr bool operator==(const operation_not_supported& a, const operation_not_supported& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const operation_not_supported& a, const operation_not_supported& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const operation_not_supported& a, const operation_not_supported& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const operation_not_supported& r)
    {
        return out << "io::platform::error::operation_not_supported{" << r.platform << "};";
    }
};

/// Any error that may have been triggered.
struct any
{
    using value_type = std::variant<unknown, api_call, operation_not_supported>;

    any(unknown e) noexcept : value{e} {}
    any(api_call e) noexcept : value{e} {}
    any(operation_not_supported e) noexcept : value{e} {}

    [[nodiscard]] friend constexpr bool operator==(const any& a, const any& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const any& a, const any& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const any& a, const any& b) noexcept = default;

    value_type value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const any& c)
    {
        return std::visit([&out](const auto& v) -> std::basic_ostream<char_type, traits>& { return out << v; }, c.value);
    }
};

} // namespace error

} // namespace fubuki::io::platform

#endif // FUBUKI_IO_PLATFORM_ERROR_HPP
