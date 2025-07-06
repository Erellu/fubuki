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

#include "extension/functions/ext_extended_dynamic_state.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
ext_extended_dynamic_state ext_extended_dynamic_state::load([[maybe_unused]] instance_handle instance,
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
#if defined(VK_EXT_extended_dynamic_state)

        .cmd =
        {
            .set_cull_mode_ext = pfn<"vkCmdSetCullModeEXT">(instance, device, device_get),
            .set_front_face_ext = pfn<"vkCmdSetFrontFaceEXT">(instance, device, device_get),
            .set_primitive_topology_ext = pfn<"vkCmdSetPrimitiveTopologyEXT">(instance, device, device_get),
            .set_viewport_with_count_ext = pfn<"vkCmdSetViewportWithCountEXT">(instance, device, device_get),
            .set_scissor_with_count_ext = pfn<"vkCmdSetScissorWithCountEXT">(instance, device, device_get),
            .bind_vertex_buffers2_ext = pfn<"vkCmdBindVertexBuffers2EXT">(instance, device, device_get),
            .set_depth_test_enable_ext = pfn<"vkCmdSetDepthTestEnableEXT">(instance, device, device_get),
            .set_depth_write_enable_ext = pfn<"vkCmdSetDepthWriteEnableEXT">(instance, device, device_get),
            .set_depth_compare_op_ext = pfn<"vkCmdSetDepthCompareOpEXT">(instance, device, device_get),
            .set_depth_bounds_test_enable_ext = pfn<"vkCmdSetDepthBoundsTestEnableEXT">(instance, device, device_get),
            .set_stencil_test_enable_ext = pfn<"vkCmdSetStencilTestEnableEXT">(instance, device, device_get),
            .set_stencil_op_ext = pfn<"vkCmdSetStencilOpEXT">(instance, device, device_get),

        },
#endif // defined(VK_EXT_extended_dynamic_state)
    };
    // clang-format on
}

} // namespace fubuki::extension::functions
