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

#ifndef FUBUKI_CORE_RECTANGLE_HPP
#define FUBUKI_CORE_RECTANGLE_HPP

#include "core/dim.hpp"
#include "core/pos.hpp"

namespace fubuki
{

/// @brief 2D rectangle.
template<typename pos_type, typename dim_type = pos_type>
requires(std::is_default_constructible_v<pos_type> and std::is_default_constructible_v<dim_type>)
struct rec2d
{
    pos2d<pos_type> offset = {};
    dim2d<dim_type> extent = {};

    [[nodiscard]] friend constexpr auto operator<=>(const rec2d&, const rec2d&) = default;
    [[nodiscard]] friend constexpr bool operator==(const rec2d&, const rec2d&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const rec2d&, const rec2d&)  = default;

    constexpr void swap(rec2d& other) noexcept
    {
        offset.swap(other.offset);
        extent.swap(other.extent);
    }

    constexpr friend void swap(rec2d& a, rec2d& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const rec2d& s)
    {
        return out << "offset: " << s.offset << " extent: " << s.extent;
    }
};

/**
 * @brief 3D rectangle.
 * @tparam pos_type Type type for the rectangle position.
 * @tparam dim_type (optional) The type for the rectangle dimension. Unless specified, defaults to `pos_type`.
 * @pre Both `pos_type` and `dim_type` must be default-constructible.
 */
template<typename pos_type, typename dim_type = pos_type>
requires(std::is_default_constructible_v<pos_type> and std::is_default_constructible_v<dim_type>)
struct rec3d
{
    pos3d<pos_type> offset = {};
    dim3d<dim_type> extent = {};

    constexpr operator rec2d<pos_type, dim_type>() const { return {offset, extent}; }

    [[nodiscard]] friend constexpr auto operator<=>(const rec3d&, const rec3d&) = default;
    [[nodiscard]] friend constexpr bool operator==(const rec3d&, const rec3d&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const rec3d&, const rec3d&)  = default;

    constexpr void swap(rec3d& other) noexcept
    {
        offset.swap(other.offset);
        extent.swap(other.extent);
    }

    constexpr friend void swap(rec3d& a, rec3d& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const rec3d& s)
    {
        return out << "offset: " << s.offset << " extent: " << s.extent;
    }
};

using rectangle2d = rec2d<std::int32_t>;
using rectangle3d = rec3d<std::int32_t>;

using u_rectangle2d = rec2d<std::uint32_t>;
using u_rectangle3d = rec3d<std::uint32_t>;

} // namespace fubuki

#endif // FUBUKI_CORE_RECTANGLE_HPP
