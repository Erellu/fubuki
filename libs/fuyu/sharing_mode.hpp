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

#ifndef FUBUKI_FUYU_SHARING_MODE_HPP
#define FUBUKI_FUYU_SHARING_MODE_HPP

#include <memory>
#include <variant>

#include <core/collect.hpp>
#include <core/future/flat_set.hpp>
#include <core/vulkan.hpp>

/**
 * Resource (buffer and image) sharing modes.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkSharingMode.html
 */
namespace fubuki::fuyu::sharing_mode
{

/**
 * Specifies that access to any range or image subresource of the object will be exclusive to a single queue family at a time.
 * @see VkSharingMode::VK_SHARING_MODE_EXCLUSIVE
 */
struct exclusive
{
    static constexpr auto vk = VK_SHARING_MODE_EXCLUSIVE;

    struct view
    {
        [[nodiscard]] friend constexpr bool operator==(const view& a, const view& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const view& a, const view& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const view& a, const view& b) noexcept = default;
    };

    [[nodiscard]] constexpr operator view() const noexcept { return {}; }

    [[nodiscard]] friend constexpr bool operator==(const exclusive& a, const exclusive& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const exclusive& a, const exclusive& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const exclusive& a, const exclusive& b) noexcept = default;

    [[nodiscard]] friend constexpr VkSharingMode to_underlying(const exclusive&) noexcept { return vk; }
};

/**
 * Specifies that concurrent access to any range or image subresource of the object from multiple queue families is supported.
 * @see VkSharingMode::VK_SHARING_MODE_CONCURRENT
 */
struct concurrent
{
    static constexpr auto vk = VK_SHARING_MODE_CONCURRENT;

    struct view
    {
        std::span<const std::uint32_t> queues = {};

        [[nodiscard]] friend constexpr bool operator==(const view& a, const view& b) noexcept { return std::ranges::equal(a.queues, b.queues); }

        [[nodiscard]] friend constexpr bool operator!=(const view& a, const view& b) noexcept { return not(a == b); }

        [[nodiscard]] friend constexpr auto operator<=>(const view& a, const view& b) noexcept
        {
            return std::lexicographical_compare_three_way(a.queues.begin(), a.queues.end(), b.queues.begin(), b.queues.end());
        }
    };

    [[nodiscard]] constexpr operator view() const noexcept { return {queues}; }

    small_flat_set<std::uint32_t> queues = {}; ///< The families of the queues that will access to this resources.

    [[nodiscard]] friend constexpr bool operator==(const concurrent& a, const concurrent& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const concurrent& a, const concurrent& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const concurrent& a, const concurrent& b) noexcept = default;

    [[nodiscard]] friend constexpr VkSharingMode to_underlying(const concurrent&) noexcept { return vk; }
};

/// Any sharing mode.
struct any
{
    using value_type = std::variant<exclusive, concurrent>;

    struct view
    {
        using value_type = std::variant<exclusive::view, concurrent::view>;

        value_type value = {};

        [[nodiscard]] friend constexpr bool operator==(const view& a, const view& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const view& a, const view& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const view& a, const view& b) noexcept = default;
    };

    [[nodiscard]] constexpr operator view() const noexcept
    {
        return std::visit([]<typename variant>(const variant& v) noexcept -> view { return view{static_cast<typename variant::view>(v)}; }, value);
    }

    value_type value = exclusive{};

    [[nodiscard]] friend constexpr bool operator==(const any& a, const any& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const any& a, const any& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const any& a, const any& b) noexcept = default;

    [[nodiscard]] friend constexpr VkSharingMode to_underlying(const any& s) noexcept
    {
        return std::visit([]<typename variant>(const variant&) noexcept { return variant::vk; }, s.value);
    }
};

[[nodiscard]] inline constexpr std::uint32_t queue_count(const any& s) noexcept
{
    if(auto* const p = std::get_if<concurrent>(std::addressof(s.value)))
    {
        return vk_size(p->queues);
    }

    return 0u;
}

[[nodiscard]] inline constexpr const std::uint32_t* queue_data(const any& s) noexcept
{
    if(auto* const p = std::get_if<concurrent>(std::addressof(s.value)))
    {
        return std::to_address(p->queues.cbegin());
    }

    return nullptr;
}

} // namespace fubuki::fuyu::sharing_mode

#endif // FUBUKI_FUYU_SHARING_MODE_HPP
