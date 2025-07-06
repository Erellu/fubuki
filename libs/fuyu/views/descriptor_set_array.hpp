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

#ifndef FUBUKI_FUYU_VIEWS_DESCRIPTOR_SET_ARRAY_HPP
#define FUBUKI_FUYU_VIEWS_DESCRIPTOR_SET_ARRAY_HPP

#include <functional>
#include <span>

#include <core/handle.hpp>
#include <core/hash.hpp>
#include <core/small_vector.hpp>

#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

namespace views
{

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
/// A view of a descriptor set.
struct descriptor_set
{
    descriptor_set_handle   handle = {};
    device_cref             device;
    descriptor_pool_handle  parent = null_handle;
    [[nodiscard]] constexpr operator descriptor_set_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const descriptor_set& a, const descriptor_set& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const descriptor_set& a, const descriptor_set& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const descriptor_set& a, const descriptor_set& b) noexcept { return a.handle <=> b.handle; }
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

namespace detail::descriptor_set_array
{

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
struct owning
{
    small_vector<descriptor_set_handle> handles = {};
    device_cref                         device;
    descriptor_pool_handle              parent = null_handle;

    /// Returns the size of this array.
    [[nodiscard]] constexpr std::size_t size() const noexcept { return handles.size(); }

    /// Returns a view of the command buffer at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] constexpr descriptor_set operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out of range.");
        return {handles[idx], device, parent};
    }

    /// Returns a view of the descriptor set at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] descriptor_set at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }

        return {handles[idx], device, parent};
    }

    [[nodiscard]] constexpr operator std::span<const descriptor_set_handle>() const noexcept { return handles; }

    [[nodiscard]] friend constexpr bool operator==(const owning& a, const owning& b) noexcept { return std::ranges::equal(a.handles, b.handles); }
    [[nodiscard]] friend constexpr bool operator!=(const owning& a, const owning& b) noexcept { return not(a == b); }
    [[nodiscard]] friend constexpr auto operator<=>(const owning& a, const owning& b) noexcept
    {
        return std::lexicographical_compare_three_way(a.handles.begin(), a.handles.end(), b.handles.begin(), b.handles.end());
    }
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

} // namespace detail::descriptor_set_array

/// A view of an array of descriptor sets allocated from a common pool.
// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
struct descriptor_set_array
{
    std::span<const descriptor_set_handle> handles = {};
    device_cref                            device;
    descriptor_pool_handle                 parent = null_handle;

    /// Returns the size of this array.
    [[nodiscard]] constexpr std::size_t size() const noexcept { return handles.size(); }

    /// Returns a view of the command buffer at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] constexpr descriptor_set operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out of range.");
        return {handles[idx], device, parent};
    }

    /// Returns a view of the descriptor set at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] descriptor_set at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }

        return {handles[idx], device, parent};
    }

    [[nodiscard]] constexpr operator std::span<const descriptor_set_handle>() const noexcept { return handles; }

    [[nodiscard]] friend constexpr bool operator==(const descriptor_set_array& a, const descriptor_set_array& b) noexcept
    {
        return std::ranges::equal(a.handles, b.handles);
    }
    [[nodiscard]] friend constexpr bool operator!=(const descriptor_set_array& a, const descriptor_set_array& b) noexcept { return not(a == b); }
    [[nodiscard]] friend constexpr auto operator<=>(const descriptor_set_array& a, const descriptor_set_array& b) noexcept
    {
        return std::lexicographical_compare_three_way(a.handles.begin(), a.handles.end(), b.handles.begin(), b.handles.end());
    }
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

template<>
struct owning<descriptor_set_array>
{
    std::optional<detail::descriptor_set_array::owning> value = {};
};

} // namespace views

using descriptor_set_view       = views::descriptor_set;
using descriptor_set_array_view = views::descriptor_set_array;

} // namespace fubuki::fuyu

namespace std
{
template<>
struct hash<fubuki::fuyu::descriptor_set_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::descriptor_set_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

template<>
struct hash<fubuki::fuyu::descriptor_set_array_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::descriptor_set_array_view& v) const noexcept { return fubuki::hash_range(v.handles); }
};

} // namespace std

#endif // FUBUKI_FUYU_VIEWS_DESCRIPTOR_SET_ARRAY_HPP
