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

#include "extension/ext_acquire_xlib_display.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::ext_acquire_xlib_display
{

#if defined(VK_EXT_acquire_xlib_display)

[[nodiscard]]
std::expected<void, api_call_info>
acquire_xlib_display(const functions& ext, physical_device_handle physical_device, Display* dpy, display_khr_handle display) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkAcquireXlibDisplayEXT">(ext, physical_device.vk, dpy, display.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<std::optional<display_khr_handle>, api_call_info>
get_rand_r_output_display(const functions& ext, physical_device_handle physical_device, Display* dpy, RROutput rr_output) noexcept
{
    display_khr_handle display;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetRandROutputDisplayEXT">(ext, physical_device.vk, dpy, rr_output, std::addressof(display.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    if(display == null_handle)
    {
        return std::nullopt;
    }

    return display;
}

#endif // defined(VK_EXT_acquire_xlib_display)

} // namespace fubuki::extension::ext_acquire_xlib_display
