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

#include "io/platform/linux/wayland/surface.hpp"

#include "io/platform/linux/wayland/display.hpp"
#include "io/platform/linux/wayland/error.hpp"
#include "io/platform/linux/wayland/interface.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

[[nodiscard]]
auto surface::create(views::display::wayland parent) noexcept -> std::optional<any_call_info>
{
    {
        const auto globals = globals_of(parent);

        if(not globals)
        {
            return globals.error().value;
        }

        m_globals = globals->get().handle;
    }

    m_handle = wl_compositor_create_surface(m_globals.compositor);

    if(m_handle == nullptr)
    {
        return any_call_info{
            call_info{.result = {code::unknown{}}, .call_literal = "wl_compositor_create_surface(parent.globals().compositor)"}
        };
    }

    return {};
}

surface::~surface() noexcept
{
    if(m_handle != nullptr)
    {
        wl_surface_destroy(m_handle);
    }
}

} // namespace fubuki::io::platform::linux_bsd::wayland
