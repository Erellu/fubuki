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

#include <memory>

#include "io/platform/linux/xkb/keymap.hpp"

#include <core/unique_c_ptr.hpp>

#include <xkbcommon/xkbcommon.h>

namespace fubuki::io::platform::linux_bsd::xkb
{

namespace
{

[[nodiscard]] keymap::modifiers_index get_modifiers(xkb_keymap* keymap) noexcept
{
    return {
        .control   = xkb_keymap_mod_get_index(keymap, "Control"),
        .alt       = xkb_keymap_mod_get_index(keymap, "Mod1"),
        .shift     = xkb_keymap_mod_get_index(keymap, "Shift"),
        .super     = xkb_keymap_mod_get_index(keymap, "Mod4"),
        .caps_lock = xkb_keymap_mod_get_index(keymap, "Lock"),
        .numlock   = xkb_keymap_mod_get_index(keymap, "Mod2"),
    };
}

} // anonymous namespace

[[nodiscard]] std::optional<any_call_info> keymap::create(xkb_context* parent, const char* c_str, format f, compile_flags compile) noexcept
{
    m_handle = xkb_keymap_new_from_string(parent, c_str, static_cast<xkb_keymap_format>(f), static_cast<xkb_keymap_compile_flags>(compile));

    if(m_handle == nullptr)
    {
        return any_call_info{
            linux_call_info{
                            .result = {},
                            .call_literal
                = "xkb_keymap_new_from_string(parent, c_str, static_cast<xkb_keymap_format>(f), static_cast<xkb_keymap_compile_flags>(compile))"_literal}
        };
    }

    m_indices = get_modifiers(m_handle);

    return {};
}

[[nodiscard]] std::optional<any_call_info> keymap::create(xkb_context* parent, std::string_view str, format f, compile_flags compile) noexcept
{
    m_handle = xkb_keymap_new_from_buffer(
        parent, std::to_address(str.begin()), str.size(), static_cast<xkb_keymap_format>(f), static_cast<xkb_keymap_compile_flags>(compile));

    if(m_handle == nullptr)
    {
        return any_call_info{
            linux_call_info{.result       = {},
                            .call_literal = "xkb_keymap_new_from_buffer(parent, std::to_address(str.begin()), str.size(), "
                                            "static_cast<xkb_keymap_format>(f), static_cast<xkb_keymap_compile_flags>(compile))"_literal}
        };
    }

    m_indices = get_modifiers(m_handle);

    return {};
}

[[nodiscard]] std::optional<any_call_info>
keymap::create(xkb_context* parent, std::span<const std::byte> buffer, format f, compile_flags compile) noexcept
{
    m_handle = xkb_keymap_new_from_buffer(parent,
                                          reinterpret_cast<const char*>(buffer.data()), // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                                          buffer.size(),
                                          static_cast<xkb_keymap_format>(f),
                                          static_cast<xkb_keymap_compile_flags>(compile));

    if(m_handle == nullptr)
    {
        return any_call_info{
            linux_call_info{.result       = {},
                            .call_literal = "xkb_keymap_new_from_buffer(parent, std::to_address(str.begin()), str.size(), "
                                            "static_cast<xkb_keymap_format>(f), static_cast<xkb_keymap_compile_flags>(compile))"_literal}
        };
    }

    m_indices = get_modifiers(m_handle);

    return {};
}

[[nodiscard]] std::optional<any_call_info> keymap::create(xkb_context* parent, const rule_names& names, compile_flags compile) noexcept
{
    const xkb_rule_names xkb_names = {
        .rules   = names.rules,
        .model   = names.model,
        .layout  = names.layout,
        .variant = names.variant,
        .options = names.options,
    };

    m_handle = xkb_keymap_new_from_names(parent, std::addressof(xkb_names), static_cast<xkb_keymap_compile_flags>(compile));

    if(m_handle == nullptr)
    {
        return any_call_info{
            linux_call_info{
                            .result = {},
                            .call_literal
                = "xkb_keymap_new_from_string(parent, c_str, static_cast<xkb_keymap_format>(f), static_cast<xkb_keymap_compile_flags>(compile))"_literal}
        };
    }

    m_indices = get_modifiers(m_handle);

    return {};
}

keymap::~keymap() noexcept
{
    if(m_handle != nullptr)
    {
        xkb_keymap_unref(m_handle);
    }
}

std::expected<std::string, any_call_info> to_string(const keymap& km)
{
    const unique_c_ptr<char> c_str{xkb_keymap_get_as_string(km.m_handle, XKB_KEYMAP_FORMAT_TEXT_V1)};

    if(c_str == nullptr)
    {
        return std::unexpected{any_call_info{
            linux_call_info{.result = {}, .call_literal = "xkb_keymap_get_as_string(km.m_handle, XKB_KEYMAP_FORMAT_TEXT_V1))"_literal}}};
    }

    return std::string{c_str.get()};
}

} // namespace fubuki::io::platform::linux_bsd::xkb
