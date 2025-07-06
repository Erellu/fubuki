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

#include "extension/functions/khr_synchronization2.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
khr_synchronization2 khr_synchronization2::load([[maybe_unused]] instance_handle instance,
                                                [[maybe_unused]] version_number  vk_version,
                                                [[maybe_unused]] device_handle   device) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");
    fubuki_assert(device != null_handle, "Device cannot be null_handle.");

    [[maybe_unused]] auto* const device_get = pfn<"vkGetDeviceProcAddr">(instance);
    fubuki_assert(device_get != nullptr, "Could not retrieve vkGetDeviceProcAddr function pointer.");

    // clang-format off
    return
    {
#if defined(VK_KHR_synchronization2)
        .queue_submit2_khr = pfn<"vkQueueSubmit2KHR">(instance, device, device_get),
        .get_queue_checkpoint_data2_nv = pfn<"vkGetQueueCheckpointData2NV">(instance, device, device_get),

        .cmd =
        {
            .set_event2_khr = pfn<"vkCmdSetEvent2KHR">(instance, device, device_get),
            .reset_event2_khr = pfn<"vkCmdResetEvent2KHR">(instance, device, device_get),
            .wait_events2_khr = pfn<"vkCmdWaitEvents2KHR">(instance, device, device_get),
            .pipeline_barrier2_khr = pfn<"vkCmdPipelineBarrier2KHR">(instance, device, device_get),
            .write_timestamp2_khr = pfn<"vkCmdWriteTimestamp2KHR">(instance, device, device_get),
            .write_buffer_marker2_amd = pfn<"vkCmdWriteBufferMarker2AMD">(instance, device, device_get),

        },
#endif // defined(VK_KHR_synchronization2)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
