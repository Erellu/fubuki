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

#ifndef FUBUKI_FUYU_VIEWS_DESCRIPTOR_SET_LAYOUT_HPP
#define FUBUKI_FUYU_VIEWS_DESCRIPTOR_SET_LAYOUT_HPP

#include <span>

#include <core/handle.hpp>

#include "fuyu/information/descriptor_set_layout.hpp"
#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/owning.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

namespace detail::descriptor_set_layout
{

struct owning_view
{
    descriptor_set_layout_handle                                        handle = {};
    device_cref                                                         device;
    descriptor_pool_handle                                              parent   = null_handle;
    small_vector<descriptor_binding::any, descriptor_binding::sbo_size> bindings = {};

    [[nodiscard]] constexpr operator descriptor_set_layout_handle() const noexcept { return handle; }
    [[nodiscard]] constexpr operator VkDescriptorSetLayout() const noexcept { return handle.vk; }

    [[nodiscard]] friend constexpr bool operator==(const owning_view& a, const owning_view& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const owning_view& a, const owning_view& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const owning_view& a, const owning_view& b) noexcept { return a.handle <=> b.handle; }
};

} // namespace detail::descriptor_set_layout

struct descriptor_set_layout
{
    descriptor_set_layout_handle             handle = {};
    device_cref                              device;
    descriptor_pool_handle                   parent   = null_handle;
    std::span<const descriptor_binding::any> bindings = {};

    [[nodiscard]] constexpr operator descriptor_set_layout_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const descriptor_set_layout& a, const descriptor_set_layout& b) noexcept
    {
        return a.handle == b.handle;
    }
    [[nodiscard]] friend constexpr bool operator!=(const descriptor_set_layout& a, const descriptor_set_layout& b) noexcept
    {
        return a.handle != b.handle;
    }
    [[nodiscard]] friend constexpr auto operator<=>(const descriptor_set_layout& a, const descriptor_set_layout& b) noexcept
    {
        return a.handle <=> b.handle;
    }
};

template<>
struct owning<descriptor_set_layout>
{
    std::optional<detail::descriptor_set_layout::owning_view> value = {};
};

} // namespace views

using descriptor_set_layout_view = views::descriptor_set_layout;

} // namespace fubuki::fuyu

// NOLINTEND(cppcoreguidelines-pro-type-member-init)
namespace std
{

template<>
struct hash<fubuki::fuyu::descriptor_set_layout_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::descriptor_set_layout_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

} // namespace std

#endif // FUBUKI_FUYU_VIEWS_DESCRIPTOR_SET_LAYOUT_HPP
