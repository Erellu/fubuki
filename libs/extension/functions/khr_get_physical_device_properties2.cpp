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

#include "extension/functions/khr_get_physical_device_properties2.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
khr_get_physical_device_properties2 khr_get_physical_device_properties2::load([[maybe_unused]] instance_handle instance,
                                                                              [[maybe_unused]] version_number  vk_version) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");

    // clang-format off
    return
    {
#if defined(VK_KHR_get_physical_device_properties2)
        .get_physical_device_features2_khr = pfn<"vkGetPhysicalDeviceFeatures2KHR">(instance),
        .get_physical_device_properties2_khr = pfn<"vkGetPhysicalDeviceProperties2KHR">(instance),
        .get_physical_device_format_properties2_khr = pfn<"vkGetPhysicalDeviceFormatProperties2KHR">(instance),
        .get_physical_device_image_format_properties2_khr = pfn<"vkGetPhysicalDeviceImageFormatProperties2KHR">(instance),
        .get_physical_device_queue_family_properties2_khr = pfn<"vkGetPhysicalDeviceQueueFamilyProperties2KHR">(instance),
        .get_physical_device_memory_properties2_khr = pfn<"vkGetPhysicalDeviceMemoryProperties2KHR">(instance),
        .get_physical_device_sparse_image_format_properties2_khr = pfn<"vkGetPhysicalDeviceSparseImageFormatProperties2KHR">(instance),

        .cmd =
        {

        },
#endif // defined(VK_KHR_get_physical_device_properties2)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
