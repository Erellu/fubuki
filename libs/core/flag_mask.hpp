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

#ifndef FUBUKI_CORE_FLAG_MASK_HPP
#define FUBUKI_CORE_FLAG_MASK_HPP

#include <type_traits>
#include <utility>

namespace fubuki
{

/**
 * A mask of `enum` values.
 * @tparam T The `enum` type.
 * @pre The `enum` type must be a bitmask.
 */
template<typename T>
requires(std::is_enum_v<T>)
class flag_mask
{
    struct token
    {
    };

public:

    using bit        = T;
    using value_type = std::underlying_type_t<bit>;

    constexpr flag_mask() noexcept                            = default;
    constexpr flag_mask(const flag_mask&) noexcept            = default;
    constexpr flag_mask(flag_mask&&) noexcept                 = default;
    constexpr flag_mask& operator=(flag_mask&&) noexcept      = default;
    constexpr flag_mask& operator=(const flag_mask&) noexcept = default;
    constexpr ~flag_mask() noexcept                           = default;

    constexpr flag_mask(bit b) noexcept : m_value{std::to_underlying(b)} {}

    /// Returns the underlying value.
    [[nodiscard]] constexpr auto value() const noexcept { return m_value; }

    /// Returns a flag_mask corresponding to the overlap of the two arguments.
    [[nodiscard]] friend constexpr flag_mask operator&(flag_mask a, flag_mask b) noexcept
    {
        return flag_mask{token{}, static_cast<value_type>(a.m_value & b.m_value)};
    }

    /// Returns a `flag_mask` corresponding to the conjunction of the two arguments.
    [[nodiscard]] friend constexpr flag_mask operator|(flag_mask a, flag_mask b) noexcept
    {
        return flag_mask{token{}, static_cast<value_type>(a.m_value | b.m_value)};
    }

    /// Checks if a mask contains an element of the `enum`.
    [[nodiscard]] friend constexpr bool operator&(flag_mask m, bit b) noexcept { return static_cast<bool>(std::to_underlying(b) & m.m_value); }

    /// Returns a `flag_mask` corresponding to the conjunction of the two arguments.
    [[nodiscard]] friend constexpr flag_mask operator|(flag_mask m, bit b) noexcept
    {
        return flag_mask{token{}, static_cast<value_type>(m.m_value | std::to_underlying(b))};
    }

    /// Sets the underlying value to a value of the target `enum`.
    constexpr flag_mask& operator&=(bit b) noexcept
    {
        m_value &= std::to_underlying(b);
        return *this;
    }

    /// Sets the underlying value to its overlap with the argument value.
    constexpr flag_mask& operator&=(flag_mask m) noexcept
    {
        m_value &= m;
        return *this;
    }

    /// Adds an element to this mask.
    constexpr flag_mask& operator|=(bit b) noexcept
    {
        m_value |= std::to_underlying(b);
        return *this;
    }

    /// Adds the contents of another `flag_mask` to this mask.
    constexpr flag_mask& operator|=(flag_mask m) noexcept
    {
        m_value |= m;
        return *this;
    }

    /// Swaps two objects.
    constexpr void swap(flag_mask& other) noexcept { std::swap(m_value, other.m_value); }

    /// Swaps two objects.
    friend constexpr void swap(flag_mask& a, flag_mask& b) noexcept { a.swap(b); }

    [[nodiscard]] friend constexpr auto operator<=>(const flag_mask&, const flag_mask&) noexcept = default;
    [[nodiscard]] friend constexpr bool operator==(const flag_mask&, const flag_mask&) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const flag_mask&, const flag_mask&) noexcept  = default;

    [[nodiscard]] friend constexpr bool operator==(const flag_mask& a, const bit& b) noexcept { return a.m_value == std::to_underlying(b); }
    [[nodiscard]] friend constexpr bool operator!=(const flag_mask& a, const bit& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr bool operator==(const bit& a, const flag_mask& b) noexcept { return std::to_underlying(a) == b.m_value; }
    [[nodiscard]] friend constexpr bool operator!=(const bit& a, const flag_mask& b) noexcept { return not(a == b); }

private:

    constexpr flag_mask(token, std::underlying_type_t<T> v) noexcept : m_value{v} {}

    value_type m_value = {};
};

} // namespace fubuki

#endif // FUBUKI_CORE_FLAG_MASK_HPP
