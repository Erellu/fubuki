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

#ifndef FUBUKI_TUTORIAL_04_EVENT_HANDLING_HPP
#define FUBUKI_TUTORIAL_04_EVENT_HANDLING_HPP

#include "resources.hpp"

#include <functional>
#include <iostream>

#include <io/event.hpp>
#include <io/event/handler.hpp>
#include <io/event/loop.hpp>

#include <support/app.hpp>

namespace tutorial::triangle
{

class event_handler final : public fubuki::io::event::handler
{
    using answer = fubuki::io::event::answer;

    std::reference_wrapper<tutorial::triangle::resources> m_rc;

public:

    event_handler(std::reference_wrapper<tutorial::triangle::resources> rc) noexcept : m_rc{rc} {}

    void handle(fubuki::surface_data, const fubuki::io::event::key::press& e) noexcept override
    {
        using key = fubuki::io::keyboard::key;

        if(e.which == key::escape)
        {
            fubuki::io::event::loop::exit();
        }
    }

    answer handle(fubuki::surface_data, const fubuki::io::event::window::close&) noexcept override
    {
        namespace app = fubuki::tutorial::support::app;

        if(const auto check = fubuki::fuyu::wait_idle(app::device()); not check)
        {
            std::cout << "Error while waiting for device to go idle: " << check.error() << std::flush;
            std::terminate();
        }

        return answer::accept;
    }

    void handle(fubuki::surface_data, const fubuki::io::event::window::resize&) noexcept override
    {
        namespace app = fubuki::tutorial::support::app;

        if(const auto check = triangle::recreate_swapchain(m_rc.get()); not check)
        {
            std::cout << "Error while recreating the swapchain: " << check.error() << std::flush;
            std::terminate();
        }
    }

    using fubuki::io::event::handler::handle;
};

} // namespace tutorial::triangle

#endif // FUBUKI_TUTORIAL_04_EVENT_HANDLING_HPP
