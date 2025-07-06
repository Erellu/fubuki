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

#ifndef FUBUKI_EXTENSION_KHR_DEVICE_GROUP_HPP
#define FUBUKI_EXTENSION_KHR_DEVICE_GROUP_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_device_group.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_device_group
{

#if defined(VK_KHR_device_group)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceGroupPeerMemoryFeaturesKHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkPeerMemoryFeatureFlags get_device_group_peer_memory_features(const functions& ext,
                                                                                                  device_handle    device,
                                                                                                  std::uint32_t    heap_index,
                                                                                                  std::uint32_t    local_device_index,
                                                                                                  std::uint32_t    remote_device_index) noexcept;

#endif // defined(VK_KHR_device_group)

namespace cmd
{

#if defined(VK_KHR_device_group)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDeviceMaskKHR.html
FUBUKI_EXTENSION_API
void set_device_mask(const functions& ext, command_buffer_handle command_buffer, std::uint32_t device_mask) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchBaseKHR.html
FUBUKI_EXTENSION_API
void dispatch_base(const functions&      ext,
                   command_buffer_handle command_buffer,
                   std::uint32_t         base_group_x,
                   std::uint32_t         base_group_y,
                   std::uint32_t         base_group_z,
                   std::uint32_t         group_count_x,
                   std::uint32_t         group_count_y,
                   std::uint32_t         group_count_z) noexcept;

#endif // defined(VK_KHR_device_group)

} // namespace cmd

} // namespace fubuki::extension::khr_device_group

#endif // FUBUKI_EXTENSION_KHR_DEVICE_GROUP_HPP
