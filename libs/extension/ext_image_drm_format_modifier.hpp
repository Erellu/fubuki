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

#ifndef FUBUKI_EXTENSION_EXT_IMAGE_DRM_FORMAT_MODIFIER_HPP
#define FUBUKI_EXTENSION_EXT_IMAGE_DRM_FORMAT_MODIFIER_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_image_drm_format_modifier.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_image_drm_format_modifier
{

#if defined(VK_EXT_image_drm_format_modifier)

namespace detail
{
///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageDrmFormatModifierPropertiesEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info> get_image_drm_format_modifier_properties(
    const functions& ext, device_handle device, image_handle image, VkImageDrmFormatModifierPropertiesEXT& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageDrmFormatModifierPropertiesEXT.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkImageDrmFormatModifierPropertiesEXT, api_call_info> get_image_drm_format_modifier_properties(
    const functions& ext, device_handle device, image_handle image, const pnext_chain<elements...>& pnext) noexcept
{
    auto result = fubuki::make<VkImageDrmFormatModifierPropertiesEXT>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_image_drm_format_modifier_properties(ext, device, image, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageDrmFormatModifierPropertiesEXT.html
[[nodiscard]] inline auto get_image_drm_format_modifier_properties(const functions& ext, device_handle device, image_handle image) noexcept
{
    return get_image_drm_format_modifier_properties(ext, device, image, empty_pnext_chain);
}

#endif // defined(VK_EXT_image_drm_format_modifier)

} // namespace fubuki::extension::ext_image_drm_format_modifier

#endif // FUBUKI_EXTENSION_EXT_IMAGE_DRM_FORMAT_MODIFIER_HPP
