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

#include "fuyu/surface.hpp"

#include <core/assertion.hpp>
#include <extension/khr_surface.hpp>

#include "fuyu/instance.hpp" // IWYU pragma: keep (required for conversion to instance_view)

namespace fubuki::fuyu
{

/********************************************************************************/
/*                            PRIVATE MEMBER FUNCTIONS                          */
/********************************************************************************/

[[nodiscard]] std::optional<api_call_info> surface::create([[maybe_unused]] traits::platform::surface::underlying info) noexcept
{
#if defined(VK_KHR_surface)

    if(m_handle == null_handle)
    {
        if(m_info.callbacks)
        {
            if(const auto check = extension::khr_surface::create(instance()->ext, instance().handle(), info, m_info.callbacks->creation))
            {
                m_handle = *check;
            }
            else
            {
                return check.error();
            }
        }
        else
        {
            if(const auto check = extension::khr_surface::create(instance()->ext, instance().handle(), info))
            {
                m_handle = *check;
            }
            else
            {
                return check.error();
            }
        }
    }

#endif // defined(VK_KHR_surface)

    return {};
}

//------------------------------------------------------------------------------

void surface::destroy() noexcept
{
#if defined(VK_KHR_surface)
    if(m_handle != null_handle)
    {
        if(m_info.callbacks)
        {
            extension::khr_surface::destroy(instance()->ext, instance().handle(), m_handle, m_info.callbacks->destruction);
        }
        else
        {
            extension::khr_surface::destroy(instance()->ext, instance().handle(), m_handle);
        }
    }
#endif // defined(VK_KHR_surface)
}

} // namespace fubuki::fuyu
