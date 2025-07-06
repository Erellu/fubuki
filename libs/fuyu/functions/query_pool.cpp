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

#include "fuyu/functions/query_pool.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu
{

// NOLINTBEGIN(bugprone-easily-swappable-parameters)
[[nodiscard]]
auto buffer_requirements(fuyu::any_query_pool_view pool,
                         const std::uint32_t       first,
                         const std::uint32_t       count,
                         const VkQueryResultFlags  flags) noexcept -> query_pool_result_buffer_requirements
{
    /*
     * According to the specs, the format in which results are returned depend on the query type.
     * https://registry.khronos.org/vulkan/specs/latest/html/chap17.html#queries-operation-memorylayout
     * https://registry.khronos.org/vulkan/specs/1.3-extensions/html/vkspec.html#queries-operation-memorylayout
     *
     * The first query’s result is written starting at the first byte requested by the command, and each subsequent query’s result begins stride bytes
     * later.
     *
     * Possible layouts:
     *
     * ------------------------------------------------------------------------
     *
     * Occlusion queries, pipeline statistics queries, transform feedback queries, primitives generated queries, mesh shader queries, and timestamp
     * queries store results in a tightly packed array of unsigned integers, either 32- or 64-bits as requested by the command, storing the numerical
     * results and, if requested, the availability status.
     *
     * ------------------------------------------------------------------------
     *
     * Performance queries store results in a tightly packed array whose type is determined by the unit member of the corresponding
     * VkPerformanceCounterKHR.
     *
     * From https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkPerformanceCounterResultKHR.html:
     * Performance query results are returned in an array of VkPerformanceCounterResultKHR unions containing the data associated with each counter in
     * the query, stored in the same order as the counters supplied in pCounterIndices when creating the performance query.
     *
     * ------------------------------------------------------------------------
     *
     * If VK_QUERY_RESULT_WITH_AVAILABILITY_BIT is used, the final element of each query’s result is an integer indicating whether the query’s result
     * is available, with any non-zero value indicating that it is available.
     *
     * ------------------------------------------------------------------------
     *
     * If VK_QUERY_RESULT_WITH_STATUS_BIT_KHR is used, the final element of each query’s result is an integer value indicating that status of the
     * query result. Positive values indicate success, negative values indicate failure, and 0 indicates that the result is not yet available.
     * Specific error codes are encoded in the VkQueryResultStatusKHR enumeration.
     *
     * ------------------------------------------------------------------------
     *
     * Occlusion queries write one integer value - the number of samples passed. Pipeline statistics queries write one integer value for each bit that
     * is enabled in the pipelineStatistics when the pool is created, and the statistics values are written in bit order starting from the least
     * significant bit. Timestamp queries write one integer value. Performance queries write one VkPerformanceCounterResultKHR value for each
     * VkPerformanceCounterKHR in the query. Transform feedback queries write two integers; the first integer is the number of primitives successfully
     * written to the corresponding transform feedback buffer and the second is the number of primitives output to the vertex stream, regardless of
     * whether they were successfully captured or not. In other words, if the transform feedback buffer was sized too small for the number of
     * primitives output by the vertex stream, the first integer represents the number of primitives actually written and the second is the number
     * that would have been written if all the transform feedback buffers associated with that vertex stream were large enough.
     * Primitives generated queries write the number of primitives output to the vertex stream, regardless of whether transform feedback is active or
     * not, or whether they were successfully captured by transform feedback or not. This is identical to the second integer of the transform feedback
     * queries if transform feedback is active. Mesh shader queries write a single integer.
     *
     * ------------------------------------------------------------------------
     *
     * If more than one query is retrieved and stride is not at least as large as the size of the array of values corresponding to a single query,
     * the values written to memory are undefined.
     *
     * ------------------------------------------------------------------------
     *
     * So to not reach the last case and also to avoid ugly if in switch in switch, we allocate a raw byte buffer, depending on query type.
     */

    static constexpr auto get_type = [](const auto& p) noexcept -> VkQueryType
    {
        using pool_type = std::decay_t<decltype(p)>;

        if constexpr(std::is_same_v<pool_type, fuyu::query_pool_view>)
        {
            return p.type;
        }
        else if constexpr(std::is_same_v<pool_type, fuyu::performance_query_pool_view>)
        {
#if defined(VK_KHR_performance_query)
            return VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR;
#else
            return VK_QUERY_TYPE_MAX_ENUM;
#endif
        }
        else
        {
            return VK_QUERY_TYPE_MAX_ENUM;
        }
    };

    const auto queries_count = static_cast<std::size_t>(count - first);

    switch(std::visit(get_type, pool))
    {
        //------- Occlusion, pipeline statistics, transform feedback, primitives generated, mesh shader, timestamp -------//
        case VK_QUERY_TYPE_OCCLUSION:
        case VK_QUERY_TYPE_PIPELINE_STATISTICS:

#if defined(VK_EXT_transform_feedback)
        case VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT:
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_EXT_primitives_generated_query)
        case VK_QUERY_TYPE_PRIMITIVES_GENERATED_EXT:
#endif // defined(VK_EXT_primitives_generated_query)

#if defined(VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT)
        case VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT:
#endif // defined(VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT)

#if defined(VK_EXT_mesh_shader)
        case VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT:
#endif // defined(VK_EXT_mesh_shader)

        case VK_QUERY_TYPE_TIMESTAMP:
        {
            const bool format_64_bit = flags & VK_QUERY_RESULT_64_BIT;

#if defined(VK_KHR_video_queue)
            const bool status_inside = (flags & VK_QUERY_RESULT_WITH_AVAILABILITY_BIT) or (flags & VK_QUERY_RESULT_WITH_STATUS_BIT_KHR);
#else
            const bool status_inside = flags & VK_QUERY_RESULT_WITH_AVAILABILITY_BIT;
#endif // defined(VK_KHR_video_queue)

            if(format_64_bit)
            {
                const std::uint32_t stride = status_inside ? 2u * sizeof(std::uint64_t) : sizeof(std::uint64_t);

                return {.byte_count = queries_count * sizeof(std::uint64_t), .stride = stride, .type = std::uint64_t{}};
            }

            {
                const std::uint32_t stride = status_inside ? 2u * sizeof(std::uint32_t) : sizeof(std::uint32_t);

                return {.byte_count = queries_count * sizeof(std::uint32_t), .stride = stride, .type = std::uint32_t{}};
            }
        }

        //---------------------- Performance query ----------------------//

#if defined(VK_KHR_performance_query)
        case VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR:
        {
            fubuki_assert(std::holds_alternative<fuyu::performance_query_pool_view>(pool),
                          "Please pass a performance_query_view for performance queries.");

            const auto formats = std::get<fuyu::performance_query_pool_view>(pool).results_formats;

            const std::size_t bytes_per_query = formats.size() * sizeof(fuyu::detail::performance_query_pool::result_storage);

            return {
                .byte_count = bytes_per_query * queries_count,
                .stride     = static_cast<std::uint32_t>(bytes_per_query),
                .type       = fuyu::detail::performance_query_pool::result_storage{},
            };
        }
#endif // defined(VK_KHR_performance_query)

        //---------------------- Invalid for results() ----------------------//

#if defined(VK_NV_ray_tracing)
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV:
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_KHR_acceleration_structure)
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR:
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR:
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_maintenance1)
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SIZE_KHR:
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR:
#endif // defined(VK_KHR_ray_tracing_maintenance1)

            //---------------------- Not supported ----------------------//

#if defined(VK_KHR_video_encode_queue)
        case VK_QUERY_TYPE_VIDEO_ENCODE_FEEDBACK_KHR:
#endif // defined(VK_KHR_video_encode_queue)

#if defined(VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR)
        case VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR:
#endif // defined(VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR)

#if defined(VK_INTEL_performance_query)
        case VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL:
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_KHR_video_queue)
        case VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR:
#endif

#if defined(VK_EXT_opacity_micromap)
        case VK_QUERY_TYPE_MICROMAP_SERIALIZATION_SIZE_EXT:
        case VK_QUERY_TYPE_MICROMAP_COMPACTED_SIZE_EXT:
#endif

        case VK_QUERY_TYPE_MAX_ENUM:
        default                    : fubuki_assert(false, "Invalid query type or query type is not supported."); return {};
    }
}
// NOLINTEND(bugprone-easily-swappable-parameters)

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

[[nodiscard]]
std::expected<void, api_call_info> results_of(fuyu::any_query_pool_view           pool,
                                              fuyu::query_pool_result_buffer_view buffer,
                                              const std::uint32_t                 first,
                                              const std::uint32_t                 count,
                                              const VkQueryResultFlags            flags) noexcept
{
    const auto visitor = [&buffer, first, count, flags](const auto& query_pool) noexcept -> std::expected<void, api_call_info>
    {
        const std::span<std::byte> storage = buffer;

        if(const auto check
           = fubuki_validate(validate_by::expected, fuyu::invoke<"vkGetQueryPoolResults">(query_pool.device, query_pool.handle.vk, first, count, storage.size(), static_cast<void*>(storage.data()), buffer.stride, flags)); not check)
        {
            return std::unexpected{check.error()};
        }

        return {};
    };

    return std::visit(visitor, pool);
}

/********************************************************************************/
/*                                  VULKAN 1.2                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_2)

void reset(fuyu::any_query_pool_view pool, const std::uint32_t first, const std::uint32_t count) noexcept
{
    const auto visitor = [first, count](auto& query_pool) noexcept
    { return fuyu::invoke<"vkResetQueryPool">(query_pool.device, query_pool.handle.vk, first, count); };

    return std::visit(visitor, pool);
}

#endif // defined(VK_VERSION_1_2)

} // namespace fubuki::fuyu
