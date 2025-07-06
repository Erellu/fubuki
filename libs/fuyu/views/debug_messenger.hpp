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

#ifndef FUBUKI_FUYU_VIEWS_DEBUG_MESSENGER_HPP
#define FUBUKI_FUYU_VIEWS_DEBUG_MESSENGER_HPP

#include <core/handle.hpp>
#include <core/vulkan.hpp>

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

class instance;

namespace views
{

/// A non-owning view of a debug messenger.
struct debug_messenger
{
#if defined(VK_EXT_debug_utils)
    debug_utils_messenger_ext_handle             handle = {};
    std::reference_wrapper<const fuyu::instance> instance;

    constexpr operator debug_utils_messenger_ext_handle() const noexcept { return handle; }

    friend constexpr bool operator==(const debug_messenger& a, const debug_messenger& b) noexcept { return a.handle == b.handle; }
    friend constexpr bool operator!=(const debug_messenger& a, const debug_messenger& b) noexcept { return a.handle != b.handle; }
    friend constexpr auto operator<=>(const debug_messenger& a, const debug_messenger& b) noexcept { return a.handle <=> b.handle; }
#else
    friend constexpr bool operator==(const debug_messenger& a, const debug_messenger& b) noexcept  = default;
    friend constexpr bool operator!=(const debug_messenger& a, const debug_messenger& b) noexcept  = default;
    friend constexpr auto operator<=>(const debug_messenger& a, const debug_messenger& b) noexcept = default;
#endif // #if defined(VK_EXT_debug_utils)
};

} // namespace views

using debug_messenger_view = views::debug_messenger;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::debug_messenger_view>
{
    [[nodiscard]] std::size_t operator()(const fubuki::fuyu::debug_messenger_view& v) const noexcept
    {
#if defined(VK_EXT_debug_utils)
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
#else
        return 602214076U; // The first digit of Avogadro's constant, hopefully shouldn't collide too much
#endif // #if defined(VK_EXT_debug_utils)
    }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_DEBUG_MESSENGER_HPP
