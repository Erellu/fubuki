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

#ifndef FUBUKI_FUYU_IMAGE_VIEW_HPP
#define FUBUKI_FUYU_IMAGE_VIEW_HPP

#include <utility>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/information/image_view.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/image.hpp"
#include "fuyu/views/image_view.hpp"
#include "fuyu/views/owning.hpp"

namespace fubuki::fuyu
{

/**
 * Image objects are not directly accessed by pipeline shaders for reading or writing image data.
 * Instead, image views representing contiguous ranges of the image subresources and containing additional metadata are used for that purpose.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkImageView.html
 */
class image_view
{

    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = image_view_handle;
    using parent_type = parent::device;
    using information = information::image_view;
    using view        = views::image_view;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param image Image seen by this view.
     * @param info Information about the view allocation.
     * @param chain Chain extending VkImageViewCreateInfo.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    template<typename... pnext_chain_members>
    image_view(views::image_resource image, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param image Image seen by this view.
     * @param info Information about the view allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     */
    image_view(views::image_resource image, information info) : image_view(image, std::move(info), empty_pnext_chain) {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param image Image seen by this view.
     * @param info Information about how the allocation was performed.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    image_view(external_handle<handle_type> handle, views::image_resource image, information info);

    /**
     * Equivalent of a noexcept constructor.
     * @param image Image seen by this view.
     * @param info Information about the view allocation.
     * @param chain Chain extending VkImageViewCreateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<image_view, api_call_info>
    make(views::image_resource image, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept;

    /**
     * Equivalent of a noexcept constructor.
     * @param  image Image seen by this view.
     * @param info Information about the view allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<image_view, api_call_info> make(views::image_resource image, information info) noexcept
    {
        return make(image, std::move(info), empty_pnext_chain);
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param image Image seen by this view.
     * @param info Information about how the allocation was performed.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]] static std::expected<image_view, api_call_info>
    make(external_handle<handle_type> handle, views::image_resource image, information info) noexcept;

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~image_view() noexcept
    {
        if(owns())
        {
            image_view::destroy();
        }
    }

    /// Move constructor.
    image_view(image_view&& other) noexcept
        : m_handle{std::exchange(other.m_handle, image_view_handle{})},
          m_parent{other.m_parent},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    image_view& operator=(image_view&& other) noexcept
    {
        swap(other);
        return *this;
    }

    image_view(const image_view&)            = delete;
    image_view& operator=(const image_view&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Conversion operator to view.
    [[nodiscard]] operator view() const noexcept { return {m_handle, m_parent, m_info.type, m_info.format}; }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns a reference to the device this image_view uses.
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
    void swap(image_view& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(image_view& a, image_view& b) noexcept { a.swap(b); }

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
    friend auto rebind(image_view& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    image_view(token, const views::image_resource image, information info) noexcept : m_parent{image.device}, m_info{std::move(info)} {}

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Creates the image_view.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkImageViewCreateInfo& info) noexcept;

    /// Destroys the image_view if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type m_handle = {};  ///< Handle.
    parent_type m_parent;       ///< Device on which the handle is allocated.
    information m_info  = {};   ///< Information about how the handle was allocated.
    bool        m_owner = true; ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline image_view::image_view(const views::image_resource image, information info, const pnext_chain<pnext_chain_members...>& chain)
    : image_view(token{}, image, std::move(info))
{
    auto vk_info = to_underlying(m_info, image);
    fubuki::extend(vk_info, chain);

    if(const auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline image_view::image_view(external_handle<handle_type> handle, views::image_resource image, information info)
    : image_view{token{}, image, std::move(info)}
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
inline std::expected<image_view, api_call_info>
image_view::make(views::image_resource image, information info, const pnext_chain<pnext_chain_members...>& chain) noexcept
{
    auto result = image_view(token{}, image, std::move(info));

    auto vk_info = to_underlying(result.m_info, image);
    fubuki::extend(vk_info, chain);

    if(auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<image_view, api_call_info>
image_view::make(external_handle<handle_type> handle, views::image_resource image, information info) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result     = image_view(token{}, image, std::move(info));
    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_IMAGE_VIEW_HPP
