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

#ifndef FUBUKI_FUYU_QUEUE_HPP
#define FUBUKI_FUYU_QUEUE_HPP

#include <cstdint>
#include <functional>
#include <limits>

#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/device_ref.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

/**
 * Queue data.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkQueue.html
 */
struct queue
{
    queue_handle  handle = {};                                        ///< Vulkan handle.
    device_cref   device;                                             ///< Logical device used by this queue.
    std::uint32_t family = std::numeric_limits<std::uint32_t>::max(); ///< Queue family index.
    std::uint32_t index  = 0;                                         ///< Queue index used in vkGetDeviceQueue.
    VkQueueFlags  type   = {};                                        ///< Queue type.

    [[nodiscard]] constexpr operator queue_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const queue& a, const queue& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const queue& a, const queue& b) noexcept { return not(a == b); }
    [[nodiscard]] friend constexpr auto operator<=>(const queue& a, const queue& b) noexcept { return a.handle <=> b.handle; }

    /// Looks for a queue dedicated to compute operations (that does not support), if any, in a range of queues.
    [[nodiscard]] static constexpr std::optional<queue> compute_dedicated(std::span<const queue> queues) noexcept
    {
        constexpr auto predicate
            = [](const queue& q) noexcept { return ((q.type & VK_QUEUE_COMPUTE_BIT) != 0) and ((q.type & VK_QUEUE_GRAPHICS_BIT) == 0); };

        if(const auto it = std::ranges::find_if(queues, predicate); it != queues.end())
        {
            return *it;
        }

        return {};
    }

    /// Finds a queue dedicated to transfer operations, if any, in a range of queues.
    [[nodiscard]] static constexpr std::optional<queue> transfer_dedicated(std::span<const queue> queues) noexcept
    {
        constexpr auto predicate = [](const queue& q) noexcept
        { return ((q.type & VK_QUEUE_TRANSFER_BIT) != 0) and (((q.type & VK_QUEUE_GRAPHICS_BIT) == 0) and ((q.type & VK_QUEUE_COMPUTE_BIT) == 0)); };

        if(const auto it = std::ranges::find_if(queues, predicate); it != queues.end())
        {
            return *it;
        }

        return {};
    }
};

/// A queue that can be used to present on a surface.
struct presentable_queue : queue
{
#if defined(VK_KHR_surface)
    surface_khr_handle surface; ///< The surface this queue can present to.
#endif                          // defined(VK_KHR_surface)

    [[nodiscard]] friend constexpr bool operator==(const presentable_queue& a, const presentable_queue& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const presentable_queue& a, const presentable_queue& b) noexcept { return not(a == b); }
    [[nodiscard]] friend constexpr auto operator<=>(const presentable_queue& a, const presentable_queue& b) noexcept { return a.handle <=> b.handle; }
};

/// The queues created upon logical device creation.
struct device_queues
{
    struct view
    {
        std::span<const queue>             all         = {};
        std::span<const presentable_queue> presentable = {};

        [[nodiscard]] friend constexpr bool operator==(const view& a, const view& b) noexcept
        {
            return std::ranges::equal(a.all, b.all) and std::ranges::equal(a.presentable, b.presentable);
        }

        [[nodiscard]] friend constexpr bool operator!=(const view& a, const view& b) noexcept { return not(a == b); }

        [[nodiscard]] friend constexpr auto operator<=>(const view& a, const view& b) noexcept
        {
            if(const auto cmp = std::lexicographical_compare_three_way(a.all.begin(), a.all.end(), b.all.begin(), b.all.end());
               cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            return std::lexicographical_compare_three_way(a.presentable.begin(), a.presentable.end(), b.presentable.begin(), b.presentable.end());
        }
    };

    small_vector<queue>             all         = {}; ///< All the queues created.
    small_vector<presentable_queue> presentable = {}; ///< The queues able to present on a surface.

    [[nodiscard]] constexpr operator view() const noexcept { return {.all = all, .presentable = presentable}; }

    [[nodiscard]] friend constexpr bool operator==(const device_queues& a, const device_queues& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const device_queues& a, const device_queues& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const device_queues& a, const device_queues& b) noexcept = default;

    /// Swaps two objects.
    void swap(device_queues& other) noexcept
    {
        all.swap(other.all);
        presentable.swap(other.presentable);
    }

    /// Swaps two objects.
    friend void swap(device_queues& a, device_queues& b) noexcept { return a.swap(b); }
};

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::queue>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::queue& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_QUEUE_HPP
