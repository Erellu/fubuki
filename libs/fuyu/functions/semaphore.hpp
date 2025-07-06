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

#ifndef FUBUKI_FUYU_FUNCTIONS_SEMAPHORE_HPP
#define FUBUKI_FUYU_FUNCTIONS_SEMAPHORE_HPP

#include <chrono>
#include <cstdint>
#include <span>

#include <core/as_span.hpp>
#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/detail/wait_result.hpp"
#include "fuyu/views/semaphore.hpp"

namespace fubuki::fuyu
{

/********************************************************************************/
/*                                  VULKAN 1.2                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_2)

namespace detail
{

[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> signal(fuyu::semaphore_view semaphore, const VkSemaphoreSignalInfo& sign) noexcept;

[[nodiscard]] FUBUKI_FUYU_API wait_result wait_on(device_cref device, const VkSemaphoreWaitInfo& wait, std::uint64_t timeout);

} // namespace detail

/**
 * Queries the current state of a timeline semaphore.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetSemaphoreCounterValueKHR.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<std::uint64_t, api_call_info> counter_value(fuyu::semaphore_view semaphore) noexcept;

//------------------------------------------------------------------------------

/**
 * Signals a semaphore.
 * @param semaphore The semaphore to signal.
 * @param value The value to signal.
 * @param pnext Chain extending VkSemaphoreSignalInfo.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkSignalSemaphore.html
 */
template<typename... pnext_elements>
[[nodiscard]] inline std::expected<void, api_call_info>
signal(fuyu::semaphore_view semaphore, std::uint64_t value, const pnext_chain<pnext_elements...>& pnext) noexcept
{
    VkSemaphoreSignalInfo semaphore_signal{
        .sType = structure_type_v<VkSemaphoreSignalInfo>, .pNext = nullptr, .semaphore = semaphore.handle.vk, .value = value};

    fubuki::extend(semaphore_signal, pnext);

    return detail::signal(semaphore, semaphore_signal);
}

/**
 * Signals a semaphore.
 * @param semaphore The semaphore to signal.
 * @param value The value to signal.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkSignalSemaphore.html
 */
[[nodiscard]] inline std::expected<void, api_call_info> signal(fuyu::semaphore_view semaphore, std::uint64_t value) noexcept
{
    return signal(semaphore, value, empty_pnext_chain);
}

//------------------------------------------------------------------------------

/**
 * Waits for semaphores to reach certain values.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction to each semaphore.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitSemaphores.html
 */
template<typename... pnext_elements>
[[nodiscard]] inline wait_result wait_on(std::span<const fuyu::semaphore_view> semaphores,
                                         std::span<const std::uint64_t>        values,
                                         std::chrono::nanoseconds              timeout,
                                         VkSemaphoreWaitFlags                  flags,
                                         const pnext_chain<pnext_elements...>& pnext)
{
    fubuki_assert(!semaphores.empty(), "Cannot wait on 0 semaphore.");

    const auto handles = collect<VkSemaphore>(semaphores);

    {
        fubuki_assert(timeout.count() >= 0, "Timeout must be positive.");
        fubuki_assert(semaphores.size() == values.size(), "Missing semaphores or values.");
        fubuki_assert(!semaphores.empty(), "At least one semaphore is required.");
    }

    VkSemaphoreWaitInfo wait{
        .sType          = structure_type_v<VkSemaphoreWaitInfo>,
        .pNext          = nullptr, // Cannot be extend yet
        .flags          = flags,
        .semaphoreCount = vk_size(handles),
        .pSemaphores    = handles.data(),
        .pValues        = values.data(),
    };

    fubuki::extend(wait, pnext);

    return detail::wait_on(semaphores.front().device, wait, static_cast<std::uint64_t>(timeout.count()));
}

/**
 * Waits for semaphores to reach certain values.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction to each semaphore.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitSemaphores.html
 */
[[nodiscard]] inline wait_result wait_on(std::span<const fuyu::semaphore_view> semaphores,
                                         std::span<const std::uint64_t>        values,
                                         std::chrono::nanoseconds              timeout,
                                         VkSemaphoreWaitFlags                  flags = {})
{
    return wait_on(semaphores, values, timeout, flags, empty_pnext_chain);
}

/**
 * Waits for semaphores to reach certain values.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction to each semaphore.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitSemaphores.html
 */
template<typename... pnext_elements>
[[nodiscard]] inline auto wait_on(std::initializer_list<fuyu::semaphore_view> semaphores,
                                  std::initializer_list<std::uint64_t>        values,
                                  std::chrono::nanoseconds                    timeout,
                                  VkSemaphoreWaitFlags                        flags,
                                  const pnext_chain<pnext_elements...>&       pnext)
{
    return wait_on(std::span{semaphores}, std::span{values}, timeout, flags, pnext);
}

/**
 * Waits for semaphores to reach certain values.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction to each semaphore.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitSemaphores.html
 */
[[nodiscard]] inline auto wait_on(std::initializer_list<fuyu::semaphore_view> semaphores,
                                  std::initializer_list<std::uint64_t>        values,
                                  std::chrono::nanoseconds                    timeout,
                                  VkSemaphoreWaitFlags                        flags = {})
{
    return wait_on(semaphores, values, timeout, flags, empty_pnext_chain);
}

//------------------------------------------------------------------------------

/**
 * Waits for the semaphore to reach a certain value.
 * @pre A VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE has been provided upon construction.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitSemaphores.html
 */
[[nodiscard]] inline auto
wait_on(fuyu::semaphore_view semaphore, std::uint64_t value, std::chrono::nanoseconds timeout, VkSemaphoreWaitFlags flags = {}) noexcept
{
    return wait_on(fubuki::as_span(semaphore), fubuki::as_span(value), timeout, flags);
}

#endif // defined (VK_VERSION_1_2

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_SEMAPHORE_HPP
