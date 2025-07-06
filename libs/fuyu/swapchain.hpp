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

#ifndef FUBUKI_FUYU_SWAPCHAIN_HPP
#define FUBUKI_FUYU_SWAPCHAIN_HPP

#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/swapchain.hpp" // IWYU pragma: export
#include "fuyu/information/swapchain.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/owning.hpp"
#include "fuyu/views/swapchain.hpp"

namespace fubuki::fuyu
{

/**
 * A swapchain object (a.k.a. swapchain) provides the ability to present rendering results to a surface.
 *
 * A swapchain is an abstraction for an array of presentable images that are associated with a surface. The presentable images are represented by
 * VkImage objects created by the platform. One image (which can be an array image for multiview/stereoscopic-3D surfaces) is displayed at a time, but
 * multiple images can be queued for presentation. An application renders to the image, and then queues the image for presentation to the surface.
 *
 * A native window cannot be associated with more than one non-retired swapchain at a time. Further, swapchains cannot be created for native windows
 * that have a non-Vulkan graphics API surface associated with them.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkSwapchainKHR.html
 */
class swapchain
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = swapchain_khr_handle;
    using parent_type = parent::device;
    using information = information::swapchain;
    using view        = views::swapchain;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param device Device on which resource will be allocated.
     * @param surface The surface referenced by this swapchain.
     * @param info Information about resource allocation.
     * @param pnext Chain extending VkSwapchainCreateInfoKHR.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    template<typename... pnext_elements>
    swapchain(device_cref device, surface_khr_handle surface, information info, const pnext_chain<pnext_elements...>& pnext);

    /**
     * Constructor.
     * @param device Device on which resource will be allocated.
     * @param surface The surface referenced by this swapchain.
     * @param info Information about resource allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    swapchain(device_cref device, surface_khr_handle surface, information info) : swapchain{device, surface, std::move(info), empty_pnext_chain} {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param surface The surface referenced by this swapchain.
     * @param info Information about the handle allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    swapchain(external_handle<handle_type> handle, device_cref device, surface_khr_handle surface, information info);

    /**
     * Equivalent of a noexcept constructor.
     * @param device Device on which resource will be allocated.
     * @param surface The surface referenced by this swapchain.
     * @param info Information about resource allocation.
     * @param pnext Chain extending VkSwapchainCreateInfoKHR.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    template<typename... pnext_elements>
    [[nodiscard]] static std::expected<swapchain, api_call_info>
    make(device_cref device, surface_khr_handle surface, information info, const pnext_chain<pnext_elements...>& pnext) noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param device Device on which resource will be allocated.
     * @param surface The surface referenced by this swapchain.
     * @param info Information about resource allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<swapchain, api_call_info> make(device_cref device, surface_khr_handle surface, information info) noexcept
    {
        return make(device, surface, std::move(info), empty_pnext_chain);
    }

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param surface The surface referenced by this swapchain.
     * @param info Information about the handle allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<swapchain, api_call_info>
    make(external_handle<handle_type> handle, device_cref device, surface_khr_handle surface, information info);

    /// Destructor .Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~swapchain() noexcept
    {
        if(owns())
        {
            swapchain::destroy();
        }
    }

    /// Move constructor.
    swapchain(swapchain&& other) noexcept
        : m_handle{std::exchange(other.m_handle, handle_type{})},
          m_parent{other.m_parent},
          m_surface{other.m_surface},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    swapchain& operator=(swapchain&& other) noexcept
    {
        swap(other);
        return *this;
    }

    swapchain(const swapchain&)            = delete;
    swapchain& operator=(const swapchain&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Conversion operator to view.
    [[nodiscard]] operator view() const noexcept { return {m_handle, m_parent, m_surface}; }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns the handle of the surface used to create this object.
    [[nodiscard]] auto surface() const noexcept { return m_surface; }

    /// Returns a reference to the device from which this object was created.
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
    void swap(swapchain& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
        std::swap(m_surface, other.m_surface);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(swapchain& a, swapchain& b) noexcept { a.swap(b); }

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
    friend auto rebind(swapchain& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    swapchain(token, device_cref device, surface_khr_handle surface, information info) noexcept
        : m_parent{device},
          m_surface{surface},
          m_info{std::move(info)}
    {
    }

#if defined(VK_KHR_swapchain)
    FUBUKI_FUYU_API
    friend std::expected<void, api_call_info> detail::recreate(swapchain& swap_chain, const VkSwapchainCreateInfoKHR& info) noexcept;

    FUBUKI_FUYU_API
    friend std::expected<VkSwapchainCreateInfoKHR, api_call_info> detail::prepare(swapchain&, std::optional<VkExtent2D>) noexcept;

#endif // defined(VK_KHR_swapchain)

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

#if defined(VK_KHR_swapchain)
    /// Creates the underlying resource.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkSwapchainCreateInfoKHR& info) noexcept;
#endif // defined(VK_KHR_swapchain)

    /// Destroys the underlying resource if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type        m_handle = {};    ///< Underlying Vulkan handle.
    parent_type        m_parent;         ///< Device on which the handle is allocated.
    surface_khr_handle m_surface = {};   ///< The render pass for which this framebuffer was created
    information        m_info    = {};   ///< Information about how the allocation was performed.
    bool               m_owner   = true; ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_elements>
inline swapchain::swapchain(device_cref dev, surface_khr_handle surface, information info, const pnext_chain<pnext_elements...>& pnext)
    : swapchain{token{}, dev, surface, std::move(info)}
{
    if(const auto check = fuyu::make_compatible(m_info, m_parent.ref, m_surface); not check)
    {
        throw api_call_exception{check.error()};
    }

    auto vk_info = to_underlying(m_info, m_surface, null_handle);
    fubuki::extend(vk_info, pnext);

    if(auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline swapchain::swapchain(external_handle<handle_type> handle, device_cref device, surface_khr_handle surface, information info)
    : swapchain{token{}, device, surface, std::move(info)}
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... pnext_elements>
[[nodiscard]] inline std::expected<swapchain, api_call_info>
swapchain::make(device_cref device, surface_khr_handle surface, information info, const pnext_chain<pnext_elements...>& pnext) noexcept
{
    auto result = swapchain(token{}, device, surface, std::move(info));

    if(const auto check = fuyu::make_compatible(result.m_info, result.m_parent.ref, result.m_surface); not check)
    {
        return std::unexpected{check.error()};
    }

    auto vk_info = to_underlying(result.m_info, result.m_surface, null_handle);
    fubuki::extend(vk_info, pnext);

    if(auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]] inline std::expected<swapchain, api_call_info>
swapchain::make(external_handle<handle_type> handle, device_cref device, surface_khr_handle surface, information info)
{
    auto result     = swapchain(token{}, device, surface, std::move(info));
    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_SWAPCHAIN_HPP
