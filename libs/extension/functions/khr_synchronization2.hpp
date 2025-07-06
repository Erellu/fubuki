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

#ifndef FUBUKI_EXTENSION_FUNCTION_KHR_SYNCHRONIZATION2_HPP
#define FUBUKI_EXTENSION_FUNCTION_KHR_SYNCHRONIZATION2_HPP

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

struct khr_synchronization2
{
#if defined(VK_KHR_synchronization2)

    struct command
    {
        PFN_vkCmdSetEvent2KHR          set_event2_khr           = nullptr;
        PFN_vkCmdResetEvent2KHR        reset_event2_khr         = nullptr;
        PFN_vkCmdWaitEvents2KHR        wait_events2_khr         = nullptr;
        PFN_vkCmdPipelineBarrier2KHR   pipeline_barrier2_khr    = nullptr;
        PFN_vkCmdWriteTimestamp2KHR    write_timestamp2_khr     = nullptr;
        PFN_vkCmdWriteBufferMarker2AMD write_buffer_marker2_amd = nullptr;
    };

    PFN_vkQueueSubmit2KHR           queue_submit2_khr             = nullptr;
    PFN_vkGetQueueCheckpointData2NV get_queue_checkpoint_data2_nv = nullptr;

    command cmd = {};

#endif // defined(VK_KHR_synchronization2)

    /// Loads the extension.
    [[nodiscard]] FUBUKI_EXTENSION_API static khr_synchronization2
    load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept;
};

} // namespace functions

/**
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_KHR_synchronization2.html
 */
namespace khr_synchronization2
{

/// Name of the extension.
inline constexpr auto name = "VK_KHR_synchronization2";

using functions = extension::functions::khr_synchronization2;

/// Loads the extension.
[[nodiscard]] inline functions
load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept
{
    return functions::load(instance, vk_version, device);
}

} // namespace khr_synchronization2

} // namespace extension

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a extension::functions::khr_synchronization2 struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<extension::functions::khr_synchronization2, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const extension::functions::khr_synchronization2&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, fubuki_name)                                                            \
    template<>                                                                                                         \
    struct get_from<extension::functions::khr_synchronization2, #vk_function_name>                                     \
    {                                                                                                                  \
        static constexpr bool valid = true;                                                                            \
                                                                                                                       \
        [[nodiscard]] constexpr static auto* get(const extension::functions::khr_synchronization2& functions) noexcept \
        {                                                                                                              \
            static_assert(                                                                                             \
                requires {                                                                                             \
                    {                                                                                                  \
                        functions.fubuki_name                                                                          \
                    };                                                                                                 \
                }, "Internal error. Bad name or version structure.");                                                  \
                                                                                                                       \
            auto pfn = functions.fubuki_name;                                                                          \
                                                                                                                       \
            using expected_pfn_type = PFN_##vk_function_name;                                                          \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                                     \
                                                                                                                       \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch.");              \
                                                                                                                       \
            return pfn;                                                                                                \
        }                                                                                                              \
    }

#if defined(VK_KHR_synchronization2)
FUBUKI_MAKE_GET_FROM(vkQueueSubmit2KHR, queue_submit2_khr);
FUBUKI_MAKE_GET_FROM(vkGetQueueCheckpointData2NV, get_queue_checkpoint_data2_nv);
FUBUKI_MAKE_GET_FROM(vkCmdSetEvent2KHR, cmd.set_event2_khr);
FUBUKI_MAKE_GET_FROM(vkCmdResetEvent2KHR, cmd.reset_event2_khr);
FUBUKI_MAKE_GET_FROM(vkCmdWaitEvents2KHR, cmd.wait_events2_khr);
FUBUKI_MAKE_GET_FROM(vkCmdPipelineBarrier2KHR, cmd.pipeline_barrier2_khr);
FUBUKI_MAKE_GET_FROM(vkCmdWriteTimestamp2KHR, cmd.write_timestamp2_khr);
FUBUKI_MAKE_GET_FROM(vkCmdWriteBufferMarker2AMD, cmd.write_buffer_marker2_amd);

#endif // defined(VK_KHR_synchronization2)

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_EXTENSION_KHR_SYNCHRONIZATION2_HPP
