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

#ifndef FUBUKI_COMMAND_SUBMIT_HPP
#define FUBUKI_COMMAND_SUBMIT_HPP

#include <optional>
#include <span>

#include <core/as_span.hpp>
#include <core/assertion.hpp>
#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/structure_type.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/command/wait_semaphore.hpp"
#include "fuyu/queue.hpp"
#include "fuyu/views/command_buffer.hpp"
#include "fuyu/views/semaphore.hpp"

namespace fubuki::fuyu
{

namespace command
{

namespace detail
{

/**
 * Submit to a queue.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info>
                              submit(const fuyu::queue& queue, std::span<const VkSubmitInfo> submissions, std::optional<fence_handle> fence) noexcept;

#if defined(VK_VERSION_1_3)

/**
 * Submit command buffers to a queue
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit2.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info>
submit(const fuyu::queue& queue, std::span<const VkSubmitInfo2> submissions, std::optional<fence_handle> fence) noexcept;

#endif // defined(VK_VERSION_1_3)

} // namespace detail

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/// Information about a submission to a queue.
struct submit_info
{
    using underlying_type = VkSubmitInfo;

    struct handles
    {
        small_vector<VkCommandBuffer>      command_buffers;
        small_vector<VkSemaphore>          wait_semaphores;
        small_vector<VkPipelineStageFlags> wait_dst_masks;
        small_vector<VkSemaphore>          signal_semaphores;
    };

    std::span<const command_buffer_view> command_buffers;   ///< Command buffers to submit.
    std::span<const wait_semaphore>      wait_semaphores;   ///< Synchronisation semaphores for waiting on the submission.
    std::span<const semaphore_handle>    signal_semaphores; ///< Synchronisation semaphores for signaling the submission.

    [[nodiscard]] friend handles handles_of(std::reference_wrapper<const submit_info> cref)
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .command_buffers   = collect<VkCommandBuffer>(s.command_buffers),
            .wait_semaphores   = collect<VkSemaphore>(s.wait_semaphores),
            .wait_dst_masks    = collect<VkPipelineStageFlags>(s.wait_semaphores),
            .signal_semaphores = collect<VkSemaphore>(s.signal_semaphores),
        };
    }

    [[nodiscard]] friend underlying_type to_underlying(std::reference_wrapper<const submit_info> /*disambiguation*/,
                                                       std::reference_wrapper<const handles> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                = structure_type_v<VkSubmitInfo>,
            .pNext                = nullptr,
            .waitSemaphoreCount   = vk_size(s.wait_semaphores),
            .pWaitSemaphores      = s.wait_semaphores.empty() ? nullptr : s.wait_semaphores.data(),
            .pWaitDstStageMask    = s.wait_dst_masks.empty() ? nullptr : s.wait_dst_masks.data(),
            .commandBufferCount   = vk_size(s.command_buffers),
            .pCommandBuffers      = s.command_buffers.data(),
            .signalSemaphoreCount = vk_size(s.signal_semaphores),
            .pSignalSemaphores    = s.signal_semaphores.empty() ? nullptr : s.signal_semaphores.data(),
        };
    }
};

/********************************************************************************/
/*                                  VULKAN 1.3                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_3)

/**
 * Structure specifying a semaphore signal or wait operation.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkSemaphoreSubmitInfo.html
 */
struct semaphore_submit_info
{
    using underlying_type = VkSemaphoreSubmitInfo;

    fuyu::semaphore_view  handle;
    std::uint64_t         value        = {};
    VkPipelineStageFlags2 stage_mask   = {};
    std::uint32_t         device_index = {};

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType       = structure_type_v<underlying_type>,
            .pNext       = nullptr,
            .semaphore   = handle.handle.vk,
            .value       = value,
            .stageMask   = stage_mask,
            .deviceIndex = device_index,
        };
    }
};

/**
 * Structure specifying a command buffer submission
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkCommandBufferSubmitInfo.html
 */
struct buffer_submit_info
{
    using underlying_type = VkCommandBufferSubmitInfo;

    command_buffer_view command_buffer;
    std::uint32_t       device_mask = {};

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        return {
            .sType         = structure_type_v<underlying_type>,
            .pNext         = nullptr,
            .commandBuffer = command_buffer.handle.vk,
            .deviceMask    = device_mask,
        };
    }
};

/**
 * Structure specifying a queue submit operation.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkSubmitInfo2.html
 */
struct submit_info_2
{
    using underlying_type = VkSubmitInfo2;

    struct handles
    {
        small_vector<VkSemaphoreSubmitInfo>     wait_semaphores   = {};
        small_vector<VkCommandBufferSubmitInfo> command_buffers   = {};
        small_vector<VkSemaphoreSubmitInfo>     signal_semaphores = {};
    };

    VkSubmitFlags                          flags;
    std::span<const semaphore_submit_info> wait_semaphores;
    std::span<const buffer_submit_info>    command_buffers;
    std::span<const semaphore_submit_info> signal_semaphores;

    [[nodiscard]] friend handles handles_of(std::reference_wrapper<const submit_info_2> cref)
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .wait_semaphores   = collect<VkSemaphoreSubmitInfo>(s.wait_semaphores),
            .command_buffers   = collect<VkCommandBufferSubmitInfo>(s.command_buffers),
            .signal_semaphores = collect<VkSemaphoreSubmitInfo>(s.signal_semaphores),
        };
    }

    [[nodiscard]] friend underlying_type to_underlying(std::reference_wrapper<const submit_info_2> cref,
                                                       std::reference_wrapper<const handles>       handles_cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();
        const auto& h = handles_cref.get();

        return {
            .sType                    = structure_type_v<underlying_type>,
            .pNext                    = nullptr,
            .flags                    = s.flags,
            .waitSemaphoreInfoCount   = vk_size(h.wait_semaphores),
            .pWaitSemaphoreInfos      = h.wait_semaphores.empty() ? nullptr : h.wait_semaphores.data(),
            .commandBufferInfoCount   = vk_size(h.command_buffers),
            .pCommandBufferInfos      = h.command_buffers.data(),
            .signalSemaphoreInfoCount = vk_size(h.signal_semaphores),
            .pSignalSemaphoreInfos    = h.signal_semaphores.empty() ? nullptr : h.signal_semaphores.data(),
        };
    }
};

#endif // defined(VK_VERSION_1_3)

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

//------------------------------------------------------------------------------

/**
 * Submit to a queue. This overloads allows to specify a pnext chain for one or more submissions.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit.html
 */
template<traits::pnext_chain::type... pnext_chains_types>
[[nodiscard]]
inline auto
submit(const fuyu::queue& queue, std::span<const submit_info> submissions, std::optional<fence_handle> fence, pnext_chains_types&&... chains)
{
    small_vector<submit_info::handles>         handles        = {};
    small_vector<submit_info::underlying_type> vk_submissions = {};
    handles.reserve(submissions.size());
    vk_submissions.reserve(submissions.size());

    for(const auto& s : submissions)
    {
        const auto& h = handles.emplace_back(handles_of(s));
        vk_submissions.emplace_back(to_underlying(s, h));
    }

    fubuki::extend_range(vk_submissions, std::forward<pnext_chains_types>(chains)...);

    return detail::submit(queue, vk_submissions, fence);
}

//------------------------------------------------------------------------------

/**
 * Submit to a queue.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit.html
 */
[[nodiscard]]
inline auto submit(const fuyu::queue& queue, std::span<const submit_info> submissions, std::optional<fence_handle> fence)
{
    return submit(queue, submissions, fence, empty_pnext_chain);
}

//------------------------------------------------------------------------------

/**
 * Submit to a queue.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit.html
 */
template<traits::pnext_chain::type pnext_chains_type>
[[nodiscard]]
inline auto submit(const fuyu::queue& queue, const submit_info& submission, std::optional<fence_handle> fence, pnext_chains_type&& chain)
{
    return submit(queue, fubuki::as_span(submission), fence, std::forward<pnext_chains_type>(chain));
}

//------------------------------------------------------------------------------

/**
 * Submit to a queue.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit.html
 */
[[nodiscard]]
inline auto submit(const fuyu::queue& queue, const submit_info& submission, std::optional<fence_handle> fence)
{
    return submit(queue, submission, fence, empty_pnext_chain);
}

/********************************************************************************/
/*                                  VULKAN 1.3                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_3)

/**
 * Submit command buffers to a queue
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit2.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info>
submit(const fuyu::queue& queue, std::span<const VkSubmitInfo2> submissions, std::optional<fence_handle> fence) noexcept;

//------------------------------------------------------------------------------

/**
 * Submit command buffers to a queue
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit2.html
 */
template<traits::pnext_chain::type... pnext_chains_types>
[[nodiscard]]
inline auto
submit(const fuyu::queue& queue, std::span<const submit_info_2> submissions, std::optional<fence_handle> fence, pnext_chains_types&&... chains)
{
    small_vector<submit_info_2::handles>         handles        = {};
    small_vector<submit_info_2::underlying_type> vk_submissions = {};
    handles.reserve(submissions.size());
    vk_submissions.reserve(submissions.size());

    for(const auto& s : submissions)
    {
        const auto& h = handles.emplace_back(handles_of(s));
        vk_submissions.emplace_back(to_underlying(s, h));
    }

    fubuki::extend_range(vk_submissions, std::forward<pnext_chains_types>(chains)...);

    return detail::submit(queue, vk_submissions, fence);
}

//------------------------------------------------------------------------------

/**
 * Submit command buffers to a queue
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit2.html
 */
[[nodiscard]]
inline auto submit(const fuyu::queue& queue, std::span<const submit_info_2> submissions, std::optional<fence_handle> fence)
{
    return submit(queue, submissions, fence, empty_pnext_chain);
}

//------------------------------------------------------------------------------

/**
 * Submit command buffers to a queue
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit2.html
 */
[[nodiscard]]
inline auto submit(const fuyu::queue& queue, const submit_info_2& submission, std::optional<fence_handle> fence)
{
    return submit(queue, fubuki::as_span(submission), fence);
}

#endif // defined(VK_VERSION_1_3)

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_COMMAND_SUBMIT_HPP
