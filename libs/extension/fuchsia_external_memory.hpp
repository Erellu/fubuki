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

#ifndef FUBUKI_EXTENSION_FUCHSIA_EXTERNAL_MEMORY_HPP
#define FUBUKI_EXTENSION_FUCHSIA_EXTERNAL_MEMORY_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/fuchsia_external_memory.hpp" // IWYU pragma: export

namespace fubuki::extension::fuchsia_external_memory
{

#if defined(VK_FUCHSIA_external_memory)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryZirconHandlePropertiesFUCHSIA.html
[[nodiscard]] FUBUKI_EXTENSION_API std::optional<api_call_info>
                                   get_memory_zircon_handle_properties(const functions&                       ext,
                                                                       device_handle                          device,
                                                                       VkExternalMemoryHandleTypeFlagBits     handle_type,
                                                                       zx_handle_t                            zircon_handle,
                                                                       VkMemoryZirconHandlePropertiesFUCHSIA& result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryZirconHandleFUCHSIA.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<zx_handle_t, api_call_info>
get_memory_zircon_handle(const functions& ext, device_handle device, const VkMemoryGetZirconHandleInfoFUCHSIA& get_zircon_handle_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryZirconHandlePropertiesFUCHSIA.html
template<typename... elements>
[[nodiscard]] inline std::expected<VkMemoryZirconHandlePropertiesFUCHSIA, api_call_info>
get_memory_zircon_handle_properties(const functions&                   ext,
                                    device_handle                      device,
                                    VkExternalMemoryHandleTypeFlagBits handle_type,
                                    zx_handle_t                        zircon_handle,
                                    const pnext_chain<elements...>&    pnext) noexcept
{
    auto result = fubuki::make<VkMemoryZirconHandlePropertiesFUCHSIA>();
    fubuki::extend(result, pnext);

    if(const auto error = detail::get_memory_zircon_handle_properties(ext, device, handle_type, zircon_handle, result))
    {
        return std::unexpected{*error};
    }

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetMemoryZirconHandlePropertiesFUCHSIA.html
[[nodiscard]] inline auto get_memory_zircon_handle_properties(const functions&                   ext,
                                                              device_handle                      device,
                                                              VkExternalMemoryHandleTypeFlagBits handle_type,
                                                              zx_handle_t                        zircon_handle) noexcept
{
    return get_memory_zircon_handle_properties(ext, device, handle_type, zircon_handle, empty_pnext_chain);
}

#endif // defined(VK_FUCHSIA_external_memory)

} // namespace fubuki::extension::fuchsia_external_memory

#endif // FUBUKI_EXTENSION_FUCHSIA_EXTERNAL_MEMORY_HPP
