# fubuki::io

> [!IMPORTANT]
> This file is _not_ a substitue for the in-code documentation.
> Its goal is to advertise the features available through `fubuki::io`.
> For examples and detailed documentation, see the `doxygen`.

## CMake

### Externally

```cmake
target_link_libraries(your_target <PUBLIC|PRIVATE> fubuki::io)
```

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "io"
                   PRIVATE_DEPENDENCIES "..."
                   HEADERS              "..."
                   SOURCES              "..."
                   PUBLIC_LINK          "..."
                   PRIVATE_LINK         "..."
                   SYSTEM_PUBLIC_LINK   "..." 
                   SYSTEM_PRIVATE_LINK  "..."
                  )
```

## Nomenclature

| Name                 | Type                     | Category                       | Description    | Notes                  |
| -------------------- | ------------------------ | ------------------------------ | -------------- | ---------------------- |
| Name of the facility | Type, in the C++ meaning | What this facility relates to. | What this does | Additional information |

## Overview

`fubuki::io` is an interface library that provides platform-agnostic abstractions over the facilities of `fubuki::io_platform`. **You should usually prefer manipulating `fubuki::io`**, as the code will stay the same on all supported platforms.

## Public API

### Window/Display

| Name                   | Type                 | Category                  | Description                                                        | Notes                                                                                                   |
| ---------------------- | -------------------- | ------------------------- | ------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------- |
| `display`              | `class`              | Display                   | An object representing a connection to a display server.           | On Windows, this is an articifial indirection to nothing, used to make the API match between platforms. |
| `information::display` | `struct`             | Information, construction | Information required to create a display.                          | N.A.                                                                                                    |
| `information::window`  | `struct`             | Information, construction | Information required to create a window.                           | N.A.                                                                                                    |
| `window`               | `class`              | Window                    | A window displayed on the screen.                                  | N.A.                                                                                                    |
| `window_state`         | Type alias, `struct` | Window                    | The state flags for windows, updated according to received events. | N.A.                                                                                                    |
| `window_style`         | Type alias, `enum`   | Window                    | The various styles available for Fubuki windows.                   | N.A.                                                                                                    |

### I/O devices

> [!NOTE]
> All of the functions presented here return instances of `std::expected`.
> **Some operations are not supported on all systems**. For example, on Linux with Wayland, most of these functions will return instances of `platform::error::operation_not_supported`.

#### Mouse

| Name                      | Type          | Category | Description                                     | Notes                     |
| ------------------------- | ------------- | -------- | ----------------------------------------------- | ------------------------- |
| `mouse::button`           | `enum`        | Mouse    | Platform-agnostic `enum` for mouse buttons.     | N.A.                      |
| `mouse::buttons_state`    | Free function | Mouse    | Returns the current state of the mouse buttons. | Not supported on Wayland. |
| `mouse::current_state`    | Free function | Mouse    | Returns the mouse current state.                | Not supported on Wayland. |
| `mouse::poll`             | Free function | Mouse    | Polls for one button state.                     | Not supported on Wayland. |
| `mouse::pos`              | Free function | Mouse    | Returns the mouse current position.             | Not supported on Wayland. |
| `mouse::scroll_direction` | `enum`        | Mouse    | Direction in which a mouse wheel can move.      | N.A.                      |
| `mouse::state`            | `struct`      | Mouse    | Structure describing the mouse state.           | N.A.                      |

#### Keyboard

| Name                          | Type                | Category | Description                                                                    | Notes                                        |
| ----------------------------- | ------------------- | -------- | ------------------------------------------------------------------------------ | -------------------------------------------- |
| `keyboard::current_modifiers` | Free function       | Keyboard | Returns current modifier mask (combination of shift, alt, ctrl and caps lock). | Not supported on Wayland.                    |
| `keyboard::key`               | `enum`              | Keyboard | Platform-agnostic `enum` for key codes.                                        | Not all keys are supported on all platforms. |
| `keyboard::modifier`          | `enum`              | Keyboard | Platform-agnostic bitmask `enum` for modifiers codes.                          | N.A.                                         |
| `keyboard::modifier_mask`     | Type alias,`struct` | Keyboard | Mask of `keyboard::modifier`                                                   | N.A.                                         |
| `keyboard::poll`              | Free function       | Keyboard | Polls for one key state.                                                       | Not supported on Wayland.                    |

#### Screen

| Name                 | Type                | Category | Description                                                                                           | Notes                                               |
| -------------------- | ------------------- | -------- | ----------------------------------------------------------------------------------------------------- | --------------------------------------------------- |
| `screen::enumerate`  | Free function       | Keyboard | Returns a list containing information about all available screen at the time this function is called. | On Wayland, only returns the current configuration. |
| `screen::properties` | Type alias,`struct` | Screen   | Information about a screen (monitor).                                                                 | N.A.                                                |

### Events

| Name         | Type     | Category | Description                                   | Notes |
| ------------ | -------- | -------- | --------------------------------------------- | ----- |
| `event::any` | `struct` | Events   | Any event that can be handled through Fubuki. | N.A.  |

#### Handling

| Name                                         | Type          | Category                           | Description                                                                                                                   | Notes                                                                                                                                       |
| -------------------------------------------- | ------------- | ---------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| `event::answer`                              | `enum`        | Events, handling                   | Answer to an event, when applicable.                                                                                          | Primarily used to answer `event::window::close`.                                                                                            |
| `event::dispatcher`                          | `class`       | Events, handling                   | An object dispatching events to handlers. event::dispatcher behaves like a container or `event::handler`, sorted by priority. | Insertions and deletions of an event handler, along with calls to functions modifying this container must be externally synchronised.       |
| `event::handler`                             | `class`       | Events, handling                   | An interface to listen and handle events triggered on a window.                                                               | This `class` is meant to be inherited to `override` relevant overloads of the `handle()` member functions, that perform nothing by default. |
| `event::queue`                               | `class`       | Events, simulation                 | A queue for events to send to a window.                                                                                       | Access to a queue must be externally synchronised. Instances of this `class` are NOT thread-safe.                                           |
| `event::send`                                | Free function | Events, simulation                 |                                                                                                                               | It is implementation-defined if a event is simulated through the underlying platform API or ends in the user event queue.                   |
| `event::send_error::any`                     | `struct`      | Events, simulation, error handling | Any error that can occur when sending an event to a window.                                                                   | N.A.                                                                                                                                        |
| `event::send_error::not_supported`           | `struct`      | Events, simulation, error handling | Obtained when attempting to send an event that is not supported on the current platform.                                      | N.A.                                                                                                                                        |
| `event::send_error::operation_not_supported` | `struct`      | Events, simulation, error handling | Obtained when an operation is not supported on the current platform.                                                          | N.A.                                                                                                                                        |
| `event::send_error::os`                      | `struct`      | Events, simulation, error handling | Obtained when attempting to send an event to a window and a OS API call failed.                                               | N.A.                                                                                                                                        |

#### Window

| Name                           | Type      | Category       | Description                                                                      | Notes                                                         |
| ------------------------------ | --------- | -------------- | -------------------------------------------------------------------------------- | ------------------------------------------------------------- |
| `event::window::activate`      | `struct`  | Events, window | Triggered when a window is activated (displayed) for the first time.             | N.A.                                                          |
| `event::window::any`           | `concept` | Events, window | Concept matching all (and only) Fubuki window events.                            | N.A.                                                          |
| `event::window::close`         | `struct`  | Events, window | Triggered when the user requests to close a window.                              | N.A.                                                          |
| `event::window::destroy_end`   | `struct`  | Events, window | Triggered when a window destruction has ended. **NOT related to destructor.**    | Cannot be triggered through `send`. Only received on Windows. |
| `event::window::destroy_start` | `struct`  | Events, window | Triggered when a window is about to be destroyed. **NOT related to destructor.** | Cannot be triggered through `send`. Only received on Windows. |
| `event::window::enable`        | `struct`  | Events, window | Triggered when a window is enabled or disabled.                                  | N.A.                                                          |
| `event::window::focus`         | `struct`  | Events, window | Triggered when a window gains or loses focus.                                    | N.A.                                                          |
| `event::window::move`          | `struct`  | Events, window | Triggered when a window is moved.                                                | Not supported on Wayland.                                     |
| `event::window::resize`        | `struct`  | Events, window | Triggered when a window is resized.                                              | N.A.                                                          |

#### Keyboard

| Name                  | Type      | Category         | Description                                             | Notes |
| --------------------- | --------- | ---------------- | ------------------------------------------------------- | ----- |
| `event::key::any`     | `concept` | Events, keyboard | Concept matching all (and only) Fubuki keyboard events. | N.A.  |
| `event::key::press`   | `struct`  | Events, keyboard | Triggered when a key has been pressed.                  | N.A.  |
| `event::key::release` | `struct`  | Events, keyboard | Triggered when a key has been pressed.                  | N.A.  |

#### Mouse

| Name                         | Type       | Category      | Description                                             | Notes                                                                                    |
| ---------------------------- | ---------- | ------------- | ------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| `event::mouse::any`          | `concept`  | Events, mouse | Concept matching all (and only) Fubuki mouse events.    | N.A.                                                                                     |
| `event::mouse::click`        | `struct`   | Events, mouse | Triggered upon single mouse click.                      | N.A.                                                                                     |
| `event::mouse::double_click` | `struct`   | Events, mouse | Triggered upon double mouse click                       | The timeout is fixed to 500ms on Linux. On Windows, can be edited through the Win32 API. |
| `event::mouse::move`         | `struct`   | Events, mouse | Triggered upon moving the mouse on a window.            | N.A.                                                                                     |
| `event::mouse::release`      | `struct`   | Events, mouse | Triggered upon releasing a button after a single click. | N.A.                                                                                     |
| `event::mouse::scroll`       | Type alias | Events, mouse | Equivalent to `wheel`.                                  | N.A.                                                                                     |
| `event::mouse::wheel`        | `struct`   | Events, mouse | Triggered upon scrolling with the mouse wheel.          | N.A.                                                                                     |

#### User

| Name                  | Type     | Category | Description           | Notes |
| --------------------- | -------- | -------- | --------------------- | ----- |
| `event::user::custom` | `struct` | Event    | A user-defined event. | N.A.  |

#### Provenance

| Name            | Type                 | Category          | Description                                                | Notes |
| --------------- | -------------------- | ----------------- | ---------------------------------------------------------- | ----- |
| `event::cause`  | Type alias, `struct` | Event, provenance | Information about what triggered an event.                 | N.A.  |
| `event::device` | Type alias, `enum`   | Event, provenance | Indicate the nature of the device that triggered an event. | N.A.  |
| `event::origin` | Type alias, `enum`   | Event, provenance | Indicates what triggered an event.                         | N.A.  |

#### Loop

| Name                        | Type                 | Category   | Description                                                                                                                  | Notes                                                                                                         |
| --------------------------- | -------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| `event::loop::execute`      | Free function        | Event loop | Execute the event loop until it exits.                                                                                       | All overloads **block**.                                                                                      |
| `event::loop::exit`         | Free function        | Event loop | Signals the event loop must be exited by queuing the corresponding event to the queue.                                       | N.A.                                                                                                          |
| `event::loop::next::system` | Free function        | Event loop | Processes the next pending system event for a given display.                                                                 | Non-blocking (excluding the duration taken to handle the event). On Wayland, may trigger more than one event. |
| `event::loop::next::user`   | Free function        | Event loop | Processes the next pending event in a user queue.                                                                            | Non-blocking (excluding the duration taken to handle the event).                                              |
| `event::loop::pending`      | Free function        | Event loop | Indicates if a display has pending events, without handling the events.                                                      | Non-blocking.                                                                                                 |
| `event::loop::routines`     | Type alias, `struct` | Event loop | Customisation points for the event loop. Allows to perform user-defined actions at various timings while waiting for events. | N.A.                                                                                                          |
