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

#ifndef FUBUKI_EXTENSION_EXT_CALIBRATED_TIMESTAMPS_HPP
#define FUBUKI_EXTENSION_EXT_CALIBRATED_TIMESTAMPS_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_calibrated_timestamps.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_calibrated_timestamps
{

#if defined(VK_EXT_calibrated_timestamps)

struct calibrated_timestamps
{
    small_vector<std::uint64_t> timestamps    = {};
    std::uint64_t               max_deviation = {};
};

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceCalibrateableTimeDomainsEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<small_vector<VkTimeDomainEXT>, api_call_info>
                                   get_physical_device_calibrateable_time_domains(const functions& ext, physical_device_handle physical_device);

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetCalibratedTimestampsEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<calibrated_timestamps, api_call_info>
get_calibrated_timestamps(const functions& ext, device_handle device, std::span<const VkCalibratedTimestampInfoEXT> infos);

#endif // defined(VK_EXT_calibrated_timestamps)

} // namespace fubuki::extension::ext_calibrated_timestamps

#endif // FUBUKI_EXTENSION_EXT_CALIBRATED_TIMESTAMPS_HPP
