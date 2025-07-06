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

#include "extension/khr_device_group_creation.hpp"

#include <core/invoke.hpp>

namespace fubuki::extension::khr_device_group_creation
{

#if defined(VK_KHR_device_group_creation)

[[nodiscard]]
std::expected<std::vector<VkPhysicalDeviceGroupProperties>, api_call_info> enumerate_physical_device_groups(const functions& ext,
                                                                                                            instance_handle  instance)
{
    std::uint32_t count = 0;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkEnumeratePhysicalDeviceGroupsKHR">(ext, instance.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<VkPhysicalDeviceGroupProperties> result;
    result.resize(count);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkEnumeratePhysicalDeviceGroupsKHR">(ext, instance.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_KHR_device_group_creation)

} // namespace fubuki::extension::khr_device_group_creation
