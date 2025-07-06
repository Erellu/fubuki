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

#include "extension/khr_external_fence_fd.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_external_fence_fd
{

#if defined(VK_KHR_external_fence_fd)

[[nodiscard]]
std::expected<void, api_call_info>
import_fence_fd(const functions& ext, device_handle device, const VkImportFenceFdInfoKHR& import_fence_fd_info) noexcept
{
    return fubuki_validate(validate_by::expected, fubuki::invoke<"vkImportFenceFdKHR">(ext, device.vk, &import_fence_fd_info));
}

[[nodiscard]]
std::expected<int, api_call_info> get_fence_fd(const functions& ext, device_handle device, const VkFenceGetFdInfoKHR& get_fd_info) noexcept
{
    int result = {};

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetFenceFdKHR">(ext, device.vk, &get_fd_info, &result)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_KHR_external_fence_fd)

} // namespace fubuki::extension::khr_external_fence_fd
