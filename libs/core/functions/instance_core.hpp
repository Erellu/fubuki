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

#ifndef FUBUKI_CORE_FUNCTIONSINSTANCE_HPP
#define FUBUKI_CORE_FUNCTIONSINSTANCE_HPP

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#include "core/config/macros.hpp"
#include "core/detail/pfn.hpp"
#include "core/handle.hpp"
#include "core/version_number.hpp"
#include "core/vulkan.hpp"

namespace fubuki
{

struct instance_core_functions
{

#if defined(VK_VERSION_1_0)
    struct vk10_core_functions
    {
        struct command
        {
        };

        PFN_vkCreateInstance                               create_instance                                    = nullptr;
        PFN_vkDestroyInstance                              destroy_instance                                   = nullptr;
        PFN_vkEnumeratePhysicalDevices                     enumerate_physical_devices                         = nullptr;
        PFN_vkGetPhysicalDeviceFeatures                    get_physical_device_features                       = nullptr;
        PFN_vkGetPhysicalDeviceFormatProperties            get_physical_device_format_properties              = nullptr;
        PFN_vkGetPhysicalDeviceImageFormatProperties       get_physical_device_image_format_properties        = nullptr;
        PFN_vkGetPhysicalDeviceProperties                  get_physical_device_properties                     = nullptr;
        PFN_vkGetPhysicalDeviceQueueFamilyProperties       get_physical_device_queue_family_properties        = nullptr;
        PFN_vkGetPhysicalDeviceMemoryProperties            get_physical_device_memory_properties              = nullptr;
        PFN_vkGetInstanceProcAddr                          get_instance_proc_addr                             = nullptr;
        PFN_vkGetDeviceProcAddr                            get_device_proc_addr                               = nullptr;
        PFN_vkCreateDevice                                 create_device                                      = nullptr;
        PFN_vkDestroyDevice                                destroy_device                                     = nullptr;
        PFN_vkEnumerateInstanceExtensionProperties         enumerate_instance_extension_properties            = nullptr;
        PFN_vkEnumerateDeviceExtensionProperties           enumerate_device_extension_properties              = nullptr;
        PFN_vkEnumerateInstanceLayerProperties             enumerate_instance_layer_properties                = nullptr;
        PFN_vkEnumerateDeviceLayerProperties               enumerate_device_layer_properties                  = nullptr;
        PFN_vkGetPhysicalDeviceSparseImageFormatProperties get_physical_device_sparse_image_format_properties = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk10_core_functions&() const { return vk10; }
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
    struct vk11_core_functions
    {
        struct command
        {
        };

        PFN_vkEnumerateInstanceVersion                      enumerate_instance_version                          = nullptr;
        PFN_vkEnumeratePhysicalDeviceGroups                 enumerate_physical_device_groups                    = nullptr;
        PFN_vkGetPhysicalDeviceFeatures2                    get_physical_device_features2                       = nullptr;
        PFN_vkGetPhysicalDeviceProperties2                  get_physical_device_properties2                     = nullptr;
        PFN_vkGetPhysicalDeviceFormatProperties2            get_physical_device_format_properties2              = nullptr;
        PFN_vkGetPhysicalDeviceImageFormatProperties2       get_physical_device_image_format_properties2        = nullptr;
        PFN_vkGetPhysicalDeviceQueueFamilyProperties2       get_physical_device_queue_family_properties2        = nullptr;
        PFN_vkGetPhysicalDeviceMemoryProperties2            get_physical_device_memory_properties2              = nullptr;
        PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 get_physical_device_sparse_image_format_properties2 = nullptr;
        PFN_vkGetPhysicalDeviceExternalBufferProperties     get_physical_device_external_buffer_properties      = nullptr;
        PFN_vkGetPhysicalDeviceExternalFenceProperties      get_physical_device_external_fence_properties       = nullptr;
        PFN_vkGetPhysicalDeviceExternalSemaphoreProperties  get_physical_device_external_semaphore_properties   = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk11_core_functions&() const { return vk11; }
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    struct vk12_core_functions
    {
        struct command
        {
        };

        command cmd = {};
    };

    [[nodiscard]] operator const vk12_core_functions&() const { return vk12; }
#endif // #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    struct vk13_core_functions
    {
        struct command
        {
        };

        PFN_vkGetPhysicalDeviceToolProperties get_physical_device_tool_properties = nullptr;

        command cmd = {};
    };

    [[nodiscard]] operator const vk13_core_functions&() const { return vk13; }
#endif // #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    struct vk14_core_functions
    {
        struct command
        {
        };

        command cmd = {};
    };

    [[nodiscard]] operator const vk14_core_functions&() const { return vk14; }
#endif // #if defined(VK_VERSION_1_4)

#if defined(VK_VERSION_1_0)
    vk10_core_functions vk10 = {};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
    vk11_core_functions vk11 = {};
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
    vk12_core_functions vk12 = {};
#endif // #if defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
    vk13_core_functions vk13 = {};
#endif // #if defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
    vk14_core_functions vk14 = {};
#endif // #if defined(VK_VERSION_1_4)
};

[[nodiscard]] FUBUKI_CORE_API instance_core_functions load(instance_handle instance, version_number version) noexcept;

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a instance_core_functions struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<instance_core_functions, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const instance_core_functions&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, version_struct, fubuki_name)                               \
    template<>                                                                                            \
    struct get_from<instance_core_functions, #vk_function_name>                                           \
    {                                                                                                     \
                                                                                                          \
        static constexpr bool                valid = true;                                                \
        [[nodiscard]] constexpr static auto* get(const instance_core_functions& functions) noexcept       \
        {                                                                                                 \
            static_assert(                                                                                \
                requires {                                                                                \
                    { functions.version_struct.fubuki_name };                                             \
                }, "Internal error. Bad name or version structure.");                                     \
                                                                                                          \
            auto pfn = functions.version_struct.fubuki_name;                                              \
                                                                                                          \
            using expected_pfn_type = PFN_##vk_function_name;                                             \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                        \
                                                                                                          \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch."); \
                                                                                                          \
            return pfn;                                                                                   \
        }                                                                                                 \
    }

FUBUKI_MAKE_GET_FROM(vkCreateInstance, vk10, create_instance);
FUBUKI_MAKE_GET_FROM(vkDestroyInstance, vk10, destroy_instance);
FUBUKI_MAKE_GET_FROM(vkEnumeratePhysicalDevices, vk10, enumerate_physical_devices);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceFeatures, vk10, get_physical_device_features);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceFormatProperties, vk10, get_physical_device_format_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceImageFormatProperties, vk10, get_physical_device_image_format_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceProperties, vk10, get_physical_device_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceQueueFamilyProperties, vk10, get_physical_device_queue_family_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceMemoryProperties, vk10, get_physical_device_memory_properties);
FUBUKI_MAKE_GET_FROM(vkGetInstanceProcAddr, vk10, get_instance_proc_addr);
FUBUKI_MAKE_GET_FROM(vkGetDeviceProcAddr, vk10, get_device_proc_addr);
FUBUKI_MAKE_GET_FROM(vkCreateDevice, vk10, create_device);
FUBUKI_MAKE_GET_FROM(vkDestroyDevice, vk10, destroy_device);
FUBUKI_MAKE_GET_FROM(vkEnumerateInstanceExtensionProperties, vk10, enumerate_instance_extension_properties);
FUBUKI_MAKE_GET_FROM(vkEnumerateDeviceExtensionProperties, vk10, enumerate_device_extension_properties);
FUBUKI_MAKE_GET_FROM(vkEnumerateInstanceLayerProperties, vk10, enumerate_instance_layer_properties);
FUBUKI_MAKE_GET_FROM(vkEnumerateDeviceLayerProperties, vk10, enumerate_device_layer_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceSparseImageFormatProperties, vk10, get_physical_device_sparse_image_format_properties);
FUBUKI_MAKE_GET_FROM(vkEnumerateInstanceVersion, vk11, enumerate_instance_version);
FUBUKI_MAKE_GET_FROM(vkEnumeratePhysicalDeviceGroups, vk11, enumerate_physical_device_groups);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceFeatures2, vk11, get_physical_device_features2);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceProperties2, vk11, get_physical_device_properties2);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceFormatProperties2, vk11, get_physical_device_format_properties2);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceImageFormatProperties2, vk11, get_physical_device_image_format_properties2);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceQueueFamilyProperties2, vk11, get_physical_device_queue_family_properties2);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceMemoryProperties2, vk11, get_physical_device_memory_properties2);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceSparseImageFormatProperties2, vk11, get_physical_device_sparse_image_format_properties2);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceExternalBufferProperties, vk11, get_physical_device_external_buffer_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceExternalFenceProperties, vk11, get_physical_device_external_fence_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceExternalSemaphoreProperties, vk11, get_physical_device_external_semaphore_properties);
FUBUKI_MAKE_GET_FROM(vkGetPhysicalDeviceToolProperties, vk13, get_physical_device_tool_properties);

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_CORE_FUNCTIONSINSTANCE_HPP
