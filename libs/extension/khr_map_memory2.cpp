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

#include "extension/khr_map_memory2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_map_memory2
{

#if defined(VK_KHR_map_memory2)

[[nodiscard]]
std::expected<std::byte*, api_call_info> map_memory2(const functions& ext, device_handle device, const VkMemoryMapInfoKHR& memory_map_info) noexcept
{
    std::byte* begin = nullptr;

    {
        auto* erased_begin = static_cast<void*>(begin);

        if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkMapMemory2KHR">(ext, device.vk, &memory_map_info, std::addressof(erased_begin))); not check)
        {
            return std::unexpected{check.error()};
        }

        begin = static_cast<std::byte*>(erased_begin);
    }

    return begin;
}

[[nodiscard]] std::expected<std::span<std::byte>, api_call_info>
map_memory2(const functions& ext, device_handle device, const VkMemoryMapInfoKHR& memory_map_info, const VkMemoryRequirements& memory_reqs) noexcept
{
    auto begin = map_memory2(ext, device, memory_map_info);

    if(not begin.has_value())
    {
        return std::unexpected{begin.error()};
    }

    const std::size_t byte_count = memory_map_info.size == VK_WHOLE_SIZE ? memory_reqs.size - memory_map_info.offset : memory_map_info.size;

    // Though correct, this is the expected way to use the API, and it's in fact safer to wrap a span here than return a raw pointer
    #if defined(__clang__) && __clang_major__ >= 19
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-container"
    #endif

    return std::span{*begin, byte_count};

    #if defined(__clang__) && __clang_major__ >= 19
        #pragma clang diagnostic pop
    #endif
}

[[nodiscard]]
VkResult unmap_memory2(const functions& ext, device_handle device, const VkMemoryUnmapInfoKHR& memory_unmap_info) noexcept
{
    return fubuki::invoke<"vkUnmapMemory2KHR">(ext, device.vk, &memory_unmap_info);
}

#endif // defined(VK_KHR_map_memory2)

} // namespace fubuki::extension::khr_map_memory2
