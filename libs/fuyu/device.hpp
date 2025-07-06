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

#ifndef FUBUKI_FUYU_DEVICE_HPP
#define FUBUKI_FUYU_DEVICE_HPP

#include <functional>
#include <optional>
#include <utility>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/traits/parameter_pack.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/device.hpp"
#include "fuyu/functions/queue.hpp" // IWYU pragma: export (contains wait_idle)
#include "fuyu/information/device.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/queue.hpp"
#include "fuyu/unsupported_features.hpp"
#include "fuyu/views/device.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

class instance;

/**
 * A logical device.
 *
 * This object abstracts the creation of a VkDevice, and performs the following operations:
 * - Loads all function pointers of Vulkan Core matching the Vulkan version of the parent instance.
 * - Loads all extensions required, and their respective functions.
 * - Creates queues matching the requirements of
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkDevice.html
 */
class device
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = device_handle;
    using parent_type = parent::instance;
    using information = information::device;
    using view        = views::device;
    using functions   = device_functions;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param instance Instance this device belongs to.
     * @param physical_device The physical device linked to this logical device.
     * @param info Device information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param chain Chain extending VkDeviceCreateInfo.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @throws api_call_exception This constructor throws instance of api_call_info if the creation failed, or of std::bad_alloc if intermediate
     * (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    // No export, inlined below
    device(instance_cref                                               instance,
           physical_device_handle                                      physical_device,
           information                                                 info,
           const information::complements&                             complements,
           const pnext_chain<pnext_chain_members...>&                  chain,
           std::optional<std::reference_wrapper<unsupported_features>> unsupported = {});

    /**
     * Constructor.
     * @param instance Instance this device belongs to.
     * @param physical_device The physical device linked to this logical device.
     * @param info Device information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    device(instance_cref                                               instance,
           physical_device_handle                                      physical_device,
           information                                                 info,
           const information::complements&                             complements = {},
           std::optional<std::reference_wrapper<unsupported_features>> unsupported = {})
        : device(instance, physical_device, std::move(info), complements, empty_pnext_chain, unsupported)
    {
    }

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param instance Instance this device belongs to.
     * @param physical_device The physical device linked to this logical device.
     * @param info Device information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    device(external_handle<handle_type>    handle,
           instance_cref                   instance,
           physical_device_handle          physical_device,
           information                     info,
           const information::complements& complements);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     * @param instance Instance this device belongs to.
     * @param physical_device The physical device linked to this logical device.
     * @param info Device information.
     * @param chain Chain extending VkDeviceCreateInfo.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<device, api_call_info> make(instance_cref                                               instance,
                                                     physical_device_handle                                      physical_device,
                                                     information                                                 info,
                                                     const information::complements&                             complements,
                                                     const pnext_chain<pnext_chain_members...>&                  chain,
                                                     std::optional<std::reference_wrapper<unsupported_features>> unsupported = {});

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     *
     * @param instance Instance this device belongs to.
     * @param physical_device The physical device linked to this logical device.
     * @param info Device information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     * @param unsupported (optional) If provided, the features that were requested but filtered out are returned in this object.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]]
    static std::expected<device, api_call_info> make(instance_cref                                               instance,
                                                     physical_device_handle                                      physical_device,
                                                     information                                                 info,
                                                     const information::complements&                             complements,
                                                     std::optional<std::reference_wrapper<unsupported_features>> unsupported = {})
    {
        return make(instance, physical_device, std::move(info), complements, empty_pnext_chain, unsupported);
    }

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param instance Instance this device belongs to.
     * @param physical_device The physical device linked to this logical device.
     * @param info Device information.
     * @param complements Complement information required upon construction, but not kept for the duration of the object's lifetime.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]]
    static std::expected<device, api_call_info> make(external_handle<handle_type>    handle,
                                                     instance_cref                   instance,
                                                     physical_device_handle          physical_device,
                                                     information                     info,
                                                     const information::complements& complements);

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~device()
    {
        if(owns())
        {
            device::destroy();
        }
    }

    /// Move constructor.
    device(device&& other) noexcept
        : m_parent{other.m_parent},
          m_physical_device{std::exchange(other.m_physical_device, {})},
          m_info{std::exchange(other.m_info, information{})},
          m_handle{std::exchange(other.m_handle, handle_type{})},
          m_functions{std::exchange(other.m_functions, functions{})},
          m_queues{std::exchange(other.m_queues, {})},
          m_vulkan_version{std::exchange(other.m_vulkan_version, {})},
          m_owner{std::exchange(other.m_owner, false)}
    {
        for(auto& q : m_queues.all)
        {
            q.device = *this;
        }

        for(auto& q : m_queues.presentable)
        {
            q.device = *this;
        }
    }

    /// Move assignment operator.
    device& operator=(device&& other) noexcept
    {
        swap(other);
        return *this;
    }

    device(const device&)            = delete;
    device& operator=(const device&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Returns a pointer to the device functions.
    [[nodiscard]] const auto* operator->() const { return &m_functions; }

    /// Conversion operator as a view.
    [[nodiscard]] operator view() const noexcept
    {
        return {
            .handle    = m_handle,
            .instance  = m_parent,
            .version   = m_vulkan_version,
            .functions = m_functions,
            .hardware  = m_physical_device,
        };
    }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns the device functions.
    [[nodiscard]] const auto& function() const noexcept { return m_functions; }

    //------------------------------------------------------------------------------

    /// Returns a reference to the instance this device uses.
    [[nodiscard]] const fuyu::instance& instance() const noexcept { return m_parent; }

    //------------------------------------------------------------------------------

    /// Returns all queues available for the device.
    [[nodiscard]] device_queues::view queues() const noexcept { return m_queues; }

    //------------------------------------------------------------------------------

    /// Returns information about underlying physical device.
    [[nodiscard]] physical_device_handle physical_device() const noexcept { return m_physical_device; }

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
    void swap(device& other) noexcept
    {
        std::swap(m_parent, other.m_parent);
        std::swap(m_physical_device, other.m_physical_device);
        std::swap(m_info, other.m_info);
        std::swap(m_handle, other.m_handle);
        std::swap(m_functions, other.m_functions);
        m_queues.swap(other.m_queues);
        std::swap(m_vulkan_version, other.m_vulkan_version);
        std::swap(m_owner, other.m_owner);

        for(auto& q : m_queues.all)
        {
            q.device = *this;
        }

        for(auto& q : m_queues.presentable)
        {
            q.device = *this;
        }

        for(auto& q : other.m_queues.all)
        {
            q.device = other;
        }

        for(auto& q : other.m_queues.presentable)
        {
            q.device = other;
        }
    }

    /// Swaps two objects.
    friend void swap(device& a, device& b) noexcept { a.swap(b); }

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
    friend auto rebind(device& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    device(token, instance_cref instance, physical_device_handle physical_device, information info) noexcept
        : m_parent{instance},
          m_physical_device{physical_device},
          m_info{std::move(info)}
    {
    }

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Creates the device.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkDeviceCreateInfo&                                   base_info,
                                                                      const information::complements&                             complements,
                                                                      std::optional<std::reference_wrapper<unsupported_features>> unsupported_features
                                                                      = {});

    /// Destroys the device if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    parent_type            m_parent;                        ///< Instance this device is linked to.
    physical_device_handle m_physical_device = null_handle; ///< The physical device this object refers to.
    information            m_info            = {};          ///< Information known about how this object was created.
    handle_type            m_handle          = {};          ///< Underlying Vulkan handle.
    functions              m_functions       = {};          ///< Vulkan Core device functions. These are loaded automatically upon call to create().
    device_queues          m_queues          = {};          ///< Queues created by this device.
    version_number         m_vulkan_version  = {};          ///< The version the parent instance was created with.
    bool                   m_owner           = true;        ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline device::device(instance_cref                                               instance,
                      physical_device_handle                                      physical_device,
                      information                                                 info,
                      const information::complements&                             complements,
                      const pnext_chain<pnext_chain_members...>&                  chain,
                      std::optional<std::reference_wrapper<unsupported_features>> unsupported)
    : device(token{}, instance, physical_device, std::move(info))
{
    // Sanity checks
    {
        fubuki_assert(physical_device != null_handle, "Physical device cannot be nullptr.");
    }

    auto device_info = fubuki::make<VkDeviceCreateInfo>();
    fubuki::extend(device_info, chain);
    device_info.pEnabledFeatures = complements.features.has_value() ? std::addressof(*complements.features) : nullptr;

    if(const auto error = create(device_info, complements, unsupported))
    {
        throw api_call_exception{{*error}};
    }
}

inline device::device(external_handle<handle_type>    handle,
                      instance_cref                   instance,
                      physical_device_handle          physical_device,
                      information                     info,
                      const information::complements& complements)
    : device(token{}, instance, physical_device, std::move(info))
{
    // Sanity checks
    {
        fubuki_assert(physical_device != null_handle, "Physical device cannot be nullptr.");
    }

    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);

    if(const auto error = create({}, complements, {}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<device, api_call_info> device::make(instance_cref                                               instance,
                                                         physical_device_handle                                      physical_device,
                                                         information                                                 info,
                                                         const information::complements&                             complements,
                                                         const pnext_chain<pnext_chain_members...>&                  chain,
                                                         std::optional<std::reference_wrapper<unsupported_features>> unsupported)
{
    auto result = device(token{}, instance, physical_device, std::move(info));

    // Sanity checks
    {
        fubuki_assert(physical_device != null_handle, "Physical device cannot be nullptr.");
    }

    auto device_info = fubuki::make<VkDeviceCreateInfo>();
    fubuki::extend(device_info, chain);
    device_info.pEnabledFeatures = complements.features.has_value() ? std::addressof(*complements.features) : nullptr;

    if(const auto error = result.create(device_info, complements, unsupported))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<device, api_call_info> device::make(external_handle<handle_type>    handle,
                                                         instance_cref                   instance,
                                                         physical_device_handle          physical_device,
                                                         information                     info,
                                                         const information::complements& complements)
{
    auto result = device(token{}, instance, physical_device, std::move(info));

    // Sanity checks
    {
        fubuki_assert(physical_device != null_handle, "Physical device cannot be nullptr.");
    }

    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(const auto error = result.create({}, complements, {}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_DEVICE_HPP
