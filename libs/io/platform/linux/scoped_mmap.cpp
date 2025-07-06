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

#include <cerrno>

#include "io/platform/linux/scoped_mmap.hpp"

#include <core/assertion.hpp>

#include <sys/mman.h>

namespace fubuki::io::platform::linux_bsd
{

scoped_mmap::scoped_mmap(void* addr, std::size_t len, int prot, int flags, int fd, ::off_t offset)
{
    auto* const begin = static_cast<std::byte*>(mmap(addr, len, prot, flags, fd, offset));

    if(begin == MAP_FAILED)
    {
        const auto error = static_cast<linux_bsd::code>(errno);
        throw call_exception{
            linux_call_info{.result = {error}, .call_literal = "mmap(addr, len, prot, flags, fd, offset)"}
        };
    }

    fubuki_assert(begin, "Internal error. mmap returned nullptr");

    // While correct, this is the only correct usage of the API

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

    m_contents = {begin, len};

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif
}

[[nodiscard]] std::expected<scoped_mmap, error::api_call>
scoped_mmap::make(void* addr, std::size_t len, int prot, int flags, int fd, ::off_t offset) noexcept
{
    auto* ptr = static_cast<std::byte*>(mmap(addr, len, prot, flags, fd, offset));
    fubuki_assert(ptr, "Internal error. mmap returned nullptr");

    if(ptr == MAP_FAILED)
    {
        const auto error = static_cast<linux_bsd::code>(errno);
        return std::unexpected{
            linux_call_info{.result = {error}, .call_literal = "mmap(addr, len, prot, flags, fd, offset"}
        };
    }

    return scoped_mmap{token{}, ptr, len};
}

scoped_mmap::~scoped_mmap() noexcept
{
    if(m_contents.data() != nullptr)
    {
        std::ignore = munmap(m_contents.data(), m_contents.size());
    }
}

} // namespace fubuki::io::platform::linux_bsd
