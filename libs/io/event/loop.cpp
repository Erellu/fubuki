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

#include <io/platform/current_platform.hpp>

#if defined(_WIN32)
    #include <io/platform/win32/event_loop.hpp>
    #include <io/platform/win32/window_registry.hpp>
#elif defined(__unix__)
    #include <io/platform/linux/event/loop.hpp>
    #include <io/platform/linux/window_registry.hpp>
#endif

#include <io/platform/event/queue.hpp>

#include "io/event/loop.hpp"

namespace fubuki::io::event::loop
{

namespace
{

void fix(routines::step& s) noexcept
{
    if(not s.before)
    {
        s.before = routines::no_op;
    }

    if(not s.after)
    {
        s.after = routines::no_op;
    }
}

void fix(routines& r) noexcept
{
    fix(r.loop);
    fix(r.system_event);
    fix(r.internal_event);

    if(not r.external_surface)
    {
        r.external_surface = routines::error::external_surface::no_op;
    }
}

} // anonymous namespace

namespace next
{

[[nodiscard]]
std::expected<std::optional<int>, routines::error::external_surface> system(platform::views::display dp) noexcept
{
    return platform::current::process_next_system_event(dp);
}

[[nodiscard]] std::optional<int> user(event::queue& q) noexcept { return platform::current::process_next_user_event(q); }

} // namespace next

[[nodiscard]]
int execute(std::span<const platform::views::display> displays, std::span<const std::reference_wrapper<event::queue>> queues, routines r) noexcept
{
    fix(r);

    r.loop.before();

    std::optional<int> exit_code = {};

    while(not platform::current::window_registry::empty() and not exit_code.has_value())
    {
        // System
        for(const auto dp : displays)
        {
            r.system_event.before();

            if(const auto system = next::system(dp))
            {
                exit_code = *system;
            }
            else
            {
                r.external_surface(system.error());
            }

            r.system_event.after();
        }

        // User queues
        for(auto& q : queues)
        {
            r.internal_event.before();
            if(const auto internal_event_result = next::user(q); not exit_code) // Preserve the first value of exit_code
            {
                exit_code = internal_event_result;
            }
            r.internal_event.after();
        }
    }

    r.loop.after();

    platform::current::window_registry::clear(); // May not be empty if a quit message was sent
    return exit_code.value_or(0);
}

[[nodiscard]] bool pending(platform::display_view dp) noexcept { return platform::current::window_registry::event_pending(dp); }

void exit(int exit_code) noexcept { return platform::current::exit_event_loop(exit_code); }

} // namespace fubuki::io::event::loop
