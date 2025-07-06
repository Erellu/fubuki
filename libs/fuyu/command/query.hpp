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

#ifndef FUBUKI_FUYU_COMMAND_QUERY_HPP
#define FUBUKI_FUYU_COMMAND_QUERY_HPP

#include <cstdint>

#include <core/config/macros.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"
#include "fuyu/views/query_pool.hpp"

namespace fubuki::fuyu
{

namespace command
{

/// Query commands.
namespace query
{

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Begin a query.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginQuery.html
 */
FUBUKI_FUYU_API
extern void begin(command_buffer_view command_buffer, fuyu::any_query_pool_view pool, std::uint32_t query, VkQueryControlFlags flags = {}) noexcept;

/**
 * End a query.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndQuery.html
 */
FUBUKI_FUYU_API
extern void end(command_buffer_view command_buffer, fuyu::any_query_pool_view pool, std::uint32_t query) noexcept;

/**
 * Reset queries in a query pool.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResetQueryPool.html
 */
FUBUKI_FUYU_API
extern void
reset_pool(command_buffer_view command_buffer, fuyu::any_query_pool_view pool, std::uint32_t first_query, std::uint32_t query_count) noexcept;

/**
 * Copy the results of queries in a query pool to a buffer object.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyQueryPoolResults.html
 */
FUBUKI_FUYU_API
extern void copy_pool_results(command_buffer_view       command_buffer,
                              fuyu::any_query_pool_view query_pool,
                              std::uint32_t             first_query,
                              std::uint32_t             query_count,
                              buffer_handle             destination,
                              VkDeviceSize              offset,
                              VkDeviceSize              stride,
                              VkQueryResultFlags        flags = {}) noexcept;

/**
 * Write a device timestamp into a query object.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteTimestamp.html
 */
FUBUKI_FUYU_API
extern void
write_timestamp(command_buffer_view command_buffer, VkPipelineStageFlagBits stage, fuyu::any_query_pool_view pool, std::uint32_t query) noexcept;

//------------------------------------------------------------------------------

/**
 * A RAII object equivalent to an immediate call to command::query::begin and a call to command::query::end upon its destruction.
 */
class scope
{
public:

    // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
    scope(command_buffer_view command_buffer, fuyu::any_query_pool_view pool, std::uint32_t query, VkQueryControlFlags flags = {}) noexcept
        : m_command_buffer{command_buffer},
          m_pool{pool},
          m_query{query}
    {
        query::begin(m_command_buffer, m_pool, m_query, flags);
    }

    ~scope() noexcept { query::end(m_command_buffer, m_pool, m_query); }

    scope(scope&&) noexcept            = delete;
    scope& operator=(scope&&) noexcept = delete;

    scope(const scope&) noexcept            = delete;
    scope& operator=(const scope&) noexcept = delete;

private:
    command_buffer_view       m_command_buffer;
    fuyu::any_query_pool_view m_pool;
    std::uint32_t             m_query;
};

/********************************************************************************/
/*                                  VULKAN 1.3                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_3)

/**
 * Write a device timestamp into a query object.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteTimestamp2KHR.html
 */
FUBUKI_FUYU_API
extern void
write_timestamp(command_buffer_view command_buffer, VkPipelineStageFlags2 stage, fuyu::any_query_pool_view pool, std::uint32_t query) noexcept;

#endif // defined(VK_VERSION_1_3)
} // namespace query

using query_scope = query::scope;

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_QUERY_HPP
