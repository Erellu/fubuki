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

#include "extension/khr_get_memory_requirements2.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_get_memory_requirements2
{

#if defined(VK_KHR_get_memory_requirements2)

namespace detail
{

void get_buffer_memory_requirements2(const functions&                       ext,
                                     device_handle                          device,
                                     const VkBufferMemoryRequirementsInfo2& info,
                                     VkMemoryRequirements2&                 result) noexcept
{
    return fubuki::invoke<"vkGetBufferMemoryRequirements2KHR">(ext, device.vk, std::addressof(info), &result);
}

void get_image_memory_requirements2(const functions&                      ext,
                                    device_handle                         device,
                                    const VkImageMemoryRequirementsInfo2& info,
                                    VkMemoryRequirements2&                result) noexcept
{
    return fubuki::invoke<"vkGetImageMemoryRequirements2KHR">(ext, device.vk, std::addressof(info), &result);
}

} // namespace detail

[[nodiscard]]
std::vector<VkSparseImageMemoryRequirements2>
get_image_sparse_memory_requirements2(const functions& ext, device_handle device, const VkImageSparseMemoryRequirementsInfo2& info)
{
    std::uint32_t count = 0;
    fubuki::invoke<"vkGetImageSparseMemoryRequirements2KHR">(ext, device.vk, std::addressof(info), &count, nullptr);

    std::vector<VkSparseImageMemoryRequirements2> result;
    result.resize(count);

    fubuki::invoke<"vkGetImageSparseMemoryRequirements2KHR">(ext, device.vk, std::addressof(info), &count, result.data());

    return result;
}

#endif // defined(VK_KHR_get_memory_requirements2)

} // namespace fubuki::extension::khr_get_memory_requirements2
