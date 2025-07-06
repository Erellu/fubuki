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

#include "extension/fuchsia_buffer_collection.hpp"

#include <core/invoke.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

namespace fubuki::extension::fuchsia_buffer_collection
{

#if defined(VK_FUCHSIA_buffer_collection)

namespace detail
{

[[nodiscard]]
std::optional<api_call_info> get_buffer_collection_properties(const functions&                     ext,
                                                              device_handle                        device,
                                                              buffer_collection_fuchsia_handle     collection,
                                                              VkBufferCollectionPropertiesFUCHSIA& result) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkGetBufferCollectionPropertiesFUCHSIA">(ext, device.vk, collection.vk, &result)); not check)
    {
        return check.error();
    }

    return {};
}

} // namespace detail

namespace
{

[[nodiscard]]
std::expected<buffer_collection_fuchsia_handle, api_call_info> create(const functions&                           ext,
                                                                      device_handle                              device,
                                                                      const VkBufferCollectionCreateInfoFUCHSIA& create_info,
                                                                      const VkAllocationCallbacks*               allocator) noexcept
{
    buffer_collection_fuchsia_handle result;

    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkCreateBufferCollectionFUCHSIA">(ext, device.vk, &create_info, allocator, &result.vk)); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

} // anonymous namespace

[[nodiscard]]
std::expected<buffer_collection_fuchsia_handle, api_call_info> create(const functions&                           ext,
                                                                      device_handle                              device,
                                                                      const VkBufferCollectionCreateInfoFUCHSIA& create_info,
                                                                      const VkAllocationCallbacks&               allocator) noexcept
{
    return create(ext, device, create_info, std::addressof(allocator));
}

[[nodiscard]]
std::expected<buffer_collection_fuchsia_handle, api_call_info>
create(const functions& ext, device_handle device, const VkBufferCollectionCreateInfoFUCHSIA& create_info) noexcept
{
    return create(ext, device, create_info, nullptr);
}

[[nodiscard]]
std::expected<void, api_call_info> set_buffer_collection_image_constraints(const functions&                     ext,
                                                                           device_handle                        device,
                                                                           buffer_collection_fuchsia_handle     collection,
                                                                           const VkImageConstraintsInfoFUCHSIA& image_constraints_info) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkSetBufferCollectionImageConstraintsFUCHSIA">(ext, device.vk, collection.vk, &image_constraints_info)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]]
std::expected<void, api_call_info> set_buffer_collection_buffer_constraints(const functions&                      ext,
                                                                            device_handle                         device,
                                                                            buffer_collection_fuchsia_handle      collection,
                                                                            const VkBufferConstraintsInfoFUCHSIA& buffer_constraints_info) noexcept
{
    if(const auto check = fubuki_validate(validate_by::expected, fubuki::invoke<"vkSetBufferCollectionBufferConstraintsFUCHSIA">(ext, device.vk, collection.vk, &buffer_constraints_info)); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

void destroy(const functions&                  ext,
             device_handle                     device,
             buffer_collection_fuchsia_handle& collection,
             const VkAllocationCallbacks&      allocator) noexcept
{
    fubuki::invoke<"vkDestroyBufferCollectionFUCHSIA">(ext, device.vk, collection.vk, std::addressof(allocator));

    collection = null_handle;
}

void destroy(const functions& ext, device_handle device, buffer_collection_fuchsia_handle& collection) noexcept
{
    fubuki::invoke<"vkDestroyBufferCollectionFUCHSIA">(ext, device.vk, collection.vk, nullptr);

    collection = null_handle;
}

#endif // defined(VK_FUCHSIA_buffer_collection)

} // namespace fubuki::extension::fuchsia_buffer_collection
