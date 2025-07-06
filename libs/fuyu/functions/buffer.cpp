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

#include "fuyu/functions/buffer.hpp"

#include <core/validate.hpp>

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu
{

namespace detail
{

#if defined(VK_VERSION_1_1)

[[nodiscard]] std::expected<fuyu::bound_buffer_view, api_call_info>
bind(fuyu::buffer_resource_view buffer, fuyu::memory_view memory, const VkBindBufferMemoryInfo& info) noexcept
{
    fubuki_assert(buffer.handle.vk == info.buffer, "Internal error: handle mistmach.");
    fubuki_assert(memory.handle.vk == info.memory, "Internal error: handle mistmach.");

    if(const auto check
       = fubuki_validate(validate_by::expected, fuyu::invoke<"vkBindBufferMemory2">(buffer.device, 1u, std::addressof(info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return fuyu::bound_buffer_view{buffer, memory, info.memoryOffset};
}

#endif // defined(VK_VERSION_1_1)

} // namespace detail

[[nodiscard]]
std::expected<fuyu::bound_buffer_view, api_call_info>
bind(fuyu::buffer_resource_view buffer, fuyu::memory_view memory, const VkDeviceSize offset) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fuyu::invoke<"vkBindBufferMemory">(buffer.device, buffer.handle.vk, memory.handle.vk, offset)); not check)
    {
        return std::unexpected{check.error()};
    }

    return fuyu::bound_buffer_view{buffer, memory, offset};
}

} // namespace fubuki::fuyu
