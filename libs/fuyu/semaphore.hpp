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

#ifndef FUBUKI_FUYU_SEMAPHORE_HPP
#define FUBUKI_FUYU_SEMAPHORE_HPP

#include <optional>
#include <utility>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/semaphore.hpp" // IWYU pragma: export
#include "fuyu/information/semaphore.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/owning.hpp"
#include "fuyu/views/semaphore.hpp"

namespace fubuki::fuyu
{

/**
 * A synchronisation primitive that can be used to insert a dependency between operations.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkSemaphore.html
 */
class semaphore
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = semaphore_handle;
    using parent_type = parent::device;
    using information = information::semaphore;
    using view        = views::semaphore;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param device Device on which the semaphore will be allocated.
     * @param info Information about the semaphore allocation.
     * @param chain Chain extending VkSemaphoreCreateInfo.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    template<typename... pnext_chain_members>
    semaphore(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param device Device on which the semaphore will be allocated.
     * @param info Information about the semaphore allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    semaphore(device_cref device, information info) : semaphore(device, std::move(info), empty_pnext_chain) {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param info Information about the handle allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    semaphore(external_handle<handle_type> handle, device_cref device, information info);

#if defined(VK_VERSION_1_2)
    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param info Information about the handle allocation.
     * @param type Type of the semaphore, specified through the pNext chain in the original allocation by a VkSemaphoreTypeCreateInfo.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    semaphore(external_handle<handle_type> handle, device_cref device, information info, VkSemaphoreType type);
#endif //   defined(VK_VERSION_1_2)

    /**
     * Equivalent of a noexcept constructor.
     * @param device Device on which the semaphore will be allocated.
     * @param info Information about the semaphore allocation.
     * @param chain Chain extending VkSemaphoreCreateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<semaphore, api_call_info>
    make(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param device Device on which the semaphore will be allocated.
     * @param info Information about the semaphore allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<semaphore, api_call_info> make(device_cref device, information info) noexcept
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
    [[nodiscard]] static std::expected<semaphore, api_call_info>
    make(external_handle<handle_type> handle, device_cref device, information info) noexcept;

#if defined(VK_VERSION_1_2)
    /**
     * Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param info Information about the handle allocation.
     * @param type Type of the semaphore, specified through the pNext chain in the original allocation by a VkSemaphoreTypeCreateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<semaphore, api_call_info>
    make(external_handle<handle_type> handle, device_cref device, information info, VkSemaphoreType type) noexcept;
#endif // defined(VK_VERSION_1_2)

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~semaphore() noexcept
    {
        if(owns())
        {
            semaphore::destroy();
        }
    }

    /// Move constructor.
    semaphore(semaphore&& other) noexcept
        : m_handle{std::exchange(other.m_handle, handle_type{})},
          m_parent{other.m_parent},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
#if defined(VK_VERSION_1_2)
          ,
          m_type{std::exchange(other.m_type, std::nullopt)}
#endif
    {
    }

    /// Move assignment operator.
    semaphore& operator=(semaphore&& other) noexcept
    {
        swap(other);
        return *this;
    }

    semaphore(const semaphore&)            = delete;
    semaphore& operator=(const semaphore&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Conversion operator to view.
    [[nodiscard]] operator view() const noexcept { return {m_handle, m_parent}; }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

#if defined(VK_VERSION_1_2)
    /// Indicates if this semaphore has a special type, that was indicated by a VkSemaphoreTypeCreateInfo in the pNext chain upon allocation.
    [[nodiscard]] const auto& type() const noexcept { return m_type; }
#endif // defined(VK_VERSION_1_2)

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns a reference to the device this semaphore uses.
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
    void swap(semaphore& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);

#if defined(VK_VERSION_1_2)
        std::swap(m_type, other.m_type);
#endif
    }

    /// Swaps two objects.
    friend void swap(semaphore& a, semaphore& b) noexcept { a.swap(b); }

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
    friend auto rebind(semaphore& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    semaphore(token, device_cref device, information info) noexcept : m_parent{device}, m_info{std::move(info)} {}

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Reads the contents of a pnext chain back into the class members.
    /// Called before create() upon construction.
    template<typename... pnext_chain_members>
    void read(const pnext_chain<pnext_chain_members...>& chain) noexcept;

    /// Creates the semaphore.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkSemaphoreCreateInfo& info) noexcept;

    /// Destroys the semaphore if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type m_handle = {};  ///< Handle.
    parent_type m_parent;       ///< Device on which the handle is allocated.
    information m_info  = {};   ///< Information.
    bool        m_owner = true; ///< Indicates if this object has ownership over its handle.

#if defined(VK_VERSION_1_2)
    std::optional<VkSemaphoreType> m_type = {}; ///< Semaphore type. Only filled when a VkSemaphoreTypeCreateInfo is provided.
#endif                                          // defined(VK_VERSION_1_2)
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline semaphore::semaphore(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain)
    : semaphore(token{}, device, std::move(info))
{
    read(chain);

    auto vk_info = to_underlying(m_info);
    fubuki::extend(vk_info, chain);

    if(const auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline semaphore::semaphore(external_handle<handle_type> handle, device_cref device, information info) : semaphore(token{}, device, std::move(info))
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

#if defined(VK_VERSION_1_2)
inline semaphore::semaphore(external_handle<handle_type> handle, device_cref device, information info, VkSemaphoreType type)
    : semaphore(token{}, device, std::move(info))
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);
    m_type   = type;

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}
#endif // defined(VK_VERSION_1_2)

template<typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<semaphore, api_call_info>
semaphore::make(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept
{
    auto result = semaphore(token{}, device, std::move(info));
    result.read(chain);

    auto vk_info = to_underlying(result.m_info);
    fubuki::extend(vk_info, chain);

    if(auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<semaphore, api_call_info> semaphore::make(external_handle<handle_type> handle, device_cref device, information info) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result     = semaphore(token{}, device, std::move(info));
    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

#if defined(VK_VERSION_1_2)

[[nodiscard]]
inline std::expected<semaphore, api_call_info>
semaphore::make(external_handle<handle_type> handle, device_cref device, information info, VkSemaphoreType type) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result     = semaphore(token{}, device, std::move(info));
    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);
    result.m_type   = type;

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

#endif // defined(VK_VERSION_1_2)

template<typename... pnext_chain_members>
inline void semaphore::read([[maybe_unused]] const pnext_chain<pnext_chain_members...>& chain) noexcept
{
#if defined(VK_VERSION_1_2)
    if constexpr(traits::parameter_pack::contains_v<VkSemaphoreTypeCreateInfo, pnext_chain_members...>)
    {
        const auto& type = std::get<VkSemaphoreTypeCreateInfo&>(chain.data());
        m_type           = type.semaphoreType;
    }
#endif // defined(VK_VERSION_1_2)
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_SEMAPHORE_HPP
