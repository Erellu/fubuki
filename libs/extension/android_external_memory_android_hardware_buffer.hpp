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

#ifndef FUBUKI_EXTENSION_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_HPP
#define FUBUKI_EXTENSION_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/android_external_memory_android_hardware_buffer.hpp" // IWYU pragma: export

namespace fubuki::extension::android_external_memory_android_hardware_buffer
{

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)

namespace detail
{
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAndroidHardwareBufferPropertiesANDROID.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info> get_android_hardware_buffer_properties(
    const functions& ext, device_handle device, const AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAndroidHardwareBufferPropertiesANDROID.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkAndroidHardwareBufferPropertiesANDROID, api_call_info> get_android_hardware_buffer_properties(
    const functions& ext, device_handle device, const AHardwareBuffer* buffer, const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkAndroidHardwareBufferPropertiesANDROID>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_android_hardware_buffer_properties(ext, device, buffer, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAndroidHardwareBufferPropertiesANDROID.html
[[nodiscard]] inline auto get_android_hardware_buffer_properties(const functions& ext, device_handle device, const AHardwareBuffer* buffer) noexcept
{
    return get_android_hardware_buffer_properties(ext, device, buffer, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryAndroidHardwareBufferANDROID.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<AHardwareBuffer*, api_call_info>
get_memory_android_hardware_buffer(const functions& ext, device_handle device, const VkMemoryGetAndroidHardwareBufferInfoANDROID& info) noexcept;

#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

} // namespace fubuki::extension::android_external_memory_android_hardware_buffer

#endif // FUBUKI_EXTENSION_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_HPP
