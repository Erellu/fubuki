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

#ifndef FUBUKI_EXTENSION_EXT_DEVICE_GENERATED_COMMANDS_HPP
#define FUBUKI_EXTENSION_EXT_DEVICE_GENERATED_COMMANDS_HPP

#include <span>

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/structure_type.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/ext_device_generated_commands.hpp" // IWYU pragma: export

namespace fubuki::extension::ext_device_generated_commands
{

#if defined(VK_EXT_device_generated_commands)

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkGeneratedCommandsMemoryRequirementsInfoEXT.html
struct commands_memory_requirements
{
    using underlying_type = VkGeneratedCommandsMemoryRequirementsInfoEXT;

    indirect_execution_set_ext_handle   execution_set      = {};
    indirect_commands_layout_ext_handle commands_layout    = {};
    std::uint32_t                       max_sequence_count = 1;
    std::uint32_t                       max_draw_count     = 1;

    [[nodiscard]] friend underlying_type to_underlying(std::reference_wrapper<const commands_memory_requirements> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                  = structure_type_v<underlying_type>,
            .pNext                  = {},
            .indirectExecutionSet   = s.execution_set.vk,
            .indirectCommandsLayout = s.commands_layout.vk,
            .maxSequenceCount       = s.max_sequence_count,
            .maxDrawCount           = s.max_draw_count,
        };
    }
};

namespace detail
{

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetGeneratedCommandsMemoryRequirementsEXT.html
FUBUKI_EXTENSION_API void get_generated_commands_memory_requirements(const functions&                                    ext,
                                                                     device_handle                                       device,
                                                                     const VkGeneratedCommandsMemoryRequirementsInfoEXT& p_info,
                                                                     VkMemoryRequirements2&                              result) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectCommandsLayoutEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<indirect_commands_layout_ext_handle, api_call_info>
                                   create_indirect_commands_layout(const functions&                             ext,
                                                                   device_handle                                device,
                                                                   const VkIndirectCommandsLayoutCreateInfoEXT& create_info,
                                                                   const VkAllocationCallbacks*                 allocator) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectCommandsLayoutEXT.html
FUBUKI_EXTENSION_API void destroy_indirect_commands_layout(const functions&                     ext,
                                                           device_handle                        device,
                                                           indirect_commands_layout_ext_handle& indirect_commands_layout,
                                                           const VkAllocationCallbacks*         allocator) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectExecutionSetEXT.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<indirect_execution_set_ext_handle, api_call_info>
                                   create_indirect_execution_set(const functions&                           ext,
                                                                 device_handle                              device,
                                                                 const VkIndirectExecutionSetCreateInfoEXT& create_info,
                                                                 const VkAllocationCallbacks*               allocator) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectExecutionSetEXT.html
FUBUKI_EXTENSION_API void destroy_indirect_execution_set(const functions&                   ext,
                                                         device_handle                      device,
                                                         indirect_execution_set_ext_handle& indirect_execution_set,
                                                         const VkAllocationCallbacks*       p_allocator) noexcept;

} // namespace detail

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetGeneratedCommandsMemoryRequirementsEXT.html
template<typename... input_pnext_elements, typename... result_pnext_elements>
inline VkMemoryRequirements2 get_generated_commands_memory_requirements(const functions&                             ext,
                                                                        device_handle                                device,
                                                                        const commands_memory_requirements&          info,
                                                                        const pnext_chain<input_pnext_elements...>&  input_pnext,
                                                                        const pnext_chain<result_pnext_elements...>& result_pnext) noexcept
{
    auto vk_commands_memory_requirements = to_underlying(info);

    VkMemoryRequirements2 result = {
        .sType              = structure_type_v<VkMemoryRequirements2>,
        .pNext              = {},
        .memoryRequirements = {},
    };

    fubuki::extend(vk_commands_memory_requirements, input_pnext);
    fubuki::extend(result, result_pnext);

    detail::get_generated_commands_memory_requirements(ext, device, vk_commands_memory_requirements, result);

    return result;
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetGeneratedCommandsMemoryRequirementsEXT.html
inline auto get_generated_commands_memory_requirements(const functions& ext, device_handle device, const commands_memory_requirements& info) noexcept
{
    return get_generated_commands_memory_requirements(ext, device, info, empty_pnext_chain, empty_pnext_chain);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectCommandsLayoutEXT.html
[[nodiscard]] inline auto create_indirect_commands_layout(const functions&                             ext,
                                                          device_handle                                device,
                                                          const VkIndirectCommandsLayoutCreateInfoEXT& create_info,
                                                          const VkAllocationCallbacks&                 allocator) noexcept
{
    return detail::create_indirect_commands_layout(ext, device, create_info, std::addressof(allocator));
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectCommandsLayoutEXT.html
[[nodiscard]] inline auto
create_indirect_commands_layout(const functions& ext, device_handle device, const VkIndirectCommandsLayoutCreateInfoEXT& create_info) noexcept
{
    return detail::create_indirect_commands_layout(ext, device, create_info, nullptr);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectCommandsLayoutEXT.html
inline void destroy_indirect_commands_layout(const functions&                     ext,
                                             device_handle                        device,
                                             indirect_commands_layout_ext_handle& indirect_commands_layout,
                                             const VkAllocationCallbacks&         allocator) noexcept
{
    return detail::destroy_indirect_commands_layout(ext, device, indirect_commands_layout, std::addressof(allocator));
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectCommandsLayoutEXT.html
inline void
destroy_indirect_commands_layout(const functions& ext, device_handle device, indirect_commands_layout_ext_handle& indirect_commands_layout) noexcept
{
    return detail::destroy_indirect_commands_layout(ext, device, indirect_commands_layout, nullptr);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectExecutionSetEXT.html
[[nodiscard]] inline auto create_indirect_execution_set(const functions&                           ext,
                                                        device_handle                              device,
                                                        const VkIndirectExecutionSetCreateInfoEXT& create_info,
                                                        const VkAllocationCallbacks&               allocator) noexcept
{
    return detail::create_indirect_execution_set(ext, device, create_info, std::addressof(allocator));
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCreateIndirectExecutionSetEXT.html
[[nodiscard]] inline auto
create_indirect_execution_set(const functions& ext, device_handle device, const VkIndirectExecutionSetCreateInfoEXT& create_info) noexcept
{
    return detail::create_indirect_execution_set(ext, device, create_info, nullptr);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectExecutionSetEXT.html
inline void destroy_indirect_execution_set(const functions&                  ext,
                                           device_handle                     device,
                                           indirect_execution_set_ext_handle indirect_execution_set,
                                           const VkAllocationCallbacks&      allocator) noexcept
{
    return detail::destroy_indirect_execution_set(ext, device, indirect_execution_set, std::addressof(allocator));
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkDestroyIndirectExecutionSetEXT.html
inline void
destroy_indirect_execution_set(const functions& ext, device_handle device, indirect_execution_set_ext_handle indirect_execution_set) noexcept
{
    return detail::destroy_indirect_execution_set(ext, device, indirect_execution_set, nullptr);
}

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateIndirectExecutionSetPipelineEXT.html
FUBUKI_EXTENSION_API void
update_indirect_execution_set_pipeline(const functions&                                        ext,
                                       device_handle                                           device,
                                       indirect_execution_set_ext_handle                       indirect_execution_set,
                                       std::span<const VkWriteIndirectExecutionSetPipelineEXT> execution_set_writes) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkUpdateIndirectExecutionSetShaderEXT.html
FUBUKI_EXTENSION_API void update_indirect_execution_set_shader(const functions&                                      ext,
                                                               device_handle                                         device,
                                                               indirect_execution_set_ext_handle                     indirect_execution_set,
                                                               std::span<const VkWriteIndirectExecutionSetShaderEXT> execution_set_writes) noexcept;

#endif // defined(VK_EXT_device_generated_commands)

namespace cmd
{

#if defined(VK_EXT_device_generated_commands)
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPreprocessGeneratedCommandsEXT.html
FUBUKI_EXTENSION_API void preprocess_generated_commands(const functions&                  ext,
                                                        command_buffer_handle             command_buffer,
                                                        const VkGeneratedCommandsInfoEXT& generated_commands_info,
                                                        command_buffer_handle             state_command_buffer) noexcept;

/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdExecuteGeneratedCommandsEXT.html
FUBUKI_EXTENSION_API void execute_generated_commands(const functions&                  ext,
                                                     command_buffer_handle             command_buffer,
                                                     bool                              is_preprocessed,
                                                     const VkGeneratedCommandsInfoEXT& generated_commands_info) noexcept;

#endif // defined(VK_EXT_device_generated_commands)

} // namespace cmd

} // namespace fubuki::extension::ext_device_generated_commands

#endif // FUBUKI_EXTENSION_EXT_DEVICE_GENERATED_COMMANDS_HPP
