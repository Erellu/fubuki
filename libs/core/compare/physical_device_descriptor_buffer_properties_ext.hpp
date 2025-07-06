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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_EXT_descriptor_buffer)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceDescriptorBufferPropertiesEXT& a,
                                               const VkPhysicalDeviceDescriptorBufferPropertiesEXT& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext)
        and equal(a.combinedImageSamplerDescriptorSingleArray, b.combinedImageSamplerDescriptorSingleArray)
        and equal(a.bufferlessPushDescriptors, b.bufferlessPushDescriptors)
        and equal(a.allowSamplerImageViewPostSubmitCreation, b.allowSamplerImageViewPostSubmitCreation)
        and equal(a.descriptorBufferOffsetAlignment, b.descriptorBufferOffsetAlignment)
        and equal(a.maxDescriptorBufferBindings, b.maxDescriptorBufferBindings)
        and equal(a.maxResourceDescriptorBufferBindings, b.maxResourceDescriptorBufferBindings)
        and equal(a.maxSamplerDescriptorBufferBindings, b.maxSamplerDescriptorBufferBindings)
        and equal(a.maxEmbeddedImmutableSamplerBindings, b.maxEmbeddedImmutableSamplerBindings)
        and equal(a.maxEmbeddedImmutableSamplers, b.maxEmbeddedImmutableSamplers)
        and equal(a.bufferCaptureReplayDescriptorDataSize, b.bufferCaptureReplayDescriptorDataSize)
        and equal(a.imageCaptureReplayDescriptorDataSize, b.imageCaptureReplayDescriptorDataSize)
        and equal(a.imageViewCaptureReplayDescriptorDataSize, b.imageViewCaptureReplayDescriptorDataSize)
        and equal(a.samplerCaptureReplayDescriptorDataSize, b.samplerCaptureReplayDescriptorDataSize)
        and equal(a.accelerationStructureCaptureReplayDescriptorDataSize, b.accelerationStructureCaptureReplayDescriptorDataSize)
        and equal(a.samplerDescriptorSize, b.samplerDescriptorSize)
        and equal(a.combinedImageSamplerDescriptorSize, b.combinedImageSamplerDescriptorSize)
        and equal(a.sampledImageDescriptorSize, b.sampledImageDescriptorSize) and equal(a.storageImageDescriptorSize, b.storageImageDescriptorSize)
        and equal(a.uniformTexelBufferDescriptorSize, b.uniformTexelBufferDescriptorSize)
        and equal(a.robustUniformTexelBufferDescriptorSize, b.robustUniformTexelBufferDescriptorSize)
        and equal(a.storageTexelBufferDescriptorSize, b.storageTexelBufferDescriptorSize)
        and equal(a.robustStorageTexelBufferDescriptorSize, b.robustStorageTexelBufferDescriptorSize)
        and equal(a.uniformBufferDescriptorSize, b.uniformBufferDescriptorSize)
        and equal(a.robustUniformBufferDescriptorSize, b.robustUniformBufferDescriptorSize)
        and equal(a.storageBufferDescriptorSize, b.storageBufferDescriptorSize)
        and equal(a.robustStorageBufferDescriptorSize, b.robustStorageBufferDescriptorSize)
        and equal(a.inputAttachmentDescriptorSize, b.inputAttachmentDescriptorSize)
        and equal(a.accelerationStructureDescriptorSize, b.accelerationStructureDescriptorSize)
        and equal(a.maxSamplerDescriptorBufferRange, b.maxSamplerDescriptorBufferRange)
        and equal(a.maxResourceDescriptorBufferRange, b.maxResourceDescriptorBufferRange)
        and equal(a.samplerDescriptorBufferAddressSpaceSize, b.samplerDescriptorBufferAddressSpaceSize)
        and equal(a.resourceDescriptorBufferAddressSpaceSize, b.resourceDescriptorBufferAddressSpaceSize)
        and equal(a.descriptorBufferAddressSpaceSize, b.descriptorBufferAddressSpaceSize);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceDescriptorBufferPropertiesEXT& a,
                                               const VkPhysicalDeviceDescriptorBufferPropertiesEXT& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceDescriptorBufferPropertiesEXT& a,
                                                const VkPhysicalDeviceDescriptorBufferPropertiesEXT& b) noexcept
{
    using result_type = detail::compare::three_way_result_t<decltype(a.sType)>;
    using detail::compare::three_way;
    using detail::compare::to_ordering;

    if(const auto cmp = to_ordering<result_type>(three_way(a.sType, b.sType)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pNext, b.pNext)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.combinedImageSamplerDescriptorSingleArray, b.combinedImageSamplerDescriptorSingleArray));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferlessPushDescriptors, b.bufferlessPushDescriptors)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.allowSamplerImageViewPostSubmitCreation, b.allowSamplerImageViewPostSubmitCreation));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorBufferOffsetAlignment, b.descriptorBufferOffsetAlignment));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorBufferBindings, b.maxDescriptorBufferBindings));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxResourceDescriptorBufferBindings, b.maxResourceDescriptorBufferBindings));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSamplerDescriptorBufferBindings, b.maxSamplerDescriptorBufferBindings));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxEmbeddedImmutableSamplerBindings, b.maxEmbeddedImmutableSamplerBindings));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxEmbeddedImmutableSamplers, b.maxEmbeddedImmutableSamplers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferCaptureReplayDescriptorDataSize, b.bufferCaptureReplayDescriptorDataSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageCaptureReplayDescriptorDataSize, b.imageCaptureReplayDescriptorDataSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageViewCaptureReplayDescriptorDataSize, b.imageViewCaptureReplayDescriptorDataSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerCaptureReplayDescriptorDataSize, b.samplerCaptureReplayDescriptorDataSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.accelerationStructureCaptureReplayDescriptorDataSize, b.accelerationStructureCaptureReplayDescriptorDataSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerDescriptorSize, b.samplerDescriptorSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.combinedImageSamplerDescriptorSize, b.combinedImageSamplerDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.sampledImageDescriptorSize, b.sampledImageDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.storageImageDescriptorSize, b.storageImageDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.uniformTexelBufferDescriptorSize, b.uniformTexelBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.robustUniformTexelBufferDescriptorSize, b.robustUniformTexelBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.storageTexelBufferDescriptorSize, b.storageTexelBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.robustStorageTexelBufferDescriptorSize, b.robustStorageTexelBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.uniformBufferDescriptorSize, b.uniformBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.robustUniformBufferDescriptorSize, b.robustUniformBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.storageBufferDescriptorSize, b.storageBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.robustStorageBufferDescriptorSize, b.robustStorageBufferDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.inputAttachmentDescriptorSize, b.inputAttachmentDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.accelerationStructureDescriptorSize, b.accelerationStructureDescriptorSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSamplerDescriptorBufferRange, b.maxSamplerDescriptorBufferRange));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxResourceDescriptorBufferRange, b.maxResourceDescriptorBufferRange));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerDescriptorBufferAddressSpaceSize, b.samplerDescriptorBufferAddressSpaceSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.resourceDescriptorBufferAddressSpaceSize, b.resourceDescriptorBufferAddressSpaceSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorBufferAddressSpaceSize, b.descriptorBufferAddressSpaceSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceDescriptorBufferPropertiesEXT& a, const VkPhysicalDeviceDescriptorBufferPropertiesEXT& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceDescriptorBufferPropertiesEXT (&a)[N],
                            const VkPhysicalDeviceDescriptorBufferPropertiesEXT (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkPhysicalDeviceDescriptorBufferPropertiesEXT& x,
                                 const VkPhysicalDeviceDescriptorBufferPropertiesEXT& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceDescriptorBufferPropertiesEXT>
{
    using type = decltype(VkPhysicalDeviceDescriptorBufferPropertiesEXT{} <=> VkPhysicalDeviceDescriptorBufferPropertiesEXT{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceDescriptorBufferPropertiesEXT& a,
                                        const VkPhysicalDeviceDescriptorBufferPropertiesEXT& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceDescriptorBufferPropertiesEXT (&a)[N],
                                        const VkPhysicalDeviceDescriptorBufferPropertiesEXT (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a,
        b,
        [](const VkPhysicalDeviceDescriptorBufferPropertiesEXT& x, const VkPhysicalDeviceDescriptorBufferPropertiesEXT& y) constexpr noexcept
        { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_EXT_descriptor_buffer)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT_HPP
