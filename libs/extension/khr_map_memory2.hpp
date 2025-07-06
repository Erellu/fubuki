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

#ifndef FUBUKI_EXTENSION_KHR_MAP_MEMORY2_HPP
#define FUBUKI_EXTENSION_KHR_MAP_MEMORY2_HPP

#include <cstddef>
#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_map_memory2.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_map_memory2
{

#if defined(VK_KHR_map_memory2)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMapMemory2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::byte*, api_call_info>
                                   map_memory2(const functions& ext, device_handle device, const VkMemoryMapInfoKHR& memory_map_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMapMemory2KHR.html
/// @param memory_reqs Information about the memory which region is mapped. Used to determine the size of the range returned upon success.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::span<std::byte>, api_call_info>
map_memory2(const functions& ext, device_handle device, const VkMemoryMapInfoKHR& memory_map_info, const VkMemoryRequirements& memory_reqs) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUnmapMemory2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API VkResult unmap_memory2(const functions&            ext,
                                                          device_handle               device,
                                                          const VkMemoryUnmapInfoKHR& memory_unmap_info) noexcept;

#endif // defined(VK_KHR_map_memory2)

} // namespace fubuki::extension::khr_map_memory2

#endif // FUBUKI_EXTENSION_KHR_MAP_MEMORY2_HPP
