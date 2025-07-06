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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#include "core/functions/instance_core.hpp"

#include "core/assertion.hpp"
#include "core/pfn.hpp"
#include "core/vulkan.hpp"

// Extracted from vulkan_core.h (Apache 2.0)
// Allows to compile with VK_NO_PROTOTYPES
extern "C"
{

// NOLINTBEGIN(readability-identifier-naming)
extern VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkInstance*                  pInstance);

extern VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);

extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                             ::uint32_t*            pPropertyCount,
                                                                             VkExtensionProperties* pProperties);

extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(::uint32_t* pPropertyCount, VkLayerProperties* pProperties);

extern VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceVersion(::uint32_t* pApiVersion);

} // extern "C"
// NOLINTEND(readability-identifier-naming)

namespace fubuki
{

[[nodiscard]] instance_core_functions load(instance_handle instance, version_number version) noexcept
{
    fubuki_assert(instance != null_handle, "Instance must not be a null handle.");
    fubuki_assert(version >= version_number(1, 0, 0), "Invalid version.");

#if defined(VK_VERSION_1_0)
    instance_core_functions::vk10_core_functions vk10 = {};

    if(version >= version_number{1, 0, 0})
    {
        // clang-format off
        vk10 =
        {
            .create_instance = vkCreateInstance,
            .destroy_instance = pfn<"vkDestroyInstance">(instance),
            .enumerate_physical_devices = pfn<"vkEnumeratePhysicalDevices">(instance),
            .get_physical_device_features = pfn<"vkGetPhysicalDeviceFeatures">(instance),
            .get_physical_device_format_properties = pfn<"vkGetPhysicalDeviceFormatProperties">(instance),
            .get_physical_device_image_format_properties = pfn<"vkGetPhysicalDeviceImageFormatProperties">(instance),
            .get_physical_device_properties = pfn<"vkGetPhysicalDeviceProperties">(instance),
            .get_physical_device_queue_family_properties = pfn<"vkGetPhysicalDeviceQueueFamilyProperties">(instance),
            .get_physical_device_memory_properties = pfn<"vkGetPhysicalDeviceMemoryProperties">(instance),
            .get_instance_proc_addr = pfn<"vkGetInstanceProcAddr">(instance),
            .get_device_proc_addr = pfn<"vkGetDeviceProcAddr">(instance),
            .create_device = pfn<"vkCreateDevice">(instance),
            .destroy_device = pfn<"vkDestroyDevice">(instance),
            .enumerate_instance_extension_properties = vkEnumerateInstanceExtensionProperties,
            .enumerate_device_extension_properties = pfn<"vkEnumerateDeviceExtensionProperties">(instance),
            .enumerate_instance_layer_properties = vkEnumerateInstanceLayerProperties,
            .enumerate_device_layer_properties = pfn<"vkEnumerateDeviceLayerProperties">(instance),
            .get_physical_device_sparse_image_format_properties = pfn<"vkGetPhysicalDeviceSparseImageFormatProperties">(instance),

            .cmd =
            {

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
    instance_core_functions::vk11_core_functions vk11 = {};

    if(version >= version_number{1, 1, 0})
    {
        // clang-format off
        vk11 =
        {
            .enumerate_instance_version = vkEnumerateInstanceVersion,
            .enumerate_physical_device_groups = pfn<"vkEnumeratePhysicalDeviceGroups">(instance),
            .get_physical_device_features2 = pfn<"vkGetPhysicalDeviceFeatures2">(instance),
            .get_physical_device_properties2 = pfn<"vkGetPhysicalDeviceProperties2">(instance),
            .get_physical_device_format_properties2 = pfn<"vkGetPhysicalDeviceFormatProperties2">(instance),
            .get_physical_device_image_format_properties2 = pfn<"vkGetPhysicalDeviceImageFormatProperties2">(instance),
            .get_physical_device_queue_family_properties2 = pfn<"vkGetPhysicalDeviceQueueFamilyProperties2">(instance),
            .get_physical_device_memory_properties2 = pfn<"vkGetPhysicalDeviceMemoryProperties2">(instance),
            .get_physical_device_sparse_image_format_properties2 = pfn<"vkGetPhysicalDeviceSparseImageFormatProperties2">(instance),
            .get_physical_device_external_buffer_properties = pfn<"vkGetPhysicalDeviceExternalBufferProperties">(instance),
            .get_physical_device_external_fence_properties = pfn<"vkGetPhysicalDeviceExternalFenceProperties">(instance),
            .get_physical_device_external_semaphore_properties = pfn<"vkGetPhysicalDeviceExternalSemaphoreProperties">(instance),

            .cmd =
            {

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    instance_core_functions::vk12_core_functions vk12 = {};

    if(version >= version_number{1, 2, 0})
    {
        // clang-format off
        vk12 =
        {

            .cmd =
            {

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    instance_core_functions::vk13_core_functions vk13 = {};

    if(version >= version_number{1, 3, 0})
    {
        // clang-format off
        vk13 =
        {
            .get_physical_device_tool_properties = pfn<"vkGetPhysicalDeviceToolProperties">(instance),

            .cmd =
            {

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    instance_core_functions::vk14_core_functions vk14 = {};

    if(version >= version_number{1, 4, 0})
    {
        // clang-format off
        vk14 =
        {

            .cmd =
            {

            },
        };
        // clang-format on
    }
#endif // #if defined(VK_VERSION_1_4)

    return {

#if defined(VK_VERSION_1_0)
        vk10,
#endif //  #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
        vk11,
#endif //  #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
        vk12,
#endif //  #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
        vk13,
#endif //  #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
        vk14,
#endif //  #if defined(VK_VERSION_1_4)
    };
}

} // namespace fubuki
