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

#ifndef FUBUKI_EXTENSION_NV_SHADING_RATE_IMAGE_HPP
#define FUBUKI_EXTENSION_NV_SHADING_RATE_IMAGE_HPP

#include <initializer_list>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_shading_rate_image.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_shading_rate_image::cmd
{

#if defined(VK_NV_shading_rate_image)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindShadingRateImageNV.html
FUBUKI_EXTENSION_API
void bind_shading_rate_image(const functions&      ext,
                             command_buffer_handle command_buffer,
                             image_view_handle     image_view,
                             VkImageLayout         image_layout) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportShadingRatePaletteNV.html
FUBUKI_EXTENSION_API
void set_viewport_shading_rate_palette(const functions&                        ext,
                                       command_buffer_handle                   command_buffer,
                                       std::uint32_t                           first_viewport,
                                       std::span<const VkShadingRatePaletteNV> shading_rate_palettes) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportShadingRatePaletteNV.html
inline void set_viewport_shading_rate_palette(const functions&                              ext,
                                              command_buffer_handle                         command_buffer,
                                              std::uint32_t                                 first_viewport,
                                              std::initializer_list<VkShadingRatePaletteNV> shading_rate_palettes) noexcept
{
    return set_viewport_shading_rate_palette(ext, command_buffer, first_viewport, std::span{shading_rate_palettes});
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoarseSampleOrderNV.html
FUBUKI_EXTENSION_API
void set_coarse_sample_order(const functions&                             ext,
                             command_buffer_handle                        command_buffer,
                             VkCoarseSampleOrderTypeNV                    sample_order_type,
                             std::span<const VkCoarseSampleOrderCustomNV> custom_sample_orders) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCoarseSampleOrderNV.html
inline void set_coarse_sample_order(const functions&                                   ext,
                                    command_buffer_handle                              command_buffer,
                                    VkCoarseSampleOrderTypeNV                          sample_order_type,
                                    std::initializer_list<VkCoarseSampleOrderCustomNV> custom_sample_orders) noexcept
{
    return set_coarse_sample_order(ext, command_buffer, sample_order_type, std::span{custom_sample_orders});
}

#endif // defined(VK_NV_shading_rate_image)

} // namespace fubuki::extension::nv_shading_rate_image::cmd

#endif // FUBUKI_EXTENSION_NV_SHADING_RATE_IMAGE_HPP
