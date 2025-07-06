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

#ifndef FUBUKI_EXTENSION_FUCHSIA_BUFFER_COLLECTION_HPP
#define FUBUKI_EXTENSION_FUCHSIA_BUFFER_COLLECTION_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/fuchsia_buffer_collection.hpp" // IWYU pragma: export

namespace fubuki::extension::fuchsia_buffer_collection
{

#if defined(VK_FUCHSIA_buffer_collection)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferCollectionPropertiesFUCHSIA.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info> get_buffer_collection_properties(
    const functions& ext, device_handle device, buffer_collection_fuchsia_handle collection, VkBufferCollectionPropertiesFUCHSIA& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateBufferCollectionFUCHSIA.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<buffer_collection_fuchsia_handle, api_call_info>
                                   create(const functions&                           ext,
                                          device_handle                              device,
                                          const VkBufferCollectionCreateInfoFUCHSIA& create_info,
                                          const VkAllocationCallbacks&               allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateBufferCollectionFUCHSIA.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<buffer_collection_fuchsia_handle, api_call_info>
create(const functions& ext, device_handle device, const VkBufferCollectionCreateInfoFUCHSIA& create_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkSetBufferCollectionImageConstraintsFUCHSIA.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   set_buffer_collection_image_constraints(const functions&                     ext,
                                                                           device_handle                        device,
                                                                           buffer_collection_fuchsia_handle     collection,
                                                                           const VkImageConstraintsInfoFUCHSIA& image_constraints_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkSetBufferCollectionBufferConstraintsFUCHSIA.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   set_buffer_collection_buffer_constraints(const functions&                      ext,
                                                                            device_handle                         device,
                                                                            buffer_collection_fuchsia_handle      collection,
                                                                            const VkBufferConstraintsInfoFUCHSIA& buffer_constraints_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyBufferCollectionFUCHSIA.html
FUBUKI_EXTENSION_API
void destroy(const functions&                  ext,
             device_handle                     device,
             buffer_collection_fuchsia_handle& collection,
             const VkAllocationCallbacks&      p_allocator) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyBufferCollectionFUCHSIA.html
FUBUKI_EXTENSION_API
void destroy(const functions& ext, device_handle device, buffer_collection_fuchsia_handle& collection) noexcept;

// VkBufferCollectionPropertiesFUCHSIA
template<typename... elements>
[[nodiscard]] inline std::expected<VkBufferCollectionPropertiesFUCHSIA, api_call_info> get_buffer_collection_properties(
    const functions& ext, device_handle device, buffer_collection_fuchsia_handle collection, const pnext_chain<elements...>& pnext) noexcept
{

    auto result = fubuki::make<VkBufferCollectionPropertiesFUCHSIA>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_buffer_collection_properties(ext, device, collection, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferCollectionPropertiesFUCHSIA.html
[[nodiscard]] inline auto
get_buffer_collection_properties(const functions& ext, device_handle device, buffer_collection_fuchsia_handle collection) noexcept
{
    return get_buffer_collection_properties(ext, device, collection, empty_pnext_chain);
}

#endif // defined(VK_FUCHSIA_buffer_collection)

} // namespace fubuki::extension::fuchsia_buffer_collection

#endif // FUBUKI_EXTENSION_FUCHSIA_BUFFER_COLLECTION_HPP
