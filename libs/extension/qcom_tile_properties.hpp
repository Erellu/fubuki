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

#ifndef FUBUKI_EXTENSION_QCOM_TILE_PROPERTIES_HPP
#define FUBUKI_EXTENSION_QCOM_TILE_PROPERTIES_HPP

#include <vector>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/qcom_tile_properties.hpp" // IWYU pragma: export

namespace fubuki::extension::qcom_tile_properties
{

#if defined(VK_QCOM_tile_properties)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetFramebufferTilePropertiesQCOM.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkTilePropertiesQCOM>, api_call_info>
                                   get_framebuffer_tile_properties(const functions& ext, device_handle device, framebuffer_handle framebuffer);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDynamicRenderingTilePropertiesQCOM.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<VkTilePropertiesQCOM, api_call_info>
get_dynamic_rendering_tile_properties(const functions& ext, device_handle device, const VkRenderingInfo& rendering_info) noexcept;

#endif // defined(VK_QCOM_tile_properties)

} // namespace fubuki::extension::qcom_tile_properties

#endif // FUBUKI_EXTENSION_QCOM_TILE_PROPERTIES_HPP
