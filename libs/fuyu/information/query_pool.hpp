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

#ifndef FUBUKI_FUYU_INFORMATION_QUERY_POOL_HPP
#define FUBUKI_FUYU_INFORMATION_QUERY_POOL_HPP

#include <cstdint>
#include <functional>
#include <optional>
#include <string>

#include <core/small_vector.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"
#include "fuyu/views/query_pool.hpp"

namespace fubuki::fuyu::information
{

/// Query pool information.
/// @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkQueryPoolCreateInfo.html
struct query_pool
{
    using underlying_type = VkQueryPoolCreateInfo;

    VkQueryType                   type                = {}; ///< Type of query this pool allows.
    std::uint32_t                 count               = {}; ///< Number of queries this pool manages.
    VkQueryPipelineStatisticFlags pipeline_statistics = {}; ///< Counters to be retrieved in queries originating from this pool.

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const query_pool& a, const query_pool& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const query_pool& a, const query_pool& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const query_pool> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType              = structure_type_v<underlying_type>,
            .pNext              = nullptr,
            .flags              = 0, // Reserved for future use as of Vulkan 1.3
            .queryType          = s.type,
            .queryCount         = s.count,
            .pipelineStatistics = s.pipeline_statistics,
        };
    }
};

/// Additional information when query pool is allocated to be a performance query.
struct performance_query_pool
{
    std::uint32_t                                      queue_family    = {}; ///< Queue family used for this query pool.
    small_vector<std::uint32_t>                        counter_indices = {}; ///< Enabled performance counters.
    small_vector<performance_query_pool_result_format> formats         = {}; ///< Formats of the results.

    [[nodiscard]] friend constexpr bool operator==(const performance_query_pool& a, const performance_query_pool& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const performance_query_pool& a, const performance_query_pool& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const performance_query_pool& a, const performance_query_pool& b) noexcept = default;
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_QUERY_POOL_HPP
