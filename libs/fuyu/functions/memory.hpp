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

#ifndef FUBUKI_FUYU_FUNCTIONS_MEMORY_HPP
#define FUBUKI_FUYU_FUNCTIONS_MEMORY_HPP

#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/memory.hpp"

namespace fubuki::fuyu
{

namespace detail
{

#if defined(VK_VERSION_1_4)
[[nodiscard]] FUBUKI_FUYU_API std::expected<fuyu::mapped_memory, api_call_info> map(memory_view memory, const VkMemoryMapInfo& info) noexcept;

FUBUKI_FUYU_API void unmap(memory_view memory, const VkMemoryUnmapInfo& info) noexcept;
#endif // defined(VK_VERSION_1_4)

} // namespace detail

/**
 * @brief Maps 'size' bytes of memory, starting from 'offset'. If size is VK_WHOLE_SIZE,
 * everything after 'offset' until the end of allocation is bound.
 * @warning Calls to this overload must be synchronised externally.
 * @param memory Memory to map.
 * @param flags Memory flags
 * @param range Region to map.
 * @pre Memory must not be mapped when calling this function.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMapMemory.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<fuyu::mapped_memory, api_call_info>
                              map(fuyu::memory_view memory, VkMemoryMapFlags flags, std::optional<fuyu::memory_range> range = {}) noexcept;

/**
 * @brief Maps 'size' bytes of memory, starting from 'offset'. If size is VK_WHOLE_SIZE,
 * everything after 'offset' until the end of allocation is bound.
 * @warning Calls to this overload must be synchronised externally.
 * @param memory Memory to map.
 * @param range Region to map.
 * @pre Memory must not be mapped when calling this function.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMapMemory.html
 */
[[nodiscard]] inline std::expected<fuyu::mapped_memory, api_call_info> map(fuyu::memory_view                 memory,
                                                                           std::optional<fuyu::memory_range> range = {}) noexcept
{
    return map(memory, {}, range);
}

/**
 * Unmaps memory.
 * @param memory Memory to unmap.
 * @pre Memory must be mapped when calling this function.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUnmapMemory.html
 */
FUBUKI_FUYU_API
void unmap(fuyu::memory_view memory) noexcept;

/**
 * Returns commitment of device memory.
 * @param memory Memory to inspect.
 * @pre Memory must have VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT property.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceMemoryCommitment.html
 */
[[nodiscard]] FUBUKI_FUYU_API VkDeviceSize commitment(fuyu::memory_view memory) noexcept;

#if defined(VK_VERSION_1_4)
/**
 * @brief Maps 'size' bytes of memory, starting from 'offset'. If size is VK_WHOLE_SIZE,
 * everything after 'offset' until the end of allocation is bound.
 * @warning Calls to this overload must be synchronised externally.
 * @param memory Memory to map.
 * @param flags Memory flags
 * @param range Region to map.
 * @param pnext Chain extending VkMemoryMapInfo.
 * @pre Memory must not be mapped when calling this function.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMapMemory2.html
 */
template<typename... elements>
[[nodiscard]] inline std::expected<fuyu::mapped_memory, api_call_info>
map(fuyu::memory_view memory, VkMemoryMapFlags flags, std::optional<fuyu::memory_range> range, const pnext_chain<elements...>& pnext) noexcept
{
    VkMemoryMapInfo vk_info{
        .sType  = structure_type_v<VkMemoryMapInfo>,
        .pNext  = {},
        .flags  = flags,
        .memory = memory.handle.vk,
        .offset = range.has_value() ? range->offset : 0,
        .size   = range.has_value() ? range->size : VK_WHOLE_SIZE,
    };

    fubuki::extend(vk_info, pnext);

    return detail::map(memory, vk_info);
}

/**
 * @brief Maps 'size' bytes of memory, starting from 'offset'. If size is VK_WHOLE_SIZE,
 * everything after 'offset' until the end of allocation is bound.
 * @warning Calls to this overload must be synchronised externally.
 * @param memory Memory to map.
 * @param range Region to map.
 * @pre Memory must not be mapped when calling this function.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMapMemory2.html
 */
template<typename... elements>
[[nodiscard]] inline std::expected<fuyu::mapped_memory, api_call_info>
map(fuyu::memory_view memory, std::optional<fuyu::memory_range> range, const pnext_chain<elements...>& pnext) noexcept
{
    return map(memory, {}, range, pnext);
}

/**
 * Unmaps memory.
 * @param memory Memory to unmap.
 * @param flags A bitmask of VkMemoryUnmapFlagBits specifying additional parameters of the memory map operation.
 * @pre Memory must be mapped when calling this function.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUnmapMemory.html
 */
template<typename... elements>
inline void unmap(fuyu::memory_view memory, VkMemoryUnmapFlags flags, const pnext_chain<elements...>& pnext) noexcept
{
    VkMemoryUnmapInfo vk_info{
        .sType  = structure_type_v<VkMemoryUnmapInfo>,
        .pNext  = {},
        .flags  = flags,
        .memory = memory.handle.vk,
    };

    fubuki::extend(vk_info, pnext);

    return detail::unmap(memory, vk_info);
}

/**
 * Unmaps memory.
 * @param memory Memory to unmap.
 * @param flags A bitmask of VkMemoryUnmapFlagBits specifying additional parameters of the memory map operation.
 * @pre Memory must be mapped when calling this function.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUnmapMemory.html
 */
inline void unmap(fuyu::memory_view memory, VkMemoryUnmapFlags flags) noexcept { return unmap(memory, flags, empty_pnext_chain); }

#endif // defined(VK_VERSION_1_4)

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_MEMORY_HPP
