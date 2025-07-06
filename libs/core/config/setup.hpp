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

#ifndef FUBUKI_CORE_CONFIG_SETUP_HPP
#define FUBUKI_CORE_CONFIG_SETUP_HPP

#include <ostream>

#include "core/config/macros.hpp"

namespace fubuki
{

/// A structure specifying build configuration.
struct configuration
{
    enum class compiler
    {
        clang,
        gcc,
        msvc,
        unknown
    };

    enum class build_type
    {
        debug,
        release,
        release_with_debug_info,
        min_size_release,
        other
    };

    enum class platform
    {
        win32,
        linux_bsd,
        unknown
    };

    enum class window_system
    {
        wayland,
        win32,
        xlib,
        unknown
    };

    compiler   compile = {}; ///< The compiler used.
    build_type build   = {}; ///< The build mode.
    platform   os      = {}; ///< The platform the programme is running on.

    friend constexpr bool operator==(const configuration&, const configuration&) noexcept  = default;
    friend constexpr bool operator!=(const configuration&, const configuration&) noexcept  = default;
    friend constexpr auto operator<=>(const configuration&, const configuration&) noexcept = default;

    /// Swaps two objects.
    void swap(configuration& other) noexcept
    {
        std::swap(compile, other.compile);
        std::swap(build, other.build);
        std::swap(os, other.os);
    }

    /// Swaps two objects.
    friend void swap(configuration& a, configuration& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type> >
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, compiler c)
    {
        using enum configuration::compiler;

        switch(c)
        {
            case clang: return out << "clang";
            case gcc  : return out << "gcc";
            case msvc : return out << "msvc";

            default:
            case unknown: return out << "unknown";
        }
    }

    template<typename char_type, typename traits = std::char_traits<char_type> >
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, build_type b)
    {
        using enum configuration::build_type;

        switch(b)
        {
            case debug                  : return out << "debug";
            case release                : return out << "release";
            case release_with_debug_info: return out << "release_with_debug_info";
            case min_size_release       : return out << "min_size_release";

            default:
            case other: return out << "other";
        }
    }

    template<typename char_type, typename traits = std::char_traits<char_type> >
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, platform p)
    {
        using enum configuration::platform;

        switch(p)
        {
            case win32    : return out << "win32";
            case linux_bsd: return out << "linux_bsd";

            default:
            case unknown: return out << "unknown";
        }
    }

    template<typename char_type, typename traits = std::char_traits<char_type> >
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, window_system s)
    {
        using enum configuration::window_system;

        switch(s)
        {
            case wayland: return out << "wayland";
            case win32  : return out << "win32";
            case xlib   : return out << "x11";

            default:
            case unknown: return out << "<nknown";
        }
    }

    template<typename char_type, typename traits = std::char_traits<char_type> >
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const configuration& config)
    {
        return out << "configuration: {"
                   << "compiler: " << config.compile << ", "
                   << "build: " << config.build << ", "
                   << "os: " << config.os << "}";
    }

/// Indicates the window system in use.
/// On Windows, this function always retruns configuration::window_system::win32.
/// On Linux, the result is based on environnement variables.
#if defined(_WIN32)
    FUBUKI_TRUE_PURE
#endif
    [[nodiscard]] FUBUKI_CORE_API static configuration::window_system current_window_system() noexcept;

    /// Indicates the current configuration.
    [[nodiscard]]
    static constexpr configuration current() noexcept
    {
#if defined(__clang__)
        constexpr auto compiler = configuration::compiler::clang;
#elif defined(__GNUC__)
        constexpr auto compiler = configuration::compiler::gcc;
#elif defined(_MSC_VER)
        constexpr auto compiler = configuration::compiler::msvc;
#else
        constexpr auto compiler = configuration::compiler::unknown;
#endif

#if defined(FUBUKI_DEBUG_BUILD)
        constexpr auto build_type = configuration::build_type::debug;
#elif defined(FUBUKI_RELEASE_BUILD)
        constexpr auto build_type = configuration::build_type::release;
#elif defined(FUBUKI_RELEASE_WITH_DEBUG_INFO_BUILD)
        constexpr auto build_type = configuration::build_type::release_with_debug_info;
#elif defined(FUBUKI_MIN_SIZE_RELEASE_BUILD)
        constexpr auto build_type = configuration::build_type::min_size_release;
#else
        constexpr auto build_type = configuration::build_type::other;
#endif

#if defined(_WIN32)
        constexpr auto os = configuration::platform::win32;
#elif defined(__unix__)
        constexpr auto os = configuration::platform::linux_bsd;
#else
        constexpr auto os = configuration::platform::unknown;
#endif

        return {compiler, build_type, os};
    }
};

/// Returns the configuration in which Fubuki has been (or is being) built.
[[nodiscard]] FUBUKI_TRUE_PURE FUBUKI_CORE_API const configuration& build_configuration() noexcept;

} // namespace fubuki

#endif // FUBUKI_CORE_CONFIG_SETUP_HPP
