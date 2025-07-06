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

#include "extension/ext_descriptor_buffer.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_descriptor_buffer
{

#if defined(VK_EXT_descriptor_buffer)

[[nodiscard]]
VkDeviceSize get_descriptor_set_layout_size(const functions& ext, device_handle device, descriptor_set_layout_handle layout) noexcept
{
    VkDeviceSize result = 0;
    fubuki::invoke<"vkGetDescriptorSetLayoutSizeEXT">(ext, device.vk, layout.vk, &result);
    return result;
}

[[nodiscard]]
VkDeviceSize get_descriptor_set_layout_binding_offset(const functions&             ext,
                                                      device_handle                device,
                                                      descriptor_set_layout_handle layout,
                                                      std::uint32_t                binding) noexcept
{
    VkDeviceSize result = 0;
    fubuki::invoke<"vkGetDescriptorSetLayoutBindingOffsetEXT">(ext, device.vk, layout.vk, binding, &result);
    return result;
}

void get_descriptor(const functions& ext, device_handle device, const VkDescriptorGetInfoEXT& descriptor_info, std::span<std::byte> buffer) noexcept
{
    return fubuki::invoke<"vkGetDescriptorEXT">(ext, device.vk, &descriptor_info, buffer.size(), buffer.data());
}

[[nodiscard]]
std::expected<void, api_call_info> get_opaque_capture_descriptor_data(const functions&                            ext,
                                                                      device_handle                               device,
                                                                      const VkBufferCaptureDescriptorDataInfoEXT& info,
                                                                      std::span<std::byte>                        buffer) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetBufferOpaqueCaptureDescriptorDataEXT">(ext, device.vk, std::addressof(info), buffer.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info> get_opaque_capture_descriptor_data(const functions&                           ext,
                                                                      device_handle                              device,
                                                                      const VkImageCaptureDescriptorDataInfoEXT& info,
                                                                      std::span<std::byte>                       buffer) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetImageOpaqueCaptureDescriptorDataEXT">(ext, device.vk, std::addressof(info), buffer.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info> get_opaque_capture_descriptor_data(const functions&                               ext,
                                                                      device_handle                                  device,
                                                                      const VkImageViewCaptureDescriptorDataInfoEXT& info,
                                                                      std::span<std::byte>                           buffer) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetImageViewOpaqueCaptureDescriptorDataEXT">(ext, device.vk, std::addressof(info), buffer.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info> get_opaque_capture_descriptor_data(const functions&                             ext,
                                                                      device_handle                                device,
                                                                      const VkSamplerCaptureDescriptorDataInfoEXT& info,
                                                                      std::span<std::byte>                         buffer) noexcept
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetSamplerOpaqueCaptureDescriptorDataEXT">(ext, device.vk, std::addressof(info), buffer.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info> get_opaque_capture_descriptor_data(const functions&                                           ext,
                                                                      device_handle                                              device,
                                                                      const VkAccelerationStructureCaptureDescriptorDataInfoEXT& info,
                                                                      std::span<std::byte>                                       buffer) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT">(ext, device.vk, std::addressof(info), buffer.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

#endif // defined(VK_EXT_descriptor_buffer)

namespace cmd
{

#if defined(VK_EXT_descriptor_buffer)

void bind_descriptor_buffers(const functions&                                  ext,
                             command_buffer_handle                             command_buffer,
                             std::span<const VkDescriptorBufferBindingInfoEXT> bindings) noexcept
{
    return fubuki::invoke<"vkCmdBindDescriptorBuffersEXT">(ext, command_buffer.vk, vk_size(bindings), bindings.data());
}

void set_descriptor_buffer_offsets(const functions&               ext,
                                   command_buffer_handle          command_buffer,
                                   VkPipelineBindPoint            pipeline_bind_point,
                                   pipeline_layout_handle         layout,
                                   std::uint32_t                  first_set,
                                   std::span<const std::uint32_t> buffer_indices,
                                   std::span<const VkDeviceSize>  offsets) noexcept
{
    fubuki_assert(buffer_indices.size() == offsets.size(), "Invalid parameters. Sizes must be equal.");

    return fubuki::invoke<"vkCmdSetDescriptorBufferOffsetsEXT">(
        ext, command_buffer.vk, pipeline_bind_point, layout.vk, first_set, vk_size(buffer_indices), buffer_indices.data(), offsets.data());
}

void bind_descriptor_buffer_embedded_samplers(const functions&       ext,
                                              command_buffer_handle  command_buffer,
                                              VkPipelineBindPoint    pipeline_bind_point,
                                              pipeline_layout_handle layout,
                                              std::uint32_t          set) noexcept
{
    return fubuki::invoke<"vkCmdBindDescriptorBufferEmbeddedSamplersEXT">(ext, command_buffer.vk, pipeline_bind_point, layout.vk, set);
}

} // namespace cmd

#endif // defined(VK_EXT_descriptor_buffer)

} // namespace fubuki::extension::ext_descriptor_buffer
