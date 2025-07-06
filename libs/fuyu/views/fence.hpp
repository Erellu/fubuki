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
#ifndef FUBUKI_FUYU_VIEWS_FENCE_HPP
#define FUBUKI_FUYU_VIEWS_FENCE_HPP

#include <utility>

#include <core/handle.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/device_ref.hpp"

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)

namespace fubuki
{

namespace fuyu
{

namespace views
{

struct fence
{
    /// State of a fence.
    enum class state
    {
        signaled,    ///< The fence was signaled, hence ready.
        not_ready,   ///< The fence was not signaled yet.
        device_lost, ///< The device was lost.
        unknown      ///< The state is unknown: the result code is not handled by Fubuki. Please open an issue.
    };

    fence_handle handle = {}; ///< Event handle.
    device_cref  device;      ///< Device on which the fence is allocated.

    [[nodiscard]] constexpr operator fence_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const fence& a, const fence& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const fence& a, const fence& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const fence& a, const fence& b) noexcept { return a.handle <=> b.handle; }
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const fence::state state)
{
    switch(state)
    {
        case fence::state::signaled   : out << "fence::state::signaled"; break;
        case fence::state::not_ready  : out << "fence::state::not_ready"; break;
        case fence::state::device_lost: out << "fence::state::device_lost"; break;
        case fence::state::unknown    : out << "fence::state::unknown"; break;
        default                       : out << "fence::state::<Invalid value> - perhaps static_cast?"; break;
    }
    return out;
}

} // namespace views

using fence_view  = views::fence;
using fence_state = fence_view::state;

using views::operator<<;

} // namespace fuyu

using fubuki::fuyu::operator<<;

} // namespace fubuki

namespace std
{

template<>
struct hash<fubuki::fuyu::fence_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::fence_view& v) const noexcept { return std::hash<decltype(v.handle.vk)>{}(v.handle.vk); }
};

template<>
struct hash<fubuki::fuyu::fence_state>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::fence_state& v) const noexcept
    {
        return std::hash<std::underlying_type_t<fubuki::fuyu::fence_state>>{}(std::to_underlying(v));
    }
};

} // namespace std

// NOLINTEND(cppcoreguidelines-pro-type-member-init)

#endif // FUBUKI_FUYU_VIEWS_FENCE_HPP
