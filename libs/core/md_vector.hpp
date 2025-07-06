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

#ifndef FUBUKI_CORE_MD_VECTOR_HPP
#define FUBUKI_CORE_MD_VECTOR_HPP

#include <cstddef>
#include <ostream>
#include <span>
#include <type_traits>
#include <vector>

#include "core/assertion.hpp"

namespace fubuki
{

/**
 * A RAII wrapper around a C-array T[][]... (with the number of dimensions known at compile-time),
 * providing a conversion to T**... (number of indirections known at compile-time too).
 * @warning You should rather use linear storage when possible. This is provided to faciliate the interface with Vulkan
 * functions requiring T**, T***, etc. (such as in KHR_acceleration_structure).
 */
template<typename T, std::size_t dimensions_count>
class md_vector;

//------------------------------------------------------------------------------

template<typename T, std::size_t dimensions_count>
requires(dimensions_count > 1)
class md_vector<T, dimensions_count> : private std::vector<md_vector<T, dimensions_count - 1>>
{
private:

    friend md_vector<T, dimensions_count + 1>;

    /********************************************************************************/
    /*                         PRIVATE NON-MEMBER FUNCTIONS                         */
    /********************************************************************************/

    template<std::size_t dim>
    static auto make_c_storage()
    {
        if constexpr(dim == 1) // Stop at 1 to support types that don't have default constructor
        {
            return std::add_pointer_t<T>{};
        }
        else
        {
            return std::add_pointer_t<std::decay_t<decltype(make_c_storage<dim - 1>())>>{};
        }
    }

public:

    /********************************************************************************/
    /*                          PUBLIC NON-MEMBER CONSTANTS                         */
    /********************************************************************************/

    static inline constexpr std::size_t dimension_count = dimensions_count;

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using c_storage = std::vector<std::decay_t<decltype(make_c_storage<dimension_count - 1>())>>;
    using base      = std::vector<md_vector<T, dimension_count - 1>>;

    using value_type             = typename base::value_type;
    using allocator_type         = typename base::allocator_type;
    using size_type              = typename base::size_type;
    using difference_type        = typename base::difference_type;
    using reference              = typename base::reference;
    using const_reference        = typename base::const_reference;
    using pointer                = typename base::pointer;
    using const_pointer          = typename base::const_pointer;
    using iterator               = typename base::iterator;
    using const_iterator         = typename base::const_iterator;
    using reverse_iterator       = typename base::reverse_iterator;
    using const_reverse_iterator = typename base::const_reverse_iterator;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    constexpr md_vector(std::span<const std::size_t, dimensions_count> array_extent) { resize(array_extent); }

public:

    template<std::convertible_to<std::size_t>... extent_types>
    constexpr md_vector(extent_types... array_extent)
    requires(sizeof...(extent_types) == dimension_count)
    {
        resize(array_extent...);
    }

    constexpr md_vector() = default;

    constexpr md_vector(const T& value, std::span<const std::size_t, dimensions_count> array_extent) { resize(value, array_extent); }

    template<std::convertible_to<std::size_t>... extent_types>
    constexpr md_vector(const T& value, extent_types... array_extent)
    requires(sizeof...(extent_types) == dimension_count)
    {
        resize(value, array_extent...);
    }

    constexpr md_vector(md_vector&& other)            = default;
    constexpr md_vector& operator=(md_vector&& other) = default;

    constexpr md_vector(const md_vector& other) : base{other}
    {
        m_c_storage.resize(size());

        refresh_c_storage();
    }

    constexpr md_vector& operator=(const md_vector& other)
    {
        base::operator=(other);

        m_c_storage.resize(size());

        refresh_c_storage();

        return *this;
    }

    /********************************************************************************/
    /*                                 ELEMENT ACCESS                               */
    /********************************************************************************/

    using base::at;
    using base::back;
    using base::front;

    [[nodiscard]]
    std::span<T> operator[](const std::size_t i)
    {
        return base::operator[](i);
    }

    [[nodiscard]]
    std::span<const T> operator[](const std::size_t i) const
    {
        return base::operator[](i);
    }

    /********************************************************************************/
    /*                                   ITERATORS                                  */
    /********************************************************************************/

    using base::begin;
    using base::cbegin;
    using base::cend;
    using base::crbegin;
    using base::crend;
    using base::end;
    using base::rbegin;
    using base::rend;

    /********************************************************************************/
    /*                                   CAPACITY                                   */
    /********************************************************************************/

    using base::capacity;
    using base::empty;
    using base::max_size;
    using base::size;

    /********************************************************************************/
    /*                                   MODIFIERS                                  */
    /********************************************************************************/

    /// Resizes the md_vector.
    /// @warning If the vector is a sub-vector inside a md_vector, you are responsible for calling refresh_c_storage().
    template<std::convertible_to<std::size_t>... extent_types>
    constexpr void resize(extent_types... array_extent)
    requires(sizeof...(extent_types) == dimension_count)
    {
        const auto as_list = std::initializer_list<std::size_t>{static_cast<std::size_t>(array_extent)...};

        return resize(std::span<const std::size_t, dimensions_count>{as_list});
    }

    /// Resizes the md_vector.
    /// @warning If the vector is a sub-vector inside a md_vector, you are responsible for calling refresh_c_storage().
    template<std::convertible_to<std::size_t>... extent_types>
    constexpr void resize(const T& value, extent_types... array_extent)
    requires(sizeof...(extent_types) == dimension_count)
    {
        const auto as_list = std::initializer_list<std::size_t>{static_cast<std::size_t>(array_extent)...};

        return resize(value, std::span<const std::size_t, dimensions_count>{as_list});
    }

    /// Returns the raw pointer of the C-like storage.
    [[nodiscard]] constexpr auto* data() noexcept { return m_c_storage.data(); }

    /// Returns the raw pointer of the C-like storage.
    [[nodiscard]] constexpr const auto* data() const noexcept { return m_c_storage.data(); }

    constexpr void swap(md_vector& other) noexcept
    {
        base::swap(other);
        m_c_storage.swap(other.m_c_storage);
    }

    /********************************************************************************/
    /*                           PRIVATE MEMBER FUNCTIONS                           */
    /********************************************************************************/

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend auto& operator<<(std::basic_ostream<char_type, traits>& out, const md_vector<T, dimension_count>& v)
    requires requires {
        {
            out << T {}
        };
    }
    {
        out << "{";

        for(const auto& e : v)
        {
            out << e << ", ";
        }

        out << "}";

        return out;
    }

private:

    /********************************************************************************/
    /*                           PRIVATE MEMBER FUNCTIONS                           */
    /********************************************************************************/

    /// Updates the C-like storage.
    constexpr void refresh_c_storage()
    {
        for(std::size_t i = 0; i < size(); ++i)
        {
            m_c_storage[i] = base::operator[](i).data();
        }
    }

    constexpr void resize(std::span<const std::size_t, dimensions_count> array_extent)
    {
        if constexpr(dimension_count == 2)
        {
            base::resize(array_extent[0]);
            for(auto& vec : *this)
            {
                vec.resize(array_extent[1]);
            }
        }
        else
        {
            const auto subspan = array_extent.subspan(1u);

            const std::span<const std::size_t, dimensions_count - 1> sub_array_extent(subspan.begin(), subspan.end());
            base::resize(array_extent[0], md_vector<T, dimension_count - 1>(sub_array_extent));
        }

        m_c_storage.resize(array_extent[0]);

        refresh_c_storage();
    }

    constexpr void resize(const T& value, std::span<const std::size_t, dimensions_count> array_extent)
    {
        if constexpr(dimension_count == 2)
        {
            base::resize(array_extent[0]);
        }
        else
        {
            const auto subspan = array_extent.subspan(1u);

            const std::span<const std::size_t, dimensions_count - 1> sub_array_extent(subspan.begin(), subspan.end());
            base::resize(array_extent[0], md_vector<T, dimension_count - 1>(sub_array_extent));
        }

        // dimension_count >=2, all elements are md_vectors
        for(auto& vec : *this)
        {
            vec.resize(array_extent[1], value);
        }

        m_c_storage.resize(array_extent[0]);

        refresh_c_storage();
    }

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    c_storage m_c_storage = {};
};

//------------------------------------------------------------------------------

template<typename T>
class md_vector<T, 1> : private std::vector<T>
{
public:

    static inline constexpr std::size_t dimension_count = 1;

    using base = std::vector<T>;

    using value_type             = typename base::value_type;
    using allocator_type         = typename base::allocator_type;
    using size_type              = typename base::size_type;
    using difference_type        = typename base::difference_type;
    using reference              = typename base::reference;
    using const_reference        = typename base::const_reference;
    using pointer                = typename base::pointer;
    using const_pointer          = typename base::const_pointer;
    using iterator               = typename base::iterator;
    using const_iterator         = typename base::const_iterator;
    using reverse_iterator       = typename base::reverse_iterator;
    using const_reverse_iterator = typename base::const_reverse_iterator;

    using base::base;

    using base::operator=;
    using base::assign;
    using base::get_allocator;

    using base::at;
    using base::operator[];
    using base::back;
    using base::data;
    using base::front;

    using base::begin;
    using base::cbegin;
    using base::cend;
    using base::crbegin;
    using base::crend;
    using base::end;
    using base::rbegin;
    using base::rend;

    using base::capacity;
    using base::empty;
    using base::max_size;
    using base::size;

    using base::reserve;
    using base::shrink_to_fit;

    using base::clear;
    using base::emplace;
    using base::emplace_back;
    using base::erase;
    using base::insert;
    using base::pop_back;
    using base::push_back;
    using base::resize;
    using base::swap;

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const md_vector<T, 1>& v)
    requires requires {
        {
            out << T {}
        };
    }
    {
        out << "{";

        for(const auto& e : v)
        {
            out << e << ", ";
        }

        out << "}";

        return out;
    }
};

//------------------------------------------------------------------------------

/// A view of a md_vector.
template<typename T, std::size_t dimensions_count>
class md_vector_view
{
public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using mutable_storage
        = std::add_pointer_t<std::add_const_t<std::remove_reference_t<decltype(*md_vector<std::remove_const_t<T>, dimensions_count>{}.data())>>>;
    using const_storage = typename md_vector<T, dimensions_count>::c_storage::const_pointer;

    using storage_t = std::conditional_t<std::is_const_v<T>, const_storage, mutable_storage>;

    /********************************************************************************/
    /*                          PUBLIC NON-MEMBER CONSTANTS                         */
    /********************************************************************************/

    static inline constexpr std::size_t dimension_count = dimensions_count;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    md_vector_view() noexcept                                 = default;
    md_vector_view(const md_vector_view&) noexcept            = default;
    md_vector_view(md_vector_view&&) noexcept                 = default;
    md_vector_view& operator=(const md_vector_view&) noexcept = default;
    md_vector_view& operator=(md_vector_view&&) noexcept      = default;

    md_vector_view(const md_vector<std::remove_const_t<T>, dimension_count>& vec) noexcept : m_data{vec.data()}, m_size{vec.size()} {}

    md_vector_view(storage_t data, std::size_t size) noexcept : m_data{data}, m_size{size} {}

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

// It's the purpose of this function to not be safe
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

    [[nodiscard]] constexpr auto& operator[](std::size_t idx) noexcept
    {
        fubuki_assert(idx < size(), "Index out of range.");
        return m_data[idx];
    }

    [[nodiscard]] constexpr const auto& operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out of range.");
        return m_data[idx];
    }

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

    [[nodiscard]] constexpr auto size() const noexcept { return m_size; }

    [[nodiscard]] constexpr auto* data() noexcept { return m_data; }

    [[nodiscard]] constexpr const auto* data() const noexcept { return m_data; }

private:

    storage_t   m_data = nullptr;
    std::size_t m_size = {};
};

//------------------------------------------------------------------------------
// Deduction guides

template<typename T, std::size_t dimensions_count>
md_vector_view(const md_vector<T, dimensions_count>&) -> md_vector_view<T, dimensions_count>;

} // namespace fubuki

#endif // FUBUKI_CORE_MD_VECTOR_HPP
