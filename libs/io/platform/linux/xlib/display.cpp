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

#include "io/platform/linux/xlib/display.hpp"

#include "io/platform/linux/xlib/code.hpp"
#include "io/platform/linux/xlib/error.hpp"

#include <X11/Xlib.h>

namespace fubuki::io::platform::linux_bsd::xlib
{

[[nodiscard]] std::expected<display::internal_atoms, error::api_call> atoms_of(Display* dp) noexcept
{
    constexpr auto handle_error = [](Atom a, string_literal literal) noexcept -> std::optional<call_info>
    {
        switch(a)
        {
            case None:
            {
                return call_info{result{code::unknown}, literal};
            }

            case BadAlloc:
            {
                return call_info{result{code::bad_alloc}, literal};
            }

            case BadValue:
            {
                return call_info{result{code::bad_value}, literal};
            }

            default:
            {
                return {};
            }
        }
    };

    display::internal_atoms atoms = {};

    {
        constexpr auto literal = R"(XInternAtom(dp, "WM_PROTOCOLS", 1);)"_literal;
        atoms.wm_protocols     = XInternAtom(dp, "WM_PROTOCOLS", 1);

        if(const auto error = handle_error(atoms.wm_protocols, literal))
        {
            return std::unexpected{*error};
        }
    }

    {
        constexpr auto literal  = R"(XInternAtom(dp, "WM_DELETE_WINDOW", 0);)"_literal;
        atoms.wm_delete_message = XInternAtom(dp, "WM_DELETE_WINDOW", 0);

        if(const auto error = handle_error(atoms.wm_delete_message, literal))
        {
            return std::unexpected{*error};
        }
    }

    {
        constexpr auto literal  = R"(XInternAtom(dp, "_NET_WM_WINDOW_OPACITY", 0);)"_literal;
        atoms.wm_window_opacity = XInternAtom(dp, "_NET_WM_WINDOW_OPACITY", 0);

        if(const auto error = handle_error(atoms.wm_window_opacity, literal))
        {
            return std::unexpected{*error};
        }
    }

    return atoms;
}

display::display(information i) : m_handle{XOpenDisplay(i.display_name.value_or(nullptr))}, m_info{i}
{
    if(m_handle == nullptr)
    {
        throw call_exception{
            call_info{.result = {code::unknown}, .call_literal = "XOpenDisplay"_literal}
        };
    }

    const auto atoms = atoms_of(m_handle);

    if(not atoms)
    {
        throw call_exception{atoms.error().value};
    }

    m_atoms = *atoms;
}

[[nodiscard]] std::expected<display, error::api_call> display::make(information i) noexcept
{
    display result{token{}, i};

    result.m_handle = XOpenDisplay(result.m_info.display_name.value_or(nullptr));

    if(result.handle() == nullptr)
    {
        return std::unexpected{error::api_call{call_info{.result = {code::unknown}, .call_literal = "XOpenDisplay"_literal}}};
    }

    const auto atoms = atoms_of(result.m_handle);

    if(not atoms)
    {
        return std::unexpected{atoms.error()};
    }

    result.m_atoms = *atoms;

    return result;
}

display::~display() noexcept
{
    if(m_handle != nullptr)
    {
        XCloseDisplay(m_handle);
    }
}

} // namespace fubuki::io::platform::linux_bsd::xlib
