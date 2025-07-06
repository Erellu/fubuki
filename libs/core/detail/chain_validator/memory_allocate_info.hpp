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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#ifndef FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_MEMORY_ALLOCATE_INFO_HPP
#define FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_MEMORY_ALLOCATE_INFO_HPP

#include "core/vulkan.hpp" // IWYU pragma: keep

namespace fubuki::detail::pnext_chain
{

template<typename base_type, typename structure_type>
struct chain_validator;

#if defined(VK_VERSION_1_0)

template<typename structure_type>
struct chain_validator<VkMemoryAllocateInfo, structure_type>
{
    static constexpr bool allowed = false;
    static constexpr bool unique  = true;
};

    #if defined(VK_EXT_external_memory_metal)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemoryMetalHandleInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_external_memory_metal)

    #if defined(VK_VERSION_1_2)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkMemoryOpaqueCaptureAddressAllocateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_2)

    #if defined(VK_NV_external_memory)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkExportMemoryAllocateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkMemoryAllocateFlagsInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkMemoryDedicatedAllocateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_FUCHSIA_buffer_collection)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemoryBufferCollectionFUCHSIA>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_FUCHSIA_buffer_collection)

    #if defined(VK_VERSION_1_1)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkExportMemoryAllocateInfo>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_VERSION_1_1)

    #if defined(VK_NV_external_memory_sci_buf)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkExportMemorySciBufInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportAndroidHardwareBufferInfoANDROID>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_ANDROID_external_memory_android_hardware_buffer)

    #if defined(VK_EXT_metal_objects)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkExportMetalObjectCreateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = false;
};
    #endif // #if defined(VK_EXT_metal_objects)

    #if defined(VK_NV_dedicated_allocation)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkDedicatedAllocationMemoryAllocateInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_dedicated_allocation)

    #if defined(VK_KHR_external_memory_fd)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemoryFdInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_external_memory_fd)

    #if defined(VK_NV_external_memory_win32)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_win32)

    #if defined(VK_EXT_metal_objects)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMetalBufferInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_metal_objects)

    #if defined(VK_EXT_memory_priority)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkMemoryPriorityAllocateInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_memory_priority)

    #if defined(VK_NV_external_memory_win32)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_win32)

    #if defined(VK_QNX_external_memory_screen_buffer)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportScreenBufferInfoQNX>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_QNX_external_memory_screen_buffer)

    #if defined(VK_NV_external_memory_sci_buf)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemorySciBufInfoNV>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_NV_external_memory_sci_buf)

    #if defined(VK_KHR_external_memory_win32)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkExportMemoryWin32HandleInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_external_memory_win32)

    #if defined(VK_EXT_external_memory_host)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemoryHostPointerInfoEXT>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_EXT_external_memory_host)

    #if defined(VK_KHR_external_memory_win32)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemoryWin32HandleInfoKHR>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_KHR_external_memory_win32)

    #if defined(VK_FUCHSIA_external_memory)
template<>
struct chain_validator<VkMemoryAllocateInfo, VkImportMemoryZirconHandleInfoFUCHSIA>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = true;
};
    #endif // #if defined(VK_FUCHSIA_external_memory)

#endif // #if defined(VK_VERSION_1_0)

} // namespace fubuki::detail::pnext_chain

#endif // FUBUKI_CORE_DETAIL_CHAIN_VALIDATOR_MEMORY_ALLOCATE_INFO_HPP
