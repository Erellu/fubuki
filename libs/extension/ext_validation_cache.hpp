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

#ifndef FUBUKI_EXTENSION_EXT_VALIDATION_CACHE_HPP
#define FUBUKI_EXTENSION_EXT_VALIDATION_CACHE_HPP

#include <cstddef>
#include <span>
#include <vector>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_validation_cache.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_validation_cache
{

#if defined(VK_EXT_validation_cache)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateValidationCacheEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<validation_cache_ext_handle, api_call_info> create(const functions&                      ext,
                                                                                                    device_handle                         device,
                                                                                                    const VkValidationCacheCreateInfoEXT& create_info,
                                                                                                    const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateValidationCacheEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<validation_cache_ext_handle, api_call_info>
                                   create(const functions& ext, device_handle device, const VkValidationCacheCreateInfoEXT& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyValidationCacheEXT.html
FUBUKI_EXTENSION_API
void destroy(const functions&             ext,
             device_handle                device,
             validation_cache_ext_handle& validation_cache,
             const VkAllocationCallbacks& allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyValidationCacheEXT.html
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, validation_cache_ext_handle& validation_cache) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkMergeValidationCachesEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> merge_validation_caches(
    const functions& ext, device_handle device, validation_cache_ext_handle dst_cache, std::span<const validation_cache_ext_handle> caches) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetValidationCacheDataEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<std::vector<std::byte>, api_call_info>
get_validation_cache_data(const functions& ext, device_handle device, validation_cache_ext_handle validation_cache);

#endif // defined(VK_EXT_validation_cache)

} // namespace fubuki::extension::ext_validation_cache

#endif // FUBUKI_EXTENSION_EXT_VALIDATION_CACHE_HPP
