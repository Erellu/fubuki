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

#ifndef FUBUKI_CORE_DETAIL_STRING_LITERAL_HPP
#define FUBUKI_CORE_DETAIL_STRING_LITERAL_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include <string_view>

namespace fubuki
{

// Clang isn't able to infer it's safe in this context, because we have a consteval constructor checking the range
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

/**
 * @brief A container-like object for string literal.
 * Can be used to ensure a raw C-string is from a string literal.
 * Used to avoid passing string_view to out-of-lifetime strings in assertion and validation functions/macros.
 * Note: the underlying C string, available through string_literal::c_str() is null-terminated.
 * The null terminator is NOT included in string_literal::size(), as it would not be included by std::strlen.
 */
class string_literal
{
private:
    friend consteval string_literal operator""_literal(const char*, std::size_t) noexcept;
    // This constructor is not public to avoid exposing a way to pass non-null terminated strings
    consteval string_literal(const char* s, std::size_t length) noexcept : m_str{s}, m_size{length} {}
public:

    using value_type             = char;
    using const_pointer          = const char*;
    using const_reference        = const char&;
    using const_iterator         = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    using pointer          = const_pointer;
    using reference        = const_reference;
    using reverse_iterator = const_reverse_iterator;
    using iterator         = const_iterator;

    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;

    // NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
    template<std::size_t size>
    consteval string_literal(const char (&s)[size]) noexcept : string_literal{static_cast<const char*>(s), size - 1}
    {
    }

    consteval string_literal() noexcept : string_literal{""} {}
    consteval string_literal(std::nullptr_t) = delete;

    constexpr string_literal(const string_literal&) noexcept = default;
    constexpr string_literal(string_literal&&) noexcept      = default;

    constexpr string_literal& operator=(const string_literal&) noexcept = default;
    constexpr string_literal& operator=(string_literal&&) noexcept      = default;

    [[nodiscard]] constexpr const_iterator begin() const noexcept { return m_str; }
    [[nodiscard]] constexpr const_iterator cbegin() const noexcept { return m_str; }
    [[nodiscard]] constexpr const_iterator end() const noexcept { return m_str + m_size; }
    [[nodiscard]] constexpr const_iterator cend() const noexcept { return m_str + m_size; }

    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator{end()}; }
    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator{cend()}; }
    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator{begin()}; }
    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept { return const_reverse_iterator{cbegin()}; }

    [[nodiscard]] constexpr const auto& operator[](std::size_t i) const noexcept { return m_str[i]; }
    [[nodiscard]] constexpr const auto& front() const noexcept { return m_str[0]; }
    [[nodiscard]] constexpr const auto& back() const noexcept { return m_str[m_size - 1]; }
    [[nodiscard]] constexpr const auto* c_str() const noexcept { return m_str; }
    [[nodiscard]] constexpr const auto* data() const noexcept { return m_str; }
    [[nodiscard]] constexpr const auto& at(std::size_t i) const
    {
        if(i >= m_size)
        {
            throw std::out_of_range("Invalid index");
        }
        return m_str[i];
    }

    [[nodiscard]] constexpr auto size() const noexcept { return m_size; }
    [[nodiscard]] constexpr auto length() const noexcept { return m_size; }
    [[nodiscard]] constexpr bool empty() const noexcept { return m_size == 0; }
    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    [[nodiscard]] constexpr auto max_size() const noexcept { return std::string_view{}.max_size(); } // Not static to match the Standard Library API

    constexpr void swap(string_literal& other) noexcept
    {
        std::swap(m_str, other.m_str);
        std::swap(m_size, other.m_size);
    }

    [[nodiscard]] constexpr operator std::string_view() const { return {m_str, m_size}; }

    [[nodiscard]] constexpr friend auto operator<=>(const string_literal& a, const string_literal& b) noexcept
    {
        return std::string_view{a.m_str, a.m_size} <=> std::string_view{b.m_str, b.m_size};
    }

    [[nodiscard]] constexpr friend bool operator==(const string_literal& a, const string_literal& b) noexcept
    {
        if(std::addressof(a) == std::addressof(b))
        {
            return true;
        }

        return std::string_view{a.m_str, a.m_size} == std::string_view{b.m_str, b.m_size};
    }

    [[nodiscard]] constexpr friend bool operator!=(const string_literal& a, const string_literal& b) noexcept { return not(a == b); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const string_literal& str)
    {
        return out << std::string_view{str.m_str, str.m_size};
    }

private:
    const char* m_str  = nullptr;
    std::size_t m_size = 0;
    // NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
};

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

[[nodiscard]] consteval string_literal operator""_literal(const char* str, const std::size_t length) noexcept { return {str, length}; }

// clang-format off
/// Heterogeneous hash for string types.
struct heterogeneous_string_hash
{
    using is_transparent = void;

    [[nodiscard]] auto operator()(const char* str) const noexcept { return std::hash<std::string_view>{}(str); }
    [[nodiscard]] auto operator()(std::string_view str) const noexcept { return std::hash<std::string_view>{}(str); }
    [[nodiscard]] auto operator()(const std::string& txt) const noexcept { return std::hash<std::string>{}(txt); }
    [[nodiscard]] auto operator()(string_literal str) const noexcept { return std::hash<std::string_view>{}(str); }
};

/// Heterogeneous 'less' for string types.
struct heterogeneous_string_less
{
    [[nodiscard]] constexpr auto operator()(const char* a, const char* b) const noexcept { return std::string_view{a} < std::string_view{b}; }
    [[nodiscard]] constexpr auto operator()(const std::string_view a, const std::string_view b) const noexcept { return a < b; }
    [[nodiscard]] constexpr auto operator()(const std::string& a, const std::string& b) const noexcept { return std::string_view{a} < std::string_view{b};}
    [[nodiscard]] constexpr auto operator()(const string_literal a, const string_literal b)  const noexcept { return a < b;}
};

/// Heterogeneous 'greater' for string types.
struct heterogeneous_string_greater
{
    [[nodiscard]] constexpr auto operator()(const char* a, const char* b)const noexcept  { return std::string_view{a} > std::string_view{b}; }
    [[nodiscard]] constexpr auto operator()(const std::string_view a, const std::string_view b) const noexcept { return a > b; }
    [[nodiscard]] constexpr auto operator()(const std::string& a, const std::string& b) const noexcept { return std::string_view{a} > std::string_view{b};}
    [[nodiscard]] constexpr auto operator()(const string_literal a, const string_literal b) const noexcept { return a > b;}
};

/// Heterogeneous compare for string types.
struct heterogeneous_string_compare
{
    [[nodiscard]] constexpr auto operator()(const char* a, const char* b) const noexcept { return std::string_view{a} <=> std::string_view{b}; }
    [[nodiscard]] constexpr auto operator()(const std::string_view a, const std::string_view b) const noexcept { return a <=> b; }
    [[nodiscard]] constexpr auto operator()(const std::string& a, const std::string& b) const noexcept { return std::string_view{a} <=> std::string_view{b};}
    [[nodiscard]] constexpr auto operator()(const string_literal a, const string_literal b) const noexcept {return a <=> b;}
};
// clang-format on

} // namespace fubuki

namespace std
{

template<>
struct hash<fubuki::string_literal>
{
    auto operator()(fubuki::string_literal str) const noexcept { return std::hash<std::string_view>{}(str); }
};

} // namespace std
#endif // FUBUKI_CORE_DETAIL_STRING_LITERAL_HPP
