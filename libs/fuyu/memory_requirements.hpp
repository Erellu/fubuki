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

#ifndef FUBUKI_FUYU_MEMORY_REQUIREMENTS_HPP
#define FUBUKI_FUYU_MEMORY_REQUIREMENTS_HPP

#include <type_traits>

#include <core/assertion.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/vulkan.hpp>

#include "fuyu/device.hpp" // IWYU pragma: keep (required for conversion from device to device_view)
#include "fuyu/views/buffer.hpp"
#include "fuyu/views/device.hpp"
#include "fuyu/views/image.hpp"

namespace fubuki
{

/// Determines memory requirements for a buffer.
template<traits::pnext_chain::type buffer_requirements_chain_type, traits::pnext_chain::type memory_requirements_chain_type>
[[nodiscard]]
inline VkMemoryRequirements memory_requirements(fuyu::device_view                device,
                                                buffer_handle                    buffer,
                                                buffer_requirements_chain_type&& buffer_requirements_chain,
                                                memory_requirements_chain_type&& memory_requirements_chain)
{
    using buffer_chain_type [[maybe_unused]] = std::decay_t<buffer_requirements_chain_type>;
    using memory_chain_type [[maybe_unused]] = std::decay_t<memory_requirements_chain_type>;

    // Sanity checks
    {
        fubuki_assert(device.handle != null_handle, "Device must not be nullptr.");
    }

#if defined(VK_VERSION_1_1)

    if(device.version >= version_number{1, 1, 0})
    {
        fubuki_assert(device->vk11.get_buffer_memory_requirements2 != nullptr, "Device functions must be loaded.");

        VkBufferMemoryRequirementsInfo2 info{.sType = structure_type_v<VkBufferMemoryRequirementsInfo2>, .pNext = nullptr, .buffer = buffer.vk};

        VkMemoryRequirements2 requirements{
            .sType              = structure_type_v<VkMemoryRequirements2>,
            .pNext              = nullptr,
            .memoryRequirements = {.size = 0, .alignment = 0, .memoryTypeBits = {}}
        };

        extend(info, std::forward<buffer_requirements_chain_type>(buffer_requirements_chain));
        extend(requirements, std::forward<memory_requirements_chain_type>(memory_requirements_chain));

        if(buffer != null_handle)
        {
            device->vk11.get_buffer_memory_requirements2(device.handle.vk, std::addressof(info), std::addressof(requirements));
        }

        return requirements.memoryRequirements; // The rest is written to the pNext chain
    }

    // Vulkan 1.0
    {
        fubuki_assert((std::is_same_v<buffer_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
        fubuki_assert((std::is_same_v<memory_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
        fubuki_assert(device->vk10.get_buffer_memory_requirements != nullptr, "Device functions must be loaded.");

        VkMemoryRequirements requirements = {};

        if(buffer != null_handle)
        {
            device->vk10.get_buffer_memory_requirements(device.handle.vk, buffer.vk, std::addressof(requirements));
        }

        return requirements;
    }

#else  // defined(VK_VERSION_1_1)
    fubuki_assert((std::is_same_v<buffer_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
    fubuki_assert((std::is_same_v<memory_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
    fubuki_assert(device->vk10.get_buffer_memory_requirements != nullptr, "Device functions must be loaded.");

    VkMemoryRequirements requirements = {};

    if(buffer != null_handle)
    {
        device->vk10.get_buffer_memory_requirements(device.handle.vk, buffer.vk, std::addressof(requirements));
    }

    return requirements;
#endif // defined(VK_VERSION_1_1)
}

/// Determines memory requirements for a buffer.
template<traits::pnext_chain::type buffer_requirements_chain_type, traits::pnext_chain::type memory_requirements_chain_type>
[[nodiscard]]
inline VkMemoryRequirements memory_requirements(fuyu::buffer_resource_view       buffer,
                                                buffer_requirements_chain_type&& buffer_requirements_chain,
                                                memory_requirements_chain_type&& memory_requirements_chain)
{
    return memory_requirements(buffer.device.get(),
                               buffer.handle,
                               std::forward<buffer_requirements_chain_type>(buffer_requirements_chain),
                               std::forward<memory_requirements_chain_type>(memory_requirements_chain));
}

//------------------------------------------------------------------------------

/// Determines memory requirements for a buffer.
[[nodiscard]]
inline auto memory_requirements(fuyu::device_view device, buffer_handle buffer)
{
    return memory_requirements(device, buffer, empty_pnext_chain, empty_pnext_chain);
}

/// Determines memory requirements for a buffer.
[[nodiscard]]
inline auto memory_requirements(fuyu::buffer_resource_view buffer)
{
    return memory_requirements(buffer.device.get(), buffer, empty_pnext_chain, empty_pnext_chain);
}

//------------------------------------------------------------------------------

/// Determines memory requirements for an image.
template<traits::pnext_chain::type image_requirements_chain_type, traits::pnext_chain::type memory_requirements_chain_type>
[[nodiscard]]
inline VkMemoryRequirements memory_requirements(fuyu::device_view                device,
                                                image_handle                     image,
                                                image_requirements_chain_type&&  image_requirements_chain,
                                                memory_requirements_chain_type&& memory_requirements_chain)
{
    using image_chain_type [[maybe_unused]]  = std::decay_t<image_requirements_chain_type>;
    using memory_chain_type [[maybe_unused]] = std::decay_t<memory_requirements_chain_type>;

    // Sanity checks
    {
        fubuki_assert(device.handle != null_handle, "Device must not be nullptr.");
    }

#if defined(VK_VERSION_1_1)
    if(device.version >= version_number{1, 1, 1})
    {
        fubuki_assert(device->vk11.get_image_memory_requirements2 != nullptr, "Device functions must be loaded.");

        VkImageMemoryRequirementsInfo2 info{.sType = structure_type_v<VkImageMemoryRequirementsInfo2>, .pNext = nullptr, .image = image.vk};

        VkMemoryRequirements2 requirements{
            .sType              = structure_type_v<VkMemoryRequirements2>,
            .pNext              = nullptr,
            .memoryRequirements = {.size = 0, .alignment = 0, .memoryTypeBits = {}}
        };

        extend(info, std::forward<image_requirements_chain_type>(image_requirements_chain));
        extend(requirements, std::forward<memory_requirements_chain_type>(memory_requirements_chain));

        if(image != null_handle)
        {
            device->vk11.get_image_memory_requirements2(device.handle.vk, std::addressof(info), std::addressof(requirements));
        }

        return requirements.memoryRequirements;
    }

    // Vulkan 1.0
    {
        fubuki_assert((std::is_same_v<image_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
        fubuki_assert((std::is_same_v<memory_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
        fubuki_assert(device->vk10.get_image_memory_requirements != nullptr, "Device functions must be loaded.");

        VkMemoryRequirements requirements = {};

        if(image != null_handle)
        {
            device->vk10.get_image_memory_requirements(device.handle.vk, image.vk, std::addressof(requirements));
        }

        return requirements;
    }
#else  // defined(VK_VERSION_1_1)
    fubuki_assert((std::is_same_v<image_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
    fubuki_assert((std::is_same_v<memory_chain_type, pnext_chain<>>), "Device was created with version < 1.1, but chain is not empty.");
    fubuki_assert(device->vk10.get_image_memory_requirements != nullptr, "Device functions must be loaded.");

    VkMemoryRequirements requirements = {};

    if(image != null_handle)
    {
        device->vk10.get_image_memory_requirements(device.handle.vk, image.vk, std::addressof(requirements));
    }

    return requirements;
#endif // defined(VK_VERSION_1_1)
}

/// Determines memory requirements for an image.
template<traits::pnext_chain::type image_requirements_chain_type, traits::pnext_chain::type memory_requirements_chain_type>
[[nodiscard]]
inline VkMemoryRequirements memory_requirements(fuyu::image_resource_view        image,
                                                image_requirements_chain_type&&  image_requirements_chain,
                                                memory_requirements_chain_type&& memory_requirements_chain)
{
    return memory_requirements(image.device.get(),
                               image.handle,
                               std::forward<image_requirements_chain_type>(image_requirements_chain),
                               std::forward<memory_requirements_chain_type>(memory_requirements_chain));
}

//------------------------------------------------------------------------------

/// Determines memory requirements for an image.
[[nodiscard]]
inline auto memory_requirements(fuyu::device_view device, image_handle image)
{
    return memory_requirements(device, image, empty_pnext_chain, empty_pnext_chain);
}

/// Determines memory requirements for an image.
[[nodiscard]]
inline auto memory_requirements(fuyu::image_resource_view image)
{
    return memory_requirements(image.device.get(), image, empty_pnext_chain, empty_pnext_chain);
}

//------------------------------------------------------------------------------

/**
 * Queries the memory requirements for a sparse image.
 * @param image The VkImage object to get the memory requirements for.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetImageSparseMemoryRequirements.html
 */
[[nodiscard]]
inline small_vector<VkSparseImageMemoryRequirements> sparse_memory_requirements(fuyu::device_view device, image_handle image)
{
    // Sanity checks
    {
        fubuki_assert(device->vk10.get_image_sparse_memory_requirements != nullptr, "Internal error. Device functions must be loaded.");
    }

    std::uint32_t count = 0;

    {
        device->vk10.get_image_sparse_memory_requirements(device.handle.vk, image.vk, &count, nullptr);
    }

    small_vector<VkSparseImageMemoryRequirements> result;
    result.resize(count);

    {
        device->vk10.get_image_sparse_memory_requirements(device.handle.vk, image.vk, &count, result.data());
    }

    return result;
}

/**
 * Queries the memory requirements for a sparse image.
 * @param image The VkImage object to get the memory requirements for.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetImageSparseMemoryRequirements.html
 */
[[nodiscard]]
inline small_vector<VkSparseImageMemoryRequirements> sparse_memory_requirements(fuyu::image_resource_view image)
{
    return sparse_memory_requirements(image.device.get(), image.handle);
}

} // namespace fubuki

#endif // FUBUKI_FUYU_MEMORY_REQUIREMENTS_HPP
