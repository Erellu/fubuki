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

#ifndef FUBUKI_FUYU_MEMORY_HPP
#define FUBUKI_FUYU_MEMORY_HPP

#include <utility>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/memory.hpp" // IWYU pragma: export
#include "fuyu/information/memory.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/memory.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

/**
 * Memory to bind to a buffer or an image.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkDeviceMemory.html
 */
class memory
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = device_memory_handle;
    using parent_type = parent::device;
    using information = information::memory;
    using view        = views::memory;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param device Device on which memory will be allocated.
     * @param info Information about memory allocation.
     * @param chain Chain extending VkAllocateMemoryInfo.
     */
    template<typename... pnext_chain_members>
    memory(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param device Device on which memory will be allocated.
     * @param info Information about memory allocation.
     */
    memory(device_cref device, information info) : memory(device, std::move(info), empty_pnext_chain) {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param info Information about the handle allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    memory(external_handle<handle_type> handle, device_cref device, information info);

    /**
     * Equivalent of a noexcept constructor.
     * @param device Device on which the memory will be allocated.
     * @param info Information about the memory allocation.
     * @param chain Chain extending VkMemoryAllocateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<memory, api_call_info> make(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param device Device on which the memory will be allocated.
     * @param info Information about the memory allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<memory, api_call_info> make(device_cref device, information info) noexcept
    {
        return make(device, std::move(info), empty_pnext_chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param info Information about the handle allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<memory, api_call_info>
    make(external_handle<handle_type> handle, device_cref device, information info) noexcept;

    /// Destructor. Frees the allocated memory if it is not VK_NULL_HANDLE.
    ~memory() noexcept
    {
        if(owns())
        {
            memory::destroy();
        }
    }

    /// Move constructor.
    memory(memory&& other) noexcept
        : m_handle{std::exchange(other.m_handle, handle_type{})},
          m_parent{other.m_parent},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    memory& operator=(memory&& other) noexcept
    {
        swap(other);
        return *this;
    }

    memory(const memory&)            = delete;
    memory& operator=(const memory&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Converts this object to a view of its resources.
    [[nodiscard]] operator view() const noexcept
    {
#if defined(VK_VERSION_1_1)
        const auto& requirements = m_info.requirements.memoryRequirements;
#else
        const auto& requirements = m_info.requirements;
#endif // defined(VK_VERSION_1_1)

        return {
            .handle       = m_handle,
            .device       = m_parent,
            .requirements = requirements,
        };
    }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the number of bytes allocated for this memory object.
    /// @note Equivalent to info().requirements.memoryRequirements.size
    [[nodiscard]] VkDeviceSize size() const noexcept
    {
#if defined(VK_VERSION_1_1)
        return m_info.requirements.memoryRequirements.size;
#else
        return m_info.requirements.size;
#endif // defined(VK_VERSION_1_1)
    }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns a reference to the device this memory region uses.
    [[nodiscard]] const fuyu::device& device() const noexcept { return m_parent; }

    //------------------------------------------------------------------------------

    /**
     * @brief Releases the ownership over the underlying Vulkan handle.
     * The caller becomes responsible of properly managing the lifetime of the Vulkan handle.
     */
    [[nodiscard("The caller becomes responsible of destroying the handle")]] owning_view<view> release() noexcept
    {
        owning_view<view> result = {.value = {*this}};

        m_handle = null_handle;

        return result;
    }

    //------------------------------------------------------------------------------

    /// Indicates if this object has ownership over its handle and will destroy it when the destructor runs.
    [[nodiscard]] bool owns() const noexcept { return m_owner; }

    /// Indicates if the object borrows its handle and will NOT destroy it when the destructor runs.
    [[nodiscard]] bool borrows() const noexcept { return not owns(); }

    //------------------------------------------------------------------------------

    /// Swaps two objects.
    void swap(memory& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(memory& a, memory& b) noexcept { a.swap(b); }

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
    friend auto rebind(memory& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    memory(token, device_cref device, information info) noexcept : m_parent{device}, m_info{std::move(info)} {}

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    [[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_FUYU_API std::expected<std::uint32_t, api_call_info> find_memory_index() const noexcept;

    /// Allocates memory on the device.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkMemoryAllocateInfo&) noexcept;

    /// Frees the allocated memory if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type m_handle = {};  ///< Underlying Vulkan handle.
    parent_type m_parent;       ///< Device on which memory is allocated.
    information m_info  = {};   ///< Memory information.
    bool        m_owner = true; ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline memory::memory(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain)
    : memory(token{}, device, std::move(info))
{
    const auto memory_index = find_memory_index();

    if(not memory_index)
    {
        throw api_call_exception{memory_index.error()};
    }

    auto vk_info = to_underlying(m_info, *memory_index);
    fubuki::extend(vk_info, chain);

    if(auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline memory::memory(external_handle<handle_type> handle, device_cref device, information info) : memory(token{}, device, std::move(info))
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<memory, api_call_info>
memory::make(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept
{
    auto result = memory(token{}, device, std::move(info));

    const auto memory_index = result.find_memory_index();

    if(not memory_index)
    {
        return std::unexpected{memory_index.error()};
    }

    auto vk_info = to_underlying(result.m_info, *memory_index);
    fubuki::extend(vk_info, chain);

    if(auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<memory, api_call_info> memory::make(external_handle<handle_type> handle, device_cref device, information info) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result     = memory(token{}, device, std::move(info));
    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_MEMORY_HPP
