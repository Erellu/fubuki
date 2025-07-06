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

#ifndef FUBUKI_FUYU_DETAIL_QUERY_POOL_HPP
#define FUBUKI_FUYU_DETAIL_QUERY_POOL_HPP

#include <cstdint>
#include <cstring>
#include <span>
#include <variant>

#include <core/vulkan.hpp>

/// Implementation details for features involing query pools.
namespace fubuki::fuyu::detail::performance_query_pool
{

/// Possible formats for query pool results.
enum class format : std::underlying_type_t<VkFormat>
{
    uint32  = VK_FORMAT_R32_UINT,
    int32   = VK_FORMAT_R32_SINT,
    uint64  = VK_FORMAT_R64_UINT,
    int64   = VK_FORMAT_R64_SINT,
    float32 = VK_FORMAT_R32_SFLOAT,
    float64 = VK_FORMAT_R64_SFLOAT,
};

#if defined(VK_KHR_performance_query)
/// Storage used by fubuki::results_of for results of performance queries.
using result_storage = VkPerformanceCounterResultKHR;
#else
/// Storage used by fubuki::results_of for results of performance queries.
union result_storage
{
    std::int32_t  int32;
    std::int64_t  int64;
    std::uint32_t uint32;
    std::uint64_t uint64;
    float         float32;
    double        float64;
};
#endif // defined(VK_KHR_performance_query)

/// Any value that may be returned by a counter in a performance query.
using any_result = std::variant<std::uint32_t, std::int32_t, std::uint64_t, std::int64_t, float, double>;

//------------------------------------------------------------------------------

/// Returns a VkFormat corresponding to a result format.
[[nodiscard]] inline constexpr auto to_vk(format f) noexcept { return static_cast<VkFormat>(f); }

//------------------------------------------------------------------------------

#if defined(FUBUKI_MAP_TYPE)
    #error Internal error. Should not be defined here.
#endif

template<format type>
struct format_traits;

#define FUBUKI_MAP_TYPE(enum_v, type_t)                   \
    template<>                                            \
    struct format_traits<enum_v>                          \
    {                                                     \
        using type                       = type_t;        \
        static constexpr auto byte_count = sizeof(type);  \
        static constexpr auto format_id  = enum_v;        \
        static constexpr auto vk_format  = to_vk(enum_v); \
    }

FUBUKI_MAP_TYPE(format::uint32, std::uint32_t);
FUBUKI_MAP_TYPE(format::int32, std::int32_t);
FUBUKI_MAP_TYPE(format::uint64, std::uint64_t);
FUBUKI_MAP_TYPE(format::int64, std::int64_t);
FUBUKI_MAP_TYPE(format::float32, float);
FUBUKI_MAP_TYPE(format::float64, double);

#undef FUBUKI_MAP_TYPE

//------------------------------------------------------------------------------

inline constexpr std::size_t byte_count(format f) noexcept
{
#if defined(FUBUKI_HANDLE_TYPE)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_HANDLE_TYPE(enum_v) \
    case(format::enum_v): return format_traits<format::enum_v>::byte_count

    switch(f)
    {
        FUBUKI_HANDLE_TYPE(uint32);
        FUBUKI_HANDLE_TYPE(int32);
        FUBUKI_HANDLE_TYPE(uint64);
        FUBUKI_HANDLE_TYPE(int64);
        FUBUKI_HANDLE_TYPE(float32);
        FUBUKI_HANDLE_TYPE(float64);
        default: return 0u;
    }

#undef FUBUKI_HANDLE_TYPE
}

//------------------------------------------------------------------------------

/**
 * Reads raw bytes from a buffer and builds an any_result out of them.
 * @param buffer The storage to read.
 * @param index The index of the result to read.
 * @param f The format the result is in.
 * @see fubuki::result_of
 *
 * @pre index MUST be a valid index for buffer. Otherwise, the behaviour is undefined.
 */
[[nodiscard]] inline constexpr any_result from_storage(const std::span<const result_storage> buffer, const std::size_t index, const format f) noexcept
{
    const auto& storage = buffer[index];

#if defined(FUBUKI_HANDLE_TYPE)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_HANDLE_TYPE(enum_v) \
    case(format::enum_v):          \
        return { storage.enum_v }

    // NOLINTBEGIN(cppcoreguidelines-pro-type-union-access)
    // This accesses storage defined by the Vulkan API, written in C
    switch(f)
    {
        FUBUKI_HANDLE_TYPE(uint32);
        FUBUKI_HANDLE_TYPE(int32);
        FUBUKI_HANDLE_TYPE(uint64);
        FUBUKI_HANDLE_TYPE(int64);
        FUBUKI_HANDLE_TYPE(float32);
        FUBUKI_HANDLE_TYPE(float64);
        default: return {};
    }
        // NOLINTEND(cppcoreguidelines-pro-type-union-access)

#undef FUBUKI_HANDLE_TYPE
}

} // namespace fubuki::fuyu::detail::performance_query_pool

#endif // FUBUKI_FUYU_DETAIL_QUERY_POOL_HPP
