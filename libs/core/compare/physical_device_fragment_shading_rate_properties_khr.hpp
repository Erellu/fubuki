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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR_HPP

#include "core/compare/extent2d.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"   // IWYU pragma: keep
#include "core/vulkan.hpp"           // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_fragment_shading_rate)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& a,
                                               const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext)
        and equal(a.minFragmentShadingRateAttachmentTexelSize, b.minFragmentShadingRateAttachmentTexelSize)
        and equal(a.maxFragmentShadingRateAttachmentTexelSize, b.maxFragmentShadingRateAttachmentTexelSize)
        and equal(a.maxFragmentShadingRateAttachmentTexelSizeAspectRatio, b.maxFragmentShadingRateAttachmentTexelSizeAspectRatio)
        and equal(a.primitiveFragmentShadingRateWithMultipleViewports, b.primitiveFragmentShadingRateWithMultipleViewports)
        and equal(a.layeredShadingRateAttachments, b.layeredShadingRateAttachments)
        and equal(a.fragmentShadingRateNonTrivialCombinerOps, b.fragmentShadingRateNonTrivialCombinerOps)
        and equal(a.maxFragmentSize, b.maxFragmentSize) and equal(a.maxFragmentSizeAspectRatio, b.maxFragmentSizeAspectRatio)
        and equal(a.maxFragmentShadingRateCoverageSamples, b.maxFragmentShadingRateCoverageSamples)
        and equal(a.maxFragmentShadingRateRasterizationSamples, b.maxFragmentShadingRateRasterizationSamples)
        and equal(a.fragmentShadingRateWithShaderDepthStencilWrites, b.fragmentShadingRateWithShaderDepthStencilWrites)
        and equal(a.fragmentShadingRateWithSampleMask, b.fragmentShadingRateWithSampleMask)
        and equal(a.fragmentShadingRateWithShaderSampleMask, b.fragmentShadingRateWithShaderSampleMask)
        and equal(a.fragmentShadingRateWithConservativeRasterization, b.fragmentShadingRateWithConservativeRasterization)
        and equal(a.fragmentShadingRateWithFragmentShaderInterlock, b.fragmentShadingRateWithFragmentShaderInterlock)
        and equal(a.fragmentShadingRateWithCustomSampleLocations, b.fragmentShadingRateWithCustomSampleLocations)
        and equal(a.fragmentShadingRateStrictMultiplyCombiner, b.fragmentShadingRateStrictMultiplyCombiner);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& a,
                                               const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& a,
                                                const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.minFragmentShadingRateAttachmentTexelSize, b.minFragmentShadingRateAttachmentTexelSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentShadingRateAttachmentTexelSize, b.maxFragmentShadingRateAttachmentTexelSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.maxFragmentShadingRateAttachmentTexelSizeAspectRatio, b.maxFragmentShadingRateAttachmentTexelSizeAspectRatio));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.primitiveFragmentShadingRateWithMultipleViewports, b.primitiveFragmentShadingRateWithMultipleViewports));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.layeredShadingRateAttachments, b.layeredShadingRateAttachments));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fragmentShadingRateNonTrivialCombinerOps, b.fragmentShadingRateNonTrivialCombinerOps));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentSize, b.maxFragmentSize)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentSizeAspectRatio, b.maxFragmentSizeAspectRatio));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.maxFragmentShadingRateCoverageSamples, b.maxFragmentShadingRateCoverageSamples));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.maxFragmentShadingRateRasterizationSamples, b.maxFragmentShadingRateRasterizationSamples));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.fragmentShadingRateWithShaderDepthStencilWrites, b.fragmentShadingRateWithShaderDepthStencilWrites));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fragmentShadingRateWithSampleMask, b.fragmentShadingRateWithSampleMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fragmentShadingRateWithShaderSampleMask, b.fragmentShadingRateWithShaderSampleMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.fragmentShadingRateWithConservativeRasterization, b.fragmentShadingRateWithConservativeRasterization));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.fragmentShadingRateWithFragmentShaderInterlock, b.fragmentShadingRateWithFragmentShaderInterlock));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.fragmentShadingRateWithCustomSampleLocations, b.fragmentShadingRateWithCustomSampleLocations));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.fragmentShadingRateStrictMultiplyCombiner, b.fragmentShadingRateStrictMultiplyCombiner));
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
inline constexpr bool equal(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& a,
                            const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR (&a)[N],
                            const VkPhysicalDeviceFragmentShadingRatePropertiesKHR (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& x,
                                 const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceFragmentShadingRatePropertiesKHR>
{
    using type = decltype(VkPhysicalDeviceFragmentShadingRatePropertiesKHR{} <=> VkPhysicalDeviceFragmentShadingRatePropertiesKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& a,
                                        const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR (&a)[N],
                                        const VkPhysicalDeviceFragmentShadingRatePropertiesKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a,
        b,
        [](const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& x, const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& y) constexpr noexcept
        { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_fragment_shading_rate)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR_HPP
