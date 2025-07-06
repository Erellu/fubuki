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

#ifndef FUBUKI_FUYU_FUNCTIONS_IMAGE_HPP
#define FUBUKI_FUYU_FUNCTIONS_IMAGE_HPP

#include <core/as_span.hpp>
#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/image.hpp"
#include "fuyu/views/image.hpp"
#include "fuyu/views/memory.hpp"

namespace fubuki::fuyu
{

namespace detail
{

#if defined(VK_VERSION_1_1)
[[nodiscard]] FUBUKI_FUYU_API std::expected<bound_image_view, api_call_info>
                              bind(fuyu::image_resource_view image, fuyu::memory_view memory, const VkBindImageMemoryInfo& info) noexcept;
#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_4)
/**
 * Retrieve information about an image subresource without an image object
 * @param device The device that owns the image.
 * @param subresource A specific image subresource from the image to query.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetDeviceImageSubresourceLayout.html
 */
FUBUKI_FUYU_API void
device_subresource_layout(device_cref device, const VkDeviceImageSubresourceInfo& subresource, VkSubresourceLayout2& result) noexcept;

/**
 * Retrieve information about an image subresource.
 * @param image The image whose layout is being queried.
 * @param subresource A specific image subresource from the image to query.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetImageSubresourceLayout2.html
 */
FUBUKI_FUYU_API void
subresource_layout(fuyu::image_resource_view image, const VkImageSubresource2& subresource, VkSubresourceLayout2& result) noexcept;

/**
 * Perform an image layout transition on the host.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkTransitionImageLayout.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> transition(device_cref                                      device,
                                                                            std::span<const VkHostImageLayoutTransitionInfo> info) noexcept;

/**
 * Copy data from host memory into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMemoryToImage.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> copy(device_cref device, const VkCopyMemoryToImageInfo& info) noexcept;

/**
 * Copy data from host memory into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToMemory.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> copy(device_cref device, const VkCopyImageToMemoryInfo& info) noexcept;

/**
 * Copy image data using the host.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToImage .html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> copy(device_cref device, const VkCopyImageToImageInfo& info) noexcept;

#endif // defined(VK_VERSION_1_4)

} // namespace detail

/**
 * Bind an image to memory.
 * @param image Image to bind.
 * @param memory Memory to bind to.
 * @param memory_offset Offset from memory begin, in bytes. Defaults to 0.

 * @pre The image must not be bound yet.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBindImageMemory.html
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<bound_image_view, api_call_info>
                              bind(fuyu::image_resource_view image, fuyu::memory_view memory, VkDeviceSize memory_offset = 0) noexcept;

/**
 * Retrieve information about an image subresource.
 * @param image The image whose layout is being queried.
 * @param subresource A specific image subresource from the image to query.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetImageSubresourceLayout.html
 */
[[nodiscard]] FUBUKI_FUYU_API VkSubresourceLayout subresource_layout(fuyu::image_resource_view image, const VkImageSubresource& subresource) noexcept;

#if defined(VK_VERSION_1_1)
/**
 * Bind an image to memory.
 * @param image Image to bind.
 * @param memory Memory to bind to.
 * @param memory_offset Offset from memory begin, in bytes.
 * @param pnext Chain extending VkBindImageMemoryInfo.

 * @pre The image must not be bound yet.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkBindImageMemory2.html
 */
template<typename... elements>
[[nodiscard]] inline std::expected<bound_image_view, api_call_info>
bind(fuyu::image_resource_view image, fuyu::memory_view memory, VkDeviceSize memory_offset, const pnext_chain<elements...>& pnext) noexcept
{
    VkBindImageMemoryInfo vk_info{
        .sType        = structure_type_v<VkBindImageMemoryInfo>,
        .pNext        = {},
        .image        = image.handle.vk,
        .memory       = memory.handle.vk,
        .memoryOffset = memory_offset,
    };

    fubuki::extend(vk_info, pnext);

    // TODO: support ranges
    return detail::bind(image, memory, vk_info);
}

#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_4)

/**
 * Perform an image layout transition on the host.
 * @param device The device that owns images participating to the transition.
 * @param transitions The transitions to perform.
 */
[[nodiscard]] inline std::expected<void, api_call_info> transition(device_cref                                      device,
                                                                   std::span<const VkHostImageLayoutTransitionInfo> transitions) noexcept
{
    return detail::transition(device, transitions);
}

/**
 * Perform an image layout transition on the host.
 * @param device The device that owns images participating to the transition.
 * @param transitions The transitions to perform.
 */
[[nodiscard]] inline std::expected<void, api_call_info> transition(device_cref                                            device,
                                                                   std::initializer_list<VkHostImageLayoutTransitionInfo> transitions) noexcept
{
    return detail::transition(device, std::span{transitions});
}

/**
 * Perform an image layout transition on the host for a single image.
 * @param image The image to transition.
 * @param before The layout the image is currently in.
 * @param after The layout the image will be.
 * @param range The subresource range affected by this transition.
 * @param pnext Chain extending VkHostImageLayoutTransitionInfo.
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> transition(image_resource_view             image,
                                                                   VkImageLayout                   before,
                                                                   VkImageLayout                   after,
                                                                   const VkImageSubresourceRange&  range,
                                                                   const pnext_chain<elements...>& pnext) noexcept
{
    VkHostImageLayoutTransitionInfo vk_info{
        .sType            = structure_type_v<VkHostImageLayoutTransitionInfo>,
        .pNext            = {},
        .image            = image.handle.vk,
        .oldLayout        = before,
        .newLayout        = after,
        .subresourceRange = range,
    };

    fubuki::extend(vk_info, pnext);

    return detail::transition(image.device, fubuki::as_span(vk_info));
}

/**
 * Perform an image layout transition on the host for a single image.
 * @param image The image to transition
 * @param before The layout the image is currently in.
 * @param after The layout the image will be.
 * @param range The subresource range affected by this transition.
 */
[[nodiscard]] inline std::expected<void, api_call_info>
transition(image_resource_view image, VkImageLayout before, VkImageLayout after, const VkImageSubresourceRange& range) noexcept
{
    return transition(image, before, after, range, empty_pnext_chain);
}

/**
 * Retrieve information about an image subresource.
 * @param image The image whose layout is being queried.
 * @param subresource A specific image subresource from the image to query.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetImageSubresourceLayout2.html
 */
template<typename... subresource_elements, typename... result_elements>
[[nodiscard]] inline VkSubresourceLayout2 subresource_layout(fuyu::image_resource_view                   image,
                                                             const VkImageSubresource&                   subresource,
                                                             const pnext_chain<subresource_elements...>& subresources_pnext,
                                                             const pnext_chain<result_elements...>&      result_pnext) noexcept
{

    auto vk_info             = fubuki::make<VkImageSubresource2>();
    vk_info.imageSubresource = subresource;
    fubuki::extend(vk_info, subresources_pnext);

    auto result = fubuki::make<VkSubresourceLayout2>();
    fubuki::extend(result, result_pnext);

    detail::subresource_layout(image, vk_info, result);

    return result;
}

/**
 * Retrieve information about an image subresource.
 * @param image The image whose layout is being queried.
 * @param subresource A specific image subresource from the image to query.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetImageSubresourceLayout2.html
 */
template<typename... result_elements>
[[nodiscard]] inline VkSubresourceLayout2 subresource_layout(fuyu::image_resource_view              image,
                                                             const VkImageSubresource&              subresource,
                                                             const pnext_chain<result_elements...>& result_pnext) noexcept
{
    auto vk_info             = fubuki::make<VkImageSubresource2>();
    vk_info.imageSubresource = subresource;

    auto result = fubuki::make<VkSubresourceLayout2>();
    fubuki::extend(result, result_pnext);

    detail::subresource_layout(image, vk_info, result);

    return result;
}

/**
 * Retrieve information about an image subresource without an image.
 * @param device The device that owns the image.
 * @param image The image whose layout is being queried.
 * @param subresource A specific image subresource from the image to query.
 * @param subresource_pnext Chain extending VkDeviceImageSubresourceInfo.
 * @param result_pnext Chain extending VkSubresourceLayout2.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetDeviceImageSubresourceLayout.html
 */
template<typename... subresource_elements, typename... result_elements>
[[nodiscard]] inline VkSubresourceLayout2 device_subresource_layout(device_cref                                 device,
                                                                    const fuyu::information::image&             image,
                                                                    const VkImageSubresource&                   subresource,
                                                                    const pnext_chain<subresource_elements...>& subresource_pnext,
                                                                    const pnext_chain<result_elements...>&      result_pnext) noexcept
{
    const auto                vk_image_info = to_underlying(image);
    const VkImageSubresource2 subresource_2 = {.sType = structure_type_v<VkImageSubresource2>, .pNext = {}, .imageSubresource = subresource};

    auto vk_info         = fubuki::make<VkDeviceImageSubresourceInfo>();
    vk_info.pCreateInfo  = std::addressof(vk_image_info);
    vk_info.pSubresource = std::addressof(subresource_2);
    fubuki::extend(vk_info, subresource_pnext);

    auto result = fubuki::make<VkSubresourceLayout2>();
    fubuki::extend(result, result_pnext);

    detail::device_subresource_layout(device, vk_info, result);

    return result;
}

/**
 * Retrieve information about an image subresource without an image.
 * @param device The device that owns the image.
 * @param image The image whose layout is being queried.
 * @param subresource A specific image subresource from the image to query.
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkGetDeviceImageSubresourceLayout.html
 */
[[nodiscard]] inline VkSubresourceLayout2
device_subresource_layout(device_cref device, const fuyu::information::image& image, const VkImageSubresource& subresource) noexcept
{
    return device_subresource_layout(device, image, subresource, empty_pnext_chain, empty_pnext_chain);
}

/**
 * Copy data from host memory into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMemoryToImage.html
 * @param destination The destination image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 * @param pnext Chain extending VkCopyMemoryToImageInfo.
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view                  destination,
                                                             VkImageLayout                        layout,
                                                             std::span<const VkMemoryToImageCopy> regions,
                                                             VkHostImageCopyFlags                 flags,
                                                             const pnext_chain<elements...>&      pnext) noexcept
{
    VkCopyMemoryToImageInfo vk_info{
        .sType          = structure_type_v<VkCopyMemoryToImageInfo>,
        .pNext          = {},
        .flags          = flags,
        .dstImage       = destination.handle.vk,
        .dstImageLayout = layout,
        .regionCount    = vk_size(regions),
        .pRegions       = regions.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::copy(destination.device, vk_info);
}

/**
 * Copy data from host memory into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMemoryToImage.html
 * @param destination The destination image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 * @param pnext Chain extending VkCopyMemoryToImageInfo.
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view                        destination,
                                                             VkImageLayout                              layout,
                                                             std::initializer_list<VkMemoryToImageCopy> regions,
                                                             VkHostImageCopyFlags                       flags,
                                                             const pnext_chain<elements...>&            pnext) noexcept
{
    return copy(destination, layout, std::span{regions}, flags, pnext);
}

/**
 * Copy data from host memory into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMemoryToImage.html
 * @param destination The destination image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 */
[[nodiscard]] inline std::expected<void, api_call_info>
copy(image_resource_view destination, VkImageLayout layout, std::span<const VkMemoryToImageCopy> regions, VkHostImageCopyFlags flags = {}) noexcept
{
    return copy(destination, layout, regions, flags, empty_pnext_chain);
}

/**
 * Copy data from host memory into an image.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyMemoryToImage.html
 * @param destination The destination image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 */
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view                        destination,
                                                             VkImageLayout                              layout,
                                                             std::initializer_list<VkMemoryToImageCopy> regions,
                                                             VkHostImageCopyFlags                       flags = {}) noexcept
{
    return copy(destination, layout, std::span{regions}, flags, empty_pnext_chain);
}

/**
 * Copy image data into host memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToMemory.html
 * @param source The source image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 * @param pnext Chain extending VkCopyImageToMemoryInfo .
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view                  source,
                                                             VkImageLayout                        layout,
                                                             std::span<const VkImageToMemoryCopy> regions,
                                                             VkHostImageCopyFlags                 flags,
                                                             const pnext_chain<elements...>&      pnext) noexcept
{
    VkCopyImageToMemoryInfo vk_info{
        .sType          = structure_type_v<VkCopyImageToMemoryInfo>,
        .pNext          = {},
        .flags          = flags,
        .srcImage       = source.handle.vk,
        .srcImageLayout = layout,
        .regionCount    = vk_size(regions),
        .pRegions       = regions.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::copy(source.device, vk_info);
}

/**
 * Copy image data into host memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToMemory.html
 * @param source The source image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 * @param pnext Chain extending VkCopyImageToMemoryInfo .
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view                        source,
                                                             VkImageLayout                              layout,
                                                             std::initializer_list<VkImageToMemoryCopy> regions,
                                                             VkHostImageCopyFlags                       flags,
                                                             const pnext_chain<elements...>&            pnext) noexcept
{
    return copy(source, layout, std::span{regions}, flags, pnext);
}

/**
 * Copy image data into host memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToMemory.html
 * @param source The source image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 */
[[nodiscard]] inline std::expected<void, api_call_info>
copy(image_resource_view source, VkImageLayout layout, std::span<const VkImageToMemoryCopy> regions, VkHostImageCopyFlags flags = {}) noexcept
{
    return copy(source, layout, regions, flags, empty_pnext_chain);
}

/**
 * Copy image data into host memory.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToMemory.html
 * @param source The source image.
 * @param layout The layout the image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 */
[[nodiscard]] inline std::expected<void, api_call_info>
copy(image_resource_view source, VkImageLayout layout, std::initializer_list<VkImageToMemoryCopy> regions, VkHostImageCopyFlags flags = {}) noexcept
{
    return copy(source, layout, std::span{regions}, flags, empty_pnext_chain);
}

/**
 * Copy image data using the host
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToImage.html
 * @param source The source image.
 * @param source_layout The layout the source image is currently in.
 * @param destination The destination image.
 * @param destination_layout The layout the destination image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 * @param pnext Chain extending VkCopyImageToImageInfo.
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view             source,
                                                             VkImageLayout                   source_layout,
                                                             image_resource_view             destination,
                                                             VkImageLayout                   destination_layout,
                                                             std::span<const VkImageCopy2>   regions,
                                                             VkHostImageCopyFlags            flags,
                                                             const pnext_chain<elements...>& pnext) noexcept
{
    VkCopyImageToImageInfo vk_info{
        .sType          = structure_type_v<VkCopyImageToImageInfo>,
        .pNext          = {},
        .flags          = flags,
        .srcImage       = source.handle.vk,
        .srcImageLayout = source_layout,
        .dstImage       = destination.handle.vk,
        .dstImageLayout = destination_layout,
        .regionCount    = vk_size(regions),
        .pRegions       = regions.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::copy(source.device, vk_info);
}

/**
 * Copy image data using the host
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToImage.html
 * @param source The source image.
 * @param source_layout The layout the source image is currently in.
 * @param destination The destination image.
 * @param destination_layout The layout the destination image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 * @param pnext Chain extending VkCopyImageToImageInfo.
 */
template<typename... elements>
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view                 source,
                                                             VkImageLayout                       source_layout,
                                                             image_resource_view                 destination,
                                                             VkImageLayout                       destination_layout,
                                                             std::initializer_list<VkImageCopy2> regions,
                                                             VkHostImageCopyFlags                flags,
                                                             const pnext_chain<elements...>&     pnext) noexcept
{
    return copy(source, source_layout, destination, destination_layout, std::span{regions}, flags, pnext);
}

/**
 * Copy image data using the host
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToImage.html
 * @param source The source image.
 * @param source_layout The layout the source image is currently in.
 * @param destination The destination image.
 * @param destination_layout The layout the destination image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 */
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view           source,
                                                             VkImageLayout                 source_layout,
                                                             image_resource_view           destination,
                                                             VkImageLayout                 destination_layout,
                                                             std::span<const VkImageCopy2> regions,
                                                             VkHostImageCopyFlags          flags = {}) noexcept
{
    return copy(source, source_layout, destination, destination_layout, std::span{regions}, flags, empty_pnext_chain);
}

/**
 * Copy image data using the host
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCopyImageToImage.html
 * @param source The source image.
 * @param source_layout The layout the source image is currently in.
 * @param destination The destination image.
 * @param destination_layout The layout the destination image is currently in.
 * @param regions The regions to copy.
 * @param flags A bitmask of VkHostImageCopyFlagBits values describing additional copy parameters.
 */
[[nodiscard]] inline std::expected<void, api_call_info> copy(image_resource_view                 source,
                                                             VkImageLayout                       source_layout,
                                                             image_resource_view                 destination,
                                                             VkImageLayout                       destination_layout,
                                                             std::initializer_list<VkImageCopy2> regions,
                                                             VkHostImageCopyFlags                flags = {}) noexcept
{
    return copy(source, source_layout, destination, destination_layout, std::span{regions}, flags, empty_pnext_chain);
}
#endif // defined(VK_VERSION_1_4)

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_IMAGE_HPP
