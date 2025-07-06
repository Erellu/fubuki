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

#include "io/platform/linux/xlib/mouse.hpp"

#include <core/assertion.hpp>

#include "io/platform/linux/xlib/detail/code.hpp"
#include "io/platform/linux/xlib/error.hpp"

#include <X11/Xlib.h>

namespace fubuki::io::platform::linux_bsd::xlib::mouse
{

namespace
{

struct query_result
{
    int          win_x     = {};
    int          win_y     = {};
    int          root_x    = {};
    int          root_y    = {};
    unsigned int mask      = {};
    Window       child_win = {};
    Window       root_win  = {};
};

[[nodiscard]] std::expected<query_result, error::any> query(Display* dp) noexcept
{
    if(dp == nullptr)
    {
        fubuki_assert(dp != nullptr, "Invalid display");
        return std::unexpected{error::unknown{}};
    }

    query_result result = {};

    if(const auto r = XQueryPointer(dp,
                                    XRootWindow(dp, DefaultScreen(dp)),
                                    &result.child_win,
                                    &result.root_win,
                                    &result.root_x,
                                    &result.root_y,
                                    &result.win_x,
                                    &result.win_y,
                                    &result.mask);
       r != True)
    {
        return std::unexpected{platform::error::any{any_call_info{call_info{
            .result{detail::from_xlib(r)},
            .call_literal
            = "XQueryPointer(dp, XRootWindow(dp, DefaultScreen(dp)), &child_win, &root_win, &root_x, &root_y, &win_x, &win_y, &mask)"_literal}}}};
    }

    return result;
}

} // anonymous namespace

[[nodiscard]]
std::expected<state, error::any> current_state(Display* dp) noexcept
{
    auto q = query(dp);

    if(not q)
    {
        return std::unexpected{q.error()};
    }

    // Note that ex_1 and ex_2 cannot be queried through XQueryPointer (but are still detected through window events)

    return state{
        .pos    = {q->root_x, q->root_y},
        .button = {
                   .left    = static_cast<bool>(q->mask & Button1Mask),
                   .central = static_cast<bool>(q->mask & Button2Mask),
                   .right   = static_cast<bool>(q->mask & Button3Mask),
                   .ex_1    = false,
                   .ex_2    = false,
                   }
    };
}

} // namespace fubuki::io::platform::linux_bsd::xlib::mouse
