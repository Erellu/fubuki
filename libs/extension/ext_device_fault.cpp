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

#include "extension/ext_device_fault.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_device_fault::detail
{

#if defined(VK_EXT_device_fault)
[[nodiscard]]
std::expected<fault, api_call_info>
get_device_fault_info(const functions& ext, device_handle device, VkDeviceFaultCountsEXT& counts, VkDeviceFaultInfoEXT& info)
{
    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDeviceFaultInfoEXT">(ext, device.vk, std::addressof(counts), nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    fault result;
    {
        result.fault_address.resize(host_size(counts.addressInfoCount));
        result.vendor_info.resize(host_size(counts.vendorInfoCount));
        result.vendor_binary_data.resize(host_size(counts.vendorBinarySize));
    }

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetDeviceFaultInfoEXT">(ext, device.vk, std::addressof(counts), std::addressof(info))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_EXT_device_fault)

} // namespace fubuki::extension::ext_device_fault::detail
