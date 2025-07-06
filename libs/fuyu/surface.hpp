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

#ifndef FUBUKI_FUYU_SURFACE_HPP
#define FUBUKI_FUYU_SURFACE_HPP

#include <utility>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/surface_data.hpp>
#include <core/traits/surface.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/surface.hpp" // IWYU pragma: export
#include "fuyu/information/surface.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/owning.hpp"
#include "fuyu/views/surface.hpp"

namespace fubuki::fuyu
{

class instance;

/**
 * Surface to render to.
 * One surface is associated to one window.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkSurfaceKHR.html
 */
class surface
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using parent_type = parent::instance;

#if defined(VK_KHR_surface)
    using handle_type = surface_khr_handle;
    using information = information::surface;
    using view        = views::surface;
#endif // #if defined(VK_KHR_surface)

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param instance Surface for which the surface will be created.
     * @param info Information about the surface created.
     * @param chain Chain extending the platform-specific Vulkan structure that will be used to create the surface.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    template<typename... pnext_chain_members>
    surface(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param instance Surface for which the surface will be created.
     * @param info Information about the surface created.
     * @param chain Chain extending the platform-specific Vulkan structure that will be used to create the surface.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    template<typename... pnext_chain_members>
    surface(instance_cref instance, surface_data info, const pnext_chain<pnext_chain_members...>& chain) : surface(instance, information{info}, chain)
    {
    }

    /**
     * Constructor.
     * @param instance Instance for which the surface will be created.
     * @param info Information about the surface created.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    surface(instance_cref instance, information info) : surface(instance, std::move(info), empty_pnext_chain) {}

    /**
     * Constructor.
     * @param instance Instance for which the surface will be created.
     * @param info Platform-specific information about the surface created.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    surface(instance_cref instance, surface_data info) : surface(instance, information{.platform = info}) {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param instance Instance on which the handle was allocated.
     * @param info Information about the handle allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    surface(external_handle<handle_type> handle, instance_cref instance, information info);

    /**
     * Equivalent of a noexcept constructor.
     * @param instance Instance for which the surface will be created.
     * @param info Information about the surface creation.
     * @param chain Chain extending the platform-specific Vulkan structure that will be used to create the surface.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<surface, api_call_info>
    make(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param instance Instance for which the surface will be created.
     * @param info Platform-specific information about the surface created.
     * @param chain Chain extending the platform-specific Vulkan structure that will be used to create the surface.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<surface, api_call_info>
    make(instance_cref instance, surface_data info, const pnext_chain<pnext_chain_members...>& chain) noexcept
    {
        return make(instance, information{info}, chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param instance Instance for which the surface will be created.
     * @param info Information about the surface creation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<surface, api_call_info> make(instance_cref instance, information info) noexcept
    {
        return make(instance, std::move(info), empty_pnext_chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param instance Instance for which the surface will be created.
     * @param info Platform-specific information about the surface created.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<surface, api_call_info> make(instance_cref instance, surface_data info) noexcept
    {
        return make(instance, information{.platform = info});
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param instance Instance on which the handle was allocated.
     * @param info Information about the handle allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<surface, api_call_info>
    make(external_handle<handle_type> handle, instance_cref instance, information info) noexcept;

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~surface() noexcept
    {
        if(owns())
        {
            surface::destroy();
        }
    }

    /// Move constructor.
    surface(surface&& other) noexcept
        :
#if defined(VK_KHR_surface)
          m_handle{std::exchange(other.m_handle, handle_type{})},
#endif // defined(VK_KHR_surface)
          m_parent{other.m_parent},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    surface& operator=(surface&& other) noexcept
    {
        swap(other);
        return *this;
    }

    surface(const surface&)            = delete;
    surface& operator=(const surface&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

#if defined(VK_KHR_surface)
    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }
#endif // defined(VK_KHR_surface)

    /// Conversion operator to a view of this object.
    [[nodiscard]] operator view() const noexcept
    {
#if defined(VK_KHR_surface)
        return {m_handle, m_parent, m_info.platform};
#else
        return {};
#endif // defined(VK_KHR_surface)
    }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    //------------------------------------------------------------------------------

#if defined(VK_KHR_surface)
    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }
#endif // defined(VK_KHR_surface)

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const auto& info() const noexcept { return m_info; }

    /// Returns a const reference to the instance this object was created from.
    [[nodiscard]] const fuyu::instance& instance() const noexcept { return m_parent; }

    /// Returns the platform-specific information known about this object.
    [[nodiscard]] auto platform_info() const noexcept { return m_info.platform; }

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

    /// Indicates if this object has ownership over its handle and will destroy it when the destructor runs.
    [[nodiscard]] bool owns() const noexcept { return m_owner; }

    /// Indicates if the object borrows its handle and will NOT destroy it when the destructor runs.
    [[nodiscard]] bool borrows() const noexcept { return not owns(); }

    //------------------------------------------------------------------------------

    /// Swaps two objects.
    void swap(surface& other) noexcept
    {
#if defined(VK_KHR_surface)
        std::swap(m_handle, other.m_handle);
#endif // defined(VK_KHR_surface)

        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(surface& a, surface& b) noexcept { a.swap(b); }

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
    friend auto rebind(surface& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    surface(token, instance_cref instance, information info) noexcept : m_parent{instance}, m_info{std::move(info)} {}

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Creates the surface.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create([[maybe_unused]] traits::platform::surface::underlying) noexcept;

    template<typename... pnext_chain_members>
    [[nodiscard]] auto create(std::monostate, const pnext_chain<pnext_chain_members...>&) noexcept
    {
        return create(std::monostate{});
    }

    template<traits::platform::surface::platform_data data, typename... pnext_chain_members>
    [[nodiscard]] auto create(data d, const pnext_chain<pnext_chain_members...>& chain) noexcept
    {
        auto vk = traits::platform::surface::to_underlying(d);
        fubuki::extend(vk, chain);

        return create(vk);
    }

    /// Destroys the surface if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

#if defined(VK_KHR_surface)
    handle_type m_handle = {}; ///< Underlying Vulkan handle.
#endif                         // defined(VK_KHR_surface)

    parent_type m_parent;       ///< Instance this surface is linked to.
    information m_info  = {};   ///< Information about the surface.
    bool        m_owner = true; ///< Indicates if this object has ownership over its handle.
};

template<typename... pnext_chain_members>
inline surface::surface(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain)
    : surface(token{}, instance, std::move(info))
{
    const auto visitor = [this, &chain]<typename T>(const T& variant) noexcept
    {
        if constexpr(requires { this->create(variant, chain); })
        {
            return this->create(variant, chain);
        }
        else
        {
            return std::make_optional(api_call_info{}); // Invalid usage
        }
    };

    if(const auto error = std::visit(visitor, m_info.platform.value))
    {
        throw api_call_exception{{*error}};
    }
}

inline surface::surface(external_handle<handle_type> handle, instance_cref instance, information info) : surface(token{}, instance, std::move(info))
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner = fuyu::indicates_ownership(handle);

#if defined(VK_KHR_surface)
    m_handle = fuyu::handle_of(handle);
#endif // defined(VK_KHR_surface)

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<surface, api_call_info>
surface::make(instance_cref instance, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept
{
    auto result = surface(token{}, instance, std::move(info));

    const auto visitor = [&result, &chain]<typename T>(const T& variant) noexcept
    {
        if constexpr(requires { result.create(variant, chain); })
        {
            return result.create(variant, chain);
        }
        else
        {
            return std::make_optional(api_call_info{}); // Invalid usage
        }
    };

    if(const auto error = std::visit(visitor, result.m_info.platform.value))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<surface, api_call_info> surface::make(external_handle<handle_type> handle, instance_cref instance, information info) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result    = surface(token{}, instance, std::move(info));
    result.m_owner = fuyu::indicates_ownership(handle);

#if defined(VK_KHR_surface)
    result.m_handle = fuyu::handle_of(handle);
#endif // defined(VK_KHR_surface)

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_SURFACE_HPP
