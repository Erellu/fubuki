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

#ifndef FUBUKI_FUYU_INFORMATION_SWAPCHAIN_HPP
#define FUBUKI_FUYU_INFORMATION_SWAPCHAIN_HPP

#include <cstdint>
#include <functional>
#include <optional>
#include <string>

#include <core/compare/extent2d.hpp> // IWYU pragma: keep
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"
#include "fuyu/sharing_mode.hpp"

namespace fubuki::fuyu::information
{

struct swapchain
{
#if defined(VK_KHR_swapchain)
    using underlying_type = VkSwapchainCreateInfoKHR;
#endif // #if defined(VK_KHR_swapchain)

    /// Indicates what kind of images the swapchain uses.
    struct target
    {
#if defined(VK_KHR_swapchain)

        std::uint32_t     minimum_count = 1;
        VkFormat          format        = VK_FORMAT_B8G8R8A8_SRGB;
        VkColorSpaceKHR   colour_space  = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        VkExtent2D        extent        = {0, 0};
        std::uint32_t     array_layers  = 0;
        VkImageUsageFlags usage         = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        sharing_mode::any sharing_mode  = {};

        [[nodiscard]] friend constexpr bool operator==(const target& a, const target& b) noexcept
        {
            return (a.minimum_count == b.minimum_count) and (a.format == b.format) and (a.colour_space == b.colour_space) and (a.extent == b.extent)
                and (a.array_layers == b.array_layers) and (a.usage == b.usage) and (a.sharing_mode == b.sharing_mode);
        }
#else
        [[nodiscard]] friend constexpr bool operator==(const target& a, const target& b) noexcept = default;
#endif // #if defined(VK_KHR_swapchain)

        [[nodiscard]] friend constexpr bool operator!=(const target& a, const target& b) noexcept { return not(a == b); }
    };

    /// Indicates how the swapchain will be presented.
    struct presentation
    {
#if defined(VK_KHR_swapchain)
        VkPresentModeKHR              mode            = VK_PRESENT_MODE_FIFO_KHR;
        VkSurfaceTransformFlagBitsKHR pre_transform   = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
        VkCompositeAlphaFlagBitsKHR   composite_alpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        bool                          clipped         = false;
#endif // #if defined(VK_KHR_swapchain)

        [[nodiscard]] friend constexpr bool operator==(const presentation& a, const presentation& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const presentation& a, const presentation& b) noexcept = default;
    };

    VkSwapchainCreateFlagsKHR flags = {}; ///< Creation flags.

    target       image   = {}; ///< The render target.
    presentation present = {}; ///< How the swapchain will be presented.

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const swapchain& a, const swapchain& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const swapchain& a, const swapchain& b) noexcept = default;

#if defined(VK_KHR_swapchain)
    [[nodiscard]] friend constexpr underlying_type
    to_underlying(std::reference_wrapper<const swapchain> cref, surface_khr_handle surface, swapchain_khr_handle old_swapchain) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                 = structure_type_v<underlying_type>,
            .pNext                 = {},
            .flags                 = s.flags,
            .surface               = surface.vk,
            .minImageCount         = s.image.minimum_count,
            .imageFormat           = s.image.format,
            .imageColorSpace       = s.image.colour_space,
            .imageExtent           = s.image.extent,
            .imageArrayLayers      = s.image.array_layers,
            .imageUsage            = s.image.usage,
            .imageSharingMode      = to_underlying(s.image.sharing_mode),
            .queueFamilyIndexCount = queue_count(s.image.sharing_mode),
            .pQueueFamilyIndices   = queue_data(s.image.sharing_mode),
            .preTransform          = s.present.pre_transform,
            .compositeAlpha        = s.present.composite_alpha,
            .presentMode           = s.present.mode,
            .clipped               = static_cast<VkBool32>(s.present.clipped),
            .oldSwapchain          = old_swapchain.vk,
        };
    }
#endif // #if defined(VK_KHR_swapchain)
};

} // namespace fubuki::fuyu::information

#endif // SWAPCHAIN_HPP
