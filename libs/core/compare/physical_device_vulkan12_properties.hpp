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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN12_PROPERTIES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN12_PROPERTIES_HPP

#include "core/compare/conformance_version.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"              // IWYU pragma: keep
#include "core/vulkan.hpp"                      // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_2)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceVulkan12Properties& a, const VkPhysicalDeviceVulkan12Properties& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.driverID, b.driverID) and equal(a.driverName, b.driverName)
        and equal(a.driverInfo, b.driverInfo) and equal(a.conformanceVersion, b.conformanceVersion)
        and equal(a.denormBehaviorIndependence, b.denormBehaviorIndependence) and equal(a.roundingModeIndependence, b.roundingModeIndependence)
        and equal(a.shaderSignedZeroInfNanPreserveFloat16, b.shaderSignedZeroInfNanPreserveFloat16)
        and equal(a.shaderSignedZeroInfNanPreserveFloat32, b.shaderSignedZeroInfNanPreserveFloat32)
        and equal(a.shaderSignedZeroInfNanPreserveFloat64, b.shaderSignedZeroInfNanPreserveFloat64)
        and equal(a.shaderDenormPreserveFloat16, b.shaderDenormPreserveFloat16)
        and equal(a.shaderDenormPreserveFloat32, b.shaderDenormPreserveFloat32)
        and equal(a.shaderDenormPreserveFloat64, b.shaderDenormPreserveFloat64)
        and equal(a.shaderDenormFlushToZeroFloat16, b.shaderDenormFlushToZeroFloat16)
        and equal(a.shaderDenormFlushToZeroFloat32, b.shaderDenormFlushToZeroFloat32)
        and equal(a.shaderDenormFlushToZeroFloat64, b.shaderDenormFlushToZeroFloat64)
        and equal(a.shaderRoundingModeRTEFloat16, b.shaderRoundingModeRTEFloat16)
        and equal(a.shaderRoundingModeRTEFloat32, b.shaderRoundingModeRTEFloat32)
        and equal(a.shaderRoundingModeRTEFloat64, b.shaderRoundingModeRTEFloat64)
        and equal(a.shaderRoundingModeRTZFloat16, b.shaderRoundingModeRTZFloat16)
        and equal(a.shaderRoundingModeRTZFloat32, b.shaderRoundingModeRTZFloat32)
        and equal(a.shaderRoundingModeRTZFloat64, b.shaderRoundingModeRTZFloat64)
        and equal(a.maxUpdateAfterBindDescriptorsInAllPools, b.maxUpdateAfterBindDescriptorsInAllPools)
        and equal(a.shaderUniformBufferArrayNonUniformIndexingNative, b.shaderUniformBufferArrayNonUniformIndexingNative)
        and equal(a.shaderSampledImageArrayNonUniformIndexingNative, b.shaderSampledImageArrayNonUniformIndexingNative)
        and equal(a.shaderStorageBufferArrayNonUniformIndexingNative, b.shaderStorageBufferArrayNonUniformIndexingNative)
        and equal(a.shaderStorageImageArrayNonUniformIndexingNative, b.shaderStorageImageArrayNonUniformIndexingNative)
        and equal(a.shaderInputAttachmentArrayNonUniformIndexingNative, b.shaderInputAttachmentArrayNonUniformIndexingNative)
        and equal(a.robustBufferAccessUpdateAfterBind, b.robustBufferAccessUpdateAfterBind)
        and equal(a.quadDivergentImplicitLod, b.quadDivergentImplicitLod)
        and equal(a.maxPerStageDescriptorUpdateAfterBindSamplers, b.maxPerStageDescriptorUpdateAfterBindSamplers)
        and equal(a.maxPerStageDescriptorUpdateAfterBindUniformBuffers, b.maxPerStageDescriptorUpdateAfterBindUniformBuffers)
        and equal(a.maxPerStageDescriptorUpdateAfterBindStorageBuffers, b.maxPerStageDescriptorUpdateAfterBindStorageBuffers)
        and equal(a.maxPerStageDescriptorUpdateAfterBindSampledImages, b.maxPerStageDescriptorUpdateAfterBindSampledImages)
        and equal(a.maxPerStageDescriptorUpdateAfterBindStorageImages, b.maxPerStageDescriptorUpdateAfterBindStorageImages)
        and equal(a.maxPerStageDescriptorUpdateAfterBindInputAttachments, b.maxPerStageDescriptorUpdateAfterBindInputAttachments)
        and equal(a.maxPerStageUpdateAfterBindResources, b.maxPerStageUpdateAfterBindResources)
        and equal(a.maxDescriptorSetUpdateAfterBindSamplers, b.maxDescriptorSetUpdateAfterBindSamplers)
        and equal(a.maxDescriptorSetUpdateAfterBindUniformBuffers, b.maxDescriptorSetUpdateAfterBindUniformBuffers)
        and equal(a.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, b.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic)
        and equal(a.maxDescriptorSetUpdateAfterBindStorageBuffers, b.maxDescriptorSetUpdateAfterBindStorageBuffers)
        and equal(a.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, b.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic)
        and equal(a.maxDescriptorSetUpdateAfterBindSampledImages, b.maxDescriptorSetUpdateAfterBindSampledImages)
        and equal(a.maxDescriptorSetUpdateAfterBindStorageImages, b.maxDescriptorSetUpdateAfterBindStorageImages)
        and equal(a.maxDescriptorSetUpdateAfterBindInputAttachments, b.maxDescriptorSetUpdateAfterBindInputAttachments)
        and equal(a.supportedDepthResolveModes, b.supportedDepthResolveModes)
        and equal(a.supportedStencilResolveModes, b.supportedStencilResolveModes) and equal(a.independentResolveNone, b.independentResolveNone)
        and equal(a.independentResolve, b.independentResolve) and equal(a.filterMinmaxSingleComponentFormats, b.filterMinmaxSingleComponentFormats)
        and equal(a.filterMinmaxImageComponentMapping, b.filterMinmaxImageComponentMapping)
        and equal(a.maxTimelineSemaphoreValueDifference, b.maxTimelineSemaphoreValueDifference)
        and equal(a.framebufferIntegerColorSampleCounts, b.framebufferIntegerColorSampleCounts);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceVulkan12Properties& a, const VkPhysicalDeviceVulkan12Properties& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceVulkan12Properties& a, const VkPhysicalDeviceVulkan12Properties& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.driverID, b.driverID)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.driverName, b.driverName)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.driverInfo, b.driverInfo)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.conformanceVersion, b.conformanceVersion)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.denormBehaviorIndependence, b.denormBehaviorIndependence));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.roundingModeIndependence, b.roundingModeIndependence)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSignedZeroInfNanPreserveFloat16, b.shaderSignedZeroInfNanPreserveFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSignedZeroInfNanPreserveFloat32, b.shaderSignedZeroInfNanPreserveFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSignedZeroInfNanPreserveFloat64, b.shaderSignedZeroInfNanPreserveFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormPreserveFloat16, b.shaderDenormPreserveFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormPreserveFloat32, b.shaderDenormPreserveFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormPreserveFloat64, b.shaderDenormPreserveFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormFlushToZeroFloat16, b.shaderDenormFlushToZeroFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormFlushToZeroFloat32, b.shaderDenormFlushToZeroFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDenormFlushToZeroFloat64, b.shaderDenormFlushToZeroFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTEFloat16, b.shaderRoundingModeRTEFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTEFloat32, b.shaderRoundingModeRTEFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTEFloat64, b.shaderRoundingModeRTEFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTZFloat16, b.shaderRoundingModeRTZFloat16));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTZFloat32, b.shaderRoundingModeRTZFloat32));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderRoundingModeRTZFloat64, b.shaderRoundingModeRTZFloat64));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxUpdateAfterBindDescriptorsInAllPools, b.maxUpdateAfterBindDescriptorsInAllPools));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderUniformBufferArrayNonUniformIndexingNative, b.shaderUniformBufferArrayNonUniformIndexingNative));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderSampledImageArrayNonUniformIndexingNative, b.shaderSampledImageArrayNonUniformIndexingNative));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderStorageBufferArrayNonUniformIndexingNative, b.shaderStorageBufferArrayNonUniformIndexingNative));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderStorageImageArrayNonUniformIndexingNative, b.shaderStorageImageArrayNonUniformIndexingNative));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.shaderInputAttachmentArrayNonUniformIndexingNative, b.shaderInputAttachmentArrayNonUniformIndexingNative));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.robustBufferAccessUpdateAfterBind, b.robustBufferAccessUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.quadDivergentImplicitLod, b.quadDivergentImplicitLod)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxPerStageDescriptorUpdateAfterBindSamplers, b.maxPerStageDescriptorUpdateAfterBindSamplers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxPerStageDescriptorUpdateAfterBindUniformBuffers, b.maxPerStageDescriptorUpdateAfterBindUniformBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxPerStageDescriptorUpdateAfterBindStorageBuffers, b.maxPerStageDescriptorUpdateAfterBindStorageBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxPerStageDescriptorUpdateAfterBindSampledImages, b.maxPerStageDescriptorUpdateAfterBindSampledImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxPerStageDescriptorUpdateAfterBindStorageImages, b.maxPerStageDescriptorUpdateAfterBindStorageImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxPerStageDescriptorUpdateAfterBindInputAttachments, b.maxPerStageDescriptorUpdateAfterBindInputAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxPerStageUpdateAfterBindResources, b.maxPerStageUpdateAfterBindResources));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetUpdateAfterBindSamplers, b.maxDescriptorSetUpdateAfterBindSamplers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxDescriptorSetUpdateAfterBindUniformBuffers, b.maxDescriptorSetUpdateAfterBindUniformBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, b.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxDescriptorSetUpdateAfterBindStorageBuffers, b.maxDescriptorSetUpdateAfterBindStorageBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, b.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxDescriptorSetUpdateAfterBindSampledImages, b.maxDescriptorSetUpdateAfterBindSampledImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxDescriptorSetUpdateAfterBindStorageImages, b.maxDescriptorSetUpdateAfterBindStorageImages));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxDescriptorSetUpdateAfterBindInputAttachments, b.maxDescriptorSetUpdateAfterBindInputAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.supportedDepthResolveModes, b.supportedDepthResolveModes));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.supportedStencilResolveModes, b.supportedStencilResolveModes));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.independentResolveNone, b.independentResolveNone)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.independentResolve, b.independentResolve)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.filterMinmaxSingleComponentFormats, b.filterMinmaxSingleComponentFormats));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.filterMinmaxImageComponentMapping, b.filterMinmaxImageComponentMapping));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxTimelineSemaphoreValueDifference, b.maxTimelineSemaphoreValueDifference));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.framebufferIntegerColorSampleCounts, b.framebufferIntegerColorSampleCounts));
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
inline constexpr bool equal(const VkPhysicalDeviceVulkan12Properties& a, const VkPhysicalDeviceVulkan12Properties& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan12Properties (&a)[N], const VkPhysicalDeviceVulkan12Properties (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceVulkan12Properties& x, const VkPhysicalDeviceVulkan12Properties& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceVulkan12Properties>
{
    using type = decltype(VkPhysicalDeviceVulkan12Properties{} <=> VkPhysicalDeviceVulkan12Properties{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan12Properties& a, const VkPhysicalDeviceVulkan12Properties& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan12Properties (&a)[N], const VkPhysicalDeviceVulkan12Properties (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceVulkan12Properties& x, const VkPhysicalDeviceVulkan12Properties& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_2)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN12_PROPERTIES_HPP
