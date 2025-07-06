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

#ifndef FUBUKI_FUYU_FUNCTIONS_SWAPCHAIN_HPP
#define FUBUKI_FUYU_FUNCTIONS_SWAPCHAIN_HPP

#include <chrono>

#include <core/assertion.hpp>
#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/structure_type.hpp>
#include <extension/khr_swapchain.hpp>

#include "fuyu/information/swapchain.hpp"
#include "fuyu/queue.hpp"
#include "fuyu/swapchain_resources.hpp"
#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/surface.hpp"
#include "fuyu/views/swapchain.hpp"

namespace fubuki::fuyu
{

class swapchain; // NOLINT(bugprone-forward-declaration-namespace)

#if defined(VK_KHR_swapchain)

namespace presentation
{

/// @copydoc fubuki::extension::khr_swapchain::presentation::success
using success = extension::khr_swapchain::presentation::success;

/// @copydoc fubuki::extension::khr_swapchain::presentation::error
using error = extension::khr_swapchain::presentation::error;

using result = std::expected<success, error>; ///< @copydoc extension::khr_swapchain::presentation::result

/**
 * Specifies how a presentation occurs.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPresentInfoKHR.html
 */
struct contents
{
    using underlying_type = VkPresentInfoKHR;

    small_vector<semaphore_handle> wait_semaphores = {}; ///< The semaphores to wait ont before issuing the present request.
    std::uint32_t                  image_index     = 0;  ///< The index of the image to present.

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const contents>       cref,
                                                                 std::reference_wrapper<const VkSwapchainKHR> swapchain,
                                                                 std::span<const VkSemaphore>                 semaphores) noexcept
    {
        return {
            .sType              = structure_type_v<underlying_type>,
            .pNext              = {},
            .waitSemaphoreCount = vk_size(semaphores),
            .pWaitSemaphores    = semaphores.empty() ? nullptr : semaphores.data(),
            .swapchainCount     = 1,
            .pSwapchains        = std::addressof(swapchain.get()),
            .pImageIndices      = std::addressof(cref.get().image_index),
            .pResults           = nullptr, // Currently, only support for one swapchain at a time
        };
    }
};

} // namespace presentation

/**
 * Specifies how a swapchain image index is acquired.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkAcquireNextImageInfoKHR.html
 */
struct swapchain_image_acquisition
{
    std::chrono::nanoseconds        timeout   = {}; ///< How much the function waits if no image is available. MUST be a positive value.
    std::optional<semaphore_handle> semaphore = {}; ///<(optional) Synchronisation semaphore.
    std::optional<fence_handle>     fence     = {}; ///< (optional) Synchronisation fence.

    std::uint32_t device_mask
        = {}; ///< A mask of physical devices for which the swapchain image will be ready to use when the semaphore or fence is signaled.

    #if defined(VK_VERSION_1_1)

    using underlying_type = VkAcquireNextImageInfoKHR;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const swapchain_image_acquisition> cref,
                                                                 swapchain_khr_handle                                      swap_chain) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        fubuki_assert(s.timeout.count() > 0, "Timeout must be positive.");

        return {
            .sType      = structure_type_v<underlying_type>,
            .pNext      = {},
            .swapchain  = swap_chain.vk,
            .timeout    = static_cast<std::uint64_t>(s.timeout.count()),
            .semaphore  = s.semaphore.value_or(null_handle).vk,
            .fence      = s.fence.value_or(null_handle).vk,
            .deviceMask = s.device_mask,
        };
    }
    #endif // defined(VK_VERSION_1_1)
};

namespace detail
{

[[nodiscard]] FUBUKI_FUYU_API presentation::result present(presentable_queue queue, const VkPresentInfoKHR& info) noexcept;

[[nodiscard]] FUBUKI_FUYU_API std::expected<VkSwapchainCreateInfoKHR, api_call_info> prepare(swapchain&, std::optional<VkExtent2D> size) noexcept;

[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> recreate(swapchain& old_swapchain, const VkSwapchainCreateInfoKHR& info) noexcept;

    #if defined(VK_VERSION_1_1)

[[nodiscard]] FUBUKI_FUYU_API std::expected<std::uint32_t, api_call_info> acquire_next_image(device_cref device,
                                                                                             const VkAcquireNextImageInfoKHR&) noexcept;

    #endif // defined(VK_VERSION_1_1)

} // namespace detail

/**
 * Modifies an instance of fubuki::information::swapchain so that it is compatible for a surface.
 *
 * @param info The information to make compatible.
 * @param device The physical device the swapchain will use.
 * @param surface The surface the swapchain will target.
 *
 * @returns Nothing, or the API call that failed.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info>
make_compatible(information::swapchain& info, physical_device_handle device, fubuki::fuyu::surface_view surface) noexcept;

/**
 * Modifies an instance of fubuki::information::swapchain so that it is compatible for a surface.
 *
 * @param info The information to make compatible.
 * @param device The device the swapchain will use.
 * @param surface The surface the swapchain will target.
 * @pre Both `surface` and `device` must come from the same instance.
 *
 * @returns Nothing, or the API call that failed.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info>
                              make_compatible(information::swapchain& info, device_cref device, surface_khr_handle surface) noexcept;

/**
 * Returns the array of presentable images associated with a swapchain.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetSwapchainImagesKHR.html
 * @throws This function CAN throw an instance of std::bad_alloc. This is however very uncommon as most existing hardware don't have more than 12
 * swapchain images.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<small_vector<image_handle>, api_call_info> images(swapchain_view swap_chain);

/**
 * Returns the index of the next available presentable image of a swapchain.
 * @param swap_chain Swapchain from which the image index is acquired.
 * @param acq Information about how the image is acquired.
 * @pre At least one of 'acq.semaphore' or 'acq.fence' must have a value that is not VK_NULL_HANDLE.
 * @pre acq.timeout must be positive.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<std::uint32_t, api_call_info> acquire_next_image(swapchain_view                     swap_chain,
                                                                                             const swapchain_image_acquisition& acq) noexcept;

/**
 * Queue an image for presentation.
 * @param queue The queue to present to.
 * @param swap_chain The swapchain issuing the image to present.
 * @param pres The details about the presentation.
 * @param pnext Chain extending VkPresentInfoKHR.
 */
template<typename... pnext_elements>
[[nodiscard]] inline auto present(presentable_queue                     queue,
                                  swapchain_khr_handle                  swap_chain,
                                  const presentation::contents&         pres,
                                  const pnext_chain<pnext_elements...>& pnext) noexcept
{
    auto vk_wait_semaphore = collect<VkSemaphore>(small_span{pres.wait_semaphores}.const_span());

    auto vk_presentation = to_underlying(pres, swap_chain.vk, vk_wait_semaphore);
    fubuki::extend(vk_presentation, pnext);

    return detail::present(queue, vk_presentation);
}

/**
 * Queue an image for presentation.
 * @param queue The queue to present to.
 * @param swap_chain The swapchain issuing the image to present.
 * @param pres The details about the presentation.
 *
 */
[[nodiscard]] inline auto present(presentable_queue queue, swapchain_khr_handle swap_chain, const presentation::contents& pres) noexcept
{
    return present(queue, swap_chain, pres, empty_pnext_chain);
}

/**
 * Recreates a swapchain and its resources.
 *
 * @param old_swapchain The swapchain to recreate.
 * @param pnext Chain extending VkSwapchainCreateInfoKHR.
 * @param size The new size of the swapchain. If specified, the value is clamped to match the surface capabilities. If not specified, the swapchain
 * will take the maximum extent allowed by the surface.
 * @returns Nothing, or an instance of fubuki::api_call_info describing the API call that failed.
 *
 * @pre No resources must be currently in used in a command buffer or being used in a frame.
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info>
recreate(swapchain& old_swapchain, const pnext_chain<elements...>& pnext, std::optional<VkExtent2D> size = {}) noexcept
{
    auto vk_info = detail::prepare(old_swapchain, size);

    if(not vk_info)
    {
        return std::unexpected{vk_info.error()};
    }

    fubuki::extend(*vk_info, pnext);
    return detail::recreate(old_swapchain, *vk_info);
}

/**
 * Recreates a swapchain and its resources.
 * @param old_swapchain The swapchain to recreate.
 * @param size The new size of the swapchain. If specified, the value is clamped to match the surface capabilities. If not specified, the swapchain
 * will take the maximum extent allowed by the surface.
 *
 * @returns Nothing, or an instance of fubuki::api_call_info describing the API call that failed.
 *
 * @pre No resources must be currently in used in a command buffer or being used in a frame.
 */
[[nodiscard]] inline auto recreate(swapchain& old_swapchain, std::optional<VkExtent2D> size = {}) noexcept
{
    return recreate(old_swapchain, empty_pnext_chain, size);
}

/**
 * Recreates a swapchain and its resources.
 * @param old_swapchain The swapchain to recreate.
 * @param old_rc The resources to recreate.
 * @param size The new size of the swapchain. If specified, the value is clamped to match the surface capabilities. If not specified, the swapchain
 * will take the maximum extent allowed by the surface.
 * @param swapchain_pnext Chain extending VkSwapchainCreateInfoKHR.
 * @param image_view_pnext Chain extending VkImageViewCreateInfo.
 * @param framebuffer_pnext Chain extending VkFramebufferCreateInfo.
 * @returns Nothing, or an instance of fubuki::api_call_info describing the API call that failed.
 *
 * @pre No resources must be currently in used in a command buffer or being used in a frame.
 */
template<typename... swapchain_pnext_elements, typename... image_view_pnext_elements, typename... framebuffer_pnext_elements>
[[nodiscard]] inline std::expected<void, api_call_info> recreate(swapchain&                                        old_swapchain,
                                                                 swapchain_resources&                              old_rc,
                                                                 const pnext_chain<swapchain_pnext_elements...>&   swapchain_pnext,
                                                                 const pnext_chain<image_view_pnext_elements...>&  image_view_pnext,
                                                                 const pnext_chain<framebuffer_pnext_elements...>& framebuffer_pnext,
                                                                 std::optional<VkExtent2D>                         size) noexcept
{
    // Old resources become invalid because the old swapchain gets destroyed when recreating a swapchain from an existing one
    // This is true even if the swapchain creation fails
    old_rc.clear();

    if(auto check = recreate(old_swapchain, swapchain_pnext, size); not check)
    {
        return std::unexpected{check.error()};
    }

    auto new_resources = swapchain_resources::make(old_swapchain, old_rc.info(), image_view_pnext, framebuffer_pnext);

    if(not new_resources)
    {
        return std::unexpected{new_resources.error()};
    }

    old_rc = *std::move(new_resources);

    return {};
}

/**
 * Recreates a swapchain and its resources.
 * @param old_swapchain The swapchain to recreate.
 * @param old_rc The resources to recreate.
 * @param size The new size of the swapchain. If specified, the value is clamped to match the surface capabilities. If not specified, the swapchain
 * will take the maximum extent allowed by the surface.
 * @returns Nothing, or an instance of fubuki::api_call_info describing the API call that failed.
 *
 * @pre No resources must be currently in used in a command buffer or being used in a frame.
 */
[[nodiscard]] inline auto recreate(swapchain& old_swapchain, swapchain_resources& old_rc, std::optional<VkExtent2D> size = {})
{
    return recreate(old_swapchain, old_rc, empty_pnext_chain, empty_pnext_chain, empty_pnext_chain, size);
}

    #if defined(VK_VERSION_1_1)

/**
 * Returns the index of the next available presentable image of a swapchain.
 * @param swap_chain Swapchain from which the image index is acquired.
 * @param acq Indications on the index acquisition.
 * @param pnext Chain extending VkAcquireNextImageInfoKHR.
 * @pre At least one of 'acq.semaphore' or 'acq.fence' must have a value that is not VK_NULL_HANDLE.
 * @pre acq.timeout must be positive.
 */
template<typename... pnext_elements>
[[nodiscard]] inline auto
acquire_next_image(swapchain_view swap_chain, const swapchain_image_acquisition& acq, const pnext_chain<pnext_elements...>& pnext) noexcept
{
    auto vk_info = to_underlying(acq, swap_chain);
    fubuki::extend(vk_info, pnext);

    return detail::acquire_next_image(swap_chain.device, vk_info);
}
    #endif // defined(VK_VERSION_1_1)

#endif // defined(VK_KHR_swapchain)

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_SWAPCHAIN_HPP
