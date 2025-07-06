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

#include "fuyu/query_pool.hpp"

#include <core/assertion.hpp>
#include <core/result.hpp>
#include <extension/ext_debug_utils.hpp>
#include <extension/khr_performance_query.hpp>

#include "fuyu/allocation.hpp"
#include "fuyu/debug/name.hpp"
#include "fuyu/device.hpp" // IWYU pragma: keep

namespace fubuki::fuyu
{

namespace
{

#if defined(VK_KHR_performance_query)
[[nodiscard]] constexpr views::performance_query_pool::result_format translate(VkPerformanceCounterStorageKHR storage) noexcept
{
    using format = views::performance_query_pool::result_format;

    switch(storage)
    {
        case VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR  : return format::int32;
        case VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR  : return format::int64;
        case VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR : return format::uint32;
        case VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR : return format::uint64;
        case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR: return format::float32;
        case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR: return format::float64;

        default:
        case VK_PERFORMANCE_COUNTER_STORAGE_MAX_ENUM_KHR:
            fubuki_assert(false, "Invalid VkPerformanceCounterStorageKHR. Perhaps static_cast?");
            return {};
    }
}
#endif // defined(VK_KHR_performance_query)

} // anonymous namespace

/********************************************************************************/
/*                            PRIVATE MEMBER FUNCTIONS                          */
/********************************************************************************/

[[nodiscard]]
std::optional<api_call_info> query_pool::create(const VkQueryPoolCreateInfo& info)
{
    // Sanity checks
    {
        fubuki_assert(m_info.count > 0, "Count must be greater than 0.");
    }

    if(m_handle == null_handle)
    {
        if(auto success = fuyu::create_handle<handle_type>(device(), info, m_info.callbacks))
        {
            m_handle = *success;
        }
        else
        {
            return success.error();
        }
    }

    // Debug markers
    if(const auto check = debug::name_if_loaded(device(), m_handle, m_info.name.value_or("<Unnamed query pool>")); not check)
    {
        return check.error();
    }

#if defined(VK_KHR_performance_query)
    if(m_performance_query_info.has_value())
    {
        const fuyu::device::view dev = device();

        const auto counters
            = extension::khr_performance_query::performance_counters(dev.functions.get().ext, dev.hardware, m_performance_query_info->queue_family);

        if(not counters)
        {
            return counters.error();
        }

        m_performance_query_info->formats.reserve(m_performance_query_info->counter_indices.size());

        for(const std::uint32_t index : m_performance_query_info->counter_indices)
        {
            m_performance_query_info->formats.push_back(translate((*counters)[index].handle.storage));
        }
    }
#endif // defined(VK_KHR_performance_query)

    return {};
}

//------------------------------------------------------------------------------

void query_pool::destroy() noexcept
{
    if(m_handle != null_handle)
    {
        fuyu::destroy_handle(device(), m_handle, m_info.callbacks);
    }
}

} // namespace fubuki::fuyu
