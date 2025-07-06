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

#include "extension/ext_calibrated_timestamps.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_calibrated_timestamps
{

#if defined(VK_EXT_calibrated_timestamps)

[[nodiscard]]
std::expected<small_vector<VkTimeDomainEXT>, api_call_info> get_physical_device_calibrateable_time_domains(const functions&       ext,
                                                                                                           physical_device_handle physical_device)
{
    small_vector<VkTimeDomainEXT> result;

    std::uint32_t count = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetPhysicalDeviceCalibrateableTimeDomainsEXT">(ext, physical_device.vk, &count, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    result.resize(count);

    if(const auto check
       = fubuki_validate(validate_by::expected,  fubuki::invoke<"vkGetPhysicalDeviceCalibrateableTimeDomainsEXT">(ext, physical_device.vk, &count, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<calibrated_timestamps, api_call_info>
get_calibrated_timestamps(const functions& ext, device_handle device, std::span<const VkCalibratedTimestampInfoEXT> infos)
{
    calibrated_timestamps result;
    result.timestamps.resize(infos.size());

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetCalibratedTimestampsEXT">(ext, device.vk, vk_size(infos), infos.data(), result.timestamps.data(), &result.max_deviation)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_EXT_calibrated_timestamps)

} // namespace fubuki::extension::ext_calibrated_timestamps
