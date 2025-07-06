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
#include <map>
#include <mutex>

#include "io/platform/linux/wayland/display.hpp"

#include "io/platform/event/key.hpp"
#include "io/platform/event/mouse.hpp"
#include "io/platform/linux/scoped_mmap.hpp"
#include "io/platform/linux/wayland/error.hpp"
#include "io/platform/linux/wayland/fixed.hpp"
#include "io/platform/linux/wayland/interface.hpp"
#include "io/platform/linux/wayland/registry.hpp"
#include "io/platform/linux/wayland/window.hpp"
#include "io/platform/linux/wayland/xdg/interface.hpp"
#include "io/platform/linux/wayland/zxdg/interface.hpp"
#include "io/platform/linux/window_registry.hpp"
#include "io/platform/linux/xkb/key_code.hpp"
#include "io/platform/mouse_button.hpp"

#include <linux/input-event-codes.h>
#include <sys/mman.h>
#include <sys/timerfd.h>
#include <xkbcommon/xkbcommon.h>

namespace fubuki::io::platform::linux_bsd::wayland
{

// NOLINTBEGIN(bugprone-easily-swappable-parameters)
namespace
{

namespace cache
{

using storage        = std::map<wl_display*, display::global>;
using iterator       = storage::iterator;
using emplace_result = std::pair<iterator, bool>;

[[nodiscard]] auto& get() noexcept
{
    static storage c;
    return c;
}

[[nodiscard]] auto& sync() noexcept
{
    static std::mutex m;
    return m;
}

} // namespace cache

namespace callback
{

namespace output
{

using storage = small_vector<screen_properties, screen_properties::typical_monitor_count>;

void geometry(void* data,
              wl_output* /*wl_output*/,
              std::int32_t x,
              std::int32_t y,
              std::int32_t /*physical_width*/,
              std::int32_t /*physical_height*/,
              std::int32_t /*subpixel*/,
              const char* make,
              const char* model,
              std::int32_t /*transform*/) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto& monitors = *static_cast<storage*>(data);

    if(monitors.empty())
    {
        monitors.emplace_back();
    }

    auto& next = monitors.back();

    next.area.offset.x = x;
    next.area.offset.y = y;
    next.name          = std::string{make} + "-" + model;
}

void mode(void* data, wl_output* /*wl_output*/, std::uint32_t /*flags*/, std::int32_t width, std::int32_t height, std::int32_t refresh) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto& monitors = *static_cast<storage*>(data);

    if(monitors.empty())
    {
        monitors.emplace_back();
    }

    constexpr auto mhz_to_hz = 1000;
    auto&          next      = monitors.back();

    next.area.extent.width  = width;
    next.area.extent.height = height;
    next.refresh_rate       = static_cast<std::uint32_t>(refresh / mhz_to_hz); // mHz
}

void done(void* data, wl_output* /*wl_output*/) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto& monitors = *static_cast<storage*>(data);

    monitors.emplace_back();
}

void scale(void* data, wl_output* /*wl_output*/, std::int32_t /*factor*/) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto& monitors = *static_cast<storage*>(data);

    if(monitors.empty())
    {
        monitors.emplace_back();
    }

    /*monitors.back().scale = factor;*/
}

void name(void* data, wl_output* /*wl_output*/, const char* name) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto& monitors = *static_cast<storage*>(data);

    if(monitors.empty())
    {
        monitors.emplace_back();
    }

    monitors.back().name = name;
}

void description(void* data, wl_output* /*wl_output*/, const char* /*description*/) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto& monitors = *static_cast<storage*>(data);

    if(monitors.empty())
    {
        monitors.emplace_back();
    }
}

} // namespace output

namespace seat
{

void capabilities(void* data, wl_seat* seat, std::uint32_t capabilities) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display::global*>(data);

    if(seat == dp->handle.seat)
    {
        dp->property.seat.flags = capabilities;
    }
}

void name(void* data, wl_seat* seat, const char* name) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display::global*>(data);

    if(seat == dp->handle.seat and name != nullptr) // nullptr check makes clang happy
    {
        dp->property.seat.name = name;
    }
}

namespace pointer
{

[[nodiscard]] bool is_for(const display_parts::input& w, const wl_pointer* pointer) noexcept
{
    return w.seat
        .and_then([pointer](const wayland::seat& seat) noexcept
                  { return seat.parts().mouse.transform([pointer](const wayland::pointer& p) noexcept -> bool { return p.handle() == pointer; }); })
        .value_or(false);
}

[[nodiscard]] std::optional<window_ref> focused_window(const display_parts::input_state& p) noexcept
{
    return p.seat.mouse.attention.transform([](const auto& attention) noexcept { return attention.surface; })
        .and_then([](surface_handle h) noexcept { return window_registry::window_of(h); });
}

void enter(void* data, wl_pointer* pointer, std::uint32_t serial, wl_surface* surface, wl_fixed_t sx, wl_fixed_t sy) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, pointer))
    {
        return;
    }

    dp->status.seat.mouse.attention = {.surface = surface_handle{surface}, .serial = serial};

    dp->status.seat.mouse.common.last_position = position2d{fixed::to<int>(sx), fixed::to<int>(sy)};

    if(auto window = pointer::focused_window(dp->status))
    {
        window->get().os_event(event::window::focus{.previous = false, .next = true, .source = {}});
        window->get().os_event(event::mouse::move{.where = *dp->status.seat.mouse.common.last_position});
    }
}

void leave(void* data, wl_pointer* pointer, std::uint32_t /*serial*/, wl_surface* surface)
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, pointer))
    {
        return;
    }

    if(auto window = pointer::focused_window(dp->status))
    {
        window->get().os_event(event::window::focus{.previous = true, .next = false, .source = {}});
    }

    if(dp->status.seat.mouse.attention.transform([surface](const auto& attention) noexcept { return attention.surface.value == surface; })
           .value_or(false))
    {
        dp->status.seat.mouse.attention = {};
    }
}

void motion(void* data, wl_pointer* pointer, std::uint32_t /*time*/, wl_fixed_t sx, wl_fixed_t sy) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, pointer))
    {
        return;
    }

    dp->status.seat.mouse.common.last_position = position2d{fixed::to<int>(sx), fixed::to<int>(sy)};

    if(auto window = pointer::focused_window(dp->status))
    {
        window->get().os_event(event::mouse::move{.where = *dp->status.seat.mouse.common.last_position});
    }
}

void button(void* data, wl_pointer* pointer, std::uint32_t /*serial*/, std::uint32_t time, std::uint32_t button, std::uint32_t state) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, pointer))
    {
        return;
    }

    constexpr auto moved_between_click = [](std::optional<position2d> previous, std::optional<position2d> next) noexcept -> bool
    {
        if(not previous.has_value() or not next.has_value())
        {
            return true;
        }

        return previous != next;
    };

    constexpr auto double_click_interval = 500; // 500 ms, as the default on Windows
    const bool     pressed               = state == WL_POINTER_BUTTON_STATE_PRESSED;

    const auto update_timestamp = [pressed, time](display_parts::seat_state::pointer::button& b) noexcept
    {
        if(pressed)
        {
            b.last_click_timestamp = time;
        }
    };

    const auto process = [&](io::mouse::button fbk_code, display_parts::seat_state::pointer::button& b) noexcept
    {
        // TODO: also handle xdg_toplevel_move when using client-side decorations

        const auto old_pos = b.last_position;

        if(const auto last = dp->status.seat.mouse.common.last_position)
        {
            b.last_position = last;
        }

        const auto window = pointer::focused_window(dp->status);

        const auto process_as_single_click = [&](wayland::window& w) noexcept
        {
            if(pressed)
            {
                const auto event = event::mouse::click{.which  = fbk_code,
                                                       .where  = b.last_position.value_or(position2d{}),
                                                       .mod    = dp->status.seat.keyboard.current_modifiers,
                                                       .source = {}};
                w.os_event(event);
            }
            else
            {
                const auto event = event::mouse::release{.which  = fbk_code,
                                                         .where  = b.last_position.value_or(position2d{}),
                                                         .mod    = dp->status.seat.keyboard.current_modifiers,
                                                         .source = {}};
                w.os_event(event);
            }
        };

        if(b.last_click_timestamp.has_value())
        {
            const auto diff = time - *b.last_click_timestamp;

            if(not pressed and b.next_release_is_double_click)
            {
                const auto event = event::mouse::double_click{.which  = fbk_code,
                                                              .where  = dp->status.seat.mouse.common.last_position.value_or(position2d{}),
                                                              .mod    = dp->status.seat.keyboard.current_modifiers,
                                                              .source = {}};

                if(window)
                {
                    window->get().os_event(event);
                }

                b.next_release_is_double_click = false;
            }

            else if(diff <= double_click_interval and pressed and not moved_between_click(old_pos, b.last_position))
            {
                b.next_release_is_double_click = true;
                // No click event here on purpose for consistency between platforms
            }

            else if(window)
            {
                process_as_single_click(*window);
            }
        }
        else if(window)
        {
            process_as_single_click(*window);
        }
        update_timestamp(b);
    };

    if(button == BTN_LEFT)
    {
        process(io::mouse::button::left, dp->status.seat.mouse.common.left);
    }
    else if(button == BTN_MIDDLE)
    {
        process(io::mouse::button::central, dp->status.seat.mouse.common.centre);
    }
    else if(button == BTN_RIGHT)
    {
        process(io::mouse::button::right, dp->status.seat.mouse.common.right);
    }
    else if(button == BTN_SIDE)
    {
        process(io::mouse::button::ex_1, dp->status.seat.mouse.common.ex_1);
    }
    else if(button == BTN_EXTRA)
    {
        process(io::mouse::button::ex_2, dp->status.seat.mouse.common.ex_2);
    }
}

void axis(void* data, wl_pointer* pointer, std::uint32_t /*time*/, std::uint32_t which, wl_fixed_t value) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, pointer))
    {
        return;
    }

    if(auto window = pointer::focused_window(dp->status))
    {
        // According to glfw, this "appears to be a common ratio"
        constexpr auto ratio = 10.0;

        const auto event = event::mouse::wheel{.ticks       = static_cast<std::int32_t>(fixed::to<double>(value) / ratio),
                                               .orientation = which == WL_POINTER_AXIS_HORIZONTAL_SCROLL ? event::mouse::wheel::direction::horizontal
                                                                                                         : event::mouse::wheel::direction::vertical,

                                               .where  = dp->status.seat.mouse.common.last_position.value_or(position2d{}),
                                               .mod    = dp->status.seat.keyboard.current_modifiers,
                                               .source = {}};

        window->get().os_event(event);
    }
}

// TODO: Maybe accumulate in a small_vector of mouse events and handle everything here?
void frame(void* /*data*/, wl_pointer* /*pointer*/) noexcept {}
void axis_source(void* /*data*/, wl_pointer* /*pointer*/, std::uint32_t /*axis_source*/) noexcept {}
void axis_stop(void* /*data*/, wl_pointer* /*pointer*/, std::uint32_t /*time*/, std::uint32_t /*axis*/) noexcept {}
void axis_discrete(void* /*data*/, wl_pointer* /*pointer*/, std::uint32_t /*axis*/, std::int32_t /*discrete*/) noexcept {}
void axis_value120(void* /*data*/, wl_pointer* /*pointer*/, std::uint32_t /*axis*/, std::int32_t /*value120*/) noexcept {}
void axis_relative_direction(void* /*data*/, wl_pointer* /*pointer*/, std::uint32_t /*axis*/, std::uint32_t /*direction*/) noexcept {}

} // namespace pointer

namespace keyboard
{

[[nodiscard]] bool is_for(const display_parts::input& dp, const wl_keyboard* keyboard) noexcept
{
    return dp.seat
        .and_then(
            [keyboard](const wayland::seat& seat) noexcept
            { return seat.parts().keyboard.transform([keyboard](const wayland::keyboard& p) noexcept -> bool { return p.handle() == keyboard; }); })
        .value_or(false);
}

[[nodiscard]] std::optional<window_ref> focused_window(const display_parts::input_state& p) noexcept
{
    return p.seat.keyboard.attention.transform([](const auto& attention) noexcept { return attention.surface; })
        .and_then([](surface_handle h) noexcept { return window_registry::window_of(h); });
}

void keymap(void* data, wl_keyboard* keyboard, std::uint32_t format, std::int32_t fd, std::uint32_t size) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    const file_descriptor file{file_descriptor::handle{fd}};

    if(format != WL_KEYBOARD_KEYMAP_FORMAT_XKB_V1)
    {
        return; // Other not supported - at the time of writing, only this format exists
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, keyboard) or not dp->context.keyboard.has_value())
    {
        return;
    }

    // Keymap
    {
        auto keymap_data = scoped_mmap::make(nullptr, size, PROT_READ, MAP_PRIVATE, fd);

        if(not keymap_data)
        {
            return; // May happen in circumstances in which the user has restricted permissions
        }

        auto keymap = xkb::keymap::make(dp->context.keyboard->handle.handle(), keymap_data->as_bytes(), static_cast<xkb::keymap::format>(format));

        if(not keymap)
        {
            return; // Indicates an error in the call - the file descriptor may be corrupted or the system may not have any more memory to allocate
        }

        dp->context.keyboard->keymap = *std::move(keymap);
    }

    // Keyboard states
    {
        // NOLINTNEXTLINE(bugprone-unchecked-optional-access): cannot be modified from elsewhere, the events are serial
        auto state = xkb::state::make(dp->context.keyboard->keymap->handle());

        if(not state)
        {
            return; // Indicates an error in the call - the system may not have any more memory to allocate or the memory used for the keymap was
                    // corrupted
        }

        dp->context.keyboard->state = *std::move(state);
    }

    // TODO: compose state and table
}

void enter(void* data, wl_keyboard* keyboard, std::uint32_t serial, wl_surface* surface, wl_array* /*keys*/) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, keyboard))
    {
        return;
    }

    dp->status.seat.keyboard.attention = {.surface = surface_handle{surface}, .serial = serial};

    if(auto window = keyboard::focused_window(dp->status))
    {
        window->get().os_event(event::window::focus{.previous = false, .next = true, .source = {}});
    }

    // TODO: update with the current keys
}

void leave(void* data, wl_keyboard* keyboard, std::uint32_t /*serial*/, wl_surface* surface) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, keyboard))
    {
        return;
    }

    if(auto window = keyboard::focused_window(dp->status))
    {
        window->get().os_event(event::window::focus{.previous = true, .next = false, .source = {}});
    }

    // Only if we leave the previous surface
    if(dp->status.seat.keyboard.attention.transform([surface](const auto& attention) noexcept { return attention.surface.value == surface; })
           .value_or(false))
    {
        dp->status.seat.keyboard.attention = {};
    }

    if(dp->context.keyboard)
    {
        if(itimerspec timer = {}; timerfd_settime(dp->context.keyboard->repeat_timer.handle().value, 0, std::addressof(timer), nullptr))
        {
            // TODO: do something smart
        }
    }
}

void key(
    void* data, wl_keyboard* keyboard, std::uint32_t /*serial*/, std::uint32_t /*time*/, std::uint32_t evdev_scancode, std::uint32_t state) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, keyboard))
    {
        return;
    }

    // The scancode from this event is the Linux **evdev** scancode.
    // To translate this to an XKB scancode, we must add 8 to the evdev scancode.
    constexpr auto evdev_to_xkb = 8;
    const auto     xkb_scancode = evdev_scancode + evdev_to_xkb;

    std::optional<xkb_keysym_t> xkb_key_sym = {};

    if(dp->context.keyboard)
    {
        if(const auto keyboard_state = dp->context.keyboard->state.transform([](auto& o) noexcept { return o.handle(); }); keyboard_state.has_value())
        {
            xkb_state_update_key(*keyboard_state, xkb_scancode, state == WL_KEYBOARD_KEY_STATE_PRESSED ? XKB_KEY_DOWN : XKB_KEY_UP);
            xkb_key_sym = xkb_state_key_get_one_sym(*keyboard_state, xkb_scancode);
        }

        // Repeat
        // These events get handled latter, when polling the timer
        {
            itimerspec timer = {};

            if(const auto keymap = dp->context.keyboard->keymap.transform([](auto& o) noexcept { return o.handle(); }); keymap.has_value())
            {
                if(xkb_keymap_key_repeats(*keymap, xkb_scancode) != 0 and dp->status.seat.keyboard.repeat.rate > 0)
                {
                    auto repeat = dp->status.seat.keyboard.repeat;

                    repeat.key = xkb_scancode;

                    // interval
                    if(repeat.rate > 1)
                    {
                        constexpr auto scale      = 1000000000;
                        timer.it_interval.tv_nsec = scale / repeat.rate;
                    }
                    else
                    {
                        timer.it_interval.tv_sec = 1;
                    }

                    // value
                    {
                        using tv_nsec_t           = decltype(timespec{}.tv_nsec);
                        constexpr tv_nsec_t scale = 1000000;
                        constexpr tv_nsec_t ms    = 1000;
                        timer.it_value.tv_nsec    = repeat.delay / ms;
                        timer.it_value.tv_nsec    = (static_cast<tv_nsec_t>(repeat.delay) % ms) * scale;
                    }
                }
            }

            if(timerfd_settime(dp->context.keyboard->repeat_timer.handle().value, 0, std::addressof(timer), nullptr))
            {
                // TODO: do something smart
            }
        }
    }

    if(xkb_key_sym.has_value())
    {
        if(const auto fbk_key = linux_bsd::xkb::from(*xkb_key_sym); fbk_key != io::keyboard::key::unknown)
        {
            if(auto window = keyboard::focused_window(dp->status))
            {
                // TODO: repetion
                if(state == WL_KEYBOARD_KEY_STATE_PRESSED)
                {
                    const event::key::press translation{
                        .which  = fbk_key,
                        .mod    = dp->status.seat.keyboard.current_modifiers,
                        .source = {},
                    };

                    window->get().os_event(translation);
                }
                else
                {
                    const event::key::release translation{
                        .which  = fbk_key,
                        .mod    = dp->status.seat.keyboard.current_modifiers,
                        .source = {},
                    };

                    window->get().os_event(translation);
                }
            }
        }
    }
}

void modifiers(void*        data,
               wl_keyboard* keyboard,
               std::uint32_t /*serial*/,
               std::uint32_t depressed,
               std::uint32_t latched,
               std::uint32_t locked,
               std::uint32_t group) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, keyboard))
    {
        return;
    }

    if(dp->context.keyboard)
    {
        if(const auto keyboard_state = dp->context.keyboard->state.transform([](auto& o) noexcept { return o.handle(); }); keyboard_state.has_value())
        {
            xkb_state_update_mask(*keyboard_state, depressed, latched, locked, 0, 0, group);

            if(const auto& keymap = dp->context.keyboard->keymap)
            {
                using modifier_code = fubuki::io::keyboard::modifier;
                const auto& index   = keymap->modifiers_indices();
                auto&       current = dp->status.seat.keyboard.current_modifiers;

                current = {};

                for(const auto& [xdg, fbk] : {
                        std::make_tuple(index.control, modifier_code::ctrl),
                        std::make_tuple(index.shift, modifier_code::shift),
                        std::make_tuple(index.alt, modifier_code::alt),
                        std::make_tuple(index.caps_lock, modifier_code::caps),
                        // std::make_tuple(modifiers.numlock, modifier_code::numlock), // TODO: numlock?
                    })
                {
                    if(xkb_state_mod_index_is_active(*keyboard_state, xdg, XKB_STATE_MODS_EFFECTIVE) == 1)
                    {
                        current |= fbk;
                    }
                }
            }
        }
    }
}

void repeat_info(void* data, wl_keyboard* keyboard, std::int32_t rate, std::int32_t delay) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display_parts::input*>(data);

    if(not is_for(*dp, keyboard))
    {
        return;
    }

    dp->status.seat.keyboard.repeat.rate  = rate;
    dp->status.seat.keyboard.repeat.delay = delay;
}

} // namespace keyboard

} // namespace seat

namespace xdg
{

void pong(void* /*user*/, xdg_wm_base* handle, std::uint32_t serial) { xdg_wm_base_pong(handle, serial); }

} // namespace xdg

} // namespace callback

namespace listener
{

namespace seat
{

constexpr wl_seat_listener properties = {.capabilities = callback::seat::capabilities, .name = callback::seat::name};

constexpr wl_pointer_listener pointer{
    .enter                   = callback::seat::pointer::enter,
    .leave                   = callback::seat::pointer::leave,
    .motion                  = callback::seat::pointer::motion,
    .button                  = callback::seat::pointer::button,
    .axis                    = callback::seat::pointer::axis,
    .frame                   = callback::seat::pointer::frame,
    .axis_source             = callback::seat::pointer::axis_source,
    .axis_stop               = callback::seat::pointer::axis_stop,
    .axis_discrete           = callback::seat::pointer::axis_discrete,
    .axis_value120           = callback::seat::pointer::axis_value120,
    .axis_relative_direction = callback::seat::pointer::axis_relative_direction,
};

constexpr wl_keyboard_listener keyboard{
    .keymap      = callback::seat::keyboard::keymap,
    .enter       = callback::seat::keyboard::enter,
    .leave       = callback::seat::keyboard::leave,
    .key         = callback::seat::keyboard::key,
    .modifiers   = callback::seat::keyboard::modifiers,
    .repeat_info = callback::seat::keyboard::repeat_info,
};

} // namespace seat

constexpr wl_output_listener output = {.geometry    = callback::output::geometry,
                                       .mode        = callback::output::mode,
                                       .done        = callback::output::done,
                                       .scale       = callback::output::scale,
                                       .name        = callback::output::name,
                                       .description = callback::output::description};

constexpr xdg_wm_base_listener xdg = {.ping = callback::xdg::pong};

} // namespace listener

namespace callback::registry
{

void global(void* data, wl_registry* registry, std::uint32_t name, const char* c_interface, std::uint32_t version) noexcept
{
    if(data == nullptr)
    {
        return;
    }

    auto* const dp = static_cast<display::global*>(data);

    const std::string_view interface = c_interface;

    if(interface == wl_compositor_interface.name)
    {
        dp->handle.compositor = static_cast<wl_compositor*>(wl_registry_bind(registry, name, std::addressof(wl_compositor_interface), 4));
    }

    else if(interface == wl_subcompositor_interface.name)
    {
        dp->handle.subcompositor = static_cast<wl_subcompositor*>(wl_registry_bind(registry, name, std::addressof(wl_subcompositor_interface), 1));
    }

    else if(interface == wl_shm_interface.name)
    {
        dp->handle.shm = static_cast<wl_shm*>(wl_registry_bind(registry, name, std::addressof(wl_shm_interface), 1));
    }

    else if(interface == wl_seat_interface.name)
    {
        constexpr auto seat_interface_v = 7;
        dp->handle.seat = static_cast<wl_seat*>(wl_registry_bind(registry, name, std::addressof(wl_seat_interface), seat_interface_v));
        wl_seat_add_listener(dp->handle.seat, std::addressof(listener::seat::properties), dp);
    }

    else if(interface == wl_output_interface.name)
    {
        dp->handle.output = static_cast<wl_output*>(wl_registry_bind(registry, name, std::addressof(wl_output_interface), version));

        wl_output_add_listener(dp->handle.output, std::addressof(listener::output), std::addressof(dp->property.screens));
    }

    else if(interface == xdg_wm_base_interface.name)
    {
        dp->handle.wm_base = static_cast<xdg_wm_base*>(wl_registry_bind(registry, name, std::addressof(xdg_wm_base_interface), 1));
        xdg_wm_base_add_listener(dp->handle.wm_base, std::addressof(listener::xdg), nullptr);
    }

    else if(interface == zxdg_decoration_manager_v1_interface.name)
    {
        dp->handle.decoration_manager
            = static_cast<zxdg_decoration_manager_v1*>(wl_registry_bind(registry, name, std::addressof(zxdg_decoration_manager_v1_interface), 1));
    }
}

void global_remove(void* /*data*/, wl_registry* /*registry*/, std::uint32_t /*name*/) noexcept {}

} // namespace callback::registry

namespace listener
{

constexpr wl_registry_listener registry{.global = callback::registry::global, .global_remove = callback::registry::global_remove};

} // namespace listener

[[nodiscard]]
std::expected<std::reference_wrapper<display::global>, error::api_call> acquire_globals_of(views::display::wayland dp) noexcept
{
    if(dp.handle == nullptr)
    {
        fubuki_assert(dp.handle != nullptr, "Invalid display");
        return std::unexpected{error::api_call{call_info{.result = {code::unknown{}}, .call_literal = "dp.handle != nullptr"_literal}}};
    }

    const std::scoped_lock<std::mutex> _{cache::sync()};

    auto& global_cache = cache::get();

    if(const auto it = global_cache.find(dp.handle); it != global_cache.end())
    {
        return it->second;
    }

    const auto make_entry = [dp]() noexcept -> std::expected<display::global, error::api_call>
    {
        display::global result = {};

        // Handles and properties
        {
            auto r = registry::make(dp);

            if(not r)
            {
                return std::unexpected{r.error()};
            }

            wl_registry_add_listener(r->handle(), std::addressof(listener::registry), std::addressof(result));
            wl_display_roundtrip(dp.handle);
            wl_display_roundtrip(dp.handle); // Necessary to retrieve the seat and screen properties

            // Don't keep dangling pointers - result goes out of scope insertion in the cache
            wl_seat_set_user_data(result.handle.seat, nullptr);
            wl_output_set_user_data(result.handle.output, nullptr);

            // An extra screen is added upon the last call to callback::output::done, with dummy data. It's not a real screen.
            if(result.property.screens.size() > 1)
            {
                result.property.screens.pop_back();
            }
        }

        // Input
        {
            auto inputs = seat::make(result.handle.seat, result.property.seat.flags);

            if(not inputs)
            {
                return std::unexpected{inputs.error()};
            }

            auto keyboard_context = xkb::context::make();

            if(not keyboard_context)
            {
                return std::unexpected{keyboard_context.error()};
            }

            auto repeat_timer = fd_timer::make(fd_timer::id::monotonic);

            if(not repeat_timer)
            {
                return std::unexpected{repeat_timer.error()};
            }

            result.input.seat = {*std::move(inputs)};

            // Keymap and state are created lazily when receiving events
            result.input.context.keyboard = display_parts::input::ctx::kb{*std::move(keyboard_context), *std::move(repeat_timer)};

            result.input.status = {};
        }

        return result;
    };

    return make_entry()
        .transform([&global_cache, dp](display::global g) noexcept { return global_cache.emplace(dp.handle, std::move(g)); })
        .and_then(
            [](cache::emplace_result it) noexcept -> std::expected<std::reference_wrapper<display::global>, error::api_call>
            {
                if(not it.second)
                {
                    return std::unexpected{
                        call_info{.result = {code::unknown{}}, .call_literal = "cache.emplace(dp, result)"_literal}
                    };
                }

                auto& globals = it.first->second;

                // NOLINTBEGIN(bugprone-unchecked-optional-access): none of this optionals can change in this scope
                if(globals.input.seat->parts().mouse)
                {
                    wl_pointer_add_listener(
                        globals.input.seat->parts().mouse->handle(), std::addressof(listener::seat::pointer), std::addressof(globals.input));
                }

                if(globals.input.seat->parts().keyboard)
                {
                    wl_keyboard_add_listener(
                        globals.input.seat->parts().keyboard->handle(), std::addressof(listener::seat::keyboard), std::addressof(globals.input));
                }
                // NOLINTEND(bugprone-unchecked-optional-access)

                return std::ref(globals);
            });
}

} // anonymous namespace
// NOLINTEND(bugprone-easily-swappable-parameters)

[[nodiscard]]
std::expected<std::reference_wrapper<const display::global>, error::api_call> globals_of(views::display::wayland dp) noexcept
{
    return acquire_globals_of(dp).transform([](std::reference_wrapper<display::global> b) noexcept { return std::cref(b); });
}

[[nodiscard]] std::optional<std::reference_wrapper<const display::global>> peek_at_globals_of(views::display::wayland dp) noexcept
{
    if(dp.handle == nullptr)
    {
        fubuki_assert(dp.handle != nullptr, "Invalid display");
        return {};
    }

    const std::scoped_lock<std::mutex> _{cache::sync()};
    auto&                              global_cache = cache::get();

    if(const auto it = global_cache.find(dp.handle); it != global_cache.end())
    {
        return it->second;
    }

    return {};
}

[[nodiscard]]
auto display::create() noexcept -> std::optional<any_call_info>
{
    m_handle = wl_display_connect(m_info.display_name.value_or(nullptr));

    if(m_handle == nullptr)
    {
        return any_call_info{
            call_info{.result = {code::unknown{}}, .call_literal = "wl_display_connect"_literal}
        };
    }

    auto g = acquire_globals_of(*this);

    if(not g)
    {
        return g.error().value;
    }

    // Input
    if(auto& seat = g->get().input.seat; seat.has_value())
    {
        auto& inputs = g->get().input;

        if(seat->parts().mouse.has_value())
        {
            // NOLINTNEXTLINE(bugprone-unchecked-optional-access)
            wl_pointer_set_user_data(inputs.seat->parts().mouse->handle(), std::addressof(g->get().input));
        }

        if(seat->parts().keyboard.has_value())
        {
            // NOLINTNEXTLINE(bugprone-unchecked-optional-access)
            wl_keyboard_set_user_data(inputs.seat->parts().keyboard->handle(), std::addressof(g->get().input));
        }
    }

    return {};
}

display::~display() noexcept
{
    if(m_handle != nullptr)
    {
        if(const auto globals = globals_of(*this))
        {
            const auto& handle = globals->get().handle;

            const std::scoped_lock<std::mutex> _{cache::sync()};

            // Globals can't be used after the display is disconnected
            if(handle.decoration_manager != nullptr)
            {
                zxdg_decoration_manager_v1_destroy(handle.decoration_manager);
            }

            if(handle.wm_base != nullptr)
            {
                xdg_wm_base_destroy(handle.wm_base);
            }

            if(handle.output != nullptr)
            {
                wl_output_destroy(handle.output);
            }

            if(handle.seat != nullptr)
            {
                wl_seat_destroy(handle.seat);
            }

            if(handle.shm != nullptr)
            {
                wl_shm_destroy(handle.shm);
            }

            if(handle.subcompositor != nullptr)
            {
                wl_subcompositor_destroy(handle.subcompositor);
            }

            if(handle.compositor != nullptr)
            {
                wl_compositor_destroy(handle.compositor);
            }
            cache::get().erase(m_handle);
        }

        wl_display_disconnect(m_handle);
    }
}

} // namespace fubuki::io::platform::linux_bsd::wayland
