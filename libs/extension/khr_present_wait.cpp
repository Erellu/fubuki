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

#include "extension/khr_present_wait.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_present_wait
{

#if defined(VK_KHR_present_wait)

[[nodiscard]]
result wait_for_present(
    const functions& ext, device_handle device, swapchain_khr_handle swapchain, std::uint64_t present_id, std::chrono::nanoseconds timeout) noexcept
{
    const auto count = timeout.count();

    fubuki_assert(count > 0, "Timeout must be positive.");

    const auto r = fubuki::invoke<"vkWaitForPresentKHR">(ext, device.vk, swapchain.vk, present_id, static_cast<std::uint64_t>(count));

    if(r == VK_SUCCESS or r == VK_SUBOPTIMAL_KHR or r == VK_TIMEOUT)
    {
        return success{static_cast<success::code>(r)};
    }

    return std::unexpected{error{static_cast<error::code>(r)}};
}

#endif // defined(VK_KHR_present_wait)

} // namespace fubuki::extension::khr_present_wait
