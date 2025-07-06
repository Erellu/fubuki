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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN12_FEATURES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN12_FEATURES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_2)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceVulkan12Features& a, const VkPhysicalDeviceVulkan12Features& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.samplerMirrorClampToEdge, b.samplerMirrorClampToEdge)
        and equal(a.drawIndirectCount, b.drawIndirectCount) and equal(a.storageBuffer8BitAccess, b.storageBuffer8BitAccess)
        and equal(a.uniformAndStorageBuffer8BitAccess, b.uniformAndStorageBuffer8BitAccess) and equal(a.storagePushConstant8, b.storagePushConstant8)
        and equal(a.shaderBufferInt64Atomics, b.shaderBufferInt64Atomics) and equal(a.shaderSharedInt64Atomics, b.shaderSharedInt64Atomics)
        and equal(a.shaderFloat16, b.shaderFloat16) and equal(a.shaderInt8, b.shaderInt8) and equal(a.descriptorIndexing, b.descriptorIndexing)
        and equal(a.shaderInputAttachmentArrayDynamicIndexing, b.shaderInputAttachmentArrayDynamicIndexing)
        and equal(a.shaderUniformTexelBufferArrayDynamicIndexing, b.shaderUniformTexelBufferArrayDynamicIndexing)
        and equal(a.shaderStorageTexelBufferArrayDynamicIndexing, b.shaderStorageTexelBufferArrayDynamicIndexing)
        and equal(a.shaderUniformBufferArrayNonUniformIndexing, b.shaderUniformBufferArrayNonUniformIndexing)
        and equal(a.shaderSampledImageArrayNonUniformIndexing, b.shaderSampledImageArrayNonUniformIndexing)
        and equal(a.shaderStorageBufferArrayNonUniformIndexing, b.shaderStorageBufferArrayNonUniformIndexing)
        and equal(a.shaderStorageImageArrayNonUniformIndexing, b.shaderStorageImageArrayNonUniformIndexing)
        and equal(a.shaderInputAttachmentArrayNonUniformIndexing, b.shaderInputAttachmentArrayNonUniformIndexing)
        and equal(a.shaderUniformTexelBufferArrayNonUniformIndexing, b.shaderUniformTexelBufferArrayNonUniformIndexing)
        and equal(a.shaderStorageTexelBufferArrayNonUniformIndexing, b.shaderStorageTexelBufferArrayNonUniformIndexing)
        and equal(a.descriptorBindingUniformBufferUpdateAfterBind, b.descriptorBindingUniformBufferUpdateAfterBind)
        and equal(a.descriptorBindingSampledImageUpdateAfterBind, b.descriptorBindingSampledImageUpdateAfterBind)
        and equal(a.descriptorBindingStorageImageUpdateAfterBind, b.descriptorBindingStorageImageUpdateAfterBind)
        and equal(a.descriptorBindingStorageBufferUpdateAfterBind, b.descriptorBindingStorageBufferUpdateAfterBind)
        and equal(a.descriptorBindingUniformTexelBufferUpdateAfterBind, b.descriptorBindingUniformTexelBufferUpdateAfterBind)
        and equal(a.descriptorBindingStorageTexelBufferUpdateAfterBind, b.descriptorBindingStorageTexelBufferUpdateAfterBind)
        and equal(a.descriptorBindingUpdateUnusedWhilePending, b.descriptorBindingUpdateUnusedWhilePending)
        and equal(a.descriptorBindingPartiallyBound, b.descriptorBindingPartiallyBound)
        and equal(a.descriptorBindingVariableDescriptorCount, b.descriptorBindingVariableDescriptorCount)
        and equal(a.runtimeDescriptorArray, b.runtimeDescriptorArray) and equal(a.samplerFilterMinmax, b.samplerFilterMinmax)
        and equal(a.scalarBlockLayout, b.scalarBlockLayout) and equal(a.imagelessFramebuffer, b.imagelessFramebuffer)
        and equal(a.uniformBufferStandardLayout, b.uniformBufferStandardLayout)
        and equal(a.shaderSubgroupExtendedTypes, b.shaderSubgroupExtendedTypes)
        and equal(a.separateDepthStencilLayouts, b.separateDepthStencilLayouts) and equal(a.hostQueryReset, b.hostQueryReset)
        and equal(a.timelineSemaphore, b.timelineSemaphore) and equal(a.bufferDeviceAddress, b.bufferDeviceAddress)
        and equal(a.bufferDeviceAddressCaptureReplay, b.bufferDeviceAddressCaptureReplay)
        and equal(a.bufferDeviceAddressMultiDevice, b.bufferDeviceAddressMultiDevice) and equal(a.vulkanMemoryModel, b.vulkanMemoryModel)
        and equal(a.vulkanMemoryModelDeviceScope, b.vulkanMemoryModelDeviceScope)
        and equal(a.vulkanMemoryModelAvailabilityVisibilityChains, b.vulkanMemoryModelAvailabilityVisibilityChains)
        and equal(a.shaderOutputViewportIndex, b.shaderOutputViewportIndex) and equal(a.shaderOutputLayer, b.shaderOutputLayer)
        and equal(a.subgroupBroadcastDynamicId, b.subgroupBroadcastDynamicId);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceVulkan12Features& a, const VkPhysicalDeviceVulkan12Features& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceVulkan12Features& a, const VkPhysicalDeviceVulkan12Features& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerMirrorClampToEdge, b.samplerMirrorClampToEdge)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.drawIndirectCount, b.drawIndirectCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.storageBuffer8BitAccess, b.storageBuffer8BitAccess)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.uniformAndStorageBuffer8BitAccess, b.uniformAndStorageBuffer8BitAccess));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.storagePushConstant8, b.storagePushConstant8)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderBufferInt64Atomics, b.shaderBufferInt64Atomics)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSharedInt64Atomics, b.shaderSharedInt64Atomics)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderFloat16, b.shaderFloat16)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderInt8, b.shaderInt8)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorIndexing, b.descriptorIndexing)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderInputAttachmentArrayDynamicIndexing, b.shaderInputAttachmentArrayDynamicIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderUniformTexelBufferArrayDynamicIndexing, b.shaderUniformTexelBufferArrayDynamicIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderStorageTexelBufferArrayDynamicIndexing, b.shaderStorageTexelBufferArrayDynamicIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderUniformBufferArrayNonUniformIndexing, b.shaderUniformBufferArrayNonUniformIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSampledImageArrayNonUniformIndexing, b.shaderSampledImageArrayNonUniformIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderStorageBufferArrayNonUniformIndexing, b.shaderStorageBufferArrayNonUniformIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderStorageImageArrayNonUniformIndexing, b.shaderStorageImageArrayNonUniformIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderInputAttachmentArrayNonUniformIndexing, b.shaderInputAttachmentArrayNonUniformIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderUniformTexelBufferArrayNonUniformIndexing, b.shaderUniformTexelBufferArrayNonUniformIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.shaderStorageTexelBufferArrayNonUniformIndexing, b.shaderStorageTexelBufferArrayNonUniformIndexing));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.descriptorBindingUniformBufferUpdateAfterBind, b.descriptorBindingUniformBufferUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.descriptorBindingSampledImageUpdateAfterBind, b.descriptorBindingSampledImageUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.descriptorBindingStorageImageUpdateAfterBind, b.descriptorBindingStorageImageUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.descriptorBindingStorageBufferUpdateAfterBind, b.descriptorBindingStorageBufferUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.descriptorBindingUniformTexelBufferUpdateAfterBind, b.descriptorBindingUniformTexelBufferUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.descriptorBindingStorageTexelBufferUpdateAfterBind, b.descriptorBindingStorageTexelBufferUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorBindingUpdateUnusedWhilePending, b.descriptorBindingUpdateUnusedWhilePending));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorBindingPartiallyBound, b.descriptorBindingPartiallyBound));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.descriptorBindingVariableDescriptorCount, b.descriptorBindingVariableDescriptorCount));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.runtimeDescriptorArray, b.runtimeDescriptorArray)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.samplerFilterMinmax, b.samplerFilterMinmax)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.scalarBlockLayout, b.scalarBlockLayout)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.imagelessFramebuffer, b.imagelessFramebuffer)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.uniformBufferStandardLayout, b.uniformBufferStandardLayout));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderSubgroupExtendedTypes, b.shaderSubgroupExtendedTypes));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.separateDepthStencilLayouts, b.separateDepthStencilLayouts));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.hostQueryReset, b.hostQueryReset)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.timelineSemaphore, b.timelineSemaphore)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferDeviceAddress, b.bufferDeviceAddress)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferDeviceAddressCaptureReplay, b.bufferDeviceAddressCaptureReplay));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.bufferDeviceAddressMultiDevice, b.bufferDeviceAddressMultiDevice));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vulkanMemoryModel, b.vulkanMemoryModel)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.vulkanMemoryModelDeviceScope, b.vulkanMemoryModelDeviceScope));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.vulkanMemoryModelAvailabilityVisibilityChains, b.vulkanMemoryModelAvailabilityVisibilityChains));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderOutputViewportIndex, b.shaderOutputViewportIndex)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderOutputLayer, b.shaderOutputLayer)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.subgroupBroadcastDynamicId, b.subgroupBroadcastDynamicId));
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
inline constexpr bool equal(const VkPhysicalDeviceVulkan12Features& a, const VkPhysicalDeviceVulkan12Features& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan12Features (&a)[N], const VkPhysicalDeviceVulkan12Features (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceVulkan12Features& x, const VkPhysicalDeviceVulkan12Features& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceVulkan12Features>
{
    using type = decltype(VkPhysicalDeviceVulkan12Features{} <=> VkPhysicalDeviceVulkan12Features{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan12Features& a, const VkPhysicalDeviceVulkan12Features& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan12Features (&a)[N], const VkPhysicalDeviceVulkan12Features (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceVulkan12Features& x, const VkPhysicalDeviceVulkan12Features& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_2)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN12_FEATURES_HPP
