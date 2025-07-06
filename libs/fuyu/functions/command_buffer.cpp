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

#include "fuyu/functions/command_buffer.hpp"

#include "fuyu/command/submit.hpp"
#include "fuyu/invoke.hpp"

namespace fubuki::fuyu
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

[[nodiscard]]
std::expected<void, api_call_info> begin(command_buffer_view command_buffer, const VkCommandBufferBeginInfo& info) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkBeginCommandBuffer">(command_buffer,std::addressof(info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, api_call_info> reset(command_buffer_view command_buffer, VkCommandBufferResetFlags flags) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkResetCommandBuffer">(command_buffer, flags)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, api_call_info> end(command_buffer_view command_buffer) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkEndCommandBuffer">(command_buffer)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, api_call_info> submit(const fuyu::queue&                       queue,
                                          std::span<const command_buffer_view>     command_buffers,
                                          std::optional<fence_handle>              fence,
                                          std::span<const command::wait_semaphore> wait_semaphores,
                                          std::span<const semaphore_handle>        signal_semaphores)
{
    const command::submit_info submission = {
        .command_buffers   = command_buffers,
        .wait_semaphores   = wait_semaphores,
        .signal_semaphores = signal_semaphores,
    };

    return cmd::submit(queue, submission, fence);
}

} // namespace fubuki::fuyu
