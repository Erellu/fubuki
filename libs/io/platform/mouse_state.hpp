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

#ifndef FUBUKI_IO_MOUSE_STATE_HPP
#define FUBUKI_IO_MOUSE_STATE_HPP

#include <core/types.hpp>

namespace fubuki::io::mouse
{

/// Mouse state.
struct state
{
    /// Status of the mouse button.
    struct buttons
    {
        bool left    = false; ///< State of the left mouse button.
        bool central = false; ///< State of the middle mouse button.
        bool right   = false; ///< State of the right mouse button.
        bool ex_1    = false; ///< State of the first extra button.
        bool ex_2    = false; ///< State of the second extra button.

        friend constexpr bool operator==(const buttons&, const buttons&) noexcept  = default;
        friend constexpr bool operator!=(const buttons&, const buttons&) noexcept  = default;
        friend constexpr auto operator<=>(const buttons&, const buttons&) noexcept = default;

        template<typename char_type, typename traits = std::char_traits<char_type>>
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const buttons& b)
        {
            return out << "{left: " << b.left << ", central: " << b.central << ", right: " << b.right << ", ex_1:" << b.ex_1 << ", ex_2:" << b.ex_2
                       << "}";
        }
    };

    position2d pos{};    ///< Mouse position on the screen.
    buttons    button{}; ///< Current buttons state.

    friend constexpr bool operator==(const state&, const state&) noexcept  = default;
    friend constexpr bool operator!=(const state&, const state&) noexcept  = default;
    friend constexpr auto operator<=>(const state&, const state&) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const state& s)
    {
        return out << "mouse: {position: " << s.pos << "buttons: " << s.button << "}";
    }
};

} // namespace fubuki::io::mouse

#endif // FUBUKI_IO_MOUSE_STATE_HPP
