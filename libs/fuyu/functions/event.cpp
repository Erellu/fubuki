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

#include "fuyu/functions/event.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

[[nodiscard]]
std::expected<void, api_call_info> set(event_view event) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkSetEvent">(event.device, event.handle.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
std::expected<void, api_call_info> reset(event_view event) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkResetEvent">(event.device, event.handle.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

//------------------------------------------------------------------------------

[[nodiscard]]
event_state current_state(event_view event) noexcept
{
    const auto result = fuyu::invoke<"vkGetEventStatus">(event.device, event.handle.vk);

    if(result == VK_EVENT_SET)
    {
        return event_state::set;
    }

    if(result == VK_EVENT_RESET)
    {
        return event_state::reset;
    }

    return event_state::unknown;
}

} // namespace fubuki::fuyu
