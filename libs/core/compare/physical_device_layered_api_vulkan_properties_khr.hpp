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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR_HPP

#include "core/compare/physical_device_limits.hpp"            // IWYU pragma: keep
#include "core/compare/physical_device_properties.hpp"        // IWYU pragma: keep
#include "core/compare/physical_device_properties2.hpp"       // IWYU pragma: keep
#include "core/compare/physical_device_sparse_properties.hpp" // IWYU pragma: keep
#include "core/detail/compare.hpp"                            // IWYU pragma: keep
#include "core/vulkan.hpp"                                    // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_KHR_maintenance7)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& a,
                                               const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext) and equal(a.properties, b.properties);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& a,
                                               const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& a,
                                                const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& b) noexcept
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

    if(const auto cmp = to_ordering<result_type>(three_way(a.properties, b.properties)); cmp != result_type::equivalent)
    {
        return cmp;
    }

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& a, const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR (&a)[N],
                            const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& x,
                                 const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceLayeredApiVulkanPropertiesKHR>
{
    using type = decltype(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR{} <=> VkPhysicalDeviceLayeredApiVulkanPropertiesKHR{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& a,
                                        const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR (&a)[N],
                                        const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(
        a,
        b,
        [](const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& x, const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR& y) constexpr noexcept
        { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_KHR_maintenance7)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR_HPP
