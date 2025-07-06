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

#include "fuyu/functions/swapchain.hpp"

#include "fuyu/device.hpp" // IWYU pragma: keep
#include "fuyu/functions/surface.hpp"
#include "fuyu/swapchain.hpp"

namespace fubuki::fuyu
{

#if defined(VK_KHR_swapchain)

namespace detail
{

[[nodiscard]] presentation::result present(presentable_queue queue, const VkPresentInfoKHR& info) noexcept
{
    return extension::khr_swapchain::present(queue.device.get().function().ext, queue, info);
}

[[nodiscard]] std::expected<VkSwapchainCreateInfoKHR, api_call_info> prepare(swapchain& s, std::optional<VkExtent2D> size) noexcept
{
    if(size.has_value())
    {
        s.m_info.image.extent = *size;
    }
    else
    {
        const auto surface_capabilities = fuyu::capabilities(s.device().physical_device(), {s.surface(), s.device().instance()});

        if(not surface_capabilities)
        {
            return std::unexpected{surface_capabilities.error()};
        }

        s.m_info.image.extent = surface_capabilities->maxImageExtent;
    }

    if(const auto fixed = make_compatible(s.m_info, s.device(), s.surface()); not fixed)
    {
        return std::unexpected{fixed.error()};
    }

    return to_underlying(s.info(), s.surface(), s.handle());
}

[[nodiscard]] std::expected<void, api_call_info> recreate(swapchain& old_swapchain, const VkSwapchainCreateInfoKHR& info) noexcept
{
    const fuyu::device_view d = old_swapchain.device();

    // NOLINTBEGIN(bugprone-unchecked-optional-access): false positive
    const auto success = old_swapchain.info().callbacks.has_value()
        ? extension::khr_swapchain::create(d.functions.get().ext, d.handle, info, old_swapchain.info().callbacks->creation)
        : extension::khr_swapchain::create(d.functions.get().ext, d.handle, info);
    // NOLINTEND(bugprone-unchecked-optional-access): false positive

    if(not success)
    {
        return std::unexpected{success.error()};
    }

    old_swapchain.destroy(); // The old swapchain is NOT automatically destroyed when recreating a new swapchain. It's only "retired"
    old_swapchain.m_handle = *success;

    return {};
}

    #if defined(VK_VERSION_1_1)

[[nodiscard]] std::expected<std::uint32_t, api_call_info> acquire_next_image(device_cref device, const VkAcquireNextImageInfoKHR& info) noexcept
{
    return extension::khr_swapchain::acquire_next_image(device.get().function().ext, device.get(), info);
}

    #endif // defined(VK_VERSION_1_1)

} // namespace detail

[[nodiscard]] std::expected<void, api_call_info>
make_compatible(information::swapchain& info, physical_device_handle device, surface_view surface) noexcept
{
    const auto surface_properties = fuyu::properties(device, surface);

    if(not surface_properties)
    {
        return std::unexpected{surface_properties.error()};
    }

    // Minimum count
    {
        // Some (buggy) implementations report a maxImageCount of 0. This occurs for example on WSL with dzn.
        // Simply clamping to the range of (minImageCount, maxImageCount) doesn't work on such platforms
        const auto max = std::max(surface_properties->capabilities.minImageCount, surface_properties->capabilities.maxImageCount);

        info.image.minimum_count = std::clamp(info.image.minimum_count, surface_properties->capabilities.minImageCount, max);
    }

    // Array layers
    info.image.array_layers = std::clamp(info.image.array_layers, 1u, surface_properties->capabilities.maxImageArrayLayers);

    // Present mode
    if(const auto it
       = std::ranges::find_if(surface_properties->present_modes, [m = info.present.mode](const VkPresentModeKHR mode) noexcept { return mode == m; });
       it == surface_properties->present_modes.end())
    {
        info.present.mode = surface_properties->present_modes.front();
    }

    // Format
    if(const auto it = std::ranges::find_if(surface_properties->formats,
                                            [&info](const VkSurfaceFormatKHR& f) noexcept
                                            { return info.image.format == f.format and info.image.colour_space == f.colorSpace; });
       it == surface_properties->formats.end())
    {
        info.image.format       = surface_properties->formats.front().format;
        info.image.colour_space = surface_properties->formats.front().colorSpace;
    }

    // Extent
    info.image.extent.width = std::clamp(
        info.image.extent.width, surface_properties->capabilities.minImageExtent.width, surface_properties->capabilities.maxImageExtent.width);
    info.image.extent.height = std::clamp(
        info.image.extent.height, surface_properties->capabilities.minImageExtent.height, surface_properties->capabilities.maxImageExtent.height);

    // Transform
    if((static_cast<VkSurfaceTransformFlagsKHR>(info.present.pre_transform) & surface_properties->capabilities.supportedTransforms) == 0)
    {
        info.present.pre_transform = surface_properties->capabilities.currentTransform;
    }

    // Composite alpha
    if((static_cast<VkCompositeAlphaFlagsKHR>(info.present.composite_alpha) & surface_properties->capabilities.supportedCompositeAlpha) == 0)
    {
        info.present.composite_alpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR; // Guaranteed to be supported according to the specifications
    }

    return {};
}

[[nodiscard]] std::expected<void, api_call_info>
make_compatible(information::swapchain& info, device_cref device, surface_khr_handle surface) noexcept
{
    return make_compatible(info, device.get().physical_device(), {surface, device.get().instance()});
}

[[nodiscard]] std::expected<small_vector<image_handle>, api_call_info> images(swapchain_view swap_chain)
{
    return extension::khr_swapchain::images(swap_chain.device.get().function().ext, swap_chain.device.get(), swap_chain);
}

[[nodiscard]] std::expected<std::uint32_t, api_call_info> acquire_next_image(swapchain_view                     swap_chain,
                                                                             const swapchain_image_acquisition& acq) noexcept
{
    return extension::khr_swapchain::acquire_next_image(
        swap_chain.device.get().function().ext, swap_chain.device.get(), swap_chain, acq.timeout, acq.semaphore, acq.fence);
}

#endif // defined(VK_KHR_swapchain)

} // namespace fubuki::fuyu
