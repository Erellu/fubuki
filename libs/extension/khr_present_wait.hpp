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

#ifndef FUBUKI_EXTENSION_KHR_PRESENT_WAIT_HPP
#define FUBUKI_EXTENSION_KHR_PRESENT_WAIT_HPP

#include <chrono>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_present_wait.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_present_wait
{

#if defined(VK_KHR_present_wait)

struct success
{
    /// Codes indicating the presentation succeeded.
    enum class code : std::underlying_type_t<VkResult>
    {
        normal     = VK_SUCCESS,
        timeout    = VK_TIMEOUT,
        suboptimal = VK_SUBOPTIMAL_KHR,
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const success& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

struct error
{
    /// Codes indicating an error occurred during the presentation.
    enum class code : std::underlying_type_t<VkResult>
    {
        out_of_host_memory              = VK_ERROR_OUT_OF_HOST_MEMORY,
        out_of_device_memory            = VK_ERROR_OUT_OF_DEVICE_MEMORY,
        device_lost                     = VK_ERROR_DEVICE_LOST,
        out_of_date                     = VK_ERROR_OUT_OF_DATE_KHR,
        surface_lost                    = VK_ERROR_SURFACE_LOST_KHR,
        full_screen_exclusive_mode_lost = VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT
    };

    code value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const error& c)
    {
        return out << fubuki::to_string_view(static_cast<VkResult>(c.value));
    }
};

using result = std::expected<success, error>; ///< Result of a call to present().

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkWaitForPresentKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API result wait_for_present(
    const functions& ext, device_handle device, swapchain_khr_handle swapchain, std::uint64_t present_id, std::chrono::nanoseconds timeout) noexcept;

#endif // defined(VK_KHR_present_wait)

} // namespace fubuki::extension::khr_present_wait

#endif // FUBUKI_EXTENSION_KHR_PRESENT_WAIT_HPP
