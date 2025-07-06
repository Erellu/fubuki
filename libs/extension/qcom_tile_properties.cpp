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

#include "extension/qcom_tile_properties.hpp"

#include <core/invoke.hpp>
#include <core/structure_type.hpp>

namespace fubuki::extension::qcom_tile_properties
{

#if defined(VK_QCOM_tile_properties)

[[nodiscard]]
std::expected<std::vector<VkTilePropertiesQCOM>, api_call_info>
get_framebuffer_tile_properties(const functions& ext, device_handle device, framebuffer_handle framebuffer)
{
    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetFramebufferTilePropertiesQCOM">(ext, device.vk, framebuffer.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkTilePropertiesQCOM> result;
    result.resize(count);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetFramebufferTilePropertiesQCOM">(ext, device.vk, framebuffer.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<VkTilePropertiesQCOM, api_call_info>
get_dynamic_rendering_tile_properties(const functions& ext, device_handle device, const VkRenderingInfo& rendering_info) noexcept
{
    auto result = fubuki::make<VkTilePropertiesQCOM>();

    const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDynamicRenderingTilePropertiesQCOM">(ext, device.vk, std::addressof(rendering_info), std::addressof(result)));

    if(not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_QCOM_tile_properties)

} // namespace fubuki::extension::qcom_tile_properties
