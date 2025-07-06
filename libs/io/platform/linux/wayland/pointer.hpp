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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_POINTER_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_POINTER_HPP

#include <core/config/macros.hpp>

#include "io/platform/error.hpp"
#include "io/platform/views/display.hpp"

extern "C"
{

struct wl_seat;
struct wl_pointer;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland
{

/**
 * Representation of a `wl_pointer`, obtained from the `wl_seat` associated to a `wl_display`.
 */
class pointer
{
    struct token
    {
    };

public:

    /**
     * Constructor.
     * @param parent Parent display.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    pointer(views::display::wayland parent)
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Constructor.
     * @param seat Parent seat.
     * @param flags Seat property flags.
     * @pre seat must not be nullptr.
     * @pre flags must be a flag combination of wl_seat_capability.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    pointer(wl_seat* seat, std::uint32_t flags)
    {
        if(const auto error = create(seat, flags))
        {
            throw call_exception{*error};
        }
    }

    pointer(const pointer&)            = delete;
    pointer& operator=(const pointer&) = delete;

    /// Move constructor.
    pointer(pointer&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)} {}

    /// Move assignment operator.
    pointer& operator=(pointer&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Destructor. Destroys the underlying handle if it is not nullptr.
     */
    FUBUKI_IO_PLATFORM_API
    ~pointer() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent display.
     * @returns The object, or an instance of any_call_info describing the call that failed.
     */
    [[nodiscard]] static std::expected<pointer, error::api_call> make(views::display::wayland parent) noexcept
    {
        pointer result = {token{}};

        if(const auto error = result.create(parent))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param seat Parent seat.
     * @param flags Seat property flags.
     * @pre seat must not be nullptr.
     * @pre flags must be a flag combination of wl_seat_capability.
     * @returns The object, or an instance of any_call_info describing the call that failed.
     */
    [[nodiscard]] static std::expected<pointer, error::api_call> make(wl_seat* seat, std::uint32_t flags) noexcept
    {
        pointer result = {token{}};

        if(const auto error = result.create(seat, flags))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Swaps two objects.
    void swap(pointer& other) noexcept { std::swap(m_handle, other.m_handle); }

    /// Swaps two objects.
    friend void swap(pointer& a, pointer& b) noexcept { a.swap(b); }

private:

    pointer(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(wl_seat* seat, std::uint32_t flags) noexcept;
    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(views::display::wayland parent) noexcept;

    wl_pointer* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_POINTER_HPP
