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

#ifndef FUBUKI_FUYU_VIEWS_SWAPCHAIN_RESOURCES_HPP
#define FUBUKI_FUYU_VIEWS_SWAPCHAIN_RESOURCES_HPP

#include <optional>
#include <span>

#include <core/handle.hpp>
#include <core/small_vector.hpp>

#include "fuyu/framebuffer.hpp"
#include "fuyu/image.hpp"
#include "fuyu/image_view.hpp"
#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/render_pass.hpp"

namespace fubuki::fuyu
{

namespace views
{

/**
 * A view of the resources required to use a swapchain and its images.
 */
// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
struct swapchain_resources
{
    /// An element of the swapchain resources.
    struct element
    {
        device_cref                     device;      ///< The device on which the resources are allocated.
        image_resource                  image;       ///< The image resource.
        image_view_description          view;        ///< The image view associated to the image resource.
        std::optional<framebuffer_view> framebuffer; ///< The framebuffer associated to the image view, or std::nullopt if none was created.

        [[nodiscard]] operator image_handle() const noexcept { return image; }
        [[nodiscard]] operator image_view_handle() const noexcept { return view; }
        [[nodiscard]] operator framebuffer_handle() const noexcept { return framebuffer.has_value() ? framebuffer->handle : null_handle; }

        [[nodiscard]] friend constexpr bool operator==(const element& a, const element& b) noexcept
        {
            return (a.image == b.image) and (a.view == b.view) and (a.framebuffer == b.framebuffer);
        }

        [[nodiscard]] friend constexpr bool                 operator!=(const element& a, const element& b) noexcept { return not(a == b); }
        [[nodiscard]] friend constexpr std::strong_ordering operator<=>(const element& a, const element& b) noexcept
        {
            if(const auto cmp = a.image <=> b.image; cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            if(const auto cmp = a.view <=> b.view; cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            if(const auto cmp = a.framebuffer <=> b.framebuffer; cmp != std::strong_ordering::equivalent)
            {
                return cmp;
            }

            return std::strong_ordering::equivalent;
        }
    };

    device_cref device;

    /// Swapchain images.
    std::span<const fuyu::image> images = {};

    /// Image views associated to the images.
    std::span<const fuyu::image_view> image_views = {};

    /// The framebuffers used. Can be nullopt if no framebuffers were created, for example when setting
    /// information::swapchain_resources::frame_buffer::enable to `false` (typically when using dynamic rendering).
    std::optional<std::span<const fuyu::framebuffer>> framebuffers = {};

    /// The render pass used to create the framebuffers.
    std::optional<fuyu::render_pass_view> render_pass = {};

    /********************************************************************************/
    /*                                    CAPACITY                                  */
    /********************************************************************************/

    /// Indicates the number of resources seen by this view.
    [[nodiscard]] std::size_t size() const noexcept
    {
        fubuki_assert((images.size() == image_views.size()) and (not framebuffers.has_value() or images.size() == framebuffers->size()),
                      "Malformed view. Image count: " << images.size() << ", image views count: " << image_views.size()
                                                      << " framebuffers: " << framebuffers.has_value()
                                                      << " framebuffers count: " << (framebuffers.has_value() ? framebuffers->size() : 0));

        return images.size();
    }

    /// Indicates if this view is empty.
    [[nodiscard]] bool empty() const noexcept { return size() == 0; }

    /********************************************************************************/
    /*                                  ELEMENT ACCESS                              */
    /********************************************************************************/

    /**
     * Returns the resource at the given index. The behaviour is undefined if `idx >= size()`.
     */
    [[nodiscard]] element operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out-of-bounds " << "(value:" << idx << ", max: " << size() << ")");
        return {device, images[idx], image_views[idx], framebuffers.has_value() ? (*framebuffers)[idx] : std::optional<framebuffer_view>{}};
    }

    /**
     * Returns the resource at the given index.
     * @throws Throws an instance of std::out_of_range if `idx >= size()`.
     */
    [[nodiscard]] element at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (value:" + std::to_string(idx) + ", max:" + std::to_string(size()) + ")");
        }

        return (*this)[idx];
    }
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

} // namespace views

using swapchain_resources_view = views::swapchain_resources;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_VIEWS_SWAPCHAIN_RESOURCES_HPP
