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

#ifndef FUBUKI_FUYU_COMMANDS_PUSH_HPP
#define FUBUKI_FUYU_COMMANDS_PUSH_HPP

#include <initializer_list>
#include <span>

#include <core/as_span.hpp>
#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

/// Commands performing push operations.
namespace command::push
{

#if defined(VK_VERSION_1_4)

namespace detail
{

/**
 * Update the values of push constants.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushConstants2.html
 */
FUBUKI_FUYU_API
void constants(command_buffer_view command_buffer, const VkPushConstantsInfo& info) noexcept;

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate.html
 */
FUBUKI_FUYU_API
void descriptor_set_with_template(command_buffer_view               command_buffer,
                                  descriptor_update_template_handle update,
                                  pipeline_layout_handle            layout,
                                  std::uint32_t                     set,
                                  const void*                       data) noexcept;

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate2.html
 */
void descriptor_set_with_template(command_buffer_view command_buffer, const VkPushDescriptorSetWithTemplateInfo& info) noexcept;

/**
 * Push descriptor updates into a command buffer
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSet2.html
 */
FUBUKI_FUYU_API
void descriptor_set(command_buffer_view command_buffer, const VkPushDescriptorSetInfo& info) noexcept;

} // namespace detail

#endif // defined(VK_VERSION_1_4)

/**
 * Update the values of push constants.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushConstants.html
 */
FUBUKI_FUYU_API
void constants(command_buffer_view        command_buffer,
               pipeline_layout_handle     layout,
               VkShaderStageFlags         stage,
               std::uint32_t              offset,
               std::span<const std::byte> data) noexcept;

#if defined(VK_VERSION_1_4)

/**
 * Update the values of push constants.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushConstants2.html
 */
template<typename... elements>
inline void constants(command_buffer_view             command_buffer,
                      pipeline_layout_handle          layout,
                      VkShaderStageFlags              stage,
                      std::uint32_t                   offset,
                      std::span<const std::byte>      data,
                      const pnext_chain<elements...>& pnext) noexcept
{
    VkPushConstantsInfo vk_info = {
        .sType      = structure_type_v<VkPushConstantsInfo>,
        .pNext      = {},
        .layout     = layout.vk,
        .stageFlags = stage,
        .offset     = offset,
        .size       = vk_size(data),
        .pValues    = data.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::constants(command_buffer, vk_info);
}

/**
 * Push descriptor updates into a command buffer
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSet.html
 */
FUBUKI_FUYU_API void descriptor_set(command_buffer_view                   command_buffer,
                                    VkPipelineBindPoint                   bind_point,
                                    pipeline_layout_handle                layout,
                                    std::uint32_t                         set,
                                    std::span<const VkWriteDescriptorSet> writes) noexcept;

/**
 * Push descriptor updates into a command buffer
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSet2.html
 */
template<typename... elements>
inline void descriptor_set(command_buffer_view                   command_buffer,
                           VkShaderStageFlags                    flags,
                           pipeline_layout_handle                layout,
                           std::uint32_t                         set,
                           std::span<const VkWriteDescriptorSet> writes,
                           const pnext_chain<elements...>&       pnext) noexcept
{
    VkPushDescriptorSetInfo vk_info = {
        .sType                = structure_type_v<VkPushDescriptorSetInfo>,
        .pNext                = {},
        .stageFlags           = flags,
        .layout               = layout.vk,
        .set                  = set,
        .descriptorWriteCount = vk_size(writes),
        .pDescriptorWrites    = writes.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::descriptor_set(command_buffer, vk_info);
}

/**
 * Push descriptor updates into a command buffer.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSet.html
 */
inline void descriptor_set(command_buffer_view                         command_buffer,
                           VkPipelineBindPoint                         bind_point,
                           pipeline_layout_handle                      layout,
                           std::uint32_t                               set,
                           std::initializer_list<VkWriteDescriptorSet> writes) noexcept
{
    return descriptor_set(command_buffer, bind_point, layout, set, std::span{writes});
}

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate.html
 */
template<typename T>
requires(std::is_same_v<T, VkDescriptorImageInfo> or std::is_same_v<T, VkDescriptorBufferInfo> or std::is_same_v<T, VkBufferView>)
inline void descriptor_set_with_template(command_buffer_view               command_buffer,
                                         descriptor_update_template_handle update,
                                         pipeline_layout_handle            layout,
                                         std::uint32_t                     set,
                                         std::span<const T>                data) noexcept
{
    return detail::descriptor_set_with_template(command_buffer, update, layout, set, data.data());
}

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate2.html
 */
template<typename T, typename... elements>
requires(std::is_same_v<T, VkDescriptorImageInfo> or std::is_same_v<T, VkDescriptorBufferInfo> or std::is_same_v<T, VkBufferView>)
inline void descriptor_set_with_template(command_buffer_view               command_buffer,
                                         descriptor_update_template_handle update,
                                         pipeline_layout_handle            layout,
                                         std::uint32_t                     set,
                                         std::span<const T>                data,
                                         const pnext_chain<elements...>&   pnext) noexcept
{
    VkPushDescriptorSetWithTemplateInfo vk_info{
        .sType                    = structure_type_v<VkPushDescriptorSetWithTemplateInfo>,
        .pNext                    = {},
        .descriptorUpdateTemplate = update.vk,
        .layout                   = layout.vk,
        .set                      = set,
        .pData                    = data.data(),
    };

    fubuki::extend(vk_info, pnext);

    return detail::descriptor_set_with_template(command_buffer, vk_info);
}

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate.html
 */
template<typename T>
inline void descriptor_set_with_template(command_buffer_view               command_buffer,
                                         descriptor_update_template_handle update,
                                         pipeline_layout_handle            layout,
                                         std::uint32_t                     set,
                                         const T&                          data) noexcept
{
    return descriptor_set_with_template(command_buffer, update, layout, set, fubuki::as_span(data));
}

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate2.html
 */
template<typename T, typename... elements>
inline void descriptor_set_with_template(command_buffer_view               command_buffer,
                                         descriptor_update_template_handle update,
                                         pipeline_layout_handle            layout,
                                         std::uint32_t                     set,
                                         const T&                          data,
                                         const pnext_chain<elements...>&   pnext) noexcept
{
    return descriptor_set_with_template(command_buffer, update, layout, set, fubuki::as_span(data), pnext);
}

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate.html
 */
template<typename T>
inline void descriptor_set_with_template(command_buffer_view               command_buffer,
                                         descriptor_update_template_handle update,
                                         pipeline_layout_handle            layout,
                                         std::uint32_t                     set,
                                         std::initializer_list<T>          data) noexcept
{
    return descriptor_set_with_template(command_buffer, update, layout, set, std::span{data});
}

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate2.html
 */
template<typename T, typename... elements>
inline void descriptor_set_with_template(command_buffer_view               command_buffer,
                                         descriptor_update_template_handle update,
                                         pipeline_layout_handle            layout,
                                         std::uint32_t                     set,
                                         std::initializer_list<T>          data,
                                         const pnext_chain<elements...>&   pnext) noexcept
{
    return descriptor_set_with_template(command_buffer, update, layout, set, std::span{data}, pnext);
}

#endif // defined(VK_VERSION_1_4)

} // namespace command::push

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMANDS_PUSH_HPP
