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

#ifndef FUBUKI_FUYU_DEBUG_MESSENGER_HPP
#define FUBUKI_FUYU_DEBUG_MESSENGER_HPP

#include <functional>
#include <utility>

#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/information/debug_messenger.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/debug_messenger.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

class instance;

namespace debug
{

/**
 * A messenger sink that intercepts validation layer messages and processes them according to a user-defined function.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkDebugUtilsMessengerEXT.html
 */
class messenger
{
    struct token
    {
    };

public:
    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using parent_type = parent::instance;

#if defined(VK_EXT_debug_utils)
    using handle_type = debug_utils_messenger_ext_handle;
#endif // #if defined(VK_EXT_debug_utils)

    using information = information::debug_messenger;
    using view        = views::debug_messenger;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param instance Instance for which the messenger will be create.
     * @param info Information about memory allocation.
     * @param chain Chain extending VkDebugUtilsMessengerCreateInfoEXT.
     *
     *  @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    template<typename... pnext_chain_members>
    // No export, inlined below
    messenger(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param instance Instance for which the messenger will be create.
     * @param info Information about memory allocation.
     *
     *  @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    messenger(instance_cref instance, information info) : messenger{instance, info, empty_pnext_chain} {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param instance Instance on which the handle was allocated.
     * @param info Information about the handle allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    messenger(external_handle<handle_type> handle, instance_cref instance, information info);

    /**
     * Equivalent of a noexcept constructor.
     * @param instance Instance for which the messenger will be create.
     * @param info Information about memory allocation.
     * @param chain Chain extending VkDebugUtilsMessengerCreateInfoEXT.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<messenger, api_call_info>
    make(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param instance Instance for which the messenger will be create.
     * @param info Information about memory allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<messenger, api_call_info> make(instance_cref instance, information info) noexcept
    {
        return make(instance, info, empty_pnext_chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param instance Instance on which the handle was allocated.
     * @param info Information about the handle allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<messenger, api_call_info>
    make(external_handle<handle_type> handle, instance_cref instance, information info) noexcept;

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~messenger() noexcept
    {
        if(owns())
        {
            messenger::destroy();
        }
    }

    /// Move constructor.
    messenger(messenger&& other) noexcept
        :
#if defined(VK_EXT_debug_utils)
          m_handle{std::exchange(other.m_handle, null_handle)},
#endif // defined(VK_EXT_debug_utils)
          m_parent{other.m_parent},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    messenger& operator=(messenger&& other) noexcept
    {
        swap(other);
        return *this;
    }

    messenger(const messenger&)            = delete;
    messenger& operator=(const messenger&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

#if defined(VK_EXT_debug_utils)
    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }
#endif // defined(VK_EXT_debug_utils)

    /// Conversion operator to a view of this object.
    [[nodiscard]] operator view() const noexcept
    {
#if defined(VK_EXT_debug_utils)
        return {m_handle, m_parent};
#else
        return {};
#endif // defined(VK_EXT_debug_utils)
    }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

#if defined(VK_EXT_debug_utils)
    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }
#endif // defined(VK_EXT_debug_utils)

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const auto& info() const noexcept { return m_info; }

    /// Returns a const reference to the instance this object was created from.
    [[nodiscard]] const fuyu::instance& instance() const noexcept { return m_parent; }

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
    void swap(messenger& other) noexcept
    {
#if defined(VK_EXT_debug_utils)
        std::swap(m_handle, other.m_handle);
#endif // defined(VK_EXT_debug_utils)

        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(messenger& a, messenger& b) noexcept { a.swap(b); }

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
    friend auto rebind(messenger& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    messenger(token, instance_cref instance, information info) noexcept : m_parent{instance}, m_info{info} {}

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

#if defined(VK_EXT_debug_utils)
    /// Creates the messenger.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkDebugUtilsMessengerCreateInfoEXT& info) noexcept;
#endif // defined(VK_EXT_debug_utils)

    /// Destroys the messenger if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

#if defined(VK_EXT_debug_utils)
    handle_type m_handle = {}; ///< Underlying handle.
#endif                         // defined(VK_EXT_debug_utils)

    parent_type m_parent;       ///< Instance this messenger is linked to.
    information m_info  = {};   ///< Information known about the allocation of this object.
    bool        m_owner = true; ///< Indicates if this object has ownership over its handle.
};

template<typename... pnext_chain_members>
inline messenger::messenger(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain)
    : messenger{token{}, instance, std::move(info)}
{

#if defined(VK_EXT_debug_utils)
    auto vk_info = to_underlying(m_info);
    fubuki::extend(vk_info, chain);

    if(const auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
#endif // defined(VK_EXT_debug_utils)
}

inline messenger::messenger(external_handle<handle_type> handle, instance_cref instance, information info) : messenger(token{}, instance, info)
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner = fuyu::indicates_ownership(handle);

#if defined(VK_EXT_debug_utils)
    m_handle = fuyu::handle_of(handle);

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
#endif // defined(VK_EXT_debug_utils)
}

template<typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<messenger, api_call_info>
messenger::make(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept
{
    auto result = messenger{token{}, instance, info};

#if defined(VK_EXT_debug_utils)
    auto vk_info = to_underlying(result.m_info);
    fubuki::extend(vk_info, chain);

    if(const auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }
#endif // defined(VK_EXT_debug_utils)

    return result;
}

[[nodiscard]]
inline std::expected<messenger, api_call_info> messenger::make(external_handle<handle_type> handle, instance_cref instance, information info) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result    = messenger(token{}, instance, info);
    result.m_owner = fuyu::indicates_ownership(handle);

#if defined(VK_EXT_debug_utils)
    result.m_handle = fuyu::handle_of(handle);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }
#endif // defined(VK_EXT_debug_utils)

    return result;
}

} // namespace debug

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_DEBUG_MESSENGER_HPP
