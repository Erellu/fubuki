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

#include "fuyu/functions/surface.hpp"

#include <core/config/macros.hpp>
#include <core/validate.hpp>
#include <extension/khr_surface.hpp>

#include "fuyu/instance.hpp" // IWYU pragma: keep (required for conversion to instance_view)

namespace fubuki::fuyu
{

#if defined(VK_KHR_surface)

[[nodiscard]] std::expected<VkSurfaceCapabilitiesKHR, api_call_info> capabilities(physical_device_handle physical_device,
                                                                                  fuyu::surface_view     s) noexcept
{
    return extension::khr_surface::capabilities(s.instance.get()->ext, physical_device, s);
}

[[nodiscard]] std::expected<small_vector<VkSurfaceFormatKHR>, api_call_info> formats(physical_device_handle physical_device, fuyu::surface_view s)
{
    return extension::khr_surface::formats(s.instance.get()->ext, physical_device, s);
}

[[nodiscard]] std::expected<small_vector<VkPresentModeKHR>, api_call_info> present_modes(physical_device_handle physical_device, fuyu::surface_view s)
{
    return extension::khr_surface::present_modes(s.instance.get()->ext, physical_device, s);
}

[[nodiscard]] std::expected<fuyu::surface_properties, api_call_info> properties(physical_device_handle physical_device, fuyu::surface_view s)
{
    fuyu::surface_properties result = {};

    if(auto check = capabilities(physical_device, s))
    {
        result.capabilities = std::move(check).value();
    }
    else
    {
        return std::unexpected{check.error()};
    }

    if(auto check = formats(physical_device, s))
    {
        result.formats = std::move(check).value();
    }
    else
    {
        return std::unexpected{check.error()};
    }

    if(auto check = present_modes(physical_device, s))
    {
        result.present_modes = std::move(check).value();
    }
    else
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_KHR_surface)

} // namespace fubuki::fuyu
