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

#include <iostream>

#include <io/event.hpp>
#include <io/event/handler.hpp>
#include <io/event/loop.hpp>

#include <support/app.hpp>

/*
 * This example illustrates how to setup an execution context for your application.
 * The resources are allocated in app.cpp, and accessible through the interface provided in resources.hpp.
 */

//------------------------------------------------------------------------------

namespace fuyu = fubuki::fuyu;
namespace app  = fubuki::tutorial::support::app;

int main()
{
    const auto app_resources_scope
        = app::init({.display{{.display = {.display_name = {}, .window_system = fubuki::configuration::window_system::wayland},
                               .window  = {"Tutorial 04: Triangle"}}},
                     .instance{},
                     .device{},
                     .swapchain{}});

    if(not app_resources_scope)
    {
        std::cerr << "Failed to create the resources for the application. API error: " << app_resources_scope.error();
        return 1;
    }

    std::cout << "Instance: " << app::instance().handle().vk << "\n"
              << "Surface: " << app::surface().handle().vk << "\n"
              << "Device: " << app::device().handle().vk << "\n"
              << "Pipeline cache: " << app::pipeline_cache().handle().vk << "\n"
              << "Swapchain: " << app::swapchain().handle().vk << "\n"
              << std::flush;

    // Event handlers
    {
        struct on_resize : fubuki::io::event::handler
        {
            void handle(fubuki::surface_data, const fubuki::io::event::window::resize&) noexcept override
            {
                // Typically, applications wait on the queues using the swapchain resources before recreating the swapchain and its resources
                // This sample code doesn't contain such code however, so we can directly recreate the swapchain

                if(const auto success = fubuki::fuyu::recreate(app::swapchain(), app::swapchain_resources()); not success)
                {
                    std::cerr << "Failed to recreate swapchain. API error: " << success.error();
                    std::terminate();
                }
            }

            using fubuki::io::event::handler::handle;
        };

        app::window().event_dispatcher().add<on_resize>(fubuki::io::event::dispatcher::priority{0});
    }

    // Process events until all windows are closed.
    return fubuki::io::event::loop::execute(app::display(), app::user_event_queue());
}
