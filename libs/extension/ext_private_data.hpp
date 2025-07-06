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

#ifndef FUBUKI_EXTENSION_EXT_PRIVATE_DATA_HPP
#define FUBUKI_EXTENSION_EXT_PRIVATE_DATA_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_private_data.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_private_data
{

#if defined(VK_EXT_private_data)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreatePrivateDataSlotEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<private_data_slot_handle, api_call_info> create_private_data_slot(
    const functions& ext, device_handle device, const VkPrivateDataSlotCreateInfo& create_info, const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreatePrivateDataSlotEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<private_data_slot_handle, api_call_info>
create_private_data_slot(const functions& ext, device_handle device, const VkPrivateDataSlotCreateInfo& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyPrivateDataSlotEXT.html
FUBUKI_EXTENSION_API
void destroy_private_data_slot(const functions&             ext,
                               device_handle                device,
                               private_data_slot_handle&    private_data_slot,
                               const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyPrivateDataSlotEXT.html
FUBUKI_EXTENSION_API
void destroy_private_data_slot(const functions& ext, device_handle device, private_data_slot_handle& private_data_slot) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkSetPrivateDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> set_private_data(const functions&         ext,
                                                                                       device_handle            device,
                                                                                       VkObjectType             object_type,
                                                                                       std::uint64_t            object_handle,
                                                                                       private_data_slot_handle private_data_slot,
                                                                                       std::uint64_t            data) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPrivateDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::uint64_t get_private_data(
    const functions& ext, device_handle device, VkObjectType object_type, std::uint64_t object_handle, private_data_slot_handle private_data_slot);

#endif // defined(VK_EXT_private_data)

} // namespace fubuki::extension::ext_private_data

#endif // FUBUKI_EXTENSION_EXT_PRIVATE_DATA_HPP
