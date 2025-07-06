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

#ifndef FUBUKI_IO_PLATFORM_LINUX_XKB_KEYMAP_HPP
#define FUBUKI_IO_PLATFORM_LINUX_XKB_KEYMAP_HPP

#include <cstddef>
#include <span>
#include <string_view>
#include <utility>

#include <core/config/macros.hpp>

#include "io/platform/error.hpp"

extern "C"
{

struct xkb_context;
struct xkb_keymap;

} // extern "C"

namespace fubuki::io::platform::linux_bsd::xkb
{

/**
 * A RAII object for `xkb_keymap`.
 * @see https://xkbcommon.org/doc/current/group__keymap.html
 */
class keymap
{
    struct token
    {
    };

public:

    struct modifiers_index
    {
        std::uint32_t control   = {};
        std::uint32_t alt       = {};
        std::uint32_t shift     = {};
        std::uint32_t super     = {};
        std::uint32_t caps_lock = {};
        std::uint32_t numlock   = {};

        [[nodiscard]] friend constexpr bool operator==(const modifiers_index& a, const modifiers_index& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const modifiers_index& a, const modifiers_index& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const modifiers_index& a, const modifiers_index& b) noexcept = default;

        /// Swaps two objects.
        void swap(modifiers_index& other) noexcept
        {
            std::swap(control, other.control);
            std::swap(alt, other.alt);
            std::swap(shift, other.shift);
            std::swap(super, other.super);
            std::swap(caps_lock, other.caps_lock);
            std::swap(numlock, other.numlock);
        }

        /// Swaps two objects.
        friend void swap(modifiers_index& a, modifiers_index& b) noexcept { a.swap(b); }
    };

    /**
     * Possible keymap formats
     * @see xkb_keymap_format
     * @see https://xkbcommon.org/doc/current/group__keymap.html
     */
    enum class format
    {
        none = 0,
        v1   = 1,
    };

    /**
     * Possible compile flags.
     * @see xkb_keymap_compile_flags
     */
    enum class compile_flags
    {
        none,
    };

    /// @see https://xkbcommon.org/doc/current/structxkb__rule__names.html
    struct rule_names
    {
        const char* rules   = "";
        const char* model   = "";
        const char* layout  = "";
        const char* variant = "";
        const char* options = "";

        [[nodiscard]] friend constexpr bool operator==(const rule_names& a, const rule_names& b) noexcept
        {
            return (std::string_view{a.rules} == std::string_view{b.rules}) and (std::string_view{a.model} == std::string_view{b.model})
                and (std::string_view{a.layout} == std::string_view{b.layout}) and (std::string_view{a.variant} == std::string_view{b.variant})
                and (std::string_view{a.options} == std::string_view{b.options});
        }
        [[nodiscard]] friend constexpr bool operator!=(const rule_names& a, const rule_names& b) noexcept { return not(a == b); }

        [[nodiscard]] friend constexpr auto operator<=>(const rule_names& a, const rule_names& b) noexcept
        {
            if(const std::strong_ordering cmp = (std::string_view{a.rules} <=> std::string_view{b.rules}); cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            if(const std::strong_ordering cmp = (std::string_view{a.model} <=> std::string_view{b.model}); cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            if(const std::strong_ordering cmp = (std::string_view{a.layout} <=> std::string_view{b.layout}); cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            if(const std::strong_ordering cmp = (std::string_view{a.variant} <=> std::string_view{b.variant});
               cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            if(const std::strong_ordering cmp = (std::string_view{a.options} <=> std::string_view{b.options});
               cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            return std::strong_ordering::equivalent;
        }

        /// Swaps two objects.
        void swap(rule_names& other) noexcept
        {
            std::swap(rules, other.rules);
            std::swap(model, other.model);
            std::swap(layout, other.layout);
            std::swap(variant, other.variant);
            std::swap(options, other.options);
        }

        /// Swaps two objects.
        friend void swap(rule_names& a, rule_names& b) noexcept { a.swap(b); }
    };

    /**
     * Creates a keymap from a null-terminated string.
     * @param parent The parent context.
     * @param c_str A null-terminated string containing the keymap.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_string
     * @see https://xkbcommon.org/doc/current/group__keymap.html#ga8d47182d367aa041b380fb49a61660bd
     */
    keymap(xkb_context* parent, const char* c_str, format f = format::v1, compile_flags compile = compile_flags::none)
    {
        if(const auto error = create(parent, c_str, f, compile))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Creates a keymap from a `char` buffer (not necessarily null-terminated).
     * @param parent The parent context.
     * @param str A string containing the keymap, not necessarily null-terminated.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_buffer
     * @see https://xkbcommon.org/doc/current/group__keymap.html#gaa6e1cc388df956a7f4f99214a1077186
     */
    keymap(xkb_context* parent, std::string_view str, format f = format::v1, compile_flags compile = compile_flags::none)
    {
        if(const auto error = create(parent, str, f, compile))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Creates a keymap from a `char` buffer (not necessarily null-terminated).
     * @param parent The parent context.
     * @param buffer A buffer containing the keymap, necessarily null-terminated.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_buffer
     * @see https://xkbcommon.org/doc/current/group__keymap.html#gaa6e1cc388df956a7f4f99214a1077186
     */
    keymap(xkb_context* parent, std::span<const char> buffer, format f = format::v1, compile_flags compile = compile_flags::none)
    {
        if(const auto error = create(parent, std::as_bytes(buffer), f, compile))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Creates a keymap from a `char` buffer (not necessarily null-terminated).
     * @param parent The parent context.
     * @param buffer A buffer containing the keymap, necessarily null-terminated.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_buffer
     * @see https://xkbcommon.org/doc/current/group__keymap.html#gaa6e1cc388df956a7f4f99214a1077186
     */
    keymap(xkb_context* parent, std::span<const std::byte> buffer, format f = format::v1, compile_flags compile = compile_flags::none)
    {
        if(const auto error = create(parent, buffer, f, compile))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Creates a keymap from a set of rules, model, layouts, variants and options names (RMLVO).
     * @param parent The parent context.
     * @param names The RMLVO names to use.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_names
     * @see https://xkbcommon.org/doc/current/group__keymap.html#ga3a2d973b77325337f043a37edf4cc4e1
     */
    keymap(xkb_context* parent, const rule_names& names, compile_flags compile = compile_flags::none)
    {
        if(const auto error = create(parent, names, compile))
        {
            throw call_exception{*error};
        }
    }

    /**
     * Creates a keymap from a null-terminated string.
     * @param parent The parent context.
     * @param c_str A null-terminated string containing the keymap.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @returns The resulting object, or an instance of any_call_info describing the call that failed.
     * @see xkb_keymap_new_from_string
     * @see https://xkbcommon.org/doc/current/group__keymap.html#ga8d47182d367aa041b380fb49a61660bd
     */
    [[nodiscard]] static std::expected<keymap, error::api_call>
    make(xkb_context* parent, const char* c_str, format f = format::v1, compile_flags compile = compile_flags::none) noexcept
    {
        keymap result{token{}};

        if(const auto error = result.create(parent, c_str, f, compile))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /**
     * Creates a keymap from a `char` buffer (not necessarily null-terminated).
     * @param parent The parent context.
     * @param str A string buffer containing the keymap, necessarily null-terminated.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_buffer
     * @see https://xkbcommon.org/doc/current/group__keymap.html#gaa6e1cc388df956a7f4f99214a1077186
     */
    [[nodiscard]] static std::expected<keymap, error::api_call>
    make(xkb_context* parent, std::string_view str, format f = format::v1, compile_flags compile = compile_flags::none)
    {
        keymap result{token{}};

        if(const auto error = result.create(parent, str, f, compile))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /**
     * Creates a keymap from a `char` buffer (not necessarily null-terminated).
     * @param parent The parent context.
     * @param buffer A buffer containing the keymap, necessarily null-terminated.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_buffer
     * @see https://xkbcommon.org/doc/current/group__keymap.html#gaa6e1cc388df956a7f4f99214a1077186
     */
    [[nodiscard]] static std::expected<keymap, error::api_call>
    make(xkb_context* parent, std::span<const char> buffer, format f = format::v1, compile_flags compile = compile_flags::none)
    {
        keymap result{token{}};

        if(const auto error = result.create(parent, std::as_bytes(buffer), f, compile))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /**
     * Creates a keymap from a `char` buffer (not necessarily null-terminated).
     * @param parent The parent context.
     * @param buffer A buffer containing the keymap, necessarily null-terminated.
     * @param f (optional) The format specifier for the contents of the buffer.
     * @param compile (optional) The compile flags.
     * @throws call_exception This constructor throws an instance of fubuki::io::platform::call_exception if a call failed.
     * @see xkb_keymap_new_from_buffer
     * @see https://xkbcommon.org/doc/current/group__keymap.html#gaa6e1cc388df956a7f4f99214a1077186
     */
    [[nodiscard]] static std::expected<keymap, error::api_call>
    make(xkb_context* parent, std::span<const std::byte> buffer, format f = format::v1, compile_flags compile = compile_flags::none)
    {
        keymap result{token{}};

        if(const auto error = result.create(parent, buffer, f, compile))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    /**
     * Creates a keymap from a set of rules, model, layouts, variants and options names (RMLVO).
     * @param parent The parent context.
     * @param names The RMLVO names to use.
     * @param compile (optional) The compile flags.
     *@returns The resulting object, or an instance of any_call_info describing the call that failed.
     * @see xkb_keymap_new_from_names
     * @see https://xkbcommon.org/doc/current/group__keymap.html#ga3a2d973b77325337f043a37edf4cc4e1
     */
    [[nodiscard]] static std::expected<keymap, error::api_call>
    make(xkb_context* parent, const rule_names& names, compile_flags compile = compile_flags::none) noexcept
    {
        keymap result{token{}};

        if(const auto error = result.create(parent, names, compile))
        {
            return std::unexpected{*error};
        }

        return result;
    }

    keymap(const keymap&)            = delete;
    keymap& operator=(const keymap&) = delete;

    /// Move constructor.
    keymap(keymap&& other) noexcept : m_handle{std::exchange(other.m_handle, nullptr)}, m_indices{std::exchange(other.m_indices, {})} {}

    /// Move assignment operator.
    keymap& operator=(keymap&& other) noexcept
    {
        swap(other);
        return *this;
    }

    /// Destructor. Destroys the underlying handle if it is not nullptr.
    /// @note Calls `xkb_keymap_unref`.
    ///  If client code called `xkb_keymap_ref` on the handle, it may not be freed.
    FUBUKI_IO_PLATFORM_API
    ~keymap() noexcept;

    /// Returns the underlying XKB handle.
    [[nodiscard]] auto* handle() noexcept { return m_handle; }

    /// Returns the underlying XKB handle.
    [[nodiscard]] const auto* handle() const noexcept { return m_handle; }

    /// Returns the indeices of the modifiers retrieved through `xkb_keymap_mod_get_index`.
    [[nodiscard]] const auto& modifiers_indices() const noexcept { return m_indices; }

    /// Swaps two objects.
    void swap(keymap& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        m_indices.swap(other.m_indices);
    }

    /// Swaps two objects.
    friend void swap(keymap& a, keymap& b) noexcept { a.swap(b); }

    /// Converts a keymap to a std::string.
    /// @see https://xkbcommon.org/doc/current/group__keymap.html#gad41304fe0b54e1cc5739b12a4796396b
    /// @returns The string, or an instance of any_call_info indicating the underlying call to `xkb_keymap_get_as_string` returned `nullptr`.
    FUBUKI_IO_PLATFORM_API
    friend std::expected<std::string, any_call_info> to_string(const keymap&);

private:

    keymap(token) noexcept {}

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info>
    create(xkb_context* parent, const char* c_str, format f = format::v1, compile_flags compile = compile_flags::none) noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info>
    create(xkb_context* parent, std::string_view str, format f = format::v1, compile_flags compile = compile_flags::none) noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info>
                                         create(xkb_context* parent, std::span<const std::byte> buffer, format f, compile_flags compile) noexcept;

    [[nodiscard]] FUBUKI_IO_PLATFORM_API std::optional<any_call_info>
                                         create(xkb_context* parent, const rule_names& names, compile_flags compile = compile_flags::none) noexcept;

    xkb_keymap*     m_handle  = nullptr;
    modifiers_index m_indices = {};
};

} // namespace fubuki::io::platform::linux_bsd::xkb

#endif // FUBUKI_IO_PLATFORM_LINUX_XKB_KEYMAP_HPP
