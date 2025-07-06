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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN_SC10_PROPERTIES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN_SC10_PROPERTIES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VKSC_VERSION_1_0)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceVulkanSC10Properties& a, const VkPhysicalDeviceVulkanSC10Properties& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.deviceNoDynamicHostAllocations, b.deviceNoDynamicHostAllocations)
        and equal(a.deviceDestroyFreesMemory, b.deviceDestroyFreesMemory)
        and equal(a.commandPoolMultipleCommandBuffersRecording, b.commandPoolMultipleCommandBuffersRecording)
        and equal(a.commandPoolResetCommandBuffer, b.commandPoolResetCommandBuffer)
        and equal(a.commandBufferSimultaneousUse, b.commandBufferSimultaneousUse)
        and equal(a.secondaryCommandBufferNullOrImagelessFramebuffer, b.secondaryCommandBufferNullOrImagelessFramebuffer)
        and equal(a.recycleDescriptorSetMemory, b.recycleDescriptorSetMemory) and equal(a.recyclePipelineMemory, b.recyclePipelineMemory)
        and equal(a.maxRenderPassSubpasses, b.maxRenderPassSubpasses) and equal(a.maxRenderPassDependencies, b.maxRenderPassDependencies)
        and equal(a.maxSubpassInputAttachments, b.maxSubpassInputAttachments)
        and equal(a.maxSubpassPreserveAttachments, b.maxSubpassPreserveAttachments)
        and equal(a.maxFramebufferAttachments, b.maxFramebufferAttachments)
        and equal(a.maxDescriptorSetLayoutBindings, b.maxDescriptorSetLayoutBindings) and equal(a.maxQueryFaultCount, b.maxQueryFaultCount)
        and equal(a.maxCallbackFaultCount, b.maxCallbackFaultCount) and equal(a.maxCommandPoolCommandBuffers, b.maxCommandPoolCommandBuffers)
        and equal(a.maxCommandBufferSize, b.maxCommandBufferSize);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceVulkanSC10Properties& a, const VkPhysicalDeviceVulkanSC10Properties& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceVulkanSC10Properties& a, const VkPhysicalDeviceVulkanSC10Properties& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.deviceNoDynamicHostAllocations, b.deviceNoDynamicHostAllocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.deviceDestroyFreesMemory, b.deviceDestroyFreesMemory)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.commandPoolMultipleCommandBuffersRecording, b.commandPoolMultipleCommandBuffersRecording));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.commandPoolResetCommandBuffer, b.commandPoolResetCommandBuffer));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.commandBufferSimultaneousUse, b.commandBufferSimultaneousUse));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.secondaryCommandBufferNullOrImagelessFramebuffer, b.secondaryCommandBufferNullOrImagelessFramebuffer));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.recycleDescriptorSetMemory, b.recycleDescriptorSetMemory));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.recyclePipelineMemory, b.recyclePipelineMemory)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxRenderPassSubpasses, b.maxRenderPassSubpasses)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxRenderPassDependencies, b.maxRenderPassDependencies)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSubpassInputAttachments, b.maxSubpassInputAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxSubpassPreserveAttachments, b.maxSubpassPreserveAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFramebufferAttachments, b.maxFramebufferAttachments)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxDescriptorSetLayoutBindings, b.maxDescriptorSetLayoutBindings));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxQueryFaultCount, b.maxQueryFaultCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxCallbackFaultCount, b.maxCallbackFaultCount)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxCommandPoolCommandBuffers, b.maxCommandPoolCommandBuffers));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxCommandBufferSize, b.maxCommandBufferSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkanSC10Properties& a, const VkPhysicalDeviceVulkanSC10Properties& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkanSC10Properties (&a)[N], const VkPhysicalDeviceVulkanSC10Properties (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceVulkanSC10Properties& x, const VkPhysicalDeviceVulkanSC10Properties& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceVulkanSC10Properties>
{
    using type = decltype(VkPhysicalDeviceVulkanSC10Properties{} <=> VkPhysicalDeviceVulkanSC10Properties{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkanSC10Properties& a, const VkPhysicalDeviceVulkanSC10Properties& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkanSC10Properties (&a)[N],
                                        const VkPhysicalDeviceVulkanSC10Properties (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a,
        b,
        [](const VkPhysicalDeviceVulkanSC10Properties& x, const VkPhysicalDeviceVulkanSC10Properties& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VKSC_VERSION_1_0)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN_SC10_PROPERTIES_HPP
