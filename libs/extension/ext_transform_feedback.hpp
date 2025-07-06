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

#ifndef FUBUKI_EXTENSION_EXT_TRANSFORM_FEEDBACK_HPP
#define FUBUKI_EXTENSION_EXT_TRANSFORM_FEEDBACK_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_transform_feedback.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_transform_feedback::cmd
{

#if defined(VK_EXT_transform_feedback)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindTransformFeedbackBuffersEXT.html
FUBUKI_EXTENSION_API
void bind_transform_feedback_buffers(const functions&               ext,
                                     command_buffer_handle          command_buffer,
                                     std::uint32_t                  first_binding,
                                     std::span<const buffer_handle> buffers,
                                     std::span<const VkDeviceSize>  offsets,
                                     std::span<const VkDeviceSize>  sizes) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginTransformFeedbackEXT.html
FUBUKI_EXTENSION_API
void begin_transform_feedback(const functions&               ext,
                              command_buffer_handle          command_buffer,
                              std::uint32_t                  first_counter_buffer,
                              std::span<const buffer_handle> counter_buffers,
                              std::span<const VkDeviceSize>  offsets) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndTransformFeedbackEXT.html
FUBUKI_EXTENSION_API
void end_transform_feedback(const functions&               ext,
                            command_buffer_handle          command_buffer,
                            std::uint32_t                  first_counter_buffer,
                            std::span<const buffer_handle> counter_buffers,
                            std::span<const VkDeviceSize>  offsets) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginQueryIndexedEXT.html
FUBUKI_EXTENSION_API
void begin_query_indexed(const functions&      ext,
                         command_buffer_handle command_buffer,
                         query_pool_handle     query_pool,
                         std::uint32_t         query,
                         VkQueryControlFlags   flags,
                         std::uint32_t         index) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndQueryIndexedEXT.html
FUBUKI_EXTENSION_API
void end_query_indexed(
    const functions& ext, command_buffer_handle command_buffer, query_pool_handle query_pool, std::uint32_t query, std::uint32_t index);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndirectByteCountEXT.html
FUBUKI_EXTENSION_API
void draw_indirect_byte_count(const functions&      ext,
                              command_buffer_handle command_buffer,
                              std::uint32_t         instance_count,
                              std::uint32_t         first_instance,
                              buffer_handle         counter_buffer,
                              VkDeviceSize          counter_buffer_offset,
                              std::uint32_t         counter_offset,
                              std::uint32_t         vertex_stride) noexcept;

/// A RAII object calling `vkCmdBeginTransformFeedbackEXT` upon construction, and `vkCmdEndTransformFeedbackEXT` upon destruction.
class scope
{
public:

    scope(const functions&               ext,
          command_buffer_handle          command_buffer,
          std::uint32_t                  first_counter_buffer,
          std::span<const buffer_handle> counter_buffers,
          std::span<const VkDeviceSize>  offsets) noexcept
        : m_ext{ext},
          m_command_buffer{command_buffer},
          m_first_counter_buffer{first_counter_buffer},
          m_counter_buffers{counter_buffers},
          m_offsets{offsets}
    {
        begin_transform_feedback(m_ext, m_command_buffer, m_first_counter_buffer, m_counter_buffers, m_offsets);
    }

    ~scope() noexcept { end_transform_feedback(m_ext, m_command_buffer, m_first_counter_buffer, m_counter_buffers, m_offsets); }

    scope(scope&&)      = delete;
    scope(const scope&) = delete;

    scope& operator=(scope&&)      = delete;
    scope& operator=(const scope&) = delete;

private:
    std::reference_wrapper<const functions> m_ext;
    command_buffer_handle                   m_command_buffer;
    std::uint32_t                           m_first_counter_buffer;
    std::span<const buffer_handle>          m_counter_buffers;
    std::span<const VkDeviceSize>           m_offsets;
};

/// A RAII object calling `vkCmdBeginQueryIndexedEXT` upon construction, and `vkCmdEndQueryIndexedEXT` upon destruction.
class query_scope
{
public:

    // NOLINTBEGIN(bugprone-easily-swappable-parameters)
    query_scope(const functions&      ext,
                command_buffer_handle command_buffer,
                query_pool_handle     query_pool,
                std::uint32_t         query,
                VkQueryControlFlags   flags,
                std::uint32_t         index) noexcept
        : m_ext{ext},
          m_command_buffer{command_buffer},
          m_query_pool{query_pool},
          m_query{query},
          m_index{index}
    {
        begin_query_indexed(m_ext, m_command_buffer, m_query_pool, m_query, flags, m_index);
    }
    // NOLINTEND(bugprone-easily-swappable-parameters)

    ~query_scope() noexcept { end_query_indexed(m_ext, m_command_buffer, m_query_pool, m_query, m_index); }

    query_scope(query_scope&&)      = delete;
    query_scope(const query_scope&) = delete;

    query_scope& operator=(query_scope&&)      = delete;
    query_scope& operator=(const query_scope&) = delete;
private:

    std::reference_wrapper<const functions> m_ext;
    command_buffer_handle                   m_command_buffer;
    query_pool_handle                       m_query_pool;
    std::uint32_t                           m_query;
    std::uint32_t                           m_index;
};

#endif // defined(VK_EXT_transform_feedback)

} // namespace fubuki::extension::ext_transform_feedback::cmd

#endif // FUBUKI_EXTENSION_EXT_TRANSFORM_FEEDBACK_HPP
