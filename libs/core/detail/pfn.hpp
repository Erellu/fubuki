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

#ifndef FUBUKI_CORE_DETAIL_PFN_HPP
#define FUBUKI_CORE_DETAIL_PFN_HPP

#include "core/compile_time_hash.hpp"
#include "core/vulkan.hpp"

namespace fubuki::detail
{

//------------------------------------------------------------------------------

/// Mock to allow pfn<"vkStuff"> syntax.
struct vk_function_hash
{
    consteval vk_function_hash(const string_literal str) : hash{compile_time_hash({str})} {}

    // NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
    template<std::size_t size>
    consteval vk_function_hash(const char (&s)[size]) noexcept : vk_function_hash{string_literal{s}}
    {
    }
    // NOLINTEND(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)

    friend consteval bool operator==(const vk_function_hash&, const vk_function_hash&)  = default;
    friend consteval bool operator!=(const vk_function_hash&, const vk_function_hash&)  = default;
    friend consteval auto operator<=>(const vk_function_hash&, const vk_function_hash&) = default;

    std::size_t hash = 0;
};

//------------------------------------------------------------------------------
// Generate traits for each PFN

namespace traits
{

template<std::size_t hash>
struct vk_function
{
    using type                        = void;
    static inline constexpr auto name = ""_literal;
};

template<std::size_t hash>
concept valid_pfn_name = not std::is_same_v<typename vk_function<hash>::type, void>;

#if defined(FUBUKI_MAKE_PFN_TRAITS)
    #error Internal error. Should not be defined.
#endif

//------------------------------------------------------------------------------
// clang-format off

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateInstance"_literal)>
{
    using type                 = PFN_vkCreateInstance;
    static constexpr auto name = "vkCreateInstance"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyInstance"_literal)>
{
    using type                 = PFN_vkDestroyInstance;
    static constexpr auto name = "vkDestroyInstance"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkEnumeratePhysicalDevices"_literal)>
{
    using type                 = PFN_vkEnumeratePhysicalDevices;
    static constexpr auto name = "vkEnumeratePhysicalDevices"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceFeatures"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceFeatures;
    static constexpr auto name = "vkGetPhysicalDeviceFeatures"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceFormatProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceFormatProperties;
    static constexpr auto name = "vkGetPhysicalDeviceFormatProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceImageFormatProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceImageFormatProperties;
    static constexpr auto name = "vkGetPhysicalDeviceImageFormatProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceProperties;
    static constexpr auto name = "vkGetPhysicalDeviceProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceQueueFamilyProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceQueueFamilyProperties;
    static constexpr auto name = "vkGetPhysicalDeviceQueueFamilyProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceMemoryProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceMemoryProperties;
    static constexpr auto name = "vkGetPhysicalDeviceMemoryProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetInstanceProcAddr"_literal)>
{
    using type                 = PFN_vkGetInstanceProcAddr;
    static constexpr auto name = "vkGetInstanceProcAddr"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetDeviceProcAddr"_literal)>
{
    using type                 = PFN_vkGetDeviceProcAddr;
    static constexpr auto name = "vkGetDeviceProcAddr"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateDevice"_literal)>
{
    using type                 = PFN_vkCreateDevice;
    static constexpr auto name = "vkCreateDevice"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyDevice"_literal)>
{
    using type                 = PFN_vkDestroyDevice;
    static constexpr auto name = "vkDestroyDevice"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkEnumerateInstanceExtensionProperties"_literal)>
{
    using type                 = PFN_vkEnumerateInstanceExtensionProperties;
    static constexpr auto name = "vkEnumerateInstanceExtensionProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkEnumerateDeviceExtensionProperties"_literal)>
{
    using type                 = PFN_vkEnumerateDeviceExtensionProperties;
    static constexpr auto name = "vkEnumerateDeviceExtensionProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkEnumerateInstanceLayerProperties"_literal)>
{
    using type                 = PFN_vkEnumerateInstanceLayerProperties;
    static constexpr auto name = "vkEnumerateInstanceLayerProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkEnumerateDeviceLayerProperties"_literal)>
{
    using type                 = PFN_vkEnumerateDeviceLayerProperties;
    static constexpr auto name = "vkEnumerateDeviceLayerProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetDeviceQueue"_literal)>
{
    using type                 = PFN_vkGetDeviceQueue;
    static constexpr auto name = "vkGetDeviceQueue"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkQueueSubmit"_literal)>
{
    using type                 = PFN_vkQueueSubmit;
    static constexpr auto name = "vkQueueSubmit"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkQueueWaitIdle"_literal)>
{
    using type                 = PFN_vkQueueWaitIdle;
    static constexpr auto name = "vkQueueWaitIdle"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDeviceWaitIdle"_literal)>
{
    using type                 = PFN_vkDeviceWaitIdle;
    static constexpr auto name = "vkDeviceWaitIdle"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkAllocateMemory"_literal)>
{
    using type                 = PFN_vkAllocateMemory;
    static constexpr auto name = "vkAllocateMemory"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkFreeMemory"_literal)>
{
    using type                 = PFN_vkFreeMemory;
    static constexpr auto name = "vkFreeMemory"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkMapMemory"_literal)>
{
    using type                 = PFN_vkMapMemory;
    static constexpr auto name = "vkMapMemory"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkUnmapMemory"_literal)>
{
    using type                 = PFN_vkUnmapMemory;
    static constexpr auto name = "vkUnmapMemory"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkFlushMappedMemoryRanges"_literal)>
{
    using type                 = PFN_vkFlushMappedMemoryRanges;
    static constexpr auto name = "vkFlushMappedMemoryRanges"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkInvalidateMappedMemoryRanges"_literal)>
{
    using type                 = PFN_vkInvalidateMappedMemoryRanges;
    static constexpr auto name = "vkInvalidateMappedMemoryRanges"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetDeviceMemoryCommitment"_literal)>
{
    using type                 = PFN_vkGetDeviceMemoryCommitment;
    static constexpr auto name = "vkGetDeviceMemoryCommitment"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkBindBufferMemory"_literal)>
{
    using type                 = PFN_vkBindBufferMemory;
    static constexpr auto name = "vkBindBufferMemory"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkBindImageMemory"_literal)>
{
    using type                 = PFN_vkBindImageMemory;
    static constexpr auto name = "vkBindImageMemory"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetBufferMemoryRequirements"_literal)>
{
    using type                 = PFN_vkGetBufferMemoryRequirements;
    static constexpr auto name = "vkGetBufferMemoryRequirements"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetImageMemoryRequirements"_literal)>
{
    using type                 = PFN_vkGetImageMemoryRequirements;
    static constexpr auto name = "vkGetImageMemoryRequirements"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetImageSparseMemoryRequirements"_literal)>
{
    using type                 = PFN_vkGetImageSparseMemoryRequirements;
    static constexpr auto name = "vkGetImageSparseMemoryRequirements"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSparseImageFormatProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSparseImageFormatProperties;
    static constexpr auto name = "vkGetPhysicalDeviceSparseImageFormatProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkQueueBindSparse"_literal)>
{
    using type                 = PFN_vkQueueBindSparse;
    static constexpr auto name = "vkQueueBindSparse"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateFence"_literal)>
{
    using type                 = PFN_vkCreateFence;
    static constexpr auto name = "vkCreateFence"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyFence"_literal)>
{
    using type                 = PFN_vkDestroyFence;
    static constexpr auto name = "vkDestroyFence"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkResetFences"_literal)>
{
    using type                 = PFN_vkResetFences;
    static constexpr auto name = "vkResetFences"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetFenceStatus"_literal)>
{
    using type                 = PFN_vkGetFenceStatus;
    static constexpr auto name = "vkGetFenceStatus"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkWaitForFences"_literal)>
{
    using type                 = PFN_vkWaitForFences;
    static constexpr auto name = "vkWaitForFences"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateSemaphore"_literal)>
{
    using type                 = PFN_vkCreateSemaphore;
    static constexpr auto name = "vkCreateSemaphore"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroySemaphore"_literal)>
{
    using type                 = PFN_vkDestroySemaphore;
    static constexpr auto name = "vkDestroySemaphore"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateEvent"_literal)>
{
    using type                 = PFN_vkCreateEvent;
    static constexpr auto name = "vkCreateEvent"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyEvent"_literal)>
{
    using type                 = PFN_vkDestroyEvent;
    static constexpr auto name = "vkDestroyEvent"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetEventStatus"_literal)>
{
    using type                 = PFN_vkGetEventStatus;
    static constexpr auto name = "vkGetEventStatus"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkSetEvent"_literal)>
{
    using type                 = PFN_vkSetEvent;
    static constexpr auto name = "vkSetEvent"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkResetEvent"_literal)>
{
    using type                 = PFN_vkResetEvent;
    static constexpr auto name = "vkResetEvent"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateQueryPool"_literal)>
{
    using type                 = PFN_vkCreateQueryPool;
    static constexpr auto name = "vkCreateQueryPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyQueryPool"_literal)>
{
    using type                 = PFN_vkDestroyQueryPool;
    static constexpr auto name = "vkDestroyQueryPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetQueryPoolResults"_literal)>
{
    using type                 = PFN_vkGetQueryPoolResults;
    static constexpr auto name = "vkGetQueryPoolResults"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateBuffer"_literal)>
{
    using type                 = PFN_vkCreateBuffer;
    static constexpr auto name = "vkCreateBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyBuffer"_literal)>
{
    using type                 = PFN_vkDestroyBuffer;
    static constexpr auto name = "vkDestroyBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateBufferView"_literal)>
{
    using type                 = PFN_vkCreateBufferView;
    static constexpr auto name = "vkCreateBufferView"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyBufferView"_literal)>
{
    using type                 = PFN_vkDestroyBufferView;
    static constexpr auto name = "vkDestroyBufferView"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateImage"_literal)>
{
    using type                 = PFN_vkCreateImage;
    static constexpr auto name = "vkCreateImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyImage"_literal)>
{
    using type                 = PFN_vkDestroyImage;
    static constexpr auto name = "vkDestroyImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetImageSubresourceLayout"_literal)>
{
    using type                 = PFN_vkGetImageSubresourceLayout;
    static constexpr auto name = "vkGetImageSubresourceLayout"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateImageView"_literal)>
{
    using type                 = PFN_vkCreateImageView;
    static constexpr auto name = "vkCreateImageView"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyImageView"_literal)>
{
    using type                 = PFN_vkDestroyImageView;
    static constexpr auto name = "vkDestroyImageView"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateShaderModule"_literal)>
{
    using type                 = PFN_vkCreateShaderModule;
    static constexpr auto name = "vkCreateShaderModule"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyShaderModule"_literal)>
{
    using type                 = PFN_vkDestroyShaderModule;
    static constexpr auto name = "vkDestroyShaderModule"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreatePipelineCache"_literal)>
{
    using type                 = PFN_vkCreatePipelineCache;
    static constexpr auto name = "vkCreatePipelineCache"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyPipelineCache"_literal)>
{
    using type                 = PFN_vkDestroyPipelineCache;
    static constexpr auto name = "vkDestroyPipelineCache"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetPipelineCacheData"_literal)>
{
    using type                 = PFN_vkGetPipelineCacheData;
    static constexpr auto name = "vkGetPipelineCacheData"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkMergePipelineCaches"_literal)>
{
    using type                 = PFN_vkMergePipelineCaches;
    static constexpr auto name = "vkMergePipelineCaches"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateGraphicsPipelines"_literal)>
{
    using type                 = PFN_vkCreateGraphicsPipelines;
    static constexpr auto name = "vkCreateGraphicsPipelines"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateComputePipelines"_literal)>
{
    using type                 = PFN_vkCreateComputePipelines;
    static constexpr auto name = "vkCreateComputePipelines"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyPipeline"_literal)>
{
    using type                 = PFN_vkDestroyPipeline;
    static constexpr auto name = "vkDestroyPipeline"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreatePipelineLayout"_literal)>
{
    using type                 = PFN_vkCreatePipelineLayout;
    static constexpr auto name = "vkCreatePipelineLayout"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyPipelineLayout"_literal)>
{
    using type                 = PFN_vkDestroyPipelineLayout;
    static constexpr auto name = "vkDestroyPipelineLayout"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateSampler"_literal)>
{
    using type                 = PFN_vkCreateSampler;
    static constexpr auto name = "vkCreateSampler"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroySampler"_literal)>
{
    using type                 = PFN_vkDestroySampler;
    static constexpr auto name = "vkDestroySampler"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateDescriptorSetLayout"_literal)>
{
    using type                 = PFN_vkCreateDescriptorSetLayout;
    static constexpr auto name = "vkCreateDescriptorSetLayout"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyDescriptorSetLayout"_literal)>
{
    using type                 = PFN_vkDestroyDescriptorSetLayout;
    static constexpr auto name = "vkDestroyDescriptorSetLayout"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateDescriptorPool"_literal)>
{
    using type                 = PFN_vkCreateDescriptorPool;
    static constexpr auto name = "vkCreateDescriptorPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyDescriptorPool"_literal)>
{
    using type                 = PFN_vkDestroyDescriptorPool;
    static constexpr auto name = "vkDestroyDescriptorPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkResetDescriptorPool"_literal)>
{
    using type                 = PFN_vkResetDescriptorPool;
    static constexpr auto name = "vkResetDescriptorPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkAllocateDescriptorSets"_literal)>
{
    using type                 = PFN_vkAllocateDescriptorSets;
    static constexpr auto name = "vkAllocateDescriptorSets"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkFreeDescriptorSets"_literal)>
{
    using type                 = PFN_vkFreeDescriptorSets;
    static constexpr auto name = "vkFreeDescriptorSets"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkUpdateDescriptorSets"_literal)>
{
    using type                 = PFN_vkUpdateDescriptorSets;
    static constexpr auto name = "vkUpdateDescriptorSets"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateFramebuffer"_literal)>
{
    using type                 = PFN_vkCreateFramebuffer;
    static constexpr auto name = "vkCreateFramebuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyFramebuffer"_literal)>
{
    using type                 = PFN_vkDestroyFramebuffer;
    static constexpr auto name = "vkDestroyFramebuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateRenderPass"_literal)>
{
    using type                 = PFN_vkCreateRenderPass;
    static constexpr auto name = "vkCreateRenderPass"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyRenderPass"_literal)>
{
    using type                 = PFN_vkDestroyRenderPass;
    static constexpr auto name = "vkDestroyRenderPass"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetRenderAreaGranularity"_literal)>
{
    using type                 = PFN_vkGetRenderAreaGranularity;
    static constexpr auto name = "vkGetRenderAreaGranularity"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCreateCommandPool"_literal)>
{
    using type                 = PFN_vkCreateCommandPool;
    static constexpr auto name = "vkCreateCommandPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkDestroyCommandPool"_literal)>
{
    using type                 = PFN_vkDestroyCommandPool;
    static constexpr auto name = "vkDestroyCommandPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkResetCommandPool"_literal)>
{
    using type                 = PFN_vkResetCommandPool;
    static constexpr auto name = "vkResetCommandPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkAllocateCommandBuffers"_literal)>
{
    using type                 = PFN_vkAllocateCommandBuffers;
    static constexpr auto name = "vkAllocateCommandBuffers"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkFreeCommandBuffers"_literal)>
{
    using type                 = PFN_vkFreeCommandBuffers;
    static constexpr auto name = "vkFreeCommandBuffers"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkBeginCommandBuffer"_literal)>
{
    using type                 = PFN_vkBeginCommandBuffer;
    static constexpr auto name = "vkBeginCommandBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkEndCommandBuffer"_literal)>
{
    using type                 = PFN_vkEndCommandBuffer;
    static constexpr auto name = "vkEndCommandBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkResetCommandBuffer"_literal)>
{
    using type                 = PFN_vkResetCommandBuffer;
    static constexpr auto name = "vkResetCommandBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdBindPipeline"_literal)>
{
    using type                 = PFN_vkCmdBindPipeline;
    static constexpr auto name = "vkCmdBindPipeline"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetViewport"_literal)>
{
    using type                 = PFN_vkCmdSetViewport;
    static constexpr auto name = "vkCmdSetViewport"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetScissor"_literal)>
{
    using type                 = PFN_vkCmdSetScissor;
    static constexpr auto name = "vkCmdSetScissor"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetLineWidth"_literal)>
{
    using type                 = PFN_vkCmdSetLineWidth;
    static constexpr auto name = "vkCmdSetLineWidth"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthBias"_literal)>
{
    using type                 = PFN_vkCmdSetDepthBias;
    static constexpr auto name = "vkCmdSetDepthBias"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetBlendConstants"_literal)>
{
    using type                 = PFN_vkCmdSetBlendConstants;
    static constexpr auto name = "vkCmdSetBlendConstants"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthBounds"_literal)>
{
    using type                 = PFN_vkCmdSetDepthBounds;
    static constexpr auto name = "vkCmdSetDepthBounds"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetStencilCompareMask"_literal)>
{
    using type                 = PFN_vkCmdSetStencilCompareMask;
    static constexpr auto name = "vkCmdSetStencilCompareMask"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetStencilWriteMask"_literal)>
{
    using type                 = PFN_vkCmdSetStencilWriteMask;
    static constexpr auto name = "vkCmdSetStencilWriteMask"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetStencilReference"_literal)>
{
    using type                 = PFN_vkCmdSetStencilReference;
    static constexpr auto name = "vkCmdSetStencilReference"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdBindDescriptorSets"_literal)>
{
    using type                 = PFN_vkCmdBindDescriptorSets;
    static constexpr auto name = "vkCmdBindDescriptorSets"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdBindIndexBuffer"_literal)>
{
    using type                 = PFN_vkCmdBindIndexBuffer;
    static constexpr auto name = "vkCmdBindIndexBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdBindVertexBuffers"_literal)>
{
    using type                 = PFN_vkCmdBindVertexBuffers;
    static constexpr auto name = "vkCmdBindVertexBuffers"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdDraw"_literal)>
{
    using type                 = PFN_vkCmdDraw;
    static constexpr auto name = "vkCmdDraw"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndexed"_literal)>
{
    using type                 = PFN_vkCmdDrawIndexed;
    static constexpr auto name = "vkCmdDrawIndexed"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndirect"_literal)>
{
    using type                 = PFN_vkCmdDrawIndirect;
    static constexpr auto name = "vkCmdDrawIndirect"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndexedIndirect"_literal)>
{
    using type                 = PFN_vkCmdDrawIndexedIndirect;
    static constexpr auto name = "vkCmdDrawIndexedIndirect"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdDispatch"_literal)>
{
    using type                 = PFN_vkCmdDispatch;
    static constexpr auto name = "vkCmdDispatch"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdDispatchIndirect"_literal)>
{
    using type                 = PFN_vkCmdDispatchIndirect;
    static constexpr auto name = "vkCmdDispatchIndirect"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdCopyBuffer"_literal)>
{
    using type                 = PFN_vkCmdCopyBuffer;
    static constexpr auto name = "vkCmdCopyBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdCopyImage"_literal)>
{
    using type                 = PFN_vkCmdCopyImage;
    static constexpr auto name = "vkCmdCopyImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdBlitImage"_literal)>
{
    using type                 = PFN_vkCmdBlitImage;
    static constexpr auto name = "vkCmdBlitImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdCopyBufferToImage"_literal)>
{
    using type                 = PFN_vkCmdCopyBufferToImage;
    static constexpr auto name = "vkCmdCopyBufferToImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdCopyImageToBuffer"_literal)>
{
    using type                 = PFN_vkCmdCopyImageToBuffer;
    static constexpr auto name = "vkCmdCopyImageToBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdUpdateBuffer"_literal)>
{
    using type                 = PFN_vkCmdUpdateBuffer;
    static constexpr auto name = "vkCmdUpdateBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdFillBuffer"_literal)>
{
    using type                 = PFN_vkCmdFillBuffer;
    static constexpr auto name = "vkCmdFillBuffer"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdClearColorImage"_literal)>
{
    using type                 = PFN_vkCmdClearColorImage;
    static constexpr auto name = "vkCmdClearColorImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdClearDepthStencilImage"_literal)>
{
    using type                 = PFN_vkCmdClearDepthStencilImage;
    static constexpr auto name = "vkCmdClearDepthStencilImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdClearAttachments"_literal)>
{
    using type                 = PFN_vkCmdClearAttachments;
    static constexpr auto name = "vkCmdClearAttachments"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdResolveImage"_literal)>
{
    using type                 = PFN_vkCmdResolveImage;
    static constexpr auto name = "vkCmdResolveImage"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdSetEvent"_literal)>
{
    using type                 = PFN_vkCmdSetEvent;
    static constexpr auto name = "vkCmdSetEvent"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdResetEvent"_literal)>
{
    using type                 = PFN_vkCmdResetEvent;
    static constexpr auto name = "vkCmdResetEvent"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdWaitEvents"_literal)>
{
    using type                 = PFN_vkCmdWaitEvents;
    static constexpr auto name = "vkCmdWaitEvents"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdPipelineBarrier"_literal)>
{
    using type                 = PFN_vkCmdPipelineBarrier;
    static constexpr auto name = "vkCmdPipelineBarrier"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdBeginQuery"_literal)>
{
    using type                 = PFN_vkCmdBeginQuery;
    static constexpr auto name = "vkCmdBeginQuery"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdEndQuery"_literal)>
{
    using type                 = PFN_vkCmdEndQuery;
    static constexpr auto name = "vkCmdEndQuery"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdResetQueryPool"_literal)>
{
    using type                 = PFN_vkCmdResetQueryPool;
    static constexpr auto name = "vkCmdResetQueryPool"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdWriteTimestamp"_literal)>
{
    using type                 = PFN_vkCmdWriteTimestamp;
    static constexpr auto name = "vkCmdWriteTimestamp"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdCopyQueryPoolResults"_literal)>
{
    using type                 = PFN_vkCmdCopyQueryPoolResults;
    static constexpr auto name = "vkCmdCopyQueryPoolResults"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdPushConstants"_literal)>
{
    using type                 = PFN_vkCmdPushConstants;
    static constexpr auto name = "vkCmdPushConstants"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdBeginRenderPass"_literal)>
{
    using type                 = PFN_vkCmdBeginRenderPass;
    static constexpr auto name = "vkCmdBeginRenderPass"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdNextSubpass"_literal)>
{
    using type                 = PFN_vkCmdNextSubpass;
    static constexpr auto name = "vkCmdNextSubpass"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdEndRenderPass"_literal)>
{
    using type                 = PFN_vkCmdEndRenderPass;
    static constexpr auto name = "vkCmdEndRenderPass"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkCmdExecuteCommands"_literal)>
{
    using type                 = PFN_vkCmdExecuteCommands;
    static constexpr auto name = "vkCmdExecuteCommands"_literal;
};
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkEnumerateInstanceVersion"_literal)>
{
    using type                 = PFN_vkEnumerateInstanceVersion;
    static constexpr auto name = "vkEnumerateInstanceVersion"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkBindBufferMemory2"_literal)>
{
    using type                 = PFN_vkBindBufferMemory2;
    static constexpr auto name = "vkBindBufferMemory2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkBindImageMemory2"_literal)>
{
    using type                 = PFN_vkBindImageMemory2;
    static constexpr auto name = "vkBindImageMemory2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetDeviceGroupPeerMemoryFeatures"_literal)>
{
    using type                 = PFN_vkGetDeviceGroupPeerMemoryFeatures;
    static constexpr auto name = "vkGetDeviceGroupPeerMemoryFeatures"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkEnumeratePhysicalDeviceGroups"_literal)>
{
    using type                 = PFN_vkEnumeratePhysicalDeviceGroups;
    static constexpr auto name = "vkEnumeratePhysicalDeviceGroups"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetImageMemoryRequirements2"_literal)>
{
    using type                 = PFN_vkGetImageMemoryRequirements2;
    static constexpr auto name = "vkGetImageMemoryRequirements2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetBufferMemoryRequirements2"_literal)>
{
    using type                 = PFN_vkGetBufferMemoryRequirements2;
    static constexpr auto name = "vkGetBufferMemoryRequirements2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetImageSparseMemoryRequirements2"_literal)>
{
    using type                 = PFN_vkGetImageSparseMemoryRequirements2;
    static constexpr auto name = "vkGetImageSparseMemoryRequirements2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceFeatures2"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceFeatures2;
    static constexpr auto name = "vkGetPhysicalDeviceFeatures2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceProperties2"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceProperties2;
    static constexpr auto name = "vkGetPhysicalDeviceProperties2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceFormatProperties2"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceFormatProperties2;
    static constexpr auto name = "vkGetPhysicalDeviceFormatProperties2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceImageFormatProperties2"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceImageFormatProperties2;
    static constexpr auto name = "vkGetPhysicalDeviceImageFormatProperties2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceQueueFamilyProperties2"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceQueueFamilyProperties2;
    static constexpr auto name = "vkGetPhysicalDeviceQueueFamilyProperties2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceMemoryProperties2"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceMemoryProperties2;
    static constexpr auto name = "vkGetPhysicalDeviceMemoryProperties2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSparseImageFormatProperties2"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSparseImageFormatProperties2;
    static constexpr auto name = "vkGetPhysicalDeviceSparseImageFormatProperties2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkTrimCommandPool"_literal)>
{
    using type                 = PFN_vkTrimCommandPool;
    static constexpr auto name = "vkTrimCommandPool"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetDeviceQueue2"_literal)>
{
    using type                 = PFN_vkGetDeviceQueue2;
    static constexpr auto name = "vkGetDeviceQueue2"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkCreateSamplerYcbcrConversion"_literal)>
{
    using type                 = PFN_vkCreateSamplerYcbcrConversion;
    static constexpr auto name = "vkCreateSamplerYcbcrConversion"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkDestroySamplerYcbcrConversion"_literal)>
{
    using type                 = PFN_vkDestroySamplerYcbcrConversion;
    static constexpr auto name = "vkDestroySamplerYcbcrConversion"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkCreateDescriptorUpdateTemplate"_literal)>
{
    using type                 = PFN_vkCreateDescriptorUpdateTemplate;
    static constexpr auto name = "vkCreateDescriptorUpdateTemplate"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkDestroyDescriptorUpdateTemplate"_literal)>
{
    using type                 = PFN_vkDestroyDescriptorUpdateTemplate;
    static constexpr auto name = "vkDestroyDescriptorUpdateTemplate"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkUpdateDescriptorSetWithTemplate"_literal)>
{
    using type                 = PFN_vkUpdateDescriptorSetWithTemplate;
    static constexpr auto name = "vkUpdateDescriptorSetWithTemplate"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalBufferProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalBufferProperties;
    static constexpr auto name = "vkGetPhysicalDeviceExternalBufferProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalFenceProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalFenceProperties;
    static constexpr auto name = "vkGetPhysicalDeviceExternalFenceProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalSemaphoreProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalSemaphoreProperties;
    static constexpr auto name = "vkGetPhysicalDeviceExternalSemaphoreProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkGetDescriptorSetLayoutSupport"_literal)>
{
    using type                 = PFN_vkGetDescriptorSetLayoutSupport;
    static constexpr auto name = "vkGetDescriptorSetLayoutSupport"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkCmdSetDeviceMask"_literal)>
{
    using type                 = PFN_vkCmdSetDeviceMask;
    static constexpr auto name = "vkCmdSetDeviceMask"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct vk_function<compile_time_hash("vkCmdDispatchBase"_literal)>
{
    using type                 = PFN_vkCmdDispatchBase;
    static constexpr auto name = "vkCmdDispatchBase"_literal;
};
#endif // #if defined (VK_VERSION_1_1)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkCreateRenderPass2"_literal)>
{
    using type                 = PFN_vkCreateRenderPass2;
    static constexpr auto name = "vkCreateRenderPass2"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkResetQueryPool"_literal)>
{
    using type                 = PFN_vkResetQueryPool;
    static constexpr auto name = "vkResetQueryPool"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkGetSemaphoreCounterValue"_literal)>
{
    using type                 = PFN_vkGetSemaphoreCounterValue;
    static constexpr auto name = "vkGetSemaphoreCounterValue"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkWaitSemaphores"_literal)>
{
    using type                 = PFN_vkWaitSemaphores;
    static constexpr auto name = "vkWaitSemaphores"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkSignalSemaphore"_literal)>
{
    using type                 = PFN_vkSignalSemaphore;
    static constexpr auto name = "vkSignalSemaphore"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkGetBufferDeviceAddress"_literal)>
{
    using type                 = PFN_vkGetBufferDeviceAddress;
    static constexpr auto name = "vkGetBufferDeviceAddress"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkGetBufferOpaqueCaptureAddress"_literal)>
{
    using type                 = PFN_vkGetBufferOpaqueCaptureAddress;
    static constexpr auto name = "vkGetBufferOpaqueCaptureAddress"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkGetDeviceMemoryOpaqueCaptureAddress"_literal)>
{
    using type                 = PFN_vkGetDeviceMemoryOpaqueCaptureAddress;
    static constexpr auto name = "vkGetDeviceMemoryOpaqueCaptureAddress"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndirectCount"_literal)>
{
    using type                 = PFN_vkCmdDrawIndirectCount;
    static constexpr auto name = "vkCmdDrawIndirectCount"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndexedIndirectCount"_literal)>
{
    using type                 = PFN_vkCmdDrawIndexedIndirectCount;
    static constexpr auto name = "vkCmdDrawIndexedIndirectCount"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkCmdBeginRenderPass2"_literal)>
{
    using type                 = PFN_vkCmdBeginRenderPass2;
    static constexpr auto name = "vkCmdBeginRenderPass2"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkCmdNextSubpass2"_literal)>
{
    using type                 = PFN_vkCmdNextSubpass2;
    static constexpr auto name = "vkCmdNextSubpass2"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_2)
template<>
struct vk_function<compile_time_hash("vkCmdEndRenderPass2"_literal)>
{
    using type                 = PFN_vkCmdEndRenderPass2;
    static constexpr auto name = "vkCmdEndRenderPass2"_literal;
};
#endif // #if defined (VK_VERSION_1_2)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceToolProperties"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceToolProperties;
    static constexpr auto name = "vkGetPhysicalDeviceToolProperties"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCreatePrivateDataSlot"_literal)>
{
    using type                 = PFN_vkCreatePrivateDataSlot;
    static constexpr auto name = "vkCreatePrivateDataSlot"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkDestroyPrivateDataSlot"_literal)>
{
    using type                 = PFN_vkDestroyPrivateDataSlot;
    static constexpr auto name = "vkDestroyPrivateDataSlot"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkSetPrivateData"_literal)>
{
    using type                 = PFN_vkSetPrivateData;
    static constexpr auto name = "vkSetPrivateData"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkGetPrivateData"_literal)>
{
    using type                 = PFN_vkGetPrivateData;
    static constexpr auto name = "vkGetPrivateData"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkQueueSubmit2"_literal)>
{
    using type                 = PFN_vkQueueSubmit2;
    static constexpr auto name = "vkQueueSubmit2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkGetDeviceBufferMemoryRequirements"_literal)>
{
    using type                 = PFN_vkGetDeviceBufferMemoryRequirements;
    static constexpr auto name = "vkGetDeviceBufferMemoryRequirements"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkGetDeviceImageMemoryRequirements"_literal)>
{
    using type                 = PFN_vkGetDeviceImageMemoryRequirements;
    static constexpr auto name = "vkGetDeviceImageMemoryRequirements"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkGetDeviceImageSparseMemoryRequirements"_literal)>
{
    using type                 = PFN_vkGetDeviceImageSparseMemoryRequirements;
    static constexpr auto name = "vkGetDeviceImageSparseMemoryRequirements"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetEvent2"_literal)>
{
    using type                 = PFN_vkCmdSetEvent2;
    static constexpr auto name = "vkCmdSetEvent2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdResetEvent2"_literal)>
{
    using type                 = PFN_vkCmdResetEvent2;
    static constexpr auto name = "vkCmdResetEvent2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdWaitEvents2"_literal)>
{
    using type                 = PFN_vkCmdWaitEvents2;
    static constexpr auto name = "vkCmdWaitEvents2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdPipelineBarrier2"_literal)>
{
    using type                 = PFN_vkCmdPipelineBarrier2;
    static constexpr auto name = "vkCmdPipelineBarrier2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdWriteTimestamp2"_literal)>
{
    using type                 = PFN_vkCmdWriteTimestamp2;
    static constexpr auto name = "vkCmdWriteTimestamp2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdCopyBuffer2"_literal)>
{
    using type                 = PFN_vkCmdCopyBuffer2;
    static constexpr auto name = "vkCmdCopyBuffer2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdCopyImage2"_literal)>
{
    using type                 = PFN_vkCmdCopyImage2;
    static constexpr auto name = "vkCmdCopyImage2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdCopyBufferToImage2"_literal)>
{
    using type                 = PFN_vkCmdCopyBufferToImage2;
    static constexpr auto name = "vkCmdCopyBufferToImage2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdCopyImageToBuffer2"_literal)>
{
    using type                 = PFN_vkCmdCopyImageToBuffer2;
    static constexpr auto name = "vkCmdCopyImageToBuffer2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdBlitImage2"_literal)>
{
    using type                 = PFN_vkCmdBlitImage2;
    static constexpr auto name = "vkCmdBlitImage2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdResolveImage2"_literal)>
{
    using type                 = PFN_vkCmdResolveImage2;
    static constexpr auto name = "vkCmdResolveImage2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdBeginRendering"_literal)>
{
    using type                 = PFN_vkCmdBeginRendering;
    static constexpr auto name = "vkCmdBeginRendering"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdEndRendering"_literal)>
{
    using type                 = PFN_vkCmdEndRendering;
    static constexpr auto name = "vkCmdEndRendering"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetCullMode"_literal)>
{
    using type                 = PFN_vkCmdSetCullMode;
    static constexpr auto name = "vkCmdSetCullMode"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetFrontFace"_literal)>
{
    using type                 = PFN_vkCmdSetFrontFace;
    static constexpr auto name = "vkCmdSetFrontFace"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetPrimitiveTopology"_literal)>
{
    using type                 = PFN_vkCmdSetPrimitiveTopology;
    static constexpr auto name = "vkCmdSetPrimitiveTopology"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetViewportWithCount"_literal)>
{
    using type                 = PFN_vkCmdSetViewportWithCount;
    static constexpr auto name = "vkCmdSetViewportWithCount"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetScissorWithCount"_literal)>
{
    using type                 = PFN_vkCmdSetScissorWithCount;
    static constexpr auto name = "vkCmdSetScissorWithCount"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdBindVertexBuffers2"_literal)>
{
    using type                 = PFN_vkCmdBindVertexBuffers2;
    static constexpr auto name = "vkCmdBindVertexBuffers2"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthTestEnable"_literal)>
{
    using type                 = PFN_vkCmdSetDepthTestEnable;
    static constexpr auto name = "vkCmdSetDepthTestEnable"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthWriteEnable"_literal)>
{
    using type                 = PFN_vkCmdSetDepthWriteEnable;
    static constexpr auto name = "vkCmdSetDepthWriteEnable"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthCompareOp"_literal)>
{
    using type                 = PFN_vkCmdSetDepthCompareOp;
    static constexpr auto name = "vkCmdSetDepthCompareOp"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthBoundsTestEnable"_literal)>
{
    using type                 = PFN_vkCmdSetDepthBoundsTestEnable;
    static constexpr auto name = "vkCmdSetDepthBoundsTestEnable"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetStencilTestEnable"_literal)>
{
    using type                 = PFN_vkCmdSetStencilTestEnable;
    static constexpr auto name = "vkCmdSetStencilTestEnable"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetStencilOp"_literal)>
{
    using type                 = PFN_vkCmdSetStencilOp;
    static constexpr auto name = "vkCmdSetStencilOp"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetRasterizerDiscardEnable"_literal)>
{
    using type                 = PFN_vkCmdSetRasterizerDiscardEnable;
    static constexpr auto name = "vkCmdSetRasterizerDiscardEnable"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthBiasEnable"_literal)>
{
    using type                 = PFN_vkCmdSetDepthBiasEnable;
    static constexpr auto name = "vkCmdSetDepthBiasEnable"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_3)
template<>
struct vk_function<compile_time_hash("vkCmdSetPrimitiveRestartEnable"_literal)>
{
    using type                 = PFN_vkCmdSetPrimitiveRestartEnable;
    static constexpr auto name = "vkCmdSetPrimitiveRestartEnable"_literal;
};
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkMapMemory2"_literal)>
{
    using type                 = PFN_vkMapMemory2;
    static constexpr auto name = "vkMapMemory2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkUnmapMemory2"_literal)>
{
    using type                 = PFN_vkUnmapMemory2;
    static constexpr auto name = "vkUnmapMemory2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkGetRenderingAreaGranularity"_literal)>
{
    using type                 = PFN_vkGetRenderingAreaGranularity;
    static constexpr auto name = "vkGetRenderingAreaGranularity"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkGetDeviceImageSubresourceLayout"_literal)>
{
    using type                 = PFN_vkGetDeviceImageSubresourceLayout;
    static constexpr auto name = "vkGetDeviceImageSubresourceLayout"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkGetImageSubresourceLayout2"_literal)>
{
    using type                 = PFN_vkGetImageSubresourceLayout2;
    static constexpr auto name = "vkGetImageSubresourceLayout2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCopyMemoryToImage"_literal)>
{
    using type                 = PFN_vkCopyMemoryToImage;
    static constexpr auto name = "vkCopyMemoryToImage"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCopyImageToMemory"_literal)>
{
    using type                 = PFN_vkCopyImageToMemory;
    static constexpr auto name = "vkCopyImageToMemory"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCopyImageToImage"_literal)>
{
    using type                 = PFN_vkCopyImageToImage;
    static constexpr auto name = "vkCopyImageToImage"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkTransitionImageLayout"_literal)>
{
    using type                 = PFN_vkTransitionImageLayout;
    static constexpr auto name = "vkTransitionImageLayout"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdSetLineStipple"_literal)>
{
    using type                 = PFN_vkCmdSetLineStipple;
    static constexpr auto name = "vkCmdSetLineStipple"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdBindIndexBuffer2"_literal)>
{
    using type                 = PFN_vkCmdBindIndexBuffer2;
    static constexpr auto name = "vkCmdBindIndexBuffer2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSet"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSet;
    static constexpr auto name = "vkCmdPushDescriptorSet"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSetWithTemplate"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSetWithTemplate;
    static constexpr auto name = "vkCmdPushDescriptorSetWithTemplate"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdSetRenderingAttachmentLocations"_literal)>
{
    using type                 = PFN_vkCmdSetRenderingAttachmentLocations;
    static constexpr auto name = "vkCmdSetRenderingAttachmentLocations"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdSetRenderingInputAttachmentIndices"_literal)>
{
    using type                 = PFN_vkCmdSetRenderingInputAttachmentIndices;
    static constexpr auto name = "vkCmdSetRenderingInputAttachmentIndices"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdBindDescriptorSets2"_literal)>
{
    using type                 = PFN_vkCmdBindDescriptorSets2;
    static constexpr auto name = "vkCmdBindDescriptorSets2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdPushConstants2"_literal)>
{
    using type                 = PFN_vkCmdPushConstants2;
    static constexpr auto name = "vkCmdPushConstants2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSet2"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSet2;
    static constexpr auto name = "vkCmdPushDescriptorSet2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSetWithTemplate2"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSetWithTemplate2;
    static constexpr auto name = "vkCmdPushDescriptorSetWithTemplate2"_literal;
};
#endif // #if defined (VK_VERSION_1_4)

#if defined(VKSC_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetCommandPoolMemoryConsumption"_literal)>
{
    using type                 = PFN_vkGetCommandPoolMemoryConsumption;
    static constexpr auto name = "vkGetCommandPoolMemoryConsumption"_literal;
};
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VKSC_VERSION_1_0)
template<>
struct vk_function<compile_time_hash("vkGetFaultData"_literal)>
{
    using type                 = PFN_vkGetFaultData;
    static constexpr auto name = "vkGetFaultData"_literal;
};
#endif // #if defined (VKSC_VERSION_1_0)

#if defined(VK_KHR_surface)
template<>
struct vk_function<compile_time_hash("vkDestroySurfaceKHR"_literal)>
{
    using type                 = PFN_vkDestroySurfaceKHR;
    static constexpr auto name = "vkDestroySurfaceKHR"_literal;
};
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfaceSupportKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfaceSupportKHR;
    static constexpr auto name = "vkGetPhysicalDeviceSurfaceSupportKHR"_literal;
};
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfaceCapabilitiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"_literal;
};
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfaceFormatsKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfaceFormatsKHR;
    static constexpr auto name = "vkGetPhysicalDeviceSurfaceFormatsKHR"_literal;
};
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfacePresentModesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfacePresentModesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceSurfacePresentModesKHR"_literal;
};
#endif // #if defined (VK_KHR_surface)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkCreateSwapchainKHR"_literal)>
{
    using type                 = PFN_vkCreateSwapchainKHR;
    static constexpr auto name = "vkCreateSwapchainKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkDestroySwapchainKHR"_literal)>
{
    using type                 = PFN_vkDestroySwapchainKHR;
    static constexpr auto name = "vkDestroySwapchainKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkGetSwapchainImagesKHR"_literal)>
{
    using type                 = PFN_vkGetSwapchainImagesKHR;
    static constexpr auto name = "vkGetSwapchainImagesKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkAcquireNextImageKHR"_literal)>
{
    using type                 = PFN_vkAcquireNextImageKHR;
    static constexpr auto name = "vkAcquireNextImageKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkQueuePresentKHR"_literal)>
{
    using type                 = PFN_vkQueuePresentKHR;
    static constexpr auto name = "vkQueuePresentKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkGetDeviceGroupPresentCapabilitiesKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceGroupPresentCapabilitiesKHR;
    static constexpr auto name = "vkGetDeviceGroupPresentCapabilitiesKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkGetDeviceGroupSurfacePresentModesKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceGroupSurfacePresentModesKHR;
    static constexpr auto name = "vkGetDeviceGroupSurfacePresentModesKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDevicePresentRectanglesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDevicePresentRectanglesKHR;
    static constexpr auto name = "vkGetPhysicalDevicePresentRectanglesKHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_swapchain)
template<>
struct vk_function<compile_time_hash("vkAcquireNextImage2KHR"_literal)>
{
    using type                 = PFN_vkAcquireNextImage2KHR;
    static constexpr auto name = "vkAcquireNextImage2KHR"_literal;
};
#endif // #if defined (VK_KHR_swapchain)

#if defined(VK_KHR_display)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceDisplayPropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceDisplayPropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceDisplayPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceDisplayPlanePropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceDisplayPlanePropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct vk_function<compile_time_hash("vkGetDisplayPlaneSupportedDisplaysKHR"_literal)>
{
    using type                 = PFN_vkGetDisplayPlaneSupportedDisplaysKHR;
    static constexpr auto name = "vkGetDisplayPlaneSupportedDisplaysKHR"_literal;
};
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct vk_function<compile_time_hash("vkGetDisplayModePropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetDisplayModePropertiesKHR;
    static constexpr auto name = "vkGetDisplayModePropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct vk_function<compile_time_hash("vkCreateDisplayModeKHR"_literal)>
{
    using type                 = PFN_vkCreateDisplayModeKHR;
    static constexpr auto name = "vkCreateDisplayModeKHR"_literal;
};
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct vk_function<compile_time_hash("vkGetDisplayPlaneCapabilitiesKHR"_literal)>
{
    using type                 = PFN_vkGetDisplayPlaneCapabilitiesKHR;
    static constexpr auto name = "vkGetDisplayPlaneCapabilitiesKHR"_literal;
};
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display)
template<>
struct vk_function<compile_time_hash("vkCreateDisplayPlaneSurfaceKHR"_literal)>
{
    using type                 = PFN_vkCreateDisplayPlaneSurfaceKHR;
    static constexpr auto name = "vkCreateDisplayPlaneSurfaceKHR"_literal;
};
#endif // #if defined (VK_KHR_display)

#if defined(VK_KHR_display_swapchain)
template<>
struct vk_function<compile_time_hash("vkCreateSharedSwapchainsKHR"_literal)>
{
    using type                 = PFN_vkCreateSharedSwapchainsKHR;
    static constexpr auto name = "vkCreateSharedSwapchainsKHR"_literal;
};
#endif // #if defined (VK_KHR_display_swapchain)

#if defined(VK_KHR_xlib_surface)
template<>
struct vk_function<compile_time_hash("vkCreateXlibSurfaceKHR"_literal)>
{
    using type                 = PFN_vkCreateXlibSurfaceKHR;
    static constexpr auto name = "vkCreateXlibSurfaceKHR"_literal;
};
#endif // #if defined (VK_KHR_xlib_surface)

#if defined(VK_KHR_xlib_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceXlibPresentationSupportKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR;
    static constexpr auto name = "vkGetPhysicalDeviceXlibPresentationSupportKHR"_literal;
};
#endif // #if defined (VK_KHR_xlib_surface)

#if defined(VK_KHR_xcb_surface)
template<>
struct vk_function<compile_time_hash("vkCreateXcbSurfaceKHR"_literal)>
{
    using type                 = PFN_vkCreateXcbSurfaceKHR;
    static constexpr auto name = "vkCreateXcbSurfaceKHR"_literal;
};
#endif // #if defined (VK_KHR_xcb_surface)

#if defined(VK_KHR_xcb_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceXcbPresentationSupportKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR;
    static constexpr auto name = "vkGetPhysicalDeviceXcbPresentationSupportKHR"_literal;
};
#endif // #if defined (VK_KHR_xcb_surface)

#if defined(VK_KHR_wayland_surface)
template<>
struct vk_function<compile_time_hash("vkCreateWaylandSurfaceKHR"_literal)>
{
    using type                 = PFN_vkCreateWaylandSurfaceKHR;
    static constexpr auto name = "vkCreateWaylandSurfaceKHR"_literal;
};
#endif // #if defined (VK_KHR_wayland_surface)

#if defined(VK_KHR_wayland_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceWaylandPresentationSupportKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR;
    static constexpr auto name = "vkGetPhysicalDeviceWaylandPresentationSupportKHR"_literal;
};
#endif // #if defined (VK_KHR_wayland_surface)

#if defined(VK_KHR_android_surface)
template<>
struct vk_function<compile_time_hash("vkCreateAndroidSurfaceKHR"_literal)>
{
    using type                 = PFN_vkCreateAndroidSurfaceKHR;
    static constexpr auto name = "vkCreateAndroidSurfaceKHR"_literal;
};
#endif // #if defined (VK_KHR_android_surface)

#if defined(VK_KHR_win32_surface)
template<>
struct vk_function<compile_time_hash("vkCreateWin32SurfaceKHR"_literal)>
{
    using type                 = PFN_vkCreateWin32SurfaceKHR;
    static constexpr auto name = "vkCreateWin32SurfaceKHR"_literal;
};
#endif // #if defined (VK_KHR_win32_surface)

#if defined(VK_KHR_win32_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceWin32PresentationSupportKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR;
    static constexpr auto name = "vkGetPhysicalDeviceWin32PresentationSupportKHR"_literal;
};
#endif // #if defined (VK_KHR_win32_surface)

#if defined(VK_EXT_debug_report)
template<>
struct vk_function<compile_time_hash("vkCreateDebugReportCallbackEXT"_literal)>
{
    using type                 = PFN_vkCreateDebugReportCallbackEXT;
    static constexpr auto name = "vkCreateDebugReportCallbackEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report)
template<>
struct vk_function<compile_time_hash("vkDestroyDebugReportCallbackEXT"_literal)>
{
    using type                 = PFN_vkDestroyDebugReportCallbackEXT;
    static constexpr auto name = "vkDestroyDebugReportCallbackEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_report)
template<>
struct vk_function<compile_time_hash("vkDebugReportMessageEXT"_literal)>
{
    using type                 = PFN_vkDebugReportMessageEXT;
    static constexpr auto name = "vkDebugReportMessageEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_report)

#if defined(VK_EXT_debug_marker)
template<>
struct vk_function<compile_time_hash("vkDebugMarkerSetObjectTagEXT"_literal)>
{
    using type                 = PFN_vkDebugMarkerSetObjectTagEXT;
    static constexpr auto name = "vkDebugMarkerSetObjectTagEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct vk_function<compile_time_hash("vkDebugMarkerSetObjectNameEXT"_literal)>
{
    using type                 = PFN_vkDebugMarkerSetObjectNameEXT;
    static constexpr auto name = "vkDebugMarkerSetObjectNameEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct vk_function<compile_time_hash("vkCmdDebugMarkerBeginEXT"_literal)>
{
    using type                 = PFN_vkCmdDebugMarkerBeginEXT;
    static constexpr auto name = "vkCmdDebugMarkerBeginEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct vk_function<compile_time_hash("vkCmdDebugMarkerEndEXT"_literal)>
{
    using type                 = PFN_vkCmdDebugMarkerEndEXT;
    static constexpr auto name = "vkCmdDebugMarkerEndEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_EXT_debug_marker)
template<>
struct vk_function<compile_time_hash("vkCmdDebugMarkerInsertEXT"_literal)>
{
    using type                 = PFN_vkCmdDebugMarkerInsertEXT;
    static constexpr auto name = "vkCmdDebugMarkerInsertEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_marker)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceVideoCapabilitiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceVideoCapabilitiesKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceVideoFormatPropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceVideoFormatPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkCreateVideoSessionKHR"_literal)>
{
    using type                 = PFN_vkCreateVideoSessionKHR;
    static constexpr auto name = "vkCreateVideoSessionKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkDestroyVideoSessionKHR"_literal)>
{
    using type                 = PFN_vkDestroyVideoSessionKHR;
    static constexpr auto name = "vkDestroyVideoSessionKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkGetVideoSessionMemoryRequirementsKHR"_literal)>
{
    using type                 = PFN_vkGetVideoSessionMemoryRequirementsKHR;
    static constexpr auto name = "vkGetVideoSessionMemoryRequirementsKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkBindVideoSessionMemoryKHR"_literal)>
{
    using type                 = PFN_vkBindVideoSessionMemoryKHR;
    static constexpr auto name = "vkBindVideoSessionMemoryKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkCreateVideoSessionParametersKHR"_literal)>
{
    using type                 = PFN_vkCreateVideoSessionParametersKHR;
    static constexpr auto name = "vkCreateVideoSessionParametersKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkUpdateVideoSessionParametersKHR"_literal)>
{
    using type                 = PFN_vkUpdateVideoSessionParametersKHR;
    static constexpr auto name = "vkUpdateVideoSessionParametersKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkDestroyVideoSessionParametersKHR"_literal)>
{
    using type                 = PFN_vkDestroyVideoSessionParametersKHR;
    static constexpr auto name = "vkDestroyVideoSessionParametersKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkCmdBeginVideoCodingKHR"_literal)>
{
    using type                 = PFN_vkCmdBeginVideoCodingKHR;
    static constexpr auto name = "vkCmdBeginVideoCodingKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkCmdEndVideoCodingKHR"_literal)>
{
    using type                 = PFN_vkCmdEndVideoCodingKHR;
    static constexpr auto name = "vkCmdEndVideoCodingKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct vk_function<compile_time_hash("vkCmdControlVideoCodingKHR"_literal)>
{
    using type                 = PFN_vkCmdControlVideoCodingKHR;
    static constexpr auto name = "vkCmdControlVideoCodingKHR"_literal;
};
#endif // #if defined (VK_KHR_video_queue)

#if defined(VK_KHR_video_decode_queue)
template<>
struct vk_function<compile_time_hash("vkCmdDecodeVideoKHR"_literal)>
{
    using type                 = PFN_vkCmdDecodeVideoKHR;
    static constexpr auto name = "vkCmdDecodeVideoKHR"_literal;
};
#endif // #if defined (VK_KHR_video_decode_queue)

#if defined(VK_EXT_transform_feedback)
template<>
struct vk_function<compile_time_hash("vkCmdBindTransformFeedbackBuffersEXT"_literal)>
{
    using type                 = PFN_vkCmdBindTransformFeedbackBuffersEXT;
    static constexpr auto name = "vkCmdBindTransformFeedbackBuffersEXT"_literal;
};
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct vk_function<compile_time_hash("vkCmdBeginTransformFeedbackEXT"_literal)>
{
    using type                 = PFN_vkCmdBeginTransformFeedbackEXT;
    static constexpr auto name = "vkCmdBeginTransformFeedbackEXT"_literal;
};
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct vk_function<compile_time_hash("vkCmdEndTransformFeedbackEXT"_literal)>
{
    using type                 = PFN_vkCmdEndTransformFeedbackEXT;
    static constexpr auto name = "vkCmdEndTransformFeedbackEXT"_literal;
};
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct vk_function<compile_time_hash("vkCmdBeginQueryIndexedEXT"_literal)>
{
    using type                 = PFN_vkCmdBeginQueryIndexedEXT;
    static constexpr auto name = "vkCmdBeginQueryIndexedEXT"_literal;
};
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct vk_function<compile_time_hash("vkCmdEndQueryIndexedEXT"_literal)>
{
    using type                 = PFN_vkCmdEndQueryIndexedEXT;
    static constexpr auto name = "vkCmdEndQueryIndexedEXT"_literal;
};
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_EXT_transform_feedback)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndirectByteCountEXT"_literal)>
{
    using type                 = PFN_vkCmdDrawIndirectByteCountEXT;
    static constexpr auto name = "vkCmdDrawIndirectByteCountEXT"_literal;
};
#endif // #if defined (VK_EXT_transform_feedback)

#if defined(VK_NVX_binary_import)
template<>
struct vk_function<compile_time_hash("vkCreateCuModuleNVX"_literal)>
{
    using type                 = PFN_vkCreateCuModuleNVX;
    static constexpr auto name = "vkCreateCuModuleNVX"_literal;
};
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct vk_function<compile_time_hash("vkCreateCuFunctionNVX"_literal)>
{
    using type                 = PFN_vkCreateCuFunctionNVX;
    static constexpr auto name = "vkCreateCuFunctionNVX"_literal;
};
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct vk_function<compile_time_hash("vkDestroyCuModuleNVX"_literal)>
{
    using type                 = PFN_vkDestroyCuModuleNVX;
    static constexpr auto name = "vkDestroyCuModuleNVX"_literal;
};
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct vk_function<compile_time_hash("vkDestroyCuFunctionNVX"_literal)>
{
    using type                 = PFN_vkDestroyCuFunctionNVX;
    static constexpr auto name = "vkDestroyCuFunctionNVX"_literal;
};
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct vk_function<compile_time_hash("vkCmdCuLaunchKernelNVX"_literal)>
{
    using type                 = PFN_vkCmdCuLaunchKernelNVX;
    static constexpr auto name = "vkCmdCuLaunchKernelNVX"_literal;
};
#endif // #if defined (VK_NVX_binary_import)

#if defined(VK_NVX_image_view_handle)
template<>
struct vk_function<compile_time_hash("vkGetImageViewHandleNVX"_literal)>
{
    using type                 = PFN_vkGetImageViewHandleNVX;
    static constexpr auto name = "vkGetImageViewHandleNVX"_literal;
};
#endif // #if defined (VK_NVX_image_view_handle)

#if defined(VK_NVX_image_view_handle)
template<>
struct vk_function<compile_time_hash("vkGetImageViewHandle64NVX"_literal)>
{
    using type                 = PFN_vkGetImageViewHandle64NVX;
    static constexpr auto name = "vkGetImageViewHandle64NVX"_literal;
};
#endif // #if defined (VK_NVX_image_view_handle)

#if defined(VK_NVX_image_view_handle)
template<>
struct vk_function<compile_time_hash("vkGetImageViewAddressNVX"_literal)>
{
    using type                 = PFN_vkGetImageViewAddressNVX;
    static constexpr auto name = "vkGetImageViewAddressNVX"_literal;
};
#endif // #if defined (VK_NVX_image_view_handle)

#if defined(VK_AMD_draw_indirect_count)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndirectCountAMD"_literal)>
{
    using type                 = PFN_vkCmdDrawIndirectCountAMD;
    static constexpr auto name = "vkCmdDrawIndirectCountAMD"_literal;
};
#endif // #if defined (VK_AMD_draw_indirect_count)

#if defined(VK_AMD_draw_indirect_count)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndexedIndirectCountAMD"_literal)>
{
    using type                 = PFN_vkCmdDrawIndexedIndirectCountAMD;
    static constexpr auto name = "vkCmdDrawIndexedIndirectCountAMD"_literal;
};
#endif // #if defined (VK_AMD_draw_indirect_count)

#if defined(VK_AMD_shader_info)
template<>
struct vk_function<compile_time_hash("vkGetShaderInfoAMD"_literal)>
{
    using type                 = PFN_vkGetShaderInfoAMD;
    static constexpr auto name = "vkGetShaderInfoAMD"_literal;
};
#endif // #if defined (VK_AMD_shader_info)

#if defined(VK_KHR_dynamic_rendering)
template<>
struct vk_function<compile_time_hash("vkCmdBeginRenderingKHR"_literal)>
{
    using type                 = PFN_vkCmdBeginRenderingKHR;
    static constexpr auto name = "vkCmdBeginRenderingKHR"_literal;
};
#endif // #if defined (VK_KHR_dynamic_rendering)

#if defined(VK_KHR_dynamic_rendering)
template<>
struct vk_function<compile_time_hash("vkCmdEndRenderingKHR"_literal)>
{
    using type                 = PFN_vkCmdEndRenderingKHR;
    static constexpr auto name = "vkCmdEndRenderingKHR"_literal;
};
#endif // #if defined (VK_KHR_dynamic_rendering)

#if defined(VK_GGP_stream_descriptor_surface)
template<>
struct vk_function<compile_time_hash("vkCreateStreamDescriptorSurfaceGGP"_literal)>
{
    using type                 = PFN_vkCreateStreamDescriptorSurfaceGGP;
    static constexpr auto name = "vkCreateStreamDescriptorSurfaceGGP"_literal;
};
#endif // #if defined (VK_GGP_stream_descriptor_surface)

#if defined(VK_NV_external_memory_capabilities)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalImageFormatPropertiesNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
    static constexpr auto name = "vkGetPhysicalDeviceExternalImageFormatPropertiesNV"_literal;
};
#endif // #if defined (VK_NV_external_memory_capabilities)

#if defined(VK_NV_external_memory_win32)
template<>
struct vk_function<compile_time_hash("vkGetMemoryWin32HandleNV"_literal)>
{
    using type                 = PFN_vkGetMemoryWin32HandleNV;
    static constexpr auto name = "vkGetMemoryWin32HandleNV"_literal;
};
#endif // #if defined (VK_NV_external_memory_win32)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceFeatures2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceFeatures2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceFeatures2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceFormatProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceFormatProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceFormatProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceImageFormatProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceImageFormatProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceImageFormatProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceQueueFamilyProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceQueueFamilyProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceMemoryProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceMemoryProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceMemoryProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_get_physical_device_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSparseImageFormatProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceSparseImageFormatProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_device_group)
template<>
struct vk_function<compile_time_hash("vkGetDeviceGroupPeerMemoryFeaturesKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR;
    static constexpr auto name = "vkGetDeviceGroupPeerMemoryFeaturesKHR"_literal;
};
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_KHR_device_group)
template<>
struct vk_function<compile_time_hash("vkCmdSetDeviceMaskKHR"_literal)>
{
    using type                 = PFN_vkCmdSetDeviceMaskKHR;
    static constexpr auto name = "vkCmdSetDeviceMaskKHR"_literal;
};
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_KHR_device_group)
template<>
struct vk_function<compile_time_hash("vkCmdDispatchBaseKHR"_literal)>
{
    using type                 = PFN_vkCmdDispatchBaseKHR;
    static constexpr auto name = "vkCmdDispatchBaseKHR"_literal;
};
#endif // #if defined (VK_KHR_device_group)

#if defined(VK_NN_vi_surface)
template<>
struct vk_function<compile_time_hash("vkCreateViSurfaceNN"_literal)>
{
    using type                 = PFN_vkCreateViSurfaceNN;
    static constexpr auto name = "vkCreateViSurfaceNN"_literal;
};
#endif // #if defined (VK_NN_vi_surface)

#if defined(VK_KHR_maintenance1)
template<>
struct vk_function<compile_time_hash("vkTrimCommandPoolKHR"_literal)>
{
    using type                 = PFN_vkTrimCommandPoolKHR;
    static constexpr auto name = "vkTrimCommandPoolKHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance1)

#if defined(VK_KHR_device_group_creation)
template<>
struct vk_function<compile_time_hash("vkEnumeratePhysicalDeviceGroupsKHR"_literal)>
{
    using type                 = PFN_vkEnumeratePhysicalDeviceGroupsKHR;
    static constexpr auto name = "vkEnumeratePhysicalDeviceGroupsKHR"_literal;
};
#endif // #if defined (VK_KHR_device_group_creation)

#if defined(VK_KHR_external_memory_capabilities)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalBufferPropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceExternalBufferPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_external_memory_capabilities)

#if defined(VK_KHR_external_memory_win32)
template<>
struct vk_function<compile_time_hash("vkGetMemoryWin32HandleKHR"_literal)>
{
    using type                 = PFN_vkGetMemoryWin32HandleKHR;
    static constexpr auto name = "vkGetMemoryWin32HandleKHR"_literal;
};
#endif // #if defined (VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_win32)
template<>
struct vk_function<compile_time_hash("vkGetMemoryWin32HandlePropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetMemoryWin32HandlePropertiesKHR;
    static constexpr auto name = "vkGetMemoryWin32HandlePropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)
template<>
struct vk_function<compile_time_hash("vkGetMemoryFdKHR"_literal)>
{
    using type                 = PFN_vkGetMemoryFdKHR;
    static constexpr auto name = "vkGetMemoryFdKHR"_literal;
};
#endif // #if defined (VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_memory_fd)
template<>
struct vk_function<compile_time_hash("vkGetMemoryFdPropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetMemoryFdPropertiesKHR;
    static constexpr auto name = "vkGetMemoryFdPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_semaphore_capabilities)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalSemaphorePropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_external_semaphore_capabilities)

#if defined(VK_KHR_external_semaphore_win32)
template<>
struct vk_function<compile_time_hash("vkImportSemaphoreWin32HandleKHR"_literal)>
{
    using type                 = PFN_vkImportSemaphoreWin32HandleKHR;
    static constexpr auto name = "vkImportSemaphoreWin32HandleKHR"_literal;
};
#endif // #if defined (VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_win32)
template<>
struct vk_function<compile_time_hash("vkGetSemaphoreWin32HandleKHR"_literal)>
{
    using type                 = PFN_vkGetSemaphoreWin32HandleKHR;
    static constexpr auto name = "vkGetSemaphoreWin32HandleKHR"_literal;
};
#endif // #if defined (VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)
template<>
struct vk_function<compile_time_hash("vkImportSemaphoreFdKHR"_literal)>
{
    using type                 = PFN_vkImportSemaphoreFdKHR;
    static constexpr auto name = "vkImportSemaphoreFdKHR"_literal;
};
#endif // #if defined (VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_external_semaphore_fd)
template<>
struct vk_function<compile_time_hash("vkGetSemaphoreFdKHR"_literal)>
{
    using type                 = PFN_vkGetSemaphoreFdKHR;
    static constexpr auto name = "vkGetSemaphoreFdKHR"_literal;
};
#endif // #if defined (VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_push_descriptor)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSetKHR"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSetKHR;
    static constexpr auto name = "vkCmdPushDescriptorSetKHR"_literal;
};
#endif // #if defined (VK_KHR_push_descriptor)

#if defined(VK_KHR_push_descriptor)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSetWithTemplateKHR"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSetWithTemplateKHR;
    static constexpr auto name = "vkCmdPushDescriptorSetWithTemplateKHR"_literal;
};
#endif // #if defined (VK_KHR_push_descriptor)

#if defined(VK_EXT_conditional_rendering)
template<>
struct vk_function<compile_time_hash("vkCmdBeginConditionalRenderingEXT"_literal)>
{
    using type                 = PFN_vkCmdBeginConditionalRenderingEXT;
    static constexpr auto name = "vkCmdBeginConditionalRenderingEXT"_literal;
};
#endif // #if defined (VK_EXT_conditional_rendering)

#if defined(VK_EXT_conditional_rendering)
template<>
struct vk_function<compile_time_hash("vkCmdEndConditionalRenderingEXT"_literal)>
{
    using type                 = PFN_vkCmdEndConditionalRenderingEXT;
    static constexpr auto name = "vkCmdEndConditionalRenderingEXT"_literal;
};
#endif // #if defined (VK_EXT_conditional_rendering)

#if defined(VK_KHR_descriptor_update_template)
template<>
struct vk_function<compile_time_hash("vkCreateDescriptorUpdateTemplateKHR"_literal)>
{
    using type                 = PFN_vkCreateDescriptorUpdateTemplateKHR;
    static constexpr auto name = "vkCreateDescriptorUpdateTemplateKHR"_literal;
};
#endif // #if defined (VK_KHR_descriptor_update_template)

#if defined(VK_KHR_descriptor_update_template)
template<>
struct vk_function<compile_time_hash("vkDestroyDescriptorUpdateTemplateKHR"_literal)>
{
    using type                 = PFN_vkDestroyDescriptorUpdateTemplateKHR;
    static constexpr auto name = "vkDestroyDescriptorUpdateTemplateKHR"_literal;
};
#endif // #if defined (VK_KHR_descriptor_update_template)

#if defined(VK_KHR_descriptor_update_template)
template<>
struct vk_function<compile_time_hash("vkUpdateDescriptorSetWithTemplateKHR"_literal)>
{
    using type                 = PFN_vkUpdateDescriptorSetWithTemplateKHR;
    static constexpr auto name = "vkUpdateDescriptorSetWithTemplateKHR"_literal;
};
#endif // #if defined (VK_KHR_descriptor_update_template)

#if defined(VK_NV_clip_space_w_scaling)
template<>
struct vk_function<compile_time_hash("vkCmdSetViewportWScalingNV"_literal)>
{
    using type                 = PFN_vkCmdSetViewportWScalingNV;
    static constexpr auto name = "vkCmdSetViewportWScalingNV"_literal;
};
#endif // #if defined (VK_NV_clip_space_w_scaling)

#if defined(VK_EXT_direct_mode_display)
template<>
struct vk_function<compile_time_hash("vkReleaseDisplayEXT"_literal)>
{
    using type                 = PFN_vkReleaseDisplayEXT;
    static constexpr auto name = "vkReleaseDisplayEXT"_literal;
};
#endif // #if defined (VK_EXT_direct_mode_display)

#if defined(VK_EXT_acquire_xlib_display)
template<>
struct vk_function<compile_time_hash("vkAcquireXlibDisplayEXT"_literal)>
{
    using type                 = PFN_vkAcquireXlibDisplayEXT;
    static constexpr auto name = "vkAcquireXlibDisplayEXT"_literal;
};
#endif // #if defined (VK_EXT_acquire_xlib_display)

#if defined(VK_EXT_acquire_xlib_display)
template<>
struct vk_function<compile_time_hash("vkGetRandROutputDisplayEXT"_literal)>
{
    using type                 = PFN_vkGetRandROutputDisplayEXT;
    static constexpr auto name = "vkGetRandROutputDisplayEXT"_literal;
};
#endif // #if defined (VK_EXT_acquire_xlib_display)

#if defined(VK_EXT_display_surface_counter)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfaceCapabilities2EXT"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT;
    static constexpr auto name = "vkGetPhysicalDeviceSurfaceCapabilities2EXT"_literal;
};
#endif // #if defined (VK_EXT_display_surface_counter)

#if defined(VK_EXT_display_control)
template<>
struct vk_function<compile_time_hash("vkDisplayPowerControlEXT"_literal)>
{
    using type                 = PFN_vkDisplayPowerControlEXT;
    static constexpr auto name = "vkDisplayPowerControlEXT"_literal;
};
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_EXT_display_control)
template<>
struct vk_function<compile_time_hash("vkRegisterDeviceEventEXT"_literal)>
{
    using type                 = PFN_vkRegisterDeviceEventEXT;
    static constexpr auto name = "vkRegisterDeviceEventEXT"_literal;
};
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_EXT_display_control)
template<>
struct vk_function<compile_time_hash("vkRegisterDisplayEventEXT"_literal)>
{
    using type                 = PFN_vkRegisterDisplayEventEXT;
    static constexpr auto name = "vkRegisterDisplayEventEXT"_literal;
};
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_EXT_display_control)
template<>
struct vk_function<compile_time_hash("vkGetSwapchainCounterEXT"_literal)>
{
    using type                 = PFN_vkGetSwapchainCounterEXT;
    static constexpr auto name = "vkGetSwapchainCounterEXT"_literal;
};
#endif // #if defined (VK_EXT_display_control)

#if defined(VK_GOOGLE_display_timing)
template<>
struct vk_function<compile_time_hash("vkGetRefreshCycleDurationGOOGLE"_literal)>
{
    using type                 = PFN_vkGetRefreshCycleDurationGOOGLE;
    static constexpr auto name = "vkGetRefreshCycleDurationGOOGLE"_literal;
};
#endif // #if defined (VK_GOOGLE_display_timing)

#if defined(VK_GOOGLE_display_timing)
template<>
struct vk_function<compile_time_hash("vkGetPastPresentationTimingGOOGLE"_literal)>
{
    using type                 = PFN_vkGetPastPresentationTimingGOOGLE;
    static constexpr auto name = "vkGetPastPresentationTimingGOOGLE"_literal;
};
#endif // #if defined (VK_GOOGLE_display_timing)

#if defined(VK_EXT_discard_rectangles)
template<>
struct vk_function<compile_time_hash("vkCmdSetDiscardRectangleEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDiscardRectangleEXT;
    static constexpr auto name = "vkCmdSetDiscardRectangleEXT"_literal;
};
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles)
template<>
struct vk_function<compile_time_hash("vkCmdSetDiscardRectangleEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDiscardRectangleEnableEXT;
    static constexpr auto name = "vkCmdSetDiscardRectangleEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_EXT_discard_rectangles)
template<>
struct vk_function<compile_time_hash("vkCmdSetDiscardRectangleModeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDiscardRectangleModeEXT;
    static constexpr auto name = "vkCmdSetDiscardRectangleModeEXT"_literal;
};
#endif // #if defined (VK_EXT_discard_rectangles)

#if defined(VK_EXT_hdr_metadata)
template<>
struct vk_function<compile_time_hash("vkSetHdrMetadataEXT"_literal)>
{
    using type                 = PFN_vkSetHdrMetadataEXT;
    static constexpr auto name = "vkSetHdrMetadataEXT"_literal;
};
#endif // #if defined (VK_EXT_hdr_metadata)

#if defined(VK_KHR_create_renderpass2)
template<>
struct vk_function<compile_time_hash("vkCreateRenderPass2KHR"_literal)>
{
    using type                 = PFN_vkCreateRenderPass2KHR;
    static constexpr auto name = "vkCreateRenderPass2KHR"_literal;
};
#endif // #if defined (VK_KHR_create_renderpass2)

#if defined(VK_KHR_create_renderpass2)
template<>
struct vk_function<compile_time_hash("vkCmdBeginRenderPass2KHR"_literal)>
{
    using type                 = PFN_vkCmdBeginRenderPass2KHR;
    static constexpr auto name = "vkCmdBeginRenderPass2KHR"_literal;
};
#endif // #if defined (VK_KHR_create_renderpass2)

#if defined(VK_KHR_create_renderpass2)
template<>
struct vk_function<compile_time_hash("vkCmdNextSubpass2KHR"_literal)>
{
    using type                 = PFN_vkCmdNextSubpass2KHR;
    static constexpr auto name = "vkCmdNextSubpass2KHR"_literal;
};
#endif // #if defined (VK_KHR_create_renderpass2)

#if defined(VK_KHR_create_renderpass2)
template<>
struct vk_function<compile_time_hash("vkCmdEndRenderPass2KHR"_literal)>
{
    using type                 = PFN_vkCmdEndRenderPass2KHR;
    static constexpr auto name = "vkCmdEndRenderPass2KHR"_literal;
};
#endif // #if defined (VK_KHR_create_renderpass2)

#if defined(VK_KHR_shared_presentable_image)
template<>
struct vk_function<compile_time_hash("vkGetSwapchainStatusKHR"_literal)>
{
    using type                 = PFN_vkGetSwapchainStatusKHR;
    static constexpr auto name = "vkGetSwapchainStatusKHR"_literal;
};
#endif // #if defined (VK_KHR_shared_presentable_image)

#if defined(VK_KHR_external_fence_capabilities)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalFencePropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceExternalFencePropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_external_fence_capabilities)

#if defined(VK_KHR_external_fence_win32)
template<>
struct vk_function<compile_time_hash("vkImportFenceWin32HandleKHR"_literal)>
{
    using type                 = PFN_vkImportFenceWin32HandleKHR;
    static constexpr auto name = "vkImportFenceWin32HandleKHR"_literal;
};
#endif // #if defined (VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_win32)
template<>
struct vk_function<compile_time_hash("vkGetFenceWin32HandleKHR"_literal)>
{
    using type                 = PFN_vkGetFenceWin32HandleKHR;
    static constexpr auto name = "vkGetFenceWin32HandleKHR"_literal;
};
#endif // #if defined (VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)
template<>
struct vk_function<compile_time_hash("vkImportFenceFdKHR"_literal)>
{
    using type                 = PFN_vkImportFenceFdKHR;
    static constexpr auto name = "vkImportFenceFdKHR"_literal;
};
#endif // #if defined (VK_KHR_external_fence_fd)

#if defined(VK_KHR_external_fence_fd)
template<>
struct vk_function<compile_time_hash("vkGetFenceFdKHR"_literal)>
{
    using type                 = PFN_vkGetFenceFdKHR;
    static constexpr auto name = "vkGetFenceFdKHR"_literal;
};
#endif // #if defined (VK_KHR_external_fence_fd)

#if defined(VK_KHR_performance_query)
template<>
struct vk_function<compile_time_hash("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR"_literal)>
{
    using type                 = PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
    static constexpr auto name = "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR"_literal;
};
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR"_literal;
};
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
template<>
struct vk_function<compile_time_hash("vkAcquireProfilingLockKHR"_literal)>
{
    using type                 = PFN_vkAcquireProfilingLockKHR;
    static constexpr auto name = "vkAcquireProfilingLockKHR"_literal;
};
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_performance_query)
template<>
struct vk_function<compile_time_hash("vkReleaseProfilingLockKHR"_literal)>
{
    using type                 = PFN_vkReleaseProfilingLockKHR;
    static constexpr auto name = "vkReleaseProfilingLockKHR"_literal;
};
#endif // #if defined (VK_KHR_performance_query)

#if defined(VK_KHR_get_surface_capabilities2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfaceCapabilities2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceSurfaceCapabilities2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_surface_capabilities2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfaceFormats2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfaceFormats2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceSurfaceFormats2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceDisplayProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceDisplayProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceDisplayProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceDisplayPlaneProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
    static constexpr auto name = "vkGetPhysicalDeviceDisplayPlaneProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct vk_function<compile_time_hash("vkGetDisplayModeProperties2KHR"_literal)>
{
    using type                 = PFN_vkGetDisplayModeProperties2KHR;
    static constexpr auto name = "vkGetDisplayModeProperties2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_KHR_get_display_properties2)
template<>
struct vk_function<compile_time_hash("vkGetDisplayPlaneCapabilities2KHR"_literal)>
{
    using type                 = PFN_vkGetDisplayPlaneCapabilities2KHR;
    static constexpr auto name = "vkGetDisplayPlaneCapabilities2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_display_properties2)

#if defined(VK_MVK_ios_surface)
template<>
struct vk_function<compile_time_hash("vkCreateIOSSurfaceMVK"_literal)>
{
    using type                 = PFN_vkCreateIOSSurfaceMVK;
    static constexpr auto name = "vkCreateIOSSurfaceMVK"_literal;
};
#endif // #if defined (VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)
template<>
struct vk_function<compile_time_hash("vkCreateMacOSSurfaceMVK"_literal)>
{
    using type                 = PFN_vkCreateMacOSSurfaceMVK;
    static constexpr auto name = "vkCreateMacOSSurfaceMVK"_literal;
};
#endif // #if defined (VK_MVK_macos_surface)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkSetDebugUtilsObjectNameEXT"_literal)>
{
    using type                 = PFN_vkSetDebugUtilsObjectNameEXT;
    static constexpr auto name = "vkSetDebugUtilsObjectNameEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkSetDebugUtilsObjectTagEXT"_literal)>
{
    using type                 = PFN_vkSetDebugUtilsObjectTagEXT;
    static constexpr auto name = "vkSetDebugUtilsObjectTagEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkQueueBeginDebugUtilsLabelEXT"_literal)>
{
    using type                 = PFN_vkQueueBeginDebugUtilsLabelEXT;
    static constexpr auto name = "vkQueueBeginDebugUtilsLabelEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkQueueEndDebugUtilsLabelEXT"_literal)>
{
    using type                 = PFN_vkQueueEndDebugUtilsLabelEXT;
    static constexpr auto name = "vkQueueEndDebugUtilsLabelEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkQueueInsertDebugUtilsLabelEXT"_literal)>
{
    using type                 = PFN_vkQueueInsertDebugUtilsLabelEXT;
    static constexpr auto name = "vkQueueInsertDebugUtilsLabelEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkCreateDebugUtilsMessengerEXT"_literal)>
{
    using type                 = PFN_vkCreateDebugUtilsMessengerEXT;
    static constexpr auto name = "vkCreateDebugUtilsMessengerEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkDestroyDebugUtilsMessengerEXT"_literal)>
{
    using type                 = PFN_vkDestroyDebugUtilsMessengerEXT;
    static constexpr auto name = "vkDestroyDebugUtilsMessengerEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkSubmitDebugUtilsMessageEXT"_literal)>
{
    using type                 = PFN_vkSubmitDebugUtilsMessageEXT;
    static constexpr auto name = "vkSubmitDebugUtilsMessageEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkCmdBeginDebugUtilsLabelEXT"_literal)>
{
    using type                 = PFN_vkCmdBeginDebugUtilsLabelEXT;
    static constexpr auto name = "vkCmdBeginDebugUtilsLabelEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkCmdEndDebugUtilsLabelEXT"_literal)>
{
    using type                 = PFN_vkCmdEndDebugUtilsLabelEXT;
    static constexpr auto name = "vkCmdEndDebugUtilsLabelEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_EXT_debug_utils)
template<>
struct vk_function<compile_time_hash("vkCmdInsertDebugUtilsLabelEXT"_literal)>
{
    using type                 = PFN_vkCmdInsertDebugUtilsLabelEXT;
    static constexpr auto name = "vkCmdInsertDebugUtilsLabelEXT"_literal;
};
#endif // #if defined (VK_EXT_debug_utils)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct vk_function<compile_time_hash("vkGetAndroidHardwareBufferPropertiesANDROID"_literal)>
{
    using type                 = PFN_vkGetAndroidHardwareBufferPropertiesANDROID;
    static constexpr auto name = "vkGetAndroidHardwareBufferPropertiesANDROID"_literal;
};
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
template<>
struct vk_function<compile_time_hash("vkGetMemoryAndroidHardwareBufferANDROID"_literal)>
{
    using type                 = PFN_vkGetMemoryAndroidHardwareBufferANDROID;
    static constexpr auto name = "vkGetMemoryAndroidHardwareBufferANDROID"_literal;
};
#endif // #if defined (VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct vk_function<compile_time_hash("vkCreateExecutionGraphPipelinesAMDX"_literal)>
{
    using type                 = PFN_vkCreateExecutionGraphPipelinesAMDX;
    static constexpr auto name = "vkCreateExecutionGraphPipelinesAMDX"_literal;
};
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct vk_function<compile_time_hash("vkGetExecutionGraphPipelineScratchSizeAMDX"_literal)>
{
    using type                 = PFN_vkGetExecutionGraphPipelineScratchSizeAMDX;
    static constexpr auto name = "vkGetExecutionGraphPipelineScratchSizeAMDX"_literal;
};
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct vk_function<compile_time_hash("vkGetExecutionGraphPipelineNodeIndexAMDX"_literal)>
{
    using type                 = PFN_vkGetExecutionGraphPipelineNodeIndexAMDX;
    static constexpr auto name = "vkGetExecutionGraphPipelineNodeIndexAMDX"_literal;
};
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct vk_function<compile_time_hash("vkCmdInitializeGraphScratchMemoryAMDX"_literal)>
{
    using type                 = PFN_vkCmdInitializeGraphScratchMemoryAMDX;
    static constexpr auto name = "vkCmdInitializeGraphScratchMemoryAMDX"_literal;
};
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct vk_function<compile_time_hash("vkCmdDispatchGraphAMDX"_literal)>
{
    using type                 = PFN_vkCmdDispatchGraphAMDX;
    static constexpr auto name = "vkCmdDispatchGraphAMDX"_literal;
};
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct vk_function<compile_time_hash("vkCmdDispatchGraphIndirectAMDX"_literal)>
{
    using type                 = PFN_vkCmdDispatchGraphIndirectAMDX;
    static constexpr auto name = "vkCmdDispatchGraphIndirectAMDX"_literal;
};
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_AMDX_shader_enqueue)
template<>
struct vk_function<compile_time_hash("vkCmdDispatchGraphIndirectCountAMDX"_literal)>
{
    using type                 = PFN_vkCmdDispatchGraphIndirectCountAMDX;
    static constexpr auto name = "vkCmdDispatchGraphIndirectCountAMDX"_literal;
};
#endif // #if defined (VK_AMDX_shader_enqueue)

#if defined(VK_EXT_sample_locations)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceMultisamplePropertiesEXT"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT;
    static constexpr auto name = "vkGetPhysicalDeviceMultisamplePropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_EXT_sample_locations)
template<>
struct vk_function<compile_time_hash("vkCmdSetSampleLocationsEXT"_literal)>
{
    using type                 = PFN_vkCmdSetSampleLocationsEXT;
    static constexpr auto name = "vkCmdSetSampleLocationsEXT"_literal;
};
#endif // #if defined (VK_EXT_sample_locations)

#if defined(VK_KHR_get_memory_requirements2)
template<>
struct vk_function<compile_time_hash("vkGetImageMemoryRequirements2KHR"_literal)>
{
    using type                 = PFN_vkGetImageMemoryRequirements2KHR;
    static constexpr auto name = "vkGetImageMemoryRequirements2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_get_memory_requirements2)
template<>
struct vk_function<compile_time_hash("vkGetBufferMemoryRequirements2KHR"_literal)>
{
    using type                 = PFN_vkGetBufferMemoryRequirements2KHR;
    static constexpr auto name = "vkGetBufferMemoryRequirements2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_get_memory_requirements2)
template<>
struct vk_function<compile_time_hash("vkGetImageSparseMemoryRequirements2KHR"_literal)>
{
    using type                 = PFN_vkGetImageSparseMemoryRequirements2KHR;
    static constexpr auto name = "vkGetImageSparseMemoryRequirements2KHR"_literal;
};
#endif // #if defined (VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCreateAccelerationStructureKHR"_literal)>
{
    using type                 = PFN_vkCreateAccelerationStructureKHR;
    static constexpr auto name = "vkCreateAccelerationStructureKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkDestroyAccelerationStructureKHR"_literal)>
{
    using type                 = PFN_vkDestroyAccelerationStructureKHR;
    static constexpr auto name = "vkDestroyAccelerationStructureKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkBuildAccelerationStructuresKHR"_literal)>
{
    using type                 = PFN_vkBuildAccelerationStructuresKHR;
    static constexpr auto name = "vkBuildAccelerationStructuresKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCopyAccelerationStructureKHR"_literal)>
{
    using type                 = PFN_vkCopyAccelerationStructureKHR;
    static constexpr auto name = "vkCopyAccelerationStructureKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCopyAccelerationStructureToMemoryKHR"_literal)>
{
    using type                 = PFN_vkCopyAccelerationStructureToMemoryKHR;
    static constexpr auto name = "vkCopyAccelerationStructureToMemoryKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCopyMemoryToAccelerationStructureKHR"_literal)>
{
    using type                 = PFN_vkCopyMemoryToAccelerationStructureKHR;
    static constexpr auto name = "vkCopyMemoryToAccelerationStructureKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkWriteAccelerationStructuresPropertiesKHR"_literal)>
{
    using type                 = PFN_vkWriteAccelerationStructuresPropertiesKHR;
    static constexpr auto name = "vkWriteAccelerationStructuresPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkGetAccelerationStructureDeviceAddressKHR"_literal)>
{
    using type                 = PFN_vkGetAccelerationStructureDeviceAddressKHR;
    static constexpr auto name = "vkGetAccelerationStructureDeviceAddressKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkGetDeviceAccelerationStructureCompatibilityKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceAccelerationStructureCompatibilityKHR;
    static constexpr auto name = "vkGetDeviceAccelerationStructureCompatibilityKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkGetAccelerationStructureBuildSizesKHR"_literal)>
{
    using type                 = PFN_vkGetAccelerationStructureBuildSizesKHR;
    static constexpr auto name = "vkGetAccelerationStructureBuildSizesKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdBuildAccelerationStructuresKHR"_literal)>
{
    using type                 = PFN_vkCmdBuildAccelerationStructuresKHR;
    static constexpr auto name = "vkCmdBuildAccelerationStructuresKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdBuildAccelerationStructuresIndirectKHR"_literal)>
{
    using type                 = PFN_vkCmdBuildAccelerationStructuresIndirectKHR;
    static constexpr auto name = "vkCmdBuildAccelerationStructuresIndirectKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdCopyAccelerationStructureKHR"_literal)>
{
    using type                 = PFN_vkCmdCopyAccelerationStructureKHR;
    static constexpr auto name = "vkCmdCopyAccelerationStructureKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdCopyAccelerationStructureToMemoryKHR"_literal)>
{
    using type                 = PFN_vkCmdCopyAccelerationStructureToMemoryKHR;
    static constexpr auto name = "vkCmdCopyAccelerationStructureToMemoryKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdCopyMemoryToAccelerationStructureKHR"_literal)>
{
    using type                 = PFN_vkCmdCopyMemoryToAccelerationStructureKHR;
    static constexpr auto name = "vkCmdCopyMemoryToAccelerationStructureKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdWriteAccelerationStructuresPropertiesKHR"_literal)>
{
    using type                 = PFN_vkCmdWriteAccelerationStructuresPropertiesKHR;
    static constexpr auto name = "vkCmdWriteAccelerationStructuresPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct vk_function<compile_time_hash("vkCreateRayTracingPipelinesKHR"_literal)>
{
    using type                 = PFN_vkCreateRayTracingPipelinesKHR;
    static constexpr auto name = "vkCreateRayTracingPipelinesKHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct vk_function<compile_time_hash("vkGetRayTracingShaderGroupHandlesKHR"_literal)>
{
    using type                 = PFN_vkGetRayTracingShaderGroupHandlesKHR;
    static constexpr auto name = "vkGetRayTracingShaderGroupHandlesKHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct vk_function<compile_time_hash("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR"_literal)>
{
    using type                 = PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
    static constexpr auto name = "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct vk_function<compile_time_hash("vkGetRayTracingShaderGroupStackSizeKHR"_literal)>
{
    using type                 = PFN_vkGetRayTracingShaderGroupStackSizeKHR;
    static constexpr auto name = "vkGetRayTracingShaderGroupStackSizeKHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct vk_function<compile_time_hash("vkCmdTraceRaysKHR"_literal)>
{
    using type                 = PFN_vkCmdTraceRaysKHR;
    static constexpr auto name = "vkCmdTraceRaysKHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct vk_function<compile_time_hash("vkCmdTraceRaysIndirectKHR"_literal)>
{
    using type                 = PFN_vkCmdTraceRaysIndirectKHR;
    static constexpr auto name = "vkCmdTraceRaysIndirectKHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct vk_function<compile_time_hash("vkCmdSetRayTracingPipelineStackSizeKHR"_literal)>
{
    using type                 = PFN_vkCmdSetRayTracingPipelineStackSizeKHR;
    static constexpr auto name = "vkCmdSetRayTracingPipelineStackSizeKHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_pipeline)

#if defined(VK_KHR_sampler_ycbcr_conversion)
template<>
struct vk_function<compile_time_hash("vkCreateSamplerYcbcrConversionKHR"_literal)>
{
    using type                 = PFN_vkCreateSamplerYcbcrConversionKHR;
    static constexpr auto name = "vkCreateSamplerYcbcrConversionKHR"_literal;
};
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_sampler_ycbcr_conversion)
template<>
struct vk_function<compile_time_hash("vkDestroySamplerYcbcrConversionKHR"_literal)>
{
    using type                 = PFN_vkDestroySamplerYcbcrConversionKHR;
    static constexpr auto name = "vkDestroySamplerYcbcrConversionKHR"_literal;
};
#endif // #if defined (VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_bind_memory2)
template<>
struct vk_function<compile_time_hash("vkBindBufferMemory2KHR"_literal)>
{
    using type                 = PFN_vkBindBufferMemory2KHR;
    static constexpr auto name = "vkBindBufferMemory2KHR"_literal;
};
#endif // #if defined (VK_KHR_bind_memory2)

#if defined(VK_KHR_bind_memory2)
template<>
struct vk_function<compile_time_hash("vkBindImageMemory2KHR"_literal)>
{
    using type                 = PFN_vkBindImageMemory2KHR;
    static constexpr auto name = "vkBindImageMemory2KHR"_literal;
};
#endif // #if defined (VK_KHR_bind_memory2)

#if defined(VK_EXT_image_drm_format_modifier)
template<>
struct vk_function<compile_time_hash("vkGetImageDrmFormatModifierPropertiesEXT"_literal)>
{
    using type                 = PFN_vkGetImageDrmFormatModifierPropertiesEXT;
    static constexpr auto name = "vkGetImageDrmFormatModifierPropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_validation_cache)
template<>
struct vk_function<compile_time_hash("vkCreateValidationCacheEXT"_literal)>
{
    using type                 = PFN_vkCreateValidationCacheEXT;
    static constexpr auto name = "vkCreateValidationCacheEXT"_literal;
};
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
template<>
struct vk_function<compile_time_hash("vkDestroyValidationCacheEXT"_literal)>
{
    using type                 = PFN_vkDestroyValidationCacheEXT;
    static constexpr auto name = "vkDestroyValidationCacheEXT"_literal;
};
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
template<>
struct vk_function<compile_time_hash("vkMergeValidationCachesEXT"_literal)>
{
    using type                 = PFN_vkMergeValidationCachesEXT;
    static constexpr auto name = "vkMergeValidationCachesEXT"_literal;
};
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_EXT_validation_cache)
template<>
struct vk_function<compile_time_hash("vkGetValidationCacheDataEXT"_literal)>
{
    using type                 = PFN_vkGetValidationCacheDataEXT;
    static constexpr auto name = "vkGetValidationCacheDataEXT"_literal;
};
#endif // #if defined (VK_EXT_validation_cache)

#if defined(VK_NV_shading_rate_image)
template<>
struct vk_function<compile_time_hash("vkCmdBindShadingRateImageNV"_literal)>
{
    using type                 = PFN_vkCmdBindShadingRateImageNV;
    static constexpr auto name = "vkCmdBindShadingRateImageNV"_literal;
};
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
template<>
struct vk_function<compile_time_hash("vkCmdSetViewportShadingRatePaletteNV"_literal)>
{
    using type                 = PFN_vkCmdSetViewportShadingRatePaletteNV;
    static constexpr auto name = "vkCmdSetViewportShadingRatePaletteNV"_literal;
};
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_shading_rate_image)
template<>
struct vk_function<compile_time_hash("vkCmdSetCoarseSampleOrderNV"_literal)>
{
    using type                 = PFN_vkCmdSetCoarseSampleOrderNV;
    static constexpr auto name = "vkCmdSetCoarseSampleOrderNV"_literal;
};
#endif // #if defined (VK_NV_shading_rate_image)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkCreateAccelerationStructureNV"_literal)>
{
    using type                 = PFN_vkCreateAccelerationStructureNV;
    static constexpr auto name = "vkCreateAccelerationStructureNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkDestroyAccelerationStructureNV"_literal)>
{
    using type                 = PFN_vkDestroyAccelerationStructureNV;
    static constexpr auto name = "vkDestroyAccelerationStructureNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkGetAccelerationStructureMemoryRequirementsNV"_literal)>
{
    using type                 = PFN_vkGetAccelerationStructureMemoryRequirementsNV;
    static constexpr auto name = "vkGetAccelerationStructureMemoryRequirementsNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkBindAccelerationStructureMemoryNV"_literal)>
{
    using type                 = PFN_vkBindAccelerationStructureMemoryNV;
    static constexpr auto name = "vkBindAccelerationStructureMemoryNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkCreateRayTracingPipelinesNV"_literal)>
{
    using type                 = PFN_vkCreateRayTracingPipelinesNV;
    static constexpr auto name = "vkCreateRayTracingPipelinesNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkGetRayTracingShaderGroupHandlesNV"_literal)>
{
    using type                 = PFN_vkGetRayTracingShaderGroupHandlesNV;
    static constexpr auto name = "vkGetRayTracingShaderGroupHandlesNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkGetAccelerationStructureHandleNV"_literal)>
{
    using type                 = PFN_vkGetAccelerationStructureHandleNV;
    static constexpr auto name = "vkGetAccelerationStructureHandleNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkCompileDeferredNV"_literal)>
{
    using type                 = PFN_vkCompileDeferredNV;
    static constexpr auto name = "vkCompileDeferredNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkCmdBuildAccelerationStructureNV"_literal)>
{
    using type                 = PFN_vkCmdBuildAccelerationStructureNV;
    static constexpr auto name = "vkCmdBuildAccelerationStructureNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkCmdCopyAccelerationStructureNV"_literal)>
{
    using type                 = PFN_vkCmdCopyAccelerationStructureNV;
    static constexpr auto name = "vkCmdCopyAccelerationStructureNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkCmdTraceRaysNV"_literal)>
{
    using type                 = PFN_vkCmdTraceRaysNV;
    static constexpr auto name = "vkCmdTraceRaysNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_NV_ray_tracing)
template<>
struct vk_function<compile_time_hash("vkCmdWriteAccelerationStructuresPropertiesNV"_literal)>
{
    using type                 = PFN_vkCmdWriteAccelerationStructuresPropertiesNV;
    static constexpr auto name = "vkCmdWriteAccelerationStructuresPropertiesNV"_literal;
};
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_KHR_maintenance3)
template<>
struct vk_function<compile_time_hash("vkGetDescriptorSetLayoutSupportKHR"_literal)>
{
    using type                 = PFN_vkGetDescriptorSetLayoutSupportKHR;
    static constexpr auto name = "vkGetDescriptorSetLayoutSupportKHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance3)

#if defined(VK_KHR_draw_indirect_count)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndirectCountKHR"_literal)>
{
    using type                 = PFN_vkCmdDrawIndirectCountKHR;
    static constexpr auto name = "vkCmdDrawIndirectCountKHR"_literal;
};
#endif // #if defined (VK_KHR_draw_indirect_count)

#if defined(VK_KHR_draw_indirect_count)
template<>
struct vk_function<compile_time_hash("vkCmdDrawIndexedIndirectCountKHR"_literal)>
{
    using type                 = PFN_vkCmdDrawIndexedIndirectCountKHR;
    static constexpr auto name = "vkCmdDrawIndexedIndirectCountKHR"_literal;
};
#endif // #if defined (VK_KHR_draw_indirect_count)

#if defined(VK_EXT_external_memory_host)
template<>
struct vk_function<compile_time_hash("vkGetMemoryHostPointerPropertiesEXT"_literal)>
{
    using type                 = PFN_vkGetMemoryHostPointerPropertiesEXT;
    static constexpr auto name = "vkGetMemoryHostPointerPropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_external_memory_host)

#if defined(VK_AMD_buffer_marker)
template<>
struct vk_function<compile_time_hash("vkCmdWriteBufferMarkerAMD"_literal)>
{
    using type                 = PFN_vkCmdWriteBufferMarkerAMD;
    static constexpr auto name = "vkCmdWriteBufferMarkerAMD"_literal;
};
#endif // #if defined (VK_AMD_buffer_marker)

#if defined(VK_AMD_buffer_marker)
template<>
struct vk_function<compile_time_hash("vkCmdWriteBufferMarker2AMD"_literal)>
{
    using type                 = PFN_vkCmdWriteBufferMarker2AMD;
    static constexpr auto name = "vkCmdWriteBufferMarker2AMD"_literal;
};
#endif // #if defined (VK_AMD_buffer_marker)

#if defined(VK_EXT_calibrated_timestamps)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
    static constexpr auto name = "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT"_literal;
};
#endif // #if defined (VK_EXT_calibrated_timestamps)

#if defined(VK_EXT_calibrated_timestamps)
template<>
struct vk_function<compile_time_hash("vkGetCalibratedTimestampsEXT"_literal)>
{
    using type                 = PFN_vkGetCalibratedTimestampsEXT;
    static constexpr auto name = "vkGetCalibratedTimestampsEXT"_literal;
};
#endif // #if defined (VK_EXT_calibrated_timestamps)

#if defined(VK_NV_mesh_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMeshTasksNV"_literal)>
{
    using type                 = PFN_vkCmdDrawMeshTasksNV;
    static constexpr auto name = "vkCmdDrawMeshTasksNV"_literal;
};
#endif // #if defined (VK_NV_mesh_shader)

#if defined(VK_NV_mesh_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMeshTasksIndirectNV"_literal)>
{
    using type                 = PFN_vkCmdDrawMeshTasksIndirectNV;
    static constexpr auto name = "vkCmdDrawMeshTasksIndirectNV"_literal;
};
#endif // #if defined (VK_NV_mesh_shader)

#if defined(VK_NV_mesh_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMeshTasksIndirectCountNV"_literal)>
{
    using type                 = PFN_vkCmdDrawMeshTasksIndirectCountNV;
    static constexpr auto name = "vkCmdDrawMeshTasksIndirectCountNV"_literal;
};
#endif // #if defined (VK_NV_mesh_shader)

#if defined(VK_NV_scissor_exclusive)
template<>
struct vk_function<compile_time_hash("vkCmdSetExclusiveScissorEnableNV"_literal)>
{
    using type                 = PFN_vkCmdSetExclusiveScissorEnableNV;
    static constexpr auto name = "vkCmdSetExclusiveScissorEnableNV"_literal;
};
#endif // #if defined (VK_NV_scissor_exclusive)

#if defined(VK_NV_scissor_exclusive)
template<>
struct vk_function<compile_time_hash("vkCmdSetExclusiveScissorNV"_literal)>
{
    using type                 = PFN_vkCmdSetExclusiveScissorNV;
    static constexpr auto name = "vkCmdSetExclusiveScissorNV"_literal;
};
#endif // #if defined (VK_NV_scissor_exclusive)

#if defined(VK_NV_device_diagnostic_checkpoints)
template<>
struct vk_function<compile_time_hash("vkGetQueueCheckpointDataNV"_literal)>
{
    using type                 = PFN_vkGetQueueCheckpointDataNV;
    static constexpr auto name = "vkGetQueueCheckpointDataNV"_literal;
};
#endif // #if defined (VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
template<>
struct vk_function<compile_time_hash("vkGetQueueCheckpointData2NV"_literal)>
{
    using type                 = PFN_vkGetQueueCheckpointData2NV;
    static constexpr auto name = "vkGetQueueCheckpointData2NV"_literal;
};
#endif // #if defined (VK_NV_device_diagnostic_checkpoints)

#if defined(VK_NV_device_diagnostic_checkpoints)
template<>
struct vk_function<compile_time_hash("vkCmdSetCheckpointNV"_literal)>
{
    using type                 = PFN_vkCmdSetCheckpointNV;
    static constexpr auto name = "vkCmdSetCheckpointNV"_literal;
};
#endif // #if defined (VK_NV_device_diagnostic_checkpoints)

#if defined(VK_KHR_timeline_semaphore)
template<>
struct vk_function<compile_time_hash("vkGetSemaphoreCounterValueKHR"_literal)>
{
    using type                 = PFN_vkGetSemaphoreCounterValueKHR;
    static constexpr auto name = "vkGetSemaphoreCounterValueKHR"_literal;
};
#endif // #if defined (VK_KHR_timeline_semaphore)

#if defined(VK_KHR_timeline_semaphore)
template<>
struct vk_function<compile_time_hash("vkWaitSemaphoresKHR"_literal)>
{
    using type                 = PFN_vkWaitSemaphoresKHR;
    static constexpr auto name = "vkWaitSemaphoresKHR"_literal;
};
#endif // #if defined (VK_KHR_timeline_semaphore)

#if defined(VK_KHR_timeline_semaphore)
template<>
struct vk_function<compile_time_hash("vkSignalSemaphoreKHR"_literal)>
{
    using type                 = PFN_vkSignalSemaphoreKHR;
    static constexpr auto name = "vkSignalSemaphoreKHR"_literal;
};
#endif // #if defined (VK_KHR_timeline_semaphore)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkInitializePerformanceApiINTEL"_literal)>
{
    using type                 = PFN_vkInitializePerformanceApiINTEL;
    static constexpr auto name = "vkInitializePerformanceApiINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkUninitializePerformanceApiINTEL"_literal)>
{
    using type                 = PFN_vkUninitializePerformanceApiINTEL;
    static constexpr auto name = "vkUninitializePerformanceApiINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkAcquirePerformanceConfigurationINTEL"_literal)>
{
    using type                 = PFN_vkAcquirePerformanceConfigurationINTEL;
    static constexpr auto name = "vkAcquirePerformanceConfigurationINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkReleasePerformanceConfigurationINTEL"_literal)>
{
    using type                 = PFN_vkReleasePerformanceConfigurationINTEL;
    static constexpr auto name = "vkReleasePerformanceConfigurationINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkQueueSetPerformanceConfigurationINTEL"_literal)>
{
    using type                 = PFN_vkQueueSetPerformanceConfigurationINTEL;
    static constexpr auto name = "vkQueueSetPerformanceConfigurationINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkGetPerformanceParameterINTEL"_literal)>
{
    using type                 = PFN_vkGetPerformanceParameterINTEL;
    static constexpr auto name = "vkGetPerformanceParameterINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkCmdSetPerformanceMarkerINTEL"_literal)>
{
    using type                 = PFN_vkCmdSetPerformanceMarkerINTEL;
    static constexpr auto name = "vkCmdSetPerformanceMarkerINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkCmdSetPerformanceStreamMarkerINTEL"_literal)>
{
    using type                 = PFN_vkCmdSetPerformanceStreamMarkerINTEL;
    static constexpr auto name = "vkCmdSetPerformanceStreamMarkerINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_INTEL_performance_query)
template<>
struct vk_function<compile_time_hash("vkCmdSetPerformanceOverrideINTEL"_literal)>
{
    using type                 = PFN_vkCmdSetPerformanceOverrideINTEL;
    static constexpr auto name = "vkCmdSetPerformanceOverrideINTEL"_literal;
};
#endif // #if defined (VK_INTEL_performance_query)

#if defined(VK_AMD_display_native_hdr)
template<>
struct vk_function<compile_time_hash("vkSetLocalDimmingAMD"_literal)>
{
    using type                 = PFN_vkSetLocalDimmingAMD;
    static constexpr auto name = "vkSetLocalDimmingAMD"_literal;
};
#endif // #if defined (VK_AMD_display_native_hdr)

#if defined(VK_FUCHSIA_imagepipe_surface)
template<>
struct vk_function<compile_time_hash("vkCreateImagePipeSurfaceFUCHSIA"_literal)>
{
    using type                 = PFN_vkCreateImagePipeSurfaceFUCHSIA;
    static constexpr auto name = "vkCreateImagePipeSurfaceFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_imagepipe_surface)

#if defined(VK_EXT_metal_surface)
template<>
struct vk_function<compile_time_hash("vkCreateMetalSurfaceEXT"_literal)>
{
    using type                 = PFN_vkCreateMetalSurfaceEXT;
    static constexpr auto name = "vkCreateMetalSurfaceEXT"_literal;
};
#endif // #if defined (VK_EXT_metal_surface)

#if defined(VK_KHR_fragment_shading_rate)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceFragmentShadingRatesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceFragmentShadingRatesKHR"_literal;
};
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_fragment_shading_rate)
template<>
struct vk_function<compile_time_hash("vkCmdSetFragmentShadingRateKHR"_literal)>
{
    using type                 = PFN_vkCmdSetFragmentShadingRateKHR;
    static constexpr auto name = "vkCmdSetFragmentShadingRateKHR"_literal;
};
#endif // #if defined (VK_KHR_fragment_shading_rate)

#if defined(VK_KHR_dynamic_rendering_local_read)
template<>
struct vk_function<compile_time_hash("vkCmdSetRenderingAttachmentLocationsKHR"_literal)>
{
    using type                 = PFN_vkCmdSetRenderingAttachmentLocationsKHR;
    static constexpr auto name = "vkCmdSetRenderingAttachmentLocationsKHR"_literal;
};
#endif // #if defined (VK_KHR_dynamic_rendering_local_read)

#if defined(VK_KHR_dynamic_rendering_local_read)
template<>
struct vk_function<compile_time_hash("vkCmdSetRenderingInputAttachmentIndicesKHR"_literal)>
{
    using type                 = PFN_vkCmdSetRenderingInputAttachmentIndicesKHR;
    static constexpr auto name = "vkCmdSetRenderingInputAttachmentIndicesKHR"_literal;
};
#endif // #if defined (VK_KHR_dynamic_rendering_local_read)

#if defined(VK_EXT_buffer_device_address)
template<>
struct vk_function<compile_time_hash("vkGetBufferDeviceAddressEXT"_literal)>
{
    using type                 = PFN_vkGetBufferDeviceAddressEXT;
    static constexpr auto name = "vkGetBufferDeviceAddressEXT"_literal;
};
#endif // #if defined (VK_EXT_buffer_device_address)

#if defined(VK_EXT_tooling_info)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceToolPropertiesEXT"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceToolPropertiesEXT;
    static constexpr auto name = "vkGetPhysicalDeviceToolPropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_tooling_info)

#if defined(VK_KHR_present_wait)
template<>
struct vk_function<compile_time_hash("vkWaitForPresentKHR"_literal)>
{
    using type                 = PFN_vkWaitForPresentKHR;
    static constexpr auto name = "vkWaitForPresentKHR"_literal;
};
#endif // #if defined (VK_KHR_present_wait)

#if defined(VK_NV_cooperative_matrix)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
    static constexpr auto name = "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV"_literal;
};
#endif // #if defined (VK_NV_cooperative_matrix)

#if defined(VK_NV_coverage_reduction_mode)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
    static constexpr auto name = "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV"_literal;
};
#endif // #if defined (VK_NV_coverage_reduction_mode)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSurfacePresentModes2EXT"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT;
    static constexpr auto name = "vkGetPhysicalDeviceSurfacePresentModes2EXT"_literal;
};
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct vk_function<compile_time_hash("vkAcquireFullScreenExclusiveModeEXT"_literal)>
{
    using type                 = PFN_vkAcquireFullScreenExclusiveModeEXT;
    static constexpr auto name = "vkAcquireFullScreenExclusiveModeEXT"_literal;
};
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct vk_function<compile_time_hash("vkReleaseFullScreenExclusiveModeEXT"_literal)>
{
    using type                 = PFN_vkReleaseFullScreenExclusiveModeEXT;
    static constexpr auto name = "vkReleaseFullScreenExclusiveModeEXT"_literal;
};
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_full_screen_exclusive)
template<>
struct vk_function<compile_time_hash("vkGetDeviceGroupSurfacePresentModes2EXT"_literal)>
{
    using type                 = PFN_vkGetDeviceGroupSurfacePresentModes2EXT;
    static constexpr auto name = "vkGetDeviceGroupSurfacePresentModes2EXT"_literal;
};
#endif // #if defined (VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_headless_surface)
template<>
struct vk_function<compile_time_hash("vkCreateHeadlessSurfaceEXT"_literal)>
{
    using type                 = PFN_vkCreateHeadlessSurfaceEXT;
    static constexpr auto name = "vkCreateHeadlessSurfaceEXT"_literal;
};
#endif // #if defined (VK_EXT_headless_surface)

#if defined(VK_KHR_buffer_device_address)
template<>
struct vk_function<compile_time_hash("vkGetBufferDeviceAddressKHR"_literal)>
{
    using type                 = PFN_vkGetBufferDeviceAddressKHR;
    static constexpr auto name = "vkGetBufferDeviceAddressKHR"_literal;
};
#endif // #if defined (VK_KHR_buffer_device_address)

#if defined(VK_KHR_buffer_device_address)
template<>
struct vk_function<compile_time_hash("vkGetBufferOpaqueCaptureAddressKHR"_literal)>
{
    using type                 = PFN_vkGetBufferOpaqueCaptureAddressKHR;
    static constexpr auto name = "vkGetBufferOpaqueCaptureAddressKHR"_literal;
};
#endif // #if defined (VK_KHR_buffer_device_address)

#if defined(VK_KHR_buffer_device_address)
template<>
struct vk_function<compile_time_hash("vkGetDeviceMemoryOpaqueCaptureAddressKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR;
    static constexpr auto name = "vkGetDeviceMemoryOpaqueCaptureAddressKHR"_literal;
};
#endif // #if defined (VK_KHR_buffer_device_address)

#if defined(VK_EXT_line_rasterization)
template<>
struct vk_function<compile_time_hash("vkCmdSetLineStippleEXT"_literal)>
{
    using type                 = PFN_vkCmdSetLineStippleEXT;
    static constexpr auto name = "vkCmdSetLineStippleEXT"_literal;
};
#endif // #if defined (VK_EXT_line_rasterization)

#if defined(VK_EXT_host_query_reset)
template<>
struct vk_function<compile_time_hash("vkResetQueryPoolEXT"_literal)>
{
    using type                 = PFN_vkResetQueryPoolEXT;
    static constexpr auto name = "vkResetQueryPoolEXT"_literal;
};
#endif // #if defined (VK_EXT_host_query_reset)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetCullModeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetCullModeEXT;
    static constexpr auto name = "vkCmdSetCullModeEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetFrontFaceEXT"_literal)>
{
    using type                 = PFN_vkCmdSetFrontFaceEXT;
    static constexpr auto name = "vkCmdSetFrontFaceEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetPrimitiveTopologyEXT"_literal)>
{
    using type                 = PFN_vkCmdSetPrimitiveTopologyEXT;
    static constexpr auto name = "vkCmdSetPrimitiveTopologyEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetViewportWithCountEXT"_literal)>
{
    using type                 = PFN_vkCmdSetViewportWithCountEXT;
    static constexpr auto name = "vkCmdSetViewportWithCountEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetScissorWithCountEXT"_literal)>
{
    using type                 = PFN_vkCmdSetScissorWithCountEXT;
    static constexpr auto name = "vkCmdSetScissorWithCountEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdBindVertexBuffers2EXT"_literal)>
{
    using type                 = PFN_vkCmdBindVertexBuffers2EXT;
    static constexpr auto name = "vkCmdBindVertexBuffers2EXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthTestEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthTestEnableEXT;
    static constexpr auto name = "vkCmdSetDepthTestEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthWriteEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthWriteEnableEXT;
    static constexpr auto name = "vkCmdSetDepthWriteEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthCompareOpEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthCompareOpEXT;
    static constexpr auto name = "vkCmdSetDepthCompareOpEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthBoundsTestEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthBoundsTestEnableEXT;
    static constexpr auto name = "vkCmdSetDepthBoundsTestEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetStencilTestEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetStencilTestEnableEXT;
    static constexpr auto name = "vkCmdSetStencilTestEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_EXT_extended_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetStencilOpEXT"_literal)>
{
    using type                 = PFN_vkCmdSetStencilOpEXT;
    static constexpr auto name = "vkCmdSetStencilOpEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct vk_function<compile_time_hash("vkCreateDeferredOperationKHR"_literal)>
{
    using type                 = PFN_vkCreateDeferredOperationKHR;
    static constexpr auto name = "vkCreateDeferredOperationKHR"_literal;
};
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct vk_function<compile_time_hash("vkDestroyDeferredOperationKHR"_literal)>
{
    using type                 = PFN_vkDestroyDeferredOperationKHR;
    static constexpr auto name = "vkDestroyDeferredOperationKHR"_literal;
};
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct vk_function<compile_time_hash("vkGetDeferredOperationMaxConcurrencyKHR"_literal)>
{
    using type                 = PFN_vkGetDeferredOperationMaxConcurrencyKHR;
    static constexpr auto name = "vkGetDeferredOperationMaxConcurrencyKHR"_literal;
};
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct vk_function<compile_time_hash("vkGetDeferredOperationResultKHR"_literal)>
{
    using type                 = PFN_vkGetDeferredOperationResultKHR;
    static constexpr auto name = "vkGetDeferredOperationResultKHR"_literal;
};
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_deferred_host_operations)
template<>
struct vk_function<compile_time_hash("vkDeferredOperationJoinKHR"_literal)>
{
    using type                 = PFN_vkDeferredOperationJoinKHR;
    static constexpr auto name = "vkDeferredOperationJoinKHR"_literal;
};
#endif // #if defined (VK_KHR_deferred_host_operations)

#if defined(VK_KHR_pipeline_executable_properties)
template<>
struct vk_function<compile_time_hash("vkGetPipelineExecutablePropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPipelineExecutablePropertiesKHR;
    static constexpr auto name = "vkGetPipelineExecutablePropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
template<>
struct vk_function<compile_time_hash("vkGetPipelineExecutableStatisticsKHR"_literal)>
{
    using type                 = PFN_vkGetPipelineExecutableStatisticsKHR;
    static constexpr auto name = "vkGetPipelineExecutableStatisticsKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_KHR_pipeline_executable_properties)
template<>
struct vk_function<compile_time_hash("vkGetPipelineExecutableInternalRepresentationsKHR"_literal)>
{
    using type                 = PFN_vkGetPipelineExecutableInternalRepresentationsKHR;
    static constexpr auto name = "vkGetPipelineExecutableInternalRepresentationsKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_executable_properties)

#if defined(VK_EXT_host_image_copy)
template<>
struct vk_function<compile_time_hash("vkCopyMemoryToImageEXT"_literal)>
{
    using type                 = PFN_vkCopyMemoryToImageEXT;
    static constexpr auto name = "vkCopyMemoryToImageEXT"_literal;
};
#endif // #if defined (VK_EXT_host_image_copy)

#if defined(VK_EXT_host_image_copy)
template<>
struct vk_function<compile_time_hash("vkCopyImageToMemoryEXT"_literal)>
{
    using type                 = PFN_vkCopyImageToMemoryEXT;
    static constexpr auto name = "vkCopyImageToMemoryEXT"_literal;
};
#endif // #if defined (VK_EXT_host_image_copy)

#if defined(VK_EXT_host_image_copy)
template<>
struct vk_function<compile_time_hash("vkCopyImageToImageEXT"_literal)>
{
    using type                 = PFN_vkCopyImageToImageEXT;
    static constexpr auto name = "vkCopyImageToImageEXT"_literal;
};
#endif // #if defined (VK_EXT_host_image_copy)

#if defined(VK_EXT_host_image_copy)
template<>
struct vk_function<compile_time_hash("vkTransitionImageLayoutEXT"_literal)>
{
    using type                 = PFN_vkTransitionImageLayoutEXT;
    static constexpr auto name = "vkTransitionImageLayoutEXT"_literal;
};
#endif // #if defined (VK_EXT_host_image_copy)

#if defined(VK_EXT_host_image_copy)
template<>
struct vk_function<compile_time_hash("vkGetImageSubresourceLayout2EXT"_literal)>
{
    using type                 = PFN_vkGetImageSubresourceLayout2EXT;
    static constexpr auto name = "vkGetImageSubresourceLayout2EXT"_literal;
};
#endif // #if defined (VK_EXT_host_image_copy)

#if defined(VK_KHR_map_memory2)
template<>
struct vk_function<compile_time_hash("vkMapMemory2KHR"_literal)>
{
    using type                 = PFN_vkMapMemory2KHR;
    static constexpr auto name = "vkMapMemory2KHR"_literal;
};
#endif // #if defined (VK_KHR_map_memory2)

#if defined(VK_KHR_map_memory2)
template<>
struct vk_function<compile_time_hash("vkUnmapMemory2KHR"_literal)>
{
    using type                 = PFN_vkUnmapMemory2KHR;
    static constexpr auto name = "vkUnmapMemory2KHR"_literal;
};
#endif // #if defined (VK_KHR_map_memory2)

#if defined(VK_EXT_swapchain_maintenance1)
template<>
struct vk_function<compile_time_hash("vkReleaseSwapchainImagesEXT"_literal)>
{
    using type                 = PFN_vkReleaseSwapchainImagesEXT;
    static constexpr auto name = "vkReleaseSwapchainImagesEXT"_literal;
};
#endif // #if defined (VK_EXT_swapchain_maintenance1)

#if defined(VK_NV_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkGetGeneratedCommandsMemoryRequirementsNV"_literal)>
{
    using type                 = PFN_vkGetGeneratedCommandsMemoryRequirementsNV;
    static constexpr auto name = "vkGetGeneratedCommandsMemoryRequirementsNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCreateIndirectCommandsLayoutNV"_literal)>
{
    using type                 = PFN_vkCreateIndirectCommandsLayoutNV;
    static constexpr auto name = "vkCreateIndirectCommandsLayoutNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkDestroyIndirectCommandsLayoutNV"_literal)>
{
    using type                 = PFN_vkDestroyIndirectCommandsLayoutNV;
    static constexpr auto name = "vkDestroyIndirectCommandsLayoutNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCmdPreprocessGeneratedCommandsNV"_literal)>
{
    using type                 = PFN_vkCmdPreprocessGeneratedCommandsNV;
    static constexpr auto name = "vkCmdPreprocessGeneratedCommandsNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCmdExecuteGeneratedCommandsNV"_literal)>
{
    using type                 = PFN_vkCmdExecuteGeneratedCommandsNV;
    static constexpr auto name = "vkCmdExecuteGeneratedCommandsNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_NV_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCmdBindPipelineShaderGroupNV"_literal)>
{
    using type                 = PFN_vkCmdBindPipelineShaderGroupNV;
    static constexpr auto name = "vkCmdBindPipelineShaderGroupNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands)

#if defined(VK_EXT_depth_bias_control)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthBias2EXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthBias2EXT;
    static constexpr auto name = "vkCmdSetDepthBias2EXT"_literal;
};
#endif // #if defined (VK_EXT_depth_bias_control)

#if defined(VK_EXT_acquire_drm_display)
template<>
struct vk_function<compile_time_hash("vkAcquireDrmDisplayEXT"_literal)>
{
    using type                 = PFN_vkAcquireDrmDisplayEXT;
    static constexpr auto name = "vkAcquireDrmDisplayEXT"_literal;
};
#endif // #if defined (VK_EXT_acquire_drm_display)

#if defined(VK_EXT_acquire_drm_display)
template<>
struct vk_function<compile_time_hash("vkGetDrmDisplayEXT"_literal)>
{
    using type                 = PFN_vkGetDrmDisplayEXT;
    static constexpr auto name = "vkGetDrmDisplayEXT"_literal;
};
#endif // #if defined (VK_EXT_acquire_drm_display)

#if defined(VK_EXT_private_data)
template<>
struct vk_function<compile_time_hash("vkCreatePrivateDataSlotEXT"_literal)>
{
    using type                 = PFN_vkCreatePrivateDataSlotEXT;
    static constexpr auto name = "vkCreatePrivateDataSlotEXT"_literal;
};
#endif // #if defined (VK_EXT_private_data)

#if defined(VK_EXT_private_data)
template<>
struct vk_function<compile_time_hash("vkDestroyPrivateDataSlotEXT"_literal)>
{
    using type                 = PFN_vkDestroyPrivateDataSlotEXT;
    static constexpr auto name = "vkDestroyPrivateDataSlotEXT"_literal;
};
#endif // #if defined (VK_EXT_private_data)

#if defined(VK_EXT_private_data)
template<>
struct vk_function<compile_time_hash("vkSetPrivateDataEXT"_literal)>
{
    using type                 = PFN_vkSetPrivateDataEXT;
    static constexpr auto name = "vkSetPrivateDataEXT"_literal;
};
#endif // #if defined (VK_EXT_private_data)

#if defined(VK_EXT_private_data)
template<>
struct vk_function<compile_time_hash("vkGetPrivateDataEXT"_literal)>
{
    using type                 = PFN_vkGetPrivateDataEXT;
    static constexpr auto name = "vkGetPrivateDataEXT"_literal;
};
#endif // #if defined (VK_EXT_private_data)

#if defined(VK_KHR_video_encode_queue)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
template<>
struct vk_function<compile_time_hash("vkGetEncodedVideoSessionParametersKHR"_literal)>
{
    using type                 = PFN_vkGetEncodedVideoSessionParametersKHR;
    static constexpr auto name = "vkGetEncodedVideoSessionParametersKHR"_literal;
};
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_KHR_video_encode_queue)
template<>
struct vk_function<compile_time_hash("vkCmdEncodeVideoKHR"_literal)>
{
    using type                 = PFN_vkCmdEncodeVideoKHR;
    static constexpr auto name = "vkCmdEncodeVideoKHR"_literal;
};
#endif // #if defined (VK_KHR_video_encode_queue)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct vk_function<compile_time_hash("vkCreateCudaModuleNV"_literal)>
{
    using type                 = PFN_vkCreateCudaModuleNV;
    static constexpr auto name = "vkCreateCudaModuleNV"_literal;
};
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct vk_function<compile_time_hash("vkGetCudaModuleCacheNV"_literal)>
{
    using type                 = PFN_vkGetCudaModuleCacheNV;
    static constexpr auto name = "vkGetCudaModuleCacheNV"_literal;
};
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct vk_function<compile_time_hash("vkCreateCudaFunctionNV"_literal)>
{
    using type                 = PFN_vkCreateCudaFunctionNV;
    static constexpr auto name = "vkCreateCudaFunctionNV"_literal;
};
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct vk_function<compile_time_hash("vkDestroyCudaModuleNV"_literal)>
{
    using type                 = PFN_vkDestroyCudaModuleNV;
    static constexpr auto name = "vkDestroyCudaModuleNV"_literal;
};
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct vk_function<compile_time_hash("vkDestroyCudaFunctionNV"_literal)>
{
    using type                 = PFN_vkDestroyCudaFunctionNV;
    static constexpr auto name = "vkDestroyCudaFunctionNV"_literal;
};
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct vk_function<compile_time_hash("vkCmdCudaLaunchKernelNV"_literal)>
{
    using type                 = PFN_vkCmdCudaLaunchKernelNV;
    static constexpr auto name = "vkCmdCudaLaunchKernelNV"_literal;
};
#endif // #if defined (VK_NV_cuda_kernel_launch)

#if defined(VK_KHR_object_refresh)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceRefreshableObjectTypesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceRefreshableObjectTypesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceRefreshableObjectTypesKHR"_literal;
};
#endif // #if defined (VK_KHR_object_refresh)

#if defined(VK_KHR_object_refresh)
template<>
struct vk_function<compile_time_hash("vkCmdRefreshObjectsKHR"_literal)>
{
    using type                 = PFN_vkCmdRefreshObjectsKHR;
    static constexpr auto name = "vkCmdRefreshObjectsKHR"_literal;
};
#endif // #if defined (VK_KHR_object_refresh)

#if defined(VK_EXT_metal_objects)
template<>
struct vk_function<compile_time_hash("vkExportMetalObjectsEXT"_literal)>
{
    using type                 = PFN_vkExportMetalObjectsEXT;
    static constexpr auto name = "vkExportMetalObjectsEXT"_literal;
};
#endif // #if defined (VK_EXT_metal_objects)

#if defined(VK_KHR_synchronization2)
template<>
struct vk_function<compile_time_hash("vkQueueSubmit2KHR"_literal)>
{
    using type                 = PFN_vkQueueSubmit2KHR;
    static constexpr auto name = "vkQueueSubmit2KHR"_literal;
};
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct vk_function<compile_time_hash("vkCmdSetEvent2KHR"_literal)>
{
    using type                 = PFN_vkCmdSetEvent2KHR;
    static constexpr auto name = "vkCmdSetEvent2KHR"_literal;
};
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct vk_function<compile_time_hash("vkCmdResetEvent2KHR"_literal)>
{
    using type                 = PFN_vkCmdResetEvent2KHR;
    static constexpr auto name = "vkCmdResetEvent2KHR"_literal;
};
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct vk_function<compile_time_hash("vkCmdWaitEvents2KHR"_literal)>
{
    using type                 = PFN_vkCmdWaitEvents2KHR;
    static constexpr auto name = "vkCmdWaitEvents2KHR"_literal;
};
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct vk_function<compile_time_hash("vkCmdPipelineBarrier2KHR"_literal)>
{
    using type                 = PFN_vkCmdPipelineBarrier2KHR;
    static constexpr auto name = "vkCmdPipelineBarrier2KHR"_literal;
};
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_KHR_synchronization2)
template<>
struct vk_function<compile_time_hash("vkCmdWriteTimestamp2KHR"_literal)>
{
    using type                 = PFN_vkCmdWriteTimestamp2KHR;
    static constexpr auto name = "vkCmdWriteTimestamp2KHR"_literal;
};
#endif // #if defined (VK_KHR_synchronization2)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetDescriptorSetLayoutSizeEXT"_literal)>
{
    using type                 = PFN_vkGetDescriptorSetLayoutSizeEXT;
    static constexpr auto name = "vkGetDescriptorSetLayoutSizeEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetDescriptorSetLayoutBindingOffsetEXT"_literal)>
{
    using type                 = PFN_vkGetDescriptorSetLayoutBindingOffsetEXT;
    static constexpr auto name = "vkGetDescriptorSetLayoutBindingOffsetEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetDescriptorEXT"_literal)>
{
    using type                 = PFN_vkGetDescriptorEXT;
    static constexpr auto name = "vkGetDescriptorEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetBufferOpaqueCaptureDescriptorDataEXT"_literal)>
{
    using type                 = PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT;
    static constexpr auto name = "vkGetBufferOpaqueCaptureDescriptorDataEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetImageOpaqueCaptureDescriptorDataEXT"_literal)>
{
    using type                 = PFN_vkGetImageOpaqueCaptureDescriptorDataEXT;
    static constexpr auto name = "vkGetImageOpaqueCaptureDescriptorDataEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetImageViewOpaqueCaptureDescriptorDataEXT"_literal)>
{
    using type                 = PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT;
    static constexpr auto name = "vkGetImageViewOpaqueCaptureDescriptorDataEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetSamplerOpaqueCaptureDescriptorDataEXT"_literal)>
{
    using type                 = PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT;
    static constexpr auto name = "vkGetSamplerOpaqueCaptureDescriptorDataEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT"_literal)>
{
    using type                 = PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT;
    static constexpr auto name = "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkCmdBindDescriptorBuffersEXT"_literal)>
{
    using type                 = PFN_vkCmdBindDescriptorBuffersEXT;
    static constexpr auto name = "vkCmdBindDescriptorBuffersEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkCmdSetDescriptorBufferOffsetsEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDescriptorBufferOffsetsEXT;
    static constexpr auto name = "vkCmdSetDescriptorBufferOffsetsEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_EXT_descriptor_buffer)
template<>
struct vk_function<compile_time_hash("vkCmdBindDescriptorBufferEmbeddedSamplersEXT"_literal)>
{
    using type                 = PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT;
    static constexpr auto name = "vkCmdBindDescriptorBufferEmbeddedSamplersEXT"_literal;
};
#endif // #if defined (VK_EXT_descriptor_buffer)

#if defined(VK_NV_fragment_shading_rate_enums)
template<>
struct vk_function<compile_time_hash("vkCmdSetFragmentShadingRateEnumNV"_literal)>
{
    using type                 = PFN_vkCmdSetFragmentShadingRateEnumNV;
    static constexpr auto name = "vkCmdSetFragmentShadingRateEnumNV"_literal;
};
#endif // #if defined (VK_NV_fragment_shading_rate_enums)

#if defined(VK_EXT_mesh_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMeshTasksEXT"_literal)>
{
    using type                 = PFN_vkCmdDrawMeshTasksEXT;
    static constexpr auto name = "vkCmdDrawMeshTasksEXT"_literal;
};
#endif // #if defined (VK_EXT_mesh_shader)

#if defined(VK_EXT_mesh_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMeshTasksIndirectEXT"_literal)>
{
    using type                 = PFN_vkCmdDrawMeshTasksIndirectEXT;
    static constexpr auto name = "vkCmdDrawMeshTasksIndirectEXT"_literal;
};
#endif // #if defined (VK_EXT_mesh_shader)

#if defined(VK_EXT_mesh_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMeshTasksIndirectCountEXT"_literal)>
{
    using type                 = PFN_vkCmdDrawMeshTasksIndirectCountEXT;
    static constexpr auto name = "vkCmdDrawMeshTasksIndirectCountEXT"_literal;
};
#endif // #if defined (VK_EXT_mesh_shader)

#if defined(VK_KHR_copy_commands2)
template<>
struct vk_function<compile_time_hash("vkCmdCopyBuffer2KHR"_literal)>
{
    using type                 = PFN_vkCmdCopyBuffer2KHR;
    static constexpr auto name = "vkCmdCopyBuffer2KHR"_literal;
};
#endif // #if defined (VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct vk_function<compile_time_hash("vkCmdCopyImage2KHR"_literal)>
{
    using type                 = PFN_vkCmdCopyImage2KHR;
    static constexpr auto name = "vkCmdCopyImage2KHR"_literal;
};
#endif // #if defined (VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct vk_function<compile_time_hash("vkCmdCopyBufferToImage2KHR"_literal)>
{
    using type                 = PFN_vkCmdCopyBufferToImage2KHR;
    static constexpr auto name = "vkCmdCopyBufferToImage2KHR"_literal;
};
#endif // #if defined (VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct vk_function<compile_time_hash("vkCmdCopyImageToBuffer2KHR"_literal)>
{
    using type                 = PFN_vkCmdCopyImageToBuffer2KHR;
    static constexpr auto name = "vkCmdCopyImageToBuffer2KHR"_literal;
};
#endif // #if defined (VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct vk_function<compile_time_hash("vkCmdBlitImage2KHR"_literal)>
{
    using type                 = PFN_vkCmdBlitImage2KHR;
    static constexpr auto name = "vkCmdBlitImage2KHR"_literal;
};
#endif // #if defined (VK_KHR_copy_commands2)

#if defined(VK_KHR_copy_commands2)
template<>
struct vk_function<compile_time_hash("vkCmdResolveImage2KHR"_literal)>
{
    using type                 = PFN_vkCmdResolveImage2KHR;
    static constexpr auto name = "vkCmdResolveImage2KHR"_literal;
};
#endif // #if defined (VK_KHR_copy_commands2)

#if defined(VK_EXT_device_fault)
template<>
struct vk_function<compile_time_hash("vkGetDeviceFaultInfoEXT"_literal)>
{
    using type                 = PFN_vkGetDeviceFaultInfoEXT;
    static constexpr auto name = "vkGetDeviceFaultInfoEXT"_literal;
};
#endif // #if defined (VK_EXT_device_fault)

#if defined(VK_NV_acquire_winrt_display)
template<>
struct vk_function<compile_time_hash("vkAcquireWinrtDisplayNV"_literal)>
{
    using type                 = PFN_vkAcquireWinrtDisplayNV;
    static constexpr auto name = "vkAcquireWinrtDisplayNV"_literal;
};
#endif // #if defined (VK_NV_acquire_winrt_display)

#if defined(VK_NV_acquire_winrt_display)
template<>
struct vk_function<compile_time_hash("vkGetWinrtDisplayNV"_literal)>
{
    using type                 = PFN_vkGetWinrtDisplayNV;
    static constexpr auto name = "vkGetWinrtDisplayNV"_literal;
};
#endif // #if defined (VK_NV_acquire_winrt_display)

#if defined(VK_EXT_directfb_surface)
template<>
struct vk_function<compile_time_hash("vkCreateDirectFBSurfaceEXT"_literal)>
{
    using type                 = PFN_vkCreateDirectFBSurfaceEXT;
    static constexpr auto name = "vkCreateDirectFBSurfaceEXT"_literal;
};
#endif // #if defined (VK_EXT_directfb_surface)

#if defined(VK_EXT_directfb_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceDirectFBPresentationSupportEXT"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
    static constexpr auto name = "vkGetPhysicalDeviceDirectFBPresentationSupportEXT"_literal;
};
#endif // #if defined (VK_EXT_directfb_surface)

#if defined(VK_EXT_vertex_input_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetVertexInputEXT"_literal)>
{
    using type                 = PFN_vkCmdSetVertexInputEXT;
    static constexpr auto name = "vkCmdSetVertexInputEXT"_literal;
};
#endif // #if defined (VK_EXT_vertex_input_dynamic_state)

#if defined(VK_FUCHSIA_external_memory)
template<>
struct vk_function<compile_time_hash("vkGetMemoryZirconHandleFUCHSIA"_literal)>
{
    using type                 = PFN_vkGetMemoryZirconHandleFUCHSIA;
    static constexpr auto name = "vkGetMemoryZirconHandleFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_memory)
template<>
struct vk_function<compile_time_hash("vkGetMemoryZirconHandlePropertiesFUCHSIA"_literal)>
{
    using type                 = PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA;
    static constexpr auto name = "vkGetMemoryZirconHandlePropertiesFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_external_memory)

#if defined(VK_FUCHSIA_external_semaphore)
template<>
struct vk_function<compile_time_hash("vkImportSemaphoreZirconHandleFUCHSIA"_literal)>
{
    using type                 = PFN_vkImportSemaphoreZirconHandleFUCHSIA;
    static constexpr auto name = "vkImportSemaphoreZirconHandleFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_external_semaphore)

#if defined(VK_FUCHSIA_external_semaphore)
template<>
struct vk_function<compile_time_hash("vkGetSemaphoreZirconHandleFUCHSIA"_literal)>
{
    using type                 = PFN_vkGetSemaphoreZirconHandleFUCHSIA;
    static constexpr auto name = "vkGetSemaphoreZirconHandleFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_external_semaphore)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct vk_function<compile_time_hash("vkCreateBufferCollectionFUCHSIA"_literal)>
{
    using type                 = PFN_vkCreateBufferCollectionFUCHSIA;
    static constexpr auto name = "vkCreateBufferCollectionFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct vk_function<compile_time_hash("vkSetBufferCollectionImageConstraintsFUCHSIA"_literal)>
{
    using type                 = PFN_vkSetBufferCollectionImageConstraintsFUCHSIA;
    static constexpr auto name = "vkSetBufferCollectionImageConstraintsFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct vk_function<compile_time_hash("vkSetBufferCollectionBufferConstraintsFUCHSIA"_literal)>
{
    using type                 = PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA;
    static constexpr auto name = "vkSetBufferCollectionBufferConstraintsFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct vk_function<compile_time_hash("vkDestroyBufferCollectionFUCHSIA"_literal)>
{
    using type                 = PFN_vkDestroyBufferCollectionFUCHSIA;
    static constexpr auto name = "vkDestroyBufferCollectionFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct vk_function<compile_time_hash("vkGetBufferCollectionPropertiesFUCHSIA"_literal)>
{
    using type                 = PFN_vkGetBufferCollectionPropertiesFUCHSIA;
    static constexpr auto name = "vkGetBufferCollectionPropertiesFUCHSIA"_literal;
};
#endif // #if defined (VK_FUCHSIA_buffer_collection)

#if defined(VK_HUAWEI_subpass_shading)
template<>
struct vk_function<compile_time_hash("vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI"_literal)>
{
    using type                 = PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI;
    static constexpr auto name = "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI"_literal;
};
#endif // #if defined (VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_subpass_shading)
template<>
struct vk_function<compile_time_hash("vkCmdSubpassShadingHUAWEI"_literal)>
{
    using type                 = PFN_vkCmdSubpassShadingHUAWEI;
    static constexpr auto name = "vkCmdSubpassShadingHUAWEI"_literal;
};
#endif // #if defined (VK_HUAWEI_subpass_shading)

#if defined(VK_HUAWEI_invocation_mask)
template<>
struct vk_function<compile_time_hash("vkCmdBindInvocationMaskHUAWEI"_literal)>
{
    using type                 = PFN_vkCmdBindInvocationMaskHUAWEI;
    static constexpr auto name = "vkCmdBindInvocationMaskHUAWEI"_literal;
};
#endif // #if defined (VK_HUAWEI_invocation_mask)

#if defined(VK_NV_external_memory_rdma)
template<>
struct vk_function<compile_time_hash("vkGetMemoryRemoteAddressNV"_literal)>
{
    using type                 = PFN_vkGetMemoryRemoteAddressNV;
    static constexpr auto name = "vkGetMemoryRemoteAddressNV"_literal;
};
#endif // #if defined (VK_NV_external_memory_rdma)

#if defined(VK_EXT_pipeline_properties)
template<>
struct vk_function<compile_time_hash("vkGetPipelinePropertiesEXT"_literal)>
{
    using type                 = PFN_vkGetPipelinePropertiesEXT;
    static constexpr auto name = "vkGetPipelinePropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_pipeline_properties)

#if defined(VK_NV_external_sci_sync)
template<>
struct vk_function<compile_time_hash("vkGetFenceSciSyncFenceNV"_literal)>
{
    using type                 = PFN_vkGetFenceSciSyncFenceNV;
    static constexpr auto name = "vkGetFenceSciSyncFenceNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
template<>
struct vk_function<compile_time_hash("vkGetFenceSciSyncObjNV"_literal)>
{
    using type                 = PFN_vkGetFenceSciSyncObjNV;
    static constexpr auto name = "vkGetFenceSciSyncObjNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
template<>
struct vk_function<compile_time_hash("vkImportFenceSciSyncFenceNV"_literal)>
{
    using type                 = PFN_vkImportFenceSciSyncFenceNV;
    static constexpr auto name = "vkImportFenceSciSyncFenceNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
template<>
struct vk_function<compile_time_hash("vkImportFenceSciSyncObjNV"_literal)>
{
    using type                 = PFN_vkImportFenceSciSyncObjNV;
    static constexpr auto name = "vkImportFenceSciSyncObjNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSciSyncAttributesNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSciSyncAttributesNV;
    static constexpr auto name = "vkGetPhysicalDeviceSciSyncAttributesNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
template<>
struct vk_function<compile_time_hash("vkGetSemaphoreSciSyncObjNV"_literal)>
{
    using type                 = PFN_vkGetSemaphoreSciSyncObjNV;
    static constexpr auto name = "vkGetSemaphoreSciSyncObjNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_sci_sync)
template<>
struct vk_function<compile_time_hash("vkImportSemaphoreSciSyncObjNV"_literal)>
{
    using type                 = PFN_vkImportSemaphoreSciSyncObjNV;
    static constexpr auto name = "vkImportSemaphoreSciSyncObjNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync)

#if defined(VK_NV_external_memory_sci_buf)
template<>
struct vk_function<compile_time_hash("vkGetMemorySciBufNV"_literal)>
{
    using type                 = PFN_vkGetMemorySciBufNV;
    static constexpr auto name = "vkGetMemorySciBufNV"_literal;
};
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV;
    static constexpr auto name = "vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV"_literal;
};
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_NV_external_memory_sci_buf)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceSciBufAttributesNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceSciBufAttributesNV;
    static constexpr auto name = "vkGetPhysicalDeviceSciBufAttributesNV"_literal;
};
#endif // #if defined (VK_NV_external_memory_sci_buf)

#if defined(VK_EXT_extended_dynamic_state2)
template<>
struct vk_function<compile_time_hash("vkCmdSetPatchControlPointsEXT"_literal)>
{
    using type                 = PFN_vkCmdSetPatchControlPointsEXT;
    static constexpr auto name = "vkCmdSetPatchControlPointsEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2)
template<>
struct vk_function<compile_time_hash("vkCmdSetRasterizerDiscardEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetRasterizerDiscardEnableEXT;
    static constexpr auto name = "vkCmdSetRasterizerDiscardEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthBiasEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthBiasEnableEXT;
    static constexpr auto name = "vkCmdSetDepthBiasEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2)
template<>
struct vk_function<compile_time_hash("vkCmdSetLogicOpEXT"_literal)>
{
    using type                 = PFN_vkCmdSetLogicOpEXT;
    static constexpr auto name = "vkCmdSetLogicOpEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_EXT_extended_dynamic_state2)
template<>
struct vk_function<compile_time_hash("vkCmdSetPrimitiveRestartEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetPrimitiveRestartEnableEXT;
    static constexpr auto name = "vkCmdSetPrimitiveRestartEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state2)

#if defined(VK_QNX_screen_surface)
template<>
struct vk_function<compile_time_hash("vkCreateScreenSurfaceQNX"_literal)>
{
    using type                 = PFN_vkCreateScreenSurfaceQNX;
    static constexpr auto name = "vkCreateScreenSurfaceQNX"_literal;
};
#endif // #if defined (VK_QNX_screen_surface)

#if defined(VK_QNX_screen_surface)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceScreenPresentationSupportQNX"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX;
    static constexpr auto name = "vkGetPhysicalDeviceScreenPresentationSupportQNX"_literal;
};
#endif // #if defined (VK_QNX_screen_surface)

#if defined(VK_EXT_color_write_enable)
template<>
struct vk_function<compile_time_hash("vkCmdSetColorWriteEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetColorWriteEnableEXT;
    static constexpr auto name = "vkCmdSetColorWriteEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_color_write_enable)

#if defined(VK_KHR_ray_tracing_maintenance1)
template<>
struct vk_function<compile_time_hash("vkCmdTraceRaysIndirect2KHR"_literal)>
{
    using type                 = PFN_vkCmdTraceRaysIndirect2KHR;
    static constexpr auto name = "vkCmdTraceRaysIndirect2KHR"_literal;
};
#endif // #if defined (VK_KHR_ray_tracing_maintenance1)

#if defined(VK_EXT_multi_draw)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMultiEXT"_literal)>
{
    using type                 = PFN_vkCmdDrawMultiEXT;
    static constexpr auto name = "vkCmdDrawMultiEXT"_literal;
};
#endif // #if defined (VK_EXT_multi_draw)

#if defined(VK_EXT_multi_draw)
template<>
struct vk_function<compile_time_hash("vkCmdDrawMultiIndexedEXT"_literal)>
{
    using type                 = PFN_vkCmdDrawMultiIndexedEXT;
    static constexpr auto name = "vkCmdDrawMultiIndexedEXT"_literal;
};
#endif // #if defined (VK_EXT_multi_draw)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCreateMicromapEXT"_literal)>
{
    using type                 = PFN_vkCreateMicromapEXT;
    static constexpr auto name = "vkCreateMicromapEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkDestroyMicromapEXT"_literal)>
{
    using type                 = PFN_vkDestroyMicromapEXT;
    static constexpr auto name = "vkDestroyMicromapEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkBuildMicromapsEXT"_literal)>
{
    using type                 = PFN_vkBuildMicromapsEXT;
    static constexpr auto name = "vkBuildMicromapsEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCopyMicromapEXT"_literal)>
{
    using type                 = PFN_vkCopyMicromapEXT;
    static constexpr auto name = "vkCopyMicromapEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCopyMicromapToMemoryEXT"_literal)>
{
    using type                 = PFN_vkCopyMicromapToMemoryEXT;
    static constexpr auto name = "vkCopyMicromapToMemoryEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCopyMemoryToMicromapEXT"_literal)>
{
    using type                 = PFN_vkCopyMemoryToMicromapEXT;
    static constexpr auto name = "vkCopyMemoryToMicromapEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkWriteMicromapsPropertiesEXT"_literal)>
{
    using type                 = PFN_vkWriteMicromapsPropertiesEXT;
    static constexpr auto name = "vkWriteMicromapsPropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkGetDeviceMicromapCompatibilityEXT"_literal)>
{
    using type                 = PFN_vkGetDeviceMicromapCompatibilityEXT;
    static constexpr auto name = "vkGetDeviceMicromapCompatibilityEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkGetMicromapBuildSizesEXT"_literal)>
{
    using type                 = PFN_vkGetMicromapBuildSizesEXT;
    static constexpr auto name = "vkGetMicromapBuildSizesEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCmdBuildMicromapsEXT"_literal)>
{
    using type                 = PFN_vkCmdBuildMicromapsEXT;
    static constexpr auto name = "vkCmdBuildMicromapsEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCmdCopyMicromapEXT"_literal)>
{
    using type                 = PFN_vkCmdCopyMicromapEXT;
    static constexpr auto name = "vkCmdCopyMicromapEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCmdCopyMicromapToMemoryEXT"_literal)>
{
    using type                 = PFN_vkCmdCopyMicromapToMemoryEXT;
    static constexpr auto name = "vkCmdCopyMicromapToMemoryEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCmdCopyMemoryToMicromapEXT"_literal)>
{
    using type                 = PFN_vkCmdCopyMemoryToMicromapEXT;
    static constexpr auto name = "vkCmdCopyMemoryToMicromapEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_EXT_opacity_micromap)
template<>
struct vk_function<compile_time_hash("vkCmdWriteMicromapsPropertiesEXT"_literal)>
{
    using type                 = PFN_vkCmdWriteMicromapsPropertiesEXT;
    static constexpr auto name = "vkCmdWriteMicromapsPropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_opacity_micromap)

#if defined(VK_HUAWEI_cluster_culling_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawClusterHUAWEI"_literal)>
{
    using type                 = PFN_vkCmdDrawClusterHUAWEI;
    static constexpr auto name = "vkCmdDrawClusterHUAWEI"_literal;
};
#endif // #if defined (VK_HUAWEI_cluster_culling_shader)

#if defined(VK_HUAWEI_cluster_culling_shader)
template<>
struct vk_function<compile_time_hash("vkCmdDrawClusterIndirectHUAWEI"_literal)>
{
    using type                 = PFN_vkCmdDrawClusterIndirectHUAWEI;
    static constexpr auto name = "vkCmdDrawClusterIndirectHUAWEI"_literal;
};
#endif // #if defined (VK_HUAWEI_cluster_culling_shader)

#if defined(VK_EXT_pageable_device_local_memory)
template<>
struct vk_function<compile_time_hash("vkSetDeviceMemoryPriorityEXT"_literal)>
{
    using type                 = PFN_vkSetDeviceMemoryPriorityEXT;
    static constexpr auto name = "vkSetDeviceMemoryPriorityEXT"_literal;
};
#endif // #if defined (VK_EXT_pageable_device_local_memory)

#if defined(VK_KHR_maintenance4)
template<>
struct vk_function<compile_time_hash("vkGetDeviceBufferMemoryRequirementsKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceBufferMemoryRequirementsKHR;
    static constexpr auto name = "vkGetDeviceBufferMemoryRequirementsKHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance4)

#if defined(VK_KHR_maintenance4)
template<>
struct vk_function<compile_time_hash("vkGetDeviceImageMemoryRequirementsKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceImageMemoryRequirementsKHR;
    static constexpr auto name = "vkGetDeviceImageMemoryRequirementsKHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance4)

#if defined(VK_KHR_maintenance4)
template<>
struct vk_function<compile_time_hash("vkGetDeviceImageSparseMemoryRequirementsKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceImageSparseMemoryRequirementsKHR;
    static constexpr auto name = "vkGetDeviceImageSparseMemoryRequirementsKHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance4)

#if defined(VK_VALVE_descriptor_set_host_mapping)
template<>
struct vk_function<compile_time_hash("vkGetDescriptorSetLayoutHostMappingInfoVALVE"_literal)>
{
    using type                 = PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE;
    static constexpr auto name = "vkGetDescriptorSetLayoutHostMappingInfoVALVE"_literal;
};
#endif // #if defined (VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_VALVE_descriptor_set_host_mapping)
template<>
struct vk_function<compile_time_hash("vkGetDescriptorSetHostMappingVALVE"_literal)>
{
    using type                 = PFN_vkGetDescriptorSetHostMappingVALVE;
    static constexpr auto name = "vkGetDescriptorSetHostMappingVALVE"_literal;
};
#endif // #if defined (VK_VALVE_descriptor_set_host_mapping)

#if defined(VK_NV_copy_memory_indirect)
template<>
struct vk_function<compile_time_hash("vkCmdCopyMemoryIndirectNV"_literal)>
{
    using type                 = PFN_vkCmdCopyMemoryIndirectNV;
    static constexpr auto name = "vkCmdCopyMemoryIndirectNV"_literal;
};
#endif // #if defined (VK_NV_copy_memory_indirect)

#if defined(VK_NV_copy_memory_indirect)
template<>
struct vk_function<compile_time_hash("vkCmdCopyMemoryToImageIndirectNV"_literal)>
{
    using type                 = PFN_vkCmdCopyMemoryToImageIndirectNV;
    static constexpr auto name = "vkCmdCopyMemoryToImageIndirectNV"_literal;
};
#endif // #if defined (VK_NV_copy_memory_indirect)

#if defined(VK_NV_memory_decompression)
template<>
struct vk_function<compile_time_hash("vkCmdDecompressMemoryNV"_literal)>
{
    using type                 = PFN_vkCmdDecompressMemoryNV;
    static constexpr auto name = "vkCmdDecompressMemoryNV"_literal;
};
#endif // #if defined (VK_NV_memory_decompression)

#if defined(VK_NV_memory_decompression)
template<>
struct vk_function<compile_time_hash("vkCmdDecompressMemoryIndirectCountNV"_literal)>
{
    using type                 = PFN_vkCmdDecompressMemoryIndirectCountNV;
    static constexpr auto name = "vkCmdDecompressMemoryIndirectCountNV"_literal;
};
#endif // #if defined (VK_NV_memory_decompression)

#if defined(VK_NV_device_generated_commands_compute)
template<>
struct vk_function<compile_time_hash("vkGetPipelineIndirectMemoryRequirementsNV"_literal)>
{
    using type                 = PFN_vkGetPipelineIndirectMemoryRequirementsNV;
    static constexpr auto name = "vkGetPipelineIndirectMemoryRequirementsNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands_compute)

#if defined(VK_NV_device_generated_commands_compute)
template<>
struct vk_function<compile_time_hash("vkGetPipelineIndirectDeviceAddressNV"_literal)>
{
    using type                 = PFN_vkGetPipelineIndirectDeviceAddressNV;
    static constexpr auto name = "vkGetPipelineIndirectDeviceAddressNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands_compute)

#if defined(VK_NV_device_generated_commands_compute)
template<>
struct vk_function<compile_time_hash("vkCmdUpdatePipelineIndirectBufferNV"_literal)>
{
    using type                 = PFN_vkCmdUpdatePipelineIndirectBufferNV;
    static constexpr auto name = "vkCmdUpdatePipelineIndirectBufferNV"_literal;
};
#endif // #if defined (VK_NV_device_generated_commands_compute)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthClampEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthClampEnableEXT;
    static constexpr auto name = "vkCmdSetDepthClampEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetPolygonModeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetPolygonModeEXT;
    static constexpr auto name = "vkCmdSetPolygonModeEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetRasterizationSamplesEXT"_literal)>
{
    using type                 = PFN_vkCmdSetRasterizationSamplesEXT;
    static constexpr auto name = "vkCmdSetRasterizationSamplesEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetSampleMaskEXT"_literal)>
{
    using type                 = PFN_vkCmdSetSampleMaskEXT;
    static constexpr auto name = "vkCmdSetSampleMaskEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetAlphaToCoverageEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetAlphaToCoverageEnableEXT;
    static constexpr auto name = "vkCmdSetAlphaToCoverageEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetAlphaToOneEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetAlphaToOneEnableEXT;
    static constexpr auto name = "vkCmdSetAlphaToOneEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetLogicOpEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetLogicOpEnableEXT;
    static constexpr auto name = "vkCmdSetLogicOpEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetColorBlendEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetColorBlendEnableEXT;
    static constexpr auto name = "vkCmdSetColorBlendEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetColorBlendEquationEXT"_literal)>
{
    using type                 = PFN_vkCmdSetColorBlendEquationEXT;
    static constexpr auto name = "vkCmdSetColorBlendEquationEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetColorWriteMaskEXT"_literal)>
{
    using type                 = PFN_vkCmdSetColorWriteMaskEXT;
    static constexpr auto name = "vkCmdSetColorWriteMaskEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetTessellationDomainOriginEXT"_literal)>
{
    using type                 = PFN_vkCmdSetTessellationDomainOriginEXT;
    static constexpr auto name = "vkCmdSetTessellationDomainOriginEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetRasterizationStreamEXT"_literal)>
{
    using type                 = PFN_vkCmdSetRasterizationStreamEXT;
    static constexpr auto name = "vkCmdSetRasterizationStreamEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetConservativeRasterizationModeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetConservativeRasterizationModeEXT;
    static constexpr auto name = "vkCmdSetConservativeRasterizationModeEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetExtraPrimitiveOverestimationSizeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT;
    static constexpr auto name = "vkCmdSetExtraPrimitiveOverestimationSizeEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthClipEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthClipEnableEXT;
    static constexpr auto name = "vkCmdSetDepthClipEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetSampleLocationsEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetSampleLocationsEnableEXT;
    static constexpr auto name = "vkCmdSetSampleLocationsEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetColorBlendAdvancedEXT"_literal)>
{
    using type                 = PFN_vkCmdSetColorBlendAdvancedEXT;
    static constexpr auto name = "vkCmdSetColorBlendAdvancedEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetProvokingVertexModeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetProvokingVertexModeEXT;
    static constexpr auto name = "vkCmdSetProvokingVertexModeEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetLineRasterizationModeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetLineRasterizationModeEXT;
    static constexpr auto name = "vkCmdSetLineRasterizationModeEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetLineStippleEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetLineStippleEnableEXT;
    static constexpr auto name = "vkCmdSetLineStippleEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthClipNegativeOneToOneEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthClipNegativeOneToOneEXT;
    static constexpr auto name = "vkCmdSetDepthClipNegativeOneToOneEXT"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetViewportWScalingEnableNV"_literal)>
{
    using type                 = PFN_vkCmdSetViewportWScalingEnableNV;
    static constexpr auto name = "vkCmdSetViewportWScalingEnableNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetViewportSwizzleNV"_literal)>
{
    using type                 = PFN_vkCmdSetViewportSwizzleNV;
    static constexpr auto name = "vkCmdSetViewportSwizzleNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetCoverageToColorEnableNV"_literal)>
{
    using type                 = PFN_vkCmdSetCoverageToColorEnableNV;
    static constexpr auto name = "vkCmdSetCoverageToColorEnableNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetCoverageToColorLocationNV"_literal)>
{
    using type                 = PFN_vkCmdSetCoverageToColorLocationNV;
    static constexpr auto name = "vkCmdSetCoverageToColorLocationNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetCoverageModulationModeNV"_literal)>
{
    using type                 = PFN_vkCmdSetCoverageModulationModeNV;
    static constexpr auto name = "vkCmdSetCoverageModulationModeNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetCoverageModulationTableEnableNV"_literal)>
{
    using type                 = PFN_vkCmdSetCoverageModulationTableEnableNV;
    static constexpr auto name = "vkCmdSetCoverageModulationTableEnableNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetCoverageModulationTableNV"_literal)>
{
    using type                 = PFN_vkCmdSetCoverageModulationTableNV;
    static constexpr auto name = "vkCmdSetCoverageModulationTableNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetShadingRateImageEnableNV"_literal)>
{
    using type                 = PFN_vkCmdSetShadingRateImageEnableNV;
    static constexpr auto name = "vkCmdSetShadingRateImageEnableNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetRepresentativeFragmentTestEnableNV"_literal)>
{
    using type                 = PFN_vkCmdSetRepresentativeFragmentTestEnableNV;
    static constexpr auto name = "vkCmdSetRepresentativeFragmentTestEnableNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_extended_dynamic_state3)
template<>
struct vk_function<compile_time_hash("vkCmdSetCoverageReductionModeNV"_literal)>
{
    using type                 = PFN_vkCmdSetCoverageReductionModeNV;
    static constexpr auto name = "vkCmdSetCoverageReductionModeNV"_literal;
};
#endif // #if defined (VK_EXT_extended_dynamic_state3)

#if defined(VK_EXT_shader_module_identifier)
template<>
struct vk_function<compile_time_hash("vkGetShaderModuleIdentifierEXT"_literal)>
{
    using type                 = PFN_vkGetShaderModuleIdentifierEXT;
    static constexpr auto name = "vkGetShaderModuleIdentifierEXT"_literal;
};
#endif // #if defined (VK_EXT_shader_module_identifier)

#if defined(VK_EXT_shader_module_identifier)
template<>
struct vk_function<compile_time_hash("vkGetShaderModuleCreateInfoIdentifierEXT"_literal)>
{
    using type                 = PFN_vkGetShaderModuleCreateInfoIdentifierEXT;
    static constexpr auto name = "vkGetShaderModuleCreateInfoIdentifierEXT"_literal;
};
#endif // #if defined (VK_EXT_shader_module_identifier)

#if defined(VK_NV_optical_flow)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceOpticalFlowImageFormatsNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV;
    static constexpr auto name = "vkGetPhysicalDeviceOpticalFlowImageFormatsNV"_literal;
};
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct vk_function<compile_time_hash("vkCreateOpticalFlowSessionNV"_literal)>
{
    using type                 = PFN_vkCreateOpticalFlowSessionNV;
    static constexpr auto name = "vkCreateOpticalFlowSessionNV"_literal;
};
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct vk_function<compile_time_hash("vkDestroyOpticalFlowSessionNV"_literal)>
{
    using type                 = PFN_vkDestroyOpticalFlowSessionNV;
    static constexpr auto name = "vkDestroyOpticalFlowSessionNV"_literal;
};
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct vk_function<compile_time_hash("vkBindOpticalFlowSessionImageNV"_literal)>
{
    using type                 = PFN_vkBindOpticalFlowSessionImageNV;
    static constexpr auto name = "vkBindOpticalFlowSessionImageNV"_literal;
};
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_NV_optical_flow)
template<>
struct vk_function<compile_time_hash("vkCmdOpticalFlowExecuteNV"_literal)>
{
    using type                 = PFN_vkCmdOpticalFlowExecuteNV;
    static constexpr auto name = "vkCmdOpticalFlowExecuteNV"_literal;
};
#endif // #if defined (VK_NV_optical_flow)

#if defined(VK_KHR_maintenance5)
template<>
struct vk_function<compile_time_hash("vkGetRenderingAreaGranularityKHR"_literal)>
{
    using type                 = PFN_vkGetRenderingAreaGranularityKHR;
    static constexpr auto name = "vkGetRenderingAreaGranularityKHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance5)

#if defined(VK_KHR_maintenance5)
template<>
struct vk_function<compile_time_hash("vkGetDeviceImageSubresourceLayoutKHR"_literal)>
{
    using type                 = PFN_vkGetDeviceImageSubresourceLayoutKHR;
    static constexpr auto name = "vkGetDeviceImageSubresourceLayoutKHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance5)

#if defined(VK_KHR_maintenance5)
template<>
struct vk_function<compile_time_hash("vkGetImageSubresourceLayout2KHR"_literal)>
{
    using type                 = PFN_vkGetImageSubresourceLayout2KHR;
    static constexpr auto name = "vkGetImageSubresourceLayout2KHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance5)

#if defined(VK_KHR_maintenance5)
template<>
struct vk_function<compile_time_hash("vkCmdBindIndexBuffer2KHR"_literal)>
{
    using type                 = PFN_vkCmdBindIndexBuffer2KHR;
    static constexpr auto name = "vkCmdBindIndexBuffer2KHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance5)

#if defined(VK_AMD_anti_lag)
template<>
struct vk_function<compile_time_hash("vkAntiLagUpdateAMD"_literal)>
{
    using type                 = PFN_vkAntiLagUpdateAMD;
    static constexpr auto name = "vkAntiLagUpdateAMD"_literal;
};
#endif // #if defined (VK_AMD_anti_lag)

#if defined(VK_EXT_shader_object)
template<>
struct vk_function<compile_time_hash("vkCreateShadersEXT"_literal)>
{
    using type                 = PFN_vkCreateShadersEXT;
    static constexpr auto name = "vkCreateShadersEXT"_literal;
};
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
template<>
struct vk_function<compile_time_hash("vkDestroyShaderEXT"_literal)>
{
    using type                 = PFN_vkDestroyShaderEXT;
    static constexpr auto name = "vkDestroyShaderEXT"_literal;
};
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
template<>
struct vk_function<compile_time_hash("vkGetShaderBinaryDataEXT"_literal)>
{
    using type                 = PFN_vkGetShaderBinaryDataEXT;
    static constexpr auto name = "vkGetShaderBinaryDataEXT"_literal;
};
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
template<>
struct vk_function<compile_time_hash("vkCmdBindShadersEXT"_literal)>
{
    using type                 = PFN_vkCmdBindShadersEXT;
    static constexpr auto name = "vkCmdBindShadersEXT"_literal;
};
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_EXT_shader_object)
template<>
struct vk_function<compile_time_hash("vkCmdSetDepthClampRangeEXT"_literal)>
{
    using type                 = PFN_vkCmdSetDepthClampRangeEXT;
    static constexpr auto name = "vkCmdSetDepthClampRangeEXT"_literal;
};
#endif // #if defined (VK_EXT_shader_object)

#if defined(VK_KHR_pipeline_binary)
template<>
struct vk_function<compile_time_hash("vkCreatePipelineBinariesKHR"_literal)>
{
    using type                 = PFN_vkCreatePipelineBinariesKHR;
    static constexpr auto name = "vkCreatePipelineBinariesKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct vk_function<compile_time_hash("vkDestroyPipelineBinaryKHR"_literal)>
{
    using type                 = PFN_vkDestroyPipelineBinaryKHR;
    static constexpr auto name = "vkDestroyPipelineBinaryKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct vk_function<compile_time_hash("vkGetPipelineKeyKHR"_literal)>
{
    using type                 = PFN_vkGetPipelineKeyKHR;
    static constexpr auto name = "vkGetPipelineKeyKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct vk_function<compile_time_hash("vkGetPipelineBinaryDataKHR"_literal)>
{
    using type                 = PFN_vkGetPipelineBinaryDataKHR;
    static constexpr auto name = "vkGetPipelineBinaryDataKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_KHR_pipeline_binary)
template<>
struct vk_function<compile_time_hash("vkReleaseCapturedPipelineDataKHR"_literal)>
{
    using type                 = PFN_vkReleaseCapturedPipelineDataKHR;
    static constexpr auto name = "vkReleaseCapturedPipelineDataKHR"_literal;
};
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_QCOM_tile_properties)
template<>
struct vk_function<compile_time_hash("vkGetFramebufferTilePropertiesQCOM"_literal)>
{
    using type                 = PFN_vkGetFramebufferTilePropertiesQCOM;
    static constexpr auto name = "vkGetFramebufferTilePropertiesQCOM"_literal;
};
#endif // #if defined (VK_QCOM_tile_properties)

#if defined(VK_QCOM_tile_properties)
template<>
struct vk_function<compile_time_hash("vkGetDynamicRenderingTilePropertiesQCOM"_literal)>
{
    using type                 = PFN_vkGetDynamicRenderingTilePropertiesQCOM;
    static constexpr auto name = "vkGetDynamicRenderingTilePropertiesQCOM"_literal;
};
#endif // #if defined (VK_QCOM_tile_properties)

#if defined(VK_NV_external_sci_sync2)
template<>
struct vk_function<compile_time_hash("vkCreateSemaphoreSciSyncPoolNV"_literal)>
{
    using type                 = PFN_vkCreateSemaphoreSciSyncPoolNV;
    static constexpr auto name = "vkCreateSemaphoreSciSyncPoolNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_external_sci_sync2)
template<>
struct vk_function<compile_time_hash("vkDestroySemaphoreSciSyncPoolNV"_literal)>
{
    using type                 = PFN_vkDestroySemaphoreSciSyncPoolNV;
    static constexpr auto name = "vkDestroySemaphoreSciSyncPoolNV"_literal;
};
#endif // #if defined (VK_NV_external_sci_sync2)

#if defined(VK_NV_cooperative_vector)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceCooperativeVectorPropertiesNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV;
    static constexpr auto name = "vkGetPhysicalDeviceCooperativeVectorPropertiesNV"_literal;
};
#endif // #if defined (VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
template<>
struct vk_function<compile_time_hash("vkConvertCooperativeVectorMatrixNV"_literal)>
{
    using type                 = PFN_vkConvertCooperativeVectorMatrixNV;
    static constexpr auto name = "vkConvertCooperativeVectorMatrixNV"_literal;
};
#endif // #if defined (VK_NV_cooperative_vector)

#if defined(VK_NV_cooperative_vector)
template<>
struct vk_function<compile_time_hash("vkCmdConvertCooperativeVectorMatrixNV"_literal)>
{
    using type                 = PFN_vkCmdConvertCooperativeVectorMatrixNV;
    static constexpr auto name = "vkCmdConvertCooperativeVectorMatrixNV"_literal;
};
#endif // #if defined (VK_NV_cooperative_vector)

#if defined(VK_NV_low_latency2)
template<>
struct vk_function<compile_time_hash("vkSetLatencySleepModeNV"_literal)>
{
    using type                 = PFN_vkSetLatencySleepModeNV;
    static constexpr auto name = "vkSetLatencySleepModeNV"_literal;
};
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct vk_function<compile_time_hash("vkLatencySleepNV"_literal)>
{
    using type                 = PFN_vkLatencySleepNV;
    static constexpr auto name = "vkLatencySleepNV"_literal;
};
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct vk_function<compile_time_hash("vkSetLatencyMarkerNV"_literal)>
{
    using type                 = PFN_vkSetLatencyMarkerNV;
    static constexpr auto name = "vkSetLatencyMarkerNV"_literal;
};
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct vk_function<compile_time_hash("vkGetLatencyTimingsNV"_literal)>
{
    using type                 = PFN_vkGetLatencyTimingsNV;
    static constexpr auto name = "vkGetLatencyTimingsNV"_literal;
};
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_NV_low_latency2)
template<>
struct vk_function<compile_time_hash("vkQueueNotifyOutOfBandNV"_literal)>
{
    using type                 = PFN_vkQueueNotifyOutOfBandNV;
    static constexpr auto name = "vkQueueNotifyOutOfBandNV"_literal;
};
#endif // #if defined (VK_NV_low_latency2)

#if defined(VK_KHR_cooperative_matrix)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR;
    static constexpr auto name = "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR"_literal;
};
#endif // #if defined (VK_KHR_cooperative_matrix)

#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
template<>
struct vk_function<compile_time_hash("vkCmdSetAttachmentFeedbackLoopEnableEXT"_literal)>
{
    using type                 = PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT;
    static constexpr auto name = "vkCmdSetAttachmentFeedbackLoopEnableEXT"_literal;
};
#endif // #if defined (VK_EXT_attachment_feedback_loop_dynamic_state)

#if defined(VK_QNX_external_memory_screen_buffer)
template<>
struct vk_function<compile_time_hash("vkGetScreenBufferPropertiesQNX"_literal)>
{
    using type                 = PFN_vkGetScreenBufferPropertiesQNX;
    static constexpr auto name = "vkGetScreenBufferPropertiesQNX"_literal;
};
#endif // #if defined (VK_QNX_external_memory_screen_buffer)

#if defined(VK_KHR_line_rasterization)
template<>
struct vk_function<compile_time_hash("vkCmdSetLineStippleKHR"_literal)>
{
    using type                 = PFN_vkCmdSetLineStippleKHR;
    static constexpr auto name = "vkCmdSetLineStippleKHR"_literal;
};
#endif // #if defined (VK_KHR_line_rasterization)

#if defined(VK_KHR_calibrated_timestamps)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR;
    static constexpr auto name = "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR"_literal;
};
#endif // #if defined (VK_KHR_calibrated_timestamps)

#if defined(VK_KHR_calibrated_timestamps)
template<>
struct vk_function<compile_time_hash("vkGetCalibratedTimestampsKHR"_literal)>
{
    using type                 = PFN_vkGetCalibratedTimestampsKHR;
    static constexpr auto name = "vkGetCalibratedTimestampsKHR"_literal;
};
#endif // #if defined (VK_KHR_calibrated_timestamps)

#if defined(VK_KHR_maintenance6)
template<>
struct vk_function<compile_time_hash("vkCmdBindDescriptorSets2KHR"_literal)>
{
    using type                 = PFN_vkCmdBindDescriptorSets2KHR;
    static constexpr auto name = "vkCmdBindDescriptorSets2KHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct vk_function<compile_time_hash("vkCmdPushConstants2KHR"_literal)>
{
    using type                 = PFN_vkCmdPushConstants2KHR;
    static constexpr auto name = "vkCmdPushConstants2KHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSet2KHR"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSet2KHR;
    static constexpr auto name = "vkCmdPushDescriptorSet2KHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct vk_function<compile_time_hash("vkCmdPushDescriptorSetWithTemplate2KHR"_literal)>
{
    using type                 = PFN_vkCmdPushDescriptorSetWithTemplate2KHR;
    static constexpr auto name = "vkCmdPushDescriptorSetWithTemplate2KHR"_literal;
};
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct vk_function<compile_time_hash("vkCmdSetDescriptorBufferOffsets2EXT"_literal)>
{
    using type                 = PFN_vkCmdSetDescriptorBufferOffsets2EXT;
    static constexpr auto name = "vkCmdSetDescriptorBufferOffsets2EXT"_literal;
};
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_KHR_maintenance6)
template<>
struct vk_function<compile_time_hash("vkCmdBindDescriptorBufferEmbeddedSamplers2EXT"_literal)>
{
    using type                 = PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT;
    static constexpr auto name = "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT"_literal;
};
#endif // #if defined (VK_KHR_maintenance6)

#if defined(VK_NV_cluster_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkGetClusterAccelerationStructureBuildSizesNV"_literal)>
{
    using type                 = PFN_vkGetClusterAccelerationStructureBuildSizesNV;
    static constexpr auto name = "vkGetClusterAccelerationStructureBuildSizesNV"_literal;
};
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_cluster_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdBuildClusterAccelerationStructureIndirectNV"_literal)>
{
    using type                 = PFN_vkCmdBuildClusterAccelerationStructureIndirectNV;
    static constexpr auto name = "vkCmdBuildClusterAccelerationStructureIndirectNV"_literal;
};
#endif // #if defined (VK_NV_cluster_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkGetPartitionedAccelerationStructuresBuildSizesNV"_literal)>
{
    using type                 = PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV;
    static constexpr auto name = "vkGetPartitionedAccelerationStructuresBuildSizesNV"_literal;
};
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_NV_partitioned_acceleration_structure)
template<>
struct vk_function<compile_time_hash("vkCmdBuildPartitionedAccelerationStructuresNV"_literal)>
{
    using type                 = PFN_vkCmdBuildPartitionedAccelerationStructuresNV;
    static constexpr auto name = "vkCmdBuildPartitionedAccelerationStructuresNV"_literal;
};
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkGetGeneratedCommandsMemoryRequirementsEXT"_literal)>
{
    using type                 = PFN_vkGetGeneratedCommandsMemoryRequirementsEXT;
    static constexpr auto name = "vkGetGeneratedCommandsMemoryRequirementsEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCreateIndirectCommandsLayoutEXT"_literal)>
{
    using type                 = PFN_vkCreateIndirectCommandsLayoutEXT;
    static constexpr auto name = "vkCreateIndirectCommandsLayoutEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkDestroyIndirectCommandsLayoutEXT"_literal)>
{
    using type                 = PFN_vkDestroyIndirectCommandsLayoutEXT;
    static constexpr auto name = "vkDestroyIndirectCommandsLayoutEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCreateIndirectExecutionSetEXT"_literal)>
{
    using type                 = PFN_vkCreateIndirectExecutionSetEXT;
    static constexpr auto name = "vkCreateIndirectExecutionSetEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkDestroyIndirectExecutionSetEXT"_literal)>
{
    using type                 = PFN_vkDestroyIndirectExecutionSetEXT;
    static constexpr auto name = "vkDestroyIndirectExecutionSetEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkUpdateIndirectExecutionSetPipelineEXT"_literal)>
{
    using type                 = PFN_vkUpdateIndirectExecutionSetPipelineEXT;
    static constexpr auto name = "vkUpdateIndirectExecutionSetPipelineEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkUpdateIndirectExecutionSetShaderEXT"_literal)>
{
    using type                 = PFN_vkUpdateIndirectExecutionSetShaderEXT;
    static constexpr auto name = "vkUpdateIndirectExecutionSetShaderEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCmdPreprocessGeneratedCommandsEXT"_literal)>
{
    using type                 = PFN_vkCmdPreprocessGeneratedCommandsEXT;
    static constexpr auto name = "vkCmdPreprocessGeneratedCommandsEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct vk_function<compile_time_hash("vkCmdExecuteGeneratedCommandsEXT"_literal)>
{
    using type                 = PFN_vkCmdExecuteGeneratedCommandsEXT;
    static constexpr auto name = "vkCmdExecuteGeneratedCommandsEXT"_literal;
};
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_NV_cooperative_matrix2)
template<>
struct vk_function<compile_time_hash("vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV"_literal)>
{
    using type                 = PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV;
    static constexpr auto name = "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV"_literal;
};
#endif // #if defined (VK_NV_cooperative_matrix2)

#if defined(VK_EXT_external_memory_metal)
template<>
struct vk_function<compile_time_hash("vkGetMemoryMetalHandleEXT"_literal)>
{
    using type                 = PFN_vkGetMemoryMetalHandleEXT;
    static constexpr auto name = "vkGetMemoryMetalHandleEXT"_literal;
};
#endif // #if defined (VK_EXT_external_memory_metal)

#if defined(VK_EXT_external_memory_metal)
template<>
struct vk_function<compile_time_hash("vkGetMemoryMetalHandlePropertiesEXT"_literal)>
{
    using type                 = PFN_vkGetMemoryMetalHandlePropertiesEXT;
    static constexpr auto name = "vkGetMemoryMetalHandlePropertiesEXT"_literal;
};
#endif // #if defined (VK_EXT_external_memory_metal)

#if defined(VK_EXT_fragment_density_map_offset)
template<>
struct vk_function<compile_time_hash("vkCmdEndRendering2EXT"_literal)>
{
    using type                 = PFN_vkCmdEndRendering2EXT;
    static constexpr auto name = "vkCmdEndRendering2EXT"_literal;
};
#endif // #if defined (VK_EXT_fragment_density_map_offset)

// clang-format on
//------------------------------------------------------------------------------

#undef FUBUKI_MAKE_PFN_TRAITS

} // namespace traits

} // namespace fubuki::detail

#endif // FUBUKI_CORE_DETAIL_PFN_HPP
