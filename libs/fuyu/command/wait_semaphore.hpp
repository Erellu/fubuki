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

#ifndef FUBUKI_FUYU_COMMAND_WAIT_SEMAPHORE_HPP
#define FUBUKI_FUYU_COMMAND_WAIT_SEMAPHORE_HPP

#include <core/vulkan.hpp>

#include "fuyu/views/semaphore.hpp"

namespace fubuki::fuyu
{

namespace command
{

/// A "wait" semaphore for submit commands.
// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
struct wait_semaphore
{
    semaphore_handle     handle = {};         ///< Vulkan handle.
    device_cref          device;              ///< Device on which the semaphore is allocated.
    VkPipelineStageFlags dst_stage_mask = {}; ///< Destination stage mask.

    [[nodiscard]] constexpr operator semaphore_handle() const noexcept { return handle; }
    [[nodiscard]] constexpr operator fuyu::semaphore_view() const noexcept { return {handle, device}; }

    [[nodiscard]] constexpr operator VkPipelineStageFlags() const noexcept { return dst_stage_mask; }
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_WAIT_SEMAPHORE_HPP
