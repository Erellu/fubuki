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

#ifndef FUBUKI_CORE_SMALL_VECTOR_HPP
#define FUBUKI_CORE_SMALL_VECTOR_HPP

#include <algorithm>
#include <cstddef>
#include <optional>
#include <ranges> // IWYU pragma: keep (required for std::from_range_t, which we use when the compiler has support for it)
#include <span>
#include <utility>
#include <variant>
#include <vector>

#include "core/future/inplace_vector.hpp"

namespace fubuki
{

/// Implementation details for fubuki::storage.
namespace detail::small_vector
{

template<typename T, std::size_t small_buffer_size>
using fixed_storage = inplace_vector<T, small_buffer_size>;

template<typename T, typename allocator>
using dynamic_storage = std::vector<T, allocator>;

template<typename T, std::size_t small_buffer_size, typename allocator>
using underlying_type = std::variant<fixed_storage<T, small_buffer_size>, dynamic_storage<T, allocator>>;

constexpr std::size_t default_byte_size  = 64; // Attempt to make the size of small_vector instances close to 64 bytes, like LLVM's SmallVector
constexpr std::size_t automatic_sbo_size = std::dynamic_extent; // Indicates the size must be computed to approximately match default_byte_size.

template<typename T, typename allocator = std::allocator<T>, std::size_t iter = 0>
[[nodiscard]] inline consteval std::size_t default_buffer_size()
{
    if constexpr(sizeof(underlying_type<T, iter, allocator>) >= default_byte_size)
    {
        return iter;
    }
    else
    {
        return default_buffer_size<T, allocator, iter + 1>();
    }
}

} // namespace detail::small_vector

// clang-format off
/**
 * @brief A small_vector is a dynamic container that uses fixed-sized stack-allocated storage under a certain size, and automatically switches to
 * dynamically-allocated storage when it goes above this size limit.
 *
 * By default, the fixed storage size is selected so that an instance of this object weights approximately 64 bytes, with a maximum possible overshoot
 * of `sizeof(T)`.
 * For example, a small_vector<int> has a fixed storage size of 12 elements for a typical x86_64 ABI.
 * The behaviour of the dynamic storage allocations can be customised using a custom allocator to pass to the std::vector
 * (by default, a small_vector uses a std::allocator).
 *
 * The interface is indentical to std::vector or inplace_vector.
 *
 * @tparam T Contents type.
 * @tparam allocator The allocator type used for dynamic storage. Must have the same interface as std::vector.
 * Defaults to std::allocator<T>
 * @tparam small_buffer_size The size of the 'small' buffer, in ELEMENT SIZE. By default, the implementation tries to determine a value so that an
 * instance of small_vector is roughly 64 bytes.
 *
 * @section Iterator Invalidation
 *
 * small_vector provide the same guarantees as std::vector regrding iterator invalidation.
 *
 * | Operation                         | Invalidated operators |
 * | --------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
 * | All read only operations          | None.                                                                                                                |
 * | `swap`, `std::swap`               | `end()`                                                                                                              |
 * | `clear`, `operator=`, `assign`    | All iterators.                                                                                                       |
 * | `reserve`, `shrink_to_fit`        | If the vector changed capacity, all of them. If not, none.                                                           |
 * | `erase`                           | Erased elements and all elements after them (including `end()`).                                                     |
 * | `push_back`, `emplace_back`       | If the vector changed capacity, all of them. If not, only `end()`.                                                   |
 * | `insert`, `emplace`               | If the vector changed capacity, all of them. If not, only those at or after the insertion point (including `end()`). |
 * | `resize`                          | If the vector changed capacity, all of them. If not, only `end()` and any elements erased                            |
 * | `pop_back`                        | The element erased and `end()`.                                                                                      |
 *
 */
// clang-format on
template<typename T, std::size_t small_buffer_size = detail::small_vector::automatic_sbo_size, typename allocator = std::allocator<T>>
requires(std::is_move_assignable_v<T>)
class small_vector
{
    static constexpr std::size_t sbo_size = []() constexpr noexcept -> std::size_t
    {
        // Wrapped in a lambda to avoid instancing default_buffer_size<T, allocator> when not needed
        if constexpr(small_buffer_size == detail::small_vector::automatic_sbo_size)
        {
            return detail::small_vector::default_buffer_size<T, allocator>();
        }

        return small_buffer_size;
    }();

public:

    using fixed_storage   = detail::small_vector::fixed_storage<T, sbo_size>;
    using dynamic_storage = detail::small_vector::dynamic_storage<T, allocator>;
    using underlying_type = detail::small_vector::underlying_type<T, sbo_size, allocator>;
    using allocator_type  = allocator;

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

    constexpr small_vector() noexcept(std::is_nothrow_constructible_v<T>) = default;

    constexpr explicit small_vector(std::size_t count)
    requires(std::constructible_from<T, T &&> and std::default_initializable<T>)
    {
        for(size_type i = 0; i < count; ++i)
        {
            emplace_back(T{});
        }
    }

    constexpr small_vector(std::size_t count, const T& value)
    requires(std::constructible_from<T, const T&> and std::copyable<T>)
    {
        resize(count, value);
    }

    template<std::input_iterator input_iterator>
    constexpr small_vector(input_iterator first, input_iterator last)
    {
        insert(end(), first, last);
    }

#if defined(__cpp_lib_containers_ranges) && __cpp_lib_containers_ranges >= 202202L

    template<std::ranges::input_range R>
    constexpr small_vector(std::from_range_t, R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R>> and std::movable<T>)
    {
        insert_range(std::forward<R>(rg));
    }

#endif // defined(__cpp_lib_containers_ranges ) and __cpp_lib_containers_ranges >= 202202L

    constexpr small_vector(const small_vector& other) noexcept(std::is_nothrow_copy_constructible_v<T>)
    requires(std::copyable<T>)
    {
        for(auto&& e : other)
        {
            emplace_back(e);
        }
    }

    constexpr small_vector(small_vector&& other) noexcept(std::is_nothrow_move_constructible_v<T>)
    requires(std::movable<T>)
    {
        for(auto&& e : other)
        {
            emplace_back(std::move(e));
        }
    }

    constexpr small_vector(std::initializer_list<T> init)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T>>> and std::movable<T>)
    {
        insert(end(), init);
    }

    constexpr ~small_vector() noexcept(std::is_nothrow_destructible_v<T>) = default;

    constexpr small_vector& operator=(const small_vector& other) noexcept(std::is_nothrow_copy_assignable_v<underlying_type>)
    requires(std::copyable<T>)
    {
        clear();
        for(auto&& element : other)
        {
            emplace_back(element);
        }
        return *this;
    }

    constexpr small_vector&
    operator=(small_vector&& other) noexcept((std::is_nothrow_move_assignable_v<T> and std::is_nothrow_move_constructible_v<T>) )
    requires(std::movable<T>)
    {
        clear();
        for(auto&& element : other)
        {
            emplace_back(std::move(element));
        }
        return *this;
    }

    constexpr small_vector& operator=(std::initializer_list<T> init)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T>>> and std::movable<T>)
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
    requires(std::constructible_from<T, std::iter_reference_t<input_iterator>> and std::movable<T>)
    {
        clear();
        insert(begin(), first, last);
    }

    constexpr void assign(std::initializer_list<T> ilist)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T>>> and std::movable<T>)
    {
        clear();
        insert_range(begin(), ilist);
    }

    template<typename R>
    constexpr void assign_range(R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R>> and std::movable<T>)
    {
        return assign(std::ranges::begin(std::forward<R>(rg)), std::ranges::end(std::forward<R>(rg)));
    }

    [[nodiscard]] constexpr std::optional<allocator_type> get_allocator() const
    requires(std::copyable<allocator_type>)
    {
        return small() ? std::optional<allocator_type>{} : std::get<dynamic_storage>(m_contents).get_allocator();
    }

    //-------------------------------------------------------------------------
    // Element access

// operator[] is purposefully unsafe
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

    [[nodiscard]] constexpr reference operator[](size_type pos) noexcept
    {
        return std::visit([pos](auto& variant) noexcept -> reference { return variant[pos]; }, m_contents);
    }

    [[nodiscard]] constexpr const_reference operator[](size_type pos) const noexcept
    {
        return std::visit([pos](const auto& variant) noexcept -> const_reference { return variant[pos]; }, m_contents);
    }
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

    [[nodiscard]] constexpr reference at(size_type pos)
    {
        if(pos >= size())
        {
            throw_out_of_range(pos);
        }

        return (*this)[pos];
    }

    [[nodiscard]] constexpr const_reference at(size_type pos) const
    {
        if(pos >= size())
        {
            throw_out_of_range(pos);
        }

        return (*this)[pos];
    }

    [[nodiscard]] constexpr reference front() noexcept
    {
        return std::visit([](auto& variant) noexcept -> reference { return variant.front(); }, m_contents);
    }

    [[nodiscard]] constexpr const_reference front() const noexcept
    {
        return std::visit([](const auto& variant) noexcept -> const_reference { return variant.front(); }, m_contents);
    }

    [[nodiscard]] constexpr reference back() noexcept
    {
        return std::visit([](auto& variant) noexcept -> reference { return variant.back(); }, m_contents);
    }

    [[nodiscard]] constexpr const_reference back() const noexcept
    {
        return std::visit([](const auto& variant) noexcept -> const_reference { return variant.back(); }, m_contents);
    }

    [[nodiscard]] constexpr pointer data() noexcept
    {
        return std::visit([](auto& variant) noexcept -> pointer { return variant.data(); }, m_contents);
    }

    [[nodiscard]] constexpr const_pointer data() const noexcept
    {
        return std::visit([](const auto& variant) noexcept -> const_pointer { return variant.data(); }, m_contents);
    }

    //-------------------------------------------------------------------------
    // Iterators

    [[nodiscard]] constexpr iterator begin() noexcept
    {
        // Cannot directly take addressof(*variant.begin()), because when the vector is empty, begin() == end(), and dereferencing end() is UB
        return std::visit([](auto& variant) noexcept { return variant.empty() ? variant.data() : std::addressof(*variant.begin()); }, m_contents);
    }

    [[nodiscard]] constexpr const_iterator begin() const noexcept
    {
        // Cannot directly take addressof(*variant.begin()), because when the vector is empty, begin() == end(), and dereferencing end() is UB
        return std::visit([](const auto& variant) noexcept { return variant.empty() ? variant.data() : std::addressof(*variant.begin()); },
                          m_contents);
    }

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

    [[nodiscard]] constexpr iterator       end() noexcept { return begin() + size(); }
    [[nodiscard]] constexpr const_iterator end() const noexcept { return begin() + size(); }

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

    [[nodiscard]] constexpr reverse_iterator       rbegin() noexcept { return reverse_iterator{end()}; }
    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator{end()}; }
    [[nodiscard]] constexpr reverse_iterator       rend() noexcept { return reverse_iterator{begin()}; }
    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator{begin()}; }

    [[nodiscard]] constexpr const_iterator cbegin() const noexcept
    {
        // Cannot directly take addressof(*variant.begin()), because when the vector is empty, begin() == end(), and dereferencing end() is UB
        return std::visit([](const auto& variant) noexcept
                          { return variant.empty() ? const_iterator{variant.data()} : const_iterator{std::addressof(*variant.cbegin())}; },
                          m_contents);
    }

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

    [[nodiscard]] constexpr const_iterator cend() const noexcept { return cbegin() + size(); }

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator{cend()}; }
    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept { return const_reverse_iterator{begin()}; }

    //-------------------------------------------------------------------------
    // Capacity

    [[nodiscard]] constexpr bool      empty() const noexcept { return size() == 0; }
    [[nodiscard]] constexpr size_type size() const noexcept
    {
        return std::visit([](const auto& variant) noexcept { return variant.size(); }, m_contents);
    }

    [[nodiscard]] constexpr size_type capacity() const noexcept
    {
        return std::visit([](const auto& variant) noexcept { return variant.capacity(); }, m_contents);
    }

    [[nodiscard]] constexpr size_type        max_size() const noexcept { return dynamic_storage{}.max_size(); }
    [[nodiscard]] static constexpr size_type max_small_size() noexcept { return fixed_storage::max_size(); }

    /// Indicates if this object uses its in-place buffer.
    [[nodiscard]] constexpr bool small() const noexcept { return std::holds_alternative<fixed_storage>(m_contents); }

    /// Indicates if this object uses its dynamic storage.
    [[nodiscard]] constexpr bool big() const noexcept { return not small(); }

    //-------------------------------------------------------------------------
    // Modifiers

    constexpr void resize(size_type count)
    requires(std::constructible_from<T, T &&> and std::default_initializable<T>)
    {
        if(count == size())
        {
            return;
        }

        if(count < max_small_size() and big())
        {
            make_small();
        }

        if(count > max_small_size() and not big())
        {
            make_big();
        }

        std::visit([count](auto& variant) { variant.resize(count); }, m_contents);
    }

    constexpr void resize(size_type count, const value_type& value)
    requires(std::constructible_from<T, const T&> and std::copyable<T>)
    {
        if(count == size())
        {
            return;
        }

        if(count < max_small_size() and big())
        {
            make_small();
        }

        if(count > max_small_size() and not big())
        {
            make_big();
        }

        std::visit([count, &value](auto& variant) { variant.resize(count, value); }, m_contents);
    }

    constexpr iterator insert(const_iterator pos, size_type count, const T& value)
    requires(std::constructible_from<T, const T&> and std::copyable<T>)
    {
        // Iterators are invalidated upon make_big(), but we need to insert at the same place it would have been placed
        const auto dist = std::distance(cbegin(), pos);

        if(size() == capacity())
        {
            make_big();
        }

        return std::visit([dist, count, &value](auto& variant) -> iterator
                          { return std::addressof(*variant.insert(variant.begin() + dist, count, value)); },
                          m_contents);
    }

    template<std::input_iterator input_iterator>
    constexpr iterator insert(const_iterator pos, input_iterator first, input_iterator last)
    requires(std::constructible_from<T, std::iter_reference_t<input_iterator>> and std::movable<T>)
    {
        assert_iterator_in_range(pos);

        // Must be computed BEFORE invalidating iterators
        const auto dist     = std::distance(cbegin(), pos);
        const auto old_size = static_cast<difference_type>(size());

        if(size() == capacity())
        {
            make_big();
        }

        if constexpr(std::random_access_iterator<input_iterator>)
        {
            if(const auto iter_range_size = static_cast<size_type>(std::distance(first, last)); size() + iter_range_size > capacity()) [[unlikely]]
            {
                make_big(size() + iter_range_size - capacity());
            }
        }

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
        for(; first != last; ++first)
        {
            emplace_back(std::move(*first));
        }

        return std::visit(
            [old_size, dist]<typename container>(container& storage) -> iterator
            {
                auto* begin_ptr = std::addressof(*storage.begin());

                auto* old_end  = begin_ptr + old_size;
                auto* position = begin_ptr + (begin_ptr + dist - begin_ptr);

                std::rotate(position, old_end, begin_ptr + storage.size());
                return position;
            },
            m_contents);
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
    }

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

    constexpr iterator insert(const_iterator pos, std::initializer_list<T> ilist)
    requires(std::constructible_from<T, std::ranges::range_reference_t<std::initializer_list<T>>> and std::movable<T>)
    {
        return insert_range(pos, std::span{ilist});
    }

    template<typename R>
    constexpr iterator insert_range(const_iterator pos, R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R>> and std::movable<T>)
    {
        auto start = std::ranges::begin(rg);
        return insert(pos, start, std::ranges::end(std::forward<R>(rg)));
    }

    template<typename... arguments>
    constexpr iterator emplace(const_iterator position, arguments&&... args)
    requires(std::constructible_from<T, arguments...> and std::movable<T>)
    {
        // Iterators are invalidated upon make_big(), but we need to insert at the same place it would have been placed
        const auto dist = std::distance(cbegin(), position);

        if(size() == capacity())
        {
            make_big();
        }

        return std::visit([dist, ... a = std::forward<arguments>(args)](auto& variant) mutable -> iterator
                          { return std::addressof(*variant.emplace(variant.begin() + dist, std::forward<decltype(a)>(a)...)); },
                          m_contents);
    }

    template<typename... arguments>
    constexpr reference emplace_back(arguments&&... args)
    requires(std::constructible_from<T, arguments...>)
    {
        if(size() == capacity())
        {
            make_big();
        }

        return std::visit([... a = std::forward<arguments>(args)](auto& variant) mutable -> reference
                          { return variant.emplace_back(std::forward<decltype(a)>(a)...); },
                          m_contents);
    }

    constexpr void pop_back() noexcept(std::is_nothrow_destructible_v<T>)
    {
        return std::visit([](auto& variant) noexcept(std::is_nothrow_destructible_v<T>) { return variant.pop_back(); }, m_contents);
    }

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

    constexpr iterator erase(const_iterator pos)
    requires(std::movable<T>)
    {
        return erase(pos, pos + 1);
    }
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

    constexpr iterator erase(const_iterator first, const_iterator last)
    requires(std::movable<T>)
    {
        auto dist_first = std::distance(cbegin(), first);
        auto dist_last  = std::distance(cbegin(), last);

        return std::visit(
            [dist_first, dist_last](auto& variant) -> iterator
            {
                auto result = variant.erase(variant.begin() + dist_first, variant.begin() + dist_last);
                return result == variant.end() ? variant.data() + variant.size() : std::addressof(*result);
            },
            m_contents);
    }

    constexpr reference push_back(const T& value)
    requires(std::constructible_from<T, const T&>)
    {
        emplace_back(value);
        return back();
    }

    constexpr reference push_back(T&& value)
    requires(std::constructible_from<T, T &&>)
    {
        emplace_back(std::move(value));
        return back();
    }

    template<std::ranges::input_range R>
    constexpr void append_range(R&& rg)
    requires(std::constructible_from<T, std::ranges::range_reference_t<R>>)
    {
        if constexpr(std::ranges::sized_range<R>)
        {
            if(const auto range_size = std::ranges::size(rg); (size() + range_size > capacity()) and small()) [[unlikely]]
            {
                make_big();
            }
        }

        for(auto&& e : std::forward<R>(rg))
        {
            if(size() == capacity() and small()) [[unlikely]]
            {
                make_big();
            }

            emplace_back(std::forward<decltype(e)>(e));
        }
    }

    constexpr void clear() noexcept(std::is_nothrow_destructible_v<T>)
    {
        std::visit([](auto& v) noexcept(std::is_nothrow_destructible_v<T>) { v.clear(); }, m_contents);
    }

    constexpr void reserve(size_type new_capacity)
    {
        if(new_capacity < size())
        {
            return;
        }

        if(new_capacity > max_small_size())
        {
            make_big(new_capacity - size());
        }
    }

    constexpr void shrink_to_fit() noexcept(false)
    {
        std::visit([](auto& v) noexcept(false) { v.shrink_to_fit(); }, m_contents);

        if(size() < max_small_size())
        {
            make_small();
        }
    }

    constexpr void swap(small_vector& other) noexcept(std::is_nothrow_swappable_v<underlying_type>) { m_contents.swap(other.m_contents); }

    //-------------------------------------------------------------------------
    // Non-member functions

    friend constexpr void swap(small_vector& a, small_vector& b) noexcept(noexcept(a.swap(b))) { a.swap(b); }

    // This is the user responsibility to compare exactly floating point numbers, hence this warning is disabled here
    // Specifically, it's not triggered through std::vector and std::array (not on clang or gcc at the time of writing), hence leaking warning would
    // be inconsistent
    // Also note that this requires to explicitly implement these operators and not defaulting them
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wfloat-equal"
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wfloat-equal"
#endif

    [[nodiscard]] friend constexpr bool operator==(const small_vector& a, const small_vector& b) noexcept(noexcept(*a.begin() == *a.begin()))
    requires(std::equality_comparable<T>)
    {
        return a.m_contents == b.m_contents;
    }

    [[nodiscard]] friend constexpr bool operator!=(const small_vector& a, const small_vector& b) noexcept(noexcept(a == b))
    requires(std::equality_comparable<T>)
    {
        return not(a == b);
    }

    [[nodiscard]] friend constexpr auto operator<=>(const small_vector& a, const small_vector& b) noexcept(noexcept(a.m_contents <=> b.m_contents))
    requires(std::three_way_comparable<underlying_type>)
    {
        return a.m_contents <=> b.m_contents;
    }

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop)
#endif

private:

    constexpr void throw_out_of_range(std::size_t pos) const
    {
        throw std::out_of_range("Index " + std::to_string(pos) + " out of range (max: " + std::to_string(size()));
    }

    constexpr void assert_iterator_in_range([[maybe_unused]] const_iterator it) noexcept
    {
        fubuki_assert(begin() <= it, "iterator not in range");
        fubuki_assert(it <= end(), "iterator not in range");
    }

    /**
     * Makes this container use the dynamic storage instead of the fixed one.
     * @param grow Additional grow size for the dynamic buffer that will be allocated.
     * Defaults to 0, i.e., the dynamic buffer will have the same size as the fixed-size one.
     * @note Invalidates all iterators.
     */
    constexpr void make_big(std::size_t grow = 0)
    {
        if(big())
        {
            return;
        }

        dynamic_storage s = {};
        s.reserve(size() + grow); // Don't resize or default init for objects that don't have a default ctor

        s.insert(s.end(), std::make_move_iterator(begin()), std::make_move_iterator(end()));

        m_contents = std::move(s);
    }

    /**
     * Makes this container use the fixed storage instead of the dynamic one.
     * @note Invalidates all iterators.
     */
    constexpr void make_small()
    {
        if(small() or size() > max_small_size())
        {
            return;
        }

        fixed_storage s;
        s.insert(s.end(), std::make_move_iterator(begin()), std::make_move_iterator(end()));

        m_contents = std::move(s);
    }

    underlying_type m_contents = {}; ///< The storage
};

/// Storage with 0-size small buffer. Equivalent to the type provided for dynamic storage.
template<typename T, typename allocator>
class small_vector<T, 0, allocator> : private std::vector<T, allocator>
{
public:
    using fixed_storage   = inplace_vector<T, 0>;
    using dynamic_storage = std::vector<T, allocator>;
    using underlying_type = dynamic_storage;

    using value_type             = T;
    using size_type              = std::size_t;
    using difference_type        = std::ptrdiff_t;
    using reference              = value_type&;
    using const_reference        = const value_type&;
    using pointer                = value_type*;
    using const_pointer          = const value_type*;
    using iterator               = typename dynamic_storage::iterator;
    using const_iterator         = typename dynamic_storage::const_iterator;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    using underlying_type::underlying_type;

    using underlying_type::operator=;
    using underlying_type::assign;

    using underlying_type::at;
    using underlying_type::operator[];
    using underlying_type::back;
    using underlying_type::data;
    using underlying_type::front;

    using underlying_type::begin;
    using underlying_type::cbegin;
    using underlying_type::cend;
    using underlying_type::crbegin;
    using underlying_type::crend;
    using underlying_type::end;
    using underlying_type::rbegin;
    using underlying_type::rend;

    using underlying_type::capacity;
    using underlying_type::empty;
    using underlying_type::max_size;
    using underlying_type::size;
    [[nodiscard]] static constexpr size_type max_small_size() noexcept { return fixed_storage::max_size(); }

    using underlying_type::reserve;
    using underlying_type::shrink_to_fit;

    using underlying_type::clear;
    using underlying_type::emplace;
    using underlying_type::emplace_back;
    using underlying_type::erase;
    using underlying_type::insert;
    using underlying_type::pop_back;
    using underlying_type::push_back;
    using underlying_type::resize;
    using underlying_type::swap;

    /// Indicates if this object uses its in-place buffer.
    [[nodiscard]] constexpr bool small() const noexcept { return false; } // NOLINT(readability-convert-member-functions-to-static)

    /// Indicates if this object uses its dynamic storage.
    [[nodiscard]] constexpr bool big() const noexcept { return true; } // NOLINT(readability-convert-member-functions-to-static)

    [[nodiscard]] friend constexpr bool operator==(const small_vector& a,
                                                   const small_vector& b) noexcept(noexcept(underlying_type{} == underlying_type{}))
    {
        return static_cast<const underlying_type&>(a) == static_cast<const underlying_type&>(b);
    }

    [[nodiscard]] friend constexpr bool operator!=(const small_vector& a,
                                                   const small_vector& b) noexcept(noexcept(underlying_type{} != underlying_type{}))
    {
        return static_cast<const underlying_type&>(a) != static_cast<const underlying_type&>(b);
    }

    [[nodiscard]] friend constexpr auto operator<=>(const small_vector& a,
                                                    const small_vector& b) noexcept(noexcept(underlying_type{} <=> underlying_type{}))
    {
        return static_cast<const underlying_type&>(a) <=> static_cast<const underlying_type&>(b);
    }
};

/**
 * View of a instance of fubuki::small_vector that behaves exactly like (and converts to) std::span.
 */
template<typename T>
class small_span
{

public:

    using range_type       = std::span<T>;
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

    constexpr small_span() noexcept                             = default;
    constexpr small_span(const small_span&) noexcept            = default;
    constexpr small_span(small_span&&) noexcept                 = default;
    constexpr small_span& operator=(const small_span&) noexcept = default;
    constexpr small_span& operator=(small_span&&) noexcept      = default;
    constexpr ~small_span() noexcept                            = default;

    template<typename U, std::size_t small_buffer_size, typename allocator>
    constexpr small_span(small_vector<U, small_buffer_size, allocator>& v) noexcept : m_contents{v.data(), v.size()}
    {
    }

    template<typename U, std::size_t small_buffer_size, typename allocator>
    constexpr small_span(const small_vector<U, small_buffer_size, allocator>& v) noexcept
    requires(std::is_const_v<T>)
        : m_contents{v.data(), v.size()}
    {
    }

    template<std::size_t small_buffer_size, typename allocator>
    constexpr small_span(const small_vector<T, small_buffer_size, allocator>&&) noexcept = delete; // Temporaries not allowed

    /// Returns the underlying std::span.
    [[nodiscard]] constexpr auto span() const noexcept { return m_contents; }

    /// Returns an std::span of the const-qualified m_contents
    [[nodiscard]] constexpr std::span<const T> const_span() const noexcept { return {m_contents}; }

    [[nodiscard]] constexpr iterator         begin() const noexcept { return m_contents.begin(); }
    [[nodiscard]] constexpr iterator         end() const noexcept { return m_contents.end(); }
    [[nodiscard]] constexpr reverse_iterator rbegin() const noexcept { return m_contents.rbegin(); }
    [[nodiscard]] constexpr reverse_iterator rend() const noexcept { return m_contents.rend(); }

    [[nodiscard]] constexpr reference front() const { return m_contents.front(); }
    [[nodiscard]] constexpr reference back() const { return m_contents.back(); }
    [[nodiscard]] constexpr reference operator[](size_type idx) const { return m_contents[idx]; }
    [[nodiscard]] constexpr pointer   data() const noexcept { return m_contents.data(); }

    [[nodiscard]] constexpr reference at(size_type pos)
    {
        if(pos >= size())
        {
            throw_out_of_range(pos);
        }

        return (*this)[pos];
    }

    [[nodiscard]] constexpr size_type size() const noexcept { return m_contents.size(); }
    [[nodiscard]] constexpr size_type size_bytes() const noexcept { return m_contents.size_bytes(); }
    [[nodiscard]] constexpr bool      empty() const noexcept { return m_contents.empty(); }

    template<std::size_t count>
    [[nodiscard]] constexpr std::span<element_type, count> first() const noexcept
    {
        return m_contents.template first<count>();
    }

    [[nodiscard]] constexpr std::span<element_type, std::dynamic_extent> first(size_type count) const noexcept { return m_contents.first(count); }

    template<std::size_t count>
    [[nodiscard]] constexpr std::span<element_type, count> last() const noexcept
    {
        return m_contents.template last<count>();
    }

    [[nodiscard]] constexpr std::span<element_type, std::dynamic_extent> last(size_type count) const noexcept { return m_contents.last(count); }

    template<std::size_t offset, std::size_t count = std::dynamic_extent>
    [[nodiscard]] constexpr auto subspan() const noexcept
    {
        return m_contents.template subspan<offset, count>();
    }

    [[nodiscard]] constexpr std::span<element_type, std::dynamic_extent> subspan(size_type offset, size_type count = std::dynamic_extent) const
    {
        return m_contents.subspan(offset, count);
    }

    [[nodiscard]] constexpr operator std::span<T>() noexcept { return m_contents; }
    [[nodiscard]] constexpr operator std::span<const T>() const noexcept { return {m_contents}; }

    [[nodiscard]] friend constexpr bool operator==(const small_span& a, const small_span& b) noexcept
    requires(std::equality_comparable<T>)
    {
        return std::ranges::equal(a.m_contents, b.m_contents);
    }

    [[nodiscard]] friend constexpr bool operator!=(const small_span& a, const small_span& b) noexcept
    requires(std::equality_comparable<T>)
    {
        return not(a == b);
    }

    [[nodiscard]] friend constexpr auto operator<=>(const small_span& a, const small_span& b) noexcept
    requires(std::three_way_comparable<T>)
    {

        return std::lexicographical_compare_three_way(a.m_contents.begin(), a.m_contents.end(), b.m_contents.begin(), b.m_contents.end());
    }

private:

    constexpr void throw_out_of_range(std::size_t pos) const
    {
        throw std::out_of_range("Index " + std::to_string(pos) + " out of range (max: " + std::to_string(size()));
    }

    std::span<T> m_contents = {};
};

//------------------------------------------------------------------------------
// Deduction guides

template<std::input_iterator input_iterator>
small_vector(input_iterator, input_iterator) -> small_vector<typename std::iterator_traits<input_iterator>::value_type,
                                                             detail::small_vector::automatic_sbo_size,
                                                             std::allocator<typename std::iterator_traits<input_iterator>::value_type>>;

#if defined(__cpp_lib_containers_ranges) && __cpp_lib_containers_ranges >= 202202L
template<std::ranges::input_range range>
small_vector(std::from_range_t, range&&)
    -> small_vector<std::ranges::range_value_t<range>, detail::small_vector::automatic_sbo_size, std::allocator<std::ranges::range_value_t<range>>>;
#endif // defined(__cpp_lib_containers_ranges) && __cpp_lib_containers_ranges >= 202202L

template<typename T, std::size_t small_buffer_size, typename allocator>
small_span(const small_vector<T, small_buffer_size, allocator>&) -> small_span<const T>;

template<typename T, std::size_t small_buffer_size, typename allocator>
small_span(small_vector<T, small_buffer_size, allocator>&) -> small_span<T>;

/// Erases all elements satisfying specific criteria.
template<typename T, std::size_t small_buffer_size, typename allocator, typename U = T>
constexpr typename fubuki::small_vector<T, small_buffer_size, allocator>::size_type erase(fubuki::small_vector<T, small_buffer_size, allocator>& c,
                                                                                          const U& value)
{
    auto it = std::remove(c.begin(), c.end(), value);
    auto r  = std::distance(it, c.end());
    c.erase(it, c.end());
    return r;
}

/// Erases all elements satisfying specific criteria.
template<typename T, std::size_t small_buffer_size, typename allocator, typename predicate>
constexpr typename fubuki::small_vector<T, small_buffer_size, allocator>::size_type erase_if(fubuki::small_vector<T, small_buffer_size, allocator>& c,
                                                                                             predicate pred)
{
    auto it = std::remove_if(c.begin(), c.end(), pred);
    auto r  = std::distance(it, c.end());
    c.erase(it, c.end());
    return r;
}

} // namespace fubuki

#endif // FUBUKI_CORE_SMALL_VECTOR_HPP
