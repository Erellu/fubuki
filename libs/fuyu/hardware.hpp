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

#ifndef FUBUKI_FUYU_HARDWARE_HPP
#define FUBUKI_FUYU_HARDWARE_HPP

#include <cstdint>
#include <vector>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/functions/instance_core.hpp>
#include <core/future/flat_set.hpp>
#include <core/pnext_chain.hpp>
#include <core/string_literal.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/physical_device.hpp"
#include "fuyu/views/device.hpp"
#include "fuyu/views/instance.hpp"

namespace fubuki::fuyu::hardware
{

/// Information about extension supported by available hardware.
struct extension_support
{
    std::vector<VkExtensionProperties> properties = {}; ///< The complete properties of the available extensions.
    small_flat_set<std::string>        names      = {}; ///< The names, in a suitable form for Vulkan (contiguous, unique values).
};

/// Determines the total number of physical devices.
[[nodiscard]] FUBUKI_FUYU_API std::expected<std::uint32_t, api_call_info> physical_device_count(instance_view instance) noexcept;

//------------------------------------------------------------------------------

/// Polls the hardware to determine the available devices.
[[nodiscard]] FUBUKI_FUYU_API std::expected<small_vector<physical_device_handle>, api_call_info> physical_devices(instance_view instance) noexcept;

//------------------------------------------------------------------------------

/// Determines the extensions supported by a device.
[[nodiscard]] FUBUKI_FUYU_API std::expected<extension_support, api_call_info> supported_extensions(instance_view, physical_device_handle) noexcept;

//------------------------------------------------------------------------------

/// Determines the extension supported by an instance when the given layer is enabled.
/// @param layer Name of the layer to check.
/// @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if host-side temporary resources allocation failed.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkEnumerateInstanceExtensionProperties.html
[[nodiscard]] FUBUKI_FUYU_API std::expected<extension_support, api_call_info> supported_instance_extensions(const char* layer);

//------------------------------------------------------------------------------

/// Determines the extensions supported by an instance when no validation layer is enabled.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkEnumerateInstanceExtensionProperties.html
/// @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if host-side temporary resources allocation failed.
[[nodiscard]] inline std::expected<extension_support, api_call_info> supported_instance_extensions()
{
    return supported_instance_extensions(nullptr);
}

//------------------------------------------------------------------------------

/// Determines the index for the requested queue family, or returns std::nullopt if no match was found.
[[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_FUYU_API std::optional<std::uint32_t> queue_family_index(std::span<const VkQueueFamilyProperties>,
                                                                                               VkQueueFlags) noexcept;

//------------------------------------------------------------------------------

/// Returns the queue properties of a physical device.
[[nodiscard]] FUBUKI_FUYU_API small_vector<VkQueueFamilyProperties> queue_properties(instance_view, physical_device_handle) noexcept;

//------------------------------------------------------------------------------

/// Returns the queue properties of a physical device.
[[nodiscard]] FUBUKI_FUYU_API small_vector<VkQueueFamilyProperties> queue_properties(device_view) noexcept;

//------------------------------------------------------------------------------

#if defined(VK_VERSION_1_1)

/// Returns the external handle types supported by buffers.
[[nodiscard]] FUBUKI_FUYU_API VkExternalBufferProperties external_buffer_properties(instance_view instance,
                                                                                    VkPhysicalDevice,
                                                                                    const VkPhysicalDeviceExternalBufferInfo& info) noexcept;

#endif // defined(VK_VERSION_1_1)

//------------------------------------------------------------------------------

/// Finds a memory index corresponding to a certain memory type.
[[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_FUYU_API std::optional<std::uint32_t>
memory_index(const VkPhysicalDeviceMemoryProperties& properties, std::uint32_t type, VkMemoryPropertyFlags flags) noexcept;

//------------------------------------------------------------------------------

/// Finds a memory index corresponding to a certain memory type.
[[nodiscard]] FUBUKI_SEMI_PURE inline std::optional<std::uint32_t>
memory_index(const VkPhysicalDeviceMemoryProperties& properties, const VkMemoryRequirements& requirements, VkMemoryPropertyFlags flags) noexcept
{
    return hardware::memory_index(properties, requirements.memoryTypeBits, flags);
}

//------------------------------------------------------------------------------

/// Finds a memory index corresponding to a certain memory type.
[[nodiscard]] FUBUKI_SEMI_PURE FUBUKI_FUYU_API std::optional<std::uint32_t>
memory_index(device_view d, const VkMemoryRequirements& requirements, VkMemoryPropertyFlags flags) noexcept;

//------------------------------------------------------------------------------

#if defined(VK_VERSION_1_1)
/// Finds a memory index corresponding to a certain memory type.
[[nodiscard]] FUBUKI_SEMI_PURE inline std::optional<std::uint32_t>
memory_index(const VkPhysicalDeviceMemoryProperties& properties, const VkMemoryRequirements2& requirements, VkMemoryPropertyFlags flags) noexcept
{
    return memory_index(properties, requirements.memoryRequirements, flags);
}

/// Finds a memory index corresponding to a certain memory type.
[[nodiscard]] FUBUKI_SEMI_PURE inline std::optional<std::uint32_t>
memory_index(device_view d, const VkMemoryRequirements2& requirements, VkMemoryPropertyFlags flags) noexcept
{
    return memory_index(d, requirements.memoryRequirements, flags);
}

#endif // defined(VK_VERSION_1_1)

//------------------------------------------------------------------------------

/// Queries available information about a physical device.
/// @note This overloads queries core features and properties and ones specified by user in the chains.
template<traits::pnext_chain::type features_chain_type, traits::pnext_chain::type properties_chain_type, traits::pnext_chain::type memory_chain_type>
[[nodiscard]]
inline std::expected<fuyu::physical_device, api_call_info> physical_device_information(instance_view                            instance,
                                                                                       physical_device_handle                   device,
                                                                                       [[maybe_unused]] features_chain_type&&   features_chain,
                                                                                       [[maybe_unused]] properties_chain_type&& properties_chain,
                                                                                       [[maybe_unused]] memory_chain_type&&     memory_chain) noexcept
{
    physical_device result = {};
    result.handle          = device;

    if(auto x = hardware::supported_extensions(instance, device))
    {
        result.extensions = std::move(x).value().properties;
    }
    else
    {
        return std::unexpected{x.error()};
    }

#if defined(VK_VERSION_1_1)
    if(instance.version >= version_number{1, 1, 0})
    {
        fubuki_assert(instance->vk11.get_physical_device_memory_properties2 != nullptr, "Instance functions must be loaded.");
        fubuki_assert(instance->vk11.get_physical_device_features2 != nullptr, "Instance functions must be loaded.");
        fubuki_assert(instance->vk11.get_physical_device_properties2 != nullptr, "Instance functions must be loaded.");

        // Memory properties
        {
            auto memory = fubuki::make<VkPhysicalDeviceMemoryProperties2>();

            extend(memory, std::forward<memory_chain_type>(memory_chain));

            instance->vk11.get_physical_device_memory_properties2(device.vk, &memory);

            result.memory.properties = memory.memoryProperties;
        }

        // Features
        {
            auto features  = fubuki::make<VkPhysicalDeviceFeatures2>();
            features.pNext = std::addressof(result.features.vk11);

    #if defined(VK_VERSION_1_4)

            if(instance.version >= version_number{1, 3, 0})
            {

                result.features.vk11.pNext = std::addressof(result.features.vk12);
                result.features.vk12.pNext = std::addressof(result.features.vk13);
                result.features.vk13.pNext = std::addressof(result.features.vk14);
                extend(result.features.vk14, std::forward<features_chain_type>(features_chain));
            }
            else
    #endif // defined(VK_VERSION_1_4)
    #if defined(VK_VERSION_1_3)

                if(instance.version >= version_number{1, 3, 0})
            {

                result.features.vk11.pNext = std::addressof(result.features.vk12);
                result.features.vk12.pNext = std::addressof(result.features.vk13);
                extend(result.features.vk13, std::forward<features_chain_type>(features_chain));
            }
            else
    #endif // defined(VK_VERSION_1_3)
    #if defined(VK_VERSION_1_2)

                if(instance.version >= version_number{1, 2, 0})
            {
                result.features.vk11.pNext = std::addressof(result.features.vk12);
                extend(result.features.vk12, std::forward<features_chain_type>(features_chain));
            }
            else
    #endif // defined(VK_VERSION_1_2)
           // Vulkan 1.1
            {
                extend(result.features.vk11, std::forward<features_chain_type>(features_chain));
            }

            // Query
            {
                instance->vk11.get_physical_device_features2(device.vk, std::addressof(features));
                result.features.vk10 = features.features;
            }
        }

        // Properties
        {
            auto properties  = fubuki::make<VkPhysicalDeviceProperties2>();
            properties.pNext = result.properties.vk11.pNext;

    #if defined(VK_VERSION_1_4)

            if(instance.version >= version_number{1, 4, 0})
            {
                result.properties.vk11.pNext = std::addressof(result.properties.vk12);
                result.properties.vk12.pNext = std::addressof(result.properties.vk13);
                result.properties.vk13.pNext = std::addressof(result.properties.vk14);
                extend(result.properties.vk14, std::forward<properties_chain_type>(properties_chain));
            }
            else
    #endif // defined(VK_VERSION_1_4)
    #if defined(VK_VERSION_1_3)

                if(instance.version >= version_number{1, 3, 0})
            {
                result.properties.vk11.pNext = std::addressof(result.properties.vk12);
                result.properties.vk12.pNext = std::addressof(result.properties.vk13);
                extend(result.properties.vk13, std::forward<properties_chain_type>(properties_chain));
            }
            else
    #endif // defined(VK_VERSION_1_3)
    #if defined(VK_VERSION_1_2)
                if(instance.version >= version_number{1, 2, 0})
            {
                result.properties.vk11.pNext = std::addressof(result.properties.vk12);
                extend(result.properties.vk12, std::forward<properties_chain_type>(properties_chain));
            }
            else
    #endif // defined(VK_VERSION_1_2)
           // Vulkan 1.1
            {
                extend(result.properties.vk11, std::forward<properties_chain_type>(properties_chain));
            }

            // Query
            {
                instance->vk11.get_physical_device_properties2(device.vk, std::addressof(properties));
                result.properties.vk10 = properties.properties;
            }
        }
        return result;
    }
#endif // defined(VK_VERSION_1_1)

    fubuki_assert(instance->vk10.get_physical_device_memory_properties != nullptr, "Instance functions must be loaded.");
    fubuki_assert(instance->vk10.get_physical_device_features != nullptr, "Instance functions must be loaded.");
    fubuki_assert(instance->vk10.get_physical_device_properties != nullptr, "Instance functions must be loaded.");

    // Memory
    {
        instance->vk10.get_physical_device_memory_properties(device.vk, std::addressof(result.memory.properties));
    }

    // Features
    {
        instance->vk10.get_physical_device_features(device.vk, std::addressof(result.features.vk10));
    }

    // Properties
    {
        instance->vk10.get_physical_device_properties(device.vk, std::addressof(result.properties.vk10));
    }

    // Chain contents assertion (placed here for readability)
    {
        using feat_chain [[maybe_unused]] = std::decay_t<features_chain_type>;
        using prop_chain [[maybe_unused]] = std::decay_t<features_chain_type>;

#if defined(VK_VERSION_1_1)
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan11Features>(typename feat_chain::elements{}), "Already added by Fubuki.");
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan11Properties>(typename prop_chain::elements{}), "Already added by Fubuki.");
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan12Features>(typename feat_chain::elements{}), "Already added by Fubuki.");
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan12Properties>(typename prop_chain::elements{}), "Already added by Fubuki.");
#endif // defined(VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan13Features>(typename feat_chain::elements{}), "Already added by Fubuki.");
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan13Properties>(typename prop_chain::elements{}), "Already added by Fubuki.");
#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan14Features>(typename feat_chain::elements{}), "Already added by Fubuki.");
        static_assert(not traits::tuple::contains<VkPhysicalDeviceVulkan14Properties>(typename prop_chain::elements{}), "Already added by Fubuki.");
#endif // defined(VK_VERSION_1_4)
    }

    return result;
}

//------------------------------------------------------------------------------

/// Queries available information about a physical device.
/// @note This overload only queries core features and properties (per Vulkan version).
[[nodiscard]]
inline std::expected<fuyu::physical_device, api_call_info> physical_device_information(instance_view instance, physical_device_handle device) noexcept
{
    return physical_device_information(instance, device, empty_pnext_chain, empty_pnext_chain, empty_pnext_chain);
}

} // namespace fubuki::fuyu::hardware

#endif // FUBUKI_FUYU_HARDWARE_HPP
