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

#ifndef FUBUKI_FUYU_VIEWS_BUFFER_RESOURCE_HPP
#define FUBUKI_FUYU_VIEWS_BUFFER_RESOURCE_HPP

#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/sharing_mode.hpp"
#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/memory.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/// A view of a buffer resource.
struct buffer_resource
{
    buffer_handle           handle = {};       ///< Buffer handle.
    device_cref             device;            ///< Device on which the buffer is allocated.
    VkBufferCreateFlags     flags        = {}; ///< Buffer flags.
    VkDeviceSize            size         = 0;  ///< Buffer size in bytes.
    VkBufferUsageFlags      usage        = {}; ///< Buffer usage flags.
    sharing_mode::any::view sharing_mode = {}; ///< Sharing mode of the buffer when accessed by more than one queue family.

    [[nodiscard]] constexpr operator buffer_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const buffer_resource& a, const buffer_resource& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const buffer_resource& a, const buffer_resource& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const buffer_resource& a, const buffer_resource& b) noexcept { return a.handle <=> b.handle; }
};

/// View of a buffer bound to a memory region.
struct bound_buffer
{
    buffer_resource buffer;        ///< Buffer.
    memory          device_memory; ///< Memory the buffer is bound to.
    VkDeviceSize    offset = 0u;   ///< Offset in bytes in the memory region.

    [[nodiscard]] constexpr operator const buffer_resource&() const noexcept { return buffer; }
    [[nodiscard]] constexpr operator buffer_handle() const noexcept { return buffer.handle; }

    [[nodiscard]] constexpr operator const memory&() const noexcept { return device_memory; }
    [[nodiscard]] constexpr operator device_memory_handle() const noexcept { return device_memory.handle; }

    [[nodiscard]] friend constexpr bool operator==(const bound_buffer& a, const bound_buffer& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const bound_buffer& a, const bound_buffer& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const bound_buffer& a, const bound_buffer& b) noexcept = default;
};

} // namespace views

/// Alias for fubuki::fuyu::views::buffer_resource.
using buffer_resource_view = views::buffer_resource;

/// Alias for fubuki::fuyu::views::bound_buffer.
using bound_buffer_view = views::bound_buffer;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::buffer_resource_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::buffer_resource_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_BUFFER_RESOURCE_HPP
