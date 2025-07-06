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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SHM_POOL_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SHM_POOL_HPP

#include <cstddef>
#include <optional>
#include <utility>

#include "io/platform/error.hpp"
#include "io/platform/linux/file_descriptor.hpp"
#include "io/platform/linux/scoped_mmap.hpp"
#include "io/platform/linux/wayland/display.hpp"

extern "C"
{

struct wl_shm_pool;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland
{

/**
 * A shared memory pool.
 */
class shm_pool
{
    struct token
    {
    };

public:

    /// Information about this pool.
    struct information
    {
        /// The format supported by Fubuki.
        static constexpr auto format = 0; // WL_SHM_FORMAT_ARGB8888

        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
        std::size_t width  = 1920; ///< The width of the pool. This value is adjusted to be at least 1.
        std::size_t height = 1080; ///< The height of the pool. This value is adjusted to be at least 1.
        std::size_t layers = 2;    ///< Number of layers (images) this pool reserves memory for. This value is adjusted to be at least 1.
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
    };

    static constexpr std::size_t format_stride = 4; // 32-bit, 4 bytes: the only format supported by Fubuki is WL_SHM_FORMAT_ARGB8888

    /**
     * Constructor.
     * @param parent Parent display.
     * @param i Informatio about this pool.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    shm_pool(platform::views::display::wayland parent, information i)
        : m_globals{globals_of(fubuki::validate_by::throw_call_exception, parent).get().handle},
          m_info{i}
    {
        if(const auto error = create())
        {
            throw call_exception{*error};
        }
    }

    shm_pool(const shm_pool&)            = delete;
    shm_pool& operator=(const shm_pool&) = delete;

    /// Move constructor.
    shm_pool(shm_pool&& other) noexcept
        : m_fd{std::move(other.m_fd)},
          m_memory{std::move(other.m_memory)},
          m_globals{other.m_globals},
          m_info{std::exchange(other.m_info, information{})},
          m_handle{std::exchange(other.m_handle, nullptr)}
    {
    }

    /// Move assignment operator.
    shm_pool& operator=(shm_pool&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /// Destroys the underlying pool, if it not nullptr.
    FUBUKI_IO_PLATFORM_API ~shm_pool() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent display.
     * @param i Information about this pool.
     * @returns The resulting object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<shm_pool, error::api_call> make(platform::views::display::wayland parent, information i) noexcept
    {
        auto globals = globals_of(parent);

        if(not globals)
        {
            return std::unexpected{globals.error()};
        }

        auto result = shm_pool{token{}, globals->get().handle, i};

        if(const auto error = result.create())
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /// Returns the size of this pool, in bytes.
    [[nodiscard]] auto size_bytes() const noexcept { return m_info.width * m_info.height * format_stride * m_info.layers; }

    /// Returns the information known about this object.
    [[nodiscard]] FUBUKI_SEMI_PURE const information& info() const noexcept { return m_info; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Returns a reference to the memory chunk owned by this pool.
    [[nodiscard]] const auto& memory() const noexcept { return m_memory; }

    /// Returns a reference to the globals retrieved by this object from the parent display registry.
    [[nodiscard]] const auto& globals() const noexcept { return m_globals; }

    /// Swaps two objects.
    void swap(shm_pool& other) noexcept
    {
        m_fd.swap(other.m_fd);
        m_memory.swap(other.m_memory);
        m_globals.swap(other.m_globals);
        std::swap(m_info, other.m_info);
        std::swap(m_handle, other.m_handle);
    }

    /// Swaps two objects.
    friend void swap(shm_pool& a, shm_pool& b) noexcept { a.swap(b); }

private:

    shm_pool(token, display::global::handles g, information i) noexcept : m_globals{g}, m_info{i}
    {
        m_info.width  = std::max(std::size_t{1}, m_info.width);
        m_info.height = std::max(std::size_t{1}, m_info.width);
        m_info.layers = std::max(std::size_t{1}, m_info.layers);
    }

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create() noexcept;

    file_descriptor          m_fd      = {};      ///< File descriptor used to describe the pooL.
    scoped_mmap              m_memory  = {};      ///< Chunk of memory, mapped to the file descriptor.
    display::global::handles m_globals = {};      ///< Shared state of the object.
    information              m_info    = {};      ///< Information about the pool.
    wl_shm_pool*             m_handle  = nullptr; ///< Underlying Wayland handle.
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SHM_POOL_HPP
