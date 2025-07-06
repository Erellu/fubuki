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

#include "extension/functions/ext_opacity_micromap.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
ext_opacity_micromap ext_opacity_micromap::load([[maybe_unused]] instance_handle instance,
                                                [[maybe_unused]] version_number  vk_version,
                                                [[maybe_unused]] device_handle   device) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");
    fubuki_assert(device != null_handle, "Device cannot be null_handle.");

    [[maybe_unused]] auto* const device_get = pfn<"vkGetDeviceProcAddr">(instance);
    fubuki_assert(device_get != nullptr, "Could not retrieve vkGetDeviceProcAddr function pointer.");

    // clang-format off
    return
    {
#if defined(VK_EXT_opacity_micromap)
        .create_micromap_ext = pfn<"vkCreateMicromapEXT">(instance, device, device_get),
        .destroy_micromap_ext = pfn<"vkDestroyMicromapEXT">(instance, device, device_get),
        .build_micromaps_ext = pfn<"vkBuildMicromapsEXT">(instance, device, device_get),
        .copy_micromap_ext = pfn<"vkCopyMicromapEXT">(instance, device, device_get),
        .copy_micromap_to_memory_ext = pfn<"vkCopyMicromapToMemoryEXT">(instance, device, device_get),
        .copy_memory_to_micromap_ext = pfn<"vkCopyMemoryToMicromapEXT">(instance, device, device_get),
        .write_micromaps_properties_ext = pfn<"vkWriteMicromapsPropertiesEXT">(instance, device, device_get),
        .get_device_micromap_compatibility_ext = pfn<"vkGetDeviceMicromapCompatibilityEXT">(instance, device, device_get),
        .get_micromap_build_sizes_ext = pfn<"vkGetMicromapBuildSizesEXT">(instance, device, device_get),

        .cmd =
        {
            .build_micromaps_ext = pfn<"vkCmdBuildMicromapsEXT">(instance, device, device_get),
            .copy_micromap_ext = pfn<"vkCmdCopyMicromapEXT">(instance, device, device_get),
            .copy_micromap_to_memory_ext = pfn<"vkCmdCopyMicromapToMemoryEXT">(instance, device, device_get),
            .copy_memory_to_micromap_ext = pfn<"vkCmdCopyMemoryToMicromapEXT">(instance, device, device_get),
            .write_micromaps_properties_ext = pfn<"vkCmdWriteMicromapsPropertiesEXT">(instance, device, device_get),

        },
#endif // defined(VK_EXT_opacity_micromap)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
