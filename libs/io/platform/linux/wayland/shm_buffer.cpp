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

#include <cstdint>
#include <limits>

#include "io/platform/linux/wayland/shm_buffer.hpp"

#include "io/platform/linux/wayland/error.hpp"
#include "io/platform/linux/wayland/interface.hpp"

namespace fubuki::io::platform::linux_bsd::wayland
{

[[nodiscard]] std::optional<any_call_info> shm_buffer::create(shm_pool& parent) noexcept
{
    const auto stride = width() * format_stride;

    if(stride > static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max()))
    {
        return any_call_info{
            call_info{.result       = {code::unknown{}},
                      .call_literal = "stride > static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max())"_literal}
        };
    }

    if(offset() > static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max()))
    {
        return any_call_info{
            call_info{.result       = {code::unknown{}},
                      .call_literal = "offset > static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max())"_literal}
        };
    }

    if(size_bytes() + offset() > parent.size_bytes())
    {
        return any_call_info{
            call_info{.result = {code::unknown{}}, .call_literal = "size_bytes() + offset() > parent.size_bytes()"_literal}
        };
    }

    m_handle = wl_shm_pool_create_buffer(parent.handle(),
                                         static_cast<std::int32_t>(offset()),
                                         static_cast<std::int32_t>(width()),
                                         static_cast<std::int32_t>(height()),
                                         static_cast<std::int32_t>(stride),
                                         information::format);

    if(m_handle == nullptr)
    {
        return any_call_info{
            call_info{.result = {code::unknown{}}, .call_literal = "wl_shm_pool_create_buffer"_literal}
        };
    }

    m_memory = parent.memory().subspan(offset(), size_bytes());

    return {};
}

shm_buffer::~shm_buffer() noexcept
{
    if(m_handle != nullptr)
    {
        wl_buffer_destroy(m_handle);
    }
}

} // namespace fubuki::io::platform::linux_bsd::wayland
