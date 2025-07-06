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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SEAT_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SEAT_HPP

#include <core/config/macros.hpp>

#include "io/platform/linux/wayland/keyboard.hpp"
#include "io/platform/linux/wayland/pointer.hpp"

extern "C"
{

struct wl_seat;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland
{

class seat
{
    struct token
    {
    };

public:

    /// Components of this seat.
    class components
    {
    public:
        std::optional<wayland::keyboard> keyboard = {}; ///< The seat's keyboard.
        std::optional<wayland::pointer>  mouse    = {}; ///< The seats's pointer.

        components() noexcept = default;
        components(std::optional<wayland::keyboard> k, std::optional<wayland::pointer> p) noexcept : keyboard{std::move(k)}, mouse{std::move(p)} {}

        components(const components&)            = delete;
        components& operator=(const components&) = delete;

        /// Move constructor.
        components(components&& other) noexcept : keyboard{std::move(other.keyboard)}, mouse{std::move(other.mouse)} {}

        ~components() noexcept = default;

        /// Swaps two objects.
        void swap(components& other) noexcept
        {
            keyboard.swap(other.keyboard);
            mouse.swap(other.mouse);
        }

        /// Swaps two objects.
        friend void swap(components& a, components& b) noexcept { a.swap(b); }
    };

    /**
     * Constructor.
     * @param parent Parent display.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    FUBUKI_IO_PLATFORM_API
    seat(platform::views::display::wayland parent);

    /**
     * Constructor.
     * @param handle Seat handle.
     * @param flags Seat property flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @pre handle must not be nullptr.
     * @pre flags must be a flag combination of wl_seat_capability.
     */
    FUBUKI_IO_PLATFORM_API
    seat(wl_seat* handle, std::uint32_t flags);

    seat(const seat&)            = delete;
    seat& operator=(const seat&) = delete;

    /// Move constructor.
    seat(seat&& other) noexcept : m_components{std::move(other.m_components)}, m_handle{std::exchange(other.m_handle, nullptr)} {}

    /// Move assignment operator.
    seat& operator=(seat&& other) noexcept
    {
        swap(other);
        return *this;
    }

    // Does NOT call wl_seat_destroy, the handle is *global* and destroying it invalidates all wl_keyboard, wl_pointer, etc. linked to it.
    // This object exists to simplify the interface of wayland::window.
    ~seat() noexcept = default;

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent display.
     * @returns The resulting object, or an instance of any_call_info describing the call that failed.
     */
    [[nodiscard]] FUBUKI_IO_PLATFORM_API static std::expected<seat, error::api_call> make(platform::views::display::wayland parent) noexcept;

    /**
     * Constructor.
     * @param handle Seat handle.
     * @param flags Seat property flags.
     * @returns The resulting object, or an instance of any_call_info describing the call that failed.
     * @pre handle must not be nullptr.
     * @pre flags must be a flag combination of wl_seat_capability.
     */
    [[nodiscard]] FUBUKI_IO_PLATFORM_API static std::expected<seat, error::api_call> make(wl_seat* handle, std::uint32_t flags) noexcept;

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Returns a reference to the parts of this seat.
    [[nodiscard]] auto& parts() noexcept { return m_components; }

    /// Returns a reference to the parts of this seat.
    [[nodiscard]] const auto& parts() const noexcept { return m_components; }

    /// Swaps two objects.
    void swap(seat& other) noexcept
    {
        m_components.swap(other.m_components);
        std::swap(m_handle, other.m_handle);
    }

    /// Swaps two objects.
    friend void swap(seat& a, seat& b) noexcept { a.swap(b); }

private:

    seat(token, std::optional<keyboard> k, std::optional<pointer> p, wl_seat* h) noexcept : m_components{std::move(k), std::move(p)}, m_handle{h} {}

    components m_components;
    wl_seat*   m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SEAT_HPP
