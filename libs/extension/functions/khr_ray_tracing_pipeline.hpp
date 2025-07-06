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

#ifndef FUBUKI_EXTENSION_FUNCTION_KHR_RAY_TRACING_PIPELINE_HPP
#define FUBUKI_EXTENSION_FUNCTION_KHR_RAY_TRACING_PIPELINE_HPP

#include <core/config/macros.hpp>
#include <core/detail/pfn.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

namespace fubuki
{

namespace extension
{

namespace functions
{

struct khr_ray_tracing_pipeline
{
#if defined(VK_KHR_ray_tracing_pipeline)

    struct command
    {
        PFN_vkCmdTraceRaysKHR                      trace_rays_khr                          = nullptr;
        PFN_vkCmdTraceRaysIndirectKHR              trace_rays_indirect_khr                 = nullptr;
        PFN_vkCmdSetRayTracingPipelineStackSizeKHR set_ray_tracing_pipeline_stack_size_khr = nullptr;
    };

    PFN_vkCreateRayTracingPipelinesKHR                    create_ray_tracing_pipelines_khr                        = nullptr;
    PFN_vkGetRayTracingShaderGroupHandlesKHR              get_ray_tracing_shader_group_handles_khr                = nullptr;
    PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR get_ray_tracing_capture_replay_shader_group_handles_khr = nullptr;
    PFN_vkGetRayTracingShaderGroupStackSizeKHR            get_ray_tracing_shader_group_stack_size_khr             = nullptr;

    command cmd = {};

#endif // defined(VK_KHR_ray_tracing_pipeline)

    /// Loads the extension.
    [[nodiscard]] FUBUKI_EXTENSION_API static khr_ray_tracing_pipeline
    load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept;
};

} // namespace functions

/**
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_KHR_ray_tracing_pipeline.html
 */
namespace khr_ray_tracing_pipeline
{

/// Name of the extension.
inline constexpr auto name = "VK_KHR_ray_tracing_pipeline";

using functions = extension::functions::khr_ray_tracing_pipeline;

/// Loads the extension.
[[nodiscard]] inline functions
load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept
{
    return functions::load(instance, vk_version, device);
}

} // namespace khr_ray_tracing_pipeline

} // namespace extension

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a extension::functions::khr_ray_tracing_pipeline struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<extension::functions::khr_ray_tracing_pipeline, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const extension::functions::khr_ray_tracing_pipeline&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, fubuki_name)                                                                \
    template<>                                                                                                             \
    struct get_from<extension::functions::khr_ray_tracing_pipeline, #vk_function_name>                                     \
    {                                                                                                                      \
        static constexpr bool valid = true;                                                                                \
                                                                                                                           \
        [[nodiscard]] constexpr static auto* get(const extension::functions::khr_ray_tracing_pipeline& functions) noexcept \
        {                                                                                                                  \
            static_assert(                                                                                                 \
                requires {                                                                                                 \
                    {                                                                                                      \
                        functions.fubuki_name                                                                              \
                    };                                                                                                     \
                }, "Internal error. Bad name or version structure.");                                                      \
                                                                                                                           \
            auto pfn = functions.fubuki_name;                                                                              \
                                                                                                                           \
            using expected_pfn_type = PFN_##vk_function_name;                                                              \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                                         \
                                                                                                                           \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch.");                  \
                                                                                                                           \
            return pfn;                                                                                                    \
        }                                                                                                                  \
    }

#if defined(VK_KHR_ray_tracing_pipeline)
FUBUKI_MAKE_GET_FROM(vkCreateRayTracingPipelinesKHR, create_ray_tracing_pipelines_khr);
FUBUKI_MAKE_GET_FROM(vkGetRayTracingShaderGroupHandlesKHR, get_ray_tracing_shader_group_handles_khr);
FUBUKI_MAKE_GET_FROM(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR, get_ray_tracing_capture_replay_shader_group_handles_khr);
FUBUKI_MAKE_GET_FROM(vkGetRayTracingShaderGroupStackSizeKHR, get_ray_tracing_shader_group_stack_size_khr);
FUBUKI_MAKE_GET_FROM(vkCmdTraceRaysKHR, cmd.trace_rays_khr);
FUBUKI_MAKE_GET_FROM(vkCmdTraceRaysIndirectKHR, cmd.trace_rays_indirect_khr);
FUBUKI_MAKE_GET_FROM(vkCmdSetRayTracingPipelineStackSizeKHR, cmd.set_ray_tracing_pipeline_stack_size_khr);

#endif // defined(VK_KHR_ray_tracing_pipeline)

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_EXTENSION_KHR_RAY_TRACING_PIPELINE_HPP
