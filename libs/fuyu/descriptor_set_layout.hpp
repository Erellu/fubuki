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

#ifndef FUBUKI_FUYU_DESCRIPTOR_SET_LAYOUT_HPP
#define FUBUKI_FUYU_DESCRIPTOR_SET_LAYOUT_HPP

#include <core/collect.hpp>
#include <core/constants.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/information/descriptor_set_layout.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/descriptor_pool.hpp"
#include "fuyu/views/descriptor_set_layout.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

/**
 * A descriptor set layout object is defined by an array of zero or more descriptor bindings. Each individual descriptor binding is specified by a
 * descriptor type, a count (array size) of the number of descriptors in the binding, a set of shader stages that can access the binding, and (if
 * using immutable samplers) an array of sampler descriptors.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkDescriptorSetLayout.html
 */
class descriptor_set_layout
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = descriptor_set_layout_handle;
    using parent_type = parent::device;
    using information = information::descriptor_set_layout;
    using view        = views::descriptor_set_layout;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * @param parent The parent descriptor pool that will allocate this descriptor set layout.
     * @param info Information about the contents of the descriptor set layout.
     * @param chain The chain extending the creation of the descriptor set layouts this object owns.
     *
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    template<typename... layout_pnext_chain_members>
    // No export, inlined below
    descriptor_set_layout(descriptor_pool_view parent, information info, const pnext_chain<layout_pnext_chain_members...>& chain);

    /**
     * Constructor.
     *
     * @param parent The parent descriptor pool that will allocate this descriptor set layout.
     * @param info Information about the contents of the descriptor set layout.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    descriptor_set_layout(descriptor_pool_view parent, information info) : descriptor_set_layout{parent, std::move(info), empty_pnext_chain} {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param parent The parent descriptor pool that allocated this descriptor set layout.
     * @param info Information about the handle allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    descriptor_set_layout(external_handle<handle_type> handle, descriptor_pool_view parent, information info);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param parent The parent descriptor pool that will allocate this descriptor set layout.
     * @param info Information about the contents of the descriptor set layout.
     * @param chain The chain extending the creation of the descriptor set layouts this object owns.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... layout_pnext_chain_members>
    [[nodiscard]] // No export, inlined below
    static std::expected<descriptor_set_layout, api_call_info>
    make(descriptor_pool_view parent, information info, const pnext_chain<layout_pnext_chain_members...>& chain);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param parent The parent descriptor pool that will allocate this descriptor set layout.
     * @param info Information about the contents of the descriptor set layout.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]]
    static std::expected<descriptor_set_layout, api_call_info> make(descriptor_pool_view parent, information info)
    {
        return make(parent, std::move(info), empty_pnext_chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param parent The parent descriptor pool that allocated this descriptor set layout.
     * @param info Information about the handle allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<descriptor_set_layout, api_call_info>
    make(external_handle<handle_type> handle, descriptor_pool_view parent, information info) noexcept;

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~descriptor_set_layout() noexcept
    {
        if(owns())
        {
            descriptor_set_layout::destroy();
        }
    }

    /// Move constructor.
    descriptor_set_layout(descriptor_set_layout&& other) noexcept
        : m_handle{std::exchange(other.m_handle, handle_type{})},
          m_parent{other.m_parent},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    descriptor_set_layout& operator=(descriptor_set_layout&& other) noexcept
    {
        swap(other);
        return *this;
    }

    descriptor_set_layout(const descriptor_set_layout&)            = delete;
    descriptor_set_layout& operator=(const descriptor_set_layout&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to view.
    [[nodiscard]]
    inline operator view() const noexcept
    {
        return {
            .handle   = m_handle,
            .device   = m_parent,
            .parent   = m_pool.handle,
            .bindings = small_span{m_info.bindings},
        };
    }

    /// Conversion operator to underlying handle.
    [[nodiscard]] inline operator handle_type() const noexcept { return m_handle; }

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] inline const information& info() const noexcept { return m_info; }

    /// Returns the underlying handle.
    [[nodiscard]] inline handle_type handle() const noexcept { return m_handle; }

    /// Returns a reference to the device this descriptor set layout uses.
    [[nodiscard]] inline const fuyu::device& device() const noexcept { return m_parent; }

    /// Returns the descriptor pool that allocated this set layout.
    [[nodiscard]] inline descriptor_pool_handle parent() const noexcept { return m_pool.handle; }

    /// Returns a view of the descriptor pool the array originates from.
    [[nodiscard]] descriptor_pool_view pool() const noexcept { return {m_pool.handle, m_parent, m_pool.flags}; }

    //------------------------------------------------------------------------------

    /**
     * @brief Releases the ownership over the underlying Vulkan handle.
     * The caller becomes responsible of properly managing the lifetime of the Vulkan handle.
     */
    [[nodiscard("The caller becomes responsible of destroying the handle")]] owning_view<view> release() noexcept
    {
        owning_view<view> result = {.value = {{
                                        .handle   = m_handle,
                                        .device   = device(),
                                        .parent   = m_pool.handle,
                                        .bindings = std::move(m_info.bindings),
                                    }}};

        m_handle = null_handle;
        m_info   = {};

        return result;
    }

    //------------------------------------------------------------------------------

    /// Indicates if this object has ownership over its handle and will destroy it when the destructor runs.
    [[nodiscard]] bool owns() const noexcept { return m_owner; }

    /// Indicates if the object borrows its handle and will NOT destroy it when the destructor runs.
    [[nodiscard]] bool borrows() const noexcept { return not owns(); }

    //------------------------------------------------------------------------------

    /// Swaps two objects.
    void swap(descriptor_set_layout& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(descriptor_set_layout& a, descriptor_set_layout& b) noexcept { a.swap(b); }

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
    friend auto rebind(descriptor_set_layout& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    struct parent_pool
    {
        descriptor_pool_handle      handle = null_handle; ///< The descriptor pool handle.
        VkDescriptorPoolCreateFlags flags  = {};          ///< The flags the parent was created with.
    };

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    descriptor_set_layout(token, descriptor_pool_view parent, information info) noexcept
        : m_parent{parent.device},
          m_pool{parent.handle, parent.flags},
          m_info{std::move(info)}
    {
    }

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Creates the descriptor set layout.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkDescriptorSetLayoutCreateInfo&) noexcept;

    /// Destroys the descriptor set layout if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type m_handle = {};  ///< Underlying Vulkan handle.
    parent_type m_parent;       ///< Parent device.
    parent_pool m_pool  = {};   ///< Pool from which the sets are allocated.
    information m_info  = {};   ///< Information about the descriptor set layout.
    bool        m_owner = true; ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... layout_pnext_chain_members>
inline descriptor_set_layout::descriptor_set_layout(descriptor_pool_view                              parent,
                                                    information                                       info,
                                                    const pnext_chain<layout_pnext_chain_members...>& chain)
    : descriptor_set_layout{token{}, parent, std::move(info)}
{
    auto bindings = collect<VkDescriptorSetLayoutBinding>(small_span<descriptor_binding::any>{m_info.bindings}.span());

    auto vk_info = to_underlying(m_info, bindings);
    fubuki::extend(vk_info, chain);

    if(const auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline descriptor_set_layout::descriptor_set_layout(external_handle<handle_type> handle, descriptor_pool_view parent, information info)
    : descriptor_set_layout{token{}, parent, std::move(info)}
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... layout_pnext_chain_members>
inline std::expected<descriptor_set_layout, api_call_info>
descriptor_set_layout::make(descriptor_pool_view parent, information info, const pnext_chain<layout_pnext_chain_members...>& chain)
{
    auto result = descriptor_set_layout{token{}, parent, std::move(info)};

    auto bindings = collect<VkDescriptorSetLayoutBinding>(small_span<descriptor_binding::any>{result.m_info.bindings}.span());

    auto vk_info = to_underlying(result.m_info, bindings);
    fubuki::extend(vk_info, chain);

    if(const auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<descriptor_set_layout, api_call_info>
descriptor_set_layout::make(external_handle<handle_type> handle, descriptor_pool_view parent, information info) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result     = descriptor_set_layout(token{}, parent, std::move(info));
    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_DESCRIPTOR_SET_LAYOUT_HPP
