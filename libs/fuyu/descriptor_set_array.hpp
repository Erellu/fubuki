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

#ifndef FUBUKI_FUYU_DESCRIPTOR_SET_ARRAY_HPP
#define FUBUKI_FUYU_DESCRIPTOR_SET_ARRAY_HPP

#include <core/collect.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/descriptor_set.hpp" // IWYU pragma: export
#include "fuyu/information/descriptor_set_array.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/descriptor_pool.hpp"
#include "fuyu/views/descriptor_set_array.hpp"
#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

/**
 * An object representing an array of descriptor sets allocated from a common pool.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkDescriptorSet.html
 */
class descriptor_set_array
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = descriptor_set_handle;
    using parent_type = parent::device;
    using information = information::descriptor_set_array;
    using view        = views::descriptor_set_array;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param parent Parent pool from which the sets will be allocated.
     * @param info Information about the allocation.
     * @param chain Chain extending VkDescriptorSetAllocateInfo.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * It can also throw an instance of std::bad_alloc if an intermediate (temporary) allocation failed.I
     */
    template<typename... pnext_chain_members>
    // No export, inlined below
    descriptor_set_array(descriptor_pool_view parent, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param parent Parent pool from which the sets will be allocated.
     * @param info Information about the allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * It can also throw an instance of std::bad_alloc if an intermediate (temporary) allocation failed.I
     */
    descriptor_set_array(descriptor_pool_view parent, information info) : descriptor_set_array{parent, std::move(info), empty_pnext_chain} {}

    /**
     * Constructor.
     * @param handles The handles this object will borrow or take ownership over.
     * @param parent Parent pool from which the descriptor sets will be allocated.
     * @param info Information about the allocation.
     */
    descriptor_set_array(external_handle<small_vector<handle_type>> handles, descriptor_pool_view parent, information info);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param parent Parent pool from which the sets will be allocated.
     * @param info Information about the allocation.
     * @param chain The chain extending VkDescriptorSetAllocateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... layout_pnext_chain_members>
    [[nodiscard]] // No export, inlined below
    static std::expected<descriptor_set_array, api_call_info>
    make(descriptor_pool_view parent, information info, const pnext_chain<layout_pnext_chain_members...>& chain);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param parent Parent pool from which the sets will be allocated.
     * @param info Information about the allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]] static std::expected<descriptor_set_array, api_call_info> make(descriptor_pool_view parent, information info)
    {
        return make(parent, std::move(info), empty_pnext_chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handles The handles this object will borrow or take ownership over.
     * @param parent Parent pool from which the descriptor sets will be allocated.
     * @param info Information about how the allocation was performed.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<descriptor_set_array, api_call_info>
    make(external_handle<small_vector<handle_type>> handles, descriptor_pool_view parent, information info) noexcept;

    /// Destructor. Frees the descriptor sets held by this object if they are owned by this object, not VK_NULL_HANDLE and if the parent pool has
    /// VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT.
    ~descriptor_set_array() noexcept
    {
        if(owns())
        {
            descriptor_set_array::destroy();
        }
    }

    /// Move constructor.
    descriptor_set_array(descriptor_set_array&& other) noexcept
        : m_handles{std::exchange(other.m_handles, small_vector<handle_type>{})},
          m_parent{other.m_parent},
          m_pool{other.m_pool},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    descriptor_set_array& operator=(descriptor_set_array&& other) noexcept
    {
        swap(other);
        return *this;
    }

    descriptor_set_array(const descriptor_set_array&)            = delete;
    descriptor_set_array& operator=(const descriptor_set_array&) = delete;

    /********************************************************************************/
    /*                                  ITERATORS                                   */
    /********************************************************************************/

    [[nodiscard]] auto begin() const noexcept { return m_handles.begin(); }
    [[nodiscard]] auto end() const noexcept { return m_handles.end(); }

    [[nodiscard]] auto begin() noexcept { return m_handles.begin(); }
    [[nodiscard]] auto end() noexcept { return m_handles.end(); }

    [[nodiscard]] auto cbegin() const noexcept { return m_handles.cbegin(); }
    [[nodiscard]] auto cend() const noexcept { return m_handles.cend(); }

    [[nodiscard]] auto rbegin() const noexcept { return m_handles.rbegin(); }
    [[nodiscard]] auto rend() const noexcept { return m_handles.rend(); }

    [[nodiscard]] auto rbegin() noexcept { return m_handles.rbegin(); }
    [[nodiscard]] auto rend() noexcept { return m_handles.rend(); }

    [[nodiscard]] auto crbegin() const noexcept { return m_handles.crbegin(); }
    [[nodiscard]] auto crend() const noexcept { return m_handles.crend(); }

    /********************************************************************************/
    /*                                  ELEMENT ACCESS                              */
    /********************************************************************************/

    /// Returns a view of the first descriptor set of this array. The behaviour is undefined if this array is empty.
    [[nodiscard]] descriptor_set_view front() const noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        return {
            m_handles.front(),
            m_parent,
            m_pool.handle,
        };
    }

    /// Returns a view of the last descriptor set of this array. The behaviour is undefined if this array is empty.
    [[nodiscard]] descriptor_set_view back() const noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        return {m_handles.back(), m_parent, m_pool.handle};
    }

    /// Returns a view of the descriptor set at the given index.
    /// Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] descriptor_set_view at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }

        return {m_handles[idx], m_parent, m_pool.handle};
    }
    /// Returns a view of the descriptor set at the given index. The behaviour is undefined if `idx >= size()`.
    [[nodiscard]] descriptor_set_view operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out-of-bounds (max: " << size() << ")");
        return {m_handles[idx], m_parent, m_pool.handle};
    }

    /********************************************************************************/
    /*                                    CAPACITY                                  */
    /********************************************************************************/

    /// Returns the size of this array.
    [[nodiscard]] std::size_t size() const noexcept { return m_handles.size(); }

    /// Indicates if this array is empty.
    [[nodiscard]] bool empty() const noexcept { return m_handles.empty(); }

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator std::span<const handle_type>() const noexcept { return m_handles; }

    /// Conversion operator to view.
    [[nodiscard]]
    inline operator view() const noexcept
    {
        return {.handles = small_span{m_handles}, .device = m_parent, .parent = m_pool.handle};
    }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] std::span<const handle_type> handle() const noexcept { return small_span{m_handles}.const_span(); }

    //------------------------------------------------------------------------------

    /// Returns a reference to the device this descriptor pool uses.
    [[nodiscard]] const fuyu::device& device() const noexcept { return m_parent; }

    //------------------------------------------------------------------------------

    /**
     * @brief Releases the ownership over the underlying Vulkan handle.
     * The caller becomes responsible of properly managing the lifetime of the Vulkan handle.
     */
    [[nodiscard("The caller becomes responsible of destroying the handle")]] owning_view<view> release() noexcept
    {
        owning_view<view> result = {.value = {{
                                        .handles = std::move(m_handles),
                                        .device  = device(),
                                        .parent  = m_pool.handle,
                                    }}};

        m_handles = {};

        return result;
    }

    //------------------------------------------------------------------------------

    /// Returns the handle of the descriptor pool the array originates from.
    [[nodiscard]] descriptor_pool_handle parent() const noexcept { return m_pool.handle; }

    /// Returns a view of the descriptor pool the array originates from.
    [[nodiscard]] descriptor_pool_view pool() const noexcept { return {m_pool.handle, m_parent, m_pool.flags}; }

    //------------------------------------------------------------------------------

    /// Indicates if this object has ownership over its handles and will destroy them when the destructor runs.
    [[nodiscard]] bool owns() const noexcept { return m_owner; }

    /// Indicates if the object borrows its handles and will NOT destroy them when the destructor runs.
    [[nodiscard]] bool borrows() const noexcept { return not owns(); }

    //------------------------------------------------------------------------------

    /// Swaps two objects.
    void swap(descriptor_set_array& other) noexcept
    {
        m_handles.swap(other.m_handles);
        std::swap(m_parent, other.m_parent);
        std::swap(m_pool, other.m_pool);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(descriptor_set_array& a, descriptor_set_array& b) noexcept { a.swap(b); }

    /**
     * @brief Changes the parent, if the underlying Vulkan handle is the same as the previous one.
     * @param p The new parent.
     * @returns Nothing, or an instance of fuyu::parent::error::incompatible indicating that the two handles were different.
     */
    [[nodiscard]]
    std::expected<void, parent_type::error::incompatible> rebind(parent_type p) noexcept
    {
        if(compatible(m_parent, p))
        {
            m_parent.swap(p);
            return {};
        }
        return std::unexpected{
            parent_type::error::incompatible{m_parent.handle, p.handle}
        };
    }

    /**
     * @brief Changes the parent, if the underlying Vulkan handle is the same as the previous one.
     * @param object The object to rebind.
     * @param parent The new parent.
     * @returns Nothing, or an instance of fuyu::parent::error::incompatible indicating that the two handles were different.
     */
    friend auto rebind(descriptor_set_array& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    descriptor_set_array(token, descriptor_pool_view parent, information info) noexcept
        : m_parent{parent.device},
          m_pool{parent.handle, parent.flags},
          m_info{std::move(info)}
    {
    }

    struct parent_pool
    {
        descriptor_pool_handle      handle = null_handle; ///< The descriptor pool handle.
        VkDescriptorPoolCreateFlags flags  = {};          ///< The flags the parent was created with.
    };

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Creates the objects.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkDescriptorSetAllocateInfo&) noexcept;

    /// Destroys the objects if they are not VK_NULL_HANDLE.
    FUBUKI_FUYU_API void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    small_vector<handle_type> m_handles = {}; ///< Underlying Vulkan handles.
    parent_type               m_parent;       ///< Device this object originates from.
    parent_pool               m_pool = {};    ///< Pool from which the sets are allocated.
    information               m_info;         ///< Information about this object.
    bool                      m_owner = true; ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline descriptor_set_array::descriptor_set_array(descriptor_pool_view parent, information info, const pnext_chain<pnext_chain_members...>& chain)
    : descriptor_set_array{token{}, parent, std::move(info)}
{
    const auto vk_layouts = collect<VkDescriptorSetLayout>(small_span{m_info.layouts}.const_span());

    auto vk_info = to_underlying(m_info, vk_layouts, m_pool.handle);
    fubuki::extend(vk_info, chain);

    if(const auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline descriptor_set_array::descriptor_set_array(external_handle<small_vector<handle_type>> handles, descriptor_pool_view parent, information info)
    : descriptor_set_array{token{}, parent, std::move(info)}
{
    m_owner   = fuyu::indicates_ownership(handles);
    m_handles = fuyu::handle_of(std::move(handles));

    if(const auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... layout_pnext_chain_members>
[[nodiscard]] // No export, inlined below
inline std::expected<descriptor_set_array, api_call_info>
descriptor_set_array::make(descriptor_pool_view parent, information info, const pnext_chain<layout_pnext_chain_members...>& chain)
{
    auto result = descriptor_set_array{token{}, parent, std::move(info)};

    const auto vk_layouts = collect<VkDescriptorSetLayout>(small_span{result.m_info.layouts}.const_span());

    auto vk_info = to_underlying(result.m_info, vk_layouts, result.m_pool.handle);
    fubuki::extend(vk_info, chain);

    if(const auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<descriptor_set_array, api_call_info>
descriptor_set_array::make(external_handle<small_vector<handle_type>> handles, descriptor_pool_view parent, information info) noexcept
{
    auto result = descriptor_set_array{token{}, parent, std::move(info)};

    result.m_owner   = fuyu::indicates_ownership(handles);
    result.m_handles = fuyu::handle_of(std::move(handles));

    if(const auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_DESCRIPTOR_SET_ARRAY_HPP
