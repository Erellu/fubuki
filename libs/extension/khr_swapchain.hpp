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

#ifndef FUBUKI_EXTENSION_KHR_SWAPCHAIN_HPP
#define FUBUKI_EXTENSION_KHR_SWAPCHAIN_HPP

#include <chrono>
#include <cstdint>
#include <optional>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_swapchain.hpp" // IWYU pragma: export

/**
 * The VK_KHR_swapchain extension is the device-level companion to the VK_KHR_surface extension.
 * It introduces VkSwapchainKHR objects, which provide the ability to present rendering results to a surface.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_KHR_swapchain.html
 */
namespace fubuki::extension::khr_swapchain
{

namespace presentation
{

struct success
{
    /// Codes indicating the presentation succeeded.
    enum class code : std::underlying_type_t<VkResult>
    {
        normal     = VK_SUCCESS,
        suboptimal = VK_SUBOPTIMAL_KHR,
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const success& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

struct error
{
    /// Codes indicating an error occurred during the presentation.
    enum class code : std::underlying_type_t<VkResult>
    {
        out_of_host_memory              = VK_ERROR_OUT_OF_HOST_MEMORY,
        out_of_device_memory            = VK_ERROR_OUT_OF_DEVICE_MEMORY,
        device_lost                     = VK_ERROR_DEVICE_LOST,
        out_of_date                     = VK_ERROR_OUT_OF_DATE_KHR,
        surface_lost                    = VK_ERROR_SURFACE_LOST_KHR,
        full_screen_exclusive_mode_lost = VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const error& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

using result = std::expected<success, error>; ///< Result of a call to present().

} // namespace presentation

#if defined(VK_KHR_swapchain)

/// Creates a swapchain for a device.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<swapchain_khr_handle, api_call_info>
                                   create(const functions& ext, device_handle device, const VkSwapchainCreateInfoKHR& info) noexcept;

/// Creates a swapchain for a device.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<swapchain_khr_handle, api_call_info>
create(const functions& ext, device_handle device, const VkSwapchainCreateInfoKHR& info, const VkAllocationCallbacks& callbacks) noexcept;

/// Destroys a swapchain for a device.
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, swapchain_khr_handle& swapchain) noexcept;

/// Destroys a swapchain for a device.
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, swapchain_khr_handle& swapchain, const VkAllocationCallbacks& callbacks) noexcept;

/**
 * Returns the index of the next available presentable image of a swapchain.
 * @param ext Extension functions.
 * @param swapchain Swapchain from which the image index is acquired.
 * @param timeout How much the function waits if no image is available.
 * @param semaphore (optional) Synchronisation semaphore.
 * @param fence (optional) Synchronisation fence.
 * @pre At least one of 'semaphore' or 'fence' must have a value that is not VK_NULL_HANDLE.
 * @pre timeout must be positive.
 */
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::uint32_t, api_call_info> acquire_next_image(const functions&                ext,
                                                                                                  device_handle                   device,
                                                                                                  swapchain_khr_handle            swapchain,
                                                                                                  std::chrono::nanoseconds        timeout,
                                                                                                  std::optional<semaphore_handle> semaphore = {},
                                                                                                  std::optional<fence_handle> fence = {}) noexcept;

/// Returns the array of presentable images associated with a swapchain.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<image_handle>, api_call_info>
                                   images(const functions& ext, device_handle device, swapchain_khr_handle swapchain);

/// Queue an image for presentation.
[[nodiscard]] FUBUKI_EXTENSION_API presentation::result present(const functions& ext, queue_handle q, const VkPresentInfoKHR& info);

    /********************************************************************************/
    /*                                 VULKAN 1.1                                   */
    /********************************************************************************/

    #if defined(VK_VERSION_1_1)

namespace detail
{

/// Queries present capabilities from other physical devices.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
present_capabilities(const functions& ext, device_handle device, VkDeviceGroupPresentCapabilitiesKHR& result) noexcept;

} // namespace detail

/// Returns the index of the next available presentable image of a swapchain.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::uint32_t, api_call_info>
                                   acquire_next_image(const functions& ext, device_handle device, const VkAcquireNextImageInfoKHR& info) noexcept;

/// Queries present capabilities from other physical devices.
template<typename... pnext_elements>
[[nodiscard]] inline std::expected<VkDeviceGroupPresentCapabilitiesKHR, api_call_info>
present_capabilities(const functions& ext, device_handle device, const pnext_chain<pnext_elements...>& pnext) noexcept
{
    VkDeviceGroupPresentCapabilitiesKHR result
        = {.sType = structure_type_v<VkDeviceGroupPresentCapabilitiesKHR>, .pNext = {}, .presentMask = {}, .modes = {}};

    fubuki::extend(result, pnext);

    if(const auto check = detail::present_capabilities(ext, device, result); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

/// Queries present capabilities from other physical devices.
[[nodiscard]] inline auto present_capabilities(const functions& ext, device_handle device) noexcept
{
    return present_capabilities(ext, device, empty_pnext_chain);
}

/// Queries present capabilities for a surface.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<VkDeviceGroupPresentModeFlagsKHR, api_call_info>
                                   present_mode(const functions& ext, device_handle device, surface_khr_handle surface) noexcept;

/// Queries present rectangles for a surface on a physical device.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkRect2D>, api_call_info>
                                   present_rectangles(const functions& ext, physical_device_handle device, surface_khr_handle surface);

    #endif // defined(VK_VERSION_1_1)

#endif // defined(VK_KHR_swapchain)

} // namespace fubuki::extension::khr_swapchain

#endif // FUBUKI_EXTENSION_KHR_SWAPCHAIN_HPP
