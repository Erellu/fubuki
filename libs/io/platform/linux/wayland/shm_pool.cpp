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
#include <string_view>

#include "io/platform/linux/wayland/shm_pool.hpp"

#include <core/unique_c_ptr.hpp>

#include "io/platform/linux/file_descriptor.hpp"
#include "io/platform/linux/scoped_mmap.hpp"
#include "io/platform/linux/wayland/error.hpp"
#include "io/platform/linux/wayland/interface.hpp"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

namespace fubuki::io::platform::linux_bsd::wayland
{

static_assert(shm_pool::information::format == WL_SHM_FORMAT_ARGB8888, "Wayland changed the value of WL_SHM_FORMAT_ARGB8888");

[[nodiscard]]
std::optional<any_call_info> shm_pool::create() noexcept
{
    if(m_globals.shm == nullptr)
    {
        return any_call_info{
            call_info{.result = {code::unknown{}}, .call_literal = "m_globals.shm != nullptr"}
        };
    }

    const unique_c_ptr<char> current_dir{get_current_dir_name()};

    if(not current_dir)
    {
        return any_call_info{
            call_info{.result = {code::unknown{}}, .call_literal = "get_current_dir_name"}
        };
    }

    {
        auto fd = file_descriptor::make_anonymous(size_bytes(), std::string_view{current_dir.get()}, "fubuki-io-wayland-shm_pool");

        if(not fd)
        {
            return fd.error().value;
        }

        m_fd = *std::move(fd);
    }

    {
        // wl_shm_create_pool calls mmap (see https://wayland-client-d.dpldocs.info/wayland.client.protocol.wl_shm_create_pool.html), so it's
        // important to use a MAP_SHARED too.
        auto mmap_scope = scoped_mmap::make(nullptr, size_bytes(), PROT_READ | PROT_WRITE, MAP_SHARED, m_fd.get().value, 0);

        if(not mmap_scope)
        {
            return mmap_scope.error().value;
        }

        m_memory = *std::move(mmap_scope);
    }

    m_handle = wl_shm_create_pool(m_globals.shm, m_fd.get().value, static_cast<std::int32_t>(size_bytes()));

    if(m_handle == nullptr)
    {
        return any_call_info{
            call_info{.result = {code::unknown{}}, .call_literal = "wl_shm_create_pool"}
        };
    }

    return {};
}

shm_pool::~shm_pool() noexcept
{
    if(m_handle != nullptr)
    {
        wl_shm_pool_destroy(m_handle);
    }
}

} // namespace fubuki::io::platform::linux_bsd::wayland
