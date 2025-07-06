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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SURFACE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SURFACE_HPP

#include "io/platform/error.hpp"
#include "io/platform/linux/wayland/display_global.hpp"
#include "io/platform/views/display.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

/**
 * Representation of a `wl_surface`.
 */
class surface
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
    surface(views::display::wayland parent)
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    surface(const surface&)            = delete;
    surface& operator=(const surface&) = delete;

    /// Move constructor.
    surface(surface&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)}, m_globals{other.m_globals} {}

    /// Move assignment operator.
    surface& operator=(surface&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Destructor. Destroys the underlying handles if they are not nullptr.
     */
    FUBUKI_IO_PLATFORM_API
    ~surface() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent display.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<surface, error::api_call> make(views::display::wayland parent) noexcept
    {
        surface result{token{}};

        if(const auto error = result.create(parent))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() const noexcept { return m_handle; } // NOTE: not const auto* for compatibility with Vulkan and fubuki::surface_data

    /// Returns a reference to the globals retrieved by this object from the parent display registry.
    [[nodiscard]] const auto& globals() const noexcept { return m_globals; }

    /// Swaps two objects.
    void swap(surface& other) noexcept { m_globals.swap(other.m_globals); }

    /// Swaps two objects.
    friend void swap(surface& a, surface& b) noexcept { a.swap(b); }

private:

    surface(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(views::display::wayland parent) noexcept;

    wl_surface*             m_handle  = {};
    display_global::handles m_globals = {};
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SURFACE_HPP
