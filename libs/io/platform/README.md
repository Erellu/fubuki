# fubuki::io::platform

> [!IMPORTANT]
> This file is _not_ a substitue for the in-code documentation.
> Its goal is to advertise the features available through `fubuki::io_platform`.
> For examples and detailed documentation, see the `doxygen`.

## CMake

### Externally

```cmake
target_link_libraries(your_target <PUBLIC|PRIVATE> fubuki::io_platform)
```

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "io_platform"
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

`fubuki::io_platform` implements the features of `fubuki::io` for the platforms natively supported by Fubuki.

> [!CAUTION]
> `fubuki::io::platform` **should not be directly used** unless platform-specific code is required.
> The facilities are designed to be used through `fubuki::io` and make some assumptions accordingly.

## Public API

### Views

| Name             | Type     | Category       | Description                   | Notes |
| ---------------- | -------- | -------------- | ----------------------------- | ----- |
| `views::display` | `struct` | Views, display | View of a display connection. | N.A.  | 

### Events

>[!NOTE]
> All features related to events described in [`fubuki::io`](https://github.com/Erellu/fubuki/blob/master/libs/io/README.md) are also available through `io::platform` under `io::platform::event`.

### Error

| Name                                      | Type       | Category       | Description                                                                                                                            | Notes                                                                                                      |
| ----------------------------------------- | ---------- | -------------- | -------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `any_call_info`                           | `struct`   | Error handling | Semantic equivalent to a `variant` of all possible `call_info` and `linux_call_info`.                                                  | N.A.                                                                                                       |
| `any_call_result`                         | `struct`   | Error handling | Semantic equivalent to a `variant` of all possible `call_result` and `linux_call_result`                                               | N.A.                                                                                                       |
| `call_exception`                          | `struct`   | Error handling | An exception thrown when a platform-specific call failed in throwing overloads of functions or constructors in `fubuki::io::platform`. | N.A.                                                                                                       |
| `call_info<window_system>`                | Type alias | Error handling | Alias to `fubuki:::call_info<call_result<window_system>>`.                                                                             | N.A.                                                                                                       |
| `call_result<window_system>`              | `struct`   | Error handling | Indicates an error occurred when doing a window-system related operation (Linux) or any operation (Windows)                            | N.A.                                                                                                       |
| `error::any`                              | `struct`   | Error          | Semantic equivalent to `variant<all other errors>`/                                                                                    | N.A.                                                                                                       |
| `error::api_call`                         | `struct`   | Error          | Indicates a platform API call failed.                                                                                                  | N.A.                                                                                                       |
| `error::operation_not_supported`          | `struct`   | Error          |                                                                                                                                        | N.A.                                                                                                       |
| `error::unknown`                          | `struct`   | Error          | An unknown error occurred.                  Indicates an operation is not supported on a given platform.                               | N.A.                                                                                                       |
| `linux_bsd::code`                         | `enum`     | Error code     | An opaque `enum` which Linux error codes are `static_cast` to.                                                                         | N.A.                                                                                                       |
| `linux_bsd::result`                       | `struct`   | Error handling | Analogue to `fubuki::result` for Linux codes.                                                                                          | N.A.                                                                                                       |
| `linux_bsd::wayland::code::any`           | `struct`   | Error handling | Semantic equivalent of `std::variant<all error codes>`.                                                                                | N.A.                                                                                                       |
| `linux_bsd::wayland::code::data_device`   | `enum`     | Error code     | Error codes related to data devices.                                                                                                   | N.A.                                                                                                       |
| `linux_bsd::wayland::code::data_offer`    | `enum`     | Error code     | Error codes related to data offers.                                                                                                    | N.A.                                                                                                       |
| `linux_bsd::wayland::code::display`       | `enum`     | Error code     | Error codes related to `wl_display`.                                                                                                   | N.A.                                                                                                       |
| `linux_bsd::wayland::code::pointer`       | `enum`     | Error code     | Error codes related to `wl_pointer`.                                                                                                   | N.A.                                                                                                       |
| `linux_bsd::wayland::code::result`        | `struct`   | Error handling | Analogue to `fubuki::result` for Wayland codes.                                                                                        | N.A.                                                                                                       |
| `linux_bsd::wayland::code::seat`          | `enum`     | Error code     | Error codes related to `wl_seat`.                                                                                                      | N.A.                                                                                                       |
| `linux_bsd::wayland::code::shell`         | `enum`     | Error code     | Error codes related to shell.                                                                                                          | N.A.                                                                                                       |
| `linux_bsd::wayland::code::shm`           | `enum`     | Error code     | Error codes related to `wl_shm` and related handles.                                                                                   | N.A.                                                                                                       |
| `linux_bsd::wayland::code::source`        | `enum`     | Error code     | Error codes related to sources.                                                                                                        | N.A.                                                                                                       |
| `linux_bsd::wayland::code::subcompositor` | `enum`     | Error code     | Error codes related to `wl_subcompositor`.                                                                                             | N.A.                                                                                                       |
| `linux_bsd::wayland::code::subsurface`    | `enum`     | Error code     | Error codes related to `wl_subsurface`.                                                                                                | N.A.                                                                                                       |
| `linux_bsd::wayland::code::success`       | `enum`     | Error code     | Tag `enum` that can be used to indicate an operation was successful.                                                                   | N.A.                                                                                                       |
| `linux_bsd::wayland::code::surface`       | `enum`     | Error code     | Error codes related to `wl_surface`.                                                                                                   | N.A.                                                                                                       |
| `linux_bsd::wayland::code::unknown`       | `enum`     | Error code     | Error codes Fubuki doesn't use or isn't aware of.                                                                                      | N.A.                                                                                                       |
| `linux_bsd::xlib::code`                   | `enum`     | Error code     | XLib error codes.                                                                                                                      | N.A.                                                                                                       |
| `linux_bsd::xlib::result`                 | `struct`   | Error handling | Analogue to `fubuki::result` for XLib codes.                                                                                           | N.A.                                                                                                       |
| `linux_call_info`                         | Type alias | Error handling | Alias to `fubuki:::call_info<linux_call_result>`                                                                                       | N.A.                                                                                                       |
| `linux_call_result`                       | `struct`   | Error handling | Analogue to `call_result` for Linux API calls unrelated to window systems (`mmap`, etc.)                                               | N.A.                                                                                                       |
| `win32::code`                             | `enum`     | Error code     | An opaque `enum` which Windows error codes are `static_cast` to.                                                                       | See [Windows system error codes](https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes) |
| `win32::result`                           | `struct`   | Error handling | Analogue to `fubuki::result` for Windows codes.                                                                                        | N.A.                                                                                                       |

### Windows

| Name                                 | Type          | Category                  | Description                                                                                 | Notes                                                                                                                                         |
| ------------------------------------ | ------------- | ------------------------- | ------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| `win32::call_info`                   | Type alias    | Error handling            | Alias to the corresponding `call_info`.                                                     | N.A.                                                                                                                                          | 
| `win32::call_result`                 | Type alias    | Error handling            | Alias to the corresponding `call_result`.                                                   | N.A.                                                                                                                                          |
| `win32::display`                     | `class`       | Display                   | Mock object used to make the API match between platforms.                                   | N.A.                                                                                                                                          |
| `win32::event::send`                 | Free function | Event, simulation         | `win32` implementation of `fubuki::io::event::send`.                                        | On Windows, Fubuki attempts to translate the events into native `::INPUT`, then into Win32 messages, and finally falls back to an user queue. |
| `win32::exit_event_loop`             | Free function | Event loop                | Posts a message to the system event queue indicating the user wants to exit the event loop. | N.A.                                                                                                                                          |
| `win32::keyboard::current_modifiers` | Free function | Keyboard                  | `win32` implementation of `fubuki::io::keyboard::current_modifiers`.                        | N.A.                                                                                                                                          |
| `win32::keyboard::from_windows`      | Free function | Keyboard, type conversion | Converts Windows virtual key codes to `fubuki::io::keyboard::key` codes.                    | N.A.                                                                                                                                          |
| `win32::keyboard::poll`              | Free function | Keyboard                  | `win32` implementation of `fubuki::io::keyboard::poll`.                                     | N.A.                                                                                                                                          |
| `win32::keyboard::to_windows`        | Free function | Keyboard, type conversion | Converts `fubuki::io::keyboard::key` codes to Windows virtual key codes .                   | N.A.                                                                                                                                          |
| `win32::make_class_id`               | Free function | Window, helper            | Generates a `string` for a window class name.                                               | N.A.                                                                                                                                          |
| `win32::module_handle`               | Free function | Window, helper            | Gets the default module handle, equivalent to Windows's API `::GetModuleHandle(nullptr)`.   | N.A.                                                                                                                                          |
| `win32::mouse::buttons_state`        | Free function | Mouse                     | `win32` implementation of `fubuki::io::mouse::buttons_state`.                               | N.A.                                                                                                                                          |
| `win32::mouse::current_state`        | Free function | Mouse                     | `win32` implementation of `fubuki::io::mouse::current_state`.                               | N.A.                                                                                                                                          |
| `win32::mouse::poll`                 | Free function | Mouse                     | `win32` implementation of `fubuki::io::mouse::poll`.                                        | N.A.                                                                                                                                          |
| `win32::mouse::pos`                  | Free function | Mouse                     | `win32` implementation of `fubuki::io::mouse::pos`.                                         | N.A.                                                                                                                                          |
| `win32::process_next_system_event`   | Free function | Event loop                | `win32` implementation of `fubuki::io::process_next_system_event`.                          | N.A.                                                                                                                                          |
| `win32::process_next_user_event`     | Free function | Event loop                | `win32` implementation of `fubuki::io::process_next_user_event`.                            | N.A.                                                                                                                                          |
| `win32::screen::enumerate`           | Free function | Screen                    | `win32` implementation of `fubuki::io::screen::enumerate`.                                  | N.A.                                                                                                                                          |
| `win32::window`                      | `class`       | Window                    | `win32` implementation of `fubuki::io::window`.                                             | N.A.                                                                                                                                          |
| `win32::window_data`                 | `struct`      | Window, wrapper           | Wrapper `struct` for data related to window creation.                                       | N.A.                                                                                                                                          |

### Linux/BSD

#### Generic

| Name                                     | Type          | Category            | Description                                                                                                      | Notes                                                           |
| ---------------------------------------- | ------------- | ------------------- | ---------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------- |
| `linux_bsd::display`                     | `class`       | Display             | Interface to the various display connections (`wayland::display`, `xlib::display`, ...).                         | N.A.                                                            |
| `linux_bsd::event::send`                 | Free function | Event, simulation   | `linux_bsd` implementation of `fubuki::io::event::send`.                                                         | On Linux, events are all added to the provided user event loop. |
| `linux_bsd::event_loop_exit_requested`   | Free function | Event loop          | Indicates if a event loop stop requested has been emitted.                                                       | N.A.                                                            |
| `linux_bsd::exit_event_loop`             | Free function | Event loop          | Emit an event loop stop request.                                                                                 | N.A.                                                            |
| `linux_bsd::fd_timer`                    | `class`       | Timer               | RAII file descriptor timer. Options are available through member `enum`s.                                        | N.A.                                                            |
| `linux_bsd::file_descriptor`             | `class`       | Memory, file system | RAII type-safe file descriptor.                                                                                  | N.A.                                                            |
| `linux_bsd::keyboard::current_modifiers` | Free function | Keyboard            | `linux_bsd` implementation of `fubuki::io::keyboard::current_modifiers`.                                         | N.A.                                                            |
| `linux_bsd::keyboard::poll`              | Free function | Keyboard            | `linux_bsd` implementation of `fubuki::io::keyboard::poll`.                                                      | N.A.                                                            |
| `linux_bsd::mouse::buttons_state`        | Free function | Mouse               | `linux_bsd` implementation of `fubuki::io::mouse::buttons_state`.                                                | N.A.                                                            |
| `linux_bsd::mouse::current_state`        | Free function | Mouse               | `linux_bsd` implementation of `fubuki::io::mouse::current_state`.                                                | N.A.                                                            |
| `linux_bsd::mouse::poll`                 | Free function | Mouse               | `linux_bsd` implementation of `fubuki::io::mouse::poll`.                                                         | N.A.                                                            |
| `linux_bsd::mouse::pos`                  | Free function | Mouse               | `linux_bsd` implementation of `fubuki::io::mouse::pos`.                                                          | N.A.                                                            |
| `linux_bsd::mouse_state`                 | `struct`      | Event handling      | Structure keeping track of the mouse state when it interacts with a window.                                      | N.A.                                                            |
| `linux_bsd::process_next_system_event`   | Free function | Event loop          | Interface to the various (`wayland`, `xlib`). Simply forwards the call based on the display connection type.     | N.A.                                                            |
| `linux_bsd::process_next_user_event`     | Free function | Event loop          | `linux_bsd` implementation of `fubuki::io::process_next_user_event`.                                             | N.A.                                                            |
| `linux_bsd::request_event_loop_exit`     | Free function | Event loop          | Emit an event loop stop request.                                                                                 | N.A.                                                            |
| `linux_bsd::scoped_mmap`                 | `class`       | Memory              | A RAII object that calls `mmap` upon construction, and `munmap` upon destruction. Behaves like a range of bytes. | N.A.                                                            |
| `linux_bsd::screen::enumerate`           | Free function | Screen              | `linux_bsd` implementation of `fubuki::io::screen::enumerate`.                                                   | N.A.                                                            |
| `linux_bsd::window`                      | `class`       | Window              | Interface to the various windows (`wayland::window`, `xlib::window`, ...).                                       | N.A.                                                            |

#### Wayland

| Name                                               | Type          | Category               | Description                                                        | Notes                                                                               |
| -------------------------------------------------- | ------------- | ---------------------- | ------------------------------------------------------------------ | ----------------------------------------------------------------------------------- |
| `linux_bsd::wayland::call_info`                    | Type alias    | Error handling         | Alias to the corresponding `call_info`.                            | N.A.                                                                                |
| `linux_bsd::wayland::call_result`                  | Type alias    | Error handling         | Alias to the corresponding `call_result`.                          | N.A.                                                                                |
| `linux_bsd::wayland::decoration`                   | `class`       | Wayland, window parts  | Interface for decorations.                                         | Currently, there is no support for client-side decorations                          |
| `linux_bsd::wayland::display`                      | `class`       | Display                | Wayland implementation of `fubuki::io::display`.                   | N.A.                                                                                |
| `linux_bsd::wayland::display_global`               | `struct`      | Wayland, display parts | Global objects retrieved through the registry of each display.     | N.A.                                                                                |
| `linux_bsd::wayland::display_parts::global_handle` | `struct`      | Display parts          | The global handles used in Fubuki.                                 | N.A.                                                                                |
| `linux_bsd::wayland::display_parts::input`         | `struct`      | Display parts          | The various inputs that a display and its windows can receive.     | N.A.                                                                                |
| `linux_bsd::wayland::display_parts::input_state`   | `struct`      | Display parts          | A structure keeping track of state changes during events.          | N.A.                                                                                |
| `linux_bsd::wayland::display_parts::properties`    | `struct`      | Display parts          | Properties and capabilities of a `wl_display`.                     | N.A.                                                                                |
| `linux_bsd::wayland::display_parts::seat_state`    | `struct`      | Display parts          | A structure keeping track of state changes during events.          | N.A.                                                                                |
| `linux_bsd::wayland::fixed::from<T>`               | Free function | Type conversion        | Converts a scalar to a fixed-point value.                          | N.A.                                                                                |
| `linux_bsd::wayland::fixed::to<T>`                 | Free function | Type conversion        | Converts a fixed-point value to the given type.                    | N.A.                                                                                |
| `linux_bsd::wayland::fixed::type`                  | Type alias    | Alias                  | The type Wayland uses for fixed-point maths.                       | N.A.                                                                                |
| `linux_bsd::wayland::keyboard`                     | `class`       | Wayland, input         | RAII wrapper for `wl_keyboard`.                                    | N.A.                                                                                |
| `linux_bsd::wayland::pointer`                      | `class`       | Wayland, input         | RAII wrapper for `wl_pointer`.                                     | N.A.                                                                                |
| `linux_bsd::wayland::process_next_system_event`    | Free function | Event loop             | Wayland implementation of `fubuki::io::process_next_system_event`. | N.A.                                                                                |
| `linux_bsd::wayland::registry`                     | `class`       | Wayland                | RAII wrapper for `wl_regsitry`.                                    | N.A.                                                                                |
| `linux_bsd::wayland::screen::enumerate`            | Free function | Screen                 | Wayland implementation of `fubuki::io::screen::enumerate`.         | N.A.                                                                                |
| `linux_bsd::wayland::seat`                         | `class`       | Wayland, input         | Interface for `wl_seat`.                                           | This object does **not** free the underlying handle, that is global to the display. |
| `linux_bsd::wayland::shm_buffer`                   | `class`       | Wayland, window parts  | RAII wrapper for `wl_shm_buffer`.                                  | N.A.                                                                                |
| `linux_bsd::wayland::shm_pool`                     | `class`       | Wayland, window parts  | RAII wrapper for `wl_shm_pool`.                                    | N.A.                                                                                |
| `linux_bsd::wayland::surface`                      | `class`       | Wayland, window parts  | RAII wrapper for `wl_surface`.                                     | N.A.                                                                                |
| `linux_bsd::wayland::window`                       | `class`       | Window                 | Wayland implementation of `fubuki::io::window`.                    | N.A.                                                                                |
| `linux_bsd::wayland::window_parts`                 | `struct`      | Window parts           | The different parts that make a window.                            | N.A.                                                                                |
| `linux_bsd::wayland::xdg::surface`                 | `class`       | XDG                    | RAII wrapper for `xdg_surface`.                                    | N.A.                                                                                |
| `linux_bsd::wayland::xdg::toplevel`                | `class`       | XDG                    | RAII wrapper for `xdg_toplevel`.                                   | N.A.                                                                                |
| `linux_bsd::wayland::xdg::wm_base`                 | `class`       | XDG                    | Interface for `xdg_wm_base` objects.                               | This object does **not** free the underlying handle, that is global to the display. |
| `linux_bsd::wayland::zxdg::decoration`             | `class`       | ZXDG                   | RAII wrapper for `zxdg_toplevel_decoration_v1`.                    | Not supported by GNOME.                                                             |

#### XLib

| Name                                           | Type          | Category       | Description                                                       | Notes |
| ---------------------------------------------- | ------------- | -------------- | ----------------------------------------------------------------- | ----- |
| `linux_bsd::xlib::call_info`                   | Type alias    | Error handling | Alias to the corresponding `call_info`.                           | N.A.  |
| `linux_bsd::xlib::call_result`                 | Type alias    | Error handling | Alias to the corresponding `call_result`.                         | N.A.  |
| `linux_bsd::xlib::display`                     | `class`       | XLib           | XLib implementation of `fubuki::io::display`.                     | N.A.  |
| `linux_bsd::xlib::display_lock`                | `class`       | XLib           | RAII XLib display lock.                                           | N.A.  |
| `linux_bsd::xlib::free_x_storage`              | `struct`      | Memory         | Deleter for XLib-acquired dynamic storage.                        | N.A.  |
| `linux_bsd::xlib::keyboard::current_modifiers` | Free function | Keyboard       | XLib implementation of `fubuki::io::keyboard::current_modifiers`. | N.A.  |
| `linux_bsd::xlib::keyboard::poll`              | Free function | Keyboard       | XLib implementation of `fubuki::io::keyboard::poll`.              | N.A.  |
| `linux_bsd::xlib::mouse::buttons_state`        | Free function | Mouse          | XLib implementation of `fubuki::io::mouse::buttons_state`.        | N.A.  |
| `linux_bsd::xlib::mouse::current_state`        | Free function | Mouse          | XLib implementation of `fubuki::io::mouse::current_state`.        | N.A.  |
| `linux_bsd::xlib::mouse::poll`                 | Free function | Mouse          | XLib implementation of `fubuki::io::mouse::poll`.                 | N.A.  |
| `linux_bsd::xlib::mouse::pos`                  | Free function | Mouse          | XLib implementation of `fubuki::io::mouse::pos`.                  | N.A.  |
| `linux_bsd::xlib::process_next_system_event`   | Free function | Event loop     | XLib implementation of `fubuki::io::process_next_system_event`.   | N.A.  |
| `linux_bsd::xlib::screen::enumerate`           | Free function | Screen         | XLib implementation of `fubuki::io::screen::enumerate`.           | N.A.  |
| `linux_bsd::xlib::unique_ptr`                  | Type alias    | Memory         | `std::unique_ptr` for XLib-acquired dynamic storage.              | N.A.  |
| `linux_bsd::xlib::window`                      | `class`       | Window         | XLib implementation of `fubuki::io::window`.                      | N.A.  |
| `linux_bsd::xlib::xrandr::crtc`                | `class`       | XRandR         | RAII wrapper for `XRRCrtcInfo`.                                   | N.A.  |
| `linux_bsd::xlib::xrandr::output`              | `class`       | XRandR         | RAII wrapper for `XRROutputInfo`.                                 | N.A.  |
| `linux_bsd::xlib::xrandr::screen_config`       | `class`       | XRandR         | RAII wrapper for `XRRScreenConfiguration`.                        | N.A.  |
| `linux_bsd::xlib::xrandr::screen_resource`     | `class`       | XRandR         | RAII wrapper for `XRRScreenResources`.                            | N.A.  |

#### XKB

| Name                      | Type          | Category             | Description                                                    | Notes |
| ------------------------- | ------------- | -------------------- | -------------------------------------------------------------- | ----- |
| `linux_bsd::xkb::context` | `class`       | XKB                  | A RAII wrapper for a `xkb_context`.                            | N.A.  |
| `linux_bsd::xkb::from`    | Free function | XKB, type conversion | Converts an XKB key sym to a `fubuki::io::keyboard::key` code. | N.A.  |
| `linux_bsd::xkb::keymap`  | `class`       | XKB                  | A RAII wrapper for a `xkb_keymap`.                             | N.A.  |
| `linux_bsd::xkb::state`   | `class`       | XKB                  | A RAII wrapper for a `xkb_state`.                              | N.A.  |
