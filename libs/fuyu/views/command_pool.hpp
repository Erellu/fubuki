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

#ifndef FUBUKI_FUYU_VIEWS_COMMAND_POOL_HPP
#define FUBUKI_FUYU_VIEWS_COMMAND_POOL_HPP

#include <limits>

#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/device_ref.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/// Command pool view.
struct command_pool
{
    command_pool_handle      handle = {};                                              ///< Vulkan handle.
    device_cref              device;                                                   ///< Device on which the command pool is allocated.
    std::uint32_t            queue_family = std::numeric_limits<std::uint32_t>::max(); ///< Queue associated to the pool.
    VkCommandPoolCreateFlags flags        = VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM; ///< The flags this pool was created with.

    [[nodiscard]] constexpr operator command_pool_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const command_pool& a, const command_pool& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const command_pool& a, const command_pool& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const command_pool& a, const command_pool& b) noexcept { return a.handle <=> b.handle; }
};

} // namespace views

using command_pool_view = views::command_pool;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::command_pool_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::command_pool_view& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_COMMAND_POOL_HPP
