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

#ifndef FUBUKI_IO_PLATFORM_LINUX_SCOPED_MMAP_HPP
#define FUBUKI_IO_PLATFORM_LINUX_SCOPED_MMAP_HPP

#include <compare>
#include <expected>
#include <span>
#include <utility>

#include <core/config/macros.hpp>

#include "io/platform/error.hpp"

#include <sys/types.h>

namespace fubuki::io::platform::linux_bsd
{

/**
 * A RAII object that calls mmap upon construction, and munmap upon destruction.
 */
class scoped_mmap
{
    struct token
    {
    };

public:

    using range_type       = std::span<std::byte>;
    using element_type     = typename range_type::element_type;
    using value_type       = typename range_type::value_type;
    using size_type        = typename range_type::size_type;
    using difference_type  = typename range_type::difference_type;
    using pointer          = typename range_type::pointer;
    using const_pointer    = typename range_type::const_pointer;
    using reference        = typename range_type::reference;
    using const_reference  = typename range_type::const_reference;
    using iterator         = typename range_type::iterator;
    using reverse_iterator = typename range_type::reverse_iterator;

    /**
     * Constructor.
     * @throws call_exception This constructor throws an instance of call_exception if a call failed.
     * @see https://man7.org/linux/man-pages/man2/mmap.2.html
     */
    FUBUKI_IO_PLATFORM_API
    scoped_mmap(void* addr, std::size_t len, int prot, int flags, int fd, ::off_t offset = 0);

    /// Default constructor. Does not map a region.
    scoped_mmap() noexcept = default;

    scoped_mmap(const scoped_mmap&)            = delete;
    scoped_mmap& operator=(const scoped_mmap&) = delete;

    /// Move constructor.
    scoped_mmap(scoped_mmap&& other) noexcept : m_contents{std::exchange(other.m_contents, std::span<std::byte>{})} {}

    /// Move assignment operator.
    scoped_mmap& operator=(scoped_mmap&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /// Destructor. Unmaps the region.
    FUBUKI_IO_PLATFORM_API ~scoped_mmap() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @returns A valid instance of scoped_mmap, or an instance of error::api_call describing the call that failed.
     * @see https://man7.org/linux/man-pages/man2/mmap.2.html
     */
    [[nodiscard]] FUBUKI_IO_PLATFORM_API static std::expected<scoped_mmap, error::api_call>
    make(void* addr, std::size_t len, int prot, int flags, int fd, ::off_t offset = 0) noexcept;

    [[nodiscard]] iterator         begin() const noexcept { return m_contents.begin(); }
    [[nodiscard]] iterator         end() const noexcept { return m_contents.end(); }
    [[nodiscard]] reverse_iterator rbegin() const noexcept { return m_contents.rbegin(); }
    [[nodiscard]] reverse_iterator rend() const noexcept { return m_contents.rend(); }

    [[nodiscard]] reference     front() const { return m_contents.front(); }
    [[nodiscard]] reference     back() const { return m_contents.back(); }
    [[nodiscard]] reference     operator[](size_type idx) const { return m_contents[idx]; }
    [[nodiscard]] const_pointer data() const noexcept { return m_contents.data(); }
    [[nodiscard]] pointer       data() noexcept { return m_contents.data(); }

    [[nodiscard]] size_type size() const noexcept { return m_contents.size(); }
    [[nodiscard]] size_type size_bytes() const noexcept { return m_contents.size_bytes(); }
    [[nodiscard]] bool      empty() const noexcept { return m_contents.empty(); }

    template<std::size_t count>
    [[nodiscard]] std::span<element_type, count> first() const noexcept
    {
        return m_contents.first<count>();
    }

    [[nodiscard]] std::span<element_type, std::dynamic_extent> first(size_type count) const noexcept { return m_contents.first(count); }
    template<std::size_t count>
    [[nodiscard]] std::span<element_type, count> last() const noexcept
    {
        return m_contents.last<count>();
    }

    [[nodiscard]] std::span<element_type, std::dynamic_extent> last(size_type count) const noexcept { return m_contents.last(count); }

    template<std::size_t offset, std::size_t count = std::dynamic_extent>
    [[nodiscard]] auto subspan() const
    {
        return m_contents.subspan<offset, count>();
    }
    [[nodiscard]] std::span<element_type, std::dynamic_extent> subspan(size_type offset, size_type count = std::dynamic_extent) const
    {
        return m_contents.subspan(offset, count);
    }

    [[nodiscard]] operator std::span<std::byte>() noexcept { return m_contents; }
    [[nodiscard]] operator std::span<const std::byte>() const noexcept { return std::as_bytes(m_contents); }
    [[nodiscard]] std::span<std::byte>       as_bytes() noexcept { return m_contents; }
    [[nodiscard]] std::span<const std::byte> as_bytes() const noexcept { return std::as_bytes(m_contents); }

    [[nodiscard]] friend bool operator==(const scoped_mmap& a, const scoped_mmap& b) noexcept
    {
        // Prefer comparison of the actual regions (in terms of address) rather than the contents.
        // This is most likely the intent of the caller
        return (a.m_contents.data() == b.m_contents.data()) and (a.m_contents.size() == b.m_contents.size());
    }

    [[nodiscard]] friend bool operator!=(const scoped_mmap& a, const scoped_mmap& b) noexcept { return not(a == b); }

    [[nodiscard]] friend auto operator<=>(const scoped_mmap& a, const scoped_mmap& b) noexcept
    {
        // Same as operator==: prefer comparison of the actual regions (in terms of address) rather than the contents.
        if(const std::strong_ordering cmp = a.m_contents.data() <=> b.m_contents.data(); cmp != std::strong_ordering::equivalent)
        {
            return cmp;
        }

        return a.m_contents.size() <=> b.m_contents.size();
    }

    void swap(scoped_mmap& other) noexcept { std::swap(m_contents, other.m_contents); }

    friend void swap(scoped_mmap& a, scoped_mmap& b) noexcept { a.swap(b); }

private:

    scoped_mmap(token, std::byte* begin, std::size_t size) noexcept : m_contents{begin, size} {}

    std::span<std::byte> m_contents = {};
};

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_SCOPED_MMAP_HPP
