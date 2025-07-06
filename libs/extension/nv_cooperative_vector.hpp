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

#ifndef FUBUKI_EXTENSION_NV_COOPERATIVE_VECTOR_HPP
#define FUBUKI_EXTENSION_NV_COOPERATIVE_VECTOR_HPP

#include <span>
#include <vector>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/nv_cooperative_vector.hpp" // IWYU pragma: export

namespace fubuki::extension::nv_cooperative_vector
{

#if defined(VK_NV_cooperative_vector)

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetPhysicalDeviceCooperativeVectorPropertiesNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<VkCooperativeVectorPropertiesNV>, api_call_info>
get_physical_device_cooperative_vector_properties(const functions& ext, physical_device_handle physical_device) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkConvertCooperativeVectorMatrixNV.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
convert_cooperative_vector_matrix(const functions& ext, device_handle device, const VkConvertCooperativeVectorMatrixInfoNV& info) noexcept;

#endif // defined(VK_NV_cooperative_vector)

namespace cmd
{

#if defined(VK_NV_cooperative_vector)
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdConvertCooperativeVectorMatrixNV.html
FUBUKI_EXTENSION_API void convert_cooperative_vector_matrix(const functions&                                        ext,
                                                            command_buffer_handle                                   command_buffer,
                                                            std::span<const VkConvertCooperativeVectorMatrixInfoNV> infos) noexcept;

#endif // defined(VK_NV_cooperative_vector)

} // namespace cmd

} // namespace fubuki::extension::nv_cooperative_vector

#endif // FUBUKI_EXTENSION_NV_COOPERATIVE_VECTOR_HPP
