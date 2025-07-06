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

#include <cstdlib>
#include <limits>
#include <sstream>

#include "io/platform/linux/file_descriptor.hpp"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

namespace fubuki::io::platform::linux_bsd
{

file_descriptor::~file_descriptor() noexcept
{
    if(m_handle.has_value())
    {
        close(m_handle->value);
    }
}

[[nodiscard]] auto file_descriptor::make_anonymous(std::size_t                     size_bytes,
                                                   std::string_view                fallback_path,
                                                   std::string_view                fallback_name_template,
                                                   [[maybe_unused]] anonymous_hint hint) noexcept -> std::expected<file_descriptor, error::api_call>
{
    if(size_bytes > static_cast<std::size_t>(std::numeric_limits<::off_t>::max()))
    {
        return std::unexpected{
            linux_call_info{.result = {}, .call_literal = "size_bytes > static_cast<std::size_t>(std::numeric_limits<::off_t>::max())"_literal}
        };
    }

    fubuki_assert(size_bytes <= static_cast<std::size_t>(std::numeric_limits<::off_t>::max()), "File too big. Reauest");

    const auto fall_back = [&]() noexcept -> std::expected<file_descriptor, any_call_info>
    {
        auto full_path
            = (std::ostringstream{} << fallback_path << fallback_name_template << (fallback_name_template.ends_with("-XXXXXX") ? "" : "-XXXXXX"))
                  .str();

        const int fd = mkostemp(full_path.data(), O_CLOEXEC);
        if(fd >= 0)
        {
            file_descriptor result{handle{fd}};

            unlink(full_path.c_str());

            if(const auto r = posix_fallocate(result.m_handle->value, 0, static_cast<::off_t>(size_bytes)); r != 0)
            {
                return std::unexpected{
                    linux_call_info{.result       = static_cast<linux_bsd::code>(r),
                                    .call_literal = "posix_fallocate(fd, 0, static_cast<::off_t>(size_bytes)"_literal}
                };
            }

            return result;
        }

        const auto error = static_cast<linux_bsd::code>(errno);

        return std::unexpected{
            linux_call_info{.result = error, .call_literal = "mkostemp"_literal}
        };
    };

#if defined(FUBUKI_HAS_MEMFD_CREATE)

    if(hint == anonymous_hint::memfd)
    {
        if(int const fd = memfd_create("fubuki-io-platform-linux", MFD_CLOEXEC | MFD_ALLOW_SEALING); fd >= 0)
        {
            file_descriptor result{handle{fd}};

            // Works because the file is currently empty, before we call posix_fallocate
            // In theory, an error returned by fcntl here is... Suspect.
            // This should NOT be possible for it to fail in that context.

            // NOLINTNEXTLINE(bugprone-unchecked-optional-access, cppcoreguidelines-pro-type-vararg)
            if(fcntl(result.m_handle->value, F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_SEAL) == -1)
            {
                const auto error = static_cast<linux_bsd::code>(errno);

                return std::unexpected{
                    linux_call_info{.result = error, .call_literal = "fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_SEAL)"_literal}
                };
            }

            if(const auto r = posix_fallocate(result.m_handle->value, 0, static_cast<::off_t>(size_bytes)); r != 0)
            {
                return std::unexpected{
                    linux_call_info{.result       = static_cast<linux_bsd::code>(r),
                                    .call_literal = "posix_fallocate(fd, 0, static_cast<::off_t>(size_bytes)"_literal}
                };
            }

            return result;
        }

        return fall_back();
    }

#endif // defined(FUBUKI_HAS_MEMFD_CREATE)

    return fall_back();
}

} // namespace fubuki::io::platform::linux_bsd
