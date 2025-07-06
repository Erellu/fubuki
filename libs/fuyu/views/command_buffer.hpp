/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2022-2023, Erwan DUHAMEL
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

#ifndef FUBUKI_FUYU_VIEWS_COMMAND_BUFFER_HPP
#define FUBUKI_FUYU_VIEWS_COMMAND_BUFFER_HPP

#include <span>

#include <vulkan/vulkan_core.h>

#include <core/handle.hpp>
#include <core/hash.hpp>
#include <core/small_vector.hpp>

#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/owning.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/// Command buffer view.
struct command_buffer
{
    command_buffer_handle handle = {};                               ///< Vulkan handle.
    device_cref           device;                                    ///< Device on which the command buffer is allocated.
    command_pool_handle   parent = null_handle;                      ///< The pool the command buffer comes from.
    VkCommandBufferLevel  level  = VK_COMMAND_BUFFER_LEVEL_MAX_ENUM; ///< Command buffer level.

    [[nodiscard]] constexpr operator command_buffer_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const command_buffer& a, const command_buffer& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const command_buffer& a, const command_buffer& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const command_buffer& a, const command_buffer& b) noexcept { return a.handle <=> b.handle; }
};

namespace detail::command_buffer_array
{

struct owning
{
    small_vector<command_buffer_handle> handles = {};                              ///< Vulkan handles.
    device_cref                         device;                                    ///< Device on which the command buffer is allocated.
    command_pool_handle                 parent = null_handle;                      ///< The pool the command buffers come from.
    VkCommandBufferLevel                level  = VK_COMMAND_BUFFER_LEVEL_MAX_ENUM; ///< Command buffer level.

    /// Returns the size of this array.
    [[nodiscard]] constexpr std::size_t size() const noexcept { return handles.size(); }

    /// Returns a view of the command buffer at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] constexpr command_buffer operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out of range.");
        return {handles[idx], device, parent, level};
    }

    /// Returns a view of the descriptor set at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] command_buffer at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }

        return {handles[idx], device, parent};
    }

    [[nodiscard]] constexpr operator std::span<const command_buffer_handle>() const noexcept { return handles; }

    [[nodiscard]] friend constexpr bool operator==(const owning& a, const owning& b) noexcept { return std::ranges::equal(a.handles, b.handles); }
    [[nodiscard]] friend constexpr bool operator!=(const owning& a, const owning& b) noexcept { return not(a == b); }
    [[nodiscard]] friend constexpr auto operator<=>(const owning& a, const owning& b) noexcept
    {
        return std::lexicographical_compare_three_way(a.handles.begin(), a.handles.end(), b.handles.begin(), b.handles.end());
    }
};

} // namespace detail::command_buffer_array

/// A view of an array of command buffers allocated from a common pool.

struct command_buffer_array
{
    std::span<const command_buffer_handle> handles = {};                              ///< Vulkan handles.
    device_cref                            device;                                    ///< Device on which the command buffer is allocated.
    command_pool_handle                    parent = null_handle;                      ///< The pool the command buffers come from.
    VkCommandBufferLevel                   level  = VK_COMMAND_BUFFER_LEVEL_MAX_ENUM; ///< Command buffer level.

    /// Returns the size of this array.
    [[nodiscard]] constexpr std::size_t size() const noexcept { return handles.size(); }

    /// Returns a view of the command buffer at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] constexpr command_buffer operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out of range.");
        return {handles[idx], device, parent, level};
    }

    /// Returns a view of the command buffer at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] command_buffer at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }

        return {handles[idx], device, parent};
    }

    [[nodiscard]] constexpr operator std::span<const command_buffer_handle>() const noexcept { return handles; }

    [[nodiscard]] friend constexpr bool operator==(const command_buffer_array& a, const command_buffer_array& b) noexcept
    {
        return std::ranges::equal(a.handles, b.handles);
    }
    [[nodiscard]] friend constexpr bool operator!=(const command_buffer_array& a, const command_buffer_array& b) noexcept { return not(a == b); }
    [[nodiscard]] friend constexpr auto operator<=>(const command_buffer_array& a, const command_buffer_array& b) noexcept
    {
        return std::lexicographical_compare_three_way(a.handles.begin(), a.handles.end(), b.handles.begin(), b.handles.end());
    }
};

template<>
struct owning<command_buffer_array>
{
    std::optional<detail::command_buffer_array::owning> value = {};
};

} // namespace views

using command_buffer_view       = views::command_buffer;
using command_buffer_array_view = views::command_buffer_array;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::command_buffer_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::command_buffer_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

template<>
struct hash<fubuki::fuyu::command_buffer_array_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::command_buffer_array_view& v) const noexcept { return fubuki::hash_range(v.handles); }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_COMMAND_BUFFER_HPP
