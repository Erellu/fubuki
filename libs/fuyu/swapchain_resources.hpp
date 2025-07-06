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
#ifndef FUBUKI_FUYU_SWAPCHAIN_RESOURCES_HPP
#define FUBUKI_FUYU_SWAPCHAIN_RESOURCES_HPP

#include <functional>
#include <ranges>
#include <utility>

#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>

#include "fuyu/information/swapchain_resources.hpp"
#include "fuyu/render_pass.hpp"
#include "fuyu/views/swapchain_resources.hpp"

namespace fubuki::fuyu
{

class swapchain;

/**
 * The resources required to use the images of a swapchain.
 */
class swapchain_resources
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using parent_type = parent::device;
    using information = information::swapchain_resources;
    using view        = views::swapchain_resources;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    template<typename... image_view_pnext_elements, typename... framebuffer_pnext_elements>
    swapchain_resources(std::reference_wrapper<const swapchain>           parent,
                        information                                       info,
                        const pnext_chain<image_view_pnext_elements...>&  image_view_pnext,
                        const pnext_chain<framebuffer_pnext_elements...>& framebuffer_pnext);

    swapchain_resources(std::reference_wrapper<const swapchain> parent, information info)
        : swapchain_resources{parent, std::move(info), empty_pnext_chain, empty_pnext_chain}
    {
    }

    template<typename... image_view_pnext_elements, typename... framebuffer_pnext_elements>
    [[nodiscard]] static std::expected<swapchain_resources, api_call_info> make(std::reference_wrapper<const swapchain>           parent,
                                                                                information                                       info,
                                                                                const pnext_chain<image_view_pnext_elements...>&  image_view_pnext,
                                                                                const pnext_chain<framebuffer_pnext_elements...>& framebuffer_pnext);

    [[nodiscard]] static std::expected<swapchain_resources, api_call_info> make(std::reference_wrapper<const swapchain> parent,
                                                                                information                             info) noexcept
    {
        return make(parent, std::move(info), empty_pnext_chain, empty_pnext_chain);
    }

    ~swapchain_resources() noexcept = default;

    /// Move constructor.
    swapchain_resources(swapchain_resources&& other) noexcept
        : m_swapchain{other.m_swapchain},
          m_parent{other.m_parent},
          m_info{other.m_info},
          m_images{std::move(other.m_images)},
          m_image_views{std::move(other.m_image_views)},
          m_framebuffers{std::move(other.m_framebuffers)},
          m_render_pass{std::move(other.m_render_pass)}
    {
    }

    /// Move assignment operator.
    swapchain_resources& operator=(swapchain_resources&& other) noexcept
    {
        swap(other);
        other.clear();
        return *this;
    }

    swapchain_resources(const swapchain_resources&)            = delete;
    swapchain_resources& operator=(const swapchain_resources&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    [[nodiscard]] operator view() const noexcept
    {
        return std::holds_alternative<information::dynamic_rendering>(m_info.render_target.value)
            ? view{device(), m_images, m_image_views, {/* no framebuffers in this configuration*/}, m_render_pass}
            : view{device(), m_images, m_image_views, m_framebuffers, m_render_pass};
    }

    /********************************************************************************/
    /*                                  ELEMENT ACCESS                              */
    /********************************************************************************/

    /**
     * Returns the resource at the given index. The behaviour is undefined if `idx >= size()`.
     */
    [[nodiscard]] auto operator[](std::size_t idx) const noexcept
    {
        const view v = *this;
        return v[idx];
    }

    /**
     * Returns the resource at the given index.
     * @throws Throws an instance of std::out_of_range if `idx >= size()`.
     */
    [[nodiscard]] auto at(std::size_t idx) const
    {
        const view v = *this;
        return v.at(idx);
    }

    void clear() noexcept
    {
        m_images.clear();
        m_image_views.clear();
        m_framebuffers.clear();
    }

    /********************************************************************************/
    /*                                    CAPACITY                                  */
    /********************************************************************************/

    [[nodiscard]] std::size_t size() const noexcept
    {
        const view v = *this;
        return v.size();
    }

    /// Indicates if these resources are empty.
    /// This can happen upon call to fuyu::recreate(swapchain&, swapchain_resources&) when swapchain-recreation failed.
    [[nodiscard]] bool empty() const noexcept { return size() == 0; }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    /// Returns a reference to the device from which this object was created.
    [[nodiscard]] FUBUKI_SEMI_PURE const fuyu::device& device() const noexcept { return m_parent; }

#if defined(VK_KHR_swapchain)
    /// Returns the parent swapchain, as a view.
    [[nodiscard]] swapchain_khr_handle parent() const noexcept { return m_swapchain; }
#endif // #if defined(VK_KHR_swapchain)

    /// Swaps two objects.
    void swap(swapchain_resources& other) noexcept
    {
#if defined(VK_KHR_swapchain)
        std::swap(m_swapchain, other.m_swapchain);
#endif // #if defined(VK_KHR_swapchain)

        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        m_images.swap(other.m_images);
        m_image_views.swap(other.m_image_views);
        m_framebuffers.swap(other.m_framebuffers);
        std::swap(m_render_pass, other.m_render_pass);
    }

    /// Swaps two objects.
    friend void swap(swapchain_resources& a, swapchain_resources& b) noexcept { a.swap(b); }

    /**
     * @brief Changes the parent, if the underlying Vulkan handle is the same as the previous one.
     * @param p The new parent.
     * @returns Nothing, or an instance of fuyu::parent::error::incompatible indicating that the two handles were different.
     */
    [[nodiscard]] FUBUKI_FUYU_API std::expected<void, parent_type::error::incompatible> rebind(parent_type p) noexcept;

    /**
     * @brief Changes the parent, if the underlying Vulkan handle is the same as the previous one.
     * @param object The object to rebind.
     * @param parent The new parent.
     * @returns Nothing, or an instance of fuyu::parent::error::incompatible indicating that the two handles were different.
     */
    friend auto rebind(swapchain_resources& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    FUBUKI_FUYU_API
    swapchain_resources(token, std::reference_wrapper<const swapchain> parent, information info) noexcept;

    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> acquire_images(const swapchain& s) noexcept;

    [[nodiscard]] FUBUKI_FUYU_API std::expected<render_pass_handle, api_call_info> make_render_pass() noexcept;

    template<typename... elements>
    [[nodiscard]] std::optional<api_call_info> make_views(const pnext_chain<elements...>& pnext) noexcept;

    template<typename... elements>
    [[nodiscard]] std::optional<api_call_info> make_framebuffers(const pnext_chain<elements...>& pnext) noexcept;

    template<typename... image_view_pnext_elements, typename... framebuffer_pnext_elements>
    [[nodiscard]] std::optional<api_call_info> create(const swapchain&                                  s,
                                                      const pnext_chain<image_view_pnext_elements...>&  image_view_pnext,
                                                      const pnext_chain<framebuffer_pnext_elements...>& framebuffer_pnext) noexcept;

#if defined(VK_KHR_swapchain)
    swapchain_khr_handle m_swapchain;
#endif // #if defined(VK_KHR_swapchain)

    parent_type                m_parent;
    information                m_info;
    small_vector<image>        m_images       = {};
    small_vector<image_view>   m_image_views  = {};
    small_vector<framebuffer>  m_framebuffers = {};
    std::optional<render_pass> m_render_pass  = {};
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... image_view_pnext_elements, typename... framebuffer_pnext_elements>
inline swapchain_resources::swapchain_resources(std::reference_wrapper<const swapchain>           parent,
                                                information                                       info,
                                                const pnext_chain<image_view_pnext_elements...>&  image_view_pnext,
                                                const pnext_chain<framebuffer_pnext_elements...>& framebuffer_pnext)
    : swapchain_resources{token{}, parent, std::move(info)}
{
    if(const auto error = create(parent, image_view_pnext, framebuffer_pnext))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... image_view_pnext_elements, typename... framebuffer_pnext_elements>
[[nodiscard]] inline std::expected<swapchain_resources, api_call_info>
swapchain_resources::make(std::reference_wrapper<const swapchain>           parent,
                          information                                       info,
                          const pnext_chain<image_view_pnext_elements...>&  image_view_pnext,
                          const pnext_chain<framebuffer_pnext_elements...>& framebuffer_pnext)
{
    auto result = swapchain_resources(token{}, parent, std::move(info));

    if(const auto error = result.create(parent, image_view_pnext, framebuffer_pnext))
    {
        return std::unexpected{*error};
    }

    return result;
}

template<typename... image_view_pnext_elements, typename... framebuffer_pnext_elements>
[[nodiscard]] std::optional<api_call_info> swapchain_resources::create(const swapchain&                                  s,
                                                                       const pnext_chain<image_view_pnext_elements...>&  image_view_pnext,
                                                                       const pnext_chain<framebuffer_pnext_elements...>& framebuffer_pnext) noexcept
{
    if(const auto error = acquire_images(s))
    {
        return *error;
    }

    if(const auto error = make_views(image_view_pnext))
    {
        return *error;
    }

    if(const auto error = make_framebuffers(framebuffer_pnext))
    {
        return *error;
    }

    return {};
}

template<typename... elements>
[[nodiscard]] std::optional<api_call_info> swapchain_resources::make_views(const pnext_chain<elements...>& pnext) noexcept
{
    for(const auto& image : m_images)
    {
        auto image_view = fuyu::image_view::make(image,
                                                 image_view::information{
                                                     .flags             = {},
                                                     .type              = VK_IMAGE_VIEW_TYPE_2D,
                                                     .format            = image.info().format,
                                                     .components        = {/*identity, required by VUID-VkFramebufferCreateInfo-pAttachments-00884*/},
                                                     .subresource_range = {.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                                                                           .baseMipLevel   = 0,
                                                                           .levelCount     = image.info().mip_levels,
                                                                           .baseArrayLayer = 0,
                                                                           .layerCount     = image.info().array_layers}
        },
                                                 pnext);

        if(not image_view)
        {
            return image_view.error();
        }

        m_image_views.emplace_back(std::move(*image_view));
    }

    fubuki_assert(m_image_views.size() == m_images.size(),
                  "Internal error: failed to create all image views. Created " << m_image_views.size() << ", should have created " << m_images.size()
                                                                               << ".");

    return {};
}

template<typename... elements>
[[nodiscard]] std::optional<api_call_info> swapchain_resources::make_framebuffers(const pnext_chain<elements...>& pnext) noexcept
{
    if(std::holds_alternative<information::dynamic_rendering>(m_info.render_target.value))
    {
        return {};
    }

    const auto render_pass = make_render_pass();

    if(not render_pass)
    {
        return render_pass.error();
    }

    for(const auto [image, image_view] : std::views::zip(m_images, m_image_views))
    {
        auto framebuffer = fuyu::framebuffer::make({*render_pass, device()},
                                                   framebuffer::information{.flags       = {},
                                                                            .attachments = {image_view},
                                                                            .width       = image.info().extent.width,
                                                                            .height      = image.info().extent.height,
                                                                            .layers      = image.info().array_layers},
                                                   pnext);

        if(not framebuffer)
        {
            return framebuffer.error();
        }

        m_framebuffers.emplace_back(std::move(*framebuffer));
    }

    fubuki_assert(m_framebuffers.size() == m_images.size(),
                  "Internal error: failed to create all framebuffers. Created " << m_framebuffers.size() << ", should have created "
                                                                                << m_images.size() << ".");

    return {};
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_SWAPCHAIN_RESOURCES_HPP
