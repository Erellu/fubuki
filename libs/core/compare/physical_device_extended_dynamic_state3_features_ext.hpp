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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE3_FEATURES_EXT_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE3_FEATURES_EXT_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_EXT_extended_dynamic_state3)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& a,
                                               const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext)
        and equal(a.extendedDynamicState3TessellationDomainOrigin, b.extendedDynamicState3TessellationDomainOrigin)
        and equal(a.extendedDynamicState3DepthClampEnable, b.extendedDynamicState3DepthClampEnable)
        and equal(a.extendedDynamicState3PolygonMode, b.extendedDynamicState3PolygonMode)
        and equal(a.extendedDynamicState3RasterizationSamples, b.extendedDynamicState3RasterizationSamples)
        and equal(a.extendedDynamicState3SampleMask, b.extendedDynamicState3SampleMask)
        and equal(a.extendedDynamicState3AlphaToCoverageEnable, b.extendedDynamicState3AlphaToCoverageEnable)
        and equal(a.extendedDynamicState3AlphaToOneEnable, b.extendedDynamicState3AlphaToOneEnable)
        and equal(a.extendedDynamicState3LogicOpEnable, b.extendedDynamicState3LogicOpEnable)
        and equal(a.extendedDynamicState3ColorBlendEnable, b.extendedDynamicState3ColorBlendEnable)
        and equal(a.extendedDynamicState3ColorBlendEquation, b.extendedDynamicState3ColorBlendEquation)
        and equal(a.extendedDynamicState3ColorWriteMask, b.extendedDynamicState3ColorWriteMask)
        and equal(a.extendedDynamicState3RasterizationStream, b.extendedDynamicState3RasterizationStream)
        and equal(a.extendedDynamicState3ConservativeRasterizationMode, b.extendedDynamicState3ConservativeRasterizationMode)
        and equal(a.extendedDynamicState3ExtraPrimitiveOverestimationSize, b.extendedDynamicState3ExtraPrimitiveOverestimationSize)
        and equal(a.extendedDynamicState3DepthClipEnable, b.extendedDynamicState3DepthClipEnable)
        and equal(a.extendedDynamicState3SampleLocationsEnable, b.extendedDynamicState3SampleLocationsEnable)
        and equal(a.extendedDynamicState3ColorBlendAdvanced, b.extendedDynamicState3ColorBlendAdvanced)
        and equal(a.extendedDynamicState3ProvokingVertexMode, b.extendedDynamicState3ProvokingVertexMode)
        and equal(a.extendedDynamicState3LineRasterizationMode, b.extendedDynamicState3LineRasterizationMode)
        and equal(a.extendedDynamicState3LineStippleEnable, b.extendedDynamicState3LineStippleEnable)
        and equal(a.extendedDynamicState3DepthClipNegativeOneToOne, b.extendedDynamicState3DepthClipNegativeOneToOne)
        and equal(a.extendedDynamicState3ViewportWScalingEnable, b.extendedDynamicState3ViewportWScalingEnable)
        and equal(a.extendedDynamicState3ViewportSwizzle, b.extendedDynamicState3ViewportSwizzle)
        and equal(a.extendedDynamicState3CoverageToColorEnable, b.extendedDynamicState3CoverageToColorEnable)
        and equal(a.extendedDynamicState3CoverageToColorLocation, b.extendedDynamicState3CoverageToColorLocation)
        and equal(a.extendedDynamicState3CoverageModulationMode, b.extendedDynamicState3CoverageModulationMode)
        and equal(a.extendedDynamicState3CoverageModulationTableEnable, b.extendedDynamicState3CoverageModulationTableEnable)
        and equal(a.extendedDynamicState3CoverageModulationTable, b.extendedDynamicState3CoverageModulationTable)
        and equal(a.extendedDynamicState3CoverageReductionMode, b.extendedDynamicState3CoverageReductionMode)
        and equal(a.extendedDynamicState3RepresentativeFragmentTestEnable, b.extendedDynamicState3RepresentativeFragmentTestEnable)
        and equal(a.extendedDynamicState3ShadingRateImageEnable, b.extendedDynamicState3ShadingRateImageEnable);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& a,
                                               const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& a,
                                                const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& b) noexcept
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

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3TessellationDomainOrigin, b.extendedDynamicState3TessellationDomainOrigin));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3DepthClampEnable, b.extendedDynamicState3DepthClampEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3PolygonMode, b.extendedDynamicState3PolygonMode));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3RasterizationSamples, b.extendedDynamicState3RasterizationSamples));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3SampleMask, b.extendedDynamicState3SampleMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3AlphaToCoverageEnable, b.extendedDynamicState3AlphaToCoverageEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3AlphaToOneEnable, b.extendedDynamicState3AlphaToOneEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3LogicOpEnable, b.extendedDynamicState3LogicOpEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3ColorBlendEnable, b.extendedDynamicState3ColorBlendEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3ColorBlendEquation, b.extendedDynamicState3ColorBlendEquation));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3ColorWriteMask, b.extendedDynamicState3ColorWriteMask));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3RasterizationStream, b.extendedDynamicState3RasterizationStream));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.extendedDynamicState3ConservativeRasterizationMode, b.extendedDynamicState3ConservativeRasterizationMode));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.extendedDynamicState3ExtraPrimitiveOverestimationSize, b.extendedDynamicState3ExtraPrimitiveOverestimationSize));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3DepthClipEnable, b.extendedDynamicState3DepthClipEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3SampleLocationsEnable, b.extendedDynamicState3SampleLocationsEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3ColorBlendAdvanced, b.extendedDynamicState3ColorBlendAdvanced));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3ProvokingVertexMode, b.extendedDynamicState3ProvokingVertexMode));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3LineRasterizationMode, b.extendedDynamicState3LineRasterizationMode));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3LineStippleEnable, b.extendedDynamicState3LineStippleEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3DepthClipNegativeOneToOne, b.extendedDynamicState3DepthClipNegativeOneToOne));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3ViewportWScalingEnable, b.extendedDynamicState3ViewportWScalingEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(three_way(a.extendedDynamicState3ViewportSwizzle, b.extendedDynamicState3ViewportSwizzle));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3CoverageToColorEnable, b.extendedDynamicState3CoverageToColorEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3CoverageToColorLocation, b.extendedDynamicState3CoverageToColorLocation));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3CoverageModulationMode, b.extendedDynamicState3CoverageModulationMode));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.extendedDynamicState3CoverageModulationTableEnable, b.extendedDynamicState3CoverageModulationTableEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3CoverageModulationTable, b.extendedDynamicState3CoverageModulationTable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3CoverageReductionMode, b.extendedDynamicState3CoverageReductionMode));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp = to_ordering<result_type>(
           three_way(a.extendedDynamicState3RepresentativeFragmentTestEnable, b.extendedDynamicState3RepresentativeFragmentTestEnable));
       cmp != result_type::equivalent)
    {
        return cmp;
    }

    if(const auto cmp
       = to_ordering<result_type>(three_way(a.extendedDynamicState3ShadingRateImageEnable, b.extendedDynamicState3ShadingRateImageEnable));
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
inline constexpr bool equal(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& a,
                            const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT (&a)[N],
                            const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& x,
                                 const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>
{
    using type = decltype(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT{} <=> VkPhysicalDeviceExtendedDynamicState3FeaturesEXT{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& a,
                                        const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT (&a)[N],
                                        const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a,
        b,
        [](const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& x, const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& y) constexpr noexcept
        { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_EXT_extended_dynamic_state3)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE3_FEATURES_EXT_HPP
