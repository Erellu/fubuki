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

#ifndef FUBUKI_FUYU_VIEWS_IMAGE_RESOURCE_HPP
#define FUBUKI_FUYU_VIEWS_IMAGE_RESOURCE_HPP

#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/sharing_mode.hpp"
#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/memory.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/// A view of an image resource.
struct image_resource
{
    image_handle            handle = {};       ///< Image handle.
    device_cref             device;            ///< Device on which the image is allocated.
    VkExtent3D              extent       = {}; ///< Image extent, in texels.
    VkFormat                format       = {}; ///< Image format.
    VkImageType             type         = {}; ///< Image type.
    VkSampleCountFlagBits   samples      = {}; ///< Samples per texels.
    VkImageTiling           tiling       = {}; ///< Image tiling
    VkImageUsageFlags       usage        = {}; ///< Image usage.
    sharing_mode::any::view sharing_mode = {}; ///< Sharing mode of the image.

    [[nodiscard]] constexpr operator image_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const image_resource& a, const image_resource& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const image_resource& a, const image_resource& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const image_resource& a, const image_resource& b) noexcept { return a.handle <=> b.handle; }
};

/// View of an image bound to a memory region.
struct bound_image
{
    image_resource image;         ///< Image.
    memory         device_memory; ///< Memory the image is bound to.
    VkDeviceSize   offset = 0u;   ///< Offset in bytes in the memory region.

    [[nodiscard]] constexpr operator const image_resource&() const noexcept { return image; }
    [[nodiscard]] constexpr operator image_handle() const noexcept { return image.handle; }

    [[nodiscard]] constexpr operator const memory&() const noexcept { return device_memory; }
    [[nodiscard]] constexpr operator device_memory_handle() const noexcept { return device_memory.handle; }

    [[nodiscard]] friend constexpr bool operator==(const bound_image& a, const bound_image& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const bound_image& a, const bound_image& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const bound_image& a, const bound_image& b) noexcept = default;
};

} // namespace views

/// Alias for fubuki::fuyu::views::image_resource.
using image_resource_view = views::image_resource;

using bound_image_view = views::bound_image;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::image_resource_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::image_resource_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_IMAGE_RESOURCE_HPP
