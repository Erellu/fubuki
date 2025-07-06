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

#ifndef FUBUKI_FUYU_COMMAND_BUFFER_ARRAY_HPP
#define FUBUKI_FUYU_COMMAND_BUFFER_ARRAY_HPP

#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/command_buffer.hpp" // IWYU pragma: export
#include "fuyu/information/command_buffer.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/command_buffer.hpp"
#include "fuyu/views/command_pool.hpp"

namespace fubuki::fuyu
{

/**
 * An object representing an array of command buffers allocated from a common pool.
 *
 * Command buffers are objects used to record commands which can be subsequently submitted to a device queue for execution. There are two levels of
 * command buffers - primary command buffers, which can execute secondary command buffers, and which are submitted to queues, and secondary command
 * buffers, which can be executed by primary command buffers, and which are not directly submitted to queues.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkCommandBuffer.html
 */
class command_buffer_array
{

    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = command_buffer_handle;
    using parent_type = parent::device;
    using information = information::command_buffer_array;
    using view        = views::command_buffer_array;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param parent Parent pool from which the command buffers will be allocated.
     * @param info Information about the allocation.
     * @param chain Chain extending VkCommandBufferAllocateInfo.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * It can also throw an instance of std::bad_alloc if an intermediate (temporary) allocation failed.I
     */
    template<typename... pnext_chain_members>
    command_buffer_array(command_pool_view parent, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param parent Parent pool from which the command buffers will be allocated.
     * @param info Information about the allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * It can also throw an instance of std::bad_alloc if an intermediate (temporary) allocation failed.I
     */
    command_buffer_array(command_pool_view parent, information info) : command_buffer_array{parent, info, empty_pnext_chain} {}

    /**
     * Constructor.
     * @param handles The handles this object will borrow or take ownership over.
     * @param parent Parent pool from which the command buffers are allocated.
     * @param info Information about the allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    command_buffer_array(external_handle<small_vector<handle_type>> handles, command_pool_view parent, information info);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param parent Parent pool from which the command buffers will be allocated.
     * @param info Information about the allocation.
     * @param chain The chain extending VkCommandBufferAllocateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... layout_pnext_chain_members>
    [[nodiscard]]
    static std::expected<command_buffer_array, api_call_info>
    make(command_pool_view parent, information info, const pnext_chain<layout_pnext_chain_members...>& chain);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param parent Parent pool from which the command buffers will be allocated.
     * @param info Information about the allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]] static std::expected<command_buffer_array, api_call_info> make(command_pool_view parent, information info)
    {
        return make(parent, info, empty_pnext_chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handles The handles this object will borrow or take ownership over.
     * @param parent Parent pool from which the command buffers are allocated.
     * @param info Information about the allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<command_buffer_array, api_call_info>
    make(external_handle<small_vector<handle_type>> handles, command_pool_view parent, information info) noexcept;

    /// Destructor. Frees the underlying handles if this object owns them.
    ~command_buffer_array() noexcept
    {
        if(owns())
        {
            command_buffer_array::destroy();
        }
    }

    /// Move constructor.
    command_buffer_array(command_buffer_array&& other) noexcept
        : m_handles{std::exchange(other.m_handles, small_vector<handle_type>{})},
          m_parent{other.m_parent},
          m_pool{other.m_pool},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}

    {
    }

    /// Move assignment operator.
    command_buffer_array& operator=(command_buffer_array&& other) noexcept
    {
        swap(other);
        return *this;
    }

    command_buffer_array(const command_buffer_array&)            = delete;
    command_buffer_array& operator=(const command_buffer_array&) = delete;

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

    /// Returns a view of the front command buffer of this array. The behaviour is undefined if this array is empty.
    [[nodiscard]] command_buffer_view front() const noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        return {m_handles.front(), device(), m_pool, m_info.level};
    }

    /// Returns a view of the last command buffer of this array. The behaviour is undefined if this array is empty.
    [[nodiscard]] command_buffer_view back() const noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        return {m_handles.back(), device(), m_pool, m_info.level};
    }

    /// Returns a view of the command buffer at the given index. @throws Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] command_buffer_view at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }

        return {m_handles[idx], device(), m_pool, m_info.level};
    }

    /// Returns a view of the command buffer at the given index. The behaviour is undefined if `idx >= size()`.
    [[nodiscard]] command_buffer_view operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out-of-bounds (max: " << size() << ")");
        return {m_handles[idx], device(), m_pool, m_info.level};
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
    [[nodiscard]] operator view() const noexcept
    {
        return {.handles = small_span{m_handles}, .device = device(), .parent = m_pool, .level = m_info.level};
    }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns the underlying handle.
    [[nodiscard]] std::span<const handle_type> handle() const noexcept { return m_handles; }

    /// Returns a reference to the device this descriptor pool uses.
    [[nodiscard]] const fuyu::device& device() const noexcept { return m_parent; }

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] auto info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the handle of the command pool the array originates from.
    [[nodiscard]] command_pool_handle parent() const noexcept { return m_pool; }

    /// Returns a view of the command pool the array originates from.
    [[nodiscard]] command_pool_view pool() const noexcept { return {m_pool, device()}; }

    //------------------------------------------------------------------------------

    /**
     * @brief Releases the ownership over the underlying Vulkan handle.
     * The caller becomes responsible of properly managing the lifetime of the Vulkan handle.
     */
    [[nodiscard]]
    owning_view<view> release() noexcept
    {
        owning_view<view> result = {.value = {{
                                        .handles = std::move(m_handles),
                                        .device  = device(),
                                        .parent  = m_pool,
                                        .level   = m_info.level,
                                    }}};

        m_handles = {};

        return result;
    }

    //------------------------------------------------------------------------------

    /// Indicates if this object has ownership over its handles and will destroy them when the destructor runs.
    [[nodiscard]] bool owns() const noexcept { return m_owner; }

    /// Indicates if the object borrows its handles and will NOT destroy them when the destructor runs.
    [[nodiscard]] bool borrows() const noexcept { return not owns(); }

    //------------------------------------------------------------------------------

    /// Swaps two objects.
    void swap(command_buffer_array& other) noexcept
    {
        m_handles.swap(other.m_handles);
        m_parent.swap(other.m_parent);
        std::swap(m_pool, other.m_pool);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(command_buffer_array& a, command_buffer_array& b) noexcept { a.swap(b); }

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
    friend auto rebind(command_buffer_array& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    command_buffer_array(token, command_pool_view parent, information info) noexcept : m_parent{parent.device}, m_pool{parent.handle}, m_info{info} {}

    /// Creates the objects.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkCommandBufferAllocateInfo&) noexcept;

    /// Destroys the objects if they are not VK_NULL_HANDLE.
    FUBUKI_FUYU_API void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    small_vector<handle_type> m_handles = {};        ///< Underlying VkCommandBuffer.
    parent_type               m_parent;              ///< Device on which the command buffer is allocated.
    command_pool_handle       m_pool  = null_handle; ///< Pool from which the command buffers are allocated.
    information               m_info  = {};          ///< Command buffer information.
    bool                      m_owner = true;        ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline command_buffer_array::command_buffer_array(command_pool_view parent, information info, const pnext_chain<pnext_chain_members...>& chain)
    : command_buffer_array{token{}, parent, std::move(info)}
{
    auto vk_info = to_underlying(m_info, m_pool);
    fubuki::extend(vk_info, chain);

    if(const auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline command_buffer_array::command_buffer_array(external_handle<small_vector<handle_type>> handles, command_pool_view parent, information info)
    : command_buffer_array{token{}, parent, info}
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
inline std::expected<command_buffer_array, api_call_info>
command_buffer_array::make(command_pool_view parent, information info, const pnext_chain<layout_pnext_chain_members...>& chain)
{
    auto result = command_buffer_array{token{}, parent, info};

    auto vk_info = to_underlying(result.m_info, result.m_pool);
    fubuki::extend(vk_info, chain);

    if(const auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<command_buffer_array, api_call_info>
command_buffer_array::make(external_handle<small_vector<handle_type>> handles, command_pool_view parent, information info) noexcept
{
    auto result = command_buffer_array{token{}, parent, info};

    result.m_owner   = fuyu::indicates_ownership(handles);
    result.m_handles = fuyu::handle_of(std::move(handles));

    if(const auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_BUFFER_ARRAY_HPP
