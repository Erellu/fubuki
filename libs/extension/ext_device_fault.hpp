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

#ifndef FUBUKI_EXTENSION_EXT_DEVICE_FAULT_HPP
#define FUBUKI_EXTENSION_EXT_DEVICE_FAULT_HPP

#include <cstddef>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_device_fault.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_device_fault
{

#if defined(VK_EXT_device_fault)

/// Information about a device fault.
struct fault
{
    small_vector<VkDeviceFaultAddressInfoEXT> fault_address;
    small_vector<VkDeviceFaultVendorInfoEXT>  vendor_info;
    small_vector<std::byte>                   vendor_binary_data;
};

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceFaultInfoEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<fault, api_call_info>
get_device_fault_info(const functions& ext, device_handle device, VkDeviceFaultCountsEXT& counts, VkDeviceFaultInfoEXT& info);

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceFaultInfoEXT.html
template<typename... count_chain_elements, typename... info_elements>
[[nodiscard]] inline auto get_device_fault_info(const functions&                            ext,
                                                device_handle                               device,
                                                const pnext_chain<count_chain_elements...>& count_pnext,
                                                const pnext_chain<info_elements...>&        info_pnext)
{
    auto counts = fubuki::make<VkDeviceFaultCountsEXT>();
    auto info   = fubuki::make<VkDeviceFaultInfoEXT>();

    fubuki::extend(counts, count_pnext);
    fubuki::extend(info, info_pnext);

    return detail::get_device_fault_info(ext, device, counts, info);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetDeviceFaultInfoEXT.html
[[nodiscard]] inline auto get_device_fault_info(const functions& ext, device_handle device)
{
    return get_device_fault_info(ext, device, empty_pnext_chain, empty_pnext_chain);
}

#endif // defined(VK_EXT_device_fault)

} // namespace fubuki::extension::ext_device_fault

#endif // FUBUKI_EXTENSION_EXT_DEVICE_FAULT_HPP
