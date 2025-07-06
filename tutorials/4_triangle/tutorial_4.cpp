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

#include "event_handling.hpp"
#include "triangle.hpp"

#include <iostream>

#include <io/event.hpp>
#include <io/event/handler.hpp>
#include <io/event/loop.hpp>

#include <support/app.hpp>

constexpr auto frames_in_flight = tutorial::triangle::default_frames_in_flight;

struct frame
{
    std::size_t index = {};
    std::size_t count = {};
};

void draw(tutorial::triangle::resources& rc, frame& f) noexcept;

int main()
{
    namespace app = fubuki::tutorial::support::app;

    const auto app_resources_scope
        = app::init({.display{{.display = {.display_name = {}, .window_system = fubuki::configuration::window_system::wayland},
                               .window  = {"Tutorial 04: Triangle"}}},
                     .instance{},
                     .device{},
                     .swapchain{{.info = {.image = {.minimum_count = frames_in_flight}}}}},
                    app::setup_pnext{.instance = fubuki::empty_pnext_chain,
                                     .device   = fubuki::owning_pnext_chain{
                                         VkPhysicalDeviceVulkan13Features{
                                               .sType                                              = {},
                                               .pNext                                              = {},
                                               .robustImageAccess                                  = false,
                                               .inlineUniformBlock                                 = false,
                                               .descriptorBindingInlineUniformBlockUpdateAfterBind = false,
                                               .pipelineCreationCacheControl                       = false,
                                               .privateData                                        = false,
                                               .shaderDemoteToHelperInvocation                     = false,
                                               .shaderTerminateInvocation                          = false,
                                               .subgroupSizeControl                                = false,
                                               .computeFullSubgroups                               = false,
                                               .synchronization2                                   = false,
                                               .textureCompressionASTC_HDR                         = false,
                                               .shaderZeroInitializeWorkgroupMemory                = false,
                                               .dynamicRendering                                   = true,
                                               .shaderIntegerDotProduct                            = false,
                                               .maintenance4                                       = false,
                                         }}.chain()});

    if(not app_resources_scope)
    {
        std::cerr << "Failed to create the resources for the application. API error: " << app_resources_scope.error();
        return 1;
    }

    auto rc = tutorial::triangle::resources::make(frames_in_flight);

    if(not rc)
    {
        std::cerr << "Failed to create the resources for the application. API error: " << rc.error();
        return 1;
    }

    // Event handlers
    {
        app::window().event_dispatcher().add<tutorial::triangle::event_handler>({}, std::ref(*rc));
    }

    constexpr auto cleanup = []() noexcept
    {
        if(const auto check = fubuki::fuyu::wait_idle(fubuki::tutorial::support::app::device()); not check)
        {
            std::cerr << "Fatal error upon tear-down: " << check.error() << std::flush;
            std::terminate();
        }
    };

    using routines = fubuki::io::event::loop::routines;

    return fubuki::io::event::loop::execute(
        app::display(),
        app::user_event_queue(),
        {
            .loop           = {.before = routines::no_op, .after = cleanup},
            .system_event   = {.before = routines::no_op, .after = [&rc, f = frame{}]() mutable noexcept { draw(*rc, f); }},
            .internal_event = {.before = routines::no_op, .after = routines::no_op},
    });
}

void draw(tutorial::triangle::resources& rc, frame& f) noexcept
{
    std::cout << "frame " << f.count++ << "\n" << std::flush;

    if(const auto r = tutorial::triangle::draw(rc, f.index))
    {
        ++f.index;
        if(f.index >= frames_in_flight)
        {
            f.index = 0;
        }
    }
    else
    {
        namespace app = fubuki::tutorial::support::app;

        if(app::window().state().closed)
        {
            return;
        }

        if(const auto* const error = std::get_if<tutorial::triangle::draw_error::swapchain>(std::addressof(r.error().value)))
        {
            using enum fubuki::fuyu::presentation::error::code;

            if(error->value == out_of_date)
            {
                if(const auto check = tutorial::triangle::recreate_swapchain(rc); not check)
                {
                    std::cerr << "Failed to recreate the swapchain with error " << check.error() << std::flush;
                    std::terminate();
                }
            }
        }
    }
}
