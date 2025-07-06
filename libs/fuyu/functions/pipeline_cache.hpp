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

#ifndef FUBUKI_FUYU_FUNCTIONS_PIPELINE_CACHE_HPP
#define FUBUKI_FUYU_FUNCTIONS_PIPELINE_CACHE_HPP

#include <cstddef>

#include <core/config/macros.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>

#include "fuyu/views/pipeline_cache.hpp"

namespace fubuki::fuyu
{

/**
 * Gets the size of the data store from a pipeline cache.
 * @param cache Pipeline cache to inspect.
 * @returns The size, in bytes, of pipeline cache's data store, or details about the API call that failed.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<std::size_t, api_call_info> data_byte_size(pipeline_cache_view cache) noexcept;

/**
 * Fills a buffer with the contents of the data store of a pipeline cache.
 * @param cache Pipeline cache to inspect.
 * @param buffer The buffer in which the results will be written. Writes at most buffer.size().
 * @returns Nothing upon success, or details about the API call that failed. If buffer.size() was inferior to the requirements as per
 * fuyu::data_byte_size, the result will indicate VK_INCOMPLETE.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> data(pipeline_cache_view cache, std::span<std::byte> buffer) noexcept;

/**
 * Gets the data store from a pipeline cache.
 * @param cache Pipeline cache to inspect.
 *
 * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if the buffer allocation failed.
 */
[[nodiscard]] inline std::expected<std::vector<std::byte>, api_call_info> data(pipeline_cache_view cache)
{
    const auto size = data_byte_size(cache);

    if(not size)
    {
        return std::unexpected{size.error()};
    }

    std::vector<std::byte> result;
    result.resize(*size);

    if(const auto write = data(cache, result); not write)
    {
        return std::unexpected{write.error()};
    }

    return result;
}

/**
 * Combine the data stores of pipeline caches.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMergePipelineCaches.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> merge(pipeline_cache_view                    dest,
                                                                       std::span<const pipeline_cache_handle> sources) noexcept;

/**
 * Combine the data stores of pipeline caches.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMergePipelineCaches.html
 */
[[nodiscard]] inline std::expected<void, api_call_info> merge(pipeline_cache_view dest, std::initializer_list<pipeline_cache_handle> sources) noexcept
{
    return merge(dest, std::span{sources});
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_PIPELINE_CACHE_HPP
