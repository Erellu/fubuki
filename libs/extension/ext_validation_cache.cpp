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

#include "extension/ext_validation_cache.hpp"

#include <core/collect.hpp>
#include <core/invoke.hpp>

namespace fubuki::extension::ext_validation_cache
{

#if defined(VK_EXT_validation_cache)

[[nodiscard]]
std::expected<validation_cache_ext_handle, api_call_info>
create(const functions& ext, device_handle device, const VkValidationCacheCreateInfoEXT& create_info, const VkAllocationCallbacks& allocator) noexcept
{
    validation_cache_ext_handle result;

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateValidationCacheEXT">(ext, device.vk, &create_info, std::addressof(allocator), &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

[[nodiscard]]
std::expected<validation_cache_ext_handle, api_call_info>
create(const functions& ext, device_handle device, const VkValidationCacheCreateInfoEXT& create_info) noexcept
{
    validation_cache_ext_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateValidationCacheEXT">(ext, device.vk, &create_info, nullptr, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

void destroy(const functions&             ext,
             device_handle                device,
             validation_cache_ext_handle& validation_cache,
             const VkAllocationCallbacks& allocator) noexcept
{
    fubuki::invoke<"vkDestroyValidationCacheEXT">(ext, device.vk, validation_cache.vk, std::addressof(allocator));
    validation_cache = null_handle;
}

void destroy(const functions& ext, device_handle device, validation_cache_ext_handle& validation_cache) noexcept
{
    fubuki::invoke<"vkDestroyValidationCacheEXT">(ext, device.vk, validation_cache.vk, nullptr);
    validation_cache = null_handle;
}

[[nodiscard]]
std::expected<void, api_call_info> merge_validation_caches(const functions&                             ext,
                                                           device_handle                                device,
                                                           validation_cache_ext_handle                  dst_cache,
                                                           std::span<const validation_cache_ext_handle> caches) noexcept
{
    auto caches_handles = collect<VkValidationCacheEXT>(caches);

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkMergeValidationCachesEXT">(ext, device.vk, dst_cache.vk, vk_size(caches_handles), caches_handles.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<std::vector<std::byte>, api_call_info>
get_validation_cache_data(const functions& ext, device_handle device, validation_cache_ext_handle validation_cache)
{
    std::size_t data_size = 0;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetValidationCacheDataEXT">(ext, device.vk, validation_cache.vk, &data_size, nullptr)); not check)
    {
        return std::unexpected{check.error()};
    }

    std::vector<std::byte> result = {};
    result.resize(data_size);

    if(const auto check
       = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetValidationCacheDataEXT">(ext, device.vk, validation_cache.vk, &data_size, result.data())); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

#endif // defined(VK_EXT_validation_cache)

} // namespace fubuki::extension::ext_validation_cache
