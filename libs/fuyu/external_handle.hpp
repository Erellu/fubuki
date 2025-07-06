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

#ifndef FUBUKI_FUYU_EXTERNAL_HANDLE_HPP
#define FUBUKI_FUYU_EXTERNAL_HANDLE_HPP

#include <variant>

#include <core/detail/handle_traits.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>

namespace fubuki::fuyu
{

/// Indicates the fuyu object (fuyu::device, fuyu::buffer...) must take the ownership over this handle, that is, destroy it when its lifetime ends.
template<typename handle_type>
requires(fubuki::detail::is_handle_v<handle_type>
         or (std::ranges::range<handle_type> and fubuki::detail::is_handle_v<std::ranges::range_value_t<handle_type>>))
struct take_ownership
{
    static constexpr bool owner = true;

    handle_type handle = {};
};

/// Indicates the fuyu object (fuyu::device, fuyu::buffer...) only borrows the object for its lifetime, and won't destroy it.
template<typename handle_type>
requires(fubuki::detail::is_handle_v<handle_type>
         or (std::ranges::range<handle_type> and fubuki::detail::is_handle_v<std::ranges::range_value_t<handle_type>>))
struct borrow
{
    static constexpr bool owner = false;

    handle_type handle = {};
};

/// A tag-like struct that can be passed to the constructor of fuyu objects (fuyu::device, fuyu::buffer...) to use Vulkan handles allocated from
/// another API.
template<typename handle_type>
struct external_handle
{
    std::variant<take_ownership<handle_type>, borrow<handle_type>> ownership;
};

//------------------------------------------------------------------------------
// Deduction guides

template<typename T>
requires(fubuki::detail::is_handle_v<T>)
take_ownership(T) -> take_ownership<T>;

template<typename T, std::size_t small_buffer_size, typename allocator>
requires(fubuki::detail::is_handle_v<T>)
take_ownership(small_vector<T, small_buffer_size, allocator>) -> take_ownership<small_vector<T, small_buffer_size, allocator>>;

template<typename T>
requires(fubuki::detail::is_handle_v<T>)
borrow(T) -> borrow<T>;

template<typename T, std::size_t small_buffer_size, typename allocator>
requires(fubuki::detail::is_handle_v<T>)
borrow(small_vector<T, small_buffer_size, allocator>) -> borrow<small_vector<T, small_buffer_size, allocator>>;

template<typename T>
external_handle(take_ownership<T>) -> external_handle<T>;

template<typename T>
external_handle(borrow<T>) -> external_handle<T>;

template<typename T>
external_handle(std::variant<take_ownership<T>, borrow<T>>) -> external_handle<T>;

//------------------------------------------------------------------------------
// Inline functions

/// Returns the underlying handle an external_handle carries.
template<typename T>
[[nodiscard]]
inline constexpr T handle_of(external_handle<T> handle) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    return std::visit([](auto variant) constexpr noexcept -> T { return std::move(variant.handle); }, std::move(handle.ownership));
}

template<typename T>
[[nodiscard]] inline constexpr bool indicates_ownership(const external_handle<T>& handle) noexcept
{
    return std::visit([]<typename U>(const U&) constexpr noexcept -> bool { return U::owner; }, handle.ownership);
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_EXTERNAL_HANDLE_HPP
