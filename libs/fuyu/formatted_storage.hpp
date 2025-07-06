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

#ifndef FUBUKI_FUYU_FORMATTED_STORAGE_HPP
#define FUBUKI_FUYU_FORMATTED_STORAGE_HPP

#include <cstddef>
#include <variant>
#include <vector>

#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/format.hpp>
#include <core/handle.hpp>
#include <core/types.hpp>
#include <core/vulkan.hpp>

#include "fuyu/detail/formatted_storage.hpp"

namespace fubuki::fuyu
{

// TODO: find a way to constexpr this. Currently, there are stuff in detail:: that uses std::memcpy (which isn't constexpr)

/// A CPU-side buffer which contains data in a certain VkFormat.
/// Can be used to upload or download a GPU-side image or buffer.
class formatted_storage
{
public:
    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    /// Information required to construct an instance of this object.
    struct information
    {
        VkExtent3D extent = {0u, 0u, 0u};        ///< Extent of the storage.
        VkFormat   format = VK_FORMAT_UNDEFINED; ///< Storage format.
    };

    using span       = detail::any_storage_span;
    using const_span = detail::any_const_storage_span;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    formatted_storage(VkFormat f)
        : m_info{
              .extent = {0u, 0u, 0u},
                .format = f
    }
    {
    }

    formatted_storage(information info) : m_info{info}
    {
        if(m_info.extent.width == 0u)
        {
            m_info.extent.height = 0u;
            m_info.extent.depth  = 0u;
        }
        else
        {
            if(m_info.extent.height == 0u)
            {
                m_info.extent.height = 1u;
            }

            if(m_info.extent.depth == 0u)
            {
                m_info.extent.depth = 1u;
            }
        }

        format(m_info.format);
    }

    formatted_storage(information info, const detail::any_storage_element initial) : m_info{info}
    {
        if(m_info.extent.width == 0u)
        {
            m_info.extent.height = 0u;
            m_info.extent.depth  = 0u;
        }
        else
        {
            if(m_info.extent.height == 0u)
            {
                m_info.extent.height = 1u;
            }

            if(m_info.extent.depth == 0u)
            {
                m_info.extent.depth = 1u;
            }
        }

        format(m_info.format, initial);
    }

    formatted_storage(const formatted_storage&)                = default;
    formatted_storage& operator=(const formatted_storage&)     = default;
    formatted_storage(formatted_storage&&) noexcept            = default;
    formatted_storage& operator=(formatted_storage&&) noexcept = default;

    ~formatted_storage() = default;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Returns a variant holding an iterable span. Use it to perform range-based for loop as follow:
    /// formatted_storage::span contents = this_object;
    /// const auto visitor = [...](auto& var)
    /// {
    ///     for(auto& item : var)
    ///     {
    ///         ...
    ///     }
    /// };
    ///
    /// std::visit(visitor, contents);
    [[nodiscard]] operator span() noexcept
    {
        constexpr auto visitor = [](auto& storage) constexpr noexcept -> detail::any_storage_span { return std::span(storage); };

        return std::visit(visitor, m_storage);
    }

    /// Returns a variant holding a const iterable span.
    [[nodiscard]] operator const_span() noexcept
    {
        constexpr auto visitor = [](const auto& storage) constexpr noexcept -> detail::any_const_storage_span { return {std::span(storage)}; };

        return std::visit(visitor, m_storage);
    }

    /********************************************************************************/
    /*                                 ELEMENT ACCESS                               */
    /********************************************************************************/

    /// Accesses an element at a given linear index.
    [[nodiscard]]
    detail::any_storage_element operator[](std::size_t linear_index) const noexcept
    {
        const auto visitor = [linear_index, this](const auto& storage) noexcept -> detail::any_storage_element
        {
            using storage_type = std::decay_t<decltype(storage)>;
            using value_type   = typename storage_type::value_type;

            if constexpr(not std::is_same_v<value_type, std::byte>)
            {
                return {storage[linear_index]};
            }
            else
            {
                const auto element_size     = description(m_info.format).block_size;
                const auto first_byte_index = linear_index * element_size;

                const std::span<const std::byte> bytes{storage};

                return {bytes.subspan(first_byte_index, element_size)};
            }
        };

        return std::visit(visitor, m_storage);
    }

    /// Accesses an element at a given linear index.
    [[nodiscard]]
    detail::any_element_ref operator[](std::size_t linear_index) noexcept
    {
        const auto visitor = [linear_index, this](auto& storage) noexcept -> detail::any_element_ref
        {
            using storage_type = std::decay_t<decltype(storage)>;
            using value_type   = typename storage_type::value_type;

            if constexpr(not std::is_same_v<value_type, std::byte>)
            {
                return {storage[linear_index]};
            }
            else
            {
                const auto element_size     = description(m_info.format).block_size;
                const auto first_byte_index = linear_index * element_size;

                return {std::span<std::byte>{storage}.subspan(first_byte_index, element_size)};
            }
        };

        return std::visit(visitor, m_storage);
    }

    /// Accesses an element at a given element index. Equivalent to [{x, 0, 0}].
    [[nodiscard]] auto operator[](pos1d<std::size_t> x_pos) const noexcept { return (*this)[{x_pos.x, 0U, 0U}]; }

    /// Accesses an element at a given element index. Equivalent to [{x, 0, 0}].
    [[nodiscard]] auto operator[](pos1d<std::size_t> x_pos) noexcept { return (*this)[{x_pos.x, 0U, 0U}]; }

    /// Accesses an element at a given element index. Equivalent to [{x, y, 0}].
    [[nodiscard]] auto operator[](pos2d<std::size_t> xy_pos) const noexcept { return (*this)[{xy_pos.x, xy_pos.y, 0U}]; }

    /// Accesses an element at a given element index. Equivalent to [{x, y, 0}].
    [[nodiscard]] auto operator[](pos2d<std::size_t> xy_pos) noexcept { return (*this)[{xy_pos.x, xy_pos.y, 0U}]; }

    /// Accesses an element at a given element index.
    [[nodiscard]]
    detail::any_storage_element operator[](pos3d<std::size_t> xyz_pos) const noexcept
    {
        const auto [w, h, d] = m_info.extent;
        const auto [x, y, z] = xyz_pos;

        std::ignore = d;

        return (*this)[x + y * w + z * w * h];
    }

    /// Accesses an element at a given element index.
    [[nodiscard]]
    detail::any_element_ref operator[](pos3d<std::size_t> xyz_pos) noexcept
    {
        const auto [w, h, d] = m_info.extent;
        const auto [x, y, z] = xyz_pos;

        std::ignore = d;

        return (*this)[x + y * w + z * w * h];
    }

    /// Accesses an element at a given linear index.
    [[nodiscard]]
    auto at(std::size_t linear_index) const
    {
        if(linear_index > size())
        {
            const std::string message = "Index " + std::to_string(linear_index) + " out of range (max: " + std::to_string(size()) + ")";
            throw std::out_of_range(message);
        }

        return (*this)[linear_index];
    }

    /// Accesses an element at a given linear index.
    [[nodiscard]]
    auto at(std::size_t linear_index)
    {
        if(linear_index > size())
        {
            const std::string message = "Index " + std::to_string(linear_index) + " out of range (max: " + std::to_string(size()) + ")";
            throw std::out_of_range(message);
        }

        return (*this)[linear_index];
    }

    /// Accesses an element at a given element index. Equivalent to [{x, 0, 0}].
    [[nodiscard]] auto at(pos1d<std::size_t> x_pos) const noexcept { return at({x_pos.x, 0U, 0U}); }

    /// Accesses an element at a given element index. Equivalent to [{x, 0, 0}].
    [[nodiscard]] auto at(pos1d<std::size_t> x_pos) noexcept { return at({x_pos.x, 0U, 0U}); }

    /// Accesses an element at a given element index. Equivalent to [{x, y, 0}].
    [[nodiscard]] auto at(pos2d<std::size_t> xy_pos) const noexcept { return at({xy_pos.x, xy_pos.y, 0U}); }

    /// Accesses an element at a given element index. Equivalent to [{x, y, 0}].
    [[nodiscard]] auto at(pos2d<std::size_t> xy_pos) noexcept { return at({xy_pos.x, xy_pos.y, 0U}); }

    /// Accesses an element at a given element index. Equivalent to [{x, y, z}].
    [[nodiscard]]
    detail::any_storage_element at(pos3d<std::size_t> xyz_pos) const noexcept
    {
        const auto [w, h, d] = m_info.extent;
        const auto [x, y, z] = xyz_pos;

        std::ignore = d;

        return at(x + y * w + z * w * h);
    }

    /// Accesses an element at a given element index. Equivalent to [{x, y, z}].
    [[nodiscard]]
    detail::any_element_ref at(pos3d<std::size_t> xyz_pos) noexcept
    {
        const auto [w, h, d] = m_info.extent;
        const auto [x, y, z] = xyz_pos;

        std::ignore = d;

        return at(x + y * w + z * w * h);
    }

    /// Returns a copy of first element.
    [[nodiscard]] auto front() const noexcept { return (*this)[0u]; }

    /// Returns a reference to the first element.
    [[nodiscard]] auto front() noexcept { return (*this)[0u]; }

    /// Returns a copy of last element.
    [[nodiscard]] auto back() const noexcept { return (*this)[size() - 1u]; }

    /// Returns a reference to the last element.
    [[nodiscard]] auto back() noexcept { return (*this)[size() - 1u]; }

    /// Returns the underlying storage as writable bytes.
    [[nodiscard]]
    std::span<std::byte> data() noexcept
    {
        constexpr auto visitor = [](auto& storage) noexcept -> std::span<std::byte> { return std::as_writable_bytes(std::span{storage}); };

        return std::visit(visitor, m_storage);
    }

    /// Returns the underlying storage as const bytes.
    [[nodiscard]]
    std::span<const std::byte> data() const noexcept
    {
        constexpr auto visitor = [](auto& storage) noexcept -> std::span<const std::byte> { return std::as_bytes(std::span{storage}); };

        return std::visit(visitor, m_storage);
    }

    /********************************************************************************/
    /*                                   CAPACITY                                   */
    /********************************************************************************/

    /// Indicates if the vector is empty.
    [[nodiscard]] bool empty() const { return size() == 0u; }

    /// Returns the number of elements.
    [[nodiscard]] std::uint32_t size() const { return m_info.extent.width * m_info.extent.height * m_info.extent.depth; }

    /// Returns the 3D extent.
    [[nodiscard]] auto extent() const { return m_info.extent; }

    /// Returns the format in use.
    [[nodiscard]] auto format() const { return m_info.format; }

    /// Reserves storage for the number of elements specified.
    /// @warning This changes the 3D dimension of this object.
    void reserve(VkExtent3D elements)
    {
        m_info.extent = elements;

        if(m_info.extent.width == 0u)
        {
            m_info.extent.height = 0u;
            m_info.extent.depth  = 0u;
        }
        else
        {
            if(m_info.extent.height == 0u)
            {
                m_info.extent.height = 1u;
            }

            if(m_info.extent.depth == 0u)
            {
                m_info.extent.depth = 1u;
            }
        }

        const auto count = m_info.extent.width * m_info.extent.height * m_info.extent.depth;

        const auto visitor = [count, element_size = description(m_info.format).block_size](auto& storage)
        {
            using storage_t = std::decay_t<decltype(storage)>;
            if constexpr(std::is_same_v<storage_t, std::vector<std::byte>>)
            {
                storage.reserve(count * element_size);
            }
            else
            {
                storage.reserve(count);
            }
        };

        std::visit(visitor, m_storage);
    }

    /// Reserves storage for the number of elements specified.
    /// @warning This changes the 3D dimension of this object.
    void reserve(dim3d<std::size_t> elements)
    {
        const VkExtent3D vk_extent = {
            vk_size(elements.width),
            vk_size(elements.height),
            vk_size(elements.depth),
        };

        return reserve(vk_extent);
    }

    /// Reserves storage for the number of elements specified.
    /// Equivalent to reserve({width, height, 1})
    /// @warning This changes the 3D dimension of this object.
    void reserve(dim2d<std::size_t> elements) { return reserve(dim3d<std::size_t>{elements.width, elements.height, 1}); }

    /// Reserves storage for the number of elements specified.
    /// Equivalent to reserve({width, 1, 1}).
    /// @warning This changes the 3D dimension of this object.
    void reserve(dim1d<std::size_t> elements) { return reserve(dim3d<std::size_t>{elements.width, 1, 1}); }

    /// Returns the number fo elements that can be held in currently-allocated storage.
    [[nodiscard]]
    std::size_t capacity() const noexcept
    {
        const auto visitor = [element_size = description(m_info.format).block_size](const auto& storage) noexcept
        {
            using storage_type = std::decay_t<decltype(storage)>;

            if constexpr(std::is_same_v<storage_type, std::vector<std::byte>>)
            {
                return storage.capacity() / element_size;
            }
            else
            {
                return storage.capacity();
            }
        };

        return std::visit(visitor, m_storage);
    }

    /// Frees unused memory.
    void shrink_to_fit()
    {
        constexpr auto visitor = [](auto& storage) { storage.shrink_to_fit(); };

        std::visit(visitor, m_storage);
    }

    /// Returns all information known about this storage.
    [[nodiscard]]
    const auto& info() const noexcept
    {
        return m_info;
    }

    /********************************************************************************/
    /*                                   MODIFIERS                                  */
    /********************************************************************************/

    // The following functions are not provided: it's too painful to keep track of new dimensions
    // - insert
    // - insert_range
    // - emplace
    // - erase
    // - push_back
    // - emplace_back
    // - append_range
    // - pop_back

    /// Clears the contents.
    void clear() noexcept
    {
        m_info.extent = {0u, 0u, 0u};

        constexpr auto visitor = [](auto& storage) noexcept { storage.clear(); };

        std::visit(visitor, m_storage);
    }

    /// Resizes the storage to the number of elements specified.
    void resize(VkExtent3D elements)
    {
        m_info.extent = elements;

        if(m_info.extent.width == 0u)
        {
            m_info.extent.height = 0u;
            m_info.extent.depth  = 0u;
        }
        else
        {
            if(m_info.extent.height == 0u)
            {
                m_info.extent.height = 1u;
            }

            if(m_info.extent.depth == 0u)
            {
                m_info.extent.depth = 1u;
            }
        }

        const auto count = m_info.extent.width * m_info.extent.height * m_info.extent.depth;

        const auto visitor = [count, element_size = description(m_info.format).block_size](auto& storage)
        {
            using storage_t = std::decay_t<decltype(storage)>;
            if constexpr(std::is_same_v<storage_t, std::vector<std::byte>>)
            {
                storage.resize(count * element_size);
            }
            else
            {
                storage.resize(count);
            }
        };

        std::visit(visitor, m_storage);
    }

    /// Resizes the storage to the number of elements specified.
    void resize(dim3d<std::size_t> elements)
    {
        const VkExtent3D vk_extent = {
            vk_size(elements.width),
            vk_size(elements.height),
            vk_size(elements.depth),
        };

        return resize(vk_extent);
    }

    /// Resizes the storage to the number of elements specified.
    /// Equivalent to resize({width, height, 1})
    void resize(dim2d<std::size_t> elements) { return resize(dim3d<std::size_t>{elements.width, elements.height, 1}); }

    /// Resizes the storage to the number of elements specified.
    /// Equivalent to resize({width, 1, 1}).
    void resize(dim1d<std::size_t> elements) { return resize(dim3d<std::size_t>{elements.width, 1, 1}); }

    /// Changes the format of this object.
    void format(const VkFormat f)
    {
        m_info.format = f;
        m_storage     = detail::storage_for(f, size());
    }

    /// Changes the format of this object and affects and initial value.
    void format(const VkFormat f, const detail::any_storage_element initial)
    {
        m_info.format = f;
        m_storage     = detail::storage_for(f, size(), initial);
    }

    void swap(formatted_storage& other) noexcept
    {
        std::swap(m_storage, other.m_storage);
        std::swap(m_info, other.m_info);
    }

    friend void swap(formatted_storage& a, formatted_storage& b) noexcept { a.swap(b); }

private:

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    detail::any_storage m_storage = {};
    information         m_info    = {};
};

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FORMATTED_STORAGE_HPP
