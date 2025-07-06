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

#ifndef FUBUKI_FUYU_FUNCTIONS_DESCRIPTOR_SET_HPP
#define FUBUKI_FUYU_FUNCTIONS_DESCRIPTOR_SET_HPP

#include <initializer_list>
#include <span>

#include <core/as_span.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/descriptor_set_array.hpp"
#include "fuyu/views/device.hpp"

namespace fubuki::fuyu
{

namespace detail
{
#if defined(VK_VERSION_1_1)

/**
 *  Update the contents of a descriptor set object using an update template.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSetWithTemplateKHR.html
 */
FUBUKI_FUYU_API
void update(descriptor_set_view set, descriptor_update_template_handle update_template, const void* data) noexcept;

#endif // defined(VK_VERSION_1_1)

} // namespace detail

/**
 * Update the contents of a descriptor set object.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSets.html
 */
FUBUKI_FUYU_API
void update(device_view device, std::span<const VkWriteDescriptorSet> writes, std::span<const VkCopyDescriptorSet> copies) noexcept;

/**
 * Update the contents of a descriptor set object.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSets.html
 */
inline void update(device_view device, std::initializer_list<VkWriteDescriptorSet> writes, std::span<const VkCopyDescriptorSet> copies) noexcept
{
    return update(device, std::span{writes}, std::span{copies});
}

/**
 * Update the contents of a descriptor set object.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSets.html
 */
inline void update(device_view device, std::span<const VkWriteDescriptorSet> writes, std::initializer_list<VkCopyDescriptorSet> copies) noexcept
{
    return update(device, std::span{writes}, std::span{copies});
}

/**
 * Update the contents of a descriptor set object.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSets.html
 */
inline void update(device_view device, std::initializer_list<VkWriteDescriptorSet> writes, std::initializer_list<VkCopyDescriptorSet> copies) noexcept
{
    return update(device, std::span{writes}, std::span{copies});
}

#if defined(VK_VERSION_1_1)

/**
 *  Update the contents of a descriptor set object using an update template.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSetWithTemplateKHR.html
 */
template<typename T>
requires(std::is_same_v<T, VkDescriptorImageInfo> or std::is_same_v<T, VkDescriptorBufferInfo> or std::is_same_v<T, VkBufferView>
    #if defined(VK_KHR_acceleration_structure)
         or std::is_same_v<T, VkAccelerationStructureKHR>
    #endif
    #if defined(VK_NV_ray_tracing)
         or std::is_same_v<T, VkAccelerationStructureNV>
    #endif
         )

inline void update(descriptor_set_view set, descriptor_update_template_handle update_template, std::span<const T> data) noexcept
{
    return detail::update(set, update_template, data.data());
}

/**
 *  Update the contents of a descriptor set object using an update template.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSetWithTemplateKHR.html
 */
template<typename T>
inline void update(descriptor_set_view set, descriptor_update_template_handle update_template, std::initializer_list<T> data) noexcept
{
    return update(set, update_template, std::span{data});
}

/**
 *  Update the contents of a descriptor set object using an update template.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateDescriptorSetWithTemplateKHR.html
 */
template<typename T>
inline void update(descriptor_set_view set, descriptor_update_template_handle update_template, const T& data) noexcept
{
    return update(set, update_template, fubuki::as_span(data));
}

#endif // defined(VK_VERSION_1_1)

// TODO: update_with_template

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_DESCRIPTOR_SET_HPP
