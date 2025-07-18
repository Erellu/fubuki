﻿/*
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

#ifndef FUBUKI_EXTENSION_KHR_EXTERNAL_MEMORY_FD_HPP
#define FUBUKI_EXTENSION_KHR_EXTERNAL_MEMORY_FD_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_external_memory_fd.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_external_memory_fd
{

#if defined(VK_KHR_external_memory_fd)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryFdPropertiesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_memory_fd_properties(
    const functions& ext, device_handle device, VkExternalMemoryHandleTypeFlagBits handle_type, int fd, VkMemoryFdPropertiesKHR& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryFdKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<int, api_call_info>
                                   get_memory_fd(const functions& ext, device_handle device, const VkMemoryGetFdInfoKHR& get_fd_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryFdPropertiesKHR.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkMemoryFdPropertiesKHR, api_call_info> get_memory_fd_properties(const functions&                   ext,
                                                                                                    device_handle                      device,
                                                                                                    VkExternalMemoryHandleTypeFlagBits handle_type,
                                                                                                    int                                fd,
                                                                                                    const pnext_chain<elements...>&    pnext) noexcept
{
    auto result = fubuki::make<VkMemoryFdPropertiesKHR>();
    fubuki::extend(result, pnext);

    if(const auto check = detail::get_memory_fd_properties(ext, device, handle_type, fd, result); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryFdPropertiesKHR.html
[[nodiscard]] inline auto
get_memory_fd_properties(const functions& ext, device_handle device, VkExternalMemoryHandleTypeFlagBits handle_type, int fd) noexcept
{
    return get_memory_fd_properties(ext, device, handle_type, fd, empty_pnext_chain);
}

#endif // defined(VK_KHR_external_memory_fd)

} // namespace fubuki::extension::khr_external_memory_fd

#endif // FUBUKI_EXTENSION_KHR_EXTERNAL_MEMORY_FD_HPP
