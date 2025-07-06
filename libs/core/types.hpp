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

#ifndef FUBUKI_CORE_TYPES_HPP
#define FUBUKI_CORE_TYPES_HPP

#include <cstdint>
#include <ostream>
#include <type_traits>

namespace fubuki
{

/// 1D dimension.
template<typename T>
requires(std::is_default_constructible_v<T>)
struct dim1d
{
    T width = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const dim1d& s)
    {
        return out << "{w: " << s.width << "}";
    }

    [[nodiscard]] constexpr operator const T&() const { return width; }

    [[nodiscard]] friend constexpr auto operator<=>(const dim1d<T>&, const dim1d<T>&) = default;
    [[nodiscard]] friend constexpr bool operator==(const dim1d<T>&, const dim1d<T>&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const dim1d<T>&, const dim1d<T>&)  = default;

    [[nodiscard]] friend constexpr bool operator==(const dim1d<T>& d, const T& t)
    requires requires {
        { d.width == t };
    }
    {
        return (d.width == t);
    }

    [[nodiscard]] inline friend constexpr bool operator==(const dim1d<T>& d, const T& t)
    requires requires {
        { d.width != t };
    }
    {
        return (d.width != t);
    }

    [[nodiscard]] inline friend constexpr auto operator<=>(const dim1d<T>& d, const T& t)
    requires requires {
        { d.width <=> t };
    }
    {
        return (d.width <=> t);
    }

    constexpr void        swap(dim1d& other) noexcept { std::swap(width, other.width); }
    constexpr friend void swap(dim1d& a, dim1d& b) noexcept { a.swap(b); }
};

/// 2D dimension.
template<typename T>
requires(std::is_default_constructible_v<T>)
struct dim2d
{
    T width  = {};
    T height = {};

    constexpr operator dim1d<T>() const { return {width}; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const dim2d& s)
    {
        return out << "{w: " << s.width << ", h: " << s.height << "}";
    }

    [[nodiscard]] friend constexpr auto operator<=>(const dim2d<T>&, const dim2d<T>&) = default;
    [[nodiscard]] friend constexpr bool operator==(const dim2d<T>&, const dim2d<T>&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const dim2d<T>&, const dim2d<T>&)  = default;

    constexpr void swap(dim2d& other) noexcept
    {
        std::swap(width, other.width);
        std::swap(height, other.height);
    }

    constexpr friend void swap(dim2d& a, dim2d& b) noexcept { a.swap(b); }
};

/// 3D dimension.
template<typename T>
requires(std::is_default_constructible_v<T>)
struct dim3d
{
    T width  = {};
    T height = {};
    T depth  = {};

    constexpr operator dim1d<T>() const { return {width}; }

    constexpr operator dim2d<T>() const { return {width, height}; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const dim3d& s)
    {
        return out << "{w: " << s.width << ", h: " << s.height << ", d: " << s.depth << "}";
    }

    [[nodiscard]] friend constexpr auto operator<=>(const dim3d<T>&, const dim3d<T>&) = default;
    [[nodiscard]] friend constexpr bool operator==(const dim3d<T>&, const dim3d<T>&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const dim3d<T>&, const dim3d<T>&)  = default;

    constexpr void swap(dim3d& other) noexcept
    {
        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(depth, other.depth);
    }

    constexpr friend void swap(dim3d& a, dim3d& b) noexcept { a.swap(b); }
};

using dimension1d = dim1d<std::int32_t>; ///< 1D signed size.
using dimension2d = dim2d<std::int32_t>; ///< 2D signed size.
using dimension3d = dim3d<std::int32_t>; ///< 3D signed size.

using u_dimension1d = dim1d<std::uint32_t>; ///< 1D unsigned size.
using u_dimension2d = dim2d<std::uint32_t>; ///< 2D unsigned size.
using u_dimension3d = dim3d<std::uint32_t>; ///< 3D unsigned size.

//------------------------------------------------------------------------------

/// 1D position.
template<typename T>
requires(std::is_default_constructible_v<T>)
struct pos1d
{
    T x = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const pos1d& s)
    {
        return out << "{x: " << s.x << "}";
    }

    [[nodiscard]] constexpr operator const T&() const { return x; }

    [[nodiscard]] friend constexpr auto operator<=>(const pos1d<T>&, const pos1d<T>&) = default;
    [[nodiscard]] friend constexpr bool operator==(const pos1d<T>&, const pos1d<T>&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const pos1d<T>&, const pos1d<T>&)  = default;

    [[nodiscard]] friend constexpr bool operator==(const pos1d<T>& p, const T& t)
    requires requires {
        { p.x == t };
    }
    {
        return (p.x == t);
    }

    [[nodiscard]] friend constexpr bool operator==(const pos1d<T>& p, const T& t)
    requires requires {
        { p.x != t };
    }
    {
        return (p.x != t);
    }

    [[nodiscard]] friend constexpr auto operator<=>(const pos1d<T>& p, const T& t)
    requires requires {
        { p.x <=> t };
    }
    {
        return (p.x <=> t);
    }

    constexpr void        swap(pos1d& other) noexcept { std::swap(x, other.x); }
    constexpr friend void swap(pos1d& a, pos1d& b) noexcept { a.swap(b); }
};

/// 2D position.
template<typename T>
requires(std::is_default_constructible_v<T>)
struct pos2d
{
    T x = {};
    T y = {};

    constexpr operator pos1d<T>() const { return {x}; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const pos2d& s)
    {
        return out << "{x: " << s.x << ", y: " << s.y << "}";
    }

    [[nodiscard]] inline friend constexpr auto operator<=>(const pos2d<T>&, const pos2d<T>&) = default;
    [[nodiscard]] inline friend constexpr bool operator==(const pos2d<T>&, const pos2d<T>&)  = default;
    [[nodiscard]] inline friend constexpr bool operator!=(const pos2d<T>&, const pos2d<T>&)  = default;

    constexpr void swap(pos2d& other) noexcept
    {
        std::swap(x, other.x);
        std::swap(y, other.y);
    }

    constexpr friend void swap(pos2d& a, pos2d& b) noexcept { a.swap(b); }
};

/// 3D position.
template<typename T>
requires(std::is_default_constructible_v<T>)
struct pos3d
{
    T x = {};
    T y = {};
    T z = {};

    constexpr operator pos1d<T>() const { return {x}; }
    constexpr operator pos2d<T>() const { return {x, y}; }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const pos3d& s)
    {
        return out << "{x: " << s.x << ", y: " << s.y << ", z: " << s.z << "}";
    }

    [[nodiscard]] friend constexpr auto operator<=>(const pos3d<T>&, const pos3d<T>&) = default;
    [[nodiscard]] friend constexpr bool operator==(const pos3d<T>&, const pos3d<T>&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const pos3d<T>&, const pos3d<T>&)  = default;

    constexpr void swap(pos3d& other) noexcept
    {
        std::swap(x, other.x);
        std::swap(y, other.y);
        std::swap(z, other.z);
    }

    constexpr friend void swap(pos3d& a, pos3d& b) noexcept { a.swap(b); }
};

using position2d = pos2d<std::int32_t>; ///< 2D signed position.
using position3d = pos2d<std::int32_t>; ///< 3D signed position.

using u_position2d = pos2d<std::int32_t>; ///< 2D unsigned position.
using u_position3d = pos2d<std::int32_t>; ///< 3D unsigned position.

//------------------------------------------------------------------------------

/// 2D rectangle.
struct rectangle2d
{
    position2d  offset = {};
    dimension2d extent = {};

    [[nodiscard]] friend constexpr auto operator<=>(const rectangle2d&, const rectangle2d&) = default;
    [[nodiscard]] friend constexpr bool operator==(const rectangle2d&, const rectangle2d&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const rectangle2d&, const rectangle2d&)  = default;

    constexpr void swap(rectangle2d& other) noexcept
    {
        offset.swap(other.offset);
        extent.swap(other.extent);
    }

    constexpr friend void swap(rectangle2d& a, rectangle2d& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const rectangle2d& s)
    {
        return out << "offset: " << s.offset << " extent: " << s.extent;
    }
};

/// 3D rectangle.
struct rectangle3d
{
    position3d  offset = {};
    dimension3d extent = {};

    constexpr operator rectangle2d() const { return {offset, extent}; }

    [[nodiscard]] friend constexpr auto operator<=>(const rectangle3d&, const rectangle3d&) = default;
    [[nodiscard]] friend constexpr bool operator==(const rectangle3d&, const rectangle3d&)  = default;
    [[nodiscard]] friend constexpr bool operator!=(const rectangle3d&, const rectangle3d&)  = default;

    constexpr void swap(rectangle3d& other) noexcept
    {
        offset.swap(other.offset);
        extent.swap(other.extent);
    }

    constexpr friend void swap(rectangle3d& a, rectangle3d& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const rectangle3d& s)
    {
        return out << "offset: " << s.offset << " extent: " << s.extent;
    }
};

} // namespace fubuki

#endif // FUBUKI_CORE_TYPES_HPP
