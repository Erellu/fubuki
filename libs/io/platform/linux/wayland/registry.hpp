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

#ifndef FUBUKI_IO_PLATFORM_WAYLAND_REGISTRY_HPP
#define FUBUKI_IO_PLATFORM_WAYLAND_REGISTRY_HPP

#include <expected>

#include "io/platform/linux/wayland/display.hpp"
#include "io/platform/linux/wayland/error.hpp"

extern "C"
{

struct wl_registry;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland
{

class registry
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
    registry(wl_display* parent)
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Constructor.
     * @param parent Parent display.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    registry(display_view::wayland parent) : registry{parent.handle} {}

    registry(const registry&)            = delete;
    registry& operator=(const registry&) = delete;

    /// Move constructor.
    registry(registry&& other) noexcept { swap(other); }

    /// Move assignment operator.
    registry& operator=(registry&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent display.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<registry, error::api_call> make(wl_display* parent) noexcept
    {
        registry result{token{}};

        if(const auto error = result.create(parent))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent display.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<registry, error::api_call> make(display_view::wayland parent) noexcept { return make(parent.handle); }

    /**
     * Destructor. Destroys the underlying handle if it is not nullptr.
     */
    FUBUKI_IO_PLATFORM_API ~registry() noexcept;

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Swaps two objects.
    void swap(registry& other) noexcept { std::swap(m_handle, other.m_handle); }

    /// Swaps two objects.
    friend void swap(registry& a, registry& b) noexcept { a.swap(b); }

private:

    registry(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(wl_display* parent) noexcept;

    wl_registry* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_WAYLAND_REGISTRY_HPP
