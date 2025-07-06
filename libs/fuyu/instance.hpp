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

#ifndef FUBUKI_FUYU_INSTANCE_HPP
#define FUBUKI_FUYU_INSTANCE_HPP

#include <functional>
#include <optional>
#include <utility>

#include <core/config/macros.hpp>
#include <core/future/flat_set.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/instance.hpp"
#include "fuyu/information/instance.hpp"
#include "fuyu/unsupported_features.hpp"
#include "fuyu/views/instance.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

/**
 * There is no global state in Vulkan and all per-application state is stored in a VkInstance object. Creating a VkInstance object initializes the
 * Vulkan library and allows the application to pass information about itself to the implementation.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkInstance.html
 */
class instance
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = instance_handle;
    using information = information::instance;
    using view        = views::instance;
    using functions   = instance_functions;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param info Instance information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param chain Chain extendeing VkInstanceCreateInfo.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    // No export, inlined below
    instance(information                                                 info,
             const information::complements&                             complements,
             const pnext_chain<pnext_chain_members...>&                  chain,
             std::optional<std::reference_wrapper<unsupported_features>> unsupported = {});

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param info Information about how the instance was allocated.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed. This constructor CAN throw an
     * instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    instance(external_handle<handle_type> handle, information info, const information::complements& complements);

    /**
     * Constructor.
     * @param info Instance information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    instance(information                                                 info,
             const information::complements&                             complements,
             std::optional<std::reference_wrapper<unsupported_features>> unsupported = {})
        : instance(std::move(info), complements, empty_pnext_chain, unsupported)
    {
    }

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     * @param info Instance information.
     * @param chain Chain extendeing VkInstanceCreateInfo.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<instance, api_call_info> make(information                                                 info,
                                                       const information::complements&                             complements,
                                                       const pnext_chain<pnext_chain_members...>&                  chain,
                                                       std::optional<std::reference_wrapper<unsupported_features>> unsupported = {});

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param info Instance information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]]
    static std::expected<instance, api_call_info>
    make(information info, const information::complements& complements, std::optional<std::reference_wrapper<unsupported_features>> unsupported = {})
    {
        return make(std::move(info), complements, empty_pnext_chain, unsupported);
    }

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param info Information about how the instance was allocated.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     *
     * @throws api_call_exception This constructor CAN throw an instance of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]]
    static std::expected<instance, api_call_info>
    make(external_handle<handle_type> handle, information info, const information::complements& complements);

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~instance() noexcept
    {
        if(owns())
        {
            instance::destroy();
        }
    }

    /// Move constructor.
    instance(instance&& other) noexcept
        : m_handle{std::exchange(other.m_handle, handle_type{})},
          m_info{std::exchange(other.m_info, information{})},
          m_functions{std::exchange(other.m_functions, functions{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    instance& operator=(instance&& other) noexcept
    {
        swap(other);
        return *this;
    }

    instance(const instance&)            = delete;
    instance& operator=(const instance&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Conversion operator as a view.
    [[nodiscard]] operator view() const noexcept
    {
        return {
            .handle    = m_handle,
            .version   = m_info.application.vulkan_version,
            .functions = m_functions,
        };
    }

    /// Returns a pointer to the instance functions.
    [[nodiscard]] const auto* operator->() const noexcept { return &m_functions; }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns the instance functions.
    [[nodiscard]] const auto& function() const noexcept { return m_functions; }

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
    void swap(instance& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_info, other.m_info);
        std::swap(m_functions, other.m_functions);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(instance& a, instance& b) noexcept { a.swap(b); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    instance(token, information info) noexcept : m_info{std::move(info)} {}

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Creates the instance.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkInstanceCreateInfo&                                 info,
                                                                      const information::complements&                             complements,
                                                                      std::optional<std::reference_wrapper<unsupported_features>> unsupported);

    /// Destroys the instance and its debug messenger when they are not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type m_handle    = {};   ///< Underlying Vulkan handle.
    information m_info      = {};   ///< Instance info.
    functions   m_functions = {};   ///< Instance functions.
    bool        m_owner     = true; ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline instance::instance(information                                                 info,
                          const information::complements&                             complements,
                          const pnext_chain<pnext_chain_members...>&                  chain,
                          std::optional<std::reference_wrapper<unsupported_features>> unsupported_features)
    : instance(token{}, std::move(info))
{
    // Everything but the pnext chain is done in create()
    VkInstanceCreateInfo vk_info = {
        .sType                   = structure_type_v<VkInstanceCreateInfo>,
        .pNext                   = nullptr,
        .flags                   = {},
        .pApplicationInfo        = nullptr,
        .enabledLayerCount       = 0,
        .ppEnabledLayerNames     = {},
        .enabledExtensionCount   = {},
        .ppEnabledExtensionNames = {},
    };

    extend(vk_info, chain);

    if(const auto error = create(vk_info, complements, unsupported_features))
    {
        throw api_call_exception{{*error}};
    }
}

inline instance::instance(external_handle<handle_type> handle, information info, const information::complements& complements)
    : instance(token{}, std::move(info))
{
    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);

    if(const auto error = create({}, complements, {}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<instance, api_call_info> instance::make(information                                                 info,
                                                             const information::complements&                             complements,
                                                             const pnext_chain<pnext_chain_members...>&                  chain,
                                                             std::optional<std::reference_wrapper<unsupported_features>> unsupported_features)
{
    auto result = instance(token{}, std::move(info));

    // Everything but the pnext chain is done in create()
    VkInstanceCreateInfo vk_info = {
        .sType                   = structure_type_v<VkInstanceCreateInfo>,
        .pNext                   = nullptr,
        .flags                   = {},
        .pApplicationInfo        = nullptr,
        .enabledLayerCount       = 0,
        .ppEnabledLayerNames     = {},
        .enabledExtensionCount   = {},
        .ppEnabledExtensionNames = {},
    };

    extend(vk_info, chain);

    if(const auto error = result.create(vk_info, complements, unsupported_features))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<instance, api_call_info>
instance::make(external_handle<handle_type> handle, information info, const information::complements& complements)
{
    auto result = instance(token{}, std::move(info));

    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(const auto error = result.create({}, complements, {}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_INSTANCE_HPP
