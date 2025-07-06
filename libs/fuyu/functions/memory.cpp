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

#include "fuyu/functions/memory.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu
{

namespace detail
{

#if defined(VK_VERSION_1_4)
[[nodiscard]] std::expected<fuyu::mapped_memory, api_call_info> map(memory_view memory, const VkMemoryMapInfo& info) noexcept
{
    fubuki_assert(memory.handle.vk == info.memory, "Internal error. Handle mismatch.");

    std::byte* begin = nullptr;

    {
        auto* erased_begin = static_cast<void*>(begin);
        if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkMapMemory2">(memory.device, std::addressof(info), std::addressof(erased_begin))); not check)
        {
            return std::unexpected{check.error()};
        }

        begin = static_cast<std::byte*>(erased_begin);
    }

    const std::size_t byte_count = info.size == VK_WHOLE_SIZE ? memory.requirements.size - info.offset : info.size;

    // Though correct, this is the expected way to use the API, and it's in fact safer to wrap a span here than return a raw pointer
    #if defined(__clang__) && __clang_major__ >= 19
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-container"
    #endif

    return mapped_memory{
        memory_region{memory, {info.offset, byte_count}},
        std::span{begin,  byte_count               }
    };

    #if defined(__clang__) && __clang_major__ >= 19
        #pragma clang diagnostic pop
    #endif
}

void unmap(memory_view memory, const VkMemoryUnmapInfo& info) noexcept
{
    fubuki_assert(memory.handle.vk == info.memory, "Internal error. Handle mismatch.");

    fuyu::invoke<"vkUnmapMemory2">(memory.device, std::addressof(info));
}

#endif // defined(VK_VERSION_1_4)

} // namespace detail

[[nodiscard]]
std::expected<mapped_memory, api_call_info> map(memory_view memory, VkMemoryMapFlags flags, std::optional<memory_range> range) noexcept
{
    std::byte* begin = nullptr;

    const auto offset = range.has_value() ? range->offset : 0;
    const auto size   = range.has_value() ? range->size : VK_WHOLE_SIZE;

    {
        auto* erased_begin = static_cast<void*>(begin);
        if(const auto check
           = fubuki_validate(validate_by::expected, fuyu::invoke<"vkMapMemory">(memory.device, memory.handle.vk, offset, size, flags, std::addressof(erased_begin))); not check)
        {
            return std::unexpected{check.error()};
        }

        begin = static_cast<std::byte*>(erased_begin);
    }

    const std::size_t byte_count = size == VK_WHOLE_SIZE ? memory.requirements.size - offset : size;

// Though correct, this is the expected way to use the API, and it's in fact safer to wrap a span here than return a raw pointer
#if defined(__clang__) && __clang_major__ >= 19
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-container"
#endif

    return mapped_memory{
        memory_region{memory, {offset, byte_count}},
        std::span{begin,  byte_count          }
    };

#if defined(__clang__) && __clang_major__ >= 19
    #pragma clang diagnostic pop
#endif
}

void unmap(memory_view memory) noexcept { fuyu::invoke<"vkUnmapMemory">(memory.device, memory.handle.vk); }

[[nodiscard]]
VkDeviceSize commitment(memory_view memory) noexcept
{
    VkDeviceSize result = 0;
    fuyu::invoke<"vkGetDeviceMemoryCommitment">(memory.device, memory.handle.vk, std::addressof(result));

    return result;
}

} // namespace fubuki::fuyu
