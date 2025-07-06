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

#ifndef FUBUKI_FUYU_VIEWS_DEVICE_HPP
#define FUBUKI_FUYU_VIEWS_DEVICE_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "fuyu/functions/device.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

class instance;

namespace views
{

/**
 * A non-owning view of a logical device.
 */
struct device
{
    device_handle                                  handle = {};   ///< Device handle.
    std::reference_wrapper<const fuyu::instance>   instance;      ///< The instance the device was created from.
    version_number                                 version = {};  ///< Vulkan version the instance uses.
    std::reference_wrapper<const device_functions> functions;     ///< Device functions.
    physical_device_handle                         hardware = {}; ///< Physical device this device uses.

    [[nodiscard]] constexpr operator device_handle() const noexcept { return handle; }

    [[nodiscard]] constexpr operator const device_functions&() const noexcept { return functions; }
    [[nodiscard]] constexpr operator const device_core_functions&() const noexcept { return functions.get().core; }
    [[nodiscard]] constexpr operator const device_ext_functions&() const noexcept { return functions.get().ext; }
    [[nodiscard]] constexpr operator physical_device_handle() const noexcept { return hardware; }

    /// Returns a pointer to the functions of this device.
    [[nodiscard]] constexpr const auto* operator->() const noexcept { return std::addressof(functions.get().core); }

    [[nodiscard]] friend constexpr bool operator==(const device& a, const device& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const device& a, const device& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const device& a, const device& b) noexcept { return a.handle <=> b.handle; }
};

} // namespace views

using device_view = views::device;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::device_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::device_view& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_DEVICE_HPP
