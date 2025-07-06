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

#ifndef FUBUKI_EXTENSION_EXT_EXTERNAL_MEMORY_METAL_HPP
#define FUBUKI_EXTENSION_EXT_EXTERNAL_MEMORY_METAL_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_external_memory_metal.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_external_memory_metal
{

#if defined(VK_EXT_external_memory_metal)

struct handle
{
    void* ptr = nullptr;
};

namespace detail

{
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryMetalHandlePropertiesEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info>
                                   get_memory_metal_handle_properties(const functions&                   ext,
                                                                      device_handle                      device,
                                                                      VkExternalMemoryHandleTypeFlagBits handle_type,
                                                                      handle                             h,
                                                                      VkMemoryMetalHandlePropertiesEXT&  result) noexcept;

} // namespace detail

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryMetalHandleEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<handle, api_call_info>
get_memory_metal_handle(const functions& ext, device_handle device, const VkMemoryGetMetalHandleInfoEXT& get_metal_handle_info) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryMetalHandlePropertiesEXT.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkMemoryMetalHandlePropertiesEXT, api_call_info>
get_memory_metal_handle_properties(const functions&                   ext,
                                   device_handle                      device,
                                   VkExternalMemoryHandleTypeFlagBits handle_type,
                                   handle                             h,
                                   const pnext_chain<elements...>&    pnext) noexcept
{
    auto result = fubuki::make<VkMemoryMetalHandlePropertiesEXT>();
    fubuki::extend(result, pnext);

    if(const auto check = detail::get_memory_metal_handle_properties(ext, device, handle_type, h, result); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryMetalHandlePropertiesEXT.html
[[nodiscard]] inline auto
get_memory_metal_handle_properties(const functions& ext, device_handle device, VkExternalMemoryHandleTypeFlagBits handle_type, handle h) noexcept
{
    return get_memory_metal_handle_properties(ext, device, handle_type, h, empty_pnext_chain);
}

#endif // defined(VK_EXT_external_memory_metal)

} // namespace fubuki::extension::ext_external_memory_metal

#endif // FUBUKI_EXTENSION_EXT_EXTERNAL_MEMORY_METAL_HPP
