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

#ifndef FUYU_FUYU_VIEWS_SWAPCHAIN_HPP
#define FUYU_FUYU_VIEWS_SWAPCHAIN_HPP

#include <functional>

#include <core/handle.hpp>

#include "fuyu/views/device_ref.hpp"

namespace fubuki::fuyu
{

namespace views
{
// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
struct swapchain
{
#if defined(VK_KHR_swapchain)
    swapchain_khr_handle handle = {};  ///< Vulkan handle.
    device_cref          device;       ///< Device on which the handle is allocated.
    surface_khr_handle   surface = {}; ///< Parent surface.

    [[nodiscard]] constexpr operator swapchain_khr_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const swapchain& a, const swapchain& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const swapchain& a, const swapchain& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const swapchain& a, const swapchain& b) noexcept { return a.handle <=> b.handle; }
#else
    [[nodiscard]] friend constexpr bool operator==(const swapchain& a, const swapchain& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const swapchain& a, const swapchain& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const swapchain& a, const swapchain& b) noexcept = default;
#endif // VK_KHR_swapchain
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

} // namespace views

using swapchain_view = views::swapchain;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::swapchain_view>
{
    [[nodiscard]] std::size_t operator()(const fubuki::fuyu::swapchain_view& v) const noexcept
    {
#if defined(VK_KHR_swapchain)
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
#else
        return 66743015u; // The first digit of the gravitational constant
#endif // #if defined(VK_KHR_swapchain)
    }
};

} // namespace std

#endif // FUYU_FUYU_VIEWS_SWAPCHAIN_HPP
