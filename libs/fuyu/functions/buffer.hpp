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

#ifndef FUBUKI_FUYU_FUNCTIONS_BUFFER_HPP
#define FUBUKI_FUYU_FUNCTIONS_BUFFER_HPP

#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/buffer.hpp"
#include "fuyu/views/memory.hpp"

namespace fubuki::fuyu
{

namespace detail
{

#if defined(VK_VERSION_1_1)

/**
 * Bind a buffer to memory.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBindBufferMemory2.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<fuyu::bound_buffer_view, api_call_info>
                              bind(fuyu::buffer_resource_view buffer, fuyu::memory_view memory, const VkBindBufferMemoryInfo& info) noexcept;

#endif // defined(VK_VERSION_1_1)

} // namespace detail

/**
 * Bind a buffer to memory.
 * @warning Calls to this overload must be synchronised externally.
 * @param buffer Buffer to bind.
 * @param memory Memory to bind to.
 * @param offset Offset from memory begin, in bytes. Defaults to 0.
 * @pre The buffer must not be bound yet.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBindBufferMemory.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<fuyu::bound_buffer_view, api_call_info>
                              bind(fuyu::buffer_resource_view buffer, fuyu::memory_view memory, VkDeviceSize offset = 0) noexcept;

#if defined(VK_VERSION_1_1)

/**
 * Bind a buffer to memory.
 * @warning Calls to this overload must be synchronised externally.
 * @param buffer Buffer to bind.
 * @param memory Memory to bind to.
 * @param offset Offset from memory begin, in bytes.
 * @param pnext Chain extending VkBindBufferMemoryInfo.
 * @pre The buffer must not be bound yet.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBindBufferMemory2.html
 */
template<typename... elements>
[[nodiscard]] inline std::expected<fuyu::bound_buffer_view, api_call_info>
bind(fuyu::buffer_resource_view buffer, fuyu::memory_view memory, VkDeviceSize offset, const pnext_chain<elements...>& pnext) noexcept
{
    VkBindBufferMemoryInfo vk_info{
        .sType        = structure_type_v<VkBindBufferMemoryInfo>,
        .pNext        = {},
        .buffer       = buffer.handle.vk,
        .memory       = memory.handle.vk,
        .memoryOffset = offset,
    };

    fubuki::extend(vk_info, pnext);

    // TODO: support ranges
    return detail::bind(buffer, memory, vk_info);
}

#endif // defined(VK_VERSION_1_1)

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_BUFFER_HPP
