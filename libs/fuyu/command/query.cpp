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

#include "fuyu/command/query.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu::command::query
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

void begin(command_buffer_view command_buffer, fuyu::any_query_pool_view pool, const std::uint32_t query, const VkQueryControlFlags flags) noexcept
{
    const auto visitor = [&command_buffer, query, flags](auto& query_pool) noexcept
    { return fuyu::invoke<"vkCmdBeginQuery">(command_buffer, query_pool.handle.vk, query, flags); };

    return std::visit(visitor, pool);
}

void reset_pool(command_buffer_view       command_buffer,
                fuyu::any_query_pool_view pool,
                const std::uint32_t       first_query,
                const std::uint32_t       query_count) noexcept
{
    const auto visitor = [&command_buffer, first_query, query_count](auto& query_pool) noexcept
    { return fuyu::invoke<"vkCmdResetQueryPool">(command_buffer, query_pool.handle.vk, first_query, query_count); };

    return std::visit(visitor, pool);
}

void copy_pool_results(command_buffer_view       command_buffer,
                       fuyu::any_query_pool_view pool,
                       const std::uint32_t       first_query,
                       const std::uint32_t       query_count,
                       buffer_handle             destination,
                       const VkDeviceSize        offset,
                       const VkDeviceSize        stride,
                       const VkQueryResultFlags  flags) noexcept
{
    const auto visitor = [=, &command_buffer](auto& query_pool) noexcept
    {
        return fuyu::invoke<"vkCmdCopyQueryPoolResults">(
            command_buffer, query_pool.handle.vk, first_query, query_count, destination.vk, offset, stride, flags);
    };

    return std::visit(visitor, pool);
}

void end(command_buffer_view command_buffer, fuyu::any_query_pool_view pool, const std::uint32_t query) noexcept
{
    const auto visitor
        = [&command_buffer, query](auto& query_pool) noexcept { return fuyu::invoke<"vkCmdEndQuery">(command_buffer, query_pool.handle.vk, query); };

    return std::visit(visitor, pool);
}

void write_timestamp(command_buffer_view           command_buffer,
                     const VkPipelineStageFlagBits stage,
                     fuyu::any_query_pool_view     pool,
                     const std::uint32_t           query) noexcept
{
    const auto visitor = [&command_buffer, stage, query](auto& query_pool) noexcept
    { return fuyu::invoke<"vkCmdWriteTimestamp">(command_buffer, stage, query_pool.handle.vk, query); };

    return std::visit(visitor, pool);
}

/********************************************************************************/
/*                                  VULKAN 1.3                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_3)

void write_timestamp(command_buffer_view         command_buffer,
                     const VkPipelineStageFlags2 stage,
                     fuyu::any_query_pool_view   pool,
                     const std::uint32_t         query) noexcept
{
    const auto visitor = [&command_buffer, stage, query](auto& query_pool) noexcept
    { return fuyu::invoke<"vkCmdWriteTimestamp2">(command_buffer, stage, query_pool.handle.vk, query); };

    return std::visit(visitor, pool);
}

#endif // defined(VK_VERSION_1_3)

} // namespace fubuki::fuyu::command::query
