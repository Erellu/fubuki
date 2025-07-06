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

#ifndef FUBUKI_CORE_DETAIL_MANUAL_HANDLE_HPP
#define FUBUKI_CORE_DETAIL_MANUAL_HANDLE_HPP

#include <cstdint>
#include <variant>

#include "core/compile_time_hash.hpp"
#include "core/detail/null_handle.hpp"
#include "core/vulkan.hpp"

namespace fubuki
{

template<std::uint64_t hash, typename T>
struct handle; // Second forward declaration for static analysis

#if defined(FUBUKI_MAKE_MANUAL_HANDLE)
    #error Internal error. Should not be defined.
#endif

#if defined(FUBUKI_MAKE_STR)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_STR(x) #x

#define FUBUKI_MAKE_MANUAL_HANDLE(vk_type, type_name)                                                  \
    template<>                                                                                         \
    struct handle<compile_time_hash(FUBUKI_MAKE_STR(fubuki_##type_name)), vk_type>                     \
    {                                                                                                  \
        static constexpr auto name      = #vk_type /*For consistency with the other handles*/;         \
        static constexpr auto name_hash = compile_time_hash((FUBUKI_MAKE_STR(fubuki_##type_name)));    \
        using underlying_type           = vk_type;                                                     \
        using self_type                 = handle<name_hash, underlying_type>;                          \
                                                                                                       \
        underlying_type vk{};                                                                          \
                                                                                                       \
        constexpr explicit handle(underlying_type h) noexcept : vk{h} {}                               \
        constexpr handle(detail::null_handle_type = {}) noexcept {}                                    \
                                                                                                       \
        constexpr auto& operator=(detail::null_handle_type) noexcept                                   \
        {                                                                                              \
            vk = {};                                                                                   \
            return *this;                                                                              \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]]                                                                                  \
        friend constexpr bool operator==(const self_type& h, const detail::null_handle_type&) noexcept \
        {                                                                                              \
            return h.vk == underlying_type{};                                                          \
        }                                                                                              \
                                                                                                       \
        friend constexpr bool operator==(const detail::null_handle_type&, const self_type& h) noexcept \
        {                                                                                              \
            return h.vk == self_type::underlying_type{};                                               \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]]                                                                                  \
        friend constexpr bool operator!=(const self_type& h, const detail::null_handle_type&) noexcept \
        {                                                                                              \
            return not(h == null_handle);                                                              \
        }                                                                                              \
                                                                                                       \
        [[nodiscard]]                                                                                  \
        friend constexpr bool operator!=(const detail::null_handle_type&, const self_type& h) noexcept \
        {                                                                                              \
            return not(h == null_handle);                                                              \
        }                                                                                              \
        [[nodiscard]] friend constexpr auto operator<=>(const self_type&, const self_type&) = default; \
        [[nodiscard]] friend constexpr bool operator==(const self_type&, const self_type&)  = default; \
        [[nodiscard]] friend constexpr bool operator!=(const self_type&, const self_type&)  = default; \
    };                                                                                                 \
                                                                                                       \
    using type_name##_handle = handle<compile_time_hash(FUBUKI_MAKE_STR(fubuki_##type_name)), vk_type>

FUBUKI_MAKE_MANUAL_HANDLE(VkPipeline, graphics_pipeline);
FUBUKI_MAKE_MANUAL_HANDLE(VkPipeline, compute_pipeline);

#if defined(VK_KHR_ray_tracing_pipeline)
FUBUKI_MAKE_MANUAL_HANDLE(VkPipeline, ray_tracing_pipeline_khr);
#endif // #if defined(VK_KHR_ray_tracing_pipeline)

#if defined(VK_NV_ray_tracing)
FUBUKI_MAKE_MANUAL_HANDLE(VkPipeline, ray_tracing_pipeline_nv);
#endif // #if defined(VK_NV_ray_tracing)

#if defined(VK_AMDX_shader_enqueue)
FUBUKI_MAKE_MANUAL_HANDLE(VkPipeline, execution_graph_pipeline);
#endif // #if defined(VK_AMDX_shader_enqueue)

using any_pipeline = std::variant<graphics_pipeline_handle,
                                  compute_pipeline_handle
#if defined(VK_KHR_ray_tracing_pipeline)
                                  ,
                                  ray_tracing_pipeline_khr_handle
#endif // #if defined(VK_KHR_ray_tracing_pipeline)
#if defined(VK_NV_ray_tracing)
                                  ,
                                  ray_tracing_pipeline_nv_handle
#endif // #if defined(VK_NV_ray_tracing)
#if defined(VK_AMDX_shader_enqueue)
                                  ,
                                  execution_graph_pipeline_handle
#endif // #if defined(VK_AMDX_shader_enqueue)
                                  >;

#undef FUBUKI_MAKE_STR
#undef FUBUKI_MAKE_MANUAL_HANDLE

} // namespace fubuki

#endif // FUBUKI_CORE_DETAIL_MANUAL_HANDLE_HPP
