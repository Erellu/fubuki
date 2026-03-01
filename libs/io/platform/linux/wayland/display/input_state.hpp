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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_INPUT_STATE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_INPUT_STATE_HPP

#include <cstdint>
#include <optional>
#include <utility>

#include "io/platform/current_platform.hpp"
#include "io/platform/keyboard_key.hpp"
#include "io/platform/linux/event/mouse_state.hpp"

namespace fubuki::io::platform::linux_bsd::wayland::display_parts
{

struct seat_state
{
    struct focus
    {
        surface_handle surface = {};
        std::uint32_t  serial  = {};

        [[nodiscard]] friend constexpr bool operator==(const focus& a, const focus& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const focus& a, const focus& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const focus& a, const focus& b) noexcept = default;

        /// Swaps two objects.
        void swap(focus& other) noexcept
        {
            surface.swap(other.surface);
            std::swap(serial, other.serial);
        }

        /// Swaps two objects.
        friend void swap(focus& a, focus& b) noexcept { a.swap(b); }
    };

    struct kb
    {
        struct repetetion
        {
            std::int32_t  rate  = 0;
            std::int32_t  delay = 0;
            std::uint32_t key   = 0; ///< XKB scancode of the key being repeated.

            [[nodiscard]] friend constexpr bool operator==(const repetetion& a, const repetetion& b) noexcept  = default;
            [[nodiscard]] friend constexpr bool operator!=(const repetetion& a, const repetetion& b) noexcept  = default;
            [[nodiscard]] friend constexpr auto operator<=>(const repetetion& a, const repetetion& b) noexcept = default;

            /// Swaps two objects.
            void swap(repetetion& other) noexcept
            {
                std::swap(rate, other.rate);
                std::swap(delay, other.delay);
                std::swap(key, other.key);
            }

            /// Swaps two objects.
            friend void swap(repetetion& a, repetetion& b) noexcept { a.swap(b); }
        };

        std::optional<focus>        attention         = {};
        io::keyboard::modifier_mask current_modifiers = {};
        repetetion                  repeat            = {};

        [[nodiscard]] friend constexpr bool operator==(const kb& a, const kb& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const kb& a, const kb& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const kb& a, const kb& b) noexcept = default;

        /// Swaps two objects.
        void swap(kb& other) noexcept
        {
            attention.swap(other.attention);
            std::swap(current_modifiers, other.current_modifiers);
            repeat.swap(other.repeat);
        }

        /// Swaps two objects.
        friend void swap(kb& a, kb& b) noexcept { a.swap(b); }
    };

    struct pointer
    {
        using button = linux_bsd::mouse_state::button;

        std::optional<focus>   attention = {};
        linux_bsd::mouse_state common    = {};

        [[nodiscard]] friend constexpr bool operator==(const pointer& a, const pointer& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const pointer& a, const pointer& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const pointer& a, const pointer& b) noexcept = default;

        /// Swaps two objects.
        void swap(pointer& other) noexcept
        {
            attention.swap(other.attention);
            common.swap(other.common);
        }

        /// Swaps two objects.
        friend void swap(pointer& a, pointer& b) noexcept { a.swap(b); }
    };

    kb      keyboard = {};
    pointer mouse    = {};

    [[nodiscard]] friend constexpr bool operator==(const seat_state& a, const seat_state& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const seat_state& a, const seat_state& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const seat_state& a, const seat_state& b) noexcept = default;

    /// Swaps two objects.
    void swap(seat_state& other) noexcept
    {
        keyboard.swap(other.keyboard);
        mouse.swap(other.mouse);
    }

    /// Swaps two objects.
    friend void swap(seat_state& a, seat_state& b) noexcept { a.swap(b); }
};

/// A structure keeping track of state changes during events.
struct input_state
{
    seat_state seat = {};

    [[nodiscard]] friend constexpr bool operator==(const input_state& a, const input_state& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const input_state& a, const input_state& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const input_state& a, const input_state& b) noexcept = default;

    /// Swaps two objects.
    void swap(input_state& other) noexcept { seat.swap(other.seat); }

    /// Swaps two objects.
    friend void swap(input_state& a, input_state& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::linux_bsd::wayland::display_parts

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_DISPLAY_INPUT_STATE_HPP
