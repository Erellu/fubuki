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

#ifndef FUBUKI_FUYU_VIEWS_QUERY_POOL_HPP
#define FUBUKI_FUYU_VIEWS_QUERY_POOL_HPP

#include <cstdint>
#include <span>
#include <variant>

#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/vulkan.hpp>

#include "fuyu/detail/query_pool.hpp"
#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/owning.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki::fuyu
{

namespace views
{

/// View of a query pool.
struct query_pool
{
    query_pool_handle             handle = {};                                  ///< Query pool handle.
    device_cref                   device;                                       ///< Device on which the query pool is allocated.
    VkQueryType                   type                = VK_QUERY_TYPE_MAX_ENUM; ///< Type of query this pool allows.
    std::uint32_t                 count               = 0;                      ///< Number of queries this pool manages.
    VkQueryPipelineStatisticFlags pipeline_statistics = {};                     ///< Counters to be retrieved in queries originating from this pool.

    [[nodiscard]] constexpr operator query_pool_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const query_pool& a, const query_pool& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const query_pool& a, const query_pool& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const query_pool& a, const query_pool& b) noexcept { return a.handle <=> b.handle; }
};

namespace detail::performance_query_pool
{
/// Any value that may be returned by a counter in a performance query.
using any_result = fuyu::detail::performance_query_pool::any_result;

using result_storage = fuyu::detail::performance_query_pool::result_storage;

/// Possible formats for performance query pool results.
using result_format = fuyu::detail::performance_query_pool::format;

template<std::ranges::range container>
requires(std::is_same_v<container, small_vector<result_format>> or std::is_same_v<container, std::span<const result_format>>)
struct view
{
    /// Any value that may be returned by a counter in a performance query.
    using any_result = detail::performance_query_pool::any_result;

    using result_storage = detail::performance_query_pool::result_storage;

    /// Possible formats for performance query pool results.
    using result_format = detail::performance_query_pool::result_format;

    query_pool_handle             handle = {};              ///< Query pool handle.
    device_cref                   device;                   ///< Device on which the query pool is allocated.
    std::uint32_t                 count               = 0;  ///< Number of queries this pool manages.
    VkQueryPipelineStatisticFlags pipeline_statistics = {}; ///< Counters to be retrieved in queries originating from this pool.
    container                     results_formats     = {}; ///< Formats of the results.

    [[nodiscard]] inline constexpr operator query_pool_handle() const noexcept { return handle; }

    [[nodiscard]] inline constexpr operator query_pool() const noexcept
    {
#if defined(VK_KHR_performance_query)
        constexpr VkQueryType type = VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR;
#else
        constexpr VkQueryType type = VK_QUERY_TYPE_MAX_ENUM; // An invalid value that will trigger a validation error
#endif

        return {
            .handle              = handle,
            .device              = device,
            .type                = type,
            .count               = count,
            .pipeline_statistics = pipeline_statistics,
        };
    }

    [[nodiscard]] friend constexpr bool operator==(const view& a, const view& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const view& a, const view& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const view& a, const view& b) noexcept { return a.handle <=> b.handle; }
};

using non_owning_view = view<std::span<const detail::performance_query_pool::result_format>>;
using owning_view     = view<small_vector<detail::performance_query_pool::result_format>>;

}; // namespace detail::performance_query_pool

//------------------------------------------------------------------------------

using performance_query_pool = detail::performance_query_pool::non_owning_view;
template<>
struct owning<performance_query_pool>
{
    std::optional<detail::performance_query_pool::owning_view> value = {};
};

//------------------------------------------------------------------------------

/// Any view of a query.
using any_query_pool = std::variant<query_pool, performance_query_pool>;

/// Possible results of queries.
using any_query_pool_results = std::
    variant<std::vector<std::uint32_t>, std::vector<std::uint64_t>, std::vector<performance_query_pool::result_storage>, std::vector<std::byte>>;

} // namespace views

/// Alias for fubuki::fuyu::views::query_pool.
using query_pool_view = views::query_pool;

/// Alias for fubuki::fuyu::views::performance_query_pool.
using performance_query_pool_view = views::performance_query_pool;

/// Alias for fubuki::fuyu::views::any_query_pool.
using any_query_pool_view = views::any_query_pool;

/// Possible results of queries.
using any_query_pool_results = views::any_query_pool_results;

/// Possible formats for query pool results.
using performance_query_pool_result_format = performance_query_pool_view::result_format;

//------------------------------------------------------------------------------

/// View of some storage used to retrieve the results of query pool.
struct query_pool_result_buffer_view
{
    using storage_type = std::
        variant<std::span<std::uint32_t>, std::span<std::uint64_t>, std::span<detail::performance_query_pool::result_storage>, std::span<std::byte>>;

    storage_type  storage = {}; ///< Underlying storage for the results. May be device-allocated host-mapped memory or host-only memory.
    std::uint32_t stride  = {}; ///< Stride between the results for each query.

    [[nodiscard]] constexpr operator std::span<std::byte>()
    {
        constexpr auto visitor = [](auto& vec) noexcept { return std::as_writable_bytes(vec); };

        return std::visit(visitor, storage);
    }

    [[nodiscard]] constexpr operator std::span<const std::byte>() const
    {
        constexpr auto visitor = [](const auto& vec) noexcept { return std::as_bytes(vec); };

        return std::visit(visitor, storage);
    }

#if defined(FUBUKI_MAKE_CONVERSION)
    #error Internal error. Should not be defined here.
#endif

// NOLINTBEGIN(bugprone-macro-parentheses)
#define FUBUKI_MAKE_OPERATOR(type)                                                                    \
    [[nodiscard]] constexpr operator std::span<type>() { return std::get<std::span<type>>(storage); } \
                                                                                                      \
    [[nodiscard]] constexpr operator std::span<const type>() const { return std::span<const type>{std::get<std::span<type>>(storage)}; }
    // NOLINTEND(bugprone-macro-parentheses)

    FUBUKI_MAKE_OPERATOR(std::uint32_t)
    FUBUKI_MAKE_OPERATOR(std::uint64_t)
    FUBUKI_MAKE_OPERATOR(detail::performance_query_pool::result_storage)

#undef FUBUKI_MAKE_OPERATOR
};

/// A host-side buffer for retrieving results of queries.
struct query_pool_result_buffer
{
    using view              = query_pool_result_buffer_view;
    using storage_type      = any_query_pool_results;
    using storage_view_type = view::storage_type;

    // C++ forbids to interpret an array of char as anything else (strict aliasing rule).
    // We allocate ones of the correct type for standard pools, and raw bytes that we then memcpy for performance queries
    storage_type  storage = {}; ///< Underlying storage.
    std::uint32_t stride  = {}; ///< Stride between the results for each query.

    [[nodiscard]] constexpr operator view() noexcept
    {
        constexpr auto visitor = [](auto& vec) noexcept -> storage_view_type { return {std::span{vec}}; };

        return {std::visit(visitor, storage), stride};
    }
};

struct query_pool_result_buffer_requirements
{
    std::size_t   byte_count = 0u; ///< Number of bytes required to store the results.
    std::uint32_t stride     = 0u; ///< Stride between the results for each query.
    std::variant<std::uint32_t, std::uint64_t, detail::performance_query_pool::result_storage, std::byte> type
        = {}; ///< Type as which the buffer must be allocated.
};

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::query_pool_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::query_pool_view& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

template<>
struct hash<fubuki::fuyu::performance_query_pool_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::performance_query_pool_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_QUERY_POOL_HPP
