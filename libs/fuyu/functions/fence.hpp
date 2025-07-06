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

#ifndef FUBUKI_FUYU_FUNCTIONS_EVENT_HPP
#define FUBUKI_FUYU_FUNCTIONS_EVENT_HPP

#include <chrono>
#include <span>

#include <core/as_span.hpp>
#include <core/config/macros.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/detail/wait_result.hpp"
#include "fuyu/views/fence.hpp"

namespace fubuki::fuyu
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Resets an array of fences.
 * @param fences Fences to reset.
 * @pre All fences must belong to the same device.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkResetFences.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> reset(std::span<const fuyu::fence_view> fences);

/**
 * Resets an array of fences.
 * @param fences Fences to reset.
 * @pre All fences must belong to the same device.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkResetFences.html
 */
[[nodiscard]] inline std::expected<void, api_call_info> reset_fences(std::initializer_list<fuyu::fence_view> fences)
{
    return reset(std::span{fences});
}

/**
 * Resets a fence.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkResetFences.html
 */
[[nodiscard]] inline std::expected<void, api_call_info> reset(fuyu::fence_view fence) noexcept { return reset(fubuki::as_span(fence)); }

//------------------------------------------------------------------------------

/**
 * Waits for one of more fences to be signaled.
 * @param fences Fences to wait for.
 * @param wait_all Waits for all fences if true, or just for the first one otherwise.
 * @param timeout Timeout.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitForFences.html
 */
[[nodiscard]] FUBUKI_FUYU_API wait_result wait_for(std::span<const fuyu::fence_view> fences, bool wait_all, std::chrono::nanoseconds timeout);

/**
 * Waits for one of more fences to be signaled.
 * @param fences Fences to wait for.
 * @param wait_all Waits for all fences if true, or just for the first one otherwise.
 * @param timeout Timeout.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitForFences.html
 */
[[nodiscard]] inline wait_result wait_for(std::initializer_list<fuyu::fence_view> fences, bool wait_all, std::chrono::nanoseconds timeout)
{
    return wait_for(std::span{fences}, wait_all, timeout);
}

/**
 * Waits for a fence to be signaled.
 * @returns 'true' if succeeded, 'false' if timeout.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitForFences.html
 */
[[nodiscard]]
inline wait_result wait_for(fuyu::fence_view fence, std::chrono::nanoseconds timeout) noexcept
{
    return wait_for(fubuki::as_span(fence), true, timeout);
}

//------------------------------------------------------------------------------

/// Returns the current state of a fence .
[[nodiscard]] FUBUKI_FUYU_API fuyu::fence_state current_state(fuyu::fence_view fence) noexcept;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_EVENT_HPP
