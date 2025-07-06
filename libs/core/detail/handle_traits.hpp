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

#ifndef FUBUKI_CORE_DETAIL_HANDLE_TRAITS_HPP
#define FUBUKI_CORE_DETAIL_HANDLE_TRAITS_HPP

#include "core/handle.hpp"
#include "core/string_literal.hpp"
#include "core/vulkan.hpp"

namespace fubuki::detail
{

template<typename handle_type>
struct handle_traits
{
    // Generic invalid values for concept declaration
    using parent          = void; ///< Parent of the handle.
    using handle          = void; ///< Type of the handle itself.
    using underlying_type = void; ///< Type of the underlying Vulkan handle.
    using vk_info         = void; ///< Type of the structure type to create/allocate a handle of this type.
    using pfn_create      = void; ///< Type of the function pointer to create/allocate a handle of this type.
    using pfn_destroy     = void; ///< Type of the function pointer to destroy/free a handle of this type.

    static constexpr auto pfn_create_name  = ""_literal; ///< Name of the function pointer to retrieve, as a raw string literal.
    static constexpr auto pfn_destroy_name = ""_literal; ///< Name of the function pointer to retrieve, as a raw string literal.
};

template<typename handle_type>
concept creatable_handle = not std::is_same_v<typename handle_traits<handle_type>::handle, void>
    and not std::is_same_v<typename handle_traits<handle_type>::underlying_type, void>
    and not std::is_same_v<typename handle_traits<handle_type>::vk_info, void>
    and not std::is_same_v<typename handle_traits<handle_type>::pfn_create, void>
    and not std::is_same_v<typename handle_traits<handle_type>::pfn_destroy, void>;

template<typename T>
struct is_handle;

template<typename T>
struct is_handle : std::false_type
{
};

template<std::uint64_t hash, typename T>
struct is_handle<fubuki::handle<hash, T>> : std::true_type
{
};

template<typename T>
inline constexpr bool is_handle_v = is_handle<T>::value;

//------------------------------------------------------------------------------
// Generated code

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<instance_handle>
{
    using handle          = instance_handle;
    using parent          = void;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkInstanceCreateInfo;
    using pfn_create      = PFN_vkCreateInstance;
    using pfn_destroy     = PFN_vkDestroyInstance;

    static constexpr auto pfn_create_name  = "vkCreateInstance"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyInstance"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
/*template<>
struct handle_traits<physical_device_handle>
{
    using handle          = physical_device_handle;
    using parent          = instance_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = ""_literal;
};*/
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<device_handle>
{
    using handle          = device_handle;
    using parent          = physical_device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDeviceCreateInfo;
    using pfn_create      = PFN_vkCreateDevice;
    using pfn_destroy     = PFN_vkDestroyDevice;

    static constexpr auto pfn_create_name  = "vkCreateDevice"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyDevice"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
/*template<>
struct handle_traits<queue_handle>
{
    using handle          = queue_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = ""_literal;
};*/
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<command_buffer_handle>
{
    using handle          = command_buffer_handle;
    using parent          = command_pool_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkCommandBufferAllocateInfo;
    using pfn_create      = PFN_vkAllocateCommandBuffers;
    using pfn_destroy     = PFN_vkFreeCommandBuffers;

    static constexpr auto pfn_create_name  = "vkAllocateCommandBuffers"_literal;
    static constexpr auto pfn_destroy_name = "vkFreeCommandBuffers"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
/*template<>
struct handle_traits<device_memory_handle>
{
    using handle          = device_memory_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = ""_literal;
};*/
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<command_pool_handle>
{
    using handle          = command_pool_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkCommandPoolCreateInfo;
    using pfn_create      = PFN_vkCreateCommandPool;
    using pfn_destroy     = PFN_vkDestroyCommandPool;

    static constexpr auto pfn_create_name  = "vkCreateCommandPool"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyCommandPool"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<buffer_handle>
{
    using handle          = buffer_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkBufferCreateInfo;
    using pfn_create      = PFN_vkCreateBuffer;
    using pfn_destroy     = PFN_vkDestroyBuffer;

    static constexpr auto pfn_create_name  = "vkCreateBuffer"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyBuffer"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<buffer_view_handle>
{
    using handle          = buffer_view_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkBufferViewCreateInfo;
    using pfn_create      = PFN_vkCreateBufferView;
    using pfn_destroy     = PFN_vkDestroyBufferView;

    static constexpr auto pfn_create_name  = "vkCreateBufferView"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyBufferView"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<image_handle>
{
    using handle          = image_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkImageCreateInfo;
    using pfn_create      = PFN_vkCreateImage;
    using pfn_destroy     = PFN_vkDestroyImage;

    static constexpr auto pfn_create_name  = "vkCreateImage"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyImage"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<image_view_handle>
{
    using handle          = image_view_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkImageViewCreateInfo;
    using pfn_create      = PFN_vkCreateImageView;
    using pfn_destroy     = PFN_vkDestroyImageView;

    static constexpr auto pfn_create_name  = "vkCreateImageView"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyImageView"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<shader_module_handle>
{
    using handle          = shader_module_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkShaderModuleCreateInfo;
    using pfn_create      = PFN_vkCreateShaderModule;
    using pfn_destroy     = PFN_vkDestroyShaderModule;

    static constexpr auto pfn_create_name  = "vkCreateShaderModule"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyShaderModule"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
/*template<>
struct handle_traits<pipeline_handle>
{
    using handle          = pipeline_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_vkDestroyPipeline;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipeline"_literal;
};*/
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<pipeline_layout_handle>
{
    using handle          = pipeline_layout_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkPipelineLayoutCreateInfo;
    using pfn_create      = PFN_vkCreatePipelineLayout;
    using pfn_destroy     = PFN_vkDestroyPipelineLayout;

    static constexpr auto pfn_create_name  = "vkCreatePipelineLayout"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipelineLayout"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<sampler_handle>
{
    using handle          = sampler_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkSamplerCreateInfo;
    using pfn_create      = PFN_vkCreateSampler;
    using pfn_destroy     = PFN_vkDestroySampler;

    static constexpr auto pfn_create_name  = "vkCreateSampler"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroySampler"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<descriptor_set_handle>
{
    using handle          = descriptor_set_handle;
    using parent          = descriptor_pool_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDescriptorSetAllocateInfo;
    using pfn_create      = PFN_vkAllocateDescriptorSets;
    using pfn_destroy     = PFN_vkFreeDescriptorSets;

    static constexpr auto pfn_create_name  = "vkAllocateDescriptorSets"_literal;
    static constexpr auto pfn_destroy_name = "vkFreeDescriptorSets"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<descriptor_set_layout_handle>
{
    using handle          = descriptor_set_layout_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDescriptorSetLayoutCreateInfo;
    using pfn_create      = PFN_vkCreateDescriptorSetLayout;
    using pfn_destroy     = PFN_vkDestroyDescriptorSetLayout;

    static constexpr auto pfn_create_name  = "vkCreateDescriptorSetLayout"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyDescriptorSetLayout"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<descriptor_pool_handle>
{
    using handle          = descriptor_pool_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDescriptorPoolCreateInfo;
    using pfn_create      = PFN_vkCreateDescriptorPool;
    using pfn_destroy     = PFN_vkDestroyDescriptorPool;

    static constexpr auto pfn_create_name  = "vkCreateDescriptorPool"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyDescriptorPool"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<fence_handle>
{
    using handle          = fence_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkFenceCreateInfo;
    using pfn_create      = PFN_vkCreateFence;
    using pfn_destroy     = PFN_vkDestroyFence;

    static constexpr auto pfn_create_name  = "vkCreateFence"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyFence"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<semaphore_handle>
{
    using handle          = semaphore_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkSemaphoreCreateInfo;
    using pfn_create      = PFN_vkCreateSemaphore;
    using pfn_destroy     = PFN_vkDestroySemaphore;

    static constexpr auto pfn_create_name  = "vkCreateSemaphore"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroySemaphore"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<event_handle>
{
    using handle          = event_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkEventCreateInfo;
    using pfn_create      = PFN_vkCreateEvent;
    using pfn_destroy     = PFN_vkDestroyEvent;

    static constexpr auto pfn_create_name  = "vkCreateEvent"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyEvent"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<query_pool_handle>
{
    using handle          = query_pool_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkQueryPoolCreateInfo;
    using pfn_create      = PFN_vkCreateQueryPool;
    using pfn_destroy     = PFN_vkDestroyQueryPool;

    static constexpr auto pfn_create_name  = "vkCreateQueryPool"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyQueryPool"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<framebuffer_handle>
{
    using handle          = framebuffer_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkFramebufferCreateInfo;
    using pfn_create      = PFN_vkCreateFramebuffer;
    using pfn_destroy     = PFN_vkDestroyFramebuffer;

    static constexpr auto pfn_create_name  = "vkCreateFramebuffer"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyFramebuffer"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<render_pass_handle>
{
    using handle          = render_pass_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkRenderPassCreateInfo;
    using pfn_create      = PFN_vkCreateRenderPass;
    using pfn_destroy     = PFN_vkDestroyRenderPass;

    static constexpr auto pfn_create_name  = "vkCreateRenderPass"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyRenderPass"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<pipeline_cache_handle>
{
    using handle          = pipeline_cache_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkPipelineCacheCreateInfo;
    using pfn_create      = PFN_vkCreatePipelineCache;
    using pfn_destroy     = PFN_vkDestroyPipelineCache;

    static constexpr auto pfn_create_name  = "vkCreatePipelineCache"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipelineCache"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_KHR_pipeline_binary)
/*template<>
struct handle_traits<pipeline_binary_khr_handle>
{
    using handle          = pipeline_binary_khr_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkPipelineBinaryCreateInfoKHR;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_vkDestroyPipelineBinaryKHR;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipelineBinaryKHR"_literal;
};*/
#endif // #if defined(VK_KHR_pipeline_binary)

#if defined(VK_NV_device_generated_commands)
template<>
struct handle_traits<indirect_commands_layout_nv_handle>
{
    using handle          = indirect_commands_layout_nv_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkIndirectCommandsLayoutCreateInfoNV;
    using pfn_create      = PFN_vkCreateIndirectCommandsLayoutNV;
    using pfn_destroy     = PFN_vkDestroyIndirectCommandsLayoutNV;

    static constexpr auto pfn_create_name  = "vkCreateIndirectCommandsLayoutNV"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyIndirectCommandsLayoutNV"_literal;
};
#endif // #if defined(VK_NV_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct handle_traits<indirect_commands_layout_ext_handle>
{
    using handle          = indirect_commands_layout_ext_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkIndirectCommandsLayoutCreateInfoEXT;
    using pfn_create      = PFN_vkCreateIndirectCommandsLayoutEXT;
    using pfn_destroy     = PFN_vkDestroyIndirectCommandsLayoutEXT;

    static constexpr auto pfn_create_name  = "vkCreateIndirectCommandsLayoutEXT"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyIndirectCommandsLayoutEXT"_literal;
};
#endif // #if defined(VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
template<>
struct handle_traits<indirect_execution_set_ext_handle>
{
    using handle          = indirect_execution_set_ext_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkIndirectExecutionSetCreateInfoEXT;
    using pfn_create      = PFN_vkCreateIndirectExecutionSetEXT;
    using pfn_destroy     = PFN_vkDestroyIndirectExecutionSetEXT;

    static constexpr auto pfn_create_name  = "vkCreateIndirectExecutionSetEXT"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyIndirectExecutionSetEXT"_literal;
};
#endif // #if defined(VK_EXT_device_generated_commands)

#if defined(VK_VERSION_1_1)
template<>
struct handle_traits<descriptor_update_template_handle>
{
    using handle          = descriptor_update_template_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDescriptorUpdateTemplateCreateInfo;
    using pfn_create      = PFN_vkCreateDescriptorUpdateTemplate;
    using pfn_destroy     = PFN_vkDestroyDescriptorUpdateTemplate;

    static constexpr auto pfn_create_name  = "vkCreateDescriptorUpdateTemplate"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyDescriptorUpdateTemplate"_literal;
};
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_1)
template<>
struct handle_traits<sampler_ycbcr_conversion_handle>
{
    using handle          = sampler_ycbcr_conversion_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkSamplerYcbcrConversionCreateInfo;
    using pfn_create      = PFN_vkCreateSamplerYcbcrConversion;
    using pfn_destroy     = PFN_vkDestroySamplerYcbcrConversion;

    static constexpr auto pfn_create_name  = "vkCreateSamplerYcbcrConversion"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroySamplerYcbcrConversion"_literal;
};
#endif // #if defined(VK_VERSION_1_1)

#if defined(VK_EXT_validation_cache)
template<>
struct handle_traits<validation_cache_ext_handle>
{
    using handle          = validation_cache_ext_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkValidationCacheCreateInfoEXT;
    using pfn_create      = PFN_vkCreateValidationCacheEXT;
    using pfn_destroy     = PFN_vkDestroyValidationCacheEXT;

    static constexpr auto pfn_create_name  = "vkCreateValidationCacheEXT"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyValidationCacheEXT"_literal;
};
#endif // #if defined(VK_EXT_validation_cache)

#if defined(VK_KHR_acceleration_structure)
template<>
struct handle_traits<acceleration_structure_khr_handle>
{
    using handle          = acceleration_structure_khr_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkAccelerationStructureCreateInfoKHR;
    using pfn_create      = PFN_vkCreateAccelerationStructureKHR;
    using pfn_destroy     = PFN_vkDestroyAccelerationStructureKHR;

    static constexpr auto pfn_create_name  = "vkCreateAccelerationStructureKHR"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyAccelerationStructureKHR"_literal;
};
#endif // #if defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
template<>
struct handle_traits<acceleration_structure_nv_handle>
{
    using handle          = acceleration_structure_nv_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkAccelerationStructureCreateInfoNV;
    using pfn_create      = PFN_vkCreateAccelerationStructureNV;
    using pfn_destroy     = PFN_vkDestroyAccelerationStructureNV;

    static constexpr auto pfn_create_name  = "vkCreateAccelerationStructureNV"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyAccelerationStructureNV"_literal;
};
#endif // #if defined(VK_NV_ray_tracing)

#if defined(VK_INTEL_performance_query)
/*template<>
struct handle_traits<performance_configuration_intel_handle>
{
    using handle          = performance_configuration_intel_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = ""_literal;
};*/
#endif // #if defined(VK_INTEL_performance_query)

#if defined(VK_FUCHSIA_buffer_collection)
template<>
struct handle_traits<buffer_collection_fuchsia_handle>
{
    using handle          = buffer_collection_fuchsia_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkBufferCollectionCreateInfoFUCHSIA;
    using pfn_create      = PFN_vkCreateBufferCollectionFUCHSIA;
    using pfn_destroy     = PFN_vkDestroyBufferCollectionFUCHSIA;

    static constexpr auto pfn_create_name  = "vkCreateBufferCollectionFUCHSIA"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyBufferCollectionFUCHSIA"_literal;
};
#endif // #if defined(VK_FUCHSIA_buffer_collection)

#if defined(VK_KHR_deferred_host_operations)
/*template<>
struct handle_traits<deferred_operation_khr_handle>
{
    using handle          = deferred_operation_khr_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_vkCreateDeferredOperationKHR;
    using pfn_destroy     = PFN_vkDestroyDeferredOperationKHR;

    static constexpr auto pfn_create_name  = "vkCreateDeferredOperationKHR"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyDeferredOperationKHR"_literal;
};*/
#endif // #if defined(VK_KHR_deferred_host_operations)

#if defined(VK_VERSION_1_3)
template<>
struct handle_traits<private_data_slot_handle>
{
    using handle          = private_data_slot_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkPrivateDataSlotCreateInfo;
    using pfn_create      = PFN_vkCreatePrivateDataSlot;
    using pfn_destroy     = PFN_vkDestroyPrivateDataSlot;

    static constexpr auto pfn_create_name  = "vkCreatePrivateDataSlot"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPrivateDataSlot"_literal;
};
#endif // #if defined(VK_VERSION_1_3)

#if defined(VK_NVX_binary_import)
template<>
struct handle_traits<cu_module_nvx_handle>
{
    using handle          = cu_module_nvx_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkCuModuleCreateInfoNVX;
    using pfn_create      = PFN_vkCreateCuModuleNVX;
    using pfn_destroy     = PFN_vkDestroyCuModuleNVX;

    static constexpr auto pfn_create_name  = "vkCreateCuModuleNVX"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyCuModuleNVX"_literal;
};
#endif // #if defined(VK_NVX_binary_import)

#if defined(VK_NVX_binary_import)
template<>
struct handle_traits<cu_function_nvx_handle>
{
    using handle          = cu_function_nvx_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkCuFunctionCreateInfoNVX;
    using pfn_create      = PFN_vkCreateCuFunctionNVX;
    using pfn_destroy     = PFN_vkDestroyCuFunctionNVX;

    static constexpr auto pfn_create_name  = "vkCreateCuFunctionNVX"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyCuFunctionNVX"_literal;
};
#endif // #if defined(VK_NVX_binary_import)

#if defined(VK_NV_optical_flow)
template<>
struct handle_traits<optical_flow_session_nv_handle>
{
    using handle          = optical_flow_session_nv_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkOpticalFlowSessionCreateInfoNV;
    using pfn_create      = PFN_vkCreateOpticalFlowSessionNV;
    using pfn_destroy     = PFN_vkDestroyOpticalFlowSessionNV;

    static constexpr auto pfn_create_name  = "vkCreateOpticalFlowSessionNV"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyOpticalFlowSessionNV"_literal;
};
#endif // #if defined(VK_NV_optical_flow)

#if defined(VK_EXT_opacity_micromap)
template<>
struct handle_traits<micromap_ext_handle>
{
    using handle          = micromap_ext_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkMicromapCreateInfoEXT;
    using pfn_create      = PFN_vkCreateMicromapEXT;
    using pfn_destroy     = PFN_vkDestroyMicromapEXT;

    static constexpr auto pfn_create_name  = "vkCreateMicromapEXT"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyMicromapEXT"_literal;
};
#endif // #if defined(VK_EXT_opacity_micromap)

#if defined(VK_EXT_shader_object)
template<>
struct handle_traits<shader_ext_handle>
{
    using handle          = shader_ext_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkShaderCreateInfoEXT;
    using pfn_create      = PFN_vkCreateShadersEXT;
    using pfn_destroy     = PFN_vkDestroyShaderEXT;

    static constexpr auto pfn_create_name  = "vkCreateShadersEXT"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyShaderEXT"_literal;
};
#endif // #if defined(VK_EXT_shader_object)

#if defined(VK_KHR_display)
/*template<>
struct handle_traits<display_khr_handle>
{
    using handle          = display_khr_handle;
    using parent          = physical_device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = ""_literal;
};*/
#endif // #if defined(VK_KHR_display)

#if defined(VK_KHR_display)
/*template<>
struct handle_traits<display_mode_khr_handle>
{
    using handle          = display_mode_khr_handle;
    using parent          = display_khr_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDisplayModeCreateInfoKHR;
    using pfn_create      = PFN_vkCreateDisplayModeKHR;
    using pfn_destroy     = PFN_;

    static constexpr auto pfn_create_name  = "vkCreateDisplayModeKHR"_literal;
    static constexpr auto pfn_destroy_name = ""_literal;
};*/
#endif // #if defined(VK_KHR_display)

#if defined(VK_KHR_surface)
/*template<>
struct handle_traits<surface_khr_handle>
{
    using handle          = surface_khr_handle;
    using parent          = instance_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = ;
    using pfn_create      = PFN_;
    using pfn_destroy     = PFN_vkDestroySurfaceKHR;

    static constexpr auto pfn_create_name  = ""_literal;
    static constexpr auto pfn_destroy_name = "vkDestroySurfaceKHR"_literal;
};*/
#endif // #if defined(VK_KHR_surface)

#if defined(VK_KHR_swapchain)
template<>
struct handle_traits<swapchain_khr_handle>
{
    using handle          = swapchain_khr_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkSwapchainCreateInfoKHR;
    using pfn_create      = PFN_vkCreateSwapchainKHR;
    using pfn_destroy     = PFN_vkDestroySwapchainKHR;

    static constexpr auto pfn_create_name  = "vkCreateSwapchainKHR"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroySwapchainKHR"_literal;
};
#endif // #if defined(VK_KHR_swapchain)

#if defined(VK_EXT_debug_report)
template<>
struct handle_traits<debug_report_callback_ext_handle>
{
    using handle          = debug_report_callback_ext_handle;
    using parent          = instance_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDebugReportCallbackCreateInfoEXT;
    using pfn_create      = PFN_vkCreateDebugReportCallbackEXT;
    using pfn_destroy     = PFN_vkDestroyDebugReportCallbackEXT;

    static constexpr auto pfn_create_name  = "vkCreateDebugReportCallbackEXT"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyDebugReportCallbackEXT"_literal;
};
#endif // #if defined(VK_EXT_debug_report)

#if defined(VK_EXT_debug_utils)
template<>
struct handle_traits<debug_utils_messenger_ext_handle>
{
    using handle          = debug_utils_messenger_ext_handle;
    using parent          = instance_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkDebugUtilsMessengerCreateInfoEXT;
    using pfn_create      = PFN_vkCreateDebugUtilsMessengerEXT;
    using pfn_destroy     = PFN_vkDestroyDebugUtilsMessengerEXT;

    static constexpr auto pfn_create_name  = "vkCreateDebugUtilsMessengerEXT"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyDebugUtilsMessengerEXT"_literal;
};
#endif // #if defined(VK_EXT_debug_utils)

#if defined(VK_KHR_video_queue)
template<>
struct handle_traits<video_session_khr_handle>
{
    using handle          = video_session_khr_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkVideoSessionCreateInfoKHR;
    using pfn_create      = PFN_vkCreateVideoSessionKHR;
    using pfn_destroy     = PFN_vkDestroyVideoSessionKHR;

    static constexpr auto pfn_create_name  = "vkCreateVideoSessionKHR"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyVideoSessionKHR"_literal;
};
#endif // #if defined(VK_KHR_video_queue)

#if defined(VK_KHR_video_queue)
template<>
struct handle_traits<video_session_parameters_khr_handle>
{
    using handle          = video_session_parameters_khr_handle;
    using parent          = video_session_khr_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkVideoSessionParametersCreateInfoKHR;
    using pfn_create      = PFN_vkCreateVideoSessionParametersKHR;
    using pfn_destroy     = PFN_vkDestroyVideoSessionParametersKHR;

    static constexpr auto pfn_create_name  = "vkCreateVideoSessionParametersKHR"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyVideoSessionParametersKHR"_literal;
};
#endif // #if defined(VK_KHR_video_queue)

#if defined(VK_NV_external_sci_sync2)
template<>
struct handle_traits<semaphore_sci_sync_pool_nv_handle>
{
    using handle          = semaphore_sci_sync_pool_nv_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkSemaphoreSciSyncPoolCreateInfoNV;
    using pfn_create      = PFN_vkCreateSemaphoreSciSyncPoolNV;
    using pfn_destroy     = PFN_vkDestroySemaphoreSciSyncPoolNV;

    static constexpr auto pfn_create_name  = "vkCreateSemaphoreSciSyncPoolNV"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroySemaphoreSciSyncPoolNV"_literal;
};
#endif // #if defined(VK_NV_external_sci_sync2)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct handle_traits<cuda_module_nv_handle>
{
    using handle          = cuda_module_nv_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkCudaModuleCreateInfoNV;
    using pfn_create      = PFN_vkCreateCudaModuleNV;
    using pfn_destroy     = PFN_vkDestroyCudaModuleNV;

    static constexpr auto pfn_create_name  = "vkCreateCudaModuleNV"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyCudaModuleNV"_literal;
};
#endif // #if defined(VK_NV_cuda_kernel_launch)

#if defined(VK_NV_cuda_kernel_launch)
template<>
struct handle_traits<cuda_function_nv_handle>
{
    using handle          = cuda_function_nv_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkCudaFunctionCreateInfoNV;
    using pfn_create      = PFN_vkCreateCudaFunctionNV;
    using pfn_destroy     = PFN_vkDestroyCudaFunctionNV;

    static constexpr auto pfn_create_name  = "vkCreateCudaFunctionNV"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyCudaFunctionNV"_literal;
};
#endif // #if defined(VK_NV_cuda_kernel_launch)

//------------------------------------------------------------------------------
// Manual traits

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<device_memory_handle>
{
    using handle          = device_memory_handle;
    using parent          = device_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkMemoryAllocateInfo;
    using pfn_create      = PFN_vkAllocateMemory;
    using pfn_destroy     = PFN_vkFreeMemory;

    static constexpr auto pfn_create_name  = "vkAllocateMemory"_literal;
    static constexpr auto pfn_destroy_name = "vkFreeMemory"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<graphics_pipeline_handle>
{
    using parent          = device_handle;
    using handle          = graphics_pipeline_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkGraphicsPipelineCreateInfo;
    using pfn_create      = PFN_vkCreateGraphicsPipelines;
    using pfn_destroy     = PFN_vkDestroyPipeline;

    static constexpr auto pfn_create_name  = "vkCreateGraphicsPipelines"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipeline"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_0)
template<>
struct handle_traits<compute_pipeline_handle>
{
    using parent          = device_handle;
    using handle          = compute_pipeline_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkComputePipelineCreateInfo;
    using pfn_create      = PFN_vkCreateComputePipelines;
    using pfn_destroy     = PFN_vkDestroyPipeline;

    static constexpr auto pfn_create_name  = "vkCreateComputePipelines"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipeline"_literal;
};
#endif // #if defined(VK_VERSION_1_0)

#if defined(VK_KHR_ray_tracing_pipeline)
template<>
struct handle_traits<ray_tracing_pipeline_khr_handle>
{
    using parent          = device_handle;
    using handle          = ray_tracing_pipeline_khr_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkRayTracingPipelineCreateInfoKHR;
    using pfn_create      = PFN_vkCreateRayTracingPipelinesKHR;
    using pfn_destroy     = PFN_vkDestroyPipeline;

    static constexpr auto pfn_create_name  = "vkCreateRayTracingPipelinesKHR"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipeline"_literal;
};

#endif // #if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
template<>
struct handle_traits<ray_tracing_pipeline_nv_handle>
{
    using parent          = device_handle;
    using handle          = ray_tracing_pipeline_nv_handle;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = VkRayTracingPipelineCreateInfoNV;
    using pfn_create      = PFN_vkCreateRayTracingPipelinesNV;
    using pfn_destroy     = PFN_vkDestroyPipeline;

    static constexpr auto pfn_create_name  = "vkCreateRayTracingPipelinesNV"_literal;
    static constexpr auto pfn_destroy_name = "vkDestroyPipeline"_literal;
};
#endif // #if defined(VK_NV_ray_tracing)

} // namespace fubuki::detail

#endif // FUBUKI_CORE_DETAIL_HANDLE_TRAITS_HPP
