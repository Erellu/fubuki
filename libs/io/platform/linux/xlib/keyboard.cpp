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

#include "io/platform/linux/xlib/detail/keyboard.hpp"

#include <core/assertion.hpp>

#include "io/platform/linux/xlib/detail/code.hpp"
#include "io/platform/linux/xlib/error.hpp"
#include "io/platform/linux/xlib/keyboard.hpp"

namespace fubuki::io::platform::linux_bsd::xlib::keyboard
{

[[nodiscard]]
std::expected<bool, error::any> poll(Display* dp, key k) noexcept
{
    if(dp == nullptr)
    {
        fubuki_assert(dp != nullptr, "Invalid display");
        return false;
    }

    const auto key_code = to_xlib_code(dp, k);

    if(not key_code)
    {
        return std::unexpected{platform::error::any{any_call_info{call_info{.result{}, .call_literal = "XKeysymToKeycode(dp, k)"_literal}}}};
    }

    constexpr std::size_t         buffer_size = 32;
    std::array<char, buffer_size> result      = {};

    if(const auto r = XQueryKeymap(dp, result.data()); r != True)
    {
        return std::unexpected{
            platform::error::any{any_call_info{call_info{.result{xlib::detail::from_xlib(r)}, .call_literal = "XQueryKeymap(dp, result)"_literal}}}};
    }

    const auto target_byte = static_cast<std::size_t>(*key_code / 8);
    const auto target_bit  = *key_code % 8;
    const auto target_mask = 0x01 << target_bit;

    if(target_byte >= result.size())
    {
        fubuki_assert(target_byte < result.size(), "Internal error");
        return false;
    }

    return result[target_byte] & target_mask; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
}

[[nodiscard]]
std::expected<modifier_mask, error::any> current_modifiers(Display* dp) noexcept
{
    if(dp == nullptr)
    {
        fubuki_assert(dp != nullptr, "Invalid display");
        return {};
    }

    modifier_mask result = {};

    constexpr std::size_t         buffer_size = 32;
    std::array<char, buffer_size> keymap      = {};

    if(const auto r = XQueryKeymap(dp, keymap.data()); r != True)
    {
        return std::unexpected{
            platform::error::any{any_call_info{call_info{.result{xlib::detail::from_xlib(r)}, .call_literal = "XQueryKeymap(dp, result)"_literal}}}};
    }

    for(const auto [k, mod] : {std::make_pair(key::ctrl, modifier::ctrl),
                               std::make_pair(key::alt, modifier::ctrl),
                               std::make_pair(key::shift, modifier::shift),
                               std::make_pair(key::caps_lock, modifier::caps)})
    {
        const auto key_code = to_xlib_code(dp, k);

        if(not key_code)
        {
            return std::unexpected{platform::error::any{any_call_info{call_info{.result{}, .call_literal = "XKeysymToKeycode(dp, k)"_literal}}}};
        }

        const auto target_byte = static_cast<std::size_t>(*key_code / 8);
        const auto target_bit  = *key_code % 8;
        const auto target_mask = 0x01 << target_bit;

        if(target_byte >= keymap.size())
        {
            fubuki_assert(target_byte < keymap.size(), "Internal error");
            return {};
        }

        if(keymap[target_byte] & target_mask) // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
        {
            result |= mod;
        }
    }

    return result;
}

[[nodiscard]] std::optional<KeyCode> to_xlib_code(Display* dp, key k) noexcept
{
    return detail::to_xlib_sym(k).transform([dp](const KeySym s) noexcept { return XKeysymToKeycode(dp, s); });
}

} // namespace fubuki::io::platform::linux_bsd::xlib::keyboard
