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

#include "fuyu/functions/fence.hpp"

#include <core/collect.hpp>

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

[[nodiscard]]
std::expected<void, api_call_info> reset(std::span<const fence_view> fences)
{
    const auto handles = collect<VkFence>(fences);

    fubuki_assert(!fences.empty(), "Cannot reset 0 fence.");

    const device_view device = fences.front().device.get();

    return fubuki_validate(validate_by::expected, fuyu::invoke<"vkResetFences">(device, vk_size(handles), handles.data()));
}

//------------------------------------------------------------------------------

[[nodiscard]]
wait_result wait_for(std::span<const fence_view> fences, bool wait_all, std::chrono::nanoseconds timeout)
{
    fubuki_assert(!fences.empty(), "Cannot reset 0 fence.");

    const auto        handles = collect<VkFence>(fences);
    const device_view device  = fences.front().device.get();

    // Validation
    {
        fubuki_assert(timeout.count() >= 0, "Timeout must be positive.");
        fubuki_assert(!fences.empty(), "At least one fence is required.");
    }

    const auto result = fuyu::invoke<"vkWaitForFences">(
        device, vk_size(handles), handles.data(), static_cast<VkBool32>(wait_all), static_cast<std::uint64_t>(timeout.count()));

    if(result == VK_SUCCESS or result == VK_TIMEOUT)
    {
        return wait_success{static_cast<wait_success::code>(result)};
    }

    return std::unexpected{wait_error{static_cast<wait_error::code>(result)}};
}

//------------------------------------------------------------------------------

[[nodiscard]]
fence_state current_state(fence_view fence) noexcept
{
    const auto result = fuyu::invoke<"vkGetFenceStatus">(fence.device, fence.handle.vk);

    if(result == VK_SUCCESS)
    {
        return fence_state::signaled;
    }

    if(result == VK_NOT_READY)
    {
        return fence_state::not_ready;
    }

    if(result == VK_ERROR_DEVICE_LOST)
    {
        return fence_state::device_lost;
    }

    return fence_state::unknown;
}

} // namespace fubuki::fuyu
