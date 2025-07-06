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

#ifndef FUBUKI_EXTENSION_EXT_HDR_METADATA_HPP
#define FUBUKI_EXTENSION_EXT_HDR_METADATA_HPP

#include <span>

#include <core/as_span.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_hdr_metadata.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_hdr_metadata
{

#if defined(VK_EXT_hdr_metadata)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkSetHdrMetadataEXT.html
FUBUKI_EXTENSION_API
void set_hdr_metadata(const functions&                      ext,
                      device_handle                         device,
                      std::span<const swapchain_khr_handle> swapchains,
                      std::span<const VkHdrMetadataEXT>     metadata) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkSetHdrMetadataEXT.html
inline void set_hdr_metadata(const functions& ext, device_handle device, swapchain_khr_handle swapchain, const VkHdrMetadataEXT& metadata) noexcept
{
    return set_hdr_metadata(ext, device, fubuki::as_span(swapchain), fubuki::as_span(metadata));
}

#endif // defined(VK_EXT_hdr_metadata)

} // namespace fubuki::extension::ext_hdr_metadata

#endif // FUBUKI_EXTENSION_EXT_HDR_METADATA_HPP
