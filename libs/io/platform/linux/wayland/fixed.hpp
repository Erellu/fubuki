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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_FIXED_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_FIXED_HPP

#include <bit>
#include <concepts>
#include <cstdint>

extern "C"
{
using wl_fixed_t = ::int32_t;
} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland::fixed
{

using type = wl_fixed_t;

/**
 * Transforms a `wl_fixed_t` into an `int` or a `double`.
 * Equivalent of `wl_fixed_to_double` or `wl_fixed_to_int`.
 * @note Re-implemented to avoid UB as per the C++ Standard.
 */
template<typename T>
requires(std::same_as<T, double> or std::same_as<T, int>)
[[nodiscard]] inline constexpr T to(type f) noexcept
{
    if constexpr(std::same_as<T, int>)
    {
        constexpr auto magic = 256;
        return f / magic;
    }
    else if constexpr(std::same_as<T, double>)
    {
        constexpr auto     magic = ((1023LL + 44LL) << 52) + (1LL << 51); // @see wayland-utils.h
        const std::int64_t bits  = magic + f;

        auto           d          = std::bit_cast<double>(bits);
        constexpr auto more_magic = (3LL << 43); // @see wayland-utils.h

        return d - more_magic;
    }

    return {};
}

/**
 * Transforms  an `int` or a `double` into a `wl_fixed_t`.
 * Equivalent of `wl_fixed_from_double` or `wl_fixed_from_int`.
 * @note Re-implemented to avoid UB as per the C++ Standard.
 */
template<typename T>
requires(std::same_as<T, double> or std::same_as<T, int>)
[[nodiscard]] inline constexpr type from(T f) noexcept
{
    if constexpr(std::same_as<T, int>)
    {
        constexpr auto magic = 256;
        return f * magic;
    }
    else if constexpr(std::same_as<T, double>)
    {
        constexpr auto magic = (3LL << (51 - 8)); // @see wayland-utils.h
        const auto     bits  = f + magic;

        return static_cast<type>(std::bit_cast<std::int64_t>(bits));
    }

    return {};
}

} // namespace fubuki::io::platform::linux_bsd::wayland::fixed

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_FIXED_HPP
