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

#ifndef FUBUKI_EXTENSION_EXT_MESH_SHADER_HPP
#define FUBUKI_EXTENSION_EXT_MESH_SHADER_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_mesh_shader.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_mesh_shader::cmd
{

#if defined(VK_EXT_mesh_shader)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawMeshTasksEXT.html
FUBUKI_EXTENSION_API
void draw_mesh_tasks(const functions&      ext,
                     command_buffer_handle command_buffer,
                     std::uint32_t         group_count_x,
                     std::uint32_t         group_count_y,
                     std::uint32_t         group_count_z) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawMeshTasksIndirectEXT.html
FUBUKI_EXTENSION_API
void draw_mesh_tasks_indirect(const functions&      ext,
                              command_buffer_handle command_buffer,
                              buffer_handle         buffer,
                              VkDeviceSize          offset,
                              std::uint32_t         draw_count,
                              std::uint32_t         stride) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawMeshTasksIndirectCountEXT.html
FUBUKI_EXTENSION_API
void draw_mesh_tasks_indirect_count(const functions&      ext,
                                    command_buffer_handle command_buffer,
                                    buffer_handle         buffer,
                                    VkDeviceSize          offset,
                                    buffer_handle         count_buffer,
                                    VkDeviceSize          count_buffer_offset,
                                    std::uint32_t         max_draw_count,
                                    std::uint32_t         stride) noexcept;

#endif // defined(VK_EXT_mesh_shader)

} // namespace fubuki::extension::ext_mesh_shader::cmd

#endif // FUBUKI_EXTENSION_EXT_MESH_SHADER_HPP
