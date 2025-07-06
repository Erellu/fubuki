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

#ifndef FUBUKI_EXTENSION_KHR_GET_MEMORY_REQUIREMENTS2_HPP
#define FUBUKI_EXTENSION_KHR_GET_MEMORY_REQUIREMENTS2_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/khr_get_memory_requirements2.hpp" // IWYU pragma: export

namespace fubuki::extension::khr_get_memory_requirements2
{

#if defined(VK_KHR_get_memory_requirements2)

namespace detail
{

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferMemoryRequirements2KHR.html
FUBUKI_EXTENSION_API void get_buffer_memory_requirements2(const functions&                       ext,
                                                          device_handle                          device,
                                                          const VkBufferMemoryRequirementsInfo2& info,
                                                          VkMemoryRequirements2&                 result) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageMemoryRequirements2KHR.html
FUBUKI_EXTENSION_API void get_image_memory_requirements2(const functions&                      ext,
                                                         device_handle                         device,
                                                         const VkImageMemoryRequirementsInfo2& info,
                                                         VkMemoryRequirements2&                result) noexcept;

} // namespace detail

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageMemoryRequirements2KHR.html
template<typename... elements>
[[nodiscard]] inline auto get_image_memory_requirements2(const functions&                      ext,
                                                         device_handle                         device,
                                                         const VkImageMemoryRequirementsInfo2& info,
                                                         const pnext_chain<elements...>&       pnext) noexcept
{
    auto result = fubuki::make<VkMemoryRequirements2>();
    fubuki::extend(result, pnext);

    detail::get_image_memory_requirements2(ext, device, info, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageMemoryRequirements2KHR.html
[[nodiscard]] inline auto
get_image_memory_requirements2(const functions& ext, device_handle device, const VkImageMemoryRequirementsInfo2& info) noexcept
{
    return get_image_memory_requirements2(ext, device, info, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferMemoryRequirements2KHR.html
template<typename... elements>
[[nodiscard]] inline auto get_buffer_memory_requirements2(const functions&                       ext,
                                                          device_handle                          device,
                                                          const VkBufferMemoryRequirementsInfo2& info,
                                                          const pnext_chain<elements...>&        pnext) noexcept
{
    auto result = fubuki::make<VkMemoryRequirements2>();
    fubuki::extend(result, pnext);

    detail::get_buffer_memory_requirements2(ext, device, info, result);

    return result;
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetBufferMemoryRequirements2KHR.html
[[nodiscard]] inline auto
get_buffer_memory_requirements2(const functions& ext, device_handle device, const VkBufferMemoryRequirementsInfo2& info) noexcept
{
    return get_buffer_memory_requirements2(ext, device, info, empty_pnext_chain);
}

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetImageSparseMemoryRequirements2KHR.html
[[nodiscard]] FUBUKI_EXTENSION_API std::vector<VkSparseImageMemoryRequirements2>
get_image_sparse_memory_requirements2(const functions& ext, device_handle device, const VkImageSparseMemoryRequirementsInfo2& info);

#endif // defined(VK_KHR_get_memory_requirements2)

} // namespace fubuki::extension::khr_get_memory_requirements2

#endif // FUBUKI_EXTENSION_KHR_GET_MEMORY_REQUIREMENTS2_HPP
