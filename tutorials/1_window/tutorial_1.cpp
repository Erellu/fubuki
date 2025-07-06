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

#include <array>
#include <iomanip>
#include <iostream>
#include <ranges>

#include <core/config/setup.hpp>
#include <io/display.hpp>
#include <io/event/handler.hpp>
#include <io/event/loop.hpp>
#include <io/event/send.hpp>
#include <io/keyboard.hpp>
#include <io/mouse.hpp>
#include <io/screen.hpp>
#include <io/window.hpp>

/*
 * Controls:
 *
 * | Key         | Effect                                      | Handler   |
 * | ----------- | ------------------------------------------- | --------- |
 * | esc         | Close the window and exit                   | handler_a |
 * | shift + esc | Exit the event loop (and the application)   | handler_a |
 * | +           | Increase the window opacity                 | handler_a |
 * | -           | Decrease the window opacity                 | handler_a |
 * | w           | Increase the window width                   | handler_a |
 * | h           | Increase the window height                  | handler_a |
 * | shift + w   | Increase the window width                   | handler_a |
 * | shift + h   | Increase the window height                  | handler_a |
 * | arrow keys  | Move the window                             | handler_a |
 * | m           | Poll the mouse state                        | handler_a |
 * | a           | Send an event::key::press{-}                | handler_a |
 * | shift + a   | Send an event::key::press{+}                | handler_a |
 * | d           | Send an event::mouse::double_click          | handler_a |
 * | s           | Send an event::mouse::scroll                | handler_a |
 * | u           | Send 3 event::user::custom holding ints     | handler_a |
 * | shift + u   | Send 1 event::user::custom holding a string | handler_a |
 * | -------------------------------------------------------------------- |
 * | p           | Set handler_b priority to 0                 | handler_b |
 * | shift + p   | Set handler_b priority to 150               | handler_b |
 * | -------------------------------------------------------------------- |
 *
 * | Mouse        | Effect          | Handler                         |
 * | ------------ | --------------- | ------------------------------- |
 * | Click        | Print to stdout | handler_a, handler_b, handler_c |
 * | Double-click | Print to stdout | handler_a                       |
 * | Scroll       | Print to stdout | handler_a                       |
 */

namespace event = fubuki::io::event;

namespace user_tag
{

using fubuki::io::event::user::make_tag;

constexpr auto str     = make_tag(333); ///< Arbitrary tag used in this example to perform some logic on event::user::custom.
constexpr auto integer = make_tag(444); ///< Arbitrary tag used in this example to perform some logic on event::user::custom.

} // namespace user_tag

struct handler_a final : event::handler
{
    handler_a(fubuki::io::window& w, fubuki::io::event::queue& q) noexcept : m_window{w}, m_queue{q} {}

    void handle(fubuki::surface_data, const event::key::press& event) noexcept override
    {
        using code     = event::key::code;
        using modifier = event::key::modifier;
        using button   = event::mouse::button;

        std::cout << "handler_a: " << " window " << std::quoted(m_window.get().info().title) << " got " << event << "\n" << std::flush;

        // Shown for demonstration purposes ('s' triggers this event)
        if(event.source.provenance != event::origin::hardware and event.source.provenance != event::origin::system)
        {
            std::cout << "   The event may not come from physical hardware : " << event.source << "\n" << std::flush;
        }

        if(event.which == code::esc)
        {
            if(event.mod & modifier::shift)
            {
                fubuki::io::event::loop::exit();
            }
            else
            {
                std::ignore = m_window.get().close();
            }

            return;
        }

        if(event.which == code::add)
        {
            constexpr auto factor = 0.1f;
            std::ignore           = m_window.get().set_opacity(m_window.get().info().opacity + factor);
            return;
        }

        if(event.which == code::substract)
        {
            constexpr auto factor = 0.1f;
            std::ignore           = m_window.get().set_opacity(m_window.get().info().opacity - factor);
            return;
        }

        if(event.which == code::left_arrow)
        {
            constexpr auto offset = 10;

            auto pos = m_window.get().info().coordinates;
            pos.x -= offset;

            std::ignore = m_window.get().move(pos);
            return;
        }

        if(event.which == code::up_arrow)
        {
            constexpr auto offset = 10;

            auto pos = m_window.get().info().coordinates;
            pos.y -= offset; // Y axis points downwards

            std::ignore = m_window.get().move(pos);
            return;
        }

        if(event.which == code::right_arrow)
        {
            constexpr auto offset = 10;

            auto pos = m_window.get().info().coordinates;
            pos.x += offset;

            std::ignore = m_window.get().move(pos);
            return;
        }

        if(event.which == code::down_arrow)
        {
            constexpr auto offset = 10;

            auto pos = m_window.get().info().coordinates;
            pos.y += offset; // Y axis points downwards

            std::ignore = m_window.get().move(pos);
            return;
        }

        if(event.which == code::w)
        {
            constexpr auto factor = 50;

            auto size = m_window.get().info().size;
            if(event.mod & modifier::shift)
            {
                size.width += factor;
            }
            else
            {
                size.width -= factor;
            }

            std::ignore = m_window.get().resize(size);

            return;
        }

        if(event.which == code::h)
        {
            constexpr auto factor = 50;

            auto size = m_window.get().info().size;
            if(event.mod & modifier::shift)
            {
                size.height += factor;
            }
            else
            {
                size.height -= factor;
            }

            std::ignore = m_window.get().resize(size);

            return;
        }

        if(event.which == code::s)
        {
            const event::mouse::scroll new_event = {
                .ticks = 5,
                .where = {0, 0},
                .mod   = {},
            };

            // Simulate a scroll (wheel) event
            if(const auto check = fubuki::io::event::send(m_queue, m_window, {{new_event}}); not check)
            {
                std::cout << "handler_a: Failed to send events: " << check.error();
            }
        }

        if(event.which == code::m)
        {
            const auto mouse_state = fubuki::io::mouse::current_state(m_window.get().parent());

            if(mouse_state)
            {
                std::cout << "handler_a: Mouse current state: " << *mouse_state << "\n" << std::flush;
            }
            else
            {
                std::cout << "handler_a: Could not retrieve mouse state: " << mouse_state.error() << "\n" << std::flush;
            }

            return;
        }

        if(event.which == code::a)
        {
            if(event.mod & modifier::shift)
            {
                const event::key::press new_event = {
                    .which = code::add,
                };

                if(const auto check = fubuki::io::event::send(m_queue, m_window, {{new_event}}); not check)
                {
                    std::cout << "handler_a: Failed to send events: " << check.error();
                }
            }
            else
            {
                const event::key::press new_event = {
                    .which = code::substract,
                };

                if(const auto check = fubuki::io::event::send(m_queue, m_window, {{new_event}}); not check)
                {
                    std::cout << "handler_a: Failed to send events: " << check.error();
                }
            }
            return;
        }

        if(event.which == code::d)
        {
            const auto mouse_pos = fubuki::io::mouse::pos(m_window.get().parent());

            if(mouse_pos)
            {
                const event::mouse::double_click new_event{
                    .which = button::left,
                    .where = *mouse_pos,
                };

                if(const auto check = fubuki::io::event::send(m_queue, m_window, {{new_event}}); not check)
                {
                    std::cout << "handler_a: Failed to send events: " << check.error();
                }
            }
            else
            {
                std::cout << "handler_a: Could not retrieve mouse pos: " << mouse_pos.error() << "\n" << std::flush;
            }

            return;
        }

        if(event.which == code::u)
        {
            if(event.mod & modifier::shift)
            {
                const event::user::custom new_event{
                    .contents = {.tag = user_tag::str, .value = std::string{"foooooo"}},
                };

                if(const auto check = fubuki::io::event::send(m_queue, m_window, {{new_event}}); not check)
                {
                    std::cout << "handler_a: Failed to send events: " << check.error();
                }
            }
            else
            {
                const event::user::custom new_event{
                    .contents = {.tag = user_tag::integer, .value = std::int32_t{45}},
                };

                if(const auto check = fubuki::io::event::send(m_queue, m_window, {{new_event}, {new_event}, {new_event}}); not check)
                {
                    std::cout << "handler_a: Failed to send events: " << check.error();
                }
            }
        }
    }

    void handle(fubuki::surface_data, const event::mouse::double_click& event) noexcept override
    {
        std::cout << "handler_a: double click detected: " << event << ", its origin is: " << event.source << "\n" << std::flush;
    }

    void handle(fubuki::surface_data, const event::mouse::click& event) noexcept override
    {
        std::cout << "handler_a: mouse click: " << event << "\n";
        using button = event::mouse::button;
        using key    = fubuki::io::keyboard::key;

        if(event.which == button::right)
        {
            constexpr std::array keys_to_poll = {key::a, key::shift, key::o};
            auto                 polled_result
                = keys_to_poll | std::views::transform([this](auto k) noexcept { return fubuki::io::keyboard::poll(m_window.get().parent(), k); });

            for(const auto [k, poll] : std::views::zip(keys_to_poll, polled_result))
            {
                if(poll.has_value())
                {
                    std::cout << "   key '" << k << "' is " << (*poll ? "pressed." : "NOT pressed.") << "\n" << std::flush;
                }
                else
                {
                    std::cout << "    Error while polling key " << k << ": " << poll.error() << "\n";
                }
            }
        }
    }

    void handle(fubuki::surface_data, const event::mouse::scroll& event) noexcept override
    {
        std::cout << "handler_a: " << " got: " << event << "\n" << std::flush;

        // Shown for demonstration purposes ('s' triggers this event)
        if(event.source.provenance != event::origin::hardware)
        {
            std::cout << "   The event may not come from physical hardware : " << event.source << "\n" << std::flush;
        }
    }

    void handle(fubuki::surface_data, const event::window::resize& event) noexcept override
    {
        std::cout << "window was resized from " << event.previous << " to " << event.next << "\n" << std::flush;
    }

    using event::handler::handle;

    std::reference_wrapper<fubuki::io::window>       m_window;
    std::reference_wrapper<fubuki::io::event::queue> m_queue;
};

//------------------------------------------------------------------------------

struct handler_b final : event::handler
{
    handler_b(fubuki::io::window& w) noexcept : m_window{w} {}

    void handle(fubuki::surface_data, const event::mouse::click& event) noexcept override
    {
        std::cout << "handler_b: mouse click " << event << "\n" << std::flush;

        if(event.which == fubuki::io::mouse::button::central)
        {
            auto& event_dispatcher = m_window.get().event_dispatcher();

            if(auto it = std::ranges::find_if(event_dispatcher,
                                              [this](const fubuki::io::event::dispatcher::entry& d) noexcept { return d.handle.get() == this; });
               it != event_dispatcher.end())
            {
                event_dispatcher.mark(it);
            }
        }
    }

    void handle(fubuki::surface_data, const event::key::press& event) noexcept override
    {
        using code     = event::key::code;
        using modifier = event::key::modifier;

        if(event.which == code::p)
        {
            using event_dispatcher = event::dispatcher;
            using priority         = event_dispatcher::priority;

            const auto new_priority = event.mod & modifier::shift ? priority{150.f} : priority{0.f};
            auto&      dispatcher   = m_window.get().event_dispatcher();

            const auto find_this = [this](const event_dispatcher::entry& h) noexcept { return h.handle.get() == this; };

            if(auto it = std::ranges::find_if(dispatcher, find_this); it != dispatcher.end())
            {
                it->precedence = new_priority;

                dispatcher.refresh(); // Will be updated next event
            }
        }
    }

    using event::handler::handle;
    std::reference_wrapper<fubuki::io::window> m_window;
};

struct handler_c final : event::handler
{
    void handle(fubuki::surface_data, const event::mouse::click& event) noexcept override
    {
        std::cout << "handler_c: mouse click " << event << "\n" << std::flush;
    }

    void handle(fubuki::surface_data, const event::user::custom& event) noexcept override
    {
        std::cout << "handler_c: user custom event " << event << ", value: ";

        if(event.contents.tag == user_tag::str)
        {
            std::cout << std::quoted(std::any_cast<std::string>(event.contents.value)) << "\n" << std::flush;
        }
        else
        {
            std::cout << std::any_cast<std::int32_t>(event.contents.value) << "\n" << std::flush;
        }
    }

    event::answer handle(fubuki::surface_data, const event::window::close& event) noexcept override
    {
        std::cout << "handler_c: " << event << "\n" << std::flush;
        return event::answer::accept;
    }

    using event::handler::handle;
};

//------------------------------------------------------------------------------

int main()
{
    auto dp = fubuki::io::display::make({.display_name = {}, .window_system = fubuki::configuration::window_system::wayland});

    if(not dp)
    {
        std::cerr << "An error occurred while creating a display: " << dp.error();
        return 1;
    }

    // Create a window through the noexcept factory returning an instance of std::expected
    auto w = fubuki::io::window::make(*dp,
                                      {
                                          .title       = "Tutorial 01: window",
                                          .size        = {.width = 500, .height = 500,}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                                          .coordinates = {0,            0,            },
                                          .opacity     = 1.f,
                                          .style       = fubuki::io::window_style::os_default,
    });

    if(not w)
    {
        std::cerr << "An error occurred while creating a window: " << w.error() << std::flush;
        return 1;
    }

    // Create a window through the throwing constructor - an error throws an instance of fubuki::io::platform::call_exception
    fubuki::io::window w2(*dp,
                          {
                              .title       = "Tutorial 01: window 2",
                              .size        = {.width = 500, .height = 500}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                              .coordinates = {500,          500          }, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                              .opacity     = 1.f,
                              .style       = fubuki::io::window_style::os_default,
    });

    std::ignore = w->show();
    std::ignore = w2.show();

    fubuki::io::event::queue user_event_queue = {};

    // Add event handlers
    {
        using priority   = event::dispatcher::priority;
        auto& dispatcher = w->event_dispatcher();

        dispatcher.add<handler_a>(priority{100.f}, *w, user_event_queue); // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        dispatcher.add<handler_b>(priority{50.f}, *w);                    // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        dispatcher.add<handler_c>(priority{0.f});                         // NOLINT(cppcoreguidelines-avoid-magic-numbers)
    }

    {
        using priority   = event::dispatcher::priority;
        auto& dispatcher = w2.event_dispatcher();

        dispatcher.add<handler_c>(priority{0.f}); // NOLINT(cppcoreguidelines-avoid-magic-numbers)
    }

    // Print all properties of screens
    {
        const auto screens = fubuki::io::screen::enumerate(*dp);

        if(screens)
        {
            for(const auto& screen : *screens)
            {
                std::cout << screen;
                std::cout << "\n------------------------------------------\n" << "\n" << std::flush;
            }
        }
        else
        {
            std::cout << "An error occurred when retrieving information about the available screens: " << screens.error();
        }
    }

    using routines = fubuki::io::event::loop::routines;

    // Process events until all windows are closed

    return fubuki::io::event::loop::execute(*dp,
                                            user_event_queue,
                                            {
                                                // Equivalent to the default argument. Written explicitly for demonstration purposes.
                                                .loop           = {.before = routines::no_op, .after = routines::no_op},
                                                .system_event   = {.before = routines::no_op, .after = routines::no_op},
                                                .internal_event = {.before = routines::no_op, .after = routines::no_op},
    });
}
