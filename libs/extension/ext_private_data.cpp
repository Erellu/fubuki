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

#include "extension/ext_private_data.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::ext_private_data
{

#if defined(VK_EXT_private_data)

namespace
{

std::expected<private_data_slot_handle, api_call_info> create_private_data_slot(const functions&                   ext,
                                                                                device_handle                      device,
                                                                                const VkPrivateDataSlotCreateInfo& create_info,
                                                                                const VkAllocationCallbacks*       allocator) noexcept
{
    private_data_slot_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreatePrivateDataSlotEXT">(ext, device.vk, &create_info, allocator, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // namespace

[[nodiscard]]
std::expected<private_data_slot_handle, api_call_info> create_private_data_slot(const functions&                   ext,
                                                                                device_handle                      device,
                                                                                const VkPrivateDataSlotCreateInfo& create_info,
                                                                                const VkAllocationCallbacks&       allocator) noexcept
{
    return create_private_data_slot(ext, device, create_info, std::addressof(allocator));
}

[[nodiscard]] std::expected<private_data_slot_handle, api_call_info>
create_private_data_slot(const functions& ext, device_handle device, const VkPrivateDataSlotCreateInfo& create_info) noexcept
{
    return create_private_data_slot(ext, device, create_info, nullptr);
}

void destroy_private_data_slot(const functions&             ext,
                               device_handle                device,
                               private_data_slot_handle&    private_data_slot,
                               const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyPrivateDataSlotEXT">(ext, device.vk, private_data_slot.vk, std::addressof(allocator));
    private_data_slot = null_handle;
}

void destroy_private_data_slot(const functions& ext, device_handle device, private_data_slot_handle& private_data_slot) noexcept
{
    fubuki::invoke<"vkDestroyPrivateDataSlotEXT">(ext, device.vk, private_data_slot.vk, nullptr);
    private_data_slot = null_handle;
}

[[nodiscard]]
std::expected<void, api_call_info> set_private_data(const functions&         ext,
                                                    device_handle            device,
                                                    VkObjectType             object_type,
                                                    std::uint64_t            object_handle,
                                                    private_data_slot_handle private_data_slot,
                                                    std::uint64_t            data) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkSetPrivateDataEXT">(ext, device.vk, object_type, object_handle, private_data_slot.vk, data)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::uint64_t get_private_data(
    const functions& ext, device_handle device, VkObjectType object_type, std::uint64_t object_handle, private_data_slot_handle private_data_slot)
{
    std::uint64_t result = 0;

    fubuki::invoke<"vkGetPrivateDataEXT">(ext, device.vk, object_type, object_handle, private_data_slot.vk, &result);

    return result;
}

#endif // defined(VK_EXT_private_data)

} // namespace fubuki::extension::ext_private_data
