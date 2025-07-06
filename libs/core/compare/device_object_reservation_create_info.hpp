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

#ifndef FUBUKI_CORE_COMPARE_DEVICE_OBJECT_RESERVATION_CREATE_INFO_HPP
#define FUBUKI_CORE_COMPARE_DEVICE_OBJECT_RESERVATION_CREATE_INFO_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VKSC_VERSION_1_0)

[[nodiscard]] inline constexpr bool operator==(const VkDeviceObjectReservationCreateInfo& a, const VkDeviceObjectReservationCreateInfo& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.pipelineCacheCreateInfoCount, b.pipelineCacheCreateInfoCount)
        and equal(a.pPipelineCacheCreateInfos, b.pPipelineCacheCreateInfos) and equal(a.pipelinePoolSizeCount, b.pipelinePoolSizeCount)
        and equal(a.pPipelinePoolSizes, b.pPipelinePoolSizes) and equal(a.semaphoreRequestCount, b.semaphoreRequestCount)
        and equal(a.commandBufferRequestCount, b.commandBufferRequestCount) and equal(a.fenceRequestCount, b.fenceRequestCount)
        and equal(a.deviceMemoryRequestCount, b.deviceMemoryRequestCount) and equal(a.bufferRequestCount, b.bufferRequestCount)
        and equal(a.imageRequestCount, b.imageRequestCount) and equal(a.eventRequestCount, b.eventRequestCount)
        and equal(a.queryPoolRequestCount, b.queryPoolRequestCount) and equal(a.bufferViewRequestCount, b.bufferViewRequestCount)
        and equal(a.imageViewRequestCount, b.imageViewRequestCount) and equal(a.layeredImageViewRequestCount, b.layeredImageViewRequestCount)
        and equal(a.pipelineCacheRequestCount, b.pipelineCacheRequestCount) and equal(a.pipelineLayoutRequestCount, b.pipelineLayoutRequestCount)
        and equal(a.renderPassRequestCount, b.renderPassRequestCount) and equal(a.graphicsPipelineRequestCount, b.graphicsPipelineRequestCount)
        and equal(a.computePipelineRequestCount, b.computePipelineRequestCount)
        and equal(a.descriptorSetLayoutRequestCount, b.descriptorSetLayoutRequestCount) and equal(a.samplerRequestCount, b.samplerRequestCount)
        and equal(a.descriptorPoolRequestCount, b.descriptorPoolRequestCount) and equal(a.descriptorSetRequestCount, b.descriptorSetRequestCount)
        and equal(a.framebufferRequestCount, b.framebufferRequestCount) and equal(a.commandPoolRequestCount, b.commandPoolRequestCount)
        and equal(a.samplerYcbcrConversionRequestCount, b.samplerYcbcrConversionRequestCount) and equal(a.surfaceRequestCount, b.surfaceRequestCount)
        and equal(a.swapchainRequestCount, b.swapchainRequestCount) and equal(a.displayModeRequestCount, b.displayModeRequestCount)
        and equal(a.subpassDescriptionRequestCount, b.subpassDescriptionRequestCount)
        and equal(a.attachmentDescriptionRequestCount, b.attachmentDescriptionRequestCount)
        and equal(a.descriptorSetLayoutBindingRequestCount, b.descriptorSetLayoutBindingRequestCount)
        and equal(a.descriptorSetLayoutBindingLimit, b.descriptorSetLayoutBindingLimit) and equal(a.maxImageViewMipLevels, b.maxImageViewMipLevels)
        and equal(a.maxImageViewArrayLayers, b.maxImageViewArrayLayers) and equal(a.maxLayeredImageViewMipLevels, b.maxLayeredImageViewMipLevels)
        and equal(a.maxOcclusionQueriesPerPool, b.maxOcclusionQueriesPerPool)
        and equal(a.maxPipelineStatisticsQueriesPerPool, b.maxPipelineStatisticsQueriesPerPool)
        and equal(a.maxTimestampQueriesPerPool, b.maxTimestampQueriesPerPool)
        and equal(a.maxImmutableSamplersPerDescriptorSetLayout, b.maxImmutableSamplersPerDescriptorSetLayout);
}

[[nodiscard]] inline constexpr bool operator!=(const VkDeviceObjectReservationCreateInfo& a, const VkDeviceObjectReservationCreateInfo& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkDeviceObjectReservationCreateInfo& a, const VkDeviceObjectReservationCreateInfo& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineCacheCreateInfoCount, b.pipelineCacheCreateInfoCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pPipelineCacheCreateInfos, b.pPipelineCacheCreateInfos)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelinePoolSizeCount, b.pipelinePoolSizeCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pPipelinePoolSizes, b.pPipelinePoolSizes)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.semaphoreRequestCount, b.semaphoreRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.commandBufferRequestCount, b.commandBufferRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fenceRequestCount, b.fenceRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.deviceMemoryRequestCount, b.deviceMemoryRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferRequestCount, b.bufferRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageRequestCount, b.imageRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.eventRequestCount, b.eventRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.queryPoolRequestCount, b.queryPoolRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferViewRequestCount, b.bufferViewRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imageViewRequestCount, b.imageViewRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.layeredImageViewRequestCount, b.layeredImageViewRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineCacheRequestCount, b.pipelineCacheRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineLayoutRequestCount, b.pipelineLayoutRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.renderPassRequestCount, b.renderPassRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.graphicsPipelineRequestCount, b.graphicsPipelineRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.computePipelineRequestCount, b.computePipelineRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorSetLayoutRequestCount, b.descriptorSetLayoutRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerRequestCount, b.samplerRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorPoolRequestCount, b.descriptorPoolRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorSetRequestCount, b.descriptorSetRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.framebufferRequestCount, b.framebufferRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.commandPoolRequestCount, b.commandPoolRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerYcbcrConversionRequestCount, b.samplerYcbcrConversionRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.surfaceRequestCount, b.surfaceRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.swapchainRequestCount, b.swapchainRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.displayModeRequestCount, b.displayModeRequestCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.subpassDescriptionRequestCount, b.subpassDescriptionRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.attachmentDescriptionRequestCount, b.attachmentDescriptionRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorSetLayoutBindingRequestCount, b.descriptorSetLayoutBindingRequestCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorSetLayoutBindingLimit, b.descriptorSetLayoutBindingLimit));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageViewMipLevels, b.maxImageViewMipLevels)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxImageViewArrayLayers, b.maxImageViewArrayLayers)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxLayeredImageViewMipLevels, b.maxLayeredImageViewMipLevels));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxOcclusionQueriesPerPool, b.maxOcclusionQueriesPerPool));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPipelineStatisticsQueriesPerPool, b.maxPipelineStatisticsQueriesPerPool));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTimestampQueriesPerPool, b.maxTimestampQueriesPerPool));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxImmutableSamplersPerDescriptorSetLayout, b.maxImmutableSamplersPerDescriptorSetLayout));
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
inline constexpr bool equal(const VkDeviceObjectReservationCreateInfo& a, const VkDeviceObjectReservationCreateInfo& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkDeviceObjectReservationCreateInfo (&a)[N], const VkDeviceObjectReservationCreateInfo (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkDeviceObjectReservationCreateInfo& x, const VkDeviceObjectReservationCreateInfo& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkDeviceObjectReservationCreateInfo>
{
    using type = decltype(VkDeviceObjectReservationCreateInfo{} <=> VkDeviceObjectReservationCreateInfo{});
};

template<>
inline constexpr std::int32_t three_way(const VkDeviceObjectReservationCreateInfo& a, const VkDeviceObjectReservationCreateInfo& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkDeviceObjectReservationCreateInfo (&a)[N], const VkDeviceObjectReservationCreateInfo (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkDeviceObjectReservationCreateInfo& x, const VkDeviceObjectReservationCreateInfo& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VKSC_VERSION_1_0)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_DEVICE_OBJECT_RESERVATION_CREATE_INFO_HPP
