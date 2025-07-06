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

#ifndef FUBUKI_EXTENSION_EXT_METAL_OBJECTS_HPP
#define FUBUKI_EXTENSION_EXT_METAL_OBJECTS_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_metal_objects.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_metal_objects
{

#if defined(VK_EXT_metal_objects)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkExportMetalObjectsEXT.html
FUBUKI_EXTENSION_API
void export_metal_objects(const functions& ext, device_handle device, VkExportMetalObjectsInfoEXT& metal_objects_info) noexcept;

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkExportMetalObjectsEXT.html
template<typename... elements>
inline void export_metal_objects(const functions& ext, device_handle device, const pnext_chain<elements...>& pnext) noexcept
{
    auto base = fubuki::make<VkExportMetalObjectsInfoEXT>();
    fubuki::extend(base, pnext);
    return export_metal_objects(ext, device, base);
}

#endif // defined(VK_EXT_metal_objects)

} // namespace fubuki::extension::ext_metal_objects

#endif // FUBUKI_EXTENSION_EXT_METAL_OBJECTS_HPP
