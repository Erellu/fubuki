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

#include "extension/khr_swapchain.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_swapchain
{

#if defined(VK_KHR_swapchain)

[[nodiscard]]
std::expected<swapchain_khr_handle, api_call_info> create(const functions& ext, device_handle device, const VkSwapchainCreateInfoKHR& info) noexcept
{
    swapchain_khr_handle swapchain{};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateSwapchainKHR">(ext, device.vk, std::addressof(info), nullptr, &swapchain.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return swapchain;
}

[[nodiscard]]
std::expected<swapchain_khr_handle, api_call_info>
create(const functions& ext, device_handle device, const VkSwapchainCreateInfoKHR& info, const VkAllocationCallbacks& callbacks) noexcept
{
    swapchain_khr_handle swapchain{};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateSwapchainKHR">(ext, device.vk, std::addressof(info), &callbacks, &swapchain.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return swapchain;
}

void destroy(const functions& ext, device_handle device, swapchain_khr_handle& swapchain) noexcept
{
    fubuki::invoke<"vkDestroySwapchainKHR">(ext, device.vk, swapchain.vk, nullptr);
    swapchain = null_handle;
}

void destroy(const functions& ext, device_handle device, swapchain_khr_handle& swapchain, const VkAllocationCallbacks& callbacks) noexcept
{
    fubuki::invoke<"vkDestroySwapchainKHR">(ext, device.vk, swapchain.vk, &callbacks);
    swapchain = null_handle;
}

[[nodiscard]]
std::expected<std::uint32_t, api_call_info> acquire_next_image(const functions&                ext,
                                                               device_handle                   device,
                                                               swapchain_khr_handle            swapchain,
                                                               std::chrono::nanoseconds        time,
                                                               std::optional<semaphore_handle> sem,
                                                               std::optional<fence_handle>     fen) noexcept
{
    const semaphore_handle semaphore = sem.has_value() ? *sem : semaphore_handle{};
    const fence_handle     fence     = fen.has_value() ? *fen : fence_handle{};

    // Sanity checks
    {
        fubuki_assert(swapchain != null_handle, "Swapchain cannot be null_handle.");
        fubuki_assert(time.count() > 0, "Timeout must be positive.");
        fubuki_assert(semaphore != null_handle or fence != null_handle, " Violation of VUID-vkAcquireNextImageKHR-semaphore-01780.");
    }

    const auto timeout = static_cast<std::uint64_t>(time.count());

    std::uint32_t result = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkAcquireNextImageKHR">(ext, device.vk, swapchain.vk, timeout, semaphore.vk, fence.vk, &result));
                                              not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<small_vector<image_handle>, api_call_info> images(const functions& ext, device_handle device, swapchain_khr_handle swapchain)
{
    // Sanity checks
    {
        fubuki_assert(device != null_handle, "Device cannot be nullptr.");
        fubuki_assert(swapchain != null_handle, "Swapchain cannot be null_handle.");
    }

    std::uint32_t count = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetSwapchainImagesKHR">(ext, device.vk, swapchain.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkImage> result{};

    result.resize(count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetSwapchainImagesKHR">(ext, device.vk, swapchain.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<image_handle>{result.begin(), result.end()};
}

//------------------------------------------------------------------------------

[[nodiscard]]
presentation::result present(const functions& ext, queue_handle q, const VkPresentInfoKHR& info)
{
    const auto result = fubuki::invoke<"vkQueuePresentKHR">(ext, q.vk, std::addressof(info));

    if(result == VK_SUCCESS or result == VK_SUBOPTIMAL_KHR)
    {
        return presentation::success{static_cast<presentation::success::code>(result)};
    }

    return std::unexpected{presentation::error{static_cast<presentation::error::code>(result)}};
}

    #if defined(VK_VERSION_1_1)

namespace detail
{

[[nodiscard]]
std::expected<void, api_call_info>
present_capabilities(const functions& ext, device_handle device, VkDeviceGroupPresentCapabilitiesKHR& result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDeviceGroupPresentCapabilitiesKHR">(ext, device.vk, std::addressof(result))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

} // namespace detail

[[nodiscard]]
std::expected<std::uint32_t, api_call_info>
acquire_next_image(const functions& ext, device_handle device, const VkAcquireNextImageInfoKHR& info) noexcept
{
    std::uint32_t result = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkAcquireNextImage2KHR">(ext, device.vk, std::addressof(info), &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<VkDeviceGroupPresentModeFlagsKHR, api_call_info>
present_mode(const functions& ext, device_handle device, surface_khr_handle surface) noexcept
{
    VkDeviceGroupPresentModeFlagsKHR result{};

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDeviceGroupSurfacePresentModesKHR">(ext, device.vk, surface.vk, &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<small_vector<VkRect2D>, api_call_info>
present_rectangles(const functions& ext, physical_device_handle device, surface_khr_handle surface)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDevicePresentRectanglesKHR">(ext, device.vk, surface.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    small_vector<VkRect2D> result{static_cast<std::size_t>(count)};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDevicePresentRectanglesKHR">(ext, device.vk, surface.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

    #endif // defined(VK_VERSION_1_1)

#endif // defined(VK_KHR_swapchain)

} // namespace fubuki::extension::khr_swapchain
