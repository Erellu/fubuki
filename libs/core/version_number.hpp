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

#ifndef FUBUKI_CONFIG_VERSION_NUMBER_HPP
#define FUBUKI_CONFIG_VERSION_NUMBER_HPP

#include <cstdint>
#include <ostream>

namespace fubuki
{

/// Version number providing a valid (implicit) conversion to a Vulkan-like encoded version number.
struct version_number
{
    std::uint32_t major = 0; ///< Major version.
    std::uint32_t minor = 0; ///< Minor version.
    std::uint32_t patch = 0; ///< Patch version.

    /// Swaps two objects.
    void swap(version_number& other) noexcept
    {
        std::swap(major, other.major);
        std::swap(minor, other.minor);
        std::swap(patch, other.patch);
    }

    /// Swaps two objects.
    friend void swap(version_number& a, version_number& b) noexcept { a.swap(b); }

    /// Converts a version_info to a uint32_t encoded as a Vulkan API version.
    [[nodiscard]]
    constexpr operator std::uint32_t() const noexcept
    {
        /* Extracted from vulkan_core:
         * #define VK_MAKE_API_VERSION(variant, major, minor, patch) \
            ((((uint32_t)(variant   )) << 29) | (((uint32_t)(major)) << 22) | (((uint32_t)(minor)) << 12) | ((uint32_t)(patch)))
         */
        constexpr std::uint32_t variant = 0;

        return ((variant << 29) | (major << 22) | (minor << 12) | patch); // NOLINT(cppcoreguidelines-avoid-magic-numbers)
    }

    [[nodiscard]] friend constexpr auto operator<=>(const version_number& a, const version_number& b) noexcept
    {
        return static_cast<std::uint32_t>(a) <=> static_cast<std::uint32_t>(b);
    }

    [[nodiscard]] friend constexpr bool operator==(const version_number& a, const version_number& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const version_number& a, const version_number& b) noexcept = default;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const version_number& v)
    {
        return out << v.major << "." << v.minor << "." << v.patch;
    }
};

} // namespace fubuki

#endif // FUBUKI_FUYU_VERSION_NUMBER_HPP
