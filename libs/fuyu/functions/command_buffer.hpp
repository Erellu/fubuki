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

#ifndef FUBUKI_FUYU_FUNCTIONS_COMMAND_BUFFER_HPP
#define FUBUKI_FUYU_FUNCTIONS_COMMAND_BUFFER_HPP

#include <optional>
#include <span>

#include <core/as_span.hpp>
#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/structure_type.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/command/wait_semaphore.hpp"
#include "fuyu/queue.hpp"
#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

struct submission
{
    std::optional<fence_handle>           fence             = {};
    small_vector<command::wait_semaphore> wait_semaphores   = {};
    small_vector<semaphore_handle>        signal_semaphores = {};
};

/**
 * Starts a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBeginCommandBuffer.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> begin(command_buffer_view             command_buffer,
                                                                       const VkCommandBufferBeginInfo& info) noexcept;

/**
 * Starts a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBeginCommandBuffer.html
 */
template<traits::pnext_chain::type pnext_chain_type>
[[nodiscard]]
inline auto begin(command_buffer_view command_buffer, VkCommandBufferUsageFlags flags, pnext_chain_type&& chain)
{
    VkCommandBufferBeginInfo info
        = {.sType = structure_type_v<VkCommandBufferBeginInfo>, .pNext = nullptr, .flags = flags, .pInheritanceInfo = nullptr};

    fubuki::extend(info, std::forward<pnext_chain_type>(chain));

    return begin(command_buffer, info);
}

/**
 * Starts a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBeginCommandBuffer.html
 */
template<traits::pnext_chain::type pnext_chain_type>
[[nodiscard]]
inline auto begin(command_buffer_view                   command_buffer,
                  VkCommandBufferUsageFlags             flags,
                  const VkCommandBufferInheritanceInfo& inheritance,
                  pnext_chain_type&&                    chain)
{
    VkCommandBufferBeginInfo info
        = {.sType = structure_type_v<VkCommandBufferBeginInfo>, .pNext = nullptr, .flags = flags, .pInheritanceInfo = &inheritance};

    extend(info, std::forward<pnext_chain_type>(chain));

    return begin(command_buffer, info);
}

/**
 * Starts a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBeginCommandBuffer.html
 */
[[nodiscard]]
inline auto begin(command_buffer_view command_buffer, VkCommandBufferUsageFlags flags = {})
{
    return begin(command_buffer, flags, empty_pnext_chain);
}

/**
 * Starts a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBeginCommandBuffer.html
 */
[[nodiscard]]
inline auto begin(command_buffer_view command_buffer, VkCommandBufferUsageFlags flags, const VkCommandBufferInheritanceInfo& inheritance)
{
    return begin(command_buffer, flags, inheritance, empty_pnext_chain);
}

//------------------------------------------------------------------------------

/**
 * Resets a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkResetCommandBuffer.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> reset(command_buffer_view       command_buffer,
                                                                       VkCommandBufferResetFlags flags = {}) noexcept;

//------------------------------------------------------------------------------

/**
 * Ends a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkEndCommandBuffer.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> end(command_buffer_view command_buffer) noexcept;

//------------------------------------------------------------------------------

/**
 * Submits command buffers to a queue.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkQueueSubmit.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> submit(const fuyu::queue&                       queue,
                                                                        std::span<const command_buffer_view>     command_buffers,
                                                                        std::optional<fence_handle>              fence             = {},
                                                                        std::span<const command::wait_semaphore> wait_semaphores   = {},
                                                                        std::span<const semaphore_handle>        signal_semaphores = {});

/**
 * Submits command buffers to a queue.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkQueueSubmit.html
 */
[[nodiscard]] inline std::expected<void, api_call_info>
submit(const fuyu::queue& queue, std::span<const command_buffer_view> command_buffers, const submission& sub)
{
    return submit(queue, command_buffers, sub.fence, sub.wait_semaphores, sub.signal_semaphores);
}

/**
 * Submits a command buffer to a queue.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkQueueSubmit.html
 */
[[nodiscard]]
inline std::expected<void, api_call_info> submit(const fuyu::queue&                       queue,
                                                 command_buffer_view                      command_buffer,
                                                 std::optional<fence_handle>              fence             = {},
                                                 std::span<const command::wait_semaphore> wait_semaphores   = {},
                                                 std::span<const semaphore_handle>        signal_semaphores = {})
{
    return submit(queue, fubuki::as_span(command_buffer), fence, wait_semaphores, signal_semaphores);
}

/**
 * Submits a command buffer to a queue.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkQueueSubmit.html
 */
[[nodiscard]]
inline std::expected<void, api_call_info> submit(const fuyu::queue& queue, command_buffer_view command_buffer, const submission& sub)
{
    return submit(queue, fubuki::as_span(command_buffer), sub.fence, sub.wait_semaphores, sub.signal_semaphores);
}

//------------------------------------------------------------------------------

/**
 * A RAII object equivalent to a call to cmd::begin() upon construction, and to cmd::end() upon destruction.
 *
 * The errors are conditionnally reported based on the constructor called. If a recorded_scope::result is provided, then the errors are reported
 * through this object.
 * If no such object is provided, the errors are NOT reported by this object (validation layers, if enabled, still catch these errors).
 * It is recommended to assert()/fubuki_assert() that recorded_scope().active() in both circumstances.
 */
class recorded_scope
{
public:

    /// An object that stores the results of API calls.
    struct result
    {
        std::optional<api_call_info> begin = {}; ///< Indicates if an error occurred upon starting the command buffer.
        std::optional<api_call_info> end   = {}; ///< Indicates if an error occurred upon ending the command buffer.
    };

    /**
     * Starts a command buffer for a given scope.
     * @param r The object that report the API call that failed.
     * @param buffer The command buffer to start.
     * @param args Optional parameters to cmd::begin. @see cmd::begin.
     */
    template<typename... arguments>
    recorded_scope(result& r, command_buffer_view buffer, arguments&&... args) noexcept : m_command_buffer{buffer},
                                                                                          m_result{r}
    {
        if(const auto check = begin(m_command_buffer, std::forward<arguments>(args)...); not check)
        {
            if(m_result.has_value())
            {
                m_result->get().begin = check.error();
            }
            m_active = false;
        }
    }

    /**
     * Starts a command buffer for a given scope. This overloads does NOT report API call errors (validation layers still report them).
     * @param buffer The command buffer to start.
     * @param args Optional parameters to cmd::begin. @see cmd::begin.
     */
    template<typename... arguments>
    recorded_scope(command_buffer_view buffer, arguments&&... args) noexcept : m_command_buffer{buffer}
    {
        if(const auto check = begin(m_command_buffer, std::forward<args>(args)...); not check)
        {
            m_active = false;
        }
    }

    /// Move constructor.
    recorded_scope(recorded_scope&& other) noexcept : m_command_buffer{other.m_command_buffer}, m_result{other.m_result}, m_active{other.m_active}
    {
        other.m_active = false;
        other.m_result = {};
    }

    recorded_scope& operator=(recorded_scope&&) noexcept = delete;

    recorded_scope(const recorded_scope&) noexcept            = delete;
    recorded_scope& operator=(const recorded_scope&) noexcept = delete;

    ~recorded_scope() noexcept
    {
        if(m_active)
        {
            if(const auto check = end(m_command_buffer); not check)
            {
                if(m_result.has_value())
                {
                    m_result->get().end = check.error();
                }
            }
        }
    }

    /// Indicates if the scope is active, that is, it was possible to start the command buffer.
    [[nodiscard]] bool active() const { return m_active; }

private:

    command_buffer_view                           m_command_buffer; ///< The command buffer that will record the commands.
    std::optional<std::reference_wrapper<result>> m_result;         ///< The object reporting API errors.
    bool                                          m_active = true;  ///< Indicates if it was possible to start the command buffer.
};

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_COMMAND_BUFFER_HPP
