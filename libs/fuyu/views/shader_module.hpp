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

#ifndef FUBUKI_FUYU_VIEWS_SHADER_MODULE_HPP
#define FUBUKI_FUYU_VIEWS_SHADER_MODULE_HPP

#include <functional>

#include <core/handle.hpp>

#include "fuyu/views/device_ref.hpp"

namespace fubuki::fuyu
{

namespace views
{

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

/// A view of a shader module.
struct shader_module
{
    shader_module_handle handle = {}; ///< Shader module handle.
    device_cref          device;      ///< Device the handle comes from.

    [[nodiscard]] constexpr operator shader_module_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const shader_module& a, const shader_module& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const shader_module& a, const shader_module& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const shader_module& a, const shader_module& b) noexcept { return a.handle <=> b.handle; }
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

} // namespace views

using shader_module_view = views::shader_module;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::shader_module_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::shader_module_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

} // namespace std

#endif // FUBUKI_FUYU_VIEWS_SHADER_MODULE_HPP
