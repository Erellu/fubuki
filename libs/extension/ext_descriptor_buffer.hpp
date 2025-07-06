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

#ifndef FUBUKI_EXTENSION_EXT_DESCRIPTOR_BUFFER_HPP
#define FUBUKI_EXTENSION_EXT_DESCRIPTOR_BUFFER_HPP

#include <cstddef>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_descriptor_buffer.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_descriptor_buffer
{

#if defined(VK_EXT_descriptor_buffer)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDescriptorSetLayoutSizeEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API VkDeviceSize get_descriptor_set_layout_size(const functions&             ext,
                                                                               device_handle                device,
                                                                               descriptor_set_layout_handle layout) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDescriptorSetLayoutBindingOffsetEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API VkDeviceSize get_descriptor_set_layout_binding_offset(const functions&             ext,
                                                                                         device_handle                device,
                                                                                         descriptor_set_layout_handle layout,
                                                                                         std::uint32_t                binding) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDescriptorEXT.html
FUBUKI_EXTENSION_API
void get_descriptor(const functions&              ext,
                    device_handle                 device,
                    const VkDescriptorGetInfoEXT& p_descriptor_info,
                    std::span<std::byte>          buffer) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferOpaqueCaptureDescriptorDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_opaque_capture_descriptor_data(
    const functions& ext, device_handle device, const VkBufferCaptureDescriptorDataInfoEXT& info, std::span<std::byte> buffer) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageOpaqueCaptureDescriptorDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_opaque_capture_descriptor_data(
    const functions& ext, device_handle device, const VkImageCaptureDescriptorDataInfoEXT& info, std::span<std::byte> buffer) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageViewOpaqueCaptureDescriptorDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_opaque_capture_descriptor_data(
    const functions& ext, device_handle device, const VkImageViewCaptureDescriptorDataInfoEXT& info, std::span<std::byte> buffer) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetSamplerOpaqueCaptureDescriptorDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_opaque_capture_descriptor_data(
    const functions& ext, device_handle device, const VkSamplerCaptureDescriptorDataInfoEXT& info, std::span<std::byte> buffer) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   get_opaque_capture_descriptor_data(const functions&                                           ext,
                                                                      device_handle                                              device,
                                                                      const VkAccelerationStructureCaptureDescriptorDataInfoEXT& info,
                                                                      std::span<std::byte>                                       buffer) noexcept;

#endif // defined(VK_EXT_descriptor_buffer)

namespace cmd
{

#if defined(VK_EXT_descriptor_buffer)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorBuffersEXT.html
FUBUKI_EXTENSION_API
void bind_descriptor_buffers(const functions&                                  ext,
                             command_buffer_handle                             command_buffer,
                             std::span<const VkDescriptorBufferBindingInfoEXT> bindings) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDescriptorBufferOffsetsEXT.html
FUBUKI_EXTENSION_API
void set_descriptor_buffer_offsets(const functions&               ext,
                                   command_buffer_handle          command_buffer,
                                   VkPipelineBindPoint            pipeline_bind_point,
                                   pipeline_layout_handle         layout,
                                   std::uint32_t                  first_set,
                                   std::span<const std::uint32_t> buffer_indices,
                                   std::span<const VkDeviceSize>  offsets) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorBufferEmbeddedSamplersEXT.html
FUBUKI_EXTENSION_API
void bind_descriptor_buffer_embedded_samplers(const functions&       ext,
                                              command_buffer_handle  command_buffer,
                                              VkPipelineBindPoint    pipeline_bind_point,
                                              pipeline_layout_handle layout,
                                              std::uint32_t          set) noexcept;

#endif // defined(VK_EXT_descriptor_buffer)

} // namespace cmd

} // namespace fubuki::extension::ext_descriptor_buffer

#endif // FUBUKI_EXTENSION_EXT_DESCRIPTOR_BUFFER_HPP
