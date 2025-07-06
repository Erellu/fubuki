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

#include "extension/khr_descriptor_update_template.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_descriptor_update_template
{

#if defined(VK_KHR_descriptor_update_template)

namespace
{

[[nodiscard]]
std::expected<descriptor_update_template_handle, api_call_info>
create_descriptor_update_template(const functions&                            ext,
                                  device_handle                               device,
                                  const VkDescriptorUpdateTemplateCreateInfo& create_info,
                                  const VkAllocationCallbacks*                allocator) noexcept
{
    descriptor_update_template_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateDescriptorUpdateTemplateKHR">(ext, device.vk, std::addressof(create_info), allocator, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // namespace

[[nodiscard]]
std::expected<descriptor_update_template_handle, api_call_info>
create_descriptor_update_template(const functions&                            ext,
                                  device_handle                               device,
                                  const VkDescriptorUpdateTemplateCreateInfo& create_info,
                                  const VkAllocationCallbacks&                allocator) noexcept
{
    return create_descriptor_update_template(ext, device, create_info, std::addressof(allocator));
}

[[nodiscard]]
std::expected<descriptor_update_template_handle, api_call_info>
create_descriptor_update_template(const functions& ext, device_handle device, const VkDescriptorUpdateTemplateCreateInfo& create_info) noexcept
{
    return create_descriptor_update_template(ext, device, create_info, nullptr);
}

void destroy_descriptor_update_template(const functions&                   ext,
                                        device_handle                      device,
                                        descriptor_update_template_handle& descriptor_update_template,
                                        const VkAllocationCallbacks&       allocator) noexcept
{
    fubuki::invoke<"vkDestroyDescriptorUpdateTemplateKHR">(ext, device.vk, descriptor_update_template.vk, std::addressof(allocator));
    descriptor_update_template = null_handle;
}

void destroy_descriptor_update_template(const functions&                   ext,
                                        device_handle                      device,
                                        descriptor_update_template_handle& descriptor_update_template) noexcept
{
    fubuki::invoke<"vkDestroyDescriptorUpdateTemplateKHR">(ext, device.vk, descriptor_update_template.vk, nullptr);
    descriptor_update_template = null_handle;
}

void update_descriptor_set_with_template(const functions&                  ext,
                                         device_handle                     device,
                                         descriptor_set_handle             descriptor_set,
                                         descriptor_update_template_handle descriptor_update_template,
                                         const void*                       data) noexcept
{
    fubuki::invoke<"vkUpdateDescriptorSetWithTemplateKHR">(ext, device.vk, descriptor_set.vk, descriptor_update_template.vk, data);
}

#endif // defined(VK_KHR_descriptor_update_template)

} // namespace fubuki::extension::khr_descriptor_update_template
