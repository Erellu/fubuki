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

#ifndef FUBUKI_CORE_FUTURE_FLAT_SET_HPP
#define FUBUKI_CORE_FUTURE_FLAT_SET_HPP

#include "core/config/macros.hpp"
#include "core/small_vector.hpp"

#ifdef __cpp_lib_flat_set
    #include <flat_set>
#else
    #include <algorithm>
    #include <functional>
    #include <initializer_list>
    #include <ranges>
    #include <vector>
#endif

namespace fubuki
{

namespace future
{

#ifdef __cpp_lib_flat_set
template<typename key, class compare = std::less<key>, class container = std::vector<key>>
using flat_set = std::flat_set;

using std::sorted_unique_t;
constexpr auto sorted_unique = std::sorted_unique;
#else

/**
 * A minimal implementation of std::flat_set, from C++23.
 * flat_set adapts a container to provide a collection of unique keys, sorted by keys.
 * @see https://en.cppreference.com/w/cpp/container/flat_set
 * @see https://en.cppreference.com/w/cpp/header/flat_set
 */
template<typename key, typename compare = std::less<key>, typename container = std::vector<key>>
class flat_set;

struct sorted_unique_t
{
    explicit sorted_unique_t() = default;
}; ///< Part of flat_set implemention. A tag used to indicate that elements of a container or range are sorted and unique.
inline constexpr sorted_unique_t sorted_unique{}; ///< @copydoc sorted_unique_t

template<typename key, typename comparison, typename key_container>
class flat_set
{
private:

    static constexpr bool transparent_comp = []()
    {
        if constexpr(requires { typename comparison::is_transparent; })
        {
            return not std::is_same_v<typename comparison::is_transparent, void>;
        }

        return false;
    }();

public:

    // types
    using key_type               = key;
    using value_type             = key;
    using key_compare            = comparison;
    using value_compare          = comparison;
    using reference              = value_type&;
    using const_reference        = const value_type&;
    using size_type              = typename key_container::size_type;
    using difference_type        = typename key_container::difference_type;
    using iterator               = typename key_container::iterator;
    using const_iterator         = typename key_container::const_iterator;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using container_type         = key_container;

    // constructors
    flat_set() : flat_set(key_compare()) {}

    explicit flat_set(container_type cont) : m_container{std::move(cont)} { sort_and_unique(); }

    template<typename allocator>
    flat_set(const container_type& cont, const allocator& a) : m_container{cont, a},
                                                               m_compare{}
    {
        sort_and_unique();
    }

    flat_set(sorted_unique_t, container_type cont) : m_container(std::move(cont)), m_compare(key_compare()) {}

    template<typename allocator>
    flat_set(sorted_unique_t, const container_type& cont, const allocator& a) : m_container{cont, a},
                                                                                m_compare{}
    {
    }

    explicit flat_set(const key_compare& comp) : m_container(), m_compare(comp) {}

    template<typename allocator>
    flat_set(const key_compare& comp, const allocator& a) : m_container{a},
                                                            m_compare{comp}
    {
    }

    template<typename allocator>
    explicit flat_set(const allocator& a) : m_container{a},
                                            m_compare{}
    {
    }

    template<typename input_iterator>
    flat_set(input_iterator first, input_iterator last, const key_compare& comp = key_compare()) : m_container(),
                                                                                                   m_compare(comp)
    {
        insert(first, last);
    }

    template<typename input_iterator, typename allocator>
    flat_set(input_iterator first, input_iterator last, const key_compare& comp, const allocator& a) : m_container(first, last, a),
                                                                                                       m_compare{comp}
    {
        sort_and_unique();
    }

    template<typename input_iterator, typename allocator>
    flat_set(input_iterator first, input_iterator last, const allocator& a) : m_container(first, last, a),
                                                                              m_compare{}
    {
        sort_and_unique();
    }

    // TODO: implement, we use C++23
    // The following require C++23 std::from_range_t, for which we do not attempt to compensate.
    //
    // template<container-compatible-range<value_type> R>
    // flat_set(from_range_t fr, R&& rg)
    //     : flat_set(fr, std::forward<R>(range), key_compare()) { }
    //
    // template<container-compatible-range<value_type> R, typename allocator>
    // flat_set(from_range_t, R&& rg, const allocator& a);
    //
    // template<container-compatible-range<value_type> R>
    // flat_set(from_range_t, R&& rg, const key_compare& comp)
    //     : flat_set(comp)
    // { insert_range(std::forward<R>(range)); }
    //
    // template<container-compatible-range<value_type> R, typename allocator>
    // flat_set(from_range_t, R&& rg, const key_compare& comp,
    //          const allocator& a);

    template<typename input_iterator>
    flat_set(sorted_unique_t, input_iterator first, input_iterator last, const key_compare& comp = key_compare())
        : m_container(first, last),
          m_compare(comp)
    {
    }

    template<typename input_iterator, typename allocator>
    flat_set(sorted_unique_t, input_iterator first, input_iterator last, const key_compare& comp, const allocator& a)
        : m_container(first, last, a),
          m_compare{comp}
    {
    }

    template<typename input_iterator, typename allocator>
    flat_set(sorted_unique_t, input_iterator first, input_iterator last, const allocator& a) : m_container(first, last, a),
                                                                                               m_compare{}
    {
    }

    flat_set(std::initializer_list<key_type> il, const key_compare& comp = key_compare()) : flat_set(il.begin(), il.end(), comp) {}

    template<typename allocator>
    flat_set(std::initializer_list<key_type> il, const key_compare& comp, const allocator& a) : m_container(std::move(il), a),
                                                                                                m_compare{comp}
    {
        sort_and_unique();
    }

    template<typename allocator>
    flat_set(std::initializer_list<key_type> il, const allocator& a) : m_container(std::move(il), a),
                                                                       m_compare{}
    {
        sort_and_unique();
    }

    flat_set(sorted_unique_t s, std::initializer_list<key_type> il, const key_compare& comp = key_compare()) : flat_set(s, il.begin(), il.end(), comp)
    {
    }

    template<typename allocator>
    flat_set(sorted_unique_t, std::initializer_list<key_type> il, const key_compare& comp, const allocator& a)
        : m_container{std::move(il), a},
          m_compare{comp}
    {
    }

    template<typename allocator>
    flat_set(sorted_unique_t, std::initializer_list<key_type> il, const allocator& a) : m_container(std::move(il), a),
                                                                                        m_compare{}
    {
    }

    flat_set& operator=(std::initializer_list<key_type> contents)
    {
        m_container = std::move(contents);
        sort_and_unique();
        return *this;
    }

    // iterators
    iterator       begin() noexcept { return std::ranges::begin(m_container); }
    const_iterator begin() const noexcept { return std::ranges::begin(m_container); }

    iterator       end() noexcept { return std::ranges::end(m_container); }
    const_iterator end() const noexcept { return std::ranges::end(m_container); }

    reverse_iterator       rbegin() noexcept { return std::ranges::rbegin(m_container); }
    const_reverse_iterator rbegin() const noexcept { return std::ranges::rbegin(m_container); }

    reverse_iterator       rend() noexcept { return std::ranges::rend(m_container); }
    const_reverse_iterator rend() const noexcept { return std::ranges::rend(m_container); }

    const_iterator cbegin() const noexcept { return std::ranges::cbegin(m_container); }
    const_iterator cend() const noexcept { return std::ranges::cend(m_container); }

    const_reverse_iterator crbegin() const noexcept { return std::ranges::crbegin(m_container); }
    const_reverse_iterator crend() const noexcept { return std::ranges::crend(m_container); }

    // capacity
    [[nodiscard]] bool empty() const noexcept { return std::ranges::empty(m_container); }

    size_type size() const noexcept
    {
        if constexpr(requires { std::ranges::size(m_container); })
        {
            return std::ranges::size(m_container);
        }
        else
        {
            return static_cast<size_type>(std::ranges::distance(cbegin(), cend()));
        }
    }

    size_type max_size() const noexcept { return m_container.max_size(); }

    // modifiers
    template<typename... args_t>
    std::pair<iterator, bool> emplace(args_t&&... args)
    requires requires { key_type{std::forward<args_t>(args)...}; }
    {
        key_type new_data{std::forward<args_t>(args)...};

        const_iterator insertion_pos;

        auto result = prepare_insertion(cbegin(), new_data, insertion_pos);

        if(result.second)
        {
            result.first = m_container.insert(insertion_pos, std::move(new_data));
        }

        return result;
    }

    template<typename... args_t>
    iterator emplace_hint(const_iterator hint, args_t&&... args)
    requires requires { key_type{std::forward<args_t>(args)...}; }
    {
        key_type new_data{std::forward<args_t>(args)...};

        const_iterator insertion_pos;

        auto result = prepare_insertion(hint, new_data, insertion_pos);

        if(result.second)
        {
            result.first = m_container.insert(insertion_pos, std::move(new_data));
        }

        return result.first;
    }

    std::pair<iterator, bool> insert(const value_type& x) { return emplace(x); }
    std::pair<iterator, bool> insert(value_type&& x) { return emplace(std::move(x)); }

    template<typename K>
    std::pair<iterator, bool> insert(K&& x)
    {
        return emplace(std::forward<K>(x));
    }

    iterator insert(const_iterator position, const value_type& x) { return emplace_hint(position, x); }
    iterator insert(const_iterator position, value_type&& x) { return emplace_hint(position, std::move(x)); }

    template<typename K>
    iterator insert(const_iterator hint, K&& x)
    requires(std::convertible_to<K, key_type>)
    {
        return emplace_hint(hint, std::forward<K>(x));
    }

    template<typename input_iterator>
    void insert(input_iterator first, input_iterator last)
    {
        m_container.insert(m_container.end(), first, last);
        sort_and_unique();
    }

    // Per the specs:
    // Effects: Equivalent to: insert(first, last)
    template<typename input_iterator>
    void insert(sorted_unique_t, input_iterator first, input_iterator last)
    {
        insert(first, last);
    }

    void insert(std::initializer_list<key_type> il) { insert(il.begin(), il.end()); }
    void insert(sorted_unique_t s, std::initializer_list<key_type> il) { insert(s, il.begin(), il.end()); }

    template<std::ranges::range R>
    void insert_range(R&& range)
    {
        if constexpr(requires { m_container.insert_range(std::forward<R>(range)); })
        {
            m_container.insert_range(std::forward<R>(range));
        }
        else if constexpr(requires { m_container.insert(m_container.end(), std::ranges::begin(range), std::ranges::end(range)); })
        {
            m_container.insert(m_container.end(), std::ranges::begin(range), std::ranges::end(range));
        }
        else
        {
            for(const auto& e : std::forward<R>(range))
            {
                m_container.insert(m_container.end(), e);
            }
        }

        sort_and_unique();
    }

    container_type extract() && { return std::move(m_container); }

    void replace(container_type&& contents)
    {
        m_container = std::move(contents);

        // As per the specs:
        // "The elements of cont must be sorted with respect to compare, and cont must not contain equal elements.
        // Otherwise, the behavior is undefined."
        // To stay consistent with std::flat_set, we do NOT call sort_and_unique().
    }

    iterator erase(iterator position) { return m_container.erase(position); }
    iterator erase(const_iterator position) { return m_container.erase(position); }

    size_type erase(const key_type& x)
    {
        if(const auto pos = find(x); pos != cend())
        {
            m_container.erase(pos);
            return 1;
        }

        return 0;
    }

    template<typename K>
    size_type erase(K&& x)
    requires(transparent_comp)
    {
        if(const auto pos = find(std::forward<K>(x)); pos != cend())
        {
            m_container.erase(pos);
            return 1;
        }

        return 0;
    }

    iterator erase(const_iterator first, const_iterator last) { return m_container.erase(first, last); }

    void swap(flat_set& y) noexcept
    {
        std::ranges::swap(m_compare, y.m_compare);
        std::ranges::swap(m_container, y.m_container);
    }

    void clear() noexcept { m_container.clear(); }

    // observers
    key_compare key_comp() const { return m_compare; }

    value_compare value_comp() const { return m_compare; }

    // set operations
    FUBUKI_SEMI_PURE iterator       find(const key_type& x) { return std::ranges::find(m_container, x); }
    FUBUKI_SEMI_PURE const_iterator find(const key_type& x) const { return std::ranges::find(m_container, x); }

    template<typename K>
    iterator find(const K& x)
    requires(transparent_comp)
    {
        return std::ranges::find(m_container, x);
    }

    template<typename K>
    const_iterator find(const K& x) const
    requires(transparent_comp)
    {
        return std::ranges::find(m_container, x);
    }

    size_type count(const key_type& x) const
    {
        for(const auto& v : *this)
        {
            if(v == x)
            {
                return 1;
            }
        }

        return 0;
    }

    template<typename K>
    size_type count(const K& x) const
    requires(transparent_comp)
    {
        return std::ranges::count(m_container, x);
    }

    bool contains(const key_type& x) const { return find(x) != cend(); }

    template<typename K>
    bool contains(const K& x) const
    requires(transparent_comp)
    {
        return find(x) != cend();
    }

    FUBUKI_SEMI_PURE iterator       lower_bound(const key_type& x) { return std::ranges::lower_bound(m_container, x); }
    FUBUKI_SEMI_PURE const_iterator lower_bound(const key_type& x) const { return std::ranges::lower_bound(m_container, x); }

    template<typename K>
    iterator lower_bound(const K& x)
    requires(transparent_comp)
    {
        return std::ranges::lower_bound(m_container, x);
    }

    template<typename K>
    const_iterator lower_bound(const K& x) const
    requires(transparent_comp)
    {
        return std::ranges::lower_bound(m_container, x);
    }

    FUBUKI_SEMI_PURE iterator       upper_bound(const key_type& x) { return std::ranges::upper_bound(m_container, x); }
    FUBUKI_SEMI_PURE const_iterator upper_bound(const key_type& x) const { return std::ranges::upper_bound(m_container, x); }

    template<typename K>
    iterator upper_bound(const K& x)
    requires(transparent_comp)
    {
        return std::ranges::upper_bound(m_container, x);
    }

    template<typename K>
    const_iterator upper_bound(const K& x) const
    requires(transparent_comp)
    {
        return std::ranges::upper_bound(m_container, x);
    }

    FUBUKI_SEMI_PURE std::pair<iterator, iterator> equal_range(const key_type& x)
    {
        auto r = std::ranges::equal_range(m_container, x);
        return std::make_pair(r.begin(), r.end());
    }

    FUBUKI_SEMI_PURE
    std::pair<const_iterator, const_iterator> equal_range(const key_type& x) const
    {
        auto r = std::ranges::equal_range(m_container, x);
        return std::make_pair(r.begin(), r.end());
    }

    template<typename K>
    std::pair<iterator, iterator> equal_range(const K& x)
    requires(transparent_comp)
    {
        return std::ranges::equal_range(m_container, x);
    }

    template<typename K>
    std::pair<const_iterator, const_iterator> equal_range(const K& x) const
    requires(transparent_comp)
    {
        return std::ranges::equal_range(m_container, x);
    }

    friend bool operator==(const flat_set& x, const flat_set& y) { return x.m_container == y.m_container; }
    friend auto operator<=>(const flat_set& x, const flat_set& y) { return x.m_container <=> y.m_container; }

    friend void swap(flat_set& x, flat_set& y) noexcept { x.swap(y); }

private:

    void sort_and_unique()
    {
        std::ranges::sort(m_container, m_compare);

        auto unique = std::ranges::unique(m_container);
        erase(unique.begin(), unique.end());
    }

    // From https://stackoverflow.com/a/10669041
    // (CC BY-SA 3.0)
    iterator remove_constness(const_iterator it) { return m_container.erase(it, it); }

    // Adapted from boost::detail::flat_tree
    // https://www.boost.org/doc/libs/1_50_0/boost/container/detail/flat_tree.hpp
    // (C) Copyright Ion Gaztanaga 2005-2012. Distributed under the Boost
    // Software License, Version 1.0. (See accompanying file
    // LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    //
    // The comments are left as-is

    std::pair<iterator, bool> prepare_insertion(const_iterator beg, const_iterator end, const value_type& val, const_iterator& commit_data)
    {
        commit_data = std::lower_bound(beg, end, val);

        auto result_it   = remove_constness(commit_data);
        bool result_bool = commit_data == end || std::invoke(m_compare, val, *commit_data);

        return {result_it, result_bool};
    }

    std::pair<iterator, bool> prepare_insertion(const value_type& val, const_iterator& commit_data)
    {
        return prepare_insertion(this->begin(), this->end(), val, commit_data);
    }

    #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    #endif

    std::pair<iterator, bool> prepare_insertion(const_iterator pos, const value_type& val, const_iterator& commit_data)
    {
        // N1780. Props to Howard Hinnant!
        // To insert val at pos:
        // if pos == end || val <= *pos
        //    if pos == begin || val >= *(pos-1)
        //       insert val before pos
        //    else
        //       insert val before upper_bound(val)
        // else if pos+1 == end || val <= *(pos+1)
        //    insert val after pos
        // else
        //    insert val before lower_bound(val)

        const value_compare& value_comp = this->m_compare;

        if(pos == this->cend() || value_comp(val, *pos))
        {
            if(pos != this->cbegin() && !value_comp(val, pos[-1]))
            {
                auto result = remove_constness(pos);

                if(value_comp(pos[-1], val))
                {
                    commit_data = pos;
                    return {result, true};
                }

                return {result, false};
            }

            return this->prepare_insertion(this->cbegin(), pos, val, commit_data);
        }

    #if defined(__clang__)
        #pragma clang diagnostic pop
    #endif

        // Works, but increases code complexity
        // Next check
        // else if (value_comp(*pos, val) && !value_comp(pos[1], val)){
        //   if(value_comp(val, pos[1])){
        //      commit_data.position = pos+1;
        //      return std::pair<iterator,bool>(pos+1, true);
        //   }
        //   else{
        //      return std::pair<iterator,bool>(pos+1, false);
        //   }
        //}

        //[... pos ... val ... ]
        // The hint is before the insertion position, so insert it
        // in the remaining range
        return this->prepare_insertion(pos, this->end(), val, commit_data);
    }

    container_type m_container;
    key_compare    m_compare;
};

template<typename input_iterator, typename compare = std::less<std::decay_t<decltype(std::declval<input_iterator>())>>>
flat_set(input_iterator, input_iterator, compare = compare()) -> flat_set<std::decay_t<decltype(std::declval<input_iterator>())>, compare>;

template<typename input_iterator,
         typename compare
         = std::less<std::decay_t<decltype(std::declval<input_iterator>())>>> // The underlying type to which the iterator "points to"
flat_set(sorted_unique_t, input_iterator, input_iterator, compare = compare())
    -> flat_set<std::decay_t<decltype(std::declval<input_iterator>())>, compare>;

// The following require C++23 std::from_range_t, for which we do not attempt to compensate.
//
// template<std::ranges::input_range R, typename compare = std::less<std::ranges::range_value_t<R>>,
//          typename allocator = std::allocator<std::ranges::range_value_t<R>>>
// flat_set(std::from_range_t, R&&, compare = compare(), allocator = allocator())
//     -> flat_set<std::ranges::range_value_t<R>, compare>;
//
// template<std::ranges::input_range R, typename allocator>
// flat_set(std::from_range_t, R&&, allocator)
//     -> flat_set<std::ranges::range_value_t<R>, std::less<std::ranges::range_value_t<R>>>;

template<typename key, typename compare = std::less<key>>
flat_set(std::initializer_list<key>, compare = compare()) -> flat_set<key, compare>;

template<typename key, typename compare = std::less<key>>
flat_set(sorted_unique_t, std::initializer_list<key>, compare = compare()) -> flat_set<key, compare>;

#endif // __cpp_lib_flat_set

} // namespace future

template<typename key, typename compare = std::less<key>, typename container = std::vector<key>>
using flat_set = future::flat_set<key, compare, container>;

template<typename key, typename compare = std::less<key>, typename container = small_vector<key>>
using small_flat_set = future::flat_set<key, compare, container>;

inline constexpr auto sorted_unique = future::sorted_unique;

} // namespace fubuki

#ifndef __cpp_lib_flat_set

namespace std
{

// This is provided by the standard library if flat_set is provided too.
template<typename key, typename compare, typename key_container, typename allocator_type>
struct uses_allocator<fubuki::future::flat_set<key, compare, key_container>, allocator_type>;

template<typename key, typename compare, typename key_container, typename allocator_type>
struct uses_allocator<fubuki::future::flat_set<key, compare, key_container>, allocator_type>
    : bool_constant<uses_allocator_v<key_container, allocator_type>>
{
};

} // namespace std

#endif // ifndef __cpp_lib_flat_set

#endif // FUBUKI_CORE_FUTURE_FLAT_SET_HPP
