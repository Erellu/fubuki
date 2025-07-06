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

#ifndef FUBUKI_CORE_COLLECT_HPP
#define FUBUKI_CORE_COLLECT_HPP

#include <cstdint>
#include <span>

#include "core/small_vector.hpp"

namespace fubuki
{

namespace detail::collect
{

template<std::ranges::contiguous_range result_type, typename to, typename from, std::ranges::contiguous_range input_type>
inline constexpr result_type perform(input_type input)
requires std::convertible_to<from, to> // Everything convertible through static_cast (int, float...)
{
    result_type result = {};
    result.reserve(std::ranges::size(input));

    for(const auto& object : input)
    {
        result.emplace_back(static_cast<to>(object));
    }

    return result;
}

template<std::ranges::contiguous_range result_type, typename to, typename from, std::ranges::contiguous_range input_type>
inline constexpr result_type perform(input_type input)
requires requires(from o) {
    o.handle();
    { o.handle().vk } -> std::convertible_to<to>;
} // Typically: objects in fuyu (fuyu::device, fuyu::buffer...)
{
    result_type result = {};
    result.reserve(std::ranges::size(input));

    for(const auto& object : input)
    {
        result.emplace_back(object.handle().vk);
    }

    return result;
}

template<std::ranges::contiguous_range result_type, typename to, typename from, std::ranges::contiguous_range input_type>
inline constexpr result_type perform(input_type input)
requires requires(from o) {
    o.handle;
    { o.handle.vk } -> std::convertible_to<to>; // Typically: fuyu::views
}
{
    result_type result = {};
    result.reserve(std::ranges::size(input));

    for(const auto& object : input)
    {
        result.emplace_back(object.handle.vk);
    }

    return result;
}

template<std::ranges::contiguous_range result_type, typename to, typename from, std::ranges::contiguous_range input_type>
inline constexpr result_type perform(input_type input)
requires requires(from o) {
    { o.vk } -> std::convertible_to<to>; // Typically: fubuki::handle
}
{
    result_type result = {};
    result.reserve(std::ranges::size(input));

    for(const auto& object : input)
    {
        result.emplace_back(object.vk);
    }

    return result;
}

template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto perform(const std::span<from, extent> range)
{
    constexpr std::size_t byte_size_limit = 64;

    // HACK: avoid instantiations with std::dynamic_extent (hence the duplicated branch)
    // This triggers an assert in clang because there is a static_assert for the size of the underlying std::array limiting its size
    if constexpr(extent == std::dynamic_extent)
    {
        return perform<fubuki::small_vector<to, detail::small_vector::automatic_sbo_size, allocator>, to, from>(range);
    }
    else if constexpr(sizeof(fubuki::small_vector<to, extent, allocator>) < byte_size_limit)
    {
        return perform<fubuki::small_vector<to, extent, allocator>, to, from>(range);
    }
    else
    {
        return perform<fubuki::small_vector<to, detail::small_vector::automatic_sbo_size, allocator>, to, from>(range);
    }
}

} // namespace detail::collect

/// Converts a type to the type Vulkan uses as a size type, aka std::uint32_t.
template<std::convertible_to<std::uint32_t> T>
[[nodiscard]]
inline constexpr auto vk_size(T x)
{
    return static_cast<std::uint32_t>(x);
}

/// Returns the size of a container, or any class exposing a size() function in the type Vulkan uses as a size type, aka std::uint32_t.
template<typename T>
[[nodiscard]]
inline constexpr auto vk_size(const T& v)
requires requires(const T& t) { t.size(); }
{
    return vk_size(v.size());
}

//------------------------------------------------------------------------------

/// Converts a type to the type the host (CPU) uses for size type, aka std::size_t.
template<std::convertible_to<std::size_t> T>
[[nodiscard]]
inline constexpr auto host_size(const T x)
{
    return static_cast<std::size_t>(x);
}

/// Returns the size of a container, or any class exposing a size() function in the type the host (CPU) uses as a size type, aka std::size_t.
template<typename T>
[[nodiscard]]
inline constexpr auto host_size(const T& v)
requires requires(const T& t) { t.size(); }
{
    return host_size(v.size());
}

//------------------------------------------------------------------------------

/// Converts a type to the type the device (GPU) uses for size type, aka std::uint64_t.
template<std::convertible_to<std::uint64_t> T>
[[nodiscard]]
inline constexpr auto device_size(const T x)
{
    return static_cast<std::uint64_t>(x);
}

/// Returns the size of a container, or any class exposing a size() function in the type the device (GPU) uses as a size type, aka std::uint64_t.
template<typename T>
[[nodiscard]]
inline constexpr auto device_size(const T& v)
requires requires(const T& t) { t.size(); }
{
    return device_size(v.size());
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<from, extent> range)
requires std::convertible_to<from, to>
{
    return detail::collect::perform<to, from, extent, allocator>(range);
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<const from, extent> range)
requires std::convertible_to<const from, to>
{
    return detail::collect::perform<to, const from, extent, allocator>(range);
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
/// This overload is aimed to be used for constructs similar to those found in fuyu::views.
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<from, extent> range)
requires requires(from v) {
    { v.vk } -> std::convertible_to<to>;
}
{
    return detail::collect::perform<to, from, extent, allocator>(range);
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
/// This overload is aimed to be used for constructs similar to those found in fuyu::views.
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<const from, extent> range)
requires requires(const from v) {
    { v.vk } -> std::convertible_to<to>;
}
{
    return detail::collect::perform<to, const from, extent, allocator>(range);
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
/// This overload is aimed to be used for constructs similar to those found in fuyu::views.
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<from, extent> range)
requires requires(from v) {
    { v.handle.vk } -> std::convertible_to<to>;
}
{
    return detail::collect::perform<to, from, extent, allocator>(range);
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
/// This overload is aimed to be used for constructs similar to those found in fuyu::views.
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<const from, extent> range)
requires requires(const from v) {
    { v.handle.vk } -> std::convertible_to<to>;
}
{
    return detail::collect::perform<to, const from, extent, allocator>(range);
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
/// This overload is aimed to be used for constructs similar to objects used in fuyu (fuyu::device, fuyu::buffer...).
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<from, extent> range)
requires requires(from v) {
    { v.handle().vk } -> std::convertible_to<to>;
}
{
    return detail::collect::perform<to, from, extent, allocator>(range);
}

//------------------------------------------------------------------------------

/// Converts a span of a type to a vector of another type.
/// This overload is aimed to be used for constructs similar to objects used in fuyu (fuyu::device, fuyu::buffer...).
template<typename to, typename from, std::size_t extent, typename allocator = std::allocator<to>>
[[nodiscard]]
inline constexpr auto collect(const std::span<const from, extent> range)
requires requires(const from v) {
    { v.handle().vk } -> std::convertible_to<to>;
}
{
    return detail::collect::perform<to, const from, extent, allocator>(range);
}

} // namespace fubuki

#endif // FUBUKI_CORE_COLLECT_HPP
