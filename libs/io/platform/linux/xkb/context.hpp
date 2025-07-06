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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XKB_CONTEXT_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XKB_CONTEXT_HPP

#include <utility>

#include <core/config/macros.hpp>

#include "io/platform/error.hpp"

extern "C"
{

struct xkb_context;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::xkb
{

/**
 * A RAII wrapper for a `xkb_context`.
 * @see https://xkbcommon.org/doc/current/structxkb__context.html
 * @see https://xkbcommon.org/doc/current/group__context.html
 */
class context
{
    struct token
    {
    };

public:

    /**
     * Context creation flags.
     * @see xkb_context_flags
     */
    enum class flags
    {
        none                 = 0,        ///< Do not apply any context flags.
        no_default_include   = (1 << 0), ///< Create this context with an empty include path.
        no_environment_names = (1 << 1), ///< Don't take RMLVO names from the environment.
        /**
         * Disable the use of secure_getenv for this context, so that privileged
         * processes can use environment variables. Client uses at their own risk.
         *          * @since 1.5.0
         */
        no_secure_getenv = (1 << 2)
    };

    /**
     * Constructor.
     * @param f (optional) Context flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     */
    context(flags f = flags::none)
    {
        if(const auto error = create(f))
        {
            throw call_exception{*error};
        }
    }

    context(const context&)            = delete;
    context& operator=(const context&) = delete;

    /// Move constructor.
    context(context&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)} {}

    /// Move assignment operator.
    context& operator=(context&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /// Destructor. Destroys the underlying handle if it is not nullptr.
    /// @note Calls `xkb_context_unref`.
    ///  If client code called `xkb_context_ref` on the handle, it may not be freed.
    FUBUKI_IO_PLATFORM_API ~context() noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param f (optional) Context flags.
     * @returns The resulting object, or an instance of error::api_call describing the call that failed.
     */
    [[nodiscard]] static std::expected<context, error::api_call> make(flags f = flags::none) noexcept
    {
        context result{token{}};

        if(const auto error = result.create(f))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /// Returns the underlying XKB handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying XKB handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Swaps two objects.
    void swap(context& other) noexcept { std::swap(m_handle, other.m_handle); }

    /// Swaps two objects.
    friend void swap(context& a, context& b) noexcept { a.swap(b); }

private:

    context(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info> create(flags f) noexcept;

    xkb_context* m_handle = nullptr;
};

} // namespace fubuki::io::platform::linux_bsd::xkb

#endif // FUBUKI_IO_PLATFORM_LINUX_XKB_CONTEXT_HPP
