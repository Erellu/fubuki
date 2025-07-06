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

#ifndef FUBUKI_FUYU_VIEWS_IMAGE_VIEW_DESCRIPTION_HPP
#define FUBUKI_FUYU_VIEWS_IMAGE_VIEW_DESCRIPTION_HPP

#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/device_ref.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/// Description of an image view.
struct image_view
{
    image_view_handle handle = {}; ///< Buffer view handle.
    device_cref       device;      ///< Device on which the image view is allocated.
    VkImageViewType   type   = {}; ///< Image view type.
    VkFormat          format = {}; ///< Image format.

    [[nodiscard]] constexpr operator image_view_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const image_view& a, const image_view& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const image_view& a, const image_view& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const image_view& a, const image_view& b) noexcept { return a.handle <=> b.handle; }
};

} // namespace views

/// Alias for fubuki::fuyu::views::image_view.
using image_view_description = views::image_view;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::image_view_description>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::image_view_description& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_IMAGE_VIEW_DESCRIPTION_HPP
