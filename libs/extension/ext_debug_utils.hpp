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

#ifndef FUBUKI_EXTENSION_EXT_DEBUG_UTILS_HPP
#define FUBUKI_EXTENSION_EXT_DEBUG_UTILS_HPP

#include <concepts>
#include <cstdint>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_debug_utils.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_debug_utils
{

#if defined(VK_EXT_debug_utils)

/// Creates a messenger for an instance.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<debug_utils_messenger_ext_handle, api_call_info>
                                   create(const functions& ext, instance_handle instance, const VkDebugUtilsMessengerCreateInfoEXT& info) noexcept;

/// Creates a messenger for an instance.
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<debug_utils_messenger_ext_handle, api_call_info> create(
    const functions& ext, instance_handle instance, const VkDebugUtilsMessengerCreateInfoEXT& info, const VkAllocationCallbacks& callbacks) noexcept;

/// Destroys a messenger for an instance.
FUBUKI_EXTENSION_API
void destroy(const functions& ext, instance_handle instance, debug_utils_messenger_ext_handle& messenger) noexcept;

/// Destroys a messenger for an instance.
FUBUKI_EXTENSION_API
void destroy(const functions&                  ext,
             instance_handle                   instance,
             debug_utils_messenger_ext_handle& messenger,
             const VkAllocationCallbacks&      callbacks) noexcept;

#endif // defined(VK_EXT_debug_utils)

namespace cmd
{

#if defined(VK_EXT_debug_utils)

/// Starts a debugging label for a command buffer.
FUBUKI_EXTENSION_API
void begin_label(const functions& ext, command_buffer_handle command_buffer, const VkDebugUtilsLabelEXT& info) noexcept;

/// Ends a debugging label for a command buffer.
FUBUKI_EXTENSION_API
void end_label(const functions& ext, command_buffer_handle command_buffer) noexcept;

/// Inserts a debugging label for a command buffer.
FUBUKI_EXTENSION_API
void insert_label(const functions& ext, command_buffer_handle command_buffer, const VkDebugUtilsLabelEXT& info) noexcept;

/**
 * A RAII object to label a scope for a command buffer.
 * Equivalent to a call to begin_label() when the object is created, and to end_label() at the scope exit.
 */
class scoped_label
{
public:

    scoped_label(const functions& ext, command_buffer_handle command_buffer, const VkDebugUtilsLabelEXT& info) noexcept
        : m_ext{ext},
          m_command_buffer{command_buffer}
    {
        begin_label(m_ext, m_command_buffer, info);
    }

    ~scoped_label() noexcept { end_label(m_ext, m_command_buffer); }

    scoped_label(const scoped_label&) noexcept            = delete;
    scoped_label(scoped_label&&) noexcept                 = delete;
    scoped_label& operator=(const scoped_label&) noexcept = delete;
    scoped_label& operator=(scoped_label&&) noexcept      = delete;

private:
    std::reference_wrapper<const functions> m_ext;
    command_buffer_handle                   m_command_buffer;
};

#endif // defined(VK_EXT_debug_utils)

} // namespace cmd

namespace queue
{

#if defined(VK_EXT_debug_utils)

/// Starts a queue label.
FUBUKI_EXTENSION_API
void begin_label(const functions& ext, queue_handle queue, const VkDebugUtilsLabelEXT& info) noexcept;

/// Ends a queue label.
FUBUKI_EXTENSION_API
void end_label(const functions& ext, queue_handle queue) noexcept;

/// Inserts a queue label.
FUBUKI_EXTENSION_API
void insert_label(const functions& ext, queue_handle queue, const VkDebugUtilsLabelEXT& info) noexcept;

/**
 * A RAII object to label a scope for a queue.
 * Equivalent to a call to begin_label() when the object is created, and to end_label() at the scope exit.
 */
class scoped_label
{
public:

    scoped_label(const functions& ext, queue_handle queue, const VkDebugUtilsLabelEXT& info) noexcept : m_ext{ext}, m_queue{queue}
    {
        begin_label(m_ext, m_queue, info);
    }

    ~scoped_label() noexcept { end_label(m_ext, m_queue); }

    scoped_label(const scoped_label&) noexcept            = delete;
    scoped_label(scoped_label&&) noexcept                 = delete;
    scoped_label& operator=(const scoped_label&) noexcept = delete;
    scoped_label& operator=(scoped_label&&) noexcept      = delete;

private:
    std::reference_wrapper<const functions> m_ext;
    queue_handle                            m_queue;
};

#endif // defined(VK_EXT_debug_utils)

} // namespace queue

namespace object
{

namespace detail
{

template<typename handle_type>
struct traits;

template<typename handle_type>
struct traits
{
    static constexpr VkObjectType type = VK_OBJECT_TYPE_UNKNOWN; // Invalid generic specialisation to trigger a compile error
};

#if defined(FUBUKI_MAKE_OBJECT_TRAITS)
    // This macro is #undef'd below
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_OBJECT_TRAITS(handle_type, object_type) \
    template<>                                              \
    struct traits<handle_type>                              \
    {                                                       \
        static constexpr VkObjectType type = object_type;   \
    }

FUBUKI_MAKE_OBJECT_TRAITS(instance_handle, VK_OBJECT_TYPE_INSTANCE);
FUBUKI_MAKE_OBJECT_TRAITS(physical_device_handle, VK_OBJECT_TYPE_PHYSICAL_DEVICE);
FUBUKI_MAKE_OBJECT_TRAITS(device_handle, VK_OBJECT_TYPE_DEVICE);
FUBUKI_MAKE_OBJECT_TRAITS(queue_handle, VK_OBJECT_TYPE_QUEUE);
FUBUKI_MAKE_OBJECT_TRAITS(semaphore_handle, VK_OBJECT_TYPE_SEMAPHORE);
FUBUKI_MAKE_OBJECT_TRAITS(command_buffer_handle, VK_OBJECT_TYPE_COMMAND_BUFFER);
FUBUKI_MAKE_OBJECT_TRAITS(fence_handle, VK_OBJECT_TYPE_FENCE);
FUBUKI_MAKE_OBJECT_TRAITS(device_memory_handle, VK_OBJECT_TYPE_DEVICE_MEMORY);
FUBUKI_MAKE_OBJECT_TRAITS(buffer_handle, VK_OBJECT_TYPE_BUFFER);
FUBUKI_MAKE_OBJECT_TRAITS(image_handle, VK_OBJECT_TYPE_IMAGE);
FUBUKI_MAKE_OBJECT_TRAITS(event_handle, VK_OBJECT_TYPE_EVENT);
FUBUKI_MAKE_OBJECT_TRAITS(query_pool_handle, VK_OBJECT_TYPE_QUERY_POOL);
FUBUKI_MAKE_OBJECT_TRAITS(buffer_view_handle, VK_OBJECT_TYPE_BUFFER_VIEW);
FUBUKI_MAKE_OBJECT_TRAITS(image_view_handle, VK_OBJECT_TYPE_IMAGE_VIEW);
FUBUKI_MAKE_OBJECT_TRAITS(shader_module_handle, VK_OBJECT_TYPE_SHADER_MODULE);
FUBUKI_MAKE_OBJECT_TRAITS(pipeline_cache_handle, VK_OBJECT_TYPE_PIPELINE_CACHE);
FUBUKI_MAKE_OBJECT_TRAITS(pipeline_layout_handle, VK_OBJECT_TYPE_PIPELINE_LAYOUT);
FUBUKI_MAKE_OBJECT_TRAITS(render_pass_handle, VK_OBJECT_TYPE_RENDER_PASS);
FUBUKI_MAKE_OBJECT_TRAITS(pipeline_handle, VK_OBJECT_TYPE_PIPELINE);
FUBUKI_MAKE_OBJECT_TRAITS(descriptor_set_layout_handle, VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT);
FUBUKI_MAKE_OBJECT_TRAITS(sampler_handle, VK_OBJECT_TYPE_SAMPLER);
FUBUKI_MAKE_OBJECT_TRAITS(descriptor_pool_handle, VK_OBJECT_TYPE_DESCRIPTOR_POOL);
FUBUKI_MAKE_OBJECT_TRAITS(descriptor_set_handle, VK_OBJECT_TYPE_DESCRIPTOR_SET);
FUBUKI_MAKE_OBJECT_TRAITS(framebuffer_handle, VK_OBJECT_TYPE_FRAMEBUFFER);
FUBUKI_MAKE_OBJECT_TRAITS(command_pool_handle, VK_OBJECT_TYPE_COMMAND_POOL);

FUBUKI_MAKE_OBJECT_TRAITS(graphics_pipeline_handle, VK_OBJECT_TYPE_PIPELINE);
FUBUKI_MAKE_OBJECT_TRAITS(compute_pipeline_handle, VK_OBJECT_TYPE_PIPELINE);

#if defined(VK_KHR_ray_tracing_pipeline)
FUBUKI_MAKE_OBJECT_TRAITS(ray_tracing_pipeline_khr_handle, VK_OBJECT_TYPE_PIPELINE);
#endif // #if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
FUBUKI_MAKE_OBJECT_TRAITS(ray_tracing_pipeline_nv_handle, VK_OBJECT_TYPE_PIPELINE);
#endif // #if defined(VK_NV_ray_tracing)

#if defined(VK_KHR_surface)
FUBUKI_MAKE_OBJECT_TRAITS(surface_khr_handle, VK_OBJECT_TYPE_SURFACE_KHR);
#endif
FUBUKI_MAKE_OBJECT_TRAITS(swapchain_khr_handle, VK_OBJECT_TYPE_SWAPCHAIN_KHR);

#if defined(VK_KHR_swapchain)
FUBUKI_MAKE_OBJECT_TRAITS(debug_report_callback_ext_handle, VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT);
#endif

#if defined(VK_KHR_display)
FUBUKI_MAKE_OBJECT_TRAITS(display_khr_handle, VK_OBJECT_TYPE_DISPLAY_KHR);
FUBUKI_MAKE_OBJECT_TRAITS(display_mode_khr_handle, VK_OBJECT_TYPE_DISPLAY_MODE_KHR);
#endif

#if defined(VK_EXT_validation_cache)
FUBUKI_MAKE_OBJECT_TRAITS(validation_cache_ext_handle, VK_OBJECT_TYPE_VALIDATION_CACHE_EXT);
#endif

#if defined(VK_VERSION_1_1)
FUBUKI_MAKE_OBJECT_TRAITS(sampler_ycbcr_conversion_handle, VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION);
FUBUKI_MAKE_OBJECT_TRAITS(descriptor_update_template_handle, VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE);
#endif

#if defined(VK_EXT_debug_utils)
FUBUKI_MAKE_OBJECT_TRAITS(debug_utils_messenger_ext_handle, VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT);
#endif

#if defined(VK_NVX_binary_import)
FUBUKI_MAKE_OBJECT_TRAITS(cu_module_nvx_handle, VK_OBJECT_TYPE_CU_MODULE_NVX);
FUBUKI_MAKE_OBJECT_TRAITS(cu_function_nvx_handle, VK_OBJECT_TYPE_CU_FUNCTION_NVX);
#endif

#if defined(VK_NV_ray_tracing)
FUBUKI_MAKE_OBJECT_TRAITS(acceleration_structure_nv_handle, VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV);
#endif

#if defined(VK_KHR_acceleration_structure)
FUBUKI_MAKE_OBJECT_TRAITS(acceleration_structure_khr_handle, VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR);
#endif

#if defined(VK_INTEL_performance_query)
FUBUKI_MAKE_OBJECT_TRAITS(performance_configuration_intel_handle, VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL);
#endif

#if defined(VK_KHR_deferred_host_operations)
FUBUKI_MAKE_OBJECT_TRAITS(deferred_operation_khr_handle, VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR);
#endif

#if defined(VK_NV_device_generated_commands)
FUBUKI_MAKE_OBJECT_TRAITS(indirect_commands_layout_nv_handle, VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV);
#endif

#if defined(VK_EXT_opacity_micromap)
FUBUKI_MAKE_OBJECT_TRAITS(micromap_ext_handle, VK_OBJECT_TYPE_MICROMAP_EXT);
#endif

#if defined(VK_NV_optical_flow)
FUBUKI_MAKE_OBJECT_TRAITS(optical_flow_session_nv_handle, VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV);
#endif

#if defined(VK_EXT_shader_object)
FUBUKI_MAKE_OBJECT_TRAITS(shader_ext_handle, VK_OBJECT_TYPE_SHADER_EXT);
#endif

#if defined(VK_VERSION_1_3)
FUBUKI_MAKE_OBJECT_TRAITS(private_data_slot_handle, VK_OBJECT_TYPE_PRIVATE_DATA_SLOT);
#endif

#if defined(VK_KHR_pipeline_binary)
FUBUKI_MAKE_OBJECT_TRAITS(pipeline_binary_khr_handle, VK_OBJECT_TYPE_PIPELINE_BINARY_KHR);
#endif // #if defined (VK_KHR_pipeline_binary)

#if defined(VK_EXT_device_generated_commands)
FUBUKI_MAKE_OBJECT_TRAITS(indirect_commands_layout_ext_handle, VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT);
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_EXT_device_generated_commands)
FUBUKI_MAKE_OBJECT_TRAITS(indirect_execution_set_ext_handle, VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT); // indirect_execution_set_ext_handle
#endif // #if defined (VK_EXT_device_generated_commands)

#if defined(VK_NV_cuda_kernel_launch)
FUBUKI_MAKE_OBJECT_TRAITS(cuda_module_nv_handle, VK_OBJECT_TYPE_CUDA_MODULE_NV);     // cuda_module_nv_handle
FUBUKI_MAKE_OBJECT_TRAITS(cuda_function_nv_handle, VK_OBJECT_TYPE_CUDA_FUNCTION_NV); // cuda_function_nv_handle
#endif                                                                               // #if defined (VK_NV_cuda_kernel_launch)

template<typename handle_type>
inline constexpr auto type_v = traits<handle_type>::type;

template<typename handle_type>
concept nameable_handle = traits<handle_type>::type != VK_OBJECT_TYPE_UNKNOWN;

#undef FUBUKI_MAKE_OBJECT_TRAITS

} // namespace detail

#if defined(VK_EXT_debug_utils)

/// Sets a handle name.
FUBUKI_EXTENSION_API
std::expected<void, api_call_info>
set_name(const functions& ext, device_handle device, std::uint64_t handle, VkObjectType type, const char* object_name) noexcept;

/// Sets a handle tag.
FUBUKI_EXTENSION_API
std::expected<void, api_call_info>
set_tag(const functions& ext, device_handle device, std::uint64_t handle, VkObjectType type, const VkDebugUtilsObjectTagInfoEXT& info) noexcept;

/// Sets a handle name.
template<detail::nameable_handle handle_type>
inline std::expected<void, api_call_info>
set_name(const functions& ext, device_handle device, handle_type handle, const char* const object_name) noexcept
{
    // clang-format off
    if(handle != null_handle)
    {
        // Windows with MSVC, platforms on which VK_DEFINE_NON_DISPATCHABLE_HANDLE uses uint64_t
        if constexpr(requires {{handle.vk} -> std::same_as<std::uint64_t&>;}) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        {
            return set_name(ext, device, handle.vk, detail::type_v<handle_type>, object_name);
        }
        // Linux, Windows with MinGW, platforms on which VK_DEFINE_NON_DISPATCHABLE_HANDLE uses opaque structure pointers
        else if constexpr(requires {{reinterpret_cast<std::uint64_t>(handle.vk)};}) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        {
            return set_name(ext,
                     device,
                     reinterpret_cast<std::uint64_t>(handle.vk), // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                     detail::type_v<handle_type>,
                     object_name);
        }
    }
    // clang-format on

    return {};
}

template<detail::nameable_handle handle_type>
inline auto set_name(const functions& ext, device_handle device, handle_type handle, const std::string& object_name) noexcept
{
    return set_name(ext, device, handle, object_name.c_str());
}

/// Sets a handle tag.
template<detail::nameable_handle handle_type>
inline std::expected<void, api_call_info>
set_tag(const functions& ext, device_handle device, handle_type handle, const VkDebugUtilsObjectTagInfoEXT& info) noexcept
{
    // clang-format off
    if(handle != null_handle)
    {
        // Windows with MSVC, platforms on which VK_DEFINE_NON_DISPATCHABLE_HANDLE uses uint64_t
        if constexpr(requires {{handle.vk} -> std::same_as<std::uint64_t&>;}) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        {
            return set_tag(ext, device, handle.vk, detail::type_v<handle_type>, info);
        }
        // Linux, Windows with MinGW, platforms on which VK_DEFINE_NON_DISPATCHABLE_HANDLE uses opaque structure pointers
        else if constexpr(requires {{reinterpret_cast<std::uint64_t>(handle.vk)};}) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        {
            return set_tag(ext,
                    device,
                    reinterpret_cast<std::uint64_t>(handle.vk), // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                    detail::type_v<handle_type>,
                    info);
        }
    }
    // clang-format on

    return {};
}

#endif // defined(VK_EXT_debug_utils)

} // namespace object

#if defined(VK_EXT_debug_utils)

/// Submits a layer message.
FUBUKI_EXTENSION_API
void submit_message(const functions&                       ext,
                    instance_handle                        instance,
                    VkDebugUtilsMessageSeverityFlagBitsEXT severity,
                    VkDebugUtilsMessageTypeFlagsEXT        type) noexcept;

/// Submits a layer message.
FUBUKI_EXTENSION_API
void submit_message(const functions&                            ext,
                    instance_handle                             instance,
                    VkDebugUtilsMessageSeverityFlagBitsEXT      severity,
                    VkDebugUtilsMessageTypeFlagsEXT             type,
                    const VkDebugUtilsMessengerCallbackDataEXT& callback) noexcept;

#endif // defined(VK_EXT_debug_utils)

} // namespace fubuki::extension::ext_debug_utils

#endif // FUBUKI_EXTENSION_EXT_DEBUG_UTILS_HPP
