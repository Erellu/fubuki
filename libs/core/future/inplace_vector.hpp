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

#ifndef FUBUKI_CORE_FUTURE_INPLACE_VECTOR_HPP
#define FUBUKI_CORE_FUTURE_INPLACE_VECTOR_HPP

#include <algorithm>
#include <array>
#include <compare>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

#include "core/assertion.hpp"

namespace fubuki
{

namespace future
{

#ifdef __cpp_lib_inplace_vector
template<typename T, std::size_t N>
using inplace_vector = std::inplace_vector<T, N>;
#else

/**
 * @brief Implementation details of fubuki::inplace_vector.
 * Based on the reference implementation (available at https://godbolt.org/z/5P78aG5xE) by Gonzalo Brito Gadeschi,
 * licensed under the MIT license.
 */
namespace detail::inplace_vector
{

/// Types of storage used for implementing inplace_vector
namespace storage
{

template<typename T>
struct empty
{
    static constexpr std::size_t capacity = 0;

    using size_type       = std::size_t;
    using underlying_type = std::monostate;

    [[nodiscard]] static constexpr T*        data() noexcept { return nullptr; }
    [[nodiscard]] static constexpr size_type size() noexcept { return 0; }
    constexpr void unsafe_set_size([[maybe_unused]] std::size_t new_size) noexcept { fubuki_assert(new_size < capacity, "Invalid size"); }

    [[nodiscard]] constexpr T* operator[]([[maybe_unused]] std::size_t i) noexcept
    {
        fubuki_assert(i == 0, "Invalid index");
        return nullptr;
    }

    [[nodiscard]] constexpr const T* operator[]([[maybe_unused]] std::size_t i) const noexcept
    {
        fubuki_assert(i == 0, "Invalid index");
        return nullptr;
    }
};

template<typename T, std::size_t count>
requires(not std::is_array_v<T>)
struct aligned_bytes
{
    static constexpr auto capacity = count;

    using size_type       = std::size_t;
    using underlying_type = std::array<std::byte, sizeof(T) * count>;

    alignas(T) underlying_type contents = {};

    // Expected to be used in addition as a target to placement-new
    [[nodiscard]] constexpr T*        data() noexcept { return std::launder(std::bit_cast<T*>(contents.data())); }
    [[nodiscard]] constexpr const T*  data() const noexcept { return std::launder(std::bit_cast<const T*>(contents.data())); }
    [[nodiscard]] constexpr size_type size() noexcept { return count; } // In ELEMENTS

    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

    [[nodiscard]] constexpr T* operator[](std::size_t i) noexcept
    {
        fubuki_assert(i < capacity, "Invalid index");

        return data() + i;
    }

    [[nodiscard]] constexpr const T* operator[](std::size_t i) const noexcept
    {
        fubuki_assert(i < capacity, "Invalid index");

        return data() + i;
    }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif
};

template<typename T, std::size_t count>
requires(not std::is_array_v<T> and not std::is_const_v<T> and not std::is_reference_v<T>)
struct standard
{
    static constexpr auto capacity = count;

    using size_type       = std::size_t;
    using underlying_type = std::conditional_t<std::is_trivially_default_constructible_v<T>, std::array<T, count>, aligned_bytes<T, count> >;

    underlying_type contents     = {};
    size_type       current_size = 0;

    [[nodiscard]] constexpr size_type size() const noexcept { return current_size; }
    [[nodiscard]] constexpr T*        data() noexcept { return contents.data(); }
    [[nodiscard]] constexpr const T*  data() const noexcept { return contents.data(); }

    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

    [[nodiscard]] constexpr T* operator[](std::size_t i) noexcept
    {
        fubuki_assert(i < capacity, "Invalid index");

        return data() + i;
    }

    [[nodiscard]] constexpr const T* operator[](std::size_t i) const noexcept
    {
        fubuki_assert(i < capacity, "Invalid index");

        return data() + i;
    }

    constexpr void unsafe_set_size(std::size_t new_size) noexcept
    {
        fubuki_assert(new_size <= capacity, "Invalid size");
        current_size = static_cast<size_type>(new_size);
    }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif
};

template<typename T, std::size_t count>
using type = std::conditional_t<count == 0, empty<T>, standard<T, count> >;

} // namespace storage

template<typename T, std::size_t count>
using storage_t = storage::type<T, count>;

} // namespace detail::inplace_vector

/**
 *  Dynamically-resizable array with contiguous inplace storage.
 *  The elements of type T are stored and properly aligned within the object itself.
 *  The capacity of internal storage is fixed at compile-time and is equal to N.
 *
 *  @note This is a C++23 implementation of C++26's std::in_place_vector based on the reference implementation
 *  (available at https://godbolt.org/z/5P78aG5xE) by Gonzalo Brito Gadeschi, licensed under the MIT license.
 *  @see https://en.cppreference.com/w/cpp/container/inplace_vector
 */
template<typename T, std::size_t capacity_v>
class inplace_vector
{
    using underlying_type = detail::inplace_vector::storage_t<T, capacity_v>;

public:

    using value_type             = T;
    using size_type              = std::size_t;
    using difference_type        = std::ptrdiff_t;
    using reference              = value_type&;
    using const_reference        = const value_type&;
    using pointer                = value_type*;
    using const_pointer          = const value_type*;
    using iterator               = pointer;
    using const_iterator         = const_pointer;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    constexpr inplace_vector() noexcept(std::is_nothrow_constructible_v<T>) = default;

    // False positive of MSVC producing a diagnostic about unreachable code
    #if defined(_MSC_VER)
        #pragma warning(push)
        #pragma warning(disable : 4702)
    #endif // defined(_MSC_VER)

    constexpr explicit inplace_vector(std::size_t count)
    requires(std::constructible_from<T, T &&> and std::default_initializable<T>)
    {
        for(size_type i = 0; i < count; ++i)
        {
            emplace_back(T{});
        }
    }

    #if defined(_MSC_VER)
        #pragma warning(pop)
    #endif // defined(_MSC_VER)

    constexpr inplace_vector(std::size_t count, const T& value)
    requires(std::constructible_from<T, const T&> and std::copyable<T>)
    {
        resize(count, value);
    }

    template<std::input_iterator input_iterator>
    constexpr inplace_vector(input_iterator first, input_iterator last)
    {
        insert(end(), first, last);
    }

    #if defined(__cpp_lib_containers_ranges) && __cpp_lib_containers_ranges >= 202202L

    template<std::ranges::input_range R>
    constexpr inplace_vector(std::from_range_t, R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R> > and std::movable<T>)
    {
        insert_range(std::forward<R>(rg));
    }

    #endif // defined(__cpp_lib_containers_ranges ) and __cpp_lib_containers_ranges >= 202202L

    // False positive of MSVC producing a diagnostic about unreachable code
    #if defined(_MSC_VER)
        #pragma warning(push)
        #pragma warning(disable : 4702)
    #endif // defined(_MSC_VER)

    constexpr inplace_vector(const inplace_vector& other) noexcept(std::is_nothrow_copy_constructible_v<T>)
    requires(std::copyable<T>)
    {
        for(auto&& e : other)
        {
            emplace_back(e);
        }
    }

    #if defined(_MSC_VER)
        #pragma warning(pop)
    #endif // defined(_MSC_VER)

    constexpr inplace_vector(inplace_vector&& other) noexcept(capacity_v == 0 or std::is_nothrow_move_constructible_v<T>)
    {
        if constexpr(capacity_v > 0)
        {
            for(auto&& e : other)
            {
                emplace_back(std::move(e));
            }
        }

        other.clear();
    }

    constexpr inplace_vector(std::initializer_list<T> init)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T> > > and std::movable<T>)
    {
        insert(end(), init);
    }

    constexpr ~inplace_vector() noexcept(std::is_nothrow_destructible_v<T>) { clear(); }

    // False positive of MSVC producing a diagnostic about unreachable code
    #if defined(_MSC_VER)
        #pragma warning(push)
        #pragma warning(disable : 4702)
    #endif // defined(_MSC_VER)

    constexpr inplace_vector& operator=(const inplace_vector& other) noexcept(std::is_nothrow_copy_assignable_v<underlying_type>)
    requires(std::copyable<T>)
    {
        clear();
        for(auto&& element : other)
        {
            emplace_back(element);
        }
        return *this;
    }

    #if defined(_MSC_VER)
        #pragma warning(pop)
    #endif // defined(_MSC_VER)

    constexpr inplace_vector&
    operator=(inplace_vector&& other) noexcept(capacity_v == 0 or (std::is_nothrow_move_assignable_v<T> and std::is_nothrow_move_constructible_v<T>))
    {
        clear();
        if constexpr(capacity_v > 0)
        {
            for(auto&& e : other)
            {
                emplace_back(std::move(e));
            }
        }
        other.clear();
        return *this;
    }

    constexpr inplace_vector& operator=(std::initializer_list<T> init)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T> > > and std::movable<T>)
    {
        assign(init);
        return *this;
    }

    constexpr void assign(size_type count, const T& value)
    requires(std::constructible_from<T, const T&> and std::movable<T>)
    {
        clear();
        insert(begin(), count, value);
    }

    template<std::input_iterator input_iterator>
    constexpr void assign(input_iterator first, input_iterator last)
    requires(std::constructible_from<T, std::iter_reference_t<input_iterator> > and std::movable<T>)
    {
        clear();
        insert(begin(), first, last);
    }

    constexpr void assign(std::initializer_list<T> ilist)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T> > > and std::movable<T>)
    {
        clear();
        insert_range(begin(), ilist);
    }

    template<typename R>
    constexpr void assign_range(R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R> > and std::movable<T>)
    {
        return assign(std::ranges::begin(std::forward<R>(rg)), std::ranges::end(std::forward<R>(rg)));
    }

    [[nodiscard]] constexpr reference at(size_type pos)
    {
        if(pos >= size())
        {
            throw_out_of_range(pos);
        }

        return *m_storage[pos];
    }

    [[nodiscard]] constexpr const_reference at(size_type pos) const
    {
        if(pos >= size())
        {
            throw_out_of_range(pos);
        }

        return *m_storage[pos];
    }

    [[nodiscard]] constexpr reference       operator[](size_type pos) noexcept { return *m_storage[pos]; }
    [[nodiscard]] constexpr const_reference operator[](size_type pos) const noexcept { return *m_storage[pos]; }

    [[nodiscard]] constexpr reference       front() noexcept { return *m_storage[0]; }
    [[nodiscard]] constexpr const_reference front() const noexcept { return *m_storage[0]; }
    [[nodiscard]] constexpr reference       back() noexcept { return *m_storage[size() - 1]; }
    [[nodiscard]] constexpr const_reference back() const noexcept { return *m_storage[size() - 1]; }
    [[nodiscard]] constexpr pointer         data() noexcept { return m_storage.data(); }
    [[nodiscard]] constexpr const_pointer   data() const noexcept { return m_storage.data(); }

    [[nodiscard]] constexpr bool             empty() const noexcept { return m_storage.size() == 0; }
    [[nodiscard]] constexpr size_type        size() const noexcept { return m_storage.size(); }
    [[nodiscard]] static constexpr size_type max_size() noexcept { return capacity_v; }
    [[nodiscard]] static constexpr size_type capacity() noexcept { return capacity_v; }

        // The functions in this scope with ignored -Wunsafe-buffer-usage are unsafe by design.
        // They are MEANT to be unsafe by the API of std::inplace_vector

    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

    [[nodiscard]] constexpr iterator       begin() noexcept { return data(); }
    [[nodiscard]] constexpr const_iterator begin() const noexcept { return data(); }
    [[nodiscard]] constexpr iterator       end() noexcept { return begin() + size(); }
    [[nodiscard]] constexpr const_iterator end() const noexcept { return begin() + size(); }

    [[nodiscard]] constexpr reverse_iterator       rbegin() noexcept { return reverse_iterator{end()}; }
    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator{end()}; }
    [[nodiscard]] constexpr reverse_iterator       rend() noexcept { return reverse_iterator{begin()}; }
    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator{begin()}; }

    [[nodiscard]] constexpr const_iterator         cbegin() const noexcept { return data(); }
    [[nodiscard]] constexpr const_iterator         cend() const noexcept { return cbegin() + size(); }
    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator{cend()}; }
    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept { return const_reverse_iterator{begin()}; }

    constexpr void resize(size_type count)
    requires(std::constructible_from<T, T &&> and std::default_initializable<T>)
    {
        if(count == size())
        {
            return;
        }

        if(count > capacity()) [[unlikely]]
        {
            throw_bad_alloc();
        }
        else if(count > size())
        {
            while(size() != count)
            {
                emplace_back(T{});
            }
        }
        else
        {
            unsafe_destroy(begin() + count, end());
            m_storage.unsafe_set_size(count);
        }
    }

    constexpr iterator insert(const_iterator pos, size_type count, const T& value)
    requires(std::constructible_from<T, const T&> and std::copyable<T>)
    {
        assert_iterator_in_range(pos);
        auto old_end = end();
        for(size_type i = 0; i < count; ++i)
        {
            emplace_back(value);
        }
        auto position = begin() + (pos - begin());
        std::rotate(position, old_end, end());
        return position;
    }

    // False positive of MSVC producing a diagnostic about unreachable code
    #if defined(_MSC_VER)
        #pragma warning(push)
        #pragma warning(disable : 4702)
    #endif // defined(_MSC_VER)

    template<std::input_iterator input_iterator>
    constexpr iterator insert(const_iterator pos, input_iterator first, input_iterator last)
    requires(std::constructible_from<T, std::iter_reference_t<input_iterator> > and std::movable<T>)
    {
        assert_iterator_in_range(pos);
        assert_valid_iterator_pair(first, last);

        if constexpr(std::random_access_iterator<input_iterator>)
        {
            if(const auto iter_range_size = static_cast<size_type>(std::distance(first, last)); size() + iter_range_size > capacity()) [[unlikely]]
            {
                throw_bad_alloc();
            }
        }

        auto old_end = end();
        for(; first != last; ++first)
        {
            emplace_back(std::move(*first));
        }
        auto position = begin() + (pos - begin());
        std::rotate(position, old_end, end());
        return position;
    }

    template<typename... arguments>
    constexpr iterator emplace(const_iterator position, arguments&&... args)
    requires(std::constructible_from<T, arguments...> and std::movable<T>)
    {
        assert_iterator_in_range(position);
        auto old_end = end();
        emplace_back(std::forward<arguments>(args)...);
        auto pos = begin() + (position - begin());
        std::rotate(pos, old_end, end());
        return pos;
    }

    #if defined(_MSC_VER)
        #pragma warning(pop)
    #endif // defined(_MSC_VER)

    constexpr void pop_back() noexcept(std::is_nothrow_destructible_v<T>)
    {
        fubuki_assert(size() > 0, "Attempting to pop_back, but this inplace_vector is empty.");
        unsafe_destroy(end() - 1, end());
        m_storage.unsafe_set_size(size() - 1);
    }

    constexpr iterator erase(const_iterator pos)
    requires(std::movable<T>)
    {
        return erase(pos, pos + 1);
    }

    constexpr iterator erase(const_iterator first, const_iterator last)
    requires(std::movable<T>)
    {
        assert_iterator_pair_in_range(first, last);
        iterator f = begin() + (first - begin());
        if(first != last)
        {
            unsafe_destroy(std::move(f + (last - first), end(), f), end());
            m_storage.unsafe_set_size(size() - static_cast<size_type>(last - first));
        }
        return f;
    }

    constexpr void resize(size_type count, const value_type& value)
    requires(std::constructible_from<T, const T&> and std::copyable<T>)
    {
        if(count == size())
        {
            return;
        }

        if(count > capacity()) [[unlikely]]
        {
            throw_bad_alloc();
        }
        else if(count > size())
        {
            insert(end(), count - size(), value);
        }
        else
        {
            unsafe_destroy(begin() + count, end());
            m_storage.unsafe_set_size(count);
        }
    }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif

    constexpr iterator insert(const_iterator pos, std::initializer_list<T> ilist)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T> > > and std::movable<T>)
    {
        return insert_range(pos, std::span{ilist});
    }

    template<typename R>
    constexpr iterator insert_range(const_iterator pos, R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R> > and std::movable<T>)
    {
        return insert(pos, std::ranges::begin(std::forward<R>(rg)), std::ranges::end(std::forward<R>(rg)));
    }

    template<typename... arguments>
    constexpr reference emplace_back(arguments&&... args)
    requires(std::constructible_from<T, arguments...>)
    {
        if(size() == capacity())
        {
            throw_bad_alloc();
        }

        return *try_emplace_back(std::forward<arguments>(args)...);
    }

    template<typename... arguments>
    constexpr pointer try_emplace_back(arguments&&... args)
    requires(std::constructible_from<T, arguments...>)
    {
        if(size() == capacity()) [[unlikely]]
        {
            return nullptr;
        }

        return std::addressof(unchecked_emplace_back(std::forward<arguments>(args)...));
    }

    template<typename... arguments>
    constexpr reference unchecked_emplace_back([[maybe_unused]] arguments&&... args)
    requires(std::constructible_from<T, arguments...>)
    {
        fubuki_assert(size() < capacity(), "inplace_vector out-of-memory");

        if constexpr(capacity_v > 0)
        {

    #if defined(_MSC_VER)
        #pragma warning(push)
        #pragma warning(disable : 4244)
    #endif
            // MSVC recognises this as a narrowing conversion in some cases, for example when constructing inplace_vector<int> from iterators of a
            // inplace_vector<float>.
            // This diagnostic is correct, but clearly such cases are what the user intended to do, so we disable this warning here.
            std::construct_at(end(), std::forward<arguments>(args)...);

    #if defined(_MSC_VER)
        #pragma warning(pop)
    #endif

            m_storage.unsafe_set_size(size() + static_cast<size_type>(1));
        }

        return back();
    }

    constexpr reference push_back(const T& value)
    requires(std::constructible_from<T, const T&>)
    {
        return emplace_back(value);
    }

    constexpr reference push_back(T&& value)
    requires(std::constructible_from<T, T &&>)
    {
        return emplace_back(std::move(value));
    }

    constexpr pointer try_push_back(const T& value)
    requires(std::constructible_from<T, const T&>)
    {
        return try_emplace_back(value);
    }
    constexpr pointer try_push_back(T&& value)
    requires(std::constructible_from<T, T &&>)
    {
        return try_emplace_back(std::move(value));
    }

    constexpr reference unchecked_push_back(const T& value)
    requires(std::constructible_from<T, const T&>)
    {
        return unchecked_emplace_back(value);
    }
    constexpr reference unchecked_push_back(T&& value)
    requires(std::constructible_from<T, T &&>)
    {
        return unchecked_emplace_back(std::move(value));
    }

    template<std::ranges::input_range R>
    constexpr void append_range(R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R> >)
    {
        if constexpr(std::ranges::sized_range<R>)
        {
            if(const auto range_size = std::ranges::size(rg); size() + range_size > capacity()) [[unlikely]]
            {
                throw_bad_alloc();
            }
        }

        for(auto&& e : std::forward<R>(rg))
        {
            if(size() == capacity()) [[unlikely]]
            {
                throw_bad_alloc();
            }

            emplace_back(std::forward<decltype(e)>(e));
        }
    }

    template<std::ranges::input_range R>
    constexpr std::ranges::borrowed_iterator_t<R> try_append_range(R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R> >)
    {
        for(auto it = std::forward<R>(rg).begin(); it != std::forward<R>(rg).end(); ++it)
        {
            if(size() == capacity()) [[unlikely]]
            {
                return it;
            }

            emplace_back(*it);
        }

        return std::ranges::end(rg);
    }

    constexpr void clear() noexcept(std::is_nothrow_destructible_v<T>)
    {
        if constexpr(capacity_v > 0)
        {
            unsafe_destroy(begin(), end());
            m_storage.unsafe_set_size(0);
        }
    }

    constexpr void reserve(size_type count)
    {
        if(count > capacity()) [[unlikely]]
        {
            throw_bad_alloc();
        }
    }

    static constexpr void shrink_to_fit() noexcept {}

    constexpr iterator insert(const_iterator pos, const T& value)
    requires(std::constructible_from<T, const T&> and std::copyable<T>)
    {
        return insert(pos, 1, value);
    }

    constexpr iterator insert(const_iterator pos, T&& value)
    requires(std::constructible_from<T, T &&> and std::movable<T>)
    {
        return emplace(pos, std::move(value));
    }

    constexpr void swap(inplace_vector& other) noexcept(capacity() == 0
                                                        or (std::is_nothrow_swappable_v<T> and std::is_nothrow_move_constructible_v<T>))
    requires(std::movable<T>)
    {
        auto tmp = std::move(other);
        other    = std::move(*this);
        (*this)  = std::move(tmp);
    }

    constexpr friend void swap(inplace_vector& a, inplace_vector& b) noexcept(noexcept(a.swap(b))) { a.swap(b); }

    [[nodiscard]] friend constexpr bool operator==(const inplace_vector& a, const inplace_vector& b) noexcept(noexcept(*a.begin() == *b.begin()))
    requires(std::equality_comparable<T>)
    {
        constexpr auto compare = [](const T& x, const T& y) constexpr noexcept(noexcept(x == y)) { return x == y; };

        return a.size() == b.size() and std::ranges::equal(a, b, compare);
    }

    [[nodiscard]] friend constexpr bool operator!=(const inplace_vector& a, const inplace_vector& b) noexcept(noexcept(a == b))
    requires(std::equality_comparable<T>)
    {
        return not(a == b);
    }

    [[nodiscard]] friend constexpr std::weak_ordering operator<=>(const inplace_vector& a, const inplace_vector& b)
    requires(std::equality_comparable<T>)
    {
        if(a.size() < b.size())
        {
            return std::weak_ordering::less;
        }

        if(a.size() > b.size())
        {
            return std::weak_ordering::greater;
        }

        bool all_equal = true;
        bool all_less  = true;
        for(size_type i = 0; i < a.size(); ++i)
        {
            if(a[i] < b[i])
            {
                all_equal = false;
            }
            if(a[i] == b[i])
            {
                all_less = false;
            }
        }

        if(all_equal)
        {
            return std::weak_ordering::equivalent;
        }

        if(all_less)
        {
            return std::weak_ordering::less;
        }

        return std::weak_ordering::greater;
    }

private:

    underlying_type m_storage;

    constexpr void throw_out_of_range(std::size_t pos) const
    {
        throw std::out_of_range("Index " + std::to_string(pos) + " out of range (max: " + std::to_string(size()));
    }

    constexpr void throw_bad_alloc() const { throw std::bad_alloc{}; }

    constexpr void assert_iterator_in_range([[maybe_unused]] const_iterator it) noexcept
    {
        fubuki_assert(begin() <= it, "iterator not in range");
        fubuki_assert(it <= end(), "iterator not in range");
    }

    template<typename it>
    constexpr void assert_valid_iterator_pair([[maybe_unused]] it first, [[maybe_unused]] it last) noexcept
    {
        fubuki_assert(first <= last, "Invalid iterator pair");
    }

    constexpr void assert_iterator_pair_in_range(const_iterator first, const_iterator last) noexcept
    {
        assert_iterator_in_range(first);
        assert_iterator_in_range(last);
        assert_valid_iterator_pair(first, last);
    }

    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

    constexpr void unsafe_destroy(T* first, T* last) noexcept(std::is_nothrow_destructible_v<T>)
    {
        assert_iterator_pair_in_range(first, last);
        if constexpr(capacity() > 0 and not std::is_trivial_v<T>)
        {
            for(; first != last; ++first)
            {
                first->~T();
            }
        }
    }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif
};

#endif // #ifdef __cpp_lib_inplace_vector

} // namespace future

using future::inplace_vector;

#ifndef __cpp_lib_inplace_vector

/// Erases all elements satisfying specific criteria.
template<typename T, std::size_t N, typename U = T>
constexpr typename fubuki::inplace_vector<T, N>::size_type erase(fubuki::inplace_vector<T, N>& c, const U& value)
{
    auto it = std::remove(c.begin(), c.end(), value);
    auto r  = std::distance(it, c.end());
    c.erase(it, c.end());
    return r;
}

/// Erases all elements satisfying specific criteria.
template<typename T, std::size_t N, typename predicate>
constexpr typename fubuki::inplace_vector<T, N>::size_type erase_if(fubuki::inplace_vector<T, N>& c, predicate pred)
{
    auto it = std::remove_if(c.begin(), c.end(), pred);
    auto r  = std::distance(it, c.end());
    c.erase(it, c.end());
    return r;
}

#endif // #ifndef __cpp_lib_inplace_vector

} // namespace fubuki

#endif // FUBUKI_CORE_FUTURE_INPLACE_VECTOR_HPP
