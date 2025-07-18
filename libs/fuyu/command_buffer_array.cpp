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

#include <memory>

#include "fuyu/command_buffer_array.hpp"

#include <core/assertion.hpp>
#include <core/collect.hpp>
#include <core/result.hpp>

#include "fuyu/device.hpp" // IWYU pragma: keep (required for conversion operators)

namespace fubuki::fuyu
{

/********************************************************************************/
/*                            PRIVATE MEMBER FUNCTIONS                          */
/********************************************************************************/

[[nodiscard]] std::optional<api_call_info> command_buffer_array::create(const VkCommandBufferAllocateInfo& info) noexcept
{
    if(m_handles.empty())
    {
        fuyu::device_view const dev = device();

        fubuki_assert(dev->vk10.allocate_command_buffers != nullptr, "Internal error. Functions should have been loaded.");

        small_vector<VkCommandBuffer> vk_handles;
        vk_handles.resize(host_size(info.commandBufferCount));

        if(const auto success
           = fubuki_validate(validate_by::expected, dev->vk10.allocate_command_buffers(dev.handle.vk, std::addressof(info), vk_handles.data())))
        {
            m_handles.assign(vk_handles.begin(), vk_handles.end());
        }
        else
        {
            return success.error();
        }
    }

    return {};
}

void command_buffer_array::destroy() noexcept
{
    if(not m_handles.empty())
    {
        const fuyu::device_view dev = device();

        fubuki_assert(dev->vk10.free_command_buffers != nullptr, "Internal error. Functions should have been loaded.");

        auto vk_handles = collect<VkCommandBuffer>(small_span{m_handles}.const_span());
        dev->vk10.free_command_buffers(dev.handle.vk, m_pool.vk, vk_size(vk_handles), vk_handles.data());

        m_handles.clear();
    }
}
} // namespace fubuki::fuyu
