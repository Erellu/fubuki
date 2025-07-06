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

#ifndef FUBUKI_FUYU_VIEWS_MEMORY_HPP
#define FUBUKI_FUYU_VIEWS_MEMORY_HPP

#include <algorithm>
#include <compare>
#include <cstddef>
#include <span>

#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/device_ref.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/// View of a memory resource.
struct memory
{
    device_memory_handle handle = {};       ///< Memory handle.
    device_cref          device;            ///< Device on which memory is allocated.
    VkMemoryRequirements requirements = {}; ///< Memory requirements.

    [[nodiscard]] constexpr operator device_memory_handle() const noexcept { return handle; }

    [[nodiscard]] constexpr operator const VkMemoryRequirements&() const noexcept { return requirements; }

    [[nodiscard]] friend constexpr bool operator==(const memory& a, const memory& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const memory& a, const memory& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const memory& a, const memory& b) noexcept { return a.handle <=> b.handle; }
};

/// A memory range.
struct memory_range
{
    VkDeviceSize offset = 0; ///< Offset in bytes starting from first memory byte.
    VkDeviceSize size   = 0; ///< Size of the region in bytes.

    [[nodiscard]] friend constexpr bool operator==(const memory_range& a, const memory_range& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const memory_range& a, const memory_range& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const memory_range& a, const memory_range& b) noexcept = default;
};

/// A memory region.
struct memory_region
{
    memory       device_memory; ///< Device memory this region is from.
    memory_range location = {}; ///< Offset in bytes starting from first memory byte.

    [[nodiscard]] constexpr operator device_memory_handle() const noexcept { return device_memory; }
    [[nodiscard]] constexpr operator const memory&() const noexcept { return device_memory; }
    [[nodiscard]] constexpr operator const VkMemoryRequirements&() const noexcept { return device_memory; }

    [[nodiscard]] constexpr operator const memory_range&() const noexcept { return location; }

    [[nodiscard]] friend constexpr bool operator==(const memory_region& a, const memory_region& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const memory_region& a, const memory_region& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const memory_region& a, const memory_region& b) noexcept = default;
};

/// Mapped region of device memory, that can be used as a range like std::span<std::byte>.
struct mapped_memory
{
    using range_type       = std::span<std::byte>;
    using element_type     = typename range_type::element_type;
    using value_type       = typename range_type::value_type;
    using size_type        = typename range_type::size_type;
    using difference_type  = typename range_type::difference_type;
    using pointer          = typename range_type::pointer;
    using const_pointer    = typename range_type::const_pointer;
    using reference        = typename range_type::reference;
    using const_reference  = typename range_type::const_reference;
    using iterator         = typename range_type::iterator;
    using reverse_iterator = typename range_type::reverse_iterator;

    memory_region        region;
    std::span<std::byte> contents = {}; ///< The bytes of the memory region represented by this structure..

    [[nodiscard]] constexpr iterator         begin() const noexcept { return contents.begin(); }
    [[nodiscard]] constexpr iterator         end() const noexcept { return contents.end(); }
    [[nodiscard]] constexpr reverse_iterator rbegin() const noexcept { return contents.rbegin(); }
    [[nodiscard]] constexpr reverse_iterator rend() const noexcept { return contents.rend(); }

    [[nodiscard]] constexpr reference front() const { return contents.front(); }
    [[nodiscard]] constexpr reference back() const { return contents.back(); }
    [[nodiscard]] constexpr reference operator[](size_type idx) const { return contents[idx]; }
    [[nodiscard]] constexpr pointer   data() const noexcept { return contents.data(); }

    [[nodiscard]] constexpr size_type size() const noexcept { return contents.size(); }
    [[nodiscard]] constexpr size_type size_bytes() const noexcept { return contents.size_bytes(); }
    [[nodiscard]] constexpr bool      empty() const noexcept { return contents.empty(); }

    template<std::size_t count>
    [[nodiscard]] constexpr std::span<element_type, count> first() const noexcept
    {
        return contents.first<count>();
    }

    [[nodiscard]] constexpr std::span<element_type, std::dynamic_extent> first(size_type count) const noexcept { return contents.first(count); }
    template<std::size_t count>
    [[nodiscard]] constexpr std::span<element_type, count> last() const noexcept
    {
        return contents.last<count>();
    }

    [[nodiscard]] constexpr std::span<element_type, std::dynamic_extent> last(size_type count) const noexcept { return contents.last(count); }

    template<std::size_t offset, std::size_t count = std::dynamic_extent>
    [[nodiscard]] constexpr auto subspan() const
    {
        return contents.subspan<offset, count>();
    }
    [[nodiscard]] constexpr std::span<element_type, std::dynamic_extent> subspan(size_type offset, size_type count = std::dynamic_extent) const
    {
        return contents.subspan(offset, count);
    }

    [[nodiscard]] constexpr operator std::span<std::byte>() noexcept { return contents; }
    [[nodiscard]] constexpr operator std::span<const std::byte>() const noexcept { return {contents}; }

    [[nodiscard]] friend constexpr bool operator==(const mapped_memory& a, const mapped_memory& b) noexcept
    {
        return (a.region == b.region) and std::ranges::equal(a.contents, b.contents);
    }
    [[nodiscard]] friend constexpr bool operator!=(const mapped_memory& a, const mapped_memory& b) noexcept { return not(a == b); }
    [[nodiscard]] friend constexpr auto operator<=>(const mapped_memory& a, const mapped_memory& b) noexcept
    {
        if(const auto compare_region = a.region <=> b.region; compare_region != std::strong_ordering::equal)
        {
            return compare_region;
        }

        return std::lexicographical_compare_three_way(a.contents.begin(), a.contents.end(), b.contents.begin(), b.contents.end());
    }
};

} // namespace views

/// Alias for fubuki::fuyu::views::buffer_resource.
using memory_view = views::memory;

/// A memory range.
using memory_range = views::memory_range;

/// A view of a memory region.
using memory_region = views::memory_region;

/// A view of a mapped region of device memory.
using mapped_memory = views::mapped_memory;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::memory_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::memory_view& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_MEMORY_HPP
