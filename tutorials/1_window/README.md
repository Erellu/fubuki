# Fubuki tutorials: 01 - Window

## Overview

This tutorial explains how to create a window, listen to events from user interactions and poll screen/keyboard/mouse information. 


> [!NOTE]
> **Fubuki, does not require you to use its `io::display`, nor its `io::window`**: you can construct a `fuyu::surface` directly from platform-dependent data (on Windows for example, from a `HWND` and an `HINSTANCE`.). You are free to use `glfw`, `SDL`, `Qt` or whatever framework you already have in use an completely ignore `fubuki::io::display` and `fubuki::io::window`.

> [!TIP]
> However, using `io::window` makes Fubuki _automagically_ fill the correct information, cross-platform.

## Window

A native window can be created through `io::window`. It requires an instance of `fubuki::io::display`, an indirection to the display server (on Windows, this is a placeholder for API consistency).

```cpp
fubuki::io::display dp {};

fubuki::io::window w
{
    dp,
    {
        .title       = "Tutorial 01: window",
        .size        = {width, height},
        .coordinates = {0, 0},
        .opacity     = 1.f,
        .style       = fubuki::io::window_style::os_default
    }
};
```

> [!IMPORTANT]
> These constructors **can** throw an instance of `fubuki::io::platform::call_exception` if an error occurred.

Alternatively, to work in `noexcept` contexts:

```cpp
auto display = fubuki::io::display::make();

if(not display)
{
    return handle(display.error());
}

// std::expected
auto w = fubuki::io::window::make(*display, fubuki::io::window::information{
    .title       = "Tutorial 01: window",
    .size        = {.width = 500, .height = 500},
    .coordinates = {.x     = 0,   .y      = 0  },
    .opacity     = 1.f,
    .style       = fubuki::io::window_style::os_default
});

if(not w)
{
    return handle(w.error());
}
```


### Manipulating a window

A window can be manipulated programmatically through its member functions:

| Function      | Operation                                                            | Note                                                                       |
| ------------- | -------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| `show`        | Shows the window.                                                    | N.A.                                                                       |
| `hide`        | Hides the window.                                                    | N.A.                                                                       |
| `close`       | Closes the window, as if the close button ("red cross") was clicked. | A window that has been closes cannot be reopened.                          |
| `enable`      | Enables the window, turning on all user interactions.                | Has an overload accepting `bool` that can conditionally enable the window. |
| `disable`     | Disables the window, turning off all user interactions.              | N.A.                                                                       |
| `set_opacity` | Changes the opacity of the window.                                   | N.A.                                                                       |
| `move`        | Moves the window to a given position, in pixels.                     | N.A.                                                                       |
| `resize`      | Changes the size of the window, in pixels.                           | N.A.                                                                       |
| `rename`      | Changes the name of the window.                                      | N.A.                                                                       |

> [!IMPORTANT]
> All these functions (except `set_opacity`) _may_ trigger events depending on the platform. A side effect is that a call to `close` **can** be cancelled if the window event handlers refuses it. See [Events](#Events) below.

> [!IMPORTANT]
> Some operations are not supported on certain platforms. For example, it is not possible to move a window when running on Linux with a Wayland compositor. On Windows, all the above operations are supported.

### Platform-specific data

Platform-specific data required to construct a `fuyu::surface` (or through any analogue third-party mechanism) is available through `window::platform_data()` and `window::operator surface_data()` (implicit).
The resulting `fubuki::surface_data` can be `std::visited` to construct a `VkSurfaceKHR`, through the corresponding platform-specific extension.

> [!TIP]
> Using `fuyu::surface` and `io::window` will _automagically_ fill the correct information, cross-platform, and use the correct Vulkan extension to create a surface, seamlessly.

> [!CAUTION]
> The caller of these functions is responsible for not messing with this data (destroying the window without it knowing about it, etc.).

## Events

> [!IMPORTANT]
> **There are many, _many_ more available events that are not explicitly handled in the example code.**
> Please refer to the documentation for all available events.

### Processing events

Events are processed through `io::event::handler`. The user is expected to inherit from this `class`, typically the following way:

```cpp
struct handle_resize : io::event::handler
{
    void handle(surface_handle, const io::event::window::resize&) noexcept override
    {
        ...
    }
};
```

**An event handler can be `enabled()` or `disabled()`, which indicates if it will be called when an event is fired.** The state is accessible through `event::handler::enabled()/disabled()`, and can be changed  through `event::handler::enable(bool)/enable()/disable()`.



> [!IMPORTANT]
> **One handler can listen to more than one event type.** 

```cpp
struct handle_window_events : io::event::handler
{
    void handle(surface_handle, const io::event::window::resize&) noexcept override
    {
        ...
    }

    void handle(surface_handle, const io::event::window::move&) noexcept override
    {
        ...
    }
};
```

### Listening to events

Events are handled per-window through an `io::event::dispatcher`.
A dispatcher works like a range of `io::event::handler`, sorted by `priority` (`float`).

The window's event dispatcher can be accessed through `window::event_dispatcher()`.

```cpp
using priority   = io::event::dispatcher::priority;
auto& dispatcher = window.event_dispatcher();

// handler_a will execute first, then handler_b, then handler_c
dispatcher.add<handler_a>(priority{100.f}, args...);
dispatcher.add<handler_b>(priority{50.f}, args...);
dispatcher.add<handler_c>(priority{0.f});
```

It is possible to look for a specific handler through the algorithms of the Standard library:

```cpp
auto& dispatcher = window.event_dispatcher();

const auto predicate = [this](const event::dispatcher::entry& h) noexcept { return dynamic_cast<some_derived_class*>(h.handle.get()) != nullptr; };

if(auto it = std::ranges::find_if(dispatcher, predicate); it != dispatcher.end())
{
    ...
}
```

> [!CAUTION]
> **When priorities are edited, a call to `dispatcher::refresh_priorities` is required**. This is potentially an expensive operation, depending on the number of event handlers, and this should not be performed extensively for optimal performance. 

> [!CAUTION]
> Any modification on an `event::dispatcher` must be externally synchronised.

### Sending events

For example:

```cpp
const event::mouse::scroll new_event = {.ticks = 5, .where = {0, 0}, .modifier = {},};

event::send(queue, window, {new_event});
```

In which:
- `queue` is an instance of `fubuki::io::event::queue`, that will store the events **if, and only if** it cannot be translated in terms of system events.
- `window` is an instance of `fubuki::io::window` that will receive the events
- `new_event` is any `fubuki::io::event`.

It is also possible to send multiple events in one call of `send`:

```cpp
const event::mouse::click click  {...};
const event::key::press   press  {...};
const event::user::custom custom {...};

event::send(window, {{click}, {press}, {custom}});
```

> [!TIP]
> It is possible to filter artificial events through the `source` member of each event.

```cpp
if(event.source.origin != event::origin::hardware)
{
    std::cout << "   The event does not come from physical hardware : " << event.source << "\n" << std::flush;
}
```

### Event loop

Events are not processed until they reach the event loop.

A simple event-loop is available through `io::event::loop::execute(...)`, which is a **blocking** function that only returns when all windows are closed or when `event::loop::exit(int = 0)` is called. `io::event::loop::execute` accepts an optional argument of type `io::event::loop::routines` that can be used to specify functions to execute each iteration at various timings, as illustrated below.

`execute()` is equivalent to the following pseudo-code:

```cpp
int execute(display_range displays, event_queue_range event_queues, routines r)
{
    r.loop.before();
    while(no_reason_to_exit())
    {
        // System events are handled first...
        for(display& dp : displays)
        {
            r.system_event.before();

            if(const auto system = next::system(dp); not system)
            {
                r.external_surface(system.error());
            }

            r.system_event.after();
        }

        // ... And events from the user-provided queues are handled next
        for(event::queue& q : event_queues)
        {
            r.internal_event.before();
            next_user_event(dp);
            r.internal_event.after();
        }
    }
    r.loop.after();
    return exit_code();
}
```

By default, all routines are no-op.

To process one event at a time (for example, when inter-operating with another API providing an event loop), call `io::event::loop::next::system` or `next::user` to handle respectively system events and events sent to a `fubuki::io::event::queue`.

> [!CAUTION]
> **WARNING**: `event::loop::next::system` and `loop::execute` MUST be called in the same thread the windows are created in. 

> [!CAUTION]
> `fubuki::io::event::queue` is **NOT thread-safe**. Access must be externally synchronised.

## IO devices (keyboard, mouse, screen...)

### Keyboard

Keyboard keys can be scanned through `io::keyboard`:

```cpp
for(const auto poll : {key::a, key::shift, key::o} 
                      | std::views::transform([](auto k) noexcept { return io::keyboard::poll(display, k); }))
{
    if(poll.has_value())
    {
        use(k, *poll);
    }
    else
    {
        handle(poll.error());
    }
}
```

When it's convenient to keep the key associated to its state, the idiomatic approach would be:

```cpp
constexpr std::array keys_to_poll = {key::a, key::shift, key::o};
auto polled_result = keys_to_poll
                     | std::views::transform([](auto k) noexcept { return io::keyboard::poll(display, k); };

for(const auto [k, poll] : std::views::zip(keys_to_poll, polled_result))
{
    if(poll.has_value())
    {
        use(k, *poll);
    }
    else
    {
        handle(poll.error());
    }
}
```

> [!NOTE]
> These operations are not supported on Wayland.

### Mouse

Mouse position and button states can be read through `io::mouse`:

```cpp

// Poll the state of the right button
if(const auto right = io::mouse::poll(display, io::mouse::button::right); right.has_value())
{
    ...
}

// Poll left, central and right buttons
if(const auto all_buttons = io::mouse::buttons_state(display); all_buttons.has_value())
{
    ...
}

// Poll the position of the mouse on the screen
if(const auto pos = io::mouse::pos(display); pos.has_value())
{
    ...
}

// Poll all of the above
if(const auto mouse_state = io::mouse::current_state(display); mouse_state.has_value())
{
    ...
}
```

> [!NOTE]
> These operations are not supported on Wayland.

### Screens

Screens currently plugged can be polled through `io::screen::enumerate`:

```cpp
const auto screens = fubuki::io::screen::enumerate(display);

for(const auto& screen : fubuki::io::screen::enumerate(display))
{
    ... // Enumerates all screens, their size, their supported resolutions and refresh rates, ...
}
```

> [!NOTE]
> The results of this function can change during the execution if a screen is suddenly plugged in or removed.

_______________________________________________

[Next tutorial](https://github.com/Erellu/fubuki/tree/master/tutorials/2_vulkan_context)
