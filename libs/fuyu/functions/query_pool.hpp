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

#ifndef FUBUKI_FUYU_FUNCTIONS_QUERY_POOL_HPP
#define FUBUKI_FUYU_FUNCTIONS_QUERY_POOL_HPP

#include <climits>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/query_pool.hpp"

namespace fubuki::fuyu
{

// In such environnements, there will be mismatches between sizes for the GPU and CPU. Not taking risks.
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
static_assert(CHAR_BIT == 8, "Fubuki does not support systems for which a byte is not 8 bits.");
static_assert(sizeof(std::uint32_t) == 4, "Fubuki does not support systems for which a uint32_t is not 4 bytes.");
static_assert(sizeof(std::uint64_t) == 8, "Fubuki does not support systems for which a uint64_t is not 8 bytes.");
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers)

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Returns the requirements for the storage buffer to retrieve the results of a query pool.
 * @param pool Query pool to check.
 * @param first First query to inspect.
 * @param count Total number of queries to inspect.
 * @param flags Bitmask specifying how and when to obtain results.
 */
[[nodiscard]] FUBUKI_FUYU_API fuyu::query_pool_result_buffer_requirements
buffer_requirements(fuyu::any_query_pool_view pool, std::uint32_t first, std::uint32_t count, VkQueryResultFlags flags) noexcept;

//------------------------------------------------------------------------------

/**
 * Allocates a host-side buffer matching requirements given as parameters.
 * @param requirements Requirements for the buffer.
 */
[[nodiscard]]
inline fuyu::query_pool_result_buffer allocate_buffer(fuyu::query_pool_result_buffer_requirements requirements)
{
    using buffer_storage = fuyu::query_pool_result_buffer::storage_type;

    const auto visitor = [byte_count = requirements.byte_count](const auto& type) -> buffer_storage
    {
        using result_type = std::decay_t<decltype(type)>;

        return {std::vector<result_type>(byte_count / sizeof(result_type))};
    };

    return {
        std::visit(visitor, requirements.type),
        requirements.stride,
    };
}

/**
 * Allocates a host-side buffer matching requirements given as parameters.
 * @param pool Query pool to check.
 * @param first First query to inspect.
 * @param count Total number of queries to inspect.
 * @param flags Bitmask specifying how and when to obtain results.
 */
[[nodiscard]]
inline fuyu::query_pool_result_buffer
allocate_buffer(fuyu::any_query_pool_view pool, const std::uint32_t first, const std::uint32_t count, const VkQueryResultFlags flags)
{
    return allocate_buffer(buffer_requirements(pool, first, count, flags));
}

//------------------------------------------------------------------------------

/**
 * Returns results for queries in a given range.
 * @param pool Query pool to check.
 * @param storage Storage for the results. May be device-allocated host-mapped memory or host-only memory.
 * @param first First query to inspect.
 * @param count Total number of queries to inspect.
 * @param flags Bitmask specifying how and when to obtain results.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetQueryPoolResults.html
 */
[[nodiscard]] FUBUKI_FUYU_API extern std::expected<void, api_call_info> results_of(fuyu::any_query_pool_view           pool,
                                                                                   fuyu::query_pool_result_buffer_view storage,
                                                                                   std::uint32_t                       first,
                                                                                   std::uint32_t                       count,
                                                                                   VkQueryResultFlags                  flags) noexcept;

/**
 * Returns results for queries in a given range and allocates a host-side buffer for them.
 * @param pool Query pool to check.
 * @param first First query to inspect.
 * @param count Total number of queries to inspect.
 * @param flags Bitmask specifying how and when to obtain results.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetQueryPoolResults.html
 *
 * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if host resource allocation failed.
 */
[[nodiscard]]
inline std::expected<any_query_pool_results, api_call_info>
results_of(fuyu::any_query_pool_view pool, const std::uint32_t first, const std::uint32_t count, const VkQueryResultFlags flags)
{
    auto buffer = allocate_buffer(pool, first, count, flags);

    if(const auto check = fubuki::fuyu::results_of(pool, buffer, first, count, flags); not check)
    {
        return std::unexpected{check.error()};
    }

    return buffer.storage;
}

/**
 * Inspects a result of a performance query.
 * @param pool Query pool.
 * @param buffer Buffer in which the results are stored.
 * @param query Query to inspect.
 * @param result_index Index of the result to inspect.
 * @pre query must be a valid query index.
 * @pre result_index must be a valid result index.
 */
[[nodiscard]]
inline auto inspect(fuyu::performance_query_pool_view         pool,
                    const fuyu::query_pool_result_buffer_view buffer,
                    std::uint32_t                             query,
                    std::size_t                               result_index) noexcept
{
    // Sanity checks
    {
        fubuki_assert(result_index < pool.results_formats.size(), "Invalid index.");
    }

    const auto        formats           = pool.results_formats;
    const std::size_t results_per_query = formats.size();

    const std::size_t index = result_index + query * results_per_query;

    return fuyu::detail::performance_query_pool::from_storage(buffer, index, formats[result_index]);
}

/********************************************************************************/
/*                                  VULKAN 1.2                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_2)
/**
 * Resets queries in range [first, first + count - 1] to 'unavailable'.
 * @param pool Query pool to inspect.
 * @param first First query to make unavailable.
 * @param count Total number of queries to make unavailable.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkResetQueryPoolEXT.html
 */
FUBUKI_FUYU_API
extern void reset(fuyu::any_query_pool_view pool, std::uint32_t first, std::uint32_t count) noexcept;
#endif // defined(VK_VERSION_1_2)

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_QUERY_POOL_HPP
