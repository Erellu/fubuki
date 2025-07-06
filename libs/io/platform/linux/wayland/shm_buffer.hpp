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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SHM_BUFFER_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SHM_BUFFER_HPP

#include <cstddef>
#include <optional>

#include "io/platform/error.hpp"
#include "io/platform/linux/wayland/shm_pool.hpp"

extern "C"
{

struct wl_buffer;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::wayland
{

/**
 * A shared memory buffer, allocated from a pool.
 */
class shm_buffer
{
    struct token
    {
    };

public:

    /// Information required to construct an instance of this object.
    struct information
    {
        static constexpr auto format = shm_pool::information::format;

        /// Index of the image of the pool this buffer represents.
        std::size_t index = 0;

        /// Width of the buffer.
        ///  If not provided, uses the weight specified in the parent pool information.
        /// If provided, this value is adjusted to be at least 1.
        std::optional<std::size_t> width = {};

        /// Height of the buffer.
        /// If not provided, uses the height specified in the parent pool information.
        /// If provided, this value is adjusted to be at least 1.
        std::optional<std::size_t> height = {};
    };

    static constexpr std::size_t format_stride = shm_pool::format_stride;

    /**
     * Constructor.
     * @param parent Parent shared memory pool.
     * @param i Information about the allocation.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    shm_buffer(shm_pool& parent, information i) : shm_buffer{token{}, parent, i}
    {
        if(const auto error = create(parent))
        {
            throw call_exception{*error};
        }
    }

    shm_buffer(const shm_buffer&)            = delete;
    shm_buffer& operator=(const shm_buffer&) = delete;

    /// Move constructor.
    shm_buffer(shm_buffer&& other) noexcept
        : m_handle{std::exchange(other.m_handle, nullptr)},
          m_info{std::exchange(other.m_info, information{})},
          m_memory{std::exchange(other.m_memory, std::span<std::byte>{})}
    {
    }

    /// Move assignment operator.
    shm_buffer& operator=(shm_buffer&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /**
     * Destructor. Destroys the underlying handle if it is not nullptr.
     */
    FUBUKI_IO_PLATFORM_API
    ~shm_buffer() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param parent Parent shared memory pool.
     * @param i Information about the allocation.
     * @returns The object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<shm_buffer, error::api_call> make(shm_pool& parent, information i) noexcept
    {
        shm_buffer result = {token{}, parent, i};

        if(const auto error = result.create(parent))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /// Returns the information known about this object.
    [[nodiscard]] const auto& info() const noexcept { return m_info; }

    /// Returns the image index this buffer uses.
    [[nodiscard]] auto index() const noexcept { return m_info.index; }

    /// Returns the width of the buffer.
    [[nodiscard]] auto width() const noexcept { return m_info.width.value_or(1); }

    /// Returns the height of the buffer.
    [[nodiscard]] auto height() const noexcept { return m_info.height.value_or(1); }

    /// Returns the offset, in bytes, at which this buffer starts in the memory owned by the parent pool.
    [[nodiscard]] auto offset() const noexcept { return height() * width() * index() * format_stride; }

    /// Returns the size, in bytes, of this buffer.
    [[nodiscard]] auto size_bytes() const noexcept { return width() * height() * format_stride; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying Wayland handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Returns the underlying memory chunck as mutable storage.
    [[nodiscard]] std::span<std::byte> memory() noexcept { return m_memory; }

    /// Returns the underlying memory chunck as unmutable storage.
    [[nodiscard]] std::span<const std::byte> memory() const noexcept { return {m_memory}; }

    /// Swaps two objects.
    void swap(shm_buffer& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_info, other.m_info);
        std::swap(m_memory, other.m_memory);
    }

    /// Swaps two objects.
    friend void swap(shm_buffer& a, shm_buffer& b) noexcept { a.swap(b); }

private:

    shm_buffer(token, shm_pool& parent, information i) noexcept : m_info{i}
    {
        m_info.index = std::min(m_info.index, parent.info().layers);

        if(m_info.width.has_value())
        {
            m_info.width = std::max(std::size_t{1}, *m_info.width);
        }
        else
        {
            m_info.width = parent.info().width;
        }

        if(m_info.height.has_value())
        {
            m_info.height = std::max(std::size_t{1}, *m_info.height);
        }
        else
        {
            m_info.height = parent.info().height;
        }
    }

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(shm_pool& parent) noexcept;

    wl_buffer*           m_handle = nullptr; ///< Underlying Wayland handle.
    information          m_info   = {};      ///< Information known about this object.
    std::span<std::byte> m_memory = {};      ///< Underlying memory chunck.
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_SHM_BUFFER_HPP
