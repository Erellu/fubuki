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

#ifndef FUBUKI_EXTENSION_KHR_DISPLAY_SWAPCHAIN_HPP
#define FUBUKI_EXTENSION_KHR_DISPLAY_SWAPCHAIN_HPP

#include <initializer_list>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_display_swapchain.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_display_swapchain
{

#if defined(VK_KHR_display_swapchain)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateSharedSwapchainsKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<swapchain_khr_handle>, api_call_info> create_shared_swapchains(
    const functions& ext, device_handle device, std::span<const VkSwapchainCreateInfoKHR> create_infos, const VkAllocationCallbacks& allocator);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateSharedSwapchainsKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<swapchain_khr_handle>, api_call_info>
create_shared_swapchains(const functions& ext, device_handle device, std::span<const VkSwapchainCreateInfoKHR> create_infos);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateSharedSwapchainsKHR.html
[[nodiscard]] inline auto
create_shared_swapchains(const functions& ext, device_handle device, std::initializer_list<VkSwapchainCreateInfoKHR> create_infos)
{
    return create_shared_swapchains(ext, device, std::span{create_infos});
}

#endif // defined(VK_KHR_display_swapchain)

} // namespace fubuki::extension::khr_display_swapchain

#endif // FUBUKI_EXTENSION_KHR_DISPLAY_SWAPCHAIN_HPP
