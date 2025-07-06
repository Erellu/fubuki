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

#ifndef FUBUKI_IO_PLATFORM_LINUX_EVENT_MOUSE_STATE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_EVENT_MOUSE_STATE_HPP

#include <cstdint>
#include <optional>

#include <core/types.hpp>

namespace fubuki::io::platform::linux_bsd
{

struct mouse_state
{
    /// State of a mouse button. Primarily used implement double click on platforms that do not provide such an event natively (XLib, Wayland, ...).
    struct button
    {
        std::optional<position2d>    last_position                = {}; ///< Last position known. Used to determine if the user double-clicked.
        std::optional<std::uint32_t> last_click_timestamp         = {}; ///< Used to determine if the user double-clicked.
        bool                         next_release_is_double_click = false;

        [[nodiscard]] friend constexpr bool operator==(const button& a, const button& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const button& a, const button& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const button& a, const button& b) noexcept = default;

        /// Swaps two objects.
        void swap(button& other) noexcept
        {
            last_position.swap(other.last_position);
            last_click_timestamp.swap(other.last_click_timestamp);
            std::swap(next_release_is_double_click, other.next_release_is_double_click);
        }

        /// Swaps two objects.
        friend void swap(button& a, button& b) noexcept { a.swap(b); }
    };

    button                    left          = {};
    button                    centre        = {};
    button                    right         = {};
    button                    ex_1          = {};
    button                    ex_2          = {};
    std::optional<position2d> last_position = {};

    [[nodiscard]] friend constexpr bool operator==(const mouse_state& a, const mouse_state& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const mouse_state& a, const mouse_state& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const mouse_state& a, const mouse_state& b) noexcept = default;

    /// Swaps two objects.
    void swap(mouse_state& other) noexcept
    {
        left.swap(other.left);
        centre.swap(other.centre);
        right.swap(other.right);
        ex_1.swap(other.ex_1);
        ex_2.swap(other.ex_2);
        last_position.swap(other.last_position);
    }

    /// Swaps two objects.
    friend void swap(mouse_state& a, mouse_state& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_EVENT_MOUSE_STATE_HPP
