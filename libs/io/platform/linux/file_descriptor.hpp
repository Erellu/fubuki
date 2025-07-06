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

#ifndef FUBUKI_IO_PLATFORM_LINUX_FILE_DESCRIPTOR_HPP
#define FUBUKI_IO_PLATFORM_LINUX_FILE_DESCRIPTOR_HPP

#include <expected>
#include <optional>
#include <string_view>
#include <utility>

#include <core/assertion.hpp>

#include "io/platform/error.hpp"

namespace fubuki::io::platform::linux_bsd
{

/**
 * A RAII object wrapping a file descriptor (fd). Closes the file descriptor upon destruction.
 */
class file_descriptor
{

public:

    /// Hints for make_anonymous
    enum class anonymous_hint
    {
        memfd,    ///< Prefer memfd_create. If not available or if the call failed, fallback to the arguments provided to make_anonymous.
        provided, ///< Directly use the arguments provided to make_anonymous.
    };

    /// File descriptor handle.
    struct handle
    {
        int value = {};

        [[nodiscard]] friend constexpr bool operator==(const handle& a, const handle& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const handle& a, const handle& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const handle& a, const handle& b) noexcept = default;
    };

    /**
     * Constructor.
     * @param h File descriptor handle. This handle is closed when the object goes out of scope.
     * @pre h must be a valid file descriptor handle.
     */
    explicit file_descriptor(handle h) noexcept : m_handle{h} {}

    /// Constructor.
    file_descriptor() noexcept = default;

    file_descriptor(const file_descriptor&)            = delete;
    file_descriptor& operator=(const file_descriptor&) = delete;

    /// Move constructor.
    file_descriptor(file_descriptor&& other) noexcept : m_handle{std::exchange(other.m_handle, std::nullopt)} {}

    /// Move assignment operator.
    file_descriptor& operator=(file_descriptor&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /// Destructor. Closes the underlying file descriptor handle.
    FUBUKI_IO_PLATFORM_API ~file_descriptor() noexcept;

    /// Returns the handle this object currently owns.
    /// If no file descriptor is owned by this object (after std::move, for example), the behaviour is undefined.
    [[nodiscard]] handle get() const noexcept
    {
        fubuki_assert(m_handle.has_value(), "This object does not refer to a valid file descriptor. Did it got std::moved?");
        return *m_handle; // NOLINT(bugprone-unchecked-optional-access)
    }

    /// Returns the handle this object currently owns, or the fallback handle specified as argument.
    [[nodiscard]] handle get_or(handle h) const noexcept { return m_handle.value_or(h); }

    /**
     * Creates an anonymous file descriptor.
     * @param size_bytes The size of the file, in bytes.
     * @param fallback_path The path to the fallback file created when `mem_fd` fails or is not available.
     * @param fallback_name_template The name template for the file, when memfd_create failed or when the hint is anonymous_hint::provided. If the
     * name does not end by "-XXXXXX", this is appended.
     * @param hint Hint for arguments usage. @see fubuki::io::platform::linux::anonymous_hint
     * @returns A file descriptor to the anonymous file, or an instance of error::api_call that describes the call that failed.
     * @pre size_bytes > static_cast<std::size_t>(std::numeric_limits<::off_t>::max())
     */
    [[nodiscard]] FUBUKI_IO_PLATFORM_API static std::expected<file_descriptor, error::api_call> make_anonymous(
        std::size_t size_bytes, std::string_view fallback_path, std::string_view fallback_name_template, anonymous_hint hint = {}) noexcept;

    /// Swaps two objects.
    void swap(file_descriptor& other) noexcept { m_handle.swap(other.m_handle); }

    /// Swaps two objects.
    friend void swap(file_descriptor& a, file_descriptor& b) noexcept { a.swap(b); }

private:

    /// Underlying handle.
    std::optional<handle> m_handle = {};
};

} // namespace fubuki::io::platform::linux_bsd

#endif // FUBUKI_IO_PLATFORM_LINUX_FILE_DESCRIPTOR_HPP
