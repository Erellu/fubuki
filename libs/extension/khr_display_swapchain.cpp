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

#include "extension/khr_display_swapchain.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::khr_display_swapchain
{

#if defined(VK_KHR_display_swapchain)

namespace
{

[[nodiscard]]
std::expected<small_vector<swapchain_khr_handle>, api_call_info> create_shared_swapchains(const functions&                          ext,
                                                                                          device_handle                             device,
                                                                                          std::span<const VkSwapchainCreateInfoKHR> create_infos,
                                                                                          const VkAllocationCallbacks*              allocator)
{
    small_vector<VkSwapchainKHR> swapchains(create_infos.size());

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateSharedSwapchainsKHR">(ext, device.vk, vk_size(create_infos), create_infos.data(), allocator, swapchains.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return small_vector<swapchain_khr_handle>{swapchains.begin(), swapchains.end()};
}

} // anonymous namespace

[[nodiscard]]
std::expected<small_vector<swapchain_khr_handle>, api_call_info> create_shared_swapchains(const functions&                          ext,
                                                                                          device_handle                             device,
                                                                                          std::span<const VkSwapchainCreateInfoKHR> create_infos,
                                                                                          const VkAllocationCallbacks&              allocator)
{
    return create_shared_swapchains(ext, device, create_infos, std::addressof(allocator));
}

[[nodiscard]]
std::expected<small_vector<swapchain_khr_handle>, api_call_info>
create_shared_swapchains(const functions& ext, device_handle device, std::span<const VkSwapchainCreateInfoKHR> create_infos)
{
    return create_shared_swapchains(ext, device, create_infos, nullptr);
}

#endif // defined(VK_KHR_display_swapchain)

} // namespace fubuki::extension::khr_display_swapchain
