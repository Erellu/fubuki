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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XKB_STATE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XKB_STATE_HPP

#include <core/config/macros.hpp>

#include "io/platform/error.hpp"

extern "C"
{

struct xkb_state;
struct xkb_keymap;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::xkb
{

/**
 * A RAII object equivalent to `xkb_state`.
 * @see https://xkbcommon.org/doc/current/group__state.html
 */
class state
{
    struct token
    {
    };

public:

    /**
     * Constructor.
     * @param parent parent Parent keymap.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    state(xkb_keymap* parent)
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent keymap.
     * @returns The resulting object, or an instance of any_call_info describing the call that failed.
     */
    [[nodiscard]] static std::expected<state, any_call_info> make(xkb_keymap* parent) noexcept
    {
        state result{token{}};

        if(const auto error = result.create(parent))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    state(const state&)            = delete;
    state& operator=(const state&) = delete;

    /// Move constructor.
    state(state&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)} {}

    /// Move assignment operator.
    state& operator=(state&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /// Destructor. Destroys the underlying handle if it is not nullptr.
    /// @note Calls `xkb_state_unref`.
    ///  If client code called `xkb_state_ref` on the handle, it may not be freed.
    FUBUKI_IO_PLATFORM_API
    ~state() noexcept;

    /// Returns the underlying XKB handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying XKB handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Swaps two objects.
    void swap(state& other) noexcept { std::swap(m_handle, other.m_handle); }

    /// Swaps two objects.
    friend void swap(state& a, state& b) noexcept { a.swap(b); }

private:

    state(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(xkb_keymap* parent) noexcept;

    xkb_state* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::xkb

#endif // FUBUKI_IO_PLATFORM_LINUX_XKB_STATE_HPP
