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

#ifndef FUBUKI_EXTENSION_NV_ACQUIRE_WINRT_DISPLAY_HPP
#define FUBUKI_EXTENSION_NV_ACQUIRE_WINRT_DISPLAY_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_acquire_winrt_display.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_acquire_winrt_display
{

#if defined(VK_NV_acquire_winrt_display)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkAcquireWinrtDisplayNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
acquire_winrt_display(const functions& ext, physical_device_handle physical_device, display_khr_handle display) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetWinrtDisplayNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<display_khr_handle, api_call_info>
get_winrt_display(const functions& ext, physical_device_handle physical_device, std::uint32_t device_relative_id) noexcept;

#endif // defined(VK_NV_acquire_winrt_display)

} // namespace fubuki::extension::nv_acquire_winrt_display

#endif // FUBUKI_EXTENSION_NV_ACQUIRE_WINRT_DISPLAY_HPP
