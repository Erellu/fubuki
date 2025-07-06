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

#ifndef FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_HPP
#define FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_HPP

#include "core/detail/compare.hpp" // IWYU pragma: keep
#include "core/vulkan.hpp"         // IWYU pragma: keep

namespace fubuki
{

#if defined(VK_VERSION_1_2)

[[nodiscard]] inline constexpr bool operator==(const VkPhysicalDeviceDescriptorIndexingFeatures& a,
                                               const VkPhysicalDeviceDescriptorIndexingFeatures& b) noexcept
{
    using detail::compare::equal;
    return equal(a.sType, b.sType) and equal(a.pNext, b.pNext)
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
        and equal(a.runtimeDescriptorArray, b.runtimeDescriptorArray);
}

[[nodiscard]] inline constexpr bool operator!=(const VkPhysicalDeviceDescriptorIndexingFeatures& a,
                                               const VkPhysicalDeviceDescriptorIndexingFeatures& b) noexcept
{
    return not(a == b);
}

[[nodiscard]] inline constexpr auto operator<=>(const VkPhysicalDeviceDescriptorIndexingFeatures& a,
                                                const VkPhysicalDeviceDescriptorIndexingFeatures& b) noexcept
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

    return result_type::equivalent;
}

namespace detail::compare
{

template<>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceDescriptorIndexingFeatures& a, const VkPhysicalDeviceDescriptorIndexingFeatures& b) noexcept
{
    return a == b;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr bool equal(const VkPhysicalDeviceDescriptorIndexingFeatures (&a)[N],
                            const VkPhysicalDeviceDescriptorIndexingFeatures (&b)[N]) noexcept
{
    return std::ranges::equal(a,
                              b,
                              [](const VkPhysicalDeviceDescriptorIndexingFeatures& x,
                                 const VkPhysicalDeviceDescriptorIndexingFeatures& y) constexpr noexcept { return x == y; });
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

template<>
struct three_way_result<VkPhysicalDeviceDescriptorIndexingFeatures>
{
    using type = decltype(VkPhysicalDeviceDescriptorIndexingFeatures{} <=> VkPhysicalDeviceDescriptorIndexingFeatures{});
};

template<>
inline constexpr std::int32_t three_way(const VkPhysicalDeviceDescriptorIndexingFeatures& a,
                                        const VkPhysicalDeviceDescriptorIndexingFeatures& b) noexcept
{
    return to_int(a <=> b);
};

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
template<std::size_t N>
[[nodiscard]]
inline constexpr std::int32_t three_way(const VkPhysicalDeviceDescriptorIndexingFeatures (&a)[N],
                                        const VkPhysicalDeviceDescriptorIndexingFeatures (&b)[N]) noexcept
{
    return to_int(lexicographical_compare_three_way(a,
                                                    b,
                                                    [](const VkPhysicalDeviceDescriptorIndexingFeatures& x,
                                                       const VkPhysicalDeviceDescriptorIndexingFeatures& y) constexpr noexcept { return x <=> y; }));
};
// NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

} // namespace detail::compare

#endif // if defined(VK_VERSION_1_2)

} // namespace fubuki

#endif // FUBUKI_CORE_COMPARE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_HPP
