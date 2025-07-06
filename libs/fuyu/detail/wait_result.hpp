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

#ifndef FUBUKI_FUYU_DETAIL_WAIT_RESULT_HPP
#define FUBUKI_FUYU_DETAIL_WAIT_RESULT_HPP

#include <expected>
#include <ostream>
#include <type_traits>

#include <core/result.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu
{

namespace detail::wait
{

/// Indicates a wait operation executed successfully.
struct success
{
    enum class code : std::underlying_type_t<VkResult>
    {
        normal  = VK_SUCCESS, ///< The operation was successful and executed on time.
        timeout = VK_TIMEOUT, ///< The operation was successful but timed out.
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const success& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

/// Indicates an error occurred during a wait operation.
struct error
{
    enum class code : std::underlying_type_t<VkResult>
    {
        out_of_host_memory   = VK_ERROR_OUT_OF_HOST_MEMORY,
        out_of_device_memory = VK_ERROR_OUT_OF_DEVICE_MEMORY,
        device_lost          = VK_ERROR_DEVICE_LOST,
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const error& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

using result = std::expected<success, error>;

/// Indicates if a wait operation timed out.
[[nodiscard]] inline constexpr bool timed_out(const success& c) noexcept { return c.value == success::code::timeout; }

/// Indicates if a wait operation timed out.
[[nodiscard]] inline constexpr bool timed_out(const result& c) noexcept { return c.has_value() and timed_out(*c); }

} // namespace detail::wait

using wait_success = detail::wait::success;
using wait_error   = detail::wait::error;
using wait_result  = detail::wait::result;
using detail::wait::timed_out;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_DETAIL_WAIT_RESULT_HPP
