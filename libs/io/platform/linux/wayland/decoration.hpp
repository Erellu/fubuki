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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DECORATION_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DECORATION_HPP

#include <optional>
#include <variant>

#include "io/platform/linux/wayland/zxdg/decoration.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

class decoration
{
public:

    using server_side = zxdg::decoration;
    struct client_side
    {
    };

    using any = std::variant<client_side, server_side>;

    decoration(server_side d) noexcept : m_value{std::in_place_type<server_side>, std::move(d)} {}

    decoration(client_side d) noexcept
        : m_value{std::in_place_type<client_side>, std::move(d)} {} // NOLINT(performance-move-const-arg): this is a placeholder

    [[nodiscard]] auto server_handle() noexcept
    {
        std::optional<zxdg_toplevel_decoration_v1*> result = {};

        if(auto* const ptr = std::get_if<server_side>(std::addressof(m_value)))
        {
            result = ptr->handle();
        }

        return result;
    }

    [[nodiscard]] auto server_handle() const noexcept
    {
        std::optional<const zxdg_toplevel_decoration_v1*> result = {};

        if(const auto* const ptr = std::get_if<server_side>(std::addressof(m_value)))
        {
            result = ptr->handle();
        }

        return result;
    }

private:

    any m_value;
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DECORATION_HPP
