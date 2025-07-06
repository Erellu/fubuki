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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN13_FEATURES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN13_FEATURES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_3)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceVulkan13Features& a, const VkPhysicalDeviceVulkan13Features& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.robustImageAccess, b.robustImageAccess)
        and equal(a.inlineUniformBlock, b.inlineUniformBlock)
        and equal(a.descriptorBindingInlineUniformBlockUpdateAfterBind, b.descriptorBindingInlineUniformBlockUpdateAfterBind)
        and equal(a.pipelineCreationCacheControl, b.pipelineCreationCacheControl) and equal(a.privateData, b.privateData)
        and equal(a.shaderDemoteToHelperInvocation, b.shaderDemoteToHelperInvocation)
        and equal(a.shaderTerminateInvocation, b.shaderTerminateInvocation) and equal(a.subgroupSizeControl, b.subgroupSizeControl)
        and equal(a.computeFullSubgroups, b.computeFullSubgroups) and equal(a.synchronization2, b.synchronization2)
        and equal(a.textureCompressionASTC_HDR, b.textureCompressionASTC_HDR)
        and equal(a.shaderZeroInitializeWorkgroupMemory, b.shaderZeroInitializeWorkgroupMemory) and equal(a.dynamicRendering, b.dynamicRendering)
        and equal(a.shaderIntegerDotProduct, b.shaderIntegerDotProduct) and equal(a.maintenance4, b.maintenance4);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceVulkan13Features& a, const VkPhysicalDeviceVulkan13Features& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceVulkan13Features& a, const VkPhysicalDeviceVulkan13Features& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.robustImageAccess, b.robustImageAccess)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.inlineUniformBlock, b.inlineUniformBlock)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.descriptorBindingInlineUniformBlockUpdateAfterBind, b.descriptorBindingInlineUniformBlockUpdateAfterBind));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.pipelineCreationCacheControl, b.pipelineCreationCacheControl));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.privateData, b.privateData)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderDemoteToHelperInvocation, b.shaderDemoteToHelperInvocation));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderTerminateInvocation, b.shaderTerminateInvocation)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.subgroupSizeControl, b.subgroupSizeControl)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.computeFullSubgroups, b.computeFullSubgroups)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.synchronization2, b.synchronization2)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.textureCompressionASTC_HDR, b.textureCompressionASTC_HDR));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderZeroInitializeWorkgroupMemory, b.shaderZeroInitializeWorkgroupMemory));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.dynamicRendering, b.dynamicRendering)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.shaderIntegerDotProduct, b.shaderIntegerDotProduct)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maintenance4, b.maintenance4)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan13Features& a, const VkPhysicalDeviceVulkan13Features& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceVulkan13Features (&a)[N], const VkPhysicalDeviceVulkan13Features (&b)[N]) noexcept
{
    return std::ranges::equal(
        a, b, [](const VkPhysicalDeviceVulkan13Features& x, const VkPhysicalDeviceVulkan13Features& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceVulkan13Features>
{
    using type = decltype(VkPhysicalDeviceVulkan13Features{} <=> VkPhysicalDeviceVulkan13Features{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan13Features& a, const VkPhysicalDeviceVulkan13Features& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceVulkan13Features (&a)[N], const VkPhysicalDeviceVulkan13Features (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a, b, [](const VkPhysicalDeviceVulkan13Features& x, const VkPhysicalDeviceVulkan13Features& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_3)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_VULKAN13_FEATURES_HPP
