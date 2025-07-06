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

#include "fuyu/functions/image.hpp"

#include "fuyu/invoke.hpp"

namespace fubuki::fuyu
{

namespace detail
{

#if defined(VK_VERSION_1_1)
[[nodiscard]] std::expected<bound_image_view, api_call_info>
bind(fuyu::image_resource_view image, fuyu::memory_view memory, const VkBindImageMemoryInfo& info) noexcept
{
    fubuki_assert(image.handle.vk == info.image, "Internal error: handle mistmach.");
    fubuki_assert(memory.handle.vk == info.memory, "Internal error: handle mistmach.");

    if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkBindImageMemory2">(image.device, 1u, std::addressof(info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return fuyu::bound_image_view{image, memory, info.memoryOffset};
}
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_4)

void device_subresource_layout(device_cref device, const VkDeviceImageSubresourceInfo& subresource, VkSubresourceLayout2& result) noexcept
{
    fuyu::invoke<"vkGetDeviceImageSubresourceLayout">(device, std::addressof(subresource), std::addressof(result));
}

void subresource_layout(fuyu::image_resource_view image, const VkImageSubresource2& subresource, VkSubresourceLayout2& result) noexcept
{
    fuyu::invoke<"vkGetImageSubresourceLayout2">(image.device, image.handle.vk, std::addressof(subresource), std::addressof(result));
}

[[nodiscard]] std::expected<void, api_call_info> transition(device_cref device, std::span<const VkHostImageLayoutTransitionInfo> info) noexcept
{
    return fubuki_validate(validate_by::expected, fuyu::invoke<"vkTransitionImageLayout">(device, vk_size(info), info.data()));
}

[[nodiscard]] std::expected<void, api_call_info> copy(device_cref device, const VkCopyMemoryToImageInfo& info) noexcept
{
    return fubuki_validate(validate_by::expected, fuyu::invoke<"vkCopyMemoryToImage">(device, std::addressof(info)));
}

[[nodiscard]] std::expected<void, api_call_info> copy(device_cref device, const VkCopyImageToMemoryInfo& info) noexcept
{
    return fubuki_validate(validate_by::expected, fuyu::invoke<"vkCopyImageToMemory">(device, std::addressof(info)));
}

[[nodiscard]] std::expected<void, api_call_info> copy(device_cref device, const VkCopyImageToImageInfo& info) noexcept
{
    return fubuki_validate(validate_by::expected, fuyu::invoke<"vkCopyImageToImage">(device, std::addressof(info)));
}

#endif // defined(VK_VERSION_1_4)

} // namespace detail

[[nodiscard]]
std::expected<bound_image_view, api_call_info> bind(fuyu::image_resource_view image, fuyu::memory_view memory, VkDeviceSize memory_offset) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fuyu::invoke<"vkBindImageMemory">(image.device, image.handle.vk, memory.handle.vk, memory_offset)); not check)
    {
        return std::unexpected{check.error()};
    }

    return bound_image_view{image, memory, memory_offset};
}

[[nodiscard]]
VkSubresourceLayout subresource_layout(fuyu::image_resource_view image, const VkImageSubresource& subresource) noexcept
{
    VkSubresourceLayout result = {};

    fuyu::invoke<"vkGetImageSubresourceLayout">(image.device, image.handle.vk, std::addressof(subresource), std::addressof(result));

    return result;
}

} // namespace fubuki::fuyu
