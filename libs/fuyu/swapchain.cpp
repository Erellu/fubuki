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

#include "fuyu/swapchain.hpp"

#include <core/result.hpp>
#include <extension/khr_surface.hpp>

#include "fuyu/debug/name.hpp"

namespace fubuki::fuyu
{

#if defined(VK_KHR_swapchain)
[[nodiscard]] std::optional<api_call_info> swapchain::create(const VkSwapchainCreateInfoKHR& info) noexcept
{
    const fuyu::device_view d = device();

    if(m_handle == null_handle)
    {
        {
            const auto success = m_info.callbacks.has_value()
                ? extension::khr_swapchain::create(d.functions.get().ext, d.handle, info, m_info.callbacks->creation)
                : extension::khr_swapchain::create(d.functions.get().ext, d.handle, info);

            if(success)
            {
                m_handle = *success;
            }
            else
            {
                return success.error();
            }
        }
    }

    // Debug markers
    if(const auto check = debug::name_if_loaded(device(), m_handle, m_info.name.value_or("<Unnamed swapchain>")); not check)
    {
        return check.error();
    }

    return {};
}
#endif // #if defined(VK_KHR_swapchain)

void swapchain::destroy() noexcept
{
#if defined(VK_KHR_swapchain)

    const fuyu::device_view d = device();

    if(m_handle != null_handle)
    {
        if(m_info.callbacks.has_value())
        {
            extension::khr_swapchain::destroy(d.functions.get().ext, d.handle, m_handle, m_info.callbacks->destruction);
        }
        else
        {
            extension::khr_swapchain::destroy(d.functions.get().ext, d.handle, m_handle);
        }
    }
#endif // defined(VK_KHR_swapchain)
}

} // namespace fubuki::fuyu
