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

#include "extension/khr_bind_memory2.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::khr_bind_memory2
{

#if defined(VK_KHR_bind_memory2)

[[nodiscard]]
std::expected<void, api_call_info>
bind_buffer_memory2(const functions& ext, device_handle device, std::span<const VkBindBufferMemoryInfo> bind_infos) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkBindBufferMemory2KHR">(ext, device.vk, vk_size(bind_infos), bind_infos.data()));
}

[[nodiscard]]
std::expected<void, api_call_info>
bind_image_memory2(const functions& ext, device_handle device, std::span<const VkBindImageMemoryInfo> bind_infos) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkBindImageMemory2KHR">(ext, device.vk, vk_size(bind_infos), bind_infos.data()));
}

#endif // defined(VK_KHR_bind_memory2)

} // namespace fubuki::extension::khr_bind_memory2
