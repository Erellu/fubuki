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

#ifndef FUBUKI_FUYU_VIEWS_INSTANCE_HPP
#define FUBUKI_FUYU_VIEWS_INSTANCE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "fuyu/functions/instance.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/**
 * A non-owning view of an instance.
 */
struct instance
{
    instance_handle                                  handle  = {}; ///< Vulkan handle.
    version_number                                   version = {}; ///< Instance version.
    std::reference_wrapper<const instance_functions> functions;    ///< Instance functions.

    /// Conversion operator to underlying handle.
    [[nodiscard]] constexpr operator instance_handle() const noexcept { return handle; }

    [[nodiscard]] constexpr operator const instance_functions&() const noexcept { return functions; }
    [[nodiscard]] constexpr operator const instance_core_functions&() const noexcept { return functions.get().core; }
    [[nodiscard]] constexpr operator const instance_ext_functions&() const noexcept { return functions.get().ext; }

    /// Returns a pointer to the functions of this instance.
    [[nodiscard]] constexpr const auto* operator->() const noexcept { return std::addressof(functions.get().core); }

    [[nodiscard]] friend constexpr bool operator==(const instance& a, const instance& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const instance& a, const instance& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const instance& a, const instance& b) noexcept { return a.handle <=> b.handle; }
};

} // namespace views

using instance_view = views::instance;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::instance_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::instance_view& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_INSTANCE_HPP
